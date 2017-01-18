/*******************************************************************************
* File Name: SRV4.h
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

#if !defined(CY_PWM_SRV4_H)
#define CY_PWM_SRV4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CyLib.h" /* For CyEnterCriticalSection() and CyExitCriticalSection() functions */

extern uint8 SRV4_initVar;


/***************************************
* Conditional Compilation Parameters
***************************************/
#define SRV4_Resolution                     (16u)
#define SRV4_UsingFixedFunction             (0u)
#define SRV4_DeadBandMode                   (0u)
#define SRV4_KillModeMinTime                (0u)
#define SRV4_KillMode                       (0u)
#define SRV4_PWMMode                        (1u)
#define SRV4_PWMModeIsCenterAligned         (0u)
#define SRV4_DeadBandUsed                   (0u)
#define SRV4_DeadBand2_4                    (0u)

#if !defined(SRV4_PWMUDB_genblk8_stsreg__REMOVED)
    #define SRV4_UseStatus                  (1u)
#else
    #define SRV4_UseStatus                  (0u)
#endif /* !defined(SRV4_PWMUDB_genblk8_stsreg__REMOVED) */

#if !defined(SRV4_PWMUDB_genblk1_ctrlreg__REMOVED)
    #define SRV4_UseControl                 (1u)
#else
    #define SRV4_UseControl                 (0u)
#endif /* !defined(SRV4_PWMUDB_genblk1_ctrlreg__REMOVED) */

#define SRV4_UseOneCompareMode              (0u)
#define SRV4_MinimumKillTime                (1u)
#define SRV4_EnableMode                     (2u)

#define SRV4_CompareMode1SW                 (0u)
#define SRV4_CompareMode2SW                 (0u)

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component PWM_v3_30 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */

/* Use Kill Mode Enumerated Types */
#define SRV4__B_PWM__DISABLED 0
#define SRV4__B_PWM__ASYNCHRONOUS 1
#define SRV4__B_PWM__SINGLECYCLE 2
#define SRV4__B_PWM__LATCHED 3
#define SRV4__B_PWM__MINTIME 4


/* Use Dead Band Mode Enumerated Types */
#define SRV4__B_PWM__DBMDISABLED 0
#define SRV4__B_PWM__DBM_2_4_CLOCKS 1
#define SRV4__B_PWM__DBM_256_CLOCKS 2


/* Used PWM Mode Enumerated Types */
#define SRV4__B_PWM__ONE_OUTPUT 0
#define SRV4__B_PWM__TWO_OUTPUTS 1
#define SRV4__B_PWM__DUAL_EDGE 2
#define SRV4__B_PWM__CENTER_ALIGN 3
#define SRV4__B_PWM__DITHER 5
#define SRV4__B_PWM__HARDWARESELECT 4


/* Used PWM Compare Mode Enumerated Types */
#define SRV4__B_PWM__LESS_THAN 1
#define SRV4__B_PWM__LESS_THAN_OR_EQUAL 2
#define SRV4__B_PWM__GREATER_THAN 3
#define SRV4__B_PWM__GREATER_THAN_OR_EQUAL_TO 4
#define SRV4__B_PWM__EQUAL 0
#define SRV4__B_PWM__FIRMWARE 5



/***************************************
* Data Struct Definition
***************************************/


/**************************************************************************
 * Sleep Wakeup Backup structure for PWM Component
 *************************************************************************/
