/*
 * 0515_1.c
 *
 * Created: 2023-05-15 ���� 9:46:58
 * Author: user
 */

#include <mega128a.h>
unsigned char led = 0xFE;
void main(void)
{
    // Please write your application code here
    DDRC=0xFF;
    PORTC=led;
        
    EIMSK=0b00010000;
    EICRB = 0b00000010;
    SREG=0x80;
    
    while(1);
}

interrupt [EXT_INT4] void LED_TEST(void)
{
    led=led<<1;
    led=led|0b00000001;
    if(led == 0xFF) led=0xFE;
    PORTC=led;
}
