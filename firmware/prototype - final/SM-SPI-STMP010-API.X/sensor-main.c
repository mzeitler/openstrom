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
#include <stdint.h>
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

void ReadC1Data(uint32_t *dataBuf,int port, relay_t relayNum, unsigned  _bits);
void ReadC2Data(uint32_t *dataBuf, int port, relay_t relayNum, unsigned _bits);

void GetParamsPowerPH1A(unsigned int port,unsigned int _bits,uint32_t *buf1);
void GetParamsPowerPH1R(unsigned int port,unsigned int _bits,uint32_t *buf1);
void GetParamsPowerPH2A(unsigned int port,unsigned int _bits,uint32_t *buf1);
void GetParamsPowerPH2R(unsigned int port,unsigned int _bits,uint32_t *buf1);

void BlockCRC(unsigned int port, unsigned _bits);
void CHCalibrate();
uint32_t Converse(uint32_t doubleword);
uint32_t PowerConverse(uint32_t doubleword);
void TestRWparameters(void);

void Get1();
void Get2();
// configuration settings
//#pragma config FPLLMUL = MUL_15,FPLLODIV = DIV_4
#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FPLLODIV = DIV_1, FWDTEN = OFF //FPLLMUL = MUL_15=60Mz,FPLLMUL = MUL_20=80Mhz

#pragma config POSCMOD = XT, FNOSC = PRIPLL, FPBDIV = DIV_4,ICESEL=ICS_PGx1
//#pragma config FNOSC=FRCPLL,POSCMOD=OFF,ICESEL=ICS_PGx1,FPBDIV= DIV_4// old 8 - periphelal clock=20Mhz(FPBDIV)
/*-------------Global Variables--------------------------------------*/
int i,j,k,l;
int delayValue;
int chnSel=6;                           //the number of sensor IC  20/04/2017
int chnNum=6;
uint32_t v1_bytes;
uint32_t c1_bytes;
uint32_t limitCurrentValue1=0x0000a740;     //this value is 40Amps input current
unsigned int port;
unsigned int _bits;
unsigned int bits5;
static uint32_t *tempbuff;
uint32_t receiveBuffer1;
uint32_t clearBuffer;
int cs;
/*-------------------------------------------------------------------*/
/*----------Energy Parameter's buffers area--------------------------*/

