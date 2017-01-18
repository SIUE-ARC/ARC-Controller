/*******************************************************************************
* File Name: DAC3.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_DAC3_H) /* Pins DAC3_H */
#define CY_PINS_DAC3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "DAC3_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} DAC3_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   DAC3_Read(void);
void    DAC3_Write(uint8 value);
uint8   DAC3_ReadDataReg(void);
#if defined(DAC3__PC) || (CY_PSOC4_4200L) 
    void    DAC3_SetDriveMode(uint8 mode);
#endif
void    DAC3_SetInterruptMode(uint16 position, uint16 mode);
uint8   DAC3_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void DAC3_Sleep(void); 
void DAC3_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(DAC3__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define DAC3_DRIVE_MODE_BITS        (3)
    #define DAC3_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - DAC3_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the DAC3_SetDriveMode() function.
         *  @{
         */
        #define DAC3_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define DAC3_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define DAC3_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define DAC3_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define DAC3_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define DAC3_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define DAC3_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define DAC3_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define DAC3_MASK               DAC3__MASK
#define DAC3_SHIFT              DAC3__SHIFT
#define DAC3_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DAC3_SetInterruptMode() function.
     *  @{
     */
        #define DAC3_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define DAC3_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define DAC3_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define DAC3_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(DAC3__SIO)
    #define DAC3_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(DAC3__PC) && (CY_PSOC4_4200L)
    #define DAC3_USBIO_ENABLE               ((uint32)0x80000000u)
    #define DAC3_USBIO_DISABLE              ((uint32)(~DAC3_USBIO_ENABLE))
    #define DAC3_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define DAC3_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define DAC3_USBIO_ENTER_SLEEP          ((uint32)((1u << DAC3_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << DAC3_USBIO_SUSPEND_DEL_SHIFT)))
    #define DAC3_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << DAC3_USBIO_SUSPEND_SHIFT)))
    #define DAC3_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << DAC3_USBIO_SUSPEND_DEL_SHIFT)))
    #define DAC3_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(DAC3__PC)
    /* Port Configuration */
    #define DAC3_PC                 (* (reg32 *) DAC3__PC)
#endif
/* Pin State */
#define DAC3_PS                     (* (reg32 *) DAC3__PS)
/* Data Register */
#define DAC3_DR                     (* (reg32 *) DAC3__DR)
/* Input Buffer Disable Override */
#define DAC3_INP_DIS                (* (reg32 *) DAC3__PC2)

/* Interrupt configuration Registers */
#define DAC3_INTCFG                 (* (reg32 *) DAC3__INTCFG)
#define DAC3_INTSTAT                (* (reg32 *) DAC3__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define DAC3_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(DAC3__SIO)
    #define DAC3_SIO_REG            (* (reg32 *) DAC3__SIO)
#endif /* (DAC3__SIO_CFG) */

/* USBIO registers */
#if !defined(DAC3__PC) && (CY_PSOC4_4200L)
    #define DAC3_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define DAC3_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define DAC3_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define DAC3_DRIVE_MODE_SHIFT       (0x00u)
#define DAC3_DRIVE_MODE_MASK        (0x07u << DAC3_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins DAC3_H */


/* [] END OF FILE */
