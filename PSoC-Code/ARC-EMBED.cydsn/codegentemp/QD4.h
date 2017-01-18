/*******************************************************************************
* File Name: QD4.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the QD4
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

#if !defined(CY_TCPWM_QD4_H)
#define CY_TCPWM_QD4_H


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
} QD4_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  QD4_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define QD4_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define QD4_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define QD4_CONFIG                         (3lu)

/* Quad Mode */
/* Parameters */
#define QD4_QUAD_ENCODING_MODES            (2lu)
#define QD4_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define QD4_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define QD4_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define QD4_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define QD4_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define QD4_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define QD4_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define QD4_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define QD4_TC_RUN_MODE                    (0lu)
#define QD4_TC_COUNTER_MODE                (0lu)
#define QD4_TC_COMP_CAP_MODE               (2lu)
#define QD4_TC_PRESCALER                   (0lu)

/* Signal modes */
#define QD4_TC_RELOAD_SIGNAL_MODE          (0lu)
#define QD4_TC_COUNT_SIGNAL_MODE           (3lu)
#define QD4_TC_START_SIGNAL_MODE           (0lu)
#define QD4_TC_STOP_SIGNAL_MODE            (0lu)
#define QD4_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define QD4_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define QD4_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define QD4_TC_START_SIGNAL_PRESENT        (0lu)
#define QD4_TC_STOP_SIGNAL_PRESENT         (0lu)
#define QD4_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define QD4_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define QD4_PWM_KILL_EVENT                 (0lu)
#define QD4_PWM_STOP_EVENT                 (0lu)
#define QD4_PWM_MODE                       (4lu)
#define QD4_PWM_OUT_N_INVERT               (0lu)
#define QD4_PWM_OUT_INVERT                 (0lu)
#define QD4_PWM_ALIGN                      (0lu)
#define QD4_PWM_RUN_MODE                   (0lu)
#define QD4_PWM_DEAD_TIME_CYCLE            (0lu)
#define QD4_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define QD4_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define QD4_PWM_COUNT_SIGNAL_MODE          (3lu)
#define QD4_PWM_START_SIGNAL_MODE          (0lu)
#define QD4_PWM_STOP_SIGNAL_MODE           (0lu)
#define QD4_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define QD4_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define QD4_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define QD4_PWM_START_SIGNAL_PRESENT       (0lu)
#define QD4_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define QD4_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define QD4_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define QD4_TC_PERIOD_VALUE                (65535lu)
#define QD4_TC_COMPARE_VALUE               (65535lu)
#define QD4_TC_COMPARE_BUF_VALUE           (65535lu)
#define QD4_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define QD4_PWM_PERIOD_VALUE               (65535lu)
#define QD4_PWM_PERIOD_BUF_VALUE           (65535lu)
#define QD4_PWM_PERIOD_SWAP                (0lu)
#define QD4_PWM_COMPARE_VALUE              (65535lu)
#define QD4_PWM_COMPARE_BUF_VALUE          (65535lu)
#define QD4_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define QD4__LEFT 0
#define QD4__RIGHT 1
#define QD4__CENTER 2
#define QD4__ASYMMETRIC 3

#define QD4__X1 0
#define QD4__X2 1
#define QD4__X4 2

#define QD4__PWM 4
#define QD4__PWM_DT 5
#define QD4__PWM_PR 6

#define QD4__INVERSE 1
#define QD4__DIRECT 0

#define QD4__CAPTURE 2
#define QD4__COMPARE 0

#define QD4__TRIG_LEVEL 3
#define QD4__TRIG_RISING 0
#define QD4__TRIG_FALLING 1
#define QD4__TRIG_BOTH 2

#define QD4__INTR_MASK_TC 1
#define QD4__INTR_MASK_CC_MATCH 2
#define QD4__INTR_MASK_NONE 0
#define QD4__INTR_MASK_TC_CC 3

#define QD4__UNCONFIG 8
#define QD4__TIMER 1
#define QD4__QUAD 3
#define QD4__PWM_SEL 7

#define QD4__COUNT_UP 0
#define QD4__COUNT_DOWN 1
#define QD4__COUNT_UPDOWN0 2
#define QD4__COUNT_UPDOWN1 3


