#include "mbed.h"

PwmOut pwm8(PC_8);  //Create a PWM output called pwm8 on pin PC8

int main()
{
    pwm8.period_ms(10);         //set PWM period to 10 ms
    pwm8 = 0.2;                 //set duty cycle to %20
    while(1);
}
