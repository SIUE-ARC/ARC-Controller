/*******************************************************************************
* File Name: QD2.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the QD2
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

#if !defined(CY_TCPWM_QD2_H)
#define CY_TCPWM_QD2_H


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
} QD2_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  QD2_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define QD2_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define QD2_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define QD2_CONFIG                         (3lu)

/* Quad Mode */
/* Parameters */
#define QD2_QUAD_ENCODING_MODES            (2lu)
#define QD2_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define QD2_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define QD2_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define QD2_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define QD2_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define QD2_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define QD2_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define QD2_QUAD_INTERRUPT_MASK            (0lu)

/* Timer/Counter Mode */
/* Parameters */
#define QD2_TC_RUN_MODE                    (0lu)
#define QD2_TC_COUNTER_MODE                (0lu)
#define QD2_TC_COMP_CAP_MODE               (2lu)
#define QD2_TC_PRESCALER                   (0lu)

/* Signal modes */
#define QD2_TC_RELOAD_SIGNAL_MODE          (0lu)
#define QD2_TC_COUNT_SIGNAL_MODE           (3lu)
#define QD2_TC_START_SIGNAL_MODE           (0lu)
#define QD2_TC_STOP_SIGNAL_MODE            (0lu)
#define QD2_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define QD2_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define QD2_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define QD2_TC_START_SIGNAL_PRESENT        (0lu)
#define QD2_TC_STOP_SIGNAL_PRESENT         (0lu)
#define QD2_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define QD2_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define QD2_PWM_KILL_EVENT                 (0lu)
#define QD2_PWM_STOP_EVENT                 (0lu)
#define QD2_PWM_MODE                       (4lu)
#define QD2_PWM_OUT_N_INVERT               (0lu)
#define QD2_PWM_OUT_INVERT                 (0lu)
#define QD2_PWM_ALIGN                      (0lu)
#define QD2_PWM_RUN_MODE                   (0lu)
#define QD2_PWM_DEAD_TIME_CYCLE            (0lu)
#define QD2_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define QD2_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define QD2_PWM_COUNT_SIGNAL_MODE          (3lu)
#define QD2_PWM_START_SIGNAL_MODE          (0lu)
#define QD2_PWM_STOP_SIGNAL_MODE           (0lu)
#define QD2_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define QD2_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define QD2_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define QD2_PWM_START_SIGNAL_PRESENT       (0lu)
#define QD2_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define QD2_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define QD2_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define QD2_TC_PERIOD_VALUE                (65535lu)
#define QD2_TC_COMPARE_VALUE               (65535lu)
#define QD2_TC_COMPARE_BUF_VALUE           (65535lu)
#define QD2_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define QD2_PWM_PERIOD_VALUE               (65535lu)
#define QD2_PWM_PERIOD_BUF_VALUE           (65535lu)
#define QD2_PWM_PERIOD_SWAP                (0lu)
#define QD2_PWM_COMPARE_VALUE              (65535lu)
#define QD2_PWM_COMPARE_BUF_VALUE          (65535lu)
#define QD2_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define QD2__LEFT 0
#define QD2__RIGHT 1
#define QD2__CENTER 2
#define QD2__ASYMMETRIC 3

#define QD2__X1 0
#define QD2__X2 1
#define QD2__X4 2

#define QD2__PWM 4
#define QD2__PWM_DT 5
#define QD2__PWM_PR 6

#define QD2__INVERSE 1
#define QD2__DIRECT 0

#define QD2__CAPTURE 2
#define QD2__COMPARE 0

#define QD2__TRIG_LEVEL 3
#define QD2__TRIG_RISING 0
#define QD2__TRIG_FALLING 1
#define QD2__TRIG_BOTH 2

#define QD2__INTR_MASK_TC 1
#define QD2__INTR_MASK_CC_MATCH 2
#define QD2__INTR_MASK_NONE 0
#define QD2__INTR_MASK_TC_CC 3

#define QD2__UNCONFIG 8
#define QD2__TIMER 1
#define QD2__QUAD 3
#define QD2__PWM_SEL 7

#define QD2__COUNT_UP 0
#define QD2__COUNT_DOWN 1
#define QD2__COUNT_UPDOWN0 2
#define QD2__COUNT_UPDOWN1 3


