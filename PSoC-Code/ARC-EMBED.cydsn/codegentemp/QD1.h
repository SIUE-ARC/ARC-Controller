/*******************************************************************************
* File Name: QD1.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the QD1
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

#if !defined(CY_TCPWM_QD1_H)
#define CY_TCPWM_QD1_H


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
} QD1_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  QD1_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define QD1_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define QD1_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define QD1_CONFIG                         (3lu)

/* Quad Mode */
/* Parameters */
#define QD1_QUAD_ENCODING_MODES            (2lu)
#define QD1_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define QD1_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define QD1_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define QD1_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define QD1_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define QD1_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define QD1_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define QD1_QUAD_INTERRUPT_MASK            (0lu)

/* Timer/Counter Mode */
/* Parameters */
#define QD1_TC_RUN_MODE                    (0lu)
#define QD1_TC_COUNTER_MODE                (0lu)
#define QD1_TC_COMP_CAP_MODE               (2lu)
#define QD1_TC_PRESCALER                   (0lu)

/* Signal modes */
#define QD1_TC_RELOAD_SIGNAL_MODE          (0lu)
#define QD1_TC_COUNT_SIGNAL_MODE           (3lu)
#define QD1_TC_START_SIGNAL_MODE           (0lu)
#define QD1_TC_STOP_SIGNAL_MODE            (0lu)
#define QD1_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define QD1_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define QD1_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define QD1_TC_START_SIGNAL_PRESENT        (0lu)
#define QD1_TC_STOP_SIGNAL_PRESENT         (0lu)
#define QD1_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define QD1_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define QD1_PWM_KILL_EVENT                 (0lu)
#define QD1_PWM_STOP_EVENT                 (0lu)
#define QD1_PWM_MODE                       (4lu)
#define QD1_PWM_OUT_N_INVERT               (0lu)
#define QD1_PWM_OUT_INVERT                 (0lu)
#define QD1_PWM_ALIGN                      (0lu)
#define QD1_PWM_RUN_MODE                   (0lu)
#define QD1_PWM_DEAD_TIME_CYCLE            (0lu)
#define QD1_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define QD1_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define QD1_PWM_COUNT_SIGNAL_MODE          (3lu)
#define QD1_PWM_START_SIGNAL_MODE          (0lu)
#define QD1_PWM_STOP_SIGNAL_MODE           (0lu)
#define QD1_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define QD1_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define QD1_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define QD1_PWM_START_SIGNAL_PRESENT       (0lu)
#define QD1_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define QD1_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define QD1_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define QD1_TC_PERIOD_VALUE                (65535lu)
#define QD1_TC_COMPARE_VALUE               (65535lu)
#define QD1_TC_COMPARE_BUF_VALUE           (65535lu)
#define QD1_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define QD1_PWM_PERIOD_VALUE               (65535lu)
#define QD1_PWM_PERIOD_BUF_VALUE           (65535lu)
#define QD1_PWM_PERIOD_SWAP                (0lu)
#define QD1_PWM_COMPARE_VALUE              (65535lu)
#define QD1_PWM_COMPARE_BUF_VALUE          (65535lu)
#define QD1_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define QD1__LEFT 0
#define QD1__RIGHT 1
#define QD1__CENTER 2
#define QD1__ASYMMETRIC 3

#define QD1__X1 0
#define QD1__X2 1
#define QD1__X4 2

#define QD1__PWM 4
#define QD1__PWM_DT 5
#define QD1__PWM_PR 6

#define QD1__INVERSE 1
#define QD1__DIRECT 0

#define QD1__CAPTURE 2
#define QD1__COMPARE 0

#define QD1__TRIG_LEVEL 3
#define QD1__TRIG_RISING 0
#define QD1__TRIG_FALLING 1
#define QD1__TRIG_BOTH 2

#define QD1__INTR_MASK_TC 1
#define QD1__INTR_MASK_CC_MATCH 2
#define QD1__INTR_MASK_NONE 0
#define QD1__INTR_MASK_TC_CC 3

#define QD1__UNCONFIG 8
#define QD1__TIMER 1
#define QD1__QUAD 3
#define QD1__PWM_SEL 7

