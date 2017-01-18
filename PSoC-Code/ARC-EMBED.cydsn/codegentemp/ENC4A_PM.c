/*******************************************************************************
* File Name: ENC4A.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "ENC4A.h"

static ENC4A_BACKUP_STRUCT  ENC4A_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: ENC4A_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function must be called for SIO and USBIO
*  pins. It is not essential if using GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet ENC4A_SUT.c usage_ENC4A_Sleep_Wakeup
*******************************************************************************/
void ENC4A_Sleep(void)
{
    #if defined(ENC4A__PC)
        ENC4A_backup.pcState = ENC4A_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            ENC4A_backup.usbState = ENC4A_CR1_REG;
            ENC4A_USB_POWER_REG |= ENC4A_USBIO_ENTER_SLEEP;
            ENC4A_CR1_REG &= ENC4A_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(ENC4A__SIO)
        ENC4A_backup.sioState = ENC4A_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        ENC4A_SIO_REG &= (uint32)(~ENC4A_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: ENC4A_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep().
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to ENC4A_Sleep() for an example usage.
*******************************************************************************/
void ENC4A_Wakeup(void)
{
    #if defined(ENC4A__PC)
        ENC4A_PC = ENC4A_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            ENC4A_USB_POWER_REG &= ENC4A_USBIO_EXIT_SLEEP_PH1;
            ENC4A_CR1_REG = ENC4A_backup.usbState;
            ENC4A_USB_POWER_REG &= ENC4A_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(ENC4A__SIO)
        ENC4A_SIO_REG = ENC4A_backup.sioState;
    #endif
}


/* [] END OF FILE */
