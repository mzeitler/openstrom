/*******************************************************************************
  USART driver static implementation of Read Write model.

  Company:
    Microchip Technology Inc.

  File Name:
    drv_usart_static_read_write.c

  Summary:
    Source code for the USART driver static implementation of File IO data
    transfer model.

  Description:
    This file contains the source code for the static implementation of the
    USART driver File IO data transfer model.

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

extern DRV_USART_OBJ  gDrvUSART0Obj ;

// *****************************************************************************
// *****************************************************************************
// Section: Instance 0 static driver functions
// *****************************************************************************
// *****************************************************************************
size_t DRV_USART0_Read(void * destination,const size_t nBytes)
{
    DRV_USART_OBJ *dObj = (DRV_USART_OBJ*)NULL;
    uint8_t * data;
    size_t count = 0;

    dObj = &gDrvUSART0Obj;

    if((destination == NULL) || (nBytes == 0))
    {
        /* We have a NULL pointer or don't have
           any data to write. */

        SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "\r\nUSART Driver: NULL data pointer or no data to write");
        return 0;
    }

    /* This is a non blocking implementation*/
    
    data = (uint8_t *)destination;

    if(dObj->queueRead != NULL)
    {
        /* This means queue is not empty. We cannot read
           data now. */
        count = 0;
    }
    else
    {
        while((PLIB_USART_ReceiverDataIsAvailable(USART_ID_1)) && (count < nBytes))
        {
            /* We need to check for errors. Store the error
               in the client error field. */
            dObj->error = PLIB_USART_ErrorsGet(USART_ID_1);

            if(dObj->error != DRV_USART_ERROR_NONE)
            {
                /* This means we have an error.*/
                /* Clear error condition */
                _DRV_USART0_ErrorConditionClear();
                        
                return(DRV_USART_READ_ERROR);
            }
            
            /* This is not a blocking implementation. We read
               the hardware till the FIFO is empty. */
            data[count] = PLIB_USART_ReceiverByteReceive(USART_ID_1);
            count ++;
        }
    }
    return(count);
}

size_t DRV_USART0_Write(void * source, const size_t nBytes)
{
    DRV_USART_OBJ *dObj = (DRV_USART_OBJ*)NULL;
    size_t count = 0;
    uint8_t * data;

    dObj = &gDrvUSART0Obj;

    if((source == NULL) || (nBytes == 0))
    {
        /* We have a NULL pointer or don't have
           any data to write. */

        SYS_DEBUG_MESSAGE(SYS_ERROR_DEBUG, "\r\nUSART Driver: NULL data pointer or no data to write");
        return 0;
    }

    data = (uint8_t *)source;

    /* This is a non blocking implementation*/

    if(dObj->queueWrite != NULL)
    {
        /* This means queue is not empty. We cannot send
           data now. */
        count = 0;
    }
    else
    {
        while((!PLIB_USART_TransmitterBufferIsFull(USART_ID_1)) && (count < nBytes))
        {
            /* This is not a blocking implementation. We write
               to the hardware till the FIFO is full. */
            PLIB_USART_TransmitterByteSend(USART_ID_1, data[count]);
            count ++;

            /* We need to check for errors. Store the error
               in the client error field. */

            dObj->error = PLIB_USART_ErrorsGet(USART_ID_1);

            if(dObj->error != DRV_USART_ERROR_NONE)
            {
                /* This means we have an error.*/
                return(DRV_USART_WRITE_ERROR);
            }
        }
    }

    return(count);
}

/*******************************************************************************
 End of File
*/
