#include <Brightness.h>

Brightness::Brightness(Time& time,
        uint8_t dayBrightness,
        uint8_t nightBrightness)
        : time(time) {
    this->nightBrightness = nightBrightness;
    this->dayBrightness = dayBrightness;

    setSunrise(8 * 60);
    setSunset(18 * 60);
}

void Brightness::setSunrise(int sunriseMinutes) {
    this->sunriseMin = sunriseMinutes;
}

void Brightness::setSunset(int sunsetMinutes) {
    this->sunsetMin = sunsetMinutes;
}

void Brightness::setSolarTime(Dusk2Dawn& calculator) {
    setSunrise(calculator.sunrise(time.getYear(), time.getMonth(), time.getDay(), time.isDaylightSavingActive()));
    setSunset(calculator.sunset(time.getYear(), time.getMonth(), time.getDay(), time.isDaylightSavingActive()));
}

uint8_t Brightness::getBrightness() {
    int currentMin = time.getHours() * 60 + time.getMinutes();

    if(currentMin < sunriseMin) {
        return nightBrightness;
    }
    else if(currentMin < sunsetMin) {
        return dayBrightness;
    }
    return nightBrightness;
}
