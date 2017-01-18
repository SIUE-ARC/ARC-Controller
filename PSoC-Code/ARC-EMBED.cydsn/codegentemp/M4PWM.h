/*******************************************************************************
* File Name: M4PWM.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the M4PWM
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

#if !defined(CY_TCPWM_M4PWM_H)
#define CY_TCPWM_M4PWM_H


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
} M4PWM_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  M4PWM_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define M4PWM_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define M4PWM_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define M4PWM_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define M4PWM_QUAD_ENCODING_MODES            (0lu)
#define M4PWM_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define M4PWM_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define M4PWM_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define M4PWM_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define M4PWM_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define M4PWM_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define M4PWM_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define M4PWM_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define M4PWM_TC_RUN_MODE                    (0lu)
#define M4PWM_TC_COUNTER_MODE                (0lu)
#define M4PWM_TC_COMP_CAP_MODE               (2lu)
#define M4PWM_TC_PRESCALER                   (0lu)

/* Signal modes */
#define M4PWM_TC_RELOAD_SIGNAL_MODE          (0lu)
#define M4PWM_TC_COUNT_SIGNAL_MODE           (3lu)
#define M4PWM_TC_START_SIGNAL_MODE           (0lu)
#define M4PWM_TC_STOP_SIGNAL_MODE            (0lu)
#define M4PWM_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define M4PWM_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define M4PWM_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define M4PWM_TC_START_SIGNAL_PRESENT        (0lu)
#define M4PWM_TC_STOP_SIGNAL_PRESENT         (0lu)
#define M4PWM_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define M4PWM_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define M4PWM_PWM_KILL_EVENT                 (0lu)
#define M4PWM_PWM_STOP_EVENT                 (0lu)
#define M4PWM_PWM_MODE                       (4lu)
#define M4PWM_PWM_OUT_N_INVERT               (0lu)
#define M4PWM_PWM_OUT_INVERT                 (0lu)
#define M4PWM_PWM_ALIGN                      (0lu)
#define M4PWM_PWM_RUN_MODE                   (0lu)
#define M4PWM_PWM_DEAD_TIME_CYCLE            (0lu)
#define M4PWM_PWM_PRESCALER                  (7lu)

/* Signal modes */
#define M4PWM_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define M4PWM_PWM_COUNT_SIGNAL_MODE          (3lu)
#define M4PWM_PWM_START_SIGNAL_MODE          (0lu)
#define M4PWM_PWM_STOP_SIGNAL_MODE           (0lu)
#define M4PWM_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define M4PWM_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define M4PWM_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define M4PWM_PWM_START_SIGNAL_PRESENT       (0lu)
#define M4PWM_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define M4PWM_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define M4PWM_PWM_INTERRUPT_MASK             (0lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define M4PWM_TC_PERIOD_VALUE                (65535lu)
#define M4PWM_TC_COMPARE_VALUE               (65535lu)
#define M4PWM_TC_COMPARE_BUF_VALUE           (65535lu)
#define M4PWM_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define M4PWM_PWM_PERIOD_VALUE               (65535lu)
#define M4PWM_PWM_PERIOD_BUF_VALUE           (65535lu)
#define M4PWM_PWM_PERIOD_SWAP                (0lu)
#define M4PWM_PWM_COMPARE_VALUE              (65535lu)
#define M4PWM_PWM_COMPARE_BUF_VALUE          (65535lu)
#define M4PWM_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define M4PWM__LEFT 0
#define M4PWM__RIGHT 1
#define M4PWM__CENTER 2
#define M4PWM__ASYMMETRIC 3

#define M4PWM__X1 0
#define M4PWM__X2 1
#define M4PWM__X4 2

#define M4PWM__PWM 4
#define M4PWM__PWM_DT 5
#define M4PWM__PWM_PR 6

#define M4PWM__INVERSE 1
#define M4PWM__DIRECT 0

#define M4PWM__CAPTURE 2
#define M4PWM__COMPARE 0

