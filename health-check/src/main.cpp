#include <Arduino.h>

#include <led.h>
#include <timer.h>
#include <Wire.h>

bool error = true;
bool errorShow = false;

void setup() {
    Serial.begin(74880);

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
