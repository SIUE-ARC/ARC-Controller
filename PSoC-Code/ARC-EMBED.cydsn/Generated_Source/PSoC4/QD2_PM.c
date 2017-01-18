/*******************************************************************************
* File Name: QD2_PM.c
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

#include "QD2.h"

static QD2_BACKUP_STRUCT QD2_backup;


/*******************************************************************************
* Function Name: QD2_SaveConfig
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
void QD2_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: QD2_Sleep
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
void QD2_Sleep(void)
{
    if(0u != (QD2_BLOCK_CONTROL_REG & QD2_MASK))
    {
        QD2_backup.enableState = 1u;
    }
    else
    {
        QD2_backup.enableState = 0u;
    }

    QD2_Stop();
    QD2_SaveConfig();
}


/*******************************************************************************
* Function Name: QD2_RestoreConfig
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
void QD2_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: QD2_Wakeup
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
void QD2_Wakeup(void)
{
    QD2_RestoreConfig();

    if(0u != QD2_backup.enableState)
    {
        QD2_Enable();
    }
}


/* [] END OF FILE */
