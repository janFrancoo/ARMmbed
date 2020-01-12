#include "mbed.h"
#include "TS_DISCO_F429ZI.h"
#include "LCD_DISCO_F429ZI.h"
 
LCD_DISCO_F429ZI lcd;
TS_DISCO_F429ZI ts;
DigitalOut led_green(LED1);
DigitalOut led_red(LED2);

int main() {
    TS_StateTypeDef TS_State;
    uint8_t status_b1, status_b2;
    uint8_t text[30];
    uint16_t xc, yc;
    uint16_t xsize = lcd.GetXSize();
    uint16_t ysize = lcd.GetYSize();
    uint16_t x = 10, y = 120, w = xsize - 20, h = 60;
    uint16_t x2 = 10, y2 = 200, w2 = xsize - 20, h2 = 60;
  
    status_b1 = ts.Init(x, y);
    status_b2 = ts.Init(x2, y2);
    
    lcd.Clear(LCD_COLOR_BLUE);
    
    lcd.SetFont(&Font16);
    lcd.SetBackColor(LCD_COLOR_DARKRED);
    lcd.DisplayStringAt(0, LINE(2), (uint8_t *)"Jan Franco", CENTER_MODE);   
    
    lcd.SetFont(&Font16);
    lcd.SetBackColor(LCD_COLOR_MAGENTA);
    lcd.DisplayStringAt(0, LINE(4), (uint8_t *)"Major????", CENTER_MODE);
            
    lcd.SetFont(&Font20);
    lcd.SetBackColor(LCD_COLOR_WHITE);
    lcd.DisplayStringAt(0, LINE(7), (uint8_t *)"RED LED", CENTER_MODE);
    
    lcd.SetFont(&Font20);
    lcd.SetBackColor(LCD_COLOR_WHITE);
    lcd.DisplayStringAt(0, LINE(11), (uint8_t *)"GREEN LED", CENTER_MODE);
    
    lcd.SetTextColor(LCD_COLOR_RED);
    lcd.FillRect(x, y, w, h);
    
    lcd.SetTextColor(LCD_COLOR_GREEN);
    lcd.FillRect(x2, y2, w2, h2);
    
    while(1){
        ts.GetState(&TS_State);  
            
        if (TS_State.TouchDetected){
            xc = TS_State.X;
            yc = TS_State.Y;
            
            sprintf((char*)text, "x=%d y=%d    ", xc, yc);
            lcd.DisplayStringAt(0, LINE(0), (uint8_t *)&text, LEFT_MODE);
            
            if(xc >= x && xc <= x + w && yc >= y && yc <= (y + h)){
                if(led_red)
                    led_red = 0;   
                else
                    led_red = 1;
            }
            
            if(xc >= x2 && xc <= (x2 + w2) && yc >= y2 && yc <= (y2 + h2)){
                if(led_green)
                    led_green = 0;   
                else
                    led_green = 1;
            }
        }
    }
}