#define M4PWM__TRIG_LEVEL 3
#define M4PWM__TRIG_RISING 0
#define M4PWM__TRIG_FALLING 1
#define M4PWM__TRIG_BOTH 2

#define M4PWM__INTR_MASK_TC 1
#define M4PWM__INTR_MASK_CC_MATCH 2
#define M4PWM__INTR_MASK_NONE 0
#define M4PWM__INTR_MASK_TC_CC 3

#define M4PWM__UNCONFIG 8
#define M4PWM__TIMER 1
#define M4PWM__QUAD 3
#define M4PWM__PWM_SEL 7

#define M4PWM__COUNT_UP 0
#define M4PWM__COUNT_DOWN 1
#define M4PWM__COUNT_UPDOWN0 2
#define M4PWM__COUNT_UPDOWN1 3


/* Prescaler */
#define M4PWM_PRESCALE_DIVBY1                ((uint32)(0u << M4PWM_PRESCALER_SHIFT))
#define M4PWM_PRESCALE_DIVBY2                ((uint32)(1u << M4PWM_PRESCALER_SHIFT))
#define M4PWM_PRESCALE_DIVBY4                ((uint32)(2u << M4PWM_PRESCALER_SHIFT))
#define M4PWM_PRESCALE_DIVBY8                ((uint32)(3u << M4PWM_PRESCALER_SHIFT))
#define M4PWM_PRESCALE_DIVBY16               ((uint32)(4u << M4PWM_PRESCALER_SHIFT))
#define M4PWM_PRESCALE_DIVBY32               ((uint32)(5u << M4PWM_PRESCALER_SHIFT))
#define M4PWM_PRESCALE_DIVBY64               ((uint32)(6u << M4PWM_PRESCALER_SHIFT))
#define M4PWM_PRESCALE_DIVBY128              ((uint32)(7u << M4PWM_PRESCALER_SHIFT))

/* TCPWM set modes */
#define M4PWM_MODE_TIMER_COMPARE             ((uint32)(M4PWM__COMPARE         <<  \
                                                                  M4PWM_MODE_SHIFT))
#define M4PWM_MODE_TIMER_CAPTURE             ((uint32)(M4PWM__CAPTURE         <<  \
                                                                  M4PWM_MODE_SHIFT))
#define M4PWM_MODE_QUAD                      ((uint32)(M4PWM__QUAD            <<  \
                                                                  M4PWM_MODE_SHIFT))
#define M4PWM_MODE_PWM                       ((uint32)(M4PWM__PWM             <<  \
                                                                  M4PWM_MODE_SHIFT))
#define M4PWM_MODE_PWM_DT                    ((uint32)(M4PWM__PWM_DT          <<  \
                                                                  M4PWM_MODE_SHIFT))
#define M4PWM_MODE_PWM_PR                    ((uint32)(M4PWM__PWM_PR          <<  \
                                                                  M4PWM_MODE_SHIFT))

/* Quad Modes */
#define M4PWM_MODE_X1                        ((uint32)(M4PWM__X1              <<  \
                                                                  M4PWM_QUAD_MODE_SHIFT))
#define M4PWM_MODE_X2                        ((uint32)(M4PWM__X2              <<  \
                                                                  M4PWM_QUAD_MODE_SHIFT))
#define M4PWM_MODE_X4                        ((uint32)(M4PWM__X4              <<  \
                                                                  M4PWM_QUAD_MODE_SHIFT))

/* Counter modes */
#define M4PWM_COUNT_UP                       ((uint32)(M4PWM__COUNT_UP        <<  \
                                                                  M4PWM_UPDOWN_SHIFT))
#define M4PWM_COUNT_DOWN                     ((uint32)(M4PWM__COUNT_DOWN      <<  \
                                                                  M4PWM_UPDOWN_SHIFT))
#define M4PWM_COUNT_UPDOWN0                  ((uint32)(M4PWM__COUNT_UPDOWN0   <<  \
                                                                  M4PWM_UPDOWN_SHIFT))
