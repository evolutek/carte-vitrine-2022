#pragma once

#include "Test.h"

class LedTest : public Test {
    private:

    const int* pins;
    int nb_pins;
    int current_led_id;
    EventsDriver* events;

    static void tick(void* data) {
        LedTest* self = (LedTest*) data;
        digitalWrite(self->pins[self->current_led_id], LOW);
        self->current_led_id++;
        if (self->current_led_id >= self->nb_pins)
            self->current_led_id = 0;
        digitalWrite(self->pins[self->current_led_id], HIGH);
    }


    public:

    LedTest(EventsDriver &events, int nb_pins, const int* pins) {
        this->pins = pins;
        this->nb_pins = nb_pins;
        this->current_led_id = 0;
        this->events = &events;
    }

    void setup() {
        for (int i = 0; i < this->nb_pins; i++)
            pinMode(this->pins[i], OUTPUT);
        digitalWrite(this->pins[0], HIGH);
        events->addEvent(LedTest::tick, this, 600, false);
    }

    void loop() {
        ;
    }
};
