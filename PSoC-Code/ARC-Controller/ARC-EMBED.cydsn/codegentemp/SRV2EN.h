/*******************************************************************************
* File Name: SRV2EN.h  
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

#if !defined(CY_PINS_SRV2EN_H) /* Pins SRV2EN_H */
#define CY_PINS_SRV2EN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "SRV2EN_aliases.h"


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
} SRV2EN_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   SRV2EN_Read(void);
void    SRV2EN_Write(uint8 value);
uint8   SRV2EN_ReadDataReg(void);
#if defined(SRV2EN__PC) || (CY_PSOC4_4200L) 
    void    SRV2EN_SetDriveMode(uint8 mode);
#endif
void    SRV2EN_SetInterruptMode(uint16 position, uint16 mode);
uint8   SRV2EN_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void SRV2EN_Sleep(void); 
void SRV2EN_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(SRV2EN__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define SRV2EN_DRIVE_MODE_BITS        (3)
    #define SRV2EN_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - SRV2EN_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the SRV2EN_SetDriveMode() function.
         *  @{
         */
        #define SRV2EN_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define SRV2EN_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define SRV2EN_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define SRV2EN_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define SRV2EN_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define SRV2EN_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define SRV2EN_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define SRV2EN_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define SRV2EN_MASK               SRV2EN__MASK
#define SRV2EN_SHIFT              SRV2EN__SHIFT
#define SRV2EN_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SRV2EN_SetInterruptMode() function.
     *  @{
     */
        #define SRV2EN_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define SRV2EN_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define SRV2EN_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define SRV2EN_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(SRV2EN__SIO)
    #define SRV2EN_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(SRV2EN__PC) && (CY_PSOC4_4200L)
    #define SRV2EN_USBIO_ENABLE               ((uint32)0x80000000u)
    #define SRV2EN_USBIO_DISABLE              ((uint32)(~SRV2EN_USBIO_ENABLE))
    #define SRV2EN_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define SRV2EN_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define SRV2EN_USBIO_ENTER_SLEEP          ((uint32)((1u << SRV2EN_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << SRV2EN_USBIO_SUSPEND_DEL_SHIFT)))
    #define SRV2EN_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << SRV2EN_USBIO_SUSPEND_SHIFT)))
    #define SRV2EN_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << SRV2EN_USBIO_SUSPEND_DEL_SHIFT)))
    #define SRV2EN_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(SRV2EN__PC)
    /* Port Configuration */
    #define SRV2EN_PC                 (* (reg32 *) SRV2EN__PC)
#endif
/* Pin State */
#define SRV2EN_PS                     (* (reg32 *) SRV2EN__PS)
/* Data Register */
#define SRV2EN_DR                     (* (reg32 *) SRV2EN__DR)
/* Input Buffer Disable Override */
#define SRV2EN_INP_DIS                (* (reg32 *) SRV2EN__PC2)

/* Interrupt configuration Registers */
#define SRV2EN_INTCFG                 (* (reg32 *) SRV2EN__INTCFG)
#define SRV2EN_INTSTAT                (* (reg32 *) SRV2EN__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define SRV2EN_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(SRV2EN__SIO)
    #define SRV2EN_SIO_REG            (* (reg32 *) SRV2EN__SIO)
#endif /* (SRV2EN__SIO_CFG) */

/* USBIO registers */
#if !defined(SRV2EN__PC) && (CY_PSOC4_4200L)
    #define SRV2EN_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define SRV2EN_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define SRV2EN_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define SRV2EN_DRIVE_MODE_SHIFT       (0x00u)
#define SRV2EN_DRIVE_MODE_MASK        (0x07u << SRV2EN_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins SRV2EN_H */


/* [] END OF FILE */
