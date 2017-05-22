/* 
 * File:   STPM-define.h
 * Author: Tony Tachev
 *
 * Upgraded on 25.July. 2016 14:53
 */


#ifdef	__cplusplus
extern "C" {
#endif
#include <stdint.h>
#include <stdlib.h>
// TODO Insert declarations
//void  Init_STPM34();        //function prototype
//void  Init_SPI_module();
//void SendFrame(char readAdd,char wrireAdd, char dataLSB,char dataMSB);
//----SPI Buffer for sending frames to configurate STPM registers-------//
// Structure of the frame:  
//          ReadAdd(1byte);				//
/*			WriteAdd(1Byte);				*/
/*			LSData[7:0];					*/
/*			MSData[15:8]					*/			
/*----------------------------------------------------------------------*/
 //char sendBuff[4]={0x0f,0x0f,0x0f,0x0f};
 
 /*------Structure definition for DSP CR1 LSB register STMP32----------*/
/*  Row:     0                                                        */
/*  Address:0x00                                                   */
/*  Name:    DSP_CR1_LSW[15:0]                                        */
/*  Read(R) Write(W) Latch(L): RW                                     */
/*  Default: 0x00A0                                                   */

typedef union{
    
    struct{    
        
   	 unsigned CLRSS_T01 :4;		
  	 unsigned ClearSS   :1;		
 
  	 unsigned ENVREF1   :1;		//  Enable internal voltage reference for primary channel:
                                // 0: reference disabled – external Vref required
                                // 1: reference enabled
 	 unsigned TC1       :3;		//Temperature compensation coefficient selection for primary 
                                //channel voltage reference VREF1
  	 unsigned           :7;
    };
    struct{
        unsigned LSB:8;
        unsigned MSB:8;
        unsigned LSW:16;
    };
    struct{
		unsigned short Address;
    };
  
}DSP_CR100bits_t;
//extern volatile DSP_CR100bits_t DSP_CR100bits  __asm__ ("DSP_CR100") __attribute__((section("sfrs")));
/*-----------------------------------------------------------------------*/

/*------Structure definition for DSP CR1 MSB register STMP32----------------*/
/*  Row:     1                                                              */
/*  Address: 0x01                                                         */
/*  Name:    DSP_CR1 MSW[31:16]                                             */
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
        unsigned LSB:8;
        unsigned MSB:8;
        unsigned MSW:16;
    };
   struct{
	unsigned short Address;
    };

} DSP_CR101bits_t;


/*------Structure definition for DSP CR2 LSB register STMP32----------*/
/*  Row:     01                                                        */
/*  Address: 0x02                                                     */
/*  Name:    DSP_CR2_LCW[15:0]                                        */
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
        unsigned LSB:8;
        unsigned MSB:8;
        unsigned LSW:16;
    };
    struct{
		unsigned short Address;
    };
  
} DSP_CR200bits_t;
/*-----------------------------------------------------------------------*/

/*------Structure definition for DSP CR1 MSB register STMP32----------------*/
/*  Row:     01                                                              */
/*  Address: 0x03                                                           */
/*  Name:    DSP_CR2 MSW[31:16]                                             */
/*  Default: 0x0400                                                         */

typedef union{
    
    struct{
    
    
   	unsigned            :1;
	unsigned AEM2		:1;	// Apparent energy mode for secondary channel:
                            // 0: use apparent RMS power
                            // 1: use apparent vectorial power
	unsigned APM2		:1;	// Apparent vectorial power mode for secondary channel:
                            // 0: use fundamental power
                            // 1: use active power					    
   	unsigned BHPFV2    	:1;	// Bypass hi-pass filter for secondary voltage channel:
                            // 0: HPF enabled
                            // 1: HPF bypassed
   	unsigned BHPFC2     :1;	// Bypass hi-pass filter for secondary current channel:
                            // 0: HPF enabled
                            // 1: HPF bypassed
   	unsigned ROC2       :1;	// Add Rogowski integrator t

   	unsigned BLPFV2     :1;	// secondary voltage channel frequency content used for reactive  power calculation:
                            // 0: fundamental
                            // 1: wideband
   	unsigned BLPFC2     :1;	// secondary current channel frequency content used for reactive power calculation:
                            // 0: fundamental
                            // 1: wideband
   	unsigned LPW2       :4;	// LED1 speed dividing factor: 0x0 = 2^(-4), 0xF = 2^11
                            // Default 0x4 = 1
	unsigned LPC2		:2;	// LED1 pulse-out power selection:LPS1 [1:0]: 00,01,10,11
                            // LED1 output: active, fundamental, reactive, apparent
	unsigned LCS2		:2;	// LCS2 [1:0]: 00,01,10,11LED1: primary channels, secondary channels, cumulative, 
                            // sigma-delta bitstream
    };
    struct{
        unsigned LSB:8;
        unsigned MSB:8;
        unsigned MSW:16;
    };
   struct{
	unsigned short Address;
    };

} DSP_CR201bits_t;


/*-----------------------------------------------------------------------*/

/*------Structure definition for DSP CR3 register STMP32-----------------*/
/*  Row:     2                                                           */
/*  Address: 04                                                          */
/*  Name:    DSP_CR3 LSW[15:0]                                           */
/*  Default: 0x04e0                                                  */

