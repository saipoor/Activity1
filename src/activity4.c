#include "Activity4.h"
#include <util/delay.h>
#include <avr/io.h>

int i=0;
void USART_initialize(uint16_t ubrr)
{
    UBRR0L= ubrr;
    UBRR0H= (ubrr>>8)&(0x00ff);
    UCSR0C=(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);
    UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}

char USARTReadmsg()
{
    while(!(UCSR0A & (1<<RXC0)))
    {

    }
    return UDR0;
}

void USARTWritemsg(uint16_t temp)
{
    if(temp>=0 && temp<=200){
        unsigned char dtemp[] = "Temperature = 20C"; 
        i = 0;
        while(dtemp[i] != 0) 
        {
            while (!( UCSR0A & (1<<UDRE0))); 
            UDR0 = dtemp[i];           
            i++;                             
        }
    }
    else if(temp>=510 && temp<=700){
       unsigned char dtemp[] = "Temperature = 29C"; 
        i = 0;
        while(dtemp[i] != 0) 
        {
            while (!( UCSR0A & (1<<UDRE0))); 
            UDR0 = dtemp[i];            
            i++;                             
        }
    }
    else if(temp>=210 && temp<=500){
       unsigned char dtemp[] = "Temperature = 25C"; 
        i = 0;
        while(dtemp[i] != 0) 
        {
            while (!( UCSR0A & (1<<UDRE0))); 
            UDR0 = dtemp[i];            
            i++;                             
        }
    }
    else if(temp>=710 && temp<=1024){
        unsigned char dtemp[] = "Temperature = 33C"; 
        i = 0;
        while(dtemp[i] != 0) 
        {
            while (!( UCSR0A & (1<<UDRE0))); 
            UDR0 = dtemp[i];           
            i++;                             
        }
    }
    else{
        unsigned char dtemp[] = "Temperature is not in range";  
        i = 0;
        while(dtemp[i] != 0) 
        {
            while (!( UCSR0A & (1<<UDRE0))); 
            UDR0 = dtemp[i];            
            i++;                             
        }
    }
    while (!( UCSR0A & (1<<UDRE0)));   
		 UDR0 = '\n';   
    while (!( UCSR0A & (1<<UDRE0)));   
		 UDR0 = '\r';					    
    _delay_ms(2000);
}
