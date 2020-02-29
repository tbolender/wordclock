#include <Renderer.h>

#include <defines.h>

Renderer::Renderer(LEDs &leds, Layout& layout) : leds(leds), layout(layout) {
}

Renderer::~Renderer() = default;

void Renderer::render(NTP& ntp) {
    render(ntp.getHours(), ntp.getMinutes());
}

void Renderer::render(int hours, int minutes) {
    bool* layoutMask = layout.getLayout(hours, minutes);
    render(layoutMask);
}

void Renderer::render(const bool* ledMask) {
    for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ledMask[i] ? CRGB::White : CRGB::Black;
    }

    leds.show();
}

void Renderer::showConnected() {
    for(int i = 0; i < 3; i++) {
        leds.setBrightness(FULL_BRIGHTNESS);
        render(layout.getSingleMinutesLayout());
        delay(500);

        leds.clear();
        delay(500);

    }
}
