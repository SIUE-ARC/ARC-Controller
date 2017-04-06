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
#include <stdlib.h>
#include "motors.h"
#include "globaldefs.h"

#define     RXBUFF_MAX      64
#define     TXBUFF_MAX      64
#define     TERMINATOR      13
#define     OVERFLOW        1

#define     MOTOREN         'a'
#define     SETMOTOR        'b'
#define     SERVOEN         'c'
#define     SERVOPW         'd'
#define     COMMEN          'e'
#define     ANALOGR         'f'
#define     ANALOGW         'g'

#define     UART            0
#define     USB             1
#define     I2C             3

flag error_UART;
volatile flag moten[4];
volatile flag srven[4];
byte UART_BUFF[RXBUFF_MAX];
volatile byte mnum, mdir, mspd;
volatile byte snum;
volatile hword spw;

byte readUART();
byte writeUART(byte data[], byte size);
byte commandLookup(byte* data);

/* [] END OF FILE */