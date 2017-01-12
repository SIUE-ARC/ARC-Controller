/*******************************************************************************
* File Name: SRV1.h
* Version 3.30
*
* Description:
*  Contains the prototypes and constants for the functions available to the
*  PWM user module.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_PWM_SRV1_H)
#define CY_PWM_SRV1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 SRV1_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define SRV1_Resolution                     (16u)
#define SRV1_UsingFixedFunction             (0u)
#define SRV1_DeadBandMode                   (0u)
#define SRV1_KillModeMinTime                (0u)
#define SRV1_KillMode                       (0u)
#define SRV1_PWMMode                        (1u)
#define SRV1_PWMModeIsCenterAligned         (0u)
#define SRV1_DeadBandUsed                   (0u)
#define SRV1_DeadBand2_4                    (0u)

#if !defined(SRV1_PWMUDB_genblk8_stsreg__REMOVED)
    #define SRV1_UseStatus                  (1u)
#else
    #define SRV1_UseStatus                  (0u)
#endif /* !defined(SRV1_PWMUDB_genblk8_stsreg__REMOVED) */

#if !defined(SRV1_PWMUDB_genblk1_ctrlreg__REMOVED)
    #define SRV1_UseControl                 (1u)
#else
    #define SRV1_UseControl                 (0u)
#endif /* !defined(SRV1_PWMUDB_genblk1_ctrlreg__REMOVED) */

#define SRV1_UseOneCompareMode              (0u)
#define SRV1_MinimumKillTime                (1u)
#define SRV1_EnableMode                     (2u)

#define SRV1_CompareMode1SW                 (0u)
#define SRV1_CompareMode2SW                 (0u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v3_30 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define SRV1__B_PWM__DISABLED 0
#define SRV1__B_PWM__ASYNCHRONOUS 1
#define SRV1__B_PWM__SINGLECYCLE 2
#define SRV1__B_PWM__LATCHED 3
#define SRV1__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define SRV1__B_PWM__DBMDISABLED 0
#define SRV1__B_PWM__DBM_2_4_CLOCKS 1
#define SRV1__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define SRV1__B_PWM__ONE_OUTPUT 0
#define SRV1__B_PWM__TWO_OUTPUTS 1
#define SRV1__B_PWM__DUAL_EDGE 2
#define SRV1__B_PWM__CENTER_ALIGN 3
#define SRV1__B_PWM__DITHER 5
#define SRV1__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define SRV1__B_PWM__LESS_THAN 1
#define SRV1__B_PWM__LESS_THAN_OR_EQUAL 2
#define SRV1__B_PWM__GREATER_THAN 3
#define SRV1__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define SRV1__B_PWM__EQUAL 0
#define SRV1__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{

    uint8 PWMEnableState;

    #if(!SRV1_UsingFixedFunction)
        uint16 PWMUdb;               /* PWM Current Counter value  */
        #if(!SRV1_PWMModeIsCenterAligned)
            uint16 PWMPeriod;
        #endif /* (!SRV1_PWMModeIsCenterAligned) */
        #if (SRV1_UseStatus)
            uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
        #endif /* (SRV1_UseStatus) */

        /* Backup for Deadband parameters */
        #if(SRV1_DeadBandMode == SRV1__B_PWM__DBM_256_CLOCKS || \
            SRV1_DeadBandMode == SRV1__B_PWM__DBM_2_4_CLOCKS)
            uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
        #endif /* deadband count is either 2-4 clocks or 256 clocks */

        /* Backup Kill Mode Counter*/
        #if(SRV1_KillModeMinTime)
            uint8 PWMKillCounterPeriod; /* Kill Mode period value */
        #endif /* (SRV1_KillModeMinTime) */

        /* Backup control register */
        #if(SRV1_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (SRV1_UseControl) */

    #endif /* (!SRV1_UsingFixedFunction) */

}SRV1_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/

void    SRV1_Start(void) ;
void    SRV1_Stop(void) ;

#if (SRV1_UseStatus || SRV1_UsingFixedFunction)
    void  SRV1_SetInterruptMode(uint8 interruptMode) ;
    uint8 SRV1_ReadStatusRegister(void) ;
#endif /* (SRV1_UseStatus || SRV1_UsingFixedFunction) */

#define SRV1_GetInterruptSource() SRV1_ReadStatusRegister()

#if (SRV1_UseControl)
    uint8 SRV1_ReadControlRegister(void) ;
    void  SRV1_WriteControlRegister(uint8 control)
          ;
