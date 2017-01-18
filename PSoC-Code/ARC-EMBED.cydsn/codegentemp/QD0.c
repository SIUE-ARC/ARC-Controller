/*******************************************************************************
* File Name: QD0.c
* Version 2.10
*
* Description:
*  This file provides the source code to the API for the QD0
*  component
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

#include "QD0.h"

uint8 QD0_initVar = 0u;


/*******************************************************************************
* Function Name: QD0_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default QD0 configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void QD0_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (QD0__QUAD == QD0_CONFIG)
        QD0_CONTROL_REG = QD0_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        QD0_TRIG_CONTROL1_REG  = QD0_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        QD0_SetInterruptMode(QD0_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        QD0_SetCounterMode(QD0_COUNT_DOWN);
        QD0_WritePeriod(QD0_QUAD_PERIOD_INIT_VALUE);
        QD0_WriteCounter(QD0_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (QD0__QUAD == QD0_CONFIG) */

    #if (QD0__TIMER == QD0_CONFIG)
        QD0_CONTROL_REG = QD0_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        QD0_TRIG_CONTROL1_REG  = QD0_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        QD0_SetInterruptMode(QD0_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        QD0_WritePeriod(QD0_TC_PERIOD_VALUE );

        #if (QD0__COMPARE == QD0_TC_COMP_CAP_MODE)
            QD0_WriteCompare(QD0_TC_COMPARE_VALUE);

            #if (1u == QD0_TC_COMPARE_SWAP)
                QD0_SetCompareSwap(1u);
                QD0_WriteCompareBuf(QD0_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == QD0_TC_COMPARE_SWAP) */
        #endif  /* (QD0__COMPARE == QD0_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (QD0_CY_TCPWM_V2 && QD0_TIMER_UPDOWN_CNT_USED && !QD0_CY_TCPWM_4000)
            QD0_WriteCounter(1u);
        #elif(QD0__COUNT_DOWN == QD0_TC_COUNTER_MODE)
            QD0_WriteCounter(QD0_TC_PERIOD_VALUE);
        #else
            QD0_WriteCounter(0u);
        #endif /* (QD0_CY_TCPWM_V2 && QD0_TIMER_UPDOWN_CNT_USED && !QD0_CY_TCPWM_4000) */
    #endif  /* (QD0__TIMER == QD0_CONFIG) */

    #if (QD0__PWM_SEL == QD0_CONFIG)
        QD0_CONTROL_REG = QD0_CTRL_PWM_BASE_CONFIG;

        #if (QD0__PWM_PR == QD0_PWM_MODE)
            QD0_CONTROL_REG |= QD0_CTRL_PWM_RUN_MODE;
            QD0_WriteCounter(QD0_PWM_PR_INIT_VALUE);
        #else
            QD0_CONTROL_REG |= QD0_CTRL_PWM_ALIGN | QD0_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (QD0_CY_TCPWM_V2 && QD0_PWM_UPDOWN_CNT_USED && !QD0_CY_TCPWM_4000)
                QD0_WriteCounter(1u);
            #elif (QD0__RIGHT == QD0_PWM_ALIGN)
                QD0_WriteCounter(QD0_PWM_PERIOD_VALUE);
            #else 
                QD0_WriteCounter(0u);
            #endif  /* (QD0_CY_TCPWM_V2 && QD0_PWM_UPDOWN_CNT_USED && !QD0_CY_TCPWM_4000) */
        #endif  /* (QD0__PWM_PR == QD0_PWM_MODE) */

        #if (QD0__PWM_DT == QD0_PWM_MODE)
            QD0_CONTROL_REG |= QD0_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (QD0__PWM_DT == QD0_PWM_MODE) */

        #if (QD0__PWM == QD0_PWM_MODE)
            QD0_CONTROL_REG |= QD0_CTRL_PWM_PRESCALER;
        #endif  /* (QD0__PWM == QD0_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        QD0_TRIG_CONTROL1_REG  = QD0_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        QD0_SetInterruptMode(QD0_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (QD0__PWM_PR == QD0_PWM_MODE)
            QD0_TRIG_CONTROL2_REG =
                    (QD0_CC_MATCH_NO_CHANGE    |
                    QD0_OVERLOW_NO_CHANGE      |
                    QD0_UNDERFLOW_NO_CHANGE);
        #else
            #if (QD0__LEFT == QD0_PWM_ALIGN)
                QD0_TRIG_CONTROL2_REG = QD0_PWM_MODE_LEFT;
            #endif  /* ( QD0_PWM_LEFT == QD0_PWM_ALIGN) */

            #if (QD0__RIGHT == QD0_PWM_ALIGN)
                QD0_TRIG_CONTROL2_REG = QD0_PWM_MODE_RIGHT;
            #endif  /* ( QD0_PWM_RIGHT == QD0_PWM_ALIGN) */

            #if (QD0__CENTER == QD0_PWM_ALIGN)
                QD0_TRIG_CONTROL2_REG = QD0_PWM_MODE_CENTER;
            #endif  /* ( QD0_PWM_CENTER == QD0_PWM_ALIGN) */

            #if (QD0__ASYMMETRIC == QD0_PWM_ALIGN)
                QD0_TRIG_CONTROL2_REG = QD0_PWM_MODE_ASYM;
            #endif  /* (QD0__ASYMMETRIC == QD0_PWM_ALIGN) */
        #endif  /* (QD0__PWM_PR == QD0_PWM_MODE) */

        /* Set other values from customizer */
        QD0_WritePeriod(QD0_PWM_PERIOD_VALUE );
        QD0_WriteCompare(QD0_PWM_COMPARE_VALUE);

        #if (1u == QD0_PWM_COMPARE_SWAP)
            QD0_SetCompareSwap(1u);
            QD0_WriteCompareBuf(QD0_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == QD0_PWM_COMPARE_SWAP) */

        #if (1u == QD0_PWM_PERIOD_SWAP)
            QD0_SetPeriodSwap(1u);
            QD0_WritePeriodBuf(QD0_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == QD0_PWM_PERIOD_SWAP) */
    #endif  /* (QD0__PWM_SEL == QD0_CONFIG) */
    
}