typedef struct
{

    uint8 PWMEnableState;

    #if(!SRV4_UsingFixedFunction)
        uint16 PWMUdb;               /* PWM Current Counter value  */
        #if(!SRV4_PWMModeIsCenterAligned)
            uint16 PWMPeriod;
        #endif /* (!SRV4_PWMModeIsCenterAligned) */
        #if (SRV4_UseStatus)
            uint8 InterruptMaskValue;   /* PWM Current Interrupt Mask */
        #endif /* (SRV4_UseStatus) */

        /* Backup for Deadband parameters */
        #if(SRV4_DeadBandMode == SRV4__B_PWM__DBM_256_CLOCKS || \
            SRV4_DeadBandMode == SRV4__B_PWM__DBM_2_4_CLOCKS)
            uint8 PWMdeadBandValue; /* Dead Band Counter Current Value */
        #endif /* deadband count is either 2-4 clocks or 256 clocks */

        /* Backup Kill Mode Counter*/
        #if(SRV4_KillModeMinTime)
            uint8 PWMKillCounterPeriod; /* Kill Mode period value */
        #endif /* (SRV4_KillModeMinTime) */

        /* Backup control register */
        #if(SRV4_UseControl)
            uint8 PWMControlRegister; /* PWM Control Register value */
        #endif /* (SRV4_UseControl) */

    #endif /* (!SRV4_UsingFixedFunction) */

}SRV4_backupStruct;


/***************************************
*        Function Prototypes
 **************************************/

void    SRV4_Start(void) ;
void    SRV4_Stop(void) ;

#if (SRV4_UseStatus || SRV4_UsingFixedFunction)
    void  SRV4_SetInterruptMode(uint8 interruptMode) ;
    uint8 SRV4_ReadStatusRegister(void) ;
#endif /* (SRV4_UseStatus || SRV4_UsingFixedFunction) */

#define SRV4_GetInterruptSource() SRV4_ReadStatusRegister()

#if (SRV4_UseControl)
    uint8 SRV4_ReadControlRegister(void) ;
    void  SRV4_WriteControlRegister(uint8 control)
          ;
#endif /* (SRV4_UseControl) */

#if (SRV4_UseOneCompareMode)
   #if (SRV4_CompareMode1SW)
       void    SRV4_SetCompareMode(uint8 comparemode)
               ;
   #endif /* (SRV4_CompareMode1SW) */
#else
    #if (SRV4_CompareMode1SW)
        void    SRV4_SetCompareMode1(uint8 comparemode)
                ;
    #endif /* (SRV4_CompareMode1SW) */
    #if (SRV4_CompareMode2SW)
        void    SRV4_SetCompareMode2(uint8 comparemode)
                ;
    #endif /* (SRV4_CompareMode2SW) */
#endif /* (SRV4_UseOneCompareMode) */

#if (!SRV4_UsingFixedFunction)
    uint16   SRV4_ReadCounter(void) ;
    uint16 SRV4_ReadCapture(void) ;

    #if (SRV4_UseStatus)
            void SRV4_ClearFIFO(void) ;
    #endif /* (SRV4_UseStatus) */

    void    SRV4_WriteCounter(uint16 counter)
            ;
#endif /* (!SRV4_UsingFixedFunction) */

void    SRV4_WritePeriod(uint16 period)
        ;
uint16 SRV4_ReadPeriod(void) ;

#if (SRV4_UseOneCompareMode)
    void    SRV4_WriteCompare(uint16 compare)
            ;
    uint16 SRV4_ReadCompare(void) ;
#else
    void    SRV4_WriteCompare1(uint16 compare)
            ;
    uint16 SRV4_ReadCompare1(void) ;
    void    SRV4_WriteCompare2(uint16 compare)
            ;
    uint16 SRV4_ReadCompare2(void) ;
#endif /* (SRV4_UseOneCompareMode) */


#if (SRV4_DeadBandUsed)
    void    SRV4_WriteDeadTime(uint8 deadtime) ;
    uint8   SRV4_ReadDeadTime(void) ;
#endif /* (SRV4_DeadBandUsed) */

#if ( SRV4_KillModeMinTime)
    void SRV4_WriteKillTime(uint8 killtime) ;
    uint8 SRV4_ReadKillTime(void) ;
#endif /* ( SRV4_KillModeMinTime) */

