#include "EncoderVelocity.h"
#include "pinout.h"
#include "EveryNMillis.h"

#define PRINT_DELAY 50

// Encoder velocity readers
EncoderVelocity encoder1(ENCODER1_A_PIN, ENCODER1_B_PIN, CPR_312_RPM);
EncoderVelocity encoder2(ENCODER2_A_PIN, ENCODER2_B_PIN, CPR_312_RPM);
EncoderVelocity encoder3(ENCODER3_A_PIN, ENCODER3_B_PIN, CPR_312_RPM);
EncoderVelocity encoder4(ENCODER4_A_PIN, ENCODER4_B_PIN, CPR_312_RPM);

void setup() {
    Serial.begin();
}

void loop(){
    // Print encoder readings every PRINT_DELAY milliseconds
    EVERY_N_MILLIS(PRINT_DELAY) {
        Serial.printf("POS, VEL: E1 %.2f, %.2f   E2 %.2f, %.2f   "
                    "E3 %.2f, %.2f   E4 %.2f, %.2f\n", 
                    encoder1.getPosition(), encoder1.getVelocity(),
                    encoder2.getPosition(), encoder2.getVelocity(),
                    encoder3.getPosition(), encoder3.getVelocity(),
                    encoder4.getPosition(), encoder4.getVelocity());
    }
}