/*******************************************************************************
* File Name: SRV4.c
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

#include "SRV4.h"

/* Error message for removed <resource> through optimization */
#ifdef SRV4_PWMUDB_genblk1_ctrlreg__REMOVED
    #error PWM_v3_30 detected with a constant 0 for the enable or \
         constant 1 for reset. This will prevent the component from operating.
#endif /* SRV4_PWMUDB_genblk1_ctrlreg__REMOVED */

uint8 SRV4_initVar = 0u;


/*******************************************************************************
* Function Name: SRV4_Start
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
*  SRV4_initVar: Is modified when this function is called for the
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void SRV4_Start(void) 
{
    /* If not Initialized then initialize all required hardware and software */
    if(SRV4_initVar == 0u)
    {
        SRV4_Init();
        SRV4_initVar = 1u;
    }
    SRV4_Enable();

}


/*******************************************************************************
* Function Name: SRV4_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the
*  customizer of the component placed onto schematic. Usually called in
*  SRV4_Start().
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void SRV4_Init(void) 
{
    #if (SRV4_UsingFixedFunction || SRV4_UseControl)
        uint8 ctrl;
    #endif /* (SRV4_UsingFixedFunction || SRV4_UseControl) */

    #if(!SRV4_UsingFixedFunction)
        #if(SRV4_UseStatus)
            /* Interrupt State Backup for Critical Region*/
            uint8 SRV4_interruptState;
        #endif /* (SRV4_UseStatus) */
    #endif /* (!SRV4_UsingFixedFunction) */

    #if (SRV4_UsingFixedFunction)
        /* You are allowed to write the compare value (FF only) */
        SRV4_CONTROL |= SRV4_CFG0_MODE;
        #if (SRV4_DeadBand2_4)
            SRV4_CONTROL |= SRV4_CFG0_DB;
        #endif /* (SRV4_DeadBand2_4) */

        ctrl = SRV4_CONTROL3 & ((uint8 )(~SRV4_CTRL_CMPMODE1_MASK));
        SRV4_CONTROL3 = ctrl | SRV4_DEFAULT_COMPARE1_MODE;

         /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
        SRV4_RT1 &= ((uint8)(~SRV4_RT1_MASK));
        SRV4_RT1 |= SRV4_SYNC;

        /*Enable DSI Sync all all inputs of the PWM*/
        SRV4_RT1 &= ((uint8)(~SRV4_SYNCDSI_MASK));
        SRV4_RT1 |= SRV4_SYNCDSI_EN;

    #elif (SRV4_UseControl)
        /* Set the default compare mode defined in the parameter */
        ctrl = SRV4_CONTROL & ((uint8)(~SRV4_CTRL_CMPMODE2_MASK)) &
                ((uint8)(~SRV4_CTRL_CMPMODE1_MASK));
        SRV4_CONTROL = ctrl | SRV4_DEFAULT_COMPARE2_MODE |
                                   SRV4_DEFAULT_COMPARE1_MODE;
    #endif /* (SRV4_UsingFixedFunction) */

    #if (!SRV4_UsingFixedFunction)
        #if (SRV4_Resolution == 8)
            /* Set FIFO 0 to 1 byte register for period*/
            SRV4_AUX_CONTROLDP0 |= (SRV4_AUX_CTRL_FIFO0_CLR);
        #else /* (SRV4_Resolution == 16)*/
            /* Set FIFO 0 to 1 byte register for period */
            SRV4_AUX_CONTROLDP0 |= (SRV4_AUX_CTRL_FIFO0_CLR);
            SRV4_AUX_CONTROLDP1 |= (SRV4_AUX_CTRL_FIFO0_CLR);
        #endif /* (SRV4_Resolution == 8) */

        SRV4_WriteCounter(SRV4_INIT_PERIOD_VALUE);
    #endif /* (!SRV4_UsingFixedFunction) */

    SRV4_WritePeriod(SRV4_INIT_PERIOD_VALUE);

        #if (SRV4_UseOneCompareMode)
            SRV4_WriteCompare(SRV4_INIT_COMPARE_VALUE1);
        #else
            SRV4_WriteCompare1(SRV4_INIT_COMPARE_VALUE1);
            SRV4_WriteCompare2(SRV4_INIT_COMPARE_VALUE2);
        #endif /* (SRV4_UseOneCompareMode) */

        #if (SRV4_KillModeMinTime)
            SRV4_WriteKillTime(SRV4_MinimumKillTime);
        #endif /* (SRV4_KillModeMinTime) */

        #if (SRV4_DeadBandUsed)
            SRV4_WriteDeadTime(SRV4_INIT_DEAD_TIME);
        #endif /* (SRV4_DeadBandUsed) */

    #if (SRV4_UseStatus || SRV4_UsingFixedFunction)
        SRV4_SetInterruptMode(SRV4_INIT_INTERRUPTS_MODE);
    #endif /* (SRV4_UseStatus || SRV4_UsingFixedFunction) */

    #if (SRV4_UsingFixedFunction)
        /* Globally Enable the Fixed Function Block chosen */
        SRV4_GLOBAL_ENABLE |= SRV4_BLOCK_EN_MASK;
        /* Set the Interrupt source to come from the status register */
        SRV4_CONTROL2 |= SRV4_CTRL2_IRQ_SEL;
    #else
        #if(SRV4_UseStatus)

            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            SRV4_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            SRV4_STATUS_AUX_CTRL |= SRV4_STATUS_ACTL_INT_EN_MASK;

             /* Exit Critical Region*/
            CyExitCriticalSection(SRV4_interruptState);

            /* Clear the FIFO to enable the SRV4_STATUS_FIFOFULL
                   bit to be set on FIFO full. */
            SRV4_ClearFIFO();
        #endif /* (SRV4_UseStatus) */
    #endif /* (SRV4_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: SRV4_Enable
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
void SRV4_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (SRV4_UsingFixedFunction)
        SRV4_GLOBAL_ENABLE |= SRV4_BLOCK_EN_MASK;
        SRV4_GLOBAL_STBY_ENABLE |= SRV4_BLOCK_STBY_EN_MASK;
    #endif /* (SRV4_UsingFixedFunction) */

    /* Enable the PWM from the control register  */
    #if (SRV4_UseControl || SRV4_UsingFixedFunction)
        SRV4_CONTROL |= SRV4_CTRL_ENABLE;
    #endif /* (SRV4_UseControl || SRV4_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: SRV4_Stop
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
void SRV4_Stop(void) 
{
    #if (SRV4_UseControl || SRV4_UsingFixedFunction)
        SRV4_CONTROL &= ((uint8)(~SRV4_CTRL_ENABLE));
    #endif /* (SRV4_UseControl || SRV4_UsingFixedFunction) */

    /* Globally disable the Fixed Function Block chosen */
    #if (SRV4_UsingFixedFunction)
        SRV4_GLOBAL_ENABLE &= ((uint8)(~SRV4_BLOCK_EN_MASK));
        SRV4_GLOBAL_STBY_ENABLE &= ((uint8)(~SRV4_BLOCK_STBY_EN_MASK));
    #endif /* (SRV4_UsingFixedFunction) */
}

