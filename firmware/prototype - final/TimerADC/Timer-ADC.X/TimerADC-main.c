/* 
 * File:   TimerADC-main.c
 * Author:Anton Tachev
 * Description: This files control Battery charging
 * 
 * Created on 01 March 2017, 09:51
 */

#include <stdio.h>
#include <stdlib.h>
#include <p32xxxx.h>
#include <plib.h>
#define SYSCLK 80000000L	// Give the system's clock frequency
/*----------------Function prototypes -----------------------------------------*/
void InitTimer1(void);
void InitADC(void);
unsigned int ReadADC16(unsigned int pin);

/*-----------------------------------------------------------------------------*/

// configuration settings
//#pragma config FPLLMUL = MUL_15,FPLLODIV = DIV_4
#pragma config FPLLMUL = MUL_15, FPLLIDIV = DIV_2, FPLLODIV = DIV_4, FWDTEN = OFF

//#pragma config POSCMOD = XT, FNOSC = PRIPLL, FPBDIV = DIV_1
#pragma config FNOSC=FRCPLL,POSCMOD=OFF,ICESEL=ICS_PGx1,FPBDIV= DIV_8  //periphelal clock=10Mhz(FPBDIV)

/*-------------Global Variables--------------------------------------*/
 main()
 {
     SYSTEMConfigPerformance(SYSCLK);                 //automatically configures for max performance
     InitTimer1();
     InitADC();
     while(1){
     
     }
}

