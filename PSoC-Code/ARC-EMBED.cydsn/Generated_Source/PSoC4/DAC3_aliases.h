/*******************************************************************************
* File Name: DAC3.h  
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

#if !defined(CY_PINS_DAC3_ALIASES_H) /* Pins DAC3_ALIASES_H */
#define CY_PINS_DAC3_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define DAC3_0			(DAC3__0__PC)
#define DAC3_0_PS		(DAC3__0__PS)
#define DAC3_0_PC		(DAC3__0__PC)
#define DAC3_0_DR		(DAC3__0__DR)
#define DAC3_0_SHIFT	(DAC3__0__SHIFT)
#define DAC3_0_INTR	((uint16)((uint16)0x0003u << (DAC3__0__SHIFT*2u)))

#define DAC3_INTR_ALL	 ((uint16)(DAC3_0_INTR))


#endif /* End Pins DAC3_ALIASES_H */


/* [] END OF FILE */
