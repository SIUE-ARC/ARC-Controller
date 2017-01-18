/*******************************************************************************
* File Name: SRV1A.c  
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
#include "SRV1A.h"

static SRV1A_BACKUP_STRUCT  SRV1A_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: SRV1A_Sleep
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
*  \snippet SRV1A_SUT.c usage_SRV1A_Sleep_Wakeup
*******************************************************************************/
void SRV1A_Sleep(void)
{
    #if defined(SRV1A__PC)
        SRV1A_backup.pcState = SRV1A_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            SRV1A_backup.usbState = SRV1A_CR1_REG;
            SRV1A_USB_POWER_REG |= SRV1A_USBIO_ENTER_SLEEP;
            SRV1A_CR1_REG &= SRV1A_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(SRV1A__SIO)
        SRV1A_backup.sioState = SRV1A_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        SRV1A_SIO_REG &= (uint32)(~SRV1A_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: SRV1A_Wakeup
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
*  Refer to SRV1A_Sleep() for an example usage.
*******************************************************************************/
void SRV1A_Wakeup(void)
{
    #if defined(SRV1A__PC)
        SRV1A_PC = SRV1A_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            SRV1A_USB_POWER_REG &= SRV1A_USBIO_EXIT_SLEEP_PH1;
            SRV1A_CR1_REG = SRV1A_backup.usbState;
            SRV1A_USB_POWER_REG &= SRV1A_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(SRV1A__SIO)
        SRV1A_SIO_REG = SRV1A_backup.sioState;
    #endif
}


/* [] END OF FILE */
