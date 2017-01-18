/*******************************************************************************
* File Name: M0PWM_PM.c
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

#include "M0PWM.h"

static M0PWM_BACKUP_STRUCT M0PWM_backup;


/*******************************************************************************
* Function Name: M0PWM_SaveConfig
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
void M0PWM_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: M0PWM_Sleep
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
void M0PWM_Sleep(void)
{
    if(0u != (M0PWM_BLOCK_CONTROL_REG & M0PWM_MASK))
    {
        M0PWM_backup.enableState = 1u;
    }
    else
    {
        M0PWM_backup.enableState = 0u;
    }

    M0PWM_Stop();
    M0PWM_SaveConfig();
}


/*******************************************************************************
* Function Name: M0PWM_RestoreConfig
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
void M0PWM_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: M0PWM_Wakeup
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
void M0PWM_Wakeup(void)
{
    M0PWM_RestoreConfig();

    if(0u != M0PWM_backup.enableState)
    {
        M0PWM_Enable();
    }
}


/* [] END OF FILE */
