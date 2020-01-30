#include "mbed.h"
#include "ServoMotor.h"

ServoMotor myservo(PC_8);
InterruptIn btn(PA_0);

int degree = 5;

void btn_down() {
    if(myservo.getPosition() >= 90 || myservo.getPosition() <= -90){
        degree *= -1;
    }
    
    myservo.move(degree);
}

int main(){
    
    btn.rise(&btn_down);
    myservo.setPosition(0);
    wait(0.5);
    
    while(1);
}
