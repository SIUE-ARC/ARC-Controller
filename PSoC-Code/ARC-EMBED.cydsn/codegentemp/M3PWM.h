/*******************************************************************************
* File Name: M3PWM.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the M3PWM
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

#if !defined(CY_TCPWM_M3PWM_H)
#define CY_TCPWM_M3PWM_H


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
} M3PWM_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  M3PWM_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define M3PWM_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define M3PWM_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define M3PWM_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define M3PWM_QUAD_ENCODING_MODES            (0lu)
#define M3PWM_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define M3PWM_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define M3PWM_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define M3PWM_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define M3PWM_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define M3PWM_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define M3PWM_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define M3PWM_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define M3PWM_TC_RUN_MODE                    (0lu)
#define M3PWM_TC_COUNTER_MODE                (0lu)
#define M3PWM_TC_COMP_CAP_MODE               (2lu)
#define M3PWM_TC_PRESCALER                   (0lu)

/* Signal modes */
#define M3PWM_TC_RELOAD_SIGNAL_MODE          (0lu)
#define M3PWM_TC_COUNT_SIGNAL_MODE           (3lu)
#define M3PWM_TC_START_SIGNAL_MODE           (0lu)
#define M3PWM_TC_STOP_SIGNAL_MODE            (0lu)
#define M3PWM_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define M3PWM_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define M3PWM_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define M3PWM_TC_START_SIGNAL_PRESENT        (0lu)
#define M3PWM_TC_STOP_SIGNAL_PRESENT         (0lu)
#define M3PWM_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define M3PWM_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define M3PWM_PWM_KILL_EVENT                 (0lu)
#define M3PWM_PWM_STOP_EVENT                 (0lu)
#define M3PWM_PWM_MODE                       (4lu)
#define M3PWM_PWM_OUT_N_INVERT               (0lu)
#define M3PWM_PWM_OUT_INVERT                 (0lu)
#define M3PWM_PWM_ALIGN                      (0lu)
#define M3PWM_PWM_RUN_MODE                   (0lu)
#define M3PWM_PWM_DEAD_TIME_CYCLE            (0lu)
#define M3PWM_PWM_PRESCALER                  (7lu)

/* Signal modes */
#define M3PWM_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define M3PWM_PWM_COUNT_SIGNAL_MODE          (3lu)
#define M3PWM_PWM_START_SIGNAL_MODE          (0lu)
#define M3PWM_PWM_STOP_SIGNAL_MODE           (0lu)
#define M3PWM_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define M3PWM_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define M3PWM_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define M3PWM_PWM_START_SIGNAL_PRESENT       (0lu)
#define M3PWM_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define M3PWM_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define M3PWM_PWM_INTERRUPT_MASK             (0lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define M3PWM_TC_PERIOD_VALUE                (65535lu)
#define M3PWM_TC_COMPARE_VALUE               (65535lu)
#define M3PWM_TC_COMPARE_BUF_VALUE           (65535lu)
#define M3PWM_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define M3PWM_PWM_PERIOD_VALUE               (65535lu)
#define M3PWM_PWM_PERIOD_BUF_VALUE           (65535lu)
#define M3PWM_PWM_PERIOD_SWAP                (0lu)
#define M3PWM_PWM_COMPARE_VALUE              (65535lu)
#define M3PWM_PWM_COMPARE_BUF_VALUE          (65535lu)
#define M3PWM_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define M3PWM__LEFT 0
#define M3PWM__RIGHT 1
#define M3PWM__CENTER 2
#define M3PWM__ASYMMETRIC 3

#define M3PWM__X1 0
#define M3PWM__X2 1
#define M3PWM__X4 2

#define M3PWM__PWM 4
#define M3PWM__PWM_DT 5
#define M3PWM__PWM_PR 6

#define M3PWM__INVERSE 1
#define M3PWM__DIRECT 0

#define M3PWM__CAPTURE 2
#define M3PWM__COMPARE 0

