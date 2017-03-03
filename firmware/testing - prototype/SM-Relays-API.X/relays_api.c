/* 
 * File:   relays_api.c
 ** Name of Project: SM-Relays-API project
 * Path:D:/PLIB-Project/SM-Relays-API.X
 * Author: Anton Tachev
 *
 * Created on:22.02.2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <plib.h>
#include <p32xxxx.h>
void Init_Relays(void);
void Switch_ON_Relay(IoPortId port,unsigned int relay);
void Switch_OFF_Relay(IoPortId port,unsigned int relay);
void Init_STPM34(int chnSel,unsigned int port,unsigned int _bits);        //function prototype are defined in STPM34_header.h
//void Switch_ON_PWMRelay(IoPortId port,unsigned int relay)
void Relay_Delay(void);
void Find_ZCR(void);

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
//int bits[16]={BIT_0,BIT_1,BIT_2,BIT_3,BIT_4,BIT_5,BIT_6,BIT_7,
            //  BIT_8,BIT_9,BIT_10,BIT_11,BIT_12,BIT_13,BIT_14,BIT_15};
int j=0;
int chnSel=6;                           //the number of sensor IC 
unsigned int port;
unsigned int _bits;

void Relay_Delay(void)
{
    int delayValue;
    delayValue=80*100;
    while(delayValue--);
    
}

int main() {

    //Init_Relays();                              // init repays outputs
    Relay_CRZ();
    while(1){
    
    Find_ZCR();                                 //catch ZCR event
    Switch_ON_PWMRelay(port,_bits);             //PWM mode
    Relay_Delay();
    Find_ZCR();                                 //catch ZCR event
    Switch_OFF_Relay(port,_bits);          
    }
    
}

