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
 * This file ethphy_regs.h represents a register definition file
 * of the UDP/IP stack.
 *
 * Author : Marco Russi
 *
 * Evolution of the file:
 * 10/08/2015 - File created - Marco Russi
 *
*/


/* inclusion files */
#include "fw_common.h"




/* Local registers defines */

/* RBR - RMII and bypass register */
#define RMIIBYPASS_RMII_MODE_MASK       0x0020
#define RMIIBYPASS_RMII_REV1_0_MASK     0x0010
#define RMIIBYPASS_RX_OVF_STS_MASK      0x0008
#define RMIIBYPASS_RX_UNF_STS_MASK      0x0004
#define RMIIBYPASS_ELAST_BUF_MASK       0x0003

/* PHYCR - PHY control register */
#define PHYCTRL_PHYADDR_MASK            0x001f
#define PHYCTRL_LED_CFG_MASK            0x0060
#define PHYCTRL_BP_STRETCH_MASK         0x0080
#define PHYCTRL_BIST_START_MASK         0x0100
#define PHYCTRL_BIST_STATUS_MASK        0x0200
#define PHYCTRL_PSR_15_MASK             0x0400
#define PHYCTRL_BIST_FE_MASK            0x0800
#define PHYCTRL_PAUSE_TX_MASK           0x1000
#define PHYCTRL_PAUSE_RX_MASK           0x2000
#define PHYCTRL_FORCE_MDIX_MASK         0x4000
#define PHYCTRL_MDIX_EN_MASK            0x8000

/* BMCR - Basic mode control register */
#define BMCON_COLTEST_MASK              0x0080
#define BMCON_DUPLEX_MASK               0x0100
#define BMCON_AN_RESTART_MASK           0x0200
#define BMCON_ISOLATE_MASK              0x0400
#define BMCON_PDWN_MASK                 0x0800
#define BMCON_AN_ENABLE_MASK            0x1000
#define BMCON_SPEED_MASK                0x2000
#define BMCON_LOOPBACK_MASK             0x4000
#define BMCON_RESET_MASK                0x8000

/* BMSR - Basic mode status register */
#define BMSTAT_EXTEND_ABLE_MASK         0x0001
#define BMSTAT_JABBER_DET_MASK          0x0002
#define BMSTAT_LINK_STAT_MASK           0x0004
#define BMSTAT_AN_ABLE_MASK             0x0008
#define BMSTAT_REM_FAULT_MASK           0x0010
#define BMSTAT_AN_COMPLETE_MASK         0x0020
#define BMSTAT_PREAMBLE_SUPPRESS_MASK   0x0040
#define BMSTAT_BASE10T_HDX_MASK         0x0800
#define BMSTAT_BASE10T_FDX_MASK         0x1000
#define BMSTAT_BASE100TX_HDX_MASK       0x2000
#define BMSTAT_BASE100TX_FDX_MASK       0x4000
#define BMSTAT_BASE100T4_MASK           0x8000
/* negotiation field mask */
#define BMSTAT_NEGOTIATION_MASK         (BMSTAT_BASE10T_HDX_MASK | BMSTAT_BASE10T_FDX_MASK | \
                                         BMSTAT_BASE100TX_HDX_MASK | BMSTAT_BASE100TX_FDX_MASK | BMSTAT_BASE100T4_MASK)
#define BMSTAT_NEGOTIATION_POS          11      /* negotiation field position */
#define BMSTAT_NEGOTIATION_LENGTH       5       /* negotiation field length */

/* PHYIDR2 - PHY identifier register #2 */
#define PHYID2_MNF_REV_MASK             0x000F
#define PHYID2_MNF_MODEL_MASK           0x03F0
#define PHYID2_OUI_LSB_MASK             0xFC00

/* ANAR - Auto-negotiation advertisement register */
#define ANAD_PROT_SEL_MASK              0x001F
#define ANAD_BASE10T_MASK               0x0020
#define ANAD_BASE10T_FDX_MASK           0x0040
#define ANAD_BASE100TX_MASK             0x0080
#define ANAD_BASE100TX_FDX_MASK         0x0100
#define ANAD_BASE100T4_MASK             0x0200
#define ANAD_PAUSE_MASK                 0x0400
#define ANAD_ASM_DIR_MASK               0x0800
#define ANAD_REM_FAULT_MASK             0x2000
#define ANAD_NP_ABLE_MASK               0x8000
/* negotiation field mask */
#define ANAD_NEGOTIATION_MASK           (ANAD_BASE10T_MASK | ANAD_BASE10T_FDX_MASK | ANAD_BASE100TX_MASK | ANAD_BASE100TX_FDX_MASK | \
                                         ANAD_BASE100T4_MASK)
