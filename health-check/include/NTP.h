#ifndef WORDCLOCK_NTP_H
#define WORDCLOCK_NTP_H

#include <Time.h>
#include <NTPClient.h>
#include <WiFiUdp.h>


class NTP : public Time {
protected:
    WiFiUDP wifi;
    NTPClient client;

public:
    NTP();
    NTP(long offset);
    virtual ~NTP();

    void setup() override;

    int getSeconds() override;

    int getMinutes() override;

    int getHours() override;

    int getDay() override;

    int getMonth() override;

    int getYear() override;

    unsigned long getEpochTime() override;

    bool updateIfNecessary() override;

    String getFormattedTime() override;
};

#endif //WORDCLOCK_NTP_H
