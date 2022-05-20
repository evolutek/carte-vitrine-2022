#pragma once

#include "Driver.h"

#include <Servo.h>


class ServoDriver : public Driver {
    private:

    Servo servo;
    int pin;


    public:

    ServoDriver(int pin) {
        this->pin = pin;
    }

    void init() {
        servo.attach(pin);
    }

    // Set the angle (not in degree or radians)
    // same as https://www.arduino.cc/reference/en/libraries/servo/writemicroseconds/
    void setAngle(int angle) {
        servo.writeMicroseconds(angle);
    }
};
