/*******************************************************************************
* File Name: QuadDec1.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the QuadDec1
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

#if !defined(CY_TCPWM_QuadDec1_H)
#define CY_TCPWM_QuadDec1_H


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
} QuadDec1_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  QuadDec1_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define QuadDec1_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define QuadDec1_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define QuadDec1_CONFIG                         (3lu)

/* Quad Mode */
/* Parameters */
#define QuadDec1_QUAD_ENCODING_MODES            (2lu)
#define QuadDec1_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define QuadDec1_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define QuadDec1_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define QuadDec1_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define QuadDec1_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define QuadDec1_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define QuadDec1_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define QuadDec1_QUAD_INTERRUPT_MASK            (0lu)

/* Timer/Counter Mode */
/* Parameters */
#define QuadDec1_TC_RUN_MODE                    (0lu)
#define QuadDec1_TC_COUNTER_MODE                (0lu)
#define QuadDec1_TC_COMP_CAP_MODE               (2lu)
#define QuadDec1_TC_PRESCALER                   (0lu)

/* Signal modes */
#define QuadDec1_TC_RELOAD_SIGNAL_MODE          (0lu)
#define QuadDec1_TC_COUNT_SIGNAL_MODE           (3lu)
#define QuadDec1_TC_START_SIGNAL_MODE           (0lu)
#define QuadDec1_TC_STOP_SIGNAL_MODE            (0lu)
#define QuadDec1_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define QuadDec1_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define QuadDec1_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define QuadDec1_TC_START_SIGNAL_PRESENT        (0lu)
#define QuadDec1_TC_STOP_SIGNAL_PRESENT         (0lu)
#define QuadDec1_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define QuadDec1_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define QuadDec1_PWM_KILL_EVENT                 (0lu)
#define QuadDec1_PWM_STOP_EVENT                 (0lu)
#define QuadDec1_PWM_MODE                       (4lu)
#define QuadDec1_PWM_OUT_N_INVERT               (0lu)
#define QuadDec1_PWM_OUT_INVERT                 (0lu)
#define QuadDec1_PWM_ALIGN                      (0lu)
#define QuadDec1_PWM_RUN_MODE                   (0lu)
#define QuadDec1_PWM_DEAD_TIME_CYCLE            (0lu)
#define QuadDec1_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define QuadDec1_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define QuadDec1_PWM_COUNT_SIGNAL_MODE          (3lu)
#define QuadDec1_PWM_START_SIGNAL_MODE          (0lu)
#define QuadDec1_PWM_STOP_SIGNAL_MODE           (0lu)
#define QuadDec1_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define QuadDec1_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define QuadDec1_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define QuadDec1_PWM_START_SIGNAL_PRESENT       (0lu)
#define QuadDec1_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define QuadDec1_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define QuadDec1_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define QuadDec1_TC_PERIOD_VALUE                (65535lu)
#define QuadDec1_TC_COMPARE_VALUE               (65535lu)
#define QuadDec1_TC_COMPARE_BUF_VALUE           (65535lu)
#define QuadDec1_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define QuadDec1_PWM_PERIOD_VALUE               (65535lu)
#define QuadDec1_PWM_PERIOD_BUF_VALUE           (65535lu)
#define QuadDec1_PWM_PERIOD_SWAP                (0lu)
#define QuadDec1_PWM_COMPARE_VALUE              (65535lu)
#define QuadDec1_PWM_COMPARE_BUF_VALUE          (65535lu)
#define QuadDec1_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define QuadDec1__LEFT 0
#define QuadDec1__RIGHT 1
#define QuadDec1__CENTER 2
#define QuadDec1__ASYMMETRIC 3

#define QuadDec1__X1 0
#define QuadDec1__X2 1
#define QuadDec1__X4 2

#define QuadDec1__PWM 4
#define QuadDec1__PWM_DT 5
#define QuadDec1__PWM_PR 6

#define QuadDec1__INVERSE 1
#define QuadDec1__DIRECT 0

#define QuadDec1__CAPTURE 2
#define QuadDec1__COMPARE 0

