/*******************************************************************************
* File Name: QuadDec_4.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the QuadDec_4
*  component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_TCPWM_QuadDec_4_H)
#define CY_TCPWM_QuadDec_4_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} QuadDec_4_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  QuadDec_4_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define QuadDec_4_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define QuadDec_4_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define QuadDec_4_CONFIG                         (3lu)

/* Quad Mode */
/* Parameters */
#define QuadDec_4_QUAD_ENCODING_MODES            (2lu)
#define QuadDec_4_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define QuadDec_4_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define QuadDec_4_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define QuadDec_4_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define QuadDec_4_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define QuadDec_4_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define QuadDec_4_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define QuadDec_4_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define QuadDec_4_TC_RUN_MODE                    (0lu)
#define QuadDec_4_TC_COUNTER_MODE                (0lu)
#define QuadDec_4_TC_COMP_CAP_MODE               (2lu)
#define QuadDec_4_TC_PRESCALER                   (0lu)

/* Signal modes */
#define QuadDec_4_TC_RELOAD_SIGNAL_MODE          (0lu)
#define QuadDec_4_TC_COUNT_SIGNAL_MODE           (3lu)
#define QuadDec_4_TC_START_SIGNAL_MODE           (0lu)
#define QuadDec_4_TC_STOP_SIGNAL_MODE            (0lu)
#define QuadDec_4_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define QuadDec_4_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define QuadDec_4_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define QuadDec_4_TC_START_SIGNAL_PRESENT        (0lu)
#define QuadDec_4_TC_STOP_SIGNAL_PRESENT         (0lu)
#define QuadDec_4_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define QuadDec_4_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define QuadDec_4_PWM_KILL_EVENT                 (0lu)
#define QuadDec_4_PWM_STOP_EVENT                 (0lu)
#define QuadDec_4_PWM_MODE                       (4lu)
#define QuadDec_4_PWM_OUT_N_INVERT               (0lu)
#define QuadDec_4_PWM_OUT_INVERT                 (0lu)
#define QuadDec_4_PWM_ALIGN                      (0lu)
#define QuadDec_4_PWM_RUN_MODE                   (0lu)
#define QuadDec_4_PWM_DEAD_TIME_CYCLE            (0lu)
#define QuadDec_4_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define QuadDec_4_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define QuadDec_4_PWM_COUNT_SIGNAL_MODE          (3lu)
#define QuadDec_4_PWM_START_SIGNAL_MODE          (0lu)
#define QuadDec_4_PWM_STOP_SIGNAL_MODE           (0lu)
#define QuadDec_4_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define QuadDec_4_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define QuadDec_4_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define QuadDec_4_PWM_START_SIGNAL_PRESENT       (0lu)
#define QuadDec_4_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define QuadDec_4_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define QuadDec_4_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define QuadDec_4_TC_PERIOD_VALUE                (65535lu)
#define QuadDec_4_TC_COMPARE_VALUE               (65535lu)
#define QuadDec_4_TC_COMPARE_BUF_VALUE           (65535lu)
#define QuadDec_4_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define QuadDec_4_PWM_PERIOD_VALUE               (65535lu)
#define QuadDec_4_PWM_PERIOD_BUF_VALUE           (65535lu)
#define QuadDec_4_PWM_PERIOD_SWAP                (0lu)
#define QuadDec_4_PWM_COMPARE_VALUE              (65535lu)
#define QuadDec_4_PWM_COMPARE_BUF_VALUE          (65535lu)
#define QuadDec_4_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define QuadDec_4__LEFT 0
#define QuadDec_4__RIGHT 1
#define QuadDec_4__CENTER 2
#define QuadDec_4__ASYMMETRIC 3

#define QuadDec_4__X1 0
#define QuadDec_4__X2 1
#define QuadDec_4__X4 2

#define QuadDec_4__PWM 4
#define QuadDec_4__PWM_DT 5
#define QuadDec_4__PWM_PR 6

#define QuadDec_4__INVERSE 1
#define QuadDec_4__DIRECT 0

