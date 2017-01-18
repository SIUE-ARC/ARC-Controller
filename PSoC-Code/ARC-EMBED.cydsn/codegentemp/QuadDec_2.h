/*******************************************************************************
* File Name: QuadDec_2.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the QuadDec_2
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

#if !defined(CY_TCPWM_QuadDec_2_H)
#define CY_TCPWM_QuadDec_2_H


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
} QuadDec_2_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  QuadDec_2_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define QuadDec_2_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define QuadDec_2_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define QuadDec_2_CONFIG                         (3lu)

/* Quad Mode */
/* Parameters */
#define QuadDec_2_QUAD_ENCODING_MODES            (2lu)
#define QuadDec_2_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define QuadDec_2_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define QuadDec_2_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define QuadDec_2_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define QuadDec_2_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define QuadDec_2_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define QuadDec_2_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define QuadDec_2_QUAD_INTERRUPT_MASK            (0lu)

/* Timer/Counter Mode */
/* Parameters */
#define QuadDec_2_TC_RUN_MODE                    (0lu)
#define QuadDec_2_TC_COUNTER_MODE                (0lu)
#define QuadDec_2_TC_COMP_CAP_MODE               (2lu)
#define QuadDec_2_TC_PRESCALER                   (0lu)

/* Signal modes */
#define QuadDec_2_TC_RELOAD_SIGNAL_MODE          (0lu)
#define QuadDec_2_TC_COUNT_SIGNAL_MODE           (3lu)
#define QuadDec_2_TC_START_SIGNAL_MODE           (0lu)
#define QuadDec_2_TC_STOP_SIGNAL_MODE            (0lu)
#define QuadDec_2_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define QuadDec_2_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define QuadDec_2_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define QuadDec_2_TC_START_SIGNAL_PRESENT        (0lu)
#define QuadDec_2_TC_STOP_SIGNAL_PRESENT         (0lu)
#define QuadDec_2_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define QuadDec_2_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define QuadDec_2_PWM_KILL_EVENT                 (0lu)
#define QuadDec_2_PWM_STOP_EVENT                 (0lu)
#define QuadDec_2_PWM_MODE                       (4lu)
#define QuadDec_2_PWM_OUT_N_INVERT               (0lu)
#define QuadDec_2_PWM_OUT_INVERT                 (0lu)
#define QuadDec_2_PWM_ALIGN                      (0lu)
#define QuadDec_2_PWM_RUN_MODE                   (0lu)
#define QuadDec_2_PWM_DEAD_TIME_CYCLE            (0lu)
#define QuadDec_2_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define QuadDec_2_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define QuadDec_2_PWM_COUNT_SIGNAL_MODE          (3lu)
#define QuadDec_2_PWM_START_SIGNAL_MODE          (0lu)
#define QuadDec_2_PWM_STOP_SIGNAL_MODE           (0lu)
#define QuadDec_2_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define QuadDec_2_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define QuadDec_2_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define QuadDec_2_PWM_START_SIGNAL_PRESENT       (0lu)
#define QuadDec_2_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define QuadDec_2_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define QuadDec_2_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define QuadDec_2_TC_PERIOD_VALUE                (65535lu)
#define QuadDec_2_TC_COMPARE_VALUE               (65535lu)
#define QuadDec_2_TC_COMPARE_BUF_VALUE           (65535lu)
#define QuadDec_2_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define QuadDec_2_PWM_PERIOD_VALUE               (65535lu)
#define QuadDec_2_PWM_PERIOD_BUF_VALUE           (65535lu)
#define QuadDec_2_PWM_PERIOD_SWAP                (0lu)
#define QuadDec_2_PWM_COMPARE_VALUE              (65535lu)
#define QuadDec_2_PWM_COMPARE_BUF_VALUE          (65535lu)
#define QuadDec_2_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define QuadDec_2__LEFT 0
#define QuadDec_2__RIGHT 1
#define QuadDec_2__CENTER 2
#define QuadDec_2__ASYMMETRIC 3

#define QuadDec_2__X1 0
#define QuadDec_2__X2 1
#define QuadDec_2__X4 2

