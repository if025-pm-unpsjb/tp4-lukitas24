#include "mbed.h"

Serial pc(USBTX, USBRX);
DigitalOut leds[] = { DigitalOut(LED1), DigitalOut(LED2), DigitalOut(LED3), DigitalOut(LED4) };


int main()
{
    pc.baud(9600);
	pc.printf("Ingresar  que led prender del 0 al 3 \n");
	char c = pc.getc();
	int idx = 0;
    while(1) {
        if(pc.readable()) {
        		c = pc.getc();
				pc.putc(c);
				int new_idx = c - '0';
			     if (new_idx >= 0 && new_idx < 4) {
			                leds[idx] = 0;
			                idx = new_idx;
			                pc.printf("\nCambiando a LED%d\n", idx);
			            } else {
			                pc.printf("\nValor inválido. Use 0, 1, 2 o 3.\n");
			            }
              }


        if (idx >= 0) {
             leds[idx] = 1;
             wait(0.25);
             leds[idx] = 0;
             wait(0.25);
         }
        }

}