#if (SRV4_UseOneCompareMode)
    #if (SRV4_CompareMode1SW)


        /*******************************************************************************
        * Function Name: SRV4_SetCompareMode
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
        void SRV4_SetCompareMode(uint8 comparemode) 
        {
            #if(SRV4_UsingFixedFunction)

                #if(0 != SRV4_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemodemasked = ((uint8)((uint8)comparemode << SRV4_CTRL_CMPMODE1_SHIFT));
                #else
                    uint8 comparemodemasked = comparemode;
                #endif /* (0 != SRV4_CTRL_CMPMODE1_SHIFT) */

                SRV4_CONTROL3 &= ((uint8)(~SRV4_CTRL_CMPMODE1_MASK)); /*Clear Existing Data */
                SRV4_CONTROL3 |= comparemodemasked;

            #elif (SRV4_UseControl)

                #if(0 != SRV4_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemode1masked = ((uint8)((uint8)comparemode << SRV4_CTRL_CMPMODE1_SHIFT)) &
                                                SRV4_CTRL_CMPMODE1_MASK;
                #else
                    uint8 comparemode1masked = comparemode & SRV4_CTRL_CMPMODE1_MASK;
                #endif /* (0 != SRV4_CTRL_CMPMODE1_SHIFT) */

                #if(0 != SRV4_CTRL_CMPMODE2_SHIFT)
                    uint8 comparemode2masked = ((uint8)((uint8)comparemode << SRV4_CTRL_CMPMODE2_SHIFT)) &
                                               SRV4_CTRL_CMPMODE2_MASK;
                #else
                    uint8 comparemode2masked = comparemode & SRV4_CTRL_CMPMODE2_MASK;
                #endif /* (0 != SRV4_CTRL_CMPMODE2_SHIFT) */

                /*Clear existing mode */
                SRV4_CONTROL &= ((uint8)(~(SRV4_CTRL_CMPMODE1_MASK |
                                            SRV4_CTRL_CMPMODE2_MASK)));
                SRV4_CONTROL |= (comparemode1masked | comparemode2masked);

            #else
                uint8 temp = comparemode;
            #endif /* (SRV4_UsingFixedFunction) */
        }
    #endif /* SRV4_CompareMode1SW */

