#pragma once

#include "Driver.h"


class LedDriver : public Driver {
    private:
        
    int pin;
    bool state;


    public:

    LedDriver(int pin) {
        this->pin = pin;
        this->state = LOW;
    }

    void init() {
        pinMode(pin, OUTPUT);
        digitalWrite(pin, LOW);
        state = LOW;
    }

    void enable() {
        state = HIGH;
        digitalWrite(pin, HIGH);
    }

    void disable() {
        state = LOW;
        digitalWrite(pin, LOW);
    }

    void invert() {
        state = !state;
        digitalWrite(pin, state);
    }
};
