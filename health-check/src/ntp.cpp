#include <ntp.h>

NTPClient* timeClient;

NTP::NTP() : client(wifi) {
}


NTP::~NTP() {
}

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

void NTP::updateIfNecessary() {
    client.update();
}