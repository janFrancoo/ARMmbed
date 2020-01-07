#include "mbed.h"

BusOut disp(PB_8, PE_2, PE_4, PE_6, PC_14, PF_0, PF_2, PF_4);

int main() {
    while(1) {
        disp = 0x86;
        wait (1);
        disp = 0xAF;
        wait (1);
        disp = 0x86;
        wait (1);
        disp = 0xAB;
        wait (1);
    }
}
