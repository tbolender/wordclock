#ifndef HEALTH_CHECK_LED_H
#define HEALTH_CHECK_LED_H

#include <FastLED.h>
#include <RTClib.h>


#define NUM_LEDS 114
#define DATA_PIN D4


void setupLed();

void setMinutes(int minute);

void setTime();


#endif //HEALTH_CHECK_LED_H