#define QD1__COUNT_UP 0
#define QD1__COUNT_DOWN 1
#define QD1__COUNT_UPDOWN0 2
#define QD1__COUNT_UPDOWN1 3


/* Prescaler */
#define QD1_PRESCALE_DIVBY1                ((uint32)(0u << QD1_PRESCALER_SHIFT))
#define QD1_PRESCALE_DIVBY2                ((uint32)(1u << QD1_PRESCALER_SHIFT))
#define QD1_PRESCALE_DIVBY4                ((uint32)(2u << QD1_PRESCALER_SHIFT))
#define QD1_PRESCALE_DIVBY8                ((uint32)(3u << QD1_PRESCALER_SHIFT))
#define QD1_PRESCALE_DIVBY16               ((uint32)(4u << QD1_PRESCALER_SHIFT))
#define QD1_PRESCALE_DIVBY32               ((uint32)(5u << QD1_PRESCALER_SHIFT))
#define QD1_PRESCALE_DIVBY64               ((uint32)(6u << QD1_PRESCALER_SHIFT))
#define QD1_PRESCALE_DIVBY128              ((uint32)(7u << QD1_PRESCALER_SHIFT))

/* TCPWM set modes */
#define QD1_MODE_TIMER_COMPARE             ((uint32)(QD1__COMPARE         <<  \
                                                                  QD1_MODE_SHIFT))
#define QD1_MODE_TIMER_CAPTURE             ((uint32)(QD1__CAPTURE         <<  \
                                                                  QD1_MODE_SHIFT))
#define QD1_MODE_QUAD                      ((uint32)(QD1__QUAD            <<  \
                                                                  QD1_MODE_SHIFT))
#define QD1_MODE_PWM                       ((uint32)(QD1__PWM             <<  \
                                                                  QD1_MODE_SHIFT))
#define QD1_MODE_PWM_DT                    ((uint32)(QD1__PWM_DT          <<  \
                                                                  QD1_MODE_SHIFT))
#define QD1_MODE_PWM_PR                    ((uint32)(QD1__PWM_PR          <<  \
                                                                  QD1_MODE_SHIFT))

/* Quad Modes */
#define QD1_MODE_X1                        ((uint32)(QD1__X1              <<  \
                                                                  QD1_QUAD_MODE_SHIFT))
#define QD1_MODE_X2                        ((uint32)(QD1__X2              <<  \
                                                                  QD1_QUAD_MODE_SHIFT))
#define QD1_MODE_X4                        ((uint32)(QD1__X4              <<  \
                                                                  QD1_QUAD_MODE_SHIFT))

/* Counter modes */
#define QD1_COUNT_UP                       ((uint32)(QD1__COUNT_UP        <<  \
                                                                  QD1_UPDOWN_SHIFT))
#define QD1_COUNT_DOWN                     ((uint32)(QD1__COUNT_DOWN      <<  \
                                                                  QD1_UPDOWN_SHIFT))
#define QD1_COUNT_UPDOWN0                  ((uint32)(QD1__COUNT_UPDOWN0   <<  \
                                                                  QD1_UPDOWN_SHIFT))
#define QD1_COUNT_UPDOWN1                  ((uint32)(QD1__COUNT_UPDOWN1   <<  \
                                                                  QD1_UPDOWN_SHIFT))

/* PWM output invert */
#define QD1_INVERT_LINE                    ((uint32)(QD1__INVERSE         <<  \
                                                                  QD1_INV_OUT_SHIFT))
#define QD1_INVERT_LINE_N                  ((uint32)(QD1__INVERSE         <<  \
                                                                  QD1_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define QD1_TRIG_RISING                    ((uint32)QD1__TRIG_RISING)
#define QD1_TRIG_FALLING                   ((uint32)QD1__TRIG_FALLING)
#define QD1_TRIG_BOTH                      ((uint32)QD1__TRIG_BOTH)
#define QD1_TRIG_LEVEL                     ((uint32)QD1__TRIG_LEVEL)

