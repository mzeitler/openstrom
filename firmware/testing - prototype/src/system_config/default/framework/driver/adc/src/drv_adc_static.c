/*******************************************************************************
  ADC Driver Initialization File

  File Name:
    drv_adc_static.c

  Summary:
    This file contains source code necessary to initialize the ADC driver.

  Description:
    This file contains source code necessary to initialize the system.  It
    implements the "DRV_ADC_Initialize" function, configuration bits, and allocates
    any necessary global system resources, such as the systemObjects structure
    that contains the object handles to all the MPLAB Harmony module objects in
    the system.
 *******************************************************************************/

/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

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

// *****************************************************************************
// *****************************************************************************
// Section: Include Files
// *****************************************************************************
// *****************************************************************************
#include "framework/driver/adc/drv_adc_static.h"
 
// *****************************************************************************
// *****************************************************************************
// Section: ADC Static Driver Functions
// *****************************************************************************
// *****************************************************************************
void DRV_ADC_Initialize(void)
{
    /* Select Clock Source */
    PLIB_ADC_ConversionClockSourceSelect(DRV_ADC_ID_1, ADC_CLOCK_SOURCE_SYSTEM_CLOCK);
    /* Select Clock Prescaler */
    PLIB_ADC_ConversionClockSet(DRV_ADC_ID_1, SYS_CLK_FREQ, 320000000);

    /* Select Power Mode */
    PLIB_ADC_StopInIdleDisable(DRV_ADC_ID_1);
	
    /* Select Voltage Reference */
    PLIB_ADC_VoltageReferenceSelect(DRV_ADC_ID_1, ADC_REFERENCE_VDD_TO_AVSS);

    /* Sampling Selections */
    /* Enable Auto Sample Mode */
    PLIB_ADC_SampleAutoStartEnable(DRV_ADC_ID_1);
    /* Sample Acquisition Time (Auto Sample Mode) */	
    PLIB_ADC_SampleAcquisitionTimeSet(DRV_ADC_ID_1, 31);
    /* Select Sampling Mode */
    PLIB_ADC_SamplingModeSelect(DRV_ADC_ID_1, ADC_SAMPLING_MODE_MUXA);
    /* Number of Samples Per Interrupt */
    PLIB_ADC_SamplesPerInterruptSelect(DRV_ADC_ID_1, ADC_16SAMPLES_PER_INTERRUPT);

    /* Conversion Selections */
    /* Select Trigger Source */
    PLIB_ADC_ConversionTriggerSourceSelect(DRV_ADC_ID_1, ADC_CONVERSION_TRIGGER_SAMP_CLEAR);
    /* Select Result Format */
    PLIB_ADC_ResultFormatSelect(DRV_ADC_ID_1, ADC_RESULT_FORMAT_INTEGER_16BIT);
    /* Buffer Mode */
    PLIB_ADC_ResultBufferModeSelect(DRV_ADC_ID_1, ADC_BUFFER_MODE_ONE_16WORD_BUFFER);

    /* Channel Selections */
    /* MUX A Negative Input Select */
    PLIB_ADC_MuxChannel0InputNegativeSelect(DRV_ADC_ID_1, ADC_MUX_A, ADC_INPUT_NEGATIVE_VREF_MINUS);
 

    /* MUX A Positive Input Select */
    PLIB_ADC_MuxChannel0InputPositiveSelect(DRV_ADC_ID_1, ADC_MUX_A, ADC_INPUT_POSITIVE_AN0);
 
}

inline void DRV_ADC_DeInitialize(void)
{
    /* Disable ADC */
    PLIB_ADC_Disable(DRV_ADC_ID_1);
}

inline void DRV_ADC_Open(void)
{
    /* Enable ADC */
    PLIB_ADC_Enable(DRV_ADC_ID_1);
}

inline void DRV_ADC_Close(void)
{
    /* Disable ADC */
    PLIB_ADC_Disable(DRV_ADC_ID_1);
}

inline void DRV_ADC_Start(void)
{
    /* Start ADC */
    PLIB_ADC_SamplingStart(DRV_ADC_ID_1);
}

inline void DRV_ADC_Stop(void)
{
    /* Stop ADC */
    PLIB_ADC_SamplingStop(DRV_ADC_ID_1);	
}

inline void DRV_ADC_NegativeInputSelect(DRV_ADC_MUX mux, DRV_ADC_INPUTS_NEGATIVE input)
{
    /* Select Negative Input */
    PLIB_ADC_MuxChannel0InputNegativeSelect(DRV_ADC_ID_1, mux, input);
}

inline void DRV_ADC_PositiveInputSelect(DRV_ADC_MUX mux, DRV_ADC_INPUTS_POSITIVE input)
{
    /* Select Positive Input */
    PLIB_ADC_MuxChannel0InputPositiveSelect(DRV_ADC_ID_1, mux, input);
}

inline void DRV_ADC_ChannelScanInputsAdd(DRV_ADC_INPUTS_SCAN scanInput)
{
    /* Add Scan Input */
    PLIB_ADC_InputScanMaskAdd(DRV_ADC_ID_1, scanInput);
}

inline void DRV_ADC_ChannelScanInputsRemove(DRV_ADC_INPUTS_SCAN scanInput)
{
    /* Remove Scan Input */
    PLIB_ADC_InputScanMaskRemove(DRV_ADC_ID_1, scanInput);
}

ADC_SAMPLE DRV_ADC_SamplesRead(uint8_t bufIndex)
{
    /* Read Result */
    return PLIB_ADC_ResultGetByIndex(DRV_ADC_ID_1, bufIndex);
}

bool DRV_ADC_SamplesAvailable(void)
{
    /* Wait for DONE Flag */
    while (!PLIB_ADC_ConversionHasCompleted(DRV_ADC_ID_1));
	
    return true;
}
