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
        c = (char) (UART_UartGetChar() & 0x000000FF);
        UART_BUFF[i] = c;
        /*if (c != 0) {
            //writeUART(&c, 1);
            switch (c & 0xf0) {
                case 0xf0:
                    writeUART("f", 1);
                    break;
                case 0xe0:
                    writeUART("e", 1);
                    break;
                case 0xd0:
                    writeUART("d", 1);
                    break;
                case 0xc0:
                    writeUART("c", 1);
                    break;
                case 0xb0:
                    writeUART("b", 1);
                    break;
                case 0xa0:
                    writeUART("a", 1);
                    break;
                case 0x90:
                    writeUART("9", 1);
                    break;
                case 0x80:
                    writeUART("8", 1);
                    break;
                case 0x70:
                    writeUART("7", 1);
                    break;
                case 0x60:
                    writeUART("6", 1);
                    break;
                case 0x50:
                    writeUART("5", 1);
                    break;
                case 0x40:
                    writeUART("4", 1);
                    break;
                case 0x30:
                    writeUART("3", 1);
                    break;
                case 0x20:
                    writeUART("2", 1);
                    break;
                case 0x10:
                    writeUART("1", 1);
                    break;
                case 0x00:
                    writeUART("0", 1);
                    break;
            }
            switch (c & 0x0f) {
                case 0xf:
                    writeUART("f", 1);
                    break;
                case 0xe:
                    writeUART("e", 1);
                    break;
                case 0xd:
                    writeUART("d", 1);
                    break;
                case 0xc:
                    writeUART("c", 1);
                    break;
                case 0xb:
                    writeUART("b", 1);
                    break;
                case 0xa:
                    writeUART("a", 1);
                    break;
                case 0x9:
                    writeUART("9", 1);
                    break;
                case 0x8:
                    writeUART("8", 1);
                    break;
                case 0x7:
                    writeUART("7", 1);
                    break;
                case 0x6:
                    writeUART("6", 1);
                    break;
                case 0x5:
                    writeUART("5", 1);
                    break;
                case 0x4:
                    writeUART("4", 1);
                    break;
                case 0x3:
                    writeUART("3", 1);
                    break;
                case 0x2:
                    writeUART("2", 1);
                    break;
                case 0x1:
                    writeUART("1", 1);
                    break;
                case 0x0:
                    writeUART("0", 1);
                    break;
            }
            writeUART(" ", 1);
        }*/
        i++;
    }
    while((c != TERMINATOR) && (i < RXBUFF_MAX));
    
    if((c != TERMINATOR) && (i == RXBUFF_MAX))
    {
        error_UART = 1;
        return -1;
    }
    
    if(i == 1) return 0;
    //else return writeUART("Hello", 5);
    else return writeUART(UART_BUFF, i);
}

char writeUART(char data[], byte size)
{
    byte i;
    
    if(size > TXBUFF_MAX) return -1;
    
    for(i = 0; i < size; i++)
    {
        UART_UartPutChar(data[i]);   
    }
    
    return 0;
}

char commandLookup(byte* data, byte size)
{
    return writeUART(data, size);
}
/* [] END OF FILE */