/* Interrupt mask */
#define QD1_INTR_MASK_TC                   ((uint32)QD1__INTR_MASK_TC)
#define QD1_INTR_MASK_CC_MATCH             ((uint32)QD1__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define QD1_CC_MATCH_SET                   (0x00u)
#define QD1_CC_MATCH_CLEAR                 (0x01u)
#define QD1_CC_MATCH_INVERT                (0x02u)
#define QD1_CC_MATCH_NO_CHANGE             (0x03u)
#define QD1_OVERLOW_SET                    (0x00u)
#define QD1_OVERLOW_CLEAR                  (0x04u)
#define QD1_OVERLOW_INVERT                 (0x08u)
#define QD1_OVERLOW_NO_CHANGE              (0x0Cu)
#define QD1_UNDERFLOW_SET                  (0x00u)
#define QD1_UNDERFLOW_CLEAR                (0x10u)
#define QD1_UNDERFLOW_INVERT               (0x20u)
#define QD1_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define QD1_PWM_MODE_LEFT                  (QD1_CC_MATCH_CLEAR        |   \
                                                         QD1_OVERLOW_SET           |   \
                                                         QD1_UNDERFLOW_NO_CHANGE)
#define QD1_PWM_MODE_RIGHT                 (QD1_CC_MATCH_SET          |   \
                                                         QD1_OVERLOW_NO_CHANGE     |   \
                                                         QD1_UNDERFLOW_CLEAR)
#define QD1_PWM_MODE_ASYM                  (QD1_CC_MATCH_INVERT       |   \
                                                         QD1_OVERLOW_SET           |   \
                                                         QD1_UNDERFLOW_CLEAR)

#if (QD1_CY_TCPWM_V2)
    #if(QD1_CY_TCPWM_4000)
        #define QD1_PWM_MODE_CENTER                (QD1_CC_MATCH_INVERT       |   \
                                                                 QD1_OVERLOW_NO_CHANGE     |   \
                                                                 QD1_UNDERFLOW_CLEAR)
    #else
        #define QD1_PWM_MODE_CENTER                (QD1_CC_MATCH_INVERT       |   \
                                                                 QD1_OVERLOW_SET           |   \
                                                                 QD1_UNDERFLOW_CLEAR)
    #endif /* (QD1_CY_TCPWM_4000) */
#else
    #define QD1_PWM_MODE_CENTER                (QD1_CC_MATCH_INVERT       |   \
                                                             QD1_OVERLOW_NO_CHANGE     |   \
                                                             QD1_UNDERFLOW_CLEAR)
#endif /* (QD1_CY_TCPWM_NEW) */

/* Command operations without condition */
#define QD1_CMD_CAPTURE                    (0u)
#define QD1_CMD_RELOAD                     (8u)
#define QD1_CMD_STOP                       (16u)
#define QD1_CMD_START                      (24u)

/* Status */
#define QD1_STATUS_DOWN                    (1u)
#define QD1_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   QD1_Init(void);
void   QD1_Enable(void);
void   QD1_Start(void);
void   QD1_Stop(void);

void   QD1_SetMode(uint32 mode);
void   QD1_SetCounterMode(uint32 counterMode);
void   QD1_SetPWMMode(uint32 modeMask);
void   QD1_SetQDMode(uint32 qdMode);

void   QD1_SetPrescaler(uint32 prescaler);
void   QD1_TriggerCommand(uint32 mask, uint32 command);
void   QD1_SetOneShot(uint32 oneShotEnable);
uint32 QD1_ReadStatus(void);

void   QD1_SetPWMSyncKill(uint32 syncKillEnable);
void   QD1_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   QD1_SetPWMDeadTime(uint32 deadTime);
void   QD1_SetPWMInvert(uint32 mask);

void   QD1_SetInterruptMode(uint32 interruptMask);
uint32 QD1_GetInterruptSourceMasked(void);
uint32 QD1_GetInterruptSource(void);
void   QD1_ClearInterrupt(uint32 interruptMask);
void   QD1_SetInterrupt(uint32 interruptMask);

void   QD1_WriteCounter(uint32 count);
uint32 QD1_ReadCounter(void);

uint32 QD1_ReadCapture(void);
uint32 QD1_ReadCaptureBuf(void);

void   QD1_WritePeriod(uint32 period);
uint32 QD1_ReadPeriod(void);
void   QD1_WritePeriodBuf(uint32 periodBuf);
uint32 QD1_ReadPeriodBuf(void);

