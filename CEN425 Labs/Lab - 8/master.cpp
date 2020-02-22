#include "mbed.h"
#include "LCD_DISCO_F429ZI.h"

SPI master(PE_6, PE_5, PE_2);
DigitalOut ssel(PE_4);
DigitalOut led(LED2);
LCD_DISCO_F429ZI lcd;

uint8_t text[20];

int8_t send_message(uint8_t);

int main() {
    
    uint8_t msg_counter = 0x00;
    uint8_t response = 0x00;
    
    led = 0;
    
    while(1) {
        sprintf((char *) text, "Message = %d ", msg_counter);
        lcd.DisplayStringAt(0, LINE(2), (uint8_t*) &text, CENTER_MODE);
        
        response = send_message(msg_counter);
        wait (0.1);
        
        sprintf((char *) text, "Response = %d ", response);
        lcd.DisplayStringAt(0, LINE(4), (uint8_t*) &text, CENTER_MODE);
        
        if(response%2 == 0) led = 1;
        else led = 0;
        
        msg_counter = (msg_counter + 1) % 0x80;    //Modulo 128
        
        wait(5);
    }
}

int8_t send_message(uint8_t msg) {
    master.lock();
    ssel = 0;
    int resp = master.write(msg);
    ssel = 1;
    master.unlock();
    
    return resp;
}
