/*******************************************************************************
  Timer Driver Interface Declarations for Static Single Instance Driver

  Company:
   OpenStorn - Smart Meter

  File Name:
    drv_tmr_static_SPI_SM.h

  Summary:
    Timer driver interface declarations for the static single instance driver.

  Description:
    The Timer device driver provides a simple interface to manage the Timer
    modules on Microchip microcontrollers. This file defines the interface
    Declarations for the OC driver.
    
 

#ifndef _DRV_RTCC_STATIC_H
#define _DRV_RTCC_STATIC_H
// *****************************************************************************
// *****************************************************************************
// Section: Include Headers
// *****************************************************************************
// *****************************************************************************
#include <stdint.h>
#include "peripheral/tmr/plib_tmr.h"
#include "peripheral/int/plib_int.h"


// *****************************************************************************
// *****************************************************************************
// Section: Interface Headers for Instance 0 for the static driver
// *****************************************************************************
// *****************************************************************************

void DRV_TMR0_Initialize(void);

inline void DRV_TMR0_Start(void);

inline void DRV_TMR0_Stop(void);

inline void DRV_TMR0_CounterClear(void);

void DRV_TMR0_CounterValueSet(uint32_t value);

uint32_t DRV_TMR0_CounterValueGet(void);

#endif // #ifndef _DRV_RTCC_STATIC_H

/*******************************************************************************
 End of File
*/
