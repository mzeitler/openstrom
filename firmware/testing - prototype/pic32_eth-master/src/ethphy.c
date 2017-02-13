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
 * This file ethphy.c represents the PHY layer source file
 * of the UDP/IP stack.
 *
 * Author : Marco Russi
 *
 * Evolution of the file:
 * 10/08/2015 - File created - Marco Russi
 *
*/


//TODO: manage RMII detection during MIIM interface initialisation


/* inclusion files */
#include "p32mx795f512l.h"
#include "fw_common.h"

#include "ethphy.h"
#include "extphy_regs.h"



/* Local defines */

/* External PHY adress */
#define UC_EXT_PHY_ADDRESS          ((uint8)1)

/* PHY required capabilities */
#define PHY_REQUIRED_CPBL_MASK      (BMSTAT_BASE10T_HDX_MASK | BMSTAT_BASE10T_FDX_MASK | BMSTAT_BASE100TX_HDX_MASK | BMSTAT_BASE100TX_FDX_MASK)


/* --- MIIM defines --- */

/* EMAC1MCFG register */
#define MIIM_RESET_BIT_POS          15
#define MIIM_CLKSEL_BIT_POS         2

/* EMAC1MIND register */
#define MIIM_NOTVALID_BIT_POS       2
#define MIIM_IS_BUSY_BIT_POS        0

/* EMAC1MADR register */
#define MIIM_PHY_ADD_BIT_POS        8
#define MIIM_REG_ADD_BIT_POS        0

/* EMAC1MCMD register */
#define MIIM_SCAN_REG_BIT_POS       1
#define MIIM_READ_REG_BIT_POS       0

/* EMAC1SUPP register */
#define RESETRMII_BIT_POS           11
#define SPEEDRMII_BIT_POS           8




/* Local macros */

#define CHECK_MIIM_IS_BUSY()        ((EMAC1MIND & (1 << MIIM_IS_BUSY_BIT_POS)) > 0)




/* Local functions prototypes */
LOCAL void      initMIIMInterface   (void);
LOCAL uint16    readPHYRegister     (uint8, uint8);
LOCAL void      writePHYRegister    (uint8, uint8, uint16);
LOCAL void      scanPHYRegister     (uint8, uint8);




/* Exported functions declaration */