typedef union{
    
   	 struct{
		unsigned SAG_TIME_THR	:14;
		unsigned ZCR_SEL	    :2;         //When DSP_CR300bits.ZCR_EN=0; ZCR_SEL=00(V1),
                                            //                             ZCR_SEL=01(C1),
                                            //                             ZCR_SEL=10(V2),
                                            //                             ZCR_SEL=11(C1);
	};
	
	struct{
        unsigned LSB:8;
        unsigned MSB:8;
        unsigned LSW		:16;

	};

	struct{
		unsigned short Address;

	};
}DSP_CR300bits_t;

/*------Structure definition for DSP CR3 register STMP32-----------------*/
/*  Row:     2                                                           */
/*  Address: 05                                                          */
/*  Name:    DSP_CR3 MSW[31:16]                                          */
/*  Default: 0x0000                                                  */


	typedef union{

		struct{
			unsigned ZCR_EN		:1;     //ZCR/CLK pin output: 0: CLK 1: ZCR
			unsigned TMP_TOL	:2;
			unsigned TMP_EN		:1;
			unsigned SW_Reset	:1;     //SW reset brings the configuration registers to default
                                        //This bit is set to zero after this action automatically
			unsigned SW_Latch1	:1;     //Primary channel measurement register latch
                                        //This bit is set to zero after this action automatically
			unsigned SW_Latch2	:1; 	//Secondary channel measurement register latch
                                        //his bit is set to zero after this action automatically
			unsigned SWAuto_Latch	:1;	//Automatic measurement register latch at 7.8125 kHz 
			unsigned LED_OFF1	:1; 	//LED1 pin output disable 0: LED1 output on 1: LED1 output disabled
			unsigned LED_OFF2	:1;     //LED2 pin output disable 0: LED2 output on1: LED2 output disabled
			unsigned EN_CUM		:1;     //Cumulative energy calculation
                                        //0: cumulative is the sum of channel energies
                                        //1: total is the difference of energies
			unsigned REFFREQ	:1; 	//Reference line frequency: 0: 50 Hz 1: 60 Hz
			unsigned		:4;
		};
	struct{
		unsigned LSB:8;
        unsigned MSB:8;
        unsigned MSW:16;
	      };
	 struct{
		unsigned short Address;
    };	
}DSP_CR301bits_t;
	
/*-----------------------------------------------------------------------*/

/*========================================================================*/
/*------Definition structure for DSP CR4 register STMP32-----------------*/
/*  Row:     3                                                           */
/*  Address: 0x06                                                        */
/*  Name:    DSP_CR400                                          */
/*  Structures:PHC2[9:0];PHV2[1:0]; PHC1[9:0]; PHV1[1:0]                 */
 
 typedef union{
 
     struct{
        unsigned PHC2:10;          //PHC2[9:0]
        unsigned PHV2: 2;          //PHV2[1:0]
        unsigned PHC1:10;          //PHC1[9:0]
        unsigned PHV1: 2;          //PHV2[1:0]
        unsigned     : 8;
     };
     struct{
        unsigned LSW:16;
        unsigned MSW:16;
     };
     struct{
			unsigned short Address;
		};
 }DSP_CR400bits_t;
 
/*------Definition structure for DSP CR5 register STMP32-----------------*/
/*  Row:     4                                                           */
/*  Address: 0x08                                                        */
/*  Name:    DSP_CR500                                          */
/*  Structures:SAG_THR1[9:0];SWV_THR1[9:0]; PHC1[9:0]; CHV1[11:0]                 */
 
 typedef union{
 
     struct{
        unsigned CHV1    :12;           //CHV1[11:0]]
        unsigned SWV_THR1:10;           //SWV_THR1[9:0]
        unsigned SAG_THR1:10;           //SAG_THR1[9:1]
     };
     struct{
        unsigned LSW:16;
        unsigned MSW:16;
     };
     struct{
			unsigned short Address;
		};
 }DSP_CR500bits_t;
 /*------Definition structure for DSP CR6 register STMP32-----------------*/
/*  Row:     5                                                           */
/*  Address: 0x0A                                                        */
/*  Name:    DSP_CR600                                                     */
/*  Structures:;SWC_THR1[9:0]; CHC1[11:0]                 */
 
 typedef union{
 
     struct{
        unsigned CHC1    :12;           //CHV1[11:0]]
        unsigned SWV_THR1:10;           //SWV_THR1[9:0]
     };
     struct{
        unsigned LSW:16;
        unsigned MSW:6;
     };
     struct{
			unsigned short Address;
		};
 }DSP_CR600bits_t;
 
  /*------Definition structure for DSP CR7 register STMP32-----------------*/
/*  Row:     6                                                           */
/*  Address: 0x0C                                                        */
/*  Name:    DSP_CR700                                                     */
/*  Structures:;SWC_THR1[9:0]; CHC1[11:0]                 */
 
 typedef union{
 
     struct{
        unsigned CHV2    :12;           //CHV1[11:0]]
        unsigned SWV_THR2:10;           //SWV_THR1[9:0]
        unsigned SAG_THR2:10;           //SAG_THR1[9:1]
     };
     struct{
        unsigned LSW:16;
        unsigned MSW:16;
     };
     struct{
			unsigned short Address;
		};
 }DSP_CR700bits_t;
 
