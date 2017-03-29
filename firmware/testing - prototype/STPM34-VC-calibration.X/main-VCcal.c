/* 
 * File:   main.c
 * Author: Anton Tachev
 * Description:  Voltage/Current calibration
 * makes voltage/current calibration
 
 * Created on 18.Aug 2016
 */
/*SPI 2 module identification                                                */
/* SCK2 - pin2 RE6                         
 * SDI2 - pin5 RG7
 * SDO2 - pin 6 RG8
 * SCS - pin 9 RG9
 * Enable(EN) - pin 45 RD11
 * 
         1. Voltage and current calibration. 
         2. Apply nominal Voltage Vn=220 VAC and nominal Current In=10Amps
         3. Calculate voltage register values as follows:
               Xv= (Vn*Av*calv*2^15)/Vref(1+R1/R2) and
               
 *             Xi= In*Ai*cali*Ks*2^15/Vref;
 * 
 *          where:
 *                  Vn - nominal test voltage 220 VAC;
 *                  In - nominal test current 10 Amps;
 *                  Vref - 1.18 V
 *                  R1 - divider resistor - 810K;
 *                  R2 - small divider resistor 470R
 *                  Ai - current Gain=2;
 *                  Av - voltage Gain=2
 *                  calv - voltage calibrator = 0.875
 *                  cali - current calibrator = 0.875
 *                  Ks - sensitivity =Rb/N = 6/2500= 0.0024
 * 
 *          
        
            Make 10 measurements and get average values for Xvav and Xiav from dsp_reg14
            and dsp_15
         5.Calculate the real  values and write them in CHVx and CHCx registers
        
           This code makes calibration for Channel-01
        
 */
#include <plib.h>
#include <stdio.h>
#include <stdint.h>

#include <machine/int_types.h>

#include <p32xxxx.h>
#include "STPM-define.h"
/*----------------Function prototypes -----------------------------------------*/

void  Init_STPM34();        //function prototype are defined in STPm34_header.h
void  SPI_Init();
void Delay(void);

//void ReadFrame(unsigned int address, unsigned int* buffer);
void SendFrame(char readAdd,char writeAdd, char dataLSB,char dataMSB);

void ReadFrameCalibration(unsigned int address, uint16_t* vxrms, uint16_t* cxrms);
void CalibrationRoutine(unsigned int V1,unsigned int C1, uint16_t* vxrms, uint16_t* cxrms);
void SetTransMode(int setmode);
void Sum_Average(uint16_t *vxrms, uint16_t *cxrms);

// configuration settings

#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FPLLODIV = DIV_8, FWDTEN = OFF
#pragma config POSCMOD = HS, FNOSC = PRIPLL, FPBDIV = DIV_1
int i,j,k;
int delayValue;
uint16_t var16;
int8_t var8;
uint32_t var32;
uint16_t calVoltValue;
uint16_t calCurrValue;
uint16_t tempCHVx;
uint16_t tempCHCx;