/* Prescaler */
#define QD2_PRESCALE_DIVBY1                ((uint32)(0u << QD2_PRESCALER_SHIFT))
#define QD2_PRESCALE_DIVBY2                ((uint32)(1u << QD2_PRESCALER_SHIFT))
#define QD2_PRESCALE_DIVBY4                ((uint32)(2u << QD2_PRESCALER_SHIFT))
#define QD2_PRESCALE_DIVBY8                ((uint32)(3u << QD2_PRESCALER_SHIFT))
#define QD2_PRESCALE_DIVBY16               ((uint32)(4u << QD2_PRESCALER_SHIFT))
#define QD2_PRESCALE_DIVBY32               ((uint32)(5u << QD2_PRESCALER_SHIFT))
#define QD2_PRESCALE_DIVBY64               ((uint32)(6u << QD2_PRESCALER_SHIFT))
#define QD2_PRESCALE_DIVBY128              ((uint32)(7u << QD2_PRESCALER_SHIFT))

/* TCPWM set modes */
#define QD2_MODE_TIMER_COMPARE             ((uint32)(QD2__COMPARE         <<  \
                                                                  QD2_MODE_SHIFT))
#define QD2_MODE_TIMER_CAPTURE             ((uint32)(QD2__CAPTURE         <<  \
                                                                  QD2_MODE_SHIFT))
#define QD2_MODE_QUAD                      ((uint32)(QD2__QUAD            <<  \
                                                                  QD2_MODE_SHIFT))
#define QD2_MODE_PWM                       ((uint32)(QD2__PWM             <<  \
                                                                  QD2_MODE_SHIFT))
#define QD2_MODE_PWM_DT                    ((uint32)(QD2__PWM_DT          <<  \
                                                                  QD2_MODE_SHIFT))
#define QD2_MODE_PWM_PR                    ((uint32)(QD2__PWM_PR          <<  \
                                                                  QD2_MODE_SHIFT))

/* Quad Modes */
#define QD2_MODE_X1                        ((uint32)(QD2__X1              <<  \
                                                                  QD2_QUAD_MODE_SHIFT))
#define QD2_MODE_X2                        ((uint32)(QD2__X2              <<  \
                                                                  QD2_QUAD_MODE_SHIFT))
#define QD2_MODE_X4                        ((uint32)(QD2__X4              <<  \
                                                                  QD2_QUAD_MODE_SHIFT))

/* Counter modes */
#define QD2_COUNT_UP                       ((uint32)(QD2__COUNT_UP        <<  \
                                                                  QD2_UPDOWN_SHIFT))
#define QD2_COUNT_DOWN                     ((uint32)(QD2__COUNT_DOWN      <<  \
                                                                  QD2_UPDOWN_SHIFT))
#define QD2_COUNT_UPDOWN0                  ((uint32)(QD2__COUNT_UPDOWN0   <<  \
                                                                  QD2_UPDOWN_SHIFT))
#define QD2_COUNT_UPDOWN1                  ((uint32)(QD2__COUNT_UPDOWN1   <<  \
                                                                  QD2_UPDOWN_SHIFT))

/* PWM output invert */
#define QD2_INVERT_LINE                    ((uint32)(QD2__INVERSE         <<  \
                                                                  QD2_INV_OUT_SHIFT))
#define QD2_INVERT_LINE_N                  ((uint32)(QD2__INVERSE         <<  \
                                                                  QD2_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define QD2_TRIG_RISING                    ((uint32)QD2__TRIG_RISING)
#define QD2_TRIG_FALLING                   ((uint32)QD2__TRIG_FALLING)
#define QD2_TRIG_BOTH                      ((uint32)QD2__TRIG_BOTH)
#define QD2_TRIG_LEVEL                     ((uint32)QD2__TRIG_LEVEL)

