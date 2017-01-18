/*******************************************************************************
* File Name: QuadDec1_PM.c
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

#include "QuadDec1.h"

static QuadDec1_BACKUP_STRUCT QuadDec1_backup;


/*******************************************************************************
* Function Name: QuadDec1_SaveConfig
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
void QuadDec1_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: QuadDec1_Sleep
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
void QuadDec1_Sleep(void)
{
    if(0u != (QuadDec1_BLOCK_CONTROL_REG & QuadDec1_MASK))
    {
        QuadDec1_backup.enableState = 1u;
    }
    else
    {
        QuadDec1_backup.enableState = 0u;
    }

    QuadDec1_Stop();
    QuadDec1_SaveConfig();
}


/*******************************************************************************
* Function Name: QuadDec1_RestoreConfig
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
void QuadDec1_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: QuadDec1_Wakeup
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
void QuadDec1_Wakeup(void)
{
    QuadDec1_RestoreConfig();

    if(0u != QuadDec1_backup.enableState)
    {
        QuadDec1_Enable();
    }
}


/* [] END OF FILE */
