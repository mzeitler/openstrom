/* 
 * File: STPM34_header.h  
 * Author: Tony Tachev
 * Comments:OpenStorm
 * Revision history: D:\PLIB-Project\SM1-Test01.X\src
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <p32xxxx.h>

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

//----SPI Buffer for sending frames to configurate STPM registers-------//
// Structure of frame:  
//          READ add(1byte);				//
/*			WriteAdd(1Byte);				*/
/*			LSData[7:0];					*/
/*			MSData[16:8]					*/			
/*----------------------------------------------------------------------*/
 char sendBuff[4]={0x0f,0x0f,0x0f,0x0f};
 

/*------Definition structure for DSP CR1 LSB register STMP32----------*/
/*  Row:     0                                                        */
/*  Address: 0x00                                                     */
/*  Name:    DSP_CR1_LCB[15:0]                                        */
/*  Default: 0x00A0                                                   */

typedef union{
    
    struct{    
        
   	 unsigned CLRSS_T01 :4;		
  	 unsigned ClassSS   :1;		
 
  	 unsigned ENVREF1   :1;		//  Enable internal voltage reference for primary channel:
                                // 0: reference disabled – external Vref required
                                // 1: reference enabled
 	 unsigned TC1       :3;		//Temperature compensation coefficient selection for primary 
                                //channel voltage reference VREF1
  	 unsigned           :7;
    };
    struct{
        unsigned LSB:16;
    };
    struct{
		unsigned short Address;
    };
  
}DSP_CR100bits_t;
/*-----------------------------------------------------------------------*/

/*------Definition structure for DSP CR1 MSB register STMP32----------------*/
/*  Row:     1                                                              */
/*  Address: 0x01                                                           */
/*  Name:    DSP_CR1 MSB[31:16]                                             */
/*  Default: 0x0400                                                         */

typedef union{
    
    struct{
    
    
   	unsigned         :1;
	unsigned AEM1	:1;	// Apparent energy mode for primary channel:
                            // 0: use apparent RMS power
                            // 1: use apparent vectorial power
	unsigned APM1	:1;	// Apparent vectorial power mode for primary channel:
                            // 0: use fundamental power
                            // 1: use active power					    
   	unsigned BHPFV1 :1;	// Bypass hi-pass filter for primary voltage channel:
                            // 0: HPF enabled
                            // 1: HPF bypassed
   	unsigned BHPFC1 :1;	// Bypass hi-pass filter for primary current channel:
                            // 0: HPF enabled
                            // 1: HPF bypassed
   	unsigned ROC1 	:1;	// Add Rogowski integrator t

   	unsigned BLPFV1 :1;	// Primary voltage channel frequency content used for reactive  power calculation:
                                 // 0: fundamental
                                 // 1: wideband
   	unsigned BLPFC1 :1;	// Primary current channel frequency content used for reactive power calculation:
                        	// 0: fundamental
                        	// 1: wideband
   	unsigned LPW1   :4;	// LED1 speed dividing factor: 0x0 = 2^(-4), 0xF = 2^11
                                // Default 0x4 = 1
	unsigned LPC1		:2;	// LED1 pulse-out power selection:LPS1 [1:0]: 00,01,10,11
                            // LED1 output: active, fundamental, reactive, apparent
	unsigned LCSI		:2;	// LCS1 [1:0]: 00,01,10,11LED1: primary channels, secondary channels, cumulative, 
                            // sigma-delta bitstream
    };
    struct{
        unsigned MSB:16;
    };
   struct{
	unsigned short Address;
    };

} DSP_CR101bits_t;


/*------Definition structure for DSP CR2 LSB register STMP32----------*/
/*  Row:     01                                                        */
/*  Address: 0x02                                                     */
/*  Name:    DSP_CR2_LCB[15:0]                                        */
/*  Default: 0x00A0                                                   */

typedef union{
    
    struct{
    
   	 unsigned CLRSS_T01 :4;		
  	 unsigned ClassSS   :1;		
 
  	 unsigned ENVREF2   :1;		//  Enable internal voltage reference for primary channel:
					// 0: reference disabled – external Vref required
					// 1: reference enabled
 	 unsigned TC2       :3;		//Temperature compensation coefficient selection for primary 
					//channel voltage reference VREF1
  	 unsigned           :7;
    };
    struct{
        unsigned LSB:16;
    };
    struct{
		unsigned short Address;
    };
  
} DSP_CR200bits_t;
/*-----------------------------------------------------------------------*/

/*------Definition structure for DSP CR1 MSB register STMP32----------------*/
/*  Row:     01                                                              */
/*  Address: 0x03                                                           */
/*  Name:    DSP_CR2 MSB[31:16]                                             */
/*  Default: 0x0400                                                         */

