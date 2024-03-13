# Lab 6: Mobile Robot I

2.12/2.120 Intro to Robotics  
Spring 2024[^1]

<details>
  <summary>Table of Contents</summary>

- [1 Mobile Robot Subteam](#1-mobile-robot-subteam)
  - [1.1 Validation](#11-validation)
    - [1.1.1 Validate Microcontroller](#111-validate-microcontroller)
    - [1.1.2 Get MAC Address](#112-get-mac-address)
    - [1.1.3 Validate Mobile Robot](#113-validate-mobile-robot)
    - [1.1.4 Validate Encoders](#114-validate-encoders)
  - [1.2 Joystick](#12-joystick)
    - [1.2.1 Read Joystick](#121-read-joystick)
    - [1.2.2 Update Setpoint](#122-update-setpoint)
- [2 Controller Subteam](#2-controller-subteam)
  - [2.1 Validation](#21-validation)
    - [2.1.1 Validate Microcontroller](#211-validate-microcontroller)
    - [2.2 Validate Joystick](#22-validate-joystick)
  - [2.2 Wireless Joystick Data](#22-wireless-joystick-data)
- [3 Drive the Mobile Robot!](#3-drive-the-mobile-robot)
- [4 Feedback Form](#4-feedback-form)

</details>

In this lab, you will be working together as a team to drive your mobile robot! First, you will split into two subteams, one for mobile robot and one for controller. Section 1 will be for the mobile robot team and Section 2 will be for the controller. Afterwards, you will recombine to practice drive your mobile robot around!

## 1 Mobile Robot Subteam

### 1.1 Validation
Estimated time of completion: 5 min

#### 1.1.1 Validate Microcontroller

Clone this repository and run `robot/blink_test.cpp`. You should see the onboard LED change colors! 

<details> <summary> <i> Forget how to clone? </i> </summary>

Please refer to the [instructions from Lab 1](
https://github.com/mit212/lab1_2024?tab=readme-ov-file#31-git-clone).

</details>

#### 1.1.2 Get MAC Address
Run `test_wireless/get_mac.cpp` to get the MAC address of your microcontroller. It should look something like `30:AE:A4:07:0D:64`. Your microcontroller will be the receiver. Tell this MAC address to the controller subteam.

#### 1.1.3 Validate Mobile Robot
Run `test_basic/motor_drive_test.cpp`. You should see each motor driving at two different speeds one-by-one. Make sure that the wheels spin in the following order: front left, front right, back left, and back right.

#### 1.1.4 Validate Encoders
Run `test_basic/encoder_test.cpp`. You should see each motor's position and velocity being printed to the Serial monitor. Make sure that E1 is front left, E2 is front right, E3 is back left, and E4 is back right.

### 1.2 Joystick
We will assume the controller subteam has successfully sent joystick data to your microcontroller. 

#### 1.2.1 Read Joystick

In `robot/robot_main.cpp`, complete `forward` and `turn` such that `forward` maps reflects `Y` joystick readings and `turn` reflects `X` joystick readings.

#### 1.2.2 Update Setpoint

In `robot/robot_drive.cpp`, complete `updateSetpoint` such that the each of the motor's setpoints are updated according to `forward` and `turn`.

## 2 Controller Subteam

### 2.1 Validation
Estimated time of completion: 5 min

#### 2.1.1 Validate Microcontroller

Clone this repository and run `robot/blink_test.cpp`. You should see the onboard LED change colors! 

<details> <summary> <i> Forget how to clone? </i> </summary>
Please refer to the [instructions from Lab 1](
https://github.com/mit212/lab1_2024?tab=readme-ov-file#31-git-clone).
</details>

#### 2.2 Validate Joystick

Run `test_sensors/joystick_test.cpp`. You should see the `X` and `Y` readings of the joystick.

### 2.2 Wireless Joystick Data

In `joystick/joystick_wireless.cpp`:

- Replace the `broadcastAddress[]` with the MAC address that the mobile robot subteam gave you. 
- Initialize analog pins
- Read analog pins
- Send joystick struct

## 3 Drive the Mobile Robot!

At this point, you should be able to use your joystick to drive your mobile robot around!

## 4 Feedback Form

Before you leave, please fill out https://tinyurl.com/212-feedback. 

| :white_check_mark: CHECKOFF 3 :white_check_mark:   |
|:---------------------------------------------------|
| Show the feedback form completion screen to a TA or LA. |

[^1]: Version 1 - 2024: Joseph Ntaimo, Jinger Chong, Josh Sohn
