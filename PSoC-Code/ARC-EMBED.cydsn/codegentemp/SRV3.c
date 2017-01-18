/*******************************************************************************
* File Name: SRV3.c
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

#include "SRV3.h"

/* Error message for removed <resource> through optimization */
#ifdef SRV3_PWMUDB_genblk1_ctrlreg__REMOVED
    #error PWM_v3_30 detected with a constant 0 for the enable or \
         constant 1 for reset. This will prevent the component from operating.
#endif /* SRV3_PWMUDB_genblk1_ctrlreg__REMOVED */

uint8 SRV3_initVar = 0u;


/*******************************************************************************
* Function Name: SRV3_Start
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
*  SRV3_initVar: Is modified when this function is called for the
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void SRV3_Start(void) 
{
    /* If not Initialized then initialize all required hardware and software */
    if(SRV3_initVar == 0u)
    {
        SRV3_Init();
        SRV3_initVar = 1u;
    }
    SRV3_Enable();

}


/*******************************************************************************
* Function Name: SRV3_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the
*  customizer of the component placed onto schematic. Usually called in
*  SRV3_Start().
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SRV3_Init(void) 
{
    #if (SRV3_UsingFixedFunction || SRV3_UseControl)
        uint8 ctrl;
    #endif /* (SRV3_UsingFixedFunction || SRV3_UseControl) */

    #if(!SRV3_UsingFixedFunction)
        #if(SRV3_UseStatus)
            /* Interrupt State Backup for Critical Region*/
            uint8 SRV3_interruptState;
        #endif /* (SRV3_UseStatus) */
    #endif /* (!SRV3_UsingFixedFunction) */

    #if (SRV3_UsingFixedFunction)
        /* You are allowed to write the compare value (FF only) */
        SRV3_CONTROL |= SRV3_CFG0_MODE;
        #if (SRV3_DeadBand2_4)
            SRV3_CONTROL |= SRV3_CFG0_DB;
        #endif /* (SRV3_DeadBand2_4) */

        ctrl = SRV3_CONTROL3 & ((uint8 )(~SRV3_CTRL_CMPMODE1_MASK));
        SRV3_CONTROL3 = ctrl | SRV3_DEFAULT_COMPARE1_MODE;

         /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
        SRV3_RT1 &= ((uint8)(~SRV3_RT1_MASK));
        SRV3_RT1 |= SRV3_SYNC;

        /*Enable DSI Sync all all inputs of the PWM*/
        SRV3_RT1 &= ((uint8)(~SRV3_SYNCDSI_MASK));
        SRV3_RT1 |= SRV3_SYNCDSI_EN;

    #elif (SRV3_UseControl)
        /* Set the default compare mode defined in the parameter */
        ctrl = SRV3_CONTROL & ((uint8)(~SRV3_CTRL_CMPMODE2_MASK)) &
                ((uint8)(~SRV3_CTRL_CMPMODE1_MASK));
        SRV3_CONTROL = ctrl | SRV3_DEFAULT_COMPARE2_MODE |
                                   SRV3_DEFAULT_COMPARE1_MODE;
    #endif /* (SRV3_UsingFixedFunction) */

    #if (!SRV3_UsingFixedFunction)
        #if (SRV3_Resolution == 8)
            /* Set FIFO 0 to 1 byte register for period*/
            SRV3_AUX_CONTROLDP0 |= (SRV3_AUX_CTRL_FIFO0_CLR);
        #else /* (SRV3_Resolution == 16)*/
            /* Set FIFO 0 to 1 byte register for period */
            SRV3_AUX_CONTROLDP0 |= (SRV3_AUX_CTRL_FIFO0_CLR);
            SRV3_AUX_CONTROLDP1 |= (SRV3_AUX_CTRL_FIFO0_CLR);
        #endif /* (SRV3_Resolution == 8) */

        SRV3_WriteCounter(SRV3_INIT_PERIOD_VALUE);
    #endif /* (!SRV3_UsingFixedFunction) */

    SRV3_WritePeriod(SRV3_INIT_PERIOD_VALUE);

        #if (SRV3_UseOneCompareMode)
            SRV3_WriteCompare(SRV3_INIT_COMPARE_VALUE1);
        #else
            SRV3_WriteCompare1(SRV3_INIT_COMPARE_VALUE1);
            SRV3_WriteCompare2(SRV3_INIT_COMPARE_VALUE2);
        #endif /* (SRV3_UseOneCompareMode) */

        #if (SRV3_KillModeMinTime)
            SRV3_WriteKillTime(SRV3_MinimumKillTime);
        #endif /* (SRV3_KillModeMinTime) */

        #if (SRV3_DeadBandUsed)
            SRV3_WriteDeadTime(SRV3_INIT_DEAD_TIME);
        #endif /* (SRV3_DeadBandUsed) */

    #if (SRV3_UseStatus || SRV3_UsingFixedFunction)
        SRV3_SetInterruptMode(SRV3_INIT_INTERRUPTS_MODE);
    #endif /* (SRV3_UseStatus || SRV3_UsingFixedFunction) */

    #if (SRV3_UsingFixedFunction)
        /* Globally Enable the Fixed Function Block chosen */
        SRV3_GLOBAL_ENABLE |= SRV3_BLOCK_EN_MASK;
        /* Set the Interrupt source to come from the status register */
        SRV3_CONTROL2 |= SRV3_CTRL2_IRQ_SEL;
    #else
        #if(SRV3_UseStatus)

            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            SRV3_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            SRV3_STATUS_AUX_CTRL |= SRV3_STATUS_ACTL_INT_EN_MASK;

             /* Exit Critical Region*/
            CyExitCriticalSection(SRV3_interruptState);

            /* Clear the FIFO to enable the SRV3_STATUS_FIFOFULL
                   bit to be set on FIFO full. */
            SRV3_ClearFIFO();
        #endif /* (SRV3_UseStatus) */
    #endif /* (SRV3_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: SRV3_Enable
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
void SRV3_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (SRV3_UsingFixedFunction)
        SRV3_GLOBAL_ENABLE |= SRV3_BLOCK_EN_MASK;
        SRV3_GLOBAL_STBY_ENABLE |= SRV3_BLOCK_STBY_EN_MASK;
    #endif /* (SRV3_UsingFixedFunction) */

    /* Enable the PWM from the control register  */
    #if (SRV3_UseControl || SRV3_UsingFixedFunction)
        SRV3_CONTROL |= SRV3_CTRL_ENABLE;
    #endif /* (SRV3_UseControl || SRV3_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: SRV3_Stop
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
void SRV3_Stop(void) 
{
    #if (SRV3_UseControl || SRV3_UsingFixedFunction)
        SRV3_CONTROL &= ((uint8)(~SRV3_CTRL_ENABLE));
    #endif /* (SRV3_UseControl || SRV3_UsingFixedFunction) */

    /* Globally disable the Fixed Function Block chosen */
    #if (SRV3_UsingFixedFunction)
        SRV3_GLOBAL_ENABLE &= ((uint8)(~SRV3_BLOCK_EN_MASK));
        SRV3_GLOBAL_STBY_ENABLE &= ((uint8)(~SRV3_BLOCK_STBY_EN_MASK));
    #endif /* (SRV3_UsingFixedFunction) */
}

