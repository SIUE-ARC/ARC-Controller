/*******************************************************************************
* File Name: IDAC0.c
* Version 1.10
*
* Description:
*  This file provides the source code of APIs for the IDAC_P4 component.
*
*******************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "IDAC0.h"

uint32 IDAC0_initVar = 0u;


/*******************************************************************************
* Function Name: IDAC0_Init
********************************************************************************
*
* Summary:
*  Initializes IDAC registers with initial values provided from customizer.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  None
*
*******************************************************************************/
void IDAC0_Init(void)
{
    uint32 regVal;
    uint8 enableInterrupts;

    /* Set initial configuration */
    enableInterrupts = CyEnterCriticalSection();
    
    #if(IDAC0_MODE_SOURCE == IDAC0_IDAC_POLARITY)
        regVal  = IDAC0_CSD_TRIM1_REG & ~(IDAC0_CSD_IDAC_TRIM1_MASK);
        regVal |=  (IDAC0_SFLASH_TRIM1_REG & IDAC0_CSD_IDAC_TRIM1_MASK);
        IDAC0_CSD_TRIM1_REG = regVal;
    #else
        regVal  = IDAC0_CSD_TRIM2_REG & ~(IDAC0_CSD_IDAC_TRIM2_MASK);
        regVal |=  (IDAC0_SFLASH_TRIM2_REG & IDAC0_CSD_IDAC_TRIM2_MASK);
        IDAC0_CSD_TRIM2_REG = regVal;
    #endif /* (IDAC0_MODE_SOURCE == IDAC0_IDAC_POLARITY) */

    /* clear previous values */
    IDAC0_IDAC_CONTROL_REG &= ((uint32)~((uint32)IDAC0_IDAC_VALUE_MASK <<
        IDAC0_IDAC_VALUE_POSITION)) | ((uint32)~((uint32)IDAC0_IDAC_MODE_MASK <<
        IDAC0_IDAC_MODE_POSITION))  | ((uint32)~((uint32)IDAC0_IDAC_RANGE_MASK  <<
        IDAC0_IDAC_RANGE_POSITION));

    IDAC0_IDAC_POLARITY_CONTROL_REG &= (~(uint32)((uint32)IDAC0_IDAC_POLARITY_MASK <<
        IDAC0_IDAC_POLARITY_POSITION));

    /* set new configuration */
    IDAC0_IDAC_CONTROL_REG |= (((uint32)IDAC0_IDAC_INIT_VALUE <<
        IDAC0_IDAC_VALUE_POSITION) | ((uint32)IDAC0_IDAC_RANGE <<
        IDAC0_IDAC_RANGE_POSITION));

    IDAC0_IDAC_POLARITY_CONTROL_REG |= ((uint32)IDAC0_IDAC_POLARITY <<
                                                           IDAC0_IDAC_POLARITY_POSITION);

    CyExitCriticalSection(enableInterrupts);

}


/*******************************************************************************
* Function Name: IDAC0_Enable
********************************************************************************
*
* Summary:
*  Enables IDAC operations.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  None
*
*******************************************************************************/
void IDAC0_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    /* Enable the IDAC */
    IDAC0_IDAC_CONTROL_REG |= ((uint32)IDAC0_IDAC_EN_MODE <<
                                                  IDAC0_IDAC_MODE_POSITION);
    IDAC0_IDAC_POLARITY_CONTROL_REG |= ((uint32)IDAC0_IDAC_CSD_EN <<
                                                           IDAC0_IDAC_CSD_EN_POSITION);
    CyExitCriticalSection(enableInterrupts);

}


/*******************************************************************************
* Function Name: IDAC0_Start
********************************************************************************
*
* Summary:
*  Starts the IDAC hardware.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  IDAC0_initVar
*
*******************************************************************************/
void IDAC0_Start(void)
{
    if(0u == IDAC0_initVar)
    {
        IDAC0_Init();
        IDAC0_initVar = 1u;
    }

    IDAC0_Enable();

}


/*******************************************************************************
* Function Name: IDAC0_Stop
********************************************************************************
*
* Summary:
*  Stops the IDAC hardware.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  None
*
*******************************************************************************/
void IDAC0_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    /* Disable the IDAC */
    IDAC0_IDAC_CONTROL_REG &= ((uint32)~((uint32)IDAC0_IDAC_MODE_MASK <<
        IDAC0_IDAC_MODE_POSITION));
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: IDAC0_SetValue
********************************************************************************
*
* Summary:
*  Sets the IDAC value.
*
* Parameters:
*  uint32 value
*
* Return:
*  None
*
* Global variables:
*  None
*
*******************************************************************************/
void IDAC0_SetValue(uint32 value)
{
    uint8 enableInterrupts;
    uint32 newRegisterValue;

    enableInterrupts = CyEnterCriticalSection();

    #if(IDAC0_IDAC_VALUE_POSITION != 0u)
        newRegisterValue = ((IDAC0_IDAC_CONTROL_REG & (~(uint32)((uint32)IDAC0_IDAC_VALUE_MASK <<
        IDAC0_IDAC_VALUE_POSITION))) | (value << IDAC0_IDAC_VALUE_POSITION));
    #else
        newRegisterValue = ((IDAC0_IDAC_CONTROL_REG & (~(uint32)IDAC0_IDAC_VALUE_MASK)) | value);
    #endif /* IDAC0_IDAC_VALUE_POSITION != 0u */

    IDAC0_IDAC_CONTROL_REG = newRegisterValue;

    CyExitCriticalSection(enableInterrupts);
}

/* [] END OF FILE */