void SRV4_Init(void) ;
void SRV4_Enable(void) ;
void SRV4_Sleep(void) ;
void SRV4_Wakeup(void) ;
void SRV4_SaveConfig(void) ;
void SRV4_RestoreConfig(void) ;


/***************************************
*         Initialization Values
**************************************/
#define SRV4_INIT_PERIOD_VALUE          (40000u)
#define SRV4_INIT_COMPARE_VALUE1        (4000u)
#define SRV4_INIT_COMPARE_VALUE2        (4000u)
#define SRV4_INIT_INTERRUPTS_MODE       (uint8)(((uint8)(0u <<   \
                                                    SRV4_STATUS_TC_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    SRV4_STATUS_CMP2_INT_EN_MASK_SHIFT)) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    SRV4_STATUS_CMP1_INT_EN_MASK_SHIFT )) | \
                                                    (uint8)((uint8)(0u <<  \
                                                    SRV4_STATUS_KILL_INT_EN_MASK_SHIFT )))
#define SRV4_DEFAULT_COMPARE2_MODE      (uint8)((uint8)2u <<  SRV4_CTRL_CMPMODE2_SHIFT)
#define SRV4_DEFAULT_COMPARE1_MODE      (uint8)((uint8)2u <<  SRV4_CTRL_CMPMODE1_SHIFT)
#define SRV4_INIT_DEAD_TIME             (1u)


/********************************
*         Registers
******************************** */

#if (SRV4_UsingFixedFunction)
   #define SRV4_PERIOD_LSB              (*(reg16 *) SRV4_PWMHW__PER0)
   #define SRV4_PERIOD_LSB_PTR          ( (reg16 *) SRV4_PWMHW__PER0)
   #define SRV4_COMPARE1_LSB            (*(reg16 *) SRV4_PWMHW__CNT_CMP0)
   #define SRV4_COMPARE1_LSB_PTR        ( (reg16 *) SRV4_PWMHW__CNT_CMP0)
   #define SRV4_COMPARE2_LSB            (0x00u)
   #define SRV4_COMPARE2_LSB_PTR        (0x00u)
   #define SRV4_COUNTER_LSB             (*(reg16 *) SRV4_PWMHW__CNT_CMP0)
   #define SRV4_COUNTER_LSB_PTR         ( (reg16 *) SRV4_PWMHW__CNT_CMP0)
   #define SRV4_CAPTURE_LSB             (*(reg16 *) SRV4_PWMHW__CAP0)
   #define SRV4_CAPTURE_LSB_PTR         ( (reg16 *) SRV4_PWMHW__CAP0)
   #define SRV4_RT1                     (*(reg8 *)  SRV4_PWMHW__RT1)
   #define SRV4_RT1_PTR                 ( (reg8 *)  SRV4_PWMHW__RT1)

