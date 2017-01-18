/*******************************************************************************
* File Name: SRV1.c
* Version 3.30
*
* Description:
*  The PWM User Module consist of an 8 or 16-bit counter with two 8 or 16-bit
*  comparitors. Each instance of this user module is capable of generating
*  two PWM outputs with the same period. The pulse width is selectable between
*  1 and 255/65535. The period is selectable between 2 and 255/65536 clocks.
*  The compare value output may be configured to be active when the present
*  counter is less than or less than/equal to the compare value.
*  A terminal count output is also provided. It generates a pulse one clock
*  width wide when the counter is equal to zero.
*
* Note:
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "SRV1.h"

/* Error message for removed <resource> through optimization */
#ifdef SRV1_PWMUDB_genblk1_ctrlreg__REMOVED
    #error PWM_v3_30 detected with a constant 0 for the enable or \
         constant 1 for reset. This will prevent the component from operating.
#endif /* SRV1_PWMUDB_genblk1_ctrlreg__REMOVED */

uint8 SRV1_initVar = 0u;


/*******************************************************************************
* Function Name: SRV1_Start
********************************************************************************
*
* Summary:
*  The start function initializes the pwm with the default values, the
*  enables the counter to begin counting.  It does not enable interrupts,
*  the EnableInt command should be called if interrupt generation is required.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  SRV1_initVar: Is modified when this function is called for the
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void SRV1_Start(void) 
{
    /* If not Initialized then initialize all required hardware and software */
    if(SRV1_initVar == 0u)
    {
        SRV1_Init();
        SRV1_initVar = 1u;
    }
    SRV1_Enable();

}


/*******************************************************************************
* Function Name: SRV1_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the
*  customizer of the component placed onto schematic. Usually called in
*  SRV1_Start().
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SRV1_Init(void) 
{
    #if (SRV1_UsingFixedFunction || SRV1_UseControl)
        uint8 ctrl;
    #endif /* (SRV1_UsingFixedFunction || SRV1_UseControl) */

    #if(!SRV1_UsingFixedFunction)
        #if(SRV1_UseStatus)
            /* Interrupt State Backup for Critical Region*/
            uint8 SRV1_interruptState;
        #endif /* (SRV1_UseStatus) */
    #endif /* (!SRV1_UsingFixedFunction) */

    #if (SRV1_UsingFixedFunction)
        /* You are allowed to write the compare value (FF only) */
        SRV1_CONTROL |= SRV1_CFG0_MODE;
        #if (SRV1_DeadBand2_4)
            SRV1_CONTROL |= SRV1_CFG0_DB;
        #endif /* (SRV1_DeadBand2_4) */

        ctrl = SRV1_CONTROL3 & ((uint8 )(~SRV1_CTRL_CMPMODE1_MASK));
        SRV1_CONTROL3 = ctrl | SRV1_DEFAULT_COMPARE1_MODE;

         /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
        SRV1_RT1 &= ((uint8)(~SRV1_RT1_MASK));
        SRV1_RT1 |= SRV1_SYNC;

        /*Enable DSI Sync all all inputs of the PWM*/
        SRV1_RT1 &= ((uint8)(~SRV1_SYNCDSI_MASK));
        SRV1_RT1 |= SRV1_SYNCDSI_EN;

    #elif (SRV1_UseControl)
        /* Set the default compare mode defined in the parameter */
        ctrl = SRV1_CONTROL & ((uint8)(~SRV1_CTRL_CMPMODE2_MASK)) &
                ((uint8)(~SRV1_CTRL_CMPMODE1_MASK));
        SRV1_CONTROL = ctrl | SRV1_DEFAULT_COMPARE2_MODE |
                                   SRV1_DEFAULT_COMPARE1_MODE;
    #endif /* (SRV1_UsingFixedFunction) */

    #if (!SRV1_UsingFixedFunction)
        #if (SRV1_Resolution == 8)
            /* Set FIFO 0 to 1 byte register for period*/
            SRV1_AUX_CONTROLDP0 |= (SRV1_AUX_CTRL_FIFO0_CLR);
        #else /* (SRV1_Resolution == 16)*/
            /* Set FIFO 0 to 1 byte register for period */
            SRV1_AUX_CONTROLDP0 |= (SRV1_AUX_CTRL_FIFO0_CLR);
            SRV1_AUX_CONTROLDP1 |= (SRV1_AUX_CTRL_FIFO0_CLR);
        #endif /* (SRV1_Resolution == 8) */

        SRV1_WriteCounter(SRV1_INIT_PERIOD_VALUE);
    #endif /* (!SRV1_UsingFixedFunction) */

    SRV1_WritePeriod(SRV1_INIT_PERIOD_VALUE);

        #if (SRV1_UseOneCompareMode)
            SRV1_WriteCompare(SRV1_INIT_COMPARE_VALUE1);
        #else
            SRV1_WriteCompare1(SRV1_INIT_COMPARE_VALUE1);
            SRV1_WriteCompare2(SRV1_INIT_COMPARE_VALUE2);
        #endif /* (SRV1_UseOneCompareMode) */

        #if (SRV1_KillModeMinTime)
            SRV1_WriteKillTime(SRV1_MinimumKillTime);
        #endif /* (SRV1_KillModeMinTime) */

        #if (SRV1_DeadBandUsed)
            SRV1_WriteDeadTime(SRV1_INIT_DEAD_TIME);
        #endif /* (SRV1_DeadBandUsed) */

    #if (SRV1_UseStatus || SRV1_UsingFixedFunction)
        SRV1_SetInterruptMode(SRV1_INIT_INTERRUPTS_MODE);
    #endif /* (SRV1_UseStatus || SRV1_UsingFixedFunction) */

    #if (SRV1_UsingFixedFunction)
        /* Globally Enable the Fixed Function Block chosen */
        SRV1_GLOBAL_ENABLE |= SRV1_BLOCK_EN_MASK;
        /* Set the Interrupt source to come from the status register */
        SRV1_CONTROL2 |= SRV1_CTRL2_IRQ_SEL;
    #else
        #if(SRV1_UseStatus)

            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            SRV1_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            SRV1_STATUS_AUX_CTRL |= SRV1_STATUS_ACTL_INT_EN_MASK;

             /* Exit Critical Region*/
            CyExitCriticalSection(SRV1_interruptState);

            /* Clear the FIFO to enable the SRV1_STATUS_FIFOFULL
                   bit to be set on FIFO full. */
            SRV1_ClearFIFO();
        #endif /* (SRV1_UseStatus) */
    #endif /* (SRV1_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: SRV1_Enable