#define QuadDec1__TRIG_LEVEL 3
#define QuadDec1__TRIG_RISING 0
#define QuadDec1__TRIG_FALLING 1
#define QuadDec1__TRIG_BOTH 2

#define QuadDec1__INTR_MASK_TC 1
#define QuadDec1__INTR_MASK_CC_MATCH 2
#define QuadDec1__INTR_MASK_NONE 0
#define QuadDec1__INTR_MASK_TC_CC 3

#define QuadDec1__UNCONFIG 8
#define QuadDec1__TIMER 1
#define QuadDec1__QUAD 3
#define QuadDec1__PWM_SEL 7

#define QuadDec1__COUNT_UP 0
#define QuadDec1__COUNT_DOWN 1
#define QuadDec1__COUNT_UPDOWN0 2
#define QuadDec1__COUNT_UPDOWN1 3


/* Prescaler */
#define QuadDec1_PRESCALE_DIVBY1                ((uint32)(0u << QuadDec1_PRESCALER_SHIFT))
#define QuadDec1_PRESCALE_DIVBY2                ((uint32)(1u << QuadDec1_PRESCALER_SHIFT))
#define QuadDec1_PRESCALE_DIVBY4                ((uint32)(2u << QuadDec1_PRESCALER_SHIFT))
#define QuadDec1_PRESCALE_DIVBY8                ((uint32)(3u << QuadDec1_PRESCALER_SHIFT))
#define QuadDec1_PRESCALE_DIVBY16               ((uint32)(4u << QuadDec1_PRESCALER_SHIFT))
#define QuadDec1_PRESCALE_DIVBY32               ((uint32)(5u << QuadDec1_PRESCALER_SHIFT))
#define QuadDec1_PRESCALE_DIVBY64               ((uint32)(6u << QuadDec1_PRESCALER_SHIFT))
#define QuadDec1_PRESCALE_DIVBY128              ((uint32)(7u << QuadDec1_PRESCALER_SHIFT))

/* TCPWM set modes */
#define QuadDec1_MODE_TIMER_COMPARE             ((uint32)(QuadDec1__COMPARE         <<  \
                                                                  QuadDec1_MODE_SHIFT))
#define QuadDec1_MODE_TIMER_CAPTURE             ((uint32)(QuadDec1__CAPTURE         <<  \
                                                                  QuadDec1_MODE_SHIFT))
#define QuadDec1_MODE_QUAD                      ((uint32)(QuadDec1__QUAD            <<  \
                                                                  QuadDec1_MODE_SHIFT))
#define QuadDec1_MODE_PWM                       ((uint32)(QuadDec1__PWM             <<  \
                                                                  QuadDec1_MODE_SHIFT))
#define QuadDec1_MODE_PWM_DT                    ((uint32)(QuadDec1__PWM_DT          <<  \
                                                                  QuadDec1_MODE_SHIFT))
#define QuadDec1_MODE_PWM_PR                    ((uint32)(QuadDec1__PWM_PR          <<  \
                                                                  QuadDec1_MODE_SHIFT))

/* Quad Modes */
#define QuadDec1_MODE_X1                        ((uint32)(QuadDec1__X1              <<  \
                                                                  QuadDec1_QUAD_MODE_SHIFT))
#define QuadDec1_MODE_X2                        ((uint32)(QuadDec1__X2              <<  \
                                                                  QuadDec1_QUAD_MODE_SHIFT))
#define QuadDec1_MODE_X4                        ((uint32)(QuadDec1__X4              <<  \
                                                                  QuadDec1_QUAD_MODE_SHIFT))

/* Counter modes */
#define QuadDec1_COUNT_UP                       ((uint32)(QuadDec1__COUNT_UP        <<  \
                                                                  QuadDec1_UPDOWN_SHIFT))
#define QuadDec1_COUNT_DOWN                     ((uint32)(QuadDec1__COUNT_DOWN      <<  \
                                                                  QuadDec1_UPDOWN_SHIFT))
#define QuadDec1_COUNT_UPDOWN0                  ((uint32)(QuadDec1__COUNT_UPDOWN0   <<  \
                                                                  QuadDec1_UPDOWN_SHIFT))
