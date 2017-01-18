/*******************************************************************************
* File Name: DAC0.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_DAC0_ALIASES_H) /* Pins DAC0_ALIASES_H */
#define CY_PINS_DAC0_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define DAC0_0			(DAC0__0__PC)
#define DAC0_0_PS		(DAC0__0__PS)
#define DAC0_0_PC		(DAC0__0__PC)
#define DAC0_0_DR		(DAC0__0__DR)
#define DAC0_0_SHIFT	(DAC0__0__SHIFT)
#define DAC0_0_INTR	((uint16)((uint16)0x0003u << (DAC0__0__SHIFT*2u)))

#define DAC0_INTR_ALL	 ((uint16)(DAC0_0_INTR))


#endif /* End Pins DAC0_ALIASES_H */


/* [] END OF FILE */