#define QuadDec_2__PWM 4
#define QuadDec_2__PWM_DT 5
#define QuadDec_2__PWM_PR 6

#define QuadDec_2__INVERSE 1
#define QuadDec_2__DIRECT 0

#define QuadDec_2__CAPTURE 2
#define QuadDec_2__COMPARE 0

#define QuadDec_2__TRIG_LEVEL 3
#define QuadDec_2__TRIG_RISING 0
#define QuadDec_2__TRIG_FALLING 1
#define QuadDec_2__TRIG_BOTH 2

#define QuadDec_2__INTR_MASK_TC 1
#define QuadDec_2__INTR_MASK_CC_MATCH 2
#define QuadDec_2__INTR_MASK_NONE 0
#define QuadDec_2__INTR_MASK_TC_CC 3

#define QuadDec_2__UNCONFIG 8
#define QuadDec_2__TIMER 1
#define QuadDec_2__QUAD 3
#define QuadDec_2__PWM_SEL 7

#define QuadDec_2__COUNT_UP 0
#define QuadDec_2__COUNT_DOWN 1
#define QuadDec_2__COUNT_UPDOWN0 2
#define QuadDec_2__COUNT_UPDOWN1 3


/* Prescaler */
#define QuadDec_2_PRESCALE_DIVBY1                ((uint32)(0u << QuadDec_2_PRESCALER_SHIFT))
#define QuadDec_2_PRESCALE_DIVBY2                ((uint32)(1u << QuadDec_2_PRESCALER_SHIFT))
#define QuadDec_2_PRESCALE_DIVBY4                ((uint32)(2u << QuadDec_2_PRESCALER_SHIFT))
#define QuadDec_2_PRESCALE_DIVBY8                ((uint32)(3u << QuadDec_2_PRESCALER_SHIFT))
#define QuadDec_2_PRESCALE_DIVBY16               ((uint32)(4u << QuadDec_2_PRESCALER_SHIFT))
#define QuadDec_2_PRESCALE_DIVBY32               ((uint32)(5u << QuadDec_2_PRESCALER_SHIFT))
#define QuadDec_2_PRESCALE_DIVBY64               ((uint32)(6u << QuadDec_2_PRESCALER_SHIFT))
#define QuadDec_2_PRESCALE_DIVBY128              ((uint32)(7u << QuadDec_2_PRESCALER_SHIFT))

/* TCPWM set modes */
#define QuadDec_2_MODE_TIMER_COMPARE             ((uint32)(QuadDec_2__COMPARE         <<  \
                                                                  QuadDec_2_MODE_SHIFT))
#define QuadDec_2_MODE_TIMER_CAPTURE             ((uint32)(QuadDec_2__CAPTURE         <<  \
                                                                  QuadDec_2_MODE_SHIFT))
#define QuadDec_2_MODE_QUAD                      ((uint32)(QuadDec_2__QUAD            <<  \
                                                                  QuadDec_2_MODE_SHIFT))
#define QuadDec_2_MODE_PWM                       ((uint32)(QuadDec_2__PWM             <<  \
                                                                  QuadDec_2_MODE_SHIFT))
#define QuadDec_2_MODE_PWM_DT                    ((uint32)(QuadDec_2__PWM_DT          <<  \
                                                                  QuadDec_2_MODE_SHIFT))
#define QuadDec_2_MODE_PWM_PR                    ((uint32)(QuadDec_2__PWM_PR          <<  \
                                                                  QuadDec_2_MODE_SHIFT))

/* Quad Modes */
#define QuadDec_2_MODE_X1                        ((uint32)(QuadDec_2__X1              <<  \
                                                                  QuadDec_2_QUAD_MODE_SHIFT))
#define QuadDec_2_MODE_X2                        ((uint32)(QuadDec_2__X2              <<  \
                                                                  QuadDec_2_QUAD_MODE_SHIFT))
#define QuadDec_2_MODE_X4                        ((uint32)(QuadDec_2__X4              <<  \
                                                                  QuadDec_2_QUAD_MODE_SHIFT))

