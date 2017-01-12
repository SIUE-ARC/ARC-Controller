/*******************************************************************************
* File Name: QuadDec3.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the QuadDec3
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

#if !defined(CY_TCPWM_QuadDec3_H)
#define CY_TCPWM_QuadDec3_H


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
} QuadDec3_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  QuadDec3_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define QuadDec3_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define QuadDec3_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define QuadDec3_CONFIG                         (3lu)

/* Quad Mode */
/* Parameters */
#define QuadDec3_QUAD_ENCODING_MODES            (2lu)
#define QuadDec3_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define QuadDec3_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define QuadDec3_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define QuadDec3_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define QuadDec3_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define QuadDec3_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define QuadDec3_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define QuadDec3_QUAD_INTERRUPT_MASK            (0lu)

/* Timer/Counter Mode */
/* Parameters */
#define QuadDec3_TC_RUN_MODE                    (0lu)
#define QuadDec3_TC_COUNTER_MODE                (0lu)
#define QuadDec3_TC_COMP_CAP_MODE               (2lu)
#define QuadDec3_TC_PRESCALER                   (0lu)

/* Signal modes */
#define QuadDec3_TC_RELOAD_SIGNAL_MODE          (0lu)
#define QuadDec3_TC_COUNT_SIGNAL_MODE           (3lu)
#define QuadDec3_TC_START_SIGNAL_MODE           (0lu)
#define QuadDec3_TC_STOP_SIGNAL_MODE            (0lu)
#define QuadDec3_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define QuadDec3_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define QuadDec3_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define QuadDec3_TC_START_SIGNAL_PRESENT        (0lu)
#define QuadDec3_TC_STOP_SIGNAL_PRESENT         (0lu)
#define QuadDec3_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define QuadDec3_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define QuadDec3_PWM_KILL_EVENT                 (0lu)
#define QuadDec3_PWM_STOP_EVENT                 (0lu)
#define QuadDec3_PWM_MODE                       (4lu)
#define QuadDec3_PWM_OUT_N_INVERT               (0lu)
#define QuadDec3_PWM_OUT_INVERT                 (0lu)
#define QuadDec3_PWM_ALIGN                      (0lu)
#define QuadDec3_PWM_RUN_MODE                   (0lu)
#define QuadDec3_PWM_DEAD_TIME_CYCLE            (0lu)
#define QuadDec3_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define QuadDec3_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define QuadDec3_PWM_COUNT_SIGNAL_MODE          (3lu)
#define QuadDec3_PWM_START_SIGNAL_MODE          (0lu)
#define QuadDec3_PWM_STOP_SIGNAL_MODE           (0lu)
#define QuadDec3_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define QuadDec3_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define QuadDec3_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define QuadDec3_PWM_START_SIGNAL_PRESENT       (0lu)
#define QuadDec3_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define QuadDec3_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define QuadDec3_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define QuadDec3_TC_PERIOD_VALUE                (65535lu)
#define QuadDec3_TC_COMPARE_VALUE               (65535lu)
#define QuadDec3_TC_COMPARE_BUF_VALUE           (65535lu)
#define QuadDec3_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define QuadDec3_PWM_PERIOD_VALUE               (65535lu)
#define QuadDec3_PWM_PERIOD_BUF_VALUE           (65535lu)
#define QuadDec3_PWM_PERIOD_SWAP                (0lu)
#define QuadDec3_PWM_COMPARE_VALUE              (65535lu)
#define QuadDec3_PWM_COMPARE_BUF_VALUE          (65535lu)
#define QuadDec3_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define QuadDec3__LEFT 0
#define QuadDec3__RIGHT 1
#define QuadDec3__CENTER 2
#define QuadDec3__ASYMMETRIC 3

#define QuadDec3__X1 0
#define QuadDec3__X2 1
#define QuadDec3__X4 2

#define QuadDec3__PWM 4
#define QuadDec3__PWM_DT 5
#define QuadDec3__PWM_PR 6

#define QuadDec3__INVERSE 1
#define QuadDec3__DIRECT 0

#define QuadDec3__CAPTURE 2
#define QuadDec3__COMPARE 0

