/* 
 * File:   main.c
 * Author: Anton Tachev
 * Description: The test function SM-SPI-STMP01 configurates STPM 34 IC in
 * fundamental mode and reads the following parameters:
 * -Active Energy;
 * -Reactive Energy
 * Created on:    09.Jan 2016
 */
/*SPI 2 module identification                                                */
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
//#include <spi.h>
#include "STPM-define.h"
/*----------------Function prototypes -----------------------------------------*/

void Init_STPM34(int chnSel);        //function prototype ale defined in STPm34_header.h
void SPI_Init();
void Delay(void);
void ReadFrame(unsigned short address, uint32_t * buffer);
void SendFrame(char readAdd,char writeAdd, char dataLSB,char dataMSB,int port,int bits);
void FrameDelay(void);                          

//test frame code
void TestWriteFrame();                               // only for verifying
void TestReadFrame();



// configuration settings
//#pragma config FPLLMUL = MUL_15,FPLLODIV = DIV_4
#pragma config FPLLMUL = MUL_15, FPLLIDIV = DIV_2, FPLLODIV = DIV_4, FWDTEN = OFF
//#pragma config POSCMOD = XT, FNOSC = PRIPLL, FPBDIV = DIV_1
#pragma config FNOSC=FRCPLL,POSCMOD=OFF,ICESEL=ICS_PGx1
/*-------------Global Variables--------------------------------------*/
int i,j,k;
int delayValue;
int chnSel=6;                           //the number of sensor IC 
unsigned int port;
unsigned int _bits;
static uint32_t *tempbuff;
  int main()
  {
   
  /* configure the proper PB frequency and the number of wait states */
   SYSTEMConfigWaitStatesAndPB(80000000L);
   CheKseg0CacheOn();                           // enable the cache for the best performance
   RtccShutdown();                              //enable RC13&RC14 as a I/O
 
 /*---------------------------------------------*/
   SPI_Init();              //initialize SPI INPUT/OUTPUTS
  //  while(chnSel--)
  // {    
  //  Init_STPM34(chnSel);       //initialize all Sensors STPM34
  // }
   while(1)
   {
       for(i=0;i<5;i++)
          {
            //1. Read Current and Voltage parameters from Chn[i]
            port=IOPORT_G;
            _bits=BIT_9;
            tempbuff=Buffer[i];
            parm_Reg[i].Address=V1_Data_Address;     
            parm_Reg[i].dataBuffer=Buffer[i];
            ReadFrame(parm_Reg[i].Address,parm_Reg[i].dataBuffer);  //read voltage(V1) value from Chn1
           
            parm_Reg[i].Address=C1_Data_Address;
            parm_Reg[i].dataBuffer=Buffer[i];
            ReadFrame(parm_Reg[i].Address,parm_Reg[i].dataBuffer);  //read current(C1) value from Chn1
            
            parm_Reg[i].Address=V2_Data_Address;                    //read voltage(V2) value from Chn2
            parm_Reg[i].dataBuffer=Buffer[i];
            ReadFrame(parm_Reg[i].Address,parm_Reg[i].dataBuffer);
            
            parm_Reg[i].Address=C2_Data_Address;                    //read current(C2) value from Chn2
            parm_Reg[i].dataBuffer=Buffer[i];
            ReadFrame(parm_Reg[i].Address,parm_Reg[i].dataBuffer);
            
            parm_Reg[i].Address=PH1_Active_Energy_Address;          //read PH1 Active energy chn1
            parm_Reg[i].dataBuffer=Buffer[i];
            ReadFrame(parm_Reg[0].Address,parm_Reg[0].dataBuffer);
            
            parm_Reg[i].Address=PH1_Reactive_Energy_Address;          //read PH1 Reactive energy chn1
            parm_Reg[i].dataBuffer=Buffer[i];
            ReadFrame(parm_Reg[i].Address,parm_Reg[i].dataBuffer);
            
            parm_Reg[i].Address=PH1_Active_Power_Address;          //read PH1 Power power chn1
            parm_Reg[i].dataBuffer=Buffer[i];
            ReadFrame(parm_Reg[i].Address,parm_Reg[i].dataBuffer);
            
            parm_Reg[i].Address=PH1_Reactive_Power_Address;          //read PH1 Active power chn1
            parm_Reg[i].dataBuffer=Buffer[i];
            ReadFrame(parm_Reg[i].Address,parm_Reg[i].dataBuffer);
            
            parm_Reg[i].Address=PH2_Active_Energy_Address;          //read PH2 Active energy chn1
            parm_Reg[i].dataBuffer=Buffer[i];
            ReadFrame(parm_Reg[i].Address,parm_Reg[i].dataBuffer);
            
            parm_Reg[i].Address=PH2_Reactive_Energy_Address;          //read PH2 Reactive energy chn1
            parm_Reg[i].dataBuffer=Buffer[i];
            ReadFrame(parm_Reg[i].Address,parm_Reg[i].dataBuffer);
            
            parm_Reg[i].Address=PH2_Active_Power_Address;          //read PH2 Power power chn1
            parm_Reg[i].dataBuffer=Buffer[i];
            ReadFrame(parm_Reg[i].Address,parm_Reg[i].dataBuffer);
            
            parm_Reg[i].Address=PH2_Reactive_Power_Address;          //read PH2 Active power chn1
            parm_Reg[i].dataBuffer=Buffer[i];
            ReadFrame(parm_Reg[i].Address,parm_Reg[i].dataBuffer);  
        }
    
   
    }
      //1. Read Current and Voltage parameters from Chn1:
      // - V1_Data[23:0] from dsp_reg2
      /*------------------------------------------------------------------------*/  
      /*  parm_Reg[0].Address=V1_Data_Address;
        parm_Reg[0].dataBuffer=Chn_Buffer1;
        ReadFrame(parm_Reg[0].Address,parm_Reg[0].dataBuffer);  //read voltage(V1) value from Chn1
      
         
        parm_Reg[0].Address=C1_Data_Address;
        parm_Reg[0].dataBuffer=Chn_Buffer1;
        ReadFrame(parm_Reg[0].Address,parm_Reg[0].dataBuffer);  //read current(C1) value from Chn1 */
      /*------------------------------------------------------------------------*/
       //2. Read Current and Voltage parameters from Chn2:
      // - V2_Data[23:0] from dsp_reg4
        
     /* parm_Reg[1].Address=V2_Data_Address;                    //read voltage(V2) value from Chn2
        parm_Reg[1].dataBuffer=Chn_Buffer1;
        ReadFrame(parm_Reg[1].Address,parm_Reg[1].dataBuffer);
        
         
        parm_Reg[1].Address=C2_Data_Address;                    //read current(C2) value from Chn2
        parm_Reg[1].dataBuffer=C5hn_Buffer1;
        ReadFrame(parm_Reg[1].Address,parm_Reg[1].dataBuffer);
      /*------------------------------------------------------------------------*/   
         //3. Read Fund Current and Fund Voltage parameters from Chn3:
      // - V1_Fund[23:0] from dsp_reg6
     /* parm_Reg[2].Address=V1_Fund_Address;                      //read voltage(V1) value from Chn3
        parm_Reg[2].dataBuffer=Chn_Buffer3;
        ReadFrame(parm_Reg[2].Address,parm_Reg[2].dataBuffer);    
        
      //-C1_Fund[23:0] from dsp reg7
         
         parm_Reg[2].Address=C1_Fund_Address;                     //read current(C1) value from Chn3
         parm_Reg[2].dataBuffer=Chn_Buffer1;
         ReadFrame(parm_Reg[2].Address,parm_Reg[2].dataBuffer);
       /*------------------------------------------------------------------------*/
       //2. Read Fund Current and Fund Voltage parameters from Chn4:
      // - V2_Fund[23:0] from dsp_reg8
        
     /* parm_Reg[3].Address=V1_Fund_Address;
        parm_Reg[3].dataBuffer=Chn_Buffer1;
        ReadFrame(parm_Reg[0].Address,parm_Reg[0].dataBuffer);
        
         //-C2_Fund[23:0] from dsp reg9
         
         parm_Reg[0].Address=C2_Fund_Address;
         parm_Reg[0].dataBuffer=Chn_Buffer1;
         
         // PH1 Fundamental Energy ph1_reg2
         parm_Reg[0].Address=PH1_Fundamental_Energy_Address;
         parm_Reg[0].dataBuffer=Chn_Buffer1;
         ReadFrame(parm_Reg[0].Address,parm_Reg[0].dataBuffer);
         
    }*/
    
}       //  ReadFrame(parm_Reg[0].Address,parm_Reg[0].dataBuffer);