/* Prescaler */
#define QD4_PRESCALE_DIVBY1                ((uint32)(0u << QD4_PRESCALER_SHIFT))
#define QD4_PRESCALE_DIVBY2                ((uint32)(1u << QD4_PRESCALER_SHIFT))
#define QD4_PRESCALE_DIVBY4                ((uint32)(2u << QD4_PRESCALER_SHIFT))
#define QD4_PRESCALE_DIVBY8                ((uint32)(3u << QD4_PRESCALER_SHIFT))
#define QD4_PRESCALE_DIVBY16               ((uint32)(4u << QD4_PRESCALER_SHIFT))
#define QD4_PRESCALE_DIVBY32               ((uint32)(5u << QD4_PRESCALER_SHIFT))
#define QD4_PRESCALE_DIVBY64               ((uint32)(6u << QD4_PRESCALER_SHIFT))
#define QD4_PRESCALE_DIVBY128              ((uint32)(7u << QD4_PRESCALER_SHIFT))

/* TCPWM set modes */
#define QD4_MODE_TIMER_COMPARE             ((uint32)(QD4__COMPARE         <<  \
                                                                  QD4_MODE_SHIFT))
#define QD4_MODE_TIMER_CAPTURE             ((uint32)(QD4__CAPTURE         <<  \
                                                                  QD4_MODE_SHIFT))
#define QD4_MODE_QUAD                      ((uint32)(QD4__QUAD            <<  \
                                                                  QD4_MODE_SHIFT))
#define QD4_MODE_PWM                       ((uint32)(QD4__PWM             <<  \
                                                                  QD4_MODE_SHIFT))
#define QD4_MODE_PWM_DT                    ((uint32)(QD4__PWM_DT          <<  \
                                                                  QD4_MODE_SHIFT))
#define QD4_MODE_PWM_PR                    ((uint32)(QD4__PWM_PR          <<  \
                                                                  QD4_MODE_SHIFT))

/* Quad Modes */
#define QD4_MODE_X1                        ((uint32)(QD4__X1              <<  \
                                                                  QD4_QUAD_MODE_SHIFT))
#define QD4_MODE_X2                        ((uint32)(QD4__X2              <<  \
                                                                  QD4_QUAD_MODE_SHIFT))
#define QD4_MODE_X4                        ((uint32)(QD4__X4              <<  \
                                                                  QD4_QUAD_MODE_SHIFT))

/* Counter modes */
#define QD4_COUNT_UP                       ((uint32)(QD4__COUNT_UP        <<  \
                                                                  QD4_UPDOWN_SHIFT))
#define QD4_COUNT_DOWN                     ((uint32)(QD4__COUNT_DOWN      <<  \
                                                                  QD4_UPDOWN_SHIFT))
#define QD4_COUNT_UPDOWN0                  ((uint32)(QD4__COUNT_UPDOWN0   <<  \
                                                                  QD4_UPDOWN_SHIFT))
#define QD4_COUNT_UPDOWN1                  ((uint32)(QD4__COUNT_UPDOWN1   <<  \
                                                                  QD4_UPDOWN_SHIFT))

/* PWM output invert */
#define QD4_INVERT_LINE                    ((uint32)(QD4__INVERSE         <<  \
                                                                  QD4_INV_OUT_SHIFT))
#define QD4_INVERT_LINE_N                  ((uint32)(QD4__INVERSE         <<  \
                                                                  QD4_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define QD4_TRIG_RISING                    ((uint32)QD4__TRIG_RISING)
#define QD4_TRIG_FALLING                   ((uint32)QD4__TRIG_FALLING)
#define QD4_TRIG_BOTH                      ((uint32)QD4__TRIG_BOTH)
#define QD4_TRIG_LEVEL                     ((uint32)QD4__TRIG_LEVEL)

