#include <Brightness.h>

Brightness::Brightness(TimezoneTime& time,
        Dusk2Dawn& sunPosition,
        uint8_t dayBrightness,
        uint8_t nightBrightness)
        : time(time), sunPosition(sunPosition) {
    this->nightBrightness = nightBrightness;
    this->dayBrightness = dayBrightness;
}

uint8_t Brightness::getCurrentBrightness() {
    return dayBrightness;
}

