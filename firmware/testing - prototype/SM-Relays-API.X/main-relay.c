/* 
 * File:   relays_api.c
 ** Name of Project: SM-Relays-API project
 * Path:D:/PLIB-Project/SM-Relays-API.X
 * Author: Anton Tachev
 *
 * Created on:25.03.2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <plib.h>
#include <p32xxxx.h>

/*-------------------Functions prototypes-------------------------------------*/
void Init_Relays(void);
void Switch_ON_Relay(IoPortId port,unsigned int relay);
void Switch_OFF_Relay(IoPortId port,unsigned int relay);
void Init_STPM34(int chnSel,unsigned int port,unsigned int _bits);        //function prototype are defined in STPM34_header.h
//void Switch_ON_PWMRelay(IoPortId port,unsigned int relay)
void Relay_Delay(void);
void Find_ZCR(void);
void Relay_CRZ(void);
/*----------------------------------------------------------------------------*/
// Configuration Bit settings
// SYSCLK = 80 MHz (8MHz Crystal/ FPLLIDIV * FPLLMUL / FPLLODIV)
// PBCLK = 40 MHz
// Primary Osc w/PLL (XT+,HS+,EC+PLL)
// WDT OFF
// Other options are don't care

#pragma config FPLLMUL = MUL_20
#pragma config FPLLIDIV = DIV_2, FPLLODIV = DIV_1, FWDTEN = OFF
//#pragma config POSCMOD = XT, FNOSC = PRIPLL, FPBDIV = DIV_1
#pragma config FNOSC=FRCPLL,POSCMOD=OFF,ICESEL=ICS_PGx1
 /* -------------------------------------------------*/
 /*                    Relays connections description               */
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
 /*   Relay_10 - RB7                  */
 /*------------------------------------------------------------------*/

int j=0;
int chnSel=6;                           //the number of sensor IC 
unsigned int port;
unsigned int _bits;

void Relay_Delay(void)
{
    int delayValue;
    delayValue=200*100;
    while(delayValue--);
    
}

int main() {
    int i=0;
   Init_Relays();                              // init repays outputs
  //  Relay_CRZ();
    while(1){
    
   // Find_ZCR();                                 //catch ZCR event
    port=IOPORT_F;
    _bits=BIT_1;
    Switch_ON_PWMRelay(port,_bits);             //PWM mode for Relay1
   
 //   Find_ZCR();                                 //catch ZCR even 
    port=IOPORT_F;                              //PWM mode for Relay2
    _bits=BIT_0;
    Switch_ON_PWMRelay(port,_bits);   
    
  //  Find_ZCR();                                 //catch ZCR even 
    port=IOPORT_D;                              //PWM mode for Relay3
    _bits=BIT_7;
    Switch_ON_PWMRelay(port,_bits);   
    
 //   Find_ZCR();                                 //catch ZCR even 
    port=IOPORT_D;                              //PWM mode for Relay4
    _bits=BIT_6;
    Switch_ON_PWMRelay(port,_bits);   
    
  //  Find_ZCR();                                 //catch ZCR even 
    port=IOPORT_D;                              //PWM mode for Relay5
    _bits=BIT_5;   
    Switch_ON_PWMRelay(port,_bits);
  //  Find_ZCR();                                 //catch ZCR even 
    port=IOPORT_D;                              //PWM mode for Relay6
    _bits=BIT_4;
    Switch_ON_PWMRelay(port,_bits);  
   
    
 //   Find_ZCR();                                 //catch ZCR even 
    port=IOPORT_C;                              //PWM mode for Relay7
    _bits=BIT_14;
    Switch_ON_PWMRelay(port,_bits);   
    
 //   Find_ZCR();                                 //catch ZCR even 
    port=IOPORT_C;                              //PWM mode for Relay8
    _bits=BIT_13;
    Switch_ON_PWMRelay(port,_bits);  
    
 //   Find_ZCR();                                 //catch ZCR even 
    port=IOPORT_B;                              //PWM mode for Relay9
    _bits=BIT_8;
    Switch_ON_PWMRelay(port,_bits);  
    
  //  Find_ZCR();                                 //catch ZCR even 
    port=IOPORT_B;                              //PWM mode for Relay10
    _bits=BIT_7;
    Switch_ON_PWMRelay(port,_bits);  
    }
    
}