#define QuadDec1_COUNT_UPDOWN1                  ((uint32)(QuadDec1__COUNT_UPDOWN1   <<  \
                                                                  QuadDec1_UPDOWN_SHIFT))

/* PWM output invert */
#define QuadDec1_INVERT_LINE                    ((uint32)(QuadDec1__INVERSE         <<  \
                                                                  QuadDec1_INV_OUT_SHIFT))
#define QuadDec1_INVERT_LINE_N                  ((uint32)(QuadDec1__INVERSE         <<  \
                                                                  QuadDec1_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define QuadDec1_TRIG_RISING                    ((uint32)QuadDec1__TRIG_RISING)
#define QuadDec1_TRIG_FALLING                   ((uint32)QuadDec1__TRIG_FALLING)
#define QuadDec1_TRIG_BOTH                      ((uint32)QuadDec1__TRIG_BOTH)
#define QuadDec1_TRIG_LEVEL                     ((uint32)QuadDec1__TRIG_LEVEL)

/* Interrupt mask */
#define QuadDec1_INTR_MASK_TC                   ((uint32)QuadDec1__INTR_MASK_TC)
#define QuadDec1_INTR_MASK_CC_MATCH             ((uint32)QuadDec1__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define QuadDec1_CC_MATCH_SET                   (0x00u)
#define QuadDec1_CC_MATCH_CLEAR                 (0x01u)
#define QuadDec1_CC_MATCH_INVERT                (0x02u)
#define QuadDec1_CC_MATCH_NO_CHANGE             (0x03u)
#define QuadDec1_OVERLOW_SET                    (0x00u)
#define QuadDec1_OVERLOW_CLEAR                  (0x04u)
#define QuadDec1_OVERLOW_INVERT                 (0x08u)
#define QuadDec1_OVERLOW_NO_CHANGE              (0x0Cu)
#define QuadDec1_UNDERFLOW_SET                  (0x00u)
#define QuadDec1_UNDERFLOW_CLEAR                (0x10u)
#define QuadDec1_UNDERFLOW_INVERT               (0x20u)
#define QuadDec1_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define QuadDec1_PWM_MODE_LEFT                  (QuadDec1_CC_MATCH_CLEAR        |   \
                                                         QuadDec1_OVERLOW_SET           |   \
                                                         QuadDec1_UNDERFLOW_NO_CHANGE)
#define QuadDec1_PWM_MODE_RIGHT                 (QuadDec1_CC_MATCH_SET          |   \
                                                         QuadDec1_OVERLOW_NO_CHANGE     |   \
                                                         QuadDec1_UNDERFLOW_CLEAR)
#define QuadDec1_PWM_MODE_ASYM                  (QuadDec1_CC_MATCH_INVERT       |   \
                                                         QuadDec1_OVERLOW_SET           |   \
                                                         QuadDec1_UNDERFLOW_CLEAR)

#if (QuadDec1_CY_TCPWM_V2)
    #if(QuadDec1_CY_TCPWM_4000)
        #define QuadDec1_PWM_MODE_CENTER                (QuadDec1_CC_MATCH_INVERT       |   \
                                                                 QuadDec1_OVERLOW_NO_CHANGE     |   \
                                                                 QuadDec1_UNDERFLOW_CLEAR)
    #else
        #define QuadDec1_PWM_MODE_CENTER                (QuadDec1_CC_MATCH_INVERT       |   \
                                                                 QuadDec1_OVERLOW_SET           |   \
                                                                 QuadDec1_UNDERFLOW_CLEAR)
    #endif /* (QuadDec1_CY_TCPWM_4000) */
#else
    #define QuadDec1_PWM_MODE_CENTER                (QuadDec1_CC_MATCH_INVERT       |   \
                                                             QuadDec1_OVERLOW_NO_CHANGE     |   \
                                                             QuadDec1_UNDERFLOW_CLEAR)
#endif /* (QuadDec1_CY_TCPWM_NEW) */

/* Command operations without condition */
#define QuadDec1_CMD_CAPTURE                    (0u)
#define QuadDec1_CMD_RELOAD                     (8u)
#define QuadDec1_CMD_STOP                       (16u)
#define QuadDec1_CMD_START                      (24u)