#define M4PWM_COUNT_UPDOWN1                  ((uint32)(M4PWM__COUNT_UPDOWN1   <<  \
                                                                  M4PWM_UPDOWN_SHIFT))

/* PWM output invert */
#define M4PWM_INVERT_LINE                    ((uint32)(M4PWM__INVERSE         <<  \
                                                                  M4PWM_INV_OUT_SHIFT))
#define M4PWM_INVERT_LINE_N                  ((uint32)(M4PWM__INVERSE         <<  \
                                                                  M4PWM_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define M4PWM_TRIG_RISING                    ((uint32)M4PWM__TRIG_RISING)
#define M4PWM_TRIG_FALLING                   ((uint32)M4PWM__TRIG_FALLING)
#define M4PWM_TRIG_BOTH                      ((uint32)M4PWM__TRIG_BOTH)
#define M4PWM_TRIG_LEVEL                     ((uint32)M4PWM__TRIG_LEVEL)

/* Interrupt mask */
#define M4PWM_INTR_MASK_TC                   ((uint32)M4PWM__INTR_MASK_TC)
#define M4PWM_INTR_MASK_CC_MATCH             ((uint32)M4PWM__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define M4PWM_CC_MATCH_SET                   (0x00u)
#define M4PWM_CC_MATCH_CLEAR                 (0x01u)
#define M4PWM_CC_MATCH_INVERT                (0x02u)
#define M4PWM_CC_MATCH_NO_CHANGE             (0x03u)
#define M4PWM_OVERLOW_SET                    (0x00u)
#define M4PWM_OVERLOW_CLEAR                  (0x04u)
#define M4PWM_OVERLOW_INVERT                 (0x08u)
#define M4PWM_OVERLOW_NO_CHANGE              (0x0Cu)
#define M4PWM_UNDERFLOW_SET                  (0x00u)
#define M4PWM_UNDERFLOW_CLEAR                (0x10u)
#define M4PWM_UNDERFLOW_INVERT               (0x20u)
#define M4PWM_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define M4PWM_PWM_MODE_LEFT                  (M4PWM_CC_MATCH_CLEAR        |   \
                                                         M4PWM_OVERLOW_SET           |   \
                                                         M4PWM_UNDERFLOW_NO_CHANGE)
#define M4PWM_PWM_MODE_RIGHT                 (M4PWM_CC_MATCH_SET          |   \
                                                         M4PWM_OVERLOW_NO_CHANGE     |   \
                                                         M4PWM_UNDERFLOW_CLEAR)
#define M4PWM_PWM_MODE_ASYM                  (M4PWM_CC_MATCH_INVERT       |   \
                                                         M4PWM_OVERLOW_SET           |   \
                                                         M4PWM_UNDERFLOW_CLEAR)

#if (M4PWM_CY_TCPWM_V2)
    #if(M4PWM_CY_TCPWM_4000)
        #define M4PWM_PWM_MODE_CENTER                (M4PWM_CC_MATCH_INVERT       |   \
                                                                 M4PWM_OVERLOW_NO_CHANGE     |   \
                                                                 M4PWM_UNDERFLOW_CLEAR)
    #else
        #define M4PWM_PWM_MODE_CENTER                (M4PWM_CC_MATCH_INVERT       |   \
                                                                 M4PWM_OVERLOW_SET           |   \
                                                                 M4PWM_UNDERFLOW_CLEAR)
    #endif /* (M4PWM_CY_TCPWM_4000) */
#else
    #define M4PWM_PWM_MODE_CENTER                (M4PWM_CC_MATCH_INVERT       |   \
                                                             M4PWM_OVERLOW_NO_CHANGE     |   \
                                                             M4PWM_UNDERFLOW_CLEAR)
#endif /* (M4PWM_CY_TCPWM_NEW) */

