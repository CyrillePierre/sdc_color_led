#include <mbed.h>
#include "color/converter.hpp"

int main() {
    DigitalOut led(LED1);
//    AnalogIn   pot(A0);
    HSL<float> hsl;

    hsl.s = 1;
    hsl.l = .01;

    PwmOut red(D3);
    PwmOut green(D5);
    PwmOut blue(D6);

    red.period_ms(1);
    green.period_ms(1);
    blue.period_ms(1);

    for (;;) {
        hsl.h += 0.001;
        if (hsl.h > 1) hsl.h = 0;
//        hsl.h = pot;

        RGB<float> rgb = toRGB(hsl).getInvert();
        red   = rgb.r;
        green = rgb.g;
        blue  = rgb.b;

        wait_ms(10);
    }
}
