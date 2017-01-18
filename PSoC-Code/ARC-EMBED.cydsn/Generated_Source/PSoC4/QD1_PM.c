/*******************************************************************************
* File Name: QD1_PM.c
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

#include "QD1.h"

static QD1_BACKUP_STRUCT QD1_backup;


/*******************************************************************************
* Function Name: QD1_SaveConfig
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
void QD1_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: QD1_Sleep
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
void QD1_Sleep(void)
{
    if(0u != (QD1_BLOCK_CONTROL_REG & QD1_MASK))
    {
        QD1_backup.enableState = 1u;
    }
    else
    {
        QD1_backup.enableState = 0u;
    }

    QD1_Stop();
    QD1_SaveConfig();
}


/*******************************************************************************
* Function Name: QD1_RestoreConfig
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
void QD1_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: QD1_Wakeup
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
void QD1_Wakeup(void)
{
    QD1_RestoreConfig();

    if(0u != QD1_backup.enableState)
    {
        QD1_Enable();
    }
}


/* [] END OF FILE */