/* Init Ethernet PHY module */
EXPORTED boolean ETHPHY_Init(void)
{
    boolean bPHYValid = B_FALSE;
    uint16 ui16RegisterData = US_NULL;

    /* init MIIM interface */
    initMIIMInterface();

    /* read BMCON register default value */
    ui16RegisterData = readPHYRegister(UC_EXT_PHY_ADDRESS, PHY_REG_BMCON);  /* maybe not needed */
    /* reset PHY */
    /* set RESET flag */
    ui16RegisterData |= BMCON_RESET_MASK;
    /* write */
    writePHYRegister(UC_EXT_PHY_ADDRESS, PHY_REG_BMCON, ui16RegisterData);
    /* ATTENTION: wait for this bit to self-clear itself - IMPLEMENT A TIMEOUT! */
    asm("nop");
    asm("nop");

    /* try to write and read-back something to PHY */
//    ui16RegisterData = readPHYRegister(UC_EXT_PHY_ADDRESS, PHY_REG_BMCON);
    ui16RegisterData = 0;
    ui16RegisterData |= (BMCON_LOOPBACK_MASK | BMCON_ISOLATE_MASK);     /* two flags */
    /* write */
    writePHYRegister(UC_EXT_PHY_ADDRESS, PHY_REG_BMCON, ui16RegisterData);
    /* read-back */
    ui16RegisterData = readPHYRegister(UC_EXT_PHY_ADDRESS, PHY_REG_BMCON);
    /* check both flags */
    if((ui16RegisterData & (BMCON_LOOPBACK_MASK | BMCON_ISOLATE_MASK)) == (BMCON_LOOPBACK_MASK | BMCON_ISOLATE_MASK))
    {
        /* write success */
        bPHYValid = B_TRUE;
    }
    else
    {
        /* write fail */
    }

    /* clear flags previously tested */
    ui16RegisterData &= (~(BMCON_LOOPBACK_MASK | BMCON_ISOLATE_MASK));
    writePHYRegister(UC_EXT_PHY_ADDRESS, PHY_REG_BMCON, ui16RegisterData);

    /* if PHY is valid */
    if(B_TRUE == bPHYValid)
    {
        /* read BMSTAT register */
        ui16RegisterData = readPHYRegister(UC_EXT_PHY_ADDRESS, PHY_REG_BMSTAT);
        /* check PHY required capabilities and Auto-negotiation ability */
        if(ui16RegisterData & (PHY_REQUIRED_CPBL_MASK | BMSTAT_AN_ABLE_MASK))
        {
            /* PHY is still valid */
        }
        else
        {
            /* PHY is not valid anymore */
            bPHYValid = B_FALSE;
        }
    }

    /* if PHY is valid */
    if(B_TRUE == bPHYValid)
    {
        /* configure MII/RMII */
        ui16RegisterData = readPHYRegister(UC_EXT_PHY_ADDRESS, PHY_REG_RMII_BYPASS);
        /* ATTENTION: RMII is used at the moment - default by strap - Do not leave this as fixed */
        ui16RegisterData |= RMIIBYPASS_RMII_MODE_MASK;      /* use RMII */
        ui16RegisterData &= (~RMIIBYPASS_RMII_REV1_0_MASK); /* use RMII 1.2 */
        //ui16RegisterData &= (~RMIIBYPASS_RMII_MODE_MASK);   /* use MII */
        writePHYRegister(UC_EXT_PHY_ADDRESS, PHY_REG_RMII_BYPASS, ui16RegisterData);

        /* configure MDIX */
        ui16RegisterData = readPHYRegister(UC_EXT_PHY_ADDRESS, PHY_REG_PHY_CTRL);
        /* enable MDIX Auto-negotiation */
        /* ATTENTION: Auto-negotiation is used at the moment - deafult by strap - Do not leave this as fixed */
        ui16RegisterData |= PHYCTRL_MDIX_EN_MASK;
        writePHYRegister(UC_EXT_PHY_ADDRESS, PHY_REG_PHY_CTRL, ui16RegisterData);

        /* configure negotiation advertisement register */
        ui16RegisterData = readPHYRegister(UC_EXT_PHY_ADDRESS, PHY_REG_ANAD);
        /* ATTENTION: Do not leave this as fixed */
        ui16RegisterData |= ANAD_PAUSE_MASK;    /* PAUSE support for full duplex */
        ui16RegisterData |= ANAD_ASM_DIR_MASK;  /* Asymmetric PAUSE support for full duplex */
        writePHYRegister(UC_EXT_PHY_ADDRESS, PHY_REG_ANAD, ui16RegisterData);

        /* read BMSTAT register */
        ui16RegisterData = readPHYRegister(UC_EXT_PHY_ADDRESS, PHY_REG_BMSTAT);
        /* if autonegotiation ability is enabled */
        if((ui16RegisterData & BMSTAT_AN_ABLE_MASK) > US_NULL)
        {
            /* start autonegotiation */
            ui16RegisterData = readPHYRegister(UC_EXT_PHY_ADDRESS, PHY_REG_BMCON);
            ui16RegisterData |= BMCON_AN_ENABLE_MASK;   /* enable auto-negotiation */
            ui16RegisterData |= BMCON_AN_RESTART_MASK;  /* restart auto-negotiation */
            writePHYRegister(UC_EXT_PHY_ADDRESS, PHY_REG_BMCON, ui16RegisterData);

            /* wait autonegotiation complete */
            do
            {
                /* read and check Auto-Negotiation Complete bit in BMSTAT register */
                ui16RegisterData = readPHYRegister(UC_EXT_PHY_ADDRESS, PHY_REG_BMSTAT);
            }
            while((ui16RegisterData & BMSTAT_AN_COMPLETE_MASK) == UL_NULL);




/*
            {
                uint16 reg;
                reg = readPHYRegister(UC_EXT_PHY_ADDRESS,PHY_REG_BMCON);
                reg = readPHYRegister(UC_EXT_PHY_ADDRESS,PHY_REG_BMSTAT);
                reg = readPHYRegister(UC_EXT_PHY_ADDRESS,PHY_REG_PHYID1);
                reg = readPHYRegister(UC_EXT_PHY_ADDRESS,PHY_REG_PHYID2);
                reg = readPHYRegister(UC_EXT_PHY_ADDRESS,PHY_REG_ANAD);
                reg = readPHYRegister(UC_EXT_PHY_ADDRESS,PHY_REG_ANLPAD);
                reg = readPHYRegister(UC_EXT_PHY_ADDRESS,PHY_REG_ANEXP);
                reg = readPHYRegister(UC_EXT_PHY_ADDRESS,PHY_REG_ANNPTR);
                reg = readPHYRegister(UC_EXT_PHY_ADDRESS,PHY_REG_ANLPRNP);
            }
*/





            /* read ANEXP register */
            ui16RegisterData = readPHYRegister(UC_EXT_PHY_ADDRESS, PHY_REG_ANEXP);
            /* read ANLPAR register */
            ui16RegisterData = readPHYRegister(UC_EXT_PHY_ADDRESS, PHY_REG_ANLPAD);
            /* read ANLPAR next page register */
            ui16RegisterData = readPHYRegister(UC_EXT_PHY_ADDRESS, PHY_REG_ANLPADNP);

            asm("nop");

            /* once the negotiation is completed get link partner capabilities from the PHY register ANLPAR */
            /* ATTENTION: not performed at the moment! */
        }
    }

    return bPHYValid;
}




/* Local functions declaration */