#define QuadDec_4__CAPTURE 2
#define QuadDec_4__COMPARE 0

#define QuadDec_4__TRIG_LEVEL 3
#define QuadDec_4__TRIG_RISING 0
#define QuadDec_4__TRIG_FALLING 1
#define QuadDec_4__TRIG_BOTH 2

#define QuadDec_4__INTR_MASK_TC 1
#define QuadDec_4__INTR_MASK_CC_MATCH 2
#define QuadDec_4__INTR_MASK_NONE 0
#define QuadDec_4__INTR_MASK_TC_CC 3

#define QuadDec_4__UNCONFIG 8
#define QuadDec_4__TIMER 1
#define QuadDec_4__QUAD 3
#define QuadDec_4__PWM_SEL 7

#define QuadDec_4__COUNT_UP 0
#define QuadDec_4__COUNT_DOWN 1
#define QuadDec_4__COUNT_UPDOWN0 2
#define QuadDec_4__COUNT_UPDOWN1 3


/* Prescaler */
#define QuadDec_4_PRESCALE_DIVBY1                ((uint32)(0u << QuadDec_4_PRESCALER_SHIFT))
#define QuadDec_4_PRESCALE_DIVBY2                ((uint32)(1u << QuadDec_4_PRESCALER_SHIFT))
#define QuadDec_4_PRESCALE_DIVBY4                ((uint32)(2u << QuadDec_4_PRESCALER_SHIFT))
#define QuadDec_4_PRESCALE_DIVBY8                ((uint32)(3u << QuadDec_4_PRESCALER_SHIFT))
#define QuadDec_4_PRESCALE_DIVBY16               ((uint32)(4u << QuadDec_4_PRESCALER_SHIFT))
#define QuadDec_4_PRESCALE_DIVBY32               ((uint32)(5u << QuadDec_4_PRESCALER_SHIFT))
#define QuadDec_4_PRESCALE_DIVBY64               ((uint32)(6u << QuadDec_4_PRESCALER_SHIFT))
#define QuadDec_4_PRESCALE_DIVBY128              ((uint32)(7u << QuadDec_4_PRESCALER_SHIFT))

/* TCPWM set modes */
#define QuadDec_4_MODE_TIMER_COMPARE             ((uint32)(QuadDec_4__COMPARE         <<  \
                                                                  QuadDec_4_MODE_SHIFT))
#define QuadDec_4_MODE_TIMER_CAPTURE             ((uint32)(QuadDec_4__CAPTURE         <<  \
                                                                  QuadDec_4_MODE_SHIFT))
#define QuadDec_4_MODE_QUAD                      ((uint32)(QuadDec_4__QUAD            <<  \
                                                                  QuadDec_4_MODE_SHIFT))
#define QuadDec_4_MODE_PWM                       ((uint32)(QuadDec_4__PWM             <<  \
                                                                  QuadDec_4_MODE_SHIFT))
#define QuadDec_4_MODE_PWM_DT                    ((uint32)(QuadDec_4__PWM_DT          <<  \
                                                                  QuadDec_4_MODE_SHIFT))
#define QuadDec_4_MODE_PWM_PR                    ((uint32)(QuadDec_4__PWM_PR          <<  \
                                                                  QuadDec_4_MODE_SHIFT))

/* Quad Modes */
#define QuadDec_4_MODE_X1                        ((uint32)(QuadDec_4__X1              <<  \
                                                                  QuadDec_4_QUAD_MODE_SHIFT))
#define QuadDec_4_MODE_X2                        ((uint32)(QuadDec_4__X2              <<  \
                                                                  QuadDec_4_QUAD_MODE_SHIFT))
#define QuadDec_4_MODE_X4                        ((uint32)(QuadDec_4__X4              <<  \
                                                                  QuadDec_4_QUAD_MODE_SHIFT))

/* Counter modes */
#define QuadDec_4_COUNT_UP                       ((uint32)(QuadDec_4__COUNT_UP        <<  \
                                                                  QuadDec_4_UPDOWN_SHIFT))
