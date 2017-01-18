/*******************************************************************************
* File Name: QD0.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the QD0
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

#if !defined(CY_TCPWM_QD0_H)
#define CY_TCPWM_QD0_H


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
} QD0_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  QD0_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define QD0_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define QD0_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define QD0_CONFIG                         (3lu)

/* Quad Mode */
/* Parameters */
#define QD0_QUAD_ENCODING_MODES            (2lu)
#define QD0_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define QD0_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define QD0_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define QD0_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define QD0_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define QD0_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define QD0_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define QD0_QUAD_INTERRUPT_MASK            (0lu)

/* Timer/Counter Mode */
/* Parameters */
#define QD0_TC_RUN_MODE                    (0lu)
#define QD0_TC_COUNTER_MODE                (0lu)
#define QD0_TC_COMP_CAP_MODE               (2lu)
#define QD0_TC_PRESCALER                   (0lu)

/* Signal modes */
#define QD0_TC_RELOAD_SIGNAL_MODE          (0lu)
#define QD0_TC_COUNT_SIGNAL_MODE           (3lu)
#define QD0_TC_START_SIGNAL_MODE           (0lu)
#define QD0_TC_STOP_SIGNAL_MODE            (0lu)
#define QD0_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define QD0_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define QD0_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define QD0_TC_START_SIGNAL_PRESENT        (0lu)
#define QD0_TC_STOP_SIGNAL_PRESENT         (0lu)
#define QD0_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define QD0_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define QD0_PWM_KILL_EVENT                 (0lu)
#define QD0_PWM_STOP_EVENT                 (0lu)
#define QD0_PWM_MODE                       (4lu)
#define QD0_PWM_OUT_N_INVERT               (0lu)
#define QD0_PWM_OUT_INVERT                 (0lu)
#define QD0_PWM_ALIGN                      (0lu)
#define QD0_PWM_RUN_MODE                   (0lu)
#define QD0_PWM_DEAD_TIME_CYCLE            (0lu)
#define QD0_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define QD0_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define QD0_PWM_COUNT_SIGNAL_MODE          (3lu)
#define QD0_PWM_START_SIGNAL_MODE          (0lu)
#define QD0_PWM_STOP_SIGNAL_MODE           (0lu)
#define QD0_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define QD0_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define QD0_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define QD0_PWM_START_SIGNAL_PRESENT       (0lu)
#define QD0_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define QD0_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define QD0_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define QD0_TC_PERIOD_VALUE                (65535lu)
#define QD0_TC_COMPARE_VALUE               (65535lu)
#define QD0_TC_COMPARE_BUF_VALUE           (65535lu)
#define QD0_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define QD0_PWM_PERIOD_VALUE               (65535lu)
#define QD0_PWM_PERIOD_BUF_VALUE           (65535lu)
#define QD0_PWM_PERIOD_SWAP                (0lu)
#define QD0_PWM_COMPARE_VALUE              (65535lu)
#define QD0_PWM_COMPARE_BUF_VALUE          (65535lu)
#define QD0_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define QD0__LEFT 0
#define QD0__RIGHT 1
#define QD0__CENTER 2
#define QD0__ASYMMETRIC 3

#define QD0__X1 0
#define QD0__X2 1
#define QD0__X4 2

#define QD0__PWM 4
#define QD0__PWM_DT 5
#define QD0__PWM_PR 6

#define QD0__INVERSE 1
#define QD0__DIRECT 0

#define QD0__CAPTURE 2
#define QD0__COMPARE 0

#define QD0__TRIG_LEVEL 3
#define QD0__TRIG_RISING 0
#define QD0__TRIG_FALLING 1
#define QD0__TRIG_BOTH 2

#define QD0__INTR_MASK_TC 1
#define QD0__INTR_MASK_CC_MATCH 2
#define QD0__INTR_MASK_NONE 0
#define QD0__INTR_MASK_TC_CC 3

#define QD0__UNCONFIG 8
#define QD0__TIMER 1
#define QD0__QUAD 3
#define QD0__PWM_SEL 7

#define QD0__COUNT_UP 0
#define QD0__COUNT_DOWN 1
#define QD0__COUNT_UPDOWN0 2
#define QD0__COUNT_UPDOWN1 3