/*------Definition structure for DSP CR8 register STMP32-----------------*/
/*  Row:     7                                                           */
/*  Address: 0x0E                                                        */
/*  Name:    DSP_CR800                                          */
/*  Structures:SAG_THR2[9:0];SWV_THR2[9:0]; PHC1[9:0]; CHV2[11:0]                 */
 
 typedef union{
 
     struct{
        unsigned CHV2    :12;           //CHV1[11:0]]
        unsigned SWV_THR2:10;           //SWV_THR1[9:0]
        unsigned SAG_THR2:10;           //SAG_THR1[9:1]
     };
     struct{
        unsigned LSW:16;
        unsigned MSW:16;
     };
     struct{
			unsigned short Address;
		};
 }DSP_CR800bits_t;
 
/*------Definition structure for DSP CR9 register STMP32-----------------*/
/*  Row:     8                                                           */
/*  Address: 0x10                                                        */
/*  Name:    DSP_CR900                                                   */
/*  Structures:OFAF1[9:0];OFA1[9:0]; AH_UP1[11:0]                        */
 
 typedef union{
 
     struct{
        unsigned AH_UP1  :12;           
        unsigned OFA1    :10;          
        unsigned OFAF1   :10;           
     };
     struct{
        unsigned LSW:16;
        unsigned MSW:16;
     };
     struct{
			unsigned short Address;
		};
 }DSP_CR900bits_t;
 
/*------Definition structure for DSP CR10 register STMP32-----------------*/
/*  Row:     9                                                           */
/*  Address: 0x12                                                        */
/*  Name:    DSP_CR1000                                                   */
/*  Structures:OFAS1[9:0];OFR1[9:0]; AH_DOWN1[11:0]                        */
 
 typedef union{
 
     struct{
        unsigned AH_DOWN1  :12;           
        unsigned OFR1     :10;          
        unsigned OFAS1    :10;           
     };
     struct{
        unsigned LSW:16;
        unsigned MSW:16;
     };
     struct{
			unsigned short Address;
		};
 }DSP_CR1000bits_t;

 /*------Definition structure for DSP CR11 register STMP32-----------------*/
/*  Row:     10                                                           */
/*  Address: 0x14                                                        */
/*  Name:    DSP_CR1100                                                   */
/*  Structures:OFAF2[9:0];OFA2[9:0]; AH_UP2[11:0]                        */
 
 typedef union{
 
     struct{
        unsigned AH_UP2   :12;           
        unsigned OFA2     :10;          
        unsigned OFAF2    :10;           
     };
     struct{
        unsigned LSW:16;
        unsigned MSW:16;
     };
     struct{
			unsigned short Address;
		};
 }DSP_CR1100bits_t;
 
 /*------Definition structure for DSP CR12 register STMP32-----------------*/
/*  Row:     11                                                           */
/*  Address: 0x16                                                       */
/*  Name:    DSP_CR1200                                                   */
/*  Structures:OFAS2[9:0];OFR2[9:0]; AH_DOWN2[11:0]                        */
 
 typedef union{
 
     struct{
        unsigned AH_DOWN2  :12;           
        unsigned OFR2     :10;          
        unsigned OFAS2    :10;           
     };
     struct{
        unsigned LSW:16;
        unsigned MSW:16;
     };
     struct{
			unsigned short Address;
		};
 }DSP_CR1200bits_t;

/*------Structure definition for DFE CR1 register STMP32-----------------*/
/*  Row:     12                                                          */
/*  Address: 18                                                          */
/*  Name:    DFE_CR1 LSB[15:0]                                                    */
/*  Default: 0x0327                                                  */

typedef union{
    
   	 struct{
			unsigned	:16;
		};

}DFE_CR100bits_t;


/*------Structure definition for DFE CR1 register STMP32-----------------*/
/*  Row:     12                                                          */
/*  Address: 19                                                         */
/*  Name:    DFE_CR1 MSW[31:16]                                                    */
/*  Default: 0x3270327                                               */

typedef union{
    
   	 struct{
			unsigned        :10;
			unsigned GAIN1	:2;
			unsigned        :4;
		};
	struct{
			unsigned LSB:8;
            unsigned MSB:8;
            unsigned MSW:16;
		};
	struct{
			unsigned short Address;
		};
}DFE_CR101bits_t;




/*------Structure definition for DFE CR2 register STMP32-----------------*/
/*  Row:     13                                                          */
/*  Address: 1B                                                          */
/*  Name:    DFE_CR2 MSW[31:16]                                          */
/*  Default: 0x3270327                                                   */

typedef union{
    
     struct{
			unsigned        :10;
			unsigned GAIN1  :2;
			unsigned        :4;
		};
	struct{
			unsigned LSB:8;
            unsigned MSB:8;
            unsigned MSW:16;
		};
	struct{
			unsigned short Address;
		};
}DFE_CR201bits_t; 



/*------Structure definition for US1 REG1 LSW register STMP32-----------------*/
/*  Row:     18                                                           */
/*  Address: 0x24                                                         */
/*  Name:    US1_REG1_LSW[15:0]                                                 */
/*  Default: 0x4007                                                */

