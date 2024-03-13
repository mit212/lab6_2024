#include <Arduino.h>
#include <ESP32Encoder.h>
#include "pinout.h"

#define PRINT_DELAY 50

// TODO: THIS TEST IS BROKEN? 

ESP32Encoder encoder1;
ESP32Encoder encoder2;
ESP32Encoder encoder3;
ESP32Encoder encoder4;

void setup(){	
	Serial.begin();

	// Enable the weak pull down resistors
	ESP32Encoder::useInternalWeakPullResistors=UP;

	encoder1.attachFullQuad(ENCODER1_A_PIN, ENCODER1_B_PIN);
	encoder2.attachFullQuad(ENCODER2_A_PIN, ENCODER2_B_PIN);
	encoder3.attachFullQuad(ENCODER3_A_PIN, ENCODER3_B_PIN);
	encoder4.attachFullQuad(ENCODER4_A_PIN, ENCODER4_B_PIN);
}

void loop(){
	// Loop and read the count
	Serial.printf("COUNTS: E1 %d   E2 %d   E3 %d   E4 %d\n", 
					encoder1.getCount(), encoder2.getCount(),
					encoder3.getCount(), encoder4.getCount());
	delay(PRINT_DELAY);
}