#else /* UseOneCompareMode */

    #if (SRV4_CompareMode1SW)


        /*******************************************************************************
        * Function Name: SRV4_SetCompareMode1
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
        void SRV4_SetCompareMode1(uint8 comparemode) 
        {
            #if(0 != SRV4_CTRL_CMPMODE1_SHIFT)
                uint8 comparemodemasked = ((uint8)((uint8)comparemode << SRV4_CTRL_CMPMODE1_SHIFT)) &
                                           SRV4_CTRL_CMPMODE1_MASK;
            #else
                uint8 comparemodemasked = comparemode & SRV4_CTRL_CMPMODE1_MASK;
            #endif /* (0 != SRV4_CTRL_CMPMODE1_SHIFT) */

            #if (SRV4_UseControl)
                SRV4_CONTROL &= ((uint8)(~SRV4_CTRL_CMPMODE1_MASK)); /*Clear existing mode */
                SRV4_CONTROL |= comparemodemasked;
            #endif /* (SRV4_UseControl) */
        }
    #endif /* SRV4_CompareMode1SW */

#if (SRV4_CompareMode2SW)


    /*******************************************************************************
    * Function Name: SRV4_SetCompareMode2
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
    void SRV4_SetCompareMode2(uint8 comparemode) 
    {

        #if(0 != SRV4_CTRL_CMPMODE2_SHIFT)
            uint8 comparemodemasked = ((uint8)((uint8)comparemode << SRV4_CTRL_CMPMODE2_SHIFT)) &
                                                 SRV4_CTRL_CMPMODE2_MASK;
        #else
            uint8 comparemodemasked = comparemode & SRV4_CTRL_CMPMODE2_MASK;
        #endif /* (0 != SRV4_CTRL_CMPMODE2_SHIFT) */

        #if (SRV4_UseControl)
            SRV4_CONTROL &= ((uint8)(~SRV4_CTRL_CMPMODE2_MASK)); /*Clear existing mode */
            SRV4_CONTROL |= comparemodemasked;
        #endif /* (SRV4_UseControl) */
    }
    #endif /*SRV4_CompareMode2SW */

#endif /* UseOneCompareMode */


#if (!SRV4_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: SRV4_WriteCounter
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
    void SRV4_WriteCounter(uint16 counter) \
                                       
    {
        CY_SET_REG16(SRV4_COUNTER_LSB_PTR, counter);
    }


    /*******************************************************************************
    * Function Name: SRV4_ReadCounter
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
    uint16 SRV4_ReadCounter(void) 
    {
        /* Force capture by reading Accumulator */
        /* Must first do a software capture to be able to read the counter */
        /* It is up to the user code to make sure there isn't already captured data in the FIFO */
          (void)CY_GET_REG8(SRV4_COUNTERCAP_LSB_PTR_8BIT);

        /* Read the data from the FIFO */
        return (CY_GET_REG16(SRV4_CAPTURE_LSB_PTR));
    }

    #if (SRV4_UseStatus)


        /*******************************************************************************
        * Function Name: SRV4_ClearFIFO
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
        void SRV4_ClearFIFO(void) 
        {
            while(0u != (SRV4_ReadStatusRegister() & SRV4_STATUS_FIFONEMPTY))
            {
                (void)SRV4_ReadCapture();
            }
        }

    #endif /* SRV4_UseStatus */

