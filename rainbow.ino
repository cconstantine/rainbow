#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 57

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 7

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
	FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

uint8_t color_pos() {
  static float pos = 0;
  static unsigned long last_tick = millis();
  unsigned long now = millis();
  float delta = 0.1 * (now - last_tick);
  pos += delta;
  last_tick = now;

  if(pos > 255) {
    pos -= 255;
  }
  return (uint8_t)(pos) ;
}


void loop() { 
  fill_rainbow(leds, NUM_LEDS, color_pos());
  FastLED.show();
}