#define QuadDec_4_COUNT_DOWN                     ((uint32)(QuadDec_4__COUNT_DOWN      <<  \
                                                                  QuadDec_4_UPDOWN_SHIFT))
#define QuadDec_4_COUNT_UPDOWN0                  ((uint32)(QuadDec_4__COUNT_UPDOWN0   <<  \
                                                                  QuadDec_4_UPDOWN_SHIFT))
#define QuadDec_4_COUNT_UPDOWN1                  ((uint32)(QuadDec_4__COUNT_UPDOWN1   <<  \
                                                                  QuadDec_4_UPDOWN_SHIFT))

/* PWM output invert */
#define QuadDec_4_INVERT_LINE                    ((uint32)(QuadDec_4__INVERSE         <<  \
                                                                  QuadDec_4_INV_OUT_SHIFT))
#define QuadDec_4_INVERT_LINE_N                  ((uint32)(QuadDec_4__INVERSE         <<  \
                                                                  QuadDec_4_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define QuadDec_4_TRIG_RISING                    ((uint32)QuadDec_4__TRIG_RISING)
#define QuadDec_4_TRIG_FALLING                   ((uint32)QuadDec_4__TRIG_FALLING)
#define QuadDec_4_TRIG_BOTH                      ((uint32)QuadDec_4__TRIG_BOTH)
#define QuadDec_4_TRIG_LEVEL                     ((uint32)QuadDec_4__TRIG_LEVEL)

/* Interrupt mask */
#define QuadDec_4_INTR_MASK_TC                   ((uint32)QuadDec_4__INTR_MASK_TC)
#define QuadDec_4_INTR_MASK_CC_MATCH             ((uint32)QuadDec_4__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define QuadDec_4_CC_MATCH_SET                   (0x00u)
#define QuadDec_4_CC_MATCH_CLEAR                 (0x01u)
#define QuadDec_4_CC_MATCH_INVERT                (0x02u)
#define QuadDec_4_CC_MATCH_NO_CHANGE             (0x03u)
#define QuadDec_4_OVERLOW_SET                    (0x00u)
#define QuadDec_4_OVERLOW_CLEAR                  (0x04u)
#define QuadDec_4_OVERLOW_INVERT                 (0x08u)
#define QuadDec_4_OVERLOW_NO_CHANGE              (0x0Cu)
#define QuadDec_4_UNDERFLOW_SET                  (0x00u)
#define QuadDec_4_UNDERFLOW_CLEAR                (0x10u)
#define QuadDec_4_UNDERFLOW_INVERT               (0x20u)
#define QuadDec_4_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define QuadDec_4_PWM_MODE_LEFT                  (QuadDec_4_CC_MATCH_CLEAR        |   \
                                                         QuadDec_4_OVERLOW_SET           |   \
                                                         QuadDec_4_UNDERFLOW_NO_CHANGE)
#define QuadDec_4_PWM_MODE_RIGHT                 (QuadDec_4_CC_MATCH_SET          |   \
                                                         QuadDec_4_OVERLOW_NO_CHANGE     |   \
                                                         QuadDec_4_UNDERFLOW_CLEAR)
#define QuadDec_4_PWM_MODE_ASYM                  (QuadDec_4_CC_MATCH_INVERT       |   \
                                                         QuadDec_4_OVERLOW_SET           |   \
                                                         QuadDec_4_UNDERFLOW_CLEAR)

#if (QuadDec_4_CY_TCPWM_V2)
    #if(QuadDec_4_CY_TCPWM_4000)
        #define QuadDec_4_PWM_MODE_CENTER                (QuadDec_4_CC_MATCH_INVERT       |   \
                                                                 QuadDec_4_OVERLOW_NO_CHANGE     |   \
                                                                 QuadDec_4_UNDERFLOW_CLEAR)
    #else
        #define QuadDec_4_PWM_MODE_CENTER                (QuadDec_4_CC_MATCH_INVERT       |   \
                                                                 QuadDec_4_OVERLOW_SET           |   \
                                                                 QuadDec_4_UNDERFLOW_CLEAR)
    #endif /* (QuadDec_4_CY_TCPWM_4000) */
