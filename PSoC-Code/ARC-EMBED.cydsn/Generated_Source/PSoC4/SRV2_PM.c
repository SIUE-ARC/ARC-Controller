/*******************************************************************************
* File Name: SRV2_PM.c
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

#include "SRV2.h"

static SRV2_backupStruct SRV2_backup;


/*******************************************************************************
* Function Name: SRV2_SaveConfig
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
*  SRV2_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void SRV2_SaveConfig(void) 
{

    #if(!SRV2_UsingFixedFunction)
        #if(!SRV2_PWMModeIsCenterAligned)
            SRV2_backup.PWMPeriod = SRV2_ReadPeriod();
        #endif /* (!SRV2_PWMModeIsCenterAligned) */
        SRV2_backup.PWMUdb = SRV2_ReadCounter();
        #if (SRV2_UseStatus)
            SRV2_backup.InterruptMaskValue = SRV2_STATUS_MASK;
        #endif /* (SRV2_UseStatus) */

        #if(SRV2_DeadBandMode == SRV2__B_PWM__DBM_256_CLOCKS || \
            SRV2_DeadBandMode == SRV2__B_PWM__DBM_2_4_CLOCKS)
            SRV2_backup.PWMdeadBandValue = SRV2_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(SRV2_KillModeMinTime)
             SRV2_backup.PWMKillCounterPeriod = SRV2_ReadKillTime();
        #endif /* (SRV2_KillModeMinTime) */

        #if(SRV2_UseControl)
            SRV2_backup.PWMControlRegister = SRV2_ReadControlRegister();
        #endif /* (SRV2_UseControl) */
    #endif  /* (!SRV2_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: SRV2_RestoreConfig
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
*  SRV2_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void SRV2_RestoreConfig(void) 
{
        #if(!SRV2_UsingFixedFunction)
            #if(!SRV2_PWMModeIsCenterAligned)
                SRV2_WritePeriod(SRV2_backup.PWMPeriod);
            #endif /* (!SRV2_PWMModeIsCenterAligned) */

            SRV2_WriteCounter(SRV2_backup.PWMUdb);

            #if (SRV2_UseStatus)
                SRV2_STATUS_MASK = SRV2_backup.InterruptMaskValue;
            #endif /* (SRV2_UseStatus) */

            #if(SRV2_DeadBandMode == SRV2__B_PWM__DBM_256_CLOCKS || \
                SRV2_DeadBandMode == SRV2__B_PWM__DBM_2_4_CLOCKS)
                SRV2_WriteDeadTime(SRV2_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(SRV2_KillModeMinTime)
                SRV2_WriteKillTime(SRV2_backup.PWMKillCounterPeriod);
            #endif /* (SRV2_KillModeMinTime) */

            #if(SRV2_UseControl)
                SRV2_WriteControlRegister(SRV2_backup.PWMControlRegister);
            #endif /* (SRV2_UseControl) */
        #endif  /* (!SRV2_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: SRV2_Sleep
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
*  SRV2_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void SRV2_Sleep(void) 
{
    #if(SRV2_UseControl)
        if(SRV2_CTRL_ENABLE == (SRV2_CONTROL & SRV2_CTRL_ENABLE))
        {
            /*Component is enabled */
            SRV2_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            SRV2_backup.PWMEnableState = 0u;
        }
    #endif /* (SRV2_UseControl) */

    /* Stop component */
    SRV2_Stop();

    /* Save registers configuration */
    SRV2_SaveConfig();
}


/*******************************************************************************
* Function Name: SRV2_Wakeup
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
*  SRV2_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void SRV2_Wakeup(void) 
{
     /* Restore registers values */
    SRV2_RestoreConfig();

    if(SRV2_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        SRV2_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
