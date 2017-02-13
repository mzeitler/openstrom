/*
 * The MIT License (MIT)
 *
 * Copyright (c) [2015] [Marco Russi]
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

/*
 * This file main.c represents the entry point of the software.
 *
 * Author : Marco Russi
 *
 * Evolution of the file:
 * 06/08/2015 - File created - Marco Russi
 *
*/

#include <stdbool.h>
#include <stdlib.h>
#include "p32mx795f512l.h"
#include "fw_common.h"

#include "int.h"
#include "ethmac.h"


/* PIC32 ESK configuration fuses */
#pragma config FPLLODIV = DIV_1, FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FWDTEN = OFF, FPBDIV = DIV_2, POSCMOD = XT, FNOSC = PRIPLL, CP = OFF
#pragma config FMIIEN = OFF, FETHIO = OFF	// external PHY in RMII/alternate configuration


#define UL_DEST_MAC_ADDRESS_HIGH            (0x00000026)
#define UL_DEST_MAC_ADDRESS_LOW             (0x2d904b96)


LOCAL const uint8 aui8FrameString[] = "ETH DRIVER FOR PIC 32 - BY MARCO RUSSI";


/* init port pins function */
LOCAL void initPins ( void )
{
    /* temporary set all digital */
    AD1PCFG = 0xFFFF;

    /* Switches */
    TRISDbits.TRISD6 = 1;
    TRISDbits.TRISD7 = 1;
    TRISDbits.TRISD13 = 1;

    /* Enable pullups on the Switch ports */
    CNENbits.CNEN15 = 1;
    CNENbits.CNEN16 = 1;
    CNENbits.CNEN19 = 1;

    /* LEDs */
    TRISDbits.TRISD0 = 0;
    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD2 = 0;

    /* ETH pins */
    TRISDbits.TRISD11 = 0;//MDC
    TRISDbits.TRISD8 = 1;//MDIO
    TRISAbits.TRISA15 = 0;//TXEN
    TRISDbits.TRISD14 = 0;//TXD0
    TRISDbits.TRISD15 = 0;//TXD1
    TRISGbits.TRISG9 = 1;//RXCLK
    TRISGbits.TRISG8 = 1;//RXDV
    TRISEbits.TRISE8 = 1;//RXD0
    TRISEbits.TRISE9 = 1;//RXD1
    TRISGbits.TRISG15 = 1;//RXERR
}


/* main function */
int main ( void )
{
    uint8 *pui8BuffPtr;
    uint64 ui64DestMACAddress;

    /* init port pins */
    initPins();

    /* init interrupts */
    INT_EnableInt();

    ETHMAC_Init();

    ui64DestMACAddress = (((uint64)UL_DEST_MAC_ADDRESS_HIGH << 32) | (UL_DEST_MAC_ADDRESS_LOW));

    /* get next buffer pointer */
    pui8BuffPtr = (uint8 *)ETHMAC_getTXBufferPointer(strlen(aui8FrameString));
    //ALIGN_32BIT_OF_8BIT_PTR(pui8BuffPtr);
    
    MEM_COPY(pui8BuffPtr, aui8FrameString, strlen(aui8FrameString));

    /* request TX packet transmission. ATTENTION: Ethernet Type set as IPv4... */
    ETHMAC_sendPacket(pui8BuffPtr, strlen(aui8FrameString), ETHMAC_ui64MACAddress, ui64DestMACAddress, 0x0800);

    while(1);
    
    return ( EXIT_FAILURE );
}