#define QuadDec3__TRIG_LEVEL 3
#define QuadDec3__TRIG_RISING 0
#define QuadDec3__TRIG_FALLING 1
#define QuadDec3__TRIG_BOTH 2

#define QuadDec3__INTR_MASK_TC 1
#define QuadDec3__INTR_MASK_CC_MATCH 2
#define QuadDec3__INTR_MASK_NONE 0
#define QuadDec3__INTR_MASK_TC_CC 3

#define QuadDec3__UNCONFIG 8
#define QuadDec3__TIMER 1
#define QuadDec3__QUAD 3
#define QuadDec3__PWM_SEL 7

#define QuadDec3__COUNT_UP 0
#define QuadDec3__COUNT_DOWN 1
#define QuadDec3__COUNT_UPDOWN0 2
#define QuadDec3__COUNT_UPDOWN1 3


/* Prescaler */
#define QuadDec3_PRESCALE_DIVBY1                ((uint32)(0u << QuadDec3_PRESCALER_SHIFT))
#define QuadDec3_PRESCALE_DIVBY2                ((uint32)(1u << QuadDec3_PRESCALER_SHIFT))
#define QuadDec3_PRESCALE_DIVBY4                ((uint32)(2u << QuadDec3_PRESCALER_SHIFT))
#define QuadDec3_PRESCALE_DIVBY8                ((uint32)(3u << QuadDec3_PRESCALER_SHIFT))
#define QuadDec3_PRESCALE_DIVBY16               ((uint32)(4u << QuadDec3_PRESCALER_SHIFT))
#define QuadDec3_PRESCALE_DIVBY32               ((uint32)(5u << QuadDec3_PRESCALER_SHIFT))
#define QuadDec3_PRESCALE_DIVBY64               ((uint32)(6u << QuadDec3_PRESCALER_SHIFT))
#define QuadDec3_PRESCALE_DIVBY128              ((uint32)(7u << QuadDec3_PRESCALER_SHIFT))

/* TCPWM set modes */
#define QuadDec3_MODE_TIMER_COMPARE             ((uint32)(QuadDec3__COMPARE         <<  \
                                                                  QuadDec3_MODE_SHIFT))
#define QuadDec3_MODE_TIMER_CAPTURE             ((uint32)(QuadDec3__CAPTURE         <<  \
                                                                  QuadDec3_MODE_SHIFT))
#define QuadDec3_MODE_QUAD                      ((uint32)(QuadDec3__QUAD            <<  \
                                                                  QuadDec3_MODE_SHIFT))
#define QuadDec3_MODE_PWM                       ((uint32)(QuadDec3__PWM             <<  \
                                                                  QuadDec3_MODE_SHIFT))
#define QuadDec3_MODE_PWM_DT                    ((uint32)(QuadDec3__PWM_DT          <<  \
                                                                  QuadDec3_MODE_SHIFT))
#define QuadDec3_MODE_PWM_PR                    ((uint32)(QuadDec3__PWM_PR          <<  \
                                                                  QuadDec3_MODE_SHIFT))

/* Quad Modes */
#define QuadDec3_MODE_X1                        ((uint32)(QuadDec3__X1              <<  \
                                                                  QuadDec3_QUAD_MODE_SHIFT))
#define QuadDec3_MODE_X2                        ((uint32)(QuadDec3__X2              <<  \
                                                                  QuadDec3_QUAD_MODE_SHIFT))
#define QuadDec3_MODE_X4                        ((uint32)(QuadDec3__X4              <<  \
                                                                  QuadDec3_QUAD_MODE_SHIFT))

/* Counter modes */
#define QuadDec3_COUNT_UP                       ((uint32)(QuadDec3__COUNT_UP        <<  \
                                                                  QuadDec3_UPDOWN_SHIFT))
#define QuadDec3_COUNT_DOWN                     ((uint32)(QuadDec3__COUNT_DOWN      <<  \
                                                                  QuadDec3_UPDOWN_SHIFT))
#define QuadDec3_COUNT_UPDOWN0                  ((uint32)(QuadDec3__COUNT_UPDOWN0   <<  \
                                                                  QuadDec3_UPDOWN_SHIFT))