#endif /* (SRV1_UseControl) */

#if (SRV1_UseOneCompareMode)
   #if (SRV1_CompareMode1SW)
       void    SRV1_SetCompareMode(uint8 comparemode)
               ;
   #endif /* (SRV1_CompareMode1SW) */
#else
    #if (SRV1_CompareMode1SW)
        void    SRV1_SetCompareMode1(uint8 comparemode)
                ;
    #endif /* (SRV1_CompareMode1SW) */
    #if (SRV1_CompareMode2SW)
        void    SRV1_SetCompareMode2(uint8 comparemode)
                ;
    #endif /* (SRV1_CompareMode2SW) */
#endif /* (SRV1_UseOneCompareMode) */

#if (!SRV1_UsingFixedFunction)
    uint16   SRV1_ReadCounter(void) ;
    uint16 SRV1_ReadCapture(void) ;

    #if (SRV1_UseStatus)
            void SRV1_ClearFIFO(void) ;
    #endif /* (SRV1_UseStatus) */

    void    SRV1_WriteCounter(uint16 counter)
            ;
#endif /* (!SRV1_UsingFixedFunction) */

void    SRV1_WritePeriod(uint16 period)
        ;
uint16 SRV1_ReadPeriod(void) ;

#if (SRV1_UseOneCompareMode)
    void    SRV1_WriteCompare(uint16 compare)
            ;
    uint16 SRV1_ReadCompare(void) ;
#else
    void    SRV1_WriteCompare1(uint16 compare)
            ;
    uint16 SRV1_ReadCompare1(void) ;
    void    SRV1_WriteCompare2(uint16 compare)
            ;
    uint16 SRV1_ReadCompare2(void) ;
#endif /* (SRV1_UseOneCompareMode) */


#if (SRV1_DeadBandUsed)
    void    SRV1_WriteDeadTime(uint8 deadtime) ;
    uint8   SRV1_ReadDeadTime(void) ;
#endif /* (SRV1_DeadBandUsed) */

#if ( SRV1_KillModeMinTime)
    void SRV1_WriteKillTime(uint8 killtime) ;
    uint8 SRV1_ReadKillTime(void) ;
#endif /* ( SRV1_KillModeMinTime) */

void SRV1_Init(void) ;
void SRV1_Enable(void) ;
void SRV1_Sleep(void) ;
void SRV1_Wakeup(void) ;
void SRV1_SaveConfig(void) ;
void SRV1_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define SRV1_INIT_PERIOD_VALUE          (40000u)
#define SRV1_INIT_COMPARE_VALUE1        (4000u)
#define SRV1_INIT_COMPARE_VALUE2        (4000u)
#define SRV1_INIT_INTERRUPTS_MODE       (uint8)(((uint8)(0u <<   \
                                                    SRV1_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    SRV1_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    SRV1_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    SRV1_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define SRV1_DEFAULT_COMPARE2_MODE      (uint8)((uint8)2u <<  SRV1_CTRL_CMPMODE2_SHIFT)
#define SRV1_DEFAULT_COMPARE1_MODE      (uint8)((uint8)2u <<  SRV1_CTRL_CMPMODE1_SHIFT)
#define SRV1_INIT_DEAD_TIME             (1u)


/********************************
*         Registers
******************************** */

#if (SRV1_UsingFixedFunction)
   #define SRV1_PERIOD_LSB              (*(reg16 *) SRV1_PWMHW__PER0)
   #define SRV1_PERIOD_LSB_PTR          ( (reg16 *) SRV1_PWMHW__PER0)
   #define SRV1_COMPARE1_LSB            (*(reg16 *) SRV1_PWMHW__CNT_CMP0)
   #define SRV1_COMPARE1_LSB_PTR        ( (reg16 *) SRV1_PWMHW__CNT_CMP0)
   #define SRV1_COMPARE2_LSB            (0x00u)
   #define SRV1_COMPARE2_LSB_PTR        (0x00u)
   #define SRV1_COUNTER_LSB             (*(reg16 *) SRV1_PWMHW__CNT_CMP0)
   #define SRV1_COUNTER_LSB_PTR         ( (reg16 *) SRV1_PWMHW__CNT_CMP0)
   #define SRV1_CAPTURE_LSB             (*(reg16 *) SRV1_PWMHW__CAP0)
   #define SRV1_CAPTURE_LSB_PTR         ( (reg16 *) SRV1_PWMHW__CAP0)
   #define SRV1_RT1                     (*(reg8 *)  SRV1_PWMHW__RT1)
   #define SRV1_RT1_PTR                 ( (reg8 *)  SRV1_PWMHW__RT1)