/* Status */
#define QuadDec1_STATUS_DOWN                    (1u)
#define QuadDec1_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   QuadDec1_Init(void);
void   QuadDec1_Enable(void);
void   QuadDec1_Start(void);
void   QuadDec1_Stop(void);

void   QuadDec1_SetMode(uint32 mode);
void   QuadDec1_SetCounterMode(uint32 counterMode);
void   QuadDec1_SetPWMMode(uint32 modeMask);
void   QuadDec1_SetQDMode(uint32 qdMode);

void   QuadDec1_SetPrescaler(uint32 prescaler);
void   QuadDec1_TriggerCommand(uint32 mask, uint32 command);
void   QuadDec1_SetOneShot(uint32 oneShotEnable);
uint32 QuadDec1_ReadStatus(void);

void   QuadDec1_SetPWMSyncKill(uint32 syncKillEnable);
void   QuadDec1_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   QuadDec1_SetPWMDeadTime(uint32 deadTime);
void   QuadDec1_SetPWMInvert(uint32 mask);

void   QuadDec1_SetInterruptMode(uint32 interruptMask);
uint32 QuadDec1_GetInterruptSourceMasked(void);
uint32 QuadDec1_GetInterruptSource(void);
void   QuadDec1_ClearInterrupt(uint32 interruptMask);
void   QuadDec1_SetInterrupt(uint32 interruptMask);

void   QuadDec1_WriteCounter(uint32 count);
uint32 QuadDec1_ReadCounter(void);

uint32 QuadDec1_ReadCapture(void);
uint32 QuadDec1_ReadCaptureBuf(void);

void   QuadDec1_WritePeriod(uint32 period);
uint32 QuadDec1_ReadPeriod(void);
void   QuadDec1_WritePeriodBuf(uint32 periodBuf);
uint32 QuadDec1_ReadPeriodBuf(void);

void   QuadDec1_WriteCompare(uint32 compare);
uint32 QuadDec1_ReadCompare(void);
void   QuadDec1_WriteCompareBuf(uint32 compareBuf);
uint32 QuadDec1_ReadCompareBuf(void);

void   QuadDec1_SetPeriodSwap(uint32 swapEnable);
void   QuadDec1_SetCompareSwap(uint32 swapEnable);

void   QuadDec1_SetCaptureMode(uint32 triggerMode);
void   QuadDec1_SetReloadMode(uint32 triggerMode);
void   QuadDec1_SetStartMode(uint32 triggerMode);
void   QuadDec1_SetStopMode(uint32 triggerMode);
void   QuadDec1_SetCountMode(uint32 triggerMode);

