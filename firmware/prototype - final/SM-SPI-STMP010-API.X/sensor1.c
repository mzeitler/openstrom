

#include <stdio.h>
#include <stdlib.h>
#include <plib.h>
#include <p32xxxx.h>
#include <proc/p32mx795f512h.h>
#include "STPM-define.h"
#include "relay.h"
void Delay(void);
//void DiplayState(int code);
void Find_ZCR(void);
//void ReadFrame(unsigned short address, uint32_t * buffer);
void SendFrame(uint32_t readAdd, uint32_t writeAdd, uint32_t dataLSB, uint32_t dataMSB, int port, int _bits);
void FrameDelay(void);
void FrameDelayR(void);
void CheckOverCurrent(uint32_t *dataBuf, IoPortId port, unsigned int relayNum);
void CSxActive(int _bits);
void CSxInActive(int _bits);
void ReadReg(int port, int _bits, uint32_t *buf); // temp function for read reg contol
void ActiveSYN(void);
void FrameDelay1(void);
void FrameSend(void);
void SelectSPI(int cs);
void SetSPIx(int cs);
void DelayEn(void);
void Delay1mS();
void SelectSPIall(void);

void STPMInitReset();
void SpiInit1(void);
void ReadRegVI(int port, int _bits, uint32_t *buf);
void ReadRegPW(int port, int _bits, uint32_t *buf);

uint32_t ReadRegControl(int cmd, uint32_t flagZ, IoPortId port, unsigned int _bits); // temp function for read reg contol
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
/* SKL2 - PIC32-pin4 - RG6                                                       */
/* SDI2 - PIC32-pin5 - RG7                                                       */
/* SDO2 - PIC32-pin6 - RG8                                                       */
//*SYN  - PIC32-pin44-RD10                                                       */
/*-------------------------------------------------------------------------------*/
#define  EnSPI PORTDbits.RD11                   // Enable (EN) for SPI selection)
#define SYN PORTDbits.RD10                      // SYN
#define CS_1   LATGbits.LATG9                    //  CS_1
#define CS_2   LATBbits.LATB5                    //  CS_2
#define CS_3   LATBbits.LATB4                    //  CS_3
#define CS_4   LATBbits.LATB2                    //  CS_4
#define CS_5   LATBbits.LATB3                    //  CS_5

void SPI_Init() {
    // Set Inputs/Outputs for SPI communication

    TRISDbits.TRISD11 = 0; //set EN as an Output
    TRISGbits.TRISG9 = 0; // set CS_1 an output
    TRISBbits.TRISB5 = 0; // set CS_2 an output
    TRISBbits.TRISB4 = 0; // set CS_3 an output
    TRISBbits.TRISB2 = 0; // set CS_4 an output
    TRISBbits.TRISB3 = 0; // set CS_5 an output
    TRISDbits.TRISD10 = 0; // set SYN as an output
   
    LATDbits.LATD11 = 0; //activate EN signal     21.04.2017
   // LATDbits.LATD11 = 1; //activate EN signal     21.04.2017
    LATDbits.LATD10 = 1; //deactivate SYN

    LATGbits.LATG9 = 1;  //1
    LATBbits.LATB5 = 1;  //1
    LATBbits.LATB4 = 1;  //1
    LATBbits.LATB2 = 1;  //1
    LATBbits.LATB3 = 1;  //1
   
    
    TRISGbits.TRISG7 = 1; //set as an input
    TRISGbits.TRISG8 = 0; //set as an output
    TRISGbits.TRISG6 = 0; //set as an output
    
    SpiChnOpen(2, SPICON_MSTEN | SPICON_SMP | SPICON_MODE32 | SPICON_ON, 2); // last was 8 = 20Mhz old value ,2 value 8
    SPI2CONbits.ON=0;
    SPI2CONbits.ENHBUF=0;
    SPI2CONbits.MODE32=1;
    SPI2CONbits.SMP=1;                  //sampled  at the end of the data
    SPI2CONbits.CKP=1;                  //ckp=1;select transfer mode 3
    SPI2CONbits.CKE=0;                  //cke=0
   
    SPI2CONbits.DISSDO=0;
    IEC0CLR=0x03800000;
    IFS0CLR=0x03800000;//Clears any existing event (rx / tx/ fault interrupt)
    SPI2CONbits.ON=1;
   

}

