#include "mbed.h"

DigitalOut gled(PG_13);
DigitalOut rled(PG_14);
InterruptIn button(PA_0);
Timeout chron;

void chron_ISR() {
    rled = !rled;
}

void button_ISR() {
    chron.attach(&chron_ISR, 5);
}

int main(){
    rled = 0;
    button.rise(&button_ISR);
    gled = 1;
    while(1);
}