void   QuadDec1_SaveConfig(void);
void   QuadDec1_RestoreConfig(void);
void   QuadDec1_Sleep(void);
void   QuadDec1_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define QuadDec1_BLOCK_CONTROL_REG              (*(reg32 *) QuadDec1_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define QuadDec1_BLOCK_CONTROL_PTR              ( (reg32 *) QuadDec1_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define QuadDec1_COMMAND_REG                    (*(reg32 *) QuadDec1_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define QuadDec1_COMMAND_PTR                    ( (reg32 *) QuadDec1_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define QuadDec1_INTRRUPT_CAUSE_REG             (*(reg32 *) QuadDec1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define QuadDec1_INTRRUPT_CAUSE_PTR             ( (reg32 *) QuadDec1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define QuadDec1_CONTROL_REG                    (*(reg32 *) QuadDec1_cy_m0s8_tcpwm_1__CTRL )
#define QuadDec1_CONTROL_PTR                    ( (reg32 *) QuadDec1_cy_m0s8_tcpwm_1__CTRL )
#define QuadDec1_STATUS_REG                     (*(reg32 *) QuadDec1_cy_m0s8_tcpwm_1__STATUS )
#define QuadDec1_STATUS_PTR                     ( (reg32 *) QuadDec1_cy_m0s8_tcpwm_1__STATUS )
#define QuadDec1_COUNTER_REG                    (*(reg32 *) QuadDec1_cy_m0s8_tcpwm_1__COUNTER )
#define QuadDec1_COUNTER_PTR                    ( (reg32 *) QuadDec1_cy_m0s8_tcpwm_1__COUNTER )
#define QuadDec1_COMP_CAP_REG                   (*(reg32 *) QuadDec1_cy_m0s8_tcpwm_1__CC )
#define QuadDec1_COMP_CAP_PTR                   ( (reg32 *) QuadDec1_cy_m0s8_tcpwm_1__CC )
#define QuadDec1_COMP_CAP_BUF_REG               (*(reg32 *) QuadDec1_cy_m0s8_tcpwm_1__CC_BUFF )
#define QuadDec1_COMP_CAP_BUF_PTR               ( (reg32 *) QuadDec1_cy_m0s8_tcpwm_1__CC_BUFF )
#define QuadDec1_PERIOD_REG                     (*(reg32 *) QuadDec1_cy_m0s8_tcpwm_1__PERIOD )
#define QuadDec1_PERIOD_PTR                     ( (reg32 *) QuadDec1_cy_m0s8_tcpwm_1__PERIOD )
#define QuadDec1_PERIOD_BUF_REG                 (*(reg32 *) QuadDec1_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define QuadDec1_PERIOD_BUF_PTR                 ( (reg32 *) QuadDec1_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define QuadDec1_TRIG_CONTROL0_REG              (*(reg32 *) QuadDec1_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define QuadDec1_TRIG_CONTROL0_PTR              ( (reg32 *) QuadDec1_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define QuadDec1_TRIG_CONTROL1_REG              (*(reg32 *) QuadDec1_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define QuadDec1_TRIG_CONTROL1_PTR              ( (reg32 *) QuadDec1_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define QuadDec1_TRIG_CONTROL2_REG              (*(reg32 *) QuadDec1_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define QuadDec1_TRIG_CONTROL2_PTR              ( (reg32 *) QuadDec1_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define QuadDec1_INTERRUPT_REQ_REG              (*(reg32 *) QuadDec1_cy_m0s8_tcpwm_1__INTR )
#define QuadDec1_INTERRUPT_REQ_PTR              ( (reg32 *) QuadDec1_cy_m0s8_tcpwm_1__INTR )
#define QuadDec1_INTERRUPT_SET_REG              (*(reg32 *) QuadDec1_cy_m0s8_tcpwm_1__INTR_SET )
#define QuadDec1_INTERRUPT_SET_PTR              ( (reg32 *) QuadDec1_cy_m0s8_tcpwm_1__INTR_SET )
#define QuadDec1_INTERRUPT_MASK_REG             (*(reg32 *) QuadDec1_cy_m0s8_tcpwm_1__INTR_MASK )
#define QuadDec1_INTERRUPT_MASK_PTR             ( (reg32 *) QuadDec1_cy_m0s8_tcpwm_1__INTR_MASK )
#define QuadDec1_INTERRUPT_MASKED_REG           (*(reg32 *) QuadDec1_cy_m0s8_tcpwm_1__INTR_MASKED )
#define QuadDec1_INTERRUPT_MASKED_PTR           ( (reg32 *) QuadDec1_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define QuadDec1_MASK                           ((uint32)QuadDec1_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define QuadDec1_RELOAD_CC_SHIFT                (0u)
#define QuadDec1_RELOAD_PERIOD_SHIFT            (1u)
#define QuadDec1_PWM_SYNC_KILL_SHIFT            (2u)
#define QuadDec1_PWM_STOP_KILL_SHIFT            (3u)
#define QuadDec1_PRESCALER_SHIFT                (8u)
#define QuadDec1_UPDOWN_SHIFT                   (16u)
#define QuadDec1_ONESHOT_SHIFT                  (18u)
#define QuadDec1_QUAD_MODE_SHIFT                (20u)
#define QuadDec1_INV_OUT_SHIFT                  (20u)
#define QuadDec1_INV_COMPL_OUT_SHIFT            (21u)
#define QuadDec1_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define QuadDec1_RELOAD_CC_MASK                 ((uint32)(QuadDec1_1BIT_MASK        <<  \
                                                                            QuadDec1_RELOAD_CC_SHIFT))
#define QuadDec1_RELOAD_PERIOD_MASK             ((uint32)(QuadDec1_1BIT_MASK        <<  \
                                                                            QuadDec1_RELOAD_PERIOD_SHIFT))
#define QuadDec1_PWM_SYNC_KILL_MASK             ((uint32)(QuadDec1_1BIT_MASK        <<  \
                                                                            QuadDec1_PWM_SYNC_KILL_SHIFT))