#define M3PWM__TRIG_LEVEL 3
#define M3PWM__TRIG_RISING 0
#define M3PWM__TRIG_FALLING 1
#define M3PWM__TRIG_BOTH 2

#define M3PWM__INTR_MASK_TC 1
#define M3PWM__INTR_MASK_CC_MATCH 2
#define M3PWM__INTR_MASK_NONE 0
#define M3PWM__INTR_MASK_TC_CC 3

#define M3PWM__UNCONFIG 8
#define M3PWM__TIMER 1
#define M3PWM__QUAD 3
#define M3PWM__PWM_SEL 7

#define M3PWM__COUNT_UP 0
#define M3PWM__COUNT_DOWN 1
#define M3PWM__COUNT_UPDOWN0 2
#define M3PWM__COUNT_UPDOWN1 3


/* Prescaler */
#define M3PWM_PRESCALE_DIVBY1                ((uint32)(0u << M3PWM_PRESCALER_SHIFT))
#define M3PWM_PRESCALE_DIVBY2                ((uint32)(1u << M3PWM_PRESCALER_SHIFT))
#define M3PWM_PRESCALE_DIVBY4                ((uint32)(2u << M3PWM_PRESCALER_SHIFT))
#define M3PWM_PRESCALE_DIVBY8                ((uint32)(3u << M3PWM_PRESCALER_SHIFT))
#define M3PWM_PRESCALE_DIVBY16               ((uint32)(4u << M3PWM_PRESCALER_SHIFT))
#define M3PWM_PRESCALE_DIVBY32               ((uint32)(5u << M3PWM_PRESCALER_SHIFT))
#define M3PWM_PRESCALE_DIVBY64               ((uint32)(6u << M3PWM_PRESCALER_SHIFT))
#define M3PWM_PRESCALE_DIVBY128              ((uint32)(7u << M3PWM_PRESCALER_SHIFT))

/* TCPWM set modes */
#define M3PWM_MODE_TIMER_COMPARE             ((uint32)(M3PWM__COMPARE         <<  \
                                                                  M3PWM_MODE_SHIFT))
#define M3PWM_MODE_TIMER_CAPTURE             ((uint32)(M3PWM__CAPTURE         <<  \
                                                                  M3PWM_MODE_SHIFT))
#define M3PWM_MODE_QUAD                      ((uint32)(M3PWM__QUAD            <<  \
                                                                  M3PWM_MODE_SHIFT))
#define M3PWM_MODE_PWM                       ((uint32)(M3PWM__PWM             <<  \
                                                                  M3PWM_MODE_SHIFT))
#define M3PWM_MODE_PWM_DT                    ((uint32)(M3PWM__PWM_DT          <<  \
                                                                  M3PWM_MODE_SHIFT))
#define M3PWM_MODE_PWM_PR                    ((uint32)(M3PWM__PWM_PR          <<  \
                                                                  M3PWM_MODE_SHIFT))

/* Quad Modes */
#define M3PWM_MODE_X1                        ((uint32)(M3PWM__X1              <<  \
                                                                  M3PWM_QUAD_MODE_SHIFT))
#define M3PWM_MODE_X2                        ((uint32)(M3PWM__X2              <<  \
                                                                  M3PWM_QUAD_MODE_SHIFT))
#define M3PWM_MODE_X4                        ((uint32)(M3PWM__X4              <<  \
                                                                  M3PWM_QUAD_MODE_SHIFT))

/* Counter modes */
#define M3PWM_COUNT_UP                       ((uint32)(M3PWM__COUNT_UP        <<  \
                                                                  M3PWM_UPDOWN_SHIFT))
#define M3PWM_COUNT_DOWN                     ((uint32)(M3PWM__COUNT_DOWN      <<  \
                                                                  M3PWM_UPDOWN_SHIFT))
#define M3PWM_COUNT_UPDOWN0                  ((uint32)(M3PWM__COUNT_UPDOWN0   <<  \
                                                                  M3PWM_UPDOWN_SHIFT))
