#include "mbed.h"

int counter = 0;
DigitalOut redLed(PG_14);
DigitalOut greenLed(PG_13);

int main()
{      
    redLed.write(0);
    greenLed.write(0);
    
    while(1){
        redLed.write(1);
        greenLed.write(0);
        wait(1);
        redLed.write(0);
        greenLed.write(1);
        wait(1);
        
        counter++;
        
        if(counter > 5){
            redLed.write(1);
            greenLed.write(1);
            wait(2);
        }
        
    }
}

