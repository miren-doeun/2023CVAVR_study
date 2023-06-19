/*
 * 0612.c
 *
 * Created: 2023-06-12 ¿ÀÀü 11:02:37
 * Author: user
 */

#include <mega128a.h>
unsigned char led=0xFE;

void main(void)
{
    DDRC =0xFF;
    PORTC=led;
    
    TCCR0=0x07;
    TIMSK=0x01;
    TCNT0=0x00;
    SREG=0x80;
    while (1);
}
interrupt [TIM0_OVF] void timer_ovf0 (void)
{
    TCNT0=0x0;
    led=led<<1;
    led=led|0b00000001;
    if(led==0xFF) led=0xFE;
    PORTC=led ;
}