#define QuadDec3_COUNT_UPDOWN1                  ((uint32)(QuadDec3__COUNT_UPDOWN1   <<  \
                                                                  QuadDec3_UPDOWN_SHIFT))

/* PWM output invert */
#define QuadDec3_INVERT_LINE                    ((uint32)(QuadDec3__INVERSE         <<  \
                                                                  QuadDec3_INV_OUT_SHIFT))
#define QuadDec3_INVERT_LINE_N                  ((uint32)(QuadDec3__INVERSE         <<  \
                                                                  QuadDec3_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define QuadDec3_TRIG_RISING                    ((uint32)QuadDec3__TRIG_RISING)
#define QuadDec3_TRIG_FALLING                   ((uint32)QuadDec3__TRIG_FALLING)
#define QuadDec3_TRIG_BOTH                      ((uint32)QuadDec3__TRIG_BOTH)
#define QuadDec3_TRIG_LEVEL                     ((uint32)QuadDec3__TRIG_LEVEL)

/* Interrupt mask */
#define QuadDec3_INTR_MASK_TC                   ((uint32)QuadDec3__INTR_MASK_TC)
#define QuadDec3_INTR_MASK_CC_MATCH             ((uint32)QuadDec3__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define QuadDec3_CC_MATCH_SET                   (0x00u)
#define QuadDec3_CC_MATCH_CLEAR                 (0x01u)
#define QuadDec3_CC_MATCH_INVERT                (0x02u)
#define QuadDec3_CC_MATCH_NO_CHANGE             (0x03u)
#define QuadDec3_OVERLOW_SET                    (0x00u)
#define QuadDec3_OVERLOW_CLEAR                  (0x04u)
#define QuadDec3_OVERLOW_INVERT                 (0x08u)
#define QuadDec3_OVERLOW_NO_CHANGE              (0x0Cu)
#define QuadDec3_UNDERFLOW_SET                  (0x00u)
#define QuadDec3_UNDERFLOW_CLEAR                (0x10u)
#define QuadDec3_UNDERFLOW_INVERT               (0x20u)
#define QuadDec3_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define QuadDec3_PWM_MODE_LEFT                  (QuadDec3_CC_MATCH_CLEAR        |   \
                                                         QuadDec3_OVERLOW_SET           |   \
                                                         QuadDec3_UNDERFLOW_NO_CHANGE)
#define QuadDec3_PWM_MODE_RIGHT                 (QuadDec3_CC_MATCH_SET          |   \
                                                         QuadDec3_OVERLOW_NO_CHANGE     |   \
                                                         QuadDec3_UNDERFLOW_CLEAR)
#define QuadDec3_PWM_MODE_ASYM                  (QuadDec3_CC_MATCH_INVERT       |   \
                                                         QuadDec3_OVERLOW_SET           |   \
                                                         QuadDec3_UNDERFLOW_CLEAR)

#if (QuadDec3_CY_TCPWM_V2)
    #if(QuadDec3_CY_TCPWM_4000)
        #define QuadDec3_PWM_MODE_CENTER                (QuadDec3_CC_MATCH_INVERT       |   \
                                                                 QuadDec3_OVERLOW_NO_CHANGE     |   \
                                                                 QuadDec3_UNDERFLOW_CLEAR)
    #else
        #define QuadDec3_PWM_MODE_CENTER                (QuadDec3_CC_MATCH_INVERT       |   \
                                                                 QuadDec3_OVERLOW_SET           |   \
                                                                 QuadDec3_UNDERFLOW_CLEAR)
    #endif /* (QuadDec3_CY_TCPWM_4000) */
#else
    #define QuadDec3_PWM_MODE_CENTER                (QuadDec3_CC_MATCH_INVERT       |   \
                                                             QuadDec3_OVERLOW_NO_CHANGE     |   \
                                                             QuadDec3_UNDERFLOW_CLEAR)
#endif /* (QuadDec3_CY_TCPWM_NEW) */

