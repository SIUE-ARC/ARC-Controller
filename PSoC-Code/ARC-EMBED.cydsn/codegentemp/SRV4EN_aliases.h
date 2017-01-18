/*******************************************************************************
* File Name: SRV4EN.h  
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

#if !defined(CY_PINS_SRV4EN_ALIASES_H) /* Pins SRV4EN_ALIASES_H */
#define CY_PINS_SRV4EN_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define SRV4EN_0			(SRV4EN__0__PC)
#define SRV4EN_0_PS		(SRV4EN__0__PS)
#define SRV4EN_0_PC		(SRV4EN__0__PC)
#define SRV4EN_0_DR		(SRV4EN__0__DR)
#define SRV4EN_0_SHIFT	(SRV4EN__0__SHIFT)
#define SRV4EN_0_INTR	((uint16)((uint16)0x0003u << (SRV4EN__0__SHIFT*2u)))

#define SRV4EN_INTR_ALL	 ((uint16)(SRV4EN_0_INTR))


#endif /* End Pins SRV4EN_ALIASES_H */


/* [] END OF FILE */
