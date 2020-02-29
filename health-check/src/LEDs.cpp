#include <LEDs.h>

LEDs::LEDs() = default;

LEDs::~LEDs() = default;

void LEDs::setup() {
    FastLED.addLeds<WS2812B, LED_DATA_PIN>(leds, NUM_LEDS);

    // Disable all leds
    for(auto& led : leds) {
        led = CRGB::Black;
    }
    FastLED.show();
}

void LEDs::setBrightness(uint8_t brightness) {
    FastLED.setBrightness(brightness);
}

CRGB &LEDs::operator[](int index) {
    return leds[index];
}

void LEDs::show() {
    FastLED.show();
}