/* Counter modes */
#define QuadDec_2_COUNT_UP                       ((uint32)(QuadDec_2__COUNT_UP        <<  \
                                                                  QuadDec_2_UPDOWN_SHIFT))
#define QuadDec_2_COUNT_DOWN                     ((uint32)(QuadDec_2__COUNT_DOWN      <<  \
                                                                  QuadDec_2_UPDOWN_SHIFT))
#define QuadDec_2_COUNT_UPDOWN0                  ((uint32)(QuadDec_2__COUNT_UPDOWN0   <<  \
                                                                  QuadDec_2_UPDOWN_SHIFT))
#define QuadDec_2_COUNT_UPDOWN1                  ((uint32)(QuadDec_2__COUNT_UPDOWN1   <<  \
                                                                  QuadDec_2_UPDOWN_SHIFT))

/* PWM output invert */
#define QuadDec_2_INVERT_LINE                    ((uint32)(QuadDec_2__INVERSE         <<  \
                                                                  QuadDec_2_INV_OUT_SHIFT))
#define QuadDec_2_INVERT_LINE_N                  ((uint32)(QuadDec_2__INVERSE         <<  \
                                                                  QuadDec_2_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define QuadDec_2_TRIG_RISING                    ((uint32)QuadDec_2__TRIG_RISING)
#define QuadDec_2_TRIG_FALLING                   ((uint32)QuadDec_2__TRIG_FALLING)
#define QuadDec_2_TRIG_BOTH                      ((uint32)QuadDec_2__TRIG_BOTH)
#define QuadDec_2_TRIG_LEVEL                     ((uint32)QuadDec_2__TRIG_LEVEL)

/* Interrupt mask */
#define QuadDec_2_INTR_MASK_TC                   ((uint32)QuadDec_2__INTR_MASK_TC)
#define QuadDec_2_INTR_MASK_CC_MATCH             ((uint32)QuadDec_2__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define QuadDec_2_CC_MATCH_SET                   (0x00u)
#define QuadDec_2_CC_MATCH_CLEAR                 (0x01u)
#define QuadDec_2_CC_MATCH_INVERT                (0x02u)
#define QuadDec_2_CC_MATCH_NO_CHANGE             (0x03u)
#define QuadDec_2_OVERLOW_SET                    (0x00u)
#define QuadDec_2_OVERLOW_CLEAR                  (0x04u)
#define QuadDec_2_OVERLOW_INVERT                 (0x08u)
#define QuadDec_2_OVERLOW_NO_CHANGE              (0x0Cu)
#define QuadDec_2_UNDERFLOW_SET                  (0x00u)
#define QuadDec_2_UNDERFLOW_CLEAR                (0x10u)
#define QuadDec_2_UNDERFLOW_INVERT               (0x20u)
#define QuadDec_2_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define QuadDec_2_PWM_MODE_LEFT                  (QuadDec_2_CC_MATCH_CLEAR        |   \
                                                         QuadDec_2_OVERLOW_SET           |   \
                                                         QuadDec_2_UNDERFLOW_NO_CHANGE)
#define QuadDec_2_PWM_MODE_RIGHT                 (QuadDec_2_CC_MATCH_SET          |   \
                                                         QuadDec_2_OVERLOW_NO_CHANGE     |   \
                                                         QuadDec_2_UNDERFLOW_CLEAR)
#define QuadDec_2_PWM_MODE_ASYM                  (QuadDec_2_CC_MATCH_INVERT       |   \
                                                         QuadDec_2_OVERLOW_SET           |   \
                                                         QuadDec_2_UNDERFLOW_CLEAR)

#if (QuadDec_2_CY_TCPWM_V2)
    #if(QuadDec_2_CY_TCPWM_4000)
        #define QuadDec_2_PWM_MODE_CENTER                (QuadDec_2_CC_MATCH_INVERT       |   \
                                                                 QuadDec_2_OVERLOW_NO_CHANGE     |   \
                                                                 QuadDec_2_UNDERFLOW_CLEAR)
    #else
        #define QuadDec_2_PWM_MODE_CENTER                (QuadDec_2_CC_MATCH_INVERT       |   \
                                                                 QuadDec_2_OVERLOW_SET           |   \
                                                                 QuadDec_2_UNDERFLOW_CLEAR)
    #endif /* (QuadDec_2_CY_TCPWM_4000) */
