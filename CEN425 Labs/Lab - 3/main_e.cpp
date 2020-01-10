#include"mbed.h"

Timer timer;
Timeout chron;
InterruptIn btn(PA_0);
DigitalOut redLED(PG_14);
DigitalOut greenLED(PG_13);

int mode = 0;
int beats = 40;

void lightDown();
void lightUp();

void lightDown(){
    redLED = 0;
    chron.attach(&lightUp, 60/beats);
}

void lightUp(){
    redLED = 1;   
    chron.attach(&lightDown, 0.1);
}

void btnDwn(){
    timer.reset();
    timer.start();
    
    if(mode == 0){
        if(beats < 200){
            beats += 10;
        }
    }
    else{
        if(beats > 40){
            beats -= 10;
        }
    }   
}

void btnUp(){
    timer.stop();
    int end = timer.read();
    
    if(end > 3){
        mode = !mode;
    } 
}

int main() {
    redLED = 0;
    
    btn.rise(&btnDwn);
    btn.fall(&btnUp);
    
    chron.attach(&lightUp, 60/beats);
    
    while(1){
        if(mode == 0){
            greenLED = 0;   
        }  
        else{
            greenLED = 1;   
        } 
    }
}
