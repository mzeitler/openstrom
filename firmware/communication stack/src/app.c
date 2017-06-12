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
static uint8_t usartRWTxData[] = "Hello World\r\n";
static enum 
{
    USART_RW_INIT,
    USART_RW_STAGE_START,
    USART_RW_STAGE_TXRX,
    USART_RW_STAGE_DELAY,
    USART_RW_STAGE_END,
    USART_RW_DONE
} usartRWState;
static char appMsgToClient[] = "Hello Client!\n\r";
static uint8_t appMsgFromClient[80];

static TCPIP_NET_HANDLE    	app_netH;
static SYS_STATUS          	app_tcpipStat;
static int                 	app_nNets;

static uint8_t *AT_Command_List[] = {
                "AT",
                "AT+RST",
                "AT+MGR",
                "AT+CWLAP",
                "AT+CWJAP?",
                "AT+CWQAP=?",
                "AT+CIFSR",
                "AT+ CWSAP?",
                "AT+CWMODE?",
                "AT+CIPSTART=?",
                "AT+ CIPMUX?",
                "AT+CWLIF",
                "AT+CIPSTATUS"
};

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

size_t txIdx,txB,rxB,txL,rxL,dly;
uint8_t txBuf[32];
uint8_t rxBuf[32];

static void USART_Task (void)
{
    switch (usartRWState)
    {
        default:
        case USART_RW_INIT:
        {
            txIdx = 0;
            usartRWState = USART_RW_STAGE_START;
            break;
        }
        
        case USART_RW_STAGE_START:
        {
            txB=0; rxB=0;
            txL=strlen(AT_Command_List[txIdx]);
            rxL=25;
            sprintf(txBuf,"%s",AT_Command_List[txIdx]);
            usartRWState = USART_RW_STAGE_TXRX;
            break;
        }
        
        case USART_RW_STAGE_TXRX:
        {
            if(txB<txL) {
                txB += DRV_USART_Write(appData.handleUSART0,&AT_Command_List[txIdx]+txB,txL-txB);
            }
            if(rxB<rxL) {
                rxB += DRV_USART_Read(appData.handleUSART0,&rxBuf[rxB],rxL-rxB);
            }
            if(txB==txL && rxB==rxL) {
                dly = 0;
                usartRWState = USART_RW_STAGE_DELAY;
            }
            break;
        }
        
        case USART_RW_STAGE_DELAY:
        {
            dly++;
            if(dly==10000) {
                usartRWState = USART_RW_STAGE_END;
            }
            break;
        }
        
        case USART_RW_STAGE_END:
        {
            txIdx++;
            if (txIdx<13) {
                usartRWState = USART_RW_STAGE_START;
            } else {
                usartRWState = USART_RW_DONE;
            }
            break;
        }
        
        case USART_RW_DONE:
        {
            break;
        }
    }
}

