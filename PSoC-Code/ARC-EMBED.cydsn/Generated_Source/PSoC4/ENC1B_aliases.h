/*******************************************************************************
* File Name: ENC1B.h  
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

#if !defined(CY_PINS_ENC1B_ALIASES_H) /* Pins ENC1B_ALIASES_H */
#define CY_PINS_ENC1B_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ENC1B_0			(ENC1B__0__PC)
#define ENC1B_0_PS		(ENC1B__0__PS)
#define ENC1B_0_PC		(ENC1B__0__PC)
#define ENC1B_0_DR		(ENC1B__0__DR)
#define ENC1B_0_SHIFT	(ENC1B__0__SHIFT)
#define ENC1B_0_INTR	((uint16)((uint16)0x0003u << (ENC1B__0__SHIFT*2u)))

#define ENC1B_INTR_ALL	 ((uint16)(ENC1B_0_INTR))


#endif /* End Pins ENC1B_ALIASES_H */


/* [] END OF FILE */
