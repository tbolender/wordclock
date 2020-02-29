#include <Wifi.h>

#include <ESP8266WiFi.h>

void Wifi::connect(const char* ssid, const char* passphrase) {
    WiFi.begin(ssid, passphrase);
}

bool Wifi::isConnected() const {
    return WiFi.status() == WL_CONNECTED;
}
