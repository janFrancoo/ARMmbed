#include "mbed.h"
#include "TS_DISCO_F429ZI.h"
#include "LCD_DISCO_F429ZI.h"
 
LCD_DISCO_F429ZI lcd;
TS_DISCO_F429ZI ts;
 
int main() {
    TS_StateTypeDef TS_State;
    uint16_t x, y;
    uint8_t text[30];
    uint8_t status;
    
    lcd.SetFont(&Font20);
    lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"TOUCHSCREEN", CENTER_MODE);
    lcd.DisplayStringAt(0, LINE(6), (uint8_t *)"DEMO", CENTER_MODE);
    wait(1);
  
    status = ts.Init(lcd.GetXSize(), lcd.GetYSize());
    if (status != TS_OK) {
      lcd.Clear(LCD_COLOR_RED);
      lcd.SetBackColor(LCD_COLOR_RED);
      lcd.SetTextColor(LCD_COLOR_WHITE);
      lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"TOUCHSCREEN", CENTER_MODE);
      lcd.DisplayStringAt(0, LINE(6), (uint8_t *)"INIT FAIL", CENTER_MODE);
    }
    else{
      lcd.Clear(LCD_COLOR_GREEN);
      lcd.SetBackColor(LCD_COLOR_GREEN);
      lcd.SetTextColor(LCD_COLOR_WHITE);
      lcd.DisplayStringAt(0, LINE(5), (uint8_t *)"TOUCHSCREEN", CENTER_MODE);
      lcd.DisplayStringAt(0, LINE(6), (uint8_t *)"INIT OK", CENTER_MODE);
    }
    wait(1);
    lcd.Clear(LCD_COLOR_BLUE);
    lcd.SetBackColor(LCD_COLOR_BLUE);
    lcd.SetTextColor(LCD_COLOR_WHITE);
    
    while(1){
        ts.GetState(&TS_State);      
        
        if (TS_State.TouchDetected){
            x = TS_State.X;
            y = TS_State.Y;
            sprintf((char*)text, "x=%d y=%d    ", x, y);
            lcd.DisplayStringAt(0, LINE(0), (uint8_t *)&text, LEFT_MODE);
            lcd.FillCircle(x, y, 5);
            wait(0.2);
            lcd.SetTextColor(LCD_COLOR_BLUE);
            lcd.FillCircle(x, y, 5);
            lcd.SetTextColor(LCD_COLOR_WHITE);
        }
    }
}
