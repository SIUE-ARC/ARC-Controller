/*******************************************************************************
* File Name: QD4.c
* Version 2.10
*
* Description:
*  This file provides the source code to the API for the QD4
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

#include "QD4.h"

uint8 QD4_initVar = 0u;


/*******************************************************************************
* Function Name: QD4_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default QD4 configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void QD4_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (QD4__QUAD == QD4_CONFIG)
        QD4_CONTROL_REG = QD4_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        QD4_TRIG_CONTROL1_REG  = QD4_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        QD4_SetInterruptMode(QD4_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        QD4_SetCounterMode(QD4_COUNT_DOWN);
        QD4_WritePeriod(QD4_QUAD_PERIOD_INIT_VALUE);
        QD4_WriteCounter(QD4_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (QD4__QUAD == QD4_CONFIG) */

    #if (QD4__TIMER == QD4_CONFIG)
        QD4_CONTROL_REG = QD4_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        QD4_TRIG_CONTROL1_REG  = QD4_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        QD4_SetInterruptMode(QD4_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        QD4_WritePeriod(QD4_TC_PERIOD_VALUE );

        #if (QD4__COMPARE == QD4_TC_COMP_CAP_MODE)
            QD4_WriteCompare(QD4_TC_COMPARE_VALUE);

            #if (1u == QD4_TC_COMPARE_SWAP)
                QD4_SetCompareSwap(1u);
                QD4_WriteCompareBuf(QD4_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == QD4_TC_COMPARE_SWAP) */
        #endif  /* (QD4__COMPARE == QD4_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (QD4_CY_TCPWM_V2 && QD4_TIMER_UPDOWN_CNT_USED && !QD4_CY_TCPWM_4000)
            QD4_WriteCounter(1u);
        #elif(QD4__COUNT_DOWN == QD4_TC_COUNTER_MODE)
            QD4_WriteCounter(QD4_TC_PERIOD_VALUE);
        #else
            QD4_WriteCounter(0u);
        #endif /* (QD4_CY_TCPWM_V2 && QD4_TIMER_UPDOWN_CNT_USED && !QD4_CY_TCPWM_4000) */
    #endif  /* (QD4__TIMER == QD4_CONFIG) */

    #if (QD4__PWM_SEL == QD4_CONFIG)
        QD4_CONTROL_REG = QD4_CTRL_PWM_BASE_CONFIG;

        #if (QD4__PWM_PR == QD4_PWM_MODE)
            QD4_CONTROL_REG |= QD4_CTRL_PWM_RUN_MODE;
            QD4_WriteCounter(QD4_PWM_PR_INIT_VALUE);
        #else
            QD4_CONTROL_REG |= QD4_CTRL_PWM_ALIGN | QD4_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (QD4_CY_TCPWM_V2 && QD4_PWM_UPDOWN_CNT_USED && !QD4_CY_TCPWM_4000)
                QD4_WriteCounter(1u);
            #elif (QD4__RIGHT == QD4_PWM_ALIGN)
                QD4_WriteCounter(QD4_PWM_PERIOD_VALUE);
            #else 
                QD4_WriteCounter(0u);
            #endif  /* (QD4_CY_TCPWM_V2 && QD4_PWM_UPDOWN_CNT_USED && !QD4_CY_TCPWM_4000) */
        #endif  /* (QD4__PWM_PR == QD4_PWM_MODE) */

        #if (QD4__PWM_DT == QD4_PWM_MODE)
            QD4_CONTROL_REG |= QD4_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (QD4__PWM_DT == QD4_PWM_MODE) */

        #if (QD4__PWM == QD4_PWM_MODE)
            QD4_CONTROL_REG |= QD4_CTRL_PWM_PRESCALER;
        #endif  /* (QD4__PWM == QD4_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        QD4_TRIG_CONTROL1_REG  = QD4_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        QD4_SetInterruptMode(QD4_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (QD4__PWM_PR == QD4_PWM_MODE)
            QD4_TRIG_CONTROL2_REG =
                    (QD4_CC_MATCH_NO_CHANGE    |
                    QD4_OVERLOW_NO_CHANGE      |
                    QD4_UNDERFLOW_NO_CHANGE);
        #else
            #if (QD4__LEFT == QD4_PWM_ALIGN)
                QD4_TRIG_CONTROL2_REG = QD4_PWM_MODE_LEFT;
            #endif  /* ( QD4_PWM_LEFT == QD4_PWM_ALIGN) */

            #if (QD4__RIGHT == QD4_PWM_ALIGN)
                QD4_TRIG_CONTROL2_REG = QD4_PWM_MODE_RIGHT;
            #endif  /* ( QD4_PWM_RIGHT == QD4_PWM_ALIGN) */

            #if (QD4__CENTER == QD4_PWM_ALIGN)
                QD4_TRIG_CONTROL2_REG = QD4_PWM_MODE_CENTER;
            #endif  /* ( QD4_PWM_CENTER == QD4_PWM_ALIGN) */

            #if (QD4__ASYMMETRIC == QD4_PWM_ALIGN)
                QD4_TRIG_CONTROL2_REG = QD4_PWM_MODE_ASYM;
            #endif  /* (QD4__ASYMMETRIC == QD4_PWM_ALIGN) */
        #endif  /* (QD4__PWM_PR == QD4_PWM_MODE) */

        /* Set other values from customizer */
        QD4_WritePeriod(QD4_PWM_PERIOD_VALUE );
        QD4_WriteCompare(QD4_PWM_COMPARE_VALUE);

        #if (1u == QD4_PWM_COMPARE_SWAP)
            QD4_SetCompareSwap(1u);
            QD4_WriteCompareBuf(QD4_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == QD4_PWM_COMPARE_SWAP) */

        #if (1u == QD4_PWM_PERIOD_SWAP)
            QD4_SetPeriodSwap(1u);
            QD4_WritePeriodBuf(QD4_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == QD4_PWM_PERIOD_SWAP) */
    #endif  /* (QD4__PWM_SEL == QD4_CONFIG) */
    
}


