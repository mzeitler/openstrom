/* 
 * File:   Relay.h
 * Author: Anton Tachev
 * Location: D:\PLIB-Project\SM-Relaytest.X
 * Created on 19.02 2017, 10:55
 */

#include <plib.h>
#include <p32xxxx.h>

/*-------------------Declare macros--------------------------*/
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


/*----------------Declare Function prototypes------------------------*/
void Init_Relays(void);
void Switch_ON_Relay(IoPortId port,unsigned int relay);
void Switch_OFF_Relay(IoPortId port,unsigned int relay);
void Switch_ON_PWMRelay(IoPortId port,unsigned int relay)
void Relay_Delay(void);

#ifndef RELAY_H
#define	RELAY_H

#ifdef	__cplusplus
extern "C" {
#endif
#ifdef	__cplusplus
}

#endif

#endif	/* RELAY_H */

