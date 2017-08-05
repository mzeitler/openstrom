// Include file for Microchip MRF24J40 802.15.4 radio hardware
// New parts (c) 2010-2012 nerdfever.com
// Originally based on Microchip MiWi DE v.3.1.3, 5/28/2010 (c) Microchip

#include "system_definitions.h"
#include "delay.h"
#if !defined(_MRF24J40_H_)
#define _MRF24J40_H_

// radio config 

#define ONE_SECOND (SYS_CLK_FREQ/2)						// 1s of PIC32 core timer ticks (== Hz)
#define MS_TO_CORE_TICKS(x) ((uint64_t)(x)*ONE_SECOND/1000)
#define CT_TICKS_SINCE(tick) (READ_CORE_TIMER() - (tick)) // number of core timer ticks since "tick"


#define	MRF24J40_TIMEOUT_TICKS	MS_TO_CORE_TICKS(19)	// reset radio hardware if no TX_BUSY stays true this long - PLL lock lost or other serious problem

#define PACKET_BUFFERS (2)								// radio RX packet buffers.  Must be a power of 2.
//#define TURBO_MODE									// propriatary MCHP modulation; up to 625 Kbps (less range tho) 
#define ENABLE_PA_LNA									// for range on MB board

// hw setup

#if defined(ENABLE_PA_LNA)
//	MB (high power) board has SiGe PA2423L, gain is nominally +22.5 dBm with 45% power-added efficiency
//	For use in USA, set output power set to be -1.9dB with 0x18 (FCC limit is 100 mW)
//	For use in Europe (and to be safe, elsewhere) set at -14.9dB with 0x70 (EU limit is 10 mW)
	#define TX_POWER			(0x18)		// use 0x18 for USA, 0x70 for Europe (and elsewhere, to be safe); uses SiGe PA2423L power amp
	#define FULL_CHANNEL_MAP    0x03FFF800	// 0b0000 0011 1111 1111 1111 1000 0000 0000 = bits 11 to 25 (for higher power MB module)
#else
	#define TX_POWER			(0x00)		// power level to be 0dBms
	#define FULL_CHANNEL_MAP	0x07FFF800	// 0b0000 0111 1111 1111 1111 1000 0000 0000 = bits 11 to 26 (for MA module)
#endif

#define RX_BUFFER_SIZE 	(144)				// 144 bytes per MRF24J40 data sheet figure 2-6
#define TX_FIFO_SIZE	(128)				// size of TX FIFO buffer in radio hardware
#define TX_PAYLOAD_SIZE (103)				// max app payload size, bytes
#define RX_PAYLOAD_SIZE (TX_PAYLOAD_SIZE)

// typedefs

typedef union					// interrupt mask for radio
{
	uint8_t Val;
	struct
	{
		uint8_t TXIF 			:1; // transmission finished interrupt (TX no longer busy)
		uint8_t 				:2;
		uint8_t RXIF 			:1; // received a packet interrupt
		uint8_t SECIF           :1;	// received a secured packet interrupt
		uint8_t 				:4;
	} bits;
} MRF24J40_IFREG;

typedef struct									// radio state
{
	uint8_t 	TX_BUSY			:1;					// transmitter is busy.  Set when TX triggered, reset by TX ISR.
	uint8_t 	TX_PENDING_ACK  :1; 				// we are currently waiting for an ack (don't know yet if we'll get one)
	uint8_t 	TX_FAIL         :1;					// last packet sent failed
	uint8_t 	TX_RETRIES		:2;					// number of tx retries of last sent packet
	uint8_t 	TX_CCAFAIL		:1;					// tells if last tx failed due to channel too busy
	uint8_t 	SLEEPING		:1;					// tells if radio is asleep now
	uint8_t 	volatile RXWriteBuffer;				// buffer number to write to in ISR (modified by ISR)
	uint8_t 	RXReadBuffer;						// buffer number to read from
	uint8_t     volatile RXPacketCount;				// number of buffers waiting to be read (modified by ISR)
	uint8_t 	IEEESeqNum;							// tx packet sequence number (initial value not important)
	uint8_t 	Channel;							// current radio channel
	uint16_t 	MyShortAddress;						// short (2 byte) address
	uint64_t    MyLongAddress;						// long (8 byte, MAC) address
	uint16_t 	MyPANID;							// PANID (2 bytes)
	uint32_t	ResetCount;							// count of times hardware has been reset
	uint32_t	LastTXTriggerTick;					// tick at which we triggered the last TX packet to go out
	// error statistics
	uint16_t	RXSecurityEnabled;					// number of packets RX's with security bit set (had to discard)
	uint16_t	RadioExtraDiscard;					// number of times we attempted to discard a packet that wasn't there (error)
	uint16_t	RXPacketTooBig;						// number of times we truncated a RX'ed packet that didn't fit in buffer
	uint16_t	RXBufferOverruns;					// number of times the RX buffer overran (because we didn't empty it fast enough)
} MRF24J40_STATUS;

