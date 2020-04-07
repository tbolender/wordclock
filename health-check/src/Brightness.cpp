#include <Brightness.h>

Brightness::Brightness(TimezoneTime& time, uint8_t dayBrightness, uint8_t nightBrightness) : time(time) {
    this->nightBrightness = nightBrightness;
    this->dayBrightness = dayBrightness;
}

uint8_t Brightness::getCurrentBrightness() {
    return dayBrightness;
}

