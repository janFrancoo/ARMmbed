#include "mbed.h"

Ticker timeup;
DigitalOut rled(PG_14);

void led_switch() {
    rled = !rled;
}

int main() {
    rled = 0;
    timeup.attach(&led_switch, 2);
    while(1);
}
