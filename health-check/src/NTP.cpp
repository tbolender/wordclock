#include <NTP.h>

NTPClient* timeClient;

NTP::NTP() : NTP(0) {
}

NTP::NTP(long offset) : client(wifi, offset) {
}

NTP::~NTP() = default;

void NTP::setup() {
    client.begin();
}

int NTP::getHours() {
    return client.getHours();
}

int NTP::getMinutes() {
    return client.getMinutes();
}

int NTP::getSeconds() {
    return client.getSeconds();
}

bool NTP::updateIfNecessary() {
    return client.update();
}

String NTP::getFormattedTime() {
    return client.getFormattedTime();
}
