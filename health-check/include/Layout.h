#ifndef HEALTH_CHECK_LAYOUT_H
#define HEALTH_CHECK_LAYOUT_H

#include <defines.h>

class Layout {
protected:
    static const int SINGLE_MINUTES[];
    static const int IT_IS[];
    static const int MINUTES[12][12];
    static const int HOURS[12][6];

    bool ledMask[NUM_LEDS];

    void clear();
    void setItIs();
    void setSingleMinutes(int minutes);
    void setMinutes(int minutes);
    void setHours(int hours, int minutes);
public:
    Layout();
    virtual ~Layout();

    bool* getLayout(int hours, int minutes);
};


#endif //HEALTH_CHECK_LAYOUT_H
