#pragma once

#include "Defines.h"
#include "Utils.h"


EventsDriver events;

LedStripDriver LedRing_l(events, PIN_LEDSTRIP_INNER, NUMBER_LEDRINGL);
LedStripDriver LedRing_b(events, PIN_LEDSTRIP_OUTER, NUMBER_LEDRINGB);

ServoDriver ServoL(events, PIN_SERVO_LEFT);
ServoDriver ServoR(events, PIN_SERVO_RIGHT);

ButtonDriver btn(events, PIN_BTN_MOVE);

// Sensor act in the same way than a button (sensibility is configured physically)
ButtonDriver Sensor1(events, PIN_SENSOR_LEFT);
ButtonDriver Sensor2(events, PIN_SENSOR_RIGHT);

StepMotorDriver motor(events, MOTOR_NB_STEPS, PIN_MOTOR_A, PIN_MOTOR_B, PIN_MOTOR_C, PIN_MOTOR_D);


void mainSetup() 
{
  ServoL.init();
  ServoR.init();
  
  LedRing_l.init();
  LedRing_b.init();
  
  btn.init();
  
  Sensor1.init();
  Sensor2.init();
  
  motor.init();
}


void mainLoop() 
{
  // Process events (i.e. trigger event that need to be triggered)
  events.processEvents();

  int State_Vitrine = door_gestion();
  
  if (State_Vitrine == 0)
  {
    action_motor();
    action_leddown();
  }  
  else
  {
    action_ledup();
    action_motor_stop();
  }
}



int door_gestion()
{
  static int State_Vitrine = 0;
  int Is_Push = 0;
  int Is_Inplace = 0;
  static int Out = 0;
  static int Can_Move = 1;
  
  
  //BTN
  if (btn.getState() == HIGH)
  {
    Is_Push = 1;
  }
  
  
  //DETECTOR OF STATUE
  if (Sensor1.getState() == HIGH)
  {
    Out = 1;
  }
  if (Sensor2.getState() == HIGH)
  {
    Out = Out && 1;
  }
  else
  {
    Out = 0;
  }
  
  if (Out)
  {
    digitalWrite(PIN_LED_STATUE, LOW);
  }
  
  if (Sensor1.getState() == HIGH)
  {
    Is_Inplace = 1;
    digitalWrite(PIN_LED_STATUE, HIGH);
  }
  if (Sensor2.getState() == HIGH)
  {
    Is_Inplace = 1;
    digitalWrite(PIN_LED_STATUE, HIGH);
  }
  
  if (Out && Is_Inplace)
  {
    Can_Move = 1;
    Out = 0;
  }
  
  
  // Vitrine en bas
  if (State_Vitrine == 0) 
  {
    digitalWrite(PIN_LED_DOWN, HIGH);
    digitalWrite(PIN_LED_UP, LOW);
    
    if (Is_Push)
    {
      ServoL.setAngle(LEFT_SERVO_LOW_ANGLE);
      ServoR.setAngle(RIGHT_SERVO_LOW_ANGLE);
      State_Vitrine = 1;
      Can_Move = 0;
    }
  }
  
  else // Vitrine en haut
  {
    digitalWrite(PIN_LED_DOWN, LOW);
    digitalWrite(PIN_LED_UP, HIGH);
    
    if (Is_Push || Can_Move)
    {
      ServoL.setAngle(LEFT_SERVO_HIGH_ANGLE);
      ServoR.setAngle(RIGHT_SERVO_HIGH_ANGLE);
      State_Vitrine = 0;
    }
  }
  
  return State_Vitrine;
}



void action_motor()
{
  motor.start();
}

void action_motor_stop()
{
  motor.stop();
}



void action_ledup()
{
  static int d1 = 0;
  static int d2 = 1;
  
  LedRing_l.setAllColor(0xFF0000); // 0xFF0000 is red
  LedRing_b.setAllColor(0xFF0000); // 0xFF0000 is red
  
  LedRing_b.update();
  LedRing_l.update();
  
  d1 = (d1+1)%2;
  d2 = (d2+1)%2;
}



void action_leddown()
{
  static int i = 0;
    
  LedRing_l.setAllColor(0xFFFFFF); // 0xFFFFFF is white
  LedRing_b.setLedColor(i, 0xFFFFFF); // 0xFFFFFF is white
   
  i = (i+1)%NUMBER_LEDRINGB;
  
  LedRing_b.update();
  LedRing_l.update();  
}
