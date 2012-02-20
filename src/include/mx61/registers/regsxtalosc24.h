/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _XTALOSC24M_H
#define _XTALOSC24M_H

#include "regs.h"

#ifndef REGS_XTALOSC24M_BASE
#define REGS_XTALOSC24M_BASE (REGS_BASE + 0x020c8000)

#endif


/*
 * HW_XTALOSC24M_MISC0 - Miscellaneous Register 0
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 3;
        unsigned CLKGATE_DELAY : 3;
        unsigned CLKGATE_CTRL : 1;
        unsigned ANAMUX : 4;
        unsigned ANAMUX_EN : 1;
        unsigned RESERVED1 : 5;
        unsigned WBCP_VPW_THRESH : 2;
        unsigned OSC_XTALOK_EN : 1;
        unsigned OSC_XTALOK : 1;
        unsigned OSC_I : 2;
        unsigned RTC_RINGOSC_EN : 1;
        unsigned RESERVED2 : 1;
        unsigned STOP_MODE_CONFIG : 1;
        unsigned RESERVED3 : 2;
        unsigned REFTOP_BIAS_TST : 2;
        unsigned RESERVED4 : 4;
        unsigned REFTOP_VBGUP : 1;
        unsigned REFTOP_VBGADJ : 3;
        unsigned REFTOP_SELFBIASOFF : 1;
        unsigned REFTOP_LOWPOWER : 1;
        unsigned REFTOP_PWDVBGUP : 1;
        unsigned RESERVED5 : 2;
        unsigned REFTOP_PWD : 1;

    } B;
} hw_xtalosc24m_misc0_t;
#endif

/*
 * constants & macros for entire XTALOSC24M_MISC0 register
 */
#define HW_XTALOSC24M_MISC0_ADDR      (REGS_XTALOSC24M_BASE + 0x150)

#ifndef __LANGUAGE_ASM__
#define HW_XTALOSC24M_MISC0           (*(volatile hw_xtalosc24m_misc0_t *) HW_XTALOSC24M_MISC0_ADDR)
#define HW_XTALOSC24M_MISC0_RD()      (HW_XTALOSC24M_MISC0.U)
#define HW_XTALOSC24M_MISC0_WR(v)     (HW_XTALOSC24M_MISC0.U = (v))
#define HW_XTALOSC24M_MISC0_SET(v)    (HW_XTALOSC24M_MISC0_WR(HW_XTALOSC24M_MISC0_RD() |  (v)))
#define HW_XTALOSC24M_MISC0_CLR(v)    (HW_XTALOSC24M_MISC0_WR(HW_XTALOSC24M_MISC0_RD() & ~(v)))
#define HW_XTALOSC24M_MISC0_TOG(v)    (HW_XTALOSC24M_MISC0_WR(HW_XTALOSC24M_MISC0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual XTALOSC24M_MISC0 bitfields
 */

/* --- Register HW_XTALOSC24M_MISC0, field CLKGATE_DELAY */

#define BP_XTALOSC24M_MISC0_CLKGATE_DELAY      26
#define BM_XTALOSC24M_MISC0_CLKGATE_DELAY      0x1c000000

#ifndef __LANGUAGE_ASM__
#define BF_XTALOSC24M_MISC0_CLKGATE_DELAY(v)   ((((reg32_t) v) << 26) & BM_XTALOSC24M_MISC0_CLKGATE_DELAY)
#else
#define BF_XTALOSC24M_MISC0_CLKGATE_DELAY(v)   (((v) << 26) & BM_XTALOSC24M_MISC0_CLKGATE_DELAY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_XTALOSC24M_MISC0_CLKGATE_DELAY(v)   BF_CS1(XTALOSC24M_MISC0, CLKGATE_DELAY, v)
#endif

/* --- Register HW_XTALOSC24M_MISC0, field CLKGATE_CTRL */

#define BP_XTALOSC24M_MISC0_CLKGATE_CTRL      25
#define BM_XTALOSC24M_MISC0_CLKGATE_CTRL      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_XTALOSC24M_MISC0_CLKGATE_CTRL(v)   ((((reg32_t) v) << 25) & BM_XTALOSC24M_MISC0_CLKGATE_CTRL)
#else
#define BF_XTALOSC24M_MISC0_CLKGATE_CTRL(v)   (((v) << 25) & BM_XTALOSC24M_MISC0_CLKGATE_CTRL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_XTALOSC24M_MISC0_CLKGATE_CTRL(v)   BF_CS1(XTALOSC24M_MISC0, CLKGATE_CTRL, v)
#endif