#if (SRV3_UseOneCompareMode)
    #if (SRV3_CompareMode1SW)


        /*******************************************************************************
        * Function Name: SRV3_SetCompareMode
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
        void SRV3_SetCompareMode(uint8 comparemode) 
        {
            #if(SRV3_UsingFixedFunction)

                #if(0 != SRV3_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemodemasked = ((uint8)((uint8)comparemode << SRV3_CTRL_CMPMODE1_SHIFT));
                #else
                    uint8 comparemodemasked = comparemode;
                #endif /* (0 != SRV3_CTRL_CMPMODE1_SHIFT) */

                SRV3_CONTROL3 &= ((uint8)(~SRV3_CTRL_CMPMODE1_MASK)); /*Clear Existing Data */
                SRV3_CONTROL3 |= comparemodemasked;

            #elif (SRV3_UseControl)

                #if(0 != SRV3_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemode1masked = ((uint8)((uint8)comparemode << SRV3_CTRL_CMPMODE1_SHIFT)) &
                                                SRV3_CTRL_CMPMODE1_MASK;
                #else
                    uint8 comparemode1masked = comparemode & SRV3_CTRL_CMPMODE1_MASK;
                #endif /* (0 != SRV3_CTRL_CMPMODE1_SHIFT) */

                #if(0 != SRV3_CTRL_CMPMODE2_SHIFT)
                    uint8 comparemode2masked = ((uint8)((uint8)comparemode << SRV3_CTRL_CMPMODE2_SHIFT)) &
                                               SRV3_CTRL_CMPMODE2_MASK;
                #else
                    uint8 comparemode2masked = comparemode & SRV3_CTRL_CMPMODE2_MASK;
                #endif /* (0 != SRV3_CTRL_CMPMODE2_SHIFT) */

                /*Clear existing mode */
                SRV3_CONTROL &= ((uint8)(~(SRV3_CTRL_CMPMODE1_MASK |
                                            SRV3_CTRL_CMPMODE2_MASK)));
                SRV3_CONTROL |= (comparemode1masked | comparemode2masked);

            #else
                uint8 temp = comparemode;
            #endif /* (SRV3_UsingFixedFunction) */
        }
    #endif /* SRV3_CompareMode1SW */

