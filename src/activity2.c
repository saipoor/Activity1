#include "activity2.h"
#include <util/delay.h>
#include <avr/io.h>

void ADC_Initialize()
{
    ADMUX=(1<<REFS0);//when AREF and AVCC equals 5v
    ADCSRA=(1<<ADEN) | (7<<ADPS0); 
}

uint16_t ReadADC(uint8_t ch)
{
    ADMUX&=0xf8;  
    ch=ch&0b00000111;//confirm the value is between 0 to  7
    ADMUX|=ch;
    ADCSRA|=(1<<ADSC);//single bit conversion starts
    while(!(ADCSRA & (1<<ADIF)))
        ADCSRA|=(1<<ADIF);//conversion completes
    return ADC;
}
