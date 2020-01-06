#include "mbed.h"

DigitalOut led_green(LED1);
DigitalOut led_red(LED2);

int main() {
    while(1) {
        led_green = 1;
        led_red = 1;
        wait(0.5);
        led_green = 0;
        wait(0.5);
        led_red = 0;
        wait(1);   
    }   
}
