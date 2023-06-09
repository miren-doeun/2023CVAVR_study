/*
 * 04.10_1.c
 *
 * Created: 2023-04-10 ���� 8:42:56
 * Author: user
 */

#include <mega128a.h>
#include <delay.h>

flash unsigned char seg[10]={0x3f, 0x06, 0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void SEG4(int);

void main(void)
{
    // Please write your application code here
    int num=1;
          
    DDRB=0xF0;
    DDRD=0xF0;
    DDRG=0x0f;
          
    PORTB=0x0;
    PORTD=0x0;
          
    while(1){
        SEG4(num);
        num++;
        if(num>9999) num=1;   
    }
}
void SEG4(int num){
    int i, N1000, N100, N10, N1, buf;
    N1000=num/1000;
    buf = num%1000;
    N100=buf/100;
    buf=num%100;
    N10=buf/10;
    N1=num%10;
    
        
    for(i=0;i<5;i++){
        PORTG=0b000001000;
        PORTD=((seg[N1]&0x0F)<<4);
        PORTB=(seg[N1]&0xF0);
        delay_ms(5);
                   
        if(10<num){
        PORTG=0x04;
        PORTD=((seg[N10]&0x0F)<<4);
        PORTB=(seg[N10]&0xF0);
        delay_ms(5);
        }
        
        if(100<num){
        PORTG=0b000000010;
        PORTD=((seg[N100]&0x0F)<<4);
        PORTB=(seg[N100]&0xF0);
        delay_ms(5);
        }
        
        if(1000<num){
        PORTG=0b00000001;
        PORTD=((seg[N1000]&0x0F)<<4);
        PORTB=(seg[N1000]&0xF0);
        delay_ms(5);
        }
    }
}