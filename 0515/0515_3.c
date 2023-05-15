/*
 * 0515_1.c
 *
 * Created: 2023-05-15 ¿ÀÀü 9:46:58
 * Author: user
 */

#include <mega128a.h>
unsigned char led = 0xFD;
void main(void)
{
    // Please write your application code here
    DDRC=0xFF;
    PORTC=led;
        
    EIMSK=0b11000000;
    EICRB = 0b11100000;
    SREG=0x80;
    
    while(1);
}

interrupt [EXT_INT6] void LED_TEST(void)
{
    led=led<<1;
    led=led|0b00000001;
    if(led == 0xFF) led=0xFE;
    PORTC=led;
}
interrupt [EXT_INT7] void LED_TEST2(void)
{
    led=led>>1;
    led=led|0x80;
    if(led == 0xFF) led=0x7F;
    PORTC=led;
}
