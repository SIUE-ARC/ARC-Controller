/*******************************************************************************
* File Name: USBFS_ep1_dma.h
* Version 1.0
*
* Description:
*  This file contains all of the channel DMA API functions.
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "USBFS_ep1_dma.h"

uint8 USBFS_ep1_dma_initVar = 0u;


/*******************************************************************************
* Function Name: USBFS_ep1_dma_Start
********************************************************************************
*
* Summary:
*  Calls Init() to configure the DMA channel based on the customizer settings if
*  the channel has not been initialized before.
*  Sets source and destination address, validates descriptor 0 and enables the
*  channel. After calling this function the DMA channel is active and waiting
*  for a trigger.
*
* Parameters:
*  srcAddress: Address of DMA transfer source for descriptor 0.
*  dstAddress: Address of DMA transfer destination for descriptor 0.
*                   
* Return:
*  None.
*
*******************************************************************************/
void USBFS_ep1_dma_Start(void * srcAddress, void * dstAddress)
{
    if(0u == USBFS_ep1_dma_initVar)
    {
        USBFS_ep1_dma_Init();
        USBFS_ep1_dma_initVar = 1u;
    }
    CyDmaEnable();
    USBFS_ep1_dma_SetSrcAddress(0, srcAddress);
    USBFS_ep1_dma_SetDstAddress(0, dstAddress);
    USBFS_ep1_dma_ValidateDescriptor(0);
    USBFS_ep1_dma_ChEnable();
}


/*******************************************************************************
* Function Name: USBFS_ep1_dma_Init
********************************************************************************
*
* Summary:
*  Initializes the DMA channel based on the parameters set in the component
*  customizer. It is not necessary to call USBFS_ep1_dma_Init() because the
*  USBFS_ep1_dma_Start() API calls this function, which is the preferred method
*  to begin component operation.
*
* Parameters:
*  None.
*                   
* Return:
*  None.
*
* Side effect:
*  The first descriptor is set to descriptor 0. This function should not be
*  called while the channel is enabled. All settings will be reset to their
*  initial values.
*
*******************************************************************************/
void USBFS_ep1_dma_Init(void)
{
    CYDMA_CH_CTL_BASE.ctl[USBFS_ep1_dma_CHANNEL] = USBFS_ep1_dma_CHANNEL_CFG;
    CYDMA_DESCR_BASE.descriptor[USBFS_ep1_dma_CHANNEL][0].ctl = USBFS_ep1_dma_DESCR0_CFG;
    CYDMA_DESCR_BASE.descriptor[USBFS_ep1_dma_CHANNEL][1].ctl = USBFS_ep1_dma_DESCR1_CFG;

    /* If the Generate IRQ option is selected for descriptor 0 or 1, set the
    * channel bit field in the DMA interrupt mask register.
    */
    #if (0u != ((USBFS_ep1_dma_DESCR0_CFG | USBFS_ep1_dma_DESCR1_CFG) & CYDMA_GENERATE_IRQ))
        CYDMA_INTR_MASK_REG |= USBFS_ep1_dma_CHANNEL_MASK;
    #endif /* (0u != ((USBFS_ep1_dma_DESCR0_CFG | USBFS_ep1_dma_DESCR1_CFG) & CYDMA_GENERATE_IRQ)) */
}


/* [] END OF FILE */
