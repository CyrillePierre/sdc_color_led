#include <mbed.h>

int main() {
    DigitalOut led(LED1);

    PwmOut red(D3);
    PwmOut green(D5);
    PwmOut blue(D6);

    red = 1 - 1;
    green = 1 - 1;
    blue = 1 - 0;

    while(1){
        led = !led;
		wait(0.5);
    }
}
