/* 
 * File:   main.c
 * Author: Anton Tachev
 * Description: The test function SM-SPI-STMP01 configurates STPM 34 IC in
 * fundamental mode and reads the following parameters:
 * -Active Energy;
 * -Reactive Energy
 * Created on 09.Jan 2016
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
#include <STPM34_header.h>
#include "STPM-define.h"
/*----------------Function prototypes -----------------------------------------*/

void  Init_STPM34();        //function prototype ale defined in STPm34_header.h
void  SPI_Init();
void Delay(void);
void ReadFrame(unsigned int address, unsigned int* buffer);
void SendFrame(char readAdd,char writeAdd, char dataLSB,char dataMSB);


// configuration settings

#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FPLLODIV = DIV_8, FWDTEN = OFF
#pragma config POSCMOD = HS, FNOSC = PRIPLL, FPBDIV = DIV_1
int i,j,k;
int delayValue;

 
  int main()
  {
   
  // configure the proper PB frequency and the number of wait states
    SYSTEMConfigWaitStatesAndPB(80000000L);
    CheKseg0CacheOn();                           // enable the cache for the best performanc 
    
    SPI_Init();
    Init_STPM34();
 
    while(1)
    {
      
      //1. Read Current and Voltage parameters from Chn1:
      // - V1_Data[23:0] from dsp_reg2
        
        parm_Reg[0].Address=V1_Data_Address;
        parm_Reg[0].dataBuffer=Chn_Buffer1;
        ReadFrame(parm_Reg[0].Address,parm_Reg[0].dataBuffer);
      //-C1_Data[23:0] from dsp reg3
         
         parm_Reg[0].Address=C1_Data_Address;
         parm_Reg[0].dataBuffer=Chn_Buffer1;
         ReadFrame(parm_Reg[0].Address,parm_Reg[0].dataBuffer);
    
       //2. Read Current and Voltage parameters from Chn2:
      // - V2_Data[23:0] from dsp_reg4
        
        parm_Reg[0].Address=V2_Data_Address;
        parm_Reg[0].dataBuffer=Chn_Buffer2;
        ReadFrame(parm_Reg[0].Address,parm_Reg[0].dataBuffer);
         //-C2_Data[23:0] from dsp reg5
         
         parm_Reg[0].Address=C2_Data_Address;
         parm_Reg[0].dataBuffer=Chn_Buffer2;
         ReadFrame(parm_Reg[0].Address,parm_Reg[0].dataBuffer);
         
         //3. Read Fund Current and Fund Voltage parameters from Chn1:
      // - V1_Fund[23:0] from dsp_reg6
        parm_Reg[0].Address=V1_Fund_Address;
        parm_Reg[0].dataBuffer=Chn_Buffer1;
        ReadFrame(parm_Reg[0].Address,parm_Reg[0].dataBuffer);
        
      //-C1_Fund[23:0] from dsp reg7
         
         parm_Reg[0].Address=C1_Fund_Address;
         parm_Reg[0].dataBuffer=Chn_Buffer1;
         ReadFrame(parm_Reg[0].Address,parm_Reg[0].dataBuffer);
    
       //2. Read Fund Current and Fund Voltage parameters from Chn2:
      // - V2_Fund[23:0] from dsp_reg8
        
        parm_Reg[0].Address=V2_Fund_Address;
        parm_Reg[0].dataBuffer=Chn_Buffer2;
        ReadFrame(parm_Reg[0].Address,parm_Reg[0].dataBuffer);
        
         //-C2_Fund[23:0] from dsp reg9
         
         parm_Reg[0].Address=C2_Fund_Address;
         parm_Reg[0].dataBuffer=Chn_Buffer2;
         ReadFrame(parm_Reg[0].Address,parm_Reg[0].dataBuffer);
         
    
         
    }
    
}
void SPI_Init()
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
    
    /*    Set SPI Bus pins                           */
    //Option1
    TRISEbits.TRISE6=0;                //SCL2 output
    TRISGbits.TRISG7=1;                //SDI2 - input(MISO)
    TRISGbits.TRISG8=0;                // SDO2 - output(MOSI)
    
    //Option 2 
    mPORTDSetPinsDigitalOut(BIT_6);
    mPORTDSetPinsDigitalIn(BIT_7);
    mPORTGSetPinsDigitalOut(BIT_8);
    
    //Open SPI_2 Object
    SpiChnOpen(2,SPICON_MSTEN|SPICON_SMP|SPICON_MODE16|SPICON_ON,4);
    }