#else
   #if (SRV4_Resolution == 8u) /* 8bit - PWM */

       #if(SRV4_PWMModeIsCenterAligned)
           #define SRV4_PERIOD_LSB      (*(reg8 *)  SRV4_PWMUDB_sP16_pwmdp_u0__D1_REG)
           #define SRV4_PERIOD_LSB_PTR  ((reg8 *)   SRV4_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #else
           #define SRV4_PERIOD_LSB      (*(reg8 *)  SRV4_PWMUDB_sP16_pwmdp_u0__F0_REG)
           #define SRV4_PERIOD_LSB_PTR  ((reg8 *)   SRV4_PWMUDB_sP16_pwmdp_u0__F0_REG)
       #endif /* (SRV4_PWMModeIsCenterAligned) */

       #define SRV4_COMPARE1_LSB        (*(reg8 *)  SRV4_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define SRV4_COMPARE1_LSB_PTR    ((reg8 *)   SRV4_PWMUDB_sP16_pwmdp_u0__D0_REG)
       #define SRV4_COMPARE2_LSB        (*(reg8 *)  SRV4_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define SRV4_COMPARE2_LSB_PTR    ((reg8 *)   SRV4_PWMUDB_sP16_pwmdp_u0__D1_REG)
       #define SRV4_COUNTERCAP_LSB      (*(reg8 *)  SRV4_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define SRV4_COUNTERCAP_LSB_PTR  ((reg8 *)   SRV4_PWMUDB_sP16_pwmdp_u0__A1_REG)
       #define SRV4_COUNTER_LSB         (*(reg8 *)  SRV4_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define SRV4_COUNTER_LSB_PTR     ((reg8 *)   SRV4_PWMUDB_sP16_pwmdp_u0__A0_REG)
       #define SRV4_CAPTURE_LSB         (*(reg8 *)  SRV4_PWMUDB_sP16_pwmdp_u0__F1_REG)
       #define SRV4_CAPTURE_LSB_PTR     ((reg8 *)   SRV4_PWMUDB_sP16_pwmdp_u0__F1_REG)

   #else
        #if(CY_PSOC3) /* 8-bit address space */
            #if(SRV4_PWMModeIsCenterAligned)
               #define SRV4_PERIOD_LSB      (*(reg16 *) SRV4_PWMUDB_sP16_pwmdp_u0__D1_REG)
               #define SRV4_PERIOD_LSB_PTR  ((reg16 *)  SRV4_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #else
               #define SRV4_PERIOD_LSB      (*(reg16 *) SRV4_PWMUDB_sP16_pwmdp_u0__F0_REG)
               #define SRV4_PERIOD_LSB_PTR  ((reg16 *)  SRV4_PWMUDB_sP16_pwmdp_u0__F0_REG)
            #endif /* (SRV4_PWMModeIsCenterAligned) */

            #define SRV4_COMPARE1_LSB       (*(reg16 *) SRV4_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define SRV4_COMPARE1_LSB_PTR   ((reg16 *)  SRV4_PWMUDB_sP16_pwmdp_u0__D0_REG)
            #define SRV4_COMPARE2_LSB       (*(reg16 *) SRV4_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define SRV4_COMPARE2_LSB_PTR   ((reg16 *)  SRV4_PWMUDB_sP16_pwmdp_u0__D1_REG)
            #define SRV4_COUNTERCAP_LSB     (*(reg16 *) SRV4_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define SRV4_COUNTERCAP_LSB_PTR ((reg16 *)  SRV4_PWMUDB_sP16_pwmdp_u0__A1_REG)
            #define SRV4_COUNTER_LSB        (*(reg16 *) SRV4_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define SRV4_COUNTER_LSB_PTR    ((reg16 *)  SRV4_PWMUDB_sP16_pwmdp_u0__A0_REG)
            #define SRV4_CAPTURE_LSB        (*(reg16 *) SRV4_PWMUDB_sP16_pwmdp_u0__F1_REG)
            #define SRV4_CAPTURE_LSB_PTR    ((reg16 *)  SRV4_PWMUDB_sP16_pwmdp_u0__F1_REG)
        #else
            #if(SRV4_PWMModeIsCenterAligned)
               #define SRV4_PERIOD_LSB      (*(reg16 *) SRV4_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
               #define SRV4_PERIOD_LSB_PTR  ((reg16 *)  SRV4_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #else
               #define SRV4_PERIOD_LSB      (*(reg16 *) SRV4_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
               #define SRV4_PERIOD_LSB_PTR  ((reg16 *)  SRV4_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG)
            #endif /* (SRV4_PWMModeIsCenterAligned) */

            #define SRV4_COMPARE1_LSB       (*(reg16 *) SRV4_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define SRV4_COMPARE1_LSB_PTR   ((reg16 *)  SRV4_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG)
            #define SRV4_COMPARE2_LSB       (*(reg16 *) SRV4_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define SRV4_COMPARE2_LSB_PTR   ((reg16 *)  SRV4_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG)
            #define SRV4_COUNTERCAP_LSB     (*(reg16 *) SRV4_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define SRV4_COUNTERCAP_LSB_PTR ((reg16 *)  SRV4_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG)
            #define SRV4_COUNTER_LSB        (*(reg16 *) SRV4_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define SRV4_COUNTER_LSB_PTR    ((reg16 *)  SRV4_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG)
            #define SRV4_CAPTURE_LSB        (*(reg16 *) SRV4_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
            #define SRV4_CAPTURE_LSB_PTR    ((reg16 *)  SRV4_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG)
        #endif /* (CY_PSOC3) */

       #define SRV4_AUX_CONTROLDP1          (*(reg8 *)  SRV4_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)
       #define SRV4_AUX_CONTROLDP1_PTR      ((reg8 *)   SRV4_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG)

   #endif /* (SRV4_Resolution == 8) */

   #define SRV4_COUNTERCAP_LSB_PTR_8BIT ( (reg8 *)  SRV4_PWMUDB_sP16_pwmdp_u0__A1_REG)
   #define SRV4_AUX_CONTROLDP0          (*(reg8 *)  SRV4_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)
   #define SRV4_AUX_CONTROLDP0_PTR      ((reg8 *)   SRV4_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG)