#else
    #define QuadDec_2_PWM_MODE_CENTER                (QuadDec_2_CC_MATCH_INVERT       |   \
                                                             QuadDec_2_OVERLOW_NO_CHANGE     |   \
                                                             QuadDec_2_UNDERFLOW_CLEAR)
#endif /* (QuadDec_2_CY_TCPWM_NEW) */

/* Command operations without condition */
#define QuadDec_2_CMD_CAPTURE                    (0u)
#define QuadDec_2_CMD_RELOAD                     (8u)
#define QuadDec_2_CMD_STOP                       (16u)
#define QuadDec_2_CMD_START                      (24u)

/* Status */
#define QuadDec_2_STATUS_DOWN                    (1u)
#define QuadDec_2_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   QuadDec_2_Init(void);
void   QuadDec_2_Enable(void);
void   QuadDec_2_Start(void);
void   QuadDec_2_Stop(void);

void   QuadDec_2_SetMode(uint32 mode);
void   QuadDec_2_SetCounterMode(uint32 counterMode);
void   QuadDec_2_SetPWMMode(uint32 modeMask);
void   QuadDec_2_SetQDMode(uint32 qdMode);

void   QuadDec_2_SetPrescaler(uint32 prescaler);
void   QuadDec_2_TriggerCommand(uint32 mask, uint32 command);
void   QuadDec_2_SetOneShot(uint32 oneShotEnable);
uint32 QuadDec_2_ReadStatus(void);

void   QuadDec_2_SetPWMSyncKill(uint32 syncKillEnable);
void   QuadDec_2_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   QuadDec_2_SetPWMDeadTime(uint32 deadTime);
void   QuadDec_2_SetPWMInvert(uint32 mask);

void   QuadDec_2_SetInterruptMode(uint32 interruptMask);
uint32 QuadDec_2_GetInterruptSourceMasked(void);
uint32 QuadDec_2_GetInterruptSource(void);
void   QuadDec_2_ClearInterrupt(uint32 interruptMask);
void   QuadDec_2_SetInterrupt(uint32 interruptMask);

void   QuadDec_2_WriteCounter(uint32 count);
uint32 QuadDec_2_ReadCounter(void);

uint32 QuadDec_2_ReadCapture(void);
uint32 QuadDec_2_ReadCaptureBuf(void);

void   QuadDec_2_WritePeriod(uint32 period);
uint32 QuadDec_2_ReadPeriod(void);
void   QuadDec_2_WritePeriodBuf(uint32 periodBuf);
uint32 QuadDec_2_ReadPeriodBuf(void);

void   QuadDec_2_WriteCompare(uint32 compare);
uint32 QuadDec_2_ReadCompare(void);
void   QuadDec_2_WriteCompareBuf(uint32 compareBuf);
uint32 QuadDec_2_ReadCompareBuf(void);

void   QuadDec_2_SetPeriodSwap(uint32 swapEnable);
void   QuadDec_2_SetCompareSwap(uint32 swapEnable);

void   QuadDec_2_SetCaptureMode(uint32 triggerMode);
void   QuadDec_2_SetReloadMode(uint32 triggerMode);
void   QuadDec_2_SetStartMode(uint32 triggerMode);
void   QuadDec_2_SetStopMode(uint32 triggerMode);
void   QuadDec_2_SetCountMode(uint32 triggerMode);

