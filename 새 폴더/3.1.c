
#include <mega128a.h>

void main(void)
{
unsigned char o_sw,n_sw;
unsigned char led=0xFE;
DDRE=0x00;
DDRC=0xFF;

PORTC=0xFF;

o_sw=0b1111000;

while (1)
      {
      n_sw=PINE&0xF0;
      if(o_sw == 0b11110000&&n_sw==0b11100000){
        led=(led<<1)|1;
        if(led==0xFF)led=0xFE;
        
        PORTC=led;
      }
      o_sw=n_sw;
      }
}