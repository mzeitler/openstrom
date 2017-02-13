/* 
 * File:   App-stpm34.h
 * Author: Tony Tachev
 *
 * Created on 22 January 2016, 11:11
 */

#ifndef APP_STPM34_H
#define	APP_STPM34_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* APP_STPM34_H */
// *****************************************************************************
/* Application states

  Summary:
    Application states enumeration

  Description:
    This enumeration defines the valid application states.  These states
    determine the behavior of the application at various times.
*/
typedef enum
{
    APP_STPM_INIT.              //this state application opens the driver
    APP_STPM34_READ ,            //in this state application reads STPM34 power values
    APP_STPM_ERROR,             //Initiate error condition
    APP_STPM_IDLE
    
}APP_STPM_STATE;
}
/*----------------------------------------------------------------------------*/
/*                               Application Data
/*
/* Summary: Holds application data for STP34_Tasks() functions
/* Remarks: Application float values for Power/Energy and buffers defined 
/*          outside of this structure
*/
// Section: Type Definitions

typedef struct
{
    APP_STPM34_STATE        state;              //application current state
    DRV_HANDLE              drvSPIHande;        //SPI Driver handle
    DRV_SPI_BUFFER_HANDLE   drvSPIWBUFhandle;   //Driver buffer hande 
    DRV_SPI_BUFFER_HANDLE   drvSPIRBUFhandle;   //
    SPI_DATA_TYPE           drvSPITXBuffer[100] //
    SPI_DATA_TYPE           drvSPIRXBuffer[100] //
            
}APP_STPM34_DATA;

typedef uintptr_t DRV_SPI_BUFFER_HANDLE;
typedef uintptr_t DRV_HANDLE;

// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
typedef unsigned char SPI_DATA_TYPE;

#define MAX_NUM_OF_BYTES        64

#define MAX_NUM_OF_BYTES_IN_BUF (MAX_NUM_OF_BYTES + 4)

#define SPI_CS1_PORT_ID          PORT_CHANNEL_G

#define SPI_CS2_PORT_ID          PORT_CHANNEL_G

#define SPI_CS3_PORT_ID          PORT_CHANNEL_B

#define SPI_CS4_PORT_ID          PORT_CHANNEL_B

#define SPI_CS5_PORT_ID          PORT_CHANNEL_G

#define SPI_CS1_PORT_PIN         PORTS_BIT_POS_6

#define SPI_CS2_PORT_PIN         PORTS_BIT_POS_5

#define SPI_CS3_PORT_PIN         PORTS_BIT_POS_4

#define SPI_CS4_PORT_PIN         PORTS_BIT_POS_2

#define SPI_CS5_PORT_PIN         PORTS_BIT_POS_3

#define APP_SPI_CS1_SELECT()     \
                   SYS_PORTS_PinClear(PORTS_ID_0,SPI_CS1_PORT_ID,SPI_CS1_PORT_PIN)

#define APP_SPI_CS2_SELECT()     \
                   SYS_PORTS_PinClear(PORTS_ID_0,SPI_CS2_PORT_ID,SPI_CS2_PORT_PIN)

#define APP_SPI_CS3_SELECT()     \
                   SYS_PORTS_PinClear(PORTS_ID_0,SPI_CS3_PORT_ID,SPI_CS3_PORT_PIN)

#define APP_SPI_CS4_SELECT()     \
                   SYS_PORTS_PinClear(PORTS_ID_0,SPI_CS4_PORT_ID,SPI_CS4_PORT_PIN)

#define APP_SPI_CS5_SELECT()     \
                   SYS_PORTS_PinClear(PORTS_ID_0,SPI_CS5_PORT_ID,SPI_CS5_PORT_PIN)


#define APP_SPI_CS1_DESELECT()   \
                     SYS_PORTS_PinSet(PORTS_ID_0,SPI_CS1_PORT_ID,SPI_CS1_PORT_PIN

#define APP_SPI_CS2_DESELECT()   \
                     SYS_PORTS_PinSet(PORTS_ID_0,SPI_CS2_PORT_ID,SPI_CS2_PORT_PIN

#define APP_SPI_CS3_DESELECT()   \
                     SYS_PORTS_PinSet(PORTS_ID_0,SPI_CS3_PORT_ID,SPI_CS3_PORT_PIN

#define APP_SPI_CS4_DESELECT()   \
                     SYS_PORTS_PinSet(PORTS_ID_0,SPI4_CS_PORT_ID,SPI_CS4_PORT_PIN

#define APP_SPI_CS5_DESELECT()   \
                     SYS_PORTS_PinSet(PORTS_ID_0,SPI_CS5_PORT_ID,SPI_CS5_PORT_PIN

/*--------------Application Tasks () Function---------------------------------*/