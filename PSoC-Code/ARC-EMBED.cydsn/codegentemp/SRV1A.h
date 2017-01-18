/*******************************************************************************
* File Name: SRV1A.h  
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

#if !defined(CY_PINS_SRV1A_H) /* Pins SRV1A_H */
#define CY_PINS_SRV1A_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SRV1A_aliases.h"


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
} SRV1A_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   SRV1A_Read(void);
void    SRV1A_Write(uint8 value);
uint8   SRV1A_ReadDataReg(void);
#if defined(SRV1A__PC) || (CY_PSOC4_4200L) 
    void    SRV1A_SetDriveMode(uint8 mode);
#endif
void    SRV1A_SetInterruptMode(uint16 position, uint16 mode);
uint8   SRV1A_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void SRV1A_Sleep(void); 
void SRV1A_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(SRV1A__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define SRV1A_DRIVE_MODE_BITS        (3)
    #define SRV1A_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SRV1A_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the SRV1A_SetDriveMode() function.
         *  @{
         */
        #define SRV1A_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define SRV1A_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define SRV1A_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define SRV1A_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define SRV1A_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define SRV1A_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define SRV1A_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define SRV1A_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define SRV1A_MASK               SRV1A__MASK
#define SRV1A_SHIFT              SRV1A__SHIFT
#define SRV1A_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SRV1A_SetInterruptMode() function.
     *  @{
     */
        #define SRV1A_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define SRV1A_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define SRV1A_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define SRV1A_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(SRV1A__SIO)
    #define SRV1A_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(SRV1A__PC) && (CY_PSOC4_4200L)
    #define SRV1A_USBIO_ENABLE               ((uint32)0x80000000u)
    #define SRV1A_USBIO_DISABLE              ((uint32)(~SRV1A_USBIO_ENABLE))
    #define SRV1A_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define SRV1A_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define SRV1A_USBIO_ENTER_SLEEP          ((uint32)((1u << SRV1A_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << SRV1A_USBIO_SUSPEND_DEL_SHIFT)))
    #define SRV1A_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << SRV1A_USBIO_SUSPEND_SHIFT)))
    #define SRV1A_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << SRV1A_USBIO_SUSPEND_DEL_SHIFT)))
    #define SRV1A_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(SRV1A__PC)
    /* Port Configuration */
    #define SRV1A_PC                 (* (reg32 *) SRV1A__PC)
#endif
/* Pin State */
#define SRV1A_PS                     (* (reg32 *) SRV1A__PS)
/* Data Register */
#define SRV1A_DR                     (* (reg32 *) SRV1A__DR)
/* Input Buffer Disable Override */
#define SRV1A_INP_DIS                (* (reg32 *) SRV1A__PC2)

/* Interrupt configuration Registers */
#define SRV1A_INTCFG                 (* (reg32 *) SRV1A__INTCFG)
#define SRV1A_INTSTAT                (* (reg32 *) SRV1A__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define SRV1A_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(SRV1A__SIO)
    #define SRV1A_SIO_REG            (* (reg32 *) SRV1A__SIO)
#endif /* (SRV1A__SIO_CFG) */

/* USBIO registers */
#if !defined(SRV1A__PC) && (CY_PSOC4_4200L)
    #define SRV1A_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define SRV1A_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define SRV1A_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define SRV1A_DRIVE_MODE_SHIFT       (0x00u)
#define SRV1A_DRIVE_MODE_MASK        (0x07u << SRV1A_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins SRV1A_H */


/* [] END OF FILE */
