/*
 * The MIT License (MIT)
 *
 * Copyright (c) [2015] [Marco Russi]
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

/*
 * This file ethmac.h represents the MAC layer inclusion file
 * of the UDP/IP stack.
 *
 * Author : Marco Russi
 *
 * Evolution of the file:
 * 10/08/2015 - File created - Marco Russi
 *
*/


#ifndef _ETHMAC_H
#define _ETHMAC_H


/* --------------- Inclusions files ------------------- */

#include <stdlib.h>
#include <sys/kmem.h>
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#include "fw_common.h"




/* --------------- Exported defines --------------------- */

/* Ethernet packet header length in bytes */
#define ETHMAC_UC_ETH_HDR_LENGTH                ((uint8)14)

/* Ethernet packet header length in bytes */
#define ETHMAC_UC_ETH_ADD_LENGTH                ((uint8)6)

/* Num of RX buffers */
#define ETHMAC_UC_RX_NUM_OF_BUFFERS             (8)

/* Num of TX buffers */
#define ETHMAC_UC_TX_NUM_OF_BUFFERS             (1)




/* ----------------- Exported variables declaration ------------------ */

/* MAC address of this device */
EXTERN uint64 ETHMAC_ui64MACAddress;




/* ------------------ Exported functions prototypes ------------------ */

EXTERN boolean  ETHMAC_Init                 (void);
EXTERN uint8 *  ETHMAC_getNextRXDataBuffer  (void);
EXTERN void     ETHMAC_sendPacket           (uint8 *, uint16, uint64, uint64, uint16);
EXTERN uint8 *  ETHMAC_getTXBufferPointer   (uint16);




#endif




/* End of files */