#define M3PWM_COUNT_UPDOWN1                  ((uint32)(M3PWM__COUNT_UPDOWN1   <<  \
                                                                  M3PWM_UPDOWN_SHIFT))

/* PWM output invert */
#define M3PWM_INVERT_LINE                    ((uint32)(M3PWM__INVERSE         <<  \
                                                                  M3PWM_INV_OUT_SHIFT))
#define M3PWM_INVERT_LINE_N                  ((uint32)(M3PWM__INVERSE         <<  \
                                                                  M3PWM_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define M3PWM_TRIG_RISING                    ((uint32)M3PWM__TRIG_RISING)
#define M3PWM_TRIG_FALLING                   ((uint32)M3PWM__TRIG_FALLING)
#define M3PWM_TRIG_BOTH                      ((uint32)M3PWM__TRIG_BOTH)
#define M3PWM_TRIG_LEVEL                     ((uint32)M3PWM__TRIG_LEVEL)

/* Interrupt mask */
#define M3PWM_INTR_MASK_TC                   ((uint32)M3PWM__INTR_MASK_TC)
#define M3PWM_INTR_MASK_CC_MATCH             ((uint32)M3PWM__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define M3PWM_CC_MATCH_SET                   (0x00u)
#define M3PWM_CC_MATCH_CLEAR                 (0x01u)
#define M3PWM_CC_MATCH_INVERT                (0x02u)
#define M3PWM_CC_MATCH_NO_CHANGE             (0x03u)
#define M3PWM_OVERLOW_SET                    (0x00u)
#define M3PWM_OVERLOW_CLEAR                  (0x04u)
#define M3PWM_OVERLOW_INVERT                 (0x08u)
#define M3PWM_OVERLOW_NO_CHANGE              (0x0Cu)
#define M3PWM_UNDERFLOW_SET                  (0x00u)
#define M3PWM_UNDERFLOW_CLEAR                (0x10u)
#define M3PWM_UNDERFLOW_INVERT               (0x20u)
#define M3PWM_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define M3PWM_PWM_MODE_LEFT                  (M3PWM_CC_MATCH_CLEAR        |   \
                                                         M3PWM_OVERLOW_SET           |   \
                                                         M3PWM_UNDERFLOW_NO_CHANGE)
#define M3PWM_PWM_MODE_RIGHT                 (M3PWM_CC_MATCH_SET          |   \
                                                         M3PWM_OVERLOW_NO_CHANGE     |   \
                                                         M3PWM_UNDERFLOW_CLEAR)
#define M3PWM_PWM_MODE_ASYM                  (M3PWM_CC_MATCH_INVERT       |   \
                                                         M3PWM_OVERLOW_SET           |   \
                                                         M3PWM_UNDERFLOW_CLEAR)

#if (M3PWM_CY_TCPWM_V2)
    #if(M3PWM_CY_TCPWM_4000)
        #define M3PWM_PWM_MODE_CENTER                (M3PWM_CC_MATCH_INVERT       |   \
                                                                 M3PWM_OVERLOW_NO_CHANGE     |   \
                                                                 M3PWM_UNDERFLOW_CLEAR)
    #else
        #define M3PWM_PWM_MODE_CENTER                (M3PWM_CC_MATCH_INVERT       |   \
                                                                 M3PWM_OVERLOW_SET           |   \
                                                                 M3PWM_UNDERFLOW_CLEAR)
    #endif /* (M3PWM_CY_TCPWM_4000) */
#else
    #define M3PWM_PWM_MODE_CENTER                (M3PWM_CC_MATCH_INVERT       |   \
                                                             M3PWM_OVERLOW_NO_CHANGE     |   \
                                                             M3PWM_UNDERFLOW_CLEAR)
#endif /* (M3PWM_CY_TCPWM_NEW) */

