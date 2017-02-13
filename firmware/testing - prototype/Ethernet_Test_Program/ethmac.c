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
 * This file ethmac.c represents the MAC layer source file
 * of the UDP/IP stack.
 *
 * Author : Marco Russi
 *
 * Evolution of the file:
 * 10/08/2015 - File created - Marco Russi
 *
*/


/*
TODO LIST:
    1)  implement the Pattern match filter feature: see setPatternMatchRXFilter() function
    2)  only one TX buffer is used at the moment!
        see ETHMAC_getTXBufferPointer function and ETHMAC_UC_TX_NUM_OF_BUFFERS define
    3)  implement a watermark reached interrupt management if necessary: see FLOW_CTRL_RX_BUFF_FULL define
    4)  check the ETHSTAT register to see transfer result in sendPacket function
    5)  check a 32-bit alignment for RX buffer allocation
    6)  implement a de-init function to free TX and RX buffers
    7)  in ETHMAC_Init function, set bInitSuccess flag according to other results also
*/




/* ----------------- Inclusions files ----------------- */
#include <xc.h>
#include <sys/attribs.h>

#include "p32mx795f512h.h"
#include "fw_common.h"

#include "ethmac.h"




/* ---------------------- Local defines -------------------- */

/* if uncomment, configure MAC as loopback. If comment, lopback is disabled */
//#define CONFIGURE_MAC_LOOPBACK

/* if uncomment, use SW defined MAC address. If comment, use the device defined one */
//#define USE_SW_MAC_ADDRESS

#ifdef USE_SW_MAC_ADDRESS
/* SW defined MAC address */
#define ULL_SW_MAC_ADDRESS          ((uint64)0x0000218956435612)
#endif

/* this value is related to ETHMAC_st_DataDcpt struct; 2 descriptors used for each TX buffer */
#define UC_NUM_OF_TX_DCPT                   ((uint8)(ETHMAC_UC_TX_NUM_OF_BUFFERS * UC_2))

/* num of RX descriptors */
#define UC_NUM_OF_RX_DCPT                   (ETHMAC_UC_RX_NUM_OF_BUFFERS)

/* length of each buffer in bytes (Minimum length in octects of datagrams to receive) */
#define US_DATA_BUFFER_LENGTH               (576)

/* Back to back inter-packet gap defined as default register value */
#define BB_INTERPACKET_GAP_VALUE            0x15

/* Non back to back inter-packet gap defined as default register value */
#define NBB_INTERPACKET_GAP_VALUE1          0xC
#define NBB_INTERPACKET_GAP_VALUE2          0x12

/* Collision window defined as default register value */
#define COLLISION_WINDOW_VALUE              0x37

/* Number of retransmission defined as default register value */
#define NUM_OF_RETX_VALUE                   0xF

/* Maximum MAC supported RX frame size.
   Any incoming ETH frame that's longer than this size will be discarded.
   The default value is 1536 (allows for VLAN tagged frames, although the VLAN tagged frames are discarded).
   Normally there's no need to touch this value unless you know exactly the maximum size of the frames
   you want to process or you need to control packets fragmentation (together with the EMAC_RX_BUFF_SIZE.
   Note: Always multiple of 16. */
#define MAC_RX_MAX_FRAME                    1536

/* Flow control  */
#define FLOW_CTRL_PTV                       16

/* Flow control RX buffer full. Should be greater than FLOW_CTRL_RX_BUFF_EMPTY */
/* ATTENTION: this value should be equal to or lower than UC_NUM_OF_RX_DCPT */
#define FLOW_CTRL_RX_BUFF_FULL              (6)
/* value check */
#if FLOW_CTRL_RX_BUFF_FULL > UC_NUM_OF_RX_DCPT
#error FLOW_CTRL_RX_BUFF_FULL define is greater than UC_NUM_OF_RX_DCPT
#endif

/* Flow control RX buffer empty. Should be lower than FLOW_CTRL_RX_BUFF_FULL */
#define FLOW_CTRL_RX_BUFF_EMPTY             0x00

/* ETH internet priority value */
#define ETH_PRIORITY                        5
#define ETH_SUB_PRIORITY                    2


/* ETHCON1 register */
#define ETHCON_PTV_BIT_POS                  16
#define ETHCON_ON_BIT_POS                   15
#define ETHCON_TXRTS_BIT_POS                9
#define ETHCON_RXEN_BIT_POS                 8
#define ETHCON_AUTOFC_BIT_POS               7
#define ETHCON_MANFC_BIT_POS                4
#define ETHCON_BUFCDEC_BIT_POS              0

/* ETHCON2 register */
#define ETHCON2_RXBUFSZ_BIT_POS             4

/* EMAC1CFG1 register */
#define EMAC1_SOFTRESET_BIT_POS             15
#define LOOPBACK_BIT_POS                    4
#define TXPAUSE_BIT_POS                     3
#define RXPAUSE_BIT_POS                     2
#define RXENABLE_BIT_POS                    0

