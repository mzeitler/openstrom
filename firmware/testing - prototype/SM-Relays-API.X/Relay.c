
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
//#include "Relay.h"

//#include "STPM-define.h"

/*-----------------------------------------------------------------------------*/
/*              Init Relays Routine                                             */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
void Init_Relays(void)
{
      RtccShutdown();                                  //enable RC13&RC14 to be configure as I/O
      mPORTFSetPinsDigitalOut(BIT_0|BIT_1);            //init Relays K1&K2
      mPORTDSetPinsDigitalOut(BIT_4|BIT_5|BIT_6|BIT_7);//init Relays K2...K6
      mPORTCSetPinsDigitalOut(BIT_13|BIT_14);           //init Relays K7&K8
      mPORTBSetPinsDigitalOut(BIT_8|BIT_7);            //init Relays K9&K10
          
}

void Switch_ON_Relay(IoPortId port,unsigned int relay)
{
    
    PORTSetBits(port,relay);                  //switch On the corresponded relay
       
}

void Switch_ON_PWMRelay(IoPortId port,unsigned int relay)
{
    int i=0;
    for(i=0;i<10;i++)
    {
        
        PORTSetBits(port,relay);                  //switch On the corresponded relay in PWM mode
        Relay_Delay();
      
        PORTClearBits(port,relay);                //generate PWM sequence
    }
    PORTSetBits(port,relay);
}

void Switch_OFF_Relay(IoPortId port,unsigned int relay)
{
    
    PORTClearBits(port,relay);                  //switch On the corresponded relay
       
}


/*------------------Relay Zero Crossing routine---------------------------------*/
/*                                                                              */
/*                                                                              */
/*------------------------------------------------------------------------------*/
/*
void Relay_CRZ(void)
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



   