/* Command operations without condition */
#define M3PWM_CMD_CAPTURE                    (0u)
#define M3PWM_CMD_RELOAD                     (8u)
#define M3PWM_CMD_STOP                       (16u)
#define M3PWM_CMD_START                      (24u)

/* Status */
#define M3PWM_STATUS_DOWN                    (1u)
#define M3PWM_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   M3PWM_Init(void);
void   M3PWM_Enable(void);
void   M3PWM_Start(void);
void   M3PWM_Stop(void);

void   M3PWM_SetMode(uint32 mode);
void   M3PWM_SetCounterMode(uint32 counterMode);
void   M3PWM_SetPWMMode(uint32 modeMask);
void   M3PWM_SetQDMode(uint32 qdMode);

void   M3PWM_SetPrescaler(uint32 prescaler);
void   M3PWM_TriggerCommand(uint32 mask, uint32 command);
void   M3PWM_SetOneShot(uint32 oneShotEnable);
uint32 M3PWM_ReadStatus(void);

void   M3PWM_SetPWMSyncKill(uint32 syncKillEnable);
void   M3PWM_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   M3PWM_SetPWMDeadTime(uint32 deadTime);
void   M3PWM_SetPWMInvert(uint32 mask);

void   M3PWM_SetInterruptMode(uint32 interruptMask);
uint32 M3PWM_GetInterruptSourceMasked(void);
uint32 M3PWM_GetInterruptSource(void);
void   M3PWM_ClearInterrupt(uint32 interruptMask);
void   M3PWM_SetInterrupt(uint32 interruptMask);

void   M3PWM_WriteCounter(uint32 count);
uint32 M3PWM_ReadCounter(void);

uint32 M3PWM_ReadCapture(void);
uint32 M3PWM_ReadCaptureBuf(void);

void   M3PWM_WritePeriod(uint32 period);
uint32 M3PWM_ReadPeriod(void);
void   M3PWM_WritePeriodBuf(uint32 periodBuf);
uint32 M3PWM_ReadPeriodBuf(void);

void   M3PWM_WriteCompare(uint32 compare);
uint32 M3PWM_ReadCompare(void);
void   M3PWM_WriteCompareBuf(uint32 compareBuf);
uint32 M3PWM_ReadCompareBuf(void);

void   M3PWM_SetPeriodSwap(uint32 swapEnable);
void   M3PWM_SetCompareSwap(uint32 swapEnable);

void   M3PWM_SetCaptureMode(uint32 triggerMode);
void   M3PWM_SetReloadMode(uint32 triggerMode);
void   M3PWM_SetStartMode(uint32 triggerMode);
void   M3PWM_SetStopMode(uint32 triggerMode);
void   M3PWM_SetCountMode(uint32 triggerMode);

