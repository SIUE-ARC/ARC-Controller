/*******************************************************************************
* File Name: IDAC2.c
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

#include "IDAC2.h"

uint32 IDAC2_initVar = 0u;


/*******************************************************************************
* Function Name: IDAC2_Init
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
void IDAC2_Init(void)
{
    uint32 regVal;
    uint8 enableInterrupts;

    /* Set initial configuration */
    enableInterrupts = CyEnterCriticalSection();
    
    #if(IDAC2_MODE_SOURCE == IDAC2_IDAC_POLARITY)
        regVal  = IDAC2_CSD_TRIM1_REG & ~(IDAC2_CSD_IDAC_TRIM1_MASK);
        regVal |=  (IDAC2_SFLASH_TRIM1_REG & IDAC2_CSD_IDAC_TRIM1_MASK);
        IDAC2_CSD_TRIM1_REG = regVal;
    #else
        regVal  = IDAC2_CSD_TRIM2_REG & ~(IDAC2_CSD_IDAC_TRIM2_MASK);
        regVal |=  (IDAC2_SFLASH_TRIM2_REG & IDAC2_CSD_IDAC_TRIM2_MASK);
        IDAC2_CSD_TRIM2_REG = regVal;
    #endif /* (IDAC2_MODE_SOURCE == IDAC2_IDAC_POLARITY) */

    /* clear previous values */
    IDAC2_IDAC_CONTROL_REG &= ((uint32)~((uint32)IDAC2_IDAC_VALUE_MASK <<
        IDAC2_IDAC_VALUE_POSITION)) | ((uint32)~((uint32)IDAC2_IDAC_MODE_MASK <<
        IDAC2_IDAC_MODE_POSITION))  | ((uint32)~((uint32)IDAC2_IDAC_RANGE_MASK  <<
        IDAC2_IDAC_RANGE_POSITION));

    IDAC2_IDAC_POLARITY_CONTROL_REG &= (~(uint32)((uint32)IDAC2_IDAC_POLARITY_MASK <<
        IDAC2_IDAC_POLARITY_POSITION));

    /* set new configuration */
    IDAC2_IDAC_CONTROL_REG |= (((uint32)IDAC2_IDAC_INIT_VALUE <<
        IDAC2_IDAC_VALUE_POSITION) | ((uint32)IDAC2_IDAC_RANGE <<
        IDAC2_IDAC_RANGE_POSITION));

    IDAC2_IDAC_POLARITY_CONTROL_REG |= ((uint32)IDAC2_IDAC_POLARITY <<
                                                           IDAC2_IDAC_POLARITY_POSITION);

    CyExitCriticalSection(enableInterrupts);

}


/*******************************************************************************
* Function Name: IDAC2_Enable
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
void IDAC2_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    /* Enable the IDAC */
    IDAC2_IDAC_CONTROL_REG |= ((uint32)IDAC2_IDAC_EN_MODE <<
                                                  IDAC2_IDAC_MODE_POSITION);
    IDAC2_IDAC_POLARITY_CONTROL_REG |= ((uint32)IDAC2_IDAC_CSD_EN <<
                                                           IDAC2_IDAC_CSD_EN_POSITION);
    CyExitCriticalSection(enableInterrupts);

}


/*******************************************************************************
* Function Name: IDAC2_Start
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
*  IDAC2_initVar
*
*******************************************************************************/
void IDAC2_Start(void)
{
    if(0u == IDAC2_initVar)
    {
        IDAC2_Init();
        IDAC2_initVar = 1u;
    }

    IDAC2_Enable();

}


/*******************************************************************************
* Function Name: IDAC2_Stop
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
void IDAC2_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    /* Disable the IDAC */
    IDAC2_IDAC_CONTROL_REG &= ((uint32)~((uint32)IDAC2_IDAC_MODE_MASK <<
        IDAC2_IDAC_MODE_POSITION));
    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: IDAC2_SetValue
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
void IDAC2_SetValue(uint32 value)
{
    uint8 enableInterrupts;
    uint32 newRegisterValue;

    enableInterrupts = CyEnterCriticalSection();

    #if(IDAC2_IDAC_VALUE_POSITION != 0u)
        newRegisterValue = ((IDAC2_IDAC_CONTROL_REG & (~(uint32)((uint32)IDAC2_IDAC_VALUE_MASK <<
        IDAC2_IDAC_VALUE_POSITION))) | (value << IDAC2_IDAC_VALUE_POSITION));
    #else
        newRegisterValue = ((IDAC2_IDAC_CONTROL_REG & (~(uint32)IDAC2_IDAC_VALUE_MASK)) | value);
    #endif /* IDAC2_IDAC_VALUE_POSITION != 0u */

    IDAC2_IDAC_CONTROL_REG = newRegisterValue;

    CyExitCriticalSection(enableInterrupts);
}

/* [] END OF FILE */
