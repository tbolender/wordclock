#include <timer.h>


RTC_DS3231 rtc;


void setupTimer() {
    if (rtc.lostPower()) {
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
}
