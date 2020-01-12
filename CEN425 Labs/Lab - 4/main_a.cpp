#include "mbed.h"
#include "LCD_DISCO_F429ZI.h"
 
LCD_DISCO_F429ZI lcd;

int main() {
    lcd.Clear(LCD_COLOR_BLUE);
    
    lcd.SetFont(&Font8);
    lcd.DisplayStringAt(0, LINE(2), (uint8_t *)"Maltepe University", CENTER_MODE);   
    
    lcd.SetFont(&Font12);
    lcd.DisplayStringAt(0, LINE(4), (uint8_t *)"Faculty of Engineering", CENTER_MODE);
    
    lcd.SetBackColor(LCD_COLOR_RED);
    lcd.SetTextColor(LCD_COLOR_WHITE);
    lcd.SetFont(&Font16);
    lcd.DisplayStringAt(0, LINE(6), (uint8_t *)"Computer Engineering Dept.", LEFT_MODE);
    
    lcd.SetFont(&Font24);
    lcd.DisplayStringAt(0, LINE(6), (uint8_t *)"CEN425", RIGHT_MODE);
    
    lcd.SetBackColor(0xAABB11DD);
    lcd.SetTextColor(LCD_COLOR_BLACK);
    lcd.SetFont(&Font20);
    lcd.DisplayStringAt(0, LINE(10), (uint8_t *)"Embedded Systems", LEFT_MODE);
    
    while(1);
}
