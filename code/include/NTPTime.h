#ifndef WORDCLOCK_NTP_H
#define WORDCLOCK_NTP_H

#include <Time.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <Timezone.h>


class NTPTime : public Time {
protected:
    WiFiUDP wifi;
    NTPClient client;
    Timezone& timezone;

public:
    explicit NTPTime(Timezone& timezone);
    ~NTPTime() override;

    void setup() override;

    time_t getEpochTime() override;

    bool updateIfNecessary() override;

    bool isDaylightSavingActive() override;

    float getOffset() override;

    String getFormattedTime() override;
};

#endif //WORDCLOCK_NTP_H
