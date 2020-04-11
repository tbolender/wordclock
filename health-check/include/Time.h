#ifndef WORDCLOCK_TIME_H
#define WORDCLOCK_TIME_H

#include <Arduino.h>

class Time {
public:
    virtual ~Time() = default;

    virtual void setup() = 0;

    virtual int getSeconds();

    virtual int getMinutes();

    virtual int getHours();

    virtual int getDay();

    virtual int getMonth();

    virtual int getYear();

    virtual time_t getEpochTime() = 0;

    virtual bool updateIfNecessary() = 0;

    virtual bool isDaylightSavingActive() = 0;

    virtual float getOffset() = 0;

    virtual String getFormattedTime();
};

#endif //WORDCLOCK_TIME_H
