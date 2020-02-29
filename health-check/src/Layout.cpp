#include <Layout.h>

const int Layout::SINGLE_MINUTES[] = {
    0, 111, 112, 113
};

const int Layout::IT_IS[] = {
    110, 109, 107, 106, 105 // ES IST
};

const int Layout::MINUTES[12][12] = {
    { 9, 10, 11 }, // UHR
    { 103, 102, 101, 100, 74, 75, 76, 77 }, // FÜNF NACH
    { 89, 90, 91, 92, 74, 75, 76, 77 }, // ZEHN NACH
    { 84, 83, 82, 81, 80, 79, 78, 74, 75, 76, 77 }, // VIERTEL NACH
    { 93, 94, 95, 96, 97, 98, 99, 74, 75, 76, 77 }, // ZWANZIG NACH
    { 103, 102, 101, 100, 67, 68, 69, 66, 65, 64, 63 }, // FÜNF VOR HALB
    { 66, 65, 64, 63 }, // HALB
    { 103, 102, 101, 100, 74, 75, 76, 77, 66, 65, 64, 63 }, // FÜNF NACH HALB
    { 93, 94, 95, 96, 97, 98, 99, 67, 68, 69 }, // ZWANZIG VOR
    { 84, 83, 82, 81, 80, 79, 78, 67, 68, 69 }, // VIERTEL VOR
    { 89, 90, 91, 92, 67, 68, 69 }, // ZEHN VOR
    { 103, 102, 101, 100, 67, 68, 69 }, // FÜNF VOR
};

const int Layout::HOURS[12][6] = {
    { 16, 15, 14, 13, 12 }, // ZWÖLF
    { 45, 46, 47, 48 }, // EINS
    { 52, 53, 54, 55 }, // ZWEI
    { 44, 43, 42, 41 }, // DREI
    { 37, 36, 35, 34 }, // VIER
    { 59, 58, 57, 56 }, // FÜNF
    { 23, 24, 25, 26, 27 }, // SECHS
    { 22, 21, 20, 19, 18, 17 }, // SIEBEN
    { 30, 31, 32, 33 }, // ACHT
    { 4, 5, 6, 7 }, // NEUN
    { 1, 2, 3, 4 }, // ZEHN
    { 57, 58, 59 }, // ELF
};

Layout::Layout() {
    clear();
};

Layout::~Layout() = default;

void Layout::clear() {
    for(bool& i : ledMask) {
        i = false;
    }
}

void Layout::setSingleMinutes(int minutes) {
    minutes %= 5;
    if(minutes == 0)
        return;

    for(int i = 0; i < minutes; i++) {
        ledMask[SINGLE_MINUTES[i-1]] = true;
    }
}

void Layout::setMinutes(int minutes) {
    // Normalize first
    minutes /= 5;

    for(int i : MINUTES[minutes]) {
        ledMask[i] = true;
    }
}

void Layout::setHours(int hours, int minutes) {
    if(minutes > 25)
        ++hours;
    hours %= 12;

    // FIXME: Handle EIN UHR case
    for(int i : HOURS[hours]) {
        ledMask[i] = true;
    }
}

bool *Layout::getLayout(int hours, int minutes) {
    clear();
    // TODO: Figure out what happens to non-initialized array elements
    setSingleMinutes(minutes);
    setMinutes(hours);
    setHours(hours, minutes);

    return ledMask;
}