/* Prescaler */
#define QD0_PRESCALE_DIVBY1                ((uint32)(0u << QD0_PRESCALER_SHIFT))
#define QD0_PRESCALE_DIVBY2                ((uint32)(1u << QD0_PRESCALER_SHIFT))
#define QD0_PRESCALE_DIVBY4                ((uint32)(2u << QD0_PRESCALER_SHIFT))
#define QD0_PRESCALE_DIVBY8                ((uint32)(3u << QD0_PRESCALER_SHIFT))
#define QD0_PRESCALE_DIVBY16               ((uint32)(4u << QD0_PRESCALER_SHIFT))
#define QD0_PRESCALE_DIVBY32               ((uint32)(5u << QD0_PRESCALER_SHIFT))
#define QD0_PRESCALE_DIVBY64               ((uint32)(6u << QD0_PRESCALER_SHIFT))
#define QD0_PRESCALE_DIVBY128              ((uint32)(7u << QD0_PRESCALER_SHIFT))

/* TCPWM set modes */
#define QD0_MODE_TIMER_COMPARE             ((uint32)(QD0__COMPARE         <<  \
                                                                  QD0_MODE_SHIFT))
#define QD0_MODE_TIMER_CAPTURE             ((uint32)(QD0__CAPTURE         <<  \
                                                                  QD0_MODE_SHIFT))
#define QD0_MODE_QUAD                      ((uint32)(QD0__QUAD            <<  \
                                                                  QD0_MODE_SHIFT))
#define QD0_MODE_PWM                       ((uint32)(QD0__PWM             <<  \
                                                                  QD0_MODE_SHIFT))
#define QD0_MODE_PWM_DT                    ((uint32)(QD0__PWM_DT          <<  \
                                                                  QD0_MODE_SHIFT))
#define QD0_MODE_PWM_PR                    ((uint32)(QD0__PWM_PR          <<  \
                                                                  QD0_MODE_SHIFT))

/* Quad Modes */
#define QD0_MODE_X1                        ((uint32)(QD0__X1              <<  \
                                                                  QD0_QUAD_MODE_SHIFT))
#define QD0_MODE_X2                        ((uint32)(QD0__X2              <<  \
                                                                  QD0_QUAD_MODE_SHIFT))
#define QD0_MODE_X4                        ((uint32)(QD0__X4              <<  \
                                                                  QD0_QUAD_MODE_SHIFT))

/* Counter modes */
#define QD0_COUNT_UP                       ((uint32)(QD0__COUNT_UP        <<  \
                                                                  QD0_UPDOWN_SHIFT))
#define QD0_COUNT_DOWN                     ((uint32)(QD0__COUNT_DOWN      <<  \
                                                                  QD0_UPDOWN_SHIFT))
#define QD0_COUNT_UPDOWN0                  ((uint32)(QD0__COUNT_UPDOWN0   <<  \
                                                                  QD0_UPDOWN_SHIFT))
#define QD0_COUNT_UPDOWN1                  ((uint32)(QD0__COUNT_UPDOWN1   <<  \
                                                                  QD0_UPDOWN_SHIFT))

/* PWM output invert */
#define QD0_INVERT_LINE                    ((uint32)(QD0__INVERSE         <<  \
                                                                  QD0_INV_OUT_SHIFT))
#define QD0_INVERT_LINE_N                  ((uint32)(QD0__INVERSE         <<  \
                                                                  QD0_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define QD0_TRIG_RISING                    ((uint32)QD0__TRIG_RISING)
#define QD0_TRIG_FALLING                   ((uint32)QD0__TRIG_FALLING)
#define QD0_TRIG_BOTH                      ((uint32)QD0__TRIG_BOTH)
#define QD0_TRIG_LEVEL                     ((uint32)QD0__TRIG_LEVEL)