/* Command operations without condition */
#define QuadDec3_CMD_CAPTURE                    (0u)
#define QuadDec3_CMD_RELOAD                     (8u)
#define QuadDec3_CMD_STOP                       (16u)
#define QuadDec3_CMD_START                      (24u)

/* Status */
#define QuadDec3_STATUS_DOWN                    (1u)
#define QuadDec3_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   QuadDec3_Init(void);
void   QuadDec3_Enable(void);
void   QuadDec3_Start(void);
void   QuadDec3_Stop(void);

void   QuadDec3_SetMode(uint32 mode);
void   QuadDec3_SetCounterMode(uint32 counterMode);
void   QuadDec3_SetPWMMode(uint32 modeMask);
void   QuadDec3_SetQDMode(uint32 qdMode);

void   QuadDec3_SetPrescaler(uint32 prescaler);
void   QuadDec3_TriggerCommand(uint32 mask, uint32 command);
void   QuadDec3_SetOneShot(uint32 oneShotEnable);
uint32 QuadDec3_ReadStatus(void);

void   QuadDec3_SetPWMSyncKill(uint32 syncKillEnable);
void   QuadDec3_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   QuadDec3_SetPWMDeadTime(uint32 deadTime);
void   QuadDec3_SetPWMInvert(uint32 mask);

void   QuadDec3_SetInterruptMode(uint32 interruptMask);
uint32 QuadDec3_GetInterruptSourceMasked(void);
uint32 QuadDec3_GetInterruptSource(void);
void   QuadDec3_ClearInterrupt(uint32 interruptMask);
void   QuadDec3_SetInterrupt(uint32 interruptMask);

void   QuadDec3_WriteCounter(uint32 count);
uint32 QuadDec3_ReadCounter(void);

uint32 QuadDec3_ReadCapture(void);
uint32 QuadDec3_ReadCaptureBuf(void);

void   QuadDec3_WritePeriod(uint32 period);
uint32 QuadDec3_ReadPeriod(void);
void   QuadDec3_WritePeriodBuf(uint32 periodBuf);
uint32 QuadDec3_ReadPeriodBuf(void);

void   QuadDec3_WriteCompare(uint32 compare);
uint32 QuadDec3_ReadCompare(void);
void   QuadDec3_WriteCompareBuf(uint32 compareBuf);
uint32 QuadDec3_ReadCompareBuf(void);

void   QuadDec3_SetPeriodSwap(uint32 swapEnable);
void   QuadDec3_SetCompareSwap(uint32 swapEnable);

void   QuadDec3_SetCaptureMode(uint32 triggerMode);
void   QuadDec3_SetReloadMode(uint32 triggerMode);
void   QuadDec3_SetStartMode(uint32 triggerMode);
void   QuadDec3_SetStopMode(uint32 triggerMode);
void   QuadDec3_SetCountMode(uint32 triggerMode);

