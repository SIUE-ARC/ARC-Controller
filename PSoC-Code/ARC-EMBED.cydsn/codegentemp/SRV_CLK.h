/*******************************************************************************
* File Name: SRV_CLK.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_SRV_CLK_H)
#define CY_CLOCK_SRV_CLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void SRV_CLK_StartEx(uint32 alignClkDiv);
#define SRV_CLK_Start() \
    SRV_CLK_StartEx(SRV_CLK__PA_DIV_ID)

#else

void SRV_CLK_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void SRV_CLK_Stop(void);

void SRV_CLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 SRV_CLK_GetDividerRegister(void);
uint8  SRV_CLK_GetFractionalDividerRegister(void);

#define SRV_CLK_Enable()                         SRV_CLK_Start()
#define SRV_CLK_Disable()                        SRV_CLK_Stop()
#define SRV_CLK_SetDividerRegister(clkDivider, reset)  \
    SRV_CLK_SetFractionalDividerRegister((clkDivider), 0u)
#define SRV_CLK_SetDivider(clkDivider)           SRV_CLK_SetDividerRegister((clkDivider), 1u)
#define SRV_CLK_SetDividerValue(clkDivider)      SRV_CLK_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define SRV_CLK_DIV_ID     SRV_CLK__DIV_ID

#define SRV_CLK_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define SRV_CLK_CTRL_REG   (*(reg32 *)SRV_CLK__CTRL_REGISTER)
#define SRV_CLK_DIV_REG    (*(reg32 *)SRV_CLK__DIV_REGISTER)

#define SRV_CLK_CMD_DIV_SHIFT          (0u)
#define SRV_CLK_CMD_PA_DIV_SHIFT       (8u)
#define SRV_CLK_CMD_DISABLE_SHIFT      (30u)
#define SRV_CLK_CMD_ENABLE_SHIFT       (31u)

#define SRV_CLK_CMD_DISABLE_MASK       ((uint32)((uint32)1u << SRV_CLK_CMD_DISABLE_SHIFT))
#define SRV_CLK_CMD_ENABLE_MASK        ((uint32)((uint32)1u << SRV_CLK_CMD_ENABLE_SHIFT))

#define SRV_CLK_DIV_FRAC_MASK  (0x000000F8u)
#define SRV_CLK_DIV_FRAC_SHIFT (3u)
#define SRV_CLK_DIV_INT_MASK   (0xFFFFFF00u)
#define SRV_CLK_DIV_INT_SHIFT  (8u)

#else 

#define SRV_CLK_DIV_REG        (*(reg32 *)SRV_CLK__REGISTER)
#define SRV_CLK_ENABLE_REG     SRV_CLK_DIV_REG
#define SRV_CLK_DIV_FRAC_MASK  SRV_CLK__FRAC_MASK
#define SRV_CLK_DIV_FRAC_SHIFT (16u)
#define SRV_CLK_DIV_INT_MASK   SRV_CLK__DIVIDER_MASK
#define SRV_CLK_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_SRV_CLK_H) */

/* [] END OF FILE */
