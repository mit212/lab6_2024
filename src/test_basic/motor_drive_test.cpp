#include <Arduino.h>
#include "pinout.h"
#include "MotorDriver.h"

#define DELAY 500 // Delay between motor movements in milliseconds

// Create an instance of the MotorDriver class
MotorDriver motor1(A_DIR1, A_PWM1, 0);
MotorDriver motor2(A_DIR2, A_PWM2, 1);
MotorDriver motor3(B_DIR1, B_PWM1, 2);
MotorDriver motor4(B_DIR2, B_PWM2, 3);

void setup() {
    // Initialize serial communication
    Serial.begin();

    // Setup the motor driver
    motor1.setup();
    motor2.setup();
    motor3.setup();
    motor4.setup();
}

void testMotor(MotorDriver motor) {
    // Move the motor forward at full speed
    Serial.println("Moving Forward at full speed");
    motor.drive(1.0); // 100% duty cycle
    delay(DELAY);

    // Stop the motor
    Serial.println("Stopping");
    motor.drive(0.0); // 0% duty cycle
    delay(DELAY);

    // Move the motor forward at half speed
    Serial.println("Moving Forward at half speed");
    motor.drive(0.5); // 50% duty cycle
    delay(DELAY);

    // Stop the motor
    Serial.println("Stopping");
    motor.drive(0.0); // 0% duty cycle
    delay(DELAY);

    // Move the motor backward at full speed
    Serial.println("Moving Backward at full speed");
    motor.drive(-1.0); // -100% duty cycle (backward)
    delay(DELAY);

    // Stop the motor
    Serial.println("Stopping");
    motor.drive(0.0); // 0% duty cycle
    delay(DELAY);

    // Move the motor backward at half speed
    Serial.println("Moving Backward at half speed");
    motor.drive(-0.5); // -50% duty cycle (backward)
    delay(DELAY);

    // Stop the motor
    Serial.println("Stopping");
    motor.drive(0.0); // 0% duty cycle
    delay(DELAY);
}

void loop() {
    testMotor(motor1);
    testMotor(motor2);
    testMotor(motor3);
    testMotor(motor4);
}