/* Interrupt mask */
#define QD0_INTR_MASK_TC                   ((uint32)QD0__INTR_MASK_TC)
#define QD0_INTR_MASK_CC_MATCH             ((uint32)QD0__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define QD0_CC_MATCH_SET                   (0x00u)
#define QD0_CC_MATCH_CLEAR                 (0x01u)
#define QD0_CC_MATCH_INVERT                (0x02u)
#define QD0_CC_MATCH_NO_CHANGE             (0x03u)
#define QD0_OVERLOW_SET                    (0x00u)
#define QD0_OVERLOW_CLEAR                  (0x04u)
#define QD0_OVERLOW_INVERT                 (0x08u)
#define QD0_OVERLOW_NO_CHANGE              (0x0Cu)
#define QD0_UNDERFLOW_SET                  (0x00u)
#define QD0_UNDERFLOW_CLEAR                (0x10u)
#define QD0_UNDERFLOW_INVERT               (0x20u)
#define QD0_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define QD0_PWM_MODE_LEFT                  (QD0_CC_MATCH_CLEAR        |   \
                                                         QD0_OVERLOW_SET           |   \
                                                         QD0_UNDERFLOW_NO_CHANGE)
#define QD0_PWM_MODE_RIGHT                 (QD0_CC_MATCH_SET          |   \
                                                         QD0_OVERLOW_NO_CHANGE     |   \
                                                         QD0_UNDERFLOW_CLEAR)
#define QD0_PWM_MODE_ASYM                  (QD0_CC_MATCH_INVERT       |   \
                                                         QD0_OVERLOW_SET           |   \
                                                         QD0_UNDERFLOW_CLEAR)

#if (QD0_CY_TCPWM_V2)
    #if(QD0_CY_TCPWM_4000)
        #define QD0_PWM_MODE_CENTER                (QD0_CC_MATCH_INVERT       |   \
                                                                 QD0_OVERLOW_NO_CHANGE     |   \
                                                                 QD0_UNDERFLOW_CLEAR)
    #else
        #define QD0_PWM_MODE_CENTER                (QD0_CC_MATCH_INVERT       |   \
                                                                 QD0_OVERLOW_SET           |   \
                                                                 QD0_UNDERFLOW_CLEAR)
    #endif /* (QD0_CY_TCPWM_4000) */
#else
    #define QD0_PWM_MODE_CENTER                (QD0_CC_MATCH_INVERT       |   \
                                                             QD0_OVERLOW_NO_CHANGE     |   \
                                                             QD0_UNDERFLOW_CLEAR)
#endif /* (QD0_CY_TCPWM_NEW) */

/* Command operations without condition */
#define QD0_CMD_CAPTURE                    (0u)
#define QD0_CMD_RELOAD                     (8u)
#define QD0_CMD_STOP                       (16u)
#define QD0_CMD_START                      (24u)

/* Status */
#define QD0_STATUS_DOWN                    (1u)
#define QD0_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   QD0_Init(void);
void   QD0_Enable(void);
void   QD0_Start(void);
void   QD0_Stop(void);

void   QD0_SetMode(uint32 mode);
void   QD0_SetCounterMode(uint32 counterMode);
void   QD0_SetPWMMode(uint32 modeMask);
void   QD0_SetQDMode(uint32 qdMode);

void   QD0_SetPrescaler(uint32 prescaler);
void   QD0_TriggerCommand(uint32 mask, uint32 command);
void   QD0_SetOneShot(uint32 oneShotEnable);
uint32 QD0_ReadStatus(void);

void   QD0_SetPWMSyncKill(uint32 syncKillEnable);
void   QD0_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   QD0_SetPWMDeadTime(uint32 deadTime);
void   QD0_SetPWMInvert(uint32 mask);

void   QD0_SetInterruptMode(uint32 interruptMask);
uint32 QD0_GetInterruptSourceMasked(void);
uint32 QD0_GetInterruptSource(void);
void   QD0_ClearInterrupt(uint32 interruptMask);
void   QD0_SetInterrupt(uint32 interruptMask);

void   QD0_WriteCounter(uint32 count);
uint32 QD0_ReadCounter(void);

uint32 QD0_ReadCapture(void);
uint32 QD0_ReadCaptureBuf(void);

void   QD0_WritePeriod(uint32 period);
uint32 QD0_ReadPeriod(void);
void   QD0_WritePeriodBuf(uint32 periodBuf);
uint32 QD0_ReadPeriodBuf(void);

void   QD0_WriteCompare(uint32 compare);
uint32 QD0_ReadCompare(void);
void   QD0_WriteCompareBuf(uint32 compareBuf);
uint32 QD0_ReadCompareBuf(void);

