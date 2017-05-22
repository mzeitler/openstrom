
/* 
 * Source File:   Relay.c
 * Name of Project: SM-Relaytest project
 * Path:D:/PLIB-Project/SM-Relaytest.X
 * Author: Anton Tachev
 *
 * Created on:19.02.2017, 12:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <plib.h>
#include <p32xxxx.h>
#include <stdint.h>
//#include "STPM-define.h"
//#include "Relay.h"

//#include "STPM-define.h"
void Relay1_Delay(int num);
void Find_ZCR(void);
/*-----------------------------------------------------------------------------*/
/*              Init Relays Routine                                             */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
void Init_Relays(void)
{
      RtccShutdown();                                  //enable RC13&RC14 to be configure as I/O
    //  mPORTFSetPinsDigitalOut(BIT_0);                  //init Relays K1
      TRISFbits.TRISF1=0;
      LATFbits.LATF1=0;
      LATFbits.LATF1=1;
   //   mPORTFSetPinsDigitalOut(BIT_1);                  // init Relay K2
      TRISFbits.TRISF0=0;
      LATFbits.LATF0=0;
      LATFbits.LATF0=1;
   //   mPORTDSetPinsDigitalOut(BIT_7);                  //init Relays K3
      TRISDbits.TRISD7=0;
      LATDbits.LATD7=0;
      LATDbits.LATD7=1;
    //  mPORTDSetPinsDigitalOut(BIT_6);                  //init Relays K4
      TRISDbits.TRISD6=0;
      LATDbits.LATD6=0;
      LATDbits.LATD6=1;
   //   mPORTDSetPinsDigitalOut(BIT_5);                  //init Relays K5
      TRISDbits.TRISD5=0;
      LATDbits.LATD5=0;
      LATDbits.LATD5=1;
    //  mPORTDSetPinsDigitalOut(BIT_4);                  //init Relays K6
      TRISDbits.TRISD4=0;
      LATDbits.LATD4=0;
      LATDbits.LATD4=1;
    //  mPORTCSetPinsDigitalOut(BIT_14);                 //init Relays K7
      TRISCbits.TRISC14=0;
      LATCbits.LATC14=0;
      LATCbits.LATC14=1;
    //  mPORTCSetPinsDigitalOut(BIT_13);                 //init Relays K8
      TRISCbits.TRISC13=0;
      LATCbits.LATC13=0;
      LATCbits.LATC13=1;
    //  mPORTBSetPinsDigitalOut(BIT_8);                  //init Relays K9
      TRISBbits.TRISB8=0;
      LATBbits.LATB8=0;
      LATBbits.LATB8=1;
    //  mPORTBSetPinsDigitalOut(BIT_7);                  //init Relays K10
      TRISBbits.TRISB7=0;
      LATBbits.LATB7=0;  
      LATBbits.LATB7=1;
}

void Switch_ON_Relay(IoPortId port,unsigned int relay)
{
    
    PORTSetBits(port,relay);                  //switch On the corresponded relay
       
}

void Switch_ON_PWMRelay(IoPortId port,unsigned int relay)
{
    int i=0;
    int j=0;
    
    for(i=0;i<8;i++)
    {
        j+=100;
        PORTClearBits(port,relay);                  //switch On the corresponded relay in PWM mode
        Relay1_Delay(j);
      
        PORTSetBits(port,relay);                //generate PWM sequence
        Relay1_Delay(j);
        PORTClearBits(port,relay);
        Relay1_Delay(j);
    }
   // PORTClearBits(port,relay); 
}

void Switch_OFF_Relay(IoPortId port,unsigned int relay)
{
    
    PORTClearBits(port,relay);                  //switch On the corresponded relay
       
}
void Relay1_Delay(int num)
{
    int delayValue;
    delayValue=num*20;
    do{
        delayValue--;
    }
    while(delayValue>=0);
    
}

/*------------------Relay Zero Crossing routine---------------------------------*/
/*                                                                              */
/*                                                                              */
/*------------------------------------------------------------------------------*/

/*void Relay_CRZ(void)
{
    int i;
    unsigned int chnSel;
    unsigned int port;
    unsigned int _bits;
    
    Init_Relays();               //Initialize Relay OUTPUTS
    SPI_Init();                 //Initialize SPI OUTPUTS
    
    for(i=1;i<6;i++)
    {
        Init_STPM34(i);         //Initialize sensors ICs STPM34
    }
    
    //Set Zero crossing Enable in DSP-cr3
    DSP_CR300bits.ZCR_SEL=0x0;          //select V1 - source of ZCR
    DSP_CR301bits.ZCR_EN=1;
    readAdd=0x05;
    writeAdd=0x05;
    dataLSB=DSP_CR301bits.LSB;
    dataMSB=DSP_CR301bits.MSB;
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB,1,1);
}*/
/*void Find_ZCR(void)
{
    uint32_t zcrFlag=0;
    ReadFrame(0x2A,&zcrFlag,IOPORT_G,BIT_9);
    zcrFlag&=0x00001000;
    while(zcrFlag!=0x00001000){}            // check if the ZCR bit in reg DSP ev1 is set active 
}*/

   
