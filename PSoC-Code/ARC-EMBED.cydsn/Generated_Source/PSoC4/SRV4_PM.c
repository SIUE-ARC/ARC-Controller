/*******************************************************************************
* File Name: SRV4_PM.c
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

#include "SRV4.h"

static SRV4_backupStruct SRV4_backup;


/*******************************************************************************
* Function Name: SRV4_SaveConfig
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
*  SRV4_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void SRV4_SaveConfig(void) 
{

    #if(!SRV4_UsingFixedFunction)
        #if(!SRV4_PWMModeIsCenterAligned)
            SRV4_backup.PWMPeriod = SRV4_ReadPeriod();
        #endif /* (!SRV4_PWMModeIsCenterAligned) */
        SRV4_backup.PWMUdb = SRV4_ReadCounter();
        #if (SRV4_UseStatus)
            SRV4_backup.InterruptMaskValue = SRV4_STATUS_MASK;
        #endif /* (SRV4_UseStatus) */

        #if(SRV4_DeadBandMode == SRV4__B_PWM__DBM_256_CLOCKS || \
            SRV4_DeadBandMode == SRV4__B_PWM__DBM_2_4_CLOCKS)
            SRV4_backup.PWMdeadBandValue = SRV4_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(SRV4_KillModeMinTime)
             SRV4_backup.PWMKillCounterPeriod = SRV4_ReadKillTime();
        #endif /* (SRV4_KillModeMinTime) */

        #if(SRV4_UseControl)
            SRV4_backup.PWMControlRegister = SRV4_ReadControlRegister();
        #endif /* (SRV4_UseControl) */
    #endif  /* (!SRV4_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: SRV4_RestoreConfig
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
*  SRV4_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void SRV4_RestoreConfig(void) 
{
        #if(!SRV4_UsingFixedFunction)
            #if(!SRV4_PWMModeIsCenterAligned)
                SRV4_WritePeriod(SRV4_backup.PWMPeriod);
            #endif /* (!SRV4_PWMModeIsCenterAligned) */

            SRV4_WriteCounter(SRV4_backup.PWMUdb);

            #if (SRV4_UseStatus)
                SRV4_STATUS_MASK = SRV4_backup.InterruptMaskValue;
            #endif /* (SRV4_UseStatus) */

            #if(SRV4_DeadBandMode == SRV4__B_PWM__DBM_256_CLOCKS || \
                SRV4_DeadBandMode == SRV4__B_PWM__DBM_2_4_CLOCKS)
                SRV4_WriteDeadTime(SRV4_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(SRV4_KillModeMinTime)
                SRV4_WriteKillTime(SRV4_backup.PWMKillCounterPeriod);
            #endif /* (SRV4_KillModeMinTime) */

            #if(SRV4_UseControl)
                SRV4_WriteControlRegister(SRV4_backup.PWMControlRegister);
            #endif /* (SRV4_UseControl) */
        #endif  /* (!SRV4_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: SRV4_Sleep
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
*  SRV4_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void SRV4_Sleep(void) 
{
    #if(SRV4_UseControl)
        if(SRV4_CTRL_ENABLE == (SRV4_CONTROL & SRV4_CTRL_ENABLE))
        {
            /*Component is enabled */
            SRV4_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            SRV4_backup.PWMEnableState = 0u;
        }
    #endif /* (SRV4_UseControl) */

    /* Stop component */
    SRV4_Stop();

    /* Save registers configuration */
    SRV4_SaveConfig();
}


/*******************************************************************************
* Function Name: SRV4_Wakeup
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
*  SRV4_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void SRV4_Wakeup(void) 
{
     /* Restore registers values */
    SRV4_RestoreConfig();

    if(SRV4_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        SRV4_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