typedef union{
    
    struct{
    
    
   	unsigned                :1;
	unsigned AEM2		:1;	// Apparent energy mode for secondary channel:
					// 0: use apparent RMS power
					// 1: use apparent vectorial power
	unsigned APM2		:1;	// Apparent vectorial power mode for secondary channel:
					// 0: use fundamental power
					// 1: use active power					    
   	unsigned BHPFV2    	:1;	// Bypass hi-pass filter for secondary voltage channel:
					// 0: HPF enabled
					// 1: HPF bypassed
    	unsigned BHPFC2	        :1;	// Bypass hi-pass filter for secondary current channel:
					// 0: HPF enabled
					// 1: HPF bypassed
    	unsigned ROC2 	        :1;	// Add Rogowski integrator t

    	unsigned BLPFV2         :1;	// secondary voltage channel frequency content used for reactive  power calculation:
					// 0: fundamental
					// 1: wideband
    	unsigned BLPFC2         :1;	// secondary current channel frequency content used for reactive power calculation:
					// 0: fundamental
					// 1: wideband
    	unsigned LPW2           :4;	// LED1 speed dividing factor: 0x0 = 2^(-4), 0xF = 2^11
					// Default 0x4 = 1
	unsigned LPC2		:2;	// LED1 pulse-out power selection:LPS1 [1:0]: 00,01,10,11
					// LED1 output: active, fundamental, reactive, apparent
	unsigned LCS2		:2;	// LCS2 [1:0]: 00,01,10,11LED1: primary channels, secondary channels, cumulative, 
					// sigma-delta bitstream
    };
    struct{
        unsigned MSB:16;
    };
   struct{
	unsigned short Address;
    };

} DSP_CR201bits_t;


/*-----------------------------------------------------------------------*/

/*------Definition structure for DSP CR3 register STMP32-----------------*/
/*  Row:     2                                                           */
/*  Address: 04                                                          */
/*  Name:    DSP_CR3 LSB[15:0]                                           */
/*  Default: 0x04e0                                                  */

typedef union{
    
   	 struct{
		unsigned SAG_TIME_THR	:14;
		unsigned ZCR_SEL	:2;
	};
	
	struct{
		unsigned LSB		:16;

	};

	struct{
		unsigned short Address;

	};
}DSP_CR300bits_t;

/*------Definition structure for DSP CR3 register STMP32-----------------*/
/*  Row:     2                                                           */
/*  Address: 05                                                          */
/*  Name:    DSP_CR3 MSB[31:16]                                          */
/*  Default: 0x0000                                                  */


	typedef union{

		struct{
			unsigned ZCR_EN		:1;	//ZCR/CLK pin output: 0: CLK 1: ZCR
			unsigned TMP_TOL	:2;
			unsigned TMP_EN		:1;
			unsigned SW_Reset	:1;	//SW reset brings the configuration registers to default
							//This bit is set to zero after this action automatically
			unsigned SW_Latch1	:1;	//Primary channel measurement register latch
							//This bit is set to zero after this action automatically
			unsigned SW_Latch2	:1;	//Secondary channel measurement register latch
							//his bit is set to zero after this action automatically
			unsigned SWAuto_Latch	:1;	//Automatic measurement register latch at 7.8125 kHz 
			unsigned LED_OFF1	:1;	//LED1 pin output disable 0: LED1 output on 1: LED1 output disabled
			unsigned LED_OFF2	:1;	//LED2 pin output disable 0: LED2 output on1: LED2 output disabled
			unsigned EN_CUM		:1;	//Cumulative energy calculation
							//0: cumulative is the sum of channel energies
							//1: total is the difference of energies
			unsigned REFFREQ	:1;	//Reference line frequency: 0: 50 Hz 1: 60 Hz
			unsigned		:4;
		};
	struct{
		unsigned MSB			:16;
	      };
	 struct{
		unsigned short Address;
    };	
}DSP_CR301bits_t;
	
/*-----------------------------------------------------------------------*/


/*------Definition structure for DFE CR1 register STMP32-----------------*/
/*  Row:     12                                                          */
/*  Address: 18                                                          */
/*  Name:    DFE_CR1 LSB[15:0]                                                    */
/*  Default: 0x0327                                                  */

typedef union{
    
   	 struct{
			unsigned	:16;
		};

}DFE_CR100bits_t;


/*------Definition structure for DFE CR1 register STMP32-----------------*/
/*  Row:     12                                                          */
/*  Address: 19                                                          */
/*  Name:    DFE_CR1 MSB[31:16]                                                    */
/*  Default: 0x0f27                                                  */

typedef union{
    
   	 struct{
			unsigned	:10;
			unsigned GAIN1	:2;
			unsigned	:4;
		};
	struct{
			unsigned MSB	:16;
		};
	struct{
			unsigned short Address;
		};
}DFE_CR101_t;




/*------Definition structure for DFE CR1 register STMP32-----------------*/
/*  Row:     13                                                          */
/*  Address: 1A                                                          */
/*  Name:    DFE_CR2 LSB[15:0]                                                    */
/*  Default: 0x0327                                                  */

typedef union{
    
   	 struct{
			unsigned	:16;
		};

}DFE_CR200bits_t;


