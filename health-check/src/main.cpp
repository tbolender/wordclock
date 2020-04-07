#include <Arduino.h>


#include <credentials.h>
#include <defines.h>

#include <LEDs.h>
#include <Wifi.h>
#include <NTP.h>
#include <Layout.h>
#include <Renderer.h>
#include <TimezoneTime.h>

Wifi wifi;

NTP ntp(TIMEZONE_OFFSET);
Timezone timezone(WINTER_TIME, SUMMER_TIME);
TimezoneTime timezoneTime(ntp, timezone);

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
    while(!timezoneTime.updateIfNecessary()) {
    }
    Serial.println("Found times!");
}

void setup() {
    Serial.begin(74880);

    leds.setup();
    leds.setBrightness(FULL_BRIGHTNESS);

    connectWifi();

    timezoneTime.setup();
    retrieveTime();

    leds.clear();
}

void loop() {
    timezoneTime.updateIfNecessary();

    Serial.println(timezoneTime.getFormattedTime());

    renderer.render(timezoneTime);

    delay(10 * 1000);
}
