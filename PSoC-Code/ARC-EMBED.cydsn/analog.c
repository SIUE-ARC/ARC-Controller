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
#include "analog.h"

/* setDac(byte, byte)
 * byte num: the DAC number to be set.
 * byte val: the value to write to the DAC reg.
 * This funciton writes a value to the chosen DAC register.
 * NOTE: DAC2 and DAC3 are 7-bit
*/
void setDAC(byte num, byte val)
{
    switch(num)
    {
        case 0:
            IDAC0_SetValue(val);
            break;
        case 1:
            IDAC1_SetValue(val);
            break;
        case 2:
            IDAC2_SetValue(val);
            break;
        case 3:
            IDAC3_SetValue(val);
            break;
    }
}

/* enableDac(byte)
 * byte num: the DAC number to toggle
 * Enables/Disables a selected DAC.
*/
void enableDAC(byte num)
{
    switch(num)
    {
        case 0:
            if(dacen[0])
            {
                IDAC0_Stop();
                dacen[0] = 0;
            }
            else
            {
                IDAC0_Start();
                dacen[0] = 1;
            }
            break;
        case 1:
            if(dacen[1])
            {
                IDAC1_Stop();
                dacen[1] = 0;
            }
            else
            {
                IDAC1_Start();
                dacen[1] = 1;
            }
            break;
        case 2:
            if(dacen[2])
            {
                IDAC2_Stop();
                dacen[2] = 0;
            }
            else
            {
                IDAC2_Start();
                dacen[2] = 1;
            }
            break;
        case 3:
            if(dacen[3])
            {
                IDAC3_Stop();
                dacen[3] = 0;
            }
            else
            {
                IDAC3_Start();
                dacen[3] = 1;
            }
            break;
    }   
}

/* enableADC(void)
 * This function disables the SAR ADC.
 * NOTE: This disables all channels; Since the channels are multiplexed
 * disabling a channel is the same as not using it, making it redundant.
*/
void enableADC()
{
    if(adcen)
    {
        adcen =0;
        ADC_Stop();
    }
    else
    {
        adcen = 1;
        ADC_Start();
    }
}
/* [] END OF FILE */
