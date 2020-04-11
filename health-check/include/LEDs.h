#ifndef WORDCLOCK_LEDS_H
#define WORDCLOCK_LEDS_H

#include <defines.h>
#include <FastLED.h>

#define LED_DATA_PIN D4

class LEDs {
protected:
    CRGB leds[NUM_LEDS];

public:
    LEDs();
    virtual ~LEDs();

    void setup();

    void setBrightness(uint8_t brightness);

    CRGB& operator[](int index);

    void show();
    void clear();
};

#endif //WORDCLOCK_LEDS_H
