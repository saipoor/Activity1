#include "activity4.h"
#include "activity3.h"
#include "activity2.h"
#include "activity1.h"
#include <util/delay.h>
#include <avr/io.h>

int main(void)
{
    while(1)
    {
        port_initialize(); 
        int check_status_led=0;
        check_status_led=led_init(); 
        if(check_status_led==1)
        {
            Timer_initialize();
            ADC_Initialize();
            uint16_t temp = 0;
            USART_initialize(103);
			temp = ReadADC(0);
			_delay_ms(200);
			pulse_wave(temp);	
			_delay_ms(200);
			USARTWritemsg(temp);
        }
    }
    return 0;
}
