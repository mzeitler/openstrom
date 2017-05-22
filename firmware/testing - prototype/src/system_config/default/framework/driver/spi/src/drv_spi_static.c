/*******************************************************************************
  SPI Driver Functions for Static Single Instance Driver

  Company:
    Microchip Technology Inc.

  File Name:
    drv_spi_static.c

  Summary:
    SPI driver impementation for the static single instance driver.

  Description:
    The SPI device driver provides a simple interface to manage the SPI
    modules on Microchip microcontrollers. This file contains implemenation
    for the SPI driver.
    
  Remarks:
    Static interfaces incorporate the driver instance number within the names
    of the routines, eliminating the need for an object ID or object handle.
    
    Static single-open interfaces also eliminate the need for the open handle.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

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
// Header Includes
// *****************************************************************************
// *****************************************************************************
#include "system_definitions.h"
#include "framework/driver/spi/drv_spi_static.h"


// *****************************************************************************
// *****************************************************************************
// Section: Instance 0 static driver functions
// *****************************************************************************
// *****************************************************************************

void DRV_SPI0_Initialize(void)
{
    PLIB_SPI_Disable(SPI_ID_2);
    PLIB_SPI_MasterEnable(SPI_ID_2);
    PLIB_SPI_SlaveSelectEnable(SPI_ID_2);
    PLIB_SPI_StopInIdleDisable(SPI_ID_2);
    PLIB_SPI_ClockPolaritySelect(SPI_ID_2, SPI_CLOCK_POLARITY_IDLE_LOW);
    PLIB_SPI_OutputDataPhaseSelect(SPI_ID_2, SPI_OUTPUT_DATA_PHASE_ON_IDLE_TO_ACTIVE_CLOCK);
    PLIB_SPI_InputSamplePhaseSelect(SPI_ID_2, SPI_INPUT_SAMPLING_PHASE_IN_MIDDLE);
    PLIB_SPI_CommunicationWidthSelect(SPI_ID_2, SPI_COMMUNICATION_WIDTH_32BITS);
    PLIB_SPI_FramedCommunicationDisable( SPI_ID_2  );
    PLIB_SPI_FIFOEnable( SPI_ID_2  );
    PLIB_SPI_BaudRateSet(SPI_ID_2, SYS_CLK_PeripheralFrequencyGet(CLK_BUS_PERIPHERAL_2), 20000000);
    PLIB_SPI_Enable(SPI_ID_2);
}

void DRV_SPI0_DeInitialize(void)
{
    /* Disable SPI */
	PLIB_SPI_Disable(SPI_ID_2);
}

bool DRV_SPI0_ReceiverBufferIsFull(void)
{
    return (PLIB_SPI_ReceiverBufferIsFull(SPI_ID_2));
}

bool DRV_SPI0_TransmitterBufferIsFull(void)
{
    return (PLIB_SPI_TransmitBufferIsFull(SPI_ID_2));
}
int32_t DRV_SPI0_BufferAddWriteRead(const void * txBuffer, void * rxBuffer, uint32_t size)
{
    bool continueLoop;
    int32_t txcounter = 0;
    int32_t rxcounter = 0;
    uint8_t unitsTxed = 0;
    const uint8_t maxUnits = 4;
    do {
        continueLoop = false;
        unitsTxed = 0;
        if (PLIB_SPI_TransmitBufferIsEmpty(SPI_ID_2))
        {
            while (!PLIB_SPI_TransmitBufferIsFull(SPI_ID_2) && (txcounter < (size>>2)) && unitsTxed != maxUnits)
            {
                PLIB_SPI_BufferWrite32bit(SPI_ID_2, ((uint32_t*)txBuffer)[txcounter]);
                txcounter++;
                continueLoop = true;
                unitsTxed++;
            }
        }
    
        while (txcounter != rxcounter)
        {
            while (PLIB_SPI_ReceiverFIFOIsEmpty(SPI_ID_2));
            ((uint32_t*)rxBuffer)[rxcounter] = PLIB_SPI_BufferRead32bit(SPI_ID_2);
            rxcounter++;
            continueLoop = true;
        }
        if (txcounter > rxcounter)
        {
            continueLoop = true;
        }
    }while(continueLoop);
    return txcounter<<2;
}
// *****************************************************************************
// *****************************************************************************
// Section: Instance 1 static driver functions
// *****************************************************************************
// *****************************************************************************

void DRV_SPI1_Initialize(void)
{
    PLIB_SPI_Disable(SPI_ID_4);
    PLIB_SPI_MasterEnable(SPI_ID_4);
    PLIB_SPI_SlaveSelectEnable(SPI_ID_4);
    PLIB_SPI_StopInIdleDisable(SPI_ID_4);
    PLIB_SPI_ClockPolaritySelect(SPI_ID_4, SPI_CLOCK_POLARITY_IDLE_LOW);
    PLIB_SPI_OutputDataPhaseSelect(SPI_ID_4, SPI_OUTPUT_DATA_PHASE_ON_IDLE_TO_ACTIVE_CLOCK);
    PLIB_SPI_InputSamplePhaseSelect(SPI_ID_4, SPI_INPUT_SAMPLING_PHASE_IN_MIDDLE);
    PLIB_SPI_CommunicationWidthSelect(SPI_ID_4, SPI_COMMUNICATION_WIDTH_8BITS);
    PLIB_SPI_FramedCommunicationDisable( SPI_ID_4  );
    PLIB_SPI_FIFOEnable( SPI_ID_4  );
    PLIB_SPI_BaudRateSet(SPI_ID_4, SYS_CLK_PeripheralFrequencyGet(CLK_BUS_PERIPHERAL_2), 20000000);
    PLIB_SPI_Enable(SPI_ID_4);
}

void DRV_SPI1_DeInitialize(void)
{
    /* Disable SPI */
	PLIB_SPI_Disable(SPI_ID_4);
}

bool DRV_SPI1_ReceiverBufferIsFull(void)
{
    return (PLIB_SPI_ReceiverBufferIsFull(SPI_ID_4));
}

bool DRV_SPI1_TransmitterBufferIsFull(void)
{
    return (PLIB_SPI_TransmitBufferIsFull(SPI_ID_4));
}
int32_t DRV_SPI1_BufferAddWriteRead(const void * txBuffer, void * rxBuffer, uint32_t size)
{
    bool continueLoop;
    int32_t txcounter = 0;
    int32_t rxcounter = 0;
    uint8_t unitsTxed = 0;
    const uint8_t maxUnits = 16;
    do {
        continueLoop = false;
        unitsTxed = 0;
        if (PLIB_SPI_TransmitBufferIsEmpty(SPI_ID_4))
        {
            while (!PLIB_SPI_TransmitBufferIsFull(SPI_ID_4) && (txcounter < size) && unitsTxed != maxUnits)
            {
                PLIB_SPI_BufferWrite(SPI_ID_4, ((uint8_t*)txBuffer)[txcounter]);
                txcounter++;
                continueLoop = true;
                unitsTxed++;
            }
        }
    
        while (txcounter != rxcounter)
        {
            while (PLIB_SPI_ReceiverFIFOIsEmpty(SPI_ID_4));
            ((uint8_t*)rxBuffer)[rxcounter] = PLIB_SPI_BufferRead(SPI_ID_4);
            rxcounter++;
            continueLoop = true;
        }
        if (txcounter > rxcounter)
        {
            continueLoop = true;
        }
    }while(continueLoop);
    return txcounter;
}

/*******************************************************************************
 End of File
*/