void   M3PWM_SaveConfig(void);
void   M3PWM_RestoreConfig(void);
void   M3PWM_Sleep(void);
void   M3PWM_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define M3PWM_BLOCK_CONTROL_REG              (*(reg32 *) M3PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define M3PWM_BLOCK_CONTROL_PTR              ( (reg32 *) M3PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define M3PWM_COMMAND_REG                    (*(reg32 *) M3PWM_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define M3PWM_COMMAND_PTR                    ( (reg32 *) M3PWM_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define M3PWM_INTRRUPT_CAUSE_REG             (*(reg32 *) M3PWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define M3PWM_INTRRUPT_CAUSE_PTR             ( (reg32 *) M3PWM_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define M3PWM_CONTROL_REG                    (*(reg32 *) M3PWM_cy_m0s8_tcpwm_1__CTRL )
#define M3PWM_CONTROL_PTR                    ( (reg32 *) M3PWM_cy_m0s8_tcpwm_1__CTRL )
#define M3PWM_STATUS_REG                     (*(reg32 *) M3PWM_cy_m0s8_tcpwm_1__STATUS )
#define M3PWM_STATUS_PTR                     ( (reg32 *) M3PWM_cy_m0s8_tcpwm_1__STATUS )
#define M3PWM_COUNTER_REG                    (*(reg32 *) M3PWM_cy_m0s8_tcpwm_1__COUNTER )
#define M3PWM_COUNTER_PTR                    ( (reg32 *) M3PWM_cy_m0s8_tcpwm_1__COUNTER )
#define M3PWM_COMP_CAP_REG                   (*(reg32 *) M3PWM_cy_m0s8_tcpwm_1__CC )
#define M3PWM_COMP_CAP_PTR                   ( (reg32 *) M3PWM_cy_m0s8_tcpwm_1__CC )
#define M3PWM_COMP_CAP_BUF_REG               (*(reg32 *) M3PWM_cy_m0s8_tcpwm_1__CC_BUFF )
#define M3PWM_COMP_CAP_BUF_PTR               ( (reg32 *) M3PWM_cy_m0s8_tcpwm_1__CC_BUFF )
#define M3PWM_PERIOD_REG                     (*(reg32 *) M3PWM_cy_m0s8_tcpwm_1__PERIOD )
#define M3PWM_PERIOD_PTR                     ( (reg32 *) M3PWM_cy_m0s8_tcpwm_1__PERIOD )
#define M3PWM_PERIOD_BUF_REG                 (*(reg32 *) M3PWM_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define M3PWM_PERIOD_BUF_PTR                 ( (reg32 *) M3PWM_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define M3PWM_TRIG_CONTROL0_REG              (*(reg32 *) M3PWM_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define M3PWM_TRIG_CONTROL0_PTR              ( (reg32 *) M3PWM_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define M3PWM_TRIG_CONTROL1_REG              (*(reg32 *) M3PWM_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define M3PWM_TRIG_CONTROL1_PTR              ( (reg32 *) M3PWM_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define M3PWM_TRIG_CONTROL2_REG              (*(reg32 *) M3PWM_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define M3PWM_TRIG_CONTROL2_PTR              ( (reg32 *) M3PWM_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define M3PWM_INTERRUPT_REQ_REG              (*(reg32 *) M3PWM_cy_m0s8_tcpwm_1__INTR )
#define M3PWM_INTERRUPT_REQ_PTR              ( (reg32 *) M3PWM_cy_m0s8_tcpwm_1__INTR )
#define M3PWM_INTERRUPT_SET_REG              (*(reg32 *) M3PWM_cy_m0s8_tcpwm_1__INTR_SET )
#define M3PWM_INTERRUPT_SET_PTR              ( (reg32 *) M3PWM_cy_m0s8_tcpwm_1__INTR_SET )
#define M3PWM_INTERRUPT_MASK_REG             (*(reg32 *) M3PWM_cy_m0s8_tcpwm_1__INTR_MASK )
#define M3PWM_INTERRUPT_MASK_PTR             ( (reg32 *) M3PWM_cy_m0s8_tcpwm_1__INTR_MASK )
#define M3PWM_INTERRUPT_MASKED_REG           (*(reg32 *) M3PWM_cy_m0s8_tcpwm_1__INTR_MASKED )
#define M3PWM_INTERRUPT_MASKED_PTR           ( (reg32 *) M3PWM_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define M3PWM_MASK                           ((uint32)M3PWM_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define M3PWM_RELOAD_CC_SHIFT                (0u)
#define M3PWM_RELOAD_PERIOD_SHIFT            (1u)
#define M3PWM_PWM_SYNC_KILL_SHIFT            (2u)
#define M3PWM_PWM_STOP_KILL_SHIFT            (3u)
#define M3PWM_PRESCALER_SHIFT                (8u)
#define M3PWM_UPDOWN_SHIFT                   (16u)
#define M3PWM_ONESHOT_SHIFT                  (18u)
#define M3PWM_QUAD_MODE_SHIFT                (20u)
#define M3PWM_INV_OUT_SHIFT                  (20u)
#define M3PWM_INV_COMPL_OUT_SHIFT            (21u)
#define M3PWM_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define M3PWM_RELOAD_CC_MASK                 ((uint32)(M3PWM_1BIT_MASK        <<  \
                                                                            M3PWM_RELOAD_CC_SHIFT))
#define M3PWM_RELOAD_PERIOD_MASK             ((uint32)(M3PWM_1BIT_MASK        <<  \
                                                                            M3PWM_RELOAD_PERIOD_SHIFT))
#define M3PWM_PWM_SYNC_KILL_MASK             ((uint32)(M3PWM_1BIT_MASK        <<  \
                                                                            M3PWM_PWM_SYNC_KILL_SHIFT))
