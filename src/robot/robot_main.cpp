#include <Arduino.h>
#include "util.h"
#include "wireless.h"
#include "robot_drive.h"
#include "robot_main.h"

void setup() {
  // Setup code here, such as initializing serial communication or motor drivers
    Serial.begin();
    setupDrive();
    setupWireless();
}

double forward = 0;
double turn = 0;

void loop() {

    // Update setpoint at 2kHz
    // Update setpoint at 50Hz
    EVERY_N_MILLIS(20) {
        if (freshWirelessData) {
            forward = mapDouble(joystick.y, 0.0, 4096.0, -MAX_FORWARD, MAX_FORWARD);
            turn = mapDouble(joystick.x, 0.0, 4096.0, -MAX_TURN, MAX_TURN);
            updateSetpoints(forward, turn);
        }
        // Serial.printf("Forward: %.2f, Turn: %.2f \n",
        //             forward, turn);
    }

    //update PID at 5kHz
    //update PID at 200Hz
    EVERY_N_MILLIS(5) {
        updateLeadLags();
    }

    // // Print values at 20Hz
    // EVERY_N_MILLIS(50) {
    //     Serial.printf("Forward: %.2f, Turn: %.2f \n",
    //                 forward, turn);
    // }
  
}