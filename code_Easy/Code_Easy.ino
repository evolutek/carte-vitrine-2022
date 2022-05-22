#include <Adafruit_NeoPixel.h>
#include <Servo.h> 


// Pins definitions

#define PIN_LED_ONBOARD 12
#define PIN_LED_UP      2
#define PIN_LED_DOWN    8

#define PIN_MOTOR_A 6
#define PIN_MOTOR_B 7
#define PIN_MOTOR_C 5
#define PIN_MOTOR_D 4

#define PIN_SENSOR_LEFT  A0
#define PIN_SENSOR_RIGHT A1

#define PIN_BTN_MOVE A2

#define PIN_LEDSTRIP_INNER 3
#define PIN_LEDSTRIP_OUTER 9

#define PIN_SERVO_LEFT  11
#define PIN_SERVO_RIGHT 10


// Other parameters

#define SENSOR_R_DETECT 100
#define SENSOR_L_DETECT 100

#define MOTOR_SPEED 30 // RPMs  //not use

#define NUMBER_LEDRINGL 16    //Number of led in the Little LedRing, Can Change
#define NUMBER_LEDRINGB 60   //Number of led in the Big LedRing, Can Change

#define SERVO_LOW_ANGLE    155
#define SERVO_HIGH_ANGLE   58

#define TIMELEDANIM 500//Time for led frame(not in seconde), Can Change
#define TIMELEDANIMUP 50//Time for led frame(not in seconde), Can Change
#define WHITE Color(255,255,255)
#define RED Color(255,0,0)

Servo ServoL;
Servo ServoR;

Adafruit_NeoPixel LedRing_l = Adafruit_NeoPixel(NUMBER_LEDRINGL, PIN_LEDSTRIP_INNER, NEO_GRB);
Adafruit_NeoPixel LedRing_b = Adafruit_NeoPixel(NUMBER_LEDRINGB, PIN_LEDSTRIP_OUTER, NEO_GRB);



void setup() 
{
  Serial.begin(9600);
  pinMode(PIN_SERVO_LEFT,OUTPUT);
  pinMode(PIN_SERVO_RIGHT,OUTPUT);
  pinMode(PIN_BTN_MOVE,INPUT_PULLUP);
  
  ServoL.attach(PIN_SERVO_LEFT);
  ServoR.attach(PIN_SERVO_RIGHT);
  
  ServoL.write(SERVO_LOW_ANGLE);
  ServoR.write(180-SERVO_LOW_ANGLE);
  
  LedRing_l.begin();
  LedRing_b.begin();
  LedRing_l.show();
  LedRing_b.show();
  LedRing_l.setBrightness(255);
  LedRing_b.setBrightness(255);
    
 	
  pinMode(PIN_LED_UP,OUTPUT);
  pinMode(PIN_LED_DOWN,OUTPUT);
  pinMode(PIN_LED_ONBOARD, OUTPUT);


  
  pinMode(PIN_SENSOR_RIGHT,INPUT);
  pinMode(PIN_SENSOR_LEFT,INPUT);  
}


void loop() 
{	
  int State_Vitrine = door_gestion();
  
  action_motor(State_Vitrine);
  action_led(State_Vitrine);
}



