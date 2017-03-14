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
    char c = 0;
    error_UART = 0;
    
    do
    {
        c = (char) UART_UartGetChar();
        if(c)
        {
            UART_BUFF[i] = c;
            i++;
        }
    }
    while((c != TERMINATOR) && (i < RXBUFF_MAX));
    
    if(i == RXBUFF_MAX) return OVERFLOW;
    
    return writeUART(UART_BUFF, i);
}

char writeUART(char* data, byte size)
{
    byte j;
    
    for(j = 0; j < size; j++)
    {
        UART_UartPutChar(data[j]);   
    }
    
    return 0;
}

char commandLookup(byte* data, byte size)
{
    return writeUART(data, size);
}
/* [] END OF FILE */
