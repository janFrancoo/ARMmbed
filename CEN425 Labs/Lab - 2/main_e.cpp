#include "mbed.h"

int bc = 0;
DigitalOut gled(PG_13);
DigitalOut rled(PG_14);
DigitalIn button(PA_0);

int main(){
    rled.write(0);
    gled.write(0);
    
    while(1){
        if(button == 1){
            bc++;
        }
        if(bc != 0 && bc % 2 == 1){
            rled.write(0);
            gled.write(1);
            wait(1);
            gled.write(0);
            wait(1);
        }
        if(bc != 0 && bc % 2 == 0){
            gled.write(0);
            rled.write(1);
            wait(1);
            rled.write(0);
            wait(1);
        }
    }   
}
