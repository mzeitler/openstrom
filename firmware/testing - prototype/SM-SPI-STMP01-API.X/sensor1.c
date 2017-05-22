

#include <stdio.h>
#include <stdlib.h>
#include <plib.h>
#include <p32xxxx.h>
#include <proc/p32mx795f512h.h>
#include "STPM-define.h"
#include "relay.h"
void Delay(void);
//void DiplayState(int code);
void  Find_ZCR(void);
//void ReadFrame(unsigned short address, uint32_t * buffer);
void SendFrame(uint32_t readAdd,uint32_t writeAdd, uint32_t dataLSB,uint32_t dataMSB,int port,int _bits);
void FrameDelay(void);
void FrameDelayR(void);
void CheckOverCurrent(uint32_t *dataBuf,IoPortId port, unsigned int relayNum);
void CSxActive(int _bits);
void CSxInActive(int _bits);
void ReadReg(int port,int _bits,uint32_t *buf);         // temp function for read reg contol
void ActiveSYN(void);
void FrameDelay1(void);
void FrameSend(void);
void SelectSPI(int cs);
void DelayEn(void);
void ReadC1Data(uint32_t *dataBuf,IoPortId port, unsigned int relayNum,unsigned _bits);
void ReadC2Data(uint32_t *dataBuf,IoPortId port, unsigned int relayNum,unsigned _bits);
void ReadRegControl(int port,int _bits,uint32_t *buf);         // temp function for read reg contol
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
//*SYN  - PIC32-pin44-RD10                                                       */
/*-------------------------------------------------------------------------------*/
#define  EnSPI PORTDbits.RD11                   // Enable (EN) for SPI selection)
#define CS_1   LATGbits.LATG9                    //  CS_1
#define CS_2   LATBbits.LATB5                    //  CS_2
#define CS_3   LATBbits.LATB4                    //  CS_3
#define CS_4   LATBbits.LATB2                    //  CS_4
#define CS_5   LATBbits.LATB3                    //  CS_5

