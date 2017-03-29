#include <stdio.h>
#include <stdlib.h>
#include <plib.h>
#include <p32xxxx.h>
#include "STPM-define.h"
#include "relay.h"
void Delay(void);
//void ReadFrame(unsigned short address, uint32_t * buffer);
void SendFrame(char readAdd,char writeAdd, char dataLSB,char dataMSB,int port,int _bits);
void FrameDelay(void);
void CheckOverCurrent(uint32_t *dataBuf,IoPortId port, unsigned int relayNum);
/*--------------------------- SPI_Init() routine----------------------------------------*/
/* PORT/pin Definitions:                                                         */
/* En   - PIC32-pin45    RD11                                                    */
/* CS_1 - PIC32-pin8     RG9                                                     */
/* CS_2 - PIC32-pin11    RB5                                                     */
/* CS_3 - PIC32-pin12    RB4                                                     */
/* CS_4 - PIC32-pin14    RB2                                                     */
/* CS_5 - PIC32-pin13    RB3                                                     */
/**/
/* SPI Bus Pins Definition                                                       */
/* SKL2 - PIC32-pin2 - RE6                                                       */
/* SDI2 - PIC32-pin5 - RG7                                                       */
/* SDO2 - PIC32-pin6 - RG8                                                       */
/*-------------------------------------------------------------------------------*/
void SPI_Init()
{
   // Set Inputs/Outputs for SPI communication
   // Option 1
    TRISDbits.TRISD11=0;           //set EN as Output
    TRISGbits.TRISG9=0;            // set CS_1 output
    TRISBbits.TRISB5=0;            // set CS_2 output
    TRISBbits.TRISB4=0;            // set CS_3 output
    TRISBbits.TRISB2=0;            // set CS_4 output
    TRISBbits.TRISB3=0;            // set CS_5 output
   
    //Option2 (macros))
    /*
    mPORTDSetPinsDigitalOut(BIT_11);
    mPORTGSetPinsDigitalOut(BIT_9);
    mPORTBSetPinsDigitalOut(BIT_2|BIT_3|BIT_4|BIT_5);
    
    //Option 2 
    mPORTGSetPinsDigitalOut(BIT_6);
    mPORTGSetPinsDigitalIn(BIT_7);
    mPORTGSetPinsDigitalOut(BIT_8);
   */
    //Open SPI_2 Object
    SpiChnOpen(2,SPICON_MSTEN|SPICON_SMP|SPICON_MODE32|SPICON_ON,4);
}
void  Init_STPM34(int chnSel,unsigned int port, unsigned int _bits)
{
    
     switch (chnSel)
    {
        case 1:                     //select parameters for Chn1/2      //select sensor1 -Ch1,Ch2
            _bits=BIT_9;
            port=IOPORT_G;          //prepare to select CS1
            break;
        case 2:                     //select parameters for Chn3/4      //select sensor1 -Ch3,Ch4
            _bits=BIT_5;
            port=IOPORT_B;          //prepare to select CS2
            break;
        case 3:                     //select parameters for Chn5/6      //select sensor1 -Ch5,Ch6
            _bits=BIT_4;
            port=IOPORT_B;          //prepare to select CS3
            break;
        case 4:                     //select parameters for Chn7/8      //select sensor1 -Ch7,Ch8
            _bits=BIT_2;
            port=IOPORT_B;          //prepare to select CS4
            break;
        case 5:                     //select parameters for Chn9/10     //select sensor1 -Ch9,Ch10
            _bits=BIT_3;
            port=IOPORT_B;          //prepare to select CS5
            break;
         default:
             break;
    }
 
   US1_REG100bits.CRC_EN=0;         //disable CRC polynomial
   readAdd=0x24;
   writeAdd=0x24;
   dataMSB=US1_REG100bits.MSB;
   dataLSB=US1_REG100bits.LSB;
   SendFrame(readAdd,writeAdd,dataLSB,dataMSB,port,_bits);
   
   
    DSP_CR100bits.ENVREF1=1;         //enable default value for Vref1=1.18v for CH0;  
    DSP_CR100bits.TC1=0x2;           //set temperature compensation for CHx; Vref1=1.18v default
    
    readAdd=0x00;                   // select dsp_cr1
    writeAdd=0x00; 
    dataLSB=DSP_CR100bits.LSB;
    dataMSB=DSP_CR100bits.MSB;
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB, port,_bits);    //write to  CR1 register
 
    DSP_CR200bits.ENVREF2=1;         //enable V ref1 bit for CHx;
    DSP_CR200bits.TC2=0x02;          //set temperature compensation for CHx;  Vref2=1.18v default
    
    readAdd=0x02;
    writeAdd=0x02; 
    dataLSB=DSP_CR200bits.LSB;
    dataMSB=DSP_CR200bits.MSB;
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB, port,_bits);    //write to  CR2 register
 
    DSP_CR101bits.BHPFV1=0;          //HPF enable voltage;DC cancellation
    DSP_CR101bits.BHPFC1=0;          //HPF enable current;DC cancellation
    DSP_CR101bits.BLPFV1=0;          //LPF included voltage;set up fundamental mode, read ZCR
    DSP_CR101bits.BLPFC1=0;          //LPF included voltage;set up fundamental mode, read ZCR
    readAdd=0x01;
    writeAdd=0x01; 
    dataLSB=DSP_CR101bits.LSB;
    dataMSB=DSP_CR101bits.MSB;
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB, port,_bits);    //write to  CR1 register
 
   DSP_CR201bits.BHPFV2=0;          //HPF enable voltage;DC cancellation
   DSP_CR201bits.BHPFC2=0;          //HPF enable current;DC cancellation
   DSP_CR201bits.BLPFV2=0;          //LPF bypassed voltage;set up fundamental mode, read ZCR
   DSP_CR201bits.BLPFC2=0;          //LPF bypassed current;set up fundamental mode
   readAdd=0x03;
   writeAdd=0x03;
   dataLSB=DSP_CR201bits.LSB;
   dataMSB=DSP_CR201bits.MSB;
   SendFrame(readAdd,writeAdd,dataLSB,dataMSB, port,_bits);
 
   
    DFE_CR101bits.GAIN1=0x02;           //set current gain for Chn1=75mV for real time work at Iload=30Amps
    DFE_CR101bits.GAIN1=0x01;           //set current gain for Chn1=134mV for simulation
    readAdd=0x19;
    writeAdd=0x19;
    dataLSB=DFE_CR101bits.LSB;
    dataMSB=DFE_CR101bits.MSB;
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB, port,_bits);
   
    //set GAIN2 in DFE_CR2 register
    DFE_CR201bits.GAIN1=0x02;           //set current gain for Chn2=75mV for real time work at Iload=30Amps
    DFE_CR201bits.GAIN1=0x02;           //set current gain for Chn2=134mV for for simulation
    readAdd=0x1B;
    writeAdd=0x1B;
    dataLSB=DFE_CR201bits.LSB;
    dataMSB=DFE_CR201bits.MSB;
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB, port,_bits);

    DSP_CR301bits.SWAuto_Latch=1;        // Automatic measurement register latch at 7.8125 kHz
    readAdd=0x05;
    writeAdd=0x05;
    dataMSB=DSP_CR301bits.MSB;
    dataLSB=DSP_CR301bits.LSB;
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB, port,_bits);
 }


