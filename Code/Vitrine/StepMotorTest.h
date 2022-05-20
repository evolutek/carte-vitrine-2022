#pragma once

#include <Stepper.h>


class StepMotorTest : public Test {
    private:

    Stepper motor;


    public:

    StepMotorTest(int a, int b, int c, int d) : motor(64 * 8, a, b, c, d) {
        ;
    }

    void setup() {
        motor.setSpeed(30);
    }

    void loop() {
        motor.step(64 * 4);
        Serial.println("blablabla");
    }
};
