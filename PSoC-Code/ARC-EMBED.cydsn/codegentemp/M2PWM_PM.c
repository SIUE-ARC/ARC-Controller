/*******************************************************************************
* File Name: M2PWM_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "M2PWM.h"

static M2PWM_BACKUP_STRUCT M2PWM_backup;


/*******************************************************************************
* Function Name: M2PWM_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void M2PWM_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: M2PWM_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void M2PWM_Sleep(void)
{
    if(0u != (M2PWM_BLOCK_CONTROL_REG & M2PWM_MASK))
    {
        M2PWM_backup.enableState = 1u;
    }
    else
    {
        M2PWM_backup.enableState = 0u;
    }

    M2PWM_Stop();
    M2PWM_SaveConfig();
}


/*******************************************************************************
* Function Name: M2PWM_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void M2PWM_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: M2PWM_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void M2PWM_Wakeup(void)
{
    M2PWM_RestoreConfig();

    if(0u != M2PWM_backup.enableState)
    {
        M2PWM_Enable();
    }
}


/* [] END OF FILE */
