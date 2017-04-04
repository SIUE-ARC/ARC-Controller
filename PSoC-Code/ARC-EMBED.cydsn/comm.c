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

byte readUART()
{
    byte i = 0;
    char c = 0;
    error_UART = 0;
    
    do
    {
        c = (byte) UART_UartGetChar();
        if(c)
        {
            UART_BUFF[i] = c;
            i++;
        }
    }
    while((c != TERMINATOR) && (i < RXBUFF_MAX));
    
    if(i == RXBUFF_MAX) return OVERFLOW;
    
    return commandLookup(UART_BUFF);
}

byte writeUART(byte* data, byte size)
{
    byte j;
    
    for(j = 0; j < size; j++)
    {
        UART_UartPutChar(data[j]);   
    }
    
    return 0;
}

byte commandLookup(byte* data)
{
    byte comm = data[0];
    byte* params = &data[2];
    
    switch(comm)
    {
        case MOTOREN:
        #ifdef DEBUGGING
            writeUART("Enabling motor ", strlen("Enabling motor "));
            writeUART(&params[0], 1);
            writeUART("\r\n", 2);
        #endif
            startMotor((byte)atoi(params[0]));
            break;
        case SETMOTOR:
        #ifdef DEBUGGING
            writeUART("Setting motor ", strlen("Setting motor "));
            writeUART(&params[0], 1);
            writeUART("\r\n", 2);
            writeUART(" Dir: ", strlen(" Dir: "));
            writeUART(&params[2], 1);
            writeUART(" Speed: ", strlen(" Speed: "));
            writeUART(&params[4], strlen(&params[4]));
            writeUART("\r\n", 2);
        #endif
            mnum = (byte)atoi(params[0]);
            mdir = (byte)atoi(params[2]);
            mspd = (byte)atoi(&params[4]);
            setMotor(mnum, mdir, mspd);
            break;
        case SERVOEN:
        #ifdef DEBUGGING
            writeUART("Enabling servo ", strlen("Enabling servo "));
            writeUART(&params[0], 1);
            writeUART("\r\n", 2);
        #endif
            startServo((byte)atoi(params[0]));
            break;
        case SERVOPW:
            snum = params[0];
            spw = (hword) atoi(&params[2]);
            setServo(snum, spw);
        #ifdef DEBUGGING
            writeUART("Setting servo ", strlen("Setting servo "));
            writeUART(itoa(params[0], &params[1], 10), 1);
            writeUART("\r\n", 2);
            writeUART("Pulse Width: ", strlen("Pulse Width: "));
            writeUART(itoa(spw, &params[10], 10), 1);
        #endif
            break;
        case COMMEN:
            break;
        case ANALOGR:
            break;
        case ANALOGW:
            break;
    }
    
    return 0;
}
/* [] END OF FILE */
