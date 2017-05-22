/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
    Microchip Technology Inc.

  File Name:
    app.h

  Summary:
    This header file provides prototypes and definitions for the application.

  Description:
    This header file provides function prototypes and data type definitions for
    the application.  Some of these are required by the system (such as the
    "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
    internally by the application (such as the "APP_STATES" definition).  Both
    are defined here for convenience.
*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
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

#ifndef _APP_H
#define _APP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "system_config.h"
#include "system_definitions.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END 

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************
    typedef uintptr_t DRV_HANDLE;
// *****************************************************************************
/* Application states

  Summary:
    Smart Meter(SM) Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
 * DATE: 20.03.2017
*/
    
typedef enum
{
	/* Application's state machine's initial state. */
	APP_STATE_INIT=0,
    //APP_STATE_RELAY_OFF,
   // APP_STATE_CHARGING_ON,        
    APP_STATE_GET_PARAM,
    APP_STATE_SEND_PARAM_ETH,
    APP_STATE_SEND_PARAM_WIFI,
    APP_STATE_SEND_PARAM_ZIGBEE,
   // APP_STATE_SPIFLASH_PROG,
    APP_STATE_ERROR,
	/* TODO: Define states used by the application state machine. */

} APP_STATES;

uint32_t buf1[12];              //contains energy params for Channels 1&2               
uint32_t buf2[12];              //contains energy params for Channels 3&4 
uint32_t buf3[12];              //contains energy params for Channels 5&6 
uint32_t buf4[12];              //contains energy params for Channels 7&8 
uint32_t buf5[12];              //contains energy params for Channels 9&10 


// *****************************************************************************
/* Application Data

  Summary:
    SmartMeter(SM) Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    Application strings and buffers are be defined outside this structure.
 
 * DATA:    20.03.2017
 */

typedef struct
{
    /* The application's current state */
    APP_STATES state;
    unsigned int port;
    unsigned int _bits;
   
    /* SPI Driver Handle  */
    DRV_HANDLE              drvSPIHandle;

    /* Write buffer handle */
   // DRV_SPI_BUFFER_HANDLE   drvSPIWRBUFHandle;

    /* Read buffer handle */
   // DRV_SPI_BUFFER_HANDLE   drvSPIRDBUFHandle;

    /* SPI Driver TX buffer  */
 //   SPI_DATA_TYPE           drvSPITXbuffer[MAX_NUM_OF_BYTES_IN_BUF];

    /* SPI Driver RX buffer  */
 //   SPI_DATA_TYPE           drvSPIRXbuffer[MAX_NUM_OF_BYTES_IN_BUF];


} APP_DATA;

typedef enum {
#ifdef _PORTA
        IOPORT_A,
#endif
#ifdef _PORTB
        IOPORT_B,
#endif
#ifdef _PORTC
        IOPORT_C,
#endif
#ifdef _PORTD
        IOPORT_D,
#endif
#ifdef _PORTE
        IOPORT_E,
#endif
#ifdef _PORTF
        IOPORT_F,
#endif
#ifdef _PORTG
        IOPORT_G,
#endif
    IOPORT_NUM
} IoPortId;

#define BIT_31                        (1 << 31)
 #define BIT_30                       (1 << 30)
 #define BIT_29                       (1 << 29)
 #define BIT_28                       (1 << 28)
 #define BIT_27                       (1 << 27)
 #define BIT_26                       (1 << 26)
 #define BIT_25                       (1 << 25)
 #define BIT_24                       (1 << 24)
 #define BIT_23                       (1 << 23)
 #define BIT_22                       (1 << 22)
 #define BIT_21                       (1 << 21)
 #define BIT_20                       (1 << 20)
 #define BIT_19                       (1 << 19)
 #define BIT_18                       (1 << 18)
 #define BIT_17                       (1 << 17)
 #define BIT_16                       (1 << 16)
 #define BIT_15                       (1 << 15)
 #define BIT_14                       (1 << 14)
 #define BIT_13                       (1 << 13)
 #define BIT_12                       (1 << 12)
 #define BIT_11                       (1 << 11)
 #define BIT_10                       (1 << 10)
 #define BIT_9                        (1 << 9)
 #define BIT_8                        (1 << 8)
 #define BIT_7                        (1 << 7)
 #define BIT_6                        (1 << 6)
 #define BIT_5                        (1 << 5)
 #define BIT_4                        (1 << 4)
 #define BIT_3                        (1 << 3)
 #define BIT_2                        (1 << 2)
 #define BIT_1                        (1 << 1)
 #define BIT_0                        (1 << 0)
// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

	
// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Summary:
     MPLAB Harmony application initialization routine.

  Description:
    This function initializes the Harmony application.  It places the 
    application in its initial state and prepares it to run so that its 
    APP_Tasks function can be called.

  Precondition:
    All other system initialization routines should be called before calling
    this routine (in "SYS_Initialize").

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Initialize();
    </code>

  Remarks:
    This routine must be called from the SYS_Initialize function.
*/

void APP_Initialize ( void );


/*******************************************************************************
  Function:
    void APP_Tasks ( void )

  Summary:
    MPLAB Harmony Demo application tasks function

  Description:
    This routine is the Harmony Demo application's tasks function.  It
    defines the application's state machine and core logic.

  Precondition:
    The system and application initialization ("SYS_Initialize") should be
    called before calling this.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>
    APP_Tasks();
    </code>

  Remarks:
    This routine must be called from SYS_Tasks() routine.
 */

void APP_Tasks( void );


#endif /* _APP_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

