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
#include "globaldefs.h"

hword adc_chan[8]; //membuffer containing the DMA controlled ADC samples
flag dacen[4]; //DAC enable flags
flag adcen; //ADC denable flag

void setDAC(byte num, byte val);
void enableDAC(byte num);
void disableADC();
/* [] END OF FILE */