/* Command operations without condition */
#define M4PWM_CMD_CAPTURE                    (0u)
#define M4PWM_CMD_RELOAD                     (8u)
#define M4PWM_CMD_STOP                       (16u)
#define M4PWM_CMD_START                      (24u)

/* Status */
#define M4PWM_STATUS_DOWN                    (1u)
#define M4PWM_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   M4PWM_Init(void);
void   M4PWM_Enable(void);
void   M4PWM_Start(void);
void   M4PWM_Stop(void);

void   M4PWM_SetMode(uint32 mode);
void   M4PWM_SetCounterMode(uint32 counterMode);
void   M4PWM_SetPWMMode(uint32 modeMask);
void   M4PWM_SetQDMode(uint32 qdMode);

void   M4PWM_SetPrescaler(uint32 prescaler);
void   M4PWM_TriggerCommand(uint32 mask, uint32 command);
void   M4PWM_SetOneShot(uint32 oneShotEnable);
uint32 M4PWM_ReadStatus(void);

void   M4PWM_SetPWMSyncKill(uint32 syncKillEnable);
void   M4PWM_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   M4PWM_SetPWMDeadTime(uint32 deadTime);
void   M4PWM_SetPWMInvert(uint32 mask);

void   M4PWM_SetInterruptMode(uint32 interruptMask);
uint32 M4PWM_GetInterruptSourceMasked(void);
uint32 M4PWM_GetInterruptSource(void);
void   M4PWM_ClearInterrupt(uint32 interruptMask);
void   M4PWM_SetInterrupt(uint32 interruptMask);

void   M4PWM_WriteCounter(uint32 count);
uint32 M4PWM_ReadCounter(void);

uint32 M4PWM_ReadCapture(void);
uint32 M4PWM_ReadCaptureBuf(void);

void   M4PWM_WritePeriod(uint32 period);
uint32 M4PWM_ReadPeriod(void);
void   M4PWM_WritePeriodBuf(uint32 periodBuf);
uint32 M4PWM_ReadPeriodBuf(void);

void   M4PWM_WriteCompare(uint32 compare);
uint32 M4PWM_ReadCompare(void);
void   M4PWM_WriteCompareBuf(uint32 compareBuf);
uint32 M4PWM_ReadCompareBuf(void);

void   M4PWM_SetPeriodSwap(uint32 swapEnable);
void   M4PWM_SetCompareSwap(uint32 swapEnable);

void   M4PWM_SetCaptureMode(uint32 triggerMode);
void   M4PWM_SetReloadMode(uint32 triggerMode);
void   M4PWM_SetStartMode(uint32 triggerMode);
void   M4PWM_SetStopMode(uint32 triggerMode);
void   M4PWM_SetCountMode(uint32 triggerMode);

