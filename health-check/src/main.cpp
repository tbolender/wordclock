#include <Arduino.h>

#include <led.h>
#include <wifi.h>
#include <ntp.h>

#include <Wire.h>

bool error = true;
bool errorShow = false;

NTP ntp;

void setup() {
    Serial.begin(74880);

    // Sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(3000);

    Serial.println("Connecting...");
    setupWifi();
    Serial.println("Connected!");

    ntp.setup();
    setupLed();
}

void loop() {
    ntp.updateIfNecessary();

    Serial.print(ntp.getHours());
    Serial.print(":");
    Serial.print(ntp.getMinutes());
    Serial.print(":");
    Serial.print(ntp.getSeconds());
    Serial.println();

    setMinutes(ntp.getSeconds());
    setTime();

    delay(1000);
}
