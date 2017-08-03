

#include <stdio.h>
#include <stdlib.h>
#include <plib.h>
#include <p32xxxx.h>
//void PageProgLSB0(char *pageArray);
void PageProgLSB0(char *pageArray);
void PageProgLSB1(char *pageArray);
void PageProgMSB(char *pageArray);
void PageProgram(char *pageArray); 


char bufferParam[5]={0x11,0x22,0x33,0x44,0x55};                       //source Buffer parameters example
char *bufferPointer=NULL;
/*------------------SpiFlashInit()---------------------------------------------*/
void SpiFlashInit()
{
    
    // Set Inputs/Outputs for SPI communication
 
    TRISBbits.TRISB12=0;           //set CS output
    TRISFbits.TRISF5=0;            //set SDO4 as an output
    TRISFbits.TRISF4=1;            //set SDI4 as an input
    TRISBbits.TRISB14=0;           //set CLk4 as an output
    
    //Option 2 
    mPORTFSetPinsDigitalOut(BIT_5);             //set SDO4 as an output
    mPORTFSetPinsDigitalIn(BIT_4);              //set SDI4 as an input
    mPORTBSetPinsDigitalOut(BIT_14);            //set CLk4 as an output
  
    //Open SPI_4 Object
  
    SPI4CONCLR=0x0C00;                         //set 8-bit mode
    
    
    SpiChnOpen(4,SPICON_MSTEN|SPICON_SMP|SPICON_ON,4);
}

/* --------------SPI- Flash Functions------------------------------------------*/
/* WriteEnable Instruction =06h ; WE code                                                */
/* Description : this instruction should be set prior to every PageProgram,    */
/*               ChipErase, WriteStatusRegister instructions                  */

void WriteEnableLatch()
{
    PORTBbits.RB12=0;               //activate /CS
    SPI4BUF=0x06;                   //set up WE code
    while(SPI4STATbits.SPITBF==1){}
    PORTBbits.RB12=1;               //deactivate /CS
}

void StorageParam(void)
{
    char codeByte=0x02;                     //Page Program Instruction
    char addByteLSB0=0;                     //LSB address A7  - A0
    char addByteLSB1=0;                     //LSB address A15 - A8
    char addByteMSB=0;                      //MSB address A23 - A16
    char dataByte;                          //dataByte
   // char *bufferParam;                       //source Buffer parameters
    char pageArray[4];                      //
    
    pageArray[0]=codeByte;
    pageArray[1]=addByteLSB0;
    pageArray[2]=addByteLSB1;
    pageArray[3]=addByteMSB;
    
    PageProgLSB0(pageArray);
    PageProgLSB1(pageArray);
    PageProgMSB(pageArray);
    
}
void PageProgram(char *pageArray)
{
    int i;
    while(SPI4STATbits.SPITBF==1){}
    for(i=0;i<4;i++)
    {
        SPI4BUF=pageArray[i];
        while(SPI4STATbits.SPITBF==1){}
    }
}

void PageProgLSB0(char *pageArray)
{
    int i;
    char dataByte;                          //dataByte
    WriteEnableLatch();
    PORTBbits.RB12=0;                   // /CS active
    bufferPointer=bufferParam;
    for(i=0;i<256;i++)
    {
        PageProgram(pageArray);
        pageArray[1]++;
        bufferPointer++;
        dataByte=*bufferPointer;
    }
    PORTBbits.RB12=1;                   //deactivate /CS
   
}

void PageProgLSB1(char *pageArray)
{
    int i;
    char dataByte;
    WriteEnableLatch();
    PORTBbits.RB12=0;                   // /CS active
    
    for(i=0;i<256;i++)
    {
        PageProgLSB0(pageArray);
        pageArray[2]++;
        bufferPointer++;
        dataByte=*bufferPointer;
    }
    PORTBbits.RB12=1;                   //deactivate /CS
   
}

void PageProgMSB(char *pageArray)
{
    int i;
    char dataByte;
    WriteEnableLatch();
    PORTBbits.RB12=0;                   // /CS active
    
    for(i=0;i<32;i++)
    {
        PageProgLSB1(pageArray);
        pageArray[3]++;
        bufferPointer++;
        dataByte=*bufferPointer;
    }
    PORTBbits.RB12=1;                   //deactivate /CS
   
}