#endif /* !SRV4_UsingFixedFunction */


/*******************************************************************************
* Function Name: SRV4_WritePeriod
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
void SRV4_WritePeriod(uint16 period) 
{
    #if(SRV4_UsingFixedFunction)
        CY_SET_REG16(SRV4_PERIOD_LSB_PTR, (uint16)period);
    #else
        CY_SET_REG16(SRV4_PERIOD_LSB_PTR, period);
    #endif /* (SRV4_UsingFixedFunction) */
}

#if (SRV4_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: SRV4_WriteCompare
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
    void SRV4_WriteCompare(uint16 compare) \
                                       
    {
        #if(SRV4_UsingFixedFunction)
            CY_SET_REG16(SRV4_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(SRV4_COMPARE1_LSB_PTR, compare);
        #endif /* (SRV4_UsingFixedFunction) */

        #if (SRV4_PWMMode == SRV4__B_PWM__DITHER)
            #if(SRV4_UsingFixedFunction)
                CY_SET_REG16(SRV4_COMPARE2_LSB_PTR, (uint16)(compare + 1u));
            #else
                CY_SET_REG16(SRV4_COMPARE2_LSB_PTR, (compare + 1u));
            #endif /* (SRV4_UsingFixedFunction) */
        #endif /* (SRV4_PWMMode == SRV4__B_PWM__DITHER) */
    }


#else


    /*******************************************************************************
    * Function Name: SRV4_WriteCompare1
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
    void SRV4_WriteCompare1(uint16 compare) \
                                        
    {
        #if(SRV4_UsingFixedFunction)
            CY_SET_REG16(SRV4_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(SRV4_COMPARE1_LSB_PTR, compare);
        #endif /* (SRV4_UsingFixedFunction) */
    }


    /*******************************************************************************
    * Function Name: SRV4_WriteCompare2
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
    void SRV4_WriteCompare2(uint16 compare) \
                                        
    {
        #if(SRV4_UsingFixedFunction)
            CY_SET_REG16(SRV4_COMPARE2_LSB_PTR, compare);
        #else
            CY_SET_REG16(SRV4_COMPARE2_LSB_PTR, compare);
        #endif /* (SRV4_UsingFixedFunction) */
    }
#endif /* UseOneCompareMode */

#if (SRV4_DeadBandUsed)


    /*******************************************************************************
    * Function Name: SRV4_WriteDeadTime
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
    void SRV4_WriteDeadTime(uint8 deadtime) 
    {
        /* If using the Dead Band 1-255 mode then just write the register */
        #if(!SRV4_DeadBand2_4)
            CY_SET_REG8(SRV4_DEADBAND_COUNT_PTR, deadtime);
        #else
            /* Otherwise the data has to be masked and offset */
            /* Clear existing data */
            SRV4_DEADBAND_COUNT &= ((uint8)(~SRV4_DEADBAND_COUNT_MASK));

            /* Set new dead time */
            #if(SRV4_DEADBAND_COUNT_SHIFT)
                SRV4_DEADBAND_COUNT |= ((uint8)((uint8)deadtime << SRV4_DEADBAND_COUNT_SHIFT)) &
                                                    SRV4_DEADBAND_COUNT_MASK;
            #else
                SRV4_DEADBAND_COUNT |= deadtime & SRV4_DEADBAND_COUNT_MASK;
            #endif /* (SRV4_DEADBAND_COUNT_SHIFT) */

        #endif /* (!SRV4_DeadBand2_4) */
    }


    /*******************************************************************************
    * Function Name: SRV4_ReadDeadTime
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
    uint8 SRV4_ReadDeadTime(void) 
    {
        /* If using the Dead Band 1-255 mode then just read the register */
        #if(!SRV4_DeadBand2_4)
            return (CY_GET_REG8(SRV4_DEADBAND_COUNT_PTR));
        #else

            /* Otherwise the data has to be masked and offset */
            #if(SRV4_DEADBAND_COUNT_SHIFT)
                return ((uint8)(((uint8)(SRV4_DEADBAND_COUNT & SRV4_DEADBAND_COUNT_MASK)) >>
                                                                           SRV4_DEADBAND_COUNT_SHIFT));
            #else
                return (SRV4_DEADBAND_COUNT & SRV4_DEADBAND_COUNT_MASK);
            #endif /* (SRV4_DEADBAND_COUNT_SHIFT) */
        #endif /* (!SRV4_DeadBand2_4) */
    }
