/*******************************************************************************
* File Name: ENC2B.h  
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

#if !defined(CY_PINS_ENC2B_H) /* Pins ENC2B_H */
#define CY_PINS_ENC2B_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ENC2B_aliases.h"


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
} ENC2B_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   ENC2B_Read(void);
void    ENC2B_Write(uint8 value);
uint8   ENC2B_ReadDataReg(void);
#if defined(ENC2B__PC) || (CY_PSOC4_4200L) 
    void    ENC2B_SetDriveMode(uint8 mode);
#endif
void    ENC2B_SetInterruptMode(uint16 position, uint16 mode);
uint8   ENC2B_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void ENC2B_Sleep(void); 
void ENC2B_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(ENC2B__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define ENC2B_DRIVE_MODE_BITS        (3)
    #define ENC2B_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ENC2B_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the ENC2B_SetDriveMode() function.
         *  @{
         */
        #define ENC2B_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define ENC2B_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define ENC2B_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define ENC2B_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define ENC2B_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define ENC2B_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define ENC2B_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define ENC2B_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define ENC2B_MASK               ENC2B__MASK
#define ENC2B_SHIFT              ENC2B__SHIFT
#define ENC2B_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ENC2B_SetInterruptMode() function.
     *  @{
     */
        #define ENC2B_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define ENC2B_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define ENC2B_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define ENC2B_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(ENC2B__SIO)
    #define ENC2B_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(ENC2B__PC) && (CY_PSOC4_4200L)
    #define ENC2B_USBIO_ENABLE               ((uint32)0x80000000u)
    #define ENC2B_USBIO_DISABLE              ((uint32)(~ENC2B_USBIO_ENABLE))
    #define ENC2B_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define ENC2B_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define ENC2B_USBIO_ENTER_SLEEP          ((uint32)((1u << ENC2B_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << ENC2B_USBIO_SUSPEND_DEL_SHIFT)))
    #define ENC2B_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << ENC2B_USBIO_SUSPEND_SHIFT)))
    #define ENC2B_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << ENC2B_USBIO_SUSPEND_DEL_SHIFT)))
    #define ENC2B_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(ENC2B__PC)
    /* Port Configuration */
    #define ENC2B_PC                 (* (reg32 *) ENC2B__PC)
#endif
/* Pin State */
#define ENC2B_PS                     (* (reg32 *) ENC2B__PS)
/* Data Register */
#define ENC2B_DR                     (* (reg32 *) ENC2B__DR)
/* Input Buffer Disable Override */
#define ENC2B_INP_DIS                (* (reg32 *) ENC2B__PC2)

/* Interrupt configuration Registers */
#define ENC2B_INTCFG                 (* (reg32 *) ENC2B__INTCFG)
#define ENC2B_INTSTAT                (* (reg32 *) ENC2B__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define ENC2B_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(ENC2B__SIO)
    #define ENC2B_SIO_REG            (* (reg32 *) ENC2B__SIO)
#endif /* (ENC2B__SIO_CFG) */

/* USBIO registers */
#if !defined(ENC2B__PC) && (CY_PSOC4_4200L)
    #define ENC2B_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define ENC2B_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define ENC2B_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define ENC2B_DRIVE_MODE_SHIFT       (0x00u)
#define ENC2B_DRIVE_MODE_MASK        (0x07u << ENC2B_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins ENC2B_H */


/* [] END OF FILE */