typedef union{
    
     struct{
			unsigned CRC_Pol   :8;
			unsigned Noise_EN  :1;
			unsigned BRK_ERR   :1;
            unsigned           :4;
            unsigned CRC_EN    :1;
            unsigned ISB_FIRST :1;
		};
	struct{
			unsigned LSB:8;
            unsigned MSB:8;
            unsigned LSW:16;
		};
	struct{
			unsigned short Address;
		};
}US1_REG100bits_t; 

/*------Structure definition for U1 REG1 MSW register STMP32-----------------*/
/*  Row:     18                                                          */
/*  Address: 0x25                                                         */
/*  Name:    US1_REG1_MSW[31:16]                                                 */
/*  Default: 0x0000                                              */

typedef union{
    
     struct{
			unsigned TIME_OUT :8;
			
		};
	struct{
			unsigned LSB:8;
            //unsigned MSB:8;
            //unsigned LSW:16;
		};
	union{
			unsigned short Address;
		};
}US1_REG101bits_t; 

/*------Structure definition for DSP_ev1 register STMP32-----------------------*/
/*  Row:     21                                                                */
/*  Address: #2A                                                               */
/*  Name:    DSP_EV1[15:0]                                                     */;
/*  Default: 0x00000000                                                        */

 typedef union{
        
     struct{
         unsigned PowerSign:     2;
         unsigned PowerOverflow: 2;
         unsigned PowerSign_PH1:         4;
         unsigned PowerOverflow_PH1:   4;
         unsigned ZCR:                   1;
         unsigned SignalStuck:           1;
         unsigned Nah:                  1;
         unsigned SWC1_ECV:              3;
     };
     struct{
         unsigned LSB:8;
         unsigned MSB:8;
         unsigned LSW:16;
     };
     struct{
         unsigned short Address;
     };
 
 }DSP_EV1bits_t;
  

/*------Structure definition for PH1 REG3 register STMP32-----------------*/
/*  Row: 44                                                               */
/*  Address: 58                                                           */
/*  Name:    PH1_REG3- PH1 Reactive Energy                                */
/*  Default: 0x00000000                                                   */

typedef struct{
	unsigned int DATA;
	unsigned short Row;
	unsigned short Address;
}PH1_ReactEvergy_t;

/*------Structure definition for PH1 REG4 register STMP32-----------------*/
/*  Row: 45                                                               */
/*  Address: 5A                                                           */
/*  Name:    PH1_REG4- PH1 Apparent Energy                                */
/*  Default: 0x00000000                                                   */

typedef struct{
	unsigned int DATA;
	unsigned short Row;
	unsigned short Address;
}__PH1_AppartEvergy;	

/*------Structure definition for PH1 REG5 register STMP32-----------------*/
/*  Row: 46                                                               */
/*  Address: 5C                                                           */
/*  Name:    PH1_REG5- PH1 Active Power [28;0]                            */
/*  Default: 0x00000000                                                   */

typedef struct{
	unsigned int DATA;
	unsigned short Row;
	unsigned short Address;
}PH1_ActivePower_t;

/*------Structure definition for PH1 REG6 register STMP32-----------------*/
/*  Row: 47                                                               */
/*  Address: 5E                                                           */
/*  Name:    PH1_REG6- PH1 Fund Power [28;0]                            */
/*  Default: 0x00000000                                                   */

typedef struct{
	unsigned int DATA;
	unsigned short Row;
	unsigned short Address;
}PH1_FundPower_t;

/*------Structure definition for PH1 REG7 register STMP32-----------------*/
/*  Row: 48                                                               */
/*  Address: 60                                                          */
/*  Name:    PH1_REG7- PH1 Reactive Power [28;0]                            */
/*  Default: 0x00000000                                                   */

typedef struct{
	unsigned int DATA;
	unsigned short Row;
	unsigned short Address;
}PH1_ReactPower_t;

/*------Structure definition for PH1 REG8 register STMP32-----------------*/
/*  Row: 49                                                              */
/*  Address: 62                                                           */
/*  Name:    PH1_REG8- PH1 Apparent Power [28;0]                            */
/*  Default: 0x00000000                                                   */

typedef struct{
	unsigned int DATA;
	unsigned short Row;
	unsigned short Address;
}PH1_AppartPower_t;

/*------Structure definition for PH2 REG1 register STMP32-----------------*/
/*  Row: 54                                                               */
/*  Address: 6C                                                           */
/*  Name:    PH2_REG1- PH2 Active Power [28:0]                            */
/*  Default: 0x00000000                                                   */

typedef struct{
	unsigned int DATA;
	unsigned short Row;
	unsigned short Address;
}PH2_ActivePower_t;

/*------Structure definition for PH2 REG2 register STMP32-----------------*/
/*  Row: 55                                                               */
/*  Address: 6E                                                           */
/*  Name:    PH2_REG2- PH2 Fundamental Power [28:0]                       */
/*  Default: 0x00000000                                                   */

typedef struct{
	unsigned int DATA;
	unsigned short Row;
	unsigned short Address;
}PH2_FundPower_t;

/*------Structure definition for PH2 REG3 register STMP32----------------*/
/*  Row: 56                                                              */
/*  Address: 70                                                          */
/*  Name:    PH2_REG3- PH2 Reactive Power [28:0]                         */
/*  Default: 0x00000000                                                  */