void   QD1_WriteCompare(uint32 compare);
uint32 QD1_ReadCompare(void);
void   QD1_WriteCompareBuf(uint32 compareBuf);
uint32 QD1_ReadCompareBuf(void);

void   QD1_SetPeriodSwap(uint32 swapEnable);
void   QD1_SetCompareSwap(uint32 swapEnable);

void   QD1_SetCaptureMode(uint32 triggerMode);
void   QD1_SetReloadMode(uint32 triggerMode);
void   QD1_SetStartMode(uint32 triggerMode);
void   QD1_SetStopMode(uint32 triggerMode);
void   QD1_SetCountMode(uint32 triggerMode);

void   QD1_SaveConfig(void);
void   QD1_RestoreConfig(void);
void   QD1_Sleep(void);
void   QD1_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define QD1_BLOCK_CONTROL_REG              (*(reg32 *) QD1_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define QD1_BLOCK_CONTROL_PTR              ( (reg32 *) QD1_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define QD1_COMMAND_REG                    (*(reg32 *) QD1_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define QD1_COMMAND_PTR                    ( (reg32 *) QD1_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define QD1_INTRRUPT_CAUSE_REG             (*(reg32 *) QD1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define QD1_INTRRUPT_CAUSE_PTR             ( (reg32 *) QD1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define QD1_CONTROL_REG                    (*(reg32 *) QD1_cy_m0s8_tcpwm_1__CTRL )
#define QD1_CONTROL_PTR                    ( (reg32 *) QD1_cy_m0s8_tcpwm_1__CTRL )
#define QD1_STATUS_REG                     (*(reg32 *) QD1_cy_m0s8_tcpwm_1__STATUS )
#define QD1_STATUS_PTR                     ( (reg32 *) QD1_cy_m0s8_tcpwm_1__STATUS )
#define QD1_COUNTER_REG                    (*(reg32 *) QD1_cy_m0s8_tcpwm_1__COUNTER )
#define QD1_COUNTER_PTR                    ( (reg32 *) QD1_cy_m0s8_tcpwm_1__COUNTER )
#define QD1_COMP_CAP_REG                   (*(reg32 *) QD1_cy_m0s8_tcpwm_1__CC )
#define QD1_COMP_CAP_PTR                   ( (reg32 *) QD1_cy_m0s8_tcpwm_1__CC )
#define QD1_COMP_CAP_BUF_REG               (*(reg32 *) QD1_cy_m0s8_tcpwm_1__CC_BUFF )
#define QD1_COMP_CAP_BUF_PTR               ( (reg32 *) QD1_cy_m0s8_tcpwm_1__CC_BUFF )
#define QD1_PERIOD_REG                     (*(reg32 *) QD1_cy_m0s8_tcpwm_1__PERIOD )
#define QD1_PERIOD_PTR                     ( (reg32 *) QD1_cy_m0s8_tcpwm_1__PERIOD )
#define QD1_PERIOD_BUF_REG                 (*(reg32 *) QD1_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define QD1_PERIOD_BUF_PTR                 ( (reg32 *) QD1_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define QD1_TRIG_CONTROL0_REG              (*(reg32 *) QD1_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define QD1_TRIG_CONTROL0_PTR              ( (reg32 *) QD1_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define QD1_TRIG_CONTROL1_REG              (*(reg32 *) QD1_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define QD1_TRIG_CONTROL1_PTR              ( (reg32 *) QD1_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define QD1_TRIG_CONTROL2_REG              (*(reg32 *) QD1_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define QD1_TRIG_CONTROL2_PTR              ( (reg32 *) QD1_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define QD1_INTERRUPT_REQ_REG              (*(reg32 *) QD1_cy_m0s8_tcpwm_1__INTR )
#define QD1_INTERRUPT_REQ_PTR              ( (reg32 *) QD1_cy_m0s8_tcpwm_1__INTR )
#define QD1_INTERRUPT_SET_REG              (*(reg32 *) QD1_cy_m0s8_tcpwm_1__INTR_SET )
#define QD1_INTERRUPT_SET_PTR              ( (reg32 *) QD1_cy_m0s8_tcpwm_1__INTR_SET )
#define QD1_INTERRUPT_MASK_REG             (*(reg32 *) QD1_cy_m0s8_tcpwm_1__INTR_MASK )
#define QD1_INTERRUPT_MASK_PTR             ( (reg32 *) QD1_cy_m0s8_tcpwm_1__INTR_MASK )
#define QD1_INTERRUPT_MASKED_REG           (*(reg32 *) QD1_cy_m0s8_tcpwm_1__INTR_MASKED )
#define QD1_INTERRUPT_MASKED_PTR           ( (reg32 *) QD1_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define QD1_MASK                           ((uint32)QD1_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define QD1_RELOAD_CC_SHIFT                (0u)
#define QD1_RELOAD_PERIOD_SHIFT            (1u)
#define QD1_PWM_SYNC_KILL_SHIFT            (2u)
#define QD1_PWM_STOP_KILL_SHIFT            (3u)
#define QD1_PRESCALER_SHIFT                (8u)
#define QD1_UPDOWN_SHIFT                   (16u)
#define QD1_ONESHOT_SHIFT                  (18u)
#define QD1_QUAD_MODE_SHIFT                (20u)
#define QD1_INV_OUT_SHIFT                  (20u)
#define QD1_INV_COMPL_OUT_SHIFT            (21u)
#define QD1_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define QD1_RELOAD_CC_MASK                 ((uint32)(QD1_1BIT_MASK        <<  \
                                                                            QD1_RELOAD_CC_SHIFT))
#define QD1_RELOAD_PERIOD_MASK             ((uint32)(QD1_1BIT_MASK        <<  \
                                                                            QD1_RELOAD_PERIOD_SHIFT))
#define QD1_PWM_SYNC_KILL_MASK             ((uint32)(QD1_1BIT_MASK        <<  \
                                                                            QD1_PWM_SYNC_KILL_SHIFT))
