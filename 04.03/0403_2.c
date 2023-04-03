#include <mega128.h>
#include <delay.h>

flash unsigned char seg[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void main(void)
{
    int i;
    DDRB=0xf0;
    DDRD=0xf0;
    DDRG=0x0f;
    PORTG=0b00001000;
    PORTB=0x0;
    PORTD=0x0;
    while(1){
        for(i=0;i<10;i++){
            PORTD=(seg[i]&0x0F)<<4;
            PORTB=(seg[i]&0xF0);
            delay_ms(500);
        }
    }
}