void   QuadDec_2_SaveConfig(void);
void   QuadDec_2_RestoreConfig(void);
void   QuadDec_2_Sleep(void);
void   QuadDec_2_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define QuadDec_2_BLOCK_CONTROL_REG              (*(reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define QuadDec_2_BLOCK_CONTROL_PTR              ( (reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define QuadDec_2_COMMAND_REG                    (*(reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define QuadDec_2_COMMAND_PTR                    ( (reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define QuadDec_2_INTRRUPT_CAUSE_REG             (*(reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define QuadDec_2_INTRRUPT_CAUSE_PTR             ( (reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define QuadDec_2_CONTROL_REG                    (*(reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__CTRL )
#define QuadDec_2_CONTROL_PTR                    ( (reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__CTRL )
#define QuadDec_2_STATUS_REG                     (*(reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__STATUS )
#define QuadDec_2_STATUS_PTR                     ( (reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__STATUS )
#define QuadDec_2_COUNTER_REG                    (*(reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__COUNTER )
#define QuadDec_2_COUNTER_PTR                    ( (reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__COUNTER )
#define QuadDec_2_COMP_CAP_REG                   (*(reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__CC )
#define QuadDec_2_COMP_CAP_PTR                   ( (reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__CC )
#define QuadDec_2_COMP_CAP_BUF_REG               (*(reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__CC_BUFF )
#define QuadDec_2_COMP_CAP_BUF_PTR               ( (reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__CC_BUFF )
#define QuadDec_2_PERIOD_REG                     (*(reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__PERIOD )
#define QuadDec_2_PERIOD_PTR                     ( (reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__PERIOD )
#define QuadDec_2_PERIOD_BUF_REG                 (*(reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define QuadDec_2_PERIOD_BUF_PTR                 ( (reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define QuadDec_2_TRIG_CONTROL0_REG              (*(reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define QuadDec_2_TRIG_CONTROL0_PTR              ( (reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define QuadDec_2_TRIG_CONTROL1_REG              (*(reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define QuadDec_2_TRIG_CONTROL1_PTR              ( (reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define QuadDec_2_TRIG_CONTROL2_REG              (*(reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define QuadDec_2_TRIG_CONTROL2_PTR              ( (reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define QuadDec_2_INTERRUPT_REQ_REG              (*(reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__INTR )
#define QuadDec_2_INTERRUPT_REQ_PTR              ( (reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__INTR )
#define QuadDec_2_INTERRUPT_SET_REG              (*(reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__INTR_SET )
#define QuadDec_2_INTERRUPT_SET_PTR              ( (reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__INTR_SET )
#define QuadDec_2_INTERRUPT_MASK_REG             (*(reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__INTR_MASK )
#define QuadDec_2_INTERRUPT_MASK_PTR             ( (reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__INTR_MASK )
#define QuadDec_2_INTERRUPT_MASKED_REG           (*(reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__INTR_MASKED )
#define QuadDec_2_INTERRUPT_MASKED_PTR           ( (reg32 *) QuadDec_2_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define QuadDec_2_MASK                           ((uint32)QuadDec_2_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define QuadDec_2_RELOAD_CC_SHIFT                (0u)
#define QuadDec_2_RELOAD_PERIOD_SHIFT            (1u)
#define QuadDec_2_PWM_SYNC_KILL_SHIFT            (2u)
#define QuadDec_2_PWM_STOP_KILL_SHIFT            (3u)
#define QuadDec_2_PRESCALER_SHIFT                (8u)
#define QuadDec_2_UPDOWN_SHIFT                   (16u)
#define QuadDec_2_ONESHOT_SHIFT                  (18u)
#define QuadDec_2_QUAD_MODE_SHIFT                (20u)
#define QuadDec_2_INV_OUT_SHIFT                  (20u)
#define QuadDec_2_INV_COMPL_OUT_SHIFT            (21u)
#define QuadDec_2_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define QuadDec_2_RELOAD_CC_MASK                 ((uint32)(QuadDec_2_1BIT_MASK        <<  \
                                                                            QuadDec_2_RELOAD_CC_SHIFT))
#define QuadDec_2_RELOAD_PERIOD_MASK             ((uint32)(QuadDec_2_1BIT_MASK        <<  \
                                                                            QuadDec_2_RELOAD_PERIOD_SHIFT))
#define QuadDec_2_PWM_SYNC_KILL_MASK             ((uint32)(QuadDec_2_1BIT_MASK        <<  \
                                                                            QuadDec_2_PWM_SYNC_KILL_SHIFT))
#define QuadDec_2_PWM_STOP_KILL_MASK             ((uint32)(QuadDec_2_1BIT_MASK        <<  \
                                                                            QuadDec_2_PWM_STOP_KILL_SHIFT))
#define QuadDec_2_PRESCALER_MASK                 ((uint32)(QuadDec_2_8BIT_MASK        <<  \
                                                                            QuadDec_2_PRESCALER_SHIFT))
#define QuadDec_2_UPDOWN_MASK                    ((uint32)(QuadDec_2_2BIT_MASK        <<  \
                                                                            QuadDec_2_UPDOWN_SHIFT))
#define QuadDec_2_ONESHOT_MASK                   ((uint32)(QuadDec_2_1BIT_MASK        <<  \
                                                                            QuadDec_2_ONESHOT_SHIFT))
