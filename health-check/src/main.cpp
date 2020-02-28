#include <Arduino.h>

#include <LEDs.h>
#include <Wifi.h>
#include <NTP.h>

NTP ntp;
LEDs leds;

void setup() {
    Serial.begin(74880);

    // Sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(3000);

    Serial.println("Connecting...");
    setupWifi();
    Serial.println("Connected!");

    ntp.setup();
    leds.setup();
}

void loop() {
    ntp.updateIfNecessary();

    Serial.print(ntp.getHours());
    Serial.print(":");
    Serial.print(ntp.getMinutes());
    Serial.print(":");
    Serial.print(ntp.getSeconds());
    Serial.println();

    leds.setTime(ntp);

    delay(1000);
}
