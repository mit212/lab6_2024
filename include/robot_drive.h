#ifndef DRIVE_H
#define DRIVE_H

#define NUM_MOTORS 4

#define Kp 0.5
#define Ki 0
#define Kd 0
#define tau 0.1

void setupDrive();
void updateSetpoints(double forward, double turn);
void updateLeadLags();

#endif // DRIVE_H