/*******************************************************************************
* File Name: QuadDec_4_PM.c
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

#include "QuadDec_4.h"

static QuadDec_4_BACKUP_STRUCT QuadDec_4_backup;


/*******************************************************************************
* Function Name: QuadDec_4_SaveConfig
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
void QuadDec_4_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: QuadDec_4_Sleep
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
void QuadDec_4_Sleep(void)
{
    if(0u != (QuadDec_4_BLOCK_CONTROL_REG & QuadDec_4_MASK))
    {
        QuadDec_4_backup.enableState = 1u;
    }
    else
    {
        QuadDec_4_backup.enableState = 0u;
    }

    QuadDec_4_Stop();
    QuadDec_4_SaveConfig();
}


/*******************************************************************************
* Function Name: QuadDec_4_RestoreConfig
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
void QuadDec_4_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: QuadDec_4_Wakeup
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
void QuadDec_4_Wakeup(void)
{
    QuadDec_4_RestoreConfig();

    if(0u != QuadDec_4_backup.enableState)
    {
        QuadDec_4_Enable();
    }
}


/* [] END OF FILE */