uint32_t buf1[10];              //contains energy params for Channels 1               
uint32_t buf2[10];              //contains energy params for Channels 2 
uint32_t buf3[10];              //contains energy params for Channels 3 
uint32_t buf4[10];              //contains energy params for Channels 4 
uint32_t buf5[10];              //contains energy params for Channels 5
uint32_t buf6[10];              //contains energy params for Channels 6
uint32_t buf7[10];              //contains energy params for Channels 7
uint32_t buf8[10];              //contains energy params for Channels 8
uint32_t buf9[10];              //contains energy params for Channels 9
uint32_t buf10[10];              //contains energy params for Channels 10
uint32_t *buff1;
uint32_t *buff2;
uint32_t pr;
unsigned char crcCom[5]={0x24,0x24,0x07,0x00,0x15};
int main()
  {
  
  /* configure the proper PB frequency and the number of wait states */
   SYSTEMConfigWaitStatesAndPB(80000000L);
   CheKseg0CacheOn();                           // enable the cache for the best performance
   RtccShutdown();                              //enable RC13&RC14 as a I/O
   mT2ClearIntFlag();
 /*---------------------------------------------*/
 
   SPI_Init();              //initialize SPI INPUT/OUTPUTS
   STPMInitReset();
   SelectSPIall();          //very important select channel SPI
   SetSPIx(1);             // Select SPI for SPTM34-1 
   _bits=BIT_9;
   port=IOPORT_G;
   BlockCRC(port,_bits);

   buff1=buf1;
   Init_STPM34(1,port,_bits);        //(the last 1,port,_bits)
 // CHCalibrate();
  //SpiInit1();
 // TestRWparameters();                 // very important use for separated testing
// to do test program //
  
  activeRelayArr[0].relayPort1=IOPORT_F;            //select port F
  activeRelayArr[0].relayPin1=BIT_1;                //select Relay1 - connector P2-15
  activeRelayArr[0].relayPort2=IOPORT_F;            //select port F
  activeRelayArr[0].relayPin2=BIT_0;                //select Relay2 - connector P2-16
         
  activeRelayArr[1].relayPort1=IOPORT_D;            //select port D
  activeRelayArr[1].relayPin1=BIT_7;                //select Relay3 - connector P2-17
  activeRelayArr[1].relayPort2=IOPORT_D;            //select port D
  activeRelayArr[1].relayPin2=BIT_6;                //select Relay4 - connector P2-18
         
  activeRelayArr[2].relayPort1=IOPORT_D;            //select port D
  activeRelayArr[2].relayPin1=BIT_5;                //select Relay5 - connector P2-19
  activeRelayArr[2].relayPort2=IOPORT_D;            //select port D
  activeRelayArr[2].relayPin2=BIT_4;                //select Relay6 - connector P2-20
         
  activeRelayArr[3].relayPort1=IOPORT_C;            //select port C
  activeRelayArr[3].relayPin1=BIT_14;               //select Relay7 - connector P2-21
  activeRelayArr[3].relayPort2=IOPORT_C;            //select port C
  activeRelayArr[3].relayPin2=BIT_13;               //select Relay8 - connector P2-22
         
  activeRelayArr[4].relayPort1=IOPORT_B;            //select port B
  activeRelayArr[4].relayPin1=BIT_8;                //select Relay9 - connector P2-23
  activeRelayArr[4].relayPort2=IOPORT_B;            //select port B
  activeRelayArr[4].relayPin2=BIT_7;                //select Relay10 - connector P2-24
 
   while(1)
   {
    /*------Select Channel-01&02 and download energy parameters--------------------*/
    /* Input ID Parameters:                                                     */
    /*     - CS1  - BIT_9                                                       */
    /*     - port - IOPORT_G                                                    */
    /*     - active relays -Relay1, Relay2                                      */
    /*     - transfer Buffer-buff1[10],buff2[10]                                          */
    /*     - Energy parameters:                                                 */
    /*          - current Irms;                                                 */
    /*          - voltage Vrms                                                  */
    /*          - Active Power PHx-A                                           */
    /*          - Reactive Power PHx-R                                          */
    /*--------------------------------------------------------------------------*/
      
       SetSPIx(1);                          // set up SPI interface for chn-01 & chn-02   
       _bits=BIT_9;                         //CS1 active
       port=IOPORT_G;                       //IOPORT_G=0x05
       BlockCRC(port,_bits);
       Init_STPM34(1,port,_bits);
       buff1=buf1;
       buff2=buf2;
       j=0;
       i=0;
       ReadC1Data(buff1,port,activeRelayArr[0],_bits);      //Get Irms and Vrms
       j++;
       GetParamsPowerPH1A(port,_bits,buf1);                 // Get Active Power chn1
       j++;
       GetParamsPowerPH1R(port,_bits,buf1);                 // get Reactive power chn1
       i=1;
       j=0;
       ReadC2Data(buff2,port,activeRelayArr[1],_bits);      //Get Irms and Vrms
       j++;
       GetParamsPowerPH2A(port,_bits,buf2);                 // Get Active Power chn2
       j++;
       GetParamsPowerPH2R(port,_bits,buf2);                 // get Reactive power chn2
    /*---------------------------------------------------------------------------*/   
       
    /*------Select Channel-03&04 and download energy parameters--------------------*/
    /* Input ID Parameters:                                                     */
    /*     - CS2  - BIT_5                                                       */
    /*     - port - IOPORT_B                                                    */
    /*     - active relays -Relay3, Relay4                                      */
    /*     - transfer Buffer-buff3[10],buff4[10]                                          */
    /*     - Energy parameters:                                                 */
    /*          - current Irms;                                                 */
    /*          - voltage Vrms                                                  */
    /*          - Active Power PHx-A                                           */
    /*          - Reactive Power PHx-R                                          */
    /*--------------------------------------------------------------------------*/
      
       SetSPIx(2);                          // set up SPI interface for chn-03&04   
       _bits=BIT_5;                         //CS2 active
       port=IOPORT_B;                       
       BlockCRC(port,_bits);
       Init_STPM34(2,port,_bits);
       buff1=buf3;
       buff2=buf4;
       i=2;
       j=0;
       ReadC1Data(buff1,port,activeRelayArr[2],_bits);      //Get Irms and Vrms
       j++;
       GetParamsPowerPH1A(port,_bits,buf1);                 // Get Active Power chn1
       j++;
       GetParamsPowerPH1R(port,_bits,buf1);                 // get Reactive power chn1
       i=3;
       j=0;
       ReadC2Data(buff2,port,activeRelayArr[3],_bits);      //Get Irms and Vrms
       j++;
       GetParamsPowerPH2A(port,_bits,buf2);                 // Get Active Power chn2
       j++;
       GetParamsPowerPH2R(port,_bits,buf2);                 // get Reactive power chn2
    /*--------------------------------------------------------------------------*/  
       
    /*------Select Channel-05&06 and download energy parameters-----------------*/
    /* Input ID Parameters:                                                     */
    /*     - CS3  - BIT_4                                                       */
    /*     - port - IOPORT_B                                                    */
    /*     - active relays -Relay5, Relay6                                      */
    /*     - transfer Buffer-buff5[10],buff6[10]                                          */
    /*     - Energy parameters:                                                 */
    /*          - current Irms;                                                 */
    /*          - voltage Vrms                                                  */
    /*          - Active Power PHx-A                                           */
    /*          - Reactive Power PHx-R                                          */
    /*--------------------------------------------------------------------------*/
      
       SetSPIx(3);                          // set up SPI interface for chn-03&04   
       _bits=BIT_4;                         //CS2 active
       port=IOPORT_B;                       
       BlockCRC(port,_bits);
       Init_STPM34(3,port,_bits);
       buff1=buf5;
       buff2=buf6;
       i=6;
       j=0;
       ReadC1Data(buff1,port,activeRelayArr[4],_bits);      //Get Irms and Vrms
       j++;
       GetParamsPowerPH1A(port,_bits,buf1);                 // Get Active Power chn1
       j++;
       GetParamsPowerPH1R(port,_bits,buf1);                 // get Reactive power chn1
       i=7;
       j=0;
       ReadC2Data(buff2,port,activeRelayArr[4],_bits);      //Get Irms and Vrms
       j++;
       GetParamsPowerPH2A(port,_bits,buf2);                 // Get Active Power chn2
       j++;
       GetParamsPowerPH2R(port,_bits,buf2);                 // get Reactive power chn2
     /*---------------------------------------------------------------*/  
     
    /*------Select Channel-07&08 and download energy parameters----- -----------*/
    /* Input ID Parameters:                                                     */
    /*     - CS4  - BIT_2                                                       */
    /*     - port - IOPORT_B                                                    */
    /*     - active relays -Relay7, Relay8                                      */
    /*     - transfer Buffer-buff7[10],buff8[10]                                          */
    /*     - Energy parameters:                                                 */
    /*          - current Irms;                                                 */
    /*          - voltage Vrms                                                  */
    /*          - Active Power PHx-A                                           */
    /*          - Reactive Power PHx-R                                          */
    /*--------------------------------------------------------------------------*/
    //    GetParamsEnergyPH1(port,_bits,buf2, activeRelayArr[0],i);         // select params from Chn3$4
       SetSPIx(4);                          // set up SPI interface for chn-03&04   
       _bits=BIT_2;                         //CS2 active
       port=IOPORT_B;                       
       BlockCRC(port,_bits);
       Init_STPM34(4,port,_bits);
       buff1=buf7;
       buff2=buf8;
       i=6;
       j=0;
       ReadC1Data(buff1,port,activeRelayArr[6],_bits);      //Get Irms and Vrms
       j++;
       GetParamsPowerPH1A(port,_bits,buf1);                 // Get Active Power chn1
       j++;
       GetParamsPowerPH1R(port,_bits,buf1);                 // get Reactive power chn1
       j++;
       i=7;
       j=0;
       ReadC2Data(buff2,port,activeRelayArr[7],_bits);      //Get Irms and Vrms
       j++;
       GetParamsPowerPH2A(port,_bits,buf2);                 // Get Active Power chn2
       j++;
       GetParamsPowerPH2R(port,_bits,buf2);                 // get Reactive power chn2
    /*---------------------------------------------------------------------------*/
     /*------Select Channel-09&10 and download energy parameters----- -----------*/
    /* Input ID Parameters:                                                     */
    /*     - CS5  - BIT_3                                                       */
    /*     - port - IOPORT_B                                                    */
    /*     - active relays -Relay9, Relay10                                      */
    /*     - transfer Buffer-buff9[10],buff10[10]                                          */
    /*     - Energy parameters:                                                 */
    /*          - current Irms;                                                 */
    /*          - voltage Vrms                                                  */
    /*          - Active Power PHx-A                                           */
    /*          - Reactive Power PHx-R                                          */
    /*--------------------------------------------------------------------------*/
      
       SetSPIx(5);                          // set up SPI interface for chn-03&04   
       _bits=BIT_3;                         //CS2 active
       port=IOPORT_B;                       
       BlockCRC(port,_bits);
       Init_STPM34(5,port,_bits);
       buff1=buf9;
       buff2=buf10;
       i=8;
       j=0;
       ReadC1Data(buff1,port,activeRelayArr[8],_bits);      //Get Irms and Vrms
       j++;
       GetParamsPowerPH1A(port,_bits,buf1);                 // Get Active Power chn1
       j++;
       GetParamsPowerPH1R(port,_bits,buf1);                 // get Reactive power chn1
       i=9;
       j=0;
       ReadC2Data(buff2,port,activeRelayArr[9],_bits);      //Get Irms and Vrms
       j++;
       GetParamsPowerPH2A(port,_bits,buf2);                 // Get Active Power chn2
       j++;
       GetParamsPowerPH2R(port,_bits,buf2);                 // get Reactive power chn2
      
    /*---------------------------------------------------------------------------*/
     
    
      
   }
} 
/*--------------------block CRC Routine----------------------------------------*/
/* This routine disable the CRC communication option --------------------------*/
/* -command    ReadReg, WriteReg, LSB,  MSB,  CRC                        
/*              0x24     0x24     0x07  0x00  0x15                             */

 void BlockCRC(unsigned int port, unsigned _bits)
{
   int i;
   SPI2CONbits.ON=0;            //stopSPI
   SPI2CONbits.MODE16=0;        //set communication byte 8 bits
   SPI2CONbits.MODE32=0;
   SPI2CONbits.ON=1;
 // while(1){                     //test point

   CSxActive(_bits);
   for(i=0;i<5;i++)
   {
       SPI2BUF=crcCom[i];
       while(SPI2STATbits.SPITBF){}
   }
   CSxInActive(_bits);
   FrameDelay();
//}
    SPI2CONbits.ON=0;            //stopSPI
    SPI2CONbits.MODE32=1;        // select Mode 32 bits
    SPI2CONbits.ON=1;            //startSPI
}
void CHCalibrate()
{
    //calibrate voltage V1
  // while(1){ 
   CSxActive(_bits);
   SPI2BUF=0xff10ffff;               //last set up calibration value 8044
   receiveBuffer1=SPI2BUF;
   FrameDelay1();                       //very important delay
   while(SPI2STATbits.SPITBF){}
   CSxInActive(_bits);
   FrameDelay();
  // }
    //calibrate current c1
    CSxActive(_bits);
    SPI2BUF=0x0A0Affff;               //0855last set up calibration value
    receiveBuffer1=SPI2BUF;
    FrameDelay1();                       //very important delay
    while(SPI2STATbits.SPITBF){}
    CSxInActive(_bits);
    FrameDelay();
    
}
uint32_t Converse(uint32_t doubleword)
{
    uint32_t lsb1, lsb2,msb1,msb2,temp;
    uint32_t cmsb2,clsb2;
    temp=doubleword;
    lsb1=temp&0xff000000;
    lsb2=temp&0x00ff0000;
    msb1=temp&0x0000ff00;
    msb2=temp&0x000000ff;
    
    lsb1=lsb1>>24;
    lsb2=lsb2>>8;
    
    msb1=msb1>>8;
    msb2=msb2<<8;
    msb2=msb2/2;
    
    cmsb2=msb2|msb1;
    clsb2=lsb2|lsb1;
    clsb2=clsb2&0x7fff;
    cmsb2=cmsb2<<16;
    return cmsb2|clsb2;
    
}   
uint32_t PowerConverse(uint32_t doubleword)
{
    uint32_t lsb1, lsb2,msb1,msb2,temp;
    uint32_t cmsb2,clsb2;
    temp=doubleword;
    lsb1=temp&0xff000000;
    lsb2=temp&0x00ff0000;
    msb1=temp&0x0000ff00;
    msb2=temp&0x000000ff;
    
    lsb1=lsb1>>24;
    lsb2=lsb2>>8;
    
    msb1=msb1>>8;
    msb2=msb2<<8;
   // msb2=msb2/2;
    
    cmsb2=msb2|msb1;
    clsb2=lsb2|lsb1;
   // clsb2=clsb2&0x7fff;
    cmsb2=cmsb2<<16;
    return (cmsb2|clsb2)/4;
}
void TestRWparameters(void)
{
     
while(1){
    for(j=0;j<50;j++){
         CSxActive(_bits);
         SPI2BUF=0x48ffffff;               //last 0x4058100
         receiveBuffer1=SPI2BUF;
         FrameDelay1();                       //very important delay
         while(SPI2STATbits.SPITBF){}
         CSxInActive(_bits);
         ActiveSYN();           //22.06.2017 very important latch Read registers     
  //-------------------Segment Read Control Register---------------------------//
         receiveBuffer1=SPI2BUF;
         SPI2STATCLR=1<<6;
         CSxActive(_bits);
         SPI2BUF=0xffffffff;      
        // receiveBuffer1=SPI2BUF;
         FrameDelay1();
         while(!SPI2STATbits.SPIRBF){}
            CSxInActive(_bits);
            receiveBuffer1=SPI2BUF;  
            receiveBuffer1=receiveBuffer1<<1;    //14.06.2007 for V,I rms and Power
            buf1[j]=Converse(receiveBuffer1);
          //buf1[j]=PowerConverse(receiveBuffer1);
         // buf1[j]=receiveBuffer1;
         // FrameDelay();         //01.07.2017 17;00
        }  
     
            i=1;
  
    }
}
void ReadC1Data(uint32_t *dataBuf, int port, relay_t relayNum, unsigned _bits)
{
    int i;
    uint32_t tempValue;
  
         CSxActive(_bits);
         SPI2BUF=0x5cffffff;               //last 0x4058100
         receiveBuffer1=SPI2BUF;
         FrameDelay1();                       //very important delay
         while(SPI2STATbits.SPITBF){}
         CSxInActive(_bits);
         ActiveSYN();           //22.06.2017 very important latch Read registers     
  //-------------------Segment Read Control Register---------------------------//
         receiveBuffer1=SPI2BUF;
         SPI2STATCLR=1<<6;
         CSxActive(_bits);
         SPI2BUF=0xffffffff;      
        // receiveBuffer1=SPI2BUF;
         FrameDelay1();
         while(!SPI2STATbits.SPIRBF){}
            CSxInActive(_bits);
            receiveBuffer1=SPI2BUF;  
            receiveBuffer1=receiveBuffer1<<1;    //14.06.2007 for V,I rms and Power
            buf1[j]=Converse(receiveBuffer1);
          //buf1[j]=PowerConverse(receiveBuffer1);
         // buf1[j]=receiveBuffer1;
         // FrameDelay();         //01.07.2017 17;00
  
    if (receiveBuffer1 >= limitCurrentValue1) {
        Find_ZCR();
        Switch_ON_Relay(port, relayNum); //two options for relay switching
        Switch_ON_PWMRelay(port, relayNum);
    }
    // how to Switch OFF relays

}

