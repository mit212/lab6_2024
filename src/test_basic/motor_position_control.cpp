#include <Arduino.h>
#include "PID.h"
#include "SimpleFilters.h"
#include "EncoderVelocity.h"
#include "pinout.h"
#include "util.h"
#include "MotorDriver.h"

#define Ti 0.0183
#define Td 0.0021
#define Kp 0.936
#define alpha 10
MotorDriver motor(DIR1, PWM1, 0);  
EncoderVelocity encoder(ENCODER_A_PIN, ENCODER_B_PIN, CPR_312_RPM, 0.2);
LeadLagFilter leadLag(alpha, Td, Ti);
double setpoint = 0;
double position = 0;
double controlEffort = 0;

#define MAX_FREQ 10.0 //rad/s
#define MAX_AMPLITUDE M_PI //rad
double freq = MAX_FREQ/2;
double amplitude = MAX_AMPLITUDE;

void setup() {
    motor.setup();
    Serial.begin(); 
}

void loop() {
    // Update sinusiodal setpoint at 2kHz
    EVERY_N_MICROS(500) {
        setpoint =  amplitude*sin(freq*millis()/1000.0);
    }

    //update PID at 5khz
    EVERY_N_MICROS(200) {
        position = encoder.getPosition();
        controlEffort = Kp*leadLag.calculate(setpoint-position);
        motor.drive(controlEffort);
    }

    // Print values at 50Hz
    EVERY_N_MILLIS(20) {
            Serial.printf("Setpoint (rad): %.2f, Position (rad): %.2f, Control Effort: %.2f\n",
                          setpoint, position, controlEffort);
        }
}