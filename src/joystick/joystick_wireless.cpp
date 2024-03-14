#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>
#include <UMS3.h>
#include "wireless.h"
#include "pinout.h"
#include "util.h"

// TODO: Replace with the mac address of the robot.
uint8_t broadcastAddress[] = {0xEC, 0xDA, 0x3B, 0x41, 0xA0, 0x38};

joystickData joystick;

// TODO: Initialize any other global variable/s.
// Hint: You only need one for your code to work at the bare minimum.

// TODO: Define the callback function when data is sent.
// Consider printing the data to Serial before sending.

void setup(void){
    // TODO: Initialize Serial communication.

    // TODO: Fill in code to set up ESP_NOW.

    // TODO: Initialize joystick pins as INPUT.

}

void loop(){

  // Read and send joystick data at 20Hz
  EVERY_N_MILLIS(50) {

    // TODO: Read data from joystick pins.
    
    // TODO: Populate joystick.x and joystick.y.

    // TODO: Send message via ESP-NOW.

  }

}