#include "Activity3.h"
#include <util/delay.h>
#include <avr/io.h>

void Timer_initialize()
{
    TCCR1A |= (1<<COM1A1) | (1<<WGM11) | (1<<WGM10);
    TCCR1B |= (1<<WGM12) | (1<<CS11) | (1<<CS10);   
    DDRB |= (1<<PB1);   
}

void pulse_wave(uint16_t temp)
{
    if(temp >= 210 && temp <= 500){
         OCR1A = 0x199;   
    }
   else if(temp >= 710 && temp <= 1024){
        OCR1A = 0x3cb;  
    }
    else if(temp >= 510 && temp <= 700){
        OCR1A = 0x2cc;  
    }
    else if(temp >= 0 && temp <= 200){
        OCR1A = 0xcc; 
    }
    else{
        OCR1A = 0x3ff; 
    }
}
