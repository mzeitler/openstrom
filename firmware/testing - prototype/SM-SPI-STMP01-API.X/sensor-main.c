/* 
 * File:   sensor-main.c
 * Author: Anton Tachev
 * Description: The main function SM-SPI-STMP02 configurates STPM 34 IC and
 * get energy parameters such as:
 * -Active Energy&Power;
 * -Reactive Energy&Power
 * -Apparent Energy&Power
 * -Fundamental Energy, ph1 Currents&Voltages, ph2 Currents&Voltages
 * Created on:    24.02.2017
 */
/*----------------SPI 2 module identification---------------------------------*/
/* SCK2 - pin2 RE6                         
 * SDI2 - pin5 RG7
 * SDO2 - pin 6 RG8
 * SCS - pin 9 RG9
 * Enable(EN) - pin 45 RD11
 */

#include <stdio.h>
#include <stdlib.h>
#include <plib.h>
#include <p32xxxx.h>
#include "relay.h"
//#include "STPM-define.h"

/*----------------Function prototypes -----------------------------------------*/

void Init_STPM34(int chnSel,unsigned int port,unsigned int _bits);        //function prototype are defined in STPM34_header.h
void SPI_Init();
void Delay(void);
void ReadFrame(unsigned short address, uint32_t * buffer,int port,int bits);
void SendFrame(char readAdd,char writeAdd, char dataLSB,char dataMSB,int port,int bits);
void FrameDelay(void);                          
//void GetParams(unsigned int port, unsigned _bits, int *buffer);
void GetParams(unsigned int port, unsigned _bits,int *buffer, relay_t activeRelay);


// configuration settings
//#pragma config FPLLMUL = MUL_15,FPLLODIV = DIV_4
#pragma config FPLLMUL = MUL_15, FPLLIDIV = DIV_2, FPLLODIV = DIV_4, FWDTEN = OFF

//#pragma config POSCMOD = XT, FNOSC = PRIPLL, FPBDIV = DIV_1
#pragma config FNOSC=FRCPLL,POSCMOD=OFF,ICESEL=ICS_PGx1,FPBDIV= DIV_8  //periphelal clock=10Mhz(FPBDIV)
/*-------------Global Variables--------------------------------------*/
int i,j,k;
int delayValue;
int chnSel=6;                           //the number of sensor IC 
unsigned int port;
unsigned int _bits;
static uint32_t *tempbuff;
//int *Buffer[5]={buf1,buf2,buf3,buf4,buf5}; 
uint32_t buf1[12];              //contains energy params for Channels 1&2               
uint32_t buf2[12];              //contains energy params for Channels 3&4 
uint32_t buf3[12];              //contains energy params for Channels 5&6 
uint32_t buf4[12];              //contains energy params for Channels 7&8 
uint32_t buf5[12];              //contains energy params for Channels 9&10 
int main()
  {
   
  /* configure the proper PB frequency and the number of wait states */
   SYSTEMConfigWaitStatesAndPB(80000000L);
   CheKseg0CacheOn();                           // enable the cache for the best performance
   RtccShutdown();                              //enable RC13&RC14 as a I/O
   mT2ClearIntFlag();
 /*---------------------------------------------*/
   SPI_Init();              //initialize SPI INPUT/OUTPUTS
    while(chnSel--)
    {    
     Init_STPM34(chnSel,port,_bits);       //initialize all Sensors STPM34
    }
   while(1)
   {
       _bits=BIT_9;
       port=IOPORT_G;                    //IOPORT_G=0x05
       
       activeRelay.relayPort1=IOPORT_F;
       activeRelay.relayPin1=BIT_1;
       activeRelay.relayPort2=IOPORT_F;
       activeRelay.relayPin2=BIT_0;
       GetParams(port,_bits,buf1, activeRelay);         // select params from Chn1$2
       
       _bits=BIT_5;
       port=IOPORT_B; 
       
       activeRelay.relayPort1=IOPORT_D;
       activeRelay.relayPin1=BIT_7;
       activeRelay.relayPort2=IOPORT_D;
       activeRelay.relayPin2=BIT_6;
      GetParams(port,_bits,buf2,activeRelay);           // select params from Chn3$4
       
       _bits=BIT_4;
       port=IOPORT_B;
       
       activeRelay.relayPort1=IOPORT_D;
       activeRelay.relayPin1=BIT_5;
       activeRelay.relayPort2=IOPORT_D;
       activeRelay.relayPin2=BIT_4;
       GetParams(port,_bits,buf3,activeRelay);           // select params from Chn5$6
       
       _bits=BIT_2;
       port=IOPORT_B;
       
       activeRelay.relayPort1=IOPORT_C;
       activeRelay.relayPin1=BIT_14;
       activeRelay.relayPort2=IOPORT_C;
       activeRelay.relayPin2=BIT_13;
       GetParams(port,_bits,buf4,activeRelay);           // select params from Chn7$8
       
       _bits=BIT_3;
       port=IOPORT_B;
       
       activeRelay.relayPort1=IOPORT_B;
       activeRelay.relayPin1=BIT_8;
       activeRelay.relayPort2=IOPORT_B;
       activeRelay.relayPin2=BIT_7;
       GetParams(port,_bits,buf5,activeRelay);           // select params from Chn9$10
       
   }
      
  }                                          // end of main 


 
