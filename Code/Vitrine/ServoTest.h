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

    EventsDriver events;

    static void tick(void* data) {
        ServoTest* self = (ServoTest*) data;

        self->writeAngle();
        
        self->current_angle += self->current_speed;

        if (self->current_angle < self->min_angle) {
            self->current_angle = self->min_angle;
            self->current_speed = -self->current_speed;
        } else if (self->current_angle > self->max_angle) {
            self->current_angle = self->max_angle;
            self->current_speed = -self->current_speed;
        }
    }

    void writeAngle() {
        this->left_servo.write(this->current_angle);
        this->right_servo.write(180 - this->current_angle);
    }


    public:

    ServoTest(EventsDriver events, int left_servo_pin, int right_servo_pin, int min_angle, int max_angle) {
        this->left_servo_pin = left_servo_pin;
        this->right_servo_pin = right_servo_pin;
        
        this->min_angle = min_angle;
        this->max_angle = max_angle;

        this->current_speed = 1;
        this->current_angle = 90;

        this->events = events;
    }

    void setup() {
        this->left_servo.attach(this->left_servo_pin);
        this->right_servo.attach(this->right_servo_pin);
        this->writeAngle();
        delay(1500);
        Serial.setTimeout(10);
        events.addEvent(tick, this, 15, false);
    }

    void loop() {
        ;
    }
};
