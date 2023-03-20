#include <mega128a.h>
#include <delay.h>
void main(void){
    int i;
    unsigned char led;
    DDRC=0XFF;
    while (1){
        led=0XFE;
        for(i=0;i<8;i++){
            PORTC=led;
            delay_ms(500);
            led<<=1;
            
            
        }
        
    }
}