#else /* UseOneCompareMode */

    #if (SRV3_CompareMode1SW)


        /*******************************************************************************
        * Function Name: SRV3_SetCompareMode1
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
        void SRV3_SetCompareMode1(uint8 comparemode) 
        {
            #if(0 != SRV3_CTRL_CMPMODE1_SHIFT)
                uint8 comparemodemasked = ((uint8)((uint8)comparemode << SRV3_CTRL_CMPMODE1_SHIFT)) &
                                           SRV3_CTRL_CMPMODE1_MASK;
            #else
                uint8 comparemodemasked = comparemode & SRV3_CTRL_CMPMODE1_MASK;
            #endif /* (0 != SRV3_CTRL_CMPMODE1_SHIFT) */

            #if (SRV3_UseControl)
                SRV3_CONTROL &= ((uint8)(~SRV3_CTRL_CMPMODE1_MASK)); /*Clear existing mode */
                SRV3_CONTROL |= comparemodemasked;
            #endif /* (SRV3_UseControl) */
        }
    #endif /* SRV3_CompareMode1SW */

#if (SRV3_CompareMode2SW)


    /*******************************************************************************
    * Function Name: SRV3_SetCompareMode2
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
    void SRV3_SetCompareMode2(uint8 comparemode) 
    {

        #if(0 != SRV3_CTRL_CMPMODE2_SHIFT)
            uint8 comparemodemasked = ((uint8)((uint8)comparemode << SRV3_CTRL_CMPMODE2_SHIFT)) &
                                                 SRV3_CTRL_CMPMODE2_MASK;
        #else
            uint8 comparemodemasked = comparemode & SRV3_CTRL_CMPMODE2_MASK;
        #endif /* (0 != SRV3_CTRL_CMPMODE2_SHIFT) */

        #if (SRV3_UseControl)
            SRV3_CONTROL &= ((uint8)(~SRV3_CTRL_CMPMODE2_MASK)); /*Clear existing mode */
            SRV3_CONTROL |= comparemodemasked;
        #endif /* (SRV3_UseControl) */
    }
    #endif /*SRV3_CompareMode2SW */

#endif /* UseOneCompareMode */


#if (!SRV3_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: SRV3_WriteCounter
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
    void SRV3_WriteCounter(uint16 counter) \
                                       
    {
        CY_SET_REG16(SRV3_COUNTER_LSB_PTR, counter);
    }


    /*******************************************************************************
    * Function Name: SRV3_ReadCounter
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
    uint16 SRV3_ReadCounter(void) 
    {
        /* Force capture by reading Accumulator */
        /* Must first do a software capture to be able to read the counter */
        /* It is up to the user code to make sure there isn't already captured data in the FIFO */
          (void)CY_GET_REG8(SRV3_COUNTERCAP_LSB_PTR_8BIT);

        /* Read the data from the FIFO */
        return (CY_GET_REG16(SRV3_CAPTURE_LSB_PTR));
    }

    #if (SRV3_UseStatus)


        /*******************************************************************************
        * Function Name: SRV3_ClearFIFO
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
        void SRV3_ClearFIFO(void) 
        {
            while(0u != (SRV3_ReadStatusRegister() & SRV3_STATUS_FIFONEMPTY))
            {
                (void)SRV3_ReadCapture();
            }
        }

    #endif /* SRV3_UseStatus */