********************************************************************************
*
* Summary:
*  Enables the PWM block operation
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  This works only if software enable mode is chosen
*
*******************************************************************************/
void SRV1_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (SRV1_UsingFixedFunction)
        SRV1_GLOBAL_ENABLE |= SRV1_BLOCK_EN_MASK;
        SRV1_GLOBAL_STBY_ENABLE |= SRV1_BLOCK_STBY_EN_MASK;
    #endif /* (SRV1_UsingFixedFunction) */

    /* Enable the PWM from the control register  */
    #if (SRV1_UseControl || SRV1_UsingFixedFunction)
        SRV1_CONTROL |= SRV1_CTRL_ENABLE;
    #endif /* (SRV1_UseControl || SRV1_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: SRV1_Stop
********************************************************************************
*
* Summary:
*  The stop function halts the PWM, but does not change any modes or disable
*  interrupts.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  If the Enable mode is set to Hardware only then this function
*  has no effect on the operation of the PWM
*
*******************************************************************************/
void SRV1_Stop(void) 
{
    #if (SRV1_UseControl || SRV1_UsingFixedFunction)
        SRV1_CONTROL &= ((uint8)(~SRV1_CTRL_ENABLE));
    #endif /* (SRV1_UseControl || SRV1_UsingFixedFunction) */

    /* Globally disable the Fixed Function Block chosen */
    #if (SRV1_UsingFixedFunction)
        SRV1_GLOBAL_ENABLE &= ((uint8)(~SRV1_BLOCK_EN_MASK));
        SRV1_GLOBAL_STBY_ENABLE &= ((uint8)(~SRV1_BLOCK_STBY_EN_MASK));
    #endif /* (SRV1_UsingFixedFunction) */
}

