#include "mbed.h"
#include "LCD_DISCO_F429ZI.h"

Timer timer;
PwmOut s1(PC_8);
DigitalOut s2(PD_7);      
LCD_DISCO_F429ZI lcd;  
InterruptIn btn(PA_0);
DigitalOut led_red(LED2); 

enum{
    INCREASE,
    DECREASE   
};

int width = 20;
int mode = INCREASE;

void btnDwn(){
    timer.reset();
    timer.start();
    
    if(mode == INCREASE){
        if(width < 160){
            width += 5;
        }
    }
    else{
        if(width > 20){
            width -= 5;   
        }   
    }   
}

void btnUp(){
    timer.stop();
    int end = timer.read();
    
    if(end > 2){
        mode = !mode;
    } 
}

int main() {  
    s2 = 0;                
    s1.period_ms(200); 
    lcd.Clear(LCD_COLOR_BLUE);
    while(1){    
        lcd.SetFont(&Font8);
        lcd.DisplayStringAt(0, LINE(2), (uint8_t *)width, CENTER_MODE);   
        
        if(mode == INCREASE){
            led_red = 1;
        }
        else{
            led_red = 0;
        }  
        
        btn.rise(&btnDwn);
        btn.fall(&btnUp);
                  
        s1.pulsewidth_ms(width);
    }    
}