/* EMAC1CFG2 register */
#define EXCESSDER_BIT_POS                   14
#define BPNOBKOFF_BIT_POS                   13
#define NOBKOFF_BIT_POS                     12
#define LONGPRE_BIT_POS                     9
#define PUREPRE_BIT_POS                     8
#define AUTOPAD_BIT_POS                     7
#define VLANPAD_BIT_POS                     6
#define PADENABLE_BIT_POS                   5
#define CRCENABLE_BIT_POS                   4
#define DELAYCRC_BIT_POS                    3
#define HUGEFRM_BIT_POS                     2
#define LENGTHCK_BIT_POS                    1
#define FULLDPLX_BIT_POS                    0

/* EMAC1IPGR register */
#define NB2BIPKTGP1_BIT_POS                 8
#define NB2BIPKTGP2_BIT_POS                 0

/* EMAC1CLRT register */
#define CWINDOW_BIT_POS                     8
#define RETX_BIT_POS                        0

/* ETHSTAT register */
#define ETHSTAT_BUFCNT_BIT_POS              16
#define ETHSTAT_BUSY_BIT_POS                7

/* ETHIRQ register */
#define ETHIRQ_TXBUSE_BIT_POS               14
#define ETHIRQ_RXBUSE_BIT_POS               13
#define ETHIRQ_FWMARK_BIT_POS               8
#define ETHIRQ_RXDONE_BIT_POS               7
#define ETHIRQ_TXDONE_BIT_POS               3
#define ETHIRQ_RXOVFLW_BIT_POS              0

/* ETHRXFC register */
#define ETHRXFC_NOTPM_BIT_POS               12
#define ETHRXFC_PMMODE_BIT_POS              8
#define ETHRXFC_CRCERREN_BIT_POS            7
#define ETHRXFC_CRCOKEN_BIT_POS             6
#define ETHRXFC_RUNTEN_BIT_POS              4
#define ETHRXFC_UCEN_BIT_POS                3
#define ETHRXFC_NOTMEEN_BIT_POS             2
#define ETHRXFC_MCEN_BIT_POS                1
#define ETHRXFC_BCEN_BIT_POS                0

/* ETHRXWM register */
#define ETHRXWM_RXFWM_BIT_POS               16
#define ETHRXWM_RXEWM_BIT_POS               0

/* ETHIEN register */
#define TXBUSEIE_BIT_POS                    14
#define RXBUSEIE_BIT_POS                    13
#define EWMARKIE_BIT_POS                    9
#define FWMARKIE_BIT_POS                    8
#define RXDONEIE_BIT_POS                    7
#define PKTPENDIE_BIT_POS                   6
#define RXACTIE_BIT_POS                     5
#define TXDONEIE_BIT_POS                    3
#define TXABORTIE_BIT_POS                   2
#define RXBUFNAIE_BIT_POS                   1
#define RXOVFLWIE_BIT_POS                   0

/* IEC1 interrupt control register */
#define ETHIE_BIT_POS                       28

/* IFS1 interrupt flag register */
#define ETHIF_BIT_POS                       28

/* IPC12 interrupt priority register */
#define ETHPRI_BIT_POS                      2
#define ETHSUBPRI_BIT_POS                   0




/* ---------------- Local enums declaration -------------- */

/* RX filter pattern match mode */
typedef enum
{
    MATCH_DISABLED,                 /* Disabled, pattern match is always unsuccessful */
    NOTPM_XOR_CKS,                  /* NOTPM = 1 XOR Pattern Match Checksum matches */
    NOTPM_XOR_CKS_AND_STAT_ADD,     /* (NOTPM = 1 XOR Pattern Match Checksum matches) AND Destination Address = Station Address */
    NOTPM_XOR_CKS_AND_UNIC_ADD,     /* (NOTPM = 1 XOR Pattern Match Checksum matches) AND Destination Address = Unicast Address */
    NOTPM_XOR_CKS_AND_BROAD_ADD,    /* (NOTPM = 1 XOR Pattern Match Checksum matches) AND Destination Address = Broadcast Address */
    NOTPM_XOR_CKS_AND_HASHT_ADD,    /* (NOTPM = 1 XOR Pattern Match Checksum matches) AND Hash Table filter match */
    NOTPM_XOR_CKS_AND_MAGIC_ADD     /* (NOTPM = 1 XOR Pattern Match Checksum matches) AND Packet = Magic Packet */
} KE_FILTER_MATCH_MODE;




/* --------------- Local structs defines -------------- */

/* Ethernet TX buffer descriptor */
typedef struct
{
    volatile union
    {
        struct
        {
            unsigned: 7;
            unsigned EOWN: 1;
            unsigned NPV: 1;
            unsigned: 7;
            unsigned bCount: 11;
            unsigned: 3;
            unsigned EOP: 1;
            unsigned SOP: 1;
        };
        unsigned int w;
    }hdr;
    unsigned char* pEDBuff;
    volatile unsigned long long stat;
    unsigned int next_ed;
}__attribute__ ((__packed__)) st_TXEthDcpt;


