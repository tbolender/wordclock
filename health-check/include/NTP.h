#ifndef WORDCLOCK_NTP_H
#define WORDCLOCK_NTP_H

#include <NTPClient.h>
#include <WiFiUdp.h>


class NTP {
protected:
    WiFiUDP wifi;
    NTPClient client;

public:
    NTP();
    virtual ~NTP();

    void setup();

    int getHours();

    int getMinutes();

    int getSeconds();

    void updateIfNecessary();
};

#endif //WORDCLOCK_NTP_H
