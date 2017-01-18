/*******************************************************************************
* File Name: IDAC3_PM.c
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

#include "IDAC3.h"


static IDAC3_BACKUP_STRUCT IDAC3_backup;


/*******************************************************************************
* Function Name: IDAC3_SaveConfig
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
void IDAC3_SaveConfig(void)
{
    /* All registers are retention - nothing to save */
}


/*******************************************************************************
* Function Name: IDAC3_Sleep
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
void IDAC3_Sleep(void)
{
        if(0u != (IDAC3_IDAC_CONTROL_REG & ((uint32)IDAC3_IDAC_MODE_MASK <<
        IDAC3_IDAC_MODE_POSITION)))
        {
            IDAC3_backup.enableState = 1u;
        }
        else
        {
            IDAC3_backup.enableState = 0u;
        }

    IDAC3_Stop();
    IDAC3_SaveConfig();
}


/*******************************************************************************
* Function Name: IDAC3_RestoreConfig
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
void IDAC3_RestoreConfig(void)
{
    /* All registers are retention - nothing to save */
}


/*******************************************************************************
* Function Name: IDAC3_Wakeup
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
void IDAC3_Wakeup(void)
{
    /* Restore IDAC register settings */
    IDAC3_RestoreConfig();
    if(IDAC3_backup.enableState == 1u)
    {
        /* Enable operation */
        IDAC3_Enable();
    } /* Do nothing if the component was disabled before */

}


/* [] END OF FILE */