void SPI_Init()
{
   // Set Inputs/Outputs for SPI communication
   
    TRISDbits.TRISD11=0;           //set EN as an Output
    TRISGbits.TRISG9=0;            // set CS_1 an output
    TRISBbits.TRISB5=0;            // set CS_2 an output
    TRISBbits.TRISB4=0;            // set CS_3 an output
    TRISBbits.TRISB2=0;            // set CS_4 an output
    TRISBbits.TRISB3=0;            // set CS_5 an output
    TRISDbits.TRISD10=0;           // set SYN as an output
    
    LATDbits.LATD11=0;             //activate EN signal     21.04.2017
    LATDbits.LATD11=1;             //activate EN signal     21.04.2017
    LATDbits.LATD10=1;              //deactivate SYN
    
    LATGbits.LATG9=1;
    LATBbits.LATB5=1;
    LATBbits.LATB4=1;
    LATBbits.LATB2=1;
    LATBbits.LATB3=1;
    TRISGbits.TRISG7=1;             //set as an input
    TRISGbits.TRISG8=0;             //set as an output
    TRISEbits.TRISE6=0;             //set as an output
    
    //Open SPI_2 Object
   SpiChnOpen(2,SPICON_MSTEN|SPICON_SMP|SPICON_MODE32|SPICON_ON,4);// last was 8 = 20Mhz old value ,2 value 8
   IFS0CLR = 0x03800000;   //Clears any existing event (rx / tx/ fault interrupt)

}
void ActiveSYN(void)
{
    PORTDbits.RD10=0;                   //active SYN
    FrameDelayR();                       //4us 
    PORTDbits.RD10=1;
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
            _bits=BIT_3;            // CS_5 active -  PORTBbits.RB3
            port=IOPORT_B;          //prepare to select CS5
            break;
         default:
             break;
    }
   
   US1_REG100bits.CRC_EN=0;         //disable CRC polynomial
   US1_REG100bits.ISB_FIRST=1;
   readAdd=0x00;
   writeAdd=0x24;
   dataMSB=US1_REG100bits.MSB;
   dataLSB=US1_REG100bits.LSB;
 
   SendFrame(readAdd,writeAdd,dataLSB,dataMSB,port,_bits);
   FrameDelay();
 
    DSP_CR100bits.ENVREF1=1;         //enable default value for Vref1=1.18v for CH0;  
    DSP_CR100bits.TC1=0x5;           //set temperature compensation for CHx; Vref1=1.21v
    
    readAdd=0x00;                   // select dsp_cr1
    writeAdd=0x00; 
    dataLSB=DSP_CR100bits.LSB;
    dataMSB=DSP_CR100bits.MSB;
  
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB,port,_bits);
    FrameDelay();

    DSP_CR301bits.SWAuto_Latch=1;        // Automatic measurement register latch at 7.8125 kHz
    readAdd=0x05;
    writeAdd=0x05;
    dataMSB=DSP_CR301bits.MSB;
    dataLSB=DSP_CR301bits.LSB;
    
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB, port,_bits);    //write to  CR1 register
    FrameDelay();
  
    DSP_CR200bits.ENVREF2=1;         //enable V ref1 bit for CHx;
    DSP_CR200bits.TC2=0x05;          //  should be x02set temperature compensation for CHx;  Vref2=1.18v default
    
    readAdd=0x00;
    writeAdd=0x02; 
    dataLSB=DSP_CR200bits.LSB;
    dataMSB=DSP_CR200bits.MSB;
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB, port,_bits);    //write to  CR2 register
    FrameDelay();
  
    DSP_CR101bits.BHPFV1=1;          //HPF enable voltage;DC cancellation
    DSP_CR101bits.BHPFC1=0;          //HPF enable current;DC cancellation
    DSP_CR101bits.BLPFV1=1;          //LPF included voltage;set up fundamental mode, read ZCR
    DSP_CR101bits.BLPFC1=0;          //LPF included voltage;set up fundamental mode, read ZCR
    readAdd=0x01;
    writeAdd=0x01; 
    dataLSB=DSP_CR101bits.LSB;
    dataMSB=DSP_CR101bits.MSB;
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB, port,_bits);    //write to  CR1 register
  
    DSP_CR201bits.BHPFV2=1;          //HPF enable voltage;DC cancellation
    DSP_CR201bits.BHPFC2=1;          //HPF enable current;DC cancellation
    DSP_CR201bits.BLPFV2=1;          //LPF bypassed voltage;set up fundamental mode, read ZCR
    DSP_CR201bits.BLPFC2=1;          //LPF bypassed current;set up fundamental mode
    readAdd=0xff;
    writeAdd=0x03;
    dataLSB=DSP_CR201bits.LSB;
    dataMSB=DSP_CR201bits.MSB;
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB, port,_bits);
  
    DFE_CR101bits.GAIN1=0x00;           //set current gain for Chn1=75mV for real time work at Iload=30Amps
    DFE_CR101bits.GAIN1=0x00;           //set current gain for Chn1=134mV for simulation
    readAdd=0xff;
    writeAdd=0x19;
    dataLSB=DFE_CR101bits.LSB;
    dataMSB=DFE_CR101bits.MSB;
    SendFrame(readAdd,writeAdd,dataLSB,dataMSB, port,_bits);
 }

void DelayEn(void)
{
    int delayValue;
    delayValue=1;                 // delay value = 3uS 
    while(delayValue--);
}
void FrameDelay(void)               //delay 4uS
{
    int delayValue;
    delayValue=16;           // last =16 value=36/40 gives 4uS pulse width, 
    while(delayValue--);
    
}
void FrameDelay1(void)               
{
    int delayValue;
    delayValue=3;           // value=2 for reading 8 params; =3 14.05.2017
    while(delayValue--);
    
}
void FrameSend(void)               //delay 4uS
{
    int delayValue;
    delayValue=10;           // value=10/12- ok for 8 params
    while(delayValue--);
}
void FrameDelayR(void)               //delay 4uS
{
    int delayValue;
    delayValue=16;           // value=32/40 gives 4uS pulse width
    while(delayValue--);
    
}
void ReadReg(int port,int _bits,uint32_t *buf)
{
        int i;
        receiveBuffer=SPI2BUF;      //clear buffer
        SPI2STATCLR=1<<6;           //clear overflow
        
        for(i=0;i<8;i++){     
             CSxActive(_bits);   
             while(SPI2STATbits.SPITBE==0);
             SPI2BUF=0xffffffff;
             FrameDelay1();                            //should be at least 4uS        
             while(!SPI2STATbits.SPIRBF==1);
            receiveBuffer=SPI2BUF;                     //clear buffer
            SPI2STATCLR=0x40;                          //clear overflow
        //save reading parameter
            *buf=receiveBuffer;
             buf++; 
             CSxInActive(_bits);
 }  
            // FrameDelay();              //???
}
 void Delay(void)
{
    int delayValue;
    delayValue=8*1000;
    while(delayValue--);
}
 
