/*******************************************************************************
* File Name: SRV1B.h  
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

#if !defined(CY_PINS_SRV1B_H) /* Pins SRV1B_H */
#define CY_PINS_SRV1B_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SRV1B_aliases.h"


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
} SRV1B_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   SRV1B_Read(void);
void    SRV1B_Write(uint8 value);
uint8   SRV1B_ReadDataReg(void);
#if defined(SRV1B__PC) || (CY_PSOC4_4200L) 
    void    SRV1B_SetDriveMode(uint8 mode);
#endif
void    SRV1B_SetInterruptMode(uint16 position, uint16 mode);
uint8   SRV1B_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void SRV1B_Sleep(void); 
void SRV1B_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(SRV1B__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define SRV1B_DRIVE_MODE_BITS        (3)
    #define SRV1B_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SRV1B_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the SRV1B_SetDriveMode() function.
         *  @{
         */
        #define SRV1B_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define SRV1B_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define SRV1B_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define SRV1B_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define SRV1B_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define SRV1B_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define SRV1B_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define SRV1B_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define SRV1B_MASK               SRV1B__MASK
#define SRV1B_SHIFT              SRV1B__SHIFT
#define SRV1B_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SRV1B_SetInterruptMode() function.
     *  @{
     */
        #define SRV1B_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define SRV1B_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define SRV1B_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define SRV1B_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(SRV1B__SIO)
    #define SRV1B_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(SRV1B__PC) && (CY_PSOC4_4200L)
    #define SRV1B_USBIO_ENABLE               ((uint32)0x80000000u)
    #define SRV1B_USBIO_DISABLE              ((uint32)(~SRV1B_USBIO_ENABLE))
    #define SRV1B_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define SRV1B_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define SRV1B_USBIO_ENTER_SLEEP          ((uint32)((1u << SRV1B_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << SRV1B_USBIO_SUSPEND_DEL_SHIFT)))
    #define SRV1B_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << SRV1B_USBIO_SUSPEND_SHIFT)))
    #define SRV1B_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << SRV1B_USBIO_SUSPEND_DEL_SHIFT)))
    #define SRV1B_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(SRV1B__PC)
    /* Port Configuration */
    #define SRV1B_PC                 (* (reg32 *) SRV1B__PC)
#endif
/* Pin State */
#define SRV1B_PS                     (* (reg32 *) SRV1B__PS)
/* Data Register */
#define SRV1B_DR                     (* (reg32 *) SRV1B__DR)
/* Input Buffer Disable Override */
#define SRV1B_INP_DIS                (* (reg32 *) SRV1B__PC2)

/* Interrupt configuration Registers */
#define SRV1B_INTCFG                 (* (reg32 *) SRV1B__INTCFG)
#define SRV1B_INTSTAT                (* (reg32 *) SRV1B__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define SRV1B_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(SRV1B__SIO)
    #define SRV1B_SIO_REG            (* (reg32 *) SRV1B__SIO)
#endif /* (SRV1B__SIO_CFG) */

/* USBIO registers */
#if !defined(SRV1B__PC) && (CY_PSOC4_4200L)
    #define SRV1B_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define SRV1B_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define SRV1B_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define SRV1B_DRIVE_MODE_SHIFT       (0x00u)
#define SRV1B_DRIVE_MODE_MASK        (0x07u << SRV1B_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins SRV1B_H */


/* [] END OF FILE */
