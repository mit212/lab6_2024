#ifndef WIRELESS_H
#define WIRELESS_H

#include <Arduino.h>

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len);

void wirelessSetup(void);

struct joystickData {
    uint16_t x;
    uint16_t y;
} ;

struct robotData {
    float angle;
    float distance;
    float controlEffort;
    uint millis;
} ;

extern joystickData joystick;
extern robotData robot;
extern bool freshWirelessData;

#endif // WIRELESS_H