/* Ethernet RX buffer descriptor */
typedef struct
{
    volatile union
    {
        struct
        {
            unsigned: 7;
            unsigned EOWN: 1;
            unsigned NPV: 1;
            unsigned: 7;
            unsigned bCount: 11;
            unsigned: 3;
            unsigned EOP: 1;
            unsigned SOP: 1;
        }flags;
        unsigned int w;
    }hdr;
    unsigned char* pEDBuff;
    volatile union
    {
        struct
        {
            unsigned PKT_Checksum: 16;
            unsigned: 8;
            unsigned RXF_RSV: 8;
            unsigned RSV: 32;
        }rxstat;
        unsigned long long s;
    }stat;
    unsigned int next_ed;
}__attribute__ ((__packed__)) st_RXEthDcpt;




/* -------------- Local macros declaration ----------- */

/* peripheral hardware macros */
#define ENABLE_ETH_INT()            (IEC1SET = (1 << ETHIE_BIT_POS))
#define DISABLE_ETH_INT()           (IEC1CLR = (1 << ETHIE_BIT_POS))
#define CLEAR_ETH_INT_FLAG()        (IFS1CLR = (1 << ETHIF_BIT_POS))
#define ENABLE_ETH_MODULE()         (ETHCON1SET = (1 << ETHCON_ON_BIT_POS))
#define DISABLE_ETH_MODULE()        (ETHCON1CLR = (1 << ETHCON_ON_BIT_POS))
#define CHECK_ETH_IS_BUSY()         ((ETHSTAT & (1 << ETHSTAT_BUSY_BIT_POS)) > 0)
#define CHECK_TX_IS_DONE()          ((ETHCON1 & (1 << ETHCON_TXRTS_BIT_POS)) > 0)

/* Ethernet datagram related set macros */
#define SET_ETHERTYPE(x,y)          ((x) = SWAP_BYTES_ORDER_16BIT_(y))




/* ----------- Exported variables declaration ------------ */

/* MAC address of this device */
EXPORTED uint64 ETHMAC_ui64MACAddress;




/* --------------- Local variables declaration ------------ */

/* TX descriptors data buffers */
LOCAL uint8 *apui8TXDcptDataBuffers[(UC_NUM_OF_TX_DCPT / 2)];

/* RX descriptors data buffers */
LOCAL uint8 *apui8RXDcptDataBuffers[UC_NUM_OF_RX_DCPT];

/* Descriptors array */
LOCAL st_TXEthDcpt stTXArrayDcpt[UC_NUM_OF_TX_DCPT];
LOCAL st_RXEthDcpt stRXArrayDcpt[UC_NUM_OF_RX_DCPT];

/* RX descriptors counter. Used by ETHMAC_getNextRXDataBuffer function */
LOCAL uint8 ui8RXDcptCount;

/* RX current descriptor pointer. Used by ETHMAC_getNextRXDataBuffer function */
LOCAL st_RXEthDcpt *stRXCurrEthDcpt;

/* Pending RX descriptor to clear flag. Used by ETHMAC_getNextRXDataBuffer function */
LOCAL boolean bPrevPending;




/* --------------- Local functions prototypes ---------------- */

LOCAL void setDestMACAddress        (uint8 *, uint64);
LOCAL void setSrcMACAddress         (uint8 *, uint64);
LOCAL void sendPacket               (uint8 **, uint16 *, uint16);
LOCAL void setRXPacket              (uint8 **, uint16, uint16);
LOCAL void resetEthController       (void);
LOCAL void resetMACModule           (void);
LOCAL void configureMACModule       (void);
LOCAL void initEthController        (void);
LOCAL void setPatternMatchRXFilter  (KE_FILTER_MATCH_MODE, uint64, uint16, uint16, boolean);




/* ------------- Exported functions implementation -------------------- */