#else
   #if (SRV1_Resolution == 8u) /* 8bit - PWM */

       #if(SRV1_PWMModeIsCenterAligned)
           #define SRV1_PERIOD_LSB      (*(reg8 *)  SRV1_PWMUDB_sP16_pwmdp_u0__D1_REG)
           #define SRV1_PERIOD_LSB_PTR  ((reg8 *)   SRV1_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #else
           #define SRV1_PERIOD_LSB      (*(reg8 *)  SRV1_PWMUDB_sP16_pwmdp_u0__F0_REG)
           #define SRV1_PERIOD_LSB_PTR  ((reg8 *)   SRV1_PWMUDB_sP16_pwmdp_u0__F0_REG)
       #endif /* (SRV1_PWMModeIsCenterAligned) */

       #define SRV1_COMPARE1_LSB        (*(reg8 *)  SRV1_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define SRV1_COMPARE1_LSB_PTR    ((reg8 *)   SRV1_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define SRV1_COMPARE2_LSB        (*(reg8 *)  SRV1_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define SRV1_COMPARE2_LSB_PTR    ((reg8 *)   SRV1_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define SRV1_COUNTERCAP_LSB      (*(reg8 *)  SRV1_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define SRV1_COUNTERCAP_LSB_PTR  ((reg8 *)   SRV1_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define SRV1_COUNTER_LSB         (*(reg8 *)  SRV1_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define SRV1_COUNTER_LSB_PTR     ((reg8 *)   SRV1_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define SRV1_CAPTURE_LSB         (*(reg8 *)  SRV1_PWMUDB_sP16_pwmdp_u0__F1_REG)
       #define SRV1_CAPTURE_LSB_PTR     ((reg8 *)   SRV1_PWMUDB_sP16_pwmdp_u0__F1_REG)

   #else
        #if(CY_PSOC3) /* 8-bit address space */
            #if(SRV1_PWMModeIsCenterAligned)
               #define SRV1_PERIOD_LSB      (*(reg16 *) SRV1_PWMUDB_sP16_pwmdp_u0__D1_REG)
               #define SRV1_PERIOD_LSB_PTR  ((reg16 *)  SRV1_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #else
               #define SRV1_PERIOD_LSB      (*(reg16 *) SRV1_PWMUDB_sP16_pwmdp_u0__F0_REG)
               #define SRV1_PERIOD_LSB_PTR  ((reg16 *)  SRV1_PWMUDB_sP16_pwmdp_u0__F0_REG)
            #endif /* (SRV1_PWMModeIsCenterAligned) */

            #define SRV1_COMPARE1_LSB       (*(reg16 *) SRV1_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define SRV1_COMPARE1_LSB_PTR   ((reg16 *)  SRV1_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define SRV1_COMPARE2_LSB       (*(reg16 *) SRV1_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define SRV1_COMPARE2_LSB_PTR   ((reg16 *)  SRV1_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define SRV1_COUNTERCAP_LSB     (*(reg16 *) SRV1_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define SRV1_COUNTERCAP_LSB_PTR ((reg16 *)  SRV1_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define SRV1_COUNTER_LSB        (*(reg16 *) SRV1_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define SRV1_COUNTER_LSB_PTR    ((reg16 *)  SRV1_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define SRV1_CAPTURE_LSB        (*(reg16 *) SRV1_PWMUDB_sP16_pwmdp_u0__F1_REG)
            #define SRV1_CAPTURE_LSB_PTR    ((reg16 *)  SRV1_PWMUDB_sP16_pwmdp_u0__F1_REG)
        #else
            #if(SRV1_PWMModeIsCenterAligned)
               #define SRV1_PERIOD_LSB      (*(reg16 *) SRV1_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
               #define SRV1_PERIOD_LSB_PTR  ((reg16 *)  SRV1_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #else
               #define SRV1_PERIOD_LSB      (*(reg16 *) SRV1_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
               #define SRV1_PERIOD_LSB_PTR  ((reg16 *)  SRV1_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
            #endif /* (SRV1_PWMModeIsCenterAligned) */

            #define SRV1_COMPARE1_LSB       (*(reg16 *) SRV1_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define SRV1_COMPARE1_LSB_PTR   ((reg16 *)  SRV1_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define SRV1_COMPARE2_LSB       (*(reg16 *) SRV1_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define SRV1_COMPARE2_LSB_PTR   ((reg16 *)  SRV1_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define SRV1_COUNTERCAP_LSB     (*(reg16 *) SRV1_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define SRV1_COUNTERCAP_LSB_PTR ((reg16 *)  SRV1_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define SRV1_COUNTER_LSB        (*(reg16 *) SRV1_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define SRV1_COUNTER_LSB_PTR    ((reg16 *)  SRV1_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define SRV1_CAPTURE_LSB        (*(reg16 *) SRV1_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
            #define SRV1_CAPTURE_LSB_PTR    ((reg16 *)  SRV1_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
        #endif /* (CY_PSOC3) */

       #define SRV1_AUX_CONTROLDP1          (*(reg8 *)  SRV1_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)
       #define SRV1_AUX_CONTROLDP1_PTR      ((reg8 *)   SRV1_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (SRV1_Resolution == 8) */

   #define SRV1_COUNTERCAP_LSB_PTR_8BIT ( (reg8 *)  SRV1_PWMUDB_sP16_pwmdp_u0__A1_REG)
   #define SRV1_AUX_CONTROLDP0          (*(reg8 *)  SRV1_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)
   #define SRV1_AUX_CONTROLDP0_PTR      ((reg8 *)   SRV1_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (SRV1_UsingFixedFunction) */