#define QuadDec_2_QUAD_MODE_MASK                 ((uint32)(QuadDec_2_3BIT_MASK        <<  \
                                                                            QuadDec_2_QUAD_MODE_SHIFT))
#define QuadDec_2_INV_OUT_MASK                   ((uint32)(QuadDec_2_2BIT_MASK        <<  \
                                                                            QuadDec_2_INV_OUT_SHIFT))
#define QuadDec_2_MODE_MASK                      ((uint32)(QuadDec_2_3BIT_MASK        <<  \
                                                                            QuadDec_2_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define QuadDec_2_CAPTURE_SHIFT                  (0u)
#define QuadDec_2_COUNT_SHIFT                    (2u)
#define QuadDec_2_RELOAD_SHIFT                   (4u)
#define QuadDec_2_STOP_SHIFT                     (6u)
#define QuadDec_2_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define QuadDec_2_CAPTURE_MASK                   ((uint32)(QuadDec_2_2BIT_MASK        <<  \
                                                                  QuadDec_2_CAPTURE_SHIFT))
#define QuadDec_2_COUNT_MASK                     ((uint32)(QuadDec_2_2BIT_MASK        <<  \
                                                                  QuadDec_2_COUNT_SHIFT))
#define QuadDec_2_RELOAD_MASK                    ((uint32)(QuadDec_2_2BIT_MASK        <<  \
                                                                  QuadDec_2_RELOAD_SHIFT))
#define QuadDec_2_STOP_MASK                      ((uint32)(QuadDec_2_2BIT_MASK        <<  \
                                                                  QuadDec_2_STOP_SHIFT))
#define QuadDec_2_START_MASK                     ((uint32)(QuadDec_2_2BIT_MASK        <<  \
                                                                  QuadDec_2_START_SHIFT))

/* MASK */
#define QuadDec_2_1BIT_MASK                      ((uint32)0x01u)
#define QuadDec_2_2BIT_MASK                      ((uint32)0x03u)
#define QuadDec_2_3BIT_MASK                      ((uint32)0x07u)
#define QuadDec_2_6BIT_MASK                      ((uint32)0x3Fu)
#define QuadDec_2_8BIT_MASK                      ((uint32)0xFFu)
#define QuadDec_2_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define QuadDec_2_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define QuadDec_2_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(QuadDec_2_QUAD_ENCODING_MODES     << QuadDec_2_QUAD_MODE_SHIFT))       |\
         ((uint32)(QuadDec_2_CONFIG                  << QuadDec_2_MODE_SHIFT)))

#define QuadDec_2_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(QuadDec_2_PWM_STOP_EVENT          << QuadDec_2_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(QuadDec_2_PWM_OUT_INVERT          << QuadDec_2_INV_OUT_SHIFT))         |\
         ((uint32)(QuadDec_2_PWM_OUT_N_INVERT        << QuadDec_2_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(QuadDec_2_PWM_MODE                << QuadDec_2_MODE_SHIFT)))

#define QuadDec_2_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(QuadDec_2_PWM_RUN_MODE         << QuadDec_2_ONESHOT_SHIFT))
            
