#ifndef WORDCLOCK_RENDERER_H
#define WORDCLOCK_RENDERER_H

#include <LEDs.h>
#include <NTPTime.h>
#include <Layout.h>

class Renderer {
private:
    LEDs& leds;
    Layout& layout;

public:
    Renderer(LEDs& leds, Layout& layout);
    virtual ~Renderer();

    void render(Time& ntp);
    void render(int hours, int minutes);
    void render(const bool* ledMask);

    void showWifiStatus(bool working);
};


#endif //WORDCLOCK_RENDERER_H
