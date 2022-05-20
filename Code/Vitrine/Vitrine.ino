#include "Utils.h"
#include "Defines.h"


const int LEDS_PINS[] = {PIN_LED_ONBOARD, PIN_LED_DETECT, PIN_LED_UP, PIN_LED_DOWN};


// Angle des Servo moteur : 58 - 155 (bas - haut)

EventsDriver events;

//StepMotorTest boardTest(events, PIN_STEP_MOTOR_A, PIN_STEP_MOTOR_B, PIN_STEP_MOTOR_C, PIN_STEP_MOTOR_D);
//ServoTest doorTest(events, PIN_SERVO_LEFT, PIN_SERVO_RIGHT, 58, 155);
//LedStripTest ledStripTest(events, PIN_LEDSTRIP_INNER, 16);
LedTest ledTest(events, 4, LEDS_PINS);


Test *tests[] = {/*&boardTest, &ledStripTest, &doorTest, */&ledTest};
const int testsLen = sizeof(tests) / sizeof(Test*);


void setup() 
{
    Serial.begin(SERIAL_BAUDRATE);
    for (int i = 0; i < testsLen; i++) {
        tests[i]->setup();
    }
}


void loop() 
{
    events.processEvents();
    /*for (int i = 0; i < testsLen; i++) {
        tests[i]->loop();
    }*/
}
