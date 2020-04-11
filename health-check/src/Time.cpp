#include <Time.h>
#include <TimeLib.h>

int Time::getSeconds() {
    return second(getEpochTime());
}

int Time::getMinutes() {
    return minute(getEpochTime());
}

int Time::getHours() {
    return hour(getEpochTime());
}

int Time::getDay() {
    return day(getEpochTime());
}

int Time::getMonth() {
    return month(getEpochTime());
}

int Time::getYear() {
    return year(getEpochTime());
}

String Time::getFormattedTime() {
    return "";
}
