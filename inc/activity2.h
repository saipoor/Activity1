#ifndef ACTIVITY2_H_INCLUDED
#define ACTIVITY2_H_INCLUDED

/**
 * @brief ADC initialisation
 * 
 * 
 */
void ADC_Initialize(void);
/**
 * @brief Reads input from one of the channel
 * 
 * @return uint16_t 
 */
uint16_t ReadADC(uint8_t);


#endif // ACTIVITY2_H_INCLUDED
