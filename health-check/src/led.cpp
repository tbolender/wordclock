#include <led.h>

CRGB leds[NUM_LEDS];
int brightness = 10;
int row = 9;

void setupLed() {
    FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(brightness);

    // Disable all leds
    for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB::Black;
    }
    FastLED.show();
}

void setMinutes(int second) {
    second %= 5;
    leds[0] = second > 0 ? CRGB::White : CRGB::Black;
    leds[111] = second > 1 ? CRGB::White : CRGB::Black;
    leds[112] = second > 2 ? CRGB::White : CRGB::Black;
    leds[113] = second > 3 ? CRGB::White : CRGB::Black;
}

void setTime() {
    // Set row
    for(int i = 1 + row*11; i < 1 + 11 + row*11; i++)
        leds[i] = CRGB::Black;
    row = ++row % 10;
    for(int i = 1 + row*11; i < 1 + 11 + row*11; i++)
        leds[i] = CRGB::White;

    // Increase brightness
    FastLED.setBrightness(brightness);
    brightness = (brightness + 10) % 200 + 10;

    // Flush
    FastLED.show();
}
