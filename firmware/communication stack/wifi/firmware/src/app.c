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


#define max_bufsize 100
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

static uint8_t ssid[] = "CU_2p6a";
static uint8_t password[] = "kyr5e94v";
//static uint8_t destDNS[] = "192.168.1.195";
static uint8_t destDNS[] = "techieservice.org";
static uint8_t port[] = "80";

static uint8_t usartRWTxData[] = "Hello World\r\n";
static uint8_t ESP_INIT[] = "AT+RST\r\n";
static uint8_t ESP_CWMODE[] = "AT+CWMODE=1\r\n";
static uint8_t ESP_CWJAP[] = "AT+CWJAP=\"";
static uint8_t ESP_CIPMUX[] = "AT+CIPMUX=0\r\n";
static uint8_t ESP_CIPSTART[] = "AT+CIPSTART=\"TCP\",\"";
static uint8_t ESP_CIPSEND[] = "AT+CIPSEND=";
static uint8_t ESP_CIPCLOSE[] = "AT+CIPCLOSE=0\r\n";

static uint8_t ESP_OK[] = "OK";
static uint8_t esp_cwjap_buf[max_bufsize];
static uint8_t esp_cwjap_count;

static uint8_t esp_connect_buf[max_bufsize];
static uint8_t esp_connect_count;

static uint8_t esp_server[max_bufsize];
static uint8_t esp_server_count;

static uint8_t esp_send_buf[max_bufsize + max_bufsize];
static uint8_t sendcount;
static uint8_t esp_send_count[3];
uint8_t destPHP[] = "GET /mcuworld/test.php?data=";