#endif /* DeadBandUsed */

#if (SRV4_UseStatus || SRV4_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: SRV4_SetInterruptMode
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
    void SRV4_SetInterruptMode(uint8 interruptMode) 
    {
        CY_SET_REG8(SRV4_STATUS_MASK_PTR, interruptMode);
    }


    /*******************************************************************************
    * Function Name: SRV4_ReadStatusRegister
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
    uint8 SRV4_ReadStatusRegister(void) 
    {
        return (CY_GET_REG8(SRV4_STATUS_PTR));
    }

#endif /* (SRV4_UseStatus || SRV4_UsingFixedFunction) */


#if (SRV4_UseControl)


    /*******************************************************************************
    * Function Name: SRV4_ReadControlRegister
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
    uint8 SRV4_ReadControlRegister(void) 
    {
        uint8 result;

        result = CY_GET_REG8(SRV4_CONTROL_PTR);
        return (result);
    }


    /*******************************************************************************
    * Function Name: SRV4_WriteControlRegister
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
    void SRV4_WriteControlRegister(uint8 control) 
    {
        CY_SET_REG8(SRV4_CONTROL_PTR, control);
    }

#endif /* (SRV4_UseControl) */


#if (!SRV4_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: SRV4_ReadCapture
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
    uint16 SRV4_ReadCapture(void) 
    {
        return (CY_GET_REG16(SRV4_CAPTURE_LSB_PTR));
    }

#endif /* (!SRV4_UsingFixedFunction) */


#if (SRV4_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: SRV4_ReadCompare
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
    uint16 SRV4_ReadCompare(void) 
    {
        #if(SRV4_UsingFixedFunction)
            return ((uint16)CY_GET_REG16(SRV4_COMPARE1_LSB_PTR));
        #else
            return (CY_GET_REG16(SRV4_COMPARE1_LSB_PTR));
        #endif /* (SRV4_UsingFixedFunction) */
    }

#else


    /*******************************************************************************
    * Function Name: SRV4_ReadCompare1
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
    uint16 SRV4_ReadCompare1(void) 
    {
        return (CY_GET_REG16(SRV4_COMPARE1_LSB_PTR));
    }


    /*******************************************************************************
    * Function Name: SRV4_ReadCompare2
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
    uint16 SRV4_ReadCompare2(void) 
    {
        return (CY_GET_REG16(SRV4_COMPARE2_LSB_PTR));
    }

#endif /* (SRV4_UseOneCompareMode) */


/*******************************************************************************
* Function Name: SRV4_ReadPeriod
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
uint16 SRV4_ReadPeriod(void) 
{
    #if(SRV4_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(SRV4_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(SRV4_PERIOD_LSB_PTR));
    #endif /* (SRV4_UsingFixedFunction) */
}

#if ( SRV4_KillModeMinTime)


    /*******************************************************************************
    * Function Name: SRV4_WriteKillTime
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
    void SRV4_WriteKillTime(uint8 killtime) 
    {
        CY_SET_REG8(SRV4_KILLMODEMINTIME_PTR, killtime);
    }


    /*******************************************************************************
    * Function Name: SRV4_ReadKillTime
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
    uint8 SRV4_ReadKillTime(void) 
    {
        return (CY_GET_REG8(SRV4_KILLMODEMINTIME_PTR));
    }

#endif /* ( SRV4_KillModeMinTime) */

/* [] END OF FILE */