#if (SRV1_UseOneCompareMode)
    #if (SRV1_CompareMode1SW)


        /*******************************************************************************
        * Function Name: SRV1_SetCompareMode
        ********************************************************************************
        *
        * Summary:
        *  This function writes the Compare Mode for the pwm output when in Dither mode,
        *  Center Align Mode or One Output Mode.
        *
        * Parameters:
        *  comparemode:  The new compare mode for the PWM output. Use the compare types
        *                defined in the H file as input arguments.
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void SRV1_SetCompareMode(uint8 comparemode) 
        {
            #if(SRV1_UsingFixedFunction)

                #if(0 != SRV1_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemodemasked = ((uint8)((uint8)comparemode << SRV1_CTRL_CMPMODE1_SHIFT));
                #else
                    uint8 comparemodemasked = comparemode;
                #endif /* (0 != SRV1_CTRL_CMPMODE1_SHIFT) */

                SRV1_CONTROL3 &= ((uint8)(~SRV1_CTRL_CMPMODE1_MASK)); /*Clear Existing Data */
                SRV1_CONTROL3 |= comparemodemasked;

            #elif (SRV1_UseControl)

                #if(0 != SRV1_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemode1masked = ((uint8)((uint8)comparemode << SRV1_CTRL_CMPMODE1_SHIFT)) &
                                                SRV1_CTRL_CMPMODE1_MASK;
                #else
                    uint8 comparemode1masked = comparemode & SRV1_CTRL_CMPMODE1_MASK;
                #endif /* (0 != SRV1_CTRL_CMPMODE1_SHIFT) */

                #if(0 != SRV1_CTRL_CMPMODE2_SHIFT)
                    uint8 comparemode2masked = ((uint8)((uint8)comparemode << SRV1_CTRL_CMPMODE2_SHIFT)) &
                                               SRV1_CTRL_CMPMODE2_MASK;
                #else
                    uint8 comparemode2masked = comparemode & SRV1_CTRL_CMPMODE2_MASK;
                #endif /* (0 != SRV1_CTRL_CMPMODE2_SHIFT) */

                /*Clear existing mode */
                SRV1_CONTROL &= ((uint8)(~(SRV1_CTRL_CMPMODE1_MASK |
                                            SRV1_CTRL_CMPMODE2_MASK)));
                SRV1_CONTROL |= (comparemode1masked | comparemode2masked);

            #else
                uint8 temp = comparemode;
            #endif /* (SRV1_UsingFixedFunction) */
        }
    #endif /* SRV1_CompareMode1SW */

#else /* UseOneCompareMode */

    #if (SRV1_CompareMode1SW)


        /*******************************************************************************
        * Function Name: SRV1_SetCompareMode1
        ********************************************************************************
        *
        * Summary:
        *  This function writes the Compare Mode for the pwm or pwm1 output
        *
        * Parameters:
        *  comparemode:  The new compare mode for the PWM output. Use the compare types
        *                defined in the H file as input arguments.
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void SRV1_SetCompareMode1(uint8 comparemode) 
        {
            #if(0 != SRV1_CTRL_CMPMODE1_SHIFT)
                uint8 comparemodemasked = ((uint8)((uint8)comparemode << SRV1_CTRL_CMPMODE1_SHIFT)) &
                                           SRV1_CTRL_CMPMODE1_MASK;
            #else
                uint8 comparemodemasked = comparemode & SRV1_CTRL_CMPMODE1_MASK;
            #endif /* (0 != SRV1_CTRL_CMPMODE1_SHIFT) */

            #if (SRV1_UseControl)
                SRV1_CONTROL &= ((uint8)(~SRV1_CTRL_CMPMODE1_MASK)); /*Clear existing mode */
                SRV1_CONTROL |= comparemodemasked;
            #endif /* (SRV1_UseControl) */
        }
    #endif /* SRV1_CompareMode1SW */

#if (SRV1_CompareMode2SW)


    /*******************************************************************************
    * Function Name: SRV1_SetCompareMode2
    ********************************************************************************
    *
    * Summary:
    *  This function writes the Compare Mode for the pwm or pwm2 output
    *
    * Parameters:
    *  comparemode:  The new compare mode for the PWM output. Use the compare types
    *                defined in the H file as input arguments.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SRV1_SetCompareMode2(uint8 comparemode) 
    {

        #if(0 != SRV1_CTRL_CMPMODE2_SHIFT)
            uint8 comparemodemasked = ((uint8)((uint8)comparemode << SRV1_CTRL_CMPMODE2_SHIFT)) &
                                                 SRV1_CTRL_CMPMODE2_MASK;
        #else
            uint8 comparemodemasked = comparemode & SRV1_CTRL_CMPMODE2_MASK;
        #endif /* (0 != SRV1_CTRL_CMPMODE2_SHIFT) */

        #if (SRV1_UseControl)
            SRV1_CONTROL &= ((uint8)(~SRV1_CTRL_CMPMODE2_MASK)); /*Clear existing mode */
            SRV1_CONTROL |= comparemodemasked;
        #endif /* (SRV1_UseControl) */
    }
    #endif /*SRV1_CompareMode2SW */