int main()
{
    
// configure the proper PB frequency and the number of wait states
    SYSTEMConfigWaitStatesAndPB(80000000L);
    CheKseg0CacheOn();                           // enable the cache for the best performance 
    
   // SPI_Init();
   // Init_STPM34();
   /// SetTransMode(2);
    cxrms=&c1rms_average;
    vxrms=&v1rms_average;
    while(1)
    {
    
        
        
        calVoltValue=V1_RMS_Data_Address;
        calCurrValue=C1_RMS_Data_Address;
        tempCHVx=DSP_CR500bits.CHV1;
        tempCHCx=DSP_CR600bits.CHC1;
        parm_Reg[0].Address=V1_RMS_Data_Address;                        //calibrate Channel1
        ReadFrameCalibration(parm_Reg[0].Address,cxrms,vxrms);
        CalibrationRoutine(calVoltValue,calCurrValue,cxrms,vxrms);
        
        
        parm_Reg[1].Address=C1_RMS_Data_Address;                        //Calibrate Channel2
        parm_Reg[1].dataBuffer=Chn_Buffer2;
        ReadFrameCalibration(parm_Reg[1].Address,parm_Reg[1].dataBuffer,cxrms,vxrms);
        
        parm_Reg[2].Address=C1_RMS_Data_Address;                        //Calibrate Channel3
        parm_Reg[2].dataBuffer=Chn_Buffer3;
        ReadFrameCalibration(parm_Reg[2].Address,parm_Reg[2].dataBuffer,cxrms,vxrms);
        
        parm_Reg[3].Address=C1_RMS_Data_Address;                        //Calibrate Channel4
        parm_Reg[3].dataBuffer=Chn_Buffer4;
        ReadFrameCalibration(parm_Reg[3].Address,parm_Reg[3].dataBuffer,cxrms,vxrms);
        
        parm_Reg[4].Address=C1_RMS_Data_Address;                        //Calibrate Channel5
        parm_Reg[4].dataBuffer=Chn_Buffer5;
        ReadFrameCalibration(parm_Reg[4].Address,parm_Reg[4].dataBuffer,cxrms,vxrms);
        
        parm_Reg[5].Address=C1_RMS_Data_Address;                        //Calibrate Channel6
        parm_Reg[5].dataBuffer=Chn_Buffer6;
        ReadFrameCalibration(parm_Reg[5].Address,parm_Reg[5].dataBuffer,cxrms,vxrms);
        
        parm_Reg[6].Address=C1_RMS_Data_Address;                        //Calibrate Channel7
        parm_Reg[6].dataBuffer=Chn_Buffer7;
        ReadFrameCalibration(parm_Reg[6].Address,parm_Reg[6].dataBuffer,cxrms,vxrms);
        
        parm_Reg[7].Address=C1_RMS_Data_Address;                        //Calibrate Channel8
       // parm_Reg[7].dataBuffer=Chn_Buffer8;
        ReadFrameCalibration(parm_Reg[7].Address,parm_Reg[7].dataBuffer,cxrms,vxrms);
        
        parm_Reg[8].Address=C1_RMS_Data_Address;                        //Calibrate Channel9
        parm_Reg[8].dataBuffer=Chn_Buffer9;
        ReadFrameCalibration(parm_Reg[8].Address,parm_Reg[8].dataBuffer,cxrms,vxrms);
        
        parm_Reg[9].Address=C1_RMS_Data_Address;                        //Calibrate Channel10
       parm_Reg[9].dataBuffer=Chn_Buffer10;
        ReadFrameCalibration(parm_Reg[9].Address,parm_Reg[9].dataBuffer,cxrms,vxrms); 
        
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
    //Option2 (macros))
    mPORTDSetPinsDigitalOut(BIT_11);
    mPORTGSetPinsDigitalOut(BIT_9);
    mPORTBSetPinsDigitalOut(BIT_2|BIT_3|BIT_4|BIT_5);
    /*    Set SPI Bus pins                           */
   
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
   DSP_CR201bits.BLPFV2=1;          //LPF bypassed -  wideband voltage;set up fundamental mode
   DSP_CR201bits.BLPFC2=1;          //LPF bypassed -  wideband current;set up fundamental mode
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
    transferValue1=(sendBuff[0]<<8)|(sendBuff[1]);
    transferValue2=(sendBuff[2]<<8)|(sendBuff[3]);
    transferValue=(transferValue1<<16)|(transferValue2);
        //pSrc=sendBuff; 
        
           while(SPI2STATbits.SPITBF==1){}
             SPI2BUF=transferValue;
}  

void CalibrationRoutine(unsigned int V1,unsigned int C1, uint16_t* vxrms, uint16_t* cxrms)
{
    uint16_t xvtemp=2;
    calVoltValue=(14336*xvtemp)/(*vxrms)-12288;
    
}

void ReadFrameCalibration(unsigned int address,uint16_t *vxrms, uint16_t* cxrms)
{
    readAdd=address;                                //read register from register map
    writeAdd=0xff;                                  //dummy write address
    dataLSB=0xff;                                   //dummy byte
    dataMSB=0xff;                                   //dummy byte
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB);
  //  ptrBuffer=buffer;
     for(i=0;i<10;i++)
         {
            while(SPI2STATbits.SPIRBF==0){}              // wait until Receive Buffer gets full i.e. SPIRBF=1
            var32= SPI2BUF;
            *vxrms+=var32;                          //separate 16-bits Vxrms voltage value
            *cxrms+=var32>>16;                      //separate 16-bits Cxrms current value
            ptrBuffer=&var32;
         //   *buffer++=*ptrBuffer;
            Delay();
         }
         Sum_Average(cxrms,vxrms);                      // go to function computes the Xv average xc average
}  
void Sum_Average(uint16_t *vxrms, uint16_t *cxrms)
{
    uint16_t temp;
    
    temp=*vxrms/10;
    *vxrms=temp;
    
    temp=*cxrms/10;
    *cxrms=temp;
}
void SetTransMode(int setmode)
{
    
     switch (setmode)
     {
         case 0 :
             SPI2CONbits.MODE16=0;                  // set 8 bits transfer mode
             SPI2CONbits.MODE32=0;
             break ;
         case 1:
             SPI2CONbits.MODE16=1;                  // set 16 bits transfer mode
             SPI2CONbits.MODE32=0;
             break;
          case 2:
             SPI2CONbits.MODE32=1;
             SPI2CONbits.MODE16=1;                  // set 32  bits ransfer mode
             break;   
             
         default:
             break;
     }
 } 

void Delay(void)
{
    delayValue=80*100;
    while(delayValue--);
  
}

