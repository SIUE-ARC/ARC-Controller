/*******************************************************************************
* File Name: TCPWM_CLK.h
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

#if !defined(CY_CLOCK_TCPWM_CLK_H)
#define CY_CLOCK_TCPWM_CLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void TCPWM_CLK_StartEx(uint32 alignClkDiv);
#define TCPWM_CLK_Start() \
    TCPWM_CLK_StartEx(TCPWM_CLK__PA_DIV_ID)

#else

void TCPWM_CLK_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void TCPWM_CLK_Stop(void);

void TCPWM_CLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 TCPWM_CLK_GetDividerRegister(void);
uint8  TCPWM_CLK_GetFractionalDividerRegister(void);

#define TCPWM_CLK_Enable()                         TCPWM_CLK_Start()
#define TCPWM_CLK_Disable()                        TCPWM_CLK_Stop()
#define TCPWM_CLK_SetDividerRegister(clkDivider, reset)  \
    TCPWM_CLK_SetFractionalDividerRegister((clkDivider), 0u)
#define TCPWM_CLK_SetDivider(clkDivider)           TCPWM_CLK_SetDividerRegister((clkDivider), 1u)
#define TCPWM_CLK_SetDividerValue(clkDivider)      TCPWM_CLK_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define TCPWM_CLK_DIV_ID     TCPWM_CLK__DIV_ID

#define TCPWM_CLK_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define TCPWM_CLK_CTRL_REG   (*(reg32 *)TCPWM_CLK__CTRL_REGISTER)
#define TCPWM_CLK_DIV_REG    (*(reg32 *)TCPWM_CLK__DIV_REGISTER)

#define TCPWM_CLK_CMD_DIV_SHIFT          (0u)
#define TCPWM_CLK_CMD_PA_DIV_SHIFT       (8u)
#define TCPWM_CLK_CMD_DISABLE_SHIFT      (30u)
#define TCPWM_CLK_CMD_ENABLE_SHIFT       (31u)

#define TCPWM_CLK_CMD_DISABLE_MASK       ((uint32)((uint32)1u << TCPWM_CLK_CMD_DISABLE_SHIFT))
#define TCPWM_CLK_CMD_ENABLE_MASK        ((uint32)((uint32)1u << TCPWM_CLK_CMD_ENABLE_SHIFT))

#define TCPWM_CLK_DIV_FRAC_MASK  (0x000000F8u)
#define TCPWM_CLK_DIV_FRAC_SHIFT (3u)
#define TCPWM_CLK_DIV_INT_MASK   (0xFFFFFF00u)
#define TCPWM_CLK_DIV_INT_SHIFT  (8u)

#else 

#define TCPWM_CLK_DIV_REG        (*(reg32 *)TCPWM_CLK__REGISTER)
#define TCPWM_CLK_ENABLE_REG     TCPWM_CLK_DIV_REG
#define TCPWM_CLK_DIV_FRAC_MASK  TCPWM_CLK__FRAC_MASK
#define TCPWM_CLK_DIV_FRAC_SHIFT (16u)
#define TCPWM_CLK_DIV_INT_MASK   TCPWM_CLK__DIVIDER_MASK
#define TCPWM_CLK_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_TCPWM_CLK_H) */

/* [] END OF FILE */