/* Interrupt mask */
#define QD4_INTR_MASK_TC                   ((uint32)QD4__INTR_MASK_TC)
#define QD4_INTR_MASK_CC_MATCH             ((uint32)QD4__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define QD4_CC_MATCH_SET                   (0x00u)
#define QD4_CC_MATCH_CLEAR                 (0x01u)
#define QD4_CC_MATCH_INVERT                (0x02u)
#define QD4_CC_MATCH_NO_CHANGE             (0x03u)
#define QD4_OVERLOW_SET                    (0x00u)
#define QD4_OVERLOW_CLEAR                  (0x04u)
#define QD4_OVERLOW_INVERT                 (0x08u)
#define QD4_OVERLOW_NO_CHANGE              (0x0Cu)
#define QD4_UNDERFLOW_SET                  (0x00u)
#define QD4_UNDERFLOW_CLEAR                (0x10u)
#define QD4_UNDERFLOW_INVERT               (0x20u)
#define QD4_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define QD4_PWM_MODE_LEFT                  (QD4_CC_MATCH_CLEAR        |   \
                                                         QD4_OVERLOW_SET           |   \
                                                         QD4_UNDERFLOW_NO_CHANGE)
#define QD4_PWM_MODE_RIGHT                 (QD4_CC_MATCH_SET          |   \
                                                         QD4_OVERLOW_NO_CHANGE     |   \
                                                         QD4_UNDERFLOW_CLEAR)
#define QD4_PWM_MODE_ASYM                  (QD4_CC_MATCH_INVERT       |   \
                                                         QD4_OVERLOW_SET           |   \
                                                         QD4_UNDERFLOW_CLEAR)

#if (QD4_CY_TCPWM_V2)
    #if(QD4_CY_TCPWM_4000)
        #define QD4_PWM_MODE_CENTER                (QD4_CC_MATCH_INVERT       |   \
                                                                 QD4_OVERLOW_NO_CHANGE     |   \
                                                                 QD4_UNDERFLOW_CLEAR)
    #else
        #define QD4_PWM_MODE_CENTER                (QD4_CC_MATCH_INVERT       |   \
                                                                 QD4_OVERLOW_SET           |   \
                                                                 QD4_UNDERFLOW_CLEAR)
    #endif /* (QD4_CY_TCPWM_4000) */
#else
    #define QD4_PWM_MODE_CENTER                (QD4_CC_MATCH_INVERT       |   \
                                                             QD4_OVERLOW_NO_CHANGE     |   \
                                                             QD4_UNDERFLOW_CLEAR)
#endif /* (QD4_CY_TCPWM_NEW) */

/* Command operations without condition */
#define QD4_CMD_CAPTURE                    (0u)
#define QD4_CMD_RELOAD                     (8u)
#define QD4_CMD_STOP                       (16u)
#define QD4_CMD_START                      (24u)

/* Status */
#define QD4_STATUS_DOWN                    (1u)
#define QD4_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   QD4_Init(void);
void   QD4_Enable(void);
void   QD4_Start(void);
void   QD4_Stop(void);

void   QD4_SetMode(uint32 mode);
void   QD4_SetCounterMode(uint32 counterMode);
void   QD4_SetPWMMode(uint32 modeMask);
void   QD4_SetQDMode(uint32 qdMode);

void   QD4_SetPrescaler(uint32 prescaler);
void   QD4_TriggerCommand(uint32 mask, uint32 command);
void   QD4_SetOneShot(uint32 oneShotEnable);
uint32 QD4_ReadStatus(void);

void   QD4_SetPWMSyncKill(uint32 syncKillEnable);
void   QD4_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   QD4_SetPWMDeadTime(uint32 deadTime);
void   QD4_SetPWMInvert(uint32 mask);

void   QD4_SetInterruptMode(uint32 interruptMask);
uint32 QD4_GetInterruptSourceMasked(void);
uint32 QD4_GetInterruptSource(void);
void   QD4_ClearInterrupt(uint32 interruptMask);
void   QD4_SetInterrupt(uint32 interruptMask);

void   QD4_WriteCounter(uint32 count);
uint32 QD4_ReadCounter(void);

uint32 QD4_ReadCapture(void);
uint32 QD4_ReadCaptureBuf(void);

void   QD4_WritePeriod(uint32 period);
uint32 QD4_ReadPeriod(void);
void   QD4_WritePeriodBuf(uint32 periodBuf);
uint32 QD4_ReadPeriodBuf(void);

void   QD4_WriteCompare(uint32 compare);
uint32 QD4_ReadCompare(void);
void   QD4_WriteCompareBuf(uint32 compareBuf);
uint32 QD4_ReadCompareBuf(void);

