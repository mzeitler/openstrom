/*******************************************************************************
  MPLAB Harmony Application 
  
  Company:
    OpenStorm Smart Meter UART driver
  
  File Name:
    UART_SM_app.c

  Summary:
    Application Template

  Description:
    This file contains the application logic.
 *******************************************************************************/


/


// *****************************************************************************

// Section: Included Files 

// *****************************************************************************

#include "app.h"

// *****************************************************************************

// Section: Global Variable Definitions

// *****************************************************************************

//const char *string1 = "*** UART Interrupt-driven Application Example ***\r\n";
//const char *string2 = "*** Type some characters and observe the LED turn ON ***\r\n";
char txPowerValueBuff_1[12]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
char txPowerValueBuff_2[12]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
char txPowerValueBuff_3[12]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
char txPowerValueBuff_4[12]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
char txPowerValueBuff_5[12]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
char txPowerValueBuff_6[12]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
char txPowerValueBuff_7[12]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
char txPowerValueBuff_8[12]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
char txPowerValueBuff_9[12]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
char txPowerValueBuff_10[12]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};

/*****************************************************
 * Initialize the application data structure. All
 * application related variables are stored in this
 * data structure.
 *****************************************************/

APP_DATA appData = 
{
};
// *****************************************************************************
/* Driver objects.

  Summary:
    Contains driver objects.

  Description:
    This structure contains driver objects returned by the driver init routines
    to the application. These objects are passed to the driver tasks routines.
*/


APP_DRV_OBJECTS appDrvObject;

// *****************************************************************************

// Section: Application Local Routines

// *****************************************************************************


// *****************************************************************************

// Section: Application Callback Routines

// *****************************************************************************



// *****************************************************************************

// Section: Application Initialization and State Machine

// *****************************************************************************

/******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* TODO: Initialize your application's state machine and other
     * parameters.
     */

    /* Place the App state machine in its initial state. */
    appData.state = USART_ENABLE;
    appData.InterruptFlag = false;
}


/*******************************************************************************
  Function:
    bool WriteString (void)

  Summary:
    Writes a string to the console
*/
bool WriteString(void)
{
    if(*appData.stringPointer == '\0')
    {
        return true;
    }

    /* Write a character at a time, only if transmitter is empty */
    while (PLIB_USART_TransmitterIsEmpty(USART_ID_2))
    {
       int i=0;
 	/* Send measured values */
	for(i0;i<10;i++)
	{
        	PLIB_USART_TransmitterByteSend(USART_ID_2, *appData.stringPointer);

       		 /* Increment to address of next character */
        	appData.stringPointer++;
	}
       // if(*appData.stringPointer == '\0')
      //  {
       //     return true;
       // }
    }
    return true;
}


/*******************************************************************************
  Function:
    bool PutCharacter (const char character)

  Summary:
    Sends a character to the console
*/
bool PutCharacter(const char character)
{
    /* Check if buffer is empty for a new transmission */
    if(PLIB_USART_TransmitterIsEmpty(USART_ID_2))
    {
        /* Send character */
        PLIB_USART_TransmitterByteSend(USART_ID_2, character);
        return true;
    }
    else
        return false;
}


/**********************************************************
 * Application tasks routine. This function implements the
 * application state machine.
 ***********************************************************/
void APP_Tasks ( void )
{
    /* check the application state*/
    switch ( appData.state )
    {
        case USART_ENABLE:
           
            /* Enable the UART module*/
            PLIB_USART_Enable(USART_ID_2);

            appData.stringPointer = txPowerValuesBuff_1;
;

            appData.state =  USART_TRANSMIT_FIRST_STRING;

            break;

        case USART_TRANSMIT_FIRST_STRING:
            if(true == WriteString())
            {
                appData.state = USART_TRANSMIT_SECOND_STRING;
                appData.stringPointer = string2;
            }

            break;

        case USART_TRANSMIT_SECOND_STRING:
            if(true == WriteString())
            {
                appData.state = USART_RECEIVE_DONE;
            }
            break;

        case USART_RECEIVE_DONE:
              if (appData.InterruptFlag)
              {
                  if(true == PutCharacter(appData.data))
                  {
                    BSP_LEDOn(BSP_LED_3);
                    appData.InterruptFlag = false;        
                  }
              }
            break;

        default:
            SYS_DEBUG (SYS_ERROR_FATAL,"ERROR! Invalid state\r\n");
            while (1);

    }

} 

/*******************************************************************************
 End of File
 */

