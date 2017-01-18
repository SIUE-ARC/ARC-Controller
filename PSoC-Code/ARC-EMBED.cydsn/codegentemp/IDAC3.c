/*******************************************************************************
* File Name: IDAC3.c
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

#include "IDAC3.h"

uint32 IDAC3_initVar = 0u;


/*******************************************************************************
* Function Name: IDAC3_Init
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
void IDAC3_Init(void)
{
    uint32 regVal;
    uint8 enableInterrupts;

    /* Set initial configuration */
    enableInterrupts = CyEnterCriticalSection();
    
    #if(IDAC3_MODE_SOURCE == IDAC3_IDAC_POLARITY)
        regVal  = IDAC3_CSD_TRIM1_REG & ~(IDAC3_CSD_IDAC_TRIM1_MASK);
        regVal |=  (IDAC3_SFLASH_TRIM1_REG & IDAC3_CSD_IDAC_TRIM1_MASK);
        IDAC3_CSD_TRIM1_REG = regVal;
    #else
        regVal  = IDAC3_CSD_TRIM2_REG & ~(IDAC3_CSD_IDAC_TRIM2_MASK);
        regVal |=  (IDAC3_SFLASH_TRIM2_REG & IDAC3_CSD_IDAC_TRIM2_MASK);
        IDAC3_CSD_TRIM2_REG = regVal;
    #endif /* (IDAC3_MODE_SOURCE == IDAC3_IDAC_POLARITY) */

    /* clear previous values */
    IDAC3_IDAC_CONTROL_REG &= ((uint32)~((uint32)IDAC3_IDAC_VALUE_MASK <<
        IDAC3_IDAC_VALUE_POSITION)) | ((uint32)~((uint32)IDAC3_IDAC_MODE_MASK <<
        IDAC3_IDAC_MODE_POSITION))  | ((uint32)~((uint32)IDAC3_IDAC_RANGE_MASK  <<
        IDAC3_IDAC_RANGE_POSITION));

    IDAC3_IDAC_POLARITY_CONTROL_REG &= (~(uint32)((uint32)IDAC3_IDAC_POLARITY_MASK <<
        IDAC3_IDAC_POLARITY_POSITION));

    /* set new configuration */
    IDAC3_IDAC_CONTROL_REG |= (((uint32)IDAC3_IDAC_INIT_VALUE <<
        IDAC3_IDAC_VALUE_POSITION) | ((uint32)IDAC3_IDAC_RANGE <<
        IDAC3_IDAC_RANGE_POSITION));

    IDAC3_IDAC_POLARITY_CONTROL_REG |= ((uint32)IDAC3_IDAC_POLARITY <<
                                                           IDAC3_IDAC_POLARITY_POSITION);

    CyExitCriticalSection(enableInterrupts);

}


/*******************************************************************************
* Function Name: IDAC3_Enable
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
void IDAC3_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    /* Enable the IDAC */
    IDAC3_IDAC_CONTROL_REG |= ((uint32)IDAC3_IDAC_EN_MODE <<
                                                  IDAC3_IDAC_MODE_POSITION);
    IDAC3_IDAC_POLARITY_CONTROL_REG |= ((uint32)IDAC3_IDAC_CSD_EN <<
                                                           IDAC3_IDAC_CSD_EN_POSITION);
    CyExitCriticalSection(enableInterrupts);

}


/*******************************************************************************
* Function Name: IDAC3_Start
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
*  IDAC3_initVar
*
*******************************************************************************/
void IDAC3_Start(void)
{
    if(0u == IDAC3_initVar)
    {
        IDAC3_Init();
        IDAC3_initVar = 1u;
    }

    IDAC3_Enable();

}


/*******************************************************************************
* Function Name: IDAC3_Stop
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
void IDAC3_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    /* Disable the IDAC */
    IDAC3_IDAC_CONTROL_REG &= ((uint32)~((uint32)IDAC3_IDAC_MODE_MASK <<
        IDAC3_IDAC_MODE_POSITION));
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: IDAC3_SetValue
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
void IDAC3_SetValue(uint32 value)
{
    uint8 enableInterrupts;
    uint32 newRegisterValue;

    enableInterrupts = CyEnterCriticalSection();

    #if(IDAC3_IDAC_VALUE_POSITION != 0u)
        newRegisterValue = ((IDAC3_IDAC_CONTROL_REG & (~(uint32)((uint32)IDAC3_IDAC_VALUE_MASK <<
        IDAC3_IDAC_VALUE_POSITION))) | (value << IDAC3_IDAC_VALUE_POSITION));
    #else
        newRegisterValue = ((IDAC3_IDAC_CONTROL_REG & (~(uint32)IDAC3_IDAC_VALUE_MASK)) | value);
    #endif /* IDAC3_IDAC_VALUE_POSITION != 0u */

    IDAC3_IDAC_CONTROL_REG = newRegisterValue;

    CyExitCriticalSection(enableInterrupts);
}

/* [] END OF FILE */
