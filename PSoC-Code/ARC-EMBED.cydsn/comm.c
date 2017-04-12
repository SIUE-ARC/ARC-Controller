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

/* readUart(void)
 * This function will grab non-null bytes from the UART buffer until the software
 * UART_BUFF is full, or a comman terminator is received. Once a command terminator
 * is received the command lookup function will be called on the software buffer.
*/
byte readUART()
{
    byte i = 0;
    char c = 0;
    
    do
    {
        c = (byte) UART_UartGetChar(); //read a byte
        if(c) //determine if byte is good
        {
            UART_BUFF[i] = c;
            i++;
        }
    }
    while((c != TERMINATOR) && (i < RXBUFF_MAX)); //wait for overflow or terminator
    
    if(i == RXBUFF_MAX) return OVERFLOW;
    
    return commandLookup(UART_BUFF);
}

/* writeUART(byte*, byte)
 * byte* data: a pointer to the memory buffer where the data to be written is located.
 * byte size: the size of the memory buffer to be written
 * This function will write a provided data buffer to the UART.
 * returns 0 when successful.
*/
byte writeUART(byte* data, byte size)
{
    for(i = 0; i < size; i++)
    {
        UART_UartPutChar(data[i]);   
    }
    
    return 0;
}

/* commandLookup(byte*)
 * byte* data: a pointer to the buffer containing the commands and parameters to be parsed.
 * This function will read the UART_BUFF and parse out the commands and parameter elements.
 * It will then call the appropriate function for the command that was specified.
 * returns 0 when successful.
*/
byte commandLookup(byte* data)
{
    byte comm = data[0];
    byte* params = &data[2];
    i = params[0];
    
    switch(comm)
    {
        case MOTOREN:
            if(moten[i])
            {
                #ifdef DEBUGGING
                writeUART("Disabling motor ", strlen("Disabling motor "));
                #endif
                stopMotor((byte)i);
                moten[i] = 0;
            }
            else
            {
                #ifdef DEBUGGING
                writeUART("Enabling motor ", strlen("Enabling motor "));
                #endif
                startMotor((byte)i);
                moten[i] = 1;
            }
            #ifdef DEBUGGING
            writeUART(&params[0], 1);
            writeUART("\r\n", 2);
            #endif
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
            mnum = (byte)atoi(&params[0]);
            mdir = (byte)atoi(&params[2]);
            mspd = (byte)atoi(&params[4]);
            setMotor(mnum, mdir, mspd);
            break;
        case SERVOEN:
            if(srven[atoi(params[0])])
            {
                #ifdef DEBUGGING
                writeUART("Disabling servo ", strlen("Disabling servo "));
                #endif
                stopServo((byte)atoi(params[0]));
                srven[atoi(params[0])] = 0;
            }
            else
            {
                #ifdef DEBUGGING
                writeUART("Enabling servo ", strlen("Enabling servo "));
                #endif
                startServo((byte)atoi(params[0]));
                srven[atoi(params[0])] = 1;
            }
            #ifdef DEBUGGING
            writeUART(&params[0], 1);
            writeUART("\r\n", 2);
            #endif
            break;
        case SERVOPW:
            snum = (byte)atoi(params[0]);
            spw = (hword)atoi(&params[2]);
            setServo(snum, spw);
        #ifdef DEBUGGING
            writeUART("Setting servo ", strlen("Setting servo "));
            writeUART(&params[0], 1);
            writeUART("\r\n", 2);
            writeUART("Pulse Width: ", strlen("Pulse Width: "));
            writeUART(&params[2], 4);
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

void disableComm(byte interface)
{
    switch(interface)
    {
        case UART:
            if(commen[UART])
            {
                UART_Stop();
                commen[UART] = 0;
            }
            else
            {
                UART_Start();
                commen[UART] = 1;
            }
            break;
        case I2C:
            if(commen[I2C])
            {
                I2C_Stop();
                commen[I2C] = 0;
            }
            else
            {
                I2C_Start();
                commen[I2C] = 1;
            }
            break;
        case USB:
            if(commen[USB])
            {
                USBFS_Stop();
                commen[USB] = 0;
            }
            else
            {
                USBFS_Start(USBFS_DEVICE, USBFS_5V_OPERATION);
                commen[USB] = 1;
            }
            break;
    }
}
/* [] END OF FILE */
