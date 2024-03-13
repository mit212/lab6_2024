#ifndef DRIVE_H
#define DRIVE_H

#define NUM_MOTORS 4

#define Ti 0.0183
#define Td 0.0021
#define Kp 0.25
#define alpha 10

void setupDrive();
void updateSetpoints(double forward, double turn);
void updateLeadLags();

#endif // DRIVE_H