/*******************************************************************************
* Function Name: QD4_Enable
********************************************************************************
*
* Summary:
*  Enables the QD4.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void QD4_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    QD4_BLOCK_CONTROL_REG |= QD4_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (QD4__PWM_SEL == QD4_CONFIG)
        #if (0u == QD4_PWM_START_SIGNAL_PRESENT)
            QD4_TriggerCommand(QD4_MASK, QD4_CMD_START);
        #endif /* (0u == QD4_PWM_START_SIGNAL_PRESENT) */
    #endif /* (QD4__PWM_SEL == QD4_CONFIG) */

    #if (QD4__TIMER == QD4_CONFIG)
        #if (0u == QD4_TC_START_SIGNAL_PRESENT)
            QD4_TriggerCommand(QD4_MASK, QD4_CMD_START);
        #endif /* (0u == QD4_TC_START_SIGNAL_PRESENT) */
    #endif /* (QD4__TIMER == QD4_CONFIG) */
    
    #if (QD4__QUAD == QD4_CONFIG)
        #if (0u != QD4_QUAD_AUTO_START)
            QD4_TriggerCommand(QD4_MASK, QD4_CMD_RELOAD);
        #endif /* (0u != QD4_QUAD_AUTO_START) */
    #endif  /* (QD4__QUAD == QD4_CONFIG) */
}


/*******************************************************************************
* Function Name: QD4_Start
********************************************************************************
*
* Summary:
*  Initializes the QD4 with default customizer
*  values when called the first time and enables the QD4.
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
*  QD4_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time QD4_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the QD4_Start() routine.
*
*******************************************************************************/
void QD4_Start(void)
{
    if (0u == QD4_initVar)
    {
        QD4_Init();
        QD4_initVar = 1u;
    }

    QD4_Enable();
}


