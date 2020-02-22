#include "mbed.h"

SPISlave slave(PE_6, PE_5, PE_2, PE_4);
DigitalOut redLED(PG_14);
DigitalOut greenLED(PG_13);

int msg = 0;

int main(){
    redLED = 0;
    greenLED = 0;
    
    while(1) {
        if(slave.receive()) {
            msg = slave.read();
            if(msg == 0){
                redLED = 0;
                greenLED = 0;
            }
            if(msg == 1){
                greenLED = 0;
                redLED = 1;
            }
            if(msg == 2){
                redLED = 0;
                greenLED = 1; 
            }
        }
    }
}
