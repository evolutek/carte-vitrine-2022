#pragma once

// Pins definitions

#define PIN_LED_ONBOARD 13
#define PIN_LED_STATUE  12
#define PIN_LED_UP      2
#define PIN_LED_DOWN    8

#define PIN_MOTOR_A 6
#define PIN_MOTOR_B 7
#define PIN_MOTOR_C 5
#define PIN_MOTOR_D 4

#define PIN_SENSOR_LEFT  A0
#define PIN_SENSOR_RIGHT A1

#define PIN_BTN_MOVE A2

#define PIN_LEDSTRIP_INNER 3
#define PIN_LEDSTRIP_OUTER 9

#define PIN_SERVO_LEFT  11
#define PIN_SERVO_RIGHT 10


// Other parameters

#define SERIAL_BAUDRATE 115200

#define MOTOR_SPEED 30 // RPMs
#define MOTOR_NB_STEPS (2 * 4 * 64) // Number of steps to do one full rotation

#define NUMBER_LEDRINGL 16    //Number of led in the Little LedRing, Can Change
#define NUMBER_LEDRINGB 60   //Number of led in the Big LedRing, Can Change

#define LEFT_SERVO_LOW_ANGLE    58
#define LEFT_SERVO_HIGH_ANGLE   155
#define RIGHT_SERVO_LOW_ANGLE   155
#define RIGHT_SERVO_HIGH_ANGLE  58