typedef struct{
	unsigned int DATA;
	unsigned short Row;
	unsigned short Address;
}PH2_ReactPower_t;

 
 
/*-----------------------------------------------------------------------------*/
/* Parameter's Buffers for Channel-Sensors IC                                          */
    unsigned int chnBuff1=0x55;
    unsigned int chnBuff2;
    uint32_t limitCurrentValue=0x55555555;          //should calculate the limit current value
/*-----------------------------------------------------------------------------*/
/*-----Definition array of structures for parameter registers----------------*/
/* Members:                                                                  */
/*      - Row;                                                               */
/*      - Address;                                                           */
/*      - dataBuffer;                                                         */
                                                          
typedef struct{
	uint32_t * dataBuffer;
	unsigned short Row;	
    uint32_t  Address;
}parm_Reg_t;  
    
/*-----Definition  for dsp_reg1------------------------------------*/
/* Row: 23                                                                  */
/* Address: 0x2E                                                              */
/* Name; PH2 Period[11:0] PH1 Period[11;0]                                  */
	unsigned short Period_Row=23;
	unsigned short Period_Address=0x2E;	


 /*-----Definition  for dsp_reg2------------------------------------*/
/* Row: 24                                                                  */
/* Address: 0x30                                                             */
/* Name: V1_Data[23:0]  
/* Description:Voltage value for Chn1 in V1_Data Register[23:0]                                                   */

	unsigned short V1_Data_Row=28;
	unsigned short V1_Data_Address=0x38;	


/*-----Definition  for dsp_reg3------------------------------------*/
/* Row: 25                                                                  */
/* Address: 0x32                                                              */
/* Name: C1_Data[23:0]                                                      */

	unsigned short C1_Data_Row=25;
	unsigned short C1_Data_Address=0x32;	


/*-----Definition  for dsp_reg4------------------------------------*/
/* Row: 26                                                                  */
/* Address: 0x34                                                              */
/* Name: V2_Data[23:0]                                                      */

	unsigned short V2_Data_Row=26;
	unsigned short V2_Data_Address=0x34;	

/*-----Definition  for dsp_reg5------------------------------------*/
/* Row: 27                                                                  */
/* Address: 0x36                                                              */
/* Name: C2_Data[23:0]                                                      */

	unsigned short C2_Data_Row=27;
	unsigned short C2_Data_Address=0x36;	


/*-----Definition  for dsp_reg6------------------------------------*/
/* Row: 28                                                                  */
/* Address: 0x38                                                            */
/* Name: V1_Fund[23:0]                                                      */

	unsigned short V1_Fund_Row=28;
	unsigned short V1_Fund_Address=0x38;	


/*-----Definition  for dsp_reg7------------------------------------*/
/* Row: 29                                                                  */
/* Address: 0x3A                                                              */
/* Name: C1_Fund[23:0]                                                      */

	unsigned short C1_Fund_Row=29;
	unsigned short C1_Fund_Address=0x3A;	


/*-----Definition  for dsp_reg8------------------------------------*/
/* Row: 30                                                                  */
/* Address: 0x3C                                                              */
/* Name: V2_Fund[23:0]                                                      */

	unsigned short V2_Fund_Row=30;
	unsigned short V2_Fund_Address=0x3C;	


/*-----Definition  for dsp_reg9------------------------------------*/
/* Row: 31                                                                  */
/* Address: 0x3E                                                              */
/* Name: C2_Fund[23:0]                                                      */

	unsigned short C2_Fund_Row=31;
	unsigned short C2_Fund_Address=0x3E;	

/*-----Definition  for dsp_reg14------------------------------------*/
/* Row: 36   
/* Address: 0x48
/* Name: C1_RMS_Data[31:16], V1_RMS_Data[15:0]  
/* MSW: C1_RMS_Data[31:16]
/* LSW: V1_RMS_Data[15:0]                                           */                             

	unsigned short C1_RMS_Data_Row=36;
	unsigned short C1_RMS_Data_Address=0x46;	

 /*-----Definition  for dsp_reg15------------------------------------*/
/* Row: 37   
/* Address: 0x48
/* Name: C2_RMS_Data[31:16], V2_RMS_Data[15:0]  
/* MSW: C2_RMS_Data[31:16]
/* LSW: V2_RMS_Data[15:0]                                           */ 

	unsigned short C2_RMS_Data_Row=37;
	unsigned short C2_RMS_Data_Address=0x48;

/*------Definition  for ph1 reg1-----------------*/
/*  Row: 42                                                         */
/*  Address: 54                                                     */
/*  Name:PH1_ Active_ Energy                                        */

	unsigned short PH1_Active_Energy_Row=0x42;
	unsigned short PH1_Active_Energy_Address=0x54;
   

/*------Definition  for ph1 reg2-----------------*/
/*  Row: 43                                                               */
/*  Address: 56                                                           */
/*  Name:PH1_Fundamental_Energy[31:0]                                            */

	unsigned short PH1_Fundamental_Energy_Row=0x43;
	unsigned short PH1_Fundamental_Energy_Address=0x56;                          

	
/*------------------------------------------------------------------------*/
    
    
/*------Definition  for ph1 reg3-----------------*/
/*  Row: 44                                                               */
/*  Address: 58                                                           */
/*  Name:PH1_Reactive_Energy
                                           */

	unsigned short PH1_Reactive_Energy_Row=0x44;
	unsigned short PH1_Reactive_Energy_Address=0x58;                          

	
