#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>
#include <UMS3.h>
#include "wireless.h"
#include "pinout.h"
#include "util.h"

#define RESOLUTION 5

// TODO: Replace with the mac address of the robot.
uint8_t broadcastAddress[] = {0xEC, 0xDA, 0x3B, 0x41, 0xA0, 0x38};

joystickData joystick;
uint16_t x = 0, y = 0;
uint16_t xPrev = 0, yPrev = 0;

UMS3 ums3;

esp_now_peer_info_t peerInfo;

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {

    bool success = status == ESP_NOW_SEND_SUCCESS ;
    if (success) {
      Serial.printf("Sent x:%d y:%d\n", joystick.x, joystick.y);
    } else {
      Serial.println("Failed");
    }

}

void setup(void){
    Serial.begin();

    //ESP_NOW Setup
    // Set device as a Wi-Fi Station
    WiFi.mode(WIFI_STA);

    // Init ESP-NOW
    if (esp_now_init() != ESP_OK) {
      Serial.println("Error initializing ESP-NOW");
      return;
    }

    //Tell the microcontroller which functions to call when
    //data is sent or received
    esp_now_register_send_cb(OnDataSent);
    
    // Register peer
    memcpy(peerInfo.peer_addr, broadcastAddress, 6);
    peerInfo.channel = 0;  
    peerInfo.encrypt = false;
  
    // Add peer        
    if (esp_now_add_peer(&peerInfo) != ESP_OK){
      Serial.println("Failed to add peer");
      return;
    }
    // ESP-NOW Setup Complete

    // Initialize analog pins
    pinMode(X_PIN, INPUT);
    pinMode(Y_PIN, INPUT);

    // Start the LED
    ums3.begin();
    // Brightness is 0-255. We set it to 1/2 brightness here
    ums3.setPixelBrightness(255/2);
}

void loop(){

  EVERY_N_MILLIS(50) {

    x = analogRead(X_PIN);
    y = analogRead(Y_PIN);

    bool update = false;
    if (abs(x - xPrev) > RESOLUTION) {
      xPrev = x;
      update = true;
    }
    if (abs(y - yPrev) > RESOLUTION) {
      yPrev = y;
      update = true;
    }
    
    if (update) {
      joystick.x = xPrev;
      joystick.y = yPrev;
      ums3.setPixelColor(xPrev/16, 0, yPrev/16);

      // Send message via ESP-NOW
      esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &joystick, sizeof(joystick));
    }    
  }

}