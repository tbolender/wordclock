#include <NTP.h>
#include <TimeLib.h>

NTPClient* timeClient;

NTP::NTP() : NTP(0) {
}

NTP::NTP(long offset) : client(wifi, offset) {
}

NTP::~NTP() = default;

void NTP::setup() {
    client.begin();
}

int NTP::getSeconds() {
    return client.getSeconds();
}

int NTP::getMinutes() {
    return client.getMinutes();
}

int NTP::getHours() {
    return client.getHours();
}

int NTP::getDay() {
    return client.getDay();
}

int NTP::getMonth() {
    return month(client.getEpochTime());
}

int NTP::getYear() {
    return year(client.getEpochTime());
}

unsigned long NTP::getEpochTime() {
    return client.getEpochTime();
}

bool NTP::updateIfNecessary() {
    return client.update();
}

String NTP::getFormattedTime() {
    return client.getFormattedTime();
}