void   QD0_SetPeriodSwap(uint32 swapEnable);
void   QD0_SetCompareSwap(uint32 swapEnable);

void   QD0_SetCaptureMode(uint32 triggerMode);
void   QD0_SetReloadMode(uint32 triggerMode);
void   QD0_SetStartMode(uint32 triggerMode);
void   QD0_SetStopMode(uint32 triggerMode);
void   QD0_SetCountMode(uint32 triggerMode);

void   QD0_SaveConfig(void);
void   QD0_RestoreConfig(void);
void   QD0_Sleep(void);
void   QD0_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define QD0_BLOCK_CONTROL_REG              (*(reg32 *) QD0_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define QD0_BLOCK_CONTROL_PTR              ( (reg32 *) QD0_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define QD0_COMMAND_REG                    (*(reg32 *) QD0_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define QD0_COMMAND_PTR                    ( (reg32 *) QD0_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define QD0_INTRRUPT_CAUSE_REG             (*(reg32 *) QD0_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define QD0_INTRRUPT_CAUSE_PTR             ( (reg32 *) QD0_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define QD0_CONTROL_REG                    (*(reg32 *) QD0_cy_m0s8_tcpwm_1__CTRL )
#define QD0_CONTROL_PTR                    ( (reg32 *) QD0_cy_m0s8_tcpwm_1__CTRL )
#define QD0_STATUS_REG                     (*(reg32 *) QD0_cy_m0s8_tcpwm_1__STATUS )
#define QD0_STATUS_PTR                     ( (reg32 *) QD0_cy_m0s8_tcpwm_1__STATUS )
#define QD0_COUNTER_REG                    (*(reg32 *) QD0_cy_m0s8_tcpwm_1__COUNTER )
#define QD0_COUNTER_PTR                    ( (reg32 *) QD0_cy_m0s8_tcpwm_1__COUNTER )
#define QD0_COMP_CAP_REG                   (*(reg32 *) QD0_cy_m0s8_tcpwm_1__CC )
#define QD0_COMP_CAP_PTR                   ( (reg32 *) QD0_cy_m0s8_tcpwm_1__CC )
#define QD0_COMP_CAP_BUF_REG               (*(reg32 *) QD0_cy_m0s8_tcpwm_1__CC_BUFF )
#define QD0_COMP_CAP_BUF_PTR               ( (reg32 *) QD0_cy_m0s8_tcpwm_1__CC_BUFF )
#define QD0_PERIOD_REG                     (*(reg32 *) QD0_cy_m0s8_tcpwm_1__PERIOD )
#define QD0_PERIOD_PTR                     ( (reg32 *) QD0_cy_m0s8_tcpwm_1__PERIOD )
#define QD0_PERIOD_BUF_REG                 (*(reg32 *) QD0_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define QD0_PERIOD_BUF_PTR                 ( (reg32 *) QD0_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define QD0_TRIG_CONTROL0_REG              (*(reg32 *) QD0_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define QD0_TRIG_CONTROL0_PTR              ( (reg32 *) QD0_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define QD0_TRIG_CONTROL1_REG              (*(reg32 *) QD0_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define QD0_TRIG_CONTROL1_PTR              ( (reg32 *) QD0_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define QD0_TRIG_CONTROL2_REG              (*(reg32 *) QD0_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define QD0_TRIG_CONTROL2_PTR              ( (reg32 *) QD0_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define QD0_INTERRUPT_REQ_REG              (*(reg32 *) QD0_cy_m0s8_tcpwm_1__INTR )
#define QD0_INTERRUPT_REQ_PTR              ( (reg32 *) QD0_cy_m0s8_tcpwm_1__INTR )
#define QD0_INTERRUPT_SET_REG              (*(reg32 *) QD0_cy_m0s8_tcpwm_1__INTR_SET )
#define QD0_INTERRUPT_SET_PTR              ( (reg32 *) QD0_cy_m0s8_tcpwm_1__INTR_SET )
#define QD0_INTERRUPT_MASK_REG             (*(reg32 *) QD0_cy_m0s8_tcpwm_1__INTR_MASK )
#define QD0_INTERRUPT_MASK_PTR             ( (reg32 *) QD0_cy_m0s8_tcpwm_1__INTR_MASK )
#define QD0_INTERRUPT_MASKED_REG           (*(reg32 *) QD0_cy_m0s8_tcpwm_1__INTR_MASKED )
#define QD0_INTERRUPT_MASKED_PTR           ( (reg32 *) QD0_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define QD0_MASK                           ((uint32)QD0_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define QD0_RELOAD_CC_SHIFT                (0u)
#define QD0_RELOAD_PERIOD_SHIFT            (1u)
#define QD0_PWM_SYNC_KILL_SHIFT            (2u)
#define QD0_PWM_STOP_KILL_SHIFT            (3u)
#define QD0_PRESCALER_SHIFT                (8u)
#define QD0_UPDOWN_SHIFT                   (16u)
#define QD0_ONESHOT_SHIFT                  (18u)
#define QD0_QUAD_MODE_SHIFT                (20u)
#define QD0_INV_OUT_SHIFT                  (20u)
#define QD0_INV_COMPL_OUT_SHIFT            (21u)
#define QD0_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define QD0_RELOAD_CC_MASK                 ((uint32)(QD0_1BIT_MASK        <<  \
                                                                            QD0_RELOAD_CC_SHIFT))
#define QD0_RELOAD_PERIOD_MASK             ((uint32)(QD0_1BIT_MASK        <<  \
                                                                            QD0_RELOAD_PERIOD_SHIFT))
#define QD0_PWM_SYNC_KILL_MASK             ((uint32)(QD0_1BIT_MASK        <<  \
                                                                            QD0_PWM_SYNC_KILL_SHIFT))
