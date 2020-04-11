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
    int sunriseMin = sunPosition.sunrise(time.getYear(), time.getMonth(), time.getDay(), time.isDaylightSavingActive());
    int sunsetMin = sunPosition.sunset(time.getYear(), time.getMonth(), time.getDay(), time.isDaylightSavingActive());
    int currentMin = time.getHours() * 60 + time.getMinutes();

    if(currentMin < sunriseMin) {
        return nightBrightness;
    }
    else if(currentMin < sunsetMin) {
        return dayBrightness;
    }
    return nightBrightness;
}