void SendFrame(uint32_t readAdd,uint32_t writeAdd, uint32_t dataLSB,uint32_t dataMSB,int port,int _bits)
{
   
/* This subroutine sends a SPI frame - 32 bits to the sensor ICs stpm34  */
    
   sendBuff[0]=readAdd;
   sendBuff[1]=writeAdd;
   sendBuff[2]=dataLSB&0x000000ff;
   sendBuff[3]=dataMSB&0x000000ff;
   transferValue1=(sendBuff[0]<<24)|(sendBuff[1]<<16);
   transferValue2=(sendBuff[2]<<8);
   transferValue=transferValue1|transferValue2|sendBuff[3];
  
   CSxActive(_bits);                            //activate CSx x={1,2,3,4,5}
    while(SPI2STATbits.SPITBE==0);
        
    SPI2BUF=transferValue;
   // putcSPI2(transferValue);
   // FrameSend();
   FrameDelay1();
   while(SPI2STATbits.SPITBF==1);               //check for empty tx buffer
     CSxInActive(_bits);
}
void GetParamsEnergyPH1(unsigned int  port, unsigned int _bits, int *buffer,relay_t activeRelay,int i)
{
            //1. Read Current and Voltage parameters from Chn[i]
            ReadC1Data(parm_Reg.dataBuffer,activeRelay.relayPort1, activeRelay.relayPin1,_bits);
            ReadC2Data(parm_Reg.dataBuffer,activeRelay.relayPort1, activeRelay.relayPin1,_bits);
            parm_Reg.Address=0x54;       //PH1 Active Energy;PH1 Fundamental Energy;PH1 Reactive Energy;Apparent Energy PH1
            parm_Reg.dataBuffer=buffer;                         
            SendFrame( parm_Reg.Address,0xff,0xff,0xff, port,_bits);            //write to  CR1 register
           //FrameDelay1();
           //ActiveSYN();
            ReadReg(port,_bits,buffer);
          //  FrameDelay();
       
}


void GetParamsEnergyPH2(unsigned int  port, unsigned int _bits, int *buffer,relay_t activeRelay,int i)
{
            //1. Read Current and Voltage parameters from Chn[i]
           // ReadC1Data(parm_Reg.dataBuffer,activeRelay.relayPort1, activeRelay.relayPin1,_bits);
          //  ReadC2Data(parm_Reg.dataBuffer,activeRelay.relayPort1, activeRelay.relayPin1,_bits);
            parm_Reg.Address=0x6c;       //PH2 Active Energy;PH2 Fundamental Energy;PH2 Reactive Energy;Apparent Energy PH2
            parm_Reg.dataBuffer=buffer;                         
            SendFrame( parm_Reg.Address,0xff,0xff,0xff, port,_bits);            //write to  CR1 register
           //FrameDelay1();
           //ActiveSYN();
            ReadReg(port,_bits,buffer);
          //  FrameDelay();
       
}