/* Init ETHMAC module */
/* TODO: set bInitSuccess flag according to other results also */
EXPORTED boolean ETHMAC_Init( void )
{
    uint8 ui8BuffCount;
    boolean bInitSuccess;
    boolean bPHYInitSuccess = B_FALSE;

    /* init all RX descriptors buffers */
    for(ui8BuffCount = UC_NULL; ui8BuffCount < UC_NUM_OF_RX_DCPT; ui8BuffCount++)
    {
        /* ATTENTION: it is necessary that IP header is always 32-bit aligned:
         * the 2 bytes are added in order to occupy 16 bytes with a 14-byte header,
         * the first 2 bytes are wasted */
        apui8RXDcptDataBuffers[ui8BuffCount] = (uint8 *)MEM_MALLOC(US_DATA_BUFFER_LENGTH + UC_2) + UC_2;
    }

    /* init all TX descriptors buffers */
    for(ui8BuffCount = UC_NULL; ui8BuffCount < (UC_NUM_OF_TX_DCPT / 2); ui8BuffCount++)
    {
        apui8TXDcptDataBuffers[ui8BuffCount] = (uint8 *)MEM_MALLOC(US_DATA_BUFFER_LENGTH);
        ALIGN_32BIT_OF_8BIT_PTR(apui8TXDcptDataBuffers[ui8BuffCount]);
        apui8TXDcptDataBuffers[ui8BuffCount] += (US_DATA_BUFFER_LENGTH - US_1);
    }

    /* no pending RX descriptors to clear */
    bPrevPending = B_FALSE;
    
    /* --- Ethernet controller reset --- */
    resetEthController();
    ENABLE_ETH_MODULE();

    /* --- MAC module reset --- */
    resetMACModule();
    
    /* enable ETH module */
    /* ATTENTION: the ETH module should be turn on before any PHY operation */
    ENABLE_ETH_MODULE();

    /* --- EXT PHY module initialization --- */
    bPHYInitSuccess = ETHPHY_Init();

    /* if external PHY init is success */
    if(B_TRUE == bPHYInitSuccess)
    {
        /* go on to config MAC and init ethernet controller */

        /* --- MAC module configuration --- */
        configureMACModule();

        /* --- Ethernet controller initialisation --- */
        initEthController();

        /* init success */
        bInitSuccess = B_TRUE;
    }
    else
    {
        /* init fail */
        bInitSuccess = B_FALSE;
    }

    return bInitSuccess;
}


/* Function to get next received data pointer */
EXPORTED uint8 * ETHMAC_getNextRXDataBuffer( void )
{
    uint8 *pui8DataBufPtr = NULL;

    if(bPrevPending == B_TRUE)
    {
        /* restore previous descriptor */
        stRXCurrEthDcpt->hdr.w = 0;           /* clear all the fields */
        stRXCurrEthDcpt->hdr.flags.NPV = 1;   /* set next pointer valid */
        stRXCurrEthDcpt->hdr.flags.EOWN = 1;  /* set hardware ownership */
        stRXCurrEthDcpt->stat.s = 0;          /* clear stat field */

        /* decrement received packet buffer count */
        ETHCON1SET = (1 << ETHCON_BUFCDEC_BIT_POS);

        bPrevPending = B_FALSE;
    }
    else
    {
        /* if first call then start from first descriptor */
        ui8RXDcptCount = UC_NUM_OF_RX_DCPT;
        stRXCurrEthDcpt = &stRXArrayDcpt[US_NULL];
    }
    
    /* get next pointer */
    while((ui8RXDcptCount > UC_NULL)
    &&    (stRXCurrEthDcpt->hdr.flags.EOWN == 1))
    {
        /* decrement descriptor counter */
        ui8RXDcptCount--;
        /* next descriptor */
        stRXCurrEthDcpt++;
    }

    /* end of list reached */
    if(ui8RXDcptCount == UC_NULL)
    {
        /* pointer is NULL */
        pui8DataBufPtr = NULL;
    }
    else
    {
        /* check if SW ownership */
        if(stRXCurrEthDcpt->hdr.flags.EOWN == 0)
        {
            /* get buffer pinter */
            pui8DataBufPtr = (uint8 *)PA_TO_KVA1((uint32)stRXCurrEthDcpt->pEDBuff);

            bPrevPending = B_TRUE;
        }
        else
        {
            /* pointer is NULL */
            pui8DataBufPtr = NULL;
        }
    }

    return pui8DataBufPtr;
}


/* send packet. Data buffers have been previously saved into the shared ETHMAC_stTXDataBuffer structure */
EXPORTED void ETHMAC_sendPacket( uint8 *pui8FramePtr, uint16 ui16DataLength, uint64 ui64HWSrcAdd, uint64 ui64HWDstAdd, uint16 ui16EthType )
{
    uint8 aui8EthernetHeader[ETHMAC_UC_ETH_HDR_LENGTH];
    uint8 *apui8PtrsArray[UC_2];
    uint16 aui16LengthArray[UC_2];

    /* set ETH addresses and type */
    setDestMACAddress(&aui8EthernetHeader[UC_0], ui64HWDstAdd);
    setSrcMACAddress(&aui8EthernetHeader[ETHMAC_UC_ETH_ADD_LENGTH], ui64HWSrcAdd);
    /* set ethernet type */
    SET_ETHERTYPE(*((uint16 *)(&aui8EthernetHeader[(UC_2 * ETHMAC_UC_ETH_ADD_LENGTH)])), ui16EthType);

    /* 1 TX descriptor for the ethernet header */
    apui8PtrsArray[UC_0] = aui8EthernetHeader;
    aui16LengthArray[UC_0] = ETHMAC_UC_ETH_HDR_LENGTH;
    
    /* 1 TX descriptor for the rest of the packet */
    apui8PtrsArray[UC_1] = pui8FramePtr;
    aui16LengthArray[UC_1] = ui16DataLength;

    /* 2 TX descriptors are used for each TX packet */
    sendPacket(apui8PtrsArray, aui16LengthArray, US_2);
}


