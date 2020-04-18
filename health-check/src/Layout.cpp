#include <Layout.h>

const int Layout::SINGLE_MINUTES[] = {
    0, 111, 112, 113
};

const int Layout::IT_IS[] = {
    110, 109, 107, 106, 105 // ES IST
};

const int Layout::MINUTES[12][12] = {
    {   9,  10,  11,  -1, -1, -1, -1, -1, -1, -1, -1, -1 }, // UHR
    { 103, 102, 101, 100, 74, 75, 76, 77, -1, -1, -1, -1 }, // FÜNF NACH
    {  89,  90,  91,  92, 74, 75, 76, 77, -1, -1, -1, -1 }, // ZEHN NACH
    {  84,  83,  82,  81, 80, 79, 78, 74, 75, 76, 77, -1 }, // VIERTEL NACH
    {  93,  94,  95,  96, 97, 98, 99, 74, 75, 76, 77, -1 }, // ZWANZIG NACH
    { 103, 102, 101, 100, 67, 68, 69, 66, 65, 64, 63, -1 }, // FÜNF VOR HALB
    {  66,  65,  64,  63, -1, -1, -1, -1, -1, -1, -1, -1 }, // HALB
    { 103, 102, 101, 100, 74, 75, 76, 77, 66, 65, 64, 63 }, // FÜNF NACH HALB
    {  93,  94,  95,  96, 97, 98, 99, 67, 68, 69, -1, -1 }, // ZWANZIG VOR
    {  84,  83,  82,  81, 80, 79, 78, 67, 68, 69, -1, -1 }, // VIERTEL VOR
    {  89,  90,  91,  92, 67, 68, 69, -1, -1, -1, -1, -1 }, // ZEHN VOR
    { 103, 102, 101, 100, 67, 68, 69, -1, -1, -1, -1, -1 }, // FÜNF VOR
};

const int Layout::HOURS[12][6] = {
    { 16, 15, 14, 13, 12, -1 }, // ZWÖLF
    { 45, 46, 47, 48, -1, -1 }, // EINS
    { 52, 53, 54, 55, -1, -1 }, // ZWEI
    { 44, 43, 42, 41, -1, -1 }, // DREI
    { 37, 36, 35, 34, -1, -1 }, // VIER
    { 59, 58, 57, 56, -1, -1 }, // FÜNF
    { 23, 24, 25, 26, 27, -1 }, // SECHS
    { 22, 21, 20, 19, 18, 17 }, // SIEBEN
    { 30, 31, 32, 33, -1, -1 }, // ACHT
    {  4,  5,  6,  7, -1, -1 }, // NEUN
    {  1,  2,  3,  4, -1, -1 }, // ZEHN
    { 61, 60, 59, -1, -1, -1 }, // ELF
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

void Layout::setItIs() {
    for(int i : IT_IS) {
        ledMask[i] = true;
    }
}

void Layout::setSingleMinutes(int minutes) {
    minutes %= 5;
    if(minutes == 0)
        return;

    for(int i = 0; i <= minutes; i++) {
        ledMask[SINGLE_MINUTES[i-1]] = true;
    }
}

void Layout::setMinutes(int minutes) {
    // Normalize first
    minutes /= 5;

    for(int i : MINUTES[minutes]) {
        if(i < 0) break;
        ledMask[i] = true;
    }
}

void Layout::setHours(int hours, int minutes) {
    if(minutes >= 25)
        ++hours;
    hours %= 12;

    // German language: Handle EIN UHR case
    if(hours == 1 && minutes < 5) {
        for(int i = 0; i < 3; i++) {
            ledMask[HOURS[1][i]] = true;
        }
        return;
    }

    for(int i : HOURS[hours]) {
        if(i < 0) break;
        ledMask[i] = true;
    }
}

bool* Layout::getSingleMinutesLayout(int minutes) {
    clear();
    setSingleMinutes(minutes);
    return ledMask;
}

bool* Layout::getLayout(int hours, int minutes) {
    clear();

    setItIs();
    setSingleMinutes(minutes);
    setMinutes(minutes);
    setHours(hours, minutes);

    return ledMask;
}
