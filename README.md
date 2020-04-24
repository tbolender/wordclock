# WordClock

My personal DIY Word Clock project.
The clock features a German layout with minute precision.
It is based on 114 LEDs and powered by a D1 mini.
Inspired by https://github.com/panbachi/wordclock and https://www.mikrocontroller.net/articles/Word_Clock.

The firmware uses a WiFi connection to retrieve the current time from an NTP service.
It supports time zones and daylight saving.
The displaying support different brightness for day and night.
The brightness is fading on sunrise and sunset based on coordinates.

The repository contains the design files for the grid and the firmware as well as some documentation.

## Running the firmware

The firmware is developed using [PlatformIO](https://platformio.org/).
Follow the installation instructions in the documentation for your platform.
On the command line use

> platformio run --target upload

to build and flash it to your connected D1 mini.

## Customizing

The files for easy customization are `code/include/defines.h` and `code/include/credentials.h`.
The first contains the configuration regarding brightness, time zone and coordinates.
The latter the credentials for the WiFi network to use for time retrieval.

### Different language layout

To use a different language layout, adapt the `code/src/Layout.cpp` class.
It determines the LED status with a boolean array with `true` for on and vice versa.
Adapt the setting functions.
In my project, the LED for minute 1 is on index 0 while the others are on 112, 113, 114.
Feel free to change it to your wiring.
For me this wiring was easier to solder for the frame I used.

## License

The project is provided under the GPLv3 license.
For full text, see the LICENSE file.
