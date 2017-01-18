/*******************************************************************************
* File Name: QuadDec_2_PM.c
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

#include "QuadDec_2.h"

static QuadDec_2_BACKUP_STRUCT QuadDec_2_backup;


/*******************************************************************************
* Function Name: QuadDec_2_SaveConfig
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
void QuadDec_2_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: QuadDec_2_Sleep
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
void QuadDec_2_Sleep(void)
{
    if(0u != (QuadDec_2_BLOCK_CONTROL_REG & QuadDec_2_MASK))
    {
        QuadDec_2_backup.enableState = 1u;
    }
    else
    {
        QuadDec_2_backup.enableState = 0u;
    }

    QuadDec_2_Stop();
    QuadDec_2_SaveConfig();
}


/*******************************************************************************
* Function Name: QuadDec_2_RestoreConfig
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
void QuadDec_2_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: QuadDec_2_Wakeup
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
void QuadDec_2_Wakeup(void)
{
    QuadDec_2_RestoreConfig();

    if(0u != QuadDec_2_backup.enableState)
    {
        QuadDec_2_Enable();
    }
}


/* [] END OF FILE */
