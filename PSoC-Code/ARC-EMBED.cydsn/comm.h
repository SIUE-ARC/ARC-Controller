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
#include "motors.h"
#include "typedefs.h"

#define     RXBUFF_MAX      64
#define     TXBUFF_MAX      64
#define     TERMINATOR      13
#define     OVERFLOW        1

flag error_UART;
byte UART_BUFF[RXBUFF_MAX];

byte readUART();
byte writeUART(byte data[], byte size);
byte commandLookup(byte* data, byte size);

/* [] END OF FILE */