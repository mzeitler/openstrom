/*******************************************************************************
  USART Driver Static implementation

  Company:
    Microchip Technology Inc.

  File Name:
    drv_usart_static.c

  Summary:
    Source code for the USART driver static implementation.

  Description:
    The USART device driver provides a simple interface to manage the USART
    modules on Microchip microcontrollers. This file contains static implementation
    for the USART driver.

  Remarks:
    Static interfaces incorporate the driver instance number within the names
    of the routines, eliminating the need for an object ID or object handle.

    Static single-open interfaces also eliminate the need for the open handle.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
//DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "system_config.h"
#include "system_definitions.h"


// *****************************************************************************
// *****************************************************************************
// Section: Global Data
// *****************************************************************************
// *****************************************************************************

/* This is the driver static object . */
DRV_USART_OBJ  gDrvUSART0Obj ;

// *****************************************************************************
// *****************************************************************************
// Section: Instance 0 static driver functions
// *****************************************************************************
// *****************************************************************************

SYS_MODULE_OBJ DRV_USART0_Initialize(void)
{
    uint32_t clockSource;

    DRV_USART_OBJ *dObj = (DRV_USART_OBJ*)NULL;
    dObj = &gDrvUSART0Obj;

    /* Disable the USART module to configure it*/
    PLIB_USART_Disable (USART_ID_1);

    /* Update the USART OBJECT parameters. */
    dObj->interruptNestingCount = 0;
    dObj->queueSizeCurrentRead  = 0;
    dObj->queueSizeCurrentWrite = 0;
    dObj->queueRead             = NULL;
    dObj->queueWrite            = NULL;
    dObj->eventHandler          = NULL;
    dObj->context               = (uintptr_t)NULL;
    dObj->error                 = DRV_USART_ERROR_NONE;

    /* Initialize the USART based on configuration settings */
    PLIB_USART_InitializeModeGeneral(USART_ID_1,
            false,  /*Auto baud*/
            false,  /*LoopBack mode*/
            false,  /*Auto wakeup on start*/
            false,  /*IRDA mode*/
            false);  /*Stop In Idle mode*/

    /* Set the line control mode */
    PLIB_USART_LineControlModeSelect(USART_ID_1, DRV_USART_LINE_CONTROL_8NONE1);

    /* We set the receive interrupt mode to receive an interrupt whenever FIFO
       is not empty */
    PLIB_USART_InitializeOperation(USART_ID_1,
            USART_RECEIVE_FIFO_ONE_CHAR,
            USART_TRANSMIT_FIFO_IDLE,
            USART_ENABLE_TX_RX_USED);

    /* Get the USART clock source value*/
    clockSource = SYS_CLK_PeripheralFrequencyGet ( CLK_BUS_PERIPHERAL_1 );

    /* Set the baud rate and enable the USART */
    PLIB_USART_BaudSetAndEnable(USART_ID_1,
            clockSource,
            115200);  /*Desired Baud rate value*/

    /* Return the driver instance value*/
    return (SYS_MODULE_OBJ)DRV_USART_INDEX_0;
}

void  DRV_USART0_Deinitialize(void)
{
    /* Disable USART module */
    PLIB_USART_Disable (USART_ID_1);

}


SYS_STATUS DRV_USART0_Status(void)
{
    /* Return the status as ready always */
    return SYS_STATUS_READY;
}


void DRV_USART0_TasksTransmit(void)
{
    /* This is the USART Driver Transmit tasks routine.
       In this function, the driver checks if a transmit
       interrupt is active and performs respective action*/

    /* Reading the transmit interrupt flag */
    if(SYS_INT_SourceStatusGet(INT_SOURCE_USART_1_TRANSMIT))
    {
        /* The USART driver is configured to generate an
           interrupt when the FIFO is empty. Additionally
           the queue is not empty. Which means there is
           work to be done in this routine. */
        _DRV_USART0_BufferQueueTxTasks();

        /* Clear up the interrupt flag */
        SYS_INT_SourceStatusClear(INT_SOURCE_USART_1_TRANSMIT);
    }
}

void DRV_USART0_TasksReceive(void)
{
    /* This is the USART Driver Receive tasks routine. If the receive
       interrupt flag is set, the tasks routines are executed.
     */

    /* Reading the receive interrupt flag */
    if(SYS_INT_SourceStatusGet(INT_SOURCE_USART_1_RECEIVE))
    {
        _DRV_USART0_BufferQueueRxTasks();

        /* Clear up the interrupt flag */
        SYS_INT_SourceStatusClear(INT_SOURCE_USART_1_RECEIVE);
    }
}


