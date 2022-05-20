#pragma once

#include "Driver.h"


/*
TB6612:
IN1 IN2 OUT1 OUT2 Mode
1   1   0    0    Short brake
0   1   0    1    CCW
1   0   1    0    CW
0   0   X    X    Stop (high impedance)

Motor connections names in order:
M1, M2, M3, M4

Connections:
AOUT1 -> M1 (+)
AOUT2 -> M3 (+)
BOUT2 -> M2 (+)
BOUT1 -> M4 (+)
Motor common wire -> (-)

Step table:
AIN1 AIN2 BIN1 BIN2
1    0    0    0
1    0    0    1
0    0    0    1
0    1    0    1
0    1    0    0
0    1    1    0
0    0    1    0
1    0    1    0

Free:
AIN1 AIN2 BIN1 BIN2
0    0    0    0

Brake:
AIN1 AIN2 BIN1 BIN2
1    1    1    1
*/


const bool _steps[8][4] = {
    {HIGH, LOW , LOW , LOW },
    {HIGH, LOW , HIGH, LOW },
    {LOW , LOW , HIGH, LOW },
    {LOW , HIGH, HIGH, LOW },
    {LOW , HIGH, LOW , LOW },
    {LOW , HIGH, LOW , HIGH},
    {LOW , LOW , LOW , HIGH},
    {HIGH, LOW , LOW , HIGH}
};
const int _stepsLen = 8;



class StepMotorDriver : public Driver {
    private:

    int _stepsPerRotation;
    int _currentStep;
    int _pins[4];
    int _pinsLen;
    bool _motorEnabled;
    int _remainingSteps;
    int _speed;
    int _timeout; // The maximum power on time for a pin (to avoid burning the motor)
    int _stepInterval; // Delay between each step
    int _freeDelay; // Delay before calling free (0 disable the call to free)

    void _writeStep(const bool* stats) {
        for (int i = _pinsLen; i--;)
            digitalWrite(_pins[i], stats[i]);
    }

    void _writeAll(bool stat) {
        for (int i = _pinsLen; i--;)
            digitalWrite(_pins[i], stat);
    }


    public:

    StepMotorDriver(int stepsPerRotation, int pinA, int pinB, int pinC, int pinD) {
        this->_stepsPerRotation = stepsPerRotation;
        this->_pins[0] = pinA;
        this->_pins[1] = pinB;
        this->_pins[2] = pinC;
        this->_pins[3] = pinD;
        this->_currentStep = 0;
        this->_remainingSteps = 0;
        this->_motorEnabled = false;
        this->_pinsLen = 4;
        this->_timeout = 10;
        this->setSpeed(5);
    }

    // Set the speed in RPM
    void setSpeed(int speed) {
        this->_speed = speed;
        this->_stepInterval = 60000 / (this->_stepsPerRotation * speed);
        if (this->_stepInterval > this->_timeout) {
            this->_freeDelay = this->_timeout;
            this->_stepInterval -= this->_timeout;
        } else {
            this->_freeDelay = 0;
        }
    }

    void enable() {
        _motorEnabled = true;
    }

    void disable() {
        _motorEnabled = false;
        _remainingSteps = 0;
    }

    void free() {
        _writeAll(LOW);
    }

    void brake() {
        _writeAll(HIGH);
    }

    void init() {
        for (int i = _pinsLen; i--;) {
            pinMode(_pins[i], OUTPUT);
            digitalWrite(_pins[i], LOW);
        }
    }

    void steps(int nbSteps) {
        _motorEnabled = false;
        _remainingSteps = nbSteps;
        while(_remainingSteps--) {
            step();
            if (_freeDelay > 0) {
                delay(_freeDelay);
                free();
            }
            delay(_stepInterval);
        }
        free();
    }

    void step() {
        _writeStep(_steps[_currentStep]);
        _currentStep++;
        if (_currentStep >= _stepsLen)
            _currentStep = 0;
    }
};
