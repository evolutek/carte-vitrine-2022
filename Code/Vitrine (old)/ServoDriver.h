#pragma once

#include "Driver.h"

#include <Servo.h>


class ServoDriver : public Driver {
    private:

    Servo servo;
    int pin;
    EventsDriver *events;
    int currentPulseWidth;
    int targetPulseWidth;
    int speed; // pulse width microseconds per tick (variation of 'currentPulseWidth' every 'updateInterval' ms)
    int minPulseWidth;
    int maxPulseWidth;
    int maxAngle;
    int updateInterval;

    static void tick(void* data) {
        ServoDriver* self = (ServoDriver*) data;
        if (self->currentPulseWidth != self->targetPulseWidth) {
            if (self->currentPulseWidth < self->targetPulseWidth) {
                self->currentPulseWidth += self->speed;
                if (self->currentPulseWidth > self->targetPulseWidth)
                    self->currentPulseWidth = self->targetPulseWidth;
            } else {
                self->currentPulseWidth -= self->speed;
                if (self->currentPulseWidth < self->targetPulseWidth)
                    self->currentPulseWidth = self->targetPulseWidth;
            }
            self->servo.writeMicroseconds(self->currentPulseWidth);
        }
    }


    public:

    ServoDriver(EventsDriver &events, int pin, int maxAngle = 180, int minPulseWidth = MIN_PULSE_WIDTH, int maxPulseWidth = MAX_PULSE_WIDTH) {
        this->events = &events;
        this->pin = pin;
        this->minPulseWidth = minPulseWidth;
        this->maxPulseWidth = maxPulseWidth;
        this->maxAngle = maxAngle;
        this->updateInterval = 8;
        this->currentPulseWidth = (minPulseWidth + maxPulseWidth) / 2;
        this->targetPulseWidth = this->currentPulseWidth;
        this->setSpeed(30); // Set a default speed
    }

    // The unit is RPM
    void setSpeed(int newSpeed) {
        speed = newSpeed * 360 * updateInterval * (maxPulseWidth - minPulseWidth) / (60000 * maxAngle);
    }

    void init() {
        servo.attach(pin);
        servo.writeMicroseconds(targetPulseWidth);
        this->events->addEvent(ServoDriver::tick, this, updateInterval, false);
    }

    // Set the angle in degree
    void setAngle(int angle) {
        targetPulseWidth = map(angle, 0, maxAngle, minPulseWidth, maxPulseWidth);
    }

    // Set the duty cycle width (pulse width) in microseconds
    // same as https://www.arduino.cc/reference/en/libraries/servo/writemicroseconds/
    void setPulseWidth(int micros) {
        targetPulseWidth = micros;
    }
};