void   QuadDec3_SaveConfig(void);
void   QuadDec3_RestoreConfig(void);
void   QuadDec3_Sleep(void);
void   QuadDec3_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define QuadDec3_BLOCK_CONTROL_REG              (*(reg32 *) QuadDec3_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define QuadDec3_BLOCK_CONTROL_PTR              ( (reg32 *) QuadDec3_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define QuadDec3_COMMAND_REG                    (*(reg32 *) QuadDec3_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define QuadDec3_COMMAND_PTR                    ( (reg32 *) QuadDec3_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define QuadDec3_INTRRUPT_CAUSE_REG             (*(reg32 *) QuadDec3_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define QuadDec3_INTRRUPT_CAUSE_PTR             ( (reg32 *) QuadDec3_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define QuadDec3_CONTROL_REG                    (*(reg32 *) QuadDec3_cy_m0s8_tcpwm_1__CTRL )
#define QuadDec3_CONTROL_PTR                    ( (reg32 *) QuadDec3_cy_m0s8_tcpwm_1__CTRL )
#define QuadDec3_STATUS_REG                     (*(reg32 *) QuadDec3_cy_m0s8_tcpwm_1__STATUS )
#define QuadDec3_STATUS_PTR                     ( (reg32 *) QuadDec3_cy_m0s8_tcpwm_1__STATUS )
#define QuadDec3_COUNTER_REG                    (*(reg32 *) QuadDec3_cy_m0s8_tcpwm_1__COUNTER )
#define QuadDec3_COUNTER_PTR                    ( (reg32 *) QuadDec3_cy_m0s8_tcpwm_1__COUNTER )
#define QuadDec3_COMP_CAP_REG                   (*(reg32 *) QuadDec3_cy_m0s8_tcpwm_1__CC )
#define QuadDec3_COMP_CAP_PTR                   ( (reg32 *) QuadDec3_cy_m0s8_tcpwm_1__CC )
#define QuadDec3_COMP_CAP_BUF_REG               (*(reg32 *) QuadDec3_cy_m0s8_tcpwm_1__CC_BUFF )
#define QuadDec3_COMP_CAP_BUF_PTR               ( (reg32 *) QuadDec3_cy_m0s8_tcpwm_1__CC_BUFF )
#define QuadDec3_PERIOD_REG                     (*(reg32 *) QuadDec3_cy_m0s8_tcpwm_1__PERIOD )
#define QuadDec3_PERIOD_PTR                     ( (reg32 *) QuadDec3_cy_m0s8_tcpwm_1__PERIOD )
#define QuadDec3_PERIOD_BUF_REG                 (*(reg32 *) QuadDec3_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define QuadDec3_PERIOD_BUF_PTR                 ( (reg32 *) QuadDec3_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define QuadDec3_TRIG_CONTROL0_REG              (*(reg32 *) QuadDec3_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define QuadDec3_TRIG_CONTROL0_PTR              ( (reg32 *) QuadDec3_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define QuadDec3_TRIG_CONTROL1_REG              (*(reg32 *) QuadDec3_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define QuadDec3_TRIG_CONTROL1_PTR              ( (reg32 *) QuadDec3_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define QuadDec3_TRIG_CONTROL2_REG              (*(reg32 *) QuadDec3_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define QuadDec3_TRIG_CONTROL2_PTR              ( (reg32 *) QuadDec3_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define QuadDec3_INTERRUPT_REQ_REG              (*(reg32 *) QuadDec3_cy_m0s8_tcpwm_1__INTR )
#define QuadDec3_INTERRUPT_REQ_PTR              ( (reg32 *) QuadDec3_cy_m0s8_tcpwm_1__INTR )
#define QuadDec3_INTERRUPT_SET_REG              (*(reg32 *) QuadDec3_cy_m0s8_tcpwm_1__INTR_SET )
#define QuadDec3_INTERRUPT_SET_PTR              ( (reg32 *) QuadDec3_cy_m0s8_tcpwm_1__INTR_SET )
#define QuadDec3_INTERRUPT_MASK_REG             (*(reg32 *) QuadDec3_cy_m0s8_tcpwm_1__INTR_MASK )
#define QuadDec3_INTERRUPT_MASK_PTR             ( (reg32 *) QuadDec3_cy_m0s8_tcpwm_1__INTR_MASK )
#define QuadDec3_INTERRUPT_MASKED_REG           (*(reg32 *) QuadDec3_cy_m0s8_tcpwm_1__INTR_MASKED )
#define QuadDec3_INTERRUPT_MASKED_PTR           ( (reg32 *) QuadDec3_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define QuadDec3_MASK                           ((uint32)QuadDec3_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define QuadDec3_RELOAD_CC_SHIFT                (0u)
#define QuadDec3_RELOAD_PERIOD_SHIFT            (1u)
#define QuadDec3_PWM_SYNC_KILL_SHIFT            (2u)
#define QuadDec3_PWM_STOP_KILL_SHIFT            (3u)
#define QuadDec3_PRESCALER_SHIFT                (8u)
#define QuadDec3_UPDOWN_SHIFT                   (16u)
#define QuadDec3_ONESHOT_SHIFT                  (18u)
#define QuadDec3_QUAD_MODE_SHIFT                (20u)
#define QuadDec3_INV_OUT_SHIFT                  (20u)
#define QuadDec3_INV_COMPL_OUT_SHIFT            (21u)
#define QuadDec3_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define QuadDec3_RELOAD_CC_MASK                 ((uint32)(QuadDec3_1BIT_MASK        <<  \
                                                                            QuadDec3_RELOAD_CC_SHIFT))
#define QuadDec3_RELOAD_PERIOD_MASK             ((uint32)(QuadDec3_1BIT_MASK        <<  \
                                                                            QuadDec3_RELOAD_PERIOD_SHIFT))
#define QuadDec3_PWM_SYNC_KILL_MASK             ((uint32)(QuadDec3_1BIT_MASK        <<  \
                                                                            QuadDec3_PWM_SYNC_KILL_SHIFT))
