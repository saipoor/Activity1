#include "Activity1.h"
#include <util/delay.h>
#include <avr/io.h>

void port_initialize()
{
    DDRD&=~(1<<PD0);
    DDRB|=(1<<PB0); 
    DDRD&=~(1<<PD4);
    PORTD|=(1<<PD0);
    PORTD|=(1<<PD4);
    return 0;
}

int led_initialize()
{
        if((!(PIND & (1<<PD0)) && (!(PIND & (1<<PD4)))))
        {
            PORTB |=(1<<PB0);//Instruction used for led on
            _delay_ms(2000);
            return 1;
        }
        else
        {
            PORTB &=~(1<<PB0);//Instruction used for led off
            _delay_ms(2000);
            return 0;
        }
}
