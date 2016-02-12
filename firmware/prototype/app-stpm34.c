
/*******************************************************************************
 OpenStrom application
  
  Company:
 Open Strom Ltd.
  
  File Name:
 app-stpm34.c

  Summary:
    Application Template

  Description:
    This file contains the application logic.
 *******************************************************************************/
#include "app.h"
#include "App-stpm34.h"
#include "drv_spi.h"

APP_DATA appData = 
{
    //Initialize appData structure. 

};

/******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    
    /* Deselect the Chip Select Lines*/
    APP_SPI_CS_DESELECT();

    /* APP state task Init */
    appData.state = APP_STATE_INIT;
}

/**********************************************************
 * Application tasks routine. This function implements the
 * application state machine.
 ***********************************************************/
void APP_STPM34_task(void)
{
    unsigned int readErrStatus;
    switch(appData.state)
    {
        case APP_STPM34_INIT:
        {
            appData.drvSPIHandle=DRV_SPI_Open(DRI_SPI_2,DRV_IO_INTENT_READWRITE);
            if(appData.drvSPIHandle!=(uintptr_t)NULL)
            {
                appData.state=APP_STPM34_READ;    
            }
            else
            {
                appData.state=APP_STPM34_ERROR;                
            }
            break;
        }
            case APP_STPM34_READ:
            {
                readErrStatus=ReadPowerValue();
                if(readErrStatus!=0)
                {
                    appData=APP_STPM34_ERROR;
                }
                else
                {
                    appdata.state=APP_STPM34_IDLE;
                }
                break;
            
            }
            case APP_STPM34_IDLE: 
            {
                DisplayError();
                break;
            }
            case APP_STPM34_IDLE:
            {
                Nop();
                break;
            }
        }
    }
}
