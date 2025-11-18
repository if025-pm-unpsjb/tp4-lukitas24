#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);


DigitalOut* leds[] = { &led1, &led2, &led3, &led4 };
const int NUM_LEDS = 4;



void ponerCeros(int pos) {
    for (int i = pos - 1; i >= 0; i--) {
        *(leds[i]) = 0;
    }
}

void buscarCero() {
    for (int i = 0; i < NUM_LEDS; i++) {
        if (*(leds[i]) == 0) {
            *(leds[i]) = 1;
            ponerCeros(i);
            break;
        }
    }
}

int main(){


	 while (1) {
		 for (int i = 0; i < NUM_LEDS; i++) {
				*(leds[i]) = 0;
			}
		 for (int i = 0; i < 15; i++) {
			 buscarCero();
			 wait(1);
		 }

	     }
}