void   M4PWM_SaveConfig(void);
void   M4PWM_RestoreConfig(void);
void   M4PWM_Sleep(void);
void   M4PWM_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define M4PWM_BLOCK_CONTROL_REG              (*(reg32 *) M4PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define M4PWM_BLOCK_CONTROL_PTR              ( (reg32 *) M4PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define M4PWM_COMMAND_REG                    (*(reg32 *) M4PWM_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define M4PWM_COMMAND_PTR                    ( (reg32 *) M4PWM_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define M4PWM_INTRRUPT_CAUSE_REG             (*(reg32 *) M4PWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define M4PWM_INTRRUPT_CAUSE_PTR             ( (reg32 *) M4PWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define M4PWM_CONTROL_REG                    (*(reg32 *) M4PWM_cy_m0s8_tcpwm_1__CTRL )
#define M4PWM_CONTROL_PTR                    ( (reg32 *) M4PWM_cy_m0s8_tcpwm_1__CTRL )
#define M4PWM_STATUS_REG                     (*(reg32 *) M4PWM_cy_m0s8_tcpwm_1__STATUS )
#define M4PWM_STATUS_PTR                     ( (reg32 *) M4PWM_cy_m0s8_tcpwm_1__STATUS )
#define M4PWM_COUNTER_REG                    (*(reg32 *) M4PWM_cy_m0s8_tcpwm_1__COUNTER )
#define M4PWM_COUNTER_PTR                    ( (reg32 *) M4PWM_cy_m0s8_tcpwm_1__COUNTER )
#define M4PWM_COMP_CAP_REG                   (*(reg32 *) M4PWM_cy_m0s8_tcpwm_1__CC )
#define M4PWM_COMP_CAP_PTR                   ( (reg32 *) M4PWM_cy_m0s8_tcpwm_1__CC )
#define M4PWM_COMP_CAP_BUF_REG               (*(reg32 *) M4PWM_cy_m0s8_tcpwm_1__CC_BUFF )
#define M4PWM_COMP_CAP_BUF_PTR               ( (reg32 *) M4PWM_cy_m0s8_tcpwm_1__CC_BUFF )
#define M4PWM_PERIOD_REG                     (*(reg32 *) M4PWM_cy_m0s8_tcpwm_1__PERIOD )
#define M4PWM_PERIOD_PTR                     ( (reg32 *) M4PWM_cy_m0s8_tcpwm_1__PERIOD )
#define M4PWM_PERIOD_BUF_REG                 (*(reg32 *) M4PWM_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define M4PWM_PERIOD_BUF_PTR                 ( (reg32 *) M4PWM_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define M4PWM_TRIG_CONTROL0_REG              (*(reg32 *) M4PWM_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define M4PWM_TRIG_CONTROL0_PTR              ( (reg32 *) M4PWM_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define M4PWM_TRIG_CONTROL1_REG              (*(reg32 *) M4PWM_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define M4PWM_TRIG_CONTROL1_PTR              ( (reg32 *) M4PWM_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define M4PWM_TRIG_CONTROL2_REG              (*(reg32 *) M4PWM_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define M4PWM_TRIG_CONTROL2_PTR              ( (reg32 *) M4PWM_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define M4PWM_INTERRUPT_REQ_REG              (*(reg32 *) M4PWM_cy_m0s8_tcpwm_1__INTR )
#define M4PWM_INTERRUPT_REQ_PTR              ( (reg32 *) M4PWM_cy_m0s8_tcpwm_1__INTR )
#define M4PWM_INTERRUPT_SET_REG              (*(reg32 *) M4PWM_cy_m0s8_tcpwm_1__INTR_SET )
#define M4PWM_INTERRUPT_SET_PTR              ( (reg32 *) M4PWM_cy_m0s8_tcpwm_1__INTR_SET )
#define M4PWM_INTERRUPT_MASK_REG             (*(reg32 *) M4PWM_cy_m0s8_tcpwm_1__INTR_MASK )
#define M4PWM_INTERRUPT_MASK_PTR             ( (reg32 *) M4PWM_cy_m0s8_tcpwm_1__INTR_MASK )
#define M4PWM_INTERRUPT_MASKED_REG           (*(reg32 *) M4PWM_cy_m0s8_tcpwm_1__INTR_MASKED )
#define M4PWM_INTERRUPT_MASKED_PTR           ( (reg32 *) M4PWM_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define M4PWM_MASK                           ((uint32)M4PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define M4PWM_RELOAD_CC_SHIFT                (0u)
#define M4PWM_RELOAD_PERIOD_SHIFT            (1u)
#define M4PWM_PWM_SYNC_KILL_SHIFT            (2u)
#define M4PWM_PWM_STOP_KILL_SHIFT            (3u)
#define M4PWM_PRESCALER_SHIFT                (8u)
#define M4PWM_UPDOWN_SHIFT                   (16u)
#define M4PWM_ONESHOT_SHIFT                  (18u)
#define M4PWM_QUAD_MODE_SHIFT                (20u)
#define M4PWM_INV_OUT_SHIFT                  (20u)
#define M4PWM_INV_COMPL_OUT_SHIFT            (21u)
#define M4PWM_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define M4PWM_RELOAD_CC_MASK                 ((uint32)(M4PWM_1BIT_MASK        <<  \
                                                                            M4PWM_RELOAD_CC_SHIFT))
#define M4PWM_RELOAD_PERIOD_MASK             ((uint32)(M4PWM_1BIT_MASK        <<  \
                                                                            M4PWM_RELOAD_PERIOD_SHIFT))
#define M4PWM_PWM_SYNC_KILL_MASK             ((uint32)(M4PWM_1BIT_MASK        <<  \
                                                                            M4PWM_PWM_SYNC_KILL_SHIFT))
