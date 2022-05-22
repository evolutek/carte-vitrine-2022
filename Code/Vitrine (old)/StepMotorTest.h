#pragma once

#include "StepMotorDriver.h"


class StepMotorTest : public Test {
    private:

    StepMotorDriver motor;
    EventsDriver *events;


    public:

    StepMotorTest(EventsDriver &events, int a, int b, int c, int d) : motor(events, 2 * 8 * 64, a, b, c, d) {
        this->events = &events;
    }

    void setup() {
        motor.init();
        motor.free();
        motor.setSpeed(8);
        motor.start();
    }

    void loop() {
        ;
    }
};
