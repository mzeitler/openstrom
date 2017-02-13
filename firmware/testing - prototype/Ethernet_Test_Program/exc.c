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
 * This file exc.c represents the only source file for exception handling.
 *
 * Author : Marco Russi
 *
 * Evolution of the file:
 * 06/08/2015 - File created - Marco Russi
 *
*/


/* Defines special funciton registers, CP0 regs  */
#include <xc.h>          


/* Global Data Definitions */

/* static in case exception condition would stop auto variable from being created */
static unsigned int _excep_code;
static unsigned int _excep_addr;

/* Section: Exception Handling */

/* This function overrides the normal _weak_ _generic_exception_handler which
is defined in the XC32 User's Guide. */

void _general_exception_handler(void)
{
    /* Mask off Mask of the ExcCode Field from the Cause Register
    Refer to the MIPs Software User's manual */
  //  _excep_code=_CP0_GET_CAUSE() & 0x0000007C >> 2;       //12122016
 //   _excep_addr=_CP0_GET_EPC();                           //16122016

  //  _CP0_SET_STATUS(_CP0_GET_STATUS()&0xFFFFFFE); /* Disable Interrupts */    //16122016

   // while (1)                 //05122016
   // {
        /* DOTO: Implement any addition exception handling */

        /* Examine _excep_code to identify the type of exception */
        /* Examine _excep_addr to find the address that caused the exception */
   // }
}
