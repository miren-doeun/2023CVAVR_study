/*
 * 0612.c
 *
 * Created: 2023-06-12 ���� 11:02:37
 * Author: user
 */

#include <mega128a.h>
unsigned char led=0xFE;

void main(void)
{
    DDRC =0xFF;
    PORTC=led;
    
    TCCR0=0x0F;
    TIMSK=0x02;
    TCNT0=0xFF;
    SREG=0x80;
    
    while (1);
}
interrupt [TIM0_OVF] void timer_ovf0 (void)
{
    led=led<<1|0x01;
    if(led==0xFF) led=0xFE;
    PORTC=led ;
}