#endif /* UseOneCompareMode */


#if (!SRV1_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: SRV1_WriteCounter
    ********************************************************************************
    *
    * Summary:
    *  Writes a new counter value directly to the counter register. This will be
    *  implemented for that currently running period and only that period. This API
    *  is valid only for UDB implementation and not available for fixed function
    *  PWM implementation.
    *
    * Parameters:
    *  counter:  The period new period counter value.
    *
    * Return:
    *  None
    *
    * Side Effects:
    *  The PWM Period will be reloaded when a counter value will be a zero
    *
    *******************************************************************************/
    void SRV1_WriteCounter(uint16 counter) \
                                       
    {
        CY_SET_REG16(SRV1_COUNTER_LSB_PTR, counter);
    }


    /*******************************************************************************
    * Function Name: SRV1_ReadCounter
    ********************************************************************************
    *
    * Summary:
    *  This function returns the current value of the counter.  It doesn't matter
    *  if the counter is enabled or running.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  The current value of the counter.
    *
    *******************************************************************************/
    uint16 SRV1_ReadCounter(void) 
    {
        /* Force capture by reading Accumulator */
        /* Must first do a software capture to be able to read the counter */
        /* It is up to the user code to make sure there isn't already captured data in the FIFO */
          (void)CY_GET_REG8(SRV1_COUNTERCAP_LSB_PTR_8BIT);

        /* Read the data from the FIFO */
        return (CY_GET_REG16(SRV1_CAPTURE_LSB_PTR));
    }

    #if (SRV1_UseStatus)


        /*******************************************************************************
        * Function Name: SRV1_ClearFIFO
        ********************************************************************************
        *
        * Summary:
        *  This function clears all capture data from the capture FIFO
        *
        * Parameters:
        *  None
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void SRV1_ClearFIFO(void) 
        {
            while(0u != (SRV1_ReadStatusRegister() & SRV1_STATUS_FIFONEMPTY))
            {
                (void)SRV1_ReadCapture();
            }
        }

    #endif /* SRV1_UseStatus */

#endif /* !SRV1_UsingFixedFunction */


/*******************************************************************************
* Function Name: SRV1_WritePeriod
********************************************************************************
*
* Summary:
*  This function is used to change the period of the counter.  The new period
*  will be loaded the next time terminal count is detected.
*
* Parameters:
*  period:  Period value. May be between 1 and (2^Resolution)-1.  A value of 0
*           will result in the counter remaining at zero.
*
* Return:
*  None
*
*******************************************************************************/
void SRV1_WritePeriod(uint16 period) 
{
    #if(SRV1_UsingFixedFunction)
        CY_SET_REG16(SRV1_PERIOD_LSB_PTR, (uint16)period);
    #else
        CY_SET_REG16(SRV1_PERIOD_LSB_PTR, period);
    #endif /* (SRV1_UsingFixedFunction) */
}

#if (SRV1_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: SRV1_WriteCompare
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare1 value when the PWM is in Dither
    *  mode. The compare output will reflect the new value on the next UDB clock.
    *  The compare output will be driven high when the present counter value is
    *  compared to the compare value based on the compare mode defined in
    *  Dither Mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    * Side Effects:
    *  This function is only available if the PWM mode parameter is set to
    *  Dither Mode, Center Aligned Mode or One Output Mode
    *
    *******************************************************************************/
    void SRV1_WriteCompare(uint16 compare) \
                                       
    {
        #if(SRV1_UsingFixedFunction)
            CY_SET_REG16(SRV1_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(SRV1_COMPARE1_LSB_PTR, compare);
        #endif /* (SRV1_UsingFixedFunction) */

        #if (SRV1_PWMMode == SRV1__B_PWM__DITHER)
            #if(SRV1_UsingFixedFunction)
                CY_SET_REG16(SRV1_COMPARE2_LSB_PTR, (uint16)(compare + 1u));
            #else
                CY_SET_REG16(SRV1_COMPARE2_LSB_PTR, (compare + 1u));
            #endif /* (SRV1_UsingFixedFunction) */
        #endif /* (SRV1_PWMMode == SRV1__B_PWM__DITHER) */
    }


#else


    /*******************************************************************************
    * Function Name: SRV1_WriteCompare1
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare1 value.  The compare output will
    *  reflect the new value on the next UDB clock.  The compare output will be
    *  driven high when the present counter value is less than or less than or
    *  equal to the compare register, depending on the mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SRV1_WriteCompare1(uint16 compare) \
                                        
    {
        #if(SRV1_UsingFixedFunction)
            CY_SET_REG16(SRV1_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(SRV1_COMPARE1_LSB_PTR, compare);
        #endif /* (SRV1_UsingFixedFunction) */
    }


    /*******************************************************************************
    * Function Name: SRV1_WriteCompare2
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare value, for compare1 output.
    *  The compare output will reflect the new value on the next UDB clock.
    *  The compare output will be driven high when the present counter value is
    *  less than or less than or equal to the compare register, depending on the
    *  mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SRV1_WriteCompare2(uint16 compare) \
                                        
    {
        #if(SRV1_UsingFixedFunction)
            CY_SET_REG16(SRV1_COMPARE2_LSB_PTR, compare);
        #else
            CY_SET_REG16(SRV1_COMPARE2_LSB_PTR, compare);
        #endif /* (SRV1_UsingFixedFunction) */
    }
