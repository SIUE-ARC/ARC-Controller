/*******************************************************************************
* File Name: IDAC2_PM.c
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

#include "IDAC2.h"


static IDAC2_BACKUP_STRUCT IDAC2_backup;


/*******************************************************************************
* Function Name: IDAC2_SaveConfig
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
void IDAC2_SaveConfig(void)
{
    /* All registers are retention - nothing to save */
}


/*******************************************************************************
* Function Name: IDAC2_Sleep
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
void IDAC2_Sleep(void)
{
        if(0u != (IDAC2_IDAC_CONTROL_REG & ((uint32)IDAC2_IDAC_MODE_MASK <<
        IDAC2_IDAC_MODE_POSITION)))
        {
            IDAC2_backup.enableState = 1u;
        }
        else
        {
            IDAC2_backup.enableState = 0u;
        }

    IDAC2_Stop();
    IDAC2_SaveConfig();
}


/*******************************************************************************
* Function Name: IDAC2_RestoreConfig
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
void IDAC2_RestoreConfig(void)
{
    /* All registers are retention - nothing to save */
}


/*******************************************************************************
* Function Name: IDAC2_Wakeup
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
void IDAC2_Wakeup(void)
{
    /* Restore IDAC register settings */
    IDAC2_RestoreConfig();
    if(IDAC2_backup.enableState == 1u)
    {
        /* Enable operation */
        IDAC2_Enable();
    } /* Do nothing if the component was disabled before */

}


/* [] END OF FILE */
