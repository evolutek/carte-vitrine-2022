#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#include <Stepper.h>

#define STEPPER_SPEED 500
#define FADDING_COLOR 0x35FF00
#define FADDING_DELAY 50
#define TAKE_COLOR 0xFF0000
#define TAKE_BLINK_DELAY 500
#define TURN_COLOR 0xFFFFFF
#define TURN_DELAY 50
#define OK_COLOR 0x0000FF
#define OK_WAIT_DELAY 5000
#define OK_BLINK_DELAY 250

bool state = true; // True = mode attente, false = mode statuette
bool initialized = false; // Dit si l'état actuel est initialisé ou pas
Adafruit_NeoPixel ledStrip = Adafruit_NeoPixel(16, 3, NEO_RGB + NEO_KHZ800);
int brightness; // Fadding purpose
bool dir; // Savoir dans quelle direction faire varier la brightness
Servo servo_droit; // pin 10
Servo servo_gauche; // pin 11
Stepper stepper(8, 6, 7, 5, 4);
int led = 0; // Pour l'animation de rotation
  
void setup() {
  ledStrip.begin();
  ledStrip.setBrightness(255);
  servo_droit.attach(10);
  servo_gauche.attach(11);
  Serial.begin(9600); // Pour debug
  stepper.setSpeed(500);
}

void loop() {
  if (state) {
    if (!initialized) {

      brightness = 10;
      dir = true;
      ledStrip.show();
      servo_droit.write(20);
      servo_gauche.write(180-20);
      initialized = true;

      // On vérifie que la vitrine soit vide avant d'attendre qu'on la remplisse
      bool on = true;
      while (digitalRead(A0) == HIGH || digitalRead(A1) == HIGH) {
        ledStrip.fill(on ? TAKE_COLOR : 0x000000, 0, 16);
        ledStrip.show();
        delay(TAKE_BLINK_DELAY);
        on = !on;
      }

      ledStrip.fill(FADDING_COLOR, 0, 16);
      
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
      if (digitalRead(A0) == HIGH || digitalRead(A1) == HIGH) {
        initialized = false;
        state = false;
      }

      // Délai
      delay(FADDING_DELAY);
      
      
    }
  } else {
    if (!initialized) {

      int i = 0;
      ledStrip.setBrightness(255);
      bool on = true;
      while (i * OK_BLINK_DELAY <= OK_WAIT_DELAY)
      {
        ledStrip.fill(on ? OK_COLOR : 0x000000, 0, 16);
        ledStrip.show();
        delay(OK_BLINK_DELAY);
        i++;
        on = !on;
      }
      ledStrip.fill(0x000000, 0, 16);
      dir = true;
      ledStrip.show();
      servo_droit.write(110);
      servo_gauche.write(180-110);
      initialized = true;
      
    } else {

      // Animation des LEDs
      ledStrip.setPixelColor(led, 0x000000);
      led = (led+1) % 16;
      ledStrip.setPixelColor(led, TURN_COLOR);

      ledStrip.show();

      // Animation du stepper
      stepper.step(5);

      // Détection du changement d'état
      if (digitalRead(A2) == HIGH || digitalRead(A0) == LOW && digitalRead(A1) == LOW ) {
        initialized = false;
        state = true;
      }

      // Délai
      delay(TURN_DELAY);

    }
  }
}
