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

hword adc_chan[8];
flag dacen[4];
flag adcen;

void setDAC(byte num, byte val);
void enableDAC(byte num);
void disableADC();
/* [] END OF FILE */
