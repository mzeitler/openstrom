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
#include <proc/p32mx795f512h.h>
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
void GetParamsEnergyPH1(unsigned int port, unsigned _bits,int *buffer, relay_t activeRelay,int i);
void GetParamsEnergyPH2(unsigned int port, unsigned _bits,int *buffer, relay_t activeRelay,int i);
void GetParamsPowerPH1(unsigned int port, unsigned _bits,int *buffer, relay_t activeRelay,int i);
void GetParamspowerPH2(unsigned int port, unsigned _bits,int *buffer, relay_t activeRelay,int i);
// configuration settings
//#pragma config FPLLMUL = MUL_15,FPLLODIV = DIV_4
#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FPLLODIV = DIV_1, FWDTEN = OFF //FPLLMUL = MUL_15=60Mz,FPLLMUL = MUL_20=80Mhz

//#pragma config POSCMOD = XT, FNOSC = PRIPLL, FPBDIV = DIV_1
#pragma config FNOSC=FRCPLL,POSCMOD=OFF,ICESEL=ICS_PGx1,FPBDIV= DIV_4// old 8 - periphelal clock=20Mhz(FPBDIV)
/*-------------Global Variables--------------------------------------*/
int i,j,k;
int delayValue;
int chnSel=6;                           //the number of sensor IC  20/04/2017
int chnNum=6;
unsigned int port;
unsigned int _bits;
static uint32_t *tempbuff;
uint32_t clearBuffer;
int cs;
/*-------------------------------------------------------------------*/
/*----------Energy Parameter's buffers area--------------------------*/
uint32_t buf1[10];              //contains energy params for Channels 1&2               
uint32_t buf2[10];              //contains energy params for Channels 3&4 
uint32_t buf3[10];              //contains energy params for Channels 5&6 
uint32_t buf4[10];              //contains energy params for Channels 7&8 
uint32_t buf5[10];              //contains energy params for Channels 9&10 
int main()
  {
    
  /* configure the proper PB frequency and the number of wait states */
   SYSTEMConfigWaitStatesAndPB(80000000L);
   CheKseg0CacheOn();                           // enable the cache for the best performance
   RtccShutdown();                              //enable RC13&RC14 as a I/O
   mT2ClearIntFlag();
 /*---------------------------------------------*/
   
   SPI_Init();              //initialize SPI INPUT/OUTPUTS
   
   
   SelectSPI(1);            // select SPI interface communication/1,2,3,4,5/
   SelectSPI(2);
   SelectSPI(3);
   SelectSPI(4);
   SelectSPI(5);

 //  while(chnNum--)
 //  {    
  //     chnSel--; 
     Init_STPM34(1,port,_bits);       //initialize  Sensors STPM34 - 3
     Init_STPM34(2,port,_bits);       //initialize  Sensors STPM34 - 2
     Init_STPM34(3,port,_bits);       //initialize  Sensors STPM34 - 3
     Init_STPM34(4,port,_bits);       //initialize  Sensors STPM34 - 4
     Init_STPM34(5,port,_bits);       //initialize  Sensors STPM34 - 5
 //  }
    
         activeRelayArr[0].relayPort1=IOPORT_F;
         activeRelayArr[0].relayPin1=BIT_1;        
         activeRelayArr[0].relayPort2=IOPORT_F;
         activeRelayArr[0].relayPin2=BIT_0;
         
         activeRelayArr[1].relayPort1=IOPORT_D;
         activeRelayArr[1].relayPin1=BIT_7;        
         activeRelayArr[1].relayPort2=IOPORT_D;
         activeRelayArr[1].relayPin2=BIT_6;
         
         activeRelayArr[2].relayPort1=IOPORT_D;
         activeRelayArr[2].relayPin1=BIT_5;
         activeRelayArr[2].relayPort2=IOPORT_D;
         activeRelayArr[2].relayPin2=BIT_4;
         
         activeRelayArr[3].relayPort1=IOPORT_C;
         activeRelayArr[3].relayPin1=BIT_14;
         activeRelayArr[3].relayPort2=IOPORT_C;
         activeRelayArr[3].relayPin2=BIT_13;
         
         activeRelayArr[4].relayPort1=IOPORT_B;
         activeRelayArr[4].relayPin1=BIT_8;
         activeRelayArr[4].relayPort2=IOPORT_B;
         activeRelayArr[4].relayPin2=BIT_7;
    
   while(1)
   {
       /*
       _bits=BIT_9;                         //CS1 active
       port=IOPORT_G;                       //IOPORT_G=0x05
       i=0;
       GetParamsEnergyPH1(port,_bits,buf1, activeRelayArr[0],i);         // select params from Chn1$2
       GetParamsEnergyPH2(port,_bits,buf1, activeRelayArr[0],i); 
       
       _bits=BIT_5;                         //CS2 active
       port=IOPORT_B; 
       i=1;      
       GetParamsEnergyPH1(port,_bits,buf1, activeRelayArr[0],i);         // select params from Chn3$4
       GetParamsEnergyPH2(port,_bits,buf1, activeRelayArr[0],i);
 
       _bits=BIT_4;                                     //CS3 active
       port=IOPORT_B;
       i=2;     
       GetParamsEnergyPH1(port,_bits,buf1, activeRelayArr[0],i);         // select params from Chn5$6
       GetParamsEnergyPH2(port,_bits,buf1, activeRelayArr[0],i);
     */
       SelectSPI(4);
       _bits=BIT_2;                                 //CS4 active
       port=IOPORT_B;
       i=0;      
       GetParamsEnergyPH1(port,_bits,buf1, activeRelayArr[0],i);         // select params from Chn7$8
     //  GetParamsEnergyPH2(port,_bits,buf1, activeRelayArr[0],i);
       
      SelectSPI(5);  
     _bits=BIT_3;                                  //CS5 active
      port=IOPORT_B;
      i=1;
      GetParamsEnergyPH1(port,_bits,buf1, activeRelayArr[0],i);         // select params from Chn9$10
    //  GetParamsEnergyPH2(port,_bits,buf1, activeRelayArr[0],i);
   
   }
}


 
