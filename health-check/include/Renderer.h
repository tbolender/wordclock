#ifndef WORDCLOCK_RENDERER_H
#define WORDCLOCK_RENDERER_H

#include <LEDs.h>
#include <NTP.h>
#include <Layout.h>

class Renderer {
private:
    LEDs& leds;
    Layout& layout;

public:
    Renderer(LEDs& leds, Layout& layout);
    virtual ~Renderer();

    void render(NTP& ntp);
    void render(int hours, int minutes);
};


#endif //WORDCLOCK_RENDERER_H