#endif /* !SRV3_UsingFixedFunction */


/*******************************************************************************
* Function Name: SRV3_WritePeriod
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
void SRV3_WritePeriod(uint16 period) 
{
    #if(SRV3_UsingFixedFunction)
        CY_SET_REG16(SRV3_PERIOD_LSB_PTR, (uint16)period);
    #else
        CY_SET_REG16(SRV3_PERIOD_LSB_PTR, period);
    #endif /* (SRV3_UsingFixedFunction) */
}

#if (SRV3_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: SRV3_WriteCompare
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
    void SRV3_WriteCompare(uint16 compare) \
                                       
    {
        #if(SRV3_UsingFixedFunction)
            CY_SET_REG16(SRV3_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(SRV3_COMPARE1_LSB_PTR, compare);
        #endif /* (SRV3_UsingFixedFunction) */

        #if (SRV3_PWMMode == SRV3__B_PWM__DITHER)
            #if(SRV3_UsingFixedFunction)
                CY_SET_REG16(SRV3_COMPARE2_LSB_PTR, (uint16)(compare + 1u));
            #else
                CY_SET_REG16(SRV3_COMPARE2_LSB_PTR, (compare + 1u));
            #endif /* (SRV3_UsingFixedFunction) */
        #endif /* (SRV3_PWMMode == SRV3__B_PWM__DITHER) */
    }


#else


    /*******************************************************************************
    * Function Name: SRV3_WriteCompare1
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
    void SRV3_WriteCompare1(uint16 compare) \
                                        
    {
        #if(SRV3_UsingFixedFunction)
            CY_SET_REG16(SRV3_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(SRV3_COMPARE1_LSB_PTR, compare);
        #endif /* (SRV3_UsingFixedFunction) */
    }


    /*******************************************************************************
    * Function Name: SRV3_WriteCompare2
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
    void SRV3_WriteCompare2(uint16 compare) \
                                        
    {
        #if(SRV3_UsingFixedFunction)
            CY_SET_REG16(SRV3_COMPARE2_LSB_PTR, compare);
        #else
            CY_SET_REG16(SRV3_COMPARE2_LSB_PTR, compare);
        #endif /* (SRV3_UsingFixedFunction) */
    }
#endif /* UseOneCompareMode */

#if (SRV3_DeadBandUsed)


    /*******************************************************************************
    * Function Name: SRV3_WriteDeadTime
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
    void SRV3_WriteDeadTime(uint8 deadtime) 
    {
        /* If using the Dead Band 1-255 mode then just write the register */
        #if(!SRV3_DeadBand2_4)
            CY_SET_REG8(SRV3_DEADBAND_COUNT_PTR, deadtime);
        #else
            /* Otherwise the data has to be masked and offset */
            /* Clear existing data */
            SRV3_DEADBAND_COUNT &= ((uint8)(~SRV3_DEADBAND_COUNT_MASK));

            /* Set new dead time */
            #if(SRV3_DEADBAND_COUNT_SHIFT)
                SRV3_DEADBAND_COUNT |= ((uint8)((uint8)deadtime << SRV3_DEADBAND_COUNT_SHIFT)) &
                                                    SRV3_DEADBAND_COUNT_MASK;
            #else
                SRV3_DEADBAND_COUNT |= deadtime & SRV3_DEADBAND_COUNT_MASK;
            #endif /* (SRV3_DEADBAND_COUNT_SHIFT) */

        #endif /* (!SRV3_DeadBand2_4) */
    }


    /*******************************************************************************
    * Function Name: SRV3_ReadDeadTime
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
    uint8 SRV3_ReadDeadTime(void) 
    {
        /* If using the Dead Band 1-255 mode then just read the register */
        #if(!SRV3_DeadBand2_4)
            return (CY_GET_REG8(SRV3_DEADBAND_COUNT_PTR));
        #else

            /* Otherwise the data has to be masked and offset */
            #if(SRV3_DEADBAND_COUNT_SHIFT)
                return ((uint8)(((uint8)(SRV3_DEADBAND_COUNT & SRV3_DEADBAND_COUNT_MASK)) >>
                                                                           SRV3_DEADBAND_COUNT_SHIFT));
            #else
                return (SRV3_DEADBAND_COUNT & SRV3_DEADBAND_COUNT_MASK);
            #endif /* (SRV3_DEADBAND_COUNT_SHIFT) */
        #endif /* (!SRV3_DeadBand2_4) */
    }