/******************************************************************************
  Function:
    static void TCP_Server_TXRX_Task (void)
    
   Remarks:
    Feeds the USB write function. 
*/
static void TCP_Server_TXRX_Task (void)
{
	static IPV4_ADDR    		dwLastIP[2] = { {-1}, {-1} };
	static IPV4_ADDR           	ipAddr;
	int                 		i;
	NET_PRES_SKT_ERROR_T 		error;

	switch (appData.txrxTaskState)
	{
        case APP_TCPIP_WAIT_FOR_IP:
        {
            app_nNets = TCPIP_STACK_NumberOfNetworksGet();

            for (i = 0; i < app_nNets; i++)
            {
                app_netH = TCPIP_STACK_IndexToNet(i);
                ipAddr.Val = TCPIP_STACK_NetAddress(app_netH);
                if (TCPIP_STACK_NetIsReady(app_netH))
                {
                    appData.txrxTaskState = APP_TCPIP_OPENING_SERVER_SOCKET;
                }
            }
            break;
        }
        case APP_TCPIP_OPENING_SERVER_SOCKET:
        {
            appData.socket = NET_PRES_SocketOpen(0, NET_PRES_SKT_ENCRYPTED_STREAM_SERVER, IP_ADDRESS_TYPE_IPV4, appData.port, 0, &error);
            if (appData.socket == NET_PRES_INVALID_SOCKET)
            {
                break;
            }
            appData.txrxTaskState = APP_TCPIP_WAIT_FOR_CONNECTION;;
        }
        break;

        case APP_TCPIP_WAIT_FOR_CONNECTION:
        {
            if (!NET_PRES_SocketIsConnected(appData.socket))
            {
                break;
            }
			appData.txrxTaskState = APP_TCPIP_NEGOTIATING_SSL;
        }
        break;

		case APP_TCPIP_NEGOTIATING_SSL:
		{
            if (NET_PRES_SocketIsNegotiatingEncryption(appData.socket))
            {
                break;
            }
            if (!NET_PRES_SocketIsSecure(appData.socket))
            {
                appData.txrxTaskState = APP_TCPIP_CLOSING_CONNECTION;
                break;
            }
            appData.txrxTaskState = APP_TCPIP_SENDING_MSG;
		}
        break;

		case APP_TCPIP_SENDING_MSG:
		{
            if (!NET_PRES_SocketIsConnected(appData.socket))
            {
                appData.txrxTaskState = APP_TCPIP_CLOSING_CONNECTION;
                break;
            }
            if (NET_PRES_SocketWriteIsReady(appData.socket, strlen(appMsgToClient), strlen(appMsgToClient)) != 0)
            {
                NET_PRES_SocketWrite(appData.socket, (uint8_t*)appMsgToClient, strlen(appMsgToClient));
                appData.txrxTaskState = APP_TCPIP_WAIT_FOR_RESPONSE;
            }
		}

        case APP_TCPIP_WAIT_FOR_RESPONSE:
        {
            if (!NET_PRES_SocketIsConnected(appData.socket))
            {
                appData.txrxTaskState = APP_TCPIP_WAIT_FOR_IP;
                break;
            }
            if (NET_PRES_SocketReadIsReady(appData.socket))
            {
                NET_PRES_SocketRead(appData.socket, appMsgFromClient, sizeof(appMsgFromClient) - 1);
            }
        }
        break;

        case APP_TCPIP_CLOSING_CONNECTION:
        {
            NET_PRES_SocketClose(appData.socket);
            appData.txrxTaskState = APP_TCPIP_OPENING_SERVER_SOCKET;
        }

        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

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

    appData.handleUSART0 = DRV_HANDLE_INVALID;

    /* initialize the USART state machine */
    usartRWState = USART_RW_INIT;
	appData.port = 49152;
    
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
    int i;

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;
       
            if (appData.handleUSART0 == DRV_HANDLE_INVALID)
            {
                appData.handleUSART0 = DRV_USART_Open(APP_DRV_USART, DRV_IO_INTENT_READWRITE|DRV_IO_INTENT_NONBLOCKING);
                appInitialized &= (DRV_HANDLE_INVALID != appData.handleUSART0);
            }

            app_tcpipStat = TCPIP_STACK_Status(sysObj.tcpip);
            if(app_tcpipStat < 0)
            {   // some error occurred
                appData.state = APP_STATE_ERROR;
				appInitialized = false;
            }
            else if(app_tcpipStat == SYS_STATUS_READY)
            {
                // now that the stack is ready we can check the
                // available interfaces
                app_nNets = TCPIP_STACK_NumberOfNetworksGet();
                for(i = 0; i < app_nNets; i++)
                {
                    app_netH = TCPIP_STACK_IndexToNet(i);
                }
                appData.txrxTaskState = APP_TCPIP_WAIT_FOR_IP;
            }
        
            if (appInitialized)
            {
            
                appData.state = APP_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            USART_Task();
            TCP_Server_TXRX_Task();
        
            break;
        }

        /* TODO: implement your application state machine.*/
        
        case APP_STATE_ERROR:
        {
			break;
		}

        /* The default state should never be executed. */
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
