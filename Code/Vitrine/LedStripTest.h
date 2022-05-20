#pragma once

#include <Adafruit_NeoPixel.h>

#include "Test.h"

#define INCRESS 0
#define DECRESS 1


class LedStripTest : public Test {
    private:

    Adafruit_NeoPixel inner_ring;
    
    int32_t colors[3];
    int32_t maxs[3];

    int32_t brightness;
    int32_t brightness_step;
    int32_t brightness_dir;
    
    int32_t tint;
    int32_t tint_step_base;
    int32_t tint_step_multiplier; // Incress the step with the brithness

    EventsDriver *events;

    static void tick(void* data) {
      LedStripTest* self = (LedStripTest*) data;

      self->setOverallColor(self->colors[0], self->colors[1], self->colors[2]);
      
      //Serial.print("R: ");
      //Serial.print(colors[0]);
      //Serial.print("G: ");
      //Serial.print(colors[1]);
      //Serial.print("B: ");
      //Serial.println(colors[2]);
      
      self->nextColor();
    }


    public:

    LedStripTest(EventsDriver &events, int inner_ring_pin, int inner_ring_len) 
        : inner_ring(inner_ring_len, inner_ring_pin, NEO_RGB + NEO_KHZ800) {
      this->events = &events;

      colors[0] = 0;
      colors[1] = 0;
      colors[2] = 0;
      
      maxs[0] = 255;
      maxs[1] = 255;
      maxs[2] = 255;
  
      brightness = 0;
      brightness_step = 15;
      brightness_dir = INCRESS;
      
      tint = 1;
      tint_step_base = 5;
      tint_step_multiplier = 30; // Incress the step with the brithness
    }

    int fromRGB(byte r, byte g, byte b) {
      return (r << 16) | (g << 8) | b;
    }

    void setup() {
      inner_ring.begin();
      inner_ring.setBrightness(255);
      events->addEvent(LedStripTest::tick, this, 50, false);
    }

    void setOverallColor(byte r, byte g, byte b) {
      inner_ring.fill(fromRGB(r, g, b), 0, inner_ring.numPixels());
      inner_ring.show();
    }

    void changeBrightness() {
      if (brightness_dir == INCRESS) {
        brightness += brightness_step;
        if (brightness >= 255) {
          brightness = 255;
          brightness_dir = DECRESS;
        }
      } else {
        brightness -= brightness_step;
        if (brightness <= 0) {
          brightness = 0;
          brightness_dir = INCRESS;
        }
      }
    }

    void changeTint() {
      int32_t tint_step = tint_step_base + tint_step_multiplier * brightness / 256;
      tint += tint_step;
      if (tint >= 768)
        tint = 0;
    }

    int clamp(int v, int minv, int maxv) {
      if (v < minv) return minv;
      if (v > maxv) return maxv;
      return v;
    }

    void nextColor() {
      changeTint();

      if (tint == 0)
        changeBrightness();
  
      int32_t rb = brightness * maxs[0] / 256;
      int32_t gb = brightness * maxs[1] / 256;
      int32_t bb = brightness * maxs[2] / 256;
    
      if (tint <= 256) {
        colors[0] = rb + (maxs[0] - rb) * (256 - tint) / 256;
        colors[1] = gb + (maxs[1] - gb) * (tint      ) / 256;
        colors[2] = bb;
      } else if (tint <= 512) {
        colors[0] = rb;
        colors[1] = gb + (maxs[1] - gb) * (512 - tint) / 256;
        colors[2] = bb + (maxs[2] - bb) * (tint - 256) / 256;
      } else {
        colors[0] = rb + (maxs[0] - rb) * (tint - 512) / 256;
        colors[1] = gb;
        colors[2] = bb + (maxs[2] - bb) * (768 - tint) / 256;
      }

      colors[0] = clamp(colors[0], 0, 255);
      colors[1] = clamp(colors[1], 0, 255);
      colors[2] = clamp(colors[2], 0, 255);
    }

  void loop() {
    ;
  }
};
