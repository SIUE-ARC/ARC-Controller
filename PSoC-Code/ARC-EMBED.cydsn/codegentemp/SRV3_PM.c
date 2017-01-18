/*******************************************************************************
* File Name: SRV3_PM.c
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

#include "SRV3.h"

static SRV3_backupStruct SRV3_backup;


/*******************************************************************************
* Function Name: SRV3_SaveConfig
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
*  SRV3_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void SRV3_SaveConfig(void) 
{

    #if(!SRV3_UsingFixedFunction)
        #if(!SRV3_PWMModeIsCenterAligned)
            SRV3_backup.PWMPeriod = SRV3_ReadPeriod();
        #endif /* (!SRV3_PWMModeIsCenterAligned) */
        SRV3_backup.PWMUdb = SRV3_ReadCounter();
        #if (SRV3_UseStatus)
            SRV3_backup.InterruptMaskValue = SRV3_STATUS_MASK;
        #endif /* (SRV3_UseStatus) */

        #if(SRV3_DeadBandMode == SRV3__B_PWM__DBM_256_CLOCKS || \
            SRV3_DeadBandMode == SRV3__B_PWM__DBM_2_4_CLOCKS)
            SRV3_backup.PWMdeadBandValue = SRV3_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(SRV3_KillModeMinTime)
             SRV3_backup.PWMKillCounterPeriod = SRV3_ReadKillTime();
        #endif /* (SRV3_KillModeMinTime) */

        #if(SRV3_UseControl)
            SRV3_backup.PWMControlRegister = SRV3_ReadControlRegister();
        #endif /* (SRV3_UseControl) */
    #endif  /* (!SRV3_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: SRV3_RestoreConfig
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
*  SRV3_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void SRV3_RestoreConfig(void) 
{
        #if(!SRV3_UsingFixedFunction)
            #if(!SRV3_PWMModeIsCenterAligned)
                SRV3_WritePeriod(SRV3_backup.PWMPeriod);
            #endif /* (!SRV3_PWMModeIsCenterAligned) */

            SRV3_WriteCounter(SRV3_backup.PWMUdb);

            #if (SRV3_UseStatus)
                SRV3_STATUS_MASK = SRV3_backup.InterruptMaskValue;
            #endif /* (SRV3_UseStatus) */

            #if(SRV3_DeadBandMode == SRV3__B_PWM__DBM_256_CLOCKS || \
                SRV3_DeadBandMode == SRV3__B_PWM__DBM_2_4_CLOCKS)
                SRV3_WriteDeadTime(SRV3_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(SRV3_KillModeMinTime)
                SRV3_WriteKillTime(SRV3_backup.PWMKillCounterPeriod);
            #endif /* (SRV3_KillModeMinTime) */

            #if(SRV3_UseControl)
                SRV3_WriteControlRegister(SRV3_backup.PWMControlRegister);
            #endif /* (SRV3_UseControl) */
        #endif  /* (!SRV3_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: SRV3_Sleep
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
*  SRV3_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void SRV3_Sleep(void) 
{
    #if(SRV3_UseControl)
        if(SRV3_CTRL_ENABLE == (SRV3_CONTROL & SRV3_CTRL_ENABLE))
        {
            /*Component is enabled */
            SRV3_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            SRV3_backup.PWMEnableState = 0u;
        }
    #endif /* (SRV3_UseControl) */

    /* Stop component */
    SRV3_Stop();

    /* Save registers configuration */
    SRV3_SaveConfig();
}


/*******************************************************************************
* Function Name: SRV3_Wakeup
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
*  SRV3_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void SRV3_Wakeup(void) 
{
     /* Restore registers values */
    SRV3_RestoreConfig();

    if(SRV3_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        SRV3_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
