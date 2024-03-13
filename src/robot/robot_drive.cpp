#include <Arduino.h>
#include "pinout.h"
#include "MotorDriver.h"
#include "SimpleFilters.h"
#include "EncoderVelocity.h"
#include "robot_drive.h"

MotorDriver motors[NUM_MOTORS] = { {A_DIR1, A_PWM1, 0}, {A_DIR2, A_PWM2, 1},
                                   {B_DIR1, A_PWM1, 2}, {B_DIR2, A_PWM2, 3} };

EncoderVelocity encoders[NUM_MOTORS] = { {ENCODER1_A_PIN, ENCODER1_B_PIN, CPR_312_RPM, 0.2},
                                         {ENCODER2_A_PIN, ENCODER2_B_PIN, CPR_312_RPM, 0.2},
                                         {ENCODER3_A_PIN, ENCODER3_B_PIN, CPR_312_RPM, 0.2}, 
                                         {ENCODER4_A_PIN, ENCODER4_B_PIN, CPR_312_RPM, 0.2} };

LeadLagFilter leadLags[NUM_MOTORS] = { {alpha, Td, Ti}, {alpha, Td, Ti}, 
                                       {alpha, Td, Ti}, {alpha, Td, Ti} };

double setpoints[NUM_MOTORS] = {0, 0, 0, 0};
double velocities[NUM_MOTORS] = {0, 0, 0, 0};
double controlEfforts[NUM_MOTORS] = {0, 0, 0, 0};

void setupDrive(){
    for (uint8_t i = 0; i < NUM_MOTORS; i++)
        motors[i].setup();
}

void updateSetpoints(double forward, double turn) {
    setpoints[0] = forward + turn;
    setpoints[1] = forward - turn;
    setpoints[2] = forward + turn;
    setpoints[3] = forward - turn;
}

void updateLeadLags() {
    for (uint8_t i = 0; i < NUM_MOTORS; i++) {
        velocities[i] = encoders[i].getVelocity();
        controlEfforts[i] = Kp * leadLags[i].calculate(setpoints[i] - velocities[i]);
        motors[i].drive(controlEfforts[i]);
    }
}