typedef struct							
{
	// note that the 1st 4 bytes of this structure are identical to the 1st 4 bytes of the RX FIFO contents

	uint8_t		frameLength;			// bytes (m+n, per 802.15.4)  Does not count itself, 2 bytes of FCS, 1 of LQI, or 1 of RSSI.
	unsigned	frameType		:3;		// per Table 79
	unsigned	securityEnabled	:1;		// per Figure 42
	unsigned	framePending 	:1;		// per Figure 42
	unsigned	ackRequest		:1;		// per Figure 42
	unsigned	panIDcomp		:1;		// per Figure 42
	unsigned					:3;		// reserved bits in 802.15.4
	unsigned	dstAddrMode		:2;		// per Table 80
	unsigned	frameVersion	:2;		// per Figure 42
	unsigned	srcAddrMode		:2;		// per Table 80
	uint8_t		frameNumber;			// packet sequence number

	// from here down is NOT (necessarily) identical to FIFO contents

	uint16_t		dstPANID;
	uint64_t		dstAddr;				// only 1st 2 bytes used if short addr
	uint16_t		srcPANID;
	uint64_t		srcAddr;				// only 1st 2 bytes used if short addr
	
	uint8_t		payloadLength;			// length of payload field
	uint8_t *		payload;				// points at payload start
	uint8_t       lqi;					// LQI value for the received packet
	uint8_t       rssi;					// RSSI value for the received packet
} PACKET;


// function prototypes

bool   RadioInit(void);
void   RadioSetAddress(uint16_t shortAddress, uint64_t longAddress, uint16_t panID);
bool   RadioSetChannel(uint8_t channel);
void   RadioSetSleep(uint8_t powerState);
uint8_t  RadioEnergyDetect(void);
void   RadioTXRaw(void);
void   RadioTXPacket(void);
uint8_t  RadioRXPacket(void);
uint8_t  RadioTXResult(void);
uint8_t  RadioWaitTXResult(void);
void   RadioDiscardPacket(void);

// public variables

extern MRF24J40_STATUS volatile RadioStatus;						// radio state
extern PACKET Tx;													// description of packet to be transmitted
extern PACKET Rx;													// description of received packet (after parsing)
extern uint8_t volatile RXBuffer[PACKET_BUFFERS][RX_BUFFER_SIZE];		// rx packet buffer

// Symbols

	// note these have the same values as Frame Types in Table 79 of 802.15.4-2006
#define PACKET_TYPE_BEACON     				0b000
#define PACKET_TYPE_DATA        			0b001
#define PACKET_TYPE_ACK         			0b010
#define PACKET_TYPE_COMMAND     			0b011

	// source and dest. addrsesing modes, IEEE 802.15.4-2006 Table 80
#define NO_ADDR_FIELD		(0)	// 00 PAN identifier and address fields are not present.
								// 01 Reserved.
#define SHORT_ADDR_FIELD	(2)	// 10 Address field contains a 16-bit short address.
#define LONG_ADDR_FIELD		(3)	// 11 Address field contains a 64-bit extended address.

#define TX_RESULT_BUSY	(0)
#define TX_RESULT_SUCCESS (1)
#define TX_RESULT_FAILED (TX_RESULT_SUCCESS+1)

// MRF24J40 hardware regsiter defintions - most of these names are from MiWi DE v3.1.3, and don't
// necessarily match the register names in the datasheet (I've fixed a few)

