#include "Activity4.h"
#include "Activity3.h"
#include "Activity2.h"
#include "Activity1.h"
#include <util/delay.h>
#include <avr/io.h>

int main(void)
{
    while(1)
    {
        port_initialize(); 
        int check_status_led=0;
        check_status_led=led_initialize(); 
        if(check_status_led==1)
        {
            Timer_initialize();
            ADC_initialize();
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
