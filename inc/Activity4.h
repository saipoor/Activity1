#ifndef ACTIVITY4_H_INCLUDED
#define ACTIVITY4_H_INCLUDED
/**
 * @brief USART initialisation
 * 
 */
void USART_initialize(uint16_t);
/**
 * @brief Reads message
 * 
 * @return char 
 */
char USARTReadmsg();
/**
 * @brief write message
 * 
 */
void USARTWritemsg(uint16_t);
#endif 
