#pragma once

#include "Driver.h"


class ButtonDriver : public Driver {
    private:
    
    bool lastState;
    float stateAvg;
    int pin;
    EventsDriver events;
    bool pullup;

    void tick() {
        if (digitalRead(pin))
            stateAvg = (stateAvg + 1) / 2;
        else
            stateAvg /= 2;
    }


    public:
    
    ButtonDriver(EventsDriver events, int pin, bool pullup = false) {
        this->pin = pin;
        this->events = events;
        this->pullup = pullup;
        this->stateAvg = 0.5;
        this->lastState = LOW;
    }

    void init() {
        pinMode(pin, pullup ? INPUT_PULLUP : INPUT);
        lastState = digitalRead(pin);
    }

    bool getState() {
        if (stateAvg > 0.74) {
            lastState = HIGH;
            return HIGH;
        }
        if (stateAvg < 0.26) {
            lastState = LOW;
            return LOW;
        }
        return lastState;
    }
};