/*------------------------------------------------------------------------*/
    
/*------Definition  for ph1 reg4-----------------*/
/*  Row: 45                                                               */
/*  Address: 5A                                                           */
/*  Name:PH1_Apparent_Energy                                              */

	unsigned short PH1_Apparent_Energy_Row=0x45;
	unsigned short PH1_Apparent_Energy_Address=0x5A;                          

	
/*------------------------------------------------------------------------*/
    
/*------Definition  for ph1 reg5-----------------*/
/*  Row: 46                                                               */
/*  Address: 5C                                                           */
/*  Name:PH1_Active_Power[28:0]                                           */

	unsigned short PH1_Active_Power_Row=0x46;
	unsigned short PH1_Active_Power_Address=0x5C; 
/*------------------------------------------------------------------------*/
 /*------Definition  for ph1 reg6-----------------*/
/*  Row: 47                                                               */
/*  Address: 5E                                                           */
/*  Name:PH1_Fundamental_Power[28:0]                                      */


	unsigned short PH1_Fundamental_Power_Row=0x47;
	unsigned short PH1_Fundamental_Power_Address=0x5E; 
/*------------------------------------------------------------------------*/ 
/*------Definition  for ph1 reg7-----------------*/
/*  Row: 48                                                               */
/*  Address: 60                                                           */
/*  Name:PH1_Reactive_Power[28:0]                                         */

	unsigned short PH1_Reactive_Power_Row=0x48;
	unsigned short PH1_Reactive_Power_Address=0x60; 
/*------------------------------------------------------------------------*/    
 
/*------Definition  for ph1 reg8-----------------*/
/*  Row: 49                                                               */
/*  Address: 62                                                           */
/*  Name:PH1_Apparent_RMS_Power[28:0]                                     */


	unsigned short PH1_Apparent_RMS_Power_Row=0x49;
	unsigned short PH1_Apparent_RMS_Power_Address=0x62; 
/*------------------------------------------------------------------------*/
    
/*------Definition  for ph1 reg9-----------------*/
/*  Row: 50                                                               */
/*  Address: 64                                                           */
/*  Name:PH1_Apparent_Vectorial_Power[28:0]                                   */


	unsigned short PH1_Apparent_Vectorial_Power_Row=0x50;
	unsigned short PH1_Apparent_Vectorial_Power_Address=0x64; 

/*------------------------------------------------------------------------*/
/*------Definition  for ph1 reg10-----------------------------------------*/
/*  Row: 51                                                               */
/*  Address: 66                                                           */
/*  Name:PH1_Momentary_Active_Power[28:0]                                 */


	unsigned short PH1_Momentary_Active_Power_Row=0x51;
	unsigned short PH1_Momentary_Active_Power_Address=0x66; 
/*------------------------------------------------------------------------*/

/*------Definition  for ph1 reg11-----------------------------------------*/
/*  Row: 52                                                               */
/*  Address: 68                                                           */
/*  Name:PH1_Momentary_Fundamental_Power[28:0]                             */
                                
	unsigned short PH1_Momentary_Fundamental_Power_Row=0x52;
	unsigned short PH1_Momentary_Fundamental_Power_Address=0x68; 
/*------------------------------------------------------------------------*/
 
/*------Definition  for ph1 reg12-----------------------------------------*/
/*  Row: 53                                                               */
/*  Address: 6A                                                           */
/*  Name:PH1_AH_ACC                                                       */
                            
                                
	unsigned short PH1_AH_ACC_Row=0x53;
	unsigned short PH1_AH_ACC_Address=0x6A; 
/*------------------------------------------------------------------------*/
    

    
/*------Definition  for ph2 reg1-----------------------------------------*/
/*  Row: 54                                                               */
/*  Address: 6C                                                           */
/*  Name:PH2_Active_Energy[31:0]
                                                       */
                            
                                
	unsigned short PH2_Active_Energy_Row=0x54;
	unsigned short PH2_Active_Energy_Address=0x6C; 
/*------------------------------------------------------------------------*/
 
/*------Definition  for ph2 reg2-----------------------------------------*/
/*  Row: 55                                                               */
/*  Address: 6E                                                           */
/*  Name:PH2_Fundamental_Energy[31:0]                                     */
                                                       
                            
                                
	unsigned short PH2_Fundamental_Energy_Row=0x55;
    unsigned short PH2_Fundamental_Energy_Address=0x6E; 
/*-----------------------------------------------------------------------*/
/*------Definition  for ph2 reg3-----------------------------------------*/
/*  Row: 56                                                               */
/*  Address: 70                                                           */
/*  Name:PH2_Reactive_Energy[31:0]                                        */
                                                       
                            
                                
	unsigned short PH2_Reactive_Energy_Row=0x56;
    unsigned short PH2_Reactive_Energy_Address=0x70; 
/*-----------------------------------------------------------------------*/    
/*------Definition  for ph2 reg4-----------------------------------------*/
/*  Row: 57                                                               */
/*  Address: 72                                                           */
/*  Name:PH2_Apparent_RMS_Energy[31:0]                                    */
                                                      
                            
                                
	unsigned short PH2_Apparent_RMS_Energy_Row=0x57;
    unsigned short PH2_Apparent_RMS_Energy_Address=0x72; 
