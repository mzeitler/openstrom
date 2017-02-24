/* 
 * File:   sdi.h
 * Author: Anton Tachev
 * Location: D:\PLIB-Project\SM-Relaytest.X
 * Created on 19.02 2017, 10:55
 */

#ifndef SDI_H
#define	SDI_H

#include <plib.h>
#include <p32xxxx.h>
#include "STPM34_header.h"
/*--------------------Function declarations------------------------------------*/
void SPI_Init();
void Delay(void);
void ReadFrame(unsigned int address, unsigned int* buffer);
void SendFrame(char readAdd,char writeAdd, char dataLSB,char dataMSB,int port,int bits);
void FrameDelay(void);  
/*-----------------------------------------------------------------------------*/



#endif	/* SDI_H */

