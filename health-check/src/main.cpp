#include <Arduino.h>


#include <credentials.h>
#include <defines.h>

#include <Dusk2Dawn.h>

#include <LEDs.h>
#include <Wifi.h>
#include <NTPTime.h>
#include <Layout.h>
#include <Renderer.h>
#include <TimezoneTime.h>
#include <Brightness.h>

Wifi wifi;

Timezone timezone(WINTER_TIME, SUMMER_TIME);
NTPTime timezoneTime(timezone);
Dusk2Dawn solarCalculator(LATITUDE, LONGITUDE, timezoneTime.getOffset());

LEDs leds;
Layout layout;
Brightness brightness(timezoneTime, FULL_BRIGHTNESS, NIGHT_BRIGHTNESS);
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

    brightness.setSolarTime(solarCalculator);
    leds.setBrightness(brightness.getBrightness());
    renderer.render(timezoneTime);

    delay(10 * 1000);
}