#endif /* (SRV4_UsingFixedFunction) */

#if(SRV4_KillModeMinTime )
    #define SRV4_KILLMODEMINTIME        (*(reg8 *)  SRV4_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    #define SRV4_KILLMODEMINTIME_PTR    ((reg8 *)   SRV4_PWMUDB_sKM_killmodecounterdp_u0__D0_REG)
    /* Fixed Function Block has no Kill Mode parameters because it is Asynchronous only */
#endif /* (SRV4_KillModeMinTime ) */

#if(SRV4_DeadBandMode == SRV4__B_PWM__DBM_256_CLOCKS)
    #define SRV4_DEADBAND_COUNT         (*(reg8 *)  SRV4_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define SRV4_DEADBAND_COUNT_PTR     ((reg8 *)   SRV4_PWMUDB_sDB255_deadbandcounterdp_u0__D0_REG)
    #define SRV4_DEADBAND_LSB_PTR       ((reg8 *)   SRV4_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
    #define SRV4_DEADBAND_LSB           (*(reg8 *)  SRV4_PWMUDB_sDB255_deadbandcounterdp_u0__A0_REG)
#elif(SRV4_DeadBandMode == SRV4__B_PWM__DBM_2_4_CLOCKS)
    
    /* In Fixed Function Block these bits are in the control blocks control register */
    #if (SRV4_UsingFixedFunction)
        #define SRV4_DEADBAND_COUNT         (*(reg8 *)  SRV4_PWMHW__CFG0)
        #define SRV4_DEADBAND_COUNT_PTR     ((reg8 *)   SRV4_PWMHW__CFG0)
        #define SRV4_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << SRV4_DEADBAND_COUNT_SHIFT)

        /* As defined by the Register Map as DEADBAND_PERIOD[1:0] in CFG0 */
        #define SRV4_DEADBAND_COUNT_SHIFT   (0x06u)
    #else
        /* Lower two bits of the added control register define the count 1-3 */
        #define SRV4_DEADBAND_COUNT         (*(reg8 *)  SRV4_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define SRV4_DEADBAND_COUNT_PTR     ((reg8 *)   SRV4_PWMUDB_genblk7_dbctrlreg__CONTROL_REG)
        #define SRV4_DEADBAND_COUNT_MASK    (uint8)((uint8)0x03u << SRV4_DEADBAND_COUNT_SHIFT)

        /* As defined by the verilog implementation of the Control Register */
        #define SRV4_DEADBAND_COUNT_SHIFT   (0x00u)
    #endif /* (SRV4_UsingFixedFunction) */
#endif /* (SRV4_DeadBandMode == SRV4__B_PWM__DBM_256_CLOCKS) */



