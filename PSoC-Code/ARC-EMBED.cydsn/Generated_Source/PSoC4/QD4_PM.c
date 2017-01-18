/*******************************************************************************
* File Name: QD4_PM.c
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

#include "QD4.h"

static QD4_BACKUP_STRUCT QD4_backup;


/*******************************************************************************
* Function Name: QD4_SaveConfig
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
void QD4_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: QD4_Sleep
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
void QD4_Sleep(void)
{
    if(0u != (QD4_BLOCK_CONTROL_REG & QD4_MASK))
    {
        QD4_backup.enableState = 1u;
    }
    else
    {
        QD4_backup.enableState = 0u;
    }

    QD4_Stop();
    QD4_SaveConfig();
}


/*******************************************************************************
* Function Name: QD4_RestoreConfig
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
void QD4_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: QD4_Wakeup
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
void QD4_Wakeup(void)
{
    QD4_RestoreConfig();

    if(0u != QD4_backup.enableState)
    {
        QD4_Enable();
    }
}


/* [] END OF FILE */
