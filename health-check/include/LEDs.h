#ifndef HEALTH_CHECK_LEDS_H
#define HEALTH_CHECK_LEDS_H

#include <FastLED.h>
#include <NTP.h>

#define NUM_LEDS 114
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
};

#endif //HEALTH_CHECK_LEDS_H