#if(SRV1_KillModeMinTime )
    #define SRV1_KILLMODEMINTIME        (*(reg8 *)  SRV1_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define SRV1_KILLMODEMINTIME_PTR    ((reg8 *)   SRV1_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (SRV1_KillModeMinTime ) */

#if(SRV1_DeadBandMode == SRV1__B_PWM__DBM_256_CLOCKS)
    #define SRV1_DEADBAND_COUNT         (*(reg8 *)  SRV1_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define SRV1_DEADBAND_COUNT_PTR     ((reg8 *)   SRV1_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define SRV1_DEADBAND_LSB_PTR       ((reg8 *)   SRV1_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define SRV1_DEADBAND_LSB           (*(reg8 *)  SRV1_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(SRV1_DeadBandMode == SRV1__B_PWM__DBM_2_4_CLOCKS)
    
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (SRV1_UsingFixedFunction)
        #define SRV1_DEADBAND_COUNT         (*(reg8 *)  SRV1_PWMHW__CFG0)
        #define SRV1_DEADBAND_COUNT_PTR     ((reg8 *)   SRV1_PWMHW__CFG0)
        #define SRV1_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << SRV1_DEADBAND_COUNT_SHIFT)

        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define SRV1_DEADBAND_COUNT_SHIFT   (0x06u)
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define SRV1_DEADBAND_COUNT         (*(reg8 *)  SRV1_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define SRV1_DEADBAND_COUNT_PTR     ((reg8 *)   SRV1_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define SRV1_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << SRV1_DEADBAND_COUNT_SHIFT)

        /* As defined by the verilog implementation of the Control Register */
        #define SRV1_DEADBAND_COUNT_SHIFT   (0x00u)
    #endif /* (SRV1_UsingFixedFunction) */
#endif /* (SRV1_DeadBandMode == SRV1__B_PWM__DBM_256_CLOCKS) */



#if (SRV1_UsingFixedFunction)
    #define SRV1_STATUS                 (*(reg8 *) SRV1_PWMHW__SR0)
    #define SRV1_STATUS_PTR             ((reg8 *) SRV1_PWMHW__SR0)
    #define SRV1_STATUS_MASK            (*(reg8 *) SRV1_PWMHW__SR0)
    #define SRV1_STATUS_MASK_PTR        ((reg8 *) SRV1_PWMHW__SR0)
    #define SRV1_CONTROL                (*(reg8 *) SRV1_PWMHW__CFG0)
    #define SRV1_CONTROL_PTR            ((reg8 *) SRV1_PWMHW__CFG0)
    #define SRV1_CONTROL2               (*(reg8 *) SRV1_PWMHW__CFG1)
    #define SRV1_CONTROL3               (*(reg8 *) SRV1_PWMHW__CFG2)
    #define SRV1_GLOBAL_ENABLE          (*(reg8 *) SRV1_PWMHW__PM_ACT_CFG)
    #define SRV1_GLOBAL_ENABLE_PTR      ( (reg8 *) SRV1_PWMHW__PM_ACT_CFG)
    #define SRV1_GLOBAL_STBY_ENABLE     (*(reg8 *) SRV1_PWMHW__PM_STBY_CFG)
    #define SRV1_GLOBAL_STBY_ENABLE_PTR ( (reg8 *) SRV1_PWMHW__PM_STBY_CFG)


    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define SRV1_BLOCK_EN_MASK          (SRV1_PWMHW__PM_ACT_MSK)
    #define SRV1_BLOCK_STBY_EN_MASK     (SRV1_PWMHW__PM_STBY_MSK)
    
    /* Control Register definitions */
    #define SRV1_CTRL_ENABLE_SHIFT      (0x00u)

    /* As defined by Register map as MODE_CFG bits in CFG2*/
    #define SRV1_CTRL_CMPMODE1_SHIFT    (0x04u)

    /* As defined by Register map */
    #define SRV1_CTRL_DEAD_TIME_SHIFT   (0x06u)  

    /* Fixed Function Block Only CFG register bit definitions */
    /*  Set to compare mode */
    #define SRV1_CFG0_MODE              (0x02u)   

    /* Enable the block to run */
    #define SRV1_CFG0_ENABLE            (0x01u)   
    
    /* As defined by Register map as DB bit in CFG0 */
    #define SRV1_CFG0_DB                (0x20u)   

    /* Control Register Bit Masks */
    #define SRV1_CTRL_ENABLE            (uint8)((uint8)0x01u << SRV1_CTRL_ENABLE_SHIFT)
    #define SRV1_CTRL_RESET             (uint8)((uint8)0x01u << SRV1_CTRL_RESET_SHIFT)
    #define SRV1_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << SRV1_CTRL_CMPMODE2_SHIFT)
    #define SRV1_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << SRV1_CTRL_CMPMODE1_SHIFT)

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define SRV1_CTRL2_IRQ_SEL_SHIFT    (0x00u)
    #define SRV1_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << SRV1_CTRL2_IRQ_SEL_SHIFT)

    /* Status Register Bit Locations */
    /* As defined by Register map as TC in SR0 */
    #define SRV1_STATUS_TC_SHIFT        (0x07u)   
    
    /* As defined by the Register map as CAP_CMP in SR0 */
    #define SRV1_STATUS_CMP1_SHIFT      (0x06u)   

    /* Status Register Interrupt Enable Bit Locations */
    #define SRV1_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)
    #define SRV1_STATUS_TC_INT_EN_MASK_SHIFT            (SRV1_STATUS_TC_SHIFT - 4u)
    #define SRV1_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)
    #define SRV1_STATUS_CMP1_INT_EN_MASK_SHIFT          (SRV1_STATUS_CMP1_SHIFT - 4u)

    /* Status Register Bit Masks */
    #define SRV1_STATUS_TC              (uint8)((uint8)0x01u << SRV1_STATUS_TC_SHIFT)
    #define SRV1_STATUS_CMP1            (uint8)((uint8)0x01u << SRV1_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks */
    #define SRV1_STATUS_TC_INT_EN_MASK              (uint8)((uint8)SRV1_STATUS_TC >> 4u)
    #define SRV1_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)SRV1_STATUS_CMP1 >> 4u)

    /*RT1 Synch Constants */
    #define SRV1_RT1_SHIFT             (0x04u)

    /* Sync TC and CMP bit masks */
    #define SRV1_RT1_MASK              (uint8)((uint8)0x03u << SRV1_RT1_SHIFT)
    #define SRV1_SYNC                  (uint8)((uint8)0x03u << SRV1_RT1_SHIFT)
    #define SRV1_SYNCDSI_SHIFT         (0x00u)

    /* Sync all DSI inputs */
    #define SRV1_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << SRV1_SYNCDSI_SHIFT)

    /* Sync all DSI inputs */
    #define SRV1_SYNCDSI_EN            (uint8)((uint8)0x0Fu << SRV1_SYNCDSI_SHIFT)


#else
    #define SRV1_STATUS                (*(reg8 *)   SRV1_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define SRV1_STATUS_PTR            ((reg8 *)    SRV1_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define SRV1_STATUS_MASK           (*(reg8 *)   SRV1_PWMUDB_genblk8_stsreg__MASK_REG)
    #define SRV1_STATUS_MASK_PTR       ((reg8 *)    SRV1_PWMUDB_genblk8_stsreg__MASK_REG)
    #define SRV1_STATUS_AUX_CTRL       (*(reg8 *)   SRV1_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define SRV1_CONTROL               (*(reg8 *)   SRV1_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define SRV1_CONTROL_PTR           ((reg8 *)    SRV1_PWMUDB_genblk1_ctrlreg__CONTROL_REG)


    /***********************************
    *          Constants
    ***********************************/

    /* Control Register bit definitions */
    #define SRV1_CTRL_ENABLE_SHIFT      (0x07u)
    #define SRV1_CTRL_RESET_SHIFT       (0x06u)
    #define SRV1_CTRL_CMPMODE2_SHIFT    (0x03u)
    #define SRV1_CTRL_CMPMODE1_SHIFT    (0x00u)
    #define SRV1_CTRL_DEAD_TIME_SHIFT   (0x00u)   /* No Shift Needed for UDB block */
    
    /* Control Register Bit Masks */
    #define SRV1_CTRL_ENABLE            (uint8)((uint8)0x01u << SRV1_CTRL_ENABLE_SHIFT)
    #define SRV1_CTRL_RESET             (uint8)((uint8)0x01u << SRV1_CTRL_RESET_SHIFT)
    #define SRV1_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << SRV1_CTRL_CMPMODE2_SHIFT)
    #define SRV1_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << SRV1_CTRL_CMPMODE1_SHIFT)

    /* Status Register Bit Locations */
    #define SRV1_STATUS_KILL_SHIFT          (0x05u)
    #define SRV1_STATUS_FIFONEMPTY_SHIFT    (0x04u)
    #define SRV1_STATUS_FIFOFULL_SHIFT      (0x03u)
    #define SRV1_STATUS_TC_SHIFT            (0x02u)
    #define SRV1_STATUS_CMP2_SHIFT          (0x01u)
    #define SRV1_STATUS_CMP1_SHIFT          (0x00u)

    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define SRV1_STATUS_KILL_INT_EN_MASK_SHIFT          (SRV1_STATUS_KILL_SHIFT)
    #define SRV1_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    (SRV1_STATUS_FIFONEMPTY_SHIFT)
    #define SRV1_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      (SRV1_STATUS_FIFOFULL_SHIFT)
    #define SRV1_STATUS_TC_INT_EN_MASK_SHIFT            (SRV1_STATUS_TC_SHIFT)
    #define SRV1_STATUS_CMP2_INT_EN_MASK_SHIFT          (SRV1_STATUS_CMP2_SHIFT)
    #define SRV1_STATUS_CMP1_INT_EN_MASK_SHIFT          (SRV1_STATUS_CMP1_SHIFT)

    /* Status Register Bit Masks */
    #define SRV1_STATUS_KILL            (uint8)((uint8)0x00u << SRV1_STATUS_KILL_SHIFT )
    #define SRV1_STATUS_FIFOFULL        (uint8)((uint8)0x01u << SRV1_STATUS_FIFOFULL_SHIFT)
    #define SRV1_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << SRV1_STATUS_FIFONEMPTY_SHIFT)
    #define SRV1_STATUS_TC              (uint8)((uint8)0x01u << SRV1_STATUS_TC_SHIFT)
    #define SRV1_STATUS_CMP2            (uint8)((uint8)0x01u << SRV1_STATUS_CMP2_SHIFT)
    #define SRV1_STATUS_CMP1            (uint8)((uint8)0x01u << SRV1_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define SRV1_STATUS_KILL_INT_EN_MASK            (SRV1_STATUS_KILL)
    #define SRV1_STATUS_FIFOFULL_INT_EN_MASK        (SRV1_STATUS_FIFOFULL)
    #define SRV1_STATUS_FIFONEMPTY_INT_EN_MASK      (SRV1_STATUS_FIFONEMPTY)
    #define SRV1_STATUS_TC_INT_EN_MASK              (SRV1_STATUS_TC)
    #define SRV1_STATUS_CMP2_INT_EN_MASK            (SRV1_STATUS_CMP2)
    #define SRV1_STATUS_CMP1_INT_EN_MASK            (SRV1_STATUS_CMP1)

    /* Datapath Auxillary Control Register bit definitions */
    #define SRV1_AUX_CTRL_FIFO0_CLR         (0x01u)
    #define SRV1_AUX_CTRL_FIFO1_CLR         (0x02u)
    #define SRV1_AUX_CTRL_FIFO0_LVL         (0x04u)
    #define SRV1_AUX_CTRL_FIFO1_LVL         (0x08u)
    #define SRV1_STATUS_ACTL_INT_EN_MASK    (0x10u) /* As defined for the ACTL Register */
#endif /* SRV1_UsingFixedFunction */

#endif  /* CY_PWM_SRV1_H */


/* [] END OF FILE */
