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

#define STEPPER_SPEED 500
#define FADDING_COLOR 0x35FF00
#define FADDING_DELAY 50
#define TAKE_COLOR 0xFF0000
#define TAKE_BLINK_DELAY 500
#define TURN_COLOR 0xFFFFFF
#define TURN_DELAY 10
#define OK_COLOR 0x0000FF
#define OK_WAIT_DELAY 5000
#define OK_BLINK_DELAY 250


bool state = true; // True = mode attente, false = mode statuette
bool initialized = false; // Dit si l'état actuel est initialisé ou pas
Adafruit_NeoPixel ledStrip = Adafruit_NeoPixel(16, PIN_LEDSTRIP_INNER, NEO_RGB + NEO_KHZ800);
int brightness; // Fadding purpose
bool dir; // Savoir dans quelle direction faire varier la brightness
Servo right_servo;
Servo left_servo;
int led = 0; // Pour l'animation de rotation

const int stepper_pins[] = {PIN_MOTOR_A, PIN_MOTOR_B, PIN_MOTOR_C, PIN_MOTOR_D};
const bool stepper_steps[8][4] = {
    {HIGH, LOW , LOW , LOW },
    {HIGH, LOW , HIGH, LOW },
    {LOW , LOW , HIGH, LOW },
    {LOW , HIGH, HIGH, LOW },
    {LOW , HIGH, LOW , LOW },
    {LOW , HIGH, LOW , HIGH},
    {LOW , LOW , LOW , HIGH},
    {HIGH, LOW , LOW , HIGH}
};
int stepper_current_step = 0;


void stepper_write_step(const bool* states) {
    for (int i = 4; i--;)
        digitalWrite(stepper_pins[i], states[i]);
}

void stepper_write_all(bool state) {
    for (int i = 4; i--;)
        digitalWrite(stepper_pins[i], state);
}

  
void setup() {
  ledStrip.begin();
  ledStrip.setBrightness(255);

  right_servo.attach(PIN_SERVO_RIGHT);
  left_servo.attach(PIN_SERVO_LEFT);

  Serial.begin(115200);

  for (int i = 4; i-- > 0;)
    pinMode(stepper_pins[i], OUTPUT);
  stepper_write_all(LOW);
}


void loop() {
  if (state) {
    stepper_write_all(LOW);

    if (!initialized) {
      brightness = 10;
      dir = true;
      ledStrip.show();
      right_servo.write(20);
      left_servo.write(180-20);
      initialized = true;

      // On vérifie que la vitrine soit vide avant d'attendre qu'on la remplisse
      bool on = true;
      while (digitalRead(PIN_SENSOR_LEFT) == HIGH || digitalRead(PIN_SENSOR_RIGHT) == HIGH) {
        ledStrip.fill(on ? TAKE_COLOR : 0x000000, 0, 16);
        ledStrip.show();
        delay(TAKE_BLINK_DELAY);
        on = !on;
      }

      ledStrip.fill(FADDING_COLOR, 0, ledStrip.numPixels());
      
    } else {
      // Animation des LEDs
      ledStrip.setBrightness(brightness);
      
      if (dir) {
        brightness = brightness + 5;
        if (brightness >= 255) {
          dir = false;
        }
      } else {
        brightness = brightness - 5;
        if (brightness <= 5) {
          dir = true;
        }
      }

      ledStrip.show();

      // Détection du changement d'état
      if (digitalRead(PIN_SENSOR_LEFT) == HIGH || digitalRead(PIN_SENSOR_RIGHT) == HIGH) {
        initialized = false;
        state = false;
      }

      // Délai
      delay(FADDING_DELAY);
    }
  } else {
    if (!initialized) {
      stepper_write_all(LOW);

      int i = 0;
      ledStrip.setBrightness(255);
      bool on = true;
      while (i * OK_BLINK_DELAY <= OK_WAIT_DELAY)
      {
        ledStrip.fill(on ? OK_COLOR : 0x000000, 0, ledStrip.numPixels());
        ledStrip.show();
        delay(OK_BLINK_DELAY);
        i++;
        on = !on;
      }
      ledStrip.fill(0x000000, 0, ledStrip.numPixels());
      dir = true;
      ledStrip.show();
      right_servo.write(110);
      left_servo.write(180-110);
      initialized = true;
      
    } else {

      // Animation des LEDs
      ledStrip.setPixelColor(led, 0x000000);
      led = (led+1) % 16;
      ledStrip.setPixelColor(led, TURN_COLOR);

      ledStrip.show();

      // Animation du stepper
      stepper_write_step(stepper_steps[stepper_current_step]);
      stepper_current_step++;
      if (stepper_current_step >= 8)
        stepper_current_step = 0;

      // Détection du changement d'état
      if (digitalRead(PIN_BTN_MOVE) == HIGH || digitalRead(PIN_SENSOR_LEFT) == LOW && digitalRead(PIN_SENSOR_RIGHT) == LOW ) {
        initialized = false;
        state = true;
      }

      // Délai
      delay(TURN_DELAY);
    }
  }
}
