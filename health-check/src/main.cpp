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

void setup() {
    Serial.begin(74880);

    // Sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(3000);

    leds.setup();
    leds.setBrightness(FULL_BRIGHTNESS);

    Serial.println("Connecting...");
    wifi.connect(WIFI_SSID, WIFI_PASSWORD);
    while(!wifi.isConnected()) {
        delay(500);
    }
    renderer.showConnected();
    Serial.println("Connected!");

    ntp.setup();
}

void loop() {
    ntp.updateIfNecessary();

    Serial.println(ntp.getFormattedTime());

    renderer.render(ntp);

    delay(10 * 1000);
}
