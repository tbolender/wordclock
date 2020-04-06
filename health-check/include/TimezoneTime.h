#ifndef WORDCLOCK_TIMEZONE_TIME_H
#define WORDCLOCK_TIMEZONE_TIME_H

#include <Arduino.h>
#include <Time.h>
#include <Timezone.h>

class TimezoneTime : public Time {
protected:
    Time& utcTime;
    Timezone& timezone;

public:
    TimezoneTime(Time& utcTime, Timezone& timezone);
    ~TimezoneTime() override;

    void setup() override;

    int getSeconds() override;

    int getMinutes() override;

    int getHours() override;

    int getDay() override;

    int getMonth() override;

    int getYear() override;

    time_t getEpochTime() override;

    bool updateIfNecessary() override;

    String getFormattedTime() override;
};

#endif //WORDCLOCK_TIMEZONE_TIME_H
