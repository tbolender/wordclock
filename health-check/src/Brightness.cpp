#include <Brightness.h>
#include <math.h>

Brightness::Brightness(Time& time,
        int transitionMinutes,
        uint8_t dayBrightness,
        uint8_t nightBrightness)
        : time(time) {
    this->nightBrightness = nightBrightness;
    this->dayBrightness = dayBrightness;
    this->transitionMinutes = transitionMinutes / 2;

    setSunrise(8 * 60);
    setSunset(17 * 60);
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

    auto difference = (float)(dayBrightness - nightBrightness);
    if(currentMin < sunriseMin - transitionMinutes) {
        return nightBrightness;
    }
    else if(currentMin < sunriseMin + transitionMinutes) {
        float fraction = min(((float)(currentMin - sunriseMin + transitionMinutes)) / transitionMinutes, 1.f);
        return nightBrightness + (int)(difference * fraction);
    }
    else if(currentMin < sunsetMin - transitionMinutes) {
        return dayBrightness;
    }
    else if(currentMin < sunsetMin + transitionMinutes) {
        float fraction = min(((float)(currentMin - sunsetMin + transitionMinutes)) / transitionMinutes, 1.f);
        return dayBrightness - (int)(difference * fraction);
    }

    return nightBrightness;
}
