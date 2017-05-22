/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "drv_spi.h"

//void Dis(int code);
// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback funtions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;
   // appData.channel[5]={1,2,3,4,5};
    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    int i=0;
    int code=1;
    int channel[5]={1,2,3,4,5};
    /* Check the application's current state. */
    
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            appData.port=0;             //this variables should be initialize         
            appData._bits=0;
            
            Dis(1);
            for(i=0;i<5;i++)            //initialize 10 Channel in 5 sensor ICs STPM34
            {
                Init_STPM34(channel[i],appData.port, appData._bits);
            }
                appData.state=APP_STATE_GET_PARAM;
                break;
        }
        
        case APP_STATE_GET_PARAM:
        {
            PLIB_TMR_Period16BitSet(TMR_ID_1, 0x9887);   //FPBCLK=10Mhz,PS=256, period=9887
            //1.Scan Sensor1 -Channels 1&2 ; get the energy parameters in buf1
            appData._bits=BIT_9;                       //Bit9- CS1 active
            appData.port=IOPORT_G;                    //IOPORT_G=0x05
            GetParamsEnergyPH1(appData.port, appData._bits, buf1);
            GetParamsEnergyPH2(appData.port, appData._bits, buf1);
            
            //2.Scan Sensor2 -Channels 3&4 ; get the energy parameters in buf2
            appData._bits=BIT_5;                       //Bit5 - CS2 active
            appData.port=IOPORT_B;                    //IOPORT_B=0x0
            GetParamsEnergyPH1(appData.port, appData._bits, buf2);
             GetParamsEnergyPH2(appData.port, appData._bits, buf2);
             
            //3.Scan Sensor3 -Channels 5&6 ; get the energy parameters in buf3
            appData._bits=BIT_4;                       //Bit4- CS3 active
            appData.port=IOPORT_B;                    //IOPORT_B=0x0
            GetParamsEnergyPH1(appData.port, appData._bits, buf3);
             GetParamsEnergyPH2(appData.port, appData._bits, buf3);
             
            //4.Scan Sensor4 -Channels 7&8 ; get the energy parameters in buf4
            appData._bits=BIT_2;                       //Bit2- CS4 active
            appData.port=IOPORT_B;                    //IOPORT_B=0x0
            GetParamsEnergyPH1(appData.port, appData._bits, buf4);
             GetParamsEnergyPH2(appData.port, appData._bits, buf4);
             
            //2.Scan Sensor5 -Channels 9&10 ; get the energy parameters in buf5
            appData._bits=BIT_3;                       //Bit3- CS5 active
            appData.port=IOPORT_B;                    //IOPORT_G=0x0
            
            GetParamsEnergyPH1(appData.port, appData._bits, buf5);
            GetParamsEnergyPH2(appData.port, appData._bits, buf5);
            
            appData.state=APP_STATE_SEND_PARAM_ETH;
            break;
        }  
        
       
        
        case APP_STATE_SEND_PARAM_ETH:
        {
            
            /*TO DO code for Ethernet communication*/
            
            appData.state=APP_STATE_SEND_PARAM_WIFI;
            break;
        }
        case APP_STATE_SEND_PARAM_WIFI:
        {
            /*TO DO code for WiFi communication*/
            appData.state=APP_STATE_SEND_PARAM_ZIGBEE;
            break;
        }
        case APP_STATE_SEND_PARAM_ZIGBEE:
        {
             /*TO DO code for ZigBee communication*/
            appData.state=APP_STATE_INIT;
            break;
        }
        
        case APP_STATE_ERROR:
        {
             /* Test failed*/
            //BSP_LEDOn(BSP_LED_9);  //????
            break;
        }
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}
 

/*******************************************************************************
 End of File
 */
