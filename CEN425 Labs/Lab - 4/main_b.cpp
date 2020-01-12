#include "mbed.h"
#include "LCD_DISCO_F429ZI.h"

LCD_DISCO_F429ZI lcd;

int main(){      
    
    uint16_t xsize = lcd.GetXSize();
    uint16_t ysize = lcd.GetYSize();
    uint16_t w1, w2, h1, h2;
    uint16_t x1, y1, x2, y2;
    
    w1 = xsize/2;
    h1 = ysize/5;
    x1 = xsize/4;
    y1 = 50;
    w2 = xsize/4;
    h2 = ysize/10;
    x2 = x1 + (w1-w2)/2;
    y2 = y1 + (h1-h2)/2;
    
    lcd.SetTextColor(LCD_COLOR_RED);
    lcd.DrawRect(x1, y1, w1, h1);
    
    lcd.SetTextColor(LCD_COLOR_YELLOW);
    lcd.FillRect(x2, y2, w2, h2);
    
    lcd.SetTextColor(LCD_COLOR_BLACK);
    lcd.DrawHLine(0, ysize/2 - 11, xsize);
    lcd.DrawHLine(0, ysize - 7, xsize);
    
    uint16_t i = 0;
    bool direction_up = true;
    while(1) {
        
        lcd.SetTextColor(LCD_COLOR_GREEN);
        lcd.FillCircle(xsize/2, ysize/2 + i, 10);
        wait(0.1);
        lcd.SetTextColor(LCD_COLOR_WHITE);
        lcd.FillCircle(xsize/2, ysize/2 + i, 10);
        
        if(i>ysize/2 - 20) direction_up = false;
        else if(i < 2) direction_up = true;
        
        if(direction_up) i = i + 2;
        else  i = i -2;
    }
}
