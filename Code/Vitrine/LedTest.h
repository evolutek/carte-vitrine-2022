#pragma once

#include "Test.h"

class LedTest : public Test {
    private:

    int* pins;
    int nb_pins;
    int current_led_id;


    public:

    LedTest(int nb_pins, int* pins) {
        this->pins = pins;
        this->nb_pins = nb_pins;
        this->current_led_id = 0;
    }

    void setup() {
        for (int i = 0; i < this->nb_pins; i++)
            pinMode(this->pins[i], OUTPUT);
        digitalWrite(this->pins[0], HIGH);
    }

    void loop() {
        delay(1000);
        digitalWrite(this->pins[this->current_led_id], LOW);
        this->current_led_id++;
        if (this->current_led_id >= this->nb_pins)
            this->current_led_id = 0;
        digitalWrite(this->pins[this->current_led_id], HIGH);
    }
};