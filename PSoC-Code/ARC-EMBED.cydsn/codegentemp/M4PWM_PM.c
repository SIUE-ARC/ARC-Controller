/*******************************************************************************
* File Name: M4PWM_PM.c
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

#include "M4PWM.h"

static M4PWM_BACKUP_STRUCT M4PWM_backup;


/*******************************************************************************
* Function Name: M4PWM_SaveConfig
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
void M4PWM_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: M4PWM_Sleep
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
void M4PWM_Sleep(void)
{
    if(0u != (M4PWM_BLOCK_CONTROL_REG & M4PWM_MASK))
    {
        M4PWM_backup.enableState = 1u;
    }
    else
    {
        M4PWM_backup.enableState = 0u;
    }

    M4PWM_Stop();
    M4PWM_SaveConfig();
}


/*******************************************************************************
* Function Name: M4PWM_RestoreConfig
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
void M4PWM_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: M4PWM_Wakeup
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
void M4PWM_Wakeup(void)
{
    M4PWM_RestoreConfig();

    if(0u != M4PWM_backup.enableState)
    {
        M4PWM_Enable();
    }
}


/* [] END OF FILE */
