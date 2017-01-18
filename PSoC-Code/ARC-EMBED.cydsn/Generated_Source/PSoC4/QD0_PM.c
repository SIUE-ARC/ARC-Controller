/*******************************************************************************
* File Name: QD0_PM.c
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

#include "QD0.h"

static QD0_BACKUP_STRUCT QD0_backup;


/*******************************************************************************
* Function Name: QD0_SaveConfig
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
void QD0_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: QD0_Sleep
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
void QD0_Sleep(void)
{
    if(0u != (QD0_BLOCK_CONTROL_REG & QD0_MASK))
    {
        QD0_backup.enableState = 1u;
    }
    else
    {
        QD0_backup.enableState = 0u;
    }

    QD0_Stop();
    QD0_SaveConfig();
}


/*******************************************************************************
* Function Name: QD0_RestoreConfig
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
void QD0_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: QD0_Wakeup
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
void QD0_Wakeup(void)
{
    QD0_RestoreConfig();

    if(0u != QD0_backup.enableState)
    {
        QD0_Enable();
    }
}


/* [] END OF FILE */