/*------Definition structure for DFE CR2 register STMP32-----------------*/
/*  Row:     13                                                          */
/*  Address: 1B                                                          */
/*  Name:    DFE_CR2 MSB[31:16]                                          */
/*  Default: 0x0f27                                                      */

typedef union{
    
   	 struct{
			unsigned	:10;
			unsigned GAIN1	:2;
			unsigned	:4;
		};
	struct{
			unsigned MSB	:16;
		};
	struct{
			unsigned short Address;
		};
}DFE_CR201_t;

		

/*------Definition structure for PH1 REG1 register STMP32-----------------*/
/*  Row: 42                                                             */
/*  Address: 52                                                          */
/*  Name:    PH1_REG1   PH1 Active Energy                                */
/*  Default: 0x00000000                                                 */

typedef struct{
	unsigned int DATA ;
	unsigned short Row;
	unsigned short Address;	
}PH1_ActiveEvergy_t;

/*------Definition structure for PH1 REG2 register STMP32-----------------*/
/*  Row: 43                                                               */
/*  Address: 56                                                           */
/*  Name:    PH1_REG2- PH1 Fundamental Energy                             */
/*  Default: 0x00000000                                                   */

typedef struct{
	unsigned int DATA;
	unsigned short Row;
	unsigned short Address;
}PH1_FundEvergy_t;

/*------Definition structure for PH1 REG3 register STMP32-----------------*/
/*  Row: 44                                                               */
/*  Address: 58                                                           */
/*  Name:    PH1_REG3- PH1 Reactive Energy                                */
/*  Default: 0x00000000                                                   */

typedef struct{
	unsigned int DATA;
	unsigned short Row;
	unsigned short Address;
}PH1_ReactEvergy_t;

/*------Definition structure for PH1 REG4 register STMP32-----------------*/
/*  Row: 45                                                               */
/*  Address: 5A                                                           */
/*  Name:    PH1_REG4- PH1 Apparent Energy                                */
/*  Default: 0x00000000                                                   */

typedef struct{
	unsigned int DATA;
	unsigned short Row;
	unsigned short Address;
}__PH1_AppartEvergy;	

/*------Definition structure for PH1 REG5 register STMP32-----------------*/
/*  Row: 46                                                               */
/*  Address: 5C                                                           */
/*  Name:    PH1_REG5- PH1 Active Power [28;0]                            */
/*  Default: 0x00000000                                                   */

typedef struct{
	unsigned int DATA;
	unsigned short Row;
	unsigned short Address;
}PH1_ActivePower_t;

/*------Definition structure for PH1 REG6 register STMP32-----------------*/
/*  Row: 47                                                               */
/*  Address: 5E                                                           */
/*  Name:    PH1_REG6- PH1 Fund Power [28;0]                            */
/*  Default: 0x00000000                                                   */

typedef struct{
	unsigned int DATA;
	unsigned short Row;
	unsigned short Address;
}PH1_FundPower_t;

/*------Definition structure for PH1 REG7 register STMP32-----------------*/
/*  Row: 48                                                               */
/*  Address: 60                                                          */
/*  Name:    PH1_REG7- PH1 Reactive Power [28;0]                            */
/*  Default: 0x00000000                                                   */

typedef struct{
	unsigned int DATA;
	unsigned short Row;
	unsigned short Address;
}PH1_ReactPower_t;

/*------Definition structure for PH1 REG8 register STMP32-----------------*/
/*  Row: 49                                                              */
/*  Address: 62                                                           */
/*  Name:    PH1_REG8- PH1 Apparent Power [28;0]                            */
/*  Default: 0x00000000                                                   */

typedef struct{
	unsigned int DATA;
	unsigned short Row;
	unsigned short Address;
}PH1_AppartPower_t;

/*------Definition structure for PH2 REG1 register STMP32-----------------*/
/*  Row: 54                                                               */
/*  Address: 6C                                                           */
/*  Name:    PH2_REG1- PH2 Active Power [28:0]                            */
/*  Default: 0x00000000                                                   */

typedef struct{
	unsigned int DATA;
	unsigned short Row;
	unsigned short Address;
}PH2_ActivePower_t;

/*------Definition structure for PH2 REG2 register STMP32-----------------*/
/*  Row: 55                                                               */
/*  Address: 6E                                                           */
/*  Name:    PH2_REG2- PH2 Fundamental Power [28:0]                       */
/*  Default: 0x00000000                                                   */

typedef struct{
	unsigned int DATA;
	unsigned short Row;
	unsigned short Address;
}PH2_FundPower_t;

/*------Definition structure for PH2 REG3 register STMP32-----------------*/
/*  Row: 56                                                               */
/*  Address: 70                                                          */
/*  Name:    PH2_REG3- PH2 Reactive Power [28:0]                       */
/*  Default: 0x00000000                                                   */

typedef struct{
	unsigned int DATA;
	unsigned short Row;
	unsigned short Address;
}PH2_ReactPower_t;
	
// Comment a function and leverage automatic documentation with slash star star
/*
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