#define QuadDec3_PWM_STOP_KILL_MASK             ((uint32)(QuadDec3_1BIT_MASK        <<  \
                                                                            QuadDec3_PWM_STOP_KILL_SHIFT))
#define QuadDec3_PRESCALER_MASK                 ((uint32)(QuadDec3_8BIT_MASK        <<  \
                                                                            QuadDec3_PRESCALER_SHIFT))
#define QuadDec3_UPDOWN_MASK                    ((uint32)(QuadDec3_2BIT_MASK        <<  \
                                                                            QuadDec3_UPDOWN_SHIFT))
#define QuadDec3_ONESHOT_MASK                   ((uint32)(QuadDec3_1BIT_MASK        <<  \
                                                                            QuadDec3_ONESHOT_SHIFT))
#define QuadDec3_QUAD_MODE_MASK                 ((uint32)(QuadDec3_3BIT_MASK        <<  \
                                                                            QuadDec3_QUAD_MODE_SHIFT))
#define QuadDec3_INV_OUT_MASK                   ((uint32)(QuadDec3_2BIT_MASK        <<  \
                                                                            QuadDec3_INV_OUT_SHIFT))
#define QuadDec3_MODE_MASK                      ((uint32)(QuadDec3_3BIT_MASK        <<  \
                                                                            QuadDec3_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define QuadDec3_CAPTURE_SHIFT                  (0u)
#define QuadDec3_COUNT_SHIFT                    (2u)
#define QuadDec3_RELOAD_SHIFT                   (4u)
#define QuadDec3_STOP_SHIFT                     (6u)
#define QuadDec3_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define QuadDec3_CAPTURE_MASK                   ((uint32)(QuadDec3_2BIT_MASK        <<  \
                                                                  QuadDec3_CAPTURE_SHIFT))
#define QuadDec3_COUNT_MASK                     ((uint32)(QuadDec3_2BIT_MASK        <<  \
                                                                  QuadDec3_COUNT_SHIFT))
#define QuadDec3_RELOAD_MASK                    ((uint32)(QuadDec3_2BIT_MASK        <<  \
                                                                  QuadDec3_RELOAD_SHIFT))
#define QuadDec3_STOP_MASK                      ((uint32)(QuadDec3_2BIT_MASK        <<  \
                                                                  QuadDec3_STOP_SHIFT))
#define QuadDec3_START_MASK                     ((uint32)(QuadDec3_2BIT_MASK        <<  \
                                                                  QuadDec3_START_SHIFT))

/* MASK */
#define QuadDec3_1BIT_MASK                      ((uint32)0x01u)
#define QuadDec3_2BIT_MASK                      ((uint32)0x03u)
#define QuadDec3_3BIT_MASK                      ((uint32)0x07u)
#define QuadDec3_6BIT_MASK                      ((uint32)0x3Fu)
#define QuadDec3_8BIT_MASK                      ((uint32)0xFFu)
#define QuadDec3_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define QuadDec3_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define QuadDec3_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(QuadDec3_QUAD_ENCODING_MODES     << QuadDec3_QUAD_MODE_SHIFT))       |\
         ((uint32)(QuadDec3_CONFIG                  << QuadDec3_MODE_SHIFT)))

#define QuadDec3_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(QuadDec3_PWM_STOP_EVENT          << QuadDec3_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(QuadDec3_PWM_OUT_INVERT          << QuadDec3_INV_OUT_SHIFT))         |\
         ((uint32)(QuadDec3_PWM_OUT_N_INVERT        << QuadDec3_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(QuadDec3_PWM_MODE                << QuadDec3_MODE_SHIFT)))