/* Function to get next TX buffer pointer where upper layers write data.
   The pointer value is calculated according to required buffer length. */
EXPORTED uint8 * ETHMAC_getTXBufferPointer( uint16 ui16ReqBufLength )
{
    uint8 *pui8RetPtr;

    /* ATTENTION: only one buffer is used at the moment */
    pui8RetPtr = (uint8 *)(apui8TXDcptDataBuffers[0] - ui16ReqBufLength);

    return pui8RetPtr;
}




/* ------------------ Local functions implementation --------------------- */

/* set destination MAC address */
LOCAL void setDestMACAddress(uint8 *pui8Frame, uint64 ui64MACAddress)
{
    *pui8Frame++ = (uint8)((ui64MACAddress & 0x0000FF0000000000) >> ULL_SHIFT_40);
    *pui8Frame++ = (uint8)((ui64MACAddress & 0x000000FF00000000) >> ULL_SHIFT_32);
    *pui8Frame++ = (uint8)((ui64MACAddress & 0x00000000FF000000) >> ULL_SHIFT_24);
    *pui8Frame++ = (uint8)((ui64MACAddress & 0x0000000000FF0000) >> ULL_SHIFT_16);
    *pui8Frame++ = (uint8)((ui64MACAddress & 0x000000000000FF00) >> ULL_SHIFT_8);
    *pui8Frame = (uint8)(ui64MACAddress & 0x00000000000000FF);
}


/* set source MAC address */
LOCAL void setSrcMACAddress(uint8 *pui8Frame, uint64 ui64MACAddress)
{
    *pui8Frame++ = (uint8)((ui64MACAddress & 0x0000FF0000000000) >> ULL_SHIFT_40);
    *pui8Frame++ = (uint8)((ui64MACAddress & 0x000000FF00000000) >> ULL_SHIFT_32);
    *pui8Frame++ = (uint8)((ui64MACAddress & 0x00000000FF000000) >> ULL_SHIFT_24);
    *pui8Frame++ = (uint8)((ui64MACAddress & 0x0000000000FF0000) >> ULL_SHIFT_16);
    *pui8Frame++ = (uint8)((ui64MACAddress & 0x000000000000FF00) >> ULL_SHIFT_8);
    *pui8Frame = (uint8)(ui64MACAddress & 0x00000000000000FF);
}


/* update TX descriptors fields and start transmission */
LOCAL void sendPacket( uint8 **pui8ArrayBuffers, uint16 *pui16ArraySizes, uint16 ui16ArrayItems )
{
    uint8 ui8BufferIndex;
    st_TXEthDcpt* pstCurrDcpt;
    st_TXEthDcpt* pstTailDcpt;

    /* init descriptors */
    pstCurrDcpt = stTXArrayDcpt;    /* init current descriptor with the first one */
    pstTailDcpt = NULL;                        /* init tail descriptor with 0 */

    /* set every descriptor with data buffers */
    for(ui8BufferIndex = UC_NULL;
        ui8BufferIndex < ui16ArrayItems;
        ui8BufferIndex++, pstCurrDcpt++, pui8ArrayBuffers++, pui16ArraySizes++)
    {
        pstCurrDcpt->pEDBuff = (uint8*)KVA_TO_PA(*pui8ArrayBuffers);   /* copy data buffer pointer */
        pstCurrDcpt->hdr.w = 0;     /* clear all the fields */
        pstCurrDcpt->hdr.NPV = 1;   /* set next pointer valid */
        pstCurrDcpt->hdr.EOWN = 1;  /* set hardware ownership */
        pstCurrDcpt->hdr.bCount = *pui16ArraySizes; /* set proper size */
        /* set tail descriptor */
        if(NULL != pstTailDcpt)
        {
            pstTailDcpt->next_ed = KVA_TO_PA(pstCurrDcpt);
        }
        pstTailDcpt = pstCurrDcpt;
    }
    /* descriptors list end as circular buffer (set the first buffer as the next one) */
    pstTailDcpt->next_ed = KVA_TO_PA(stTXArrayDcpt); /* anyway this is not used */

    /* prepare descriptors array */
    stTXArrayDcpt[0].hdr.SOP = 1;   /* start of packet */
    stTXArrayDcpt[(ui16ArrayItems - US_1)].hdr.EOP = 1; /* end of packet */

    /* set the TX descriptors start address */
    ETHTXST = KVA_TO_PA(stTXArrayDcpt);

    /* start transmission */
    ETHCON1SET = (1 << ETHCON_TXRTS_BIT_POS);

    /* wait until packet is sent */
    while(CHECK_TX_IS_DONE());
    /* ATTENTION: maybe it is not necessary to wait... */
}