void ReadC2Data(uint32_t *dataBuf,int port, relay_t relayNum, unsigned _bits)
{
    CSxActive(_bits);
         SPI2BUF=0x48ffffff;               //last 0x4058100
         receiveBuffer1=SPI2BUF;
         FrameDelay1();                       //very important delay
         while(SPI2STATbits.SPITBF){}
         CSxInActive(_bits);
         ActiveSYN();           //22.06.2017 very important latch Read registers     
  //-------------------Segment Read Control Register---------------------------//
         receiveBuffer1=SPI2BUF;
         SPI2STATCLR=1<<6;
         CSxActive(_bits);
         SPI2BUF=0xffffffff;      
        // receiveBuffer1=SPI2BUF;
         FrameDelay1();
         while(!SPI2STATbits.SPIRBF){}
            CSxInActive(_bits);
            receiveBuffer1=SPI2BUF;  
            receiveBuffer1=receiveBuffer1<<1;    //14.06.2007 for V,I rms and Power
            buf1[j]=Converse(receiveBuffer1);
          //buf1[j]=PowerConverse(receiveBuffer1);
         // buf1[j]=receiveBuffer1;
         // FrameDelay();         //01.07.2017 17;00
  
    
    if (receiveBuffer1 >= limitCurrentValue1) {
        Find_ZCR();
        Switch_ON_Relay(port, relayNum);
        Switch_ON_PWMRelay(port, relayNum);
    }
    // how to Switch OFF relays

}
void GetParamsPowerPH1A(unsigned int port,unsigned int _bits,uint32_t *buf1)
{
         CSxActive(_bits);
         SPI2BUF=0x5cffffff;               //get PH1 Active Power Register
         receiveBuffer1=SPI2BUF;
         FrameDelay1();                       //very important delay
         while(SPI2STATbits.SPITBF){}
         CSxInActive(_bits);
         ActiveSYN();           //22.06.2017 very important latch Read registers     
  //-------------------Segment Read Control Register---------------------------//
         receiveBuffer1=SPI2BUF;
         SPI2STATCLR=1<<6;
         CSxActive(_bits);
         SPI2BUF=0xffffffff;      
        // receiveBuffer1=SPI2BUF;
         FrameDelay1();
         while(!SPI2STATbits.SPIRBF){}
            CSxInActive(_bits);
            receiveBuffer1=SPI2BUF;  
            receiveBuffer1=receiveBuffer1<<1;    //14.06.2007 for V,I rms and Power
            buf1[j]=PowerConverse(receiveBuffer1);
         // FrameDelay();         //01.07.2017 17;00
}
void GetParamsPowerPH1R(unsigned int port,unsigned int _bits,uint32_t *buf1)
{
     CSxActive(_bits);
         SPI2BUF=0x60ffffff;               //get PH2 Reactive power Register
         receiveBuffer1=SPI2BUF;
         FrameDelay1();                       //very important delay
         while(SPI2STATbits.SPITBF){}
         CSxInActive(_bits);
         ActiveSYN();           //22.06.2017 very important latch Read registers     
  //-------------------Segment Read Control Register---------------------------//
         receiveBuffer1=SPI2BUF;
         SPI2STATCLR=1<<6;
         CSxActive(_bits);
         SPI2BUF=0xffffffff;      
        // receiveBuffer1=SPI2BUF;
         FrameDelay1();
         while(!SPI2STATbits.SPIRBF){}
            CSxInActive(_bits);
            receiveBuffer1=SPI2BUF;  
            receiveBuffer1=receiveBuffer1<<1;    //14.06.2007 for V,I rms and Power        
            buf1[j]=PowerConverse(receiveBuffer1);       
         // FrameDelay();         //01.07.2017 17;00
}

