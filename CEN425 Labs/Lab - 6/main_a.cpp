#include "mbed.h"
#include "LCD_DISCO_F429ZI.h"

LCD_DISCO_F429ZI lcd;
AnalogIn myadc(PC_1);

float voltage;
uint8_t sensor_voltage[30];

int main() {
          
    lcd.SetFont(&Font16);
    lcd.DisplayStringAt(0, LINE(2), (uint8_t *)"Voltmeter", CENTER_MODE);
    
    while(1) {
        voltage = myadc.read();
        sprintf((char*)sensor_voltage, "Voltage = %.4f", voltage);
        lcd.DisplayStringAt(0, LINE(4), sensor_voltage, CENTER_MODE);
        wait(0.2);
    }
}