/*-------------------------------------------------------------------------------*/
/* PORT/pin Definitions:                                                         */
/* En   - PIC32-pin45    RD11                                                    */
/* CS_1 - PIC32-pin8     RG9                                                     */
/* CS_2 - PIC32-pin11    RG5                                                     */
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
    
    mPORTDSetPinsDigitalOut(BIT_11);
    mPORTGSetPinsDigitalOut(BIT_9);
    mPORTBSetPinsDigitalOut(BIT_2|BIT_3|BIT_4|BIT_5);
    
    //Option 2 
    mPORTGSetPinsDigitalOut(BIT_6);
    mPORTGSetPinsDigitalIn(BIT_7);
    mPORTGSetPinsDigitalOut(BIT_8);
   
    //Open SPI_2 Object
    SpiChnOpen(2,SPICON_MSTEN|SPICON_SMP|SPICON_MODE32|SPICON_ON,4);
}
void  Init_STPM34(int chnSel)
{
    //int tempChipSel;
    //tempChipSel=chipSel;
     switch (chnSel)
    {
        case 1:                     //select parameters for Chn1/2      //select sensor1 -Ch1,Ch2
            _bits=BIT_9;
            port=IOPORT_G;
            break;
        case 2:                     //select parameters for Chn3/4      //select sensor1 -Ch3,Ch4
            _bits=BIT_5;
            port=IOPORT_B;
            break;
        case 3:                     //select parameters for Chn5/6      //select sensor1 -Ch5,Ch6
            _bits=BIT_4;
            port=IOPORT_B;
            break;
        case 4:                     //select parameters for Chn7/8      //select sensor1 -Ch7,Ch8
            _bits=BIT_2;
            port=IOPORT_B;
            break;
        case 5:                     //select parameters for Chn9/10     //select sensor1 -Ch9,Ch10
            _bits=BIT_3;
            port=IOPORT_B;
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
    DSP_CR100bits.TC1=0x2;           //set temperature compensation for CH0; Vref1=1.18v default
    
    readAdd=0x00;                   // select dsp_cr1
    writeAdd=0x00; 
    dataLSB=DSP_CR100bits.LSB;
    dataMSB=DSP_CR100bits.MSB;
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB, port,_bits);    //write to  CR1 register
 
    DSP_CR200bits.ENVREF2=1;         //enable V ref1 bit for CH1;
    DSP_CR200bits.TC2=0x02;          //set temperature compensation for CH1;  Vref2=1.18v default
    
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

void TestWriteFrame()
{
    sendBuff[0]=0x00;                   //readAdd;
    sendBuff[1]=0x00;                   //writeAdd;
    sendBuff[2]=0x05;                   //dataLSB;
    sendBuff[3]=0x00;                   //dataMSB;
    transferValue1=(sendBuff[0]<<8)|(sendBuff[1]);
    transferValue2=(sendBuff[2]<<8)|(sendBuff[3]);
    transferValue=(transferValue1<<16)|(transferValue2);
                                               // activate Enable signal
     mPORTDSetBits(BIT_11);
    //LATGbits.LATG9=0;                       //activate CS1
    mPORTGClearBits(BIT_9);
    while(SPI2STATbits.SPITBF==1){}
    SPI2BUF=transferValue;
    FrameDelay();
    mPORTGSetBits(BIT_9);              
}
void FrameDelay(void)
{
    delayValue=30;
    while(delayValue--);
    
}

 void Delay(void)
{
    delayValue=8*1;
    while(delayValue--);
}

void SendFrame(char readAdd,char writeAdd, char dataLSB,char dataMSB,int port,int bits)
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
                                           
    PORTClearBits(port, _bits);             //activate CSx x={1,2,3,4,5}
    
    while(SPI2STATbits.SPITBF==1){}
       SPI2BUF=transferValue;
      FrameDelay();
      while(SPI2STATbits.SPIRBF==0){}               //bit0=SPIRBF
       receiveBuffer=SPI2BUF;
   
   PORTToggleBits(port,_bits);              //deactivate CSx
  
}

void ReadFrame(unsigned short address, uint32_t *buffer)
{
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
         
      buffer=tempbuff;
      *buffer=SPI2BUF;
      tempbuff=buffer+1;
      
        // *buffer=SPI2BUF;
        //  buffer=buffer+1;
           //*buf1=SPI2BUF;
                                       //increment buffer        
    mPORTGSetBits(BIT_9);                       //deactivate CS1     
   
}

/*  void TestReadFrame()
 {
        receiveBuffer=SPI2BUF;
        SendFrame(0xff,0xff,0xff,0xff);                       
   
    //  FrameDelay();                         //should be 4uS
   
    while(SPI2STATbits.SPIRBF==0){}
         receiveBuffer=SPI2BUF;
        // *buffer=SPI2BUF;
         //*buffer=receiveBuffer;
   
    mPORTGSetBits(BIT_9);                       //deactivate CS1    
    mPORTDSetBits(BIT_11);                  // deactivate Enable signal
 }  */
 