/* --- Register HW_XTALOSC24M_MISC0, field ANAMUX */

#define BP_XTALOSC24M_MISC0_ANAMUX      21
#define BM_XTALOSC24M_MISC0_ANAMUX      0x01e00000

#ifndef __LANGUAGE_ASM__
#define BF_XTALOSC24M_MISC0_ANAMUX(v)   ((((reg32_t) v) << 21) & BM_XTALOSC24M_MISC0_ANAMUX)
#else
#define BF_XTALOSC24M_MISC0_ANAMUX(v)   (((v) << 21) & BM_XTALOSC24M_MISC0_ANAMUX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_XTALOSC24M_MISC0_ANAMUX(v)   BF_CS1(XTALOSC24M_MISC0, ANAMUX, v)
#endif

/* --- Register HW_XTALOSC24M_MISC0, field ANAMUX_EN */

#define BP_XTALOSC24M_MISC0_ANAMUX_EN      20
#define BM_XTALOSC24M_MISC0_ANAMUX_EN      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_XTALOSC24M_MISC0_ANAMUX_EN(v)   ((((reg32_t) v) << 20) & BM_XTALOSC24M_MISC0_ANAMUX_EN)
#else
#define BF_XTALOSC24M_MISC0_ANAMUX_EN(v)   (((v) << 20) & BM_XTALOSC24M_MISC0_ANAMUX_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_XTALOSC24M_MISC0_ANAMUX_EN(v)   BF_CS1(XTALOSC24M_MISC0, ANAMUX_EN, v)
#endif

/* --- Register HW_XTALOSC24M_MISC0, field WBCP_VPW_THRESH */

#define BP_XTALOSC24M_MISC0_WBCP_VPW_THRESH      18
#define BM_XTALOSC24M_MISC0_WBCP_VPW_THRESH      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_XTALOSC24M_MISC0_WBCP_VPW_THRESH(v)   ((((reg32_t) v) << 18) & BM_XTALOSC24M_MISC0_WBCP_VPW_THRESH)
#else
#define BF_XTALOSC24M_MISC0_WBCP_VPW_THRESH(v)   (((v) << 18) & BM_XTALOSC24M_MISC0_WBCP_VPW_THRESH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_XTALOSC24M_MISC0_WBCP_VPW_THRESH(v)   BF_CS1(XTALOSC24M_MISC0, WBCP_VPW_THRESH, v)
#endif

/* --- Register HW_XTALOSC24M_MISC0, field OSC_XTALOK_EN */

#define BP_XTALOSC24M_MISC0_OSC_XTALOK_EN      17
#define BM_XTALOSC24M_MISC0_OSC_XTALOK_EN      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_XTALOSC24M_MISC0_OSC_XTALOK_EN(v)   ((((reg32_t) v) << 17) & BM_XTALOSC24M_MISC0_OSC_XTALOK_EN)
#else
#define BF_XTALOSC24M_MISC0_OSC_XTALOK_EN(v)   (((v) << 17) & BM_XTALOSC24M_MISC0_OSC_XTALOK_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_XTALOSC24M_MISC0_OSC_XTALOK_EN(v)   BF_CS1(XTALOSC24M_MISC0, OSC_XTALOK_EN, v)
#endif

/* --- Register HW_XTALOSC24M_MISC0, field OSC_XTALOK */

#define BP_XTALOSC24M_MISC0_OSC_XTALOK      16
#define BM_XTALOSC24M_MISC0_OSC_XTALOK      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_XTALOSC24M_MISC0_OSC_XTALOK(v)   ((((reg32_t) v) << 16) & BM_XTALOSC24M_MISC0_OSC_XTALOK)
#else
#define BF_XTALOSC24M_MISC0_OSC_XTALOK(v)   (((v) << 16) & BM_XTALOSC24M_MISC0_OSC_XTALOK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_XTALOSC24M_MISC0_OSC_XTALOK(v)   BF_CS1(XTALOSC24M_MISC0, OSC_XTALOK, v)
#endif