#if (SRV4_UsingFixedFunction)
    #define SRV4_STATUS                 (*(reg8 *) SRV4_PWMHW__SR0)
    #define SRV4_STATUS_PTR             ((reg8 *) SRV4_PWMHW__SR0)
    #define SRV4_STATUS_MASK            (*(reg8 *) SRV4_PWMHW__SR0)
    #define SRV4_STATUS_MASK_PTR        ((reg8 *) SRV4_PWMHW__SR0)
    #define SRV4_CONTROL                (*(reg8 *) SRV4_PWMHW__CFG0)
    #define SRV4_CONTROL_PTR            ((reg8 *) SRV4_PWMHW__CFG0)
    #define SRV4_CONTROL2               (*(reg8 *) SRV4_PWMHW__CFG1)
    #define SRV4_CONTROL3               (*(reg8 *) SRV4_PWMHW__CFG2)
    #define SRV4_GLOBAL_ENABLE          (*(reg8 *) SRV4_PWMHW__PM_ACT_CFG)
    #define SRV4_GLOBAL_ENABLE_PTR      ( (reg8 *) SRV4_PWMHW__PM_ACT_CFG)
    #define SRV4_GLOBAL_STBY_ENABLE     (*(reg8 *) SRV4_PWMHW__PM_STBY_CFG)
    #define SRV4_GLOBAL_STBY_ENABLE_PTR ( (reg8 *) SRV4_PWMHW__PM_STBY_CFG)


    /***********************************
    *          Constants
    ***********************************/

    /* Fixed Function Block Chosen */
    #define SRV4_BLOCK_EN_MASK          (SRV4_PWMHW__PM_ACT_MSK)
    #define SRV4_BLOCK_STBY_EN_MASK     (SRV4_PWMHW__PM_STBY_MSK)
    
    /* Control Register definitions */
    #define SRV4_CTRL_ENABLE_SHIFT      (0x00u)

    /* As defined by Register map as MODE_CFG bits in CFG2*/
    #define SRV4_CTRL_CMPMODE1_SHIFT    (0x04u)

    /* As defined by Register map */
    #define SRV4_CTRL_DEAD_TIME_SHIFT   (0x06u)  

    /* Fixed Function Block Only CFG register bit definitions */
    /*  Set to compare mode */
    #define SRV4_CFG0_MODE              (0x02u)   

    /* Enable the block to run */
    #define SRV4_CFG0_ENABLE            (0x01u)   
    
    /* As defined by Register map as DB bit in CFG0 */
    #define SRV4_CFG0_DB                (0x20u)   

    /* Control Register Bit Masks */
    #define SRV4_CTRL_ENABLE            (uint8)((uint8)0x01u << SRV4_CTRL_ENABLE_SHIFT)
    #define SRV4_CTRL_RESET             (uint8)((uint8)0x01u << SRV4_CTRL_RESET_SHIFT)
    #define SRV4_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << SRV4_CTRL_CMPMODE2_SHIFT)
    #define SRV4_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << SRV4_CTRL_CMPMODE1_SHIFT)

    /* Control2 Register Bit Masks */
    /* As defined in Register Map, Part of the TMRX_CFG1 register */
    #define SRV4_CTRL2_IRQ_SEL_SHIFT    (0x00u)
    #define SRV4_CTRL2_IRQ_SEL          (uint8)((uint8)0x01u << SRV4_CTRL2_IRQ_SEL_SHIFT)

    /* Status Register Bit Locations */
    /* As defined by Register map as TC in SR0 */
    #define SRV4_STATUS_TC_SHIFT        (0x07u)   
    
    /* As defined by the Register map as CAP_CMP in SR0 */
    #define SRV4_STATUS_CMP1_SHIFT      (0x06u)   

    /* Status Register Interrupt Enable Bit Locations */
    #define SRV4_STATUS_KILL_INT_EN_MASK_SHIFT          (0x00u)
    #define SRV4_STATUS_TC_INT_EN_MASK_SHIFT            (SRV4_STATUS_TC_SHIFT - 4u)
    #define SRV4_STATUS_CMP2_INT_EN_MASK_SHIFT          (0x00u)
    #define SRV4_STATUS_CMP1_INT_EN_MASK_SHIFT          (SRV4_STATUS_CMP1_SHIFT - 4u)

    /* Status Register Bit Masks */
    #define SRV4_STATUS_TC              (uint8)((uint8)0x01u << SRV4_STATUS_TC_SHIFT)
    #define SRV4_STATUS_CMP1            (uint8)((uint8)0x01u << SRV4_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks */
    #define SRV4_STATUS_TC_INT_EN_MASK              (uint8)((uint8)SRV4_STATUS_TC >> 4u)
    #define SRV4_STATUS_CMP1_INT_EN_MASK            (uint8)((uint8)SRV4_STATUS_CMP1 >> 4u)

    /*RT1 Synch Constants */
    #define SRV4_RT1_SHIFT             (0x04u)

    /* Sync TC and CMP bit masks */
    #define SRV4_RT1_MASK              (uint8)((uint8)0x03u << SRV4_RT1_SHIFT)
    #define SRV4_SYNC                  (uint8)((uint8)0x03u << SRV4_RT1_SHIFT)
    #define SRV4_SYNCDSI_SHIFT         (0x00u)

    /* Sync all DSI inputs */
    #define SRV4_SYNCDSI_MASK          (uint8)((uint8)0x0Fu << SRV4_SYNCDSI_SHIFT)

    /* Sync all DSI inputs */
    #define SRV4_SYNCDSI_EN            (uint8)((uint8)0x0Fu << SRV4_SYNCDSI_SHIFT)


