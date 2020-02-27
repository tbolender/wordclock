#ifndef HEALTH_CHECK_NTP_H
#define HEALTH_CHECK_NTP_H

#include <NTPClient.h>
#include <WiFiUdp.h>


class NTP {
protected:
    WiFiUDP wifi;
    NTPClient client;
public:
    NTP();
    ~NTP();

    void setup();

    int getHours();

    int getMinutes();

    int getSeconds();

    void updateIfNecessary();
};

#endif //HEALTH_CHECK_NTP_H