//long address registers
#define RFCTRL0 (0x200)
#define RFCTRL1 (0x201)
#define RFCTRL2 (0x202)
#define RFCTRL3 (0x203)
#define RFCTRL4 (0x204)
#define RFCTRL5 (0x205)
#define RFCTRL6 (0x206)
#define RFCTRL7 (0x207)
#define RFCTRL8 (0x208)
#define CAL1 (0x209)
#define CAL2 (0x20a)
#define CAL3 (0x20b)
#define SFCNTRH (0x20c)
#define SFCNTRM (0x20d)
#define SFCNTRL (0x20e)
#define RFSTATE (0x20f)
#define RSSI (0x210)
#define CLKIRQCR (0x211)
#define SRCADRMODE (0x212)
#define SRCADDR0 (0x213)
#define SRCADDR1 (0x214)
#define SRCADDR2 (0x215)
#define SRCADDR3 (0x216)
#define SRCADDR4 (0x217)
#define SRCADDR5 (0x218)
#define SRCADDR6 (0x219)
#define SRCADDR7 (0x21a)
#define RXFRAMESTATE (0x21b)
#define SECSTATUS (0x21c)
#define STCCMP (0x21d)
#define HLEN (0x21e)
#define FLEN (0x21f)
#define SCLKDIV (0x220)
//#define reserved (0x221)
#define WAKETIMEL (0x222)
#define WAKETIMEH (0x223)
#define TXREMCNTL (0x224)
#define TXREMCNTH (0x225)
#define TXMAINCNTL (0x226)
#define TXMAINCNTM (0x227)
#define TXMAINCNTH0 (0x228)
#define TXMAINCNTH1 (0x229)
#define RFMANUALCTRLEN (0x22a)
#define RFMANUALCTRL (0x22b)
#define RFRXCTRL RFMANUALCTRL
#define TxDACMANUALCTRL (0x22c)
#define RFMANUALCTRL2 (0x22d)
#define TESTRSSI (0x22e)
#define TESTMODE (0x22f)

#define NORMAL_TX_FIFO  (0x000)
#define BEACON_TX_FIFO  (0x080)
#define GTS1_TX_FIFO    (0x100)
#define GTS2_TX_FIFO    (0x180)
#define SECURITY_FIFO   (0x280)
#define RX_FIFO         (0x300)

//short address registers for reading
#define READ_PANIDL (0x02)
#define READ_PANIDH (0x04)
#define READ_SADRL (0x06)
#define READ_SADRH (0x08)
#define READ_EADR0 (0x0A)
#define READ_EADR1 (0x0C)
#define READ_EADR2 (0x0E)
#define READ_EADR3 (0x10)
#define READ_EADR4 (0x12)
#define READ_EADR5 (0x14)
#define READ_EADR6 (0x16)
#define READ_EADR7 (0x18)
#define READ_RXFLUSH (0x1a)
#define READ_TXSTATE0 (0x1c)
#define READ_TXSTATE1 (0x1e)
#define READ_ORDER (0x20)
#define READ_TXMCR (0x22)
#define READ_ACKTMOUT (0x24)
#define READ_SLALLOC (0x26)
#define READ_SYMTICKL (0x28)
#define READ_SYMTICKH (0x2A)
#define READ_PAONTIME (0x2C)
#define READ_PAONSETUP (0x2E)
#define READ_FFOEN (0x30)
#define READ_CSMACR (0x32)
#define READ_TXBCNTRIG (0x34)
#define READ_TXNMTRIG (0x36)
#define READ_TXG1TRIG (0x38)
#define READ_TXG2TRIG (0x3A)
#define READ_ESLOTG23 (0x3C)
#define READ_ESLOTG45 (0x3E)
#define READ_ESLOTG67 (0x40)
#define READ_TXPEND (0x42)
#define READ_WAKECON (0x44)
#define READ_FRMOFFSET (0x46)
#define READ_TXSR (0x48)
#define READ_TXLERR (0x4A)
#define READ_GATE_CLK (0x4C)
#define READ_TXOFFSET (0x4E)
#define READ_HSYMTMR0 (0x50)
#define READ_HSYMTMR1 (0x52)
#define READ_SOFTRST (0x54)
#define READ_BISTCR (0x56)
#define READ_SECCR0 (0x58)
#define READ_SECCR1 (0x5A)
#define READ_TXPEMISP (0x5C)
#define READ_SECISR (0x5E)
#define READ_RXSR (0x60)
#define READ_ISRSTS (0x62)
#define READ_INTMSK (0x64)
#define READ_GPIO (0x66)
#define READ_GPIODIR (0x68)
#define READ_SLPACK (0x6A)
#define READ_RFCTL (0x6C)
#define READ_SECCR2 (0x6E)
#define READ_BBREG0 (0x70)
#define READ_BBREG1 (0x72)
#define READ_BBREG2 (0x74)
#define READ_BBREG3 (0x76)
#define READ_BBREG4 (0x78)
#define READ_BBREG5 (0x7A)
#define READ_BBREG6 (0x7C)
#define READ_RSSITHCCA (0x7E)