#define QD1_PWM_STOP_KILL_MASK             ((uint32)(QD1_1BIT_MASK        <<  \
                                                                            QD1_PWM_STOP_KILL_SHIFT))
#define QD1_PRESCALER_MASK                 ((uint32)(QD1_8BIT_MASK        <<  \
                                                                            QD1_PRESCALER_SHIFT))
#define QD1_UPDOWN_MASK                    ((uint32)(QD1_2BIT_MASK        <<  \
                                                                            QD1_UPDOWN_SHIFT))
#define QD1_ONESHOT_MASK                   ((uint32)(QD1_1BIT_MASK        <<  \
                                                                            QD1_ONESHOT_SHIFT))
#define QD1_QUAD_MODE_MASK                 ((uint32)(QD1_3BIT_MASK        <<  \
                                                                            QD1_QUAD_MODE_SHIFT))
#define QD1_INV_OUT_MASK                   ((uint32)(QD1_2BIT_MASK        <<  \
                                                                            QD1_INV_OUT_SHIFT))
#define QD1_MODE_MASK                      ((uint32)(QD1_3BIT_MASK        <<  \
                                                                            QD1_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define QD1_CAPTURE_SHIFT                  (0u)
#define QD1_COUNT_SHIFT                    (2u)
#define QD1_RELOAD_SHIFT                   (4u)
#define QD1_STOP_SHIFT                     (6u)
#define QD1_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define QD1_CAPTURE_MASK                   ((uint32)(QD1_2BIT_MASK        <<  \
                                                                  QD1_CAPTURE_SHIFT))
#define QD1_COUNT_MASK                     ((uint32)(QD1_2BIT_MASK        <<  \
                                                                  QD1_COUNT_SHIFT))
#define QD1_RELOAD_MASK                    ((uint32)(QD1_2BIT_MASK        <<  \
                                                                  QD1_RELOAD_SHIFT))
#define QD1_STOP_MASK                      ((uint32)(QD1_2BIT_MASK        <<  \
                                                                  QD1_STOP_SHIFT))
#define QD1_START_MASK                     ((uint32)(QD1_2BIT_MASK        <<  \
                                                                  QD1_START_SHIFT))

