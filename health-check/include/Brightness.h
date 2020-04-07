#ifndef HEALTH_CHECK_BRIGHTNESS_H
#define HEALTH_CHECK_BRIGHTNESS_H


#include <TimezoneTime.h>

class Brightness {
protected:
    TimezoneTime& time;
    uint8_t dayBrightness;
    uint8_t nightBrightness;

public:
    Brightness(TimezoneTime& time, uint8_t dayBrightness, uint8_t nightBrightness);

    uint8_t getCurrentBrightness();
};


#endif //HEALTH_CHECK_BRIGHTNESS_H
