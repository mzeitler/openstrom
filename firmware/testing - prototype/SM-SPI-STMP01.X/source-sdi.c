#include <plib.h>
#include <p32xxxx.h>
#include "sdi.h"
//#include <spi.h>
#include "STPM-define.h"
unsigned int port;
unsigned int _bits;

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