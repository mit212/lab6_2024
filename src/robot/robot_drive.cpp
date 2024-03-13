#include <Arduino.h>
#include "pinout.h"
#include "MotorDriver.h"
#include "EncoderVelocity.h"
#include "PID.h"
#include "util.h"
#include "robot_drive.h"

MotorDriver motors[NUM_MOTORS] = { {A_DIR1, A_PWM1, 0}, {A_DIR2, A_PWM2, 1},
                                   {B_DIR1, B_PWM1, 2}, {B_DIR2, B_PWM2, 3} };

EncoderVelocity encoders[NUM_MOTORS] = { {ENCODER1_A_PIN, ENCODER1_B_PIN, CPR_312_RPM, 0.2},
                                         {ENCODER2_A_PIN, ENCODER2_B_PIN, CPR_312_RPM, 0.2},
                                         {ENCODER3_A_PIN, ENCODER3_B_PIN, CPR_312_RPM, 0.2}, 
                                         {ENCODER4_A_PIN, ENCODER4_B_PIN, CPR_312_RPM, 0.2} };

PID pids[NUM_MOTORS] = { {Kp, Ki, Kd, 0, tau, false}, {Kp, Ki, Kd, 0, tau, false}, 
                         {Kp, Ki, Kd, 0, tau, false}, {Kp, Ki, Kd, 0, tau, false} };

double setpoints[NUM_MOTORS] = {0, 0, 0, 0};
double velocities[NUM_MOTORS] = {0, 0, 0, 0};
double controlEfforts[NUM_MOTORS] = {0, 0, 0, 0};

double forward = 0;
double turn = 0;

void setup() {
    // Setup code here, such as initializing serial communication or motor drivers
    Serial.begin();

    setupWireless();
    
    for (uint8_t i = 0; i < NUM_MOTORS; i++)
        motors[i].setup();
}

void loop() {
    // Update setpoint at 50Hz
    EVERY_N_MILLIS(20) {
        if (freshWirelessData) {
            forward = mapDouble(joystick.y, 0.0, 4096.0, -MAX_FORWARD, MAX_FORWARD);
            turn = mapDouble(joystick.x, 0.0, 4096.0, -MAX_TURN, MAX_TURN);

            setpoints[0] = forward + turn;
            setpoints[1] = forward - turn;
            setpoints[2] = forward + turn;
            setpoints[3] = forward - turn;
        }
    }

    //update PID at 200Hz
    EVERY_N_MILLIS(5) {
        for (uint8_t i = 0; i < NUM_MOTORS; i++) {
            // Motors on right side are set up mirrored
            velocities[i] = pow(-1, i) * encoders[i].getVelocity(); 
            controlEfforts[i] = pids[i].calculateParallel(velocities[i], setpoints[i]);
            motors[i].drive(controlEfforts[i]);
        }
    }

    // Print values at 20Hz
    EVERY_N_MILLIS(50) {
        Serial.printf("Forward: %.2f, Turn: %.2f \n",
                    forward, turn);
    }
}