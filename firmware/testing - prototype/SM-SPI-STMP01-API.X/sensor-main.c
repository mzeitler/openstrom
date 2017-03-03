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

/*----------------Function prototypes -----------------------------------------*/

void Init_STPM34(int chnSel,unsigned int port,unsigned int _bits);        //function prototype are defined in STPM34_header.h
void SPI_Init();
void Delay(void);
void ReadFrame(unsigned short address, uint32_t * buffer);
void SendFrame(char readAdd,char writeAdd, char dataLSB,char dataMSB,int port,int bits);
void FrameDelay(void);                          
void GetParams(unsigned int port, unsigned _bits);


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
    while(chnSel--)
   {    
    Init_STPM34(chnSel,port,_bits);       //initialize all Sensors STPM34
   }
   while(1)
   {
       GetParams(0,0);
   }
      
  }                                          // end of main 


 