void DRV_USART0_TasksError(void)
{
    /* This is the USART Driver Error tasks routine. In this function, the
     * driver checks if an error interrupt has occurred. If so the error
     * condition is cleared.  */

    /* Reading the error interrupt flag */
    if(SYS_INT_SourceStatusGet(INT_SOURCE_USART_1_ERROR))
    {
        /* This means an error has occurred */
        _DRV_USART0_BufferQueueErrorTasks();
        /* Clear up the error interrupt flag */
        SYS_INT_SourceStatusClear(INT_SOURCE_USART_1_ERROR);
    }
}

DRV_HANDLE DRV_USART0_Open(const SYS_MODULE_INDEX index, const DRV_IO_INTENT ioIntent)
{

    /* Return the driver instance value*/
    return ((DRV_HANDLE)DRV_USART_INDEX_0 );
}

void DRV_USART0_Close(void)
{
    return;
}

DRV_USART_CLIENT_STATUS DRV_USART0_ClientStatus(void)
{
    /* Return the status as ready always*/
    return DRV_USART_CLIENT_STATUS_READY;
}

DRV_USART_TRANSFER_STATUS DRV_USART0_TransferStatus( void )
{
    DRV_USART_TRANSFER_STATUS result = 0;

    /* Check if RX data available */
    if(PLIB_USART_ReceiverDataIsAvailable(USART_ID_1))
    {
        result|= DRV_USART_TRANSFER_STATUS_RECEIVER_DATA_PRESENT;
    }
    else
    {
        result|= DRV_USART_TRANSFER_STATUS_RECEIVER_EMPTY;
    }

    /* Check if TX Buffer is empty */
    if(PLIB_USART_TransmitterIsEmpty(USART_ID_1))
    {
        result|= DRV_USART_TRANSFER_STATUS_TRANSMIT_EMPTY;
    }

    /* Check if the TX buffer is full */
    if(PLIB_USART_TransmitterBufferIsFull(USART_ID_1))
    {
        result|= DRV_USART_TRANSFER_STATUS_TRANSMIT_FULL;
    }

    return(result);
}

DRV_USART_ERROR DRV_USART0_ErrorGet(void)
{
    DRV_USART_ERROR error;
    error = gDrvUSART0Obj.error;

    /* Clear the error before returning */
    gDrvUSART0Obj.error = DRV_USART_ERROR_NONE;

    /* Return the error*/
    return(error);
}


// *****************************************************************************
// *****************************************************************************
// Section: Local functions
// *****************************************************************************
// *****************************************************************************

void _DRV_USART0_BufferQueueRxTasks(void)
{
    DRV_USART_BUFFER_OBJ * bufferObj;
    DRV_USART_OBJ *dObj = (DRV_USART_OBJ*)NULL;

    dObj = &gDrvUSART0Obj;

    /* In this function, the driver checks if there are any buffers in queue. If
       so the buffer is serviced. A buffer that is serviced completely is
       removed from the queue. Start by getting the buffer at the head of the
       queue */

    bufferObj = dObj->queueRead;

    if(bufferObj != NULL)
    {
        /* The USART driver is configured to generate an interrupt when the FIFO
           is not empty. Additionally the queue is not empty. Which means there
           is work to done in this routine. Read data from the FIFO until either
           the FIFO is empty or until we have read the requested number of bytes.
           */

        while((PLIB_USART_ReceiverDataIsAvailable(USART_ID_1))
                && (bufferObj->nCurrentBytes < bufferObj->size ))
        {
            bufferObj->buffer[bufferObj->nCurrentBytes] = PLIB_USART_ReceiverByteReceive(USART_ID_1);
            bufferObj->nCurrentBytes ++;
        }

        /* Check if this buffer is done */

        if(bufferObj->nCurrentBytes >= bufferObj->size)
        {
            /* This means the buffer is completed. If there
               is a callback registered with client, then
               call it */

            if((dObj->eventHandler != NULL) && (bufferObj->flags & DRV_USART_BUFFER_OBJ_FLAG_BUFFER_ADD))
            {
                /* Call the event handler. We additionally increment the
                   interrupt nesting count which lets the driver functions
                   that are called from the event handler know that an
                   interrupt context is active.
                   */

                dObj->interruptNestingCount ++;

                dObj->eventHandler(DRV_USART_BUFFER_EVENT_COMPLETE,
                        bufferObj->bufferHandle,
                        dObj->context);

                dObj->interruptNestingCount --;
            }

            /* Get the next buffer in the queue and deallocate
               this buffer */

            dObj->queueRead = bufferObj->next;
            bufferObj->inUse = false;
            dObj->queueSizeCurrentRead --;

            /* Reset the next and previous pointers */
            bufferObj->next = NULL;
            bufferObj->previous = NULL;

            /* Reset the current head's previous pointer */
            if (dObj->queueRead != NULL)
            {
                dObj->queueRead->previous = NULL;
            }

        }
    }

}

