/*
 * 20503.c
 *
 * Created: 2023-03-20 ���� 9:16:20
 * Author: user
 */

#include <mega128a.h>
#include <delay.h>

void main(void)
{
    DDRC=0XFF;
    
    // Please write your application code here
    DDRC=0XFF;
    while(1){
        PORTC=0X55;
        delay_ms(500);
        PORTC=0XAA;
        delay_ms(500);
    }
    
}