/* MASK */
#define QD1_1BIT_MASK                      ((uint32)0x01u)
#define QD1_2BIT_MASK                      ((uint32)0x03u)
#define QD1_3BIT_MASK                      ((uint32)0x07u)
#define QD1_6BIT_MASK                      ((uint32)0x3Fu)
#define QD1_8BIT_MASK                      ((uint32)0xFFu)
#define QD1_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define QD1_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define QD1_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(QD1_QUAD_ENCODING_MODES     << QD1_QUAD_MODE_SHIFT))       |\
         ((uint32)(QD1_CONFIG                  << QD1_MODE_SHIFT)))

#define QD1_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(QD1_PWM_STOP_EVENT          << QD1_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(QD1_PWM_OUT_INVERT          << QD1_INV_OUT_SHIFT))         |\
         ((uint32)(QD1_PWM_OUT_N_INVERT        << QD1_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(QD1_PWM_MODE                << QD1_MODE_SHIFT)))

#define QD1_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(QD1_PWM_RUN_MODE         << QD1_ONESHOT_SHIFT))
            
#define QD1_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(QD1_PWM_ALIGN            << QD1_UPDOWN_SHIFT))

#define QD1_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(QD1_PWM_KILL_EVENT      << QD1_PWM_SYNC_KILL_SHIFT))

#define QD1_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(QD1_PWM_DEAD_TIME_CYCLE  << QD1_PRESCALER_SHIFT))

#define QD1_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(QD1_PWM_PRESCALER        << QD1_PRESCALER_SHIFT))

#define QD1_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(QD1_TC_PRESCALER            << QD1_PRESCALER_SHIFT))       |\
         ((uint32)(QD1_TC_COUNTER_MODE         << QD1_UPDOWN_SHIFT))          |\
         ((uint32)(QD1_TC_RUN_MODE             << QD1_ONESHOT_SHIFT))         |\
         ((uint32)(QD1_TC_COMP_CAP_MODE        << QD1_MODE_SHIFT)))
        
#define QD1_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(QD1_QUAD_PHIA_SIGNAL_MODE   << QD1_COUNT_SHIFT))           |\
         ((uint32)(QD1_QUAD_INDEX_SIGNAL_MODE  << QD1_RELOAD_SHIFT))          |\
         ((uint32)(QD1_QUAD_STOP_SIGNAL_MODE   << QD1_STOP_SHIFT))            |\
         ((uint32)(QD1_QUAD_PHIB_SIGNAL_MODE   << QD1_START_SHIFT)))

#define QD1_PWM_SIGNALS_MODES                                                              \
        (((uint32)(QD1_PWM_SWITCH_SIGNAL_MODE  << QD1_CAPTURE_SHIFT))         |\
         ((uint32)(QD1_PWM_COUNT_SIGNAL_MODE   << QD1_COUNT_SHIFT))           |\
         ((uint32)(QD1_PWM_RELOAD_SIGNAL_MODE  << QD1_RELOAD_SHIFT))          |\
         ((uint32)(QD1_PWM_STOP_SIGNAL_MODE    << QD1_STOP_SHIFT))            |\
         ((uint32)(QD1_PWM_START_SIGNAL_MODE   << QD1_START_SHIFT)))

#define QD1_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(QD1_TC_CAPTURE_SIGNAL_MODE  << QD1_CAPTURE_SHIFT))         |\
         ((uint32)(QD1_TC_COUNT_SIGNAL_MODE    << QD1_COUNT_SHIFT))           |\
         ((uint32)(QD1_TC_RELOAD_SIGNAL_MODE   << QD1_RELOAD_SHIFT))          |\
         ((uint32)(QD1_TC_STOP_SIGNAL_MODE     << QD1_STOP_SHIFT))            |\
         ((uint32)(QD1_TC_START_SIGNAL_MODE    << QD1_START_SHIFT)))
        
#define QD1_TIMER_UPDOWN_CNT_USED                                                          \
                ((QD1__COUNT_UPDOWN0 == QD1_TC_COUNTER_MODE)                  ||\
                 (QD1__COUNT_UPDOWN1 == QD1_TC_COUNTER_MODE))

#define QD1_PWM_UPDOWN_CNT_USED                                                            \
                ((QD1__CENTER == QD1_PWM_ALIGN)                               ||\
                 (QD1__ASYMMETRIC == QD1_PWM_ALIGN))               
        
#define QD1_PWM_PR_INIT_VALUE              (1u)
#define QD1_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_QD1_H */

/* [] END OF FILE */