/*-----------------------------------------------------------------------*/    
 
/*------Definition  for ph2 reg5-----------------------------------------*/
/*  Row: 58                                                               */
/*  Address: 74                                                           */
/*  Name:PH2_Active_Power[28:0]                                           */
                             
	unsigned short PH2_Active_Power_Row=0x58;
    unsigned short PH2_Active_Power_Address=0x74; 
/*-----------------------------------------------------------------------*/ 
    
/*------Definition  for ph2 reg6-----------------------------------------*/
/*  Row: 59                                                               */
/*  Address: 76                                                           */
/*  Name:PH2_Fundamental_Power[28:0]                                      */
                                                                                                                          
	unsigned short PH2_Fundamental_Power_Row=0x59;
    unsigned short PH2_Fundamental_Power_Address=0x76; 
/*-----------------------------------------------------------------------*/
    
/*------Definition  for ph2 reg7-----------------------------------------*/
/*  Row: 60                                                               */
/*  Address: 78                                                           */
/*  Name:PH2_Reactive_Power[28:0]                                         */
                                                                               
                              
	unsigned short PH2_Reactive_Power_Row=0x60;
    unsigned short PH2_Reactive_Power_Address=0x78; 
/*-----------------------------------------------------------------------*/   
    
/*------Definition  for ph2 reg8-----------------------------------------*/
/*  Row: 61                                                               */
/*  Address: 7A                                                           */
/*  Name:PH2_Apparent_RMS_Power[28:0}]                                    */
                                                                               
                              
	unsigned short PH2_Apparent_RMS_Power_Row=0x61;
    unsigned short PH2_Apparent_RMS_Power_Address=0x7A; 
/*-----------------------------------------------------------------------*/ 
/*------Definition  for ph2 reg9-----------------------------------------*/
/*  Row: 62                                                               */
/*  Address: 7C                                                          */
/*  Name:PH2_Apparent_Vectorial_Power[28:0]                              */
                                                                               
                              
	unsigned short PH2_Apparent_Vectorial_Power_Row=0x62;
    unsigned short PH2_Apparent_Vectorial_Power_Address=0x7C; 
/*-----------------------------------------------------------------------*/    
    
/*------Definition  for ph2 reg10-----------------------------------------*/
/*  Row: 63                                                               */
/*  Address: 7E                                                          */
/*  Name:PH2_Momentary_Active_Power[28:0]                                */
                                                                               
                              
	unsigned short PH2_Momentary_Active_Power_Row=0x63;
    unsigned short PH2_Momentary_Active_Power_Address=0x7E; 
/*-----------------------------------------------------------------------*/     
    
/*------Definition  for ph2 reg11-----------------------------------------*/
/*  Row: 64                                                               */
/*  Address: 80                                                          */
/*  Name:PH2_Momentary_Fundamental_Power[28:0]                            */
                                                                            
                            
	unsigned short PH2_Momentary_Fundamental_Power_Row=0x64;
    unsigned short PH2_Momentary_Fundamental_Power_Address=0x80; 
/*-----------------------------------------------------------------------*/
/*------Definition  for tot_reg1-----------------------------------------*/
/*  Row: 66                                                               */
/*  Address: 84                                                          */
/*  Name:Total Active Energy [31:0]                                      */
                                                                            
                            
	unsigned short Total_Active_Energy_Row=0x66;
    unsigned short Total_Active_Energy_Address=0x84; 
/*-----------------------------------------------------------------------*/ 
/*------Definition  for tot_reg2-----------------------------------------*/
/*  Row: 67                                                               */
/*  Address: 86                                                          */
/*  Name:Total Fundamental Energy [31:0]                                      */
                                                                            
                            
	unsigned short Total_Fundamental_Energy_Row=0x67;
    unsigned short Total_Fundamental_Energy_Address=0x86; 
/*-----------------------------------------------------------------------*/
    
/*------Definition  for tot_reg3-----------------------------------------*/
/*  Row: 68                                                               */
/*  Address: 88                                                          */
/*  Name:Total Reactive Energy [31:0]                                      */
                                                                            
                            
	unsigned short Total_Reactive_Energy_Row=0x68;
    unsigned short Total_Reactive_Energy_Address=0x88; 
/*-----------------------------------------------------------------------*/
    
/*------Definition  for tot_reg4-----------------------------------------*/
/*  Row: 69                                                               */
/*  Address: 8A                                                         */
/*  Name:Total Apparent Energy [31:0]                                      */
                                                                            
                            
	unsigned short Total_Apparent_Energy_Row=0x69;
    unsigned short Total_Apparent_Energy_Address=0x8A; 
/*-----------------------------------------------------------------------*/
 
/* Activate objects of configuration registers*/    
DSP_CR100bits_t DSP_CR100bits;
DSP_CR101bits_t DSP_CR101bits;
DSP_CR200bits_t DSP_CR200bits;   
DSP_CR201bits_t DSP_CR201bits;
DSP_CR400bits_t DSP_CR400bits;
US1_REG100bits_t US1_REG100bits;


   
DFE_CR101bits_t DFE_CR101bits;
DFE_CR201bits_t DFE_CR201bits;
DSP_CR300bits_t DSP_CR300bits;
DSP_CR301bits_t DSP_CR301bits;
DSP_CR400bits_t DSP_CR400bits;
DSP_CR500bits_t DSP_CR500bits;