int door_gestion()
{
  static int State_Vitrine = 1;
  int Is_Push = 0;
  static int Press = 0;
  int Is_Inplace = 0;
  static int Out = 0;
  static int Can_Move = 1;
  
  //BTN
  if (digitalRead(PIN_BTN_MOVE) == HIGH && !Press)
  {
    Is_Push = 1;
    Press = 1;
  }
  if (digitalRead(PIN_BTN_MOVE) == LOW)
  {
    Press = 0;
  }

  if (Is_Push)
  {
    Serial.println("push");
  }
  
  
  //DETECTOR OF STATUE
  if (digitalRead(PIN_SENSOR_LEFT) == LOW)
  {
    Out = 1;
  }
  if (digitalRead(PIN_SENSOR_RIGHT) == LOW)
  {
    Out = Out && 1;
  }
  else
  {
    Out = 0;
  }
  
  if (Out)
  {
    digitalWrite(PIN_LED_ONBOARD, LOW);
  }
  
  if (digitalRead(PIN_SENSOR_LEFT) == HIGH)
  {
    Is_Inplace = 1;
    digitalWrite(PIN_LED_ONBOARD, HIGH);
  }
  if (digitalRead(PIN_SENSOR_RIGHT) == HIGH)
  {
    Is_Inplace = 1;
    digitalWrite(PIN_LED_ONBOARD, HIGH);
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
      Serial.println("bas vers haut");
      ServoL.write(SERVO_LOW_ANGLE);
      ServoR.write(180-SERVO_LOW_ANGLE);
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
      LedRing_l.fill(LedRing_l.RED, 0, NUMBER_LEDRINGL);
      LedRing_l.show();
      delay(2500);
      Serial.println("haut vers bas");
      ServoL.write(SERVO_HIGH_ANGLE);
      ServoR.write(180-SERVO_HIGH_ANGLE);
      State_Vitrine = 0;
    }
  }
  
  return State_Vitrine;
}



void action_motor(int state)
{
  static bool _steps[8][4] = {
    {HIGH, LOW , LOW , LOW },
    {HIGH, LOW , HIGH, LOW },
    {LOW , LOW , HIGH, LOW },
    {LOW , HIGH, HIGH, LOW },
    {LOW , HIGH, LOW , LOW },
    {LOW , HIGH, LOW , HIGH},
    {LOW , LOW , LOW , HIGH},
    {HIGH, LOW , LOW , HIGH}};
  static int _pins[4] = {
    PIN_MOTOR_A, PIN_MOTOR_B, PIN_MOTOR_C, PIN_MOTOR_D};
  static int _pinsLen = 4;
  static int _stepsLen = 8;
  static int _currentStep = 0;

  if (state)
  {
    digitalWrite(PIN_MOTOR_A,HIGH);
    digitalWrite(PIN_MOTOR_B,HIGH);
    digitalWrite(PIN_MOTOR_C,HIGH);
    digitalWrite(PIN_MOTOR_D,HIGH);
  }
  else
  {
    for (int i = _pinsLen; i--;)
    {
      digitalWrite(_pins[i], _steps[_currentStep][i]);
    }
    _currentStep++;
    if (_currentStep >= _stepsLen)
    {
      _currentStep = 0;
    }
  }
}


void action_led(int state)
{
  static int _delay = 0;
  if (_delay <= TIMELEDANIM)
  {
    _delay ++;
  }
  else
  {
    static int i1 = 0;
    static int i2 = NUMBER_LEDRINGB/2;
    LedRing_b.clear();
    LedRing_l.clear();
      
    
    
    LedRing_b.setPixelColor(i2, (state==0 ?LedRing_b.WHITE : LedRing_b.RED));
    LedRing_l.setPixelColor(i1, (state == 0 ? LedRing_l.WHITE : LedRing_l.RED));
     
    i1 = (i1+1)%NUMBER_LEDRINGL;
    i2 = (i2+1)%NUMBER_LEDRINGB;
    
    LedRing_b.show();
    LedRing_l.show(); 
  
    _delay = 0;
  }
   
}

/*
void action_ledup()
{
  static int _delay = 0;
  if (_delay <= TIMELEDANIMUP)
  {
    _delay ++;
  }
  else
  {
    static int d1 = 0;
    static int d2 = 1;
    
    LedRing_b.clear();
    LedRing_l.clear();  
    
    for (int i=d1; i< NUMBER_LEDRINGL; i+=2)
    {
      LedRing_l.setPixelColor(i, LedRing_l.RED);
    }
    
    for (int i=d2; i< NUMBER_LEDRINGB; i+=2)
    {
     	LedRing_b.setPixelColor(i, LedRing_b.RED);
    }
    
    LedRing_b.show();
    LedRing_l.show();
    
    d1 = (d1+1)%2;
    d2 = (d2+1)%2;
  }
}
*/





  
