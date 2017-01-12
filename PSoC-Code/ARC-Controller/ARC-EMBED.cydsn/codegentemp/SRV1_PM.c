/*******************************************************************************
* File Name: SRV1_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SRV1.h"

static SRV1_backupStruct SRV1_backup;


/*******************************************************************************
* Function Name: SRV1_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SRV1_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void SRV1_SaveConfig(void) 
{

    #if(!SRV1_UsingFixedFunction)
        #if(!SRV1_PWMModeIsCenterAligned)
            SRV1_backup.PWMPeriod = SRV1_ReadPeriod();
        #endif /* (!SRV1_PWMModeIsCenterAligned) */
        SRV1_backup.PWMUdb = SRV1_ReadCounter();
        #if (SRV1_UseStatus)
            SRV1_backup.InterruptMaskValue = SRV1_STATUS_MASK;
        #endif /* (SRV1_UseStatus) */

        #if(SRV1_DeadBandMode == SRV1__B_PWM__DBM_256_CLOCKS || \
            SRV1_DeadBandMode == SRV1__B_PWM__DBM_2_4_CLOCKS)
            SRV1_backup.PWMdeadBandValue = SRV1_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(SRV1_KillModeMinTime)
             SRV1_backup.PWMKillCounterPeriod = SRV1_ReadKillTime();
        #endif /* (SRV1_KillModeMinTime) */

        #if(SRV1_UseControl)
            SRV1_backup.PWMControlRegister = SRV1_ReadControlRegister();
        #endif /* (SRV1_UseControl) */
    #endif  /* (!SRV1_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: SRV1_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SRV1_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void SRV1_RestoreConfig(void) 
{
        #if(!SRV1_UsingFixedFunction)
            #if(!SRV1_PWMModeIsCenterAligned)
                SRV1_WritePeriod(SRV1_backup.PWMPeriod);
            #endif /* (!SRV1_PWMModeIsCenterAligned) */

            SRV1_WriteCounter(SRV1_backup.PWMUdb);

            #if (SRV1_UseStatus)
                SRV1_STATUS_MASK = SRV1_backup.InterruptMaskValue;
            #endif /* (SRV1_UseStatus) */

            #if(SRV1_DeadBandMode == SRV1__B_PWM__DBM_256_CLOCKS || \
                SRV1_DeadBandMode == SRV1__B_PWM__DBM_2_4_CLOCKS)
                SRV1_WriteDeadTime(SRV1_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(SRV1_KillModeMinTime)
                SRV1_WriteKillTime(SRV1_backup.PWMKillCounterPeriod);
            #endif /* (SRV1_KillModeMinTime) */

            #if(SRV1_UseControl)
                SRV1_WriteControlRegister(SRV1_backup.PWMControlRegister);
            #endif /* (SRV1_UseControl) */
        #endif  /* (!SRV1_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: SRV1_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SRV1_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void SRV1_Sleep(void) 
{
    #if(SRV1_UseControl)
        if(SRV1_CTRL_ENABLE == (SRV1_CONTROL & SRV1_CTRL_ENABLE))
        {
            /*Component is enabled */
            SRV1_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            SRV1_backup.PWMEnableState = 0u;
        }
    #endif /* (SRV1_UseControl) */

    /* Stop component */
    SRV1_Stop();

    /* Save registers configuration */
    SRV1_SaveConfig();
}


/*******************************************************************************
* Function Name: SRV1_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SRV1_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void SRV1_Wakeup(void) 
{
     /* Restore registers values */
    SRV1_RestoreConfig();

    if(SRV1_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        SRV1_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