#else
    #define QuadDec_4_PWM_MODE_CENTER                (QuadDec_4_CC_MATCH_INVERT       |   \
                                                             QuadDec_4_OVERLOW_NO_CHANGE     |   \
                                                             QuadDec_4_UNDERFLOW_CLEAR)
#endif /* (QuadDec_4_CY_TCPWM_NEW) */

/* Command operations without condition */
#define QuadDec_4_CMD_CAPTURE                    (0u)
#define QuadDec_4_CMD_RELOAD                     (8u)
#define QuadDec_4_CMD_STOP                       (16u)
#define QuadDec_4_CMD_START                      (24u)

/* Status */
#define QuadDec_4_STATUS_DOWN                    (1u)
#define QuadDec_4_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   QuadDec_4_Init(void);
void   QuadDec_4_Enable(void);
void   QuadDec_4_Start(void);
void   QuadDec_4_Stop(void);

void   QuadDec_4_SetMode(uint32 mode);
void   QuadDec_4_SetCounterMode(uint32 counterMode);
void   QuadDec_4_SetPWMMode(uint32 modeMask);
void   QuadDec_4_SetQDMode(uint32 qdMode);

void   QuadDec_4_SetPrescaler(uint32 prescaler);
void   QuadDec_4_TriggerCommand(uint32 mask, uint32 command);
void   QuadDec_4_SetOneShot(uint32 oneShotEnable);
uint32 QuadDec_4_ReadStatus(void);

void   QuadDec_4_SetPWMSyncKill(uint32 syncKillEnable);
void   QuadDec_4_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   QuadDec_4_SetPWMDeadTime(uint32 deadTime);
void   QuadDec_4_SetPWMInvert(uint32 mask);

void   QuadDec_4_SetInterruptMode(uint32 interruptMask);
uint32 QuadDec_4_GetInterruptSourceMasked(void);
uint32 QuadDec_4_GetInterruptSource(void);
void   QuadDec_4_ClearInterrupt(uint32 interruptMask);
void   QuadDec_4_SetInterrupt(uint32 interruptMask);

void   QuadDec_4_WriteCounter(uint32 count);
uint32 QuadDec_4_ReadCounter(void);

uint32 QuadDec_4_ReadCapture(void);
uint32 QuadDec_4_ReadCaptureBuf(void);

void   QuadDec_4_WritePeriod(uint32 period);
uint32 QuadDec_4_ReadPeriod(void);
void   QuadDec_4_WritePeriodBuf(uint32 periodBuf);
uint32 QuadDec_4_ReadPeriodBuf(void);

void   QuadDec_4_WriteCompare(uint32 compare);
uint32 QuadDec_4_ReadCompare(void);
void   QuadDec_4_WriteCompareBuf(uint32 compareBuf);
uint32 QuadDec_4_ReadCompareBuf(void);

void   QuadDec_4_SetPeriodSwap(uint32 swapEnable);
void   QuadDec_4_SetCompareSwap(uint32 swapEnable);

void   QuadDec_4_SetCaptureMode(uint32 triggerMode);
void   QuadDec_4_SetReloadMode(uint32 triggerMode);
void   QuadDec_4_SetStartMode(uint32 triggerMode);
void   QuadDec_4_SetStopMode(uint32 triggerMode);
void   QuadDec_4_SetCountMode(uint32 triggerMode);

