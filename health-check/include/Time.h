#ifndef WORDCLOCK_TIME_H
#define WORDCLOCK_TIME_H

#include <Arduino.h>

class Time {
public:
    virtual ~Time() = default;

    virtual void setup() = 0;

    virtual int getHours() = 0;

    virtual int getMinutes() = 0;

    virtual int getSeconds() = 0;

    virtual bool updateIfNecessary() = 0;

    virtual String getFormattedTime() = 0;
};

#endif //WORDCLOCK_TIME_H