/* Interrupt mask */
#define QD2_INTR_MASK_TC                   ((uint32)QD2__INTR_MASK_TC)
#define QD2_INTR_MASK_CC_MATCH             ((uint32)QD2__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define QD2_CC_MATCH_SET                   (0x00u)
#define QD2_CC_MATCH_CLEAR                 (0x01u)
#define QD2_CC_MATCH_INVERT                (0x02u)
#define QD2_CC_MATCH_NO_CHANGE             (0x03u)
#define QD2_OVERLOW_SET                    (0x00u)
#define QD2_OVERLOW_CLEAR                  (0x04u)
#define QD2_OVERLOW_INVERT                 (0x08u)
#define QD2_OVERLOW_NO_CHANGE              (0x0Cu)
#define QD2_UNDERFLOW_SET                  (0x00u)
#define QD2_UNDERFLOW_CLEAR                (0x10u)
#define QD2_UNDERFLOW_INVERT               (0x20u)
#define QD2_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define QD2_PWM_MODE_LEFT                  (QD2_CC_MATCH_CLEAR        |   \
                                                         QD2_OVERLOW_SET           |   \
                                                         QD2_UNDERFLOW_NO_CHANGE)
#define QD2_PWM_MODE_RIGHT                 (QD2_CC_MATCH_SET          |   \
                                                         QD2_OVERLOW_NO_CHANGE     |   \
                                                         QD2_UNDERFLOW_CLEAR)
#define QD2_PWM_MODE_ASYM                  (QD2_CC_MATCH_INVERT       |   \
                                                         QD2_OVERLOW_SET           |   \
                                                         QD2_UNDERFLOW_CLEAR)

#if (QD2_CY_TCPWM_V2)
    #if(QD2_CY_TCPWM_4000)
        #define QD2_PWM_MODE_CENTER                (QD2_CC_MATCH_INVERT       |   \
                                                                 QD2_OVERLOW_NO_CHANGE     |   \
                                                                 QD2_UNDERFLOW_CLEAR)
    #else
        #define QD2_PWM_MODE_CENTER                (QD2_CC_MATCH_INVERT       |   \
                                                                 QD2_OVERLOW_SET           |   \
                                                                 QD2_UNDERFLOW_CLEAR)
    #endif /* (QD2_CY_TCPWM_4000) */
#else
    #define QD2_PWM_MODE_CENTER                (QD2_CC_MATCH_INVERT       |   \
                                                             QD2_OVERLOW_NO_CHANGE     |   \
                                                             QD2_UNDERFLOW_CLEAR)
#endif /* (QD2_CY_TCPWM_NEW) */

/* Command operations without condition */
#define QD2_CMD_CAPTURE                    (0u)
#define QD2_CMD_RELOAD                     (8u)
#define QD2_CMD_STOP                       (16u)
#define QD2_CMD_START                      (24u)

/* Status */
#define QD2_STATUS_DOWN                    (1u)
#define QD2_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   QD2_Init(void);
void   QD2_Enable(void);
void   QD2_Start(void);
void   QD2_Stop(void);

void   QD2_SetMode(uint32 mode);
void   QD2_SetCounterMode(uint32 counterMode);
void   QD2_SetPWMMode(uint32 modeMask);
void   QD2_SetQDMode(uint32 qdMode);

void   QD2_SetPrescaler(uint32 prescaler);
void   QD2_TriggerCommand(uint32 mask, uint32 command);
void   QD2_SetOneShot(uint32 oneShotEnable);
uint32 QD2_ReadStatus(void);

void   QD2_SetPWMSyncKill(uint32 syncKillEnable);
void   QD2_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   QD2_SetPWMDeadTime(uint32 deadTime);
void   QD2_SetPWMInvert(uint32 mask);

void   QD2_SetInterruptMode(uint32 interruptMask);
uint32 QD2_GetInterruptSourceMasked(void);
uint32 QD2_GetInterruptSource(void);
void   QD2_ClearInterrupt(uint32 interruptMask);
void   QD2_SetInterrupt(uint32 interruptMask);

void   QD2_WriteCounter(uint32 count);
uint32 QD2_ReadCounter(void);

uint32 QD2_ReadCapture(void);
uint32 QD2_ReadCaptureBuf(void);

void   QD2_WritePeriod(uint32 period);
uint32 QD2_ReadPeriod(void);
void   QD2_WritePeriodBuf(uint32 periodBuf);
uint32 QD2_ReadPeriodBuf(void);