#endif /* DeadBandUsed */

#if (SRV3_UseStatus || SRV3_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: SRV3_SetInterruptMode
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
    void SRV3_SetInterruptMode(uint8 interruptMode) 
    {
        CY_SET_REG8(SRV3_STATUS_MASK_PTR, interruptMode);
    }


    /*******************************************************************************
    * Function Name: SRV3_ReadStatusRegister
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
    uint8 SRV3_ReadStatusRegister(void) 
    {
        return (CY_GET_REG8(SRV3_STATUS_PTR));
    }

#endif /* (SRV3_UseStatus || SRV3_UsingFixedFunction) */


#if (SRV3_UseControl)


    /*******************************************************************************
    * Function Name: SRV3_ReadControlRegister
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
    uint8 SRV3_ReadControlRegister(void) 
    {
        uint8 result;

        result = CY_GET_REG8(SRV3_CONTROL_PTR);
        return (result);
    }


    /*******************************************************************************
    * Function Name: SRV3_WriteControlRegister
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
    void SRV3_WriteControlRegister(uint8 control) 
    {
        CY_SET_REG8(SRV3_CONTROL_PTR, control);
    }

#endif /* (SRV3_UseControl) */


#if (!SRV3_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: SRV3_ReadCapture
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
    uint16 SRV3_ReadCapture(void) 
    {
        return (CY_GET_REG16(SRV3_CAPTURE_LSB_PTR));
    }

#endif /* (!SRV3_UsingFixedFunction) */


#if (SRV3_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: SRV3_ReadCompare
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
    uint16 SRV3_ReadCompare(void) 
    {
        #if(SRV3_UsingFixedFunction)
            return ((uint16)CY_GET_REG16(SRV3_COMPARE1_LSB_PTR));
        #else
            return (CY_GET_REG16(SRV3_COMPARE1_LSB_PTR));
        #endif /* (SRV3_UsingFixedFunction) */
    }

#else


    /*******************************************************************************
    * Function Name: SRV3_ReadCompare1
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
    uint16 SRV3_ReadCompare1(void) 
    {
        return (CY_GET_REG16(SRV3_COMPARE1_LSB_PTR));
    }


    /*******************************************************************************
    * Function Name: SRV3_ReadCompare2
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
    uint16 SRV3_ReadCompare2(void) 
    {
        return (CY_GET_REG16(SRV3_COMPARE2_LSB_PTR));
    }

#endif /* (SRV3_UseOneCompareMode) */


/*******************************************************************************
* Function Name: SRV3_ReadPeriod
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
uint16 SRV3_ReadPeriod(void) 
{
    #if(SRV3_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(SRV3_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(SRV3_PERIOD_LSB_PTR));
    #endif /* (SRV3_UsingFixedFunction) */
}

#if ( SRV3_KillModeMinTime)


    /*******************************************************************************
    * Function Name: SRV3_WriteKillTime
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
    void SRV3_WriteKillTime(uint8 killtime) 
    {
        CY_SET_REG8(SRV3_KILLMODEMINTIME_PTR, killtime);
    }


    /*******************************************************************************
    * Function Name: SRV3_ReadKillTime
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
    uint8 SRV3_ReadKillTime(void) 
    {
        return (CY_GET_REG8(SRV3_KILLMODEMINTIME_PTR));
    }

#endif /* ( SRV3_KillModeMinTime) */

/* [] END OF FILE */
