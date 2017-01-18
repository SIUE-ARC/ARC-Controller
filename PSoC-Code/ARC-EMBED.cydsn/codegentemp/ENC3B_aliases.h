/*******************************************************************************
* File Name: ENC3B.h  
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

#if !defined(CY_PINS_ENC3B_ALIASES_H) /* Pins ENC3B_ALIASES_H */
#define CY_PINS_ENC3B_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ENC3B_0			(ENC3B__0__PC)
#define ENC3B_0_PS		(ENC3B__0__PS)
#define ENC3B_0_PC		(ENC3B__0__PC)
#define ENC3B_0_DR		(ENC3B__0__DR)
#define ENC3B_0_SHIFT	(ENC3B__0__SHIFT)
#define ENC3B_0_INTR	((uint16)((uint16)0x0003u << (ENC3B__0__SHIFT*2u)))

#define ENC3B_INTR_ALL	 ((uint16)(ENC3B_0_INTR))


#endif /* End Pins ENC3B_ALIASES_H */


/* [] END OF FILE */