void _DRV_USART0_BufferQueueTxTasks(void)
{
    /* Start by getting the buffer at the head of queue. */

    DRV_USART_BUFFER_OBJ * bufferObj;
    DRV_USART_OBJ *dObj = (DRV_USART_OBJ*)NULL;

    dObj = &gDrvUSART0Obj;
    bufferObj = dObj->queueWrite;

    if(bufferObj != NULL)
    {
        /* This means the queue is not empty. Check if this buffer is done */
        if(bufferObj->nCurrentBytes >= bufferObj->size)
        {
            /* This means the buffer is completed. If there
               is a callback registered with client, then
               call it */

            if((dObj->eventHandler != NULL) && (bufferObj->flags & DRV_USART_BUFFER_OBJ_FLAG_BUFFER_ADD))
            {
                /* Before calling the event handler, the interrupt nesting
                   counter is incremented. This will allow driver routine that
                   are called from the event handler to know the interrupt
                   nesting level. Events are only generated for buffers that
                   were submitted using the buffer add routine */

                dObj->interruptNestingCount ++;

                dObj->eventHandler(DRV_USART_BUFFER_EVENT_COMPLETE,
                        bufferObj->bufferHandle,
                        dObj->context);

                /* Decrement the nesting count */
                dObj->interruptNestingCount -- ;
            }

            /* Get the next buffer in the queue and deallocate
             * this buffer */

            dObj->queueWrite = bufferObj->next;
            bufferObj->inUse = false;
            dObj->queueSizeCurrentWrite --;

            /* Reset the next and previous pointers */
            bufferObj->next = NULL;
            bufferObj->previous = NULL;

            /* Reset the current head's previous pointer */
            if (dObj->queueWrite != NULL)
            {
                dObj->queueWrite->previous = NULL;
            }

        }
    }

    /* Check if the queue is still not empty and process
       the buffer */

    if(dObj->queueWrite != NULL)
    {
        bufferObj = dObj->queueWrite;

        /* Fill up the FIFO with data until the FIFO is full
           and we have data to send */
        while((!PLIB_USART_TransmitterBufferIsFull(USART_ID_1))
                && (bufferObj->nCurrentBytes < bufferObj->size ))
        {
            PLIB_USART_TransmitterByteSend(USART_ID_1, bufferObj->buffer[bufferObj->nCurrentBytes]);
            bufferObj->nCurrentBytes ++;
        }
    }

}

void _DRV_USART0_BufferQueueErrorTasks(void)
{
    DRV_USART_OBJ *dObj = (DRV_USART_OBJ*)NULL;
    DRV_USART_BUFFER_OBJ * bufferObj;
    bool mutexGrabbed  = true;

    dObj = &gDrvUSART0Obj;

    /* USART driver will take care that TX erros( like overflow etc) are not
     * going to occur at any time based on checks before write.
     * So, only RX errors are to be handled/reported */

    /* Get the RX buffer at the head */
    bufferObj = dObj->queueRead;

    /* mutexGrabbed will always be true for non-RTOS case.
     * Will be false when mutex aquisition timed out in RTOS mode */
    if(true == mutexGrabbed)
    {
        if(bufferObj != NULL)
        {
            /* Get the USART errors */
            dObj->error = PLIB_USART_ErrorsGet(USART_ID_1);

	        /* Clear error condition */
            _DRV_USART0_ErrorConditionClear();

            /* Call event handler in Buffer queue request only.
             * If it's a File i/o request then DRV_USART_Read call itself
             * will return with error result */
            if((dObj->eventHandler != NULL) && (bufferObj->flags & DRV_USART_BUFFER_OBJ_FLAG_BUFFER_ADD))
            {
                /* Call the event handler with buffer event error state */
                dObj->eventHandler(DRV_USART_BUFFER_EVENT_ERROR,
                        bufferObj->bufferHandle,
                        dObj->context);
            }

            /* Get the next buffer in the queue and deallocate
             * this buffer */

            dObj->queueRead = bufferObj->next;
            bufferObj->inUse = false;
            dObj->queueSizeCurrentRead --;

            /* Reset the next and previous pointers */
            bufferObj->next = NULL;
            bufferObj->previous = NULL;

            /* If queue head is not null, update buffer pointer parameters*/
            if (dObj->queueRead != NULL)
            {
                /* Reset the updated head's previous pointer */
                dObj->queueRead->previous = NULL;
            }
        }
    }
}