void  Init_STPM34()
{
 
    //set Voltage Reference
   
    DSP_CR100bits.ENVREF1=1;         //enable Vref1 bit for CH0;  
    DSP_CR100bits.TC1=0x2;           //set temperature compensation for CH0; Vref1=1.18v default
    
    readAdd=0x00;
    writeAdd=0x00; 
    dataLSB=DSP_CR100bits.LSB;
    dataMSB=DSP_CR100bits.MSB;
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB);    //write to  CR1 register
    
    DSP_CR200bits.ENVREF2=1;         //enable V ref1 bit for CH1;
    DSP_CR200bits.TC2=0x02;          //set temperature compensation for CH1;  Vref2=1.18v default
    
    readAdd=0x00;
    writeAdd=0x02; 
    dataLSB=DSP_CR200bits.LSB;
    dataMSB=DSP_CR200bits.MSB;
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB);    //write to  CR2 register
    /***********************************/
   
   DSP_CR101bits.BHPFV1=0;          //HPF enable voltage;DC cancellation
   DSP_CR101bits.BHPFC1=0;          //HPF enable current;DC cancellation
   DSP_CR101bits.BLPFV1=1;          //LPF wideband voltage;set up fundamental mode
   DSP_CR101bits.BLPFC1=1;          //LPF wideband current;set up fundamental mode
  
   readAdd=0x01;
   writeAdd=0x01; 
   dataLSB=DSP_CR101bits.LSB;
   dataMSB=DSP_CR101bits.MSB;
   SendFrame(readAdd,writeAdd,dataLSB,dataMSB);    //write to  CR1 register
   
   DSP_CR201bits.BHPFV2=0;          //HPF enable voltage;DC cancellation
   DSP_CR201bits.BHPFC2=0;          //HPF enable current;DC cancellation
   DSP_CR201bits.BLPFV2=1;          //LPF wideband voltage;set up fundamental mode
   DSP_CR201bits.BLPFC2=1;          //LPF wideband current;set up fundamental mode
   readAdd=0x03;
   writeAdd=0x03;
   dataLSB=DSP_CR201bits.LSB;
   dataMSB=DSP_CR201bits.MSB;
   SendFrame(readAdd,writeAdd,dataLSB,dataMSB);
   
   //set GAIN1, in DFE_CR1 register
   
    DFE_CR101bits.GAIN1=0x02;           //set current gain for Chn1
    readAdd=0x00;
    writeAdd=0x19;
    dataLSB=DFE_CR101bits.LSB;
    dataMSB=DFE_CR101bits.MSB;
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB);
    
    //set GAIN2 in DFE_CR2 register
    DFE_CR201bits.GAIN1=0x02;           //set current gain for Chn2
    readAdd=0x00;
    writeAdd=0x1B;
    dataLSB=DFE_CR201bits.LSB;
    dataMSB=DFE_CR201bits.MSB;
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB);
  
   DSP_CR301bits.SWAuto_Latch=1;        // Automatic measurement register latch at 7.8125 kHz
   readAdd=0x05;
   writeAdd=0x05;
   dataLSB=DSP_CR301bits.LSB;
   dataMSB=DSP_CR301bits.MSB;
   SendFrame(readAdd,writeAdd,dataLSB,dataMSB);
   
 }

void SendFrame(char readAdd,char writeAdd, char dataLSB,char dataMSB)
{
    sendBuff[0]=readAdd;
    sendBuff[1]=writeAdd;
    sendBuff[2]=dataLSB;
    sendBuff[3]=dataMSB;
      
        pSrc=sendBuff; 
        for(ix=0;ix<4;ix++)
        {
            SpiChnPutC(1,*pSrc++);// send data
        }
  
}
void Delay(void)
{
    delayValue=80*100;
    while(delayValue--);
    
}
void ReadFrame(unsigned int address, unsigned int *buffer)
{
    readAdd=address;
    writeAdd=0xff;
    dataLSB=0xff;
    dataMSB=0xff;
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB);
     for(i=0;i<10;i++)
         {
            SpiChnGetS(2,buffer,4);
            Delay();
         }  
}
