/*******************************************************************************
* File Name: IDAC1_PM.c
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

#include "IDAC1.h"


static IDAC1_BACKUP_STRUCT IDAC1_backup;


/*******************************************************************************
* Function Name: IDAC1_SaveConfig
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
void IDAC1_SaveConfig(void)
{
    /* All registers are retention - nothing to save */
}


/*******************************************************************************
* Function Name: IDAC1_Sleep
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
void IDAC1_Sleep(void)
{
        if(0u != (IDAC1_IDAC_CONTROL_REG & ((uint32)IDAC1_IDAC_MODE_MASK <<
        IDAC1_IDAC_MODE_POSITION)))
        {
            IDAC1_backup.enableState = 1u;
        }
        else
        {
            IDAC1_backup.enableState = 0u;
        }

    IDAC1_Stop();
    IDAC1_SaveConfig();
}


/*******************************************************************************
* Function Name: IDAC1_RestoreConfig
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
void IDAC1_RestoreConfig(void)
{
    /* All registers are retention - nothing to save */
}


/*******************************************************************************
* Function Name: IDAC1_Wakeup
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
void IDAC1_Wakeup(void)
{
    /* Restore IDAC register settings */
    IDAC1_RestoreConfig();
    if(IDAC1_backup.enableState == 1u)
    {
        /* Enable operation */
        IDAC1_Enable();
    } /* Do nothing if the component was disabled before */

}


/* [] END OF FILE */
