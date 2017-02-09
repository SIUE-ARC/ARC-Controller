/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "comm.h"

char readUART()
{
    byte i = 0;
    byte c = 0;
    error_UART = 0;
    
    do
    {
        c = UART_UartGetChar();
        UART_BUFF[i] = c;
        i++;
    }
    while(c && (i < RXBUFF_MAX));
    
    if(c && (i == RXBUFF_MAX))
    {
        error_UART = 1;
        return -1;
    }
    
    if(i == 1) return 0;
    else return commandLookup(UART_BUFF);
}

char writeUART(byte* data, byte size)
{
    byte i;
    
    if(size > TXBUFF_MAX) return -1;
    
    for(i = 0; i < size; i++)
    {
        UART_UartPutChar(data[i]);   
    }
    
    return 0;
}
/* [] END OF FILE */
