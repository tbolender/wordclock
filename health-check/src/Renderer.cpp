#include <Renderer.h>

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