void GetParamsPowerPH1(unsigned int  port, unsigned int _bits, int *buffer,relay_t activeRelay,int i)
{
            //1. Read Current and Voltage parameters from Chn[i]
            ReadC1Data(parm_Reg.dataBuffer,activeRelay.relayPort1, activeRelay.relayPin1,_bits);
            ReadC2Data(parm_Reg.dataBuffer,activeRelay.relayPort1, activeRelay.relayPin1,_bits);
            parm_Reg.Address=0x5c;       //PH1 Active Power;PH1 Fundamental Power;PH1 Reactive Power;ApparentPower PH1
            parm_Reg.dataBuffer=buffer;                         
            SendFrame( parm_Reg.Address,0xff,0xff,0xff, port,_bits);            //write to  CR1 register
           //FrameDelay1();
           //ActiveSYN();
            ReadReg(port,_bits,buffer);
          //  FrameDelay();
       
}


void GetParamsPowerPH2(unsigned int  port, unsigned int _bits, int *buffer,relay_t activeRelay,int i)
{
            //1. Read Current and Voltage parameters from Chn[i]
            ReadC1Data(parm_Reg.dataBuffer,activeRelay.relayPort1, activeRelay.relayPin1,_bits);
            ReadC2Data(parm_Reg.dataBuffer,activeRelay.relayPort1, activeRelay.relayPin1,_bits);
            parm_Reg.Address=0x74;       //PH2 Active Energy;PH2 Fundamental Energy;PH2 Reactive Energy;Apparent Energy PH2
            parm_Reg.dataBuffer=buffer;                         
            SendFrame( parm_Reg.Address,0xff,0xff,0xff, port,_bits);            //write to  CR1 register
           //FrameDelay1();
           //ActiveSYN();
            ReadReg(port,_bits,buffer);
          //  FrameDelay();
       
}
void CSxActive(int _bits)
{
   
        
        switch(_bits){
        
        case 0x200:
            LATGbits.LATG9=0;                //CS1 goes low active
            break;       
        case 0x020:
            LATBbits.LATB5=0;                //CS2 goes low active
            break;
        case 0x010:
            LATBbits.LATB4=0;                //CS3 goes low active
            break;
            
        case 0x004:
            LATBbits.LATB2=0;                //CS4 goes low active
            break;
        case 0x008:
            LATBbits.LATB3=0;                //CS5 goes low active
            break;
        default:
            break;
    }
}
void CSxInActive(int _bits)
{
     switch(_bits){
        
        case 0x200:
           LATGbits.LATG9=1;                //CS1 goes low active
            break;
        case 0x020:
            LATBbits.LATB5=1;                //CS2 goes low active
            break;
        case 0x010:
            LATBbits.LATB4=1;                //CS3 goes low active
            break;
            
        case 0x004:
            LATBbits.LATB2=1;                //CS4 goes low active
            break;
        case 0x008:
          LATBbits.LATB3=1;                //CS5 goes low active
            break;
        default:
            break;
     }
}

void Dis(int code)
{
     int i;
     switch (code)
     {
         case 1:                    //Init state displayed
         {
             LATBbits.LATB13=0;
             LATGbits.LATG3=1;
             break;
         }
         case 2:                    //Get Params displayed
         {
             LATBbits.LATB13=0;
             LATGbits.LATG3=1;
             break;
         }   
         case 3:                    //Ethernet displayed
         {
             LATBbits.LATB13=0;
             for(i=0;i<2;i++)
             {
                LATGbits.LATG3=1;
                Delay();
                LATGbits.LATG3=0;
                Delay();
             }
                break;
         }
                case 4:             //Wifi displayed
                {
                    LATBbits.LATB13=0;
                    for(i=0;i<3;i++)
                    {
                         LATGbits.LATG3=1;
                         Delay();
                         LATGbits.LATG3=0;
                         Delay();
                    }
                break;
                }
            default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
     }
 }
