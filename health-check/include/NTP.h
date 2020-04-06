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

    int getHours() override;

    int getMinutes() override;

    int getSeconds() override;

    bool updateIfNecessary() override;

    String getFormattedTime() override;
};

#endif //WORDCLOCK_NTP_H