#define QD0_PWM_STOP_KILL_MASK             ((uint32)(QD0_1BIT_MASK        <<  \
                                                                            QD0_PWM_STOP_KILL_SHIFT))
#define QD0_PRESCALER_MASK                 ((uint32)(QD0_8BIT_MASK        <<  \
                                                                            QD0_PRESCALER_SHIFT))
#define QD0_UPDOWN_MASK                    ((uint32)(QD0_2BIT_MASK        <<  \
                                                                            QD0_UPDOWN_SHIFT))
#define QD0_ONESHOT_MASK                   ((uint32)(QD0_1BIT_MASK        <<  \
                                                                            QD0_ONESHOT_SHIFT))
#define QD0_QUAD_MODE_MASK                 ((uint32)(QD0_3BIT_MASK        <<  \
                                                                            QD0_QUAD_MODE_SHIFT))
#define QD0_INV_OUT_MASK                   ((uint32)(QD0_2BIT_MASK        <<  \
                                                                            QD0_INV_OUT_SHIFT))
#define QD0_MODE_MASK                      ((uint32)(QD0_3BIT_MASK        <<  \
                                                                            QD0_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define QD0_CAPTURE_SHIFT                  (0u)
#define QD0_COUNT_SHIFT                    (2u)
#define QD0_RELOAD_SHIFT                   (4u)
#define QD0_STOP_SHIFT                     (6u)
#define QD0_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define QD0_CAPTURE_MASK                   ((uint32)(QD0_2BIT_MASK        <<  \
                                                                  QD0_CAPTURE_SHIFT))
#define QD0_COUNT_MASK                     ((uint32)(QD0_2BIT_MASK        <<  \
                                                                  QD0_COUNT_SHIFT))
#define QD0_RELOAD_MASK                    ((uint32)(QD0_2BIT_MASK        <<  \
                                                                  QD0_RELOAD_SHIFT))
#define QD0_STOP_MASK                      ((uint32)(QD0_2BIT_MASK        <<  \
                                                                  QD0_STOP_SHIFT))
#define QD0_START_MASK                     ((uint32)(QD0_2BIT_MASK        <<  \
                                                                  QD0_START_SHIFT))

/* MASK */
#define QD0_1BIT_MASK                      ((uint32)0x01u)
#define QD0_2BIT_MASK                      ((uint32)0x03u)
#define QD0_3BIT_MASK                      ((uint32)0x07u)
#define QD0_6BIT_MASK                      ((uint32)0x3Fu)
#define QD0_8BIT_MASK                      ((uint32)0xFFu)
#define QD0_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define QD0_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define QD0_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(QD0_QUAD_ENCODING_MODES     << QD0_QUAD_MODE_SHIFT))       |\
         ((uint32)(QD0_CONFIG                  << QD0_MODE_SHIFT)))