/* --- Register HW_XTALOSC24M_MISC0, field OSC_I */

#define BP_XTALOSC24M_MISC0_OSC_I      14
#define BM_XTALOSC24M_MISC0_OSC_I      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_XTALOSC24M_MISC0_OSC_I(v)   ((((reg32_t) v) << 14) & BM_XTALOSC24M_MISC0_OSC_I)
#else
#define BF_XTALOSC24M_MISC0_OSC_I(v)   (((v) << 14) & BM_XTALOSC24M_MISC0_OSC_I)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_XTALOSC24M_MISC0_OSC_I(v)   BF_CS1(XTALOSC24M_MISC0, OSC_I, v)
#endif

/* --- Register HW_XTALOSC24M_MISC0, field RTC_RINGOSC_EN */

#define BP_XTALOSC24M_MISC0_RTC_RINGOSC_EN      13
#define BM_XTALOSC24M_MISC0_RTC_RINGOSC_EN      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_XTALOSC24M_MISC0_RTC_RINGOSC_EN(v)   ((((reg32_t) v) << 13) & BM_XTALOSC24M_MISC0_RTC_RINGOSC_EN)
#else
#define BF_XTALOSC24M_MISC0_RTC_RINGOSC_EN(v)   (((v) << 13) & BM_XTALOSC24M_MISC0_RTC_RINGOSC_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_XTALOSC24M_MISC0_RTC_RINGOSC_EN(v)   BF_CS1(XTALOSC24M_MISC0, RTC_RINGOSC_EN, v)
#endif

/* --- Register HW_XTALOSC24M_MISC0, field STOP_MODE_CONFIG */

#define BP_XTALOSC24M_MISC0_STOP_MODE_CONFIG      12
#define BM_XTALOSC24M_MISC0_STOP_MODE_CONFIG      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_XTALOSC24M_MISC0_STOP_MODE_CONFIG(v)   ((((reg32_t) v) << 12) & BM_XTALOSC24M_MISC0_STOP_MODE_CONFIG)
#else
#define BF_XTALOSC24M_MISC0_STOP_MODE_CONFIG(v)   (((v) << 12) & BM_XTALOSC24M_MISC0_STOP_MODE_CONFIG)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_XTALOSC24M_MISC0_STOP_MODE_CONFIG(v)   BF_CS1(XTALOSC24M_MISC0, STOP_MODE_CONFIG, v)
#endif

/* --- Register HW_XTALOSC24M_MISC0, field REFTOP_BIAS_TST */

#define BP_XTALOSC24M_MISC0_REFTOP_BIAS_TST      8
#define BM_XTALOSC24M_MISC0_REFTOP_BIAS_TST      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_XTALOSC24M_MISC0_REFTOP_BIAS_TST(v)   ((((reg32_t) v) << 8) & BM_XTALOSC24M_MISC0_REFTOP_BIAS_TST)
#else
#define BF_XTALOSC24M_MISC0_REFTOP_BIAS_TST(v)   (((v) << 8) & BM_XTALOSC24M_MISC0_REFTOP_BIAS_TST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_XTALOSC24M_MISC0_REFTOP_BIAS_TST(v)   BF_CS1(XTALOSC24M_MISC0, REFTOP_BIAS_TST, v)
#endif

/* --- Register HW_XTALOSC24M_MISC0, field REFTOP_VBGUP */

#define BP_XTALOSC24M_MISC0_REFTOP_VBGUP      7
#define BM_XTALOSC24M_MISC0_REFTOP_VBGUP      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_XTALOSC24M_MISC0_REFTOP_VBGUP(v)   ((((reg32_t) v) << 7) & BM_XTALOSC24M_MISC0_REFTOP_VBGUP)
#else
#define BF_XTALOSC24M_MISC0_REFTOP_VBGUP(v)   (((v) << 7) & BM_XTALOSC24M_MISC0_REFTOP_VBGUP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_XTALOSC24M_MISC0_REFTOP_VBGUP(v)   BF_CS1(XTALOSC24M_MISC0, REFTOP_VBGUP, v)
#endif

/* --- Register HW_XTALOSC24M_MISC0, field REFTOP_VBGADJ */

