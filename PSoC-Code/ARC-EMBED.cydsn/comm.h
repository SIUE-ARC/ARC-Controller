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

#include <project.h>
#include "typedefs.h"

#define     RXBUFF_MAX      64
#define     TXBUFF_MAX      64
#define     TERMINATOR      13

flag error_UART;
char UART_BUFF[RXBUFF_MAX];

char readUART();
char writeUART(char data[], byte size);
char commandLookup(byte* data, byte size);

/* [] END OF FILE */