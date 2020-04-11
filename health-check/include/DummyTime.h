#ifndef WORDCLOCK_DUMMY_TIME_H
#define WORDCLOCK_DUMMY_TIME_H

#include <Time.h>

class DummyTime : public Time {
protected:
    int year;
    int month;
    int day;
    int dayMinutes;

    bool daylightSaving;

public:
    explicit DummyTime(int year, int month, int day, bool daylightSaving);
    ~DummyTime() override;

    void setup() override;

    time_t getEpochTime() override;

    bool updateIfNecessary() override;

    bool isDaylightSavingActive() override;

    float getOffset() override;
};

#endif //WORDCLOCK_DUMMY_TIME_H
