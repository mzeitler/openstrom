/*
 * Open Strom
 *
 * Copyright (c) [2015] [Anton Tachev]
 
*/

/*
 * This file main.c represents the entry point of the software.
 *
 * Author : Anton Tachev
 *
 * Evolution of the file:
 * 30.11.2016 - File created - Anton Tachev
 *
*/

#include <stdbool.h>
#include <stdlib.h>
#include "p32mx795f512h.h"
#include "fw_common.h"
#include "string.h"
#include "int.h"
#include "ethmac.h"


/* PIC32 ESK configuration fuses */
//#pragma config FPLLODIV = DIV_1, FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FWDTEN = OFF, FPBDIV = DIV_2
#pragma config FPLLMUL = MUL_15, FPLLIDIV = DIV_2, FPLLODIV = DIV_4, FWDTEN = OFF
//#pragma POSCMOD = XT, FNOSC = PRIPLL, CP = OFF

#pragma config FMIIEN = OFF, FETHIO = ON	// external PHY in RMII/alternate configuration
#pragma config FNOSC=FRCPLL,POSCMOD=OFF,ICESEL=ICS_PGx1

#define UL_DEST_MAC_ADDRESS_HIGH            (0x00000026)
#define UL_DEST_MAC_ADDRESS_LOW             (0x2d904b96)


LOCAL const uint8 aui8FrameString[] = "ETH DRIVER FOR PIC 32";


/* init port pins function for Pic32mx795f512H  */
LOCAL void initPins ( void )
{
    /* temporary set all digital */
    AD1PCFG = 0xFFFF;

    /* Switches */
    //TRISDbits.TRISD6 = 1;
   // TRISDbits.TRISD7 = 1;
   // TRISDbits.TRISD13 = 1;

    /* Enable pullups on the Switch ports */
   // CNENbits.CNEN15 = 1;
   // CNENbits.CNEN16 = 1;
   // CNENbits.CNEN19 = 1;

    /* LEDs */
   // TRISDbits.TRISD0 = 0;
    //TRISDbits.TRISD1 = 0;
   // TRISDbits.TRISD2 = 0;

    /* ETH pins for Pic32mx795f512H */
   
    TRISBbits.TRISB15 = 0;//MDC 
    TRISDbits.TRISD1 = 1;//MDIO
    TRISEbits.TRISE5 = 0;//TXEN
    TRISEbits.TRISE6 = 0;//TXD0
    TRISEbits.TRISE7 = 0;//TXD1
    TRISEbits.TRISE3 = 1;//RXCLK
    TRISEbits.TRISE2 = 1;//RXDV 
    TRISEbits.TRISE1 = 1;//RXD0
    TRISEbits.TRISE0 = 1;//RXD1
    TRISEbits.TRISE4 = 1;//RXERR
}


/* main function */
int main ( void )
{
    uint8 *pui8BuffPtr;
    uint64 ui64DestMACAddress;
    char*alfa;
          
         /* init port pins */
    initPins();

    /* init interrupts      20122016 Disable Interrupt*/
    INT_EnableInt();

    ETHMAC_Init();

  //  ui64DestMACAddress = (((uint64)UL_DEST_MAC_ADDRESS_HIGH << 32) | (UL_DEST_MAC_ADDRESS_LOW));
   ui64DestMACAddress=0x000000262d904b96;

    /* get next buffer pointer */
    pui8BuffPtr = (uint8 *)ETHMAC_getTXBufferPointer(strlen(aui8FrameString));
    ALIGN_32BIT_OF_8BIT_PTR(pui8BuffPtr);
    
    MEM_COPY(pui8BuffPtr, aui8FrameString, strlen(aui8FrameString));
  
    /* request TX packet transmission. ATTENTION: Ethernet Type set as IPv4... */
    while(1){                   //18122016
    ETHMAC_sendPacket(pui8BuffPtr, strlen(aui8FrameString), ETHMAC_ui64MACAddress, ui64DestMACAddress, 0x0800);
    }
    while(1);                             
    
    return ( EXIT_FAILURE );
}



