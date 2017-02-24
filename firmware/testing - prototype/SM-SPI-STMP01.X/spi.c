
/* 
 * File:   sdi.c
 * Author: Anton Tachev
 * Location: D:\PLIB-Project\SM-SPI-STMP01.X
 * Created on 20.02 2017, 06:55
 */

#include <plib.h>
#include <p32xxxx.h>
#include "p32mx795f512h.h"
#include "STPM34_header.h"
#include "sdi.h"


void SPI_Init()
/*-------------------------------------------------------------------------------*/
/* PORT/pin Definitions:                                                         */
/* En   - PIC32-pin45    RD11                                                    */
/* CS_1 - PIC32-pin8     RG9   active --|________________|--                     */
/* CS_2 - PIC32-pin11    RG5   active --|________________|--                     */
/* CS_3 - PIC32-pin12    RB4   active --|________________|--                     */
/* CS_4 - PIC32-pin14    RB2   active --|________________|--                     */
/* CS_5 - PIC32-pin13    RB3   active --|________________|--                     */
/**/
/* SPI Bus Pins Definition                                                       */
/* SKL2 - PIC32-pin2 - RE6                                                       */
/* SDI2 - PIC32-pin5 - RG7                                                       */
/* SDO2 - PIC32-pin6 - RG8                                                       */
/*-------------------------------------------------------------------------------*/

void Init_SPI(void)
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
    
    
    //Set SPI Bus pins                    
    //Option1
      TRISEbits.TRISE6=0;               //SCL2 output
      TRISGbits.TRISG7=1;               //SDI2 - input(MISO)
      TRISGbits.TRISG8=0;               // SDO2 - output(MOSI)
    
    //Option 2 
    mPORTGSetPinsDigitalOut(BIT_6);
    mPORTGSetPinsDigitalIn(BIT_7);
    mPORTGSetPinsDigitalOut(BIT_8);
    //Open SPI_2 Object
    SpiChnOpen(2,SPICON_MSTEN|SPICON_SMP|SPICON_MODE32|SPICON_ON,4); // 4,2,1 should check to find the eligible devisor???
    }

void  Init_STPM34(int chnSel)
{
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
    DSP_CR101bits.BHPFC1=0;          //HPF enable voltage;DC cancellation
    DSP_CR101bits.BLPFV1=1;          //LPF included voltage;set up fundamental mode, read ZCR
    DSP_CR101bits.BLPFC1=1;          //LPF included voltage;set up fundamental mode, read ZCR
    readAdd=0x01;
    writeAdd=0x01; 
    dataLSB=DSP_CR101bits.LSB;
    dataMSB=DSP_CR101bits.MSB;
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB, port,_bits);    //write to  CR1 register
 
   DSP_CR201bits.BHPFV2=0;         //HPF enable voltage;DC cancellation
   DSP_CR201bits.BHPFC2=0;         //HPF enable voltage;DC cancellation
   DSP_CR201bits.BLPFV2=1;         //LPF included voltage;set up fundamental mode, read ZCR
   DSP_CR201bits.BLPFC2=1;         //LPF included voltage;set up fundamental mode, read ZCR
   readAdd=0x03;
   writeAdd=0x03;
   dataLSB=DSP_CR201bits.LSB;
   dataMSB=DSP_CR201bits.MSB;
   SendFrame(readAdd,writeAdd,dataLSB,dataMSB, port,_bits);
 
   
    DFE_CR101bits.GAIN1=0x02;           //set current gain for Chn1=75mV
    readAdd=0x19;
    writeAdd=0x19;
    dataLSB=DFE_CR101bits.LSB;
    dataMSB=DFE_CR101bits.MSB;
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB, port,_bits);
   
    //set GAIN2 in DFE_CR2 register
    DFE_CR201bits.GAIN1=0x02;           //set current gain for Chn2=75mV
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
                                           
    PORTClearBits(port, _bits);             //activate CSx x={12,3,4,5}
    
    while(SPI2STATbits.SPITBF==1){}
       SPI2BUF=transferValue;
      FrameDelay();
      while(SPI2STATbits.SPIRBF==0){}
       receiveBuffer=SPI2BUF;
   
   PORTToggleBits(port,_bits);              //deactivate CSx
  
}

void ReadFrame(unsigned int address, unsigned int *buffer)
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
         //receiveBuffer=SPI2BUF;
         *buffer=SPI2BUF;
        // *buffer=receiveBuffer;
                                                // deactivate Enable signal
    mPORTGSetBits(BIT_9);                       //deactivate CS1     
   
}