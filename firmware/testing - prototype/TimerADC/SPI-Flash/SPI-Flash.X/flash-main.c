/* 
 * File:   flash-main.c
 * Author: Anton Tachev
 * Description: The main function of this code is to control SPI flash  w25q16dv
 * Created on:    24.02.2017
 */
/*----------------SPI-flash memory to pic32mx connection-----------------------*/
/* CLK - SCLK/RB14  - pin29                       
 * SI  - SD04/RF5   - pin32
 * SO  - SDI4/RF4   - pin 31
 * CS  - RB12       - pin 27  

 */
/*----------------Function prototypes -----------------------------------------*/

void SpiFlashInit(void);
void WriteEnableLatch(void);
void ReadFlash(unsigned int *Dest, unsigned int byte);
void ChipErase(void);
void StorageParam(void);


/*-----------------------------------------------------------------------------*/
#include<stdio.h>
#include <stdlib.h>
#include <plib.h>
#include <p32xxxx.h>
int main() 
{
    unsigned int *sourceBuff;
    unsigned int *destBuff;
    unsigned int buffLength;
    int i,j,k;
    SpiFlashInit();
    WriteEnableLatch();
    StorageParam();       
}

