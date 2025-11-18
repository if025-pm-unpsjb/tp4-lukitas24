#include "mbed.h"
Serial pc(USBTX, USBRX);
int main()
{
    pc.baud(9600);
    while(1) {
        pc.putc(pc.getc());
    }
}
