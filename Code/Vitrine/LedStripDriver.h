#pragma once

#include "Driver.h"

#include <Adafruit_NeoPixel.h>


class LedStripDriver : public Driver {
    private:

    Adafruit_NeoPixel ledStrip;


    public:

    LedStripDriver(int pin, int len) {
        ledStrip = Adafruit_NeoPixel(len, pin, NEO_RGB + NEO_KHZ800);
    }

    void init() {
      ledStrip.begin();
      ledStrip.setBrightness(255);
    }

    void setLedColor(int pos, int color) {
        ledStrip.setPixelColor(pos, color);
    }

    void setAllColor(int color) {
        ledStrip.fill(color, 0, ledStrip.numPixels());
    }

    void update() {
        ledStrip.show();
    }

    void enable() {
        ledStrip.setBrightness(255);
        update();
    }

    void disable() {
        ledStrip.setBrightness(0);
        update();
    }
};