void   QD4_SetPeriodSwap(uint32 swapEnable);
void   QD4_SetCompareSwap(uint32 swapEnable);

void   QD4_SetCaptureMode(uint32 triggerMode);
void   QD4_SetReloadMode(uint32 triggerMode);
void   QD4_SetStartMode(uint32 triggerMode);
void   QD4_SetStopMode(uint32 triggerMode);
void   QD4_SetCountMode(uint32 triggerMode);

void   QD4_SaveConfig(void);
void   QD4_RestoreConfig(void);
void   QD4_Sleep(void);
void   QD4_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define QD4_BLOCK_CONTROL_REG              (*(reg32 *) QD4_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define QD4_BLOCK_CONTROL_PTR              ( (reg32 *) QD4_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define QD4_COMMAND_REG                    (*(reg32 *) QD4_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define QD4_COMMAND_PTR                    ( (reg32 *) QD4_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define QD4_INTRRUPT_CAUSE_REG             (*(reg32 *) QD4_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define QD4_INTRRUPT_CAUSE_PTR             ( (reg32 *) QD4_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define QD4_CONTROL_REG                    (*(reg32 *) QD4_cy_m0s8_tcpwm_1__CTRL )
#define QD4_CONTROL_PTR                    ( (reg32 *) QD4_cy_m0s8_tcpwm_1__CTRL )
#define QD4_STATUS_REG                     (*(reg32 *) QD4_cy_m0s8_tcpwm_1__STATUS )
#define QD4_STATUS_PTR                     ( (reg32 *) QD4_cy_m0s8_tcpwm_1__STATUS )
#define QD4_COUNTER_REG                    (*(reg32 *) QD4_cy_m0s8_tcpwm_1__COUNTER )
#define QD4_COUNTER_PTR                    ( (reg32 *) QD4_cy_m0s8_tcpwm_1__COUNTER )
#define QD4_COMP_CAP_REG                   (*(reg32 *) QD4_cy_m0s8_tcpwm_1__CC )
#define QD4_COMP_CAP_PTR                   ( (reg32 *) QD4_cy_m0s8_tcpwm_1__CC )
#define QD4_COMP_CAP_BUF_REG               (*(reg32 *) QD4_cy_m0s8_tcpwm_1__CC_BUFF )
#define QD4_COMP_CAP_BUF_PTR               ( (reg32 *) QD4_cy_m0s8_tcpwm_1__CC_BUFF )
#define QD4_PERIOD_REG                     (*(reg32 *) QD4_cy_m0s8_tcpwm_1__PERIOD )
#define QD4_PERIOD_PTR                     ( (reg32 *) QD4_cy_m0s8_tcpwm_1__PERIOD )
#define QD4_PERIOD_BUF_REG                 (*(reg32 *) QD4_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define QD4_PERIOD_BUF_PTR                 ( (reg32 *) QD4_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define QD4_TRIG_CONTROL0_REG              (*(reg32 *) QD4_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define QD4_TRIG_CONTROL0_PTR              ( (reg32 *) QD4_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define QD4_TRIG_CONTROL1_REG              (*(reg32 *) QD4_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define QD4_TRIG_CONTROL1_PTR              ( (reg32 *) QD4_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define QD4_TRIG_CONTROL2_REG              (*(reg32 *) QD4_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define QD4_TRIG_CONTROL2_PTR              ( (reg32 *) QD4_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define QD4_INTERRUPT_REQ_REG              (*(reg32 *) QD4_cy_m0s8_tcpwm_1__INTR )
#define QD4_INTERRUPT_REQ_PTR              ( (reg32 *) QD4_cy_m0s8_tcpwm_1__INTR )
#define QD4_INTERRUPT_SET_REG              (*(reg32 *) QD4_cy_m0s8_tcpwm_1__INTR_SET )
#define QD4_INTERRUPT_SET_PTR              ( (reg32 *) QD4_cy_m0s8_tcpwm_1__INTR_SET )
#define QD4_INTERRUPT_MASK_REG             (*(reg32 *) QD4_cy_m0s8_tcpwm_1__INTR_MASK )
#define QD4_INTERRUPT_MASK_PTR             ( (reg32 *) QD4_cy_m0s8_tcpwm_1__INTR_MASK )
#define QD4_INTERRUPT_MASKED_REG           (*(reg32 *) QD4_cy_m0s8_tcpwm_1__INTR_MASKED )
#define QD4_INTERRUPT_MASKED_PTR           ( (reg32 *) QD4_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define QD4_MASK                           ((uint32)QD4_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define QD4_RELOAD_CC_SHIFT                (0u)
#define QD4_RELOAD_PERIOD_SHIFT            (1u)
#define QD4_PWM_SYNC_KILL_SHIFT            (2u)
#define QD4_PWM_STOP_KILL_SHIFT            (3u)
#define QD4_PRESCALER_SHIFT                (8u)
#define QD4_UPDOWN_SHIFT                   (16u)
#define QD4_ONESHOT_SHIFT                  (18u)
#define QD4_QUAD_MODE_SHIFT                (20u)
#define QD4_INV_OUT_SHIFT                  (20u)
#define QD4_INV_COMPL_OUT_SHIFT            (21u)
#define QD4_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define QD4_RELOAD_CC_MASK                 ((uint32)(QD4_1BIT_MASK        <<  \
                                                                            QD4_RELOAD_CC_SHIFT))
#define QD4_RELOAD_PERIOD_MASK             ((uint32)(QD4_1BIT_MASK        <<  \
                                                                            QD4_RELOAD_PERIOD_SHIFT))
#define QD4_PWM_SYNC_KILL_MASK             ((uint32)(QD4_1BIT_MASK        <<  \
                                                                            QD4_PWM_SYNC_KILL_SHIFT))
