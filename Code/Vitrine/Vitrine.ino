#include "ServoTest.h"
#include "StepMotorTest.h"
#include "LedStripTest.h"


// Pins definitions

#define PIN_LED_ONBOARD 13
#define PIN_LED_DETECT 12
#define PIN_LED_UP 2
#define PIN_LED_DOWN 8

#define PIN_STEP_MOTOR_A 7
#define PIN_STEP_MOTOR_B 5
#define PIN_STEP_MOTOR_C 6
#define PIN_STEP_MOTOR_D 4

#define PIN_SENSOR_LEFT A0
#define PIN_SENSOR_RIGHT A1

#define PIN_BTN_MOVE A2

#define PIN_LEDSTRIP_INNER 3
#define PIN_LEDSTRIP_OUTER 9

#define PIN_SERVO_LEFT 11
#define PIN_SERVO_RIGHT 10



// Other parameters

#define SERIAL_BAUDRATE 115200
#define MOTOR_SPEED 30 // RPMs
#define MOTOR_NB_STEPS 8


//const int PINS[] = {PIN_LED_ONBOARD, PIN_LED_DETECT, PIN_LED_UP, PIN_LED_DOWN};
//const int NB_PINS = 4;

/*
 * Angle des Servo moteur : 58 - 155 (bas - haut)
 */


StepMotorTest stepMotorTest(PIN_STEP_MOTOR_A, PIN_STEP_MOTOR_B, PIN_STEP_MOTOR_C, PIN_STEP_MOTOR_D);
ServoTest servoTest(PIN_SERVO_LEFT, PIN_SERVO_RIGHT, 58, 155);
LedStripTest ledStripTest(PIN_LEDSTRIP_INNER, 16);


Test *tests[] = {/*&stepMotorTest,*/ &ledStripTest/*, &servoTest*/};
const int tests_len = sizeof(tests) / sizeof(Test*);


void setup() 
{
  Serial.begin(SERIAL_BAUDRATE);
  for (int i = 0; i < tests_len; i++) {
    tests[i]->setup();
  }
}


void loop() 
{
  for (int i = 0; i < tests_len; i++) {
    tests[i]->loop();
  }
}