#else
    #define SRV4_STATUS                (*(reg8 *)   SRV4_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define SRV4_STATUS_PTR            ((reg8 *)    SRV4_PWMUDB_genblk8_stsreg__STATUS_REG )
    #define SRV4_STATUS_MASK           (*(reg8 *)   SRV4_PWMUDB_genblk8_stsreg__MASK_REG)
    #define SRV4_STATUS_MASK_PTR       ((reg8 *)    SRV4_PWMUDB_genblk8_stsreg__MASK_REG)
    #define SRV4_STATUS_AUX_CTRL       (*(reg8 *)   SRV4_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG)
    #define SRV4_CONTROL               (*(reg8 *)   SRV4_PWMUDB_genblk1_ctrlreg__CONTROL_REG)
    #define SRV4_CONTROL_PTR           ((reg8 *)    SRV4_PWMUDB_genblk1_ctrlreg__CONTROL_REG)


    /***********************************
    *          Constants
    ***********************************/

    /* Control Register bit definitions */
    #define SRV4_CTRL_ENABLE_SHIFT      (0x07u)
    #define SRV4_CTRL_RESET_SHIFT       (0x06u)
    #define SRV4_CTRL_CMPMODE2_SHIFT    (0x03u)
    #define SRV4_CTRL_CMPMODE1_SHIFT    (0x00u)
    #define SRV4_CTRL_DEAD_TIME_SHIFT   (0x00u)   /* No Shift Needed for UDB block */
    
    /* Control Register Bit Masks */
    #define SRV4_CTRL_ENABLE            (uint8)((uint8)0x01u << SRV4_CTRL_ENABLE_SHIFT)
    #define SRV4_CTRL_RESET             (uint8)((uint8)0x01u << SRV4_CTRL_RESET_SHIFT)
    #define SRV4_CTRL_CMPMODE2_MASK     (uint8)((uint8)0x07u << SRV4_CTRL_CMPMODE2_SHIFT)
    #define SRV4_CTRL_CMPMODE1_MASK     (uint8)((uint8)0x07u << SRV4_CTRL_CMPMODE1_SHIFT)

    /* Status Register Bit Locations */
    #define SRV4_STATUS_KILL_SHIFT          (0x05u)
    #define SRV4_STATUS_FIFONEMPTY_SHIFT    (0x04u)
    #define SRV4_STATUS_FIFOFULL_SHIFT      (0x03u)
    #define SRV4_STATUS_TC_SHIFT            (0x02u)
    #define SRV4_STATUS_CMP2_SHIFT          (0x01u)
    #define SRV4_STATUS_CMP1_SHIFT          (0x00u)

    /* Status Register Interrupt Enable Bit Locations - UDB Status Interrupt Mask match Status Bit Locations*/
    #define SRV4_STATUS_KILL_INT_EN_MASK_SHIFT          (SRV4_STATUS_KILL_SHIFT)
    #define SRV4_STATUS_FIFONEMPTY_INT_EN_MASK_SHIFT    (SRV4_STATUS_FIFONEMPTY_SHIFT)
    #define SRV4_STATUS_FIFOFULL_INT_EN_MASK_SHIFT      (SRV4_STATUS_FIFOFULL_SHIFT)
    #define SRV4_STATUS_TC_INT_EN_MASK_SHIFT            (SRV4_STATUS_TC_SHIFT)
    #define SRV4_STATUS_CMP2_INT_EN_MASK_SHIFT          (SRV4_STATUS_CMP2_SHIFT)
    #define SRV4_STATUS_CMP1_INT_EN_MASK_SHIFT          (SRV4_STATUS_CMP1_SHIFT)

    /* Status Register Bit Masks */
    #define SRV4_STATUS_KILL            (uint8)((uint8)0x00u << SRV4_STATUS_KILL_SHIFT )
    #define SRV4_STATUS_FIFOFULL        (uint8)((uint8)0x01u << SRV4_STATUS_FIFOFULL_SHIFT)
    #define SRV4_STATUS_FIFONEMPTY      (uint8)((uint8)0x01u << SRV4_STATUS_FIFONEMPTY_SHIFT)
    #define SRV4_STATUS_TC              (uint8)((uint8)0x01u << SRV4_STATUS_TC_SHIFT)
    #define SRV4_STATUS_CMP2            (uint8)((uint8)0x01u << SRV4_STATUS_CMP2_SHIFT)
    #define SRV4_STATUS_CMP1            (uint8)((uint8)0x01u << SRV4_STATUS_CMP1_SHIFT)

    /* Status Register Interrupt Bit Masks  - UDB Status Interrupt Mask match Status Bit Locations */
    #define SRV4_STATUS_KILL_INT_EN_MASK            (SRV4_STATUS_KILL)
    #define SRV4_STATUS_FIFOFULL_INT_EN_MASK        (SRV4_STATUS_FIFOFULL)
    #define SRV4_STATUS_FIFONEMPTY_INT_EN_MASK      (SRV4_STATUS_FIFONEMPTY)
    #define SRV4_STATUS_TC_INT_EN_MASK              (SRV4_STATUS_TC)
    #define SRV4_STATUS_CMP2_INT_EN_MASK            (SRV4_STATUS_CMP2)
    #define SRV4_STATUS_CMP1_INT_EN_MASK            (SRV4_STATUS_CMP1)

    /* Datapath Auxillary Control Register bit definitions */
    #define SRV4_AUX_CTRL_FIFO0_CLR         (0x01u)
    #define SRV4_AUX_CTRL_FIFO1_CLR         (0x02u)
    #define SRV4_AUX_CTRL_FIFO0_LVL         (0x04u)
    #define SRV4_AUX_CTRL_FIFO1_LVL         (0x08u)
    #define SRV4_STATUS_ACTL_INT_EN_MASK    (0x10u) /* As defined for the ACTL Register */
#endif /* SRV4_UsingFixedFunction */

#endif  /* CY_PWM_SRV4_H */


/* [] END OF FILE */