/*******************************************************************************
* Function Name: QD0_Enable
********************************************************************************
*
* Summary:
*  Enables the QD0.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void QD0_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    QD0_BLOCK_CONTROL_REG |= QD0_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (QD0__PWM_SEL == QD0_CONFIG)
        #if (0u == QD0_PWM_START_SIGNAL_PRESENT)
            QD0_TriggerCommand(QD0_MASK, QD0_CMD_START);
        #endif /* (0u == QD0_PWM_START_SIGNAL_PRESENT) */
    #endif /* (QD0__PWM_SEL == QD0_CONFIG) */

    #if (QD0__TIMER == QD0_CONFIG)
        #if (0u == QD0_TC_START_SIGNAL_PRESENT)
            QD0_TriggerCommand(QD0_MASK, QD0_CMD_START);
        #endif /* (0u == QD0_TC_START_SIGNAL_PRESENT) */
    #endif /* (QD0__TIMER == QD0_CONFIG) */
    
    #if (QD0__QUAD == QD0_CONFIG)
        #if (0u != QD0_QUAD_AUTO_START)
            QD0_TriggerCommand(QD0_MASK, QD0_CMD_RELOAD);
        #endif /* (0u != QD0_QUAD_AUTO_START) */
    #endif  /* (QD0__QUAD == QD0_CONFIG) */
}


/*******************************************************************************
* Function Name: QD0_Start
********************************************************************************
*
* Summary:
*  Initializes the QD0 with default customizer
*  values when called the first time and enables the QD0.
*  For subsequent calls the configuration is left unchanged and the component is
*  just enabled.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  QD0_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time QD0_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the QD0_Start() routine.
*
*******************************************************************************/
void QD0_Start(void)
{
    if (0u == QD0_initVar)
    {
        QD0_Init();
        QD0_initVar = 1u;
    }

    QD0_Enable();
}