void STPMInitReset() {

    SYN = 0;
    Delay1mS();
    SYN = 1;
    Delay1mS();
    SYN = 0;
    Delay1mS();
    SYN = 1;
    Delay1mS();
    SYN = 0;
    Delay1mS();
    SYN = 1;
    Delay1mS();
    CS_1 = 0;
  //  CS_2 = 0;
  //  CS_3 = 0;
  //  CS_4 = 0;
  //  CS_5 = 0;
    Delay1mS();
      CS_1 = 1;
   // CS_2 = 1;
  //  CS_3 = 1;
  //  CS_4 = 1;
   // CS_5 = 1;
    /*-------------------------------------------------------------------------*/
   
   
}

/*--------------------------------------------------------------------------*/
void ActiveSYN(void) {
    PORTDbits.RD10 = 0; //active SYN
    FrameDelayR(); //4us 
    PORTDbits.RD10 = 1;
}

void Init_STPM34(int chnSel, unsigned int port, unsigned int _bits) {
    
    int i;

    switch (chnSel) {
        case 1: //select parameters for Chn 1/2      //select sensor1 -Ch1,Ch2
            _bits = BIT_9;
            port = IOPORT_G; //prepare to select CS1
            break;
        case 2: //select parameters for Chn 3/4      //select sensor1 -Ch3,Ch4
            _bits = BIT_5;
            port = IOPORT_B; //prepare to select CS2
            break;
        case 3: //select parameters for Chn 5/6      //select sensor1 -Ch5,Ch6
            _bits = BIT_4;
            port = IOPORT_B; //prepare to select CS3
            break;
        case 4: //select parameters for Chn 7/8      //select sensor1 -Ch7,Ch8
            _bits = BIT_2;
            port = IOPORT_B; //prepare to select CS4
            break;
        case 5: //select parameters for Chn 9/10     //select sensor1 -Ch9,Ch10
            _bits = BIT_3; // CS_5 active -  PORTBbits.RB3
            port = IOPORT_B; //prepare to select CS5
            break;
        default:
            break;
    }
    
    //set dsp_cr1
   
    DSP_CR100bits.ENVREF1 = 1;  //enable default value for Vref1=1.18v for CH0;  
    DSP_CR100bits.TC1 = 1 ;   //set temperature compensation for CHx; Vref1=1.2v, 50 degree
    readAdd = 0x00;             // select read register dsp_cr1
    writeAdd = 0x00;            // select write register dsp_cr1
    dataLSB = DSP_CR100bits.LSB;
    dataMSB = DSP_CR100bits.MSB;
    SendFrame(readAdd, writeAdd, dataLSB, dataMSB, port, _bits);
    FrameDelay();
    i=0;            //test point
  
    //set dsp_cr2
  
    DSP_CR200bits.ENVREF2 = 1;  //enable V ref1 bit for CHx;
    DSP_CR200bits.TC2 = 1;    //  should be x02set temperature compensation for CHx;  Vref2=1.18v
    readAdd = 0x02;             // select read register dsp_cr2        
    writeAdd = 0x02;            // select write register dsp_cr2
    dataLSB = DSP_CR200bits.LSB;
    dataMSB = DSP_CR200bits.MSB;
    SendFrame(readAdd, writeAdd, dataLSB, dataMSB, port, _bits); //write to  CR2 register
    FrameDelay();
  
    //set dsp_cr3
 
    DSP_CR301bits.SWAuto_Latch = 0; // Automatic measurement register latch at 7.8125 kHz
    DSP_CR301bits.ZCR_EN=1;         // ZCR option enable
    readAdd = 0x05;
    writeAdd = 0x05;
    dataMSB = DSP_CR301bits.MSB;
    dataLSB = DSP_CR301bits.LSB;
    SendFrame(readAdd, writeAdd, dataLSB, dataMSB, port, _bits); //write to  CR1 register
    FrameDelay();
  
    //set dfe_cr1
   
    DFE_CR101bits.GAIN1 = 0; //set current gain for Chn1=150mV
    readAdd = 0xff;
    writeAdd = 0x19;
    dataLSB = DFE_CR101bits.LSB;
    dataMSB = DFE_CR101bits.MSB;
    SendFrame(readAdd, writeAdd, dataLSB, dataMSB, port, _bits);
    FrameDelay();
  
    //set dfe_cr2 
    
    DFE_CR201bits.GAIN2 = 2; //set current gain for Chn2 for 150mV   
    readAdd = 0xff;
    writeAdd = 0x1B;
    dataLSB = DFE_CR201bits.LSB;
    dataMSB = DFE_CR201bits.MSB;
    SendFrame(readAdd, writeAdd, dataLSB, dataMSB, port, _bits);
    FrameDelay();
   
    //set dsp_cr1
    
    DSP_CR101bits.BHPFV1 = 0; //HPF enable voltage;DC cancellation
    DSP_CR101bits.BHPFC1 = 0; //HPF enable current;DC cancellation
    DSP_CR101bits.BLPFV1 = 0; //LPF included voltage;set up fundamental mode, read ZCR
    DSP_CR101bits.BLPFC1 = 0; //LPF included voltage;set up fundamental mode, read ZCR
    readAdd = 0x01;
    writeAdd = 0x01;
    dataLSB = DSP_CR101bits.LSB;
    dataMSB = DSP_CR101bits.MSB;
    SendFrame(readAdd, writeAdd, dataLSB, dataMSB, port, _bits); //write to  CR1 register
    FrameDelay();
    
    //set dsp_cr2
    
    DSP_CR201bits.BHPFV2 = 0; //HPF enable voltage;DC cancellation
    DSP_CR201bits.BHPFC2 =0; //HPF enable current;DC cancellation
    DSP_CR201bits.BLPFV2 =0; //LPF bypassed voltage;set up fundamental mode, read ZCR
    DSP_CR201bits.BLPFC2 = 0; //LPF bypassed current;set up fundamental mode
    readAdd = 0xff;
    writeAdd = 0x03;
    dataLSB = DSP_CR201bits.LSB;
    dataMSB = DSP_CR201bits.MSB;
    SendFrame(readAdd, writeAdd, dataLSB, dataMSB, port, _bits);
    FrameDelay();
  
}