/* update RX descriptors fields in order to receive packets */
LOCAL void setRXPacket( uint8** pui8ArrayBuffers, uint16 ui16ArraySize, uint16 ui16ArrayItems )
{
    uint8 ui8BufferIndex;
    st_RXEthDcpt* pstCurrDcpt;
    st_RXEthDcpt* pstTailDcpt;

    /* init descriptors */
    pstCurrDcpt = stRXArrayDcpt;    /* init current descriptor with the first one */
    pstTailDcpt = NULL;             /* init tail descriptor with 0 */

    /* set the RX data buffer size */
    ETHCON2 = ((ui16ArraySize / UL_16) << ETHCON2_RXBUFSZ_BIT_POS);

    /* set every descriptor with data buffers */
    for(ui8BufferIndex = UC_NULL;
        ui8BufferIndex < ui16ArrayItems;
        ui8BufferIndex++, pstCurrDcpt++, pui8ArrayBuffers++)
    {
        pstCurrDcpt->pEDBuff = (uint8 *)KVA_TO_PA(*pui8ArrayBuffers);   /* copy data buffer pointer */
        pstCurrDcpt->hdr.w = 0;     /* clear all the fields */
        pstCurrDcpt->hdr.flags.NPV = 1;   /* set next pointer valid */
        pstCurrDcpt->hdr.flags.EOWN = 1;  /* set hardware ownership */
        /* set tail descriptor */
        if(NULL != pstTailDcpt)
        {
            pstTailDcpt->next_ed = KVA_TO_PA(pstCurrDcpt);
        }
        pstTailDcpt = pstCurrDcpt;
    }
    /* connect first descriptor after last descriptor in the ring */
    pstTailDcpt->next_ed = KVA_TO_PA(stRXArrayDcpt);

    /* set RX descriptors start address */
    ETHRXST = KVA_TO_PA(stRXArrayDcpt);

    /* once RX enabled, the Ethernet Controller will receive frames and place them in the receive buffers we just programmed */

    /* to check eventuals received packet check the BUFCNT (ETHSTAT<16:23>) or RXDONE (ETHIRQ<7>) */
}


/* reset ETH controller */
LOCAL void resetEthController(void)
{
    /* disable ethernet interrupt */
    DISABLE_ETH_INT();

    /* turn ethernet controller off */
    ETHCON1CLR = (1 << ETHCON_ON_BIT_POS) | (1 << ETHCON_RXEN_BIT_POS) | (1 << ETHCON_TXRTS_BIT_POS);

    /* abort the Wait activity by polling ETHBUSY bit */
    while(CHECK_ETH_IS_BUSY());

    /* clear ethernet interrupt flag */
    CLEAR_ETH_INT_FLAG();

    /* disable ethernet controller interrupt generation */
    ETHIEN = 0;
    /* clear eventual int events */
    ETHIRQ = 0;

    /* clear ethernet TX and RX start addresses */
    ETHTXST = 0;
    ETHRXST = 0;
}


/* reset MAC module */
LOCAL void resetMACModule (void)
{
    /* reset MAC */
    EMAC1CFG1SET = (1 << EMAC1_SOFTRESET_BIT_POS);
    asm("nop");
    asm("nop");
    asm("nop");
    asm("nop");
    EMAC1CFG1CLR = (1 << EMAC1_SOFTRESET_BIT_POS);
    EMAC1CFG1SET=(1 <<8);
    EMAC1CFG1SET=(1 <<9);
    EMAC1CFG1SET=(1 <<10);
    EMAC1CFG1SET=(1 <<11);
}