void   QuadDec_4_SaveConfig(void);
void   QuadDec_4_RestoreConfig(void);
void   QuadDec_4_Sleep(void);
void   QuadDec_4_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define QuadDec_4_BLOCK_CONTROL_REG              (*(reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define QuadDec_4_BLOCK_CONTROL_PTR              ( (reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define QuadDec_4_COMMAND_REG                    (*(reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define QuadDec_4_COMMAND_PTR                    ( (reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define QuadDec_4_INTRRUPT_CAUSE_REG             (*(reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define QuadDec_4_INTRRUPT_CAUSE_PTR             ( (reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define QuadDec_4_CONTROL_REG                    (*(reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__CTRL )
#define QuadDec_4_CONTROL_PTR                    ( (reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__CTRL )
#define QuadDec_4_STATUS_REG                     (*(reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__STATUS )
#define QuadDec_4_STATUS_PTR                     ( (reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__STATUS )
#define QuadDec_4_COUNTER_REG                    (*(reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__COUNTER )
#define QuadDec_4_COUNTER_PTR                    ( (reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__COUNTER )
#define QuadDec_4_COMP_CAP_REG                   (*(reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__CC )
#define QuadDec_4_COMP_CAP_PTR                   ( (reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__CC )
#define QuadDec_4_COMP_CAP_BUF_REG               (*(reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__CC_BUFF )
#define QuadDec_4_COMP_CAP_BUF_PTR               ( (reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__CC_BUFF )
#define QuadDec_4_PERIOD_REG                     (*(reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__PERIOD )
#define QuadDec_4_PERIOD_PTR                     ( (reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__PERIOD )
#define QuadDec_4_PERIOD_BUF_REG                 (*(reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define QuadDec_4_PERIOD_BUF_PTR                 ( (reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define QuadDec_4_TRIG_CONTROL0_REG              (*(reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define QuadDec_4_TRIG_CONTROL0_PTR              ( (reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define QuadDec_4_TRIG_CONTROL1_REG              (*(reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define QuadDec_4_TRIG_CONTROL1_PTR              ( (reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define QuadDec_4_TRIG_CONTROL2_REG              (*(reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define QuadDec_4_TRIG_CONTROL2_PTR              ( (reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define QuadDec_4_INTERRUPT_REQ_REG              (*(reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__INTR )
#define QuadDec_4_INTERRUPT_REQ_PTR              ( (reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__INTR )
#define QuadDec_4_INTERRUPT_SET_REG              (*(reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__INTR_SET )
#define QuadDec_4_INTERRUPT_SET_PTR              ( (reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__INTR_SET )
#define QuadDec_4_INTERRUPT_MASK_REG             (*(reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__INTR_MASK )
#define QuadDec_4_INTERRUPT_MASK_PTR             ( (reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__INTR_MASK )
#define QuadDec_4_INTERRUPT_MASKED_REG           (*(reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__INTR_MASKED )
#define QuadDec_4_INTERRUPT_MASKED_PTR           ( (reg32 *) QuadDec_4_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define QuadDec_4_MASK                           ((uint32)QuadDec_4_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define QuadDec_4_RELOAD_CC_SHIFT                (0u)
#define QuadDec_4_RELOAD_PERIOD_SHIFT            (1u)
#define QuadDec_4_PWM_SYNC_KILL_SHIFT            (2u)
#define QuadDec_4_PWM_STOP_KILL_SHIFT            (3u)
#define QuadDec_4_PRESCALER_SHIFT                (8u)
#define QuadDec_4_UPDOWN_SHIFT                   (16u)
#define QuadDec_4_ONESHOT_SHIFT                  (18u)
#define QuadDec_4_QUAD_MODE_SHIFT                (20u)
#define QuadDec_4_INV_OUT_SHIFT                  (20u)
#define QuadDec_4_INV_COMPL_OUT_SHIFT            (21u)
#define QuadDec_4_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define QuadDec_4_RELOAD_CC_MASK                 ((uint32)(QuadDec_4_1BIT_MASK        <<  \
                                                                            QuadDec_4_RELOAD_CC_SHIFT))
#define QuadDec_4_RELOAD_PERIOD_MASK             ((uint32)(QuadDec_4_1BIT_MASK        <<  \
                                                                            QuadDec_4_RELOAD_PERIOD_SHIFT))
#define QuadDec_4_PWM_SYNC_KILL_MASK             ((uint32)(QuadDec_4_1BIT_MASK        <<  \
                                                                            QuadDec_4_PWM_SYNC_KILL_SHIFT))
#define QuadDec_4_PWM_STOP_KILL_MASK             ((uint32)(QuadDec_4_1BIT_MASK        <<  \
                                                                            QuadDec_4_PWM_STOP_KILL_SHIFT))
#define QuadDec_4_PRESCALER_MASK                 ((uint32)(QuadDec_4_8BIT_MASK        <<  \
                                                                            QuadDec_4_PRESCALER_SHIFT))
#define QuadDec_4_UPDOWN_MASK                    ((uint32)(QuadDec_4_2BIT_MASK        <<  \
                                                                            QuadDec_4_UPDOWN_SHIFT))
#define QuadDec_4_ONESHOT_MASK                   ((uint32)(QuadDec_4_1BIT_MASK        <<  \
                                                                            QuadDec_4_ONESHOT_SHIFT))
