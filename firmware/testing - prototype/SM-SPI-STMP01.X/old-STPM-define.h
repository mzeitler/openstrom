/* 
 * File:   STPM-define.h
 * Author: anton
 *
 * Upgraded on 25.July. 2016 14:53
 */


#ifdef	__cplusplus
extern "C" {
#endif
#include "STPM34_header.h"
/*-----------------------------------------------------------------------------*/
/* Parameter's Buffers for Channel-Sensors IC                                          */
    unsigned int chnBuff1=0x55;
    unsigned int chnBuff2;
/*-----------------------------------------------------------------------------*/

/*-----Definition array of structures for parameter registers----------------*/
/* Members:                                                                  */
/*      - Row;                                                               */
/*      - Address;                                                           */
/*      - dataBuffer;                                                         */
                                                          
typedef struct{
	unsigned int* dataBuffer;
	unsigned short Row;
	unsigned short Address;	
}parm_Reg_t;  
    
/*-----Definition  for dsp_reg1------------------------------------*/
/* Row: 23                                                                  */
/* Address: 0x2E                                                              */
/* Name; PH2 Period[11:0] PH1 Period[11;0]                                  */
	unsigned short Period_Row=23;
	unsigned short Period_Address=0x2E;	


 /*-----Definition  for dsp_reg2------------------------------------*/
/* Row: 24                                                                  */
/* Address: 0x30                                                              */
/* Name: V1_Data[23:0]                                                      */

	unsigned short V1_Data_Row=24;
	unsigned short V1_Data_Address=0x30;	


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
/* Address: 0x38                                                              */
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
/* Address: 0x46
/* Name: C1_RMS_Data[17:0], V1_RMS_Data[17:0]  
/* MSW: C1_RMS_Data[17:0]
/* LSW: V1_RMS_Data[17:0]

	unsigned short C2_RMS_Data_Row=36;
	unsigned short C2_RMS_Data_Address=0x46;	

 /*-----Definition  for dsp_reg15------------------------------------*/
/* Row: 37   
/* Address: 0x48
/* Name: C2_RMS_Data[17:0], V2_RMS_Data[17:0]  
/* MSW: C2_RMS_Data[17:0]
/* LSW: V2_RMS_Data[17:0]

	unsigned short C2_RMS_Data_Row=37;
	unsigned short C2_RMS_Data_Address=0x48;

/*------Definition  for ph1 reg1-----------------*/
/*  Row: 42                                                               */
/*  Address: 54                                                           */
/*  Name:PH1_ Active_ Energy                                 */

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
 
/* Activate objects of configuration registers*/    
DSP_CR100bits_t DSP_CR100bits;
DSP_CR101bits_t DSP_CR101bits;
DSP_CR200bits_t DSP_CR200bits;   
DSP_CR201bits_t DSP_CR201bits;
  
DFE_CR101bits_t DFE_CR101bits;
DFE_CR201bits_t DFE_CR201bits;
DSP_CR301bits_t DSP_CR301bits;
DSP_CR400bits_t DSP_CR400bits; 
DSP_CR500bits_t DSP_CR500bits;
/*----------------------------------------------------------------------------*/
//activate arrays of parameters structures
parm_Reg_t parm_Reg[10];
// declare global variables
unsigned int Chn_Buffer1[100];
unsigned int Chn_Buffer2[100];
unsigned int Chn_Buffer3[100];
unsigned int Chn_Buffer4[100];
unsigned int Chn_Buffer5[100];
unsigned int Chn_Buffer6[100];
unsigned int Chn_Buffer7[100];
unsigned int Chn_Buffer8[100];
unsigned int Chn_Buffer9[100];
unsigned int Chn_Buffer10[100];

char readAdd,writeAdd;
char dataLSB,dataMSB;
int ix;
char sendBuff[4];
char *pSrc;

int bits[16]={BIT_0,BIT_1,BIT_2,BIT_3,BIT_4,BIT_5,BIT_6,BIT_7,
              BIT_8,BIT_9,BIT_10,BIT_11,BIT_12,BIT_13,BIT_14,BIT_15};

#ifdef	__cplusplus
}
#endif



