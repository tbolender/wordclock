#include <Arduino.h>


#include <credentials.h>
#include <defines.h>

#include <LEDs.h>
#include <Wifi.h>
#include <NTP.h>
#include <Layout.h>
#include <Renderer.h>

Wifi wifi;
NTP ntp;
LEDs leds;
Layout layout;
Renderer renderer(leds, layout);

void connectWifi();

void retrieveTime();

void setup() {
    Serial.begin(74880);

    // Sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(3000);

    leds.setup();
    leds.setBrightness(FULL_BRIGHTNESS);

    connectWifi();

    ntp.setup();
    retrieveTime();

    leds.clear();
}

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

void loop() {
    ntp.updateIfNecessary();

    Serial.println(ntp.getFormattedTime());

    renderer.render(ntp);

    delay(10 * 1000);
}