void   QD2_WriteCompare(uint32 compare);
uint32 QD2_ReadCompare(void);
void   QD2_WriteCompareBuf(uint32 compareBuf);
uint32 QD2_ReadCompareBuf(void);

void   QD2_SetPeriodSwap(uint32 swapEnable);
void   QD2_SetCompareSwap(uint32 swapEnable);

void   QD2_SetCaptureMode(uint32 triggerMode);
void   QD2_SetReloadMode(uint32 triggerMode);
void   QD2_SetStartMode(uint32 triggerMode);
void   QD2_SetStopMode(uint32 triggerMode);
void   QD2_SetCountMode(uint32 triggerMode);

void   QD2_SaveConfig(void);
void   QD2_RestoreConfig(void);
void   QD2_Sleep(void);
void   QD2_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define QD2_BLOCK_CONTROL_REG              (*(reg32 *) QD2_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define QD2_BLOCK_CONTROL_PTR              ( (reg32 *) QD2_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define QD2_COMMAND_REG                    (*(reg32 *) QD2_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define QD2_COMMAND_PTR                    ( (reg32 *) QD2_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define QD2_INTRRUPT_CAUSE_REG             (*(reg32 *) QD2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define QD2_INTRRUPT_CAUSE_PTR             ( (reg32 *) QD2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define QD2_CONTROL_REG                    (*(reg32 *) QD2_cy_m0s8_tcpwm_1__CTRL )
#define QD2_CONTROL_PTR                    ( (reg32 *) QD2_cy_m0s8_tcpwm_1__CTRL )
#define QD2_STATUS_REG                     (*(reg32 *) QD2_cy_m0s8_tcpwm_1__STATUS )
#define QD2_STATUS_PTR                     ( (reg32 *) QD2_cy_m0s8_tcpwm_1__STATUS )
#define QD2_COUNTER_REG                    (*(reg32 *) QD2_cy_m0s8_tcpwm_1__COUNTER )
#define QD2_COUNTER_PTR                    ( (reg32 *) QD2_cy_m0s8_tcpwm_1__COUNTER )
#define QD2_COMP_CAP_REG                   (*(reg32 *) QD2_cy_m0s8_tcpwm_1__CC )
#define QD2_COMP_CAP_PTR                   ( (reg32 *) QD2_cy_m0s8_tcpwm_1__CC )
#define QD2_COMP_CAP_BUF_REG               (*(reg32 *) QD2_cy_m0s8_tcpwm_1__CC_BUFF )
#define QD2_COMP_CAP_BUF_PTR               ( (reg32 *) QD2_cy_m0s8_tcpwm_1__CC_BUFF )
#define QD2_PERIOD_REG                     (*(reg32 *) QD2_cy_m0s8_tcpwm_1__PERIOD )
#define QD2_PERIOD_PTR                     ( (reg32 *) QD2_cy_m0s8_tcpwm_1__PERIOD )
#define QD2_PERIOD_BUF_REG                 (*(reg32 *) QD2_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define QD2_PERIOD_BUF_PTR                 ( (reg32 *) QD2_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define QD2_TRIG_CONTROL0_REG              (*(reg32 *) QD2_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define QD2_TRIG_CONTROL0_PTR              ( (reg32 *) QD2_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define QD2_TRIG_CONTROL1_REG              (*(reg32 *) QD2_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define QD2_TRIG_CONTROL1_PTR              ( (reg32 *) QD2_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define QD2_TRIG_CONTROL2_REG              (*(reg32 *) QD2_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define QD2_TRIG_CONTROL2_PTR              ( (reg32 *) QD2_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define QD2_INTERRUPT_REQ_REG              (*(reg32 *) QD2_cy_m0s8_tcpwm_1__INTR )
#define QD2_INTERRUPT_REQ_PTR              ( (reg32 *) QD2_cy_m0s8_tcpwm_1__INTR )
#define QD2_INTERRUPT_SET_REG              (*(reg32 *) QD2_cy_m0s8_tcpwm_1__INTR_SET )
#define QD2_INTERRUPT_SET_PTR              ( (reg32 *) QD2_cy_m0s8_tcpwm_1__INTR_SET )
#define QD2_INTERRUPT_MASK_REG             (*(reg32 *) QD2_cy_m0s8_tcpwm_1__INTR_MASK )
#define QD2_INTERRUPT_MASK_PTR             ( (reg32 *) QD2_cy_m0s8_tcpwm_1__INTR_MASK )
#define QD2_INTERRUPT_MASKED_REG           (*(reg32 *) QD2_cy_m0s8_tcpwm_1__INTR_MASKED )
#define QD2_INTERRUPT_MASKED_PTR           ( (reg32 *) QD2_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define QD2_MASK                           ((uint32)QD2_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define QD2_RELOAD_CC_SHIFT                (0u)
#define QD2_RELOAD_PERIOD_SHIFT            (1u)
#define QD2_PWM_SYNC_KILL_SHIFT            (2u)
#define QD2_PWM_STOP_KILL_SHIFT            (3u)
#define QD2_PRESCALER_SHIFT                (8u)
#define QD2_UPDOWN_SHIFT                   (16u)
#define QD2_ONESHOT_SHIFT                  (18u)
#define QD2_QUAD_MODE_SHIFT                (20u)
#define QD2_INV_OUT_SHIFT                  (20u)
#define QD2_INV_COMPL_OUT_SHIFT            (21u)
#define QD2_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define QD2_RELOAD_CC_MASK                 ((uint32)(QD2_1BIT_MASK        <<  \
                                                                            QD2_RELOAD_CC_SHIFT))
#define QD2_RELOAD_PERIOD_MASK             ((uint32)(QD2_1BIT_MASK        <<  \
                                                                            QD2_RELOAD_PERIOD_SHIFT))
#define QD2_PWM_SYNC_KILL_MASK             ((uint32)(QD2_1BIT_MASK        <<  \
                                                                            QD2_PWM_SYNC_KILL_SHIFT))