#define QuadDec1_PWM_STOP_KILL_MASK             ((uint32)(QuadDec1_1BIT_MASK        <<  \
                                                                            QuadDec1_PWM_STOP_KILL_SHIFT))
#define QuadDec1_PRESCALER_MASK                 ((uint32)(QuadDec1_8BIT_MASK        <<  \
                                                                            QuadDec1_PRESCALER_SHIFT))
#define QuadDec1_UPDOWN_MASK                    ((uint32)(QuadDec1_2BIT_MASK        <<  \
                                                                            QuadDec1_UPDOWN_SHIFT))
#define QuadDec1_ONESHOT_MASK                   ((uint32)(QuadDec1_1BIT_MASK        <<  \
                                                                            QuadDec1_ONESHOT_SHIFT))
#define QuadDec1_QUAD_MODE_MASK                 ((uint32)(QuadDec1_3BIT_MASK        <<  \
                                                                            QuadDec1_QUAD_MODE_SHIFT))
#define QuadDec1_INV_OUT_MASK                   ((uint32)(QuadDec1_2BIT_MASK        <<  \
                                                                            QuadDec1_INV_OUT_SHIFT))
#define QuadDec1_MODE_MASK                      ((uint32)(QuadDec1_3BIT_MASK        <<  \
                                                                            QuadDec1_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define QuadDec1_CAPTURE_SHIFT                  (0u)
#define QuadDec1_COUNT_SHIFT                    (2u)
#define QuadDec1_RELOAD_SHIFT                   (4u)
#define QuadDec1_STOP_SHIFT                     (6u)
#define QuadDec1_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define QuadDec1_CAPTURE_MASK                   ((uint32)(QuadDec1_2BIT_MASK        <<  \
                                                                  QuadDec1_CAPTURE_SHIFT))
#define QuadDec1_COUNT_MASK                     ((uint32)(QuadDec1_2BIT_MASK        <<  \
                                                                  QuadDec1_COUNT_SHIFT))
#define QuadDec1_RELOAD_MASK                    ((uint32)(QuadDec1_2BIT_MASK        <<  \
                                                                  QuadDec1_RELOAD_SHIFT))
#define QuadDec1_STOP_MASK                      ((uint32)(QuadDec1_2BIT_MASK        <<  \
                                                                  QuadDec1_STOP_SHIFT))
#define QuadDec1_START_MASK                     ((uint32)(QuadDec1_2BIT_MASK        <<  \
                                                                  QuadDec1_START_SHIFT))

/* MASK */
#define QuadDec1_1BIT_MASK                      ((uint32)0x01u)
#define QuadDec1_2BIT_MASK                      ((uint32)0x03u)
#define QuadDec1_3BIT_MASK                      ((uint32)0x07u)
#define QuadDec1_6BIT_MASK                      ((uint32)0x3Fu)
#define QuadDec1_8BIT_MASK                      ((uint32)0xFFu)
#define QuadDec1_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define QuadDec1_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define QuadDec1_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(QuadDec1_QUAD_ENCODING_MODES     << QuadDec1_QUAD_MODE_SHIFT))       |\
         ((uint32)(QuadDec1_CONFIG                  << QuadDec1_MODE_SHIFT)))

#define QuadDec1_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(QuadDec1_PWM_STOP_EVENT          << QuadDec1_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(QuadDec1_PWM_OUT_INVERT          << QuadDec1_INV_OUT_SHIFT))         |\
         ((uint32)(QuadDec1_PWM_OUT_N_INVERT        << QuadDec1_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(QuadDec1_PWM_MODE                << QuadDec1_MODE_SHIFT)))

