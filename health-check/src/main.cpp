#include <Arduino.h>


#include <credentials.h>
#include <defines.h>

#include <LEDs.h>
#include <Wifi.h>
#include <NTP.h>
#include <Layout.h>
#include <Renderer.h>

Wifi wifi;
NTP ntp(TIMEZONE_OFFSET);
LEDs leds;
Layout layout;
Renderer renderer(leds, layout);

void connectWifi() {
    Serial.println("Connecting...");
    wifi.connect(WIFI_SSID, WIFI_PASSWORD);
    while(!wifi.isConnected()) {
        delay(200);
    }
    renderer.showWifiStatus(true);
    Serial.println("Connected!");
}

void retrieveTime() {
    Serial.println("Retrieving time...");
    while(!ntp.updateIfNecessary()) {
    }
    Serial.println("Found times!");
}

void setup() {
    Serial.begin(74880);

    leds.setup();
    leds.setBrightness(FULL_BRIGHTNESS);

    connectWifi();

    ntp.setup();
    retrieveTime();

    leds.clear();
}

void loop() {
    ntp.updateIfNecessary();

    Serial.println(ntp.getFormattedTime());

    renderer.render(ntp);

    delay(10 * 1000);
}