#define QD0_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(QD0_PWM_STOP_EVENT          << QD0_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(QD0_PWM_OUT_INVERT          << QD0_INV_OUT_SHIFT))         |\
         ((uint32)(QD0_PWM_OUT_N_INVERT        << QD0_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(QD0_PWM_MODE                << QD0_MODE_SHIFT)))

#define QD0_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(QD0_PWM_RUN_MODE         << QD0_ONESHOT_SHIFT))
            
#define QD0_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(QD0_PWM_ALIGN            << QD0_UPDOWN_SHIFT))

#define QD0_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(QD0_PWM_KILL_EVENT      << QD0_PWM_SYNC_KILL_SHIFT))

#define QD0_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(QD0_PWM_DEAD_TIME_CYCLE  << QD0_PRESCALER_SHIFT))

#define QD0_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(QD0_PWM_PRESCALER        << QD0_PRESCALER_SHIFT))

#define QD0_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(QD0_TC_PRESCALER            << QD0_PRESCALER_SHIFT))       |\
         ((uint32)(QD0_TC_COUNTER_MODE         << QD0_UPDOWN_SHIFT))          |\
         ((uint32)(QD0_TC_RUN_MODE             << QD0_ONESHOT_SHIFT))         |\
         ((uint32)(QD0_TC_COMP_CAP_MODE        << QD0_MODE_SHIFT)))
        
#define QD0_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(QD0_QUAD_PHIA_SIGNAL_MODE   << QD0_COUNT_SHIFT))           |\
         ((uint32)(QD0_QUAD_INDEX_SIGNAL_MODE  << QD0_RELOAD_SHIFT))          |\
         ((uint32)(QD0_QUAD_STOP_SIGNAL_MODE   << QD0_STOP_SHIFT))            |\
         ((uint32)(QD0_QUAD_PHIB_SIGNAL_MODE   << QD0_START_SHIFT)))

#define QD0_PWM_SIGNALS_MODES                                                              \
        (((uint32)(QD0_PWM_SWITCH_SIGNAL_MODE  << QD0_CAPTURE_SHIFT))         |\
         ((uint32)(QD0_PWM_COUNT_SIGNAL_MODE   << QD0_COUNT_SHIFT))           |\
         ((uint32)(QD0_PWM_RELOAD_SIGNAL_MODE  << QD0_RELOAD_SHIFT))          |\
         ((uint32)(QD0_PWM_STOP_SIGNAL_MODE    << QD0_STOP_SHIFT))            |\
         ((uint32)(QD0_PWM_START_SIGNAL_MODE   << QD0_START_SHIFT)))

#define QD0_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(QD0_TC_CAPTURE_SIGNAL_MODE  << QD0_CAPTURE_SHIFT))         |\
         ((uint32)(QD0_TC_COUNT_SIGNAL_MODE    << QD0_COUNT_SHIFT))           |\
         ((uint32)(QD0_TC_RELOAD_SIGNAL_MODE   << QD0_RELOAD_SHIFT))          |\
         ((uint32)(QD0_TC_STOP_SIGNAL_MODE     << QD0_STOP_SHIFT))            |\
         ((uint32)(QD0_TC_START_SIGNAL_MODE    << QD0_START_SHIFT)))
        
#define QD0_TIMER_UPDOWN_CNT_USED                                                          \
                ((QD0__COUNT_UPDOWN0 == QD0_TC_COUNTER_MODE)                  ||\
                 (QD0__COUNT_UPDOWN1 == QD0_TC_COUNTER_MODE))

#define QD0_PWM_UPDOWN_CNT_USED                                                            \
                ((QD0__CENTER == QD0_PWM_ALIGN)                               ||\
                 (QD0__ASYMMETRIC == QD0_PWM_ALIGN))               
        
#define QD0_PWM_PR_INIT_VALUE              (1u)
#define QD0_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_QD0_H */

/* [] END OF FILE */