#define QD2_PWM_STOP_KILL_MASK             ((uint32)(QD2_1BIT_MASK        <<  \
                                                                            QD2_PWM_STOP_KILL_SHIFT))
#define QD2_PRESCALER_MASK                 ((uint32)(QD2_8BIT_MASK        <<  \
                                                                            QD2_PRESCALER_SHIFT))
#define QD2_UPDOWN_MASK                    ((uint32)(QD2_2BIT_MASK        <<  \
                                                                            QD2_UPDOWN_SHIFT))
#define QD2_ONESHOT_MASK                   ((uint32)(QD2_1BIT_MASK        <<  \
                                                                            QD2_ONESHOT_SHIFT))
#define QD2_QUAD_MODE_MASK                 ((uint32)(QD2_3BIT_MASK        <<  \
                                                                            QD2_QUAD_MODE_SHIFT))
#define QD2_INV_OUT_MASK                   ((uint32)(QD2_2BIT_MASK        <<  \
                                                                            QD2_INV_OUT_SHIFT))
#define QD2_MODE_MASK                      ((uint32)(QD2_3BIT_MASK        <<  \
                                                                            QD2_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define QD2_CAPTURE_SHIFT                  (0u)
#define QD2_COUNT_SHIFT                    (2u)
#define QD2_RELOAD_SHIFT                   (4u)
#define QD2_STOP_SHIFT                     (6u)
#define QD2_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define QD2_CAPTURE_MASK                   ((uint32)(QD2_2BIT_MASK        <<  \
                                                                  QD2_CAPTURE_SHIFT))
#define QD2_COUNT_MASK                     ((uint32)(QD2_2BIT_MASK        <<  \
                                                                  QD2_COUNT_SHIFT))
#define QD2_RELOAD_MASK                    ((uint32)(QD2_2BIT_MASK        <<  \
                                                                  QD2_RELOAD_SHIFT))
#define QD2_STOP_MASK                      ((uint32)(QD2_2BIT_MASK        <<  \
                                                                  QD2_STOP_SHIFT))
#define QD2_START_MASK                     ((uint32)(QD2_2BIT_MASK        <<  \
                                                                  QD2_START_SHIFT))

/* MASK */
#define QD2_1BIT_MASK                      ((uint32)0x01u)
#define QD2_2BIT_MASK                      ((uint32)0x03u)
#define QD2_3BIT_MASK                      ((uint32)0x07u)
#define QD2_6BIT_MASK                      ((uint32)0x3Fu)
#define QD2_8BIT_MASK                      ((uint32)0xFFu)
#define QD2_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define QD2_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define QD2_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(QD2_QUAD_ENCODING_MODES     << QD2_QUAD_MODE_SHIFT))       |\
         ((uint32)(QD2_CONFIG                  << QD2_MODE_SHIFT)))

