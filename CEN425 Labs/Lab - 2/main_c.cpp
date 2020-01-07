#include "mbed.h"

BusOut disp(PB_8, PE_2, PE_4, PE_6, PC_14, PF_0, PF_2, PF_4);

int main() {
    while(1) {
        disp = 0xA4;
        wait (1);
        disp = 0xB0;
        wait (1);
        disp = 0x99;
        wait (1);
        disp = 0x92;
        wait (1);
        disp = 0x82;
        wait (1);
        disp = 0xF8;
        wait (1);
        disp = 0x80;
        wait (1);
        disp = 0x90;
        wait (1);   
    }
}