/* configure MAC module registers */
LOCAL void configureMACModule (void)
{
    /* enable MAC receive */
    EMAC1CFG1SET = (1 << RXENABLE_BIT_POS);             //03122016 set bit0 Rx enable

    /* set MAC TX flow control */
    EMAC1CFG1SET = (1 << TXPAUSE_BIT_POS);              //03122016 set bit3 TXPAUSE

    /* set MAC RX flow control */
    EMAC1CFG1SET = (1 << RXPAUSE_BIT_POS);              //03122016 set bit2 RXPAUSE

#ifdef CONFIGURE_MAC_LOOPBACK
    /* set MAC loopback */
    EMAC1CFG1SET = (1 << LOOPBACK_BIT_POS);
#endif

    /* Padding and CRC append are enabled by default */
#if 0
    /* if this small frames will be not sent... maybe */
    /* disable automatic padding generation */
    EMAC1CFG2CLR = (1 << PADENABLE_BIT_POS);
    EMAC1CFG2CLR = (1 << VLANPAD_BIT_POS);
    EMAC1CFG2CLR = (1 << AUTOPAD_BIT_POS);
    /* disable automatic CRC generation and append */
    EMAC1CFG2CLR = (1 << CRCENABLE_BIT_POS);
#endif

    /* allow to tx and rx huge frames */
    EMAC1CFG2SET = (1 << HUGEFRM_BIT_POS);              //03122016 bit2=1 select  huge frames

    /* ATTENTION: if following values are defined as default register values than it is not necessary to write them */
    /* program back-to-back inter-packet gap */
    EMAC1IPGT = BB_INTERPACKET_GAP_VALUE;               // 03122016  set time=0x15 or 9.8uS for 10Mbps

    /* program non back-to-back inter-packet gap */
    EMAC1IPGRCLR = (0x7F << NB2BIPKTGP1_BIT_POS);
    EMAC1IPGRSET = ((NBB_INTERPACKET_GAP_VALUE1 & 0x7F) << NB2BIPKTGP1_BIT_POS);

    EMAC1IPGRCLR = (0x7F << NB2BIPKTGP2_BIT_POS);
    EMAC1IPGRSET = ((NBB_INTERPACKET_GAP_VALUE2 & 0x7F) << NB2BIPKTGP2_BIT_POS);

    /* set the collision window */
    EMAC1CLRTCLR = (0x3F << CWINDOW_BIT_POS);
    EMAC1CLRTSET = ((COLLISION_WINDOW_VALUE & 0x3F) << CWINDOW_BIT_POS);

    /* set the maxinum number of retransmissions */
    EMAC1CLRTCLR = (0x0F << RETX_BIT_POS);
    EMAC1CLRTSET = ((NUM_OF_RETX_VALUE & 0x0F) << RETX_BIT_POS);

    /* set maximum frame length */
    EMAC1MAXF = MAC_RX_MAX_FRAME;

    /* Update SW defined MAC address */
#ifdef USE_SW_MAC_ADDRESS
    EMAC1SA0 = (uint16)ULL_SW_MAC_ADDRESS;
    EMAC1SA1 = (uint16)(ULL_SW_MAC_ADDRESS >> ULL_SHIFT_16);
    EMAC1SA2 = (uint16)(ULL_SW_MAC_ADDRESS >> ULL_SHIFT_32);    /* most significant - first transmitted */
#endif

    /* prepare MAC address variable value */
    ETHMAC_ui64MACAddress = ULL_NULL;
    ETHMAC_ui64MACAddress = (uint64)EMAC1SA0;
    ETHMAC_ui64MACAddress |= ((uint64)EMAC1SA1 << ULL_SHIFT_16);
    ETHMAC_ui64MACAddress |= ((uint64)EMAC1SA2 << ULL_SHIFT_32);
}


/* init ETH controller registers */
LOCAL void initEthController( void )
{
    /* stop an eventual transmit */
    ETHCON1CLR = (1 << ETHCON_TXRTS_BIT_POS);   //05122016; BIT_POS=9 

    /* set PTV value */
    ETHCON1CLR = (0xFFFF << ETHCON_PTV_BIT_POS);            //05122016  BIT_POS=16 set Pause Timer Value
    ETHCON1SET = (FLOW_CTRL_PTV << ETHCON_PTV_BIT_POS);

    /* set RX buffer full watermark pointer */
    ETHRXWMCLR = (0xFF << ETHRXWM_RXFWM_BIT_POS);           //05122016 BIT POS=16 
    ETHRXWMSET = (FLOW_CTRL_RX_BUFF_FULL << ETHRXWM_RXFWM_BIT_POS);

    /* set RX buffer empty watermark pointer */
    ETHRXWMCLR = (0xFF << ETHRXWM_RXEWM_BIT_POS);           //05122016 BIT_POS=0       
    ETHRXWMSET = (FLOW_CTRL_RX_BUFF_EMPTY << ETHRXWM_RXEWM_BIT_POS);

    /* disable manual flow control */
    ETHCON1CLR = (1 << ETHCON_MANFC_BIT_POS);               //05122016 BIT_POS=4

    /* enable auto flow control */
    ETHCON1SET = (1 << ETHCON_AUTOFC_BIT_POS);               //05122016 BIT_POS=7

    /* ATTENTION: set RX filters here */

    /* enable RX filters */
//    ETHRXFCSET = (1 << ETHRXFC_CRCERREN_BIT_POS);
    ETHRXFCSET = (1 << ETHRXFC_CRCOKEN_BIT_POS);             //05122016 BIT_POS=6
    ETHRXFCSET = (1 << ETHRXFC_RUNTEN_BIT_POS);
    ETHRXFCSET = (1 << ETHRXFC_UCEN_BIT_POS);
    ETHRXFCSET = (1 << ETHRXFC_NOTMEEN_BIT_POS);
    ETHRXFCSET = (1 << ETHRXFC_MCEN_BIT_POS);
    ETHRXFCSET = (1 << ETHRXFC_BCEN_BIT_POS);

    /* set RX pattern match filter */
    /* ATTENTION: not supported yet! */
//    setPatternMatchRXFilter(...);

    /* prepare RX packet */
    setRXPacket(apui8RXDcptDataBuffers, US_DATA_BUFFER_LENGTH, UC_NUM_OF_RX_DCPT); //05122016 data-buffer-length=8

    /* set eth interrupts */
    ETHIENSET = (1 << TXBUSEIE_BIT_POS);
    ETHIENSET = (1 << RXBUSEIE_BIT_POS);
//    ETHIENSET = (1 << FWMARKIE_BIT_POS);
//    ETHIENSET = (1 << RXDONEIE_BIT_POS);
//    ETHIENSET = (1 << TXDONEIE_BIT_POS);
    ETHIENSET = (1 << RXOVFLWIE_BIT_POS);

    /* set int priority */
    IPC12SET = (ETH_PRIORITY << ETHPRI_BIT_POS);
    IPC12SET = (ETH_SUB_PRIORITY << ETHSUBPRI_BIT_POS);

    /* enable interrupt */
    ENABLE_ETH_INT();

    /* enable reception */
    ETHCON1SET = (1 << ETHCON_RXEN_BIT_POS);
}


