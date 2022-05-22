#include <Stepper.h>

int PINS[] = {4, 5, 6, 7};

void setup()
{
  Serial.begin(115200);
  Serial.setTimeout(10);
}


/*
Best pins configuration:
7564
*/


byte buff[125];

void loop()
{
  Serial.println("Begin of tests");
  
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (j != i) {
        for (int k = 0; k < 4; k++) {
          if (k != i && k != j) {
            for (int m = 0; m < 4; m++) {
              if (m != i && m != j && m != k) {
                Stepper stepper(64 * 4, PINS[i], PINS[j], PINS[k], PINS[m]);
                stepper.setSpeed(45);
                
                Serial.print(PINS[i]);
                Serial.print(' ');
                Serial.print(PINS[j]);
                Serial.print(' ');
                Serial.print(PINS[k]);
                Serial.print(' ');
                Serial.println(PINS[m]);

                while (!Serial.available()) {
                  stepper.step(32);
                  Serial.print('.');
                  delay(1);
                }
                Serial.println();

                Serial.readBytes(buff, 125);
              }
            }
          }
        }
      }
    }
  }
}
