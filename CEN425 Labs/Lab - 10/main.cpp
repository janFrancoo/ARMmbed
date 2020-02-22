#include "mbed.h"
#include "LCD_DISCO_F429ZI.h"

LCD_DISCO_F429ZI lcd;
Serial slave(PD_8, PD_9);

DigitalOut led1(PG_13);
DigitalOut led2(PG_14);

uint8_t text[20];

void serialIn() {
  char ch = slave.getc();
  led1 = !led1;
  sprintf((char*)text, "Data = %c", ch);
  lcd.DisplayStringAt(0, LINE(2), (uint8_t *)&text, LEFT_MODE);
}

int main()
{
  slave.attach(&serialIn);
  led1 = 0;
  led2 = 1;

  BSP_LCD_SetFont(&Font20);
  lcd.Clear(LCD_COLOR_BLUE);
  lcd.SetBackColor(LCD_COLOR_BLUE);
  lcd.SetTextColor(LCD_COLOR_WHITE);
  while(1);
}