#endif /* UseOneCompareMode */

#if (SRV1_DeadBandUsed)


    /*******************************************************************************
    * Function Name: SRV1_WriteDeadTime
    ********************************************************************************
    *
    * Summary:
    *  This function writes the dead-band counts to the corresponding register
    *
    * Parameters:
    *  deadtime:  Number of counts for dead time
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SRV1_WriteDeadTime(uint8 deadtime) 
    {
        /* If using the Dead Band 1-255 mode then just write the register */
        #if(!SRV1_DeadBand2_4)
            CY_SET_REG8(SRV1_DEADBAND_COUNT_PTR, deadtime);
        #else
            /* Otherwise the data has to be masked and offset */
            /* Clear existing data */
            SRV1_DEADBAND_COUNT &= ((uint8)(~SRV1_DEADBAND_COUNT_MASK));

            /* Set new dead time */
            #if(SRV1_DEADBAND_COUNT_SHIFT)
                SRV1_DEADBAND_COUNT |= ((uint8)((uint8)deadtime << SRV1_DEADBAND_COUNT_SHIFT)) &
                                                    SRV1_DEADBAND_COUNT_MASK;
            #else
                SRV1_DEADBAND_COUNT |= deadtime & SRV1_DEADBAND_COUNT_MASK;
            #endif /* (SRV1_DEADBAND_COUNT_SHIFT) */

        #endif /* (!SRV1_DeadBand2_4) */
    }


    /*******************************************************************************
    * Function Name: SRV1_ReadDeadTime
    ********************************************************************************
    *
    * Summary:
    *  This function reads the dead-band counts from the corresponding register
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Dead Band Counts
    *
    *******************************************************************************/
    uint8 SRV1_ReadDeadTime(void) 
    {
        /* If using the Dead Band 1-255 mode then just read the register */
        #if(!SRV1_DeadBand2_4)
            return (CY_GET_REG8(SRV1_DEADBAND_COUNT_PTR));
        #else

            /* Otherwise the data has to be masked and offset */
            #if(SRV1_DEADBAND_COUNT_SHIFT)
                return ((uint8)(((uint8)(SRV1_DEADBAND_COUNT & SRV1_DEADBAND_COUNT_MASK)) >>
                                                                           SRV1_DEADBAND_COUNT_SHIFT));
            #else
                return (SRV1_DEADBAND_COUNT & SRV1_DEADBAND_COUNT_MASK);
            #endif /* (SRV1_DEADBAND_COUNT_SHIFT) */
        #endif /* (!SRV1_DeadBand2_4) */
    }
#endif /* DeadBandUsed */

#if (SRV1_UseStatus || SRV1_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: SRV1_SetInterruptMode
    ********************************************************************************
    *
    * Summary:
    *  This function configures the interrupts mask control of theinterrupt
    *  source status register.
    *
    * Parameters:
    *  uint8 interruptMode: Bit field containing the interrupt sources enabled
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SRV1_SetInterruptMode(uint8 interruptMode) 
    {
        CY_SET_REG8(SRV1_STATUS_MASK_PTR, interruptMode);
    }


    /*******************************************************************************
    * Function Name: SRV1_ReadStatusRegister
    ********************************************************************************
    *
    * Summary:
    *  This function returns the current state of the status register.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8 : Current status register value. The status register bits are:
    *  [7:6] : Unused(0)
    *  [5]   : Kill event output
    *  [4]   : FIFO not empty
    *  [3]   : FIFO full
    *  [2]   : Terminal count
    *  [1]   : Compare output 2
    *  [0]   : Compare output 1
    *
    *******************************************************************************/
    uint8 SRV1_ReadStatusRegister(void) 
    {
        return (CY_GET_REG8(SRV1_STATUS_PTR));
    }