static uint8_t app_rx_buf[max_bufsize];
//http://techieservice.org/mcuworld/test.php/?data=xx
static enum
{
    WIFI_RST,
    WIFI_INIT,      //AT+RST
    WIFI_INIT_RECEIVE,
    WIFI_CWMODE,    //CWMODE
    WIFI_CWMODE_RECEIVE,
    WIFI_CWJAP,     //CWJAP
    WIFI_CWJAP_RECEIVE,
    WIFI_CIPMUX,    //CIPMUX
    WIFI_CIPMUX_RECEIVE,
    WIFI_CONNECT,   //CIPSTART     
    WIFI_CONNECT_RECEIVE,
    WIFI_CIPSTART, //CIPSTART      
    WIFI_CIPSTART_RECEIVE,
    WIFI_SEND_DATA, //CIPSEND      
    WIFI_SEND_DATA_RECEIVE,
    WIFI_CLOSE,
    
}wifiStatus;
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
void make_cwjap(void)
{
    uint8_t cnt, cur_cnt = 0;
    uint8_t temp_buf1[] = "\",\"";
    uint8_t temp_buf2[] = "\"\r\n";
    
    for(cnt = 0; cnt < (sizeof(ESP_CWJAP) - 1); cnt++)
    {
        esp_cwjap_buf[cnt] = ESP_CWJAP[cnt];
    }
    cur_cnt = cnt;
    
    for(cnt = cur_cnt; cnt < (cur_cnt + sizeof(ssid) - 1); cnt++)
    {
        esp_cwjap_buf[cnt] = ssid[cnt - cur_cnt];
    }
    cur_cnt = cnt;
    
    for(cnt = cur_cnt; cnt < (cur_cnt + sizeof(temp_buf1) - 1); cnt++)
    {
        esp_cwjap_buf[cnt] = temp_buf1[cnt - cur_cnt];
    }
    cur_cnt = cnt;
    
    for(cnt = cur_cnt; cnt < (cur_cnt + sizeof(password) - 1); cnt++)
    {
        esp_cwjap_buf[cnt] = password[cnt - cur_cnt];
    }
    cur_cnt = cnt;
    
    for(cnt = cur_cnt; cnt < (cur_cnt + sizeof(temp_buf2)); cnt++)
    {
        esp_cwjap_buf[cnt] = temp_buf2[cnt - cur_cnt];
    }
    esp_cwjap_count = cnt - 1;
}
void make_connection(void)
{
    uint8_t cnt, cur_cnt;
    uint8_t temp_buf1[] = "\",";
    uint8_t temp_buf2[] = "\r\n";
    
    for(cnt = 0; cnt < (sizeof(ESP_CIPSTART) - 1); cnt++)
    {
        esp_connect_buf[cnt] = ESP_CIPSTART[cnt];
    }
    cur_cnt = cnt;
    
    for(cnt = cur_cnt; cnt < (cur_cnt + sizeof(destDNS) - 1); cnt++)
    {
        esp_connect_buf[cnt] = destDNS[cnt - cur_cnt];
    }
    cur_cnt = cnt;
    
    for(cnt = cur_cnt; cnt < (cur_cnt + sizeof(temp_buf1) - 1); cnt++)
    {
        esp_connect_buf[cnt] = temp_buf1[cnt - cur_cnt];
    }
    cur_cnt = cnt;
    
    for(cnt = cur_cnt; cnt < (cur_cnt + sizeof(port) - 1); cnt++)
    {
        esp_connect_buf[cnt] = port[cnt - cur_cnt];
    }
    cur_cnt = cnt;
    
    for(cnt = cur_cnt; cnt < (cur_cnt + sizeof(temp_buf2)); cnt++)
    {
        esp_connect_buf[cnt] = temp_buf2[cnt - cur_cnt];
    }
    esp_connect_count = cnt - 1;
}
void make_server()
{
    uint8_t cnt, cur_cnt;
    uint8_t tmp_buf[] = "\r\n";
    for(cnt = 0; cnt < (sizeof(ESP_CIPSEND) - 1); cnt++)
    {
        esp_server[cnt] = ESP_CIPSEND[cnt];
    }
    cur_cnt = cnt;
    
    for(cnt = cur_cnt; cnt < (cur_cnt + sizeof(esp_send_count)); cnt++)
    {
        esp_server[cnt] = esp_send_count[cnt - cur_cnt];
    }
    cur_cnt = cnt;
    
    for(cnt = cur_cnt; cnt < (cur_cnt + sizeof(tmp_buf)); cnt++)
    {
        esp_server[cnt] = tmp_buf[cnt - cur_cnt];
    }
    esp_server_count = cnt;
}
void make_sendinfo(uint8_t *info)
{
    uint8_t http[] = " HTTP/1.1\r\nHost: ";
    uint8_t temp_buf[] = "\r\n\r\n";
    uint8_t tmp_sendcount;
    uint8_t cnt, cur_cnt;
    for(cnt = 0; cnt < (sizeof(destPHP) - 1); cnt++)
    {
        esp_send_buf[cnt] = destPHP[cnt];
    }
    tmp_sendcount = cnt;
    
    for(cnt = tmp_sendcount; cnt < (tmp_sendcount + sizeof(info) - 2); cnt++)
    {
        esp_send_buf[cnt] = info[cnt - tmp_sendcount];
    }
    tmp_sendcount = cnt;
    
    for(cnt = tmp_sendcount; cnt < (tmp_sendcount + sizeof(http) - 1); cnt++)
    {
        esp_send_buf[cnt] = http[cnt - tmp_sendcount];
    }
    tmp_sendcount = cnt;

    for(cnt = tmp_sendcount; cnt < (tmp_sendcount + sizeof(destDNS) - 1); cnt++)
    {
        esp_send_buf[cnt] = destDNS[cnt - tmp_sendcount];
    }
    tmp_sendcount = cnt;
    
    for(cnt = tmp_sendcount; cnt < (tmp_sendcount + sizeof(temp_buf) - 1); cnt++)
    {
        esp_send_buf[cnt] = temp_buf[cnt - tmp_sendcount];
    }
    tmp_sendcount = cnt;
    sendcount = cnt;
    
    if(tmp_sendcount >= 100)
    {
        esp_send_count[0] = '0' + tmp_sendcount / 100 % 10;
        esp_send_count[1] = '0' + tmp_sendcount / 10 % 10;
        esp_send_count[2] = '0' + tmp_sendcount % 10;
    }
    else if((tmp_sendcount < 100) && (tmp_sendcount >= 10))
    {
        esp_send_count[0] = '0';
        esp_send_count[1] = '0' + tmp_sendcount / 10 % 10;
        esp_send_count[2] = '0' + tmp_sendcount % 10;
    }
    else
    {
        esp_send_count[0] = '0';
        esp_send_count[1] = '0';
        esp_send_count[2] = '0' + tmp_sendcount % 10;
    }
    
    make_server();
}
void make_tmpsendinfo(uint8_t *info)
{
    uint8_t http[] = " HTTP/1.1\r\nHost: ";
    uint8_t temp_buf[] = "\r\n\r\n";
    uint8_t tmp_sendcount;
    uint8_t cnt, cur_cnt;
    for(cnt = 0; cnt < (sizeof(destPHP) - 1); cnt++)
    {
        esp_send_buf[cnt] = destPHP[cnt];
    }
    tmp_sendcount = cnt;
    
    for(cnt = tmp_sendcount; cnt < (tmp_sendcount + sizeof(http) - 1); cnt++)
    {
        esp_send_buf[cnt] = http[cnt - tmp_sendcount];
    }
    tmp_sendcount = cnt;

    for(cnt = tmp_sendcount; cnt < (tmp_sendcount + sizeof(destDNS) - 1); cnt++)
    {
        esp_send_buf[cnt] = destDNS[cnt - tmp_sendcount];
    }
    tmp_sendcount = cnt;
    
    for(cnt = tmp_sendcount; cnt < (tmp_sendcount + sizeof(temp_buf) - 1); cnt++)
    {
        esp_send_buf[cnt] = temp_buf[cnt - tmp_sendcount];
    }
    tmp_sendcount = cnt;
    sendcount = cnt;
    
    if(tmp_sendcount >= 100)
    {
        esp_send_count[0] = '0' + tmp_sendcount / 100 % 10;
        esp_send_count[1] = '0' + tmp_sendcount / 10 % 10;
        esp_send_count[2] = '0' + tmp_sendcount % 10;
    }
    else if((tmp_sendcount < 100) && (tmp_sendcount >= 10))
    {
        esp_send_count[0] = '0';
        esp_send_count[1] = '0' + tmp_sendcount / 10 % 10;
        esp_send_count[2] = '0' + tmp_sendcount % 10;
    }
    else
    {
        esp_send_count[0] = '0';
        esp_send_count[1] = '0';
        esp_send_count[2] = '0' + tmp_sendcount % 10;
    }
    
    make_server();
}
void startDelay(void)
{
    DRV_TMR0_Start(); // Start the Timers
    delay = 0;
}

