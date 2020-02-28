#ifndef HEALTH_CHECK_LED_H
#define HEALTH_CHECK_LED_H

#include <FastLED.h>
#include <ntp.h>

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

    void setTime(NTP& ntp);
    void setTime(int hours, int minutes);
};

#endif //HEALTH_CHECK_LED_H