#define QD4_PWM_STOP_KILL_MASK             ((uint32)(QD4_1BIT_MASK        <<  \
                                                                            QD4_PWM_STOP_KILL_SHIFT))
#define QD4_PRESCALER_MASK                 ((uint32)(QD4_8BIT_MASK        <<  \
                                                                            QD4_PRESCALER_SHIFT))
#define QD4_UPDOWN_MASK                    ((uint32)(QD4_2BIT_MASK        <<  \
                                                                            QD4_UPDOWN_SHIFT))
#define QD4_ONESHOT_MASK                   ((uint32)(QD4_1BIT_MASK        <<  \
                                                                            QD4_ONESHOT_SHIFT))
#define QD4_QUAD_MODE_MASK                 ((uint32)(QD4_3BIT_MASK        <<  \
                                                                            QD4_QUAD_MODE_SHIFT))
#define QD4_INV_OUT_MASK                   ((uint32)(QD4_2BIT_MASK        <<  \
                                                                            QD4_INV_OUT_SHIFT))
#define QD4_MODE_MASK                      ((uint32)(QD4_3BIT_MASK        <<  \
                                                                            QD4_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define QD4_CAPTURE_SHIFT                  (0u)
#define QD4_COUNT_SHIFT                    (2u)
#define QD4_RELOAD_SHIFT                   (4u)
#define QD4_STOP_SHIFT                     (6u)
#define QD4_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define QD4_CAPTURE_MASK                   ((uint32)(QD4_2BIT_MASK        <<  \
                                                                  QD4_CAPTURE_SHIFT))
#define QD4_COUNT_MASK                     ((uint32)(QD4_2BIT_MASK        <<  \
                                                                  QD4_COUNT_SHIFT))
#define QD4_RELOAD_MASK                    ((uint32)(QD4_2BIT_MASK        <<  \
                                                                  QD4_RELOAD_SHIFT))
#define QD4_STOP_MASK                      ((uint32)(QD4_2BIT_MASK        <<  \
                                                                  QD4_STOP_SHIFT))
#define QD4_START_MASK                     ((uint32)(QD4_2BIT_MASK        <<  \
                                                                  QD4_START_SHIFT))

/* MASK */
#define QD4_1BIT_MASK                      ((uint32)0x01u)
#define QD4_2BIT_MASK                      ((uint32)0x03u)
#define QD4_3BIT_MASK                      ((uint32)0x07u)
#define QD4_6BIT_MASK                      ((uint32)0x3Fu)
#define QD4_8BIT_MASK                      ((uint32)0xFFu)
#define QD4_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define QD4_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define QD4_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(QD4_QUAD_ENCODING_MODES     << QD4_QUAD_MODE_SHIFT))       |\
         ((uint32)(QD4_CONFIG                  << QD4_MODE_SHIFT)))

