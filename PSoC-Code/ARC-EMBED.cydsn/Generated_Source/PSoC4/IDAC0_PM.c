/*******************************************************************************
* File Name: IDAC0_PM.c
* Version 1.10
*
* Description:
*  This file provides Low power mode APIs for IDAC_P4 component.
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "IDAC0.h"


static IDAC0_BACKUP_STRUCT IDAC0_backup;


/*******************************************************************************
* Function Name: IDAC0_SaveConfig
********************************************************************************
*
* Summary:
*  Saves component state before sleep
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  None
*
*******************************************************************************/
void IDAC0_SaveConfig(void)
{
    /* All registers are retention - nothing to save */
}


/*******************************************************************************
* Function Name: IDAC0_Sleep
********************************************************************************
*
* Summary:
*  Calls _SaveConfig() function
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void IDAC0_Sleep(void)
{
        if(0u != (IDAC0_IDAC_CONTROL_REG & ((uint32)IDAC0_IDAC_MODE_MASK <<
        IDAC0_IDAC_MODE_POSITION)))
        {
            IDAC0_backup.enableState = 1u;
        }
        else
        {
            IDAC0_backup.enableState = 0u;
        }

    IDAC0_Stop();
    IDAC0_SaveConfig();
}


/*******************************************************************************
* Function Name: IDAC0_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores component state after wakeup
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  None
*
*******************************************************************************/
void IDAC0_RestoreConfig(void)
{
    /* All registers are retention - nothing to save */
}


/*******************************************************************************
* Function Name: IDAC0_Wakeup
********************************************************************************
*
* Summary:
*  Calls _RestoreConfig() function
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void IDAC0_Wakeup(void)
{
    /* Restore IDAC register settings */
    IDAC0_RestoreConfig();
    if(IDAC0_backup.enableState == 1u)
    {
        /* Enable operation */
        IDAC0_Enable();
    } /* Do nothing if the component was disabled before */

}


/* [] END OF FILE */