#define QuadDec3_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(QuadDec3_PWM_RUN_MODE         << QuadDec3_ONESHOT_SHIFT))
            
#define QuadDec3_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(QuadDec3_PWM_ALIGN            << QuadDec3_UPDOWN_SHIFT))

#define QuadDec3_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(QuadDec3_PWM_KILL_EVENT      << QuadDec3_PWM_SYNC_KILL_SHIFT))

#define QuadDec3_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(QuadDec3_PWM_DEAD_TIME_CYCLE  << QuadDec3_PRESCALER_SHIFT))

#define QuadDec3_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(QuadDec3_PWM_PRESCALER        << QuadDec3_PRESCALER_SHIFT))

#define QuadDec3_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(QuadDec3_TC_PRESCALER            << QuadDec3_PRESCALER_SHIFT))       |\
         ((uint32)(QuadDec3_TC_COUNTER_MODE         << QuadDec3_UPDOWN_SHIFT))          |\
         ((uint32)(QuadDec3_TC_RUN_MODE             << QuadDec3_ONESHOT_SHIFT))         |\
         ((uint32)(QuadDec3_TC_COMP_CAP_MODE        << QuadDec3_MODE_SHIFT)))
        
#define QuadDec3_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(QuadDec3_QUAD_PHIA_SIGNAL_MODE   << QuadDec3_COUNT_SHIFT))           |\
         ((uint32)(QuadDec3_QUAD_INDEX_SIGNAL_MODE  << QuadDec3_RELOAD_SHIFT))          |\
         ((uint32)(QuadDec3_QUAD_STOP_SIGNAL_MODE   << QuadDec3_STOP_SHIFT))            |\
         ((uint32)(QuadDec3_QUAD_PHIB_SIGNAL_MODE   << QuadDec3_START_SHIFT)))

#define QuadDec3_PWM_SIGNALS_MODES                                                              \
        (((uint32)(QuadDec3_PWM_SWITCH_SIGNAL_MODE  << QuadDec3_CAPTURE_SHIFT))         |\
         ((uint32)(QuadDec3_PWM_COUNT_SIGNAL_MODE   << QuadDec3_COUNT_SHIFT))           |\
         ((uint32)(QuadDec3_PWM_RELOAD_SIGNAL_MODE  << QuadDec3_RELOAD_SHIFT))          |\
         ((uint32)(QuadDec3_PWM_STOP_SIGNAL_MODE    << QuadDec3_STOP_SHIFT))            |\
         ((uint32)(QuadDec3_PWM_START_SIGNAL_MODE   << QuadDec3_START_SHIFT)))

#define QuadDec3_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(QuadDec3_TC_CAPTURE_SIGNAL_MODE  << QuadDec3_CAPTURE_SHIFT))         |\
         ((uint32)(QuadDec3_TC_COUNT_SIGNAL_MODE    << QuadDec3_COUNT_SHIFT))           |\
         ((uint32)(QuadDec3_TC_RELOAD_SIGNAL_MODE   << QuadDec3_RELOAD_SHIFT))          |\
         ((uint32)(QuadDec3_TC_STOP_SIGNAL_MODE     << QuadDec3_STOP_SHIFT))            |\
         ((uint32)(QuadDec3_TC_START_SIGNAL_MODE    << QuadDec3_START_SHIFT)))
        
#define QuadDec3_TIMER_UPDOWN_CNT_USED                                                          \
                ((QuadDec3__COUNT_UPDOWN0 == QuadDec3_TC_COUNTER_MODE)                  ||\
                 (QuadDec3__COUNT_UPDOWN1 == QuadDec3_TC_COUNTER_MODE))

#define QuadDec3_PWM_UPDOWN_CNT_USED                                                            \
                ((QuadDec3__CENTER == QuadDec3_PWM_ALIGN)                               ||\
                 (QuadDec3__ASYMMETRIC == QuadDec3_PWM_ALIGN))               
        
#define QuadDec3_PWM_PR_INIT_VALUE              (1u)
#define QuadDec3_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_QuadDec3_H */

/* [] END OF FILE */
