/* 
 * File:   RelayTest-main.c
 * Name of Project: SM-Relaytest project
 * Path:D:/PLIB-Project/SM-Relaytest.X
 * Author: Anton Tachev
 *
 * Created on:10.12.2015, 10:57
 */

#include <stdio.h>
#include <stdlib.h>
#include <plib.h>
#include <p32xxxx.h>
#include <math.h>


// Configuration Bit settings
// SYSCLK = 80 MHz (8MHz Crystal/ FPLLIDIV * FPLLMUL / FPLLODIV)
// PBCLK = 40 MHz
// Primary Osc w/PLL (XT+,HS+,EC+PLL)
// WDT OFF
// Other options are don't care


/*----------------Declare Function prototypes------------------------*/
void Init_Relays(void);
void Switch_ON_Relay(IoPortId port,unsigned int relay);
void Relay_Delay(void);
/*-------------------Declare Global variables------------------*/
unsigned int delayValue;
/*-------------------Declare macros*/
#define switch_Rl1(_var) (PORTFbits.RF1=_var)
#define switch_Rl2(_var) (PORTFbits.RF0=_var)
#define switch_Rl3(_var) (PORTDbits.RD7=_var)
#define switch_Rl4(_var) (PORTDbits.RD6=_var)
#define switch_Rl5(_var) (PORTDbits.RD5=_var)
#define switch_Rl6(_var) (PORTDbits.RD4=_var)
#define switch_Rl7(_var) (PORTCbits.RC14=_var)
#define switch_Rl8(_var) (PORTCbits.RC13=_var)
#define switch_Rl9(_var) (PORTBbits.RB8=_var)
#define switch_Rl10(_var) (PORTBbits.RB7=_var)

#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FPLLODIV = DIV_1, FWDTEN = OFF
#pragma config POSCMOD = HS, FNOSC = PRIPLL, FPBDIV = DIV_1
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
int bits[16]={BIT_0,BIT_1,BIT_2,BIT_3,BIT_4,BIT_5,BIT_6,BIT_7,
              BIT_8,BIT_9,BIT_10,BIT_11,BIT_12,BIT_13,BIT_14,BIT_15};
int j=0;
              

int main(void)
{
    unsigned i,j;
    
     Init_Relays();
   
    while(1){
           
        
           switch_Rl1(1); 
           switch_Rl2(1);
           switch_Rl3(1);
           switch_Rl4(1);
           switch_Rl5(1);
           switch_Rl6(1);
           switch_Rl7(1);
           switch_Rl8(1);
           switch_Rl9(1);
           switch_Rl10(1);
           Relay_Delay();            //delay=4ms
           switch_Rl1(0); 
           switch_Rl2(0);
           switch_Rl3(0);
           switch_Rl4(0);
           switch_Rl5(0);
           switch_Rl6(0);
           switch_Rl7(0);
           switch_Rl8(0);
           switch_Rl9(0);
           switch_Rl10(0);
           Relay_Delay();            //delay=4ms
        
         
    }
   
}

void Init_Relays(void)
{
    //1.Option 1 
      mPORTFSetPinsDigitalOut(BIT_0|BIT_1);            //init Relays K1&K2
      mPORTDSetPinsDigitalOut(BIT_4|BIT_5|BIT_6|BIT_7);//init Relays K2...K6
      mPORTCSetPinsDigitalOut(BIT_13|BIT_14);           //init Relays K7&K8
      mPORTBSetPinsDigitalOut(BIT_8|BIT_7);            //init Relays K9&K10
    //2. Option 2
     
     // TRISB=0x0;
     // TRISF=0x0;
     // TRISD=0x0;
     // TRISC=0x0;
      
      
}
void Switch_ON_Relay(IoPortId port,unsigned int relay)
{
    PORTWrite(port,relay);
    switch_Rl1(1);        
}
void Relay_Delay(void)
{
    delayValue=80*100;
    while(delayValue--);
    
}
