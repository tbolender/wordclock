#ifndef HEALTH_CHECK_RENDERER_H
#define HEALTH_CHECK_RENDERER_H

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


#endif //HEALTH_CHECK_RENDERER_H