void endDelay(void)
{
    DRV_TMR0_Stop();
    delay = 0;
}
/******************************************************************************
  Function:
    static void USART_Task (void)

   Remarks:
    Feeds the USART transmitter by reading characters from a specified pipe.  The pipeRead function is a 
    standard interface that allows data to be exchanged between different automatically 
    generated application modules.  Typically, the pipe is connected to the application's
    USART receive function, but could be any other Harmony module which supports the pipe interface. 
*/
static void USART_Task (void)
{
    uint8_t i;
    
    switch (wifiStatus)
    {
        default:
            break;
        case WIFI_RST:
        {
            appData.tx_count = 0;
            appData.rx_count = 0;
            delay = 0;
            
            make_cwjap();
            make_connection();
    
            wifiStatus = WIFI_INIT;
            break;
        }
        case WIFI_INIT:
        {
            if (appData.tx_count < (sizeof(ESP_INIT) - 1)) 
            {
                if(!DRV_USART_TransmitBufferIsFull(appData.handleUSART0))
                {
                    DRV_USART_WriteByte(appData.handleUSART0, ESP_INIT[appData.tx_count]);
                    appData.tx_count++;
                }
                
                /* Have we finished sending message? */
                if (appData.tx_count == (sizeof(ESP_INIT) - 1))
                {
                    wifiStatus = WIFI_INIT_RECEIVE;
                }
            }
            
            break;
        }

        case WIFI_INIT_RECEIVE:
        {
            if (appData.rx_count < sizeof(app_rx_buf)) 
            {
                if(!DRV_USART_ReceiverBufferIsEmpty(appData.handleUSART0))
                {
                    /* Read the received character */
                    app_rx_buf[appData.rx_count] = DRV_USART_ReadByte(appData.handleUSART0);
                    appData.rx_count++;
                    
                    if(strstr(app_rx_buf, "ready") != NULL)
                    {
                        appData.tx_count = 0;
                        appData.rx_count = 0;
                        
                        for(i = 0; i < max_bufsize; i++)
                            app_rx_buf[i] = 0;
                        
//                        startDelay(); //delay for 5 seconds for wifi_connected.
                    }
                    
                    if(strstr(app_rx_buf, "WIFI GOT IP") != NULL)
                    {
                        appData.tx_count = 0;
                        appData.rx_count = 0;
                        
                        for(i = 0; i < max_bufsize; i++)
                            app_rx_buf[i] = 0;
                        
                        wifiStatus = WIFI_CIPMUX;
                    }
                    
                    if(appData.rx_count >= max_bufsize)
                        appData.rx_count = 0;
                }
            }
            if(delay >= 2000) // finished delay
            {
                appData.tx_count = 0;
                appData.rx_count = 0;
                        
                for(i = 0; i < max_bufsize; i++)
                    app_rx_buf[i] = 0;
                        
                endDelay();
                wifiStatus = WIFI_CWMODE;
            }
            break;
        }
        case WIFI_CWMODE:
        {
            if (appData.tx_count < sizeof(ESP_CWMODE)) 
            {
                if(!DRV_USART_TransmitBufferIsFull(appData.handleUSART0))
                {
                    DRV_USART_WriteByte(appData.handleUSART0, ESP_CWMODE[appData.tx_count]);
                    appData.tx_count++;
                }
                
                /* Have we finished sending message? */
                if (appData.tx_count == sizeof(ESP_CWMODE))
                {
                    wifiStatus = WIFI_CWMODE_RECEIVE;
                }
            }
            
            break;
        }

        case WIFI_CWMODE_RECEIVE:
        {
            if (appData.rx_count < sizeof(app_rx_buf)) 
            {
                if(!DRV_USART_ReceiverBufferIsEmpty(appData.handleUSART0))
                {
                    /* Read the received character */
                    app_rx_buf[appData.rx_count] = DRV_USART_ReadByte(appData.handleUSART0);
                    appData.rx_count++;
                    
                    if(strstr(app_rx_buf, ESP_OK) != NULL)
                    {
                        wifiStatus = WIFI_CWJAP;
                        appData.tx_count = 0;
                        appData.rx_count = 0;
                        for(i = 0; i < max_bufsize; i++)
                            app_rx_buf[i] = 0;
                    }
                    
                }
            }
            break;
        }    
        case WIFI_CWJAP:
        {
            if (appData.tx_count < esp_cwjap_count) 
            {
                if(!DRV_USART_TransmitBufferIsFull(appData.handleUSART0))
                {
                    DRV_USART_WriteByte(appData.handleUSART0, esp_cwjap_buf[appData.tx_count]);
                    appData.tx_count++;
                }
                
                /* Have we finished sending message? */
                if (appData.tx_count == esp_cwjap_count)
                {
                    wifiStatus = WIFI_CWJAP_RECEIVE;
                }
            }
            
            break;
        }

        case WIFI_CWJAP_RECEIVE:
        {
            if (appData.rx_count < sizeof(app_rx_buf)) 
            {
                if(!DRV_USART_ReceiverBufferIsEmpty(appData.handleUSART0))
                {
                    /* Read the received character */
                    app_rx_buf[appData.rx_count] = DRV_USART_ReadByte(appData.handleUSART0);
                    appData.rx_count++;
                    
                    if(strstr(app_rx_buf, ESP_OK) != NULL)
                    {
                        appData.tx_count = 0;
                        appData.rx_count = 0;
                        for(i = 0; i < max_bufsize; i++)
                            app_rx_buf[i] = 0;
                        
                        wifiStatus = WIFI_CIPMUX;
                    }
                    if(strstr(app_rx_buf, "FAIL") != NULL)
                    {
                        wifiStatus = WIFI_INIT;
                    }
                    
                }
            }
            break;
        }
        case WIFI_CIPMUX:
        {
            if (appData.tx_count < (sizeof(ESP_CIPMUX) - 1)) 
            {
                if(!DRV_USART_TransmitBufferIsFull(appData.handleUSART0))
                {
                    DRV_USART_WriteByte(appData.handleUSART0, ESP_CIPMUX[appData.tx_count]);
                    appData.tx_count++;
                }
                
                /* Have we finished sending message? */
                if (appData.tx_count == (sizeof(ESP_CWMODE) - 1))
                {
                    wifiStatus = WIFI_CIPMUX_RECEIVE;
                }
            }
            
            break;
        }

        case WIFI_CIPMUX_RECEIVE:
        {
            if (appData.rx_count < sizeof(app_rx_buf)) 
            {
                if(!DRV_USART_ReceiverBufferIsEmpty(appData.handleUSART0))
                {
                    /* Read the received character */
                    app_rx_buf[appData.rx_count] = DRV_USART_ReadByte(appData.handleUSART0);
                    appData.rx_count++;
                    
                    if(strstr(app_rx_buf, ESP_OK) != NULL)
                    {
                        wifiStatus = WIFI_CONNECT;
                        appData.tx_count = 0;
                        appData.rx_count = 0;
                        for(i = 0; i < max_bufsize; i++)
                            app_rx_buf[i] = 0;
                    }
                }
            }
            break;
        }
        case WIFI_CONNECT:
        {
            if (appData.tx_count < esp_connect_count) 
            {
                if(!DRV_USART_TransmitBufferIsFull(appData.handleUSART0))
                {
                    DRV_USART_WriteByte(appData.handleUSART0, esp_connect_buf[appData.tx_count]);
                    appData.tx_count++;
                }
                
                /* Have we finished sending message? */
                if (appData.tx_count == esp_connect_count)
                {
                    wifiStatus = WIFI_CONNECT_RECEIVE;
                }
            }
            
            break;
        }

        case WIFI_CONNECT_RECEIVE:
        {
            if (appData.rx_count < sizeof(app_rx_buf)) 
            {
                if(!DRV_USART_ReceiverBufferIsEmpty(appData.handleUSART0))
                {
                    /* Read the received character */
                    app_rx_buf[appData.rx_count] = DRV_USART_ReadByte(appData.handleUSART0);
                    appData.rx_count++;
                    
                    if(strstr(app_rx_buf, ESP_OK) != NULL)
                    {
                        appData.tx_count = 0;
                        appData.rx_count = 0;
                        for(i = 0; i < max_bufsize; i++)
                            app_rx_buf[i] = 0;
 //////////////////////////////////////////////////                       
                        make_sendinfo("30");
///////////////////////////////////////////////////                        
                        wifiStatus = WIFI_CIPSTART;
                    }
                }
            }
            break;
        }
        case WIFI_CIPSTART:
        {
            if (appData.tx_count < (esp_server_count - 1)) 
            {
                if(!DRV_USART_TransmitBufferIsFull(appData.handleUSART0))
                {
                    DRV_USART_WriteByte(appData.handleUSART0, esp_server[appData.tx_count]);
                    appData.tx_count++;
                }
                
                /* Have we finished sending message? */
                if (appData.tx_count == (esp_server_count - 1))
                {
                    wifiStatus = WIFI_CIPSTART_RECEIVE;
                }
            }
            break;
        }

        case WIFI_CIPSTART_RECEIVE:
        {
            if (appData.rx_count < sizeof(app_rx_buf)) 
            {
                if(!DRV_USART_ReceiverBufferIsEmpty(appData.handleUSART0))
                {
                    /* Read the received character */
                    app_rx_buf[appData.rx_count] = DRV_USART_ReadByte(appData.handleUSART0);
                    appData.rx_count++;
                    
                    if(strstr(app_rx_buf, ">") != NULL)
                    {
                        appData.tx_count = 0;
                        appData.rx_count = 0;
                        for(i = 0; i < max_bufsize; i++)
                            app_rx_buf[i] = 0;
                        
                        wifiStatus = WIFI_SEND_DATA;
                    }
                }
            }
            break;
        }
        case WIFI_SEND_DATA:
        {
            if (appData.tx_count < sendcount) 
            {
                if(!DRV_USART_TransmitBufferIsFull(appData.handleUSART0))
                {
                    DRV_USART_WriteByte(appData.handleUSART0, esp_send_buf[appData.tx_count]);
                    appData.tx_count++;
                }
                
                /* Have we finished sending message? */
                if (appData.tx_count == sendcount)
                {
                    wifiStatus = WIFI_SEND_DATA_RECEIVE;
                }
            }
            
            break;
        }

        case WIFI_SEND_DATA_RECEIVE:
        {
            if (appData.rx_count < sizeof(app_rx_buf)) 
            {
                if(!DRV_USART_ReceiverBufferIsEmpty(appData.handleUSART0))
                {
                    /* Read the received character */
                    app_rx_buf[appData.rx_count] = DRV_USART_ReadByte(appData.handleUSART0);
                    appData.rx_count++;
                    
                    if(strstr(app_rx_buf, "CLOSED") != NULL)
                    {
                        wifiStatus = WIFI_CLOSE;
                        appData.tx_count = 0;
                        appData.rx_count = 0;
                        for(i = 0; i < max_bufsize; i++)
                            app_rx_buf[i] = 0;
                    }
                    
                }
            }
            break;
        }
        case WIFI_CLOSE:
        {

            
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
    PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_TIMER_1);
    appData.handleUSART0 = DRV_HANDLE_INVALID;

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
                appInitialized &= ( DRV_HANDLE_INVALID != appData.handleUSART0 );
            }

            if (appInitialized)
            {
                /* initialize the USART state machine */
                wifiStatus = WIFI_RST;
            
                appData.state = APP_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            USART_Task();
        
            break;
        }

        /* TODO: implement your application state machine.*/
        

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
