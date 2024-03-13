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
    EVERY_N_MICROS(500) {
        int x = joystick.x < CONTROLLER_DEADBAND ? 0 : joystick.x;
        int y = joystick.y < CONTROLLER_DEADBAND ? 0 : joystick.y;
        forward = mapDouble(y, 0, 4096, -MAX_FORWARD, MAX_FORWARD);
        turn = mapDouble(x, 0, 4096, -MAX_TURN, MAX_TURN);
        updateSetpoints(forward, turn);
    }

    //update PID at 5khz
    EVERY_N_MICROS(200) {
        updateLeadLags();
    }

    // Print values at 50Hz
    EVERY_N_MILLIS(20) {
            Serial.printf("Forward: %.2f, Turn: %.2f",
                          forward, turn);
    }
  
}