#define QuadDec_2_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(QuadDec_2_PWM_ALIGN            << QuadDec_2_UPDOWN_SHIFT))

#define QuadDec_2_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(QuadDec_2_PWM_KILL_EVENT      << QuadDec_2_PWM_SYNC_KILL_SHIFT))

#define QuadDec_2_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(QuadDec_2_PWM_DEAD_TIME_CYCLE  << QuadDec_2_PRESCALER_SHIFT))

#define QuadDec_2_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(QuadDec_2_PWM_PRESCALER        << QuadDec_2_PRESCALER_SHIFT))

#define QuadDec_2_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(QuadDec_2_TC_PRESCALER            << QuadDec_2_PRESCALER_SHIFT))       |\
         ((uint32)(QuadDec_2_TC_COUNTER_MODE         << QuadDec_2_UPDOWN_SHIFT))          |\
         ((uint32)(QuadDec_2_TC_RUN_MODE             << QuadDec_2_ONESHOT_SHIFT))         |\
         ((uint32)(QuadDec_2_TC_COMP_CAP_MODE        << QuadDec_2_MODE_SHIFT)))
        
#define QuadDec_2_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(QuadDec_2_QUAD_PHIA_SIGNAL_MODE   << QuadDec_2_COUNT_SHIFT))           |\
         ((uint32)(QuadDec_2_QUAD_INDEX_SIGNAL_MODE  << QuadDec_2_RELOAD_SHIFT))          |\
         ((uint32)(QuadDec_2_QUAD_STOP_SIGNAL_MODE   << QuadDec_2_STOP_SHIFT))            |\
         ((uint32)(QuadDec_2_QUAD_PHIB_SIGNAL_MODE   << QuadDec_2_START_SHIFT)))

#define QuadDec_2_PWM_SIGNALS_MODES                                                              \
        (((uint32)(QuadDec_2_PWM_SWITCH_SIGNAL_MODE  << QuadDec_2_CAPTURE_SHIFT))         |\
         ((uint32)(QuadDec_2_PWM_COUNT_SIGNAL_MODE   << QuadDec_2_COUNT_SHIFT))           |\
         ((uint32)(QuadDec_2_PWM_RELOAD_SIGNAL_MODE  << QuadDec_2_RELOAD_SHIFT))          |\
         ((uint32)(QuadDec_2_PWM_STOP_SIGNAL_MODE    << QuadDec_2_STOP_SHIFT))            |\
         ((uint32)(QuadDec_2_PWM_START_SIGNAL_MODE   << QuadDec_2_START_SHIFT)))

#define QuadDec_2_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(QuadDec_2_TC_CAPTURE_SIGNAL_MODE  << QuadDec_2_CAPTURE_SHIFT))         |\
         ((uint32)(QuadDec_2_TC_COUNT_SIGNAL_MODE    << QuadDec_2_COUNT_SHIFT))           |\
         ((uint32)(QuadDec_2_TC_RELOAD_SIGNAL_MODE   << QuadDec_2_RELOAD_SHIFT))          |\
         ((uint32)(QuadDec_2_TC_STOP_SIGNAL_MODE     << QuadDec_2_STOP_SHIFT))            |\
         ((uint32)(QuadDec_2_TC_START_SIGNAL_MODE    << QuadDec_2_START_SHIFT)))
        
#define QuadDec_2_TIMER_UPDOWN_CNT_USED                                                          \
                ((QuadDec_2__COUNT_UPDOWN0 == QuadDec_2_TC_COUNTER_MODE)                  ||\
                 (QuadDec_2__COUNT_UPDOWN1 == QuadDec_2_TC_COUNTER_MODE))

#define QuadDec_2_PWM_UPDOWN_CNT_USED                                                            \
                ((QuadDec_2__CENTER == QuadDec_2_PWM_ALIGN)                               ||\
                 (QuadDec_2__ASYMMETRIC == QuadDec_2_PWM_ALIGN))               
        
#define QuadDec_2_PWM_PR_INIT_VALUE              (1u)
#define QuadDec_2_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_QuadDec_2_H */

/* [] END OF FILE */