// short address registers for writing
// note these are the register address << 1, +1 (to include the write bit at the end of the sequence)

#define WRITE_PANIDL (0x03)
#define WRITE_PANIDH (0x05)
#define WRITE_SADRL (0x07)
#define WRITE_SADRH (0x09)
#define WRITE_EADR0 (0x0B)
#define WRITE_EADR1 (0x0D)
#define WRITE_EADR2 (0x0F)
#define WRITE_EADR3 (0x11)
#define WRITE_EADR4 (0x13)
#define WRITE_EADR5 (0x15)
#define WRITE_EADR6 (0x17)
#define WRITE_EADR7 (0x19)
#define WRITE_RXFLUSH (0x1B)
#define WRITE_TXSTATE0 (0x1D)
#define WRITE_TXSTATE1 (0x1F)
#define WRITE_ORDER (0x21)
#define WRITE_TXMCR (0x23)
#define WRITE_ACKTMOUT (0x25)
#define WRITE_SLALLOC (0x27)
#define WRITE_SYMTICKL (0x29)
#define WRITE_SYMTICKH (0x2B)
#define WRITE_PAONTIME (0x2D)
#define WRITE_PAONSETUP (0x2F)
#define WRITE_FFOEN (0x31)
#define WRITE_CSMACR (0x33)
#define WRITE_TXBCNTRIG (0x35)
#define WRITE_TXNMTRIG (0x37)
#define WRITE_TXG1TRIG (0x39)
#define WRITE_TXG2TRIG (0x3B)
#define WRITE_ESLOTG23 (0x3D)
#define WRITE_ESLOTG45 (0x3F)
#define WRITE_ESLOTG67 (0x41)
#define WRITE_TXPEND (0x43)
#define WRITE_WAKECON (0x45)
#define WRITE_FRMOFFSET (0x47)
#define WRITE_TXSR (0x49)
#define WRITE_TXLERR (0x4B)
#define WRITE_GATE_CLK (0x4D)
#define WRITE_TXOFFSET (0x4F)
#define WRITE_HSYMTMR0 (0x51)
#define WRITE_HSYMTMR1 (0x53)
#define WRITE_SOFTRST (0x55)
#define WRITE_BISTCR (0x57)
#define WRITE_SECCR0 (0x59)
#define WRITE_SECCR1 (0x5B)
#define WRITE_TXPEMISP (0x5D)
#define WRITE_SECISR (0x5F)
#define WRITE_RXSR (0x61)
#define WRITE_ISRSTS (0x63)
#define WRITE_INTMSK (0x65)
#define WRITE_GPIO (0x67)
#define WRITE_GPIODIR (0x69)
#define WRITE_SLPACK (0x6B)
#define WRITE_RFCTL (0x6D)
#define WRITE_SECCR2 (0x6F)
#define WRITE_BBREG0 (0x71)
#define WRITE_BBREG1 (0x73)
#define WRITE_BBREG2 (0x75)
#define WRITE_BBREG3 (0x77)
#define WRITE_BBREG4 (0x79)
#define WRITE_BBREG5 (0x7B)
#define WRITE_BBREG6 (0x7D)
#define WRITE_RSSITHCCA (0x7F)

#endif	// #if !defined(_MRF24J40_H_)

