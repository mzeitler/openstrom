/* 
 * File:   RelayTest-main.c
 * Author: Anton Tachev
 *
 * Created on:10.12.2015, 10:57
 */

#include <stdio.h>
#include <stdlib.h>
#include <plib.h>
#include <p32xxxx.h>
#include <STPM34_header.h>

// Configuration Bit settings
// SYSCLK = 80 MHz (8MHz Crystal/ FPLLIDIV * FPLLMUL / FPLLODIV)
// PBCLK = 40 MHz
// Primary Osc w/PLL (XT+,HS+,EC+PLL)
// WDT OFF
// Other options are don't care
//------------------SPI Channel #2 description-----------------//
//  Pin4 - SCK2(RG6) - SPI 2 Serial Clk - OUTPUT set portG-6
//  PIN5 - SDI2(RG7) - SPI 2 Serial input - INPUT set PortG-7
//  PIN6 - SDO2(RG8) - SPI 2 Serial output - OUTPUT set PORTG-8
//  PIN8 - SCS1 (RG9)- SPI Chip Select 1 - OUTPUT set PORTG-9
//-------------------------------------------------------------//
char readAdd,writeAdd;
char dataLSB,dataMSB;
unsigned int*ptrSendBuff;
//unsigned int sendBuff[4]={0x0f,0x0f,0x0f,0x0f};
void  Init_STPM32();        //function prototype
void  Init_SPI_module();
void SendFrame(char readAdd,char wrireAdd, char dataLSB,char dataMSB);


#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FPLLODIV = DIV_1, FWDTEN = OFF
#pragma config POSCMOD = HS, FNOSC = PRIPLL, FPBDIV = DIV_1
/*------------------------------------------------------------------*/
 /*                    Relay's connections description              */
 /*                                                                 */
 /*   Relay_01 - RF1                  */
 /*   Relay_02 - RF0                  */
 /*   Relay_03 - RD7                  */
 /*   Relay_04 - RD6                  */
 /*   Relay_05 - RD5                  */
 /*   Relay_06 - RD4                  */
 /*   Relay_07 - RC14                 */
 /*   Relay_08 - RC13                 */
 /*   Relay_09 - RB8                  */
 /*   Relay_10 - RB10                 */
 /*------------------------------------------------------------------*/
int bits[16]={BIT_0,BIT_1,BIT_2,BIT_3,BIT_4,BIT_5,BIT_6,BIT_7,
              BIT_8,BIT_9,BIT_10,BIT_11,BIT_12,BIT_13,BIT_14,BIT_15};

/*typedef struct{
    
    unsigned CLRSS_T01 :3;
    unsigned ClassSS   :1;
    unsigned ENVREF1   :1;
    unsigned           :8;
    unsigned           :2;
    unsigned BHPFV1    :1;
    unsigned BHPFC1    :1;
    unsigned           :1;
    unsigned BLPFV1    :1;
    unsigned BLPFC1    :1;
    unsigned           :8;
} __DSP_CR1bits_t;*/
int main(void)
{
    unsigned spiClk; 
    
    Init_STPM32();
    Init_SPI_module();
    SpiChnSetBrg(1,0);                  //set chn1 to baud rate=20Mhz
    ptrSendBuff=sendBuff;
    SpiChnPutS(1,ptrSendBuff,1);        //sends frame to stpm34
    unsigned char temp; 
    temp= sendBuff [1];
   DSP_CR100bits_t DSP_CR100;
   DSP_CR101bits_t DSP_CR101;
   PH1_ActivePower_t ph1APower;
 
   
   
   int delayValue;
    
  //  DSP_CR100.ENVREF1=1;
    
   // DSP_CR100.LSB=0xff00;
   // DSP_CR101.MSB=0xff00;
    
//   DSP_CR1bits.Address=0x05;
 //
  //  temp=DSP_CR1bits.Address;
    int i=0;
    float rxBuff[]={1234,6,2345.11};
    //// pins Direction
    
    mPORTFSetPinsDigitalOut(BIT_0|BIT_1);               //set directions of PORT pins
    mPORTDSetPinsDigitalOut(BIT_7|BIT_6|BIT_5|BIT_4);
    mPORTCSetPinsDigitalOut(BIT_14|BIT_13);
    mPORTBSetPinsDigitalOut(BIT_8|BIT_10);
    
    mPORTFSetBits(BIT_0|BIT_1);                         //Set pins to non active state
    mPORTDSetBits(BIT_7|BIT_6|BIT_5|BIT_4);
    mPORTCSetBits(BIT_14|BIT_13);
    mPORTBSetBits(BIT_8|BIT_10);
    while(1){
        for(i=0;i<16;i++)
        {
          mPORTFToggleBits(bits[i]);
          delayValue=100*100;
          while(delayValue--);
         mPORTFClearBits(bits[i]);
        }   
   }
   
}
void  Init_STPM32()
{
    
    //set VREF1 bits
    DSP_CR100bits_t DSP_CR100bits;
    DSP_CR100bits.ENVREF1=1;         //enable Vref1 bit
    DSP_CR200bits_t DSP_CR200bits;   //enable vref2 bit
    //set Temp compensation
    DSP_CR200bits.ENVREF2=1;
    DSP_CR100bits.TC1=0x2;
    DSP_CR200bits.TC2=0x02;
    //set GAIN1,2
    DFE_CR101_t DFE_CR101;
    DFE_CR201_t DFE_CR201;
    DFE_CR101.GAIN1=0x00;
    DFE_CR201.GAIN1=0x00;
    //set LPF and HPF properties
   DSP_CR101bits_t DSP_CR101bits;  // 
   DSP_CR201bits_t DSP_CR201bits;
   DSP_CR101bits.BHPFV1=0;          //HPF enable voltage
   DSP_CR101bits.BHPFC1=0;          //HPF enable current
   DSP_CR101bits.BLPFV1=1;          //LPF wideband voltage
   DSP_CR101bits.BLPFC1=1;          //LPF wideband current
   
   DSP_CR201bits.BHPFV2=0;          //HPF enable voltage
   DSP_CR201bits.BHPFC2=0;          //HPF enable current
   DSP_CR201bits.BLPFV2=1;          //LPF wideband voltage
   DSP_CR201bits.BLPFC2=1;          //LPF wideband current
   //send process
   readAdd=0x00;
   writeAdd=0x01;
   dataLSB=DSP_CR100bits.LSB;
   dataMSB=DSP_CR101bits.MSB;
   SendFrame(readAdd,writeAdd,dataLSB,dataMSB);
   //send function
  
}

void Init_SPI_module()

{
    mPORTGSetPinsDigitalOut(BIT_6|BIT_8|BIT_9);    //set RG6/8/9 as OUTPUTS
    mPORTGSetPinsDigitalIn(BIT_7);               //set RG as an Input
    
}

void SendFrame(char readAdd,char writeAdd, char dataLSB,char dataMSB)
{
   sendBuff[0]=readAdd;
   sendBuff[1]=writeAdd;
   sendBuff[2]=dataLSB;
   sendBuff[3]=dataMSB;
}
