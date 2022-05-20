#include "Utils.h"
#include "Defines.h"


const int LEDS_PINS[] = {PIN_LED_ONBOARD, PIN_LED_STATUE, PIN_LED_UP, PIN_LED_DOWN};


// Angle des Servo moteur : 58 - 155 (bas - haut)

EventsDriver events;

ServoTest doorTest(events, PIN_SERVO_LEFT, PIN_SERVO_RIGHT, 58, 155);
StepMotorTest boardTest(events, PIN_MOTOR_A, PIN_MOTOR_B, PIN_MOTOR_C, PIN_MOTOR_D);
LedStripTest ledStripTest(events, PIN_LEDSTRIP_INNER, 16);
LedTest ledTest(events, 4, LEDS_PINS);
ButtonTest btnTest(events, PIN_BTN_MOVE);


Test *tests[] = {&ledStripTest, &ledTest, &doorTest, &boardTest, &btnTest};
const int testsLen = sizeof(tests) / sizeof(Test*);


void testSetup() 
{
    Serial.begin(SERIAL_BAUDRATE);
    for (int i = 0; i < testsLen; i++) {
        tests[i]->setup();
    }
}


void testLoop()
{
    events.processEvents();
    for (int i = 0; i < testsLen; i++) {
        tests[i]->loop();
    }
}
