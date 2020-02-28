#include <LEDs.h>

int row = 9;

void setMinutes(CRGB* leds, int minutes);
void setTime(CRGB* leds);

LEDs::LEDs() = default;

LEDs::~LEDs() = default;

void LEDs::setup() {
    FastLED.addLeds<WS2812B, LED_DATA_PIN>(leds, NUM_LEDS);
    setBrightness(50);

    // Disable all leds
    for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = CRGB::Black;
    }
    FastLED.show();
}

void LEDs::setBrightness(uint8_t brightness) {
    FastLED.setBrightness(brightness);
}

void LEDs::setTime(NTP& ntp) {
    setTime(ntp.getHours(), ntp.getMinutes());
}

void LEDs::setTime(int hours, int minutes) {
    setMinutes(leds, minutes);
    ::setTime(leds);
}

void setMinutes(CRGB* leds, int minutes) {
    minutes %= 5;
    leds[0] = minutes > 0 ? CRGB::White : CRGB::Black;
    leds[111] = minutes > 1 ? CRGB::White : CRGB::Black;
    leds[112] = minutes > 2 ? CRGB::White : CRGB::Black;
    leds[113] = minutes > 3 ? CRGB::White : CRGB::Black;
}

void setTime(CRGB* leds) {
    // Set row
    for(int i = 1 + row*11; i < 1 + 11 + row*11; i++)
        leds[i] = CRGB::Black;
    row = ++row % 10;
    for(int i = 1 + row*11; i < 1 + 11 + row*11; i++)
        leds[i] = CRGB::White;

    // Flush
    FastLED.show();
}