#endif /* (SRV1_UseStatus || SRV1_UsingFixedFunction) */


#if (SRV1_UseControl)


    /*******************************************************************************
    * Function Name: SRV1_ReadControlRegister
    ********************************************************************************
    *
    * Summary:
    *  Returns the current state of the control register. This API is available
    *  only if the control register is not removed.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8 : Current control register value
    *
    *******************************************************************************/
    uint8 SRV1_ReadControlRegister(void) 
    {
        uint8 result;

        result = CY_GET_REG8(SRV1_CONTROL_PTR);
        return (result);
    }


    /*******************************************************************************
    * Function Name: SRV1_WriteControlRegister
    ********************************************************************************
    *
    * Summary:
    *  Sets the bit field of the control register. This API is available only if
    *  the control register is not removed.
    *
    * Parameters:
    *  uint8 control: Control register bit field, The status register bits are:
    *  [7]   : PWM Enable
    *  [6]   : Reset
    *  [5:3] : Compare Mode2
    *  [2:0] : Compare Mode2
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SRV1_WriteControlRegister(uint8 control) 
    {
        CY_SET_REG8(SRV1_CONTROL_PTR, control);
    }

#endif /* (SRV1_UseControl) */


#if (!SRV1_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: SRV1_ReadCapture
    ********************************************************************************
    *
    * Summary:
    *  Reads the capture value from the capture FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: The current capture value
    *
    *******************************************************************************/
    uint16 SRV1_ReadCapture(void) 
    {
        return (CY_GET_REG16(SRV1_CAPTURE_LSB_PTR));
    }

#endif /* (!SRV1_UsingFixedFunction) */


#if (SRV1_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: SRV1_ReadCompare
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare output when the PWM Mode parameter is
    *  set to Dither mode, Center Aligned mode, or One Output mode.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value
    *
    *******************************************************************************/
    uint16 SRV1_ReadCompare(void) 
    {
        #if(SRV1_UsingFixedFunction)
            return ((uint16)CY_GET_REG16(SRV1_COMPARE1_LSB_PTR));
        #else
            return (CY_GET_REG16(SRV1_COMPARE1_LSB_PTR));
        #endif /* (SRV1_UsingFixedFunction) */
    }

#else


    /*******************************************************************************
    * Function Name: SRV1_ReadCompare1
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare1 output.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/
    uint16 SRV1_ReadCompare1(void) 
    {
        return (CY_GET_REG16(SRV1_COMPARE1_LSB_PTR));
    }


    /*******************************************************************************
    * Function Name: SRV1_ReadCompare2
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare2 output.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/
    uint16 SRV1_ReadCompare2(void) 
    {
        return (CY_GET_REG16(SRV1_COMPARE2_LSB_PTR));
    }

#endif /* (SRV1_UseOneCompareMode) */


/*******************************************************************************
* Function Name: SRV1_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the period value used by the PWM hardware.
*
* Parameters:
*  None
*
* Return:
*  uint8/16: Period value
*
*******************************************************************************/
uint16 SRV1_ReadPeriod(void) 
{
    #if(SRV1_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(SRV1_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(SRV1_PERIOD_LSB_PTR));
    #endif /* (SRV1_UsingFixedFunction) */
}

#if ( SRV1_KillModeMinTime)


    /*******************************************************************************
    * Function Name: SRV1_WriteKillTime
    ********************************************************************************
    *
    * Summary:
    *  Writes the kill time value used by the hardware when the Kill Mode
    *  is set to Minimum Time.
    *
    * Parameters:
    *  uint8: Minimum Time kill counts
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void SRV1_WriteKillTime(uint8 killtime) 
    {
        CY_SET_REG8(SRV1_KILLMODEMINTIME_PTR, killtime);
    }


    /*******************************************************************************
    * Function Name: SRV1_ReadKillTime
    ********************************************************************************
    *
    * Summary:
    *  Reads the kill time value used by the hardware when the Kill Mode is set
    *  to Minimum Time.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8: The current Minimum Time kill counts
    *
    *******************************************************************************/
    uint8 SRV1_ReadKillTime(void) 
    {
        return (CY_GET_REG8(SRV1_KILLMODEMINTIME_PTR));
    }

#endif /* ( SRV1_KillModeMinTime) */

/* [] END OF FILE */