/*******************************************************************************
* Function Name: QD4_Stop
********************************************************************************
*
* Summary:
*  Disables the QD4.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void QD4_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD4_BLOCK_CONTROL_REG &= (uint32)~QD4_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD4_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the QD4. This function is used when
*  configured as a generic QD4 and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the QD4 to operate in
*   Values:
*   - QD4_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - QD4_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - QD4_MODE_QUAD - Quadrature decoder
*         - QD4_MODE_PWM - PWM
*         - QD4_MODE_PWM_DT - PWM with dead time
*         - QD4_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void QD4_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD4_CONTROL_REG &= (uint32)~QD4_MODE_MASK;
    QD4_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD4_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - QD4_MODE_X1 - Counts on phi 1 rising
*         - QD4_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - QD4_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void QD4_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD4_CONTROL_REG &= (uint32)~QD4_QUAD_MODE_MASK;
    QD4_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD4_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - QD4_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - QD4_PRESCALE_DIVBY2    - Divide by 2
*         - QD4_PRESCALE_DIVBY4    - Divide by 4
*         - QD4_PRESCALE_DIVBY8    - Divide by 8
*         - QD4_PRESCALE_DIVBY16   - Divide by 16
*         - QD4_PRESCALE_DIVBY32   - Divide by 32
*         - QD4_PRESCALE_DIVBY64   - Divide by 64
*         - QD4_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void QD4_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD4_CONTROL_REG &= (uint32)~QD4_PRESCALER_MASK;
    QD4_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD4_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the QD4 runs
*  continuously or stops when terminal count is reached.  By default the
*  QD4 operates in the continuous mode.
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
void QD4_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD4_CONTROL_REG &= (uint32)~QD4_ONESHOT_MASK;
    QD4_CONTROL_REG |= ((uint32)((oneShotEnable & QD4_1BIT_MASK) <<
                                                               QD4_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD4_SetPWMMode
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
void QD4_SetPWMMode(uint32 modeMask)
{
    QD4_TRIG_CONTROL2_REG = (modeMask & QD4_6BIT_MASK);
}



/*******************************************************************************
* Function Name: QD4_SetPWMSyncKill
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
void QD4_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD4_CONTROL_REG &= (uint32)~QD4_PWM_SYNC_KILL_MASK;
    QD4_CONTROL_REG |= ((uint32)((syncKillEnable & QD4_1BIT_MASK)  <<
                                               QD4_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD4_SetPWMStopOnKill
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
void QD4_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD4_CONTROL_REG &= (uint32)~QD4_PWM_STOP_KILL_MASK;
    QD4_CONTROL_REG |= ((uint32)((stopOnKillEnable & QD4_1BIT_MASK)  <<
                                                         QD4_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD4_SetPWMDeadTime
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
void QD4_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD4_CONTROL_REG &= (uint32)~QD4_PRESCALER_MASK;
    QD4_CONTROL_REG |= ((uint32)((deadTime & QD4_8BIT_MASK) <<
                                                          QD4_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD4_SetPWMInvert
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
*         - QD4_INVERT_LINE   - Inverts the line output
*         - QD4_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void QD4_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD4_CONTROL_REG &= (uint32)~QD4_INV_OUT_MASK;
    QD4_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: QD4_WriteCounter
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
void QD4_WriteCounter(uint32 count)
{
    QD4_COUNTER_REG = (count & QD4_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QD4_ReadCounter
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
uint32 QD4_ReadCounter(void)
{
    return (QD4_COUNTER_REG & QD4_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QD4_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - QD4_COUNT_UP       - Counts up
*     - QD4_COUNT_DOWN     - Counts down
*     - QD4_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - QD4_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void QD4_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD4_CONTROL_REG &= (uint32)~QD4_UPDOWN_MASK;
    QD4_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD4_WritePeriod
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
void QD4_WritePeriod(uint32 period)
{
    QD4_PERIOD_REG = (period & QD4_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QD4_ReadPeriod
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
uint32 QD4_ReadPeriod(void)
{
    return (QD4_PERIOD_REG & QD4_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QD4_SetCompareSwap
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
void QD4_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD4_CONTROL_REG &= (uint32)~QD4_RELOAD_CC_MASK;
    QD4_CONTROL_REG |= (swapEnable & QD4_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD4_WritePeriodBuf
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
void QD4_WritePeriodBuf(uint32 periodBuf)
{
    QD4_PERIOD_BUF_REG = (periodBuf & QD4_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QD4_ReadPeriodBuf
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
uint32 QD4_ReadPeriodBuf(void)
{
    return (QD4_PERIOD_BUF_REG & QD4_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QD4_SetPeriodSwap
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
void QD4_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD4_CONTROL_REG &= (uint32)~QD4_RELOAD_PERIOD_MASK;
    QD4_CONTROL_REG |= ((uint32)((swapEnable & QD4_1BIT_MASK) <<
                                                            QD4_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD4_WriteCompare
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
void QD4_WriteCompare(uint32 compare)
{
    #if (QD4_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (QD4_CY_TCPWM_4000) */

    #if (QD4_CY_TCPWM_4000)
        currentMode = ((QD4_CONTROL_REG & QD4_UPDOWN_MASK) >> QD4_UPDOWN_SHIFT);

        if (((uint32)QD4__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)QD4__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (QD4_CY_TCPWM_4000) */
    
    QD4_COMP_CAP_REG = (compare & QD4_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QD4_ReadCompare
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
uint32 QD4_ReadCompare(void)
{
    #if (QD4_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (QD4_CY_TCPWM_4000) */

    #if (QD4_CY_TCPWM_4000)
        currentMode = ((QD4_CONTROL_REG & QD4_UPDOWN_MASK) >> QD4_UPDOWN_SHIFT);
        
        regVal = QD4_COMP_CAP_REG;
        
        if (((uint32)QD4__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)QD4__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & QD4_16BIT_MASK);
    #else
        return (QD4_COMP_CAP_REG & QD4_16BIT_MASK);
    #endif /* (QD4_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: QD4_WriteCompareBuf
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
void QD4_WriteCompareBuf(uint32 compareBuf)
{
    #if (QD4_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (QD4_CY_TCPWM_4000) */

    #if (QD4_CY_TCPWM_4000)
        currentMode = ((QD4_CONTROL_REG & QD4_UPDOWN_MASK) >> QD4_UPDOWN_SHIFT);

        if (((uint32)QD4__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)QD4__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (QD4_CY_TCPWM_4000) */
    
    QD4_COMP_CAP_BUF_REG = (compareBuf & QD4_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QD4_ReadCompareBuf
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
uint32 QD4_ReadCompareBuf(void)
{
    #if (QD4_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (QD4_CY_TCPWM_4000) */

    #if (QD4_CY_TCPWM_4000)
        currentMode = ((QD4_CONTROL_REG & QD4_UPDOWN_MASK) >> QD4_UPDOWN_SHIFT);

        regVal = QD4_COMP_CAP_BUF_REG;
        
        if (((uint32)QD4__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)QD4__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & QD4_16BIT_MASK);
    #else
        return (QD4_COMP_CAP_BUF_REG & QD4_16BIT_MASK);
    #endif /* (QD4_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: QD4_ReadCapture
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
uint32 QD4_ReadCapture(void)
{
    return (QD4_COMP_CAP_REG & QD4_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QD4_ReadCaptureBuf
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
uint32 QD4_ReadCaptureBuf(void)
{
    return (QD4_COMP_CAP_BUF_REG & QD4_16BIT_MASK);
}


/*******************************************************************************
* Function Name: QD4_SetCaptureMode
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
*     - QD4_TRIG_LEVEL     - Level
*     - QD4_TRIG_RISING    - Rising edge
*     - QD4_TRIG_FALLING   - Falling edge
*     - QD4_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void QD4_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD4_TRIG_CONTROL1_REG &= (uint32)~QD4_CAPTURE_MASK;
    QD4_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD4_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - QD4_TRIG_LEVEL     - Level
*     - QD4_TRIG_RISING    - Rising edge
*     - QD4_TRIG_FALLING   - Falling edge
*     - QD4_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void QD4_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD4_TRIG_CONTROL1_REG &= (uint32)~QD4_RELOAD_MASK;
    QD4_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << QD4_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD4_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - QD4_TRIG_LEVEL     - Level
*     - QD4_TRIG_RISING    - Rising edge
*     - QD4_TRIG_FALLING   - Falling edge
*     - QD4_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void QD4_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD4_TRIG_CONTROL1_REG &= (uint32)~QD4_START_MASK;
    QD4_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << QD4_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD4_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - QD4_TRIG_LEVEL     - Level
*     - QD4_TRIG_RISING    - Rising edge
*     - QD4_TRIG_FALLING   - Falling edge
*     - QD4_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void QD4_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD4_TRIG_CONTROL1_REG &= (uint32)~QD4_STOP_MASK;
    QD4_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << QD4_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD4_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - QD4_TRIG_LEVEL     - Level
*     - QD4_TRIG_RISING    - Rising edge
*     - QD4_TRIG_FALLING   - Falling edge
*     - QD4_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void QD4_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD4_TRIG_CONTROL1_REG &= (uint32)~QD4_COUNT_MASK;
    QD4_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << QD4_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD4_TriggerCommand
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
*     - QD4_CMD_CAPTURE    - Trigger Capture/Switch command
*     - QD4_CMD_RELOAD     - Trigger Reload/Index command
*     - QD4_CMD_STOP       - Trigger Stop/Kill command
*     - QD4_CMD_START      - Trigger Start/phiB command
*
* Return:
*  None
*
*******************************************************************************/
void QD4_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    QD4_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: QD4_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the QD4.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - QD4_STATUS_DOWN    - Set if counting down
*     - QD4_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 QD4_ReadStatus(void)
{
    return ((QD4_STATUS_REG >> QD4_RUNNING_STATUS_SHIFT) |
            (QD4_STATUS_REG & QD4_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: QD4_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - QD4_INTR_MASK_TC       - Terminal count mask
*     - QD4_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void QD4_SetInterruptMode(uint32 interruptMask)
{
    QD4_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: QD4_GetInterruptSourceMasked
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
*     - QD4_INTR_MASK_TC       - Terminal count mask
*     - QD4_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 QD4_GetInterruptSourceMasked(void)
{
    return (QD4_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: QD4_GetInterruptSource
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
*     - QD4_INTR_MASK_TC       - Terminal count mask
*     - QD4_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 QD4_GetInterruptSource(void)
{
    return (QD4_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: QD4_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - QD4_INTR_MASK_TC       - Terminal count mask
*     - QD4_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void QD4_ClearInterrupt(uint32 interruptMask)
{
    QD4_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: QD4_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - QD4_INTR_MASK_TC       - Terminal count mask
*     - QD4_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void QD4_SetInterrupt(uint32 interruptMask)
{
    QD4_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
