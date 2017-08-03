/* 
 * File:   Timer1.c
 * Author:Anton Tachev
 * Description: This files control Battery charging
 * 
 * Created on 01 March 2017, 09:51
 */
#include <stdio.h>
#include <stdlib.h>
#include <p32xxxx.h>
#include <plib.h>

void InitTimer1()
{
    // Timer1 as configured would trigger an interrupt at a frequency of (10MHZ/256/0x9897)  times a second.
    
    OpenTimer1( T1_ON | T1_SOURCE_INT | T1_PS_1_256, 0x9897);//turn on timer1;FPBCLK=10Mhz;PS=256;period=9897
	 
	ConfigIntTimer1( T1_INT_ON | T1_INT_PRIOR_2);            //configured the timer to produce an interrupt with a priority of 2
	

	INTEnableSystemMultiVectoredInt();                      // Use multi-vectored interrupts
	
}

void InitADC()
{
    AD1PCFGbits.PCFG9=0;                                    // sett RB9/AN9 as an analog input
    AD1PCFGbits.PCFG10=0;                                   //sett RB10/AN10 as an analog input
    AD1PCFGCLR=0x0600;                                      // the same
   // mPORTBSetPinsAnalogIn(BIT_9|BIT_10);
    
    AD1CON1bits.FORM=0x0;                           //set output format Integer 16-bits
    AD1CON1bits.SSRC=0x7;                           //auto convert
    AD1CON1bits.ASAM=1;                             //sample auto start bit
    
    AD1CON2bits.VCFG=0;                            //set AVref AVdd:AVss
    AD1CON2=0x0;
    
    AD1CON3=0x0101;                                 //configure sample clock
    
    AD1CHSbits.CH0NB=0;                             //Vref- negative
    AD1CHSbits.CH0SB=0x9;                           // read input AN9
    
    AD1CON1bits.ON=1;                               //start ADc operations
 
}


unsigned int ReadADC16(unsigned int pin)
{
    unsigned int adcValue;
    unsigned int *ptrADC16;
    
    switch(pin)
    {
        case 0:
            AD1CHSbits.CH0SB=0x0;               //select input AN0
            break;
        case 9:
            AD1CHSbits.CH0SB=0x9;               //select input AN9
            break;
        case 10:
            AD1CHSbits.CH0SB=0xA;               //select input AN10
            break;    
        default:
            break;
            
    }
    
    IFS1bits.AD1IF=0;                           // clear up interrupt flag
    IEC1bits.AD1IE=0;                           //disable interrupts
   // ptrADC16=&ADC1BUF0;
    
    AD1CON1bits.ASAM=1;                         //set auto scan samples
    while(!AD1CON1bits.DONE);
    adcValue=ADC1BUF0;
    *ptrADC16=adcValue;
    
}
/*------------- Timer2 Interrupt Service Routine------------------*/

void __ISR(_TIMER_2_VECTOR, IPL2SRS) handlesTimer2Ints(void)
{
    unsigned int batteryValue;
    unsigned int voltCheck;
    
   voltCheck=ReadADC16(10);
    if(voltCheck<= 0xD174)                  //Vx=0xD175 is input voltage less that 10V
    {
        batteryValue = ReadADC16(9);        // read BatteryCheck input
        if( batteryValue <=  0x72CF)        //Vy=0xD175 is input voltage less that 7V
        {
            //charge On active
            PORTFbits.RF3=1;                //start charging           
        }
        else{
            PORTFbits.RF3=0;                //OFF charging
        }
    }

   PORTFbits.RF3=0;
   mT1ClearIntFlag();

}
