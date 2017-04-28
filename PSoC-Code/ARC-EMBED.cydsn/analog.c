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