DSP_EV1bits_t DSP_EV1bits;
/*----------------------------------------------------------------------------*/
//activate arrays of parameters structures
//parm_Reg_t parm_Reg[5];
parm_Reg_t parm_Reg;
// declare global variables
             

//uint32_t buf1[12];              //contains energy params for Channels 1&2               
//uint32_t buf2[12];              //contains energy params for Channels 3&4 
//uint32_t buf3[12];              //contains energy params for Channels 5&6 
//uint32_t buf4[12];              //contains energy params for Channels 7&8 
//uint32_t buf5[12];              //contains energy params for Channels 9&10 
/*
uint32_t buf6[52];
uint32_t buf7[52];
uint32_t buf8[52];
uint32_t buf8[52];
uint32_t buf9[52];
uint32_t buf10[52];

uint32_t Chn_Buffer1[52];           //this array comprises param froom Ch1&Ch2
uint32_t Chn_Buffer3[52];           //this array comprises param froom Ch3&Ch4
uint32_t Chn_Buffer5[52];           //this array comprises param froom Ch5&Ch6
uint32_t Chn_Buffer7[52];           //this array comprises param froom Ch7&Ch8
uint32_t Chn_Buffer9[52];           //this array comprises param froom Ch9&Ch10 */

//int *Buffer[5]={buf1,buf2,buf3,buf4,buf5};         // define an array of pointers to the channel buffers
/*
// Channels energy parameters
uint32_t *c1Data;
uint32_t *v1Data;
uint32_t *c2Data;
uint32_t *v2Data;
uint32_t *v1Fund;
uint32_t *c1Fund;
uint32_t *v2Fund;
uint32_t *c2Fund;
uint16_t *c1RMS;
uint16_t *v1RMS;
uint16_t *c2RMS;
uint16_t *v2RMS;
uint32_t *ph1ActiveEnergy;
uint32_t *ph1FundamentalEnergy;
uint32_t *ph1ReactiveEnergy;
uint32_t *ph1ApparentEnergy;
uint32_t *ph1ActivePower;
uint32_t *ph1FundamentalPower;
uint32_t *ph1ReactiveePower;
uint32_t *ph1ApparetRMSPower;
uint32_t *ph1ApparentVectorialPower;
uint32_t *ph1MomentaryActivePower;
uint32_t *ph1MomentaryFunndamentalPower;

uint32_t *ph2ActiveEnergy;
uint32_t *ph2FundamentalEnergy;
uint32_t *ph2ReactiveEnergy;
uint32_t *ph2ApparentEnergy;
uint32_t *ph2ActivePower;
uint32_t *ph2FundamentalPower;
uint32_t *ph2ReactiveePower;
uint32_t *ph2ApparetRMSPower;
uint32_t *ph2ApparentVectorialPower;
uint32_t *ph2MomentaryActivePower;
uint32_t *ph2MomentaryFunndamentalPower;

uint32_t *TotalActiveEnergy;
uint32_t *TotalFundamentalEnergy;
uint32_t *TotalReactiveEnergy;
uint32_t *TotalApparentEnergy;

// Average values for voltages and currents calibration 
uint16_t c1rms_average=0;                               //Channel 1
uint16_t v1rms_average=0;

uint16_t c2rms_average=0;                               //Channel 2
uint16_t v2rms_average=0;

uint16_t c3rms_average=0;                               //Channel 3
uint16_t v3rms_average=0;

uint16_t c4rms_average=0;                               // Channel 4
uint16_t v4rms_average=0;

uint16_t c5rms_average=0;                               //  Channel 5
uint16_t v5rms_average=0;

uint16_t c6rms_average=0;                               // Channel 6
uint16_t v6rms_average=0;

uint16_t c7rms_average=0;                               // Channel 7
uint16_t v7rms_average=0;

uint16_t c8rms_average=0;                               // Channel 8
uint16_t v8rms_average=0;

uint16_t c9rms_average=0;                               // Channel 9
uint16_t v9rms_average=0;

uint16_t c10rms_average=0;                              //Channel 10
uint16_t v10rms_average=0;

uint16_t *cxrms;
uint16_t *vxrms;
*/

unsigned int relayNum1;
unsigned int relayNum2;

uint32_t  readAdd,writeAdd;
uint32_t  dataLSB,dataMSB;
int ix;
uint32_t sendBuff[4];
char receiveBuff[4];
//char *pSrc;
uint32_t *pSrc;
uint32_t transferValue=0x00000000;
uint32_t transferValue1=0x00000000;
uint32_t transferValue2=0x00000000;
uint32_t transferValue3=0x00000000;
uint32_t receiveBuffer;
uint32_t *ptrBuffer;
char *pRcv;

int bits[16]={BIT_0,BIT_1,BIT_2,BIT_3,BIT_4,BIT_5,BIT_6,BIT_7,
              BIT_8,BIT_9,BIT_10,BIT_11,BIT_12,BIT_13,BIT_14,BIT_15};

#ifdef	__cplusplus
}
#endif



