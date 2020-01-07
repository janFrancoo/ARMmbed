#include "mbed.h"

DigitalOut rled(PG_14);
DigitalIn button(PA_0);

int main(){
    while(1){
        if(button == 1){
            rled.write(1);   
        }
        else{
            rled.write(0);   
        }
    }   
}