#define M3PWM_PWM_STOP_KILL_MASK             ((uint32)(M3PWM_1BIT_MASK        <<  \
                                                                            M3PWM_PWM_STOP_KILL_SHIFT))
#define M3PWM_PRESCALER_MASK                 ((uint32)(M3PWM_8BIT_MASK        <<  \
                                                                            M3PWM_PRESCALER_SHIFT))
#define M3PWM_UPDOWN_MASK                    ((uint32)(M3PWM_2BIT_MASK        <<  \
                                                                            M3PWM_UPDOWN_SHIFT))
#define M3PWM_ONESHOT_MASK                   ((uint32)(M3PWM_1BIT_MASK        <<  \
                                                                            M3PWM_ONESHOT_SHIFT))
#define M3PWM_QUAD_MODE_MASK                 ((uint32)(M3PWM_3BIT_MASK        <<  \
                                                                            M3PWM_QUAD_MODE_SHIFT))
#define M3PWM_INV_OUT_MASK                   ((uint32)(M3PWM_2BIT_MASK        <<  \
                                                                            M3PWM_INV_OUT_SHIFT))
#define M3PWM_MODE_MASK                      ((uint32)(M3PWM_3BIT_MASK        <<  \
                                                                            M3PWM_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define M3PWM_CAPTURE_SHIFT                  (0u)
#define M3PWM_COUNT_SHIFT                    (2u)
#define M3PWM_RELOAD_SHIFT                   (4u)
#define M3PWM_STOP_SHIFT                     (6u)
#define M3PWM_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define M3PWM_CAPTURE_MASK                   ((uint32)(M3PWM_2BIT_MASK        <<  \
                                                                  M3PWM_CAPTURE_SHIFT))
#define M3PWM_COUNT_MASK                     ((uint32)(M3PWM_2BIT_MASK        <<  \
                                                                  M3PWM_COUNT_SHIFT))
#define M3PWM_RELOAD_MASK                    ((uint32)(M3PWM_2BIT_MASK        <<  \
                                                                  M3PWM_RELOAD_SHIFT))
#define M3PWM_STOP_MASK                      ((uint32)(M3PWM_2BIT_MASK        <<  \
                                                                  M3PWM_STOP_SHIFT))
#define M3PWM_START_MASK                     ((uint32)(M3PWM_2BIT_MASK        <<  \
                                                                  M3PWM_START_SHIFT))

/* MASK */
#define M3PWM_1BIT_MASK                      ((uint32)0x01u)
#define M3PWM_2BIT_MASK                      ((uint32)0x03u)
#define M3PWM_3BIT_MASK                      ((uint32)0x07u)
#define M3PWM_6BIT_MASK                      ((uint32)0x3Fu)
#define M3PWM_8BIT_MASK                      ((uint32)0xFFu)
#define M3PWM_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define M3PWM_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define M3PWM_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(M3PWM_QUAD_ENCODING_MODES     << M3PWM_QUAD_MODE_SHIFT))       |\
         ((uint32)(M3PWM_CONFIG                  << M3PWM_MODE_SHIFT)))

#define M3PWM_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(M3PWM_PWM_STOP_EVENT          << M3PWM_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(M3PWM_PWM_OUT_INVERT          << M3PWM_INV_OUT_SHIFT))         |\
         ((uint32)(M3PWM_PWM_OUT_N_INVERT        << M3PWM_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(M3PWM_PWM_MODE                << M3PWM_MODE_SHIFT)))