#define QuadDec1_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(QuadDec1_PWM_RUN_MODE         << QuadDec1_ONESHOT_SHIFT))
            
#define QuadDec1_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(QuadDec1_PWM_ALIGN            << QuadDec1_UPDOWN_SHIFT))

#define QuadDec1_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(QuadDec1_PWM_KILL_EVENT      << QuadDec1_PWM_SYNC_KILL_SHIFT))

#define QuadDec1_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(QuadDec1_PWM_DEAD_TIME_CYCLE  << QuadDec1_PRESCALER_SHIFT))

#define QuadDec1_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(QuadDec1_PWM_PRESCALER        << QuadDec1_PRESCALER_SHIFT))

#define QuadDec1_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(QuadDec1_TC_PRESCALER            << QuadDec1_PRESCALER_SHIFT))       |\
         ((uint32)(QuadDec1_TC_COUNTER_MODE         << QuadDec1_UPDOWN_SHIFT))          |\
         ((uint32)(QuadDec1_TC_RUN_MODE             << QuadDec1_ONESHOT_SHIFT))         |\
         ((uint32)(QuadDec1_TC_COMP_CAP_MODE        << QuadDec1_MODE_SHIFT)))
        
#define QuadDec1_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(QuadDec1_QUAD_PHIA_SIGNAL_MODE   << QuadDec1_COUNT_SHIFT))           |\
         ((uint32)(QuadDec1_QUAD_INDEX_SIGNAL_MODE  << QuadDec1_RELOAD_SHIFT))          |\
         ((uint32)(QuadDec1_QUAD_STOP_SIGNAL_MODE   << QuadDec1_STOP_SHIFT))            |\
         ((uint32)(QuadDec1_QUAD_PHIB_SIGNAL_MODE   << QuadDec1_START_SHIFT)))

#define QuadDec1_PWM_SIGNALS_MODES                                                              \
        (((uint32)(QuadDec1_PWM_SWITCH_SIGNAL_MODE  << QuadDec1_CAPTURE_SHIFT))         |\
         ((uint32)(QuadDec1_PWM_COUNT_SIGNAL_MODE   << QuadDec1_COUNT_SHIFT))           |\
         ((uint32)(QuadDec1_PWM_RELOAD_SIGNAL_MODE  << QuadDec1_RELOAD_SHIFT))          |\
         ((uint32)(QuadDec1_PWM_STOP_SIGNAL_MODE    << QuadDec1_STOP_SHIFT))            |\
         ((uint32)(QuadDec1_PWM_START_SIGNAL_MODE   << QuadDec1_START_SHIFT)))

#define QuadDec1_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(QuadDec1_TC_CAPTURE_SIGNAL_MODE  << QuadDec1_CAPTURE_SHIFT))         |\
         ((uint32)(QuadDec1_TC_COUNT_SIGNAL_MODE    << QuadDec1_COUNT_SHIFT))           |\
         ((uint32)(QuadDec1_TC_RELOAD_SIGNAL_MODE   << QuadDec1_RELOAD_SHIFT))          |\
         ((uint32)(QuadDec1_TC_STOP_SIGNAL_MODE     << QuadDec1_STOP_SHIFT))            |\
         ((uint32)(QuadDec1_TC_START_SIGNAL_MODE    << QuadDec1_START_SHIFT)))
        
#define QuadDec1_TIMER_UPDOWN_CNT_USED                                                          \
                ((QuadDec1__COUNT_UPDOWN0 == QuadDec1_TC_COUNTER_MODE)                  ||\
                 (QuadDec1__COUNT_UPDOWN1 == QuadDec1_TC_COUNTER_MODE))

#define QuadDec1_PWM_UPDOWN_CNT_USED                                                            \
                ((QuadDec1__CENTER == QuadDec1_PWM_ALIGN)                               ||\
                 (QuadDec1__ASYMMETRIC == QuadDec1_PWM_ALIGN))               
        
#define QuadDec1_PWM_PR_INIT_VALUE              (1u)
#define QuadDec1_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_QuadDec1_H */

/* [] END OF FILE */
