#include "mbed.h"

Timer t;
DigitalOut gled(PG_13);
DigitalOut rled(PG_14);
InterruptIn button(PA_0);

void button_ISR() {
    t.stop();                           
    int time_press_button = t.read();
    if(time_press_button < 0.5) 
        gled = 1;
}

int main() {
    button.rise(&button_ISR);
    t.reset();           
    t.start();
    rled = 1;
}
