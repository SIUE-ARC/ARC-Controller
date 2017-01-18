/*******************************************************************************
* File Name: ENC4B.h  
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

#if !defined(CY_PINS_ENC4B_ALIASES_H) /* Pins ENC4B_ALIASES_H */
#define CY_PINS_ENC4B_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ENC4B_0			(ENC4B__0__PC)
#define ENC4B_0_PS		(ENC4B__0__PS)
#define ENC4B_0_PC		(ENC4B__0__PC)
#define ENC4B_0_DR		(ENC4B__0__DR)
#define ENC4B_0_SHIFT	(ENC4B__0__SHIFT)
#define ENC4B_0_INTR	((uint16)((uint16)0x0003u << (ENC4B__0__SHIFT*2u)))

#define ENC4B_INTR_ALL	 ((uint16)(ENC4B_0_INTR))


#endif /* End Pins ENC4B_ALIASES_H */


/* [] END OF FILE */