void Delay1mS() {
    int delayValue;
    delayValue = 100000; // value=1 mS=100000 
    while (delayValue--);
}

void DelayEn(void) {
    int delayValue;
    delayValue = 3100; // 10000delay value = 1mS 
    while (delayValue--);
}

void FrameDelay(void) //delay 4uS
{
    int delayValue;
    delayValue = 40;    //last value 36
    while (delayValue--);

}

void FrameDelay1(void) {
    int delayValue;

    delayValue = 2; // value=7 the last
    while (delayValue--);

}

void FrameSend(void) //delay 4uS
{
    int delayValue;
    delayValue = 16; // 4uS
    while (delayValue--);
}

void FrameDelayR(void) //delay 4uS
{
    int delayValue;
    delayValue =10; // value=36 gives 4uS pulse width
                                                                                                                                                                        while (delayValue--);

}

void ReadReg(int port, int _bits, uint32_t *buf) {
    int i;
    receiveBuffer = SPI2BUF; //clear buffer
    SPI2STATCLR = 1 << 6; //clear overflow
   
  //  for (i = 0; i < 1; i++) {                            //reads consecutively 4 read-latch registers
        
        CSxActive(_bits);                               // activate CSx
        SPI2BUF = 0xffffffff;                            //sends dummy command to read register
        FrameDelay1();                                  //should be at least 4uS    
        while(!SPI2STATbits.SPIRBF){}
        CSxInActive(_bits);
          receiveBuffer=SPI2BUF;                        // reads the selected parameter register  
          receiveBuffer=receiveBuffer<<1;               // 15.06.2017 should be checked                                   
        //save reading parameter
         *buf = receiveBuffer;
         CSxInActive(_bits);
         buf++; 
        // FrameDelay();            //07.06.2017
        // i=0;    //test point
   // }
  //  i=0;          //test point
     
}

void Delay(void) {
    int delayValue;
    delayValue = 8 * 1000;
    while (delayValue--);
}

