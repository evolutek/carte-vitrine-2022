#pragma once

#include "Test.h"

#include <Servo.h>


class ServoTest : public Test {
    private:

    Servo left_servo;
    Servo right_servo;

    int left_servo_pin;
    int right_servo_pin;

    int min_angle;
    int max_angle;

    int current_speed;
    int current_angle;


    public:

    ServoTest(int left_servo_pin, int right_servo_pin, int min_angle, int max_angle) {
        this->left_servo_pin = left_servo_pin;
        this->right_servo_pin = right_servo_pin;
        
        this->min_angle = min_angle;
        this->max_angle = max_angle;

        this->current_speed = 1;
        this->current_angle = 90;
    }

    void writeAngle() {
        this->left_servo.write(this->current_angle);
        this->right_servo.write(180 - this->current_angle);
    }

    void setup() {
        this->left_servo.attach(this->left_servo_pin);
        this->right_servo.attach(this->right_servo_pin);
        this->writeAngle();
        delay(1500);
        Serial.setTimeout(10);
    }

    void loop() {
        writeAngle();
        
        current_angle += current_speed;

        if (current_angle < min_angle) {
            current_angle = min_angle;
            current_speed = -current_speed;
        } else if (current_angle > max_angle) {
            current_angle = max_angle;
            current_speed = -current_speed;
        }

        delay(20);
    }
};