/* set pattern match filter registers */
LOCAL void setPatternMatchRXFilter( KE_FILTER_MATCH_MODE eMatchMode, uint64 ui64matchMask, uint16 ui16matchOffs, uint16 matchChecksum, boolean bmatchInvert)
{
    /* clear PMMODE bits (pattern match mode) */
    ETHRXFCCLR = (0xF << ETHRXFC_PMMODE_BIT_POS);

    /* set match mask */
    ETHPMM0 = (uint32)ui64matchMask;
    ETHPMM1 = (uint32)(ui64matchMask >> ULL_SHIFT_32);

    /* set match offset */
    ETHPMO = ui16matchOffs;

    /* set match checksum */
    ETHPMCS = matchChecksum;

    /* update match invert */
    if(B_TRUE == bmatchInvert)
    {
        ETHRXFCSET = (1 << ETHRXFC_NOTPM_BIT_POS);  /* set NOTPM */
    }
    else
    {
        ETHRXFCCLR = (1 << ETHRXFC_NOTPM_BIT_POS);  /* clear NOTPM */
    }

    /* set pattern match mode */
    switch(eMatchMode)
    {
        case MATCH_DISABLED:
        {
            /* leave disabled */

            break;
        }

        case NOTPM_XOR_CKS:
        {
            ETHRXFCSET = (0x1 << ETHRXFC_PMMODE_BIT_POS);

            break;
        }

        case NOTPM_XOR_CKS_AND_STAT_ADD:
        {
            ETHRXFCSET = (0x2 << ETHRXFC_PMMODE_BIT_POS);
            /* 0x3 is valid as well */

            break;
        }

        case NOTPM_XOR_CKS_AND_UNIC_ADD:
        {
            ETHRXFCSET = (0x4 << ETHRXFC_PMMODE_BIT_POS);
            /* 0x5 is valid as well */

            break;
        }

        case NOTPM_XOR_CKS_AND_BROAD_ADD:
        {
            ETHRXFCSET = (0x6 << ETHRXFC_PMMODE_BIT_POS);
            /* 0x7 is valid as well */

            break;
        }

        case NOTPM_XOR_CKS_AND_HASHT_ADD:
        {
            ETHRXFCSET = (0x8 << ETHRXFC_PMMODE_BIT_POS);

            break;
        }

        case NOTPM_XOR_CKS_AND_MAGIC_ADD:
        {
            ETHRXFCSET = (0x9 << ETHRXFC_PMMODE_BIT_POS);

            break;
        }

        default:
        {
            /* leave disabled */

            break;
        }
    }
}


/* ETH Interrupt service routine */
LOCAL void __ISR(_ETH_VECTOR, ipl5) Eth_IntHandler (void)
{
    uint16 ui16EthFlags;
//    ETHMAC_st_DataDcpt *stDataDcpt;

    /* read interrupt flags */
    ui16EthFlags = ETHIRQ;

    /* the sooner we acknowledge, the smaller the chance to miss another event
       of the same type because of a lengthy ISR */
    /* acknowledge the interrupt flags */
    ETHIRQCLR = ui16EthFlags;

//    if((ui16EthFlags & (1 << ETHIRQ_FWMARK_BIT_POS)) > 0)
//    if((ui16EthFlags & (1 << ETHIRQ_TXBUSE_BIT_POS)) > 0)
//    if((ui16EthFlags & (1 << ETHIRQ_RXBUSE_BIT_POS)) > 0)
//    if((ui16EthFlags & (1 << ETHIRQ_RXOVFLW_BIT_POS)) > 0)
//    if((ui16EthFlags & (1 << ETHIRQ_RXDONE_BIT_POS)) > 0)
//    if((ui16EthFlags & (1 << ETHIRQ_TXDONE_BIT_POS)) > 0)

    /* clear interrupt flag */
    CLEAR_ETH_INT_FLAG();
}




/* End of file */
