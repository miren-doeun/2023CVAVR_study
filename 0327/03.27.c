/*
 * 03.27.c
 *
 * Created: 2023-03-27 ���� 8:53:35
 * Author: user
 */

#include <mega128.h>
#include <delay.h>

void main(void)
{
while (1)
    {
    // Please write your application code here
      int i;
      unsigned char led;
      DDRC = 0xFF;
      
      while(1){
          led = 0b01111111;
          for(i=0;i<8;i++){
          PORTC=led;
          delay_ms(500);
          led>>=1;
          }
      }
    }
}
