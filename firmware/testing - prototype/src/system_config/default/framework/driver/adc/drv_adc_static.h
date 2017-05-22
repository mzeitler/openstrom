/*******************************************************************************
  ADC Driver Interface Declarations for Static Single Instance Driver

  Company:
    Microchip Technology Inc.

  File Name:
    drv_adc_static.h

  Summary:
    ADC driver interface declarations for the static single instance driver.

  Description:
    The ADC device driver provides a simple interface to manage the ADC
    modules on Microchip microcontrollers. This file defines the interface
    Declarations for the ADC driver.
    
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

#ifndef _DRV_ADC_STATIC_H
#define _DRV_ADC_STATIC_H

#include <stdbool.h>
#include "system_config.h"
#include "peripheral/adc/plib_adc.h"

typedef enum {

    DRV_ADC_ID_1 = ADC_ID_1,
    DRV_ADC_NUMBER_OF_MODULES

} DRV_ADC_MODULE_ID;

typedef enum {

    DRV_ADC_MUX_A = ADC_MUX_A,
    DRV_ADC_MUX_B = ADC_MUX_B

} DRV_ADC_MUX;

typedef enum {

    DRV_ADC_FILLING_BUF_0TO7 = ADC_FILLING_BUF_0TO7,
    DRV_ADC_FILLING_BUF_8TOF = ADC_FILLING_BUF_8TOF

} DRV_ADC_RESULT_BUF_STATUS;

typedef enum {

    DRV_ADC_REFERENCE_VDD_TO_AVSS = ADC_REFERENCE_VDD_TO_AVSS,
    DRV_ADC_REFERENCE_VREFPLUS_TO_AVSS = ADC_REFERENCE_VREFPLUS_TO_AVSS,
    DRV_ADC_REFERENCE_AVDD_TO_VREF_NEG = ADC_REFERENCE_AVDD_TO_VREF_NEG,
    DRV_ADC_REFERENCE_VREFPLUS_TO_VREFNEG = ADC_REFERENCE_VREFPLUS_TO_VREFNEG

} DRV_ADC_VOLTAGE_REFERENCE;

typedef enum {

    DRV_ADC_SAMPLING_MODE_ALTERNATE_INPUT = ADC_SAMPLING_MODE_ALTERNATE_INPUT,
    DRV_ADC_SAMPLING_MODE_MUXA = ADC_SAMPLING_MODE_MUXA

} DRV_ADC_SAMPLING_MODE;

typedef enum {
    DRV_ADC_1SAMPLE_PER_INTERRUPT = ADC_1SAMPLE_PER_INTERRUPT,
    DRV_ADC_2SAMPLES_PER_INTERRUPT = ADC_2SAMPLES_PER_INTERRUPT,
    DRV_ADC_3SAMPLES_PER_INTERRUPT = ADC_3SAMPLES_PER_INTERRUPT,
    DRV_ADC_4SAMPLES_PER_INTERRUPT = ADC_4SAMPLES_PER_INTERRUPT,
    DRV_ADC_5SAMPLES_PER_INTERRUPT = ADC_5SAMPLES_PER_INTERRUPT,
    DRV_ADC_6SAMPLES_PER_INTERRUPT = ADC_6SAMPLES_PER_INTERRUPT,
    DRV_ADC_7SAMPLES_PER_INTERRUPT = ADC_7SAMPLES_PER_INTERRUPT,
    DRV_ADC_8SAMPLES_PER_INTERRUPT = ADC_8SAMPLES_PER_INTERRUPT,
    DRV_ADC_9SAMPLES_PER_INTERRUPT = ADC_9SAMPLES_PER_INTERRUPT,
    DRV_ADC_10SAMPLES_PER_INTERRUPT = ADC_10SAMPLES_PER_INTERRUPT,
    DRV_ADC_11SAMPLES_PER_INTERRUPT = ADC_11SAMPLES_PER_INTERRUPT,
    DRV_ADC_12SAMPLES_PER_INTERRUPT = ADC_12SAMPLES_PER_INTERRUPT,
    DRV_ADC_13SAMPLES_PER_INTERRUPT = ADC_13SAMPLES_PER_INTERRUPT,
    DRV_ADC_14SAMPLES_PER_INTERRUPT = ADC_14SAMPLES_PER_INTERRUPT,
    DRV_ADC_15SAMPLES_PER_INTERRUPT = ADC_15SAMPLES_PER_INTERRUPT,
    DRV_ADC_16SAMPLES_PER_INTERRUPT = ADC_16SAMPLES_PER_INTERRUPT

} DRV_ADC_SAMPLES_PER_INTERRUPT;

typedef enum {

    DRV_ADC_INPUT_POSITIVE_AN0 = ADC_INPUT_POSITIVE_AN0,
    DRV_ADC_POSITIVE_INPUT_NUM
	
} DRV_ADC_INPUTS_POSITIVE;

typedef enum {

    DRV_ADC_SCAN_INPUT_NUM
} DRV_ADC_INPUTS_SCAN;


typedef enum {

    DRV_ADC_INPUT_NEGATIVE_VREF_MINUS = ADC_INPUT_NEGATIVE_VREF_MINUS,
    DRV_ADC_INPUT_NEGATIVE_AN1 = ADC_INPUT_NEGATIVE_AN1

} DRV_ADC_INPUTS_NEGATIVE;

typedef enum {

    DRV_ADC_CLOCK_SOURCE_SYSTEM_CLOCK = ADC_CLOCK_SOURCE_SYSTEM_CLOCK,
    DRV_ADC_CLOCK_SOURCE_INTERNAL_RC = ADC_CLOCK_SOURCE_INTERNAL_RC

} DRV_ADC_CLOCK_SOURCE;

typedef enum {

    DRV_ADC_CONVERSION_TRIGGER_SAMP_CLEAR = ADC_CONVERSION_TRIGGER_SAMP_CLEAR,
    DRV_ADC_CONVERSION_TRIGGER_INT0_TRANSITION = ADC_CONVERSION_TRIGGER_INT0_TRANSITION,
    DRV_ADC_CONVERSION_TRIGGER_TMR3_COMPARE_MATCH = ADC_CONVERSION_TRIGGER_TMR3_COMPARE_MATCH,
    DRV_ADC_CONVERSION_TRIGGER_CTMU_EVENT = ADC_CONVERSION_TRIGGER_CTMU_EVENT,
    DRV_ADC_CONVERSION_TRIGGER_INTERNAL_COUNT = ADC_CONVERSION_TRIGGER_INTERNAL_COUNT

} DRV_ADC_CONVERSION_TRIGGER_SOURCE;

typedef enum {

    DRV_ADC_RESULT_FORMAT_INTEGER_16BIT = ADC_RESULT_FORMAT_INTEGER_16BIT,
    DRV_ADC_RESULT_FORMAT_SIGNED_INTEGER_16BIT = ADC_RESULT_FORMAT_SIGNED_INTEGER_16BIT,
    DRV_ADC_RESULT_FORMAT_FRACTIONAL_16BIT = ADC_RESULT_FORMAT_FRACTIONAL_16BIT,
    DRV_ADC_RESULT_FORMAT_SIGNED_FRACTIONAL_16BIT = ADC_RESULT_FORMAT_SIGNED_FRACTIONAL_16BIT,
    DRV_ADC_RESULT_FORMAT_INTEGER_32BIT = ADC_RESULT_FORMAT_INTEGER_32BIT,
    DRV_ADC_RESULT_FORMAT_SIGNED_INTEGER_32BIT = ADC_RESULT_FORMAT_SIGNED_INTEGER_32BIT,
    DRV_ADC_RESULT_FORMAT_FRACTIONAL_32BIT = ADC_RESULT_FORMAT_FRACTIONAL_32BIT,
    DRV_ADC_RESULT_FORMAT_SIGNED_FRACTIONAL_32BIT = ADC_RESULT_FORMAT_SIGNED_FRACTIONAL_32BIT

} DRV_ADC_RESULT_FORMAT;

// *****************************************************************************
// *****************************************************************************
// Section: Interface Headers for ADC Static Driver
// *****************************************************************************
// *****************************************************************************
void DRV_ADC_Initialize(void);

inline void DRV_ADC_DeInitialize(void);

inline void DRV_ADC_Open(void);

inline void DRV_ADC_Close(void);

inline void DRV_ADC_Start(void);

inline void DRV_ADC_Stop(void);

inline void DRV_ADC_NegativeInputSelect(DRV_ADC_MUX mux, DRV_ADC_INPUTS_NEGATIVE input);

inline void DRV_ADC_PositiveInputSelect(DRV_ADC_MUX mux, DRV_ADC_INPUTS_POSITIVE input);

inline void DRV_ADC_ChannelScanInputsAdd(DRV_ADC_INPUTS_SCAN scanInput);

inline void DRV_ADC_ChannelScanInputsRemove(DRV_ADC_INPUTS_SCAN scanInput);

ADC_SAMPLE DRV_ADC_SamplesRead(uint8_t bufIndex);

bool DRV_ADC_SamplesAvailable(void);

#endif // #ifndef _DRV_ADC_STATIC_H

/*******************************************************************************
 End of File
*/
