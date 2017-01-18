/*******************************************************************************
* File Name: DAC2.c  
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
#include "DAC2.h"

static DAC2_BACKUP_STRUCT  DAC2_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: DAC2_Sleep
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
*  \snippet DAC2_SUT.c usage_DAC2_Sleep_Wakeup
*******************************************************************************/
void DAC2_Sleep(void)
{
    #if defined(DAC2__PC)
        DAC2_backup.pcState = DAC2_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            DAC2_backup.usbState = DAC2_CR1_REG;
            DAC2_USB_POWER_REG |= DAC2_USBIO_ENTER_SLEEP;
            DAC2_CR1_REG &= DAC2_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(DAC2__SIO)
        DAC2_backup.sioState = DAC2_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        DAC2_SIO_REG &= (uint32)(~DAC2_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: DAC2_Wakeup
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
*  Refer to DAC2_Sleep() for an example usage.
*******************************************************************************/
void DAC2_Wakeup(void)
{
    #if defined(DAC2__PC)
        DAC2_PC = DAC2_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            DAC2_USB_POWER_REG &= DAC2_USBIO_EXIT_SLEEP_PH1;
            DAC2_CR1_REG = DAC2_backup.usbState;
            DAC2_USB_POWER_REG &= DAC2_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(DAC2__SIO)
        DAC2_SIO_REG = DAC2_backup.sioState;
    #endif
}


/* [] END OF FILE */
