#ifndef HEALTH_CHECK_BRIGHTNESS_H
#define HEALTH_CHECK_BRIGHTNESS_H


#include <TimezoneTime.h>
#include <Dusk2Dawn.h>

class Brightness {
protected:
    TimezoneTime& time;
    uint8_t dayBrightness;
    uint8_t nightBrightness;

    int sunriseMin;
    int sunsetMin;

public:
    Brightness(TimezoneTime& time, uint8_t dayBrightness, uint8_t nightBrightness);

    void setSunrise(int sunriseMinutes);
    void setSunset(int sunsetMinutes);

    void setSolarTime(Dusk2Dawn& calculator);

    uint8_t getBrightness();
};


#endif //HEALTH_CHECK_BRIGHTNESS_H
