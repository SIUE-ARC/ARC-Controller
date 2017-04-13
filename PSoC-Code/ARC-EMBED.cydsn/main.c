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
#include "comm.h"


/* Main routine:
 * perform PID on each motor
 * check all available interfaces for data
 * perform actions on data
 * repeat
*/

void init()
{
    ADC_DMA_Start((void*)ADC_SAR_CHAN0_RESULT_PTR, &adc_chan);
    UART_Start();
    USBFS_Start(USBFS_DEVICE, USBFS_5V_OPERATION);
    I2C_Start();
    resolution = PI*wheel_diam/encoder_res;
    writeUART("Hello, world!\r\n", strlen("Hello, world!\r\n"));
}

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    while(1)
    {
        readUART();
    }
}

/* [] END OF FILE */
