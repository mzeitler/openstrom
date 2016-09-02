/* 
 * File:   main.c
 * Name of Project: SM-UART project
 * Path:D:/PLIB-Project/SM-UART1.X
 * Created on 11 Aug 2016, 09:58
 * Author: Anton Tachev
 */

/******************************************************************************/
/*  Files to Include                                                          */
/******************************************************************************/
#ifdef __XC32
    #include <xc.h>          /* Defines special funciton registers, CP0 regs  */
#endif

#include <plib.h>           /* Include to use PIC32 peripheral libraries      */
#include <stdint.h>         /* For uint32_t definition                        */
#include <stdbool.h>        /* For true/false definition                      */
#include "uart.h"
/******************************************************************************/
/*                define constants and macros                                 */
/******************************************************************************/
#define UART_CMD_MODULE_ID              UART1
#define DESIRED_CMD_BAUDRATE            (9600)
#define	GetPeripheralClock()		(80000000/(1 << OSCCONbits.PBDIV))
#define	GetInstructionClock()		(80000000)
/***************************FUNCTIONS Prototypes********************************/
void UART_Init();
void UART_TXbyte(unsigned int  *buffer, unsigned int number);
 
// configuration settings SYSCLK=80Mhz; PBCLK=40Mhz;
//The max PBCLK=80Mhz when FPBDIV = DIV_1

#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FPLLODIV = DIV_8, FWDTEN = OFF
#pragma config POSCMOD = HS, FNOSC = PRIPLL, FPBDIV = DIV_2
/*************************Global Variables**************************************/
unsigned int startBuffer[4]={0x01,0x02,0x03,0x04};
int i,j,k;
int delayValue;
/*******************************************************************************/

 int main() {

    UART_Init();
    
    while(1)
    {
         UART_TXbyte(startBuffer,4);
    }
}

void UART_Init()
{
  
    //1. Using p32mx795f512h.h definitions)
    
    U1MODEbits.UEN=1;                //Set up TxD, RxD accessible 
    U1MODEbits.BRGH=0x1;                //set up PBCLK = SYSCLK/16; 80Mhz/16=5Mhz
    U1MODEbits.PDSEL=0;              //8 bit data  no parity
    U1MODEbits.STSEL=0x1;               //1 stop bit
  // U1MODEbits.ON=1;                    // enable UART1
    
    U1MODECLR=0xff;
    U1MODEbits.w=0x0109;            //set U1MODE through the full Register
    //2. 
   // U1MODEbits.w=0101;            //set all configuration bits of U1MODE
    //3. using plib functions
  //  UARTConfigure(UART_CMD_MODULE_ID, UART_ENABLE_PINS_TX_RX_ONLY);
             
    //UARTSetFifoMode(UART_CMD_MODULE_ID, UART_INTERRUPT_ON_TX_NOT_FULL | UART_INTERRUPT_ON_RX_NOT_EMPTY);
 //   UARTSetLineControl(UART_CMD_MODULE_ID, UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1);
 //   UARTSetDataRate(UART_CMD_MODULE_ID, GetPeripheralClock(), DESIRED_CMD_BAUDRATE);
  //  UARTEnable(UART_CMD_MODULE_ID, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));
}
void UART_TXbyte(unsigned int  *buffer, unsigned int number)
{
    U1STAbits.UTXEN=1;                  //enable TxD transmitter 
    U1MODEbits.ON=1;                    //enable TxD pin and process
    while(number--!=0)
    {
        while(U1STAbits.UTXBF==1){}
        
            U1TXREG=*buffer++;
       
    }
}