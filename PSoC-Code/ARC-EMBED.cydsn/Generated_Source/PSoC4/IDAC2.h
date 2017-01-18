/*******************************************************************************
* File Name: IDAC2.h
* Version 1.10
*
* Description:
*  This file provides constants and parameter values for the IDAC_P4
*  component.
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_IDAC_IDAC2_H)
#define CY_IDAC_IDAC2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h"


/***************************************
* Internal Type defines
***************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} IDAC2_BACKUP_STRUCT;


extern uint32 IDAC2_initVar;

/**************************************
*    Enumerated Types and Parameters
**************************************/

/* IDAC polarity setting constants */
#define IDAC2__SOURCE 0
#define IDAC2__SINK 1


/* IDAC range setting constants */
#define IDAC2__LOWRANGE 0
#define IDAC2__HIGHRANGE 1


/* IDAC polarity setting definitions */
#define IDAC2_MODE_SOURCE    (IDAC2__SOURCE)
#define IDAC2_MODE_SINK      (IDAC2__SINK)

/* IDAC RANGE setting definitions */
#define IDAC2_MODE_LOWRANGE  (IDAC2__LOWRANGE)
#define IDAC2_MODE_HIGHRANGE (IDAC2__HIGHRANGE)

/***************************************
*   Conditional Compilation Parameters
****************************************/

#define IDAC2_IDAC_RESOLUTION    (7u)
#define IDAC2_IDAC_RANGE         (1u)
#define IDAC2_IDAC_POLARITY      (0u)


/***************************************
*    Initial Parameter Constants
***************************************/
#define IDAC2_IDAC_INIT_VALUE    (0u)




/***************************************
*        Function Prototypes
***************************************/

void IDAC2_Init(void);
void IDAC2_Enable(void);
void IDAC2_Start(void);
void IDAC2_Stop(void);
void IDAC2_SetValue(uint32  value);
void IDAC2_SaveConfig(void);
void IDAC2_Sleep(void);
void IDAC2_RestoreConfig(void);
void IDAC2_Wakeup(void);


/***************************************
*            API Constants
***************************************/

#define IDAC2_IDAC_EN_MODE           (3u)
#define IDAC2_IDAC_CSD_EN            (1u)
#define IDAC2_IDAC_CSD_EN_POSITION   (31u)

#define IDAC2_IDAC_VALUE_POSITION    (IDAC2_cy_psoc4_idac__CSD_IDAC_SHIFT)

#define IDAC2_IDAC_MODE_SHIFT        (8u)
#define IDAC2_IDAC_MODE_POSITION     ((uint32)IDAC2_cy_psoc4_idac__CSD_IDAC_SHIFT +\
                                                 IDAC2_IDAC_MODE_SHIFT)

#define IDAC2_IDAC_RANGE_SHIFT       (10u)
#define IDAC2_IDAC_RANGE_POSITION    ((uint32)IDAC2_cy_psoc4_idac__CSD_IDAC_SHIFT +\
                                                 IDAC2_IDAC_RANGE_SHIFT)

#define IDAC2_IDAC_POLARITY_POSITION ((uint32)IDAC2_cy_psoc4_idac__POLARITY_SHIFT)

#define IDAC2_IDAC_TRIM1_POSITION    ((uint32)IDAC2_cy_psoc4_idac__CSD_TRIM1_SHIFT)
#define IDAC2_IDAC_TRIM2_POSITION    ((uint32)IDAC2_cy_psoc4_idac__CSD_TRIM2_SHIFT)

#define IDAC2_IDAC_CDS_EN_MASK       (0x80000000u)

#if(IDAC2_IDAC_RESOLUTION == 8u)
  #define IDAC2_IDAC_VALUE_MASK      (0xFFu)
#else
  #define IDAC2_IDAC_VALUE_MASK      (0x7Fu)
#endif /* (IDAC2_IDAC_RESOLUTION == 8u) */

#define IDAC2_IDAC_MODE_MASK         (3u)
#define IDAC2_IDAC_RANGE_MASK        (1u)
#define IDAC2_IDAC_POLARITY_MASK     (1u)

