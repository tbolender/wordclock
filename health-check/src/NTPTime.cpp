#include <NTPTime.h>
#include <TimeLib.h>

NTPTime::NTPTime(Timezone& timezone) : client(wifi), timezone(timezone) {
}

NTPTime::~NTPTime() = default;

void NTPTime::setup() {
    client.begin();
}

time_t NTPTime::getEpochTime() {
    return timezone.toLocal(client.getEpochTime());
}

bool NTPTime::isDaylightSavingActive() {
    return timezone.utcIsDST(client.getEpochTime());
}

float NTPTime::getOffset() {
    return (getEpochTime() - client.getEpochTime()) / (60.0f * 60.0f);
}

bool NTPTime::updateIfNecessary() {
    return client.update();
}


String NTPTime::getFormattedTime() {
    return client.getFormattedTime();
}