#define M4PWM_PWM_STOP_KILL_MASK             ((uint32)(M4PWM_1BIT_MASK        <<  \
                                                                            M4PWM_PWM_STOP_KILL_SHIFT))
#define M4PWM_PRESCALER_MASK                 ((uint32)(M4PWM_8BIT_MASK        <<  \
                                                                            M4PWM_PRESCALER_SHIFT))
#define M4PWM_UPDOWN_MASK                    ((uint32)(M4PWM_2BIT_MASK        <<  \
                                                                            M4PWM_UPDOWN_SHIFT))
#define M4PWM_ONESHOT_MASK                   ((uint32)(M4PWM_1BIT_MASK        <<  \
                                                                            M4PWM_ONESHOT_SHIFT))
#define M4PWM_QUAD_MODE_MASK                 ((uint32)(M4PWM_3BIT_MASK        <<  \
                                                                            M4PWM_QUAD_MODE_SHIFT))
#define M4PWM_INV_OUT_MASK                   ((uint32)(M4PWM_2BIT_MASK        <<  \
                                                                            M4PWM_INV_OUT_SHIFT))
#define M4PWM_MODE_MASK                      ((uint32)(M4PWM_3BIT_MASK        <<  \
                                                                            M4PWM_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define M4PWM_CAPTURE_SHIFT                  (0u)
#define M4PWM_COUNT_SHIFT                    (2u)
#define M4PWM_RELOAD_SHIFT                   (4u)
#define M4PWM_STOP_SHIFT                     (6u)
#define M4PWM_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define M4PWM_CAPTURE_MASK                   ((uint32)(M4PWM_2BIT_MASK        <<  \
                                                                  M4PWM_CAPTURE_SHIFT))
#define M4PWM_COUNT_MASK                     ((uint32)(M4PWM_2BIT_MASK        <<  \
                                                                  M4PWM_COUNT_SHIFT))
#define M4PWM_RELOAD_MASK                    ((uint32)(M4PWM_2BIT_MASK        <<  \
                                                                  M4PWM_RELOAD_SHIFT))
#define M4PWM_STOP_MASK                      ((uint32)(M4PWM_2BIT_MASK        <<  \
                                                                  M4PWM_STOP_SHIFT))
#define M4PWM_START_MASK                     ((uint32)(M4PWM_2BIT_MASK        <<  \
                                                                  M4PWM_START_SHIFT))

/* MASK */
#define M4PWM_1BIT_MASK                      ((uint32)0x01u)
#define M4PWM_2BIT_MASK                      ((uint32)0x03u)
#define M4PWM_3BIT_MASK                      ((uint32)0x07u)
#define M4PWM_6BIT_MASK                      ((uint32)0x3Fu)
#define M4PWM_8BIT_MASK                      ((uint32)0xFFu)
#define M4PWM_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define M4PWM_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define M4PWM_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(M4PWM_QUAD_ENCODING_MODES     << M4PWM_QUAD_MODE_SHIFT))       |\
         ((uint32)(M4PWM_CONFIG                  << M4PWM_MODE_SHIFT)))

#define M4PWM_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(M4PWM_PWM_STOP_EVENT          << M4PWM_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(M4PWM_PWM_OUT_INVERT          << M4PWM_INV_OUT_SHIFT))         |\
         ((uint32)(M4PWM_PWM_OUT_N_INVERT        << M4PWM_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(M4PWM_PWM_MODE                << M4PWM_MODE_SHIFT)))