#define IDAC2_CSD_IDAC_TRIM1_MASK    (0x0000000FuL << IDAC2_IDAC_TRIM1_POSITION)
#define IDAC2_CSD_IDAC_TRIM2_MASK    (0x0000000FuL << IDAC2_IDAC_TRIM2_POSITION)


/***************************************
*        Registers
***************************************/

#define IDAC2_IDAC_CONTROL_REG    (*(reg32 *)IDAC2_cy_psoc4_idac__CSD_IDAC)
#define IDAC2_IDAC_CONTROL_PTR    ( (reg32 *)IDAC2_cy_psoc4_idac__CSD_IDAC)

#define IDAC2_IDAC_POLARITY_CONTROL_REG    (*(reg32 *)IDAC2_cy_psoc4_idac__CONTROL)
#define IDAC2_IDAC_POLARITY_CONTROL_PTR    ( (reg32 *)IDAC2_cy_psoc4_idac__CONTROL)

#define IDAC2_CSD_TRIM1_REG       (*(reg32 *)IDAC2_cy_psoc4_idac__CSD_TRIM1)
#define IDAC2_CSD_TRIM1_PTR       ( (reg32 *)IDAC2_cy_psoc4_idac__CSD_TRIM1)

#define IDAC2_CSD_TRIM2_REG       (*(reg32 *)IDAC2_cy_psoc4_idac__CSD_TRIM2)
#define IDAC2_CSD_TRIM2_PTR       ( (reg32 *)IDAC2_cy_psoc4_idac__CSD_TRIM2)

#if (CY_PSOC4_4100M || CY_PSOC4_4200M)
    #if(IDAC2_cy_psoc4_idac__IDAC_NUMBER > 2u)
        #define IDAC2_SFLASH_TRIM1_REG       (*(reg8 *)CYREG_SFLASH_CSD1_TRIM1_HVIDAC)
        #define IDAC2_SFLASH_TRIM1_PTR       ( (reg8 *)CYREG_SFLASH_CSD1_TRIM1_HVIDAC)
        
        #define IDAC2_SFLASH_TRIM2_REG       (*(reg8 *)CYREG_SFLASH_CSD1_TRIM2_HVIDAC)
        #define IDAC2_SFLASH_TRIM2_PTR       ( (reg8 *)CYREG_SFLASH_CSD1_TRIM2_HVIDAC)
    #else
        #define IDAC2_SFLASH_TRIM1_REG       (*(reg8 *)CYREG_SFLASH_CSD_TRIM1_HVIDAC)
        #define IDAC2_SFLASH_TRIM1_PTR       ( (reg8 *)CYREG_SFLASH_CSD_TRIM1_HVIDAC)
        
        #define IDAC2_SFLASH_TRIM2_REG       (*(reg8 *)CYREG_SFLASH_CSD_TRIM2_HVIDAC)
        #define IDAC2_SFLASH_TRIM2_PTR       ( (reg8 *)CYREG_SFLASH_CSD_TRIM2_HVIDAC)
    #endif /* (IDAC2_cy_psoc4_idac__IDAC_NUMBER > 2u) */
#else
    #define IDAC2_SFLASH_TRIM1_REG       (*(reg8 *)CYREG_SFLASH_CSD_TRIM1_HVIDAC)
    #define IDAC2_SFLASH_TRIM1_PTR       ( (reg8 *)CYREG_SFLASH_CSD_TRIM1_HVIDAC)
    
    #define IDAC2_SFLASH_TRIM2_REG       (*(reg8 *)CYREG_SFLASH_CSD_TRIM2_HVIDAC)
    #define IDAC2_SFLASH_TRIM2_PTR       ( (reg8 *)CYREG_SFLASH_CSD_TRIM2_HVIDAC)
#endif /* (CY_PSOC4_4100M || CY_PSOC4_4200M) */

#endif /* CY_IDAC_IDAC2_H */

/* [] END OF FILE */