/* initialise the MIIM interface */
LOCAL void initMIIMInterface(void)
{
    /* detect alternate or default I/O configuration */
    /* FETHIO (DEVCFG3<25>) */
    /* not used here at the moment - set in main.c */

    /* detect MII/RMII operation mode */
    /* FMIIEN (DEVCFG3<24>) */
    /* not used here at the moment - set in main.c */

    /* initialise all pins used by the MAC PHY interface as digital */
    /* see main.c */

    /* ATTENTION: do following reset instruction if RMII operation is selected */
    EMAC1SUPPSET = (1 << RESETRMII_BIT_POS);
    asm("nop");
    asm("nop");
    asm("nop");
    EMAC1SUPPCLR = (1 << RESETRMII_BIT_POS);

    /* RMII is running in 100 Mbps */
    EMAC1SUPPSET = (1 << SPEEDRMII_BIT_POS);

    /* issue an MIIM block reset */
    EMAC1MCFGSET = (1 << MIIM_RESET_BIT_POS);
    asm("nop");
    asm("nop");
    asm("nop");
    EMAC1MCFGCLR = (1 << MIIM_RESET_BIT_POS);

    /* select MIIM clock divider */
    EMAC1MCFGCLR = (0x0F << MIIM_CLKSEL_BIT_POS);
    /* ATTENTION: this value should be calculated dinamically - clock set at 20 Mhz */
    EMAC1MCFGSET = (9 << MIIM_CLKSEL_BIT_POS);
}


LOCAL uint16 readPHYRegister(uint8 ui8PHYAddress, uint8 ui8RegAddress)
{
    uint16 ui16ReadData;

    /* poll MIIMBUSY flag */
    while(CHECK_MIIM_IS_BUSY());

    /* set the PHY address */
    EMAC1MADRCLR = (0x1F << MIIM_PHY_ADD_BIT_POS);
    EMAC1MADRSET = ((ui8PHYAddress & 0x1F) << MIIM_PHY_ADD_BIT_POS);

    /* set the register address */
    EMAC1MADRCLR = (0x1F << MIIM_REG_ADD_BIT_POS);
    EMAC1MADRSET = ((ui8RegAddress & 0x1F) << MIIM_REG_ADD_BIT_POS);

    /* set read command */
    EMAC1MCMDSET = (1 << MIIM_READ_REG_BIT_POS);

    /* wait 3 SYSCLK cycles */
    asm("nop");
    asm("nop");
    asm("nop");

    /* poll MIIMBUSY flag */
    while(CHECK_MIIM_IS_BUSY());

    /* clear read command */
    EMAC1MCMDCLR = (1 << MIIM_READ_REG_BIT_POS);

    /* read 16-bit data */
    ui16ReadData = (EMAC1MRDD & 0x0000FFFF);

    return ui16ReadData;
}


LOCAL void writePHYRegister(uint8 ui8PHYAddress, uint8 ui8RegAddress, uint16 ui16DataToWrite)
{
    /* poll MIIMBUSY flag */
    while(CHECK_MIIM_IS_BUSY());

    /* set the PHY address */
    EMAC1MADRCLR = (0x1F << MIIM_PHY_ADD_BIT_POS);
    EMAC1MADRSET = ((ui8PHYAddress & 0x1F) << MIIM_PHY_ADD_BIT_POS);

    /* set the register address */
    EMAC1MADRCLR = (0x1F << MIIM_REG_ADD_BIT_POS);
    EMAC1MADRSET = ((ui8RegAddress & 0x1F) << MIIM_REG_ADD_BIT_POS);

    /* set read command */
    EMAC1MWTD = (ui16DataToWrite & 0x0000FFFF);

    /* wait 3 SYSCLK cycles */
    asm("nop");
    asm("nop");
    asm("nop");
}


LOCAL void scanPHYRegister(uint8 ui8PHYAddress, uint8 ui8RegAddress)
{
    uint16 ui16ReadData;

    /* poll MIIMBUSY flag */
    while(CHECK_MIIM_IS_BUSY());

    /* set the PHY address */
    EMAC1MADRCLR = (0x1F << MIIM_PHY_ADD_BIT_POS);
    EMAC1MADRSET = ((ui8PHYAddress & 0x1F) << MIIM_PHY_ADD_BIT_POS);

    /* set the register address */
    EMAC1MADRCLR = (0x1F << MIIM_REG_ADD_BIT_POS);
    EMAC1MADRSET = ((ui8RegAddress & 0x1F) << MIIM_REG_ADD_BIT_POS);

    /* set scan command */
    EMAC1MCMDSET = (1 << MIIM_SCAN_REG_BIT_POS);

    /* wait 3 SYSCLK cycles */
    asm("nop");
    asm("nop");
    asm("nop");

    /* poll NOT VALID flag */
    while((EMAC1MIND & (1 << MIIM_NOTVALID_BIT_POS)) == 1);

    /* read first 16-bit data */
    ui16ReadData = (EMAC1MRDD & 0x0000FFFF);

    //TODO: ...read other registers after frame time (no way to determine when register is updated)

    /* stop scan - clear scan command */
    EMAC1MCMDCLR = (1 << MIIM_SCAN_REG_BIT_POS);
}




/* End of files */