/*------------------Relay Zero Crossing routine---------------------------------*/
/*                                                                              */
/*                                                                              */
/*------------------------------------------------------------------------------*/
void Relay_CRZ(void)
{
    int i;
    unsigned int chnSel;
    unsigned int port;
    unsigned int _bits;
    
//    Init_Relays();               //Initialize Relay OUTPUTS
    SPI_Init();                 //Initialize SPI OUTPUTS
    
    for(i=1;i<6;i++)
    {
        Init_STPM34(i,port,_bits);       //initialize all Sensors STPM34
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

/*void Find_ZCR(void)
{
    while(DSP_EV1bits.ZCR!=1){}            // check if the ZCR bit in reg DSP ev1 is set active 
}*/

void CheckOverCurrent(uint32_t *dataBuf,IoPortId port, unsigned int relayNum)  //located in sensor1.c
{
    if(dataBuf[0] >= limitCurrentValue)                                
    {
        Find_ZCR();                                                            //located in Relay1.c 
        Switch_ON_Relay(port,relayNum);
        Switch_ON_PWMRelay(port,relayNum);             //located in Relay1.c alternative choice
    }
   
}

/*-------------------------------------------------------------------------------*/
void SelectSPI(int cs)
{
    switch (cs)
    {
        case 1:
            EnSPI=0;
            DelayEn();
            CS_1=0;
            DelayEn();
            EnSPI=1;
            CS_1=1;
            break;
        case 2:
            EnSPI=0;
            DelayEn();
            CS_2=0;
            DelayEn();
            EnSPI=1;
            CS_2=1;
            break;
        case 3:
            EnSPI=0;
            DelayEn();
            CS_3=0;
            DelayEn();
            EnSPI=1;
            CS_3=1;
            break;
         case 4:
            EnSPI=0;
            DelayEn();
            CS_4=0;
            DelayEn();
            EnSPI=1;
            CS_4=1;
            break;
         case 5:
            EnSPI=0;
            DelayEn();
            CS_5=0;
            DelayEn();
            EnSPI=1;
            CS_5=1;
            break;
        default:
            break;
    }
}

void ReadC1Data(uint32_t *dataBuf,IoPortId port, unsigned int relayNum,unsigned _bits)
{
    receiveBuffer=SPI2BUF;                         
    SPI2STATCLR=1<<6;                                //clear overflow event
    CSxActive(_bits);
    while(SPI2STATbits.SPITBE==0);
    SPI2BUF=0x32ffffff;                             //read C1 Data Register
    FrameDelay1();
    CSxInActive(_bits);
    FrameDelay();                                   //delay 4uS
    /*--------------------------------------------------------------------*/
     CSxActive(_bits);
     while(SPI2STATbits.SPITBE==0);
     SPI2BUF=0xffffffff;
     FrameDelay1();
     while(!SPI2STATbits.SPIRBF==1);
     receiveBuffer=SPI2BUF;
     if(receiveBuffer >= limitCurrentValue)
     {
         Find_ZCR();
         Switch_ON_Relay(port, relayNum);           //two options for relay switching
         Switch_ON_PWMRelay(port, relayNum);
     }
     // how to Switch OFF relays
     
}
    
void ReadC2Data(uint32_t *dataBuf,IoPortId port, unsigned int relayNum,unsigned _bits)
{
    receiveBuffer=SPI2BUF;
    SPI2STATCLR=1<<6;
    CSxActive(_bits);
    while(SPI2STATbits.SPITBE==0);
    SPI2BUF=0x36ffffff;                             //read C2 Data Register
    FrameDelay1();
    CSxInActive(_bits);
    FrameDelay();                                   //delay 4uS
    /*--------------------------------------------------------------------*/
     CSxActive(_bits);
     while(SPI2STATbits.SPITBE==0);
     SPI2BUF=0xffffffff;
     FrameDelay1();
     while(!SPI2STATbits.SPIRBF==1);
     receiveBuffer=SPI2BUF;
     if(receiveBuffer >= limitCurrentValue)
     {
         Find_ZCR();
         Switch_ON_Relay(port, relayNum);
         Switch_ON_PWMRelay(port, relayNum);
     }
     // how to Switch OFF relays
     
}
void ReadRegControl(int port,int _bits,uint32_t *buf)
{
      receiveBuffer=SPI2BUF;      //clear buffer
        SPI2STATCLR=1<<6;           //clear overflow   
             CSxActive(_bits);   
             while(SPI2STATbits.SPITBE==0);
             SPI2BUF=0xffffffff;
             FrameDelay1();                            //should be at least 4uS        
             while(!SPI2STATbits.SPIRBF==1);
            receiveBuffer=SPI2BUF;                     //clear buffer
             CSxInActive(_bits);
   
            // FrameDelay();              //???
}
    