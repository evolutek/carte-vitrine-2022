#pragma once

#include "Test.h"

class ButtonTest : public Test {
    private:

    ButtonDriver btn;
    EventsDriver *events;

    static void tick(void* data) {
        ButtonTest* self = (ButtonTest*) data;
        if (self->btn.getState() == HIGH) {
          Serial.println("Button pressed");
        }
    }


    public:

    ButtonTest(EventsDriver &events, int pin) : btn(events, pin) {
      this->events = &events;
    }

    void setup() {
      btn.init();
      events->addEvent(ButtonTest::tick, this, 100, false);
    }

    void loop() {
      ;
    }
};