#define M4PWM_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(M4PWM_PWM_RUN_MODE         << M4PWM_ONESHOT_SHIFT))
            
#define M4PWM_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(M4PWM_PWM_ALIGN            << M4PWM_UPDOWN_SHIFT))

#define M4PWM_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(M4PWM_PWM_KILL_EVENT      << M4PWM_PWM_SYNC_KILL_SHIFT))

#define M4PWM_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(M4PWM_PWM_DEAD_TIME_CYCLE  << M4PWM_PRESCALER_SHIFT))

#define M4PWM_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(M4PWM_PWM_PRESCALER        << M4PWM_PRESCALER_SHIFT))

#define M4PWM_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(M4PWM_TC_PRESCALER            << M4PWM_PRESCALER_SHIFT))       |\
         ((uint32)(M4PWM_TC_COUNTER_MODE         << M4PWM_UPDOWN_SHIFT))          |\
         ((uint32)(M4PWM_TC_RUN_MODE             << M4PWM_ONESHOT_SHIFT))         |\
         ((uint32)(M4PWM_TC_COMP_CAP_MODE        << M4PWM_MODE_SHIFT)))
        
#define M4PWM_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(M4PWM_QUAD_PHIA_SIGNAL_MODE   << M4PWM_COUNT_SHIFT))           |\
         ((uint32)(M4PWM_QUAD_INDEX_SIGNAL_MODE  << M4PWM_RELOAD_SHIFT))          |\
         ((uint32)(M4PWM_QUAD_STOP_SIGNAL_MODE   << M4PWM_STOP_SHIFT))            |\
         ((uint32)(M4PWM_QUAD_PHIB_SIGNAL_MODE   << M4PWM_START_SHIFT)))

#define M4PWM_PWM_SIGNALS_MODES                                                              \
        (((uint32)(M4PWM_PWM_SWITCH_SIGNAL_MODE  << M4PWM_CAPTURE_SHIFT))         |\
         ((uint32)(M4PWM_PWM_COUNT_SIGNAL_MODE   << M4PWM_COUNT_SHIFT))           |\
         ((uint32)(M4PWM_PWM_RELOAD_SIGNAL_MODE  << M4PWM_RELOAD_SHIFT))          |\
         ((uint32)(M4PWM_PWM_STOP_SIGNAL_MODE    << M4PWM_STOP_SHIFT))            |\
         ((uint32)(M4PWM_PWM_START_SIGNAL_MODE   << M4PWM_START_SHIFT)))

#define M4PWM_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(M4PWM_TC_CAPTURE_SIGNAL_MODE  << M4PWM_CAPTURE_SHIFT))         |\
         ((uint32)(M4PWM_TC_COUNT_SIGNAL_MODE    << M4PWM_COUNT_SHIFT))           |\
         ((uint32)(M4PWM_TC_RELOAD_SIGNAL_MODE   << M4PWM_RELOAD_SHIFT))          |\
         ((uint32)(M4PWM_TC_STOP_SIGNAL_MODE     << M4PWM_STOP_SHIFT))            |\
         ((uint32)(M4PWM_TC_START_SIGNAL_MODE    << M4PWM_START_SHIFT)))
        
#define M4PWM_TIMER_UPDOWN_CNT_USED                                                          \
                ((M4PWM__COUNT_UPDOWN0 == M4PWM_TC_COUNTER_MODE)                  ||\
                 (M4PWM__COUNT_UPDOWN1 == M4PWM_TC_COUNTER_MODE))

#define M4PWM_PWM_UPDOWN_CNT_USED                                                            \
                ((M4PWM__CENTER == M4PWM_PWM_ALIGN)                               ||\
                 (M4PWM__ASYMMETRIC == M4PWM_PWM_ALIGN))               
        
#define M4PWM_PWM_PR_INIT_VALUE              (1u)
#define M4PWM_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_M4PWM_H */

/* [] END OF FILE */