void GetParamsPowerPH2A(unsigned int port,unsigned int _bits,uint32_t *buf2)
{
         CSxActive(_bits);
         SPI2BUF=0x74ffffff;               //get PH2 Active Power Register
         receiveBuffer1=SPI2BUF;
         FrameDelay1();                       //very important delay
         while(SPI2STATbits.SPITBF){}
         CSxInActive(_bits);
         ActiveSYN();           //22.06.2017 very important latch Read registers     
  //-------------------Segment Read Control Register---------------------------//
         receiveBuffer1=SPI2BUF;
         SPI2STATCLR=1<<6;
         CSxActive(_bits);
         SPI2BUF=0xffffffff;      
        // receiveBuffer1=SPI2BUF;
         FrameDelay1();
         while(!SPI2STATbits.SPIRBF){}
            CSxInActive(_bits);
            receiveBuffer1=SPI2BUF;  
            receiveBuffer1=receiveBuffer1<<1;    //14.06.2007 for V,I rms and Power
            buf1[j]=Converse(receiveBuffer1);
          //buf1[j]=PowerConverse(receiveBuffer1);
         // buf1[j]=receiveBuffer1;
         // FrameDelay();         //01.07.2017 17;00
}
void GetParamsPowerPH2R(unsigned int port,unsigned int _bits,uint32_t *buf2)
{
         CSxActive(_bits);
         SPI2BUF=0x78ffffff;               //get PH2 Reactive Power Register
         receiveBuffer1=SPI2BUF;
         FrameDelay1();                       //very important delay
         while(SPI2STATbits.SPITBF){}
         CSxInActive(_bits);
         ActiveSYN();           //22.06.2017 very important latch Read registers     
  //-------------------Segment Read Control Register---------------------------//
         receiveBuffer1=SPI2BUF;
         SPI2STATCLR=1<<6;
         CSxActive(_bits);
         SPI2BUF=0xffffffff;      
        // receiveBuffer1=SPI2BUF;
         FrameDelay1();
         while(!SPI2STATbits.SPIRBF){}
            CSxInActive(_bits);
            receiveBuffer1=SPI2BUF;  
            receiveBuffer1=receiveBuffer1<<1;    //14.06.2007 for V,I rms and Power        
             buf1[j]=PowerConverse(receiveBuffer1);             
         // FrameDelay();         //01.07.2017 17;00
}