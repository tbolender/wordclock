#include <wifi.h>

#include <defines.h>

#include <ESP8266WiFi.h>

void setupWifi() {
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    while(WiFi.status() != WL_CONNECTED) {
        delay(500);
    }
}
