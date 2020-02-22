#include "mbed.h"

Timer timer;
Timer timerDouble;
DigitalOut led(LED2);
InterruptIn btn(PA_0);
SPI master(PE_6, PE_5, PE_2);

int countt = 0, signal = 0;

void send_message(uint8_t msg) {
    master.lock();
    master.write(msg);
    master.unlock();
}

void down() {
    timerDouble.start();
    timer.reset();
    timer.start();
    if(countt){
        timerDouble.stop();
        int end = timerDouble.read();
        if(end < 2){
            signal = 2;
        }
        countt = 0;
    }
    signal = 1;
}

void up() {
    timer.stop();
    int end = timer.read();
    if(end > 2){
        signal = 0;
    }
    countt = 1;
}

int main() {
    btn.rise(&down);
    btn.fall(&up);
    
    while(1) {
        send_message(signal);
    }
}
