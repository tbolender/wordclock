#ifndef WORDCLOCK_DEFINES_H
#define WORDCLOCK_DEFINES_H

#include <Timezone.h>

#define NUM_LEDS 114

#define FULL_BRIGHTNESS 150
#define NIGHT_BRIGHTNESS 30

#define SUMMER_TIME (TimeChangeRule) {"MESZ", Last, Sun, Mar, 2, 120}
#define WINTER_TIME (TimeChangeRule) {"MEZ", Last, Sun, Oct, 2, 60}

#define LATITUDE 50.7753455
#define LONGITUDE 6.0838868

#endif //WORDCLOCK_DEFINES_H