/*******************************************************************************
* Function Name: QD0_Stop
********************************************************************************
*
* Summary:
*  Disables the QD0.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void QD0_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD0_BLOCK_CONTROL_REG &= (uint32)~QD0_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD0_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the QD0. This function is used when
*  configured as a generic QD0 and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the QD0 to operate in
*   Values:
*   - QD0_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - QD0_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - QD0_MODE_QUAD - Quadrature decoder
*         - QD0_MODE_PWM - PWM
*         - QD0_MODE_PWM_DT - PWM with dead time
*         - QD0_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void QD0_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD0_CONTROL_REG &= (uint32)~QD0_MODE_MASK;
    QD0_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD0_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - QD0_MODE_X1 - Counts on phi 1 rising
*         - QD0_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - QD0_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void QD0_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD0_CONTROL_REG &= (uint32)~QD0_QUAD_MODE_MASK;
    QD0_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD0_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - QD0_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - QD0_PRESCALE_DIVBY2    - Divide by 2
*         - QD0_PRESCALE_DIVBY4    - Divide by 4
*         - QD0_PRESCALE_DIVBY8    - Divide by 8
*         - QD0_PRESCALE_DIVBY16   - Divide by 16
*         - QD0_PRESCALE_DIVBY32   - Divide by 32
*         - QD0_PRESCALE_DIVBY64   - Divide by 64
*         - QD0_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void QD0_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD0_CONTROL_REG &= (uint32)~QD0_PRESCALER_MASK;
    QD0_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD0_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the QD0 runs
*  continuously or stops when terminal count is reached.  By default the
*  QD0 operates in the continuous mode.
*
* Parameters:
*  oneShotEnable
*   Values:
*     - 0 - Continuous
*     - 1 - Enable One Shot
*
* Return:
*  None
*
*******************************************************************************/
void QD0_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD0_CONTROL_REG &= (uint32)~QD0_ONESHOT_MASK;
    QD0_CONTROL_REG |= ((uint32)((oneShotEnable & QD0_1BIT_MASK) <<
                                                               QD0_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD0_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the three must be ORed together to form
*  the mode.
*
* Parameters:
*  modeMask: A combination of three mode settings.  Mask must include a value
*  for each of the three or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET        - Set on comparison match
*     - CC_MATCH_CLEAR      - Clear on comparison match
*     - CC_MATCH_INVERT     - Invert on comparison match
*     - CC_MATCH_NO_CHANGE  - No change on comparison match
*     - OVERLOW_SET         - Set on overflow
*     - OVERLOW_CLEAR       - Clear on  overflow
*     - OVERLOW_INVERT      - Invert on overflow
*     - OVERLOW_NO_CHANGE   - No change on overflow
*     - UNDERFLOW_SET       - Set on underflow
*     - UNDERFLOW_CLEAR     - Clear on underflow
*     - UNDERFLOW_INVERT    - Invert on underflow
*     - UNDERFLOW_NO_CHANGE - No change on underflow
*     - PWM_MODE_LEFT       - Setting for left aligned PWM.  Should be combined
*                             with up counting mode
*     - PWM_MODE_RIGHT      - Setting for right aligned PWM.  Should be combined
*                             with down counting mode
*     - PWM_MODE_CENTER     - Setting for center aligned PWM.  Should be
*                             combined with up/down 0 mode
*     - PWM_MODE_ASYM       - Setting for asymmetric PWM.  Should be combined
*                             with up/down 1 mode
*
* Return:
*  None
*
*******************************************************************************/
void QD0_SetPWMMode(uint32 modeMask)
{
    QD0_TRIG_CONTROL2_REG = (modeMask & QD0_6BIT_MASK);
}



/*******************************************************************************
* Function Name: QD0_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to the PWM
*  and PWM with dead time modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in the pass through mode
*  (Level sensitive signal).

*
* Parameters:
*  syncKillEnable
*   Values:
*     - 0 - Asynchronous
*     - 1 - Synchronous
*
* Return:
*  None
*
*******************************************************************************/
void QD0_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD0_CONTROL_REG &= (uint32)~QD0_PWM_SYNC_KILL_MASK;
    QD0_CONTROL_REG |= ((uint32)((syncKillEnable & QD0_1BIT_MASK)  <<
                                               QD0_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD0_SetPWMStopOnKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes the PWM counter to stop.  By default the kill operation does not stop
*  the counter.  This functionality is only applicable to the three PWM modes.
*
*
* Parameters:
*  stopOnKillEnable
*   Values:
*     - 0 - Don't stop
*     - 1 - Stop
*
* Return:
*  None
*
*******************************************************************************/
void QD0_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD0_CONTROL_REG &= (uint32)~QD0_PWM_STOP_KILL_MASK;
    QD0_CONTROL_REG |= ((uint32)((stopOnKillEnable & QD0_1BIT_MASK)  <<
                                                         QD0_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD0_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in the dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void QD0_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD0_CONTROL_REG &= (uint32)~QD0_PRESCALER_MASK;
    QD0_CONTROL_REG |= ((uint32)((deadTime & QD0_8BIT_MASK) <<
                                                          QD0_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD0_SetPWMInvert
********************************************************************************
*
* Summary:
*  Writes the bits that control whether the line and line_n outputs are
*  inverted from their normal output values.  This functionality is only
*  applicable to the three PWM modes.
*
* Parameters:
*  mask: Mask of outputs to invert.
*   Values:
*         - QD0_INVERT_LINE   - Inverts the line output
*         - QD0_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void QD0_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD0_CONTROL_REG &= (uint32)~QD0_INV_OUT_MASK;
    QD0_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: QD0_WriteCounter
********************************************************************************
*
* Summary:
*  Writes a new 16bit counter value directly into the counter register, thus
*  setting the counter (not the period) to the value written. It is not
*  advised to write to this field when the counter is running.
*
* Parameters:
*  count: value to write
*
* Return:
*  None
*
*******************************************************************************/
void QD0_WriteCounter(uint32 count)
{
    QD0_COUNTER_REG = (count & QD0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QD0_ReadCounter
********************************************************************************
*
* Summary:
*  Reads the current counter value.
*
* Parameters:
*  None
*
* Return:
*  Current counter value
*
*******************************************************************************/
uint32 QD0_ReadCounter(void)
{
    return (QD0_COUNTER_REG & QD0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QD0_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - QD0_COUNT_UP       - Counts up
*     - QD0_COUNT_DOWN     - Counts down
*     - QD0_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - QD0_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void QD0_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD0_CONTROL_REG &= (uint32)~QD0_UPDOWN_MASK;
    QD0_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD0_WritePeriod
********************************************************************************
*
* Summary:
*  Writes the 16 bit period register with the new period value.
*  To cause the counter to count for N cycles this register should be written
*  with N-1 (counts from 0 to period inclusive).
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void QD0_WritePeriod(uint32 period)
{
    QD0_PERIOD_REG = (period & QD0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QD0_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the 16 bit period register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 QD0_ReadPeriod(void)
{
    return (QD0_PERIOD_REG & QD0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QD0_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in the Timer/Counter mode(without capture) the swap
*  occurs at a TC event. In the PWM mode the swap occurs at the next TC event
*  following a hardware switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void QD0_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD0_CONTROL_REG &= (uint32)~QD0_RELOAD_CC_MASK;
    QD0_CONTROL_REG |= (swapEnable & QD0_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD0_WritePeriodBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit period buf register with the new period value.
*
* Parameters:
*  periodBuf: Period value
*
* Return:
*  None
*
*******************************************************************************/
void QD0_WritePeriodBuf(uint32 periodBuf)
{
    QD0_PERIOD_BUF_REG = (periodBuf & QD0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QD0_ReadPeriodBuf
********************************************************************************
*
* Summary:
*  Reads the 16 bit period buf register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 QD0_ReadPeriodBuf(void)
{
    return (QD0_PERIOD_BUF_REG & QD0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QD0_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In the PWM mode the swap occurs at the next TC event following a hardware
*  switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void QD0_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD0_CONTROL_REG &= (uint32)~QD0_RELOAD_PERIOD_MASK;
    QD0_CONTROL_REG |= ((uint32)((swapEnable & QD0_1BIT_MASK) <<
                                                            QD0_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD0_WriteCompare
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compare: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void QD0_WriteCompare(uint32 compare)
{
    #if (QD0_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (QD0_CY_TCPWM_4000) */

    #if (QD0_CY_TCPWM_4000)
        currentMode = ((QD0_CONTROL_REG & QD0_UPDOWN_MASK) >> QD0_UPDOWN_SHIFT);

        if (((uint32)QD0__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)QD0__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (QD0_CY_TCPWM_4000) */
    
    QD0_COMP_CAP_REG = (compare & QD0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QD0_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 QD0_ReadCompare(void)
{
    #if (QD0_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (QD0_CY_TCPWM_4000) */

    #if (QD0_CY_TCPWM_4000)
        currentMode = ((QD0_CONTROL_REG & QD0_UPDOWN_MASK) >> QD0_UPDOWN_SHIFT);
        
        regVal = QD0_COMP_CAP_REG;
        
        if (((uint32)QD0__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)QD0__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & QD0_16BIT_MASK);
    #else
        return (QD0_COMP_CAP_REG & QD0_16BIT_MASK);
    #endif /* (QD0_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: QD0_WriteCompareBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare buffer register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compareBuf: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void QD0_WriteCompareBuf(uint32 compareBuf)
{
    #if (QD0_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (QD0_CY_TCPWM_4000) */

    #if (QD0_CY_TCPWM_4000)
        currentMode = ((QD0_CONTROL_REG & QD0_UPDOWN_MASK) >> QD0_UPDOWN_SHIFT);

        if (((uint32)QD0__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)QD0__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (QD0_CY_TCPWM_4000) */
    
    QD0_COMP_CAP_BUF_REG = (compareBuf & QD0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QD0_ReadCompareBuf
********************************************************************************
*
* Summary:
*  Reads the compare buffer register. Not applicable for Timer/Counter with
*  Capture or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare buffer value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 QD0_ReadCompareBuf(void)
{
    #if (QD0_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (QD0_CY_TCPWM_4000) */

    #if (QD0_CY_TCPWM_4000)
        currentMode = ((QD0_CONTROL_REG & QD0_UPDOWN_MASK) >> QD0_UPDOWN_SHIFT);

        regVal = QD0_COMP_CAP_BUF_REG;
        
        if (((uint32)QD0__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)QD0__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & QD0_16BIT_MASK);
    #else
        return (QD0_COMP_CAP_BUF_REG & QD0_16BIT_MASK);
    #endif /* (QD0_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: QD0_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 QD0_ReadCapture(void)
{
    return (QD0_COMP_CAP_REG & QD0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QD0_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 QD0_ReadCaptureBuf(void)
{
    return (QD0_COMP_CAP_BUF_REG & QD0_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QD0_SetCaptureMode
********************************************************************************
*
* Summary:
*  Sets the capture trigger mode. For PWM mode this is the switch input.
*  This input is not applicable to the Timer/Counter without Capture and
*  Quadrature Decoder modes.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - QD0_TRIG_LEVEL     - Level
*     - QD0_TRIG_RISING    - Rising edge
*     - QD0_TRIG_FALLING   - Falling edge
*     - QD0_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void QD0_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD0_TRIG_CONTROL1_REG &= (uint32)~QD0_CAPTURE_MASK;
    QD0_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD0_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - QD0_TRIG_LEVEL     - Level
*     - QD0_TRIG_RISING    - Rising edge
*     - QD0_TRIG_FALLING   - Falling edge
*     - QD0_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void QD0_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD0_TRIG_CONTROL1_REG &= (uint32)~QD0_RELOAD_MASK;
    QD0_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << QD0_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD0_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - QD0_TRIG_LEVEL     - Level
*     - QD0_TRIG_RISING    - Rising edge
*     - QD0_TRIG_FALLING   - Falling edge
*     - QD0_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void QD0_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD0_TRIG_CONTROL1_REG &= (uint32)~QD0_START_MASK;
    QD0_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << QD0_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD0_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - QD0_TRIG_LEVEL     - Level
*     - QD0_TRIG_RISING    - Rising edge
*     - QD0_TRIG_FALLING   - Falling edge
*     - QD0_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void QD0_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD0_TRIG_CONTROL1_REG &= (uint32)~QD0_STOP_MASK;
    QD0_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << QD0_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD0_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - QD0_TRIG_LEVEL     - Level
*     - QD0_TRIG_RISING    - Rising edge
*     - QD0_TRIG_FALLING   - Falling edge
*     - QD0_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void QD0_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD0_TRIG_CONTROL1_REG &= (uint32)~QD0_COUNT_MASK;
    QD0_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << QD0_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD0_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: A combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - QD0_CMD_CAPTURE    - Trigger Capture/Switch command
*     - QD0_CMD_RELOAD     - Trigger Reload/Index command
*     - QD0_CMD_STOP       - Trigger Stop/Kill command
*     - QD0_CMD_START      - Trigger Start/phiB command
*
* Return:
*  None
*
*******************************************************************************/
void QD0_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD0_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD0_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the QD0.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - QD0_STATUS_DOWN    - Set if counting down
*     - QD0_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 QD0_ReadStatus(void)
{
    return ((QD0_STATUS_REG >> QD0_RUNNING_STATUS_SHIFT) |
            (QD0_STATUS_REG & QD0_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: QD0_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - QD0_INTR_MASK_TC       - Terminal count mask
*     - QD0_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void QD0_SetInterruptMode(uint32 interruptMask)
{
    QD0_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: QD0_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the interrupt requests masked by the interrupt mask.
*
* Parameters:
*   None
*
* Return:
*  Masked interrupt source
*   Values:
*     - QD0_INTR_MASK_TC       - Terminal count mask
*     - QD0_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 QD0_GetInterruptSourceMasked(void)
{
    return (QD0_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: QD0_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the interrupt requests (without masking).
*
* Parameters:
*  None
*
* Return:
*  Interrupt request value
*   Values:
*     - QD0_INTR_MASK_TC       - Terminal count mask
*     - QD0_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 QD0_GetInterruptSource(void)
{
    return (QD0_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: QD0_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - QD0_INTR_MASK_TC       - Terminal count mask
*     - QD0_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void QD0_ClearInterrupt(uint32 interruptMask)
{
    QD0_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: QD0_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - QD0_INTR_MASK_TC       - Terminal count mask
*     - QD0_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void QD0_SetInterrupt(uint32 interruptMask)
{
    QD0_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
