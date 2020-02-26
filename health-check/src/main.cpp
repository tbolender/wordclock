#include <Arduino.h>

#include <led.h>
#include <timer.h>
#include <Wire.h>

bool error = true;
bool errorShow = false;

void setup() {
    Wire.begin(D0, D5);
    Serial.begin(115200);

    // Sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(3000);

    error = !rtc.begin();

    setupLed();
    setupTimer();
}

void loop() {
    if(error) {
        setMinutes(errorShow ? 4 : 0);
        errorShow = !errorShow;
    }
    else {
        setMinutes(rtc.now().second());
    }
    setTime(rtc.now());

    delay(1000);
}
