#include <DummyTime.h>
#include <TimeLib.h>


DummyTime::DummyTime(int year, int month, int day, bool daylightSaving) {
    setTime(0, 0, 0, day, month, year);
    this->dayMinutes = 0;
    this->daylightSaving = daylightSaving;
}

DummyTime::~DummyTime() = default;

void DummyTime::setup() {
}

time_t DummyTime::getEpochTime() {
    return now() + dayMinutes * 60;
}

bool DummyTime::updateIfNecessary() {
    dayMinutes += 5;
    return true;
}

bool DummyTime::isDaylightSavingActive() {
    return daylightSaving;
}

float DummyTime::getOffset() {
    return 120;
}