#define QuadDec_4_QUAD_MODE_MASK                 ((uint32)(QuadDec_4_3BIT_MASK        <<  \
                                                                            QuadDec_4_QUAD_MODE_SHIFT))
#define QuadDec_4_INV_OUT_MASK                   ((uint32)(QuadDec_4_2BIT_MASK        <<  \
                                                                            QuadDec_4_INV_OUT_SHIFT))
#define QuadDec_4_MODE_MASK                      ((uint32)(QuadDec_4_3BIT_MASK        <<  \
                                                                            QuadDec_4_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define QuadDec_4_CAPTURE_SHIFT                  (0u)
#define QuadDec_4_COUNT_SHIFT                    (2u)
#define QuadDec_4_RELOAD_SHIFT                   (4u)
#define QuadDec_4_STOP_SHIFT                     (6u)
#define QuadDec_4_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define QuadDec_4_CAPTURE_MASK                   ((uint32)(QuadDec_4_2BIT_MASK        <<  \
                                                                  QuadDec_4_CAPTURE_SHIFT))
#define QuadDec_4_COUNT_MASK                     ((uint32)(QuadDec_4_2BIT_MASK        <<  \
                                                                  QuadDec_4_COUNT_SHIFT))
#define QuadDec_4_RELOAD_MASK                    ((uint32)(QuadDec_4_2BIT_MASK        <<  \
                                                                  QuadDec_4_RELOAD_SHIFT))
#define QuadDec_4_STOP_MASK                      ((uint32)(QuadDec_4_2BIT_MASK        <<  \
                                                                  QuadDec_4_STOP_SHIFT))
#define QuadDec_4_START_MASK                     ((uint32)(QuadDec_4_2BIT_MASK        <<  \
                                                                  QuadDec_4_START_SHIFT))

/* MASK */
#define QuadDec_4_1BIT_MASK                      ((uint32)0x01u)
#define QuadDec_4_2BIT_MASK                      ((uint32)0x03u)
#define QuadDec_4_3BIT_MASK                      ((uint32)0x07u)
#define QuadDec_4_6BIT_MASK                      ((uint32)0x3Fu)
#define QuadDec_4_8BIT_MASK                      ((uint32)0xFFu)
#define QuadDec_4_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define QuadDec_4_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define QuadDec_4_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(QuadDec_4_QUAD_ENCODING_MODES     << QuadDec_4_QUAD_MODE_SHIFT))       |\
         ((uint32)(QuadDec_4_CONFIG                  << QuadDec_4_MODE_SHIFT)))

#define QuadDec_4_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(QuadDec_4_PWM_STOP_EVENT          << QuadDec_4_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(QuadDec_4_PWM_OUT_INVERT          << QuadDec_4_INV_OUT_SHIFT))         |\
         ((uint32)(QuadDec_4_PWM_OUT_N_INVERT        << QuadDec_4_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(QuadDec_4_PWM_MODE                << QuadDec_4_MODE_SHIFT)))

#define QuadDec_4_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(QuadDec_4_PWM_RUN_MODE         << QuadDec_4_ONESHOT_SHIFT))
            
#define QuadDec_4_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(QuadDec_4_PWM_ALIGN            << QuadDec_4_UPDOWN_SHIFT))

