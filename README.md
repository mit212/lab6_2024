# Lab 6: Mobile Robot I

2.12/2.120 Intro to Robotics  
Spring 2024[^1]

<details>
  <summary>Table of Contents</summary>

- [1 Mobile Robot](#1-mobile-robot)
  - [1.1 Validation](#11-validation)
    - [1.1.1 Validate Microcontroller](#111-validate-microcontroller)
    - [1.1.1 Validate Mobile Robot](#111-validate-mobile-robot)
  - [1.2 Read Joystick Data](#12-read-joystick-data)
  - [1.3 Drive Robot](#13-drive-robot)
- [2 Controller](#2-controller)
  - [2.1 Validation](#21-validation)
    - [2.1.1 Validate Microcontroller](#211-validate-microcontroller)
    - [2.2 Read Joystick](#22-read-joystick)
  - [2.3 Send Joystick Data](#23-send-joystick-data)
- [4 Free Exploration](#4-free-exploration)
- [4.1 Wireless Communication](#41-wireless-communication)
  - [4.1.1 Wiring](#411-wiring)
  - [4.1.2 Coding](#412-coding)
  - [4.1.3 Wireless Sensor-controlled Motor](#413-wireless-sensor-controlled-motor)
- [4.2 TFT Display](#42-tft-display)
  - [4.2.1 Wiring](#421-wiring)
  - [4.2.2 Coding](#422-coding)
  - [4.2.3 Sensor Integration](#423-sensor-integration)
- [5 Feedback Form](#5-feedback-form)

</details>

In this lab, you will be working together as a team to drive your mobile robot! First, you will split into two subteams, one for mobile robot and one for controller. Section 1 will be for the mobile robot team and Section 2 will be for the controller. Afterwards, you will recombine to practice drive your mobile robot around!

## 1 Mobile Robot

### 1.1 Validation
Estimated time of completion: 5 min

#### 1.1.1 Validate Microcontroller

Clone this repository and run `robot/blink_test.cpp`. You should see the onboard LED change colors! 

<details> <summary> <i> Forget how to clone? </i> </summary>

Please refer to the [instructions from Lab 1](
https://github.com/mit212/lab1_2024?tab=readme-ov-file#31-git-clone).

</details>

#### 1.1.1 Validate Mobile Robot

### 1.2 Read Joystick Data

### 1.3 Drive Robot

## 2 Controller

### 2.1 Validation
Estimated time of completion: 5 min

#### 2.1.1 Validate Microcontroller

Clone this repository and run `robot/blink_test.cpp`. You should see the onboard LED change colors! 

<details> <summary> <i> Forget how to clone? </i> </summary>
Please refer to the [instructions from Lab 1](
https://github.com/mit212/lab1_2024?tab=readme-ov-file#31-git-clone).
</details>

#### 2.2 Read Joystick

### 2.3 Send Joystick Data

## 4 Free Exploration
Estimated time of completion: now until the end of lab

The next two subsections are purposefully open-ended to encourage exploration. You are welcome to do either, both, or something completely different!  (We have random sensors in the bin.) Again, consider doing something you think will be useful for the final project. You will demonstrate to the staff what you have made in the last 10-15 minutes of lab.

## 4.1 Wireless Communication

Upto now, we've only used wired communications. What happens if we want to control the mobile robot via joystick for the final project? Clearly, the joystick can't also be physically attached to the mobile robot. The microcontrollers we are using can communicate to each other via WiFi. 

### 4.1.1 Wiring

You first need to divide your setup into a *sender* and a *receiver*. In our case, the *sender* should be connected to your chosen sensor, while the *receiver* should be connected to the motor. Ask the staff for any necessary parts and rewire your setup.

### 4.1.2 Coding

Run `get_mac.cpp` on the *receiver* to get the MAC address of the *receiver* microcontroller. Then, replace `broadcastAddress` in `wireless/esp_now_sender.cpp` to be that MAC address. Run `wireless/esp_now_sender.cpp` on the *sender* and `wireless/esp_now_receiver.cpp` on the *receiver*. Keep the *receiver* connected to your machine and open the Serial Monitor. 

Confirm that the data received, as printed on the Serial Monitor, is reasonable given the data sent. Hint: Refer to lines `60` to `63` in `wireless/esp_now_sender.cpp` to see what data is being sent.

### 4.1.3 Wireless Sensor-controlled Motor 

Copy `wireless/esp_now_sender.cpp` to `lab_code/sensor_sender.cpp` and `wireless/esp_now_receiver.cpp` to `lab_code/robot_receiver.cpp`. 

Then, modify the newly copied code so that the *sender* reads and sends sensor data, while the *receiver* parses this data and uses it to command the motor. Remember what you learned in previous labs about `struct`s to define a message type. You may need to incorporate code from `test_code/motor_position/control.cpp`.

If you get stuck, refer to this [tutorial](https://randomnerdtutorials.com/esp-now-esp32-arduino-ide/) or ask the staff for help!

## 4.2 TFT Display

Up to now, we've conducted all our validation tests by printing to the Serial Monitor. This requires constant wired connection to your machine, which isn't always ideal. For example, you might want to troubleshoot sensors on your mobile robot as it is moving! In some cases, it is more convenient to instead use a TFT display.

### 4.2.1 Wiring

Ask the staff for a TFT display and wire it onto your breadboard using [this Adafruit page](https://learn.adafruit.com/adafruit-3-5-color-320x480-tft-touchscreen-breakout/spi-wiring-and-test) as reference. If you did the wireless setup, wire the display to the *sender*. Or, if your breadboard is too crowded, ask the staff for another microcontroller and breadboard. Remember to validate the new microcontroller by first running `robot/blink_test.cpp`.

### 4.2.2 Coding

Import the `Adafruit_HX8357` library and copy the example code into `test_code/display_test.cpp`. Run `test_code/display_test.cpp` to show text and shapes on your display. 

### 4.2.3 Sensor Integration

Choose a sensor whose readings will be printed on the display. If you are using a new microcontroller and breadboard, rewire your chosen sensor on the new breadboard and revalidate it first using the test code you wrote in `test_sensors/`.

In `lab_code/display_sensor.cpp`, combine `test_code/display_test.cpp` and the test code you wrote in `test_sensors/` to print sensor readings to the display instead of the Serial Monitor. You may find the implementation of `testText()` in `test_code/display_test.cpp` helpful.


| :white_check_mark: CHECKOFF 2 :white_check_mark:   |
|:---------------------------------------------------|
| Show your chosen mini-project to a TA or LA. |

## 5 Feedback Form

Before you leave, please fill out https://tinyurl.com/212-feedback. 

| :white_check_mark: CHECKOFF 3 :white_check_mark:   |
|:---------------------------------------------------|
| Show the feedback form completion screen to a TA or LA. |

[^1]: Version 1 - 2024: Joseph Ntaimo, Jinger Chong, Josh Sohn