#define ANAD_NEGOTIATION_POS            5       /* negotiation field position */
#define ANAD_NEGOTIATION_LENGTH         5       /* negotiation field length */

/* ANLPAR - Auto-negotiation link partner ability register (BASE page) */
#define ANLPAD_PROT_SEL_MASK            0x001F
#define ANLPAD_BASE10T_MASK             0x0020
#define ANLPAD_BASE10T_FDX_MASK         0x0040
#define ANLPAD_BASE100TX_MASK           0x0080
#define ANLPAD_BASE100TX_FDX_MASK       0x0100
#define ANLPAD_BASE100T4_MASK           0x0200
#define ANLPAD_PAUSE_MASK               0x0400
#define ANLPAD_ASM_DIR_MASK             0x0800
#define ANLPAD_REM_FAULT_MASK           0x2000
#define ANLPAD_ACK_MASK                 0x4000
#define ANLPAD_NP_ABLE_MASK             0x8000

/* ANLPAR - Auto-negotiation link partner ability register (Next page) */
#define ANLPADNP_MESSAGE_MASK           0x07FF
#define ANLPADNP_TOGGLE_MASK            0x0800
#define ANLPADNP_ACK2_MASK              0x1000
#define ANLPADNP_MSGP_MASK              0x2000
#define ANLPADNP_ACK_MASK               0x4000
#define ANLPADNP_NP_MASK                0x8000

/* ANER - Auto-negotiate Expansion register */
#define ANEXP_LP_AN_ABLE_MASK           0x0001
#define ANEXP_PAGE_RX_MASK              0x0002
#define ANEXP_NP_ABLE_MASK              0x0004
#define ANEXP_LP_NP_ABLE_MASK           0x0008
#define ANEXP_PDF_MASK                  0x0010

/* ANNPTR - Auto-negotiation next page transmit register */
#define ANNPTR_MESSAGE_MASK             0x07FF
#define ANNPTR_TOGGLE_MASK              0x0800
#define ANNPTR_ACK2_MASK                0x1000
#define ANNPTR_MSGP_MASK                0x2000
#define ANNPTR_NP_MASK                  0x8000

/*
#define ANLPRNP_MESSAGE_MASK            0x07FF
#define ANLPRNP_TOGGLE_MASK             0x0800
#define ANLPRNP_ACK2_MASK               0x1000
#define ANLPRNP_MSGP_MASK               0x2000
#define ANLPRNP_ACK_MASK                0x4000
#define ANLPRNP_NP_MASK                 0x8000
*/




/* Exported enums declaration */

/* PHY basic registers addresses */
typedef enum
{
    PHY_REG_BMCON       = 0,    /* Basic:    Control Register */
    PHY_REG_BMSTAT      = 1,    /* Basic:    Status Register */
    PHY_REG_PHYID1      = 2,    /* Extended: PHY Identifier 1 */
    PHY_REG_PHYID2      = 3,    /* Extended: PHY Identifier 2 */
    PHY_REG_ANAD        = 4,    /* Extended: Auto-Negotiation Advertisement Register */
    PHY_REG_ANLPAD      = 5,    /* Extended: Auto-Negotiation Link Partner Advertisement */
    PHY_REG_ANLPADNP    = 5,    /* Extended: Auto-Negotiation Link Partner Advertisement, Next Page (?) */
    PHY_REG_ANEXP       = 6,    /* Extended: Auto-Negotiation Expansion */
    PHY_REG_ANNPTR      = 7,    /* Extended: Auto-Negotiation Next Page Transmit */
    PHY_REG_ANLPRNP     = 8     /* Extended: Auto-Negotiation Link Partner Received Next Page */
} KE_PHY_BASIC_REG;


/* PHY vendor registers addresses */
typedef enum
{
    PHY_REG_STAT            = 0x10,
    PHY_REG_MII_INT_CTRL    = 0x11,
    PHY_REG_MII_INT_STAT    = 0x12,
    PHY_REG_FALSE_CS_COUNT  = 0x14,
    PHY_REG_RXERR_COUNT     = 0x15,
    PHY_REG_PCS_CONFIG      = 0x16,
    PHY_REG_RMII_BYPASS     = 0x17,
    PHY_REG_LED_CTRL        = 0x18,
    PHY_REG_PHY_CTRL        = 0x19,
    PHY_REG_10BT_CTRL       = 0x1a,
    PHY_REG_TEST_CTRL       = 0x1b,
    PHY_REG_ENERGY_CTRL     = 0x1d
}KE_PHY_VENDOR_REG;




/* End of files */
