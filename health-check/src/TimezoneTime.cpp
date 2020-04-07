#include <TimezoneTime.h>

TimezoneTime::TimezoneTime(Time& utcTime, Timezone& timezone) : utcTime(utcTime), timezone(timezone) {
}

TimezoneTime::~TimezoneTime() = default;

void TimezoneTime::setup() {
    utcTime.setup();
}

int TimezoneTime::getSeconds() {
    return second(getEpochTime());
}

int TimezoneTime::getMinutes() {
    return minute(getEpochTime());
}

int TimezoneTime::getHours() {
    return hour(getEpochTime());
}

int TimezoneTime::getDay() {
    return day(getEpochTime());
}

int TimezoneTime::getMonth() {
    return month(getEpochTime());
}

int TimezoneTime::getYear() {
    return year(getEpochTime());
}

time_t TimezoneTime::getEpochTime() {
    return timezone.toLocal(utcTime.getEpochTime());
}

bool TimezoneTime::isDaylightSavingActive() {
    return timezone.utcIsDST(utcTime.getEpochTime());
}

float TimezoneTime::getOffset() {
    return (getEpochTime() - utcTime.getEpochTime()) / (60.0f * 60.0f);
}

bool TimezoneTime::updateIfNecessary() {
    return utcTime.updateIfNecessary();
}

String TimezoneTime::getFormattedTime() {
    return utcTime.getFormattedTime();
}