void SendFrame(uint32_t readAdd, uint32_t writeAdd, uint32_t dataLSB, uint32_t dataMSB, int port, int _bits) {
 
    /* This subroutine sends a SPI frame - 32 bits to the sensor ICs stpm34  */
   
    sendBuff[0] = readAdd;
    sendBuff[1] = writeAdd;
    sendBuff[2] = dataLSB & 0x000000ff;
    sendBuff[3] = dataMSB & 0x000000ff;
    transferValue1 = (sendBuff[0] << 24) | (sendBuff[1] << 16);
    transferValue2 = (sendBuff[2] << 8);
    transferValue = transferValue1 | transferValue2 | sendBuff[3];
    CSxActive(_bits);               //activate CSx x={1,2,3,4,5}
    SPI2BUF = transferValue;
    //receiveBuffer=SPI2BUF;          // 29.06.2017 ?? check and validate
    FrameDelay1();                //24.05 2017
    while(SPI2STATbits.SPITBF){}
    CSxInActive(_bits);
}
void GetParamsEnergyPH1(unsigned int port, unsigned int _bits, int *buffer, relay_t activeRelay, int i)
{
    int j;
    //1. Read Current and Voltage parameters from Chn[i]
     // ReadC1Data(parm_Reg.dataBuffer,activeRelay.relayPort1, activeRelay.relayPin1,_bits);
     //  ReadC2Data(parm_Reg.dataBuffer,activeRelay.relayPort1, activeRelay.relayPin1,_bits);
    for(j=0;j<10;j++){     //test point
    parm_Reg.Address = 0x48; //PH1 Active Energy;PH1 Fundamental Energy;PH1 Reactive Energy;Apparent Energy PH1
    parm_Reg.dataBuffer = buffer;
    SendFrame(parm_Reg.Address, 0xff, 0xff, 0xff, port, _bits); //write to  CR1 register
    FrameDelay();         //07.06.2017
   // FrameDelay();          //07.06.2017
    ReadReg(port, _bits, buffer);
    buffer++;
    buffer++;
    buffer++;
    buffer++;
    FrameDelay();             //07.06.2017
    }
    j=0;
}

void GetParamsEnergyPH2(unsigned int port, unsigned int _bits, int *buffer, relay_t activeRelay, int i) {
    //1. Read Current and Voltage parameters from Chn[i]
   //ReadC1Data(parm_Reg.dataBuffer,activeRelay.relayPort1, activeRelay.relayPin1,_bits);
    //  ReadC2Data(parm_Reg.dataBuffer,activeRelay.relayPort1, activeRelay.relayPin1,_bits);
    parm_Reg.Address = 0x6c; //PH2 Active Energy;PH2 Fundamental Energy;PH2 Reactive Energy;Apparent Energy PH2
    parm_Reg.dataBuffer = buffer;
    SendFrame(parm_Reg.Address, 0xff, 0xff, 0xff, port, _bits); //write to  CR1 register
    FrameDelay();
    ReadReg(port, _bits, buffer);
   

}

void GetParamsPowerPH1(unsigned int port, unsigned int _bits, int *buffer, relay_t activeRelay, int i) {
    //1. Read Current and Voltage parameters from Chn[i]
   // ReadC1Data(parm_Reg.dataBuffer, activeRelay.relayPort1, activeRelay.relayPin1, _bits);
   // ReadC2Data(parm_Reg.dataBuffer,activeRelay.relayPort1, activeRelay.relayPin1,_bits);
    parm_Reg.Address = 0x5c; //PH1 Active Power;PH1 Fundamental Power;PH1 Reactive Power;ApparentPower PH1
    parm_Reg.dataBuffer = buffer;
    SendFrame(parm_Reg.Address, 0xff, 0xff, 0xff, port, _bits); //write to  CR1 register
    //FrameDelay1();
    //ActiveSYN();
    ReadReg(port, _bits, buffer);
    //  FrameDelay();

}

void GetParamsPowerPH2(unsigned int port, unsigned int _bits, int *buffer, relay_t activeRelay, int i) {
    //1. Read Current and Voltage parameters from Chn[i]
    // ReadC1Data(parm_Reg.dataBuffer,activeRelay.relayPort1, activeRelay.relayPin1,_bits);
   // ReadC2Data(parm_Reg.dataBuffer, activeRelay.relayPort1, activeRelay.relayPin1, _bits);
    parm_Reg.Address = 0x74; //PH2 Active Energy;PH2 Fundamental Energy;PH2 Reactive Energy;Apparent Energy PH2
    parm_Reg.dataBuffer = buffer;
    SendFrame(parm_Reg.Address, 0xff, 0xff, 0xff, port, _bits); //write to  CR1 register
    //FrameDelay1();
    //ActiveSYN();
    ReadReg(port, _bits, buffer);
    //  FrameDelay();

}

void CSxActive(int _bits) {


    switch (_bits) {

        case 0x200:
            LATGbits.LATG9 = 0; //CS1 goes low active
            break;
        case 0x020:
            LATBbits.LATB5 = 0; //CS2 goes low active
            break;
        case 0x010:
            LATBbits.LATB4 = 0; //CS3 goes low active
            break;

        case 0x004:
            LATBbits.LATB2 = 0; //CS4 goes low active
            break;
        case 0x008:
            LATBbits.LATB3 = 0; //CS5 goes low active
            break;
        default:
            break;
    }
}