#define QD4_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(QD4_PWM_STOP_EVENT          << QD4_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(QD4_PWM_OUT_INVERT          << QD4_INV_OUT_SHIFT))         |\
         ((uint32)(QD4_PWM_OUT_N_INVERT        << QD4_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(QD4_PWM_MODE                << QD4_MODE_SHIFT)))

#define QD4_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(QD4_PWM_RUN_MODE         << QD4_ONESHOT_SHIFT))
            
#define QD4_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(QD4_PWM_ALIGN            << QD4_UPDOWN_SHIFT))

#define QD4_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(QD4_PWM_KILL_EVENT      << QD4_PWM_SYNC_KILL_SHIFT))

#define QD4_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(QD4_PWM_DEAD_TIME_CYCLE  << QD4_PRESCALER_SHIFT))

#define QD4_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(QD4_PWM_PRESCALER        << QD4_PRESCALER_SHIFT))

#define QD4_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(QD4_TC_PRESCALER            << QD4_PRESCALER_SHIFT))       |\
         ((uint32)(QD4_TC_COUNTER_MODE         << QD4_UPDOWN_SHIFT))          |\
         ((uint32)(QD4_TC_RUN_MODE             << QD4_ONESHOT_SHIFT))         |\
         ((uint32)(QD4_TC_COMP_CAP_MODE        << QD4_MODE_SHIFT)))
        
#define QD4_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(QD4_QUAD_PHIA_SIGNAL_MODE   << QD4_COUNT_SHIFT))           |\
         ((uint32)(QD4_QUAD_INDEX_SIGNAL_MODE  << QD4_RELOAD_SHIFT))          |\
         ((uint32)(QD4_QUAD_STOP_SIGNAL_MODE   << QD4_STOP_SHIFT))            |\
         ((uint32)(QD4_QUAD_PHIB_SIGNAL_MODE   << QD4_START_SHIFT)))

#define QD4_PWM_SIGNALS_MODES                                                              \
        (((uint32)(QD4_PWM_SWITCH_SIGNAL_MODE  << QD4_CAPTURE_SHIFT))         |\
         ((uint32)(QD4_PWM_COUNT_SIGNAL_MODE   << QD4_COUNT_SHIFT))           |\
         ((uint32)(QD4_PWM_RELOAD_SIGNAL_MODE  << QD4_RELOAD_SHIFT))          |\
         ((uint32)(QD4_PWM_STOP_SIGNAL_MODE    << QD4_STOP_SHIFT))            |\
         ((uint32)(QD4_PWM_START_SIGNAL_MODE   << QD4_START_SHIFT)))

#define QD4_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(QD4_TC_CAPTURE_SIGNAL_MODE  << QD4_CAPTURE_SHIFT))         |\
         ((uint32)(QD4_TC_COUNT_SIGNAL_MODE    << QD4_COUNT_SHIFT))           |\
         ((uint32)(QD4_TC_RELOAD_SIGNAL_MODE   << QD4_RELOAD_SHIFT))          |\
         ((uint32)(QD4_TC_STOP_SIGNAL_MODE     << QD4_STOP_SHIFT))            |\
         ((uint32)(QD4_TC_START_SIGNAL_MODE    << QD4_START_SHIFT)))
        
#define QD4_TIMER_UPDOWN_CNT_USED                                                          \
                ((QD4__COUNT_UPDOWN0 == QD4_TC_COUNTER_MODE)                  ||\
                 (QD4__COUNT_UPDOWN1 == QD4_TC_COUNTER_MODE))

#define QD4_PWM_UPDOWN_CNT_USED                                                            \
                ((QD4__CENTER == QD4_PWM_ALIGN)                               ||\
                 (QD4__ASYMMETRIC == QD4_PWM_ALIGN))               
        
#define QD4_PWM_PR_INIT_VALUE              (1u)
#define QD4_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_QD4_H */

/* [] END OF FILE */