void FrameDelay(void)
{
    int delayValue;
    delayValue=30;
    while(delayValue--);
    
}

 void Delay(void)
{
    int delayValue;
    delayValue=8*1;
    while(delayValue--);
}

void SendFrame(char readAdd,char writeAdd, char dataLSB,char dataMSB,int port,int _bits)
{
/* This subroutine sends a SPI frame - 32 bits to the sensor ICs stpm34  */
 
   transferValue=SPI2BUF;                   // clear up the receive Buffer SPI2BUF
   sendBuff[0]=readAdd;
   sendBuff[1]=writeAdd;
   sendBuff[2]=dataLSB;
   sendBuff[3]=dataMSB;
   transferValue1=(sendBuff[0]<<8)|(sendBuff[1]);
   transferValue2=(sendBuff[2])<<8|(sendBuff[3]);
   transferValue=(transferValue1<<16)|(transferValue2);
                                           
    PORTClearBits(port,_bits);             //activate CSx x={1,2,3,4,5}
    
    while(SPI2STATbits.SPITBF==1){}
       SPI2BUF=transferValue;
      FrameDelay();
//      while(SPI2STATbits.SPIRBF==0){}               //bit0=SPIRBF  23.03.2017
       receiveBuffer=SPI2BUF;
   
   PORTToggleBits(port,_bits);              //deactivate CSx
  
}

void ReadFrame(unsigned short address, uint32_t *buffer,int port,int _bits)
{
    uint32_t *tempbuff;
    
    readAdd=address;                                //read register from register map
    writeAdd=address;                               //dummy write address
    dataLSB=0xff;                                   //dummy byte
    dataMSB=0xff;                                   //dummy byte

    SendFrame(readAdd,writeAdd,dataLSB,dataMSB, port,_bits);
   //Send Frame
    receiveBuffer=SPI2BUF;
    receiveBuffer=SPI2BUF;
      
    mPORTGClearBits(BIT_9);                          //activate CS1
    while(SPI2STATbits.SPITBF==1){}
    SPI2BUF=0xffff0000;                    //send command ff,ff,ff,ff
   
      FrameDelay();                         //should be 4uS
    while(SPI2STATbits.SPIRBF==0){}
      
      *buffer=SPI2BUF;                      //increment buffer  
      buffer++;                                      
    mPORTGSetBits(BIT_9);                       //deactivate CS1     
   
}
/*------------------Relay Zero Crossing routine---------------------------------*/
/*                                                                              */
/*                                                                              */
/*------------------------------------------------------------------------------*/

void Relay_CRZ(void)
{
    int i;
    unsigned int chnSel=5;
    unsigned int port;
    unsigned int _bits;
    
    Init_Relays();               //Initialize Relay OUTPUTS
    SPI_Init();                 //Initialize SPI OUTPUTS
    
    while(chnSel--)
    {    
     Init_STPM34(chnSel,port,_bits);       //initialize all Sensors STPM34
    }
    
    //Set Zero crossing Enable in DSP-cr3
    DSP_CR300bits.ZCR_SEL=0x0;          //select V1 - source of ZCR
    DSP_CR301bits.ZCR_EN=1;
    readAdd=0x05;
    writeAdd=0x05;
    dataLSB=DSP_CR301bits.LSB;
    dataMSB=DSP_CR301bits.MSB;
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB,1,1);
}
void Find_ZCR(void)
{
    uint32_t zcrFlag=0;
    ReadFrame(0x2A,&zcrFlag,IOPORT_G,BIT_9);
    zcrFlag&=0x00001000;
    while(zcrFlag!=0x00001000){}            // check if the ZCR bit in reg DSP ev1 is set active 
}



