#include "mbed.h"
#include "rtos.h"
 
DigitalOut led(LED1);
DigitalIn button(PA_0);
 
void led_thread() {
    while (true) {
        Thread::signal_wait(0x1);
        led = !led;
        Thread::wait(1000);
    }
}
 
int main (void) {
    Thread thread;
    thread.start(callback(led_thread));
 
    while (true) {
        if(button) {
            thread.signal_set(0x1);
        }
    }
}
