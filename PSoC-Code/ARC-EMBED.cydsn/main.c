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

int main()
{
    int i;
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_Start();
    
    for(i = 0; i < 100000; i++);
    writeUART("Hello World!", 12);

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    while(1)
    {
        readUART();
    }
}

/* [] END OF FILE */
