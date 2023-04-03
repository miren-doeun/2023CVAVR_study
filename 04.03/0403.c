/*
 * 0403.c
 *
 * Created: 2023-04-03 ¿ÀÀü 9:29:47
 * Author: user
 */

#include <mega128a.h>
#include <delay.h>

void main(void)
{
    DDRB=0xF0;
    DDRD=0xF0;
    DDRG=0x0F;

    
    while (1)
    {
        // Please write your application code here
            PORTG=0b00000001;
            PORTB=0b00000000;
            PORTD=0b01100000;
            delay_ms(5);
            PORTG=0b00000010;
            PORTB=0b01010000;
            PORTD=0b10110000;
            delay_ms(5);
            PORTG=0b00000100;
            PORTB=0b01000000;
            PORTD=0b11110000;
            delay_ms(5);
            PORTG=0b00001000;
            PORTB=0b01100000;
            PORTD=0b01100000;
            delay_ms(5);
    }
}