void CSxInActive(int _bits) {
    switch (_bits) {

        case 0x200:
            LATGbits.LATG9 = 1; //CS1 goes low active
            break;
        case 0x020:
            LATBbits.LATB5 = 1; //CS2 goes low active
            break;
        case 0x010:
            LATBbits.LATB4 = 1; //CS3 goes low active
            break;

        case 0x004:
            LATBbits.LATB2 = 1; //CS4 goes low active
            break;
        case 0x008:
            LATBbits.LATB3 = 1; //CS5 goes low active
            break;
        default:
            break;
    }
}

void Dis(int code) {
    int i;
    switch (code) {
        case 1: //Init state displayed
        {
            LATBbits.LATB13 = 0;
            LATGbits.LATG3 = 1;
            break;
        }
        case 2: //Get Params displayed
        {
            LATBbits.LATB13 = 0;
            LATGbits.LATG3 = 1;
            break;
        }
        case 3: //Ethernet displayed
        {
            LATBbits.LATB13 = 0;
            for (i = 0; i < 2; i++) {
                LATGbits.LATG3 = 1;
                Delay();
                LATGbits.LATG3 = 0;
                Delay();
            }
            break;
        }
        case 4: //Wifi displayed
        {
            LATBbits.LATB13 = 0;
            for (i = 0; i < 3; i++) {
                LATGbits.LATG3 = 1;
                Delay();
                LATGbits.LATG3 = 0;
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
void Relay_CRZ(void) {
    int i;
    unsigned int chnSel;
    unsigned int port;
    unsigned int _bits;

    //    Init_Relays();               //Initialize Relay OUTPUTS
    SPI_Init(); //Initialize SPI OUTPUTS

    for (i = 1; i < 6; i++) {
        Init_STPM34(i, port, _bits); //initialize all Sensors STPM34
    }

    //Set Zero crossing Enable in DSP-cr3
    DSP_CR300bits.ZCR_SEL = 0x0; //select V1 - source of ZCR
    DSP_CR301bits.ZCR_EN = 1;
    readAdd = 0x05;
    writeAdd = 0x05;
    dataLSB = DSP_CR301bits.LSB;
    dataMSB = DSP_CR301bits.MSB;
    SendFrame(readAdd, writeAdd, dataLSB, dataMSB, 1, 1);
}

/*void Find_ZCR(void)
{
    while(DSP_EV1bits.ZCR!=1){}            // check if the ZCR bit in reg DSP ev1 is set active 
}*/

void CheckOverCurrent(uint32_t *dataBuf, IoPortId port, unsigned int relayNum) //located in sensor1.c
{
    if (dataBuf[0] >= limitCurrentValue) {
        Find_ZCR(); //located in Relay1.c 
        Switch_ON_Relay(port, relayNum);
        Switch_ON_PWMRelay(port, relayNum); //located in Relay1.c alternative choice
    }

}

void SelectSPIall(void) {
    EnSPI = 0;          //set up EN(RD11) to low level
    FrameDelay();
     CS_1 = 0;          // the last was CS_5=0;
     CS_2 = 0;
     CS_3 = 0;
     CS_4 = 0;
     CS_5 = 0;
     
    EnSPI = 1;
    DelayEn();
  /*  
  // CS_1 = 1;
    CS_2 = 1;
    CS_3 = 1;
    CS_4 = 1;
    CS_5 = 1;
  */
}

/*-------------------------------------------------------------------------------*/
void SelectSPI(int cs) {
    switch (cs) {
        case 1:
            EnSPI = 0;
            DelayEn();
            CS_1 = 0;
            DelayEn();
            EnSPI = 1;
            CS_1 = 1;
            break;
        case 2:
            EnSPI = 0;
            DelayEn();
            CS_2 = 0;
            DelayEn();
            EnSPI = 1;
            CS_2 = 1;
            break;
        case 3:
            EnSPI = 0;
            DelayEn();
            CS_3 = 0;
            DelayEn();
            EnSPI = 1;
            CS_3 = 1;
            break;
        case 4:
            EnSPI = 0;
            DelayEn();
            CS_4 = 0;
            DelayEn();
            EnSPI = 1;
            CS_4 = 1;
            break;
        case 5:
            EnSPI = 0;
            DelayEn();
            CS_5 = 0;
            DelayEn();
            EnSPI = 1;
            CS_5 = 1;
            break;
        default:
            break;
    }
}


uint32_t ReadRegControl(int cmd, uint32_t flagZ, IoPortId port, unsigned int _bits) {
   
    SendFrame(0x2A, 0xff, 0xff, 0xff, port, _bits);
    FrameDelay();
    receiveBuffer = SPI2BUF; //clear buffer
    SPI2STATCLR = 1 << 6; //clear overflow   
    CSxActive(_bits);
    FrameDelay();
    SPI2BUF = 0xffffffff;
    FrameDelay1(); //should be at least 4uS   
    while(!SPI2STATbits.SPIRBF){}
    receiveBuffer = SPI2BUF; //clear buffer
    CSxInActive(_bits);
    return receiveBuffer;
}
void SetSPIx(int cs)
{
   
    switch(cs){
        case 1:                     //set up SPI Chn1&Chn2  STPM1
            CS_1=0;
            CS_2=1;
            CS_3=1;
            CS_4=1;
            CS_5=1;
            break;
         case 2:                     //set up SPI Chn3&Chn4  STPM2
            CS_1=1;
            CS_2=0;
            CS_3=1;
            CS_4=1;
            CS_5=1;
            break;
        case 3:                     //set up SPI Chn5&Chn6  STPM3
            CS_1=1;
            CS_2=1;
            CS_3=0;
            CS_4=1;
            CS_5=1;
            break;   
        case 4:                     //set up SPI Chn7&Chn8  STPM4
            CS_1=1;
            CS_2=1;
            CS_3=1;
            CS_4=0;
            CS_5=1;
            break;  
        case 5:                     //set up SPI Chn9&Chn10  STPM5
            CS_1=1;
            CS_2=1;
            CS_3=1;
            CS_4=1;
            CS_5=0;
            break;  
        default:
            break;
    }
}
void SpiInit1(void)
{
EnSPI = 0;
    DelayEn();
    // CS_1 = 0;
    // CS_2 = 0;
    // CS_3 = 0;
   //  CS_4 = 0;
    CS_5 = 0;
   
    DelayEn();
    EnSPI = 1;
    
    DelayEn();
   // CS_1 = 1;
   // CS_2 = 1;
  //  CS_3 = 1;
  //  CS_4 = 1;
   
   CS_5 = 1;
}
void ReadRegVI(int port, int _bits, uint32_t *buf)
/*-------------------------------------------------------------------*/
/* Description: This routine reads the measured values from */
/*              the registers dsp-reg14 #48and dsp-reg15 #4A*/
/* Specific: The read values for currents CHI is divided by 2 */
{
    int i;
    receiveBuffer = SPI2BUF; //clear buffer
    SPI2STATCLR = 1 << 6; //clear overflow
   
  //  for (i = 0; i < 1; i++) {                            //reads consecutively 4 read-latch registers
        
        CSxActive(_bits);                               // activate CSx
        SPI2BUF = 0xffffffff;                            //sends dummy command to read register
        FrameDelay1();                                  //should be at least 4uS    
        while(!SPI2STATbits.SPIRBF){}
        CSxInActive(_bits);
          receiveBuffer=SPI2BUF;                        // reads the selected parameter register  
          receiveBuffer=receiveBuffer<<1;               // 15.06.2017 should be checked    
          receiveBuffer=receiveBuffer-0x30810000;
          receiveBuffer/=2;
        //save reading parameter
         *buf = receiveBuffer;
         buf++; 
        // FrameDelay();            //07.06.2017
        // i=0;    //test point
   // }
  //  i=0;          //test point
     
}
void ReadRegPW(int port, int _bits, uint32_t *buf)
{
    int i;
    receiveBuffer = SPI2BUF; //clear buffer
    SPI2STATCLR = 1 << 6; //clear overflow
   
  //  for (i = 0; i < 1; i++) {                            //reads consecutively 4 read-latch registers
        
        CSxActive(_bits);                               // activate CSx
        SPI2BUF = 0xffffffff;                            //sends dummy command to read register
        FrameDelay1();                                  //should be at least 4uS    
        while(!SPI2STATbits.SPIRBF){}
        CSxInActive(_bits);
          receiveBuffer=SPI2BUF;                        // reads the selected parameter register  
          receiveBuffer=receiveBuffer<<1;               // 15.06.2017 should be checked   
          receiveBuffer/=4;
        //save reading parameter
         *buf = receiveBuffer;
         buf++; 
        // FrameDelay();            //07.06.2017
        // i=0;    //test point
   // }
  //  i=0;          //test point
    
}