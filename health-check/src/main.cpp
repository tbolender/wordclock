#include <Arduino.h>

#include <led.h>


void setup() {
    // Sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(3000);

    setupLed();
}

void loop() {
    loopLed();

    delay(1000);
}