#define QD2_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(QD2_PWM_STOP_EVENT          << QD2_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(QD2_PWM_OUT_INVERT          << QD2_INV_OUT_SHIFT))         |\
         ((uint32)(QD2_PWM_OUT_N_INVERT        << QD2_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(QD2_PWM_MODE                << QD2_MODE_SHIFT)))

#define QD2_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(QD2_PWM_RUN_MODE         << QD2_ONESHOT_SHIFT))
            
#define QD2_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(QD2_PWM_ALIGN            << QD2_UPDOWN_SHIFT))

#define QD2_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(QD2_PWM_KILL_EVENT      << QD2_PWM_SYNC_KILL_SHIFT))

#define QD2_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(QD2_PWM_DEAD_TIME_CYCLE  << QD2_PRESCALER_SHIFT))

#define QD2_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(QD2_PWM_PRESCALER        << QD2_PRESCALER_SHIFT))

#define QD2_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(QD2_TC_PRESCALER            << QD2_PRESCALER_SHIFT))       |\
         ((uint32)(QD2_TC_COUNTER_MODE         << QD2_UPDOWN_SHIFT))          |\
         ((uint32)(QD2_TC_RUN_MODE             << QD2_ONESHOT_SHIFT))         |\
         ((uint32)(QD2_TC_COMP_CAP_MODE        << QD2_MODE_SHIFT)))
        
#define QD2_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(QD2_QUAD_PHIA_SIGNAL_MODE   << QD2_COUNT_SHIFT))           |\
         ((uint32)(QD2_QUAD_INDEX_SIGNAL_MODE  << QD2_RELOAD_SHIFT))          |\
         ((uint32)(QD2_QUAD_STOP_SIGNAL_MODE   << QD2_STOP_SHIFT))            |\
         ((uint32)(QD2_QUAD_PHIB_SIGNAL_MODE   << QD2_START_SHIFT)))

#define QD2_PWM_SIGNALS_MODES                                                              \
        (((uint32)(QD2_PWM_SWITCH_SIGNAL_MODE  << QD2_CAPTURE_SHIFT))         |\
         ((uint32)(QD2_PWM_COUNT_SIGNAL_MODE   << QD2_COUNT_SHIFT))           |\
         ((uint32)(QD2_PWM_RELOAD_SIGNAL_MODE  << QD2_RELOAD_SHIFT))          |\
         ((uint32)(QD2_PWM_STOP_SIGNAL_MODE    << QD2_STOP_SHIFT))            |\
         ((uint32)(QD2_PWM_START_SIGNAL_MODE   << QD2_START_SHIFT)))

#define QD2_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(QD2_TC_CAPTURE_SIGNAL_MODE  << QD2_CAPTURE_SHIFT))         |\
         ((uint32)(QD2_TC_COUNT_SIGNAL_MODE    << QD2_COUNT_SHIFT))           |\
         ((uint32)(QD2_TC_RELOAD_SIGNAL_MODE   << QD2_RELOAD_SHIFT))          |\
         ((uint32)(QD2_TC_STOP_SIGNAL_MODE     << QD2_STOP_SHIFT))            |\
         ((uint32)(QD2_TC_START_SIGNAL_MODE    << QD2_START_SHIFT)))
        
#define QD2_TIMER_UPDOWN_CNT_USED                                                          \
                ((QD2__COUNT_UPDOWN0 == QD2_TC_COUNTER_MODE)                  ||\
                 (QD2__COUNT_UPDOWN1 == QD2_TC_COUNTER_MODE))

#define QD2_PWM_UPDOWN_CNT_USED                                                            \
                ((QD2__CENTER == QD2_PWM_ALIGN)                               ||\
                 (QD2__ASYMMETRIC == QD2_PWM_ALIGN))               
        
#define QD2_PWM_PR_INIT_VALUE              (1u)
#define QD2_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_QD2_H */

/* [] END OF FILE */
