/*
 * 2.2.c
 *
 * Created: 2023-05-01 ¿ÀÀü 9:52:20
 * Author: user
 */

#include <mega128a.h>

void main(void)
{
unsigned char key;
DDRE=0x00;
DDRC=0xFF;

PORTC=0xFF;
while (1)
    {
    key= PINE&0b11110000;
    
    if(0b11100000==key) PORTC=0x00;
    else if(0b11010000==key) PORTC=0xFF;
    else if(0b10110000==key) PORTC=0x55;
    else if(0b01110000==key) PORTC=0xAA;
    }
}
