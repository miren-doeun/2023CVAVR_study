#include <mega128a.h>
unsigned char led =0x00;
unsigned char cnt =0;

void main(void)
{
    DDRC=0xFF;
    PORTC= led;
    
    TCCR0=0x06;
    TIMSK=0x01;
    TCNT0=6;
    SREG=0x80;
    
    while(1);
}

interrupt [TIM0_OVF] void timer_int0 (void)
{
    TCNT0=6;
    cnt++;
    if(cnt==250){
        led=led ^ 0xFF;
        PORTC=led;
        cnt=0;
    }
}