void _DRV_USART0_ErrorConditionClear()
{
    uint8_t dummyData = 0u;
    /* RX length = (FIFO level + RX register) */
    uint8_t RXlength = _DRV_USART_RX_DEPTH;

    /* If it's a overrun error then clear it to flush FIFO */
    if(USART_ERROR_RECEIVER_OVERRUN & PLIB_USART_ErrorsGet(USART_ID_1))
    {
        PLIB_USART_ReceiverOverrunErrorClear(USART_ID_1);
    }

    /* Read existing error bytes from FIFO to clear parity and framing error flags*/
    while( (USART_ERROR_PARITY | USART_ERROR_FRAMING) & PLIB_USART_ErrorsGet(USART_ID_1) )
    {
        dummyData = PLIB_USART_ReceiverByteReceive(USART_ID_1);
        RXlength--;

        /* Try to flush error bytes for one full FIFO and exit instead of
         * blocking here if more error bytes are received*/
        if(0u == RXlength)
        {
            break;
        }
    }

    /* Ignore the warning */
    (void)dummyData;

    /* Clear error interrupt flag */
    SYS_INT_SourceStatusClear(INT_SOURCE_USART_1_ERROR);

    /* Clear up the receive interrupt flag so that RX interrupt is not
     * triggered for error bytes*/
    SYS_INT_SourceStatusClear(INT_SOURCE_USART_1_RECEIVE);
}



DRV_USART_BAUD_SET_RESULT DRV_USART0_BaudSet(uint32_t baud)
{
    uint32_t clockSource;
    int32_t brgValueLow=0;
    int32_t brgValueHigh=0;
    DRV_USART_BAUD_SET_RESULT retVal = DRV_USART_BAUD_SET_SUCCESS;
#if defined (PLIB_USART_ExistsModuleBusyStatus)
    bool isEnabled = false;
#endif

    /* Get the USART clock source value*/
    clockSource = SYS_CLK_PeripheralFrequencyGet ( CLK_BUS_PERIPHERAL_1 );

    /* Calculate low and high baud values */
    brgValueLow  = ( (clockSource/baud) >> 4 ) - 1;
    brgValueHigh = ( (clockSource/baud) >> 2 ) - 1;

#if defined (PLIB_USART_ExistsModuleBusyStatus)
        isEnabled = PLIB_USART_ModuleIsBusy (USART_ID_1);
        if (isEnabled)
        {
            PLIB_USART_Disable (USART_ID_1);
            while (PLIB_USART_ModuleIsBusy (USART_ID_1));
        }
#endif

    /* Check if the baud value can be set with high baud settings */
    if ((brgValueHigh >= 0) && (brgValueHigh <= UINT16_MAX))
    {
        PLIB_USART_BaudRateHighEnable(USART_ID_1);
        PLIB_USART_BaudRateHighSet(USART_ID_1,clockSource,baud);
    }

    /* Check if the baud value can be set with low baud settings */
    else if ((brgValueLow >= 0) && (brgValueLow <= UINT16_MAX))
    {
        PLIB_USART_BaudRateHighDisable(USART_ID_1);
        PLIB_USART_BaudRateSet(USART_ID_1, clockSource, baud);
    }
    else
    {
            retVal = DRV_USART_BAUD_SET_ERROR;
    }

#if defined (PLIB_USART_ExistsModuleBusyStatus)
    if (isEnabled)
    {
        PLIB_USART_Enable (USART_ID_1);
    }
#endif

    return retVal;
}


DRV_USART_LINE_CONTROL_SET_RESULT DRV_USART0_LineControlSet(DRV_USART_LINE_CONTROL lineControlMode)
{
#if defined (PLIB_USART_ExistsModuleBusyStatus)
    bool isEnabled = false;
#endif
#if defined (PLIB_USART_ExistsModuleBusyStatus)
        isEnabled = PLIB_USART_ModuleIsBusy (USART_ID_1);
        if (isEnabled)
        {
            PLIB_USART_Disable (USART_ID_1);
            while (PLIB_USART_ModuleIsBusy (USART_ID_1));
        }
#endif

    /* Set the Line Control Mode */
    PLIB_USART_LineControlModeSelect(USART_ID_1, lineControlMode);

#if defined (PLIB_USART_ExistsModuleBusyStatus)
        if (isEnabled)
        {
            PLIB_USART_Enable (USART_ID_1);
        }
#endif

    /* Return success */
    return(DRV_USART_LINE_CONTROL_SET_SUCCESS);
}

/*******************************************************************************
 End of File
*/
