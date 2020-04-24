#ifndef WORDCLOCK_WIFI_H
#define WORDCLOCK_WIFI_H

class Wifi {
public:
    void connect(const char* ssid, const char* passphrase);

    bool isConnected() const;
};


#endif //WORDCLOCK_WIFI_H