#define BP_XTALOSC24M_MISC0_REFTOP_VBGADJ      4
#define BM_XTALOSC24M_MISC0_REFTOP_VBGADJ      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_XTALOSC24M_MISC0_REFTOP_VBGADJ(v)   ((((reg32_t) v) << 4) & BM_XTALOSC24M_MISC0_REFTOP_VBGADJ)
#else
#define BF_XTALOSC24M_MISC0_REFTOP_VBGADJ(v)   (((v) << 4) & BM_XTALOSC24M_MISC0_REFTOP_VBGADJ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_XTALOSC24M_MISC0_REFTOP_VBGADJ(v)   BF_CS1(XTALOSC24M_MISC0, REFTOP_VBGADJ, v)
#endif

/* --- Register HW_XTALOSC24M_MISC0, field REFTOP_SELFBIASOFF */

#define BP_XTALOSC24M_MISC0_REFTOP_SELFBIASOFF      3
#define BM_XTALOSC24M_MISC0_REFTOP_SELFBIASOFF      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_XTALOSC24M_MISC0_REFTOP_SELFBIASOFF(v)   ((((reg32_t) v) << 3) & BM_XTALOSC24M_MISC0_REFTOP_SELFBIASOFF)
#else
#define BF_XTALOSC24M_MISC0_REFTOP_SELFBIASOFF(v)   (((v) << 3) & BM_XTALOSC24M_MISC0_REFTOP_SELFBIASOFF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_XTALOSC24M_MISC0_REFTOP_SELFBIASOFF(v)   BF_CS1(XTALOSC24M_MISC0, REFTOP_SELFBIASOFF, v)
#endif

/* --- Register HW_XTALOSC24M_MISC0, field REFTOP_LOWPOWER */

#define BP_XTALOSC24M_MISC0_REFTOP_LOWPOWER      2
#define BM_XTALOSC24M_MISC0_REFTOP_LOWPOWER      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_XTALOSC24M_MISC0_REFTOP_LOWPOWER(v)   ((((reg32_t) v) << 2) & BM_XTALOSC24M_MISC0_REFTOP_LOWPOWER)
#else
#define BF_XTALOSC24M_MISC0_REFTOP_LOWPOWER(v)   (((v) << 2) & BM_XTALOSC24M_MISC0_REFTOP_LOWPOWER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_XTALOSC24M_MISC0_REFTOP_LOWPOWER(v)   BF_CS1(XTALOSC24M_MISC0, REFTOP_LOWPOWER, v)
#endif

/* --- Register HW_XTALOSC24M_MISC0, field REFTOP_PWDVBGUP */

#define BP_XTALOSC24M_MISC0_REFTOP_PWDVBGUP      1
#define BM_XTALOSC24M_MISC0_REFTOP_PWDVBGUP      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_XTALOSC24M_MISC0_REFTOP_PWDVBGUP(v)   ((((reg32_t) v) << 1) & BM_XTALOSC24M_MISC0_REFTOP_PWDVBGUP)
#else
#define BF_XTALOSC24M_MISC0_REFTOP_PWDVBGUP(v)   (((v) << 1) & BM_XTALOSC24M_MISC0_REFTOP_PWDVBGUP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_XTALOSC24M_MISC0_REFTOP_PWDVBGUP(v)   BF_CS1(XTALOSC24M_MISC0, REFTOP_PWDVBGUP, v)
#endif

/* --- Register HW_XTALOSC24M_MISC0, field REFTOP_PWD */

#define BP_XTALOSC24M_MISC0_REFTOP_PWD      0
#define BM_XTALOSC24M_MISC0_REFTOP_PWD      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_XTALOSC24M_MISC0_REFTOP_PWD(v)   ((((reg32_t) v) << 0) & BM_XTALOSC24M_MISC0_REFTOP_PWD)
#else
#define BF_XTALOSC24M_MISC0_REFTOP_PWD(v)   (((v) << 0) & BM_XTALOSC24M_MISC0_REFTOP_PWD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_XTALOSC24M_MISC0_REFTOP_PWD(v)   BF_CS1(XTALOSC24M_MISC0, REFTOP_PWD, v)
#endif


#endif // _XTALOSC24M_H