#define QuadDec_4_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(QuadDec_4_PWM_KILL_EVENT      << QuadDec_4_PWM_SYNC_KILL_SHIFT))

#define QuadDec_4_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(QuadDec_4_PWM_DEAD_TIME_CYCLE  << QuadDec_4_PRESCALER_SHIFT))

#define QuadDec_4_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(QuadDec_4_PWM_PRESCALER        << QuadDec_4_PRESCALER_SHIFT))

#define QuadDec_4_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(QuadDec_4_TC_PRESCALER            << QuadDec_4_PRESCALER_SHIFT))       |\
         ((uint32)(QuadDec_4_TC_COUNTER_MODE         << QuadDec_4_UPDOWN_SHIFT))          |\
         ((uint32)(QuadDec_4_TC_RUN_MODE             << QuadDec_4_ONESHOT_SHIFT))         |\
         ((uint32)(QuadDec_4_TC_COMP_CAP_MODE        << QuadDec_4_MODE_SHIFT)))
        
#define QuadDec_4_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(QuadDec_4_QUAD_PHIA_SIGNAL_MODE   << QuadDec_4_COUNT_SHIFT))           |\
         ((uint32)(QuadDec_4_QUAD_INDEX_SIGNAL_MODE  << QuadDec_4_RELOAD_SHIFT))          |\
         ((uint32)(QuadDec_4_QUAD_STOP_SIGNAL_MODE   << QuadDec_4_STOP_SHIFT))            |\
         ((uint32)(QuadDec_4_QUAD_PHIB_SIGNAL_MODE   << QuadDec_4_START_SHIFT)))

#define QuadDec_4_PWM_SIGNALS_MODES                                                              \
        (((uint32)(QuadDec_4_PWM_SWITCH_SIGNAL_MODE  << QuadDec_4_CAPTURE_SHIFT))         |\
         ((uint32)(QuadDec_4_PWM_COUNT_SIGNAL_MODE   << QuadDec_4_COUNT_SHIFT))           |\
         ((uint32)(QuadDec_4_PWM_RELOAD_SIGNAL_MODE  << QuadDec_4_RELOAD_SHIFT))          |\
         ((uint32)(QuadDec_4_PWM_STOP_SIGNAL_MODE    << QuadDec_4_STOP_SHIFT))            |\
         ((uint32)(QuadDec_4_PWM_START_SIGNAL_MODE   << QuadDec_4_START_SHIFT)))

#define QuadDec_4_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(QuadDec_4_TC_CAPTURE_SIGNAL_MODE  << QuadDec_4_CAPTURE_SHIFT))         |\
         ((uint32)(QuadDec_4_TC_COUNT_SIGNAL_MODE    << QuadDec_4_COUNT_SHIFT))           |\
         ((uint32)(QuadDec_4_TC_RELOAD_SIGNAL_MODE   << QuadDec_4_RELOAD_SHIFT))          |\
         ((uint32)(QuadDec_4_TC_STOP_SIGNAL_MODE     << QuadDec_4_STOP_SHIFT))            |\
         ((uint32)(QuadDec_4_TC_START_SIGNAL_MODE    << QuadDec_4_START_SHIFT)))
        
#define QuadDec_4_TIMER_UPDOWN_CNT_USED                                                          \
                ((QuadDec_4__COUNT_UPDOWN0 == QuadDec_4_TC_COUNTER_MODE)                  ||\
                 (QuadDec_4__COUNT_UPDOWN1 == QuadDec_4_TC_COUNTER_MODE))

#define QuadDec_4_PWM_UPDOWN_CNT_USED                                                            \
                ((QuadDec_4__CENTER == QuadDec_4_PWM_ALIGN)                               ||\
                 (QuadDec_4__ASYMMETRIC == QuadDec_4_PWM_ALIGN))               
        
#define QuadDec_4_PWM_PR_INIT_VALUE              (1u)
#define QuadDec_4_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_QuadDec_4_H */

/* [] END OF FILE */
