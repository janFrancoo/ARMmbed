#include"mbed.h"

InterruptIn btn(PA_0);
DigitalOut redLED(PG_14);
DigitalOut greenLED(PG_13);

int start = 0;

void btn_down_ISR() {
    greenLED = greenLED ^ 1;
}

void btn_up_ISR() {
    if(start == 0)
        start = 1;
    else 
        start = 0;
}

int main() {
    btn.rise(&btn_down_ISR);
    btn.fall(&btn_up_ISR);
    greenLED = 0;
    redLED = 0;
    
    while(1) {
        if(start == 1) {
            redLED = redLED ^ 1;
            wait(0.5);
        }
        else 
            redLED = 0;
    }
}
