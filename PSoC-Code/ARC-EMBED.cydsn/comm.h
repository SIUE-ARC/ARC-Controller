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
#include "analog.h"
#include "globaldefs.h"

/* USB device number. */
#define     USBFS_DEVICE    0u

/* Active endpoints of USB device. */
#define     IN_EP_NUM       1u
#define     OUT_EP_NUM      2u

/* Size of SRAM buffer to store endpoint data. */
#define     BUFFER_SIZE     64u


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
#define     ADCEN           'j'

#define     UART            0
#define     USB             1
#define     I2C             2

volatile flag moten[4];
volatile flag srven[4];
volatile flag commen[3];

byte UART_BUFF[RXBUFF_MAX];

volatile byte mnum, mdir, mspd;
volatile byte snum;
volatile hword spw;

byte readUART();
byte writeUART(byte data[], byte size);
byte commandLookup(byte* data);
void disableComm(byte interface);
void enableComm(byte interface);

/* [] END OF FILE */