#define M3PWM_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(M3PWM_PWM_RUN_MODE         << M3PWM_ONESHOT_SHIFT))
            
#define M3PWM_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(M3PWM_PWM_ALIGN            << M3PWM_UPDOWN_SHIFT))

#define M3PWM_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(M3PWM_PWM_KILL_EVENT      << M3PWM_PWM_SYNC_KILL_SHIFT))

#define M3PWM_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(M3PWM_PWM_DEAD_TIME_CYCLE  << M3PWM_PRESCALER_SHIFT))

#define M3PWM_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(M3PWM_PWM_PRESCALER        << M3PWM_PRESCALER_SHIFT))

#define M3PWM_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(M3PWM_TC_PRESCALER            << M3PWM_PRESCALER_SHIFT))       |\
         ((uint32)(M3PWM_TC_COUNTER_MODE         << M3PWM_UPDOWN_SHIFT))          |\
         ((uint32)(M3PWM_TC_RUN_MODE             << M3PWM_ONESHOT_SHIFT))         |\
         ((uint32)(M3PWM_TC_COMP_CAP_MODE        << M3PWM_MODE_SHIFT)))
        
#define M3PWM_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(M3PWM_QUAD_PHIA_SIGNAL_MODE   << M3PWM_COUNT_SHIFT))           |\
         ((uint32)(M3PWM_QUAD_INDEX_SIGNAL_MODE  << M3PWM_RELOAD_SHIFT))          |\
         ((uint32)(M3PWM_QUAD_STOP_SIGNAL_MODE   << M3PWM_STOP_SHIFT))            |\
         ((uint32)(M3PWM_QUAD_PHIB_SIGNAL_MODE   << M3PWM_START_SHIFT)))

#define M3PWM_PWM_SIGNALS_MODES                                                              \
        (((uint32)(M3PWM_PWM_SWITCH_SIGNAL_MODE  << M3PWM_CAPTURE_SHIFT))         |\
         ((uint32)(M3PWM_PWM_COUNT_SIGNAL_MODE   << M3PWM_COUNT_SHIFT))           |\
         ((uint32)(M3PWM_PWM_RELOAD_SIGNAL_MODE  << M3PWM_RELOAD_SHIFT))          |\
         ((uint32)(M3PWM_PWM_STOP_SIGNAL_MODE    << M3PWM_STOP_SHIFT))            |\
         ((uint32)(M3PWM_PWM_START_SIGNAL_MODE   << M3PWM_START_SHIFT)))

#define M3PWM_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(M3PWM_TC_CAPTURE_SIGNAL_MODE  << M3PWM_CAPTURE_SHIFT))         |\
         ((uint32)(M3PWM_TC_COUNT_SIGNAL_MODE    << M3PWM_COUNT_SHIFT))           |\
         ((uint32)(M3PWM_TC_RELOAD_SIGNAL_MODE   << M3PWM_RELOAD_SHIFT))          |\
         ((uint32)(M3PWM_TC_STOP_SIGNAL_MODE     << M3PWM_STOP_SHIFT))            |\
         ((uint32)(M3PWM_TC_START_SIGNAL_MODE    << M3PWM_START_SHIFT)))
        
#define M3PWM_TIMER_UPDOWN_CNT_USED                                                          \
                ((M3PWM__COUNT_UPDOWN0 == M3PWM_TC_COUNTER_MODE)                  ||\
                 (M3PWM__COUNT_UPDOWN1 == M3PWM_TC_COUNTER_MODE))

#define M3PWM_PWM_UPDOWN_CNT_USED                                                            \
                ((M3PWM__CENTER == M3PWM_PWM_ALIGN)                               ||\
                 (M3PWM__ASYMMETRIC == M3PWM_PWM_ALIGN))               
        
#define M3PWM_PWM_PR_INIT_VALUE              (1u)
#define M3PWM_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_M3PWM_H */

/* [] END OF FILE */
