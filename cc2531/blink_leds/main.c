#include "cc2530.h"

#define LED1_PIN P1_1
#define LED1_MASK  0x02 //0000 0010

#define LED2_PIN P0_0
#define LED2_MASK 0x01 //0000 0001

void wait(unsigned int time) {
    for (unsigned int loop1 = 0; loop1 < time; loop1++) {
        for (unsigned int loop2 = 0; loop2 < 65535; loop2++) {}
    }
}

void main(void) {
    //red led
    //set port to GPIO 0000 0000 & 1111 1101
    P1SEL &= ~LED1_MASK;

    //set port to output 0000 0000 | 0000 0010
    P1DIR |= LED1_MASK;

    //green led
    //set port to GPIO
    P0SEL &= ~LED2_MASK;

    //set port to output
    P0DIR |= LED2_MASK;

    while (0 < 1) {
        LED1_PIN = 1 & 0xFF;
        LED2_PIN = 0 & 0xFF;

        wait(5);

        LED1_PIN = 0 & 0xFF;
        LED2_PIN = 1 & 0xFF;

        wait(5);
    }
}
