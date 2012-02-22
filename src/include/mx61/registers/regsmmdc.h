/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _MMDC_H
#define _MMDC_H

#include "regs.h"

#ifndef REGS_MMDC_BASE
#define REGS_MMDC_BASE (REGS_BASE + 0x00000000)
#endif


/*!
 * @brief HW_MMDC_MDCTL - MMDC Core Control Register
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 16; //!< Reserved
        unsigned DSIZ : 2; //!< DDR data bus size. This field determines the size of the data bus of the DDR memory
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned BL : 1; //!< Burst Length. This field determines the burst length of the DDR device.  In DDR2/ LPDDR2 mode the MMDC supports burst length 4.  In DDR3 mode the MMDC supports burst length 8.
        unsigned COL : 3; //!< Column Address Width. This field specifies the number of column addresses used by the memory array. It will determine how an incoming address will be decoded.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned ROW : 3; //!< Row Address Width. This field specifies the number of row addresses used by the memory array.  It will affect the way an incoming address will be decoded.  Settings 110-111 are reserved
        unsigned RESERVED3 : 3; //!< Reserved
        unsigned SDE_1 : 1; //!< MMDC Enable CS1. This bit enables/disables accesses from the MMDC toward Chip Select 1. The reset value of this bit is "0" (i.e No clocks and clock enable will be driven to the memory).  At the enabling point the MMDC will perform an initialization process (including a delay on RESET and/or CKE) for both chip selects. The initialization length depends on the configured memory type.
        unsigned SDE_0 : 1; //!< MMDC Enable CS0. This bit enables/disables accesses from the MMDC toward Chip Select 0. The reset value of this bit is "0" (i.e No clocks and clock enable will be driven to the memory).  At the enabling point the MMDC will perform an initialization process (including a delay on RESET and/or CKE) for both chip selects. The initialization length depends on the configured memory type.
    } B;
} hw_mmdc_mdctl_t;
#endif

/*
 * constants & macros for entire MMDC_MDCTL register
 */
#define HW_MMDC_MDCTL_ADDR      (REGS_MMDC_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MDCTL           (*(volatile hw_mmdc_mdctl_t *) HW_MMDC_MDCTL_ADDR)
#define HW_MMDC_MDCTL_RD()      (HW_MMDC_MDCTL.U)
#define HW_MMDC_MDCTL_WR(v)     (HW_MMDC_MDCTL.U = (v))
#define HW_MMDC_MDCTL_SET(v)    (HW_MMDC_MDCTL_WR(HW_MMDC_MDCTL_RD() |  (v)))
#define HW_MMDC_MDCTL_CLR(v)    (HW_MMDC_MDCTL_WR(HW_MMDC_MDCTL_RD() & ~(v)))
#define HW_MMDC_MDCTL_TOG(v)    (HW_MMDC_MDCTL_WR(HW_MMDC_MDCTL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MDCTL bitfields
 */

/* --- Register HW_MMDC_MDCTL, field DSIZ
 *
 * DDR data bus size. This field determines the size of the data bus of
 * the DDR memory
 */

#define BP_MMDC_MDCTL_DSIZ      16
#define BM_MMDC_MDCTL_DSIZ      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCTL_DSIZ(v)   ((((reg32_t) v) << 16) & BM_MMDC_MDCTL_DSIZ)
#else
#define BF_MMDC_MDCTL_DSIZ(v)   (((v) << 16) & BM_MMDC_MDCTL_DSIZ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCTL_DSIZ(v)   BF_CS1(MMDC_MDCTL, DSIZ, v)
#endif

/* --- Register HW_MMDC_MDCTL, field BL
 *
 * Burst Length. This field determines the burst length of the DDR
 * device.  In DDR2/ LPDDR2 mode the MMDC supports                                 burst length 4.
 * In DDR3 mode the MMDC supports burst length 8.
 */

#define BP_MMDC_MDCTL_BL      19
#define BM_MMDC_MDCTL_BL      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCTL_BL(v)   ((((reg32_t) v) << 19) & BM_MMDC_MDCTL_BL)
#else
#define BF_MMDC_MDCTL_BL(v)   (((v) << 19) & BM_MMDC_MDCTL_BL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCTL_BL(v)   BF_CS1(MMDC_MDCTL, BL, v)
#endif

/* --- Register HW_MMDC_MDCTL, field COL
 *
 * Column Address Width. This field specifies the number of column
 * addresses used by the memory array. It will determine how an
 * incoming address will be decoded.
 */

#define BP_MMDC_MDCTL_COL      20
#define BM_MMDC_MDCTL_COL      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCTL_COL(v)   ((((reg32_t) v) << 20) & BM_MMDC_MDCTL_COL)
#else
#define BF_MMDC_MDCTL_COL(v)   (((v) << 20) & BM_MMDC_MDCTL_COL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCTL_COL(v)   BF_CS1(MMDC_MDCTL, COL, v)
#endif

/* --- Register HW_MMDC_MDCTL, field ROW
 *
 * Row Address Width. This field specifies the number of row addresses
 * used by the memory array.  It will affect the way an incoming address will be decoded.  Settings
 * 110-111 are reserved
 */

#define BP_MMDC_MDCTL_ROW      24
#define BM_MMDC_MDCTL_ROW      0x07000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCTL_ROW(v)   ((((reg32_t) v) << 24) & BM_MMDC_MDCTL_ROW)
#else
#define BF_MMDC_MDCTL_ROW(v)   (((v) << 24) & BM_MMDC_MDCTL_ROW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCTL_ROW(v)   BF_CS1(MMDC_MDCTL, ROW, v)
#endif

/* --- Register HW_MMDC_MDCTL, field SDE_1
 *
 * MMDC Enable CS1. This bit enables/disables accesses from the MMDC
 * toward Chip Select 1. The reset value of this bit is "0" (i.e No
 * clocks and clock enable will be driven to the memory).  At the enabling point the MMDC will
 * perform an initialization process                                 (including a delay on RESET
 * and/or CKE) for both chip selects. The                                 initialization length
 * depends on the configured memory type.
 */

#define BP_MMDC_MDCTL_SDE_1      30
#define BM_MMDC_MDCTL_SDE_1      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCTL_SDE_1(v)   ((((reg32_t) v) << 30) & BM_MMDC_MDCTL_SDE_1)
#else
#define BF_MMDC_MDCTL_SDE_1(v)   (((v) << 30) & BM_MMDC_MDCTL_SDE_1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCTL_SDE_1(v)   BF_CS1(MMDC_MDCTL, SDE_1, v)
#endif

/* --- Register HW_MMDC_MDCTL, field SDE_0
 *
 * MMDC Enable CS0. This bit enables/disables accesses from the MMDC
 * toward Chip Select 0. The reset value of this bit is "0" (i.e No
 * clocks and clock enable will be driven to the memory).  At the enabling point the MMDC will
 * perform an initialization process                                 (including a delay on RESET
 * and/or CKE) for both chip selects. The                                 initialization length
 * depends on the configured memory type.
 */

#define BP_MMDC_MDCTL_SDE_0      31
#define BM_MMDC_MDCTL_SDE_0      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCTL_SDE_0(v)   ((((reg32_t) v) << 31) & BM_MMDC_MDCTL_SDE_0)
#else
#define BF_MMDC_MDCTL_SDE_0(v)   (((v) << 31) & BM_MMDC_MDCTL_SDE_0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCTL_SDE_0(v)   BF_CS1(MMDC_MDCTL, SDE_0, v)
#endif

/*!
 * @brief HW_MMDC_MDPDC - MMDC Core Power Down Control Register
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: LP2_2ch_x16, LP2_2ch_x32   PRCT
 * field encoding        PRCT[2:0]    Precharge Timer        000    Disabled (Bit field reset
 * value)      001    2 clocks      010    4 clocks      011    8 clocks      100    16 clocks
 * 101    32 clocks      110    64 clocks      111    128 clocks         PWDT field encoding
 * PWDT[3:0]    Power Down Time-out        0000    Disabled (bit field reset
 * value)      0001    16 cycles      0010    32 cycles      0011    64 cycles      0100    128
 * cycles      0101    256 cycles      0110    512 cycles      0111    1024 cycles      1000    2048
 * cycles      1001    4096 cycles      1010    8196 cycles      1011    16384 cycles      1100
 * 32768 cycles      1101-1111    Reserved
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TCKSRE : 3; //!< Valid clock cycles after self-refresh entry.  This field determines the amount of clock cycles after self-refresh entry
        unsigned TCKSRX : 3; //!< Valid clock cycles before self-refresh exit. This field determines the amount of clock cycles before self-refresh exit
        unsigned BOTH_CS_PD : 1; //!< Parallel power down entry to both chip selects.  When power down timer is used for both chip-selects (i.e PWDT_0 and PWDT1 don't equal "0") , then if this bit is enabled, the MMDC will enter power down only if the amount of idle cycles of both chip selects was obtained.
        unsigned SLOW_PD : 1; //!< Slow/fast power down.  In DDR3 mode this field is referred to slow precharge power-down.  In DDR2 mode this field is referred to slow active power-down.  In LPDDR2 mode this field is not relevant.  Memory should be configured the same.
        unsigned PWDT_0 : 4; //!< Power Down Timer - Chip Select 0.  This field determines the amount of idle cycle for which chip select 0 will be automatically get into precharge/active power down. The amount of cycles are determined according to the PWDT Field Encoding table above.
        unsigned PWDT_1 : 4; //!< Power Down Timer - Chip Select 1.  This field determines the amount of idle cycle for which chip select 1 will be automatically get into precharge/active power down. The amount of cycles are determined according to the PWDT Field Encoding table above.
        unsigned TCKE : 3; //!< CKE minimum pulse width. This field determines the minimum pulse width of CKE.
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned PRCT_0 : 3; //!< Precharge Timer - Chip Select 0.  This field determines the amount of idle cycle for which chip select 0 will be automatically precharged. The amount of cycles are determined according to the table below.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned PRCT_1 : 3; //!< Precharge Timer - Chip Select 1.  This field determines the amount of idle cycle for which chip select 1 will be automatically precharged. The amount of cycles are determined according to the PRCT Field Encoding table above.
        unsigned RESERVED2 : 1; //!< Reserved
    } B;
} hw_mmdc_mdpdc_t;
#endif

/*
 * constants & macros for entire MMDC_MDPDC register
 */
#define HW_MMDC_MDPDC_ADDR      (REGS_MMDC_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MDPDC           (*(volatile hw_mmdc_mdpdc_t *) HW_MMDC_MDPDC_ADDR)
#define HW_MMDC_MDPDC_RD()      (HW_MMDC_MDPDC.U)
#define HW_MMDC_MDPDC_WR(v)     (HW_MMDC_MDPDC.U = (v))
#define HW_MMDC_MDPDC_SET(v)    (HW_MMDC_MDPDC_WR(HW_MMDC_MDPDC_RD() |  (v)))
#define HW_MMDC_MDPDC_CLR(v)    (HW_MMDC_MDPDC_WR(HW_MMDC_MDPDC_RD() & ~(v)))
#define HW_MMDC_MDPDC_TOG(v)    (HW_MMDC_MDPDC_WR(HW_MMDC_MDPDC_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MDPDC bitfields
 */

/* --- Register HW_MMDC_MDPDC, field TCKSRE
 *
 * Valid clock cycles after self-refresh entry.  This field determines the amount of clock cycles
 * after self-refresh                                 entry
 */

#define BP_MMDC_MDPDC_TCKSRE      0
#define BM_MMDC_MDPDC_TCKSRE      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDPDC_TCKSRE(v)   ((((reg32_t) v) << 0) & BM_MMDC_MDPDC_TCKSRE)
#else
#define BF_MMDC_MDPDC_TCKSRE(v)   (((v) << 0) & BM_MMDC_MDPDC_TCKSRE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDPDC_TCKSRE(v)   BF_CS1(MMDC_MDPDC, TCKSRE, v)
#endif

/* --- Register HW_MMDC_MDPDC, field TCKSRX
 *
 * Valid clock cycles before self-refresh exit. This field determines
 * the amount of clock cycles before self-refresh exit
 */

#define BP_MMDC_MDPDC_TCKSRX      3
#define BM_MMDC_MDPDC_TCKSRX      0x00000038

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDPDC_TCKSRX(v)   ((((reg32_t) v) << 3) & BM_MMDC_MDPDC_TCKSRX)
#else
#define BF_MMDC_MDPDC_TCKSRX(v)   (((v) << 3) & BM_MMDC_MDPDC_TCKSRX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDPDC_TCKSRX(v)   BF_CS1(MMDC_MDPDC, TCKSRX, v)
#endif

/* --- Register HW_MMDC_MDPDC, field BOTH_CS_PD
 *
 * Parallel power down entry to both chip selects.  When power down timer is used for both chip-
 * selects (i.e PWDT_0 and                                 PWDT1 don't equal "0") , then if this bit
 * is enabled, the MMDC will                                 enter power down only if the amount of
 * idle cycles of both chip                                 selects was obtained.
 */

#define BP_MMDC_MDPDC_BOTH_CS_PD      6
#define BM_MMDC_MDPDC_BOTH_CS_PD      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDPDC_BOTH_CS_PD(v)   ((((reg32_t) v) << 6) & BM_MMDC_MDPDC_BOTH_CS_PD)
#else
#define BF_MMDC_MDPDC_BOTH_CS_PD(v)   (((v) << 6) & BM_MMDC_MDPDC_BOTH_CS_PD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDPDC_BOTH_CS_PD(v)   BF_CS1(MMDC_MDPDC, BOTH_CS_PD, v)
#endif

/* --- Register HW_MMDC_MDPDC, field SLOW_PD
 *
 * Slow/fast power down.  In DDR3 mode this field is referred to slow precharge power-down.  In DDR2
 * mode this field is referred to slow                                 active power-down.  In LPDDR2
 * mode this field is not relevant.  Memory should be configured the same.
 */

#define BP_MMDC_MDPDC_SLOW_PD      7
#define BM_MMDC_MDPDC_SLOW_PD      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDPDC_SLOW_PD(v)   ((((reg32_t) v) << 7) & BM_MMDC_MDPDC_SLOW_PD)
#else
#define BF_MMDC_MDPDC_SLOW_PD(v)   (((v) << 7) & BM_MMDC_MDPDC_SLOW_PD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDPDC_SLOW_PD(v)   BF_CS1(MMDC_MDPDC, SLOW_PD, v)
#endif

/* --- Register HW_MMDC_MDPDC, field PWDT_0
 *
 * Power Down Timer - Chip Select 0.  This field determines the amount of idle cycle for which chip
 * select                                 0 will be automatically get into precharge/active power
 * down. The amount of cycles are determined according to the PWDT Field Encoding table above.
 */

#define BP_MMDC_MDPDC_PWDT_0      8
#define BM_MMDC_MDPDC_PWDT_0      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDPDC_PWDT_0(v)   ((((reg32_t) v) << 8) & BM_MMDC_MDPDC_PWDT_0)
#else
#define BF_MMDC_MDPDC_PWDT_0(v)   (((v) << 8) & BM_MMDC_MDPDC_PWDT_0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDPDC_PWDT_0(v)   BF_CS1(MMDC_MDPDC, PWDT_0, v)
#endif

/* --- Register HW_MMDC_MDPDC, field PWDT_1
 *
 * Power Down Timer - Chip Select 1.  This field determines the amount of idle cycle for which chip
 * select                                 1 will be automatically get into precharge/active power
 * down. The                                 amount of cycles are determined according to the PWDT
 * Field Encoding table above.
 */

#define BP_MMDC_MDPDC_PWDT_1      12
#define BM_MMDC_MDPDC_PWDT_1      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDPDC_PWDT_1(v)   ((((reg32_t) v) << 12) & BM_MMDC_MDPDC_PWDT_1)
#else
#define BF_MMDC_MDPDC_PWDT_1(v)   (((v) << 12) & BM_MMDC_MDPDC_PWDT_1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDPDC_PWDT_1(v)   BF_CS1(MMDC_MDPDC, PWDT_1, v)
#endif

/* --- Register HW_MMDC_MDPDC, field TCKE
 *
 * CKE minimum pulse width. This field determines the minimum pulse
 * width of CKE.
 */

#define BP_MMDC_MDPDC_TCKE      16
#define BM_MMDC_MDPDC_TCKE      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDPDC_TCKE(v)   ((((reg32_t) v) << 16) & BM_MMDC_MDPDC_TCKE)
#else
#define BF_MMDC_MDPDC_TCKE(v)   (((v) << 16) & BM_MMDC_MDPDC_TCKE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDPDC_TCKE(v)   BF_CS1(MMDC_MDPDC, TCKE, v)
#endif

/* --- Register HW_MMDC_MDPDC, field PRCT_0
 *
 * Precharge Timer - Chip Select 0.  This field determines the amount of idle cycle for which chip
 * select                                 0 will be automatically precharged. The amount of cycles
 * are                                 determined according to the table below.
 */

#define BP_MMDC_MDPDC_PRCT_0      24
#define BM_MMDC_MDPDC_PRCT_0      0x07000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDPDC_PRCT_0(v)   ((((reg32_t) v) << 24) & BM_MMDC_MDPDC_PRCT_0)
#else
#define BF_MMDC_MDPDC_PRCT_0(v)   (((v) << 24) & BM_MMDC_MDPDC_PRCT_0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDPDC_PRCT_0(v)   BF_CS1(MMDC_MDPDC, PRCT_0, v)
#endif

/* --- Register HW_MMDC_MDPDC, field PRCT_1
 *
 * Precharge Timer - Chip Select 1.  This field determines the amount of idle cycle for which chip
 * select                                 1 will be automatically precharged. The amount of cycles
 * are                                 determined according to the PRCT Field Encoding table above.
 */

#define BP_MMDC_MDPDC_PRCT_1      28
#define BM_MMDC_MDPDC_PRCT_1      0x70000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDPDC_PRCT_1(v)   ((((reg32_t) v) << 28) & BM_MMDC_MDPDC_PRCT_1)
#else
#define BF_MMDC_MDPDC_PRCT_1(v)   (((v) << 28) & BM_MMDC_MDPDC_PRCT_1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDPDC_PRCT_1(v)   BF_CS1(MMDC_MDPDC, PRCT_1, v)
#endif

/*!
 * @brief HW_MMDC_MDOTC - MMDC Core ODT Timing Control Register
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: LP2_2ch_x16, LP2_2ch_x32  For
 * further information see .
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 4; //!< Reserved
        unsigned TODT_IDLE_OFF : 5; //!< ODT turn off latency. This field determines the Idle period before turning memory ODT off. This field is not relevant in LPDDR2 mode.
        unsigned RESERVED1 : 3; //!< Reserved
        unsigned TODTLON : 3; //!< ODT turn on latency. This field determines the delay between ODT signal and the associated RTT, where according to JEDEC standard it equals WL(write latency) - 2. Therefore, the value that is configured to tODTLon field should correspond the value that is configured to MDCGFG1[tCWL]  In DDR2 this field is called 'tAOND'  In LPDDR2 this field is not relevant.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned TAXPD : 4; //!< Asynchronous ODT to power down exit delay. In DDR3 should be set to tCWL-1  In DDR2 mode this field is referred to ODT power down exit latency.  This field is not relevant in LPDDR2 mode.
        unsigned TANPD : 4; //!< Asynchronous ODT to power down entry delay. In DDR3 should be set to tCWL-1  In DDR2 mode this field is referred to ODT to power down entry latency.  This field is not relevant in LPDDR2 mode.
        unsigned TAONPD : 3; //!< Asynchronous RTT turn-on delay (power down with DLL frozen). This field determines the time between termination cuircuit gets out of high impedance and begins to turn on till ODT resistance are fully on.  In DDR2 mode his field is referred to ODT turn-on (power down mode) max value.  This field is not relevant in LPDDR2 mode.
        unsigned TAOFPD : 3; //!< Asynchronous RTT turn-off delay (power down with DLL frozen). This field determines the time between termination cuircuit starts to turn off the ODT resistance till termination has reached high impedance.  DDR2: ODT turn-off (power down mode) max value.  This field is not relevant in LPDDR2 mode.
        unsigned RESERVED3 : 2; //!< Reserved
    } B;
} hw_mmdc_mdotc_t;
#endif

/*
 * constants & macros for entire MMDC_MDOTC register
 */
#define HW_MMDC_MDOTC_ADDR      (REGS_MMDC_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MDOTC           (*(volatile hw_mmdc_mdotc_t *) HW_MMDC_MDOTC_ADDR)
#define HW_MMDC_MDOTC_RD()      (HW_MMDC_MDOTC.U)
#define HW_MMDC_MDOTC_WR(v)     (HW_MMDC_MDOTC.U = (v))
#define HW_MMDC_MDOTC_SET(v)    (HW_MMDC_MDOTC_WR(HW_MMDC_MDOTC_RD() |  (v)))
#define HW_MMDC_MDOTC_CLR(v)    (HW_MMDC_MDOTC_WR(HW_MMDC_MDOTC_RD() & ~(v)))
#define HW_MMDC_MDOTC_TOG(v)    (HW_MMDC_MDOTC_WR(HW_MMDC_MDOTC_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MDOTC bitfields
 */

/* --- Register HW_MMDC_MDOTC, field TODT_IDLE_OFF
 *
 * ODT turn off latency. This field determines the Idle period before
 * turning memory ODT off. This field is not relevant in LPDDR2
 * mode.
 */

#define BP_MMDC_MDOTC_TODT_IDLE_OFF      4
#define BM_MMDC_MDOTC_TODT_IDLE_OFF      0x000001f0

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDOTC_TODT_IDLE_OFF(v)   ((((reg32_t) v) << 4) & BM_MMDC_MDOTC_TODT_IDLE_OFF)
#else
#define BF_MMDC_MDOTC_TODT_IDLE_OFF(v)   (((v) << 4) & BM_MMDC_MDOTC_TODT_IDLE_OFF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDOTC_TODT_IDLE_OFF(v)   BF_CS1(MMDC_MDOTC, TODT_IDLE_OFF, v)
#endif

/* --- Register HW_MMDC_MDOTC, field TODTLON
 *
 * ODT turn on latency. This field determines the delay between ODT
 * signal and the associated RTT, where according to JEDEC standard it
 * equals WL(write latency) - 2. Therefore, the value that is
 * configured to tODTLon field should correspond the value that is
 * configured to MDCGFG1[tCWL]  In DDR2 this field is called 'tAOND'  In LPDDR2 this field is not
 * relevant.
 */

#define BP_MMDC_MDOTC_TODTLON      12
#define BM_MMDC_MDOTC_TODTLON      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDOTC_TODTLON(v)   ((((reg32_t) v) << 12) & BM_MMDC_MDOTC_TODTLON)
#else
#define BF_MMDC_MDOTC_TODTLON(v)   (((v) << 12) & BM_MMDC_MDOTC_TODTLON)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDOTC_TODTLON(v)   BF_CS1(MMDC_MDOTC, TODTLON, v)
#endif

/* --- Register HW_MMDC_MDOTC, field TAXPD
 *
 * Asynchronous ODT to power down exit delay. In DDR3 should be set to
 * tCWL-1  In DDR2 mode this field is referred to ODT power                                 down
 * exit latency.  This field is not relevant in LPDDR2 mode.
 */

#define BP_MMDC_MDOTC_TAXPD      16
#define BM_MMDC_MDOTC_TAXPD      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDOTC_TAXPD(v)   ((((reg32_t) v) << 16) & BM_MMDC_MDOTC_TAXPD)
#else
#define BF_MMDC_MDOTC_TAXPD(v)   (((v) << 16) & BM_MMDC_MDOTC_TAXPD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDOTC_TAXPD(v)   BF_CS1(MMDC_MDOTC, TAXPD, v)
#endif

/* --- Register HW_MMDC_MDOTC, field TANPD
 *
 * Asynchronous ODT to power down entry delay. In DDR3 should be set to
 * tCWL-1  In DDR2 mode this field is referred to ODT to                                 power down
 * entry latency.  This field is not relevant in LPDDR2 mode.
 */

#define BP_MMDC_MDOTC_TANPD      20
#define BM_MMDC_MDOTC_TANPD      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDOTC_TANPD(v)   ((((reg32_t) v) << 20) & BM_MMDC_MDOTC_TANPD)
#else
#define BF_MMDC_MDOTC_TANPD(v)   (((v) << 20) & BM_MMDC_MDOTC_TANPD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDOTC_TANPD(v)   BF_CS1(MMDC_MDOTC, TANPD, v)
#endif

/* --- Register HW_MMDC_MDOTC, field TAONPD
 *
 * Asynchronous RTT turn-on delay (power down with DLL frozen). This
 * field determines the time between termination cuircuit gets out of
 * high impedance and begins to turn on till ODT resistance are fully
 * on.  In DDR2 mode his field is referred to ODT turn-on                                 (power
 * down mode) max value.  This field is not relevant in LPDDR2 mode.
 */

#define BP_MMDC_MDOTC_TAONPD      24
#define BM_MMDC_MDOTC_TAONPD      0x07000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDOTC_TAONPD(v)   ((((reg32_t) v) << 24) & BM_MMDC_MDOTC_TAONPD)
#else
#define BF_MMDC_MDOTC_TAONPD(v)   (((v) << 24) & BM_MMDC_MDOTC_TAONPD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDOTC_TAONPD(v)   BF_CS1(MMDC_MDOTC, TAONPD, v)
#endif

/* --- Register HW_MMDC_MDOTC, field TAOFPD
 *
 * Asynchronous RTT turn-off delay (power down with DLL frozen). This
 * field determines the time between termination cuircuit starts to
 * turn off the ODT resistance till termination has reached high
 * impedance.  DDR2: ODT turn-off (power down mode) max                                 value.  This
 * field is not relevant in LPDDR2 mode.
 */

#define BP_MMDC_MDOTC_TAOFPD      27
#define BM_MMDC_MDOTC_TAOFPD      0x38000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDOTC_TAOFPD(v)   ((((reg32_t) v) << 27) & BM_MMDC_MDOTC_TAOFPD)
#else
#define BF_MMDC_MDOTC_TAOFPD(v)   (((v) << 27) & BM_MMDC_MDOTC_TAOFPD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDOTC_TAOFPD(v)   BF_CS1(MMDC_MDOTC, TAOFPD, v)
#endif

/*!
 * @brief HW_MMDC_MDCFG0 - MMDC Core Timing Configuration Register 0
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TCL : 4; //!< CAS Read Latency.  In DDR3 mode this field is referred to CL.  In LPDDR2 /DDR2 mode this field is referred to RL.  In LPDDR2 mode only the RL/WL pairs are allowed as specified in MR2 register  See DDR2 SDRAM Specification JESD79-2E (April 2008) , to DDR3 SDRAM Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) for a detailed description of this parameter.
        unsigned TFAW : 5; //!< Four Active Window (all banks).  See DDR2 SDRAM Specification JESD79-2E (April 2008), to DDR3 SDRAM Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) for a detailed description of this parameter.
        unsigned TXPDLL : 4; //!< Exit precharge power down with DLL frozen to commands requiring DLL.  This field is not relevant in LPDDR2 mode.  In DDR2 mode this field is referred to the time from exit active power down to read commands(tXARD/tXARDS depending to memory configuration)  See DDR2 SDRAM Specification JESD79-2E (April 2008) , to DDR3 SDRAM Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) for a detailed description of this parameter.
        unsigned TXP : 3; //!< Exit power down with DLL-on to any valid command. Exit power down with DLL-frozen to commands not requiring a locked DLL   In DDR2 mode this field is referred to Exit precharge power down to any command.   In LPDDR2 mode this field is referred to Exit power-down to next valid command delay.  See DDR2 SDRAM Specification JESD79-2E (April 2008), to DDR3 SDRAM Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) for a detailed description of this parameter.
        unsigned TXS : 8; //!< Exit self refresh to non READ command. (Named tXSNR in DDR2 devices) In LPDDR2 it is called tXSR, self-refresh exit to next valid command delay.  See DDR2 SDRAM Specification JESD79-2E (April 2008), to DDR3 SDRAM Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) for a detailed description of this parameter.
        unsigned TRFC : 8; //!< Refresh command to Active or Refresh command time.  See DDR2 SDRAM Specification JESD79-2E (April 2008) , to DDR3 SDRAM Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) for a detailed description of this parameter.
    } B;
} hw_mmdc_mdcfg0_t;
#endif

/*
 * constants & macros for entire MMDC_MDCFG0 register
 */
#define HW_MMDC_MDCFG0_ADDR      (REGS_MMDC_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MDCFG0           (*(volatile hw_mmdc_mdcfg0_t *) HW_MMDC_MDCFG0_ADDR)
#define HW_MMDC_MDCFG0_RD()      (HW_MMDC_MDCFG0.U)
#define HW_MMDC_MDCFG0_WR(v)     (HW_MMDC_MDCFG0.U = (v))
#define HW_MMDC_MDCFG0_SET(v)    (HW_MMDC_MDCFG0_WR(HW_MMDC_MDCFG0_RD() |  (v)))
#define HW_MMDC_MDCFG0_CLR(v)    (HW_MMDC_MDCFG0_WR(HW_MMDC_MDCFG0_RD() & ~(v)))
#define HW_MMDC_MDCFG0_TOG(v)    (HW_MMDC_MDCFG0_WR(HW_MMDC_MDCFG0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MDCFG0 bitfields
 */

/* --- Register HW_MMDC_MDCFG0, field TCL
 *
 * CAS Read Latency.  In DDR3 mode this field is referred to CL.  In LPDDR2 /DDR2 mode this field is
 * referred to RL.  In LPDDR2 mode only the RL/WL pairs are allowed as specified in
 * MR2 register  See DDR2 SDRAM Specification JESD79-2E (April 2008) , to DDR3 SDRAM
 * Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification
 * JESD209-2B (February 2010) for a detailed description of this
 * parameter.
 */

#define BP_MMDC_MDCFG0_TCL      0
#define BM_MMDC_MDCFG0_TCL      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCFG0_TCL(v)   ((((reg32_t) v) << 0) & BM_MMDC_MDCFG0_TCL)
#else
#define BF_MMDC_MDCFG0_TCL(v)   (((v) << 0) & BM_MMDC_MDCFG0_TCL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCFG0_TCL(v)   BF_CS1(MMDC_MDCFG0, TCL, v)
#endif

/* --- Register HW_MMDC_MDCFG0, field TFAW
 *
 * Four Active Window (all banks).  See DDR2 SDRAM Specification JESD79-2E (April 2008), to DDR3
 * SDRAM                                 Specification JESD79-3E (July 2010) and LPDDR2 SDRAM
 * Specification                                 JESD209-2B (February 2010) and LPDDR2 SDRAM
 * Specification JESD209-2B                                 (February 2010) for a detailed
 * description of this parameter.
 */

#define BP_MMDC_MDCFG0_TFAW      4
#define BM_MMDC_MDCFG0_TFAW      0x000001f0

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCFG0_TFAW(v)   ((((reg32_t) v) << 4) & BM_MMDC_MDCFG0_TFAW)
#else
#define BF_MMDC_MDCFG0_TFAW(v)   (((v) << 4) & BM_MMDC_MDCFG0_TFAW)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCFG0_TFAW(v)   BF_CS1(MMDC_MDCFG0, TFAW, v)
#endif

/* --- Register HW_MMDC_MDCFG0, field TXPDLL
 *
 * Exit precharge power down with DLL frozen to commands requiring
 * DLL.  This field is not relevant in LPDDR2 mode.  In DDR2 mode this field is referred to the time
 * from exit active power down to read commands(tXARD/tXARDS depending
 * to memory configuration)  See DDR2 SDRAM Specification JESD79-2E (April 2008) , to DDR3 SDRAM
 * Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification
 * JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B
 * (February 2010) for a detailed description of this parameter.
 */

#define BP_MMDC_MDCFG0_TXPDLL      9
#define BM_MMDC_MDCFG0_TXPDLL      0x00001e00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCFG0_TXPDLL(v)   ((((reg32_t) v) << 9) & BM_MMDC_MDCFG0_TXPDLL)
#else
#define BF_MMDC_MDCFG0_TXPDLL(v)   (((v) << 9) & BM_MMDC_MDCFG0_TXPDLL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCFG0_TXPDLL(v)   BF_CS1(MMDC_MDCFG0, TXPDLL, v)
#endif

/* --- Register HW_MMDC_MDCFG0, field TXP
 *
 * Exit power down with DLL-on to any valid command. Exit power down
 * with DLL-frozen to commands not requiring a locked DLL   In DDR2 mode this field is referred to
 * Exit                                     precharge power down to any command.   In LPDDR2 mode
 * this field is referred to Exit power-down to next                                 valid command
 * delay.  See DDR2 SDRAM Specification JESD79-2E (April 2008), to DDR3 SDRAM
 * Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification
 * JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B
 * (February 2010) for a detailed description of this parameter.
 */

#define BP_MMDC_MDCFG0_TXP      13
#define BM_MMDC_MDCFG0_TXP      0x0000e000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCFG0_TXP(v)   ((((reg32_t) v) << 13) & BM_MMDC_MDCFG0_TXP)
#else
#define BF_MMDC_MDCFG0_TXP(v)   (((v) << 13) & BM_MMDC_MDCFG0_TXP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCFG0_TXP(v)   BF_CS1(MMDC_MDCFG0, TXP, v)
#endif

/* --- Register HW_MMDC_MDCFG0, field TXS
 *
 * Exit self refresh to non READ command. (Named                                     tXSNR in DDR2
 * devices) In LPDDR2 it is called tXSR,                                 self-refresh exit to next
 * valid command delay.  See DDR2 SDRAM Specification JESD79-2E (April 2008), to DDR3 SDRAM
 * Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification
 * JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B
 * (February 2010) for a detailed description of this parameter.
 */

#define BP_MMDC_MDCFG0_TXS      16
#define BM_MMDC_MDCFG0_TXS      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCFG0_TXS(v)   ((((reg32_t) v) << 16) & BM_MMDC_MDCFG0_TXS)
#else
#define BF_MMDC_MDCFG0_TXS(v)   (((v) << 16) & BM_MMDC_MDCFG0_TXS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCFG0_TXS(v)   BF_CS1(MMDC_MDCFG0, TXS, v)
#endif

/* --- Register HW_MMDC_MDCFG0, field TRFC
 *
 * Refresh command to Active or Refresh command time.  See DDR2 SDRAM Specification JESD79-2E (April
 * 2008) , to DDR3 SDRAM                                 Specification JESD79-3E (July 2010) and
 * LPDDR2 SDRAM Specification                                 JESD209-2B (February 2010) and LPDDR2
 * SDRAM Specification JESD209-2B                                 (February 2010) for a detailed
 * description of this parameter.
 */

#define BP_MMDC_MDCFG0_TRFC      24
#define BM_MMDC_MDCFG0_TRFC      0xff000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCFG0_TRFC(v)   ((((reg32_t) v) << 24) & BM_MMDC_MDCFG0_TRFC)
#else
#define BF_MMDC_MDCFG0_TRFC(v)   (((v) << 24) & BM_MMDC_MDCFG0_TRFC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCFG0_TRFC(v)   BF_CS1(MMDC_MDCFG0, TRFC, v)
#endif

/*!
 * @brief HW_MMDC_MDCFG1 - MMDC Core Timing Configuration Register 1
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TCWL : 3; //!< CAS Write Latency.  In DDR2 mode this field is referred to WL and equals RL-1.  In DDR3 mode this field is referred to CWL.  In LPDDR2 mode this field is referred to WL.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned TMRD : 4; //!< Mode Register Set command cycle (all banks).  In DDR3 mode this field shoud be set to max (tMRD,tMOD).  In DDR2 mode this field is Set to tMRD.  In LPDDR2 mode this field should be set to max(tMRR,tMRW)  See DDR2 SDRAM Specification JESD79-2E (April 2008) and to DDR3 SDRAM Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) for a detailed description of this parameter.
        unsigned TWR : 3; //!< WRITE recovery time (same bank).  See DDR2 SDRAM Specification JESD79-2E (April 2008) and to DDR3 SDRAM Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) for a detailed description of this parameter.
        unsigned RESERVED1 : 3; //!< Reserved
        unsigned TRPA : 1; //!< Precharge-all command period.  (This field is valid only for DDR2/ DDR3 memories)  In LPDDR2 mode this parameter should be configured at tRPab_LP.  See DDR2 SDRAM Specification JESD79-2E (April 2008) and to DDR3 SDRAM Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) for a detailed description of this parameter.
        unsigned TRAS : 5; //!< Active to Precharge command period (same bank).  See DDR2 SDRAM Specification JESD79-2E (April 2008) and to DDR3 SDRAM Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) for a detailed description of this parameter.
        unsigned TRC : 5; //!< Active to Active or Refresh command period (same bank).  (This field is valid only for DDR2/ DDR3 memories)  In LPDDR2 mode this parameter should be configured at tRC_LP.  See DDR2 SDRAM Specification JESD79-2E (April 2008) and to DDR3 SDRAM Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) for a detailed description of this parameter.
        unsigned TRP : 3; //!< Precharge command period (same bank).  (This field is valid only for DDR2/ DDR3 memories)  IIn LPDDR2 mode this parameter should be configured at tRPpb_LP.  See DDR2 SDRAM Specification JESD79-2E (April 2008) and to DDR3 SDRAM Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) for a detailed description of this parameter.
        unsigned TRCD : 3; //!< Active command to internal read or write delay time (same bank).  (This field is valid only for DDR2/ DDR3 memories)  In LPDDR2 mode this parameter should be configured at tRCD_LP.  See DDR2 SDRAM Specification JESD79-2E (April 2008) and to DDR3 SDRAM Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) for a detailed description of this parameter.
    } B;
} hw_mmdc_mdcfg1_t;
#endif

/*
 * constants & macros for entire MMDC_MDCFG1 register
 */
#define HW_MMDC_MDCFG1_ADDR      (REGS_MMDC_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MDCFG1           (*(volatile hw_mmdc_mdcfg1_t *) HW_MMDC_MDCFG1_ADDR)
#define HW_MMDC_MDCFG1_RD()      (HW_MMDC_MDCFG1.U)
#define HW_MMDC_MDCFG1_WR(v)     (HW_MMDC_MDCFG1.U = (v))
#define HW_MMDC_MDCFG1_SET(v)    (HW_MMDC_MDCFG1_WR(HW_MMDC_MDCFG1_RD() |  (v)))
#define HW_MMDC_MDCFG1_CLR(v)    (HW_MMDC_MDCFG1_WR(HW_MMDC_MDCFG1_RD() & ~(v)))
#define HW_MMDC_MDCFG1_TOG(v)    (HW_MMDC_MDCFG1_WR(HW_MMDC_MDCFG1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MDCFG1 bitfields
 */

/* --- Register HW_MMDC_MDCFG1, field TCWL
 *
 * CAS Write Latency.  In DDR2 mode this field is referred to WL and
 * equals RL-1.  In DDR3 mode this field is referred to CWL.  In LPDDR2 mode this field is referred
 * to WL.
 */

#define BP_MMDC_MDCFG1_TCWL      0
#define BM_MMDC_MDCFG1_TCWL      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCFG1_TCWL(v)   ((((reg32_t) v) << 0) & BM_MMDC_MDCFG1_TCWL)
#else
#define BF_MMDC_MDCFG1_TCWL(v)   (((v) << 0) & BM_MMDC_MDCFG1_TCWL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCFG1_TCWL(v)   BF_CS1(MMDC_MDCFG1, TCWL, v)
#endif

/* --- Register HW_MMDC_MDCFG1, field TMRD
 *
 * Mode Register Set command cycle (all banks).  In DDR3 mode this field shoud be set to max
 * (tMRD,tMOD).  In DDR2 mode this field is Set to tMRD.  In LPDDR2 mode this field should be set to
 * max(tMRR,tMRW)  See DDR2 SDRAM Specification JESD79-2E (April 2008) and to DDR3 SDRAM
 * Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification
 * JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B
 * (February 2010) for a detailed description of this parameter.
 */

#define BP_MMDC_MDCFG1_TMRD      5
#define BM_MMDC_MDCFG1_TMRD      0x000001e0

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCFG1_TMRD(v)   ((((reg32_t) v) << 5) & BM_MMDC_MDCFG1_TMRD)
#else
#define BF_MMDC_MDCFG1_TMRD(v)   (((v) << 5) & BM_MMDC_MDCFG1_TMRD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCFG1_TMRD(v)   BF_CS1(MMDC_MDCFG1, TMRD, v)
#endif

/* --- Register HW_MMDC_MDCFG1, field TWR
 *
 * WRITE recovery time (same bank).  See DDR2 SDRAM Specification JESD79-2E (April 2008) and to DDR3
 * SDRAM                                 Specification JESD79-3E (July 2010) and LPDDR2 SDRAM
 * Specification                                 JESD209-2B (February 2010) and LPDDR2 SDRAM
 * Specification JESD209-2B                                 (February 2010) for a detailed
 * description of this parameter.
 */

#define BP_MMDC_MDCFG1_TWR      9
#define BM_MMDC_MDCFG1_TWR      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCFG1_TWR(v)   ((((reg32_t) v) << 9) & BM_MMDC_MDCFG1_TWR)
#else
#define BF_MMDC_MDCFG1_TWR(v)   (((v) << 9) & BM_MMDC_MDCFG1_TWR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCFG1_TWR(v)   BF_CS1(MMDC_MDCFG1, TWR, v)
#endif

/* --- Register HW_MMDC_MDCFG1, field TRPA
 *
 * Precharge-all command period.  (This field is valid only for DDR2/ DDR3
 * memories)  In LPDDR2 mode this parameter should be configured at tRPab_LP.  See DDR2 SDRAM
 * Specification JESD79-2E (April 2008) and to DDR3 SDRAM
 * Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification
 * JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B
 * (February 2010) for a detailed description of this parameter.
 */

#define BP_MMDC_MDCFG1_TRPA      15
#define BM_MMDC_MDCFG1_TRPA      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCFG1_TRPA(v)   ((((reg32_t) v) << 15) & BM_MMDC_MDCFG1_TRPA)
#else
#define BF_MMDC_MDCFG1_TRPA(v)   (((v) << 15) & BM_MMDC_MDCFG1_TRPA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCFG1_TRPA(v)   BF_CS1(MMDC_MDCFG1, TRPA, v)
#endif

/* --- Register HW_MMDC_MDCFG1, field TRAS
 *
 * Active to Precharge command period (same bank).  See DDR2 SDRAM Specification JESD79-2E (April
 * 2008) and to DDR3 SDRAM                                 Specification JESD79-3E (July 2010) and
 * LPDDR2 SDRAM Specification                                 JESD209-2B (February 2010) and LPDDR2
 * SDRAM Specification JESD209-2B                                 (February 2010) for a detailed
 * description of this parameter.
 */

#define BP_MMDC_MDCFG1_TRAS      16
#define BM_MMDC_MDCFG1_TRAS      0x001f0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCFG1_TRAS(v)   ((((reg32_t) v) << 16) & BM_MMDC_MDCFG1_TRAS)
#else
#define BF_MMDC_MDCFG1_TRAS(v)   (((v) << 16) & BM_MMDC_MDCFG1_TRAS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCFG1_TRAS(v)   BF_CS1(MMDC_MDCFG1, TRAS, v)
#endif

/* --- Register HW_MMDC_MDCFG1, field TRC
 *
 * Active to Active or Refresh command period (same bank).  (This field is valid only for DDR2/ DDR3
 * memories)  In LPDDR2 mode this parameter should be configured at tRC_LP.  See DDR2 SDRAM
 * Specification JESD79-2E (April 2008) and to DDR3 SDRAM
 * Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification
 * JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B
 * (February 2010) for a detailed description of this parameter.
 */

#define BP_MMDC_MDCFG1_TRC      21
#define BM_MMDC_MDCFG1_TRC      0x03e00000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCFG1_TRC(v)   ((((reg32_t) v) << 21) & BM_MMDC_MDCFG1_TRC)
#else
#define BF_MMDC_MDCFG1_TRC(v)   (((v) << 21) & BM_MMDC_MDCFG1_TRC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCFG1_TRC(v)   BF_CS1(MMDC_MDCFG1, TRC, v)
#endif

/* --- Register HW_MMDC_MDCFG1, field TRP
 *
 * Precharge command period (same bank).  (This field is valid only for DDR2/ DDR3
 * memories)  IIn LPDDR2 mode this parameter should be configured at tRPpb_LP.  See DDR2 SDRAM
 * Specification JESD79-2E (April 2008) and to DDR3 SDRAM
 * Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification
 * JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B
 * (February 2010) for a detailed description of this parameter.
 */

#define BP_MMDC_MDCFG1_TRP      26
#define BM_MMDC_MDCFG1_TRP      0x1c000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCFG1_TRP(v)   ((((reg32_t) v) << 26) & BM_MMDC_MDCFG1_TRP)
#else
#define BF_MMDC_MDCFG1_TRP(v)   (((v) << 26) & BM_MMDC_MDCFG1_TRP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCFG1_TRP(v)   BF_CS1(MMDC_MDCFG1, TRP, v)
#endif

/* --- Register HW_MMDC_MDCFG1, field TRCD
 *
 * Active command to internal read or write delay time (same bank).  (This field is valid only for
 * DDR2/ DDR3                                 memories)  In LPDDR2 mode this parameter should be
 * configured at tRCD_LP.  See DDR2 SDRAM Specification JESD79-2E (April 2008) and to DDR3 SDRAM
 * Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification
 * JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B
 * (February 2010) for a detailed description of this parameter.
 */

#define BP_MMDC_MDCFG1_TRCD      29
#define BM_MMDC_MDCFG1_TRCD      0xe0000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCFG1_TRCD(v)   ((((reg32_t) v) << 29) & BM_MMDC_MDCFG1_TRCD)
#else
#define BF_MMDC_MDCFG1_TRCD(v)   (((v) << 29) & BM_MMDC_MDCFG1_TRCD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCFG1_TRCD(v)   BF_CS1(MMDC_MDCFG1, TRCD, v)
#endif

/*!
 * @brief HW_MMDC_MDCFG2 - MMDC Core Timing Configuration Register 2
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TRRD : 3; //!< Active to Active command period (all banks).  See DDR2 SDRAM Specification JESD79-2E (April 2008) and to DDR3 SDRAM Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) for a detailed description of this parameter.
        unsigned TWTR : 3; //!< Internal WRITE to READ command delay (same bank).  See DDR2 SDRAM Specification JESD79-2E (April 2008) and to DDR3 SDRAM Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) for a detailed description of this parameter.
        unsigned TRTP : 3; //!< Internal READ command to Precharge command delay (same bank).  See DDR2 SDRAM Specification JESD79-2E (April 2008) and to DDR3 SDRAM Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) for a detailed description of this parameter.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned TDLLK : 9; //!< DLL locking time.  In DDR2 mode this field is called tXSRD, exit self refresh to read command.  This field is not relevant in LPDDR2 mode.  See DDR2 SDRAM Specification JESD79-2E (April 2008) and to DDR3 SDRAM Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B (February 2010) for a detailed description of this parameter.
        unsigned RESERVED1 : 7; //!< Reserved
    } B;
} hw_mmdc_mdcfg2_t;
#endif

/*
 * constants & macros for entire MMDC_MDCFG2 register
 */
#define HW_MMDC_MDCFG2_ADDR      (REGS_MMDC_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MDCFG2           (*(volatile hw_mmdc_mdcfg2_t *) HW_MMDC_MDCFG2_ADDR)
#define HW_MMDC_MDCFG2_RD()      (HW_MMDC_MDCFG2.U)
#define HW_MMDC_MDCFG2_WR(v)     (HW_MMDC_MDCFG2.U = (v))
#define HW_MMDC_MDCFG2_SET(v)    (HW_MMDC_MDCFG2_WR(HW_MMDC_MDCFG2_RD() |  (v)))
#define HW_MMDC_MDCFG2_CLR(v)    (HW_MMDC_MDCFG2_WR(HW_MMDC_MDCFG2_RD() & ~(v)))
#define HW_MMDC_MDCFG2_TOG(v)    (HW_MMDC_MDCFG2_WR(HW_MMDC_MDCFG2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MDCFG2 bitfields
 */

/* --- Register HW_MMDC_MDCFG2, field TRRD
 *
 * Active to Active command period (all banks).  See DDR2 SDRAM Specification JESD79-2E (April 2008)
 * and to DDR3 SDRAM                                 Specification JESD79-3E (July 2010) and LPDDR2
 * SDRAM Specification                                 JESD209-2B (February 2010) and LPDDR2 SDRAM
 * Specification JESD209-2B                                 (February 2010) for a detailed
 * description of this parameter.
 */

#define BP_MMDC_MDCFG2_TRRD      0
#define BM_MMDC_MDCFG2_TRRD      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCFG2_TRRD(v)   ((((reg32_t) v) << 0) & BM_MMDC_MDCFG2_TRRD)
#else
#define BF_MMDC_MDCFG2_TRRD(v)   (((v) << 0) & BM_MMDC_MDCFG2_TRRD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCFG2_TRRD(v)   BF_CS1(MMDC_MDCFG2, TRRD, v)
#endif

/* --- Register HW_MMDC_MDCFG2, field TWTR
 *
 * Internal WRITE to READ command delay (same bank).  See DDR2 SDRAM Specification JESD79-2E (April
 * 2008) and to DDR3 SDRAM                                 Specification JESD79-3E (July 2010) and
 * LPDDR2 SDRAM Specification                                 JESD209-2B (February 2010) and LPDDR2
 * SDRAM Specification JESD209-2B                                 (February 2010) for a detailed
 * description of this parameter.
 */

#define BP_MMDC_MDCFG2_TWTR      3
#define BM_MMDC_MDCFG2_TWTR      0x00000038

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCFG2_TWTR(v)   ((((reg32_t) v) << 3) & BM_MMDC_MDCFG2_TWTR)
#else
#define BF_MMDC_MDCFG2_TWTR(v)   (((v) << 3) & BM_MMDC_MDCFG2_TWTR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCFG2_TWTR(v)   BF_CS1(MMDC_MDCFG2, TWTR, v)
#endif

/* --- Register HW_MMDC_MDCFG2, field TRTP
 *
 * Internal READ command to Precharge command delay (same bank).  See DDR2 SDRAM Specification
 * JESD79-2E (April 2008) and to DDR3 SDRAM                                 Specification JESD79-3E
 * (July 2010) and LPDDR2 SDRAM Specification                                 JESD209-2B (February
 * 2010) and LPDDR2 SDRAM Specification JESD209-2B                                 (February 2010)
 * for a detailed description of this parameter.
 */

#define BP_MMDC_MDCFG2_TRTP      6
#define BM_MMDC_MDCFG2_TRTP      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCFG2_TRTP(v)   ((((reg32_t) v) << 6) & BM_MMDC_MDCFG2_TRTP)
#else
#define BF_MMDC_MDCFG2_TRTP(v)   (((v) << 6) & BM_MMDC_MDCFG2_TRTP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCFG2_TRTP(v)   BF_CS1(MMDC_MDCFG2, TRTP, v)
#endif

/* --- Register HW_MMDC_MDCFG2, field TDLLK
 *
 * DLL locking time.  In DDR2 mode this field is called tXSRD, exit
 * self refresh to read command.  This field is not relevant in LPDDR2 mode.  See DDR2 SDRAM
 * Specification JESD79-2E (April 2008) and to DDR3 SDRAM
 * Specification JESD79-3E (July 2010) and LPDDR2 SDRAM Specification
 * JESD209-2B (February 2010) and LPDDR2 SDRAM Specification JESD209-2B
 * (February 2010) for a detailed description of this parameter.
 */

#define BP_MMDC_MDCFG2_TDLLK      16
#define BM_MMDC_MDCFG2_TDLLK      0x01ff0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCFG2_TDLLK(v)   ((((reg32_t) v) << 16) & BM_MMDC_MDCFG2_TDLLK)
#else
#define BF_MMDC_MDCFG2_TDLLK(v)   (((v) << 16) & BM_MMDC_MDCFG2_TDLLK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCFG2_TDLLK(v)   BF_CS1(MMDC_MDCFG2, TDLLK, v)
#endif

/*!
 * @brief HW_MMDC_MDMISC - MMDC Core Miscellaneous Register
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned RST : 1; //!< Software Reset. When this bit is asserted then the internal FSMs and registers of the MMDC will be initialized.  This bit once asserted gets deasserted automatically.
        unsigned LPDDR2_2CH : 1; //!< LPDDR2 2-channels mode. When this bit is set to "1" then dual channel mode is activated.  This field should be cleared for DDR3 mode.
        unsigned DDR_TYPE : 2; //!< DDR TYPE. This field determines the type of the external DDR device.
        unsigned DDR_4_BANK : 1; //!< Number of banks per DDR device. When this bit is set to "1" then the MMDC will work with DDR device of 4 banks.
        unsigned RALAT : 3; //!< Read Additional Latency. This field determines the additional read latency which is added to CAS latency and internal delays for which the MMDC will retrieve the read data from the internal FIFO. This field is used to compensate on board/chip delays.  In LPDDR2 mode 2 extra cycles will be added internally in order to compensate tDQSCK delay.
        unsigned MIF3_MODE : 2; //!< Command prediction working mode. This field determines the level of command prediction that will be used by the MMDC
        unsigned LPDDR2_S2 : 1; //!< LPDDR2 S2 device type indication.  In case LPDDR2 device is used (DDR_TYPE = 0x1), this bit will indicate whether S2 or S4 device is used.  This bit should be cleared in DDR3 mode
        unsigned BI_ON : 1; //!< Bank Interleaving On. This bit controls the organization of the bank, row and column address bits.  For further information see .
        unsigned RESERVED1 : 3; //!< Reserved
        unsigned WALAT : 2; //!< Write Additional latency.  In case the write-leveling calibration process indicates a delay   around half  cycle (between CK and the associated DQS) then this field must be configured accordingly.  This field will add delay on the obe I/O control, which will compensate on the additional write leveling delay on DQS and prevent the DQS from being croped.
        unsigned LHD : 1; //!< Latency hiding disable.  This is a debug feature. When set to "1" the MMDC will handle one read/write access at a time. Meaning that the MMDC pipe-line will be limitted to 1 open access (next AXI address phase will be acknowledged if the current AXI data phase had finished)
        unsigned ADDR_MIRROR : 1; //!< Address mirroring.  This feature is not supported for LPDDR2 memories. But only for DDR2 or DDR3 memories.  For further information see .
        unsigned CALIB_PER_CS : 1; //!< Number of chip-select for calibration process. This bit determines the chip-select index that the associated calibration is targetted to. Relevant for read, write, write leveling and read DQS gating calibrations
        unsigned RESERVED2 : 9; //!< Reserved
        unsigned CS1_RDY : 1; //!< External status device on CS1. This is a read-only status bit, that indicates whether the external memory is in wake-up period.
        unsigned CS0_RDY : 1; //!< External status device on CS0. This is a read-only status bit, that indicates whether the external memory is in wake-up period.
    } B;
} hw_mmdc_mdmisc_t;
#endif

/*
 * constants & macros for entire MMDC_MDMISC register
 */
#define HW_MMDC_MDMISC_ADDR      (REGS_MMDC_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MDMISC           (*(volatile hw_mmdc_mdmisc_t *) HW_MMDC_MDMISC_ADDR)
#define HW_MMDC_MDMISC_RD()      (HW_MMDC_MDMISC.U)
#define HW_MMDC_MDMISC_WR(v)     (HW_MMDC_MDMISC.U = (v))
#define HW_MMDC_MDMISC_SET(v)    (HW_MMDC_MDMISC_WR(HW_MMDC_MDMISC_RD() |  (v)))
#define HW_MMDC_MDMISC_CLR(v)    (HW_MMDC_MDMISC_WR(HW_MMDC_MDMISC_RD() & ~(v)))
#define HW_MMDC_MDMISC_TOG(v)    (HW_MMDC_MDMISC_WR(HW_MMDC_MDMISC_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MDMISC bitfields
 */

/* --- Register HW_MMDC_MDMISC, field RST
 *
 * Software Reset. When this bit is asserted then the internal FSMs and
 * registers of the MMDC will be initialized.  This bit once asserted gets deasserted automatically.
 */

#define BP_MMDC_MDMISC_RST      1
#define BM_MMDC_MDMISC_RST      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMISC_RST(v)   ((((reg32_t) v) << 1) & BM_MMDC_MDMISC_RST)
#else
#define BF_MMDC_MDMISC_RST(v)   (((v) << 1) & BM_MMDC_MDMISC_RST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMISC_RST(v)   BF_CS1(MMDC_MDMISC, RST, v)
#endif

/* --- Register HW_MMDC_MDMISC, field LPDDR2_2CH
 *
 * LPDDR2 2-channels mode. When this bit is set to "1" then dual channel mode is activated.  This
 * field should be cleared for DDR3 mode.
 */

#define BP_MMDC_MDMISC_LPDDR2_2CH      2
#define BM_MMDC_MDMISC_LPDDR2_2CH      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMISC_LPDDR2_2CH(v)   ((((reg32_t) v) << 2) & BM_MMDC_MDMISC_LPDDR2_2CH)
#else
#define BF_MMDC_MDMISC_LPDDR2_2CH(v)   (((v) << 2) & BM_MMDC_MDMISC_LPDDR2_2CH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMISC_LPDDR2_2CH(v)   BF_CS1(MMDC_MDMISC, LPDDR2_2CH, v)
#endif

/* --- Register HW_MMDC_MDMISC, field DDR_TYPE
 *
 * DDR TYPE. This field determines the type of the external DDR
 * device.
 */

#define BP_MMDC_MDMISC_DDR_TYPE      3
#define BM_MMDC_MDMISC_DDR_TYPE      0x00000018

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMISC_DDR_TYPE(v)   ((((reg32_t) v) << 3) & BM_MMDC_MDMISC_DDR_TYPE)
#else
#define BF_MMDC_MDMISC_DDR_TYPE(v)   (((v) << 3) & BM_MMDC_MDMISC_DDR_TYPE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMISC_DDR_TYPE(v)   BF_CS1(MMDC_MDMISC, DDR_TYPE, v)
#endif

/* --- Register HW_MMDC_MDMISC, field DDR_4_BANK
 *
 * Number of banks per DDR device. When this bit is set to "1" then the
 * MMDC will work with DDR device of 4 banks.
 */

#define BP_MMDC_MDMISC_DDR_4_BANK      5
#define BM_MMDC_MDMISC_DDR_4_BANK      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMISC_DDR_4_BANK(v)   ((((reg32_t) v) << 5) & BM_MMDC_MDMISC_DDR_4_BANK)
#else
#define BF_MMDC_MDMISC_DDR_4_BANK(v)   (((v) << 5) & BM_MMDC_MDMISC_DDR_4_BANK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMISC_DDR_4_BANK(v)   BF_CS1(MMDC_MDMISC, DDR_4_BANK, v)
#endif

/* --- Register HW_MMDC_MDMISC, field RALAT
 *
 * Read Additional Latency. This field determines the additional read
 * latency which is added to CAS latency and internal delays for which
 * the MMDC will retrieve the read data from the internal FIFO. This
 * field is used to compensate on board/chip delays.  In LPDDR2 mode 2 extra cycles will be added
 * internally in order to                                 compensate tDQSCK delay.
 */

#define BP_MMDC_MDMISC_RALAT      6
#define BM_MMDC_MDMISC_RALAT      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMISC_RALAT(v)   ((((reg32_t) v) << 6) & BM_MMDC_MDMISC_RALAT)
#else
#define BF_MMDC_MDMISC_RALAT(v)   (((v) << 6) & BM_MMDC_MDMISC_RALAT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMISC_RALAT(v)   BF_CS1(MMDC_MDMISC, RALAT, v)
#endif

/* --- Register HW_MMDC_MDMISC, field MIF3_MODE
 *
 * Command prediction working mode. This field determines the level of
 * command prediction that will be used by the MMDC
 */

#define BP_MMDC_MDMISC_MIF3_MODE      9
#define BM_MMDC_MDMISC_MIF3_MODE      0x00000600

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMISC_MIF3_MODE(v)   ((((reg32_t) v) << 9) & BM_MMDC_MDMISC_MIF3_MODE)
#else
#define BF_MMDC_MDMISC_MIF3_MODE(v)   (((v) << 9) & BM_MMDC_MDMISC_MIF3_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMISC_MIF3_MODE(v)   BF_CS1(MMDC_MDMISC, MIF3_MODE, v)
#endif

/* --- Register HW_MMDC_MDMISC, field LPDDR2_S2
 *
 * LPDDR2 S2 device type indication.  In case LPDDR2 device is used (DDR_TYPE = 0x1), this bit will
 * indicate whether S2 or S4 device is used.  This bit should be cleared in DDR3 mode
 */

#define BP_MMDC_MDMISC_LPDDR2_S2      11
#define BM_MMDC_MDMISC_LPDDR2_S2      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMISC_LPDDR2_S2(v)   ((((reg32_t) v) << 11) & BM_MMDC_MDMISC_LPDDR2_S2)
#else
#define BF_MMDC_MDMISC_LPDDR2_S2(v)   (((v) << 11) & BM_MMDC_MDMISC_LPDDR2_S2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMISC_LPDDR2_S2(v)   BF_CS1(MMDC_MDMISC, LPDDR2_S2, v)
#endif

/* --- Register HW_MMDC_MDMISC, field BI_ON
 *
 * Bank Interleaving On. This bit controls the organization of the bank,
 * row and column address bits.  For further information see .
 */

#define BP_MMDC_MDMISC_BI_ON      12
#define BM_MMDC_MDMISC_BI_ON      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMISC_BI_ON(v)   ((((reg32_t) v) << 12) & BM_MMDC_MDMISC_BI_ON)
#else
#define BF_MMDC_MDMISC_BI_ON(v)   (((v) << 12) & BM_MMDC_MDMISC_BI_ON)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMISC_BI_ON(v)   BF_CS1(MMDC_MDMISC, BI_ON, v)
#endif

/* --- Register HW_MMDC_MDMISC, field WALAT
 *
 * Write Additional latency.  In case the write-leveling calibration process indicates a delay
 * around half  cycle (between CK and the associated DQS) then this field must be configured
 * accordingly.  This field will add delay on the obe I/O control, which will compensate on the
 * additional write leveling delay on DQS and prevent the DQS from being croped.
 */

#define BP_MMDC_MDMISC_WALAT      16
#define BM_MMDC_MDMISC_WALAT      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMISC_WALAT(v)   ((((reg32_t) v) << 16) & BM_MMDC_MDMISC_WALAT)
#else
#define BF_MMDC_MDMISC_WALAT(v)   (((v) << 16) & BM_MMDC_MDMISC_WALAT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMISC_WALAT(v)   BF_CS1(MMDC_MDMISC, WALAT, v)
#endif

/* --- Register HW_MMDC_MDMISC, field LHD
 *
 * Latency hiding disable.  This is a debug feature. When set to "1" the MMDC will handle one
 * read/write access at a time. Meaning that the MMDC pipe-line will be
 * limitted to 1 open access (next AXI address phase will be
 * acknowledged if the current AXI data phase had finished)
 */

#define BP_MMDC_MDMISC_LHD      18
#define BM_MMDC_MDMISC_LHD      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMISC_LHD(v)   ((((reg32_t) v) << 18) & BM_MMDC_MDMISC_LHD)
#else
#define BF_MMDC_MDMISC_LHD(v)   (((v) << 18) & BM_MMDC_MDMISC_LHD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMISC_LHD(v)   BF_CS1(MMDC_MDMISC, LHD, v)
#endif

/* --- Register HW_MMDC_MDMISC, field ADDR_MIRROR
 *
 * Address mirroring.  This feature is not supported for LPDDR2 memories. But only for DDR2 or DDR3
 * memories.  For further information see .
 */

#define BP_MMDC_MDMISC_ADDR_MIRROR      19
#define BM_MMDC_MDMISC_ADDR_MIRROR      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMISC_ADDR_MIRROR(v)   ((((reg32_t) v) << 19) & BM_MMDC_MDMISC_ADDR_MIRROR)
#else
#define BF_MMDC_MDMISC_ADDR_MIRROR(v)   (((v) << 19) & BM_MMDC_MDMISC_ADDR_MIRROR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMISC_ADDR_MIRROR(v)   BF_CS1(MMDC_MDMISC, ADDR_MIRROR, v)
#endif

/* --- Register HW_MMDC_MDMISC, field CALIB_PER_CS
 *
 * Number of chip-select for calibration process. This bit determines
 * the chip-select index that the associated calibration is targetted
 * to. Relevant for read, write, write leveling and read DQS gating
 * calibrations
 */

#define BP_MMDC_MDMISC_CALIB_PER_CS      20
#define BM_MMDC_MDMISC_CALIB_PER_CS      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMISC_CALIB_PER_CS(v)   ((((reg32_t) v) << 20) & BM_MMDC_MDMISC_CALIB_PER_CS)
#else
#define BF_MMDC_MDMISC_CALIB_PER_CS(v)   (((v) << 20) & BM_MMDC_MDMISC_CALIB_PER_CS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMISC_CALIB_PER_CS(v)   BF_CS1(MMDC_MDMISC, CALIB_PER_CS, v)
#endif

/* --- Register HW_MMDC_MDMISC, field CS1_RDY
 *
 * External status device on CS1. This is a read-only status bit, that
 * indicates whether the external memory is in wake-up period.
 */

#define BP_MMDC_MDMISC_CS1_RDY      30
#define BM_MMDC_MDMISC_CS1_RDY      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMISC_CS1_RDY(v)   ((((reg32_t) v) << 30) & BM_MMDC_MDMISC_CS1_RDY)
#else
#define BF_MMDC_MDMISC_CS1_RDY(v)   (((v) << 30) & BM_MMDC_MDMISC_CS1_RDY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMISC_CS1_RDY(v)   BF_CS1(MMDC_MDMISC, CS1_RDY, v)
#endif

/* --- Register HW_MMDC_MDMISC, field CS0_RDY
 *
 * External status device on CS0. This is a read-only status bit, that
 * indicates whether the external memory is in wake-up period.
 */

#define BP_MMDC_MDMISC_CS0_RDY      31
#define BM_MMDC_MDMISC_CS0_RDY      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMISC_CS0_RDY(v)   ((((reg32_t) v) << 31) & BM_MMDC_MDMISC_CS0_RDY)
#else
#define BF_MMDC_MDMISC_CS0_RDY(v)   (((v) << 31) & BM_MMDC_MDMISC_CS0_RDY)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMISC_CS0_RDY(v)   BF_CS1(MMDC_MDMISC, CS0_RDY, v)
#endif

/*!
 * @brief HW_MMDC_MDSCR - MMDC Core Special Command Register
 *
 * This register is used to issue special commands manually toward the
 * external DDR device (such as load mode register, manual self refresh,
 * manual precharge and so on). Every write to this register will be
 * interpreted as a command, and a read from this register will show the
 * last command that was executed.  Every write to this register will result in one special command,
 * and the                             IP bus will assert ips_xfr_wait as long as the special
 * command is being                             carried out.  Supported Mode Of Operations:  For
 * Channel 0: All  For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CMD_BA : 3; //!< Bank Address. This field determines the address of the bank within the selected chip-select where the command is targetted to.
        unsigned CMD_CS : 1; //!< Chip Select. This field determines which chip select the command is targeted to
        unsigned CMD : 3; //!< Command. This field contains the command to be executed.  This field will be automatically cleared after the command will be send to the DDR memory.
        unsigned RESERVED0 : 2; //!< Reserved.
        unsigned WL_EN : 1; //!< DQS pads direction. This bit controls the DQS pads direction during write-leveling calibration process.  Before starting the write-leveling calibration process this bit should be set to "1". It should be set to "0" when sending write leveling exit command.  For further information see .
        unsigned MRR_READ_DATA_VALID : 1; //!< MRR read data valid. This field indicates that read data is valid at MDMRR register  This field is relevant only for LPDDR2 mode
        unsigned RESERVED1 : 3; //!< Reserved
        unsigned CON_ACK : 1; //!< Configuration acknowledge.  Whenever this bit is set, it is permitted to configure MMDC IP registers.
        unsigned CON_REQ : 1; //!< Configuration request.  When this bit is set then the MMDC will clean the pending AXI accesses and will prevent from further AXI accesses to be acknowledged. This field guarantee safe configuration (or change configuration) of the MMDC while no access is in process and prevents an unexpected behaviour.  After setting this bit, it is needed to poll on CON_ACK until it is set to "1". When CON_ACK is asserted then configuration is permitted. After configuration is completed then this bit must be deasserted in order to process further AXI accesses.  This bit is asserted at the end of the reset sequence, meaning that the MMDC is waiting to configure and intialize the external memory before accepting any AXI accesses. Configuration request/acknowledge mechanism should be used for the following procedures: changing of timing parameters , during calibration process or driving commands via MDSCR[CMD]
        unsigned CMD_ADDR_LSB : 8; //!< Command/Address LSB. This field indicates the LSB of the command/Address  In LPDDR2 this field indicates the MRR/MRW address
        unsigned CMD_ADDR_MSB : 8; //!< Command/Address MSB. This field indicates the MSB of the command/Address.  In LPDDR2 this field indicates the MRW operand
    } B;
} hw_mmdc_mdscr_t;
#endif

/*
 * constants & macros for entire MMDC_MDSCR register
 */
#define HW_MMDC_MDSCR_ADDR      (REGS_MMDC_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MDSCR           (*(volatile hw_mmdc_mdscr_t *) HW_MMDC_MDSCR_ADDR)
#define HW_MMDC_MDSCR_RD()      (HW_MMDC_MDSCR.U)
#define HW_MMDC_MDSCR_WR(v)     (HW_MMDC_MDSCR.U = (v))
#define HW_MMDC_MDSCR_SET(v)    (HW_MMDC_MDSCR_WR(HW_MMDC_MDSCR_RD() |  (v)))
#define HW_MMDC_MDSCR_CLR(v)    (HW_MMDC_MDSCR_WR(HW_MMDC_MDSCR_RD() & ~(v)))
#define HW_MMDC_MDSCR_TOG(v)    (HW_MMDC_MDSCR_WR(HW_MMDC_MDSCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MDSCR bitfields
 */

/* --- Register HW_MMDC_MDSCR, field CMD_BA
 *
 * Bank Address. This field determines the address of the bank within
 * the selected chip-select where the command is targetted to.
 */

#define BP_MMDC_MDSCR_CMD_BA      0
#define BM_MMDC_MDSCR_CMD_BA      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDSCR_CMD_BA(v)   ((((reg32_t) v) << 0) & BM_MMDC_MDSCR_CMD_BA)
#else
#define BF_MMDC_MDSCR_CMD_BA(v)   (((v) << 0) & BM_MMDC_MDSCR_CMD_BA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDSCR_CMD_BA(v)   BF_CS1(MMDC_MDSCR, CMD_BA, v)
#endif

/* --- Register HW_MMDC_MDSCR, field CMD_CS
 *
 * Chip Select. This field determines which chip select the command is
 * targeted to
 */

#define BP_MMDC_MDSCR_CMD_CS      3
#define BM_MMDC_MDSCR_CMD_CS      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDSCR_CMD_CS(v)   ((((reg32_t) v) << 3) & BM_MMDC_MDSCR_CMD_CS)
#else
#define BF_MMDC_MDSCR_CMD_CS(v)   (((v) << 3) & BM_MMDC_MDSCR_CMD_CS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDSCR_CMD_CS(v)   BF_CS1(MMDC_MDSCR, CMD_CS, v)
#endif

/* --- Register HW_MMDC_MDSCR, field CMD
 *
 * Command. This field contains the command to be executed.  This field will be automatically
 * cleared after the command will be                                 send to the DDR memory.
 */

#define BP_MMDC_MDSCR_CMD      4
#define BM_MMDC_MDSCR_CMD      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDSCR_CMD(v)   ((((reg32_t) v) << 4) & BM_MMDC_MDSCR_CMD)
#else
#define BF_MMDC_MDSCR_CMD(v)   (((v) << 4) & BM_MMDC_MDSCR_CMD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDSCR_CMD(v)   BF_CS1(MMDC_MDSCR, CMD, v)
#endif

/* --- Register HW_MMDC_MDSCR, field WL_EN
 *
 * DQS pads direction. This bit controls the DQS pads direction during
 * write-leveling calibration process.  Before starting the write-leveling calibration process this
 * bit                                 should be set to "1". It should be set to "0" when sending
 * write                                 leveling exit command.  For further information see .
 */

#define BP_MMDC_MDSCR_WL_EN      9
#define BM_MMDC_MDSCR_WL_EN      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDSCR_WL_EN(v)   ((((reg32_t) v) << 9) & BM_MMDC_MDSCR_WL_EN)
#else
#define BF_MMDC_MDSCR_WL_EN(v)   (((v) << 9) & BM_MMDC_MDSCR_WL_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDSCR_WL_EN(v)   BF_CS1(MMDC_MDSCR, WL_EN, v)
#endif

/* --- Register HW_MMDC_MDSCR, field MRR_READ_DATA_VALID
 *
 * MRR read data valid. This field indicates that read data is valid at
 * MDMRR register  This field is relevant only for LPDDR2 mode
 */

#define BP_MMDC_MDSCR_MRR_READ_DATA_VALID      10
#define BM_MMDC_MDSCR_MRR_READ_DATA_VALID      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDSCR_MRR_READ_DATA_VALID(v)   ((((reg32_t) v) << 10) & BM_MMDC_MDSCR_MRR_READ_DATA_VALID)
#else
#define BF_MMDC_MDSCR_MRR_READ_DATA_VALID(v)   (((v) << 10) & BM_MMDC_MDSCR_MRR_READ_DATA_VALID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDSCR_MRR_READ_DATA_VALID(v)   BF_CS1(MMDC_MDSCR, MRR_READ_DATA_VALID, v)
#endif

/* --- Register HW_MMDC_MDSCR, field CON_ACK
 *
 * Configuration acknowledge.  Whenever this bit is set, it is permitted to configure MMDC IP
 * registers.
 */

#define BP_MMDC_MDSCR_CON_ACK      14
#define BM_MMDC_MDSCR_CON_ACK      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDSCR_CON_ACK(v)   ((((reg32_t) v) << 14) & BM_MMDC_MDSCR_CON_ACK)
#else
#define BF_MMDC_MDSCR_CON_ACK(v)   (((v) << 14) & BM_MMDC_MDSCR_CON_ACK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDSCR_CON_ACK(v)   BF_CS1(MMDC_MDSCR, CON_ACK, v)
#endif

/* --- Register HW_MMDC_MDSCR, field CON_REQ
 *
 * Configuration request.  When this bit is set then the MMDC will clean the pending AXI
 * accesses and will prevent from further AXI accesses to be
 * acknowledged. This field guarantee safe configuration (or change
 * configuration) of the MMDC while no access is in process and
 * prevents an unexpected behaviour.  After setting this bit, it is needed to poll on CON_ACK until
 * it is                                 set to "1". When CON_ACK is asserted then configuration is
 * permitted. After configuration is completed then this bit must be
 * deasserted in order to process further AXI accesses.  This bit is asserted at the end of the
 * reset sequence, meaning                                 that the MMDC is waiting to configure and
 * intialize the external                                 memory before accepting any AXI accesses.
 * Configuration                                 request/acknowledge mechanism should be used for
 * the following                                 procedures: changing of timing parameters , during
 * calibration                                 process or driving commands via MDSCR[CMD]
 */

#define BP_MMDC_MDSCR_CON_REQ      15
#define BM_MMDC_MDSCR_CON_REQ      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDSCR_CON_REQ(v)   ((((reg32_t) v) << 15) & BM_MMDC_MDSCR_CON_REQ)
#else
#define BF_MMDC_MDSCR_CON_REQ(v)   (((v) << 15) & BM_MMDC_MDSCR_CON_REQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDSCR_CON_REQ(v)   BF_CS1(MMDC_MDSCR, CON_REQ, v)
#endif

/* --- Register HW_MMDC_MDSCR, field CMD_ADDR_LSB
 *
 * Command/Address LSB. This field indicates the LSB of the
 * command/Address  In LPDDR2 this field indicates the MRR/MRW address
 */

#define BP_MMDC_MDSCR_CMD_ADDR_LSB      16
#define BM_MMDC_MDSCR_CMD_ADDR_LSB      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDSCR_CMD_ADDR_LSB(v)   ((((reg32_t) v) << 16) & BM_MMDC_MDSCR_CMD_ADDR_LSB)
#else
#define BF_MMDC_MDSCR_CMD_ADDR_LSB(v)   (((v) << 16) & BM_MMDC_MDSCR_CMD_ADDR_LSB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDSCR_CMD_ADDR_LSB(v)   BF_CS1(MMDC_MDSCR, CMD_ADDR_LSB, v)
#endif

/* --- Register HW_MMDC_MDSCR, field CMD_ADDR_MSB
 *
 * Command/Address MSB. This field indicates the MSB of the
 * command/Address.  In LPDDR2 this field indicates the MRW operand
 */

#define BP_MMDC_MDSCR_CMD_ADDR_MSB      24
#define BM_MMDC_MDSCR_CMD_ADDR_MSB      0xff000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDSCR_CMD_ADDR_MSB(v)   ((((reg32_t) v) << 24) & BM_MMDC_MDSCR_CMD_ADDR_MSB)
#else
#define BF_MMDC_MDSCR_CMD_ADDR_MSB(v)   (((v) << 24) & BM_MMDC_MDSCR_CMD_ADDR_MSB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDSCR_CMD_ADDR_MSB(v)   BF_CS1(MMDC_MDSCR, CMD_ADDR_MSB, v)
#endif

/*!
 * @brief HW_MMDC_MDREF - MMDC Core Refresh Control Register
 *
 * This register determines the refresh scheme that will be executed toward
 * the DDR device. It specifies how often a refresh cycle occurs and how
 * many refresh commands will be executed every refresh cycle.  For further information see .  The
 * following tables show examples of possible refresh schemes.   Refresh rate example for REF_SEL =
 * 0          REFR[2:0]    Number of refresh commands every
 * 64KHz    Average periodic refresh                                                 rate  (tREFI)
 * System Refresh period        0x0    1    15.6 μs    tRFC      0x1    2    7.8 μs    2*tRFC
 * 0x3    4    3.9μs    4*tRFC      0x7    8    1.95 μs    8*tRFC        Refresh rate example for
 * REF_SEL = 1          REFR[2:0]    Number of refresh commands every
 * 32KHz    Average periodic refresh                                                 rate  (tREFI)
 * System Refresh period        0x1    2    15.6 μs    2*tRFC      0x3    4    7.8 μs    4*tRFC
 * 0x7    8    3.9μs    8*tRFC        Refresh rate example for REF_SEL = 2@ 400MHz
 * REFR[2:0]    Number of refresh commands every
 * refresh cycle    REF_CNT    Average periodic refresh
 * rate  (tREFI)    System Refresh period        0x0    1    0x618    3.9 μs    tRFC      0x1    2
 * 0xC30    3.9 μs    2*tRFC      0x2    3    0x1248    3.9μs    3*tRFC      0x3    4    0x1860
 * 3.9 μs    4*tRFC       Other refresh configurations are also allowed; the configuration values
 * in the tables above are only examples for obtaining the desired average
 * periodic refresh rate.  If the required average periodic refresh rate (tREFI) is kept, all of the
 * rows will be refreshed in every refresh window. Because the memory
 * device issues additional refresh commands for every refresh it receives,
 * the tREFI remains the same across the device, regardless of its number
 * of rows. This is particularly relevant in the tRFC parameter, which
 * becomes bigger as the density increases.  Supported Mode Of Operations:  For Channel 0: All  For
 * Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned START_REF : 1; //!< Manual start of refresh cycle. When this field is set to '1' the MMDC will start a refresh cycle immediately according to number of refresh commands that are configured in 'REFR' field.  This bit returns to zero automatically.
        unsigned RESERVED0 : 10; //!< Reserved
        unsigned REFR : 3; //!< Refresh Rate.  This field determines how many refresh commands will be issued every refresh cycle.  After every refresh command the MMDC won't drive any command to the DDR device untill satisfying tRFC period
        unsigned REF_SEL : 2; //!< Refresh Selector.  This bit selects the source of the clock that will trigger each refresh cycle:
        unsigned REF_CNT : 16; //!< Refresh Counter at DDR clock period  If REF_SEL equals '2' a refresh cycle will begin every amount of DDR cycles configured in this field.
    } B;
} hw_mmdc_mdref_t;
#endif

/*
 * constants & macros for entire MMDC_MDREF register
 */
#define HW_MMDC_MDREF_ADDR      (REGS_MMDC_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MDREF           (*(volatile hw_mmdc_mdref_t *) HW_MMDC_MDREF_ADDR)
#define HW_MMDC_MDREF_RD()      (HW_MMDC_MDREF.U)
#define HW_MMDC_MDREF_WR(v)     (HW_MMDC_MDREF.U = (v))
#define HW_MMDC_MDREF_SET(v)    (HW_MMDC_MDREF_WR(HW_MMDC_MDREF_RD() |  (v)))
#define HW_MMDC_MDREF_CLR(v)    (HW_MMDC_MDREF_WR(HW_MMDC_MDREF_RD() & ~(v)))
#define HW_MMDC_MDREF_TOG(v)    (HW_MMDC_MDREF_WR(HW_MMDC_MDREF_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MDREF bitfields
 */

/* --- Register HW_MMDC_MDREF, field START_REF
 *
 * Manual start of refresh cycle. When this field is set to '1' the MMDC
 * will start a refresh cycle immediately according to number of
 * refresh commands that are configured in 'REFR' field.  This bit returns to zero automatically.
 */

#define BP_MMDC_MDREF_START_REF      0
#define BM_MMDC_MDREF_START_REF      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDREF_START_REF(v)   ((((reg32_t) v) << 0) & BM_MMDC_MDREF_START_REF)
#else
#define BF_MMDC_MDREF_START_REF(v)   (((v) << 0) & BM_MMDC_MDREF_START_REF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDREF_START_REF(v)   BF_CS1(MMDC_MDREF, START_REF, v)
#endif

/* --- Register HW_MMDC_MDREF, field REFR
 *
 * Refresh Rate.  This field determines how many refresh commands will be issued every
 * refresh cycle.  After every refresh command the MMDC won't drive any command to the
 * DDR device untill satisfying tRFC period
 */

#define BP_MMDC_MDREF_REFR      11
#define BM_MMDC_MDREF_REFR      0x00003800

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDREF_REFR(v)   ((((reg32_t) v) << 11) & BM_MMDC_MDREF_REFR)
#else
#define BF_MMDC_MDREF_REFR(v)   (((v) << 11) & BM_MMDC_MDREF_REFR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDREF_REFR(v)   BF_CS1(MMDC_MDREF, REFR, v)
#endif

/* --- Register HW_MMDC_MDREF, field REF_SEL
 *
 * Refresh Selector.  This bit selects the source of the clock that will trigger each
 * refresh cycle:
 */

#define BP_MMDC_MDREF_REF_SEL      14
#define BM_MMDC_MDREF_REF_SEL      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDREF_REF_SEL(v)   ((((reg32_t) v) << 14) & BM_MMDC_MDREF_REF_SEL)
#else
#define BF_MMDC_MDREF_REF_SEL(v)   (((v) << 14) & BM_MMDC_MDREF_REF_SEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDREF_REF_SEL(v)   BF_CS1(MMDC_MDREF, REF_SEL, v)
#endif

/* --- Register HW_MMDC_MDREF, field REF_CNT
 *
 * Refresh Counter at DDR clock period  If REF_SEL equals '2' a refresh cycle will begin every
 * amount of DDR                                 cycles configured in this field.
 */

#define BP_MMDC_MDREF_REF_CNT      16
#define BM_MMDC_MDREF_REF_CNT      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDREF_REF_CNT(v)   ((((reg32_t) v) << 16) & BM_MMDC_MDREF_REF_CNT)
#else
#define BF_MMDC_MDREF_REF_CNT(v)   (((v) << 16) & BM_MMDC_MDREF_REF_CNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDREF_REF_CNT(v)   BF_CS1(MMDC_MDREF, REF_CNT, v)
#endif

/*!
 * @brief HW_MMDC_MDRWD - MMDC Core Read/Write Command Delay Register
 *
 * This register determines the delay between back to back read and write
 * accesses. The register reset values are set to the minimum required
 * value. As the default values are set to achieve optimal results, changing
 * them is discouraged.  Supported Mode Of Operations:  For Channel 0: All  For Channel 1:
 * LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RTR_DIFF : 3; //!< Read to read delay for different chip-select. This field controls the delay between read to read commands toward different chip select.  The total delay is calculated according to: BL/2 + RTR_DIFF
        unsigned RTW_DIFF : 3; //!< Read to write delay for different chip-select. This field controls the delay between read to write commands toward different chip select.  The total delay is calculated according to: BL/2 + RTW_DIFF + (tCL - tCWL) + RALAT
        unsigned WTW_DIFF : 3; //!< Write to write delay for different chip-select. This field controls the delay between write to write commands toward different chip select.  The total delay is calculated according to: BL/2 + WTW_DIFF
        unsigned WTR_DIFF : 3; //!< Write to read delay for different chip-select. This field controls the delay between write to read commands toward different chip select.  The total delay is calculated according to: BL/2 + WTR_DIFF + (tCL-tCWL) + RALAT
        unsigned RTW_SAME : 3; //!< Read to write delay for the same chip-select. This field controls the delay between read to write commands toward the same chip select.  The total delay is calculated according to: BL/2 + RTW_SAME + (tCL-tCWL) + RALAT
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned TDAI : 13; //!< Device auto initialization period.(maximum)  This field is relevant only to LPDDR2 mode
        unsigned RESERVED1 : 3; //!< Reserved
    } B;
} hw_mmdc_mdrwd_t;
#endif

/*
 * constants & macros for entire MMDC_MDRWD register
 */
#define HW_MMDC_MDRWD_ADDR      (REGS_MMDC_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MDRWD           (*(volatile hw_mmdc_mdrwd_t *) HW_MMDC_MDRWD_ADDR)
#define HW_MMDC_MDRWD_RD()      (HW_MMDC_MDRWD.U)
#define HW_MMDC_MDRWD_WR(v)     (HW_MMDC_MDRWD.U = (v))
#define HW_MMDC_MDRWD_SET(v)    (HW_MMDC_MDRWD_WR(HW_MMDC_MDRWD_RD() |  (v)))
#define HW_MMDC_MDRWD_CLR(v)    (HW_MMDC_MDRWD_WR(HW_MMDC_MDRWD_RD() & ~(v)))
#define HW_MMDC_MDRWD_TOG(v)    (HW_MMDC_MDRWD_WR(HW_MMDC_MDRWD_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MDRWD bitfields
 */

/* --- Register HW_MMDC_MDRWD, field RTR_DIFF
 *
 * Read to read delay for different chip-select. This field controls the
 * delay between read to read commands toward different chip                                 select.
 * The total delay is calculated according to: BL/2 + RTR_DIFF
 */

#define BP_MMDC_MDRWD_RTR_DIFF      0
#define BM_MMDC_MDRWD_RTR_DIFF      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDRWD_RTR_DIFF(v)   ((((reg32_t) v) << 0) & BM_MMDC_MDRWD_RTR_DIFF)
#else
#define BF_MMDC_MDRWD_RTR_DIFF(v)   (((v) << 0) & BM_MMDC_MDRWD_RTR_DIFF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDRWD_RTR_DIFF(v)   BF_CS1(MMDC_MDRWD, RTR_DIFF, v)
#endif

/* --- Register HW_MMDC_MDRWD, field RTW_DIFF
 *
 * Read to write delay for different chip-select. This field controls
 * the delay between read to write commands toward different chip
 * select.  The total delay is calculated according to: BL/2 + RTW_DIFF + (tCL -
 * tCWL) + RALAT
 */

#define BP_MMDC_MDRWD_RTW_DIFF      3
#define BM_MMDC_MDRWD_RTW_DIFF      0x00000038

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDRWD_RTW_DIFF(v)   ((((reg32_t) v) << 3) & BM_MMDC_MDRWD_RTW_DIFF)
#else
#define BF_MMDC_MDRWD_RTW_DIFF(v)   (((v) << 3) & BM_MMDC_MDRWD_RTW_DIFF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDRWD_RTW_DIFF(v)   BF_CS1(MMDC_MDRWD, RTW_DIFF, v)
#endif

/* --- Register HW_MMDC_MDRWD, field WTW_DIFF
 *
 * Write to write delay for different chip-select. This field controls
 * the delay between write to write commands toward different chip
 * select.  The total delay is calculated according to: BL/2 + WTW_DIFF
 */

#define BP_MMDC_MDRWD_WTW_DIFF      6
#define BM_MMDC_MDRWD_WTW_DIFF      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDRWD_WTW_DIFF(v)   ((((reg32_t) v) << 6) & BM_MMDC_MDRWD_WTW_DIFF)
#else
#define BF_MMDC_MDRWD_WTW_DIFF(v)   (((v) << 6) & BM_MMDC_MDRWD_WTW_DIFF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDRWD_WTW_DIFF(v)   BF_CS1(MMDC_MDRWD, WTW_DIFF, v)
#endif

/* --- Register HW_MMDC_MDRWD, field WTR_DIFF
 *
 * Write to read delay for different chip-select. This field controls
 * the delay between write to read commands toward different chip
 * select.  The total delay is calculated according to: BL/2 + WTR_DIFF +
 * (tCL-tCWL) + RALAT
 */

#define BP_MMDC_MDRWD_WTR_DIFF      9
#define BM_MMDC_MDRWD_WTR_DIFF      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDRWD_WTR_DIFF(v)   ((((reg32_t) v) << 9) & BM_MMDC_MDRWD_WTR_DIFF)
#else
#define BF_MMDC_MDRWD_WTR_DIFF(v)   (((v) << 9) & BM_MMDC_MDRWD_WTR_DIFF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDRWD_WTR_DIFF(v)   BF_CS1(MMDC_MDRWD, WTR_DIFF, v)
#endif

/* --- Register HW_MMDC_MDRWD, field RTW_SAME
 *
 * Read to write delay for the same chip-select. This field controls the
 * delay between read to write commands toward the same chip                                 select.
 * The total delay is calculated according to: BL/2 + RTW_SAME +
 * (tCL-tCWL) + RALAT
 */

#define BP_MMDC_MDRWD_RTW_SAME      12
#define BM_MMDC_MDRWD_RTW_SAME      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDRWD_RTW_SAME(v)   ((((reg32_t) v) << 12) & BM_MMDC_MDRWD_RTW_SAME)
#else
#define BF_MMDC_MDRWD_RTW_SAME(v)   (((v) << 12) & BM_MMDC_MDRWD_RTW_SAME)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDRWD_RTW_SAME(v)   BF_CS1(MMDC_MDRWD, RTW_SAME, v)
#endif

/* --- Register HW_MMDC_MDRWD, field TDAI
 *
 * Device auto initialization period.(maximum)  This field is relevant only to LPDDR2 mode
 */

#define BP_MMDC_MDRWD_TDAI      16
#define BM_MMDC_MDRWD_TDAI      0x1fff0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDRWD_TDAI(v)   ((((reg32_t) v) << 16) & BM_MMDC_MDRWD_TDAI)
#else
#define BF_MMDC_MDRWD_TDAI(v)   (((v) << 16) & BM_MMDC_MDRWD_TDAI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDRWD_TDAI(v)   BF_CS1(MMDC_MDRWD, TDAI, v)
#endif

/*!
 * @brief HW_MMDC_MDOR - MMDC Core Out of Reset Delays Register
 *
 * This register defines delays that must be kept when MMDC exits                         reset.
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RST_TO_CKE : 6; //!< DDR3: Time from SDE enable to CKE rise. In case that DDR reset# is low, will wait until it's high and then wait this period until rising CKE. (JEDEC value is 500 us)  In DDR2 mode this field is referred to to the time from SDE enable to CKE rise. (JEDEC value is 200 us)  LPDDR2: Idle time ater first CKE assertion. (JEDEC value is 200 us)  Each cycle in this field is 15.625 us.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned SDE_TO_RST : 6; //!< DDR3: Time from SDE enable until DDR reset# is high.  In DDR2/ LPDDR2 mode this field is not relevant .  Each cycle in this field is 15.625 us.
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned TXPR : 8; //!< DDR2/ DDR3: CKE HIGH to a valid command.  This field is not relevant in LPDDR2 mode.   According to DDR2 JEDEC standard this field supposes to be 400 ns.   DDR3: As defined in timing parameter table.
        unsigned RESERVED2 : 8; //!< Reserved
    } B;
} hw_mmdc_mdor_t;
#endif

/*
 * constants & macros for entire MMDC_MDOR register
 */
#define HW_MMDC_MDOR_ADDR      (REGS_MMDC_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MDOR           (*(volatile hw_mmdc_mdor_t *) HW_MMDC_MDOR_ADDR)
#define HW_MMDC_MDOR_RD()      (HW_MMDC_MDOR.U)
#define HW_MMDC_MDOR_WR(v)     (HW_MMDC_MDOR.U = (v))
#define HW_MMDC_MDOR_SET(v)    (HW_MMDC_MDOR_WR(HW_MMDC_MDOR_RD() |  (v)))
#define HW_MMDC_MDOR_CLR(v)    (HW_MMDC_MDOR_WR(HW_MMDC_MDOR_RD() & ~(v)))
#define HW_MMDC_MDOR_TOG(v)    (HW_MMDC_MDOR_WR(HW_MMDC_MDOR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MDOR bitfields
 */

/* --- Register HW_MMDC_MDOR, field RST_TO_CKE
 *
 * DDR3: Time from SDE enable to CKE rise. In case that DDR reset# is
 * low, will wait until it's high and then wait this period until
 * rising CKE. (JEDEC value is 500 us)  In DDR2 mode this field is referred to to the
 * time from SDE enable to CKE rise. (JEDEC value is 200 us)  LPDDR2: Idle time ater first CKE
 * assertion. (JEDEC value is 200                                 us)  Each cycle in this field is
 * 15.625 us.
 */

#define BP_MMDC_MDOR_RST_TO_CKE      0
#define BM_MMDC_MDOR_RST_TO_CKE      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDOR_RST_TO_CKE(v)   ((((reg32_t) v) << 0) & BM_MMDC_MDOR_RST_TO_CKE)
#else
#define BF_MMDC_MDOR_RST_TO_CKE(v)   (((v) << 0) & BM_MMDC_MDOR_RST_TO_CKE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDOR_RST_TO_CKE(v)   BF_CS1(MMDC_MDOR, RST_TO_CKE, v)
#endif

/* --- Register HW_MMDC_MDOR, field SDE_TO_RST
 *
 * DDR3: Time from SDE enable until DDR reset# is high.  In DDR2/ LPDDR2 mode this field is not
 * relevant .  Each cycle in this field is 15.625 us.
 */

#define BP_MMDC_MDOR_SDE_TO_RST      8
#define BM_MMDC_MDOR_SDE_TO_RST      0x00003f00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDOR_SDE_TO_RST(v)   ((((reg32_t) v) << 8) & BM_MMDC_MDOR_SDE_TO_RST)
#else
#define BF_MMDC_MDOR_SDE_TO_RST(v)   (((v) << 8) & BM_MMDC_MDOR_SDE_TO_RST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDOR_SDE_TO_RST(v)   BF_CS1(MMDC_MDOR, SDE_TO_RST, v)
#endif

/* --- Register HW_MMDC_MDOR, field TXPR
 *
 * DDR2/ DDR3: CKE HIGH to a valid                                 command.  This field is not
 * relevant in LPDDR2 mode.   According to DDR2 JEDEC standard this field
 * supposes to be 400 ns.   DDR3: As defined in timing parameter table.
 */

#define BP_MMDC_MDOR_TXPR      16
#define BM_MMDC_MDOR_TXPR      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDOR_TXPR(v)   ((((reg32_t) v) << 16) & BM_MMDC_MDOR_TXPR)
#else
#define BF_MMDC_MDOR_TXPR(v)   (((v) << 16) & BM_MMDC_MDOR_TXPR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDOR_TXPR(v)   BF_CS1(MMDC_MDOR, TXPR, v)
#endif

/*!
 * @brief HW_MMDC_MDMRR - MMDC Core MRR Data Register
 *
 * This register contains data that was collected after issuing MRR command.
 * The data in this register is valid only when MDSCR[MRR_READ_DATA_VALID]
 * is set to "1".  This register is relevant only in LPDDR2 mode. For further information
 * see .  Supported Mode Of Operations:  For Channel 0: LP2_2ch_x16, LP2_2ch_x32  For Channel 1:
 * LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MRR_READ_DATA0 : 8; //!< MRR DATA that arrived on DQ[7:0]
        unsigned MRR_READ_DATA1 : 8; //!< MRR DATA that arrived on DQ[15:8]
        unsigned MRR_READ_DATA2 : 8; //!< MRR DATA that arrived on DQ[23:16]
        unsigned MRR_READ_DATA3 : 8; //!< MRR DATA that arrived on DQ[31:24]
    } B;
} hw_mmdc_mdmrr_t;
#endif

/*
 * constants & macros for entire MMDC_MDMRR register
 */
#define HW_MMDC_MDMRR_ADDR      (REGS_MMDC_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MDMRR           (*(volatile hw_mmdc_mdmrr_t *) HW_MMDC_MDMRR_ADDR)
#define HW_MMDC_MDMRR_RD()      (HW_MMDC_MDMRR.U)
#define HW_MMDC_MDMRR_WR(v)     (HW_MMDC_MDMRR.U = (v))
#define HW_MMDC_MDMRR_SET(v)    (HW_MMDC_MDMRR_WR(HW_MMDC_MDMRR_RD() |  (v)))
#define HW_MMDC_MDMRR_CLR(v)    (HW_MMDC_MDMRR_WR(HW_MMDC_MDMRR_RD() & ~(v)))
#define HW_MMDC_MDMRR_TOG(v)    (HW_MMDC_MDMRR_WR(HW_MMDC_MDMRR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MDMRR bitfields
 */

/* --- Register HW_MMDC_MDMRR, field MRR_READ_DATA0
 *
 * MRR DATA that arrived on DQ[7:0]
 */

#define BP_MMDC_MDMRR_MRR_READ_DATA0      0
#define BM_MMDC_MDMRR_MRR_READ_DATA0      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMRR_MRR_READ_DATA0(v)   ((((reg32_t) v) << 0) & BM_MMDC_MDMRR_MRR_READ_DATA0)
#else
#define BF_MMDC_MDMRR_MRR_READ_DATA0(v)   (((v) << 0) & BM_MMDC_MDMRR_MRR_READ_DATA0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMRR_MRR_READ_DATA0(v)   BF_CS1(MMDC_MDMRR, MRR_READ_DATA0, v)
#endif

/* --- Register HW_MMDC_MDMRR, field MRR_READ_DATA1
 *
 * MRR DATA that arrived on DQ[15:8]
 */

#define BP_MMDC_MDMRR_MRR_READ_DATA1      8
#define BM_MMDC_MDMRR_MRR_READ_DATA1      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMRR_MRR_READ_DATA1(v)   ((((reg32_t) v) << 8) & BM_MMDC_MDMRR_MRR_READ_DATA1)
#else
#define BF_MMDC_MDMRR_MRR_READ_DATA1(v)   (((v) << 8) & BM_MMDC_MDMRR_MRR_READ_DATA1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMRR_MRR_READ_DATA1(v)   BF_CS1(MMDC_MDMRR, MRR_READ_DATA1, v)
#endif

/* --- Register HW_MMDC_MDMRR, field MRR_READ_DATA2
 *
 * MRR DATA that arrived on DQ[23:16]
 */

#define BP_MMDC_MDMRR_MRR_READ_DATA2      16
#define BM_MMDC_MDMRR_MRR_READ_DATA2      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMRR_MRR_READ_DATA2(v)   ((((reg32_t) v) << 16) & BM_MMDC_MDMRR_MRR_READ_DATA2)
#else
#define BF_MMDC_MDMRR_MRR_READ_DATA2(v)   (((v) << 16) & BM_MMDC_MDMRR_MRR_READ_DATA2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMRR_MRR_READ_DATA2(v)   BF_CS1(MMDC_MDMRR, MRR_READ_DATA2, v)
#endif

/* --- Register HW_MMDC_MDMRR, field MRR_READ_DATA3
 *
 * MRR DATA that arrived on DQ[31:24]
 */

#define BP_MMDC_MDMRR_MRR_READ_DATA3      24
#define BM_MMDC_MDMRR_MRR_READ_DATA3      0xff000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMRR_MRR_READ_DATA3(v)   ((((reg32_t) v) << 24) & BM_MMDC_MDMRR_MRR_READ_DATA3)
#else
#define BF_MMDC_MDMRR_MRR_READ_DATA3(v)   (((v) << 24) & BM_MMDC_MDMRR_MRR_READ_DATA3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMRR_MRR_READ_DATA3(v)   BF_CS1(MMDC_MDMRR, MRR_READ_DATA3, v)
#endif

/*!
 * @brief HW_MMDC_MDCFG3LP - MMDC Core Timing Configuration Register 3
 *
 * This register is relevant only for LPDDR2 mode.  Supported Mode Of Operations:  For Channel 0:
 * LP2_2ch_x16, LP2_2ch_x32  For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned TRPAB_LP : 4; //!< Precharge (all banks) command period.  (This field is valid only for LPDDR2 memories)
        unsigned TRPPB_LP : 4; //!< Precharge (per bank) command period (same bank).  (This field is valid only for LPDDR2 memories)
        unsigned TRCD_LP : 4; //!< Active command to internal read or write delay time (same bank).  (This field is valid only for LPDDR2 memories)
        unsigned RESERVED0 : 4; //!< Reserved
        unsigned RC_LP : 6; //!< Active to Active or Refresh command period (same bank).  (This field is valid only for LPDDR2 memories)
        unsigned RESERVED1 : 10; //!< Reserved
    } B;
} hw_mmdc_mdcfg3lp_t;
#endif

/*
 * constants & macros for entire MMDC_MDCFG3LP register
 */
#define HW_MMDC_MDCFG3LP_ADDR      (REGS_MMDC_BASE + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MDCFG3LP           (*(volatile hw_mmdc_mdcfg3lp_t *) HW_MMDC_MDCFG3LP_ADDR)
#define HW_MMDC_MDCFG3LP_RD()      (HW_MMDC_MDCFG3LP.U)
#define HW_MMDC_MDCFG3LP_WR(v)     (HW_MMDC_MDCFG3LP.U = (v))
#define HW_MMDC_MDCFG3LP_SET(v)    (HW_MMDC_MDCFG3LP_WR(HW_MMDC_MDCFG3LP_RD() |  (v)))
#define HW_MMDC_MDCFG3LP_CLR(v)    (HW_MMDC_MDCFG3LP_WR(HW_MMDC_MDCFG3LP_RD() & ~(v)))
#define HW_MMDC_MDCFG3LP_TOG(v)    (HW_MMDC_MDCFG3LP_WR(HW_MMDC_MDCFG3LP_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MDCFG3LP bitfields
 */

/* --- Register HW_MMDC_MDCFG3LP, field TRPAB_LP
 *
 * Precharge (all banks) command period.  (This field is valid only for LPDDR2 memories)
 */

#define BP_MMDC_MDCFG3LP_TRPAB_LP      0
#define BM_MMDC_MDCFG3LP_TRPAB_LP      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCFG3LP_TRPAB_LP(v)   ((((reg32_t) v) << 0) & BM_MMDC_MDCFG3LP_TRPAB_LP)
#else
#define BF_MMDC_MDCFG3LP_TRPAB_LP(v)   (((v) << 0) & BM_MMDC_MDCFG3LP_TRPAB_LP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCFG3LP_TRPAB_LP(v)   BF_CS1(MMDC_MDCFG3LP, TRPAB_LP, v)
#endif

/* --- Register HW_MMDC_MDCFG3LP, field TRPPB_LP
 *
 * Precharge (per bank) command period (same bank).  (This field is valid only for LPDDR2 memories)
 */

#define BP_MMDC_MDCFG3LP_TRPPB_LP      4
#define BM_MMDC_MDCFG3LP_TRPPB_LP      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCFG3LP_TRPPB_LP(v)   ((((reg32_t) v) << 4) & BM_MMDC_MDCFG3LP_TRPPB_LP)
#else
#define BF_MMDC_MDCFG3LP_TRPPB_LP(v)   (((v) << 4) & BM_MMDC_MDCFG3LP_TRPPB_LP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCFG3LP_TRPPB_LP(v)   BF_CS1(MMDC_MDCFG3LP, TRPPB_LP, v)
#endif

/* --- Register HW_MMDC_MDCFG3LP, field TRCD_LP
 *
 * Active command to internal read or write delay time (same bank).  (This field is valid only for
 * LPDDR2 memories)
 */

#define BP_MMDC_MDCFG3LP_TRCD_LP      8
#define BM_MMDC_MDCFG3LP_TRCD_LP      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCFG3LP_TRCD_LP(v)   ((((reg32_t) v) << 8) & BM_MMDC_MDCFG3LP_TRCD_LP)
#else
#define BF_MMDC_MDCFG3LP_TRCD_LP(v)   (((v) << 8) & BM_MMDC_MDCFG3LP_TRCD_LP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCFG3LP_TRCD_LP(v)   BF_CS1(MMDC_MDCFG3LP, TRCD_LP, v)
#endif

/* --- Register HW_MMDC_MDCFG3LP, field RC_LP
 *
 * Active to Active or Refresh command period (same bank).  (This field is valid only for LPDDR2
 * memories)
 */

#define BP_MMDC_MDCFG3LP_RC_LP      16
#define BM_MMDC_MDCFG3LP_RC_LP      0x003f0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDCFG3LP_RC_LP(v)   ((((reg32_t) v) << 16) & BM_MMDC_MDCFG3LP_RC_LP)
#else
#define BF_MMDC_MDCFG3LP_RC_LP(v)   (((v) << 16) & BM_MMDC_MDCFG3LP_RC_LP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDCFG3LP_RC_LP(v)   BF_CS1(MMDC_MDCFG3LP, RC_LP, v)
#endif

/*!
 * @brief HW_MMDC_MDMR4 - MMDC Core MR4 Derating Register
 *
 * This register is relevant only for LPDDR2 mode. It is used to dynamically
 * change certain values depending on MR4 read result, which is based on
 * memory temperature sensor result.  Supported Mode of Operations:  For Channel 0: LP2_2ch_x16,
 * LP2_2ch_x32  For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned UPDATE_DE_REQ : 1; //!< Update Derated Values Request.  This read modify write field is automatically cleared after the request is issued.
        unsigned UPDATE_DE_ACK : 1; //!< Update Derated Values Acknowledge.  This read only bit will be cleared upon UPDATE_DE_REQ assertion and will be set after the new values are taken.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned TRCD_DE : 1; //!< tRCD derating value.
        unsigned TRC_DE : 1; //!< tRC derating value.
        unsigned TRAS_DE : 1; //!< tRAS derating value.
        unsigned TRP_DE : 1; //!< tRP derating value.
        unsigned TRRD_DE : 1; //!< tRRD derating value.
        unsigned RESERVED1 : 23; //!< Reserved
    } B;
} hw_mmdc_mdmr4_t;
#endif

/*
 * constants & macros for entire MMDC_MDMR4 register
 */
#define HW_MMDC_MDMR4_ADDR      (REGS_MMDC_BASE + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MDMR4           (*(volatile hw_mmdc_mdmr4_t *) HW_MMDC_MDMR4_ADDR)
#define HW_MMDC_MDMR4_RD()      (HW_MMDC_MDMR4.U)
#define HW_MMDC_MDMR4_WR(v)     (HW_MMDC_MDMR4.U = (v))
#define HW_MMDC_MDMR4_SET(v)    (HW_MMDC_MDMR4_WR(HW_MMDC_MDMR4_RD() |  (v)))
#define HW_MMDC_MDMR4_CLR(v)    (HW_MMDC_MDMR4_WR(HW_MMDC_MDMR4_RD() & ~(v)))
#define HW_MMDC_MDMR4_TOG(v)    (HW_MMDC_MDMR4_WR(HW_MMDC_MDMR4_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MDMR4 bitfields
 */

/* --- Register HW_MMDC_MDMR4, field UPDATE_DE_REQ
 *
 * Update Derated Values Request.  This read modify write field is automatically cleared after the
 * request is issued.
 */

#define BP_MMDC_MDMR4_UPDATE_DE_REQ      0
#define BM_MMDC_MDMR4_UPDATE_DE_REQ      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMR4_UPDATE_DE_REQ(v)   ((((reg32_t) v) << 0) & BM_MMDC_MDMR4_UPDATE_DE_REQ)
#else
#define BF_MMDC_MDMR4_UPDATE_DE_REQ(v)   (((v) << 0) & BM_MMDC_MDMR4_UPDATE_DE_REQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMR4_UPDATE_DE_REQ(v)   BF_CS1(MMDC_MDMR4, UPDATE_DE_REQ, v)
#endif

/* --- Register HW_MMDC_MDMR4, field UPDATE_DE_ACK
 *
 * Update Derated Values Acknowledge.  This read only bit will be cleared upon UPDATE_DE_REQ
 * assertion and                                 will be set after the new values are taken.
 */

#define BP_MMDC_MDMR4_UPDATE_DE_ACK      1
#define BM_MMDC_MDMR4_UPDATE_DE_ACK      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMR4_UPDATE_DE_ACK(v)   ((((reg32_t) v) << 1) & BM_MMDC_MDMR4_UPDATE_DE_ACK)
#else
#define BF_MMDC_MDMR4_UPDATE_DE_ACK(v)   (((v) << 1) & BM_MMDC_MDMR4_UPDATE_DE_ACK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMR4_UPDATE_DE_ACK(v)   BF_CS1(MMDC_MDMR4, UPDATE_DE_ACK, v)
#endif

/* --- Register HW_MMDC_MDMR4, field TRCD_DE
 *
 * tRCD derating value.
 */

#define BP_MMDC_MDMR4_TRCD_DE      4
#define BM_MMDC_MDMR4_TRCD_DE      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMR4_TRCD_DE(v)   ((((reg32_t) v) << 4) & BM_MMDC_MDMR4_TRCD_DE)
#else
#define BF_MMDC_MDMR4_TRCD_DE(v)   (((v) << 4) & BM_MMDC_MDMR4_TRCD_DE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMR4_TRCD_DE(v)   BF_CS1(MMDC_MDMR4, TRCD_DE, v)
#endif

/* --- Register HW_MMDC_MDMR4, field TRC_DE
 *
 * tRC derating value.
 */

#define BP_MMDC_MDMR4_TRC_DE      5
#define BM_MMDC_MDMR4_TRC_DE      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMR4_TRC_DE(v)   ((((reg32_t) v) << 5) & BM_MMDC_MDMR4_TRC_DE)
#else
#define BF_MMDC_MDMR4_TRC_DE(v)   (((v) << 5) & BM_MMDC_MDMR4_TRC_DE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMR4_TRC_DE(v)   BF_CS1(MMDC_MDMR4, TRC_DE, v)
#endif

/* --- Register HW_MMDC_MDMR4, field TRAS_DE
 *
 * tRAS derating value.
 */

#define BP_MMDC_MDMR4_TRAS_DE      6
#define BM_MMDC_MDMR4_TRAS_DE      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMR4_TRAS_DE(v)   ((((reg32_t) v) << 6) & BM_MMDC_MDMR4_TRAS_DE)
#else
#define BF_MMDC_MDMR4_TRAS_DE(v)   (((v) << 6) & BM_MMDC_MDMR4_TRAS_DE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMR4_TRAS_DE(v)   BF_CS1(MMDC_MDMR4, TRAS_DE, v)
#endif

/* --- Register HW_MMDC_MDMR4, field TRP_DE
 *
 * tRP derating value.
 */

#define BP_MMDC_MDMR4_TRP_DE      7
#define BM_MMDC_MDMR4_TRP_DE      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMR4_TRP_DE(v)   ((((reg32_t) v) << 7) & BM_MMDC_MDMR4_TRP_DE)
#else
#define BF_MMDC_MDMR4_TRP_DE(v)   (((v) << 7) & BM_MMDC_MDMR4_TRP_DE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMR4_TRP_DE(v)   BF_CS1(MMDC_MDMR4, TRP_DE, v)
#endif

/* --- Register HW_MMDC_MDMR4, field TRRD_DE
 *
 * tRRD derating value.
 */

#define BP_MMDC_MDMR4_TRRD_DE      8
#define BM_MMDC_MDMR4_TRRD_DE      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDMR4_TRRD_DE(v)   ((((reg32_t) v) << 8) & BM_MMDC_MDMR4_TRRD_DE)
#else
#define BF_MMDC_MDMR4_TRRD_DE(v)   (((v) << 8) & BM_MMDC_MDMR4_TRRD_DE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDMR4_TRRD_DE(v)   BF_CS1(MMDC_MDMR4, TRRD_DE, v)
#endif

/*!
 * @brief HW_MMDC_MDASP - MMDC Core Address Space Partition Register
 *
 * This register defines the partitioning between chip select 0 and chip
 * select 1. For further information see .  Supported Mode Of Operations:  For Channel 0: All  For
 * Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CS0_END : 7; //!< CS0_END. Defines the absolute last address associated with CS0 with increments of 256Mb
        unsigned RESERVED0 : 25; //!< Reserved
    } B;
} hw_mmdc_mdasp_t;
#endif

/*
 * constants & macros for entire MMDC_MDASP register
 */
#define HW_MMDC_MDASP_ADDR      (REGS_MMDC_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MDASP           (*(volatile hw_mmdc_mdasp_t *) HW_MMDC_MDASP_ADDR)
#define HW_MMDC_MDASP_RD()      (HW_MMDC_MDASP.U)
#define HW_MMDC_MDASP_WR(v)     (HW_MMDC_MDASP.U = (v))
#define HW_MMDC_MDASP_SET(v)    (HW_MMDC_MDASP_WR(HW_MMDC_MDASP_RD() |  (v)))
#define HW_MMDC_MDASP_CLR(v)    (HW_MMDC_MDASP_WR(HW_MMDC_MDASP_RD() & ~(v)))
#define HW_MMDC_MDASP_TOG(v)    (HW_MMDC_MDASP_WR(HW_MMDC_MDASP_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MDASP bitfields
 */

/* --- Register HW_MMDC_MDASP, field CS0_END
 *
 * CS0_END. Defines the absolute last address associated with CS0 with
 * increments of 256Mb
 */

#define BP_MMDC_MDASP_CS0_END      0
#define BM_MMDC_MDASP_CS0_END      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MDASP_CS0_END(v)   ((((reg32_t) v) << 0) & BM_MMDC_MDASP_CS0_END)
#else
#define BF_MMDC_MDASP_CS0_END(v)   (((v) << 0) & BM_MMDC_MDASP_CS0_END)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MDASP_CS0_END(v)   BF_CS1(MMDC_MDASP, CS0_END, v)
#endif

/*!
 * @brief HW_MMDC_MAARCR - MMDC Core AXI Reordering Control Regsiter
 *
 * This register determines the values of the weights used for the                             re-
 * ordering arbitration engine. For further information see .  Supported Mode Of Operations:  For
 * Channel 0: All  For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ARCR_GUARD : 4; //!< ARCR Guard. After an access reached the maximum dynamic score value, it will wait additional ARCR_GUARD arbitration cycles and then will gain the highest priority in the optimization/reordering mechanism.
        unsigned ARCR_DYN_MAX : 4; //!< ARCR Dynamic Maximum. ARCR_DYN_MAX is the maximum dynamic score value that each access inside the optimization/reordering mechanism can get.
        unsigned ARCR_DYN_JMP : 4; //!< ARCR Dynamic Jump. Each time an access wan't chosen by the optimization/reordering mechanism then its dynamic score will be incremented by ARCR_DYN_JMP value.  Setting ARCR_DYN_JMP may cause starvation of low priority accesses  ARCR_DYN_JMP must be smaller than ARCR_DYN_MAX  Default ARCR_DYN_JMP value is 0x0001 - encoding 1
        unsigned RESERVED0 : 4; //!< Reserved
        unsigned ARCR_ACC_HIT : 3; //!< ARCR Access Hit Rate. This value will be added by the optimization/reordering mechanism to any pending access that has the same access type (read/write) as the previous access.  Default value of is ARCR_ACC_HIT 0x0010 - encoding 2.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned ARCR_PAG_HIT : 3; //!< ARCR Page Hit Rate. This value will be added by the optimization/reordering mechanism to any pending access that is targeted to an open DDR row.  Default value of ARCR_PAG_HIT is 0x00100 - encoding 4.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned ARCR_RCH_EN : 1; //!< This bit defines whether Real time channel is activated and bypassed all other pending accesses, So accesses with QoS=='F' will be granted the highest prioritiy in the optimization/reordering mechanism  Default value is 0x1 - encoding 1 (Enabled)
        unsigned RESERVED3 : 3; //!< Reserved
        unsigned ARCR_EXC_ERR_EN : 1; //!< This bit defines whether exclusive read/write access violation of AXI 6.2.4 rule result in SLV Error response or in OKAY response  Default value is 0x1 - encoding 1(response is SLV Error)
        unsigned RESERVED4 : 1; //!< Reserved
        unsigned ARCR_SEC_ERR_EN : 1; //!< This bit defines whether security read/write access violation result in SLV Error response or in OKAY response  Default value is 0x1 - encoding 1(response is SLV Error, rresp/bresp=2'b10)
        unsigned ARCR_SEC_ERR_LOCK : 1; //!< Once set, this bit locks ARCR_SEC_ERR_EN and prevents from its updating. This bit can be only cleared by reset  Default value is 0x0 - encoding 0 (unlocked)
    } B;
} hw_mmdc_maarcr_t;
#endif

/*
 * constants & macros for entire MMDC_MAARCR register
 */
#define HW_MMDC_MAARCR_ADDR      (REGS_MMDC_BASE + 0x400)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MAARCR           (*(volatile hw_mmdc_maarcr_t *) HW_MMDC_MAARCR_ADDR)
#define HW_MMDC_MAARCR_RD()      (HW_MMDC_MAARCR.U)
#define HW_MMDC_MAARCR_WR(v)     (HW_MMDC_MAARCR.U = (v))
#define HW_MMDC_MAARCR_SET(v)    (HW_MMDC_MAARCR_WR(HW_MMDC_MAARCR_RD() |  (v)))
#define HW_MMDC_MAARCR_CLR(v)    (HW_MMDC_MAARCR_WR(HW_MMDC_MAARCR_RD() & ~(v)))
#define HW_MMDC_MAARCR_TOG(v)    (HW_MMDC_MAARCR_WR(HW_MMDC_MAARCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MAARCR bitfields
 */

/* --- Register HW_MMDC_MAARCR, field ARCR_GUARD
 *
 * ARCR Guard. After an access reached the maximum dynamic score value,
 * it will wait additional ARCR_GUARD arbitration cycles and then will
 * gain the highest priority in the optimization/reordering
 * mechanism.
 */

#define BP_MMDC_MAARCR_ARCR_GUARD      0
#define BM_MMDC_MAARCR_ARCR_GUARD      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAARCR_ARCR_GUARD(v)   ((((reg32_t) v) << 0) & BM_MMDC_MAARCR_ARCR_GUARD)
#else
#define BF_MMDC_MAARCR_ARCR_GUARD(v)   (((v) << 0) & BM_MMDC_MAARCR_ARCR_GUARD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAARCR_ARCR_GUARD(v)   BF_CS1(MMDC_MAARCR, ARCR_GUARD, v)
#endif

/* --- Register HW_MMDC_MAARCR, field ARCR_DYN_MAX
 *
 * ARCR Dynamic Maximum. ARCR_DYN_MAX is the maximum dynamic score value
 * that each access inside the optimization/reordering mechanism can
 * get.
 */

#define BP_MMDC_MAARCR_ARCR_DYN_MAX      4
#define BM_MMDC_MAARCR_ARCR_DYN_MAX      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAARCR_ARCR_DYN_MAX(v)   ((((reg32_t) v) << 4) & BM_MMDC_MAARCR_ARCR_DYN_MAX)
#else
#define BF_MMDC_MAARCR_ARCR_DYN_MAX(v)   (((v) << 4) & BM_MMDC_MAARCR_ARCR_DYN_MAX)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAARCR_ARCR_DYN_MAX(v)   BF_CS1(MMDC_MAARCR, ARCR_DYN_MAX, v)
#endif

/* --- Register HW_MMDC_MAARCR, field ARCR_DYN_JMP
 *
 * ARCR Dynamic Jump. Each time an access wan't chosen by the
 * optimization/reordering mechanism then its dynamic score will be
 * incremented by ARCR_DYN_JMP value.  Setting ARCR_DYN_JMP may cause starvation of low priority
 * accesses  ARCR_DYN_JMP must be smaller than ARCR_DYN_MAX  Default ARCR_DYN_JMP value is 0x0001 -
 * encoding 1
 */

#define BP_MMDC_MAARCR_ARCR_DYN_JMP      8
#define BM_MMDC_MAARCR_ARCR_DYN_JMP      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAARCR_ARCR_DYN_JMP(v)   ((((reg32_t) v) << 8) & BM_MMDC_MAARCR_ARCR_DYN_JMP)
#else
#define BF_MMDC_MAARCR_ARCR_DYN_JMP(v)   (((v) << 8) & BM_MMDC_MAARCR_ARCR_DYN_JMP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAARCR_ARCR_DYN_JMP(v)   BF_CS1(MMDC_MAARCR, ARCR_DYN_JMP, v)
#endif

/* --- Register HW_MMDC_MAARCR, field ARCR_ACC_HIT
 *
 * ARCR Access Hit Rate. This value will be added by the
 * optimization/reordering mechanism to any pending access that has the
 * same access type (read/write) as the previous access.  Default value of is ARCR_ACC_HIT 0x0010 -
 * encoding 2.
 */

#define BP_MMDC_MAARCR_ARCR_ACC_HIT      16
#define BM_MMDC_MAARCR_ARCR_ACC_HIT      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAARCR_ARCR_ACC_HIT(v)   ((((reg32_t) v) << 16) & BM_MMDC_MAARCR_ARCR_ACC_HIT)
#else
#define BF_MMDC_MAARCR_ARCR_ACC_HIT(v)   (((v) << 16) & BM_MMDC_MAARCR_ARCR_ACC_HIT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAARCR_ARCR_ACC_HIT(v)   BF_CS1(MMDC_MAARCR, ARCR_ACC_HIT, v)
#endif

/* --- Register HW_MMDC_MAARCR, field ARCR_PAG_HIT
 *
 * ARCR Page Hit Rate. This value will be added by the
 * optimization/reordering mechanism to any pending access that is
 * targeted to an open DDR row.  Default value of ARCR_PAG_HIT is 0x00100 - encoding 4.
 */

#define BP_MMDC_MAARCR_ARCR_PAG_HIT      20
#define BM_MMDC_MAARCR_ARCR_PAG_HIT      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAARCR_ARCR_PAG_HIT(v)   ((((reg32_t) v) << 20) & BM_MMDC_MAARCR_ARCR_PAG_HIT)
#else
#define BF_MMDC_MAARCR_ARCR_PAG_HIT(v)   (((v) << 20) & BM_MMDC_MAARCR_ARCR_PAG_HIT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAARCR_ARCR_PAG_HIT(v)   BF_CS1(MMDC_MAARCR, ARCR_PAG_HIT, v)
#endif

/* --- Register HW_MMDC_MAARCR, field ARCR_RCH_EN
 *
 * This bit defines whether Real time channel is activated and bypassed
 * all other pending accesses, So accesses with QoS=='F' will be
 * granted the highest prioritiy in the optimization/reordering
 * mechanism  Default value is 0x1 - encoding 1 (Enabled)
 */

#define BP_MMDC_MAARCR_ARCR_RCH_EN      24
#define BM_MMDC_MAARCR_ARCR_RCH_EN      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAARCR_ARCR_RCH_EN(v)   ((((reg32_t) v) << 24) & BM_MMDC_MAARCR_ARCR_RCH_EN)
#else
#define BF_MMDC_MAARCR_ARCR_RCH_EN(v)   (((v) << 24) & BM_MMDC_MAARCR_ARCR_RCH_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAARCR_ARCR_RCH_EN(v)   BF_CS1(MMDC_MAARCR, ARCR_RCH_EN, v)
#endif

/* --- Register HW_MMDC_MAARCR, field ARCR_EXC_ERR_EN
 *
 * This bit defines whether exclusive read/write access violation of AXI
 * 6.2.4 rule result in SLV Error response or in OKAY response  Default value is 0x1 - encoding
 * 1(response is SLV Error)
 */

#define BP_MMDC_MAARCR_ARCR_EXC_ERR_EN      28
#define BM_MMDC_MAARCR_ARCR_EXC_ERR_EN      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAARCR_ARCR_EXC_ERR_EN(v)   ((((reg32_t) v) << 28) & BM_MMDC_MAARCR_ARCR_EXC_ERR_EN)
#else
#define BF_MMDC_MAARCR_ARCR_EXC_ERR_EN(v)   (((v) << 28) & BM_MMDC_MAARCR_ARCR_EXC_ERR_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAARCR_ARCR_EXC_ERR_EN(v)   BF_CS1(MMDC_MAARCR, ARCR_EXC_ERR_EN, v)
#endif

/* --- Register HW_MMDC_MAARCR, field ARCR_SEC_ERR_EN
 *
 * This bit defines whether security read/write access violation result
 * in SLV Error response or in OKAY response  Default value is 0x1 - encoding 1(response is SLV
 * Error,                                 rresp/bresp=2'b10)
 */

#define BP_MMDC_MAARCR_ARCR_SEC_ERR_EN      30
#define BM_MMDC_MAARCR_ARCR_SEC_ERR_EN      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAARCR_ARCR_SEC_ERR_EN(v)   ((((reg32_t) v) << 30) & BM_MMDC_MAARCR_ARCR_SEC_ERR_EN)
#else
#define BF_MMDC_MAARCR_ARCR_SEC_ERR_EN(v)   (((v) << 30) & BM_MMDC_MAARCR_ARCR_SEC_ERR_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAARCR_ARCR_SEC_ERR_EN(v)   BF_CS1(MMDC_MAARCR, ARCR_SEC_ERR_EN, v)
#endif

/* --- Register HW_MMDC_MAARCR, field ARCR_SEC_ERR_LOCK
 *
 * Once set, this bit locks ARCR_SEC_ERR_EN and prevents from its
 * updating. This bit can be only cleared by reset  Default value is 0x0 - encoding 0 (unlocked)
 */

#define BP_MMDC_MAARCR_ARCR_SEC_ERR_LOCK      31
#define BM_MMDC_MAARCR_ARCR_SEC_ERR_LOCK      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAARCR_ARCR_SEC_ERR_LOCK(v)   ((((reg32_t) v) << 31) & BM_MMDC_MAARCR_ARCR_SEC_ERR_LOCK)
#else
#define BF_MMDC_MAARCR_ARCR_SEC_ERR_LOCK(v)   (((v) << 31) & BM_MMDC_MAARCR_ARCR_SEC_ERR_LOCK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAARCR_ARCR_SEC_ERR_LOCK(v)   BF_CS1(MMDC_MAARCR, ARCR_SEC_ERR_LOCK, v)
#endif

/*!
 * @brief HW_MMDC_MAPSR - MMDC Core Power Saving Control and Status                        Register
 *
 * The MAPSR determines the power saving features of MMDC. For further
 * information see .  Supported Mode Of Operations:  For Channel 0: All  For Channel 1: LP2_2ch_x16,
 * LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PSD : 1; //!< Automatic Power Saving Disable. When the value of PSD is "0" (i.e automatic power saving is enabled) then the PST is activated and MMDC will enter automatically to self-refresh while the number of idle cycle reached.  This bit must be disabled (i.e set to "1") during calibration process
        unsigned RESERVED0 : 3; //!< Reserved.
        unsigned PSS : 1; //!< Power Saving Status. This read only bit indicates whether the MMDC is in automatic power saving mode.
        unsigned RIS : 1; //!< Read Idle Status.This read only bit indicates whether read request buffer is idle (empty) or not.
        unsigned WIS : 1; //!< Write Idle Status.This read only bit indicates whether write request buffer is idle (empty) or not.
        unsigned RESERVED1 : 1; //!< Reserved.
        unsigned PST : 8; //!< Automatic Power saving timer.  Valid only when PSD is set to "0". When the MMDC is idle for amount of cycles specified in that field then the DDR device will be entered automatically into self-refresh mode.  The real value which is used is register-value multiplied by 64.
        unsigned RESERVED2 : 4; //!< Reserved
        unsigned LPMD : 1; //!< General LPMD request. SW request for LPMD. Assertion of this bit will yield in self-refresh entry sequence
        unsigned DVFS : 1; //!< General DVFS request. SW request for DVFS. Assertion of this bit will yield in self-refresh entry sequence
        unsigned RESERVED3 : 2; //!< Reserved
        unsigned LPACK : 1; //!< General low-power acknowledge. This read only bit indicates whether a low-power acknowledge was asserted and that MMDC is in self-refresh mode
        unsigned DVACK : 1; //!< General DVFS acknowledge. This read only bit indicates whether a dvfs acknowledge was asserted and that MMDC is in self-refresh mode
        unsigned RESERVED4 : 6; //!< Reserved
    } B;
} hw_mmdc_mapsr_t;
#endif

/*
 * constants & macros for entire MMDC_MAPSR register
 */
#define HW_MMDC_MAPSR_ADDR      (REGS_MMDC_BASE + 0x404)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MAPSR           (*(volatile hw_mmdc_mapsr_t *) HW_MMDC_MAPSR_ADDR)
#define HW_MMDC_MAPSR_RD()      (HW_MMDC_MAPSR.U)
#define HW_MMDC_MAPSR_WR(v)     (HW_MMDC_MAPSR.U = (v))
#define HW_MMDC_MAPSR_SET(v)    (HW_MMDC_MAPSR_WR(HW_MMDC_MAPSR_RD() |  (v)))
#define HW_MMDC_MAPSR_CLR(v)    (HW_MMDC_MAPSR_WR(HW_MMDC_MAPSR_RD() & ~(v)))
#define HW_MMDC_MAPSR_TOG(v)    (HW_MMDC_MAPSR_WR(HW_MMDC_MAPSR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MAPSR bitfields
 */

/* --- Register HW_MMDC_MAPSR, field PSD
 *
 * Automatic Power Saving Disable. When the value of PSD is "0" (i.e
 * automatic power saving is enabled) then the PST is activated and
 * MMDC will enter automatically to self-refresh while the number of
 * idle cycle reached.  This bit must be disabled (i.e set to "1") during calibration
 * process
 */

#define BP_MMDC_MAPSR_PSD      0
#define BM_MMDC_MAPSR_PSD      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAPSR_PSD(v)   ((((reg32_t) v) << 0) & BM_MMDC_MAPSR_PSD)
#else
#define BF_MMDC_MAPSR_PSD(v)   (((v) << 0) & BM_MMDC_MAPSR_PSD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAPSR_PSD(v)   BF_CS1(MMDC_MAPSR, PSD, v)
#endif

/* --- Register HW_MMDC_MAPSR, field PSS
 *
 * Power Saving Status. This read only bit indicates whether the MMDC is
 * in automatic power saving mode.
 */

#define BP_MMDC_MAPSR_PSS      4
#define BM_MMDC_MAPSR_PSS      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAPSR_PSS(v)   ((((reg32_t) v) << 4) & BM_MMDC_MAPSR_PSS)
#else
#define BF_MMDC_MAPSR_PSS(v)   (((v) << 4) & BM_MMDC_MAPSR_PSS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAPSR_PSS(v)   BF_CS1(MMDC_MAPSR, PSS, v)
#endif

/* --- Register HW_MMDC_MAPSR, field RIS
 *
 * Read Idle Status.This read only bit indicates whether read request
 * buffer is idle (empty) or not.
 */

#define BP_MMDC_MAPSR_RIS      5
#define BM_MMDC_MAPSR_RIS      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAPSR_RIS(v)   ((((reg32_t) v) << 5) & BM_MMDC_MAPSR_RIS)
#else
#define BF_MMDC_MAPSR_RIS(v)   (((v) << 5) & BM_MMDC_MAPSR_RIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAPSR_RIS(v)   BF_CS1(MMDC_MAPSR, RIS, v)
#endif

/* --- Register HW_MMDC_MAPSR, field WIS
 *
 * Write Idle Status.This read only bit indicates whether write request
 * buffer is idle (empty) or not.
 */

#define BP_MMDC_MAPSR_WIS      6
#define BM_MMDC_MAPSR_WIS      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAPSR_WIS(v)   ((((reg32_t) v) << 6) & BM_MMDC_MAPSR_WIS)
#else
#define BF_MMDC_MAPSR_WIS(v)   (((v) << 6) & BM_MMDC_MAPSR_WIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAPSR_WIS(v)   BF_CS1(MMDC_MAPSR, WIS, v)
#endif

/* --- Register HW_MMDC_MAPSR, field PST
 *
 * Automatic Power saving timer.  Valid only when PSD is set to "0". When the MMDC is idle for
 * amount                                 of cycles specified in that field then the DDR device will
 * be                                 entered automatically into self-refresh mode.  The real value
 * which is used is register-value multiplied by 64.
 */

#define BP_MMDC_MAPSR_PST      8
#define BM_MMDC_MAPSR_PST      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAPSR_PST(v)   ((((reg32_t) v) << 8) & BM_MMDC_MAPSR_PST)
#else
#define BF_MMDC_MAPSR_PST(v)   (((v) << 8) & BM_MMDC_MAPSR_PST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAPSR_PST(v)   BF_CS1(MMDC_MAPSR, PST, v)
#endif

/* --- Register HW_MMDC_MAPSR, field LPMD
 *
 * General LPMD request. SW request for LPMD. Assertion of this bit will
 * yield in self-refresh entry sequence
 */

#define BP_MMDC_MAPSR_LPMD      20
#define BM_MMDC_MAPSR_LPMD      0x00100000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAPSR_LPMD(v)   ((((reg32_t) v) << 20) & BM_MMDC_MAPSR_LPMD)
#else
#define BF_MMDC_MAPSR_LPMD(v)   (((v) << 20) & BM_MMDC_MAPSR_LPMD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAPSR_LPMD(v)   BF_CS1(MMDC_MAPSR, LPMD, v)
#endif

/* --- Register HW_MMDC_MAPSR, field DVFS
 *
 * General DVFS request. SW request for DVFS. Assertion of this bit will
 * yield in self-refresh entry sequence
 */

#define BP_MMDC_MAPSR_DVFS      21
#define BM_MMDC_MAPSR_DVFS      0x00200000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAPSR_DVFS(v)   ((((reg32_t) v) << 21) & BM_MMDC_MAPSR_DVFS)
#else
#define BF_MMDC_MAPSR_DVFS(v)   (((v) << 21) & BM_MMDC_MAPSR_DVFS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAPSR_DVFS(v)   BF_CS1(MMDC_MAPSR, DVFS, v)
#endif

/* --- Register HW_MMDC_MAPSR, field LPACK
 *
 * General low-power acknowledge. This read only bit indicates whether a
 * low-power acknowledge was asserted and that MMDC is in self-refresh
 * mode
 */

#define BP_MMDC_MAPSR_LPACK      24
#define BM_MMDC_MAPSR_LPACK      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAPSR_LPACK(v)   ((((reg32_t) v) << 24) & BM_MMDC_MAPSR_LPACK)
#else
#define BF_MMDC_MAPSR_LPACK(v)   (((v) << 24) & BM_MMDC_MAPSR_LPACK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAPSR_LPACK(v)   BF_CS1(MMDC_MAPSR, LPACK, v)
#endif

/* --- Register HW_MMDC_MAPSR, field DVACK
 *
 * General DVFS acknowledge. This read only bit indicates whether a dvfs
 * acknowledge was asserted and that MMDC is in self-refresh mode
 */

#define BP_MMDC_MAPSR_DVACK      25
#define BM_MMDC_MAPSR_DVACK      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAPSR_DVACK(v)   ((((reg32_t) v) << 25) & BM_MMDC_MAPSR_DVACK)
#else
#define BF_MMDC_MAPSR_DVACK(v)   (((v) << 25) & BM_MMDC_MAPSR_DVACK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAPSR_DVACK(v)   BF_CS1(MMDC_MAPSR, DVACK, v)
#endif

/*!
 * @brief HW_MMDC_MAEXIDR0 - MMDC Core Exclusive ID Monitor Register0
 *
 * This register defines the ID to be monitored for exclusive accesses of
 * monitor0 and monitor1. For further information see .  Supported Mode Of Operations:  For Channel
 * 0: All  For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EXC_ID_MONITOR0 : 16; //!< This feild defines ID for Exclusive monitor#0. Default value is 0x0000
        unsigned EXC_ID_MONITOR1 : 16; //!< This feild defines ID for Exclusive monitor#1. Default value is 0x0020
    } B;
} hw_mmdc_maexidr0_t;
#endif

/*
 * constants & macros for entire MMDC_MAEXIDR0 register
 */
#define HW_MMDC_MAEXIDR0_ADDR      (REGS_MMDC_BASE + 0x408)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MAEXIDR0           (*(volatile hw_mmdc_maexidr0_t *) HW_MMDC_MAEXIDR0_ADDR)
#define HW_MMDC_MAEXIDR0_RD()      (HW_MMDC_MAEXIDR0.U)
#define HW_MMDC_MAEXIDR0_WR(v)     (HW_MMDC_MAEXIDR0.U = (v))
#define HW_MMDC_MAEXIDR0_SET(v)    (HW_MMDC_MAEXIDR0_WR(HW_MMDC_MAEXIDR0_RD() |  (v)))
#define HW_MMDC_MAEXIDR0_CLR(v)    (HW_MMDC_MAEXIDR0_WR(HW_MMDC_MAEXIDR0_RD() & ~(v)))
#define HW_MMDC_MAEXIDR0_TOG(v)    (HW_MMDC_MAEXIDR0_WR(HW_MMDC_MAEXIDR0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MAEXIDR0 bitfields
 */

/* --- Register HW_MMDC_MAEXIDR0, field EXC_ID_MONITOR0
 *
 * This feild defines ID for Exclusive monitor#0. Default value is
 * 0x0000
 */

#define BP_MMDC_MAEXIDR0_EXC_ID_MONITOR0      0
#define BM_MMDC_MAEXIDR0_EXC_ID_MONITOR0      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAEXIDR0_EXC_ID_MONITOR0(v)   ((((reg32_t) v) << 0) & BM_MMDC_MAEXIDR0_EXC_ID_MONITOR0)
#else
#define BF_MMDC_MAEXIDR0_EXC_ID_MONITOR0(v)   (((v) << 0) & BM_MMDC_MAEXIDR0_EXC_ID_MONITOR0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAEXIDR0_EXC_ID_MONITOR0(v)   BF_CS1(MMDC_MAEXIDR0, EXC_ID_MONITOR0, v)
#endif

/* --- Register HW_MMDC_MAEXIDR0, field EXC_ID_MONITOR1
 *
 * This feild defines ID for Exclusive monitor#1. Default value is
 * 0x0020
 */

#define BP_MMDC_MAEXIDR0_EXC_ID_MONITOR1      16
#define BM_MMDC_MAEXIDR0_EXC_ID_MONITOR1      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAEXIDR0_EXC_ID_MONITOR1(v)   ((((reg32_t) v) << 16) & BM_MMDC_MAEXIDR0_EXC_ID_MONITOR1)
#else
#define BF_MMDC_MAEXIDR0_EXC_ID_MONITOR1(v)   (((v) << 16) & BM_MMDC_MAEXIDR0_EXC_ID_MONITOR1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAEXIDR0_EXC_ID_MONITOR1(v)   BF_CS1(MMDC_MAEXIDR0, EXC_ID_MONITOR1, v)
#endif

/*!
 * @brief HW_MMDC_MAEXIDR1 - MMDC Core Exclusive ID Monitor Register1
 *
 * This register defines the ID to be monitored for exclusive accesses of
 * monitor2 and monitor3. For further information see .  Supported Mode Of Operations:  For Channel
 * 0: All  For channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EXC_ID_MONITOR2 : 16; //!< This feild defines ID for Exclusive monitor#2. Default value is 0x0040
        unsigned EXC_ID_MONITOR3 : 16; //!< This feild defines ID for Exclusive monitor#3. Default value is 0x0060
    } B;
} hw_mmdc_maexidr1_t;
#endif

/*
 * constants & macros for entire MMDC_MAEXIDR1 register
 */
#define HW_MMDC_MAEXIDR1_ADDR      (REGS_MMDC_BASE + 0x40c)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MAEXIDR1           (*(volatile hw_mmdc_maexidr1_t *) HW_MMDC_MAEXIDR1_ADDR)
#define HW_MMDC_MAEXIDR1_RD()      (HW_MMDC_MAEXIDR1.U)
#define HW_MMDC_MAEXIDR1_WR(v)     (HW_MMDC_MAEXIDR1.U = (v))
#define HW_MMDC_MAEXIDR1_SET(v)    (HW_MMDC_MAEXIDR1_WR(HW_MMDC_MAEXIDR1_RD() |  (v)))
#define HW_MMDC_MAEXIDR1_CLR(v)    (HW_MMDC_MAEXIDR1_WR(HW_MMDC_MAEXIDR1_RD() & ~(v)))
#define HW_MMDC_MAEXIDR1_TOG(v)    (HW_MMDC_MAEXIDR1_WR(HW_MMDC_MAEXIDR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MAEXIDR1 bitfields
 */

/* --- Register HW_MMDC_MAEXIDR1, field EXC_ID_MONITOR2
 *
 * This feild defines ID for Exclusive monitor#2. Default value is
 * 0x0040
 */

#define BP_MMDC_MAEXIDR1_EXC_ID_MONITOR2      0
#define BM_MMDC_MAEXIDR1_EXC_ID_MONITOR2      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAEXIDR1_EXC_ID_MONITOR2(v)   ((((reg32_t) v) << 0) & BM_MMDC_MAEXIDR1_EXC_ID_MONITOR2)
#else
#define BF_MMDC_MAEXIDR1_EXC_ID_MONITOR2(v)   (((v) << 0) & BM_MMDC_MAEXIDR1_EXC_ID_MONITOR2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAEXIDR1_EXC_ID_MONITOR2(v)   BF_CS1(MMDC_MAEXIDR1, EXC_ID_MONITOR2, v)
#endif

/* --- Register HW_MMDC_MAEXIDR1, field EXC_ID_MONITOR3
 *
 * This feild defines ID for Exclusive monitor#3. Default value is
 * 0x0060
 */

#define BP_MMDC_MAEXIDR1_EXC_ID_MONITOR3      16
#define BM_MMDC_MAEXIDR1_EXC_ID_MONITOR3      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAEXIDR1_EXC_ID_MONITOR3(v)   ((((reg32_t) v) << 16) & BM_MMDC_MAEXIDR1_EXC_ID_MONITOR3)
#else
#define BF_MMDC_MAEXIDR1_EXC_ID_MONITOR3(v)   (((v) << 16) & BM_MMDC_MAEXIDR1_EXC_ID_MONITOR3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAEXIDR1_EXC_ID_MONITOR3(v)   BF_CS1(MMDC_MAEXIDR1, EXC_ID_MONITOR3, v)
#endif

/*!
 * @brief HW_MMDC_MADPCR0 - MMDC Core Debug and Profiling Control Register                        0
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DBG_EN : 1; //!< Debug and Profiling Enable. Enable debug and profiling mechanism. When this bit is asserted then the MMDC will perform a profiling based on the ID that is configured to MADPCR1. Upon assertion of PRF_FRZ the profiling will be freezed and the profiling results will be sampled to the status registers (MADPSR0-MADPSR5). For further information see .  default is "disable"
        unsigned DBG_RST : 1; //!< Debug and Profiling Reset. Reset all debug and profiling counters and components.
        unsigned PRF_FRZ : 1; //!< Profiling freeze. When this bit is assertted then the profilling mechanism will be freezed and the associated status registers ( MADPSR0-MADPSR5) will hold the the current profiling values.
        unsigned CYC_OVF : 1; //!< Total Profiling Cycles Count Overflow. When profiling mechanism is enabled (DBG_EN is set to "1") then this bit is asserted when overflow of CYC_COUNT occurred. Cleared by writing 1 to it.
        unsigned RESERVED0 : 4; //!< Reserved.
        unsigned SBS_EN : 1; //!< Step By Step debug Enable. Enable step by step mode. Every time this mechanism is enabled then setting SBS to "1" will dispatch one pending AXI access to the DDR and in parallel its attributes will be observed in the status registes (MASBS0 and MASBS1). For further information see .
        unsigned SBS : 1; //!< Step By Step trigger. If SBS_EN is set to "1" then dispatching AXI pending access toward the DDR will done only if this bit is set to "1", otherewise no access will be dispatched toward the DDR. This bit is cleared when the pending access has been issued toward the DDR device.
        unsigned RESERVED1 : 22; //!< Reserved.
    } B;
} hw_mmdc_madpcr0_t;
#endif

/*
 * constants & macros for entire MMDC_MADPCR0 register
 */
#define HW_MMDC_MADPCR0_ADDR      (REGS_MMDC_BASE + 0x410)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MADPCR0           (*(volatile hw_mmdc_madpcr0_t *) HW_MMDC_MADPCR0_ADDR)
#define HW_MMDC_MADPCR0_RD()      (HW_MMDC_MADPCR0.U)
#define HW_MMDC_MADPCR0_WR(v)     (HW_MMDC_MADPCR0.U = (v))
#define HW_MMDC_MADPCR0_SET(v)    (HW_MMDC_MADPCR0_WR(HW_MMDC_MADPCR0_RD() |  (v)))
#define HW_MMDC_MADPCR0_CLR(v)    (HW_MMDC_MADPCR0_WR(HW_MMDC_MADPCR0_RD() & ~(v)))
#define HW_MMDC_MADPCR0_TOG(v)    (HW_MMDC_MADPCR0_WR(HW_MMDC_MADPCR0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MADPCR0 bitfields
 */

/* --- Register HW_MMDC_MADPCR0, field DBG_EN
 *
 * Debug and Profiling Enable. Enable debug and profiling mechanism.
 * When this bit is asserted then the MMDC will perform a profiling
 * based on the ID that is configured to MADPCR1. Upon assertion of
 * PRF_FRZ the profiling will be freezed and the profiling results will
 * be sampled to the status registers (MADPSR0-MADPSR5). For further
 * information see .  default is "disable"
 */

#define BP_MMDC_MADPCR0_DBG_EN      0
#define BM_MMDC_MADPCR0_DBG_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MADPCR0_DBG_EN(v)   ((((reg32_t) v) << 0) & BM_MMDC_MADPCR0_DBG_EN)
#else
#define BF_MMDC_MADPCR0_DBG_EN(v)   (((v) << 0) & BM_MMDC_MADPCR0_DBG_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MADPCR0_DBG_EN(v)   BF_CS1(MMDC_MADPCR0, DBG_EN, v)
#endif

/* --- Register HW_MMDC_MADPCR0, field DBG_RST
 *
 * Debug and Profiling Reset. Reset all debug and profiling counters and
 * components.
 */

#define BP_MMDC_MADPCR0_DBG_RST      1
#define BM_MMDC_MADPCR0_DBG_RST      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MADPCR0_DBG_RST(v)   ((((reg32_t) v) << 1) & BM_MMDC_MADPCR0_DBG_RST)
#else
#define BF_MMDC_MADPCR0_DBG_RST(v)   (((v) << 1) & BM_MMDC_MADPCR0_DBG_RST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MADPCR0_DBG_RST(v)   BF_CS1(MMDC_MADPCR0, DBG_RST, v)
#endif

/* --- Register HW_MMDC_MADPCR0, field PRF_FRZ
 *
 * Profiling freeze. When this bit is assertted then the profilling
 * mechanism will be freezed and the associated status registers (
 * MADPSR0-MADPSR5) will hold the the current profiling values.
 */

#define BP_MMDC_MADPCR0_PRF_FRZ      2
#define BM_MMDC_MADPCR0_PRF_FRZ      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MADPCR0_PRF_FRZ(v)   ((((reg32_t) v) << 2) & BM_MMDC_MADPCR0_PRF_FRZ)
#else
#define BF_MMDC_MADPCR0_PRF_FRZ(v)   (((v) << 2) & BM_MMDC_MADPCR0_PRF_FRZ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MADPCR0_PRF_FRZ(v)   BF_CS1(MMDC_MADPCR0, PRF_FRZ, v)
#endif

/* --- Register HW_MMDC_MADPCR0, field CYC_OVF
 *
 * Total Profiling Cycles Count Overflow. When profiling mechanism is
 * enabled (DBG_EN is set to "1") then this bit is asserted when
 * overflow of CYC_COUNT occurred. Cleared by writing 1 to it.
 */

#define BP_MMDC_MADPCR0_CYC_OVF      3
#define BM_MMDC_MADPCR0_CYC_OVF      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MADPCR0_CYC_OVF(v)   ((((reg32_t) v) << 3) & BM_MMDC_MADPCR0_CYC_OVF)
#else
#define BF_MMDC_MADPCR0_CYC_OVF(v)   (((v) << 3) & BM_MMDC_MADPCR0_CYC_OVF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MADPCR0_CYC_OVF(v)   BF_CS1(MMDC_MADPCR0, CYC_OVF, v)
#endif

/* --- Register HW_MMDC_MADPCR0, field SBS_EN
 *
 * Step By Step debug Enable. Enable step by step mode. Every time this
 * mechanism is enabled then setting SBS to "1" will dispatch one
 * pending AXI access to the DDR and in parallel its attributes will be
 * observed in the status registes (MASBS0 and MASBS1). For further
 * information see .
 */

#define BP_MMDC_MADPCR0_SBS_EN      8
#define BM_MMDC_MADPCR0_SBS_EN      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MADPCR0_SBS_EN(v)   ((((reg32_t) v) << 8) & BM_MMDC_MADPCR0_SBS_EN)
#else
#define BF_MMDC_MADPCR0_SBS_EN(v)   (((v) << 8) & BM_MMDC_MADPCR0_SBS_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MADPCR0_SBS_EN(v)   BF_CS1(MMDC_MADPCR0, SBS_EN, v)
#endif

/* --- Register HW_MMDC_MADPCR0, field SBS
 *
 * Step By Step trigger. If SBS_EN is set to "1" then dispatching AXI
 * pending access toward the DDR will done only if this bit is set to
 * "1", otherewise no access will be dispatched toward the DDR. This
 * bit is cleared when the pending access has been issued toward the
 * DDR device.
 */

#define BP_MMDC_MADPCR0_SBS      9
#define BM_MMDC_MADPCR0_SBS      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MADPCR0_SBS(v)   ((((reg32_t) v) << 9) & BM_MMDC_MADPCR0_SBS)
#else
#define BF_MMDC_MADPCR0_SBS(v)   (((v) << 9) & BM_MMDC_MADPCR0_SBS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MADPCR0_SBS(v)   BF_CS1(MMDC_MADPCR0, SBS, v)
#endif

/*!
 * @brief HW_MMDC_MADPCR1 - MMDC Core Debug and Profiling Control Register                        1
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PRF_AXI_ID : 16; //!< Profiling AXI ID. AXI IDs that matches a bit-wise AND logic operation between PRF_AXI_ID and PRF_AXI_ID_MASK are chosen for profiling.  Default value is 0x0, to choose any ID-s for profiling
        unsigned PRF_AXI_ID_MASK : 16; //!< Profiling AXI ID Mask. AXI ID bits which masked by this value are chosen for profiling.
    } B;
} hw_mmdc_madpcr1_t;
#endif

/*
 * constants & macros for entire MMDC_MADPCR1 register
 */
#define HW_MMDC_MADPCR1_ADDR      (REGS_MMDC_BASE + 0x414)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MADPCR1           (*(volatile hw_mmdc_madpcr1_t *) HW_MMDC_MADPCR1_ADDR)
#define HW_MMDC_MADPCR1_RD()      (HW_MMDC_MADPCR1.U)
#define HW_MMDC_MADPCR1_WR(v)     (HW_MMDC_MADPCR1.U = (v))
#define HW_MMDC_MADPCR1_SET(v)    (HW_MMDC_MADPCR1_WR(HW_MMDC_MADPCR1_RD() |  (v)))
#define HW_MMDC_MADPCR1_CLR(v)    (HW_MMDC_MADPCR1_WR(HW_MMDC_MADPCR1_RD() & ~(v)))
#define HW_MMDC_MADPCR1_TOG(v)    (HW_MMDC_MADPCR1_WR(HW_MMDC_MADPCR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MADPCR1 bitfields
 */

/* --- Register HW_MMDC_MADPCR1, field PRF_AXI_ID
 *
 * Profiling AXI ID. AXI IDs that matches a bit-wise AND logic operation
 * between PRF_AXI_ID and PRF_AXI_ID_MASK are chosen for profiling.  Default value is 0x0, to choose
 * any ID-s for profiling
 */

#define BP_MMDC_MADPCR1_PRF_AXI_ID      0
#define BM_MMDC_MADPCR1_PRF_AXI_ID      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MADPCR1_PRF_AXI_ID(v)   ((((reg32_t) v) << 0) & BM_MMDC_MADPCR1_PRF_AXI_ID)
#else
#define BF_MMDC_MADPCR1_PRF_AXI_ID(v)   (((v) << 0) & BM_MMDC_MADPCR1_PRF_AXI_ID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MADPCR1_PRF_AXI_ID(v)   BF_CS1(MMDC_MADPCR1, PRF_AXI_ID, v)
#endif

/* --- Register HW_MMDC_MADPCR1, field PRF_AXI_ID_MASK
 *
 * Profiling AXI ID Mask. AXI ID bits which masked by this value are
 * chosen for profiling.
 */

#define BP_MMDC_MADPCR1_PRF_AXI_ID_MASK      16
#define BM_MMDC_MADPCR1_PRF_AXI_ID_MASK      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MADPCR1_PRF_AXI_ID_MASK(v)   ((((reg32_t) v) << 16) & BM_MMDC_MADPCR1_PRF_AXI_ID_MASK)
#else
#define BF_MMDC_MADPCR1_PRF_AXI_ID_MASK(v)   (((v) << 16) & BM_MMDC_MADPCR1_PRF_AXI_ID_MASK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MADPCR1_PRF_AXI_ID_MASK(v)   BF_CS1(MMDC_MADPCR1, PRF_AXI_ID_MASK, v)
#endif

/*!
 * @brief HW_MMDC_MADPSR0 - MMDC Core Debug and Profiling Status Register                        0
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CYC_COUNT : 32; //!< Total Profiling cycle Count. This field reflects the total cycle count in case the profiling mechanism is enabled from assertion of DBG_EN and until PRF_FRZ is asserted
    } B;
} hw_mmdc_madpsr0_t;
#endif

/*
 * constants & macros for entire MMDC_MADPSR0 register
 */
#define HW_MMDC_MADPSR0_ADDR      (REGS_MMDC_BASE + 0x418)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MADPSR0           (*(volatile hw_mmdc_madpsr0_t *) HW_MMDC_MADPSR0_ADDR)
#define HW_MMDC_MADPSR0_RD()      (HW_MMDC_MADPSR0.U)
#define HW_MMDC_MADPSR0_WR(v)     (HW_MMDC_MADPSR0.U = (v))
#define HW_MMDC_MADPSR0_SET(v)    (HW_MMDC_MADPSR0_WR(HW_MMDC_MADPSR0_RD() |  (v)))
#define HW_MMDC_MADPSR0_CLR(v)    (HW_MMDC_MADPSR0_WR(HW_MMDC_MADPSR0_RD() & ~(v)))
#define HW_MMDC_MADPSR0_TOG(v)    (HW_MMDC_MADPSR0_WR(HW_MMDC_MADPSR0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MADPSR0 bitfields
 */

/* --- Register HW_MMDC_MADPSR0, field CYC_COUNT
 *
 * Total Profiling cycle Count. This field reflects the total cycle
 * count in case the profiling mechanism is enabled from assertion of
 * DBG_EN and until PRF_FRZ is asserted
 */

#define BP_MMDC_MADPSR0_CYC_COUNT      0
#define BM_MMDC_MADPSR0_CYC_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MADPSR0_CYC_COUNT(v)   ((((reg32_t) v) << 0) & BM_MMDC_MADPSR0_CYC_COUNT)
#else
#define BF_MMDC_MADPSR0_CYC_COUNT(v)   (((v) << 0) & BM_MMDC_MADPSR0_CYC_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MADPSR0_CYC_COUNT(v)   BF_CS1(MMDC_MADPSR0, CYC_COUNT, v)
#endif

/*!
 * @brief HW_MMDC_MADPSR1 - MMDC Core Debug and Profiling Status Register                        1
 *
 * The register reflects the total cycles during which the MMDC state machines were
 * busy (both writes and reads). This information can be used for DDR
 * Utilization calculation.  Supported Mode Of Operations:  For Channel 0: All  For Channel 1:
 * LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned BUSY_COUNT : 32; //!< Profiling Busy Cycles Count. This field reflects the total number of cycles where the MMDC read and write state machines were busy during the profiling period. Can be used for DDR utilization calculations
    } B;
} hw_mmdc_madpsr1_t;
#endif

/*
 * constants & macros for entire MMDC_MADPSR1 register
 */
#define HW_MMDC_MADPSR1_ADDR      (REGS_MMDC_BASE + 0x41c)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MADPSR1           (*(volatile hw_mmdc_madpsr1_t *) HW_MMDC_MADPSR1_ADDR)
#define HW_MMDC_MADPSR1_RD()      (HW_MMDC_MADPSR1.U)
#define HW_MMDC_MADPSR1_WR(v)     (HW_MMDC_MADPSR1.U = (v))
#define HW_MMDC_MADPSR1_SET(v)    (HW_MMDC_MADPSR1_WR(HW_MMDC_MADPSR1_RD() |  (v)))
#define HW_MMDC_MADPSR1_CLR(v)    (HW_MMDC_MADPSR1_WR(HW_MMDC_MADPSR1_RD() & ~(v)))
#define HW_MMDC_MADPSR1_TOG(v)    (HW_MMDC_MADPSR1_WR(HW_MMDC_MADPSR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MADPSR1 bitfields
 */

/* --- Register HW_MMDC_MADPSR1, field BUSY_COUNT
 *
 * Profiling Busy Cycles Count. This field reflects the total number of
 * cycles where the MMDC read and write state machines were busy during
 * the profiling period. Can be used for DDR utilization
 * calculations
 */

#define BP_MMDC_MADPSR1_BUSY_COUNT      0
#define BM_MMDC_MADPSR1_BUSY_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MADPSR1_BUSY_COUNT(v)   ((((reg32_t) v) << 0) & BM_MMDC_MADPSR1_BUSY_COUNT)
#else
#define BF_MMDC_MADPSR1_BUSY_COUNT(v)   (((v) << 0) & BM_MMDC_MADPSR1_BUSY_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MADPSR1_BUSY_COUNT(v)   BF_CS1(MMDC_MADPSR1, BUSY_COUNT, v)
#endif

/*!
 * @brief HW_MMDC_MADPSR2 - MMDC Core Debug and Profiling Status Register                        2
 *
 * This register reflects the total number of read accesses (per AXI ID)
 * toward MMDC.  Supported Mode Of Operations:  For Channel 0: All  For Channel 1: LP2_2ch_x16,
 * LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RD_ACC_COUNT : 32; //!< Profiling Read Access Count. This register reflects the total number of read accesses (per AXI ID) toward MMDC.
    } B;
} hw_mmdc_madpsr2_t;
#endif

/*
 * constants & macros for entire MMDC_MADPSR2 register
 */
#define HW_MMDC_MADPSR2_ADDR      (REGS_MMDC_BASE + 0x420)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MADPSR2           (*(volatile hw_mmdc_madpsr2_t *) HW_MMDC_MADPSR2_ADDR)
#define HW_MMDC_MADPSR2_RD()      (HW_MMDC_MADPSR2.U)
#define HW_MMDC_MADPSR2_WR(v)     (HW_MMDC_MADPSR2.U = (v))
#define HW_MMDC_MADPSR2_SET(v)    (HW_MMDC_MADPSR2_WR(HW_MMDC_MADPSR2_RD() |  (v)))
#define HW_MMDC_MADPSR2_CLR(v)    (HW_MMDC_MADPSR2_WR(HW_MMDC_MADPSR2_RD() & ~(v)))
#define HW_MMDC_MADPSR2_TOG(v)    (HW_MMDC_MADPSR2_WR(HW_MMDC_MADPSR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MADPSR2 bitfields
 */

/* --- Register HW_MMDC_MADPSR2, field RD_ACC_COUNT
 *
 * Profiling Read Access Count. This register reflects the total number
 * of read accesses (per AXI ID) toward MMDC.
 */

#define BP_MMDC_MADPSR2_RD_ACC_COUNT      0
#define BM_MMDC_MADPSR2_RD_ACC_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MADPSR2_RD_ACC_COUNT(v)   ((((reg32_t) v) << 0) & BM_MMDC_MADPSR2_RD_ACC_COUNT)
#else
#define BF_MMDC_MADPSR2_RD_ACC_COUNT(v)   (((v) << 0) & BM_MMDC_MADPSR2_RD_ACC_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MADPSR2_RD_ACC_COUNT(v)   BF_CS1(MMDC_MADPSR2, RD_ACC_COUNT, v)
#endif

/*!
 * @brief HW_MMDC_MADPSR3 - MMDC Core Debug and Profiling Status Register                        3
 *
 * This register reflects the total number of write accesses (per AXI ID)
 * toward MMDC.  Supported Mode Of Operations:  For Channel 0: All  For Channel 1: LP2_2ch_x16,
 * LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WR_ACC_COUNT : 32; //!< Profiling Write Access Count. This register reflects the total number of write accesses (per AXI ID) toward MMDC.
    } B;
} hw_mmdc_madpsr3_t;
#endif

/*
 * constants & macros for entire MMDC_MADPSR3 register
 */
#define HW_MMDC_MADPSR3_ADDR      (REGS_MMDC_BASE + 0x424)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MADPSR3           (*(volatile hw_mmdc_madpsr3_t *) HW_MMDC_MADPSR3_ADDR)
#define HW_MMDC_MADPSR3_RD()      (HW_MMDC_MADPSR3.U)
#define HW_MMDC_MADPSR3_WR(v)     (HW_MMDC_MADPSR3.U = (v))
#define HW_MMDC_MADPSR3_SET(v)    (HW_MMDC_MADPSR3_WR(HW_MMDC_MADPSR3_RD() |  (v)))
#define HW_MMDC_MADPSR3_CLR(v)    (HW_MMDC_MADPSR3_WR(HW_MMDC_MADPSR3_RD() & ~(v)))
#define HW_MMDC_MADPSR3_TOG(v)    (HW_MMDC_MADPSR3_WR(HW_MMDC_MADPSR3_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MADPSR3 bitfields
 */

/* --- Register HW_MMDC_MADPSR3, field WR_ACC_COUNT
 *
 * Profiling Write Access Count. This register reflects the total number
 * of write accesses (per AXI ID) toward MMDC.
 */

#define BP_MMDC_MADPSR3_WR_ACC_COUNT      0
#define BM_MMDC_MADPSR3_WR_ACC_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MADPSR3_WR_ACC_COUNT(v)   ((((reg32_t) v) << 0) & BM_MMDC_MADPSR3_WR_ACC_COUNT)
#else
#define BF_MMDC_MADPSR3_WR_ACC_COUNT(v)   (((v) << 0) & BM_MMDC_MADPSR3_WR_ACC_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MADPSR3_WR_ACC_COUNT(v)   BF_CS1(MMDC_MADPSR3, WR_ACC_COUNT, v)
#endif

/*!
 * @brief HW_MMDC_MADPSR4 - MMDC Core Debug and Profiling Status Register                        4
 *
 * This register reflects the total number of bytes that were transferred
 * during read access (per AXI ID) toward MMDC.  Supported Mode Of Operations:  For Channel 0: All
 * For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RD_BYTES_COUNT : 32; //!< Profiling Read Bytes Count. This register reflects the total number of bytes that were transferred during read access (per AXI ID) toward MMDC.
    } B;
} hw_mmdc_madpsr4_t;
#endif

/*
 * constants & macros for entire MMDC_MADPSR4 register
 */
#define HW_MMDC_MADPSR4_ADDR      (REGS_MMDC_BASE + 0x428)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MADPSR4           (*(volatile hw_mmdc_madpsr4_t *) HW_MMDC_MADPSR4_ADDR)
#define HW_MMDC_MADPSR4_RD()      (HW_MMDC_MADPSR4.U)
#define HW_MMDC_MADPSR4_WR(v)     (HW_MMDC_MADPSR4.U = (v))
#define HW_MMDC_MADPSR4_SET(v)    (HW_MMDC_MADPSR4_WR(HW_MMDC_MADPSR4_RD() |  (v)))
#define HW_MMDC_MADPSR4_CLR(v)    (HW_MMDC_MADPSR4_WR(HW_MMDC_MADPSR4_RD() & ~(v)))
#define HW_MMDC_MADPSR4_TOG(v)    (HW_MMDC_MADPSR4_WR(HW_MMDC_MADPSR4_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MADPSR4 bitfields
 */

/* --- Register HW_MMDC_MADPSR4, field RD_BYTES_COUNT
 *
 * Profiling Read Bytes Count. This register reflects the total number
 * of bytes that were transferred during read access (per AXI ID)
 * toward MMDC.
 */

#define BP_MMDC_MADPSR4_RD_BYTES_COUNT      0
#define BM_MMDC_MADPSR4_RD_BYTES_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MADPSR4_RD_BYTES_COUNT(v)   ((((reg32_t) v) << 0) & BM_MMDC_MADPSR4_RD_BYTES_COUNT)
#else
#define BF_MMDC_MADPSR4_RD_BYTES_COUNT(v)   (((v) << 0) & BM_MMDC_MADPSR4_RD_BYTES_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MADPSR4_RD_BYTES_COUNT(v)   BF_CS1(MMDC_MADPSR4, RD_BYTES_COUNT, v)
#endif

/*!
 * @brief HW_MMDC_MADPSR5 - MMDC Core Debug and Profiling Status Register                        5
 *
 * This register reflects the total number of bytes that were transferred
 * during write access (per AXI ID) toward MMDC.  Supported Mode Of Operations:  For Channel 0: All
 * For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WR_BYTES_COUNT : 32; //!< Profiling Write Bytes Count. This register reflects the total number of bytes that were transferred during write access (per AXI ID) toward MMDC.
    } B;
} hw_mmdc_madpsr5_t;
#endif

/*
 * constants & macros for entire MMDC_MADPSR5 register
 */
#define HW_MMDC_MADPSR5_ADDR      (REGS_MMDC_BASE + 0x42c)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MADPSR5           (*(volatile hw_mmdc_madpsr5_t *) HW_MMDC_MADPSR5_ADDR)
#define HW_MMDC_MADPSR5_RD()      (HW_MMDC_MADPSR5.U)
#define HW_MMDC_MADPSR5_WR(v)     (HW_MMDC_MADPSR5.U = (v))
#define HW_MMDC_MADPSR5_SET(v)    (HW_MMDC_MADPSR5_WR(HW_MMDC_MADPSR5_RD() |  (v)))
#define HW_MMDC_MADPSR5_CLR(v)    (HW_MMDC_MADPSR5_WR(HW_MMDC_MADPSR5_RD() & ~(v)))
#define HW_MMDC_MADPSR5_TOG(v)    (HW_MMDC_MADPSR5_WR(HW_MMDC_MADPSR5_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MADPSR5 bitfields
 */

/* --- Register HW_MMDC_MADPSR5, field WR_BYTES_COUNT
 *
 * Profiling Write Bytes Count. This register reflects the total number
 * of bytes that were transferred during write access (per AXI ID)
 * toward MMDC.
 */

#define BP_MMDC_MADPSR5_WR_BYTES_COUNT      0
#define BM_MMDC_MADPSR5_WR_BYTES_COUNT      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MADPSR5_WR_BYTES_COUNT(v)   ((((reg32_t) v) << 0) & BM_MMDC_MADPSR5_WR_BYTES_COUNT)
#else
#define BF_MMDC_MADPSR5_WR_BYTES_COUNT(v)   (((v) << 0) & BM_MMDC_MADPSR5_WR_BYTES_COUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MADPSR5_WR_BYTES_COUNT(v)   BF_CS1(MMDC_MADPSR5, WR_BYTES_COUNT, v)
#endif

/*!
 * @brief HW_MMDC_MASBS0 - MMDC Core Step By Step Address Register
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SBS_ADDR : 32; //!< Step By Step Address. These bits reflect the address of the pending request in case of step by step mode.
    } B;
} hw_mmdc_masbs0_t;
#endif

/*
 * constants & macros for entire MMDC_MASBS0 register
 */
#define HW_MMDC_MASBS0_ADDR      (REGS_MMDC_BASE + 0x430)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MASBS0           (*(volatile hw_mmdc_masbs0_t *) HW_MMDC_MASBS0_ADDR)
#define HW_MMDC_MASBS0_RD()      (HW_MMDC_MASBS0.U)
#define HW_MMDC_MASBS0_WR(v)     (HW_MMDC_MASBS0.U = (v))
#define HW_MMDC_MASBS0_SET(v)    (HW_MMDC_MASBS0_WR(HW_MMDC_MASBS0_RD() |  (v)))
#define HW_MMDC_MASBS0_CLR(v)    (HW_MMDC_MASBS0_WR(HW_MMDC_MASBS0_RD() & ~(v)))
#define HW_MMDC_MASBS0_TOG(v)    (HW_MMDC_MASBS0_WR(HW_MMDC_MASBS0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MASBS0 bitfields
 */

/* --- Register HW_MMDC_MASBS0, field SBS_ADDR
 *
 * Step By Step Address. These bits reflect the address of the pending
 * request in case of step by step mode.
 */

#define BP_MMDC_MASBS0_SBS_ADDR      0
#define BM_MMDC_MASBS0_SBS_ADDR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MASBS0_SBS_ADDR(v)   ((((reg32_t) v) << 0) & BM_MMDC_MASBS0_SBS_ADDR)
#else
#define BF_MMDC_MASBS0_SBS_ADDR(v)   (((v) << 0) & BM_MMDC_MASBS0_SBS_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MASBS0_SBS_ADDR(v)   BF_CS1(MMDC_MASBS0, SBS_ADDR, v)
#endif

/*!
 * @brief HW_MMDC_MASBS1 - MMDC Core Step By Step Address Attributes                        Register
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SBS_VLD : 1; //!< Step By Step Valid. This bit reflects whether there is a pending request in case of step by step mode.
        unsigned SBS_TYPE : 1; //!< Step By Step Request Type. These bits reflect the type (read/write) of the pending request in case of step by step mode.
        unsigned SBS_LOCK : 2; //!< Step By Step Lock. These bits reflect the AXI LOCK of the pending request in case of step by step mode.
        unsigned SBS_PROT : 3; //!< Step By Step Protection. These bits reflect the AXI PROT of the pending request in case of step by step mode.
        unsigned SBS_BURST : 2; //!< Step By Step Burst. These bits reflect the AXI BURST of the pending request in case of step by step mode.
        unsigned SBS_SIZE : 3; //!< Step By Step Size. These bits reflect the AXI SIZE of the pending request in case of step by step mode.
        unsigned SBS_BUFF : 1; //!< Step By Step Buffered. This bit reflect the AXI CACHE[0] of the pending request in case of step by step mode. Relevant only for write requests
        unsigned SBS_LEN : 3; //!< Step By Step Length. These bits reflect the AXI LENGTH of the pending request in case of step by step mode.
        unsigned SBS_AXI_ID : 16; //!< Step By Step AXI ID. These bits reflect the AXI ID of the pending request in case of step by step mode.
    } B;
} hw_mmdc_masbs1_t;
#endif

/*
 * constants & macros for entire MMDC_MASBS1 register
 */
#define HW_MMDC_MASBS1_ADDR      (REGS_MMDC_BASE + 0x434)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MASBS1           (*(volatile hw_mmdc_masbs1_t *) HW_MMDC_MASBS1_ADDR)
#define HW_MMDC_MASBS1_RD()      (HW_MMDC_MASBS1.U)
#define HW_MMDC_MASBS1_WR(v)     (HW_MMDC_MASBS1.U = (v))
#define HW_MMDC_MASBS1_SET(v)    (HW_MMDC_MASBS1_WR(HW_MMDC_MASBS1_RD() |  (v)))
#define HW_MMDC_MASBS1_CLR(v)    (HW_MMDC_MASBS1_WR(HW_MMDC_MASBS1_RD() & ~(v)))
#define HW_MMDC_MASBS1_TOG(v)    (HW_MMDC_MASBS1_WR(HW_MMDC_MASBS1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MASBS1 bitfields
 */

/* --- Register HW_MMDC_MASBS1, field SBS_VLD
 *
 * Step By Step Valid. This bit reflects whether there is a pending
 * request in case of step by step mode.
 */

#define BP_MMDC_MASBS1_SBS_VLD      0
#define BM_MMDC_MASBS1_SBS_VLD      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MASBS1_SBS_VLD(v)   ((((reg32_t) v) << 0) & BM_MMDC_MASBS1_SBS_VLD)
#else
#define BF_MMDC_MASBS1_SBS_VLD(v)   (((v) << 0) & BM_MMDC_MASBS1_SBS_VLD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MASBS1_SBS_VLD(v)   BF_CS1(MMDC_MASBS1, SBS_VLD, v)
#endif

/* --- Register HW_MMDC_MASBS1, field SBS_TYPE
 *
 * Step By Step Request Type. These bits reflect the type (read/write)
 * of the pending request in case of step by step mode.
 */

#define BP_MMDC_MASBS1_SBS_TYPE      1
#define BM_MMDC_MASBS1_SBS_TYPE      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MASBS1_SBS_TYPE(v)   ((((reg32_t) v) << 1) & BM_MMDC_MASBS1_SBS_TYPE)
#else
#define BF_MMDC_MASBS1_SBS_TYPE(v)   (((v) << 1) & BM_MMDC_MASBS1_SBS_TYPE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MASBS1_SBS_TYPE(v)   BF_CS1(MMDC_MASBS1, SBS_TYPE, v)
#endif

/* --- Register HW_MMDC_MASBS1, field SBS_LOCK
 *
 * Step By Step Lock. These bits reflect the AXI LOCK of the pending
 * request in case of step by step mode.
 */

#define BP_MMDC_MASBS1_SBS_LOCK      2
#define BM_MMDC_MASBS1_SBS_LOCK      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MASBS1_SBS_LOCK(v)   ((((reg32_t) v) << 2) & BM_MMDC_MASBS1_SBS_LOCK)
#else
#define BF_MMDC_MASBS1_SBS_LOCK(v)   (((v) << 2) & BM_MMDC_MASBS1_SBS_LOCK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MASBS1_SBS_LOCK(v)   BF_CS1(MMDC_MASBS1, SBS_LOCK, v)
#endif

/* --- Register HW_MMDC_MASBS1, field SBS_PROT
 *
 * Step By Step Protection. These bits reflect the AXI PROT of the
 * pending request in case of step by step mode.
 */

#define BP_MMDC_MASBS1_SBS_PROT      4
#define BM_MMDC_MASBS1_SBS_PROT      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MASBS1_SBS_PROT(v)   ((((reg32_t) v) << 4) & BM_MMDC_MASBS1_SBS_PROT)
#else
#define BF_MMDC_MASBS1_SBS_PROT(v)   (((v) << 4) & BM_MMDC_MASBS1_SBS_PROT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MASBS1_SBS_PROT(v)   BF_CS1(MMDC_MASBS1, SBS_PROT, v)
#endif

/* --- Register HW_MMDC_MASBS1, field SBS_BURST
 *
 * Step By Step Burst. These bits reflect the AXI BURST of the pending
 * request in case of step by step mode.
 */

#define BP_MMDC_MASBS1_SBS_BURST      7
#define BM_MMDC_MASBS1_SBS_BURST      0x00000180

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MASBS1_SBS_BURST(v)   ((((reg32_t) v) << 7) & BM_MMDC_MASBS1_SBS_BURST)
#else
#define BF_MMDC_MASBS1_SBS_BURST(v)   (((v) << 7) & BM_MMDC_MASBS1_SBS_BURST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MASBS1_SBS_BURST(v)   BF_CS1(MMDC_MASBS1, SBS_BURST, v)
#endif

/* --- Register HW_MMDC_MASBS1, field SBS_SIZE
 *
 * Step By Step Size. These bits reflect the AXI SIZE of the pending
 * request in case of step by step mode.
 */

#define BP_MMDC_MASBS1_SBS_SIZE      9
#define BM_MMDC_MASBS1_SBS_SIZE      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MASBS1_SBS_SIZE(v)   ((((reg32_t) v) << 9) & BM_MMDC_MASBS1_SBS_SIZE)
#else
#define BF_MMDC_MASBS1_SBS_SIZE(v)   (((v) << 9) & BM_MMDC_MASBS1_SBS_SIZE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MASBS1_SBS_SIZE(v)   BF_CS1(MMDC_MASBS1, SBS_SIZE, v)
#endif

/* --- Register HW_MMDC_MASBS1, field SBS_BUFF
 *
 * Step By Step Buffered. This bit reflect the AXI CACHE[0] of the
 * pending request in case of step by step mode. Relevant only for
 * write requests
 */

#define BP_MMDC_MASBS1_SBS_BUFF      12
#define BM_MMDC_MASBS1_SBS_BUFF      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MASBS1_SBS_BUFF(v)   ((((reg32_t) v) << 12) & BM_MMDC_MASBS1_SBS_BUFF)
#else
#define BF_MMDC_MASBS1_SBS_BUFF(v)   (((v) << 12) & BM_MMDC_MASBS1_SBS_BUFF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MASBS1_SBS_BUFF(v)   BF_CS1(MMDC_MASBS1, SBS_BUFF, v)
#endif

/* --- Register HW_MMDC_MASBS1, field SBS_LEN
 *
 * Step By Step Length. These bits reflect the AXI LENGTH of the pending
 * request in case of step by step mode.
 */

#define BP_MMDC_MASBS1_SBS_LEN      13
#define BM_MMDC_MASBS1_SBS_LEN      0x0000e000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MASBS1_SBS_LEN(v)   ((((reg32_t) v) << 13) & BM_MMDC_MASBS1_SBS_LEN)
#else
#define BF_MMDC_MASBS1_SBS_LEN(v)   (((v) << 13) & BM_MMDC_MASBS1_SBS_LEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MASBS1_SBS_LEN(v)   BF_CS1(MMDC_MASBS1, SBS_LEN, v)
#endif

/* --- Register HW_MMDC_MASBS1, field SBS_AXI_ID
 *
 * Step By Step AXI ID. These bits reflect the AXI ID of the pending
 * request in case of step by step mode.
 */

#define BP_MMDC_MASBS1_SBS_AXI_ID      16
#define BM_MMDC_MASBS1_SBS_AXI_ID      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MASBS1_SBS_AXI_ID(v)   ((((reg32_t) v) << 16) & BM_MMDC_MASBS1_SBS_AXI_ID)
#else
#define BF_MMDC_MASBS1_SBS_AXI_ID(v)   (((v) << 16) & BM_MMDC_MASBS1_SBS_AXI_ID)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MASBS1_SBS_AXI_ID(v)   BF_CS1(MMDC_MASBS1, SBS_AXI_ID, v)
#endif

/*!
 * @brief HW_MMDC_MAGENP - MMDC Core General Purpose Register
 *
 * This register is a general 32 bit read/write register.  Supported Mode Of Operations:  For
 * Channel 0: All  For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned GP31 : 32; //!< General purpose read/write bits.
    } B;
} hw_mmdc_magenp_t;
#endif

/*
 * constants & macros for entire MMDC_MAGENP register
 */
#define HW_MMDC_MAGENP_ADDR      (REGS_MMDC_BASE + 0x440)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MAGENP           (*(volatile hw_mmdc_magenp_t *) HW_MMDC_MAGENP_ADDR)
#define HW_MMDC_MAGENP_RD()      (HW_MMDC_MAGENP.U)
#define HW_MMDC_MAGENP_WR(v)     (HW_MMDC_MAGENP.U = (v))
#define HW_MMDC_MAGENP_SET(v)    (HW_MMDC_MAGENP_WR(HW_MMDC_MAGENP_RD() |  (v)))
#define HW_MMDC_MAGENP_CLR(v)    (HW_MMDC_MAGENP_WR(HW_MMDC_MAGENP_RD() & ~(v)))
#define HW_MMDC_MAGENP_TOG(v)    (HW_MMDC_MAGENP_WR(HW_MMDC_MAGENP_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MAGENP bitfields
 */

/* --- Register HW_MMDC_MAGENP, field GP31
 *
 * General purpose read/write bits.
 */

#define BP_MMDC_MAGENP_GP31      0
#define BM_MMDC_MAGENP_GP31      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MAGENP_GP31(v)   ((((reg32_t) v) << 0) & BM_MMDC_MAGENP_GP31)
#else
#define BF_MMDC_MAGENP_GP31(v)   (((v) << 0) & BM_MMDC_MAGENP_GP31)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MAGENP_GP31(v)   BF_CS1(MMDC_MAGENP, GP31, v)
#endif

/*!
 * @brief HW_MMDC_MPZQHWCTRL - MMDC PHY ZQ HW control register
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: This register is reserved for
 * channel 1.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ZQ_MODE : 2; //!< ZQ calibration mode:
        unsigned ZQ_HW_PER : 4; //!< ZQ periodic calibration time. This field determines how often the periodic ZQ calibration is performed.  This field is applied for both ZQ short calibration and ZQ automatic calibration process with i.MX ZQ calibration pad. Whenever this timer is expired then according to ZQ_MODE the ZQ automatic calibration process with the i.MX ZQ calibration pad will be issued and/or short/long command will be issued to the external DDR device.  This field is ignored if ZQ_MODE equals "00"
        unsigned ZQ_HW_PU_RES : 5; //!< ZQ automatic calibration pull-up result. This field holds the pull-up resistor value calculated at the end of the ZQ automatic calibration process with the i.MX ZQ calibration pad.
        unsigned ZQ_HW_PD_RES : 5; //!< ZQ HW calibration pull-down result. This field holds the pull-down resistor value calculated at the end of the ZQ automatic calibration process with the i.MX ZQ calibration pad.
        unsigned ZQ_HW_FOR : 1; //!< Force ZQ automatic calibration process with the i.MX ZQ calibration pad. When this bit is asserted then the MMDC will issue one ZQ automatic calibration process with the i.MX ZQ calibration pad. It is the user responsibility to make sure that all the accesses to DDR will be finished before asserting this bit using CON_REQ/CON_ACK mechanism. HW will negate this bit upon completion of the ZQ calibration process. Upon negation of this bit the ZQ HW calibration pull-up and pull-down results (ZQ_HW_PU_RES and ZQ_HW_PD_RES respectively) are valid  In order to enable this bit ZQ_MODE must be set to either "1" or "3"
        unsigned TZQ_INIT : 3; //!< Device ZQ long/init time. This field holds the number of cycles that are required by the external DDR device to perform ZQ long calibration right after reset. Upon driving the command to the DDR device then no further accesses will be issued to the DDR device till satisfying that time.  In LPDDR2 the ZQ init time is taken from MPZQLP2CTL[ZQ_LP2_HW_ZQINIT]  This field should not be update during ZQ calibration.
        unsigned TZQ_OPER : 3; //!< Device ZQ long/oper time. This field holds the number of cycles that are required by the external DDR device to perform ZQ long calibration except the first ZQ long command that is isued after reset. Upon driving the command to the DDR device then no further accesses will be issued to the DDR device till satisfying that time.  In LPDDR2 the ZQ oper time is taken from MPZQLP2CTL[ZQ_LP2_HW_ZQCL]  This field should not be update during ZQ calibration.
        unsigned TZQ_CS : 3; //!< Device ZQ short time. This field holds the number of cycles that are required by the external DDR device to perform ZQ short calibration. Upon driving the command to the DDR device then no further accesses will be issued to the DDR device till satisfying that time.  In LPDDR2 the ZQ short time is taken from MPZQLP2CTL[ZQ_LP2_HW_ZQCS]  This field should not be update during ZQ calibration.
        unsigned RESERVED0 : 1; //!< Reserved.
        unsigned ZQ_EARLY_COMPARATOR_EN_TIMER : 5; //!< ZQ early comparator enable timer. This timer defines the interval between the warming up of the comparator of the i.MX ZQ calibration pad and the begining of the ZQ calibration process with the pad
    } B;
} hw_mmdc_mpzqhwctrl_t;
#endif

/*
 * constants & macros for entire MMDC_MPZQHWCTRL register
 */
#define HW_MMDC_MPZQHWCTRL_ADDR      (REGS_MMDC_BASE + 0x800)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPZQHWCTRL           (*(volatile hw_mmdc_mpzqhwctrl_t *) HW_MMDC_MPZQHWCTRL_ADDR)
#define HW_MMDC_MPZQHWCTRL_RD()      (HW_MMDC_MPZQHWCTRL.U)
#define HW_MMDC_MPZQHWCTRL_WR(v)     (HW_MMDC_MPZQHWCTRL.U = (v))
#define HW_MMDC_MPZQHWCTRL_SET(v)    (HW_MMDC_MPZQHWCTRL_WR(HW_MMDC_MPZQHWCTRL_RD() |  (v)))
#define HW_MMDC_MPZQHWCTRL_CLR(v)    (HW_MMDC_MPZQHWCTRL_WR(HW_MMDC_MPZQHWCTRL_RD() & ~(v)))
#define HW_MMDC_MPZQHWCTRL_TOG(v)    (HW_MMDC_MPZQHWCTRL_WR(HW_MMDC_MPZQHWCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPZQHWCTRL bitfields
 */

/* --- Register HW_MMDC_MPZQHWCTRL, field ZQ_MODE
 *
 * ZQ calibration mode:
 */

#define BP_MMDC_MPZQHWCTRL_ZQ_MODE      0
#define BM_MMDC_MPZQHWCTRL_ZQ_MODE      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPZQHWCTRL_ZQ_MODE(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPZQHWCTRL_ZQ_MODE)
#else
#define BF_MMDC_MPZQHWCTRL_ZQ_MODE(v)   (((v) << 0) & BM_MMDC_MPZQHWCTRL_ZQ_MODE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPZQHWCTRL_ZQ_MODE(v)   BF_CS1(MMDC_MPZQHWCTRL, ZQ_MODE, v)
#endif

/* --- Register HW_MMDC_MPZQHWCTRL, field ZQ_HW_PER
 *
 * ZQ periodic calibration time. This field determines how often the
 * periodic ZQ calibration is performed.  This field is applied for both ZQ short calibration and ZQ
 * automatic                                 calibration process with i.MX ZQ calibration pad.
 * Whenever this                                 timer is expired then according to ZQ_MODE the ZQ
 * automatic                                 calibration process with the i.MX ZQ calibration pad
 * will be issued                                 and/or short/long command will be issued to the
 * external DDR                                 device.  This field is ignored if ZQ_MODE equals
 * "00"
 */

#define BP_MMDC_MPZQHWCTRL_ZQ_HW_PER      2
#define BM_MMDC_MPZQHWCTRL_ZQ_HW_PER      0x0000003c

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPZQHWCTRL_ZQ_HW_PER(v)   ((((reg32_t) v) << 2) & BM_MMDC_MPZQHWCTRL_ZQ_HW_PER)
#else
#define BF_MMDC_MPZQHWCTRL_ZQ_HW_PER(v)   (((v) << 2) & BM_MMDC_MPZQHWCTRL_ZQ_HW_PER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPZQHWCTRL_ZQ_HW_PER(v)   BF_CS1(MMDC_MPZQHWCTRL, ZQ_HW_PER, v)
#endif

/* --- Register HW_MMDC_MPZQHWCTRL, field ZQ_HW_PU_RES
 *
 * ZQ automatic calibration pull-up result. This field holds the pull-up
 * resistor value calculated at the end of the ZQ automatic calibration
 * process with the i.MX ZQ calibration pad.
 */

#define BP_MMDC_MPZQHWCTRL_ZQ_HW_PU_RES      6
#define BM_MMDC_MPZQHWCTRL_ZQ_HW_PU_RES      0x000007c0

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPZQHWCTRL_ZQ_HW_PU_RES(v)   ((((reg32_t) v) << 6) & BM_MMDC_MPZQHWCTRL_ZQ_HW_PU_RES)
#else
#define BF_MMDC_MPZQHWCTRL_ZQ_HW_PU_RES(v)   (((v) << 6) & BM_MMDC_MPZQHWCTRL_ZQ_HW_PU_RES)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPZQHWCTRL_ZQ_HW_PU_RES(v)   BF_CS1(MMDC_MPZQHWCTRL, ZQ_HW_PU_RES, v)
#endif

/* --- Register HW_MMDC_MPZQHWCTRL, field ZQ_HW_PD_RES
 *
 * ZQ HW calibration pull-down result. This field holds the pull-down
 * resistor value calculated at the end of the ZQ automatic calibration
 * process with the i.MX ZQ calibration pad.
 */

#define BP_MMDC_MPZQHWCTRL_ZQ_HW_PD_RES      11
#define BM_MMDC_MPZQHWCTRL_ZQ_HW_PD_RES      0x0000f800

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPZQHWCTRL_ZQ_HW_PD_RES(v)   ((((reg32_t) v) << 11) & BM_MMDC_MPZQHWCTRL_ZQ_HW_PD_RES)
#else
#define BF_MMDC_MPZQHWCTRL_ZQ_HW_PD_RES(v)   (((v) << 11) & BM_MMDC_MPZQHWCTRL_ZQ_HW_PD_RES)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPZQHWCTRL_ZQ_HW_PD_RES(v)   BF_CS1(MMDC_MPZQHWCTRL, ZQ_HW_PD_RES, v)
#endif

/* --- Register HW_MMDC_MPZQHWCTRL, field ZQ_HW_FOR
 *
 * Force ZQ automatic calibration process with the i.MX ZQ calibration
 * pad. When this bit is asserted then the MMDC will issue one ZQ
 * automatic calibration process with the i.MX ZQ calibration pad. It
 * is the user responsibility to make sure that all the accesses to DDR
 * will be finished before asserting this bit using CON_REQ/CON_ACK
 * mechanism. HW will negate this bit upon completion of the ZQ
 * calibration process. Upon negation of this bit the ZQ HW calibration
 * pull-up and pull-down results (ZQ_HW_PU_RES and ZQ_HW_PD_RES
 * respectively) are valid  In order to enable this bit ZQ_MODE must be set to either "1" or
 * "3"
 */

#define BP_MMDC_MPZQHWCTRL_ZQ_HW_FOR      16
#define BM_MMDC_MPZQHWCTRL_ZQ_HW_FOR      0x00010000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPZQHWCTRL_ZQ_HW_FOR(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPZQHWCTRL_ZQ_HW_FOR)
#else
#define BF_MMDC_MPZQHWCTRL_ZQ_HW_FOR(v)   (((v) << 16) & BM_MMDC_MPZQHWCTRL_ZQ_HW_FOR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPZQHWCTRL_ZQ_HW_FOR(v)   BF_CS1(MMDC_MPZQHWCTRL, ZQ_HW_FOR, v)
#endif

/* --- Register HW_MMDC_MPZQHWCTRL, field TZQ_INIT
 *
 * Device ZQ long/init time. This field holds the number of cycles that
 * are required by the external DDR device to perform ZQ long
 * calibration right after reset. Upon driving the command to the DDR
 * device then no further accesses will be issued to the DDR device
 * till satisfying that time.  In LPDDR2 the ZQ init time is taken from
 * MPZQLP2CTL[ZQ_LP2_HW_ZQINIT]  This field should not be update during ZQ calibration.
 */

#define BP_MMDC_MPZQHWCTRL_TZQ_INIT      17
#define BM_MMDC_MPZQHWCTRL_TZQ_INIT      0x000e0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPZQHWCTRL_TZQ_INIT(v)   ((((reg32_t) v) << 17) & BM_MMDC_MPZQHWCTRL_TZQ_INIT)
#else
#define BF_MMDC_MPZQHWCTRL_TZQ_INIT(v)   (((v) << 17) & BM_MMDC_MPZQHWCTRL_TZQ_INIT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPZQHWCTRL_TZQ_INIT(v)   BF_CS1(MMDC_MPZQHWCTRL, TZQ_INIT, v)
#endif

/* --- Register HW_MMDC_MPZQHWCTRL, field TZQ_OPER
 *
 * Device ZQ long/oper time. This field holds the number of cycles that
 * are required by the external DDR device to perform ZQ long
 * calibration except the first ZQ long command that is isued after
 * reset. Upon driving the command to the DDR device then no further
 * accesses will be issued to the DDR device till satisfying that
 * time.  In LPDDR2 the ZQ oper time is taken from
 * MPZQLP2CTL[ZQ_LP2_HW_ZQCL]  This field should not be update during ZQ calibration.
 */

#define BP_MMDC_MPZQHWCTRL_TZQ_OPER      20
#define BM_MMDC_MPZQHWCTRL_TZQ_OPER      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPZQHWCTRL_TZQ_OPER(v)   ((((reg32_t) v) << 20) & BM_MMDC_MPZQHWCTRL_TZQ_OPER)
#else
#define BF_MMDC_MPZQHWCTRL_TZQ_OPER(v)   (((v) << 20) & BM_MMDC_MPZQHWCTRL_TZQ_OPER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPZQHWCTRL_TZQ_OPER(v)   BF_CS1(MMDC_MPZQHWCTRL, TZQ_OPER, v)
#endif

/* --- Register HW_MMDC_MPZQHWCTRL, field TZQ_CS
 *
 * Device ZQ short time. This field holds the number of cycles that are
 * required by the external DDR device to perform ZQ short calibration.
 * Upon driving the command to the DDR device then no further accesses
 * will be issued to the DDR device till satisfying that time.  In LPDDR2 the ZQ short time is taken
 * from                                 MPZQLP2CTL[ZQ_LP2_HW_ZQCS]  This field should not be update
 * during ZQ calibration.
 */

#define BP_MMDC_MPZQHWCTRL_TZQ_CS      23
#define BM_MMDC_MPZQHWCTRL_TZQ_CS      0x03800000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPZQHWCTRL_TZQ_CS(v)   ((((reg32_t) v) << 23) & BM_MMDC_MPZQHWCTRL_TZQ_CS)
#else
#define BF_MMDC_MPZQHWCTRL_TZQ_CS(v)   (((v) << 23) & BM_MMDC_MPZQHWCTRL_TZQ_CS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPZQHWCTRL_TZQ_CS(v)   BF_CS1(MMDC_MPZQHWCTRL, TZQ_CS, v)
#endif

/* --- Register HW_MMDC_MPZQHWCTRL, field ZQ_EARLY_COMPARATOR_EN_TIMER
 *
 * ZQ early comparator enable timer. This timer defines the interval
 * between the warming up of the comparator of the i.MX ZQ calibration
 * pad and the begining of the ZQ calibration process with the pad
 */

#define BP_MMDC_MPZQHWCTRL_ZQ_EARLY_COMPARATOR_EN_TIMER      27
#define BM_MMDC_MPZQHWCTRL_ZQ_EARLY_COMPARATOR_EN_TIMER      0xf8000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPZQHWCTRL_ZQ_EARLY_COMPARATOR_EN_TIMER(v)   ((((reg32_t) v) << 27) & BM_MMDC_MPZQHWCTRL_ZQ_EARLY_COMPARATOR_EN_TIMER)
#else
#define BF_MMDC_MPZQHWCTRL_ZQ_EARLY_COMPARATOR_EN_TIMER(v)   (((v) << 27) & BM_MMDC_MPZQHWCTRL_ZQ_EARLY_COMPARATOR_EN_TIMER)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPZQHWCTRL_ZQ_EARLY_COMPARATOR_EN_TIMER(v)   BF_CS1(MMDC_MPZQHWCTRL, ZQ_EARLY_COMPARATOR_EN_TIMER, v)
#endif

/*!
 * @brief HW_MMDC_MPZQSWCTRL - MMDC PHY ZQ SW control register
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: This register is reserved.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ZQ_SW_FOR : 1; //!< ZQ SW calibration enable. This bit when asserted enables ZQ SW calibration. HW negates this bit upon completion of the ZQ SW calibration. Upon negation of this bit the ZQ SW calibration result (i.e ZQ_SW_RES) is valid
        unsigned ZQ_SW_RES : 1; //!< ZQ software calibration result. This bit reflects the ZQ calibration voltage comparator value.
        unsigned ZQ_SW_PU_VAL : 5; //!< ZQ software pull-up resistence.This field determines the value of the PU resistor during SW ZQ calibration.
        unsigned ZQ_SW_PD_VAL : 5; //!< ZQ software pull-down resistence.This field determines the value of the PD resistor during SW ZQ calibration.
        unsigned ZQ_SW_PD : 1; //!< ZQ software PU/PD calibration. This bit determines the calibration stage (PU or PD).
        unsigned USE_ZQ_SW_VAL : 1; //!< Use SW ZQ configured value for I/O pads resistor controls. This bit selects whether ZQ SW value or ZQ HW value will be driven to the I/O pads resistor controls. By default this bit is cleared and MMDC drives the HW ZQ status bits on the resistor controls of the I/O pads.  This bit should not be updated during ZQ calibration.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned ZQ_CMP_OUT_SMP : 2; //!< Defines the amount of cycles between driving the ZQ signals to the ZQ pad and till sampling the comparator enable output while performing ZQ calibration process with the i.MX ZQ calibration pad
        unsigned RESERVED1 : 14; //!< Reserved
    } B;
} hw_mmdc_mpzqswctrl_t;
#endif

/*
 * constants & macros for entire MMDC_MPZQSWCTRL register
 */
#define HW_MMDC_MPZQSWCTRL_ADDR      (REGS_MMDC_BASE + 0x804)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPZQSWCTRL           (*(volatile hw_mmdc_mpzqswctrl_t *) HW_MMDC_MPZQSWCTRL_ADDR)
#define HW_MMDC_MPZQSWCTRL_RD()      (HW_MMDC_MPZQSWCTRL.U)
#define HW_MMDC_MPZQSWCTRL_WR(v)     (HW_MMDC_MPZQSWCTRL.U = (v))
#define HW_MMDC_MPZQSWCTRL_SET(v)    (HW_MMDC_MPZQSWCTRL_WR(HW_MMDC_MPZQSWCTRL_RD() |  (v)))
#define HW_MMDC_MPZQSWCTRL_CLR(v)    (HW_MMDC_MPZQSWCTRL_WR(HW_MMDC_MPZQSWCTRL_RD() & ~(v)))
#define HW_MMDC_MPZQSWCTRL_TOG(v)    (HW_MMDC_MPZQSWCTRL_WR(HW_MMDC_MPZQSWCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPZQSWCTRL bitfields
 */

/* --- Register HW_MMDC_MPZQSWCTRL, field ZQ_SW_FOR
 *
 * ZQ SW calibration enable. This bit when asserted enables ZQ SW
 * calibration. HW negates this bit upon completion of the ZQ SW
 * calibration. Upon negation of this bit the ZQ SW calibration result
 * (i.e ZQ_SW_RES) is valid
 */

#define BP_MMDC_MPZQSWCTRL_ZQ_SW_FOR      0
#define BM_MMDC_MPZQSWCTRL_ZQ_SW_FOR      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPZQSWCTRL_ZQ_SW_FOR(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPZQSWCTRL_ZQ_SW_FOR)
#else
#define BF_MMDC_MPZQSWCTRL_ZQ_SW_FOR(v)   (((v) << 0) & BM_MMDC_MPZQSWCTRL_ZQ_SW_FOR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPZQSWCTRL_ZQ_SW_FOR(v)   BF_CS1(MMDC_MPZQSWCTRL, ZQ_SW_FOR, v)
#endif

/* --- Register HW_MMDC_MPZQSWCTRL, field ZQ_SW_RES
 *
 * ZQ software calibration result. This bit reflects the ZQ calibration
 * voltage comparator value.
 */

#define BP_MMDC_MPZQSWCTRL_ZQ_SW_RES      1
#define BM_MMDC_MPZQSWCTRL_ZQ_SW_RES      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPZQSWCTRL_ZQ_SW_RES(v)   ((((reg32_t) v) << 1) & BM_MMDC_MPZQSWCTRL_ZQ_SW_RES)
#else
#define BF_MMDC_MPZQSWCTRL_ZQ_SW_RES(v)   (((v) << 1) & BM_MMDC_MPZQSWCTRL_ZQ_SW_RES)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPZQSWCTRL_ZQ_SW_RES(v)   BF_CS1(MMDC_MPZQSWCTRL, ZQ_SW_RES, v)
#endif

/* --- Register HW_MMDC_MPZQSWCTRL, field ZQ_SW_PU_VAL
 *
 * ZQ software pull-up resistence.This field determines the value of the
 * PU resistor during SW ZQ calibration.
 */

#define BP_MMDC_MPZQSWCTRL_ZQ_SW_PU_VAL      2
#define BM_MMDC_MPZQSWCTRL_ZQ_SW_PU_VAL      0x0000007c

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPZQSWCTRL_ZQ_SW_PU_VAL(v)   ((((reg32_t) v) << 2) & BM_MMDC_MPZQSWCTRL_ZQ_SW_PU_VAL)
#else
#define BF_MMDC_MPZQSWCTRL_ZQ_SW_PU_VAL(v)   (((v) << 2) & BM_MMDC_MPZQSWCTRL_ZQ_SW_PU_VAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPZQSWCTRL_ZQ_SW_PU_VAL(v)   BF_CS1(MMDC_MPZQSWCTRL, ZQ_SW_PU_VAL, v)
#endif

/* --- Register HW_MMDC_MPZQSWCTRL, field ZQ_SW_PD_VAL
 *
 * ZQ software pull-down resistence.This field determines the value of
 * the PD resistor during SW ZQ calibration.
 */

#define BP_MMDC_MPZQSWCTRL_ZQ_SW_PD_VAL      7
#define BM_MMDC_MPZQSWCTRL_ZQ_SW_PD_VAL      0x00000f80

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPZQSWCTRL_ZQ_SW_PD_VAL(v)   ((((reg32_t) v) << 7) & BM_MMDC_MPZQSWCTRL_ZQ_SW_PD_VAL)
#else
#define BF_MMDC_MPZQSWCTRL_ZQ_SW_PD_VAL(v)   (((v) << 7) & BM_MMDC_MPZQSWCTRL_ZQ_SW_PD_VAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPZQSWCTRL_ZQ_SW_PD_VAL(v)   BF_CS1(MMDC_MPZQSWCTRL, ZQ_SW_PD_VAL, v)
#endif

/* --- Register HW_MMDC_MPZQSWCTRL, field ZQ_SW_PD
 *
 * ZQ software PU/PD calibration. This bit determines the calibration
 * stage (PU or PD).
 */

#define BP_MMDC_MPZQSWCTRL_ZQ_SW_PD      12
#define BM_MMDC_MPZQSWCTRL_ZQ_SW_PD      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPZQSWCTRL_ZQ_SW_PD(v)   ((((reg32_t) v) << 12) & BM_MMDC_MPZQSWCTRL_ZQ_SW_PD)
#else
#define BF_MMDC_MPZQSWCTRL_ZQ_SW_PD(v)   (((v) << 12) & BM_MMDC_MPZQSWCTRL_ZQ_SW_PD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPZQSWCTRL_ZQ_SW_PD(v)   BF_CS1(MMDC_MPZQSWCTRL, ZQ_SW_PD, v)
#endif

/* --- Register HW_MMDC_MPZQSWCTRL, field USE_ZQ_SW_VAL
 *
 * Use SW ZQ configured value for I/O pads resistor controls. This bit
 * selects whether ZQ SW value or ZQ HW value will be driven to the I/O
 * pads resistor controls. By default this bit is cleared and MMDC
 * drives the HW ZQ status bits on the resistor controls of the I/O
 * pads.  This bit should not be updated during ZQ calibration.
 */

#define BP_MMDC_MPZQSWCTRL_USE_ZQ_SW_VAL      13
#define BM_MMDC_MPZQSWCTRL_USE_ZQ_SW_VAL      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPZQSWCTRL_USE_ZQ_SW_VAL(v)   ((((reg32_t) v) << 13) & BM_MMDC_MPZQSWCTRL_USE_ZQ_SW_VAL)
#else
#define BF_MMDC_MPZQSWCTRL_USE_ZQ_SW_VAL(v)   (((v) << 13) & BM_MMDC_MPZQSWCTRL_USE_ZQ_SW_VAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPZQSWCTRL_USE_ZQ_SW_VAL(v)   BF_CS1(MMDC_MPZQSWCTRL, USE_ZQ_SW_VAL, v)
#endif

/* --- Register HW_MMDC_MPZQSWCTRL, field ZQ_CMP_OUT_SMP
 *
 * Defines the amount of cycles between driving the ZQ signals to the ZQ
 * pad and till sampling the comparator enable output while performing
 * ZQ calibration process with the i.MX ZQ calibration pad
 */

#define BP_MMDC_MPZQSWCTRL_ZQ_CMP_OUT_SMP      16
#define BM_MMDC_MPZQSWCTRL_ZQ_CMP_OUT_SMP      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPZQSWCTRL_ZQ_CMP_OUT_SMP(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPZQSWCTRL_ZQ_CMP_OUT_SMP)
#else
#define BF_MMDC_MPZQSWCTRL_ZQ_CMP_OUT_SMP(v)   (((v) << 16) & BM_MMDC_MPZQSWCTRL_ZQ_CMP_OUT_SMP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPZQSWCTRL_ZQ_CMP_OUT_SMP(v)   BF_CS1(MMDC_MPZQSWCTRL, ZQ_CMP_OUT_SMP, v)
#endif

/*!
 * @brief HW_MMDC_MPWLGCR - MMDC PHY Write Leveling Configuration and Error Status                        Register
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: DDR3_x64, LP2_2ch_x16,
 * LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned HW_WL_EN : 1; //!< Write-Leveling HW (automatic) enable. If this bit is asserted then the MMDC will perform the whole Write-Leveling sequence with the DDR device (assuming that Write-Leveling procedure is already enabled in the DDR device through MRS command). HW negates this bit upon completion of the HW write-leveling. Negation of this bit also points that the write-leveling HW calibration results are valid  Before issuing the first DQS the MMDC counts 25 + 15 cycles automatically as required by the standard.
        unsigned SW_WL_EN : 1; //!< Write-Leveling SW enable. If this bit is asserted then the MMDC will perform one write-leveling iteration with the DDR device (assuming that Write-Leveling procedure is already enabled in the DDR device through MRS command). HW negate this bit upon completion of the SW write-leveling. Negation of this bit also points that the write-leveling SW calibration result is valid  If this bit and the SW_WL_CNT_EN are enabled the MMDC counts 25 + 15 cycles before issuing the SW write-leveling DQS.
        unsigned SW_WL_CNT_EN : 1; //!< SW write-leveling count down enable.This bit when asserted set a certain delay of (25+15) cycles from the setting of SW_WL_EN and before driving the DQS to the DDR device.This bit should be asserted before the first SW write-leveling request and after issuing the write leveling MRS command
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned WL_SW_RES0 : 1; //!< Byte0 write-leveling software result. This bit reflects the value that is driven by the DDR device on DQ0 during SW write-leveling.
        unsigned WL_SW_RES1 : 1; //!< Byte1 write-leveling software result. This bit reflects the value that is driven by the DDR device on DQ8 during SW write-leveling.
        unsigned WL_SW_RES2 : 1; //!< Byte2 write-leveling software result. This bit reflects the value that is driven by the DDR device on DQ16 during SW write-leveling.
        unsigned WL_SW_RES3 : 1; //!< Byte3 write-leveling software result. This bit reflects the value that is driven by the DDR device on DQ24 during SW write-leveling.
        unsigned WL_HW_ERR0 : 1; //!< Byte0 write-leveling HW calibration error. This bit is asserted when an error was found on byte0 during write-leveling HW calibration.  This bit is valid only upon completion of the write-leveling HW calibration (i.e HW_WL_EN bit is de-asserted)
        unsigned WL_HW_ERR1 : 1; //!< Byte1 write-leveling HW calibration error. This bit is asserted when an error was found on byte1 during write-leveling HW calibration.  This bit is valid only upon completion of the write-leveling HW calibration (i.e HW_WL_EN bit is de-asserted)
        unsigned WL_HW_ERR2 : 1; //!< Byte2 write-leveling HW calibration error. This bit is asserted when an error was found on byte2 during write-leveling HW calibration.  This bit is valid only upon completion of the write-leveling HW calibration (i.e HW_WL_EN bit is de-asserted)
        unsigned WL_HW_ERR3 : 1; //!< Byte3 write-leveling HW calibration error. This bit is asserted when an error was found on byte3 during write-leveling HW calibration.  This bit is valid only upon completion of the write-leveling HW calibration (i.e HW_WL_EN bit is de-asserted)
        unsigned RESERVED1 : 20; //!< Reserved
    } B;
} hw_mmdc_mpwlgcr_t;
#endif

/*
 * constants & macros for entire MMDC_MPWLGCR register
 */
#define HW_MMDC_MPWLGCR_ADDR      (REGS_MMDC_BASE + 0x808)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPWLGCR           (*(volatile hw_mmdc_mpwlgcr_t *) HW_MMDC_MPWLGCR_ADDR)
#define HW_MMDC_MPWLGCR_RD()      (HW_MMDC_MPWLGCR.U)
#define HW_MMDC_MPWLGCR_WR(v)     (HW_MMDC_MPWLGCR.U = (v))
#define HW_MMDC_MPWLGCR_SET(v)    (HW_MMDC_MPWLGCR_WR(HW_MMDC_MPWLGCR_RD() |  (v)))
#define HW_MMDC_MPWLGCR_CLR(v)    (HW_MMDC_MPWLGCR_WR(HW_MMDC_MPWLGCR_RD() & ~(v)))
#define HW_MMDC_MPWLGCR_TOG(v)    (HW_MMDC_MPWLGCR_WR(HW_MMDC_MPWLGCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPWLGCR bitfields
 */

/* --- Register HW_MMDC_MPWLGCR, field HW_WL_EN
 *
 * Write-Leveling HW (automatic) enable. If this bit is asserted then
 * the MMDC will perform the whole Write-Leveling sequence with the DDR
 * device (assuming that Write-Leveling procedure is already enabled in
 * the DDR device through MRS command). HW negates this bit upon
 * completion of the HW write-leveling. Negation of this bit also
 * points that the write-leveling HW calibration results are valid  Before issuing the first DQS the
 * MMDC counts 25 + 15 cycles                                 automatically as required by the
 * standard.
 */

#define BP_MMDC_MPWLGCR_HW_WL_EN      0
#define BM_MMDC_MPWLGCR_HW_WL_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLGCR_HW_WL_EN(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPWLGCR_HW_WL_EN)
#else
#define BF_MMDC_MPWLGCR_HW_WL_EN(v)   (((v) << 0) & BM_MMDC_MPWLGCR_HW_WL_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLGCR_HW_WL_EN(v)   BF_CS1(MMDC_MPWLGCR, HW_WL_EN, v)
#endif

/* --- Register HW_MMDC_MPWLGCR, field SW_WL_EN
 *
 * Write-Leveling SW enable. If this bit is asserted then the MMDC will
 * perform one write-leveling iteration with the DDR device (assuming
 * that Write-Leveling procedure is already enabled in the DDR device
 * through MRS command). HW negate this bit upon completion of the SW
 * write-leveling. Negation of this bit also points that the                                 write-
 * leveling SW calibration result is valid  If this bit and the SW_WL_CNT_EN are enabled the MMDC
 * counts 25 +                                 15 cycles before issuing the SW write-leveling DQS.
 */

#define BP_MMDC_MPWLGCR_SW_WL_EN      1
#define BM_MMDC_MPWLGCR_SW_WL_EN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLGCR_SW_WL_EN(v)   ((((reg32_t) v) << 1) & BM_MMDC_MPWLGCR_SW_WL_EN)
#else
#define BF_MMDC_MPWLGCR_SW_WL_EN(v)   (((v) << 1) & BM_MMDC_MPWLGCR_SW_WL_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLGCR_SW_WL_EN(v)   BF_CS1(MMDC_MPWLGCR, SW_WL_EN, v)
#endif

/* --- Register HW_MMDC_MPWLGCR, field SW_WL_CNT_EN
 *
 * SW write-leveling count down enable.This bit when asserted set a
 * certain delay of (25+15) cycles from the setting of SW_WL_EN and
 * before driving the DQS to the DDR device.This bit should be asserted
 * before the first SW write-leveling request and after issuing the
 * write leveling MRS command
 */

#define BP_MMDC_MPWLGCR_SW_WL_CNT_EN      2
#define BM_MMDC_MPWLGCR_SW_WL_CNT_EN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLGCR_SW_WL_CNT_EN(v)   ((((reg32_t) v) << 2) & BM_MMDC_MPWLGCR_SW_WL_CNT_EN)
#else
#define BF_MMDC_MPWLGCR_SW_WL_CNT_EN(v)   (((v) << 2) & BM_MMDC_MPWLGCR_SW_WL_CNT_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLGCR_SW_WL_CNT_EN(v)   BF_CS1(MMDC_MPWLGCR, SW_WL_CNT_EN, v)
#endif

/* --- Register HW_MMDC_MPWLGCR, field WL_SW_RES0
 *
 * Byte0 write-leveling software result. This bit reflects the value
 * that is driven by the DDR device on DQ0 during SW                                 write-leveling.
 */

#define BP_MMDC_MPWLGCR_WL_SW_RES0      4
#define BM_MMDC_MPWLGCR_WL_SW_RES0      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLGCR_WL_SW_RES0(v)   ((((reg32_t) v) << 4) & BM_MMDC_MPWLGCR_WL_SW_RES0)
#else
#define BF_MMDC_MPWLGCR_WL_SW_RES0(v)   (((v) << 4) & BM_MMDC_MPWLGCR_WL_SW_RES0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLGCR_WL_SW_RES0(v)   BF_CS1(MMDC_MPWLGCR, WL_SW_RES0, v)
#endif

/* --- Register HW_MMDC_MPWLGCR, field WL_SW_RES1
 *
 * Byte1 write-leveling software result. This bit reflects the value
 * that is driven by the DDR device on DQ8 during SW                                 write-leveling.
 */

#define BP_MMDC_MPWLGCR_WL_SW_RES1      5
#define BM_MMDC_MPWLGCR_WL_SW_RES1      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLGCR_WL_SW_RES1(v)   ((((reg32_t) v) << 5) & BM_MMDC_MPWLGCR_WL_SW_RES1)
#else
#define BF_MMDC_MPWLGCR_WL_SW_RES1(v)   (((v) << 5) & BM_MMDC_MPWLGCR_WL_SW_RES1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLGCR_WL_SW_RES1(v)   BF_CS1(MMDC_MPWLGCR, WL_SW_RES1, v)
#endif

/* --- Register HW_MMDC_MPWLGCR, field WL_SW_RES2
 *
 * Byte2 write-leveling software result. This bit reflects the value
 * that is driven by the DDR device on DQ16 during SW                                 write-
 * leveling.
 */

#define BP_MMDC_MPWLGCR_WL_SW_RES2      6
#define BM_MMDC_MPWLGCR_WL_SW_RES2      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLGCR_WL_SW_RES2(v)   ((((reg32_t) v) << 6) & BM_MMDC_MPWLGCR_WL_SW_RES2)
#else
#define BF_MMDC_MPWLGCR_WL_SW_RES2(v)   (((v) << 6) & BM_MMDC_MPWLGCR_WL_SW_RES2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLGCR_WL_SW_RES2(v)   BF_CS1(MMDC_MPWLGCR, WL_SW_RES2, v)
#endif

/* --- Register HW_MMDC_MPWLGCR, field WL_SW_RES3
 *
 * Byte3 write-leveling software result. This bit reflects the value
 * that is driven by the DDR device on DQ24 during SW                                 write-
 * leveling.
 */

#define BP_MMDC_MPWLGCR_WL_SW_RES3      7
#define BM_MMDC_MPWLGCR_WL_SW_RES3      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLGCR_WL_SW_RES3(v)   ((((reg32_t) v) << 7) & BM_MMDC_MPWLGCR_WL_SW_RES3)
#else
#define BF_MMDC_MPWLGCR_WL_SW_RES3(v)   (((v) << 7) & BM_MMDC_MPWLGCR_WL_SW_RES3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLGCR_WL_SW_RES3(v)   BF_CS1(MMDC_MPWLGCR, WL_SW_RES3, v)
#endif

/* --- Register HW_MMDC_MPWLGCR, field WL_HW_ERR0
 *
 * Byte0 write-leveling HW calibration error. This bit is asserted when
 * an error was found on byte0 during write-leveling HW                                 calibration.
 * This bit is valid only upon completion of the write-leveling HW
 * calibration (i.e HW_WL_EN bit is de-asserted)
 */

#define BP_MMDC_MPWLGCR_WL_HW_ERR0      8
#define BM_MMDC_MPWLGCR_WL_HW_ERR0      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLGCR_WL_HW_ERR0(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPWLGCR_WL_HW_ERR0)
#else
#define BF_MMDC_MPWLGCR_WL_HW_ERR0(v)   (((v) << 8) & BM_MMDC_MPWLGCR_WL_HW_ERR0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLGCR_WL_HW_ERR0(v)   BF_CS1(MMDC_MPWLGCR, WL_HW_ERR0, v)
#endif

/* --- Register HW_MMDC_MPWLGCR, field WL_HW_ERR1
 *
 * Byte1 write-leveling HW calibration error. This bit is asserted when
 * an error was found on byte1 during write-leveling HW                                 calibration.
 * This bit is valid only upon completion of the write-leveling HW
 * calibration (i.e HW_WL_EN bit is de-asserted)
 */

#define BP_MMDC_MPWLGCR_WL_HW_ERR1      9
#define BM_MMDC_MPWLGCR_WL_HW_ERR1      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLGCR_WL_HW_ERR1(v)   ((((reg32_t) v) << 9) & BM_MMDC_MPWLGCR_WL_HW_ERR1)
#else
#define BF_MMDC_MPWLGCR_WL_HW_ERR1(v)   (((v) << 9) & BM_MMDC_MPWLGCR_WL_HW_ERR1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLGCR_WL_HW_ERR1(v)   BF_CS1(MMDC_MPWLGCR, WL_HW_ERR1, v)
#endif

/* --- Register HW_MMDC_MPWLGCR, field WL_HW_ERR2
 *
 * Byte2 write-leveling HW calibration error. This bit is asserted when
 * an error was found on byte2 during write-leveling HW                                 calibration.
 * This bit is valid only upon completion of the write-leveling HW
 * calibration (i.e HW_WL_EN bit is de-asserted)
 */

#define BP_MMDC_MPWLGCR_WL_HW_ERR2      10
#define BM_MMDC_MPWLGCR_WL_HW_ERR2      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLGCR_WL_HW_ERR2(v)   ((((reg32_t) v) << 10) & BM_MMDC_MPWLGCR_WL_HW_ERR2)
#else
#define BF_MMDC_MPWLGCR_WL_HW_ERR2(v)   (((v) << 10) & BM_MMDC_MPWLGCR_WL_HW_ERR2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLGCR_WL_HW_ERR2(v)   BF_CS1(MMDC_MPWLGCR, WL_HW_ERR2, v)
#endif

/* --- Register HW_MMDC_MPWLGCR, field WL_HW_ERR3
 *
 * Byte3 write-leveling HW calibration error. This bit is asserted when
 * an error was found on byte3 during write-leveling HW                                 calibration.
 * This bit is valid only upon completion of the write-leveling HW
 * calibration (i.e HW_WL_EN bit is de-asserted)
 */

#define BP_MMDC_MPWLGCR_WL_HW_ERR3      11
#define BM_MMDC_MPWLGCR_WL_HW_ERR3      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLGCR_WL_HW_ERR3(v)   ((((reg32_t) v) << 11) & BM_MMDC_MPWLGCR_WL_HW_ERR3)
#else
#define BF_MMDC_MPWLGCR_WL_HW_ERR3(v)   (((v) << 11) & BM_MMDC_MPWLGCR_WL_HW_ERR3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLGCR_WL_HW_ERR3(v)   BF_CS1(MMDC_MPWLGCR, WL_HW_ERR3, v)
#endif

/*!
 * @brief HW_MMDC_MPWLDECTRL0 - MMDC PHY Write Leveling Delay Control Register                        0
 *
 * Supported Mode OF Operations:  For Channel 0: All  For Channel 1: DDR3_x64, LP2_2ch_x16,
 * LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WL_DL_ABS_OFFSET0 : 7; //!< Absolute write-leveling delay offset for Byte 0. This field indicates the absolute delay between CK and write DQS of Byte0 with fractions of a clock period and up to half cycle. This value is process and frequency independent. The value of the delay can be calculated using the following equation (WR_DL_ABS_OFFSET1 / 256) * clock period  When SW write-leveling is enabled (i.e SW_WL_EN = 1) then this value will be taken as is to the associated delay-line. When HW write-leveling is enabled (i.e HW_WL_EN = 1 ) then this value will indicate (status) the value that is taken to the associated delay-line at the end of the write-leveling calibration.  The delay-line has a resolution that may vary between device to device, therefore is some cases an increment of the delay by 1 step may be smaller than the delay-line resolution.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned WL_HC_DEL0 : 1; //!< Write leveling half cycle delay for Byte 0. This field indicates whether a delay of half cycle between CK and write DQS is added to the delay that is indicated in the associated WR_DL_ABS_OFFSET and WL_CYC_DEL. So the total delay is the sum of (WL_DL_ABS_OFFSET/256*cycle) + (WL_HC_DEL*half cycle) + (WL_CYC_DEL*cycle).  When SW write-leveling is enabled (i.e SW_WL_EN = 1) then this value will be taken as is and will be added to the associated delay that is configured in WL_DL_OFFSET and WL_CYC_DEL. When HW write-leveling is enabled (i.e HW_WL_EN = 1 ) then this value will indicate (status) whether a delay of half cycle was added or not to the associated WL_DL_OFFSET and WL_CYC_DEL.
        unsigned WL_CYC_DEL0 : 2; //!< Write leveling cycle delay for Byte 0. This field indicates whether a delay of 1 or 2 cycles between CK and write DQS is added to the delay that is indicated in the associated WR_DL_ABS_OFFSET and WL_HC_DEL. So the total delay is the sum of (WL_DL_ABS_OFFSET/256*cycle) + (WL_HC_DEL*half cycle) + (WL_CYC_DEL*cycle).  When both SW write-leveling is enabled (i.e SW_WL_EN = 1) or HW write-leveling is enabled (i.e HW_WL_EN = 1 ) then this value will be taken as is and will be added to the associated delay that is configured in WL_DL_OFFSET and WL_HC_DEL.  Note that in HW write-leveling this field is not used for indication, as in WL_DL_OFFSET and WL_HC_DEL, but for configuration.
        unsigned RESERVED1 : 5; //!< Reserved
        unsigned WL_DL_ABS_OFFSET1 : 7; //!< Absolute write-leveling delay offset for Byte 1. This field indicates the absolute delay between CK and write DQS of Byte1 with fractions of a clock period and up to half cycle. This value is process and frequency independent. The value of the delay can be calculated using the following equation (WR_DL_ABS_OFFSET1 / 256) * clock period  When SW write-leveling is enabled (i.e SW_WL_EN = 1) then this value will be taken as is to the associated delay-line. When HW write-leveling is enabled (i.e HW_WL_EN = 1 ) then this value will indicate (status) the value that is taken to the associated delay-line at the end of the write-leveling calibration.  The delay-line has a resolution that may vary between device to device, therefore is some cases an increment of the delay by 1 step may be smaller than the delay-line resolution.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned WL_HC_DEL1 : 1; //!< Write leveling half cycle delay for Byte 1. This field indicates whether a delay of half cycle between CK and write DQS is added to the delay that is indicated in the associated WR_DL_ABS_OFFSET and WL_CYC_DEL. So the total delay is the sum of (WL_DL_ABS_OFFSET/256*cycle) + (WL_HC_DEL*half cycle) + (WL_CYC_DEL*cycle).  When SW write-leveling is enabled (i.e SW_WL_EN = 1) then this value will be taken as is and will be added to the associated delay that is configured in WL_DL_OFFSET and WL_CYC_DEL. When HW write-leveling is enabled (i.e HW_WL_EN = 1 ) then this value will indicate (status) whether a delay of half cycle was added or not to the associated WL_DL_OFFSET and WL_CYC_DEL.
        unsigned WL_CYC_DEL1 : 2; //!< Write leveling cycle delay for Byte 1. This field indicates whether a delay of 1 or 2 cycles between CK and write DQS is added to the delay that is indicated in the associated WR_DL_ABS_OFFSET and WL_HC_DEL. So the total delay is the sum of (WL_DL_ABS_OFFSET/256*cycle) + (WL_HC_DEL*half cycle) + (WL_CYC_DEL*cycle).  When both SW write-leveling is enabled (i.e SW_WL_EN = 1) or HW write-leveling is enabled (i.e HW_WL_EN = 1 ) then this value will be taken as is and will be added to the associated delay that is configured in WL_DL_OFFSET and WL_HC_DEL.  Note that in HW write-leveling this field is not used for indication, as in WL_DL_OFFSET and WL_HC_DEL, but for configuration.
        unsigned RESERVED3 : 5; //!< Reserved
    } B;
} hw_mmdc_mpwldectrl0_t;
#endif

/*
 * constants & macros for entire MMDC_MPWLDECTRL0 register
 */
#define HW_MMDC_MPWLDECTRL0_ADDR      (REGS_MMDC_BASE + 0x80c)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPWLDECTRL0           (*(volatile hw_mmdc_mpwldectrl0_t *) HW_MMDC_MPWLDECTRL0_ADDR)
#define HW_MMDC_MPWLDECTRL0_RD()      (HW_MMDC_MPWLDECTRL0.U)
#define HW_MMDC_MPWLDECTRL0_WR(v)     (HW_MMDC_MPWLDECTRL0.U = (v))
#define HW_MMDC_MPWLDECTRL0_SET(v)    (HW_MMDC_MPWLDECTRL0_WR(HW_MMDC_MPWLDECTRL0_RD() |  (v)))
#define HW_MMDC_MPWLDECTRL0_CLR(v)    (HW_MMDC_MPWLDECTRL0_WR(HW_MMDC_MPWLDECTRL0_RD() & ~(v)))
#define HW_MMDC_MPWLDECTRL0_TOG(v)    (HW_MMDC_MPWLDECTRL0_WR(HW_MMDC_MPWLDECTRL0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPWLDECTRL0 bitfields
 */

/* --- Register HW_MMDC_MPWLDECTRL0, field WL_DL_ABS_OFFSET0
 *
 * Absolute write-leveling delay offset for Byte 0. This field indicates
 * the absolute delay between CK and write DQS of Byte0 with fractions
 * of a clock period and up to half cycle. This value is process and
 * frequency independent. The value of the delay can be calculated
 * using the following equation (WR_DL_ABS_OFFSET1 / 256) * clock
 * period  When SW write-leveling is enabled (i.e SW_WL_EN = 1) then this value
 * will be taken as is to the associated delay-line. When HW                                 write-
 * leveling is enabled (i.e HW_WL_EN = 1 ) then this value will
 * indicate (status) the value that is taken to the associated
 * delay-line at the end of the write-leveling calibration.  The delay-line has a resolution that
 * may vary between device to                                 device, therefore is some cases an
 * increment of the delay by 1 step                                 may be smaller than the delay-
 * line resolution.
 */

#define BP_MMDC_MPWLDECTRL0_WL_DL_ABS_OFFSET0      0
#define BM_MMDC_MPWLDECTRL0_WL_DL_ABS_OFFSET0      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLDECTRL0_WL_DL_ABS_OFFSET0(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPWLDECTRL0_WL_DL_ABS_OFFSET0)
#else
#define BF_MMDC_MPWLDECTRL0_WL_DL_ABS_OFFSET0(v)   (((v) << 0) & BM_MMDC_MPWLDECTRL0_WL_DL_ABS_OFFSET0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLDECTRL0_WL_DL_ABS_OFFSET0(v)   BF_CS1(MMDC_MPWLDECTRL0, WL_DL_ABS_OFFSET0, v)
#endif

/* --- Register HW_MMDC_MPWLDECTRL0, field WL_HC_DEL0
 *
 * Write leveling half cycle delay for Byte 0. This field indicates
 * whether a delay of half cycle between CK and write DQS is added to
 * the delay that is indicated in the associated WR_DL_ABS_OFFSET and
 * WL_CYC_DEL. So the total delay is the sum of
 * (WL_DL_ABS_OFFSET/256*cycle) + (WL_HC_DEL*half cycle) +
 * (WL_CYC_DEL*cycle).  When SW write-leveling is enabled (i.e SW_WL_EN = 1) then this value
 * will be taken as is and will be added to the associated delay that
 * is configured in WL_DL_OFFSET and WL_CYC_DEL. When HW write-leveling
 * is enabled (i.e HW_WL_EN = 1 ) then this value will indicate
 * (status) whether a delay of half cycle was added or not to the
 * associated WL_DL_OFFSET and WL_CYC_DEL.
 */

#define BP_MMDC_MPWLDECTRL0_WL_HC_DEL0      8
#define BM_MMDC_MPWLDECTRL0_WL_HC_DEL0      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLDECTRL0_WL_HC_DEL0(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPWLDECTRL0_WL_HC_DEL0)
#else
#define BF_MMDC_MPWLDECTRL0_WL_HC_DEL0(v)   (((v) << 8) & BM_MMDC_MPWLDECTRL0_WL_HC_DEL0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLDECTRL0_WL_HC_DEL0(v)   BF_CS1(MMDC_MPWLDECTRL0, WL_HC_DEL0, v)
#endif

/* --- Register HW_MMDC_MPWLDECTRL0, field WL_CYC_DEL0
 *
 * Write leveling cycle delay for Byte 0. This field indicates whether a
 * delay of 1 or 2 cycles between CK and write DQS is added to the
 * delay that is indicated in the associated WR_DL_ABS_OFFSET and
 * WL_HC_DEL. So the total delay is the sum of
 * (WL_DL_ABS_OFFSET/256*cycle) + (WL_HC_DEL*half cycle) +
 * (WL_CYC_DEL*cycle).  When both SW write-leveling is enabled (i.e SW_WL_EN = 1) or HW
 * write-leveling is enabled (i.e HW_WL_EN = 1 ) then this value will
 * be taken as is and will be added to the associated delay that is
 * configured in WL_DL_OFFSET and WL_HC_DEL.  Note that in HW write-leveling this field is not used
 * for indication,                                 as in WL_DL_OFFSET and WL_HC_DEL, but for
 * configuration.
 */

#define BP_MMDC_MPWLDECTRL0_WL_CYC_DEL0      9
#define BM_MMDC_MPWLDECTRL0_WL_CYC_DEL0      0x00000600

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLDECTRL0_WL_CYC_DEL0(v)   ((((reg32_t) v) << 9) & BM_MMDC_MPWLDECTRL0_WL_CYC_DEL0)
#else
#define BF_MMDC_MPWLDECTRL0_WL_CYC_DEL0(v)   (((v) << 9) & BM_MMDC_MPWLDECTRL0_WL_CYC_DEL0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLDECTRL0_WL_CYC_DEL0(v)   BF_CS1(MMDC_MPWLDECTRL0, WL_CYC_DEL0, v)
#endif

/* --- Register HW_MMDC_MPWLDECTRL0, field WL_DL_ABS_OFFSET1
 *
 * Absolute write-leveling delay offset for Byte 1. This field indicates
 * the absolute delay between CK and write DQS of Byte1 with fractions
 * of a clock period and up to half cycle. This value is process and
 * frequency independent. The value of the delay can be calculated
 * using the following equation (WR_DL_ABS_OFFSET1 / 256) * clock
 * period  When SW write-leveling is enabled (i.e SW_WL_EN = 1) then this value
 * will be taken as is to the associated delay-line. When HW                                 write-
 * leveling is enabled (i.e HW_WL_EN = 1 ) then this value will
 * indicate (status) the value that is taken to the associated
 * delay-line at the end of the write-leveling calibration.  The delay-line has a resolution that
 * may vary between device to                                 device, therefore is some cases an
 * increment of the delay by 1 step                                 may be smaller than the delay-
 * line resolution.
 */

#define BP_MMDC_MPWLDECTRL0_WL_DL_ABS_OFFSET1      16
#define BM_MMDC_MPWLDECTRL0_WL_DL_ABS_OFFSET1      0x007f0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLDECTRL0_WL_DL_ABS_OFFSET1(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPWLDECTRL0_WL_DL_ABS_OFFSET1)
#else
#define BF_MMDC_MPWLDECTRL0_WL_DL_ABS_OFFSET1(v)   (((v) << 16) & BM_MMDC_MPWLDECTRL0_WL_DL_ABS_OFFSET1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLDECTRL0_WL_DL_ABS_OFFSET1(v)   BF_CS1(MMDC_MPWLDECTRL0, WL_DL_ABS_OFFSET1, v)
#endif

/* --- Register HW_MMDC_MPWLDECTRL0, field WL_HC_DEL1
 *
 * Write leveling half cycle delay for Byte 1. This field indicates
 * whether a delay of half cycle between CK and write DQS is added to
 * the delay that is indicated in the associated WR_DL_ABS_OFFSET and
 * WL_CYC_DEL. So the total delay is the sum of
 * (WL_DL_ABS_OFFSET/256*cycle) + (WL_HC_DEL*half cycle) +
 * (WL_CYC_DEL*cycle).  When SW write-leveling is enabled (i.e SW_WL_EN = 1) then this value
 * will be taken as is and will be added to the associated delay that
 * is configured in WL_DL_OFFSET and WL_CYC_DEL. When HW write-leveling
 * is enabled (i.e HW_WL_EN = 1 ) then this value will indicate
 * (status) whether a delay of half cycle was added or not to the
 * associated WL_DL_OFFSET and WL_CYC_DEL.
 */

#define BP_MMDC_MPWLDECTRL0_WL_HC_DEL1      24
#define BM_MMDC_MPWLDECTRL0_WL_HC_DEL1      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLDECTRL0_WL_HC_DEL1(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPWLDECTRL0_WL_HC_DEL1)
#else
#define BF_MMDC_MPWLDECTRL0_WL_HC_DEL1(v)   (((v) << 24) & BM_MMDC_MPWLDECTRL0_WL_HC_DEL1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLDECTRL0_WL_HC_DEL1(v)   BF_CS1(MMDC_MPWLDECTRL0, WL_HC_DEL1, v)
#endif

/* --- Register HW_MMDC_MPWLDECTRL0, field WL_CYC_DEL1
 *
 * Write leveling cycle delay for Byte 1. This field indicates whether a
 * delay of 1 or 2 cycles between CK and write DQS is added to the
 * delay that is indicated in the associated WR_DL_ABS_OFFSET and
 * WL_HC_DEL. So the total delay is the sum of
 * (WL_DL_ABS_OFFSET/256*cycle) + (WL_HC_DEL*half cycle) +
 * (WL_CYC_DEL*cycle).  When both SW write-leveling is enabled (i.e SW_WL_EN = 1) or HW
 * write-leveling is enabled (i.e HW_WL_EN = 1 ) then this value will
 * be taken as is and will be added to the associated delay that is
 * configured in WL_DL_OFFSET and WL_HC_DEL.  Note that in HW write-leveling this field is not used
 * for indication,                                 as in WL_DL_OFFSET and WL_HC_DEL, but for
 * configuration.
 */

#define BP_MMDC_MPWLDECTRL0_WL_CYC_DEL1      25
#define BM_MMDC_MPWLDECTRL0_WL_CYC_DEL1      0x06000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLDECTRL0_WL_CYC_DEL1(v)   ((((reg32_t) v) << 25) & BM_MMDC_MPWLDECTRL0_WL_CYC_DEL1)
#else
#define BF_MMDC_MPWLDECTRL0_WL_CYC_DEL1(v)   (((v) << 25) & BM_MMDC_MPWLDECTRL0_WL_CYC_DEL1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLDECTRL0_WL_CYC_DEL1(v)   BF_CS1(MMDC_MPWLDECTRL0, WL_CYC_DEL1, v)
#endif

/*!
 * @brief HW_MMDC_MPWLDECTRL1 - MMDC PHY Write Leveling Delay Control Register                        1
 *
 * Supported Mode Of Operations:  For Channel 0: All  FOr Channel 1: DDR3_x64, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WL_DL_ABS_OFFSET2 : 7; //!< Absolute write-leveling delay offset for Byte 2. This field indicates the absolute delay between CK and write DQS of Byte1 with fractions of a clock period and up to half cycle. This value is process and frequency independent. The value of the delay can be calculated using the following equation (WR_DL_ABS_OFFSET2 / 256) * clock period  When SW write-leveling is enabled (i.e SW_WL_EN = 1) then this value will be taken as is to the associated delay-line. When HW write-leveling is enabled (i.e HW_WL_EN = 1 ) then this value will indicate (status) the value that is taken to the associated delay-line at the end of the write-leveling calibration.  The delay-line has a resolution that may vary between device to device, therefore is some cases an increment of the delay by 1 step may be smaller than the delay-line resolution.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned WL_HC_DEL2 : 1; //!< Write leveling half cycle delay for Byte 2. This field indicates whether a delay of half cycle between CK and write DQS is added to the delay that is indicated in the associated WR_DL_ABS_OFFSET and WL_CYC_DEL. So the total delay is the sum of (WL_DL_ABS_OFFSET/256*cycle) + (WL_HC_DEL*half cycle) + (WL_CYC_DEL*cycle).  When SW write-leveling is enabled (i.e SW_WL_EN = 1) then this value will be taken as is and will be added to the associated delay that is configured in WL_DL_OFFSET and WL_CYC_DEL. When HW write-leveling is enabled (i.e HW_WL_EN = 1 ) then this value will indicate (status) whether a delay of half cycle was added or not to the associated WL_DL_OFFSET and WL_CYC_DEL.
        unsigned WL_CYC_DEL2 : 2; //!< Write leveling cycle delay for Byte 2. This field indicates whether a delay of 1 or 2 cycles between CK and write DQS is added to the delay that is indicated in the associated WR_DL_ABS_OFFSET and WL_HC_DEL. So the total delay is the sum of (WL_DL_ABS_OFFSET/256*cycle) + (WL_HC_DEL*half cycle) + (WL_CYC_DEL*cycle).  When both SW write-leveling is enabled (i.e SW_WL_EN = 1) or HW write-leveling is enabled (i.e HW_WL_EN = 1 ) then this value will be taken as is and will be added to the associated delay that is configured in WL_DL_OFFSET and WL_HC_DEL.  Note that in HW write-leveling this field is not used for indication, as in WL_DL_OFFSET and WL_HC_DEL, but for configuration.
        unsigned RESERVED1 : 5; //!< Reserved
        unsigned WL_DL_ABS_OFFSET3 : 7; //!< Absolute write-leveling delay offset for Byte 3. This field indicates the absolute delay between CK and write DQS of Byte3 with fractions of a clock period and up to half cycle. This value is process and frequency independent. The value of the delay can be calculated using the following equation (WL_DL_ABS_OFFSET3 / 256) * clock period  When SW write-leveling is enabled (i.e SW_WL_EN = 1) then this value will be taken as is to the associated delay-line. When HW write-leveling is enabled (i.e HW_WL_EN = 1 ) then this value will indicate (status) the value that is taken to the associated delay-line at the end of the write-leveling calibration.  The delay-line has a resolution that may vary between device to device, therefore is some cases an increment of the delay by 1 step may be smaller than the delay-line resolution.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned WL_HC_DEL3 : 1; //!< Write leveling half cycle delay for Byte 3. This field indicates whether a delay of half cycle between CK and write DQS is added to the delay that is indicated in the associated WL_DL_ABS_OFFSET and WL_CYC_DEL. So the total delay is the sum of (WL_DL_ABS_OFFSET/256*cycle) + (WL_HC_DEL*half cycle) + (WL_CYC_DEL*cycle).  When SW write-leveling is enabled (i.e SW_WL_EN = 1) then this value will be taken as is and will be added to the associated delay that is configured in WL_DL_OFFSET and WL_CYC_DEL. When HW write-leveling is enabled (i.e HW_WL_EN = 1 ) then this value will indicate (status) whether a delay of half cycle was added or not to the associated WL_DL_OFFSET and WL_CYC_DEL.
        unsigned WL_CYC_DEL3 : 2; //!< Write leveling cycle delay for Byte 3. This field indicates whether a delay of 1 or 2 cycles between CK and write DQS is added to the delay that is indicated in the associated WL_DL_ABS_OFFSET and WL_HC_DEL. So the total delay is the sum of (WL_DL_ABS_OFFSET/256*cycle) + (WL_HC_DEL*half cycle) + (WL_CYC_DEL*cycle).  When both SW write-leveling is enabled (i.e SW_WL_EN = 1) or HW write-leveling is enabled (i.e HW_WL_EN = 1 ) then this value will be taken as is and will be added to the associated delay that is configured in WL_DL_OFFSET and WL_HC_DEL.  Note that in HW write-leveling this field is not used for indication, as in WL_DL_OFFSET and WL_HC_DEL, but for configuration.
        unsigned RESERVED3 : 5; //!< Reserved
    } B;
} hw_mmdc_mpwldectrl1_t;
#endif

/*
 * constants & macros for entire MMDC_MPWLDECTRL1 register
 */
#define HW_MMDC_MPWLDECTRL1_ADDR      (REGS_MMDC_BASE + 0x810)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPWLDECTRL1           (*(volatile hw_mmdc_mpwldectrl1_t *) HW_MMDC_MPWLDECTRL1_ADDR)
#define HW_MMDC_MPWLDECTRL1_RD()      (HW_MMDC_MPWLDECTRL1.U)
#define HW_MMDC_MPWLDECTRL1_WR(v)     (HW_MMDC_MPWLDECTRL1.U = (v))
#define HW_MMDC_MPWLDECTRL1_SET(v)    (HW_MMDC_MPWLDECTRL1_WR(HW_MMDC_MPWLDECTRL1_RD() |  (v)))
#define HW_MMDC_MPWLDECTRL1_CLR(v)    (HW_MMDC_MPWLDECTRL1_WR(HW_MMDC_MPWLDECTRL1_RD() & ~(v)))
#define HW_MMDC_MPWLDECTRL1_TOG(v)    (HW_MMDC_MPWLDECTRL1_WR(HW_MMDC_MPWLDECTRL1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPWLDECTRL1 bitfields
 */

/* --- Register HW_MMDC_MPWLDECTRL1, field WL_DL_ABS_OFFSET2
 *
 * Absolute write-leveling delay offset for Byte 2. This field indicates
 * the absolute delay between CK and write DQS of Byte1 with fractions
 * of a clock period and up to half cycle. This value is process and
 * frequency independent. The value of the delay can be calculated
 * using the following equation (WR_DL_ABS_OFFSET2 / 256) * clock
 * period  When SW write-leveling is enabled (i.e SW_WL_EN = 1) then this value
 * will be taken as is to the associated delay-line. When HW                                 write-
 * leveling is enabled (i.e HW_WL_EN = 1 ) then this value will
 * indicate (status) the value that is taken to the associated
 * delay-line at the end of the write-leveling calibration.  The delay-line has a resolution that
 * may vary between device to                                 device, therefore is some cases an
 * increment of the delay by 1 step                                 may be smaller than the delay-
 * line resolution.
 */

#define BP_MMDC_MPWLDECTRL1_WL_DL_ABS_OFFSET2      0
#define BM_MMDC_MPWLDECTRL1_WL_DL_ABS_OFFSET2      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLDECTRL1_WL_DL_ABS_OFFSET2(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPWLDECTRL1_WL_DL_ABS_OFFSET2)
#else
#define BF_MMDC_MPWLDECTRL1_WL_DL_ABS_OFFSET2(v)   (((v) << 0) & BM_MMDC_MPWLDECTRL1_WL_DL_ABS_OFFSET2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLDECTRL1_WL_DL_ABS_OFFSET2(v)   BF_CS1(MMDC_MPWLDECTRL1, WL_DL_ABS_OFFSET2, v)
#endif

/* --- Register HW_MMDC_MPWLDECTRL1, field WL_HC_DEL2
 *
 * Write leveling half cycle delay for Byte 2. This field indicates
 * whether a delay of half cycle between CK and write DQS is added to
 * the delay that is indicated in the associated WR_DL_ABS_OFFSET and
 * WL_CYC_DEL. So the total delay is the sum of
 * (WL_DL_ABS_OFFSET/256*cycle) + (WL_HC_DEL*half cycle) +
 * (WL_CYC_DEL*cycle).  When SW write-leveling is enabled (i.e SW_WL_EN = 1) then this value
 * will be taken as is and will be added to the associated delay that
 * is configured in WL_DL_OFFSET and WL_CYC_DEL. When HW write-leveling
 * is enabled (i.e HW_WL_EN = 1 ) then this value will indicate
 * (status) whether a delay of half cycle was added or not to the
 * associated WL_DL_OFFSET and WL_CYC_DEL.
 */

#define BP_MMDC_MPWLDECTRL1_WL_HC_DEL2      8
#define BM_MMDC_MPWLDECTRL1_WL_HC_DEL2      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLDECTRL1_WL_HC_DEL2(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPWLDECTRL1_WL_HC_DEL2)
#else
#define BF_MMDC_MPWLDECTRL1_WL_HC_DEL2(v)   (((v) << 8) & BM_MMDC_MPWLDECTRL1_WL_HC_DEL2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLDECTRL1_WL_HC_DEL2(v)   BF_CS1(MMDC_MPWLDECTRL1, WL_HC_DEL2, v)
#endif

/* --- Register HW_MMDC_MPWLDECTRL1, field WL_CYC_DEL2
 *
 * Write leveling cycle delay for Byte 2. This field indicates whether a
 * delay of 1 or 2 cycles between CK and write DQS is added to the
 * delay that is indicated in the associated WR_DL_ABS_OFFSET and
 * WL_HC_DEL. So the total delay is the sum of
 * (WL_DL_ABS_OFFSET/256*cycle) + (WL_HC_DEL*half cycle) +
 * (WL_CYC_DEL*cycle).  When both SW write-leveling is enabled (i.e SW_WL_EN = 1) or HW
 * write-leveling is enabled (i.e HW_WL_EN = 1 ) then this value will
 * be taken as is and will be added to the associated delay that is
 * configured in WL_DL_OFFSET and WL_HC_DEL.  Note that in HW write-leveling this field is not used
 * for indication,                                 as in WL_DL_OFFSET and WL_HC_DEL, but for
 * configuration.
 */

#define BP_MMDC_MPWLDECTRL1_WL_CYC_DEL2      9
#define BM_MMDC_MPWLDECTRL1_WL_CYC_DEL2      0x00000600

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLDECTRL1_WL_CYC_DEL2(v)   ((((reg32_t) v) << 9) & BM_MMDC_MPWLDECTRL1_WL_CYC_DEL2)
#else
#define BF_MMDC_MPWLDECTRL1_WL_CYC_DEL2(v)   (((v) << 9) & BM_MMDC_MPWLDECTRL1_WL_CYC_DEL2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLDECTRL1_WL_CYC_DEL2(v)   BF_CS1(MMDC_MPWLDECTRL1, WL_CYC_DEL2, v)
#endif

/* --- Register HW_MMDC_MPWLDECTRL1, field WL_DL_ABS_OFFSET3
 *
 * Absolute write-leveling delay offset for Byte 3. This field indicates
 * the absolute delay between CK and write DQS of Byte3 with fractions
 * of a clock period and up to half cycle. This value is process and
 * frequency independent. The value of the delay can be calculated
 * using the following equation (WL_DL_ABS_OFFSET3 / 256) * clock
 * period  When SW write-leveling is enabled (i.e SW_WL_EN = 1) then this value
 * will be taken as is to the associated delay-line. When HW                                 write-
 * leveling is enabled (i.e HW_WL_EN = 1 ) then this value will
 * indicate (status) the value that is taken to the associated
 * delay-line at the end of the write-leveling calibration.  The delay-line has a resolution that
 * may vary between device to                                 device, therefore is some cases an
 * increment of the delay by 1 step                                 may be smaller than the delay-
 * line resolution.
 */

#define BP_MMDC_MPWLDECTRL1_WL_DL_ABS_OFFSET3      16
#define BM_MMDC_MPWLDECTRL1_WL_DL_ABS_OFFSET3      0x007f0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLDECTRL1_WL_DL_ABS_OFFSET3(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPWLDECTRL1_WL_DL_ABS_OFFSET3)
#else
#define BF_MMDC_MPWLDECTRL1_WL_DL_ABS_OFFSET3(v)   (((v) << 16) & BM_MMDC_MPWLDECTRL1_WL_DL_ABS_OFFSET3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLDECTRL1_WL_DL_ABS_OFFSET3(v)   BF_CS1(MMDC_MPWLDECTRL1, WL_DL_ABS_OFFSET3, v)
#endif

/* --- Register HW_MMDC_MPWLDECTRL1, field WL_HC_DEL3
 *
 * Write leveling half cycle delay for Byte 3. This field indicates
 * whether a delay of half cycle between CK and write DQS is added to
 * the delay that is indicated in the associated WL_DL_ABS_OFFSET and
 * WL_CYC_DEL. So the total delay is the sum of
 * (WL_DL_ABS_OFFSET/256*cycle) + (WL_HC_DEL*half cycle) +
 * (WL_CYC_DEL*cycle).  When SW write-leveling is enabled (i.e SW_WL_EN = 1) then this value
 * will be taken as is and will be added to the associated delay that
 * is configured in WL_DL_OFFSET and WL_CYC_DEL. When HW write-leveling
 * is enabled (i.e HW_WL_EN = 1 ) then this value will indicate
 * (status) whether a delay of half cycle was added or not to the
 * associated WL_DL_OFFSET and WL_CYC_DEL.
 */

#define BP_MMDC_MPWLDECTRL1_WL_HC_DEL3      24
#define BM_MMDC_MPWLDECTRL1_WL_HC_DEL3      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLDECTRL1_WL_HC_DEL3(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPWLDECTRL1_WL_HC_DEL3)
#else
#define BF_MMDC_MPWLDECTRL1_WL_HC_DEL3(v)   (((v) << 24) & BM_MMDC_MPWLDECTRL1_WL_HC_DEL3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLDECTRL1_WL_HC_DEL3(v)   BF_CS1(MMDC_MPWLDECTRL1, WL_HC_DEL3, v)
#endif

/* --- Register HW_MMDC_MPWLDECTRL1, field WL_CYC_DEL3
 *
 * Write leveling cycle delay for Byte 3. This field indicates whether a
 * delay of 1 or 2 cycles between CK and write DQS is added to the
 * delay that is indicated in the associated WL_DL_ABS_OFFSET and
 * WL_HC_DEL. So the total delay is the sum of
 * (WL_DL_ABS_OFFSET/256*cycle) + (WL_HC_DEL*half cycle) +
 * (WL_CYC_DEL*cycle).  When both SW write-leveling is enabled (i.e SW_WL_EN = 1) or HW
 * write-leveling is enabled (i.e HW_WL_EN = 1 ) then this value will
 * be taken as is and will be added to the associated delay that is
 * configured in WL_DL_OFFSET and WL_HC_DEL.  Note that in HW write-leveling this field is not used
 * for indication,                                 as in WL_DL_OFFSET and WL_HC_DEL, but for
 * configuration.
 */

#define BP_MMDC_MPWLDECTRL1_WL_CYC_DEL3      25
#define BM_MMDC_MPWLDECTRL1_WL_CYC_DEL3      0x06000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLDECTRL1_WL_CYC_DEL3(v)   ((((reg32_t) v) << 25) & BM_MMDC_MPWLDECTRL1_WL_CYC_DEL3)
#else
#define BF_MMDC_MPWLDECTRL1_WL_CYC_DEL3(v)   (((v) << 25) & BM_MMDC_MPWLDECTRL1_WL_CYC_DEL3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLDECTRL1_WL_CYC_DEL3(v)   BF_CS1(MMDC_MPWLDECTRL1, WL_CYC_DEL3, v)
#endif

/*!
 * @brief HW_MMDC_MPWLDLST - MMDC PHY Write Leveling delay-line Status                        Register
 *
 * This register holds the status of the four write leveling delay-lines.  Supported Mode Of
 * Operations:  For Channel 0: All  For Channel 1: DDR3_x64, LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WL_DL_UNIT_NUM0 : 7; //!< This field reflects the number of delay units that are actually used by write leveling delay-line 0.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned WL_DL_UNIT_NUM1 : 7; //!< This field reflects the number of delay units that are actually used by write leveling delay-line 1.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned WL_DL_UNIT_NUM2 : 7; //!< This field reflects the number of delay units that are actually used by write leveling delay-line 2.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned WL_DL_UNIT_NUM3 : 7; //!< This field reflects the number of delay units that are actually used by write leveling delay-line 3.
        unsigned RESERVED3 : 1; //!< Reserved
    } B;
} hw_mmdc_mpwldlst_t;
#endif

/*
 * constants & macros for entire MMDC_MPWLDLST register
 */
#define HW_MMDC_MPWLDLST_ADDR      (REGS_MMDC_BASE + 0x814)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPWLDLST           (*(volatile hw_mmdc_mpwldlst_t *) HW_MMDC_MPWLDLST_ADDR)
#define HW_MMDC_MPWLDLST_RD()      (HW_MMDC_MPWLDLST.U)
#define HW_MMDC_MPWLDLST_WR(v)     (HW_MMDC_MPWLDLST.U = (v))
#define HW_MMDC_MPWLDLST_SET(v)    (HW_MMDC_MPWLDLST_WR(HW_MMDC_MPWLDLST_RD() |  (v)))
#define HW_MMDC_MPWLDLST_CLR(v)    (HW_MMDC_MPWLDLST_WR(HW_MMDC_MPWLDLST_RD() & ~(v)))
#define HW_MMDC_MPWLDLST_TOG(v)    (HW_MMDC_MPWLDLST_WR(HW_MMDC_MPWLDLST_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPWLDLST bitfields
 */

/* --- Register HW_MMDC_MPWLDLST, field WL_DL_UNIT_NUM0
 *
 * This field reflects the number of delay units that are actually used
 * by write leveling delay-line 0.
 */

#define BP_MMDC_MPWLDLST_WL_DL_UNIT_NUM0      0
#define BM_MMDC_MPWLDLST_WL_DL_UNIT_NUM0      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLDLST_WL_DL_UNIT_NUM0(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPWLDLST_WL_DL_UNIT_NUM0)
#else
#define BF_MMDC_MPWLDLST_WL_DL_UNIT_NUM0(v)   (((v) << 0) & BM_MMDC_MPWLDLST_WL_DL_UNIT_NUM0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLDLST_WL_DL_UNIT_NUM0(v)   BF_CS1(MMDC_MPWLDLST, WL_DL_UNIT_NUM0, v)
#endif

/* --- Register HW_MMDC_MPWLDLST, field WL_DL_UNIT_NUM1
 *
 * This field reflects the number of delay units that are actually used
 * by write leveling delay-line 1.
 */

#define BP_MMDC_MPWLDLST_WL_DL_UNIT_NUM1      8
#define BM_MMDC_MPWLDLST_WL_DL_UNIT_NUM1      0x00007f00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLDLST_WL_DL_UNIT_NUM1(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPWLDLST_WL_DL_UNIT_NUM1)
#else
#define BF_MMDC_MPWLDLST_WL_DL_UNIT_NUM1(v)   (((v) << 8) & BM_MMDC_MPWLDLST_WL_DL_UNIT_NUM1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLDLST_WL_DL_UNIT_NUM1(v)   BF_CS1(MMDC_MPWLDLST, WL_DL_UNIT_NUM1, v)
#endif

/* --- Register HW_MMDC_MPWLDLST, field WL_DL_UNIT_NUM2
 *
 * This field reflects the number of delay units that are actually used
 * by write leveling delay-line 2.
 */

#define BP_MMDC_MPWLDLST_WL_DL_UNIT_NUM2      16
#define BM_MMDC_MPWLDLST_WL_DL_UNIT_NUM2      0x007f0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLDLST_WL_DL_UNIT_NUM2(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPWLDLST_WL_DL_UNIT_NUM2)
#else
#define BF_MMDC_MPWLDLST_WL_DL_UNIT_NUM2(v)   (((v) << 16) & BM_MMDC_MPWLDLST_WL_DL_UNIT_NUM2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLDLST_WL_DL_UNIT_NUM2(v)   BF_CS1(MMDC_MPWLDLST, WL_DL_UNIT_NUM2, v)
#endif

/* --- Register HW_MMDC_MPWLDLST, field WL_DL_UNIT_NUM3
 *
 * This field reflects the number of delay units that are actually used
 * by write leveling delay-line 3.
 */

#define BP_MMDC_MPWLDLST_WL_DL_UNIT_NUM3      24
#define BM_MMDC_MPWLDLST_WL_DL_UNIT_NUM3      0x7f000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLDLST_WL_DL_UNIT_NUM3(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPWLDLST_WL_DL_UNIT_NUM3)
#else
#define BF_MMDC_MPWLDLST_WL_DL_UNIT_NUM3(v)   (((v) << 24) & BM_MMDC_MPWLDLST_WL_DL_UNIT_NUM3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLDLST_WL_DL_UNIT_NUM3(v)   BF_CS1(MMDC_MPWLDLST, WL_DL_UNIT_NUM3, v)
#endif

/*!
 * @brief HW_MMDC_MPODTCTRL - MMDC PHY ODT control register
 *
 * In LPDDR2 mode this register should be cleared, so no termination will
 * be activated  Supported Mode Of Operations:  For Channel 0: DDR3_x16, DDR3_x32, DDR3_x64  For
 * Channel 1: DDR3_x64
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ODT_WR_PAS_EN : 1; //!< Inactive write CS ODT enable. The bit determines if ODT pin of the inactive CS will be asserted during write accesses.
        unsigned ODT_WR_ACT_EN : 1; //!< Active write CS ODT enable. The bit determines if ODT pin of the active CS will be asserted during write accesses.
        unsigned ODT_RD_PAS_EN : 1; //!< Inactive read CS ODT enable. The bit determines if ODT pin of the inactive CS will be asserted during read accesses.
        unsigned ODT_RD_ACT_EN : 1; //!< Active read CS ODT enable. The bit determines if ODT pin of the active CS will be asserted during read accesses.
        unsigned ODT0_INT_RES : 3; //!< On chip ODT byte0 resistor - This field determines the Rtt_Nom of the on chip ODT byte0 resistor during read accesses.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned ODT1_INT_RES : 3; //!< On chip ODT byte1 resistor - This field determines the Rtt_Nom of the on chip ODT byte1 resistor during read accesses.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned ODT2_INT_RES : 3; //!< On chip ODT byte2 resistor - This field determines the Rtt_Nom of the on chip ODT byte2 resistor during read accesses.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned ODT3_INT_RES : 3; //!< On chip ODT byte3 resistor - This field determines the Rtt_Nom of the on chip ODT byte3 resistor during read accesses.
        unsigned RESERVED3 : 13; //!< Reserved
    } B;
} hw_mmdc_mpodtctrl_t;
#endif

/*
 * constants & macros for entire MMDC_MPODTCTRL register
 */
#define HW_MMDC_MPODTCTRL_ADDR      (REGS_MMDC_BASE + 0x818)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPODTCTRL           (*(volatile hw_mmdc_mpodtctrl_t *) HW_MMDC_MPODTCTRL_ADDR)
#define HW_MMDC_MPODTCTRL_RD()      (HW_MMDC_MPODTCTRL.U)
#define HW_MMDC_MPODTCTRL_WR(v)     (HW_MMDC_MPODTCTRL.U = (v))
#define HW_MMDC_MPODTCTRL_SET(v)    (HW_MMDC_MPODTCTRL_WR(HW_MMDC_MPODTCTRL_RD() |  (v)))
#define HW_MMDC_MPODTCTRL_CLR(v)    (HW_MMDC_MPODTCTRL_WR(HW_MMDC_MPODTCTRL_RD() & ~(v)))
#define HW_MMDC_MPODTCTRL_TOG(v)    (HW_MMDC_MPODTCTRL_WR(HW_MMDC_MPODTCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPODTCTRL bitfields
 */

/* --- Register HW_MMDC_MPODTCTRL, field ODT_WR_PAS_EN
 *
 * Inactive write CS ODT enable. The bit determines if ODT pin of the
 * inactive CS will be asserted during write accesses.
 */

#define BP_MMDC_MPODTCTRL_ODT_WR_PAS_EN      0
#define BM_MMDC_MPODTCTRL_ODT_WR_PAS_EN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPODTCTRL_ODT_WR_PAS_EN(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPODTCTRL_ODT_WR_PAS_EN)
#else
#define BF_MMDC_MPODTCTRL_ODT_WR_PAS_EN(v)   (((v) << 0) & BM_MMDC_MPODTCTRL_ODT_WR_PAS_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPODTCTRL_ODT_WR_PAS_EN(v)   BF_CS1(MMDC_MPODTCTRL, ODT_WR_PAS_EN, v)
#endif

/* --- Register HW_MMDC_MPODTCTRL, field ODT_WR_ACT_EN
 *
 * Active write CS ODT enable. The bit determines if ODT pin of the
 * active CS will be asserted during write accesses.
 */

#define BP_MMDC_MPODTCTRL_ODT_WR_ACT_EN      1
#define BM_MMDC_MPODTCTRL_ODT_WR_ACT_EN      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPODTCTRL_ODT_WR_ACT_EN(v)   ((((reg32_t) v) << 1) & BM_MMDC_MPODTCTRL_ODT_WR_ACT_EN)
#else
#define BF_MMDC_MPODTCTRL_ODT_WR_ACT_EN(v)   (((v) << 1) & BM_MMDC_MPODTCTRL_ODT_WR_ACT_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPODTCTRL_ODT_WR_ACT_EN(v)   BF_CS1(MMDC_MPODTCTRL, ODT_WR_ACT_EN, v)
#endif

/* --- Register HW_MMDC_MPODTCTRL, field ODT_RD_PAS_EN
 *
 * Inactive read CS ODT enable. The bit determines if ODT pin of the
 * inactive CS will be asserted during read accesses.
 */

#define BP_MMDC_MPODTCTRL_ODT_RD_PAS_EN      2
#define BM_MMDC_MPODTCTRL_ODT_RD_PAS_EN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPODTCTRL_ODT_RD_PAS_EN(v)   ((((reg32_t) v) << 2) & BM_MMDC_MPODTCTRL_ODT_RD_PAS_EN)
#else
#define BF_MMDC_MPODTCTRL_ODT_RD_PAS_EN(v)   (((v) << 2) & BM_MMDC_MPODTCTRL_ODT_RD_PAS_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPODTCTRL_ODT_RD_PAS_EN(v)   BF_CS1(MMDC_MPODTCTRL, ODT_RD_PAS_EN, v)
#endif

/* --- Register HW_MMDC_MPODTCTRL, field ODT_RD_ACT_EN
 *
 * Active read CS ODT enable. The bit determines if ODT pin of the
 * active CS will be asserted during read accesses.
 */

#define BP_MMDC_MPODTCTRL_ODT_RD_ACT_EN      3
#define BM_MMDC_MPODTCTRL_ODT_RD_ACT_EN      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPODTCTRL_ODT_RD_ACT_EN(v)   ((((reg32_t) v) << 3) & BM_MMDC_MPODTCTRL_ODT_RD_ACT_EN)
#else
#define BF_MMDC_MPODTCTRL_ODT_RD_ACT_EN(v)   (((v) << 3) & BM_MMDC_MPODTCTRL_ODT_RD_ACT_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPODTCTRL_ODT_RD_ACT_EN(v)   BF_CS1(MMDC_MPODTCTRL, ODT_RD_ACT_EN, v)
#endif

/* --- Register HW_MMDC_MPODTCTRL, field ODT0_INT_RES
 *
 * On chip ODT byte0 resistor - This field determines the Rtt_Nom of the
 * on chip ODT byte0 resistor during read accesses.
 */

#define BP_MMDC_MPODTCTRL_ODT0_INT_RES      4
#define BM_MMDC_MPODTCTRL_ODT0_INT_RES      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPODTCTRL_ODT0_INT_RES(v)   ((((reg32_t) v) << 4) & BM_MMDC_MPODTCTRL_ODT0_INT_RES)
#else
#define BF_MMDC_MPODTCTRL_ODT0_INT_RES(v)   (((v) << 4) & BM_MMDC_MPODTCTRL_ODT0_INT_RES)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPODTCTRL_ODT0_INT_RES(v)   BF_CS1(MMDC_MPODTCTRL, ODT0_INT_RES, v)
#endif

/* --- Register HW_MMDC_MPODTCTRL, field ODT1_INT_RES
 *
 * On chip ODT byte1 resistor - This field determines the Rtt_Nom of the
 * on chip ODT byte1 resistor during read accesses.
 */

#define BP_MMDC_MPODTCTRL_ODT1_INT_RES      8
#define BM_MMDC_MPODTCTRL_ODT1_INT_RES      0x00000700

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPODTCTRL_ODT1_INT_RES(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPODTCTRL_ODT1_INT_RES)
#else
#define BF_MMDC_MPODTCTRL_ODT1_INT_RES(v)   (((v) << 8) & BM_MMDC_MPODTCTRL_ODT1_INT_RES)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPODTCTRL_ODT1_INT_RES(v)   BF_CS1(MMDC_MPODTCTRL, ODT1_INT_RES, v)
#endif

/* --- Register HW_MMDC_MPODTCTRL, field ODT2_INT_RES
 *
 * On chip ODT byte2 resistor - This field determines the Rtt_Nom of the
 * on chip ODT byte2 resistor during read accesses.
 */

#define BP_MMDC_MPODTCTRL_ODT2_INT_RES      12
#define BM_MMDC_MPODTCTRL_ODT2_INT_RES      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPODTCTRL_ODT2_INT_RES(v)   ((((reg32_t) v) << 12) & BM_MMDC_MPODTCTRL_ODT2_INT_RES)
#else
#define BF_MMDC_MPODTCTRL_ODT2_INT_RES(v)   (((v) << 12) & BM_MMDC_MPODTCTRL_ODT2_INT_RES)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPODTCTRL_ODT2_INT_RES(v)   BF_CS1(MMDC_MPODTCTRL, ODT2_INT_RES, v)
#endif

/* --- Register HW_MMDC_MPODTCTRL, field ODT3_INT_RES
 *
 * On chip ODT byte3 resistor - This field determines the Rtt_Nom of the
 * on chip ODT byte3 resistor during read accesses.
 */

#define BP_MMDC_MPODTCTRL_ODT3_INT_RES      16
#define BM_MMDC_MPODTCTRL_ODT3_INT_RES      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPODTCTRL_ODT3_INT_RES(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPODTCTRL_ODT3_INT_RES)
#else
#define BF_MMDC_MPODTCTRL_ODT3_INT_RES(v)   (((v) << 16) & BM_MMDC_MPODTCTRL_ODT3_INT_RES)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPODTCTRL_ODT3_INT_RES(v)   BF_CS1(MMDC_MPODTCTRL, ODT3_INT_RES, v)
#endif

/*!
 * @brief HW_MMDC_MPRDDQBY0DL - MMDC PHY Read DQ Byte0 Delay Register
 *
 * This register is used to add fine-tuning adjustment to every bit in the
 * read DQ byte0 relative to the read DQS. This delay is in addition to the read data calibration.
 * If operating in 64-bit mode, there is an identical register that is mapped at the second base
 * address.  Supported Mode Of Operations:  For Channel 0: All  For Channel 1: DDR3_x64,
 * LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RD_DQ0_DEL : 3; //!< Read dqs0 to dq0 delay fine-tuning. This field holds the number of delay units that are added to dq0 relative to dqs0.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned RD_DQ1_DEL : 3; //!< Read dqs0 to dq1 delay fine-tuning. This field holds the number of delay units that are added to dq1 relative to dqs0.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned RD_DQ2_DEL : 3; //!< Read dqs0 to dq2 delay fine-tuning. This field holds the number of delay units that are added to dq2 relative to dqs0.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned RD_DQ3_DEL : 3; //!< Read dqs0 to dq3 delay fine-tuning. This field holds the number of delay units that are added to dq3 relative to dqs0.
        unsigned RESERVED3 : 1; //!< Reserved
        unsigned RD_DQ4_DEL : 3; //!< Read dqs0 to dq4 delay fine-tuning. This field holds the number of delay units that are added to dq4 relative to dqs0.
        unsigned RESERVED4 : 1; //!< Reserved
        unsigned RD_DQ5_DEL : 3; //!< Read dqs0 to dq5 delay fine-tuning. This field holds the number of delay units that are added to dq5 relative to dqs0.
        unsigned RESERVED5 : 1; //!< Reserved
        unsigned RD_DQ6_DEL : 3; //!< Read dqs0 to dq6 delay fine-tuning. This field holds the number of delay units that are added to dq6 relative to dqs0.
        unsigned RESERVED6 : 1; //!< Reserved
        unsigned RD_DQ7_DEL : 3; //!< Read dqs0 to dq7 delay fine-tuning. This field holds the number of delay units that are added to dq7 relative to dqs0.
        unsigned RESERVED7 : 1; //!< Reserved
    } B;
} hw_mmdc_mprddqby0dl_t;
#endif

/*
 * constants & macros for entire MMDC_MPRDDQBY0DL register
 */
#define HW_MMDC_MPRDDQBY0DL_ADDR      (REGS_MMDC_BASE + 0x81c)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPRDDQBY0DL           (*(volatile hw_mmdc_mprddqby0dl_t *) HW_MMDC_MPRDDQBY0DL_ADDR)
#define HW_MMDC_MPRDDQBY0DL_RD()      (HW_MMDC_MPRDDQBY0DL.U)
#define HW_MMDC_MPRDDQBY0DL_WR(v)     (HW_MMDC_MPRDDQBY0DL.U = (v))
#define HW_MMDC_MPRDDQBY0DL_SET(v)    (HW_MMDC_MPRDDQBY0DL_WR(HW_MMDC_MPRDDQBY0DL_RD() |  (v)))
#define HW_MMDC_MPRDDQBY0DL_CLR(v)    (HW_MMDC_MPRDDQBY0DL_WR(HW_MMDC_MPRDDQBY0DL_RD() & ~(v)))
#define HW_MMDC_MPRDDQBY0DL_TOG(v)    (HW_MMDC_MPRDDQBY0DL_WR(HW_MMDC_MPRDDQBY0DL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPRDDQBY0DL bitfields
 */

/* --- Register HW_MMDC_MPRDDQBY0DL, field RD_DQ0_DEL
 *
 * Read dqs0 to dq0 delay fine-tuning. This field holds the number of
 * delay units that are added to dq0 relative to dqs0.
 */

#define BP_MMDC_MPRDDQBY0DL_RD_DQ0_DEL      0
#define BM_MMDC_MPRDDQBY0DL_RD_DQ0_DEL      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY0DL_RD_DQ0_DEL(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPRDDQBY0DL_RD_DQ0_DEL)
#else
#define BF_MMDC_MPRDDQBY0DL_RD_DQ0_DEL(v)   (((v) << 0) & BM_MMDC_MPRDDQBY0DL_RD_DQ0_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY0DL_RD_DQ0_DEL(v)   BF_CS1(MMDC_MPRDDQBY0DL, RD_DQ0_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY0DL, field RD_DQ1_DEL
 *
 * Read dqs0 to dq1 delay fine-tuning. This field holds the number of
 * delay units that are added to dq1 relative to dqs0.
 */

#define BP_MMDC_MPRDDQBY0DL_RD_DQ1_DEL      4
#define BM_MMDC_MPRDDQBY0DL_RD_DQ1_DEL      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY0DL_RD_DQ1_DEL(v)   ((((reg32_t) v) << 4) & BM_MMDC_MPRDDQBY0DL_RD_DQ1_DEL)
#else
#define BF_MMDC_MPRDDQBY0DL_RD_DQ1_DEL(v)   (((v) << 4) & BM_MMDC_MPRDDQBY0DL_RD_DQ1_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY0DL_RD_DQ1_DEL(v)   BF_CS1(MMDC_MPRDDQBY0DL, RD_DQ1_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY0DL, field RD_DQ2_DEL
 *
 * Read dqs0 to dq2 delay fine-tuning. This field holds the number of
 * delay units that are added to dq2 relative to dqs0.
 */

#define BP_MMDC_MPRDDQBY0DL_RD_DQ2_DEL      8
#define BM_MMDC_MPRDDQBY0DL_RD_DQ2_DEL      0x00000700

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY0DL_RD_DQ2_DEL(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPRDDQBY0DL_RD_DQ2_DEL)
#else
#define BF_MMDC_MPRDDQBY0DL_RD_DQ2_DEL(v)   (((v) << 8) & BM_MMDC_MPRDDQBY0DL_RD_DQ2_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY0DL_RD_DQ2_DEL(v)   BF_CS1(MMDC_MPRDDQBY0DL, RD_DQ2_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY0DL, field RD_DQ3_DEL
 *
 * Read dqs0 to dq3 delay fine-tuning. This field holds the number of
 * delay units that are added to dq3 relative to dqs0.
 */

#define BP_MMDC_MPRDDQBY0DL_RD_DQ3_DEL      12
#define BM_MMDC_MPRDDQBY0DL_RD_DQ3_DEL      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY0DL_RD_DQ3_DEL(v)   ((((reg32_t) v) << 12) & BM_MMDC_MPRDDQBY0DL_RD_DQ3_DEL)
#else
#define BF_MMDC_MPRDDQBY0DL_RD_DQ3_DEL(v)   (((v) << 12) & BM_MMDC_MPRDDQBY0DL_RD_DQ3_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY0DL_RD_DQ3_DEL(v)   BF_CS1(MMDC_MPRDDQBY0DL, RD_DQ3_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY0DL, field RD_DQ4_DEL
 *
 * Read dqs0 to dq4 delay fine-tuning. This field holds the number of
 * delay units that are added to dq4 relative to dqs0.
 */

#define BP_MMDC_MPRDDQBY0DL_RD_DQ4_DEL      16
#define BM_MMDC_MPRDDQBY0DL_RD_DQ4_DEL      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY0DL_RD_DQ4_DEL(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPRDDQBY0DL_RD_DQ4_DEL)
#else
#define BF_MMDC_MPRDDQBY0DL_RD_DQ4_DEL(v)   (((v) << 16) & BM_MMDC_MPRDDQBY0DL_RD_DQ4_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY0DL_RD_DQ4_DEL(v)   BF_CS1(MMDC_MPRDDQBY0DL, RD_DQ4_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY0DL, field RD_DQ5_DEL
 *
 * Read dqs0 to dq5 delay fine-tuning. This field holds the number of
 * delay units that are added to dq5 relative to dqs0.
 */

#define BP_MMDC_MPRDDQBY0DL_RD_DQ5_DEL      20
#define BM_MMDC_MPRDDQBY0DL_RD_DQ5_DEL      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY0DL_RD_DQ5_DEL(v)   ((((reg32_t) v) << 20) & BM_MMDC_MPRDDQBY0DL_RD_DQ5_DEL)
#else
#define BF_MMDC_MPRDDQBY0DL_RD_DQ5_DEL(v)   (((v) << 20) & BM_MMDC_MPRDDQBY0DL_RD_DQ5_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY0DL_RD_DQ5_DEL(v)   BF_CS1(MMDC_MPRDDQBY0DL, RD_DQ5_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY0DL, field RD_DQ6_DEL
 *
 * Read dqs0 to dq6 delay fine-tuning. This field holds the number of
 * delay units that are added to dq6 relative to dqs0.
 */

#define BP_MMDC_MPRDDQBY0DL_RD_DQ6_DEL      24
#define BM_MMDC_MPRDDQBY0DL_RD_DQ6_DEL      0x07000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY0DL_RD_DQ6_DEL(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPRDDQBY0DL_RD_DQ6_DEL)
#else
#define BF_MMDC_MPRDDQBY0DL_RD_DQ6_DEL(v)   (((v) << 24) & BM_MMDC_MPRDDQBY0DL_RD_DQ6_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY0DL_RD_DQ6_DEL(v)   BF_CS1(MMDC_MPRDDQBY0DL, RD_DQ6_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY0DL, field RD_DQ7_DEL
 *
 * Read dqs0 to dq7 delay fine-tuning. This field holds the number of
 * delay units that are added to dq7 relative to dqs0.
 */

#define BP_MMDC_MPRDDQBY0DL_RD_DQ7_DEL      28
#define BM_MMDC_MPRDDQBY0DL_RD_DQ7_DEL      0x70000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY0DL_RD_DQ7_DEL(v)   ((((reg32_t) v) << 28) & BM_MMDC_MPRDDQBY0DL_RD_DQ7_DEL)
#else
#define BF_MMDC_MPRDDQBY0DL_RD_DQ7_DEL(v)   (((v) << 28) & BM_MMDC_MPRDDQBY0DL_RD_DQ7_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY0DL_RD_DQ7_DEL(v)   BF_CS1(MMDC_MPRDDQBY0DL, RD_DQ7_DEL, v)
#endif

/*!
 * @brief HW_MMDC_MPRDDQBY1DL - MMDC PHY Read DQ Byte1 Delay Register
 *
 * This register is used to add fine-tuning adjustment to every bit in the
 * read DQ byte1 relative to the read DQS  Supported Mode Of Operations:  FOr Channel 0: All  For
 * Channel 1: DDR3_x64, LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RD_DQ8_DEL : 3; //!< Read dqs1 to dq8 delay fine-tuning. This field holds the number of delay units that are added to dq8 relative to dqs1.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned RD_DQ9_DEL : 3; //!< Read dqs1 to dq9 delay fine-tuning. This field holds the number of delay units that are added to dq9 relative to dqs1.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned RD_DQ10_DEL : 3; //!< Read dqs1 to dq10 delay fine-tuning. This field holds the number of delay units that are added to dq10 relative to dqs1.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned RD_DQ11_DEL : 3; //!< Read dqs1 to dq11 delay fine-tuning. This field holds the number of delay units that are added to dq11 relative to dqs1.
        unsigned RESERVED3 : 1; //!< Reserved
        unsigned RD_DQ12_DEL : 3; //!< Read dqs1 to dq12 delay fine-tuning. This field holds the number of delay units that are added to dq12 relative to dqs1.
        unsigned RESERVED4 : 1; //!< Reserved
        unsigned RD_DQ13_DEL : 3; //!< Read dqs1 to dq13 delay fine-tuning. This field holds the number of delay units that are added to dq13 relative to dqs1.
        unsigned RESERVED5 : 1; //!< Reserved
        unsigned RD_DQ14_DEL : 3; //!< Read dqs1 to dq14 delay fine-tuning. This field holds the number of delay units that are added to dq14 relative to dqs1.
        unsigned RESERVED6 : 1; //!< Reserved
        unsigned RD_DQ15_DEL : 3; //!< Read dqs1 to dq15 delay fine-tuning. This field holds the number of delay units that are added to dq15 relative to dqs1.
        unsigned RESERVED7 : 1; //!< Reserved
    } B;
} hw_mmdc_mprddqby1dl_t;
#endif

/*
 * constants & macros for entire MMDC_MPRDDQBY1DL register
 */
#define HW_MMDC_MPRDDQBY1DL_ADDR      (REGS_MMDC_BASE + 0x820)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPRDDQBY1DL           (*(volatile hw_mmdc_mprddqby1dl_t *) HW_MMDC_MPRDDQBY1DL_ADDR)
#define HW_MMDC_MPRDDQBY1DL_RD()      (HW_MMDC_MPRDDQBY1DL.U)
#define HW_MMDC_MPRDDQBY1DL_WR(v)     (HW_MMDC_MPRDDQBY1DL.U = (v))
#define HW_MMDC_MPRDDQBY1DL_SET(v)    (HW_MMDC_MPRDDQBY1DL_WR(HW_MMDC_MPRDDQBY1DL_RD() |  (v)))
#define HW_MMDC_MPRDDQBY1DL_CLR(v)    (HW_MMDC_MPRDDQBY1DL_WR(HW_MMDC_MPRDDQBY1DL_RD() & ~(v)))
#define HW_MMDC_MPRDDQBY1DL_TOG(v)    (HW_MMDC_MPRDDQBY1DL_WR(HW_MMDC_MPRDDQBY1DL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPRDDQBY1DL bitfields
 */

/* --- Register HW_MMDC_MPRDDQBY1DL, field RD_DQ8_DEL
 *
 * Read dqs1 to dq8 delay fine-tuning. This field holds the number of
 * delay units that are added to dq8 relative to dqs1.
 */

#define BP_MMDC_MPRDDQBY1DL_RD_DQ8_DEL      0
#define BM_MMDC_MPRDDQBY1DL_RD_DQ8_DEL      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY1DL_RD_DQ8_DEL(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPRDDQBY1DL_RD_DQ8_DEL)
#else
#define BF_MMDC_MPRDDQBY1DL_RD_DQ8_DEL(v)   (((v) << 0) & BM_MMDC_MPRDDQBY1DL_RD_DQ8_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY1DL_RD_DQ8_DEL(v)   BF_CS1(MMDC_MPRDDQBY1DL, RD_DQ8_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY1DL, field RD_DQ9_DEL
 *
 * Read dqs1 to dq9 delay fine-tuning. This field holds the number of
 * delay units that are added to dq9 relative to dqs1.
 */

#define BP_MMDC_MPRDDQBY1DL_RD_DQ9_DEL      4
#define BM_MMDC_MPRDDQBY1DL_RD_DQ9_DEL      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY1DL_RD_DQ9_DEL(v)   ((((reg32_t) v) << 4) & BM_MMDC_MPRDDQBY1DL_RD_DQ9_DEL)
#else
#define BF_MMDC_MPRDDQBY1DL_RD_DQ9_DEL(v)   (((v) << 4) & BM_MMDC_MPRDDQBY1DL_RD_DQ9_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY1DL_RD_DQ9_DEL(v)   BF_CS1(MMDC_MPRDDQBY1DL, RD_DQ9_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY1DL, field RD_DQ10_DEL
 *
 * Read dqs1 to dq10 delay fine-tuning. This field holds the number of
 * delay units that are added to dq10 relative to dqs1.
 */

#define BP_MMDC_MPRDDQBY1DL_RD_DQ10_DEL      8
#define BM_MMDC_MPRDDQBY1DL_RD_DQ10_DEL      0x00000700

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY1DL_RD_DQ10_DEL(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPRDDQBY1DL_RD_DQ10_DEL)
#else
#define BF_MMDC_MPRDDQBY1DL_RD_DQ10_DEL(v)   (((v) << 8) & BM_MMDC_MPRDDQBY1DL_RD_DQ10_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY1DL_RD_DQ10_DEL(v)   BF_CS1(MMDC_MPRDDQBY1DL, RD_DQ10_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY1DL, field RD_DQ11_DEL
 *
 * Read dqs1 to dq11 delay fine-tuning. This field holds the number of
 * delay units that are added to dq11 relative to dqs1.
 */

#define BP_MMDC_MPRDDQBY1DL_RD_DQ11_DEL      12
#define BM_MMDC_MPRDDQBY1DL_RD_DQ11_DEL      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY1DL_RD_DQ11_DEL(v)   ((((reg32_t) v) << 12) & BM_MMDC_MPRDDQBY1DL_RD_DQ11_DEL)
#else
#define BF_MMDC_MPRDDQBY1DL_RD_DQ11_DEL(v)   (((v) << 12) & BM_MMDC_MPRDDQBY1DL_RD_DQ11_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY1DL_RD_DQ11_DEL(v)   BF_CS1(MMDC_MPRDDQBY1DL, RD_DQ11_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY1DL, field RD_DQ12_DEL
 *
 * Read dqs1 to dq12 delay fine-tuning. This field holds the number of
 * delay units that are added to dq12 relative to dqs1.
 */

#define BP_MMDC_MPRDDQBY1DL_RD_DQ12_DEL      16
#define BM_MMDC_MPRDDQBY1DL_RD_DQ12_DEL      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY1DL_RD_DQ12_DEL(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPRDDQBY1DL_RD_DQ12_DEL)
#else
#define BF_MMDC_MPRDDQBY1DL_RD_DQ12_DEL(v)   (((v) << 16) & BM_MMDC_MPRDDQBY1DL_RD_DQ12_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY1DL_RD_DQ12_DEL(v)   BF_CS1(MMDC_MPRDDQBY1DL, RD_DQ12_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY1DL, field RD_DQ13_DEL
 *
 * Read dqs1 to dq13 delay fine-tuning. This field holds the number of
 * delay units that are added to dq13 relative to dqs1.
 */

#define BP_MMDC_MPRDDQBY1DL_RD_DQ13_DEL      20
#define BM_MMDC_MPRDDQBY1DL_RD_DQ13_DEL      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY1DL_RD_DQ13_DEL(v)   ((((reg32_t) v) << 20) & BM_MMDC_MPRDDQBY1DL_RD_DQ13_DEL)
#else
#define BF_MMDC_MPRDDQBY1DL_RD_DQ13_DEL(v)   (((v) << 20) & BM_MMDC_MPRDDQBY1DL_RD_DQ13_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY1DL_RD_DQ13_DEL(v)   BF_CS1(MMDC_MPRDDQBY1DL, RD_DQ13_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY1DL, field RD_DQ14_DEL
 *
 * Read dqs1 to dq14 delay fine-tuning. This field holds the number of
 * delay units that are added to dq14 relative to dqs1.
 */

#define BP_MMDC_MPRDDQBY1DL_RD_DQ14_DEL      24
#define BM_MMDC_MPRDDQBY1DL_RD_DQ14_DEL      0x07000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY1DL_RD_DQ14_DEL(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPRDDQBY1DL_RD_DQ14_DEL)
#else
#define BF_MMDC_MPRDDQBY1DL_RD_DQ14_DEL(v)   (((v) << 24) & BM_MMDC_MPRDDQBY1DL_RD_DQ14_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY1DL_RD_DQ14_DEL(v)   BF_CS1(MMDC_MPRDDQBY1DL, RD_DQ14_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY1DL, field RD_DQ15_DEL
 *
 * Read dqs1 to dq15 delay fine-tuning. This field holds the number of
 * delay units that are added to dq15 relative to dqs1.
 */

#define BP_MMDC_MPRDDQBY1DL_RD_DQ15_DEL      28
#define BM_MMDC_MPRDDQBY1DL_RD_DQ15_DEL      0x70000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY1DL_RD_DQ15_DEL(v)   ((((reg32_t) v) << 28) & BM_MMDC_MPRDDQBY1DL_RD_DQ15_DEL)
#else
#define BF_MMDC_MPRDDQBY1DL_RD_DQ15_DEL(v)   (((v) << 28) & BM_MMDC_MPRDDQBY1DL_RD_DQ15_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY1DL_RD_DQ15_DEL(v)   BF_CS1(MMDC_MPRDDQBY1DL, RD_DQ15_DEL, v)
#endif

/*!
 * @brief HW_MMDC_MPRDDQBY2DL - MMDC PHY Read DQ Byte2 Delay Register
 *
 * This register is used to add fine-tuning adjustment to every bit in the
 * read DQ byte2 relative to the read DQS  Supported Mode Of Operations:  For Channel 0: All  For
 * Channel 1: DDR3_x64, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RD_DQ16_DEL : 3; //!< Read dqs2 to dq16 delay fine-tuning. This field holds the number of delay units that are added to dq16 relative to dqs2.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned RD_DQ17_DEL : 3; //!< Read dqs2 to dq17 delay fine-tuning. This field holds the number of delay units that are added to dq17 relative to dqs2.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned RD_DQ18_DEL : 3; //!< Read dqs2 to dq18 delay fine-tuning. This field holds the number of delay units that are added to dq18 relative to dqs2.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned RD_DQ19_DEL : 3; //!< Read dqs2 to dq19 delay fine-tuning. This field holds the number of delay units that are added to dq19 relative to dqs2.
        unsigned RESERVED3 : 1; //!< Reserved
        unsigned RD_DQ20_DEL : 3; //!< Read dqs2 to dq20 delay fine-tuning. This field holds the number of delay units that are added to dq20 relative to dqs2.
        unsigned RESERVED4 : 1; //!< Reserved
        unsigned RD_DQ21_DEL : 3; //!< Read dqs2 to dq21 delay fine-tuning. This field holds the number of delay units that are added to dq21 relative to dqs2.
        unsigned RESERVED5 : 1; //!< Reserved
        unsigned RD_DQ22_DEL : 3; //!< Read dqs2 to dq22 delay fine-tuning. This field holds the number of delay units that are added to dq22 relative to dqs2.
        unsigned RESERVED6 : 1; //!< Reserved
        unsigned RD_DQ23_DEL : 3; //!< Read dqs2 to dq23 delay fine-tuning. This field holds the number of delay units that are added to dq23 relative to dqs2.
        unsigned RESERVED7 : 1; //!< Reserved
    } B;
} hw_mmdc_mprddqby2dl_t;
#endif

/*
 * constants & macros for entire MMDC_MPRDDQBY2DL register
 */
#define HW_MMDC_MPRDDQBY2DL_ADDR      (REGS_MMDC_BASE + 0x824)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPRDDQBY2DL           (*(volatile hw_mmdc_mprddqby2dl_t *) HW_MMDC_MPRDDQBY2DL_ADDR)
#define HW_MMDC_MPRDDQBY2DL_RD()      (HW_MMDC_MPRDDQBY2DL.U)
#define HW_MMDC_MPRDDQBY2DL_WR(v)     (HW_MMDC_MPRDDQBY2DL.U = (v))
#define HW_MMDC_MPRDDQBY2DL_SET(v)    (HW_MMDC_MPRDDQBY2DL_WR(HW_MMDC_MPRDDQBY2DL_RD() |  (v)))
#define HW_MMDC_MPRDDQBY2DL_CLR(v)    (HW_MMDC_MPRDDQBY2DL_WR(HW_MMDC_MPRDDQBY2DL_RD() & ~(v)))
#define HW_MMDC_MPRDDQBY2DL_TOG(v)    (HW_MMDC_MPRDDQBY2DL_WR(HW_MMDC_MPRDDQBY2DL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPRDDQBY2DL bitfields
 */

/* --- Register HW_MMDC_MPRDDQBY2DL, field RD_DQ16_DEL
 *
 * Read dqs2 to dq16 delay fine-tuning. This field holds the number of
 * delay units that are added to dq16 relative to dqs2.
 */

#define BP_MMDC_MPRDDQBY2DL_RD_DQ16_DEL      0
#define BM_MMDC_MPRDDQBY2DL_RD_DQ16_DEL      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY2DL_RD_DQ16_DEL(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPRDDQBY2DL_RD_DQ16_DEL)
#else
#define BF_MMDC_MPRDDQBY2DL_RD_DQ16_DEL(v)   (((v) << 0) & BM_MMDC_MPRDDQBY2DL_RD_DQ16_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY2DL_RD_DQ16_DEL(v)   BF_CS1(MMDC_MPRDDQBY2DL, RD_DQ16_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY2DL, field RD_DQ17_DEL
 *
 * Read dqs2 to dq17 delay fine-tuning. This field holds the number of
 * delay units that are added to dq17 relative to dqs2.
 */

#define BP_MMDC_MPRDDQBY2DL_RD_DQ17_DEL      4
#define BM_MMDC_MPRDDQBY2DL_RD_DQ17_DEL      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY2DL_RD_DQ17_DEL(v)   ((((reg32_t) v) << 4) & BM_MMDC_MPRDDQBY2DL_RD_DQ17_DEL)
#else
#define BF_MMDC_MPRDDQBY2DL_RD_DQ17_DEL(v)   (((v) << 4) & BM_MMDC_MPRDDQBY2DL_RD_DQ17_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY2DL_RD_DQ17_DEL(v)   BF_CS1(MMDC_MPRDDQBY2DL, RD_DQ17_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY2DL, field RD_DQ18_DEL
 *
 * Read dqs2 to dq18 delay fine-tuning. This field holds the number of
 * delay units that are added to dq18 relative to dqs2.
 */

#define BP_MMDC_MPRDDQBY2DL_RD_DQ18_DEL      8
#define BM_MMDC_MPRDDQBY2DL_RD_DQ18_DEL      0x00000700

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY2DL_RD_DQ18_DEL(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPRDDQBY2DL_RD_DQ18_DEL)
#else
#define BF_MMDC_MPRDDQBY2DL_RD_DQ18_DEL(v)   (((v) << 8) & BM_MMDC_MPRDDQBY2DL_RD_DQ18_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY2DL_RD_DQ18_DEL(v)   BF_CS1(MMDC_MPRDDQBY2DL, RD_DQ18_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY2DL, field RD_DQ19_DEL
 *
 * Read dqs2 to dq19 delay fine-tuning. This field holds the number of
 * delay units that are added to dq19 relative to dqs2.
 */

#define BP_MMDC_MPRDDQBY2DL_RD_DQ19_DEL      12
#define BM_MMDC_MPRDDQBY2DL_RD_DQ19_DEL      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY2DL_RD_DQ19_DEL(v)   ((((reg32_t) v) << 12) & BM_MMDC_MPRDDQBY2DL_RD_DQ19_DEL)
#else
#define BF_MMDC_MPRDDQBY2DL_RD_DQ19_DEL(v)   (((v) << 12) & BM_MMDC_MPRDDQBY2DL_RD_DQ19_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY2DL_RD_DQ19_DEL(v)   BF_CS1(MMDC_MPRDDQBY2DL, RD_DQ19_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY2DL, field RD_DQ20_DEL
 *
 * Read dqs2 to dq20 delay fine-tuning. This field holds the number of
 * delay units that are added to dq20 relative to dqs2.
 */

#define BP_MMDC_MPRDDQBY2DL_RD_DQ20_DEL      16
#define BM_MMDC_MPRDDQBY2DL_RD_DQ20_DEL      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY2DL_RD_DQ20_DEL(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPRDDQBY2DL_RD_DQ20_DEL)
#else
#define BF_MMDC_MPRDDQBY2DL_RD_DQ20_DEL(v)   (((v) << 16) & BM_MMDC_MPRDDQBY2DL_RD_DQ20_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY2DL_RD_DQ20_DEL(v)   BF_CS1(MMDC_MPRDDQBY2DL, RD_DQ20_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY2DL, field RD_DQ21_DEL
 *
 * Read dqs2 to dq21 delay fine-tuning. This field holds the number of
 * delay units that are added to dq21 relative to dqs2.
 */

#define BP_MMDC_MPRDDQBY2DL_RD_DQ21_DEL      20
#define BM_MMDC_MPRDDQBY2DL_RD_DQ21_DEL      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY2DL_RD_DQ21_DEL(v)   ((((reg32_t) v) << 20) & BM_MMDC_MPRDDQBY2DL_RD_DQ21_DEL)
#else
#define BF_MMDC_MPRDDQBY2DL_RD_DQ21_DEL(v)   (((v) << 20) & BM_MMDC_MPRDDQBY2DL_RD_DQ21_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY2DL_RD_DQ21_DEL(v)   BF_CS1(MMDC_MPRDDQBY2DL, RD_DQ21_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY2DL, field RD_DQ22_DEL
 *
 * Read dqs2 to dq22 delay fine-tuning. This field holds the number of
 * delay units that are added to dq22 relative to dqs2.
 */

#define BP_MMDC_MPRDDQBY2DL_RD_DQ22_DEL      24
#define BM_MMDC_MPRDDQBY2DL_RD_DQ22_DEL      0x07000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY2DL_RD_DQ22_DEL(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPRDDQBY2DL_RD_DQ22_DEL)
#else
#define BF_MMDC_MPRDDQBY2DL_RD_DQ22_DEL(v)   (((v) << 24) & BM_MMDC_MPRDDQBY2DL_RD_DQ22_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY2DL_RD_DQ22_DEL(v)   BF_CS1(MMDC_MPRDDQBY2DL, RD_DQ22_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY2DL, field RD_DQ23_DEL
 *
 * Read dqs2 to dq23 delay fine-tuning. This field holds the number of
 * delay units that are added to dq23 relative to dqs2.
 */

#define BP_MMDC_MPRDDQBY2DL_RD_DQ23_DEL      28
#define BM_MMDC_MPRDDQBY2DL_RD_DQ23_DEL      0x70000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY2DL_RD_DQ23_DEL(v)   ((((reg32_t) v) << 28) & BM_MMDC_MPRDDQBY2DL_RD_DQ23_DEL)
#else
#define BF_MMDC_MPRDDQBY2DL_RD_DQ23_DEL(v)   (((v) << 28) & BM_MMDC_MPRDDQBY2DL_RD_DQ23_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY2DL_RD_DQ23_DEL(v)   BF_CS1(MMDC_MPRDDQBY2DL, RD_DQ23_DEL, v)
#endif

/*!
 * @brief HW_MMDC_MPRDDQBY3DL - MMDC PHY Read DQ Byte3 Delay Register
 *
 * This register is used to add fine-tuning adjustment to every bit in the
 * read DQ byte3 relative to the read DQS.  The bit assignments and the bit field
 * descriptions for the register are shown below.  Supported Mode Of Operations:  For Channel 0: All
 * For Channel 1: DDR3_x64, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RD_DQ24_DEL : 3; //!< Read dqs3 to dq24 delay fine-tuning. This field holds the number of delay units that are added to dq24 relative to dqs3.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned RD_DQ25_DEL : 3; //!< Read dqs3 to dq25 delay fine-tuning. This field holds the number of delay units that are added to dq25 relative to dqs3.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned RD_DQ26_DEL : 3; //!< Read dqs3 to dq26 delay fine-tuning. This field holds the number of delay units that are added to dq26 relative to dqs3.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned RD_DQ27_DEL : 3; //!< Read dqs3 to dq27 delay fine-tuning. This field holds the number of delay units that are added to dq27 relative to dqs3.
        unsigned RESERVED3 : 1; //!< Reserved
        unsigned RD_DQ28_DEL : 3; //!< Read dqs3 to dq28 delay fine-tuning. This field holds the number of delay units that are added to dq28 relative to dqs3.
        unsigned RESERVED4 : 1; //!< Reserved
        unsigned RD_DQ29_DEL : 3; //!< Read dqs3 to dq29 delay fine-tuning. This field holds the number of delay units that are added to dq29 relative to dqs3.
        unsigned RESERVED5 : 1; //!< Reserved
        unsigned RD_DQ30_DEL : 3; //!< Read dqs3 to dq30 delay fine-tuning. This field holds the number of delay units that are added to dq30 relative to dqs3.
        unsigned RESERVED6 : 1; //!< Reserved
        unsigned RD_DQ31_DEL : 3; //!< Read dqs3 to dq31 delay fine-tuning. This field holds the number of delay units that are added to dq31 relative to dqs3.
        unsigned RESERVED7 : 1; //!< Reserved
    } B;
} hw_mmdc_mprddqby3dl_t;
#endif

/*
 * constants & macros for entire MMDC_MPRDDQBY3DL register
 */
#define HW_MMDC_MPRDDQBY3DL_ADDR      (REGS_MMDC_BASE + 0x828)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPRDDQBY3DL           (*(volatile hw_mmdc_mprddqby3dl_t *) HW_MMDC_MPRDDQBY3DL_ADDR)
#define HW_MMDC_MPRDDQBY3DL_RD()      (HW_MMDC_MPRDDQBY3DL.U)
#define HW_MMDC_MPRDDQBY3DL_WR(v)     (HW_MMDC_MPRDDQBY3DL.U = (v))
#define HW_MMDC_MPRDDQBY3DL_SET(v)    (HW_MMDC_MPRDDQBY3DL_WR(HW_MMDC_MPRDDQBY3DL_RD() |  (v)))
#define HW_MMDC_MPRDDQBY3DL_CLR(v)    (HW_MMDC_MPRDDQBY3DL_WR(HW_MMDC_MPRDDQBY3DL_RD() & ~(v)))
#define HW_MMDC_MPRDDQBY3DL_TOG(v)    (HW_MMDC_MPRDDQBY3DL_WR(HW_MMDC_MPRDDQBY3DL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPRDDQBY3DL bitfields
 */

/* --- Register HW_MMDC_MPRDDQBY3DL, field RD_DQ24_DEL
 *
 * Read dqs3 to dq24 delay fine-tuning. This field holds the number of
 * delay units that are added to dq24 relative to dqs3.
 */

#define BP_MMDC_MPRDDQBY3DL_RD_DQ24_DEL      0
#define BM_MMDC_MPRDDQBY3DL_RD_DQ24_DEL      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY3DL_RD_DQ24_DEL(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPRDDQBY3DL_RD_DQ24_DEL)
#else
#define BF_MMDC_MPRDDQBY3DL_RD_DQ24_DEL(v)   (((v) << 0) & BM_MMDC_MPRDDQBY3DL_RD_DQ24_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY3DL_RD_DQ24_DEL(v)   BF_CS1(MMDC_MPRDDQBY3DL, RD_DQ24_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY3DL, field RD_DQ25_DEL
 *
 * Read dqs3 to dq25 delay fine-tuning. This field holds the number of
 * delay units that are added to dq25 relative to dqs3.
 */

#define BP_MMDC_MPRDDQBY3DL_RD_DQ25_DEL      4
#define BM_MMDC_MPRDDQBY3DL_RD_DQ25_DEL      0x00000070

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY3DL_RD_DQ25_DEL(v)   ((((reg32_t) v) << 4) & BM_MMDC_MPRDDQBY3DL_RD_DQ25_DEL)
#else
#define BF_MMDC_MPRDDQBY3DL_RD_DQ25_DEL(v)   (((v) << 4) & BM_MMDC_MPRDDQBY3DL_RD_DQ25_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY3DL_RD_DQ25_DEL(v)   BF_CS1(MMDC_MPRDDQBY3DL, RD_DQ25_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY3DL, field RD_DQ26_DEL
 *
 * Read dqs3 to dq26 delay fine-tuning. This field holds the number of
 * delay units that are added to dq26 relative to dqs3.
 */

#define BP_MMDC_MPRDDQBY3DL_RD_DQ26_DEL      8
#define BM_MMDC_MPRDDQBY3DL_RD_DQ26_DEL      0x00000700

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY3DL_RD_DQ26_DEL(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPRDDQBY3DL_RD_DQ26_DEL)
#else
#define BF_MMDC_MPRDDQBY3DL_RD_DQ26_DEL(v)   (((v) << 8) & BM_MMDC_MPRDDQBY3DL_RD_DQ26_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY3DL_RD_DQ26_DEL(v)   BF_CS1(MMDC_MPRDDQBY3DL, RD_DQ26_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY3DL, field RD_DQ27_DEL
 *
 * Read dqs3 to dq27 delay fine-tuning. This field holds the number of
 * delay units that are added to dq27 relative to dqs3.
 */

#define BP_MMDC_MPRDDQBY3DL_RD_DQ27_DEL      12
#define BM_MMDC_MPRDDQBY3DL_RD_DQ27_DEL      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY3DL_RD_DQ27_DEL(v)   ((((reg32_t) v) << 12) & BM_MMDC_MPRDDQBY3DL_RD_DQ27_DEL)
#else
#define BF_MMDC_MPRDDQBY3DL_RD_DQ27_DEL(v)   (((v) << 12) & BM_MMDC_MPRDDQBY3DL_RD_DQ27_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY3DL_RD_DQ27_DEL(v)   BF_CS1(MMDC_MPRDDQBY3DL, RD_DQ27_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY3DL, field RD_DQ28_DEL
 *
 * Read dqs3 to dq28 delay fine-tuning. This field holds the number of
 * delay units that are added to dq28 relative to dqs3.
 */

#define BP_MMDC_MPRDDQBY3DL_RD_DQ28_DEL      16
#define BM_MMDC_MPRDDQBY3DL_RD_DQ28_DEL      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY3DL_RD_DQ28_DEL(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPRDDQBY3DL_RD_DQ28_DEL)
#else
#define BF_MMDC_MPRDDQBY3DL_RD_DQ28_DEL(v)   (((v) << 16) & BM_MMDC_MPRDDQBY3DL_RD_DQ28_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY3DL_RD_DQ28_DEL(v)   BF_CS1(MMDC_MPRDDQBY3DL, RD_DQ28_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY3DL, field RD_DQ29_DEL
 *
 * Read dqs3 to dq29 delay fine-tuning. This field holds the number of
 * delay units that are added to dq29 relative to dqs3.
 */

#define BP_MMDC_MPRDDQBY3DL_RD_DQ29_DEL      20
#define BM_MMDC_MPRDDQBY3DL_RD_DQ29_DEL      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY3DL_RD_DQ29_DEL(v)   ((((reg32_t) v) << 20) & BM_MMDC_MPRDDQBY3DL_RD_DQ29_DEL)
#else
#define BF_MMDC_MPRDDQBY3DL_RD_DQ29_DEL(v)   (((v) << 20) & BM_MMDC_MPRDDQBY3DL_RD_DQ29_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY3DL_RD_DQ29_DEL(v)   BF_CS1(MMDC_MPRDDQBY3DL, RD_DQ29_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY3DL, field RD_DQ30_DEL
 *
 * Read dqs3 to dq30 delay fine-tuning. This field holds the number of
 * delay units that are added to dq30 relative to dqs3.
 */

#define BP_MMDC_MPRDDQBY3DL_RD_DQ30_DEL      24
#define BM_MMDC_MPRDDQBY3DL_RD_DQ30_DEL      0x07000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY3DL_RD_DQ30_DEL(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPRDDQBY3DL_RD_DQ30_DEL)
#else
#define BF_MMDC_MPRDDQBY3DL_RD_DQ30_DEL(v)   (((v) << 24) & BM_MMDC_MPRDDQBY3DL_RD_DQ30_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY3DL_RD_DQ30_DEL(v)   BF_CS1(MMDC_MPRDDQBY3DL, RD_DQ30_DEL, v)
#endif

/* --- Register HW_MMDC_MPRDDQBY3DL, field RD_DQ31_DEL
 *
 * Read dqs3 to dq31 delay fine-tuning. This field holds the number of
 * delay units that are added to dq31 relative to dqs3.
 */

#define BP_MMDC_MPRDDQBY3DL_RD_DQ31_DEL      28
#define BM_MMDC_MPRDDQBY3DL_RD_DQ31_DEL      0x70000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDQBY3DL_RD_DQ31_DEL(v)   ((((reg32_t) v) << 28) & BM_MMDC_MPRDDQBY3DL_RD_DQ31_DEL)
#else
#define BF_MMDC_MPRDDQBY3DL_RD_DQ31_DEL(v)   (((v) << 28) & BM_MMDC_MPRDDQBY3DL_RD_DQ31_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDQBY3DL_RD_DQ31_DEL(v)   BF_CS1(MMDC_MPRDDQBY3DL, RD_DQ31_DEL, v)
#endif

/*!
 * @brief HW_MMDC_MPWRDQBY0DL - MMDC PHY Write DQ Byte0 Delay Register
 *
 * This register is used to add fine-tuning adjustment to every bit in the
 * write DQ byte0 relative to the write DQS  Supported Mode Of Operations:  For Channel 0: All  For
 * Channel 1: DDR3_x64, LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WR_DQ0_DEL : 2; //!< Write dq0 delay fine-tuning. This field holds the number of delay units that are added to dq0 relative to dqs0.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned WR_DQ1_DEL : 2; //!< Write dq1 delay fine-tuning. This field holds the number of delay units that are added to dq1 relative to dqs0.
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned WR_DQ2_DEL : 2; //!< Write dq2 delay fine-tuning. This field holds the number of delay units that are added to dq2 relative to dqs0.
        unsigned RESERVED2 : 2; //!< Reserved
        unsigned WR_DQ3_DEL : 2; //!< Write dq3 delay fine-tuning. This field holds the number of delay units that are added to dq3 relative to dqs0.
        unsigned RESERVED3 : 2; //!< Reserved
        unsigned WR_DQ4_DEL : 2; //!< Write dq4 delay fine-tuning. This field holds the number of delay units that are added to dq4 relative to dqs0.
        unsigned RESERVED4 : 2; //!< Reserved
        unsigned WR_DQ5_DEL : 2; //!< Write dq5 delay fine-tuning. This field holds the number of delay units that are added to dq5 relative to dqs0.
        unsigned RESERVED5 : 2; //!< Reserved
        unsigned WR_DQ6_DEL : 2; //!< Write dq6 delay fine-tuning. This field holds the number of delay units that are added to dq6 relative to dqs0.
        unsigned RESERVED6 : 2; //!< Reserved
        unsigned WR_DQ7_DEL : 2; //!< Write dq7 delay fine-tuning. This field holds the number of delay units that are added to dq7 relative to dqs0.
        unsigned WR_DM0_DEL : 2; //!< Write dm0 delay fine-tuning. This field holds the number of delay units that are added to dm0 relative to dqs0.
    } B;
} hw_mmdc_mpwrdqby0dl_t;
#endif

/*
 * constants & macros for entire MMDC_MPWRDQBY0DL register
 */
#define HW_MMDC_MPWRDQBY0DL_ADDR      (REGS_MMDC_BASE + 0x82c)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPWRDQBY0DL           (*(volatile hw_mmdc_mpwrdqby0dl_t *) HW_MMDC_MPWRDQBY0DL_ADDR)
#define HW_MMDC_MPWRDQBY0DL_RD()      (HW_MMDC_MPWRDQBY0DL.U)
#define HW_MMDC_MPWRDQBY0DL_WR(v)     (HW_MMDC_MPWRDQBY0DL.U = (v))
#define HW_MMDC_MPWRDQBY0DL_SET(v)    (HW_MMDC_MPWRDQBY0DL_WR(HW_MMDC_MPWRDQBY0DL_RD() |  (v)))
#define HW_MMDC_MPWRDQBY0DL_CLR(v)    (HW_MMDC_MPWRDQBY0DL_WR(HW_MMDC_MPWRDQBY0DL_RD() & ~(v)))
#define HW_MMDC_MPWRDQBY0DL_TOG(v)    (HW_MMDC_MPWRDQBY0DL_WR(HW_MMDC_MPWRDQBY0DL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPWRDQBY0DL bitfields
 */

/* --- Register HW_MMDC_MPWRDQBY0DL, field WR_DQ0_DEL
 *
 * Write dq0 delay fine-tuning. This field holds the number of delay
 * units that are added to dq0 relative to dqs0.
 */

#define BP_MMDC_MPWRDQBY0DL_WR_DQ0_DEL      0
#define BM_MMDC_MPWRDQBY0DL_WR_DQ0_DEL      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY0DL_WR_DQ0_DEL(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPWRDQBY0DL_WR_DQ0_DEL)
#else
#define BF_MMDC_MPWRDQBY0DL_WR_DQ0_DEL(v)   (((v) << 0) & BM_MMDC_MPWRDQBY0DL_WR_DQ0_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY0DL_WR_DQ0_DEL(v)   BF_CS1(MMDC_MPWRDQBY0DL, WR_DQ0_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY0DL, field WR_DQ1_DEL
 *
 * Write dq1 delay fine-tuning. This field holds the number of delay
 * units that are added to dq1 relative to dqs0.
 */

#define BP_MMDC_MPWRDQBY0DL_WR_DQ1_DEL      4
#define BM_MMDC_MPWRDQBY0DL_WR_DQ1_DEL      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY0DL_WR_DQ1_DEL(v)   ((((reg32_t) v) << 4) & BM_MMDC_MPWRDQBY0DL_WR_DQ1_DEL)
#else
#define BF_MMDC_MPWRDQBY0DL_WR_DQ1_DEL(v)   (((v) << 4) & BM_MMDC_MPWRDQBY0DL_WR_DQ1_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY0DL_WR_DQ1_DEL(v)   BF_CS1(MMDC_MPWRDQBY0DL, WR_DQ1_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY0DL, field WR_DQ2_DEL
 *
 * Write dq2 delay fine-tuning. This field holds the number of delay
 * units that are added to dq2 relative to dqs0.
 */

#define BP_MMDC_MPWRDQBY0DL_WR_DQ2_DEL      8
#define BM_MMDC_MPWRDQBY0DL_WR_DQ2_DEL      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY0DL_WR_DQ2_DEL(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPWRDQBY0DL_WR_DQ2_DEL)
#else
#define BF_MMDC_MPWRDQBY0DL_WR_DQ2_DEL(v)   (((v) << 8) & BM_MMDC_MPWRDQBY0DL_WR_DQ2_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY0DL_WR_DQ2_DEL(v)   BF_CS1(MMDC_MPWRDQBY0DL, WR_DQ2_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY0DL, field WR_DQ3_DEL
 *
 * Write dq3 delay fine-tuning. This field holds the number of delay
 * units that are added to dq3 relative to dqs0.
 */

#define BP_MMDC_MPWRDQBY0DL_WR_DQ3_DEL      12
#define BM_MMDC_MPWRDQBY0DL_WR_DQ3_DEL      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY0DL_WR_DQ3_DEL(v)   ((((reg32_t) v) << 12) & BM_MMDC_MPWRDQBY0DL_WR_DQ3_DEL)
#else
#define BF_MMDC_MPWRDQBY0DL_WR_DQ3_DEL(v)   (((v) << 12) & BM_MMDC_MPWRDQBY0DL_WR_DQ3_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY0DL_WR_DQ3_DEL(v)   BF_CS1(MMDC_MPWRDQBY0DL, WR_DQ3_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY0DL, field WR_DQ4_DEL
 *
 * Write dq4 delay fine-tuning. This field holds the number of delay
 * units that are added to dq4 relative to dqs0.
 */

#define BP_MMDC_MPWRDQBY0DL_WR_DQ4_DEL      16
#define BM_MMDC_MPWRDQBY0DL_WR_DQ4_DEL      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY0DL_WR_DQ4_DEL(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPWRDQBY0DL_WR_DQ4_DEL)
#else
#define BF_MMDC_MPWRDQBY0DL_WR_DQ4_DEL(v)   (((v) << 16) & BM_MMDC_MPWRDQBY0DL_WR_DQ4_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY0DL_WR_DQ4_DEL(v)   BF_CS1(MMDC_MPWRDQBY0DL, WR_DQ4_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY0DL, field WR_DQ5_DEL
 *
 * Write dq5 delay fine-tuning. This field holds the number of delay
 * units that are added to dq5 relative to dqs0.
 */

#define BP_MMDC_MPWRDQBY0DL_WR_DQ5_DEL      20
#define BM_MMDC_MPWRDQBY0DL_WR_DQ5_DEL      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY0DL_WR_DQ5_DEL(v)   ((((reg32_t) v) << 20) & BM_MMDC_MPWRDQBY0DL_WR_DQ5_DEL)
#else
#define BF_MMDC_MPWRDQBY0DL_WR_DQ5_DEL(v)   (((v) << 20) & BM_MMDC_MPWRDQBY0DL_WR_DQ5_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY0DL_WR_DQ5_DEL(v)   BF_CS1(MMDC_MPWRDQBY0DL, WR_DQ5_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY0DL, field WR_DQ6_DEL
 *
 * Write dq6 delay fine-tuning. This field holds the number of delay
 * units that are added to dq6 relative to dqs0.
 */

#define BP_MMDC_MPWRDQBY0DL_WR_DQ6_DEL      24
#define BM_MMDC_MPWRDQBY0DL_WR_DQ6_DEL      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY0DL_WR_DQ6_DEL(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPWRDQBY0DL_WR_DQ6_DEL)
#else
#define BF_MMDC_MPWRDQBY0DL_WR_DQ6_DEL(v)   (((v) << 24) & BM_MMDC_MPWRDQBY0DL_WR_DQ6_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY0DL_WR_DQ6_DEL(v)   BF_CS1(MMDC_MPWRDQBY0DL, WR_DQ6_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY0DL, field WR_DQ7_DEL
 *
 * Write dq7 delay fine-tuning. This field holds the number of delay
 * units that are added to dq7 relative to dqs0.
 */

#define BP_MMDC_MPWRDQBY0DL_WR_DQ7_DEL      28
#define BM_MMDC_MPWRDQBY0DL_WR_DQ7_DEL      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY0DL_WR_DQ7_DEL(v)   ((((reg32_t) v) << 28) & BM_MMDC_MPWRDQBY0DL_WR_DQ7_DEL)
#else
#define BF_MMDC_MPWRDQBY0DL_WR_DQ7_DEL(v)   (((v) << 28) & BM_MMDC_MPWRDQBY0DL_WR_DQ7_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY0DL_WR_DQ7_DEL(v)   BF_CS1(MMDC_MPWRDQBY0DL, WR_DQ7_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY0DL, field WR_DM0_DEL
 *
 * Write dm0 delay fine-tuning. This field holds the number of delay
 * units that are added to dm0 relative to dqs0.
 */

#define BP_MMDC_MPWRDQBY0DL_WR_DM0_DEL      30
#define BM_MMDC_MPWRDQBY0DL_WR_DM0_DEL      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY0DL_WR_DM0_DEL(v)   ((((reg32_t) v) << 30) & BM_MMDC_MPWRDQBY0DL_WR_DM0_DEL)
#else
#define BF_MMDC_MPWRDQBY0DL_WR_DM0_DEL(v)   (((v) << 30) & BM_MMDC_MPWRDQBY0DL_WR_DM0_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY0DL_WR_DM0_DEL(v)   BF_CS1(MMDC_MPWRDQBY0DL, WR_DM0_DEL, v)
#endif

/*!
 * @brief HW_MMDC_MPWRDQBY1DL - MMDC PHY Write DQ Byte1 Delay Register
 *
 * This register is used to add fine-tuning adjustment to every bit in the
 * write DQ byte1 relative to the write DQS  Supported Mode Of Operations:  For Channel 0: All  For
 * Channel 1: DDR3_x64, LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WR_DQ8_DEL : 2; //!< Write dq8 delay fine-tuning. This field holds the number of delay units that are added to dq8 relative to dqs1.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned WR_DQ9_DEL : 2; //!< Write dq9 delay fine-tuning. This field holds the number of delay units that are added to dq9 relative to dqs1.
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned WR_DQ10_DEL : 2; //!< Write dq10 delay fine-tuning. This field holds the number of delay units that are added to dq10 relative to dqs1.
        unsigned RESERVED2 : 2; //!< Reserved
        unsigned WR_DQ11_DEL : 2; //!< Write dq11 delay fine-tuning. This field holds the number of delay units that are added to dq11 relative to dqs1.
        unsigned RESERVED3 : 2; //!< Reserved
        unsigned WR_DQ12_DEL : 2; //!< Write dq12 delay fine-tuning. This field holds the number of delay units that are added to dq12 relative to dqs1.
        unsigned RESERVED4 : 2; //!< Reserved
        unsigned WR_DQ13_DEL : 2; //!< Write dq13 delay fine-tuning. This field holds the number of delay units that are added to dq13 relative to dqs1.
        unsigned RESERVED5 : 2; //!< Reserved
        unsigned WR_DQ14_DEL : 2; //!< Write dq14 delay fine-tuning. This field holds the number of delay units that are added to dq14 relative to dqs1.
        unsigned RESERVED6 : 2; //!< Reserved
        unsigned WR_DQ15_DEL : 2; //!< Write dq15 delay fine-tuning. This field holds the number of delay units that are added to dq15 relative to dqs1.
        unsigned WR_DM1_DEL : 2; //!< Write dm1 delay fine-tuning. This field holds the number of delay units that are added to dm1 relative to dqs1.
    } B;
} hw_mmdc_mpwrdqby1dl_t;
#endif

/*
 * constants & macros for entire MMDC_MPWRDQBY1DL register
 */
#define HW_MMDC_MPWRDQBY1DL_ADDR      (REGS_MMDC_BASE + 0x830)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPWRDQBY1DL           (*(volatile hw_mmdc_mpwrdqby1dl_t *) HW_MMDC_MPWRDQBY1DL_ADDR)
#define HW_MMDC_MPWRDQBY1DL_RD()      (HW_MMDC_MPWRDQBY1DL.U)
#define HW_MMDC_MPWRDQBY1DL_WR(v)     (HW_MMDC_MPWRDQBY1DL.U = (v))
#define HW_MMDC_MPWRDQBY1DL_SET(v)    (HW_MMDC_MPWRDQBY1DL_WR(HW_MMDC_MPWRDQBY1DL_RD() |  (v)))
#define HW_MMDC_MPWRDQBY1DL_CLR(v)    (HW_MMDC_MPWRDQBY1DL_WR(HW_MMDC_MPWRDQBY1DL_RD() & ~(v)))
#define HW_MMDC_MPWRDQBY1DL_TOG(v)    (HW_MMDC_MPWRDQBY1DL_WR(HW_MMDC_MPWRDQBY1DL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPWRDQBY1DL bitfields
 */

/* --- Register HW_MMDC_MPWRDQBY1DL, field WR_DQ8_DEL
 *
 * Write dq8 delay fine-tuning. This field holds the number of delay
 * units that are added to dq8 relative to dqs1.
 */

#define BP_MMDC_MPWRDQBY1DL_WR_DQ8_DEL      0
#define BM_MMDC_MPWRDQBY1DL_WR_DQ8_DEL      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY1DL_WR_DQ8_DEL(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPWRDQBY1DL_WR_DQ8_DEL)
#else
#define BF_MMDC_MPWRDQBY1DL_WR_DQ8_DEL(v)   (((v) << 0) & BM_MMDC_MPWRDQBY1DL_WR_DQ8_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY1DL_WR_DQ8_DEL(v)   BF_CS1(MMDC_MPWRDQBY1DL, WR_DQ8_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY1DL, field WR_DQ9_DEL
 *
 * Write dq9 delay fine-tuning. This field holds the number of delay
 * units that are added to dq9 relative to dqs1.
 */

#define BP_MMDC_MPWRDQBY1DL_WR_DQ9_DEL      4
#define BM_MMDC_MPWRDQBY1DL_WR_DQ9_DEL      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY1DL_WR_DQ9_DEL(v)   ((((reg32_t) v) << 4) & BM_MMDC_MPWRDQBY1DL_WR_DQ9_DEL)
#else
#define BF_MMDC_MPWRDQBY1DL_WR_DQ9_DEL(v)   (((v) << 4) & BM_MMDC_MPWRDQBY1DL_WR_DQ9_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY1DL_WR_DQ9_DEL(v)   BF_CS1(MMDC_MPWRDQBY1DL, WR_DQ9_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY1DL, field WR_DQ10_DEL
 *
 * Write dq10 delay fine-tuning. This field holds the number of delay
 * units that are added to dq10 relative to dqs1.
 */

#define BP_MMDC_MPWRDQBY1DL_WR_DQ10_DEL      8
#define BM_MMDC_MPWRDQBY1DL_WR_DQ10_DEL      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY1DL_WR_DQ10_DEL(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPWRDQBY1DL_WR_DQ10_DEL)
#else
#define BF_MMDC_MPWRDQBY1DL_WR_DQ10_DEL(v)   (((v) << 8) & BM_MMDC_MPWRDQBY1DL_WR_DQ10_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY1DL_WR_DQ10_DEL(v)   BF_CS1(MMDC_MPWRDQBY1DL, WR_DQ10_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY1DL, field WR_DQ11_DEL
 *
 * Write dq11 delay fine-tuning. This field holds the number of delay
 * units that are added to dq11 relative to dqs1.
 */

#define BP_MMDC_MPWRDQBY1DL_WR_DQ11_DEL      12
#define BM_MMDC_MPWRDQBY1DL_WR_DQ11_DEL      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY1DL_WR_DQ11_DEL(v)   ((((reg32_t) v) << 12) & BM_MMDC_MPWRDQBY1DL_WR_DQ11_DEL)
#else
#define BF_MMDC_MPWRDQBY1DL_WR_DQ11_DEL(v)   (((v) << 12) & BM_MMDC_MPWRDQBY1DL_WR_DQ11_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY1DL_WR_DQ11_DEL(v)   BF_CS1(MMDC_MPWRDQBY1DL, WR_DQ11_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY1DL, field WR_DQ12_DEL
 *
 * Write dq12 delay fine-tuning. This field holds the number of delay
 * units that are added to dq12 relative to dqs1.
 */

#define BP_MMDC_MPWRDQBY1DL_WR_DQ12_DEL      16
#define BM_MMDC_MPWRDQBY1DL_WR_DQ12_DEL      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY1DL_WR_DQ12_DEL(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPWRDQBY1DL_WR_DQ12_DEL)
#else
#define BF_MMDC_MPWRDQBY1DL_WR_DQ12_DEL(v)   (((v) << 16) & BM_MMDC_MPWRDQBY1DL_WR_DQ12_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY1DL_WR_DQ12_DEL(v)   BF_CS1(MMDC_MPWRDQBY1DL, WR_DQ12_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY1DL, field WR_DQ13_DEL
 *
 * Write dq13 delay fine-tuning. This field holds the number of delay
 * units that are added to dq13 relative to dqs1.
 */

#define BP_MMDC_MPWRDQBY1DL_WR_DQ13_DEL      20
#define BM_MMDC_MPWRDQBY1DL_WR_DQ13_DEL      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY1DL_WR_DQ13_DEL(v)   ((((reg32_t) v) << 20) & BM_MMDC_MPWRDQBY1DL_WR_DQ13_DEL)
#else
#define BF_MMDC_MPWRDQBY1DL_WR_DQ13_DEL(v)   (((v) << 20) & BM_MMDC_MPWRDQBY1DL_WR_DQ13_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY1DL_WR_DQ13_DEL(v)   BF_CS1(MMDC_MPWRDQBY1DL, WR_DQ13_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY1DL, field WR_DQ14_DEL
 *
 * Write dq14 delay fine-tuning. This field holds the number of delay
 * units that are added to dq14 relative to dqs1.
 */

#define BP_MMDC_MPWRDQBY1DL_WR_DQ14_DEL      24
#define BM_MMDC_MPWRDQBY1DL_WR_DQ14_DEL      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY1DL_WR_DQ14_DEL(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPWRDQBY1DL_WR_DQ14_DEL)
#else
#define BF_MMDC_MPWRDQBY1DL_WR_DQ14_DEL(v)   (((v) << 24) & BM_MMDC_MPWRDQBY1DL_WR_DQ14_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY1DL_WR_DQ14_DEL(v)   BF_CS1(MMDC_MPWRDQBY1DL, WR_DQ14_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY1DL, field WR_DQ15_DEL
 *
 * Write dq15 delay fine-tuning. This field holds the number of delay
 * units that are added to dq15 relative to dqs1.
 */

#define BP_MMDC_MPWRDQBY1DL_WR_DQ15_DEL      28
#define BM_MMDC_MPWRDQBY1DL_WR_DQ15_DEL      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY1DL_WR_DQ15_DEL(v)   ((((reg32_t) v) << 28) & BM_MMDC_MPWRDQBY1DL_WR_DQ15_DEL)
#else
#define BF_MMDC_MPWRDQBY1DL_WR_DQ15_DEL(v)   (((v) << 28) & BM_MMDC_MPWRDQBY1DL_WR_DQ15_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY1DL_WR_DQ15_DEL(v)   BF_CS1(MMDC_MPWRDQBY1DL, WR_DQ15_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY1DL, field WR_DM1_DEL
 *
 * Write dm1 delay fine-tuning. This field holds the number of delay
 * units that are added to dm1 relative to dqs1.
 */

#define BP_MMDC_MPWRDQBY1DL_WR_DM1_DEL      30
#define BM_MMDC_MPWRDQBY1DL_WR_DM1_DEL      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY1DL_WR_DM1_DEL(v)   ((((reg32_t) v) << 30) & BM_MMDC_MPWRDQBY1DL_WR_DM1_DEL)
#else
#define BF_MMDC_MPWRDQBY1DL_WR_DM1_DEL(v)   (((v) << 30) & BM_MMDC_MPWRDQBY1DL_WR_DM1_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY1DL_WR_DM1_DEL(v)   BF_CS1(MMDC_MPWRDQBY1DL, WR_DM1_DEL, v)
#endif

/*!
 * @brief HW_MMDC_MPWRDQBY2DL - MMDC PHY Write DQ Byte2 Delay Register
 *
 * This register is used to add fine-tuning adjustment to every bit in the
 * write DQ byte2 relative to the write DQS  Supported Mode Of Operations:  For Channel 0: All  For
 * Channel 1: DDR3_x64, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WR_DQ16_DEL : 2; //!< Write dq16 delay fine tuning. This field holds the number of delay units that are added to dq16 relative to dqs2.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned WR_DQ17_DEL : 2; //!< Write dq17 delay fine tuning. This field holds the number of delay units that are added to dq17 relative to dqs2.
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned WR_DQ18_DEL : 2; //!< Write dq18 delay fine tuning. This field holds the number of delay units that are added to dq18 relative to dqs2.
        unsigned RESERVED2 : 2; //!< Reserved
        unsigned WR_DQ19_DEL : 2; //!< Write dq19 delay fine tuning. This field holds the number of delay units that are added to dq19 relative to dqs2.
        unsigned RESERVED3 : 2; //!< Reserved
        unsigned WR_DQ20_DEL : 2; //!< Write dq20 delay fine tuning. This field holds the number of delay units that are added to dq20 relative to dqs2.
        unsigned RESERVED4 : 2; //!< Reserved
        unsigned WR_DQ21_DEL : 2; //!< Write dq21 delay fine tuning. This field holds the number of delay units that are added to dq21 relative to dqs2.
        unsigned RESERVED5 : 2; //!< Reserved
        unsigned WR_DQ22_DEL : 2; //!< Write dq22 delay fine tuning. This field holds the number of delay units that are added to dq22 relative to dqs2.
        unsigned RESERVED6 : 2; //!< Reserved
        unsigned WR_DQ23_DEL : 2; //!< Write dq23 delay fine tuning. This field holds the number of delay units that are added to dq23 relative to dqs2.
        unsigned WR_DM2_DEL : 2; //!< Write dm2 delay fine-tuning. This field holds the number of delay units that are added to dm2 relative to dqs2.
    } B;
} hw_mmdc_mpwrdqby2dl_t;
#endif

/*
 * constants & macros for entire MMDC_MPWRDQBY2DL register
 */
#define HW_MMDC_MPWRDQBY2DL_ADDR      (REGS_MMDC_BASE + 0x834)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPWRDQBY2DL           (*(volatile hw_mmdc_mpwrdqby2dl_t *) HW_MMDC_MPWRDQBY2DL_ADDR)
#define HW_MMDC_MPWRDQBY2DL_RD()      (HW_MMDC_MPWRDQBY2DL.U)
#define HW_MMDC_MPWRDQBY2DL_WR(v)     (HW_MMDC_MPWRDQBY2DL.U = (v))
#define HW_MMDC_MPWRDQBY2DL_SET(v)    (HW_MMDC_MPWRDQBY2DL_WR(HW_MMDC_MPWRDQBY2DL_RD() |  (v)))
#define HW_MMDC_MPWRDQBY2DL_CLR(v)    (HW_MMDC_MPWRDQBY2DL_WR(HW_MMDC_MPWRDQBY2DL_RD() & ~(v)))
#define HW_MMDC_MPWRDQBY2DL_TOG(v)    (HW_MMDC_MPWRDQBY2DL_WR(HW_MMDC_MPWRDQBY2DL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPWRDQBY2DL bitfields
 */

/* --- Register HW_MMDC_MPWRDQBY2DL, field WR_DQ16_DEL
 *
 * Write dq16 delay fine tuning. This field holds the number of delay
 * units that are added to dq16 relative to dqs2.
 */

#define BP_MMDC_MPWRDQBY2DL_WR_DQ16_DEL      0
#define BM_MMDC_MPWRDQBY2DL_WR_DQ16_DEL      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY2DL_WR_DQ16_DEL(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPWRDQBY2DL_WR_DQ16_DEL)
#else
#define BF_MMDC_MPWRDQBY2DL_WR_DQ16_DEL(v)   (((v) << 0) & BM_MMDC_MPWRDQBY2DL_WR_DQ16_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY2DL_WR_DQ16_DEL(v)   BF_CS1(MMDC_MPWRDQBY2DL, WR_DQ16_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY2DL, field WR_DQ17_DEL
 *
 * Write dq17 delay fine tuning. This field holds the number of delay
 * units that are added to dq17 relative to dqs2.
 */

#define BP_MMDC_MPWRDQBY2DL_WR_DQ17_DEL      4
#define BM_MMDC_MPWRDQBY2DL_WR_DQ17_DEL      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY2DL_WR_DQ17_DEL(v)   ((((reg32_t) v) << 4) & BM_MMDC_MPWRDQBY2DL_WR_DQ17_DEL)
#else
#define BF_MMDC_MPWRDQBY2DL_WR_DQ17_DEL(v)   (((v) << 4) & BM_MMDC_MPWRDQBY2DL_WR_DQ17_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY2DL_WR_DQ17_DEL(v)   BF_CS1(MMDC_MPWRDQBY2DL, WR_DQ17_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY2DL, field WR_DQ18_DEL
 *
 * Write dq18 delay fine tuning. This field holds the number of delay
 * units that are added to dq18 relative to dqs2.
 */

#define BP_MMDC_MPWRDQBY2DL_WR_DQ18_DEL      8
#define BM_MMDC_MPWRDQBY2DL_WR_DQ18_DEL      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY2DL_WR_DQ18_DEL(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPWRDQBY2DL_WR_DQ18_DEL)
#else
#define BF_MMDC_MPWRDQBY2DL_WR_DQ18_DEL(v)   (((v) << 8) & BM_MMDC_MPWRDQBY2DL_WR_DQ18_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY2DL_WR_DQ18_DEL(v)   BF_CS1(MMDC_MPWRDQBY2DL, WR_DQ18_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY2DL, field WR_DQ19_DEL
 *
 * Write dq19 delay fine tuning. This field holds the number of delay
 * units that are added to dq19 relative to dqs2.
 */

#define BP_MMDC_MPWRDQBY2DL_WR_DQ19_DEL      12
#define BM_MMDC_MPWRDQBY2DL_WR_DQ19_DEL      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY2DL_WR_DQ19_DEL(v)   ((((reg32_t) v) << 12) & BM_MMDC_MPWRDQBY2DL_WR_DQ19_DEL)
#else
#define BF_MMDC_MPWRDQBY2DL_WR_DQ19_DEL(v)   (((v) << 12) & BM_MMDC_MPWRDQBY2DL_WR_DQ19_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY2DL_WR_DQ19_DEL(v)   BF_CS1(MMDC_MPWRDQBY2DL, WR_DQ19_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY2DL, field WR_DQ20_DEL
 *
 * Write dq20 delay fine tuning. This field holds the number of delay
 * units that are added to dq20 relative to dqs2.
 */

#define BP_MMDC_MPWRDQBY2DL_WR_DQ20_DEL      16
#define BM_MMDC_MPWRDQBY2DL_WR_DQ20_DEL      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY2DL_WR_DQ20_DEL(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPWRDQBY2DL_WR_DQ20_DEL)
#else
#define BF_MMDC_MPWRDQBY2DL_WR_DQ20_DEL(v)   (((v) << 16) & BM_MMDC_MPWRDQBY2DL_WR_DQ20_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY2DL_WR_DQ20_DEL(v)   BF_CS1(MMDC_MPWRDQBY2DL, WR_DQ20_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY2DL, field WR_DQ21_DEL
 *
 * Write dq21 delay fine tuning. This field holds the number of delay
 * units that are added to dq21 relative to dqs2.
 */

#define BP_MMDC_MPWRDQBY2DL_WR_DQ21_DEL      20
#define BM_MMDC_MPWRDQBY2DL_WR_DQ21_DEL      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY2DL_WR_DQ21_DEL(v)   ((((reg32_t) v) << 20) & BM_MMDC_MPWRDQBY2DL_WR_DQ21_DEL)
#else
#define BF_MMDC_MPWRDQBY2DL_WR_DQ21_DEL(v)   (((v) << 20) & BM_MMDC_MPWRDQBY2DL_WR_DQ21_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY2DL_WR_DQ21_DEL(v)   BF_CS1(MMDC_MPWRDQBY2DL, WR_DQ21_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY2DL, field WR_DQ22_DEL
 *
 * Write dq22 delay fine tuning. This field holds the number of delay
 * units that are added to dq22 relative to dqs2.
 */

#define BP_MMDC_MPWRDQBY2DL_WR_DQ22_DEL      24
#define BM_MMDC_MPWRDQBY2DL_WR_DQ22_DEL      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY2DL_WR_DQ22_DEL(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPWRDQBY2DL_WR_DQ22_DEL)
#else
#define BF_MMDC_MPWRDQBY2DL_WR_DQ22_DEL(v)   (((v) << 24) & BM_MMDC_MPWRDQBY2DL_WR_DQ22_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY2DL_WR_DQ22_DEL(v)   BF_CS1(MMDC_MPWRDQBY2DL, WR_DQ22_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY2DL, field WR_DQ23_DEL
 *
 * Write dq23 delay fine tuning. This field holds the number of delay
 * units that are added to dq23 relative to dqs2.
 */

#define BP_MMDC_MPWRDQBY2DL_WR_DQ23_DEL      28
#define BM_MMDC_MPWRDQBY2DL_WR_DQ23_DEL      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY2DL_WR_DQ23_DEL(v)   ((((reg32_t) v) << 28) & BM_MMDC_MPWRDQBY2DL_WR_DQ23_DEL)
#else
#define BF_MMDC_MPWRDQBY2DL_WR_DQ23_DEL(v)   (((v) << 28) & BM_MMDC_MPWRDQBY2DL_WR_DQ23_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY2DL_WR_DQ23_DEL(v)   BF_CS1(MMDC_MPWRDQBY2DL, WR_DQ23_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY2DL, field WR_DM2_DEL
 *
 * Write dm2 delay fine-tuning. This field holds the number of delay
 * units that are added to dm2 relative to dqs2.
 */

#define BP_MMDC_MPWRDQBY2DL_WR_DM2_DEL      30
#define BM_MMDC_MPWRDQBY2DL_WR_DM2_DEL      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY2DL_WR_DM2_DEL(v)   ((((reg32_t) v) << 30) & BM_MMDC_MPWRDQBY2DL_WR_DM2_DEL)
#else
#define BF_MMDC_MPWRDQBY2DL_WR_DM2_DEL(v)   (((v) << 30) & BM_MMDC_MPWRDQBY2DL_WR_DM2_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY2DL_WR_DM2_DEL(v)   BF_CS1(MMDC_MPWRDQBY2DL, WR_DM2_DEL, v)
#endif

/*!
 * @brief HW_MMDC_MPWRDQBY3DL - MMDC PHY Write DQ Byte3 Delay Register
 *
 * This register is used to add fine-tuning adjustment to every bit in the
 * write DQ byte3 relative to the write DQS  Supported Mode Of Operations:  For Channel 0: All  For
 * Channel 1: DDR3_x64, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WR_DQ24_DEL : 2; //!< Write dq24 delay fine tuning. This field holds the number of delay units that are added to dq24 relative to dqs3.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned WR_DQ25_DEL : 2; //!< Write dq25 delay fine tuning. This field holds the number of delay units that are added to dq25 relative to dqs3.
        unsigned RESERVED1 : 2; //!< Reserved
        unsigned WR_DQ26_DEL : 2; //!< Write dq26 delay fine tuning. This field holds the number of delay units that are added to dq26 relative to dqs3.
        unsigned RESERVED2 : 2; //!< Reserved
        unsigned WR_DQ27_DEL : 2; //!< Write dq27 delay fine tuning. This field holds the number of delay units that are added to dq27 relative to dqs3.
        unsigned RESERVED3 : 2; //!< Reserved
        unsigned WR_DQ28_DEL : 2; //!< Write dq28 delay fine tuning. This field holds the number of delay units that are added to dq28 relative to dqs3.
        unsigned RESERVED4 : 2; //!< Reserved
        unsigned WR_DQ29_DEL : 2; //!< Write dq29 delay fine tuning. This field holds the number of delay units that are added to dq29 relative to dqs3.
        unsigned RESERVED5 : 2; //!< Reserved
        unsigned WR_DQ30_DEL : 2; //!< Write dq30 delay fine tuning. This field holds the number of delay units that are added to dq30 relative to dqs3.
        unsigned RESERVED6 : 2; //!< Reserved
        unsigned WR_DQ31_DEL : 2; //!< Write dq31 delay fine tuning. This field holds the number of delay units that are added to dq31 relative to dqs3.
        unsigned WR_DM3_DEL : 2; //!< Write dm3 delay fine tuning. This field holds the number of delay units that are added to dm3 relative to dqs3.
    } B;
} hw_mmdc_mpwrdqby3dl_t;
#endif

/*
 * constants & macros for entire MMDC_MPWRDQBY3DL register
 */
#define HW_MMDC_MPWRDQBY3DL_ADDR      (REGS_MMDC_BASE + 0x838)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPWRDQBY3DL           (*(volatile hw_mmdc_mpwrdqby3dl_t *) HW_MMDC_MPWRDQBY3DL_ADDR)
#define HW_MMDC_MPWRDQBY3DL_RD()      (HW_MMDC_MPWRDQBY3DL.U)
#define HW_MMDC_MPWRDQBY3DL_WR(v)     (HW_MMDC_MPWRDQBY3DL.U = (v))
#define HW_MMDC_MPWRDQBY3DL_SET(v)    (HW_MMDC_MPWRDQBY3DL_WR(HW_MMDC_MPWRDQBY3DL_RD() |  (v)))
#define HW_MMDC_MPWRDQBY3DL_CLR(v)    (HW_MMDC_MPWRDQBY3DL_WR(HW_MMDC_MPWRDQBY3DL_RD() & ~(v)))
#define HW_MMDC_MPWRDQBY3DL_TOG(v)    (HW_MMDC_MPWRDQBY3DL_WR(HW_MMDC_MPWRDQBY3DL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPWRDQBY3DL bitfields
 */

/* --- Register HW_MMDC_MPWRDQBY3DL, field WR_DQ24_DEL
 *
 * Write dq24 delay fine tuning. This field holds the number of delay
 * units that are added to dq24 relative to dqs3.
 */

#define BP_MMDC_MPWRDQBY3DL_WR_DQ24_DEL      0
#define BM_MMDC_MPWRDQBY3DL_WR_DQ24_DEL      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY3DL_WR_DQ24_DEL(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPWRDQBY3DL_WR_DQ24_DEL)
#else
#define BF_MMDC_MPWRDQBY3DL_WR_DQ24_DEL(v)   (((v) << 0) & BM_MMDC_MPWRDQBY3DL_WR_DQ24_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY3DL_WR_DQ24_DEL(v)   BF_CS1(MMDC_MPWRDQBY3DL, WR_DQ24_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY3DL, field WR_DQ25_DEL
 *
 * Write dq25 delay fine tuning. This field holds the number of delay
 * units that are added to dq25 relative to dqs3.
 */

#define BP_MMDC_MPWRDQBY3DL_WR_DQ25_DEL      4
#define BM_MMDC_MPWRDQBY3DL_WR_DQ25_DEL      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY3DL_WR_DQ25_DEL(v)   ((((reg32_t) v) << 4) & BM_MMDC_MPWRDQBY3DL_WR_DQ25_DEL)
#else
#define BF_MMDC_MPWRDQBY3DL_WR_DQ25_DEL(v)   (((v) << 4) & BM_MMDC_MPWRDQBY3DL_WR_DQ25_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY3DL_WR_DQ25_DEL(v)   BF_CS1(MMDC_MPWRDQBY3DL, WR_DQ25_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY3DL, field WR_DQ26_DEL
 *
 * Write dq26 delay fine tuning. This field holds the number of delay
 * units that are added to dq26 relative to dqs3.
 */

#define BP_MMDC_MPWRDQBY3DL_WR_DQ26_DEL      8
#define BM_MMDC_MPWRDQBY3DL_WR_DQ26_DEL      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY3DL_WR_DQ26_DEL(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPWRDQBY3DL_WR_DQ26_DEL)
#else
#define BF_MMDC_MPWRDQBY3DL_WR_DQ26_DEL(v)   (((v) << 8) & BM_MMDC_MPWRDQBY3DL_WR_DQ26_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY3DL_WR_DQ26_DEL(v)   BF_CS1(MMDC_MPWRDQBY3DL, WR_DQ26_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY3DL, field WR_DQ27_DEL
 *
 * Write dq27 delay fine tuning. This field holds the number of delay
 * units that are added to dq27 relative to dqs3.
 */

#define BP_MMDC_MPWRDQBY3DL_WR_DQ27_DEL      12
#define BM_MMDC_MPWRDQBY3DL_WR_DQ27_DEL      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY3DL_WR_DQ27_DEL(v)   ((((reg32_t) v) << 12) & BM_MMDC_MPWRDQBY3DL_WR_DQ27_DEL)
#else
#define BF_MMDC_MPWRDQBY3DL_WR_DQ27_DEL(v)   (((v) << 12) & BM_MMDC_MPWRDQBY3DL_WR_DQ27_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY3DL_WR_DQ27_DEL(v)   BF_CS1(MMDC_MPWRDQBY3DL, WR_DQ27_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY3DL, field WR_DQ28_DEL
 *
 * Write dq28 delay fine tuning. This field holds the number of delay
 * units that are added to dq28 relative to dqs3.
 */

#define BP_MMDC_MPWRDQBY3DL_WR_DQ28_DEL      16
#define BM_MMDC_MPWRDQBY3DL_WR_DQ28_DEL      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY3DL_WR_DQ28_DEL(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPWRDQBY3DL_WR_DQ28_DEL)
#else
#define BF_MMDC_MPWRDQBY3DL_WR_DQ28_DEL(v)   (((v) << 16) & BM_MMDC_MPWRDQBY3DL_WR_DQ28_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY3DL_WR_DQ28_DEL(v)   BF_CS1(MMDC_MPWRDQBY3DL, WR_DQ28_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY3DL, field WR_DQ29_DEL
 *
 * Write dq29 delay fine tuning. This field holds the number of delay
 * units that are added to dq29 relative to dqs3.
 */

#define BP_MMDC_MPWRDQBY3DL_WR_DQ29_DEL      20
#define BM_MMDC_MPWRDQBY3DL_WR_DQ29_DEL      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY3DL_WR_DQ29_DEL(v)   ((((reg32_t) v) << 20) & BM_MMDC_MPWRDQBY3DL_WR_DQ29_DEL)
#else
#define BF_MMDC_MPWRDQBY3DL_WR_DQ29_DEL(v)   (((v) << 20) & BM_MMDC_MPWRDQBY3DL_WR_DQ29_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY3DL_WR_DQ29_DEL(v)   BF_CS1(MMDC_MPWRDQBY3DL, WR_DQ29_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY3DL, field WR_DQ30_DEL
 *
 * Write dq30 delay fine tuning. This field holds the number of delay
 * units that are added to dq30 relative to dqs3.
 */

#define BP_MMDC_MPWRDQBY3DL_WR_DQ30_DEL      24
#define BM_MMDC_MPWRDQBY3DL_WR_DQ30_DEL      0x03000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY3DL_WR_DQ30_DEL(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPWRDQBY3DL_WR_DQ30_DEL)
#else
#define BF_MMDC_MPWRDQBY3DL_WR_DQ30_DEL(v)   (((v) << 24) & BM_MMDC_MPWRDQBY3DL_WR_DQ30_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY3DL_WR_DQ30_DEL(v)   BF_CS1(MMDC_MPWRDQBY3DL, WR_DQ30_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY3DL, field WR_DQ31_DEL
 *
 * Write dq31 delay fine tuning. This field holds the number of delay
 * units that are added to dq31 relative to dqs3.
 */

#define BP_MMDC_MPWRDQBY3DL_WR_DQ31_DEL      28
#define BM_MMDC_MPWRDQBY3DL_WR_DQ31_DEL      0x30000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY3DL_WR_DQ31_DEL(v)   ((((reg32_t) v) << 28) & BM_MMDC_MPWRDQBY3DL_WR_DQ31_DEL)
#else
#define BF_MMDC_MPWRDQBY3DL_WR_DQ31_DEL(v)   (((v) << 28) & BM_MMDC_MPWRDQBY3DL_WR_DQ31_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY3DL_WR_DQ31_DEL(v)   BF_CS1(MMDC_MPWRDQBY3DL, WR_DQ31_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRDQBY3DL, field WR_DM3_DEL
 *
 * Write dm3 delay fine tuning. This field holds the number of delay
 * units that are added to dm3 relative to dqs3.
 */

#define BP_MMDC_MPWRDQBY3DL_WR_DM3_DEL      30
#define BM_MMDC_MPWRDQBY3DL_WR_DM3_DEL      0xc0000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDQBY3DL_WR_DM3_DEL(v)   ((((reg32_t) v) << 30) & BM_MMDC_MPWRDQBY3DL_WR_DM3_DEL)
#else
#define BF_MMDC_MPWRDQBY3DL_WR_DM3_DEL(v)   (((v) << 30) & BM_MMDC_MPWRDQBY3DL_WR_DM3_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDQBY3DL_WR_DM3_DEL(v)   BF_CS1(MMDC_MPWRDQBY3DL, WR_DM3_DEL, v)
#endif

/*!
 * @brief HW_MMDC_MPDGCTRL0 - MMDC PHY Read DQS Gating Control Register 0
 *
 * Supported Mode Of Operations:  For Channel 0: DDR3_x16, DDR3_x32, DDR3_x64  For Channel 1:
 * DDR3_x64
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DG_DL_ABS_OFFSET0 : 7; //!< Absolute read DQS gating delay offset for Byte0. This field indicates the absolute delay between read DQS gate and the middle of the read DQS preamble of Byte0 with fractions of a clock period and up to half cycle.The fraction is process and frequency independent. The delay of the delay-line would be (DG_DL_ABS_OFFSET0 / 256)* fast_clk.  This field can also bit written by HW. Upon completion of the automatic read DQS gating calibration this field gets the value of the 7 LSB of ((HW_DG_LOW0 + HW_DG_UP0) /2).  Note that not all changes will have effect on the actual delay. If the requested change is smaller than the delay-line resolution, then no change will occur.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned DG_HC_DEL0 : 4; //!< Read DQS gating half cycles delay for Byte0 (Channel 0 register) and Byte4 in 64-bit mode (Channel 1 register). This field indicates the delay in half cycles between read DQS gate and the middle of the read DQS preamble of Byte0/4. This delay is added to the delay that is genearted by the read DQS1 gating delay-line, So the total read DQS gating delay is (DG_HC_DEL#)*0.5*cycle + (DG_DL_ABS_OFFSET#)*1/256*cycle  Upon completion of the automatic read DQS gating calibration this field gets the value of the 4 MSB of ((HW_DG_LOW1 + HW_DG_UP1) /2).
        unsigned HW_DG_ERR : 1; //!< HW DQS gating error. This bit valid is asserted when an error was found during the read DQS gating HW calibration process. Error can occur when no valid value was found during HW calibration.  This bit is valid only after HW_DG_EN is de-asserted.
        unsigned RESERVED1 : 3; //!< Reserved
        unsigned DG_DL_ABS_OFFSET1 : 7; //!< Absolute read DQS gating delay offset for Byte1. This field indicates the absolute delay between read DQS gate and the middle of the read DQS preamble of Byte1 with fractions of a clock period and up to half cycle.The fraction is process and frequency independent. The delay of the delay-line would be (DG_DL_ABS_OFFSET1 / 256)* fast_clk.  This field can also bit written by HW. Upon completion of the automatic read DQS gating calibration this field gets the value of the 7 LSB of ((HW_DG_LOW1 + HW_DG_UP1) /2).  Note that not all changes will have effect on the actual delay. If the requested change is smaller than the delay-line resolution, then no change will occur.
        unsigned DG_EXT_UP : 1; //!< DG extend upper boundary. By default the upper boundary of DQS gating HW calibration is set according to first failing comparison after at least one passing comparison. If this bit is asserted then the upper boundary is set accroding to the last passing comparison.
        unsigned DG_HC_DEL1 : 4; //!< Read DQS gating half cycles delay for Byte1 (channel 0 register) and Byte5 in 64-bit mode (channel 1 register). This field indicates the delay in half cycles between read DQS gate and the middle of the read DQS preamble of Byte1. This delay is added to the delay that is genearted by the read DQS1 gating delay-line, So the total read DQS gating delay is (DG_HC_DEL#)*0.5*cycle + (DG_DL_ABS_OFFSET#)*1/256*cycle  Upon completion of the automatic read DQS gating calibration this field gets the value of the 4 MSB of ((HW_DG_LOW1 + HW_DG_UP1) /2).
        unsigned HW_DG_EN : 1; //!< Enable automatic read DQS gating calibration. If this bit is asserted then the MMDC performs automatic read DQS gating calibration. HW negates this bit upon completion of the automatic read DQS gating.  Note:  Before issuing the first read command the MMDC counts 12 cycles.  In LPDDR2 mode automatic (HW) read DQS gating should be disabled and Pull-up/pull-down resistors on DQS/DQS# should be enabled while ODT resistors must be disconnected.
        unsigned DG_DIS : 1; //!< Read DQS gating disable. If this bit is asserted then the MMDC disables the read DQS gating mechnism.  If this bits is asserted (read DQS gating is disabled) then pulll-up and pull-down resistors suppose to be used on DQS and DQS# respectively
        unsigned DG_CMP_CYC : 1; //!< Read DQS gating sample cycle. If this bit is asserted then the MMDC waits 32 cycles before comparing the read data, Otherwise it waits 16 DDR cycles.
        unsigned RST_RD_FIFO : 1; //!< Reset Read Data FIFO and associated pointers. If this bit is asserted then the MMDC resets the read data FIFO and the associated pointers. This bit is self cleared after the FIFO reset is done.
    } B;
} hw_mmdc_mpdgctrl0_t;
#endif

/*
 * constants & macros for entire MMDC_MPDGCTRL0 register
 */
#define HW_MMDC_MPDGCTRL0_ADDR      (REGS_MMDC_BASE + 0x83c)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPDGCTRL0           (*(volatile hw_mmdc_mpdgctrl0_t *) HW_MMDC_MPDGCTRL0_ADDR)
#define HW_MMDC_MPDGCTRL0_RD()      (HW_MMDC_MPDGCTRL0.U)
#define HW_MMDC_MPDGCTRL0_WR(v)     (HW_MMDC_MPDGCTRL0.U = (v))
#define HW_MMDC_MPDGCTRL0_SET(v)    (HW_MMDC_MPDGCTRL0_WR(HW_MMDC_MPDGCTRL0_RD() |  (v)))
#define HW_MMDC_MPDGCTRL0_CLR(v)    (HW_MMDC_MPDGCTRL0_WR(HW_MMDC_MPDGCTRL0_RD() & ~(v)))
#define HW_MMDC_MPDGCTRL0_TOG(v)    (HW_MMDC_MPDGCTRL0_WR(HW_MMDC_MPDGCTRL0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPDGCTRL0 bitfields
 */

/* --- Register HW_MMDC_MPDGCTRL0, field DG_DL_ABS_OFFSET0
 *
 * Absolute read DQS gating delay offset for Byte0. This field indicates
 * the absolute delay between read DQS gate and the middle of the read
 * DQS preamble of Byte0 with fractions of a clock period and up to
 * half cycle.The fraction is process and frequency independent. The
 * delay of the delay-line would be (DG_DL_ABS_OFFSET0 / 256)*
 * fast_clk.  This field can also bit written by HW. Upon completion of the
 * automatic read DQS gating calibration this field gets the value of
 * the 7 LSB of ((HW_DG_LOW0 + HW_DG_UP0) /2).  Note that not all changes will have effect on the
 * actual delay. If                                 the requested change is smaller than the delay-
 * line resolution, then                                 no change will occur.
 */

#define BP_MMDC_MPDGCTRL0_DG_DL_ABS_OFFSET0      0
#define BM_MMDC_MPDGCTRL0_DG_DL_ABS_OFFSET0      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGCTRL0_DG_DL_ABS_OFFSET0(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPDGCTRL0_DG_DL_ABS_OFFSET0)
#else
#define BF_MMDC_MPDGCTRL0_DG_DL_ABS_OFFSET0(v)   (((v) << 0) & BM_MMDC_MPDGCTRL0_DG_DL_ABS_OFFSET0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGCTRL0_DG_DL_ABS_OFFSET0(v)   BF_CS1(MMDC_MPDGCTRL0, DG_DL_ABS_OFFSET0, v)
#endif

/* --- Register HW_MMDC_MPDGCTRL0, field DG_HC_DEL0
 *
 * Read DQS gating half cycles delay for Byte0 (Channel 0 register) and Byte4 in 64-bit mode
 * (Channel 1 register). This field indicates the                                 delay in half
 * cycles between read DQS gate and the middle of the                                 read DQS
 * preamble of Byte0/4. This delay is added to the delay that is
 * genearted by the read DQS1 gating delay-line, So the total read DQS
 * gating delay is (DG_HC_DEL#)*0.5*cycle +
 * (DG_DL_ABS_OFFSET#)*1/256*cycle  Upon completion of the automatic read DQS gating calibration
 * this                                 field gets the value of the 4 MSB of ((HW_DG_LOW1 +
 * HW_DG_UP1)                                 /2).
 */

#define BP_MMDC_MPDGCTRL0_DG_HC_DEL0      8
#define BM_MMDC_MPDGCTRL0_DG_HC_DEL0      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGCTRL0_DG_HC_DEL0(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPDGCTRL0_DG_HC_DEL0)
#else
#define BF_MMDC_MPDGCTRL0_DG_HC_DEL0(v)   (((v) << 8) & BM_MMDC_MPDGCTRL0_DG_HC_DEL0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGCTRL0_DG_HC_DEL0(v)   BF_CS1(MMDC_MPDGCTRL0, DG_HC_DEL0, v)
#endif

/* --- Register HW_MMDC_MPDGCTRL0, field HW_DG_ERR
 *
 * HW DQS gating error. This bit valid is asserted when an error was
 * found during the read DQS gating HW calibration process. Error can
 * occur when no valid value was found during HW calibration.  This bit is valid only after HW_DG_EN
 * is de-asserted.
 */

#define BP_MMDC_MPDGCTRL0_HW_DG_ERR      12
#define BM_MMDC_MPDGCTRL0_HW_DG_ERR      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGCTRL0_HW_DG_ERR(v)   ((((reg32_t) v) << 12) & BM_MMDC_MPDGCTRL0_HW_DG_ERR)
#else
#define BF_MMDC_MPDGCTRL0_HW_DG_ERR(v)   (((v) << 12) & BM_MMDC_MPDGCTRL0_HW_DG_ERR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGCTRL0_HW_DG_ERR(v)   BF_CS1(MMDC_MPDGCTRL0, HW_DG_ERR, v)
#endif

/* --- Register HW_MMDC_MPDGCTRL0, field DG_DL_ABS_OFFSET1
 *
 * Absolute read DQS gating delay offset for Byte1. This field indicates
 * the absolute delay between read DQS gate and the middle of the read
 * DQS preamble of Byte1 with fractions of a clock period and up to
 * half cycle.The fraction is process and frequency independent. The
 * delay of the delay-line would be (DG_DL_ABS_OFFSET1 / 256)*
 * fast_clk.  This field can also bit written by HW. Upon completion of the
 * automatic read DQS gating calibration this field gets the value of
 * the 7 LSB of ((HW_DG_LOW1 + HW_DG_UP1) /2).  Note that not all changes will have effect on the
 * actual delay. If                                 the requested change is smaller than the delay-
 * line resolution, then                                 no change will occur.
 */

#define BP_MMDC_MPDGCTRL0_DG_DL_ABS_OFFSET1      16
#define BM_MMDC_MPDGCTRL0_DG_DL_ABS_OFFSET1      0x007f0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGCTRL0_DG_DL_ABS_OFFSET1(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPDGCTRL0_DG_DL_ABS_OFFSET1)
#else
#define BF_MMDC_MPDGCTRL0_DG_DL_ABS_OFFSET1(v)   (((v) << 16) & BM_MMDC_MPDGCTRL0_DG_DL_ABS_OFFSET1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGCTRL0_DG_DL_ABS_OFFSET1(v)   BF_CS1(MMDC_MPDGCTRL0, DG_DL_ABS_OFFSET1, v)
#endif

/* --- Register HW_MMDC_MPDGCTRL0, field DG_EXT_UP
 *
 * DG extend upper boundary. By default the upper boundary of DQS gating
 * HW calibration is set according to first failing comparison after at
 * least one passing comparison. If this bit is asserted then the upper
 * boundary is set accroding to the last passing comparison.
 */

#define BP_MMDC_MPDGCTRL0_DG_EXT_UP      23
#define BM_MMDC_MPDGCTRL0_DG_EXT_UP      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGCTRL0_DG_EXT_UP(v)   ((((reg32_t) v) << 23) & BM_MMDC_MPDGCTRL0_DG_EXT_UP)
#else
#define BF_MMDC_MPDGCTRL0_DG_EXT_UP(v)   (((v) << 23) & BM_MMDC_MPDGCTRL0_DG_EXT_UP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGCTRL0_DG_EXT_UP(v)   BF_CS1(MMDC_MPDGCTRL0, DG_EXT_UP, v)
#endif

/* --- Register HW_MMDC_MPDGCTRL0, field DG_HC_DEL1
 *
 * Read DQS gating half cycles delay for Byte1 (channel 0 register) and Byte5 in 64-bit mode
 * (channel 1 register). This field indicates the                                 delay in half
 * cycles between read DQS gate and the middle of the                                 read DQS
 * preamble of Byte1. This delay is added to the delay that is
 * genearted by the read DQS1 gating delay-line, So the total read DQS
 * gating delay is (DG_HC_DEL#)*0.5*cycle +
 * (DG_DL_ABS_OFFSET#)*1/256*cycle  Upon completion of the automatic read DQS gating calibration
 * this                                 field gets the value of the 4 MSB of ((HW_DG_LOW1 +
 * HW_DG_UP1)                                 /2).
 */

#define BP_MMDC_MPDGCTRL0_DG_HC_DEL1      24
#define BM_MMDC_MPDGCTRL0_DG_HC_DEL1      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGCTRL0_DG_HC_DEL1(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPDGCTRL0_DG_HC_DEL1)
#else
#define BF_MMDC_MPDGCTRL0_DG_HC_DEL1(v)   (((v) << 24) & BM_MMDC_MPDGCTRL0_DG_HC_DEL1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGCTRL0_DG_HC_DEL1(v)   BF_CS1(MMDC_MPDGCTRL0, DG_HC_DEL1, v)
#endif

/* --- Register HW_MMDC_MPDGCTRL0, field HW_DG_EN
 *
 * Enable automatic read DQS gating calibration. If this bit is asserted
 * then the MMDC performs automatic read DQS gating calibration. HW
 * negates this bit upon completion of the automatic read DQS
 * gating.  Note:  Before issuing the first read command the MMDC counts 12 cycles.  In LPDDR2 mode
 * automatic (HW) read DQS gating should be disabled and                                 Pull-up
 * /pull-down resistors on DQS/DQS# should be enabled while ODT
 * resistors must be disconnected.
 */

#define BP_MMDC_MPDGCTRL0_HW_DG_EN      28
#define BM_MMDC_MPDGCTRL0_HW_DG_EN      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGCTRL0_HW_DG_EN(v)   ((((reg32_t) v) << 28) & BM_MMDC_MPDGCTRL0_HW_DG_EN)
#else
#define BF_MMDC_MPDGCTRL0_HW_DG_EN(v)   (((v) << 28) & BM_MMDC_MPDGCTRL0_HW_DG_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGCTRL0_HW_DG_EN(v)   BF_CS1(MMDC_MPDGCTRL0, HW_DG_EN, v)
#endif

/* --- Register HW_MMDC_MPDGCTRL0, field DG_DIS
 *
 * Read DQS gating disable. If this bit is asserted then the MMDC
 * disables the read DQS gating mechnism.  If this bits is asserted (read DQS gating is disabled)
 * then pulll-up                                 and pull-down resistors suppose to be used on DQS
 * and DQS#                                 respectively
 */

#define BP_MMDC_MPDGCTRL0_DG_DIS      29
#define BM_MMDC_MPDGCTRL0_DG_DIS      0x20000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGCTRL0_DG_DIS(v)   ((((reg32_t) v) << 29) & BM_MMDC_MPDGCTRL0_DG_DIS)
#else
#define BF_MMDC_MPDGCTRL0_DG_DIS(v)   (((v) << 29) & BM_MMDC_MPDGCTRL0_DG_DIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGCTRL0_DG_DIS(v)   BF_CS1(MMDC_MPDGCTRL0, DG_DIS, v)
#endif

/* --- Register HW_MMDC_MPDGCTRL0, field DG_CMP_CYC
 *
 * Read DQS gating sample cycle. If this bit is asserted then the MMDC
 * waits 32 cycles before comparing the read data, Otherwise it waits
 * 16 DDR cycles.
 */

#define BP_MMDC_MPDGCTRL0_DG_CMP_CYC      30
#define BM_MMDC_MPDGCTRL0_DG_CMP_CYC      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGCTRL0_DG_CMP_CYC(v)   ((((reg32_t) v) << 30) & BM_MMDC_MPDGCTRL0_DG_CMP_CYC)
#else
#define BF_MMDC_MPDGCTRL0_DG_CMP_CYC(v)   (((v) << 30) & BM_MMDC_MPDGCTRL0_DG_CMP_CYC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGCTRL0_DG_CMP_CYC(v)   BF_CS1(MMDC_MPDGCTRL0, DG_CMP_CYC, v)
#endif

/* --- Register HW_MMDC_MPDGCTRL0, field RST_RD_FIFO
 *
 * Reset Read Data FIFO and associated pointers. If this bit is asserted
 * then the MMDC resets the read data FIFO and the associated pointers.
 * This bit is self cleared after the FIFO reset is done.
 */

#define BP_MMDC_MPDGCTRL0_RST_RD_FIFO      31
#define BM_MMDC_MPDGCTRL0_RST_RD_FIFO      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGCTRL0_RST_RD_FIFO(v)   ((((reg32_t) v) << 31) & BM_MMDC_MPDGCTRL0_RST_RD_FIFO)
#else
#define BF_MMDC_MPDGCTRL0_RST_RD_FIFO(v)   (((v) << 31) & BM_MMDC_MPDGCTRL0_RST_RD_FIFO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGCTRL0_RST_RD_FIFO(v)   BF_CS1(MMDC_MPDGCTRL0, RST_RD_FIFO, v)
#endif

/*!
 * @brief HW_MMDC_MPDGCTRL1 - MMDC PHY Read DQS Gating Control Register 1
 *
 * Supported Mode Of Operations:  For Channel 0: DDR3_x16, DDR3_x32, DDR3_x64  For Channel 1:
 * DDR3_x64
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DG_DL_ABS_OFFSET2 : 7; //!< Absolute read DQS gating delay offset for Byte2. This field indicates the absolute delay between read DQS gate and the middle of the read DQS preamble of Byte2 with fractions of a clock period and up to half cycle.The fraction is process and frequency independent. The delay of the delay-line would be (DG_DL_ABS_OFFSET2 / 256)* fast_clk.  This field can also bit written by HW. Upon completion of the automatic read DQS gating calibration this field gets the value of the 7 LSB of ((HW_DG_LOW2 + HW_DG_UP2) /2).  Note that not all changes will have effect on the actual delay. If the requested change is smaller than the delay-line resolution, then no change will occur.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned DG_HC_DEL2 : 4; //!< Read DQS gating half cycles delay for Byte2 (Channel 0 register) and Byte6 for 64-bit mode(channel 1 register). This field indicates the delay in half cycles between read DQS gate and the middle of the read DQS preamble of Byte2/5. This delay is added to the delay that is genearted by the read DQS1 gating delay-line, So the total read DQS gating delay is (DG_HC_DEL#)*0.5*cycle + (DG_DL_ABS_OFFSET#)*1/256*cycle  Upon completion of the automatic read DQS gating calibration this field gets the value of the 4 MSB of ((HW_DG_LOW2 + HW_DG_UP2) /2).
        unsigned RESERVED1 : 4; //!< Reserved
        unsigned DG_DL_ABS_OFFSET3 : 7; //!< Absolute read DQS gating delay offset for Byte3. This field indicates the absolute delay between read DQS gate and the middle of the read DQS preamble of Byte3 with fractions of a clock period and up to half cycle.The fraction is process and frequency independent. The delay of the delay-line would be (DG_DL_ABS_OFFSET3 / 256)* fast_clk.  This field can also bit written by HW. Upon completion of the automatic read DQS gating calibration this field gets the value of the 7 LSB of ((HW_DG_LOW3 + HW_DG_UP3) /2).  Note that not all changes will have effect on the actual delay. If the requested change is smaller than the delay-line resolution, then no change will occur.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned DG_HC_DEL3 : 4; //!< Read DQS gating half cycles delay for Byte3 (Channel 0 register) and Byte7 for 64-bit data (Channel 1 register). This field indicates the delay in half cycles between read DQS gate and the middle of the read DQS preamble of Byte3/7. This delay is added to the delay that is genearted by the read DQS1 gating delay-line, So the total read DQS gating delay is (DG_HC_DEL#)*0.5*cycle + (DG_DL_ABS_OFFSET#)*1/256*cycle  Upon completion of the automatic read DQS gating calibration this field gets the value of the 4 MSB of ((HW_DG_LOW3 + HW_DG_UP3) /2).
        unsigned RESERVED3 : 4; //!< Reserved
    } B;
} hw_mmdc_mpdgctrl1_t;
#endif

/*
 * constants & macros for entire MMDC_MPDGCTRL1 register
 */
#define HW_MMDC_MPDGCTRL1_ADDR      (REGS_MMDC_BASE + 0x840)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPDGCTRL1           (*(volatile hw_mmdc_mpdgctrl1_t *) HW_MMDC_MPDGCTRL1_ADDR)
#define HW_MMDC_MPDGCTRL1_RD()      (HW_MMDC_MPDGCTRL1.U)
#define HW_MMDC_MPDGCTRL1_WR(v)     (HW_MMDC_MPDGCTRL1.U = (v))
#define HW_MMDC_MPDGCTRL1_SET(v)    (HW_MMDC_MPDGCTRL1_WR(HW_MMDC_MPDGCTRL1_RD() |  (v)))
#define HW_MMDC_MPDGCTRL1_CLR(v)    (HW_MMDC_MPDGCTRL1_WR(HW_MMDC_MPDGCTRL1_RD() & ~(v)))
#define HW_MMDC_MPDGCTRL1_TOG(v)    (HW_MMDC_MPDGCTRL1_WR(HW_MMDC_MPDGCTRL1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPDGCTRL1 bitfields
 */

/* --- Register HW_MMDC_MPDGCTRL1, field DG_DL_ABS_OFFSET2
 *
 * Absolute read DQS gating delay offset for Byte2. This field indicates
 * the absolute delay between read DQS gate and the middle of the read
 * DQS preamble of Byte2 with fractions of a clock period and up to
 * half cycle.The fraction is process and frequency independent. The
 * delay of the delay-line would be (DG_DL_ABS_OFFSET2 / 256)*
 * fast_clk.  This field can also bit written by HW. Upon completion of the
 * automatic read DQS gating calibration this field gets the value of
 * the 7 LSB of ((HW_DG_LOW2 + HW_DG_UP2) /2).  Note that not all changes will have effect on the
 * actual delay. If                                 the requested change is smaller than the delay-
 * line resolution, then                                 no change will occur.
 */

#define BP_MMDC_MPDGCTRL1_DG_DL_ABS_OFFSET2      0
#define BM_MMDC_MPDGCTRL1_DG_DL_ABS_OFFSET2      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGCTRL1_DG_DL_ABS_OFFSET2(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPDGCTRL1_DG_DL_ABS_OFFSET2)
#else
#define BF_MMDC_MPDGCTRL1_DG_DL_ABS_OFFSET2(v)   (((v) << 0) & BM_MMDC_MPDGCTRL1_DG_DL_ABS_OFFSET2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGCTRL1_DG_DL_ABS_OFFSET2(v)   BF_CS1(MMDC_MPDGCTRL1, DG_DL_ABS_OFFSET2, v)
#endif

/* --- Register HW_MMDC_MPDGCTRL1, field DG_HC_DEL2
 *
 * Read DQS gating half cycles delay for Byte2 (Channel 0 register) and Byte6 for 64-bit
 * mode(channel 1 register). This field indicates the                                 delay in half
 * cycles between read DQS gate and the middle of the                                 read DQS
 * preamble of Byte2/5. This delay is added to the delay that is
 * genearted by the read DQS1 gating delay-line, So the total read DQS
 * gating delay is (DG_HC_DEL#)*0.5*cycle +
 * (DG_DL_ABS_OFFSET#)*1/256*cycle  Upon completion of the automatic read DQS gating calibration
 * this                                 field gets the value of the 4 MSB of ((HW_DG_LOW2 +
 * HW_DG_UP2)                                 /2).
 */

#define BP_MMDC_MPDGCTRL1_DG_HC_DEL2      8
#define BM_MMDC_MPDGCTRL1_DG_HC_DEL2      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGCTRL1_DG_HC_DEL2(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPDGCTRL1_DG_HC_DEL2)
#else
#define BF_MMDC_MPDGCTRL1_DG_HC_DEL2(v)   (((v) << 8) & BM_MMDC_MPDGCTRL1_DG_HC_DEL2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGCTRL1_DG_HC_DEL2(v)   BF_CS1(MMDC_MPDGCTRL1, DG_HC_DEL2, v)
#endif

/* --- Register HW_MMDC_MPDGCTRL1, field DG_DL_ABS_OFFSET3
 *
 * Absolute read DQS gating delay offset for Byte3. This field indicates
 * the absolute delay between read DQS gate and the middle of the read
 * DQS preamble of Byte3 with fractions of a clock period and up to
 * half cycle.The fraction is process and frequency independent. The
 * delay of the delay-line would be (DG_DL_ABS_OFFSET3 / 256)*
 * fast_clk.  This field can also bit written by HW. Upon completion of the
 * automatic read DQS gating calibration this field gets the value of
 * the 7 LSB of ((HW_DG_LOW3 + HW_DG_UP3) /2).  Note that not all changes will have effect on the
 * actual delay. If                                 the requested change is smaller than the delay-
 * line resolution, then                                 no change will occur.
 */

#define BP_MMDC_MPDGCTRL1_DG_DL_ABS_OFFSET3      16
#define BM_MMDC_MPDGCTRL1_DG_DL_ABS_OFFSET3      0x007f0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGCTRL1_DG_DL_ABS_OFFSET3(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPDGCTRL1_DG_DL_ABS_OFFSET3)
#else
#define BF_MMDC_MPDGCTRL1_DG_DL_ABS_OFFSET3(v)   (((v) << 16) & BM_MMDC_MPDGCTRL1_DG_DL_ABS_OFFSET3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGCTRL1_DG_DL_ABS_OFFSET3(v)   BF_CS1(MMDC_MPDGCTRL1, DG_DL_ABS_OFFSET3, v)
#endif

/* --- Register HW_MMDC_MPDGCTRL1, field DG_HC_DEL3
 *
 * Read DQS gating half cycles delay for Byte3 (Channel 0 register) and Byte7 for 64-bit data
 * (Channel 1 register). This field indicates the                                 delay in half
 * cycles between read DQS gate and the middle of the                                 read DQS
 * preamble of Byte3/7. This delay is added to the delay that is
 * genearted by the read DQS1 gating delay-line, So the total read DQS
 * gating delay is (DG_HC_DEL#)*0.5*cycle +
 * (DG_DL_ABS_OFFSET#)*1/256*cycle  Upon completion of the automatic read DQS gating calibration
 * this                                 field gets the value of the 4 MSB of ((HW_DG_LOW3 +
 * HW_DG_UP3)                                 /2).
 */

#define BP_MMDC_MPDGCTRL1_DG_HC_DEL3      24
#define BM_MMDC_MPDGCTRL1_DG_HC_DEL3      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGCTRL1_DG_HC_DEL3(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPDGCTRL1_DG_HC_DEL3)
#else
#define BF_MMDC_MPDGCTRL1_DG_HC_DEL3(v)   (((v) << 24) & BM_MMDC_MPDGCTRL1_DG_HC_DEL3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGCTRL1_DG_HC_DEL3(v)   BF_CS1(MMDC_MPDGCTRL1, DG_HC_DEL3, v)
#endif

/*!
 * @brief HW_MMDC_MPDGDLST0 - MMDC PHY Read DQS Gating delay-line Status                        Register
 *
 * This register holds the status of the 4 dqs gating delay-lines.  Supported Mode Of Operations:
 * For Channel 0: DDR3_x16, DDR3_x32, DDR3_x64  For Channel 1: DDR3_x64
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DG_DL_UNIT_NUM0 : 7; //!< This field reflects the number of delay units that are actually used by read DQS gating delay-line 0.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned DG_DL_UNIT_NUM1 : 7; //!< This field reflects the number of delay units that are actually used by read DQS gating delay-line 1.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned DG_DL_UNIT_NUM2 : 7; //!< This field reflects the number of delay units that are actually used by read DQS gating delay-line 2.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned DG_DL_UNIT_NUM3 : 7; //!< This field reflects the number of delay units that are actually used by read DQS gating delay-line 3.
        unsigned RESERVED3 : 1; //!< Reserved
    } B;
} hw_mmdc_mpdgdlst0_t;
#endif

/*
 * constants & macros for entire MMDC_MPDGDLST0 register
 */
#define HW_MMDC_MPDGDLST0_ADDR      (REGS_MMDC_BASE + 0x844)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPDGDLST0           (*(volatile hw_mmdc_mpdgdlst0_t *) HW_MMDC_MPDGDLST0_ADDR)
#define HW_MMDC_MPDGDLST0_RD()      (HW_MMDC_MPDGDLST0.U)
#define HW_MMDC_MPDGDLST0_WR(v)     (HW_MMDC_MPDGDLST0.U = (v))
#define HW_MMDC_MPDGDLST0_SET(v)    (HW_MMDC_MPDGDLST0_WR(HW_MMDC_MPDGDLST0_RD() |  (v)))
#define HW_MMDC_MPDGDLST0_CLR(v)    (HW_MMDC_MPDGDLST0_WR(HW_MMDC_MPDGDLST0_RD() & ~(v)))
#define HW_MMDC_MPDGDLST0_TOG(v)    (HW_MMDC_MPDGDLST0_WR(HW_MMDC_MPDGDLST0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPDGDLST0 bitfields
 */

/* --- Register HW_MMDC_MPDGDLST0, field DG_DL_UNIT_NUM0
 *
 * This field reflects the number of delay units that are actually used
 * by read DQS gating delay-line 0.
 */

#define BP_MMDC_MPDGDLST0_DG_DL_UNIT_NUM0      0
#define BM_MMDC_MPDGDLST0_DG_DL_UNIT_NUM0      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGDLST0_DG_DL_UNIT_NUM0(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPDGDLST0_DG_DL_UNIT_NUM0)
#else
#define BF_MMDC_MPDGDLST0_DG_DL_UNIT_NUM0(v)   (((v) << 0) & BM_MMDC_MPDGDLST0_DG_DL_UNIT_NUM0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGDLST0_DG_DL_UNIT_NUM0(v)   BF_CS1(MMDC_MPDGDLST0, DG_DL_UNIT_NUM0, v)
#endif

/* --- Register HW_MMDC_MPDGDLST0, field DG_DL_UNIT_NUM1
 *
 * This field reflects the number of delay units that are actually used
 * by read DQS gating delay-line 1.
 */

#define BP_MMDC_MPDGDLST0_DG_DL_UNIT_NUM1      8
#define BM_MMDC_MPDGDLST0_DG_DL_UNIT_NUM1      0x00007f00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGDLST0_DG_DL_UNIT_NUM1(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPDGDLST0_DG_DL_UNIT_NUM1)
#else
#define BF_MMDC_MPDGDLST0_DG_DL_UNIT_NUM1(v)   (((v) << 8) & BM_MMDC_MPDGDLST0_DG_DL_UNIT_NUM1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGDLST0_DG_DL_UNIT_NUM1(v)   BF_CS1(MMDC_MPDGDLST0, DG_DL_UNIT_NUM1, v)
#endif

/* --- Register HW_MMDC_MPDGDLST0, field DG_DL_UNIT_NUM2
 *
 * This field reflects the number of delay units that are actually used
 * by read DQS gating delay-line 2.
 */

#define BP_MMDC_MPDGDLST0_DG_DL_UNIT_NUM2      16
#define BM_MMDC_MPDGDLST0_DG_DL_UNIT_NUM2      0x007f0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGDLST0_DG_DL_UNIT_NUM2(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPDGDLST0_DG_DL_UNIT_NUM2)
#else
#define BF_MMDC_MPDGDLST0_DG_DL_UNIT_NUM2(v)   (((v) << 16) & BM_MMDC_MPDGDLST0_DG_DL_UNIT_NUM2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGDLST0_DG_DL_UNIT_NUM2(v)   BF_CS1(MMDC_MPDGDLST0, DG_DL_UNIT_NUM2, v)
#endif

/* --- Register HW_MMDC_MPDGDLST0, field DG_DL_UNIT_NUM3
 *
 * This field reflects the number of delay units that are actually used
 * by read DQS gating delay-line 3.
 */

#define BP_MMDC_MPDGDLST0_DG_DL_UNIT_NUM3      24
#define BM_MMDC_MPDGDLST0_DG_DL_UNIT_NUM3      0x7f000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGDLST0_DG_DL_UNIT_NUM3(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPDGDLST0_DG_DL_UNIT_NUM3)
#else
#define BF_MMDC_MPDGDLST0_DG_DL_UNIT_NUM3(v)   (((v) << 24) & BM_MMDC_MPDGDLST0_DG_DL_UNIT_NUM3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGDLST0_DG_DL_UNIT_NUM3(v)   BF_CS1(MMDC_MPDGDLST0, DG_DL_UNIT_NUM3, v)
#endif

/*!
 * @brief HW_MMDC_MPRDDLCTL - MMDC PHY Read delay-lines Configuration                        Register
 *
 * This register controls read delay-lines functionality; it determines DQS
 * delay relative to the associated DQ read access. The delay-line
 * compensates for process variations and produces a constant delay
 * regardless of the process, temperature and voltage.  Supported Mode Of Operations:  For Channel
 * 0: All  For Channel 1: DDR3_x64, LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RD_DL_ABS_OFFSET0 : 7; //!< Absolute read delay offset for Byte0. This field indicates the absolute delay between read DQS strobe and the read data of Byte0 with fractions of a clock period and up to half cycle. The fraction is process and frequency independent. The delay of the delay-line would be (RD_DL_ABS_OFFSET0 / 256) * fast_clk. So for the default value of 64 we get a quarter cycle delay.  This field can also bit written by HW. Upon completion of the read delay-line HW calibration this field gets the value of (HW_RD_DL_LOW0 + HW_RD_DL_UP0) /2  Note that not all changes will have effect on the actual delay. If the requested change is smaller than the delay-line resolution, then no change will occur.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned RD_DL_ABS_OFFSET1 : 7; //!< Absolute read delay offset for Byte1. This field indicates the absolute delay between read DQS strobe and the read data of Byte1 with fractions of a clock period and up to half cycle. The fraction is process and frequency independent. The delay of the delay-line would be (RD_DL_ABS_OFFSET1 / 256) * fast_clk. So for the default value of 64 we get a quarter cycle delay.  This field can also bit written by HW. Upon completion of the read delay-line HW calibration this field gets the value of (HW_RD_DL_LOW1 + HW_RD_DL_UP1) /2  Note that not all changes will have effect on the actual delay. If the requested change is smaller than the delay-line resolution, then no change will occur.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned RD_DL_ABS_OFFSET2 : 7; //!< Absolute read delay offset for Byte2. This field indicates the absolute delay between read DQS strobe and the read data of Byte2 with fractions of a clock period and up to half cycle. The fraction is process and frequency independent. The delay of the delay-line would be (RD_DL_ABS_OFFSET2 / 256) * fast_clk. So for the default value of 64 we get a quarter cycle delay.  This field can also bit written by HW. Upon completion of the read delay-line HW calibration this field gets the value of (HW_RD_DL_LOW2 + HW_RD_DL_UP2) /2  Note that not all changes will have effect on the actual delay. If the requested change is smaller than the delay-line resolution, then no change will occur.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned RD_DL_ABS_OFFSET3 : 7; //!< Absolute read delay offset for Byte3. This field indicates the absolute delay between read DQS strobe and the read data of Byte3 with fractions of a clock period and up to half cycle. The fraction is process and frequency independent. The delay of the delay-line would be (RD_DL_ABS_OFFSET3 / 256) * fast_clk. So for the default value of 64 we get a quarter cycle delay.  This field can also bit written by HW. Upon completion of the read delay-line HW calibration this field gets the value of (HW_RD_DL_LOW3 + HW_RD_DL_UP3) /2  Note that not all changes will have effect on the actual delay. If the requested change is smaller than the delay-line resolution, then no change will occur.
        unsigned RESERVED3 : 1; //!< Reserved
    } B;
} hw_mmdc_mprddlctl_t;
#endif

/*
 * constants & macros for entire MMDC_MPRDDLCTL register
 */
#define HW_MMDC_MPRDDLCTL_ADDR      (REGS_MMDC_BASE + 0x848)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPRDDLCTL           (*(volatile hw_mmdc_mprddlctl_t *) HW_MMDC_MPRDDLCTL_ADDR)
#define HW_MMDC_MPRDDLCTL_RD()      (HW_MMDC_MPRDDLCTL.U)
#define HW_MMDC_MPRDDLCTL_WR(v)     (HW_MMDC_MPRDDLCTL.U = (v))
#define HW_MMDC_MPRDDLCTL_SET(v)    (HW_MMDC_MPRDDLCTL_WR(HW_MMDC_MPRDDLCTL_RD() |  (v)))
#define HW_MMDC_MPRDDLCTL_CLR(v)    (HW_MMDC_MPRDDLCTL_WR(HW_MMDC_MPRDDLCTL_RD() & ~(v)))
#define HW_MMDC_MPRDDLCTL_TOG(v)    (HW_MMDC_MPRDDLCTL_WR(HW_MMDC_MPRDDLCTL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPRDDLCTL bitfields
 */

/* --- Register HW_MMDC_MPRDDLCTL, field RD_DL_ABS_OFFSET0
 *
 * Absolute read delay offset for Byte0. This field indicates the
 * absolute delay between read DQS strobe and the read data of Byte0
 * with fractions of a clock period and up to half cycle. The fraction
 * is process and frequency independent. The delay of the delay-line
 * would be (RD_DL_ABS_OFFSET0 / 256) * fast_clk. So for the default
 * value of 64 we get a quarter cycle delay.  This field can also bit written by HW. Upon completion
 * of the read                                 delay-line HW calibration this field gets the value
 * of                                 (HW_RD_DL_LOW0 + HW_RD_DL_UP0) /2  Note that not all changes
 * will have effect on the actual delay. If                                 the requested change is
 * smaller than the delay-line resolution, then                                 no change will
 * occur.
 */

#define BP_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET0      0
#define BM_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET0      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET0(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET0)
#else
#define BF_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET0(v)   (((v) << 0) & BM_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET0(v)   BF_CS1(MMDC_MPRDDLCTL, RD_DL_ABS_OFFSET0, v)
#endif

/* --- Register HW_MMDC_MPRDDLCTL, field RD_DL_ABS_OFFSET1
 *
 * Absolute read delay offset for Byte1. This field indicates the
 * absolute delay between read DQS strobe and the read data of Byte1
 * with fractions of a clock period and up to half cycle. The fraction
 * is process and frequency independent. The delay of the delay-line
 * would be (RD_DL_ABS_OFFSET1 / 256) * fast_clk. So for the default
 * value of 64 we get a quarter cycle delay.  This field can also bit written by HW. Upon completion
 * of the read                                 delay-line HW calibration this field gets the value
 * of                                 (HW_RD_DL_LOW1 + HW_RD_DL_UP1) /2  Note that not all changes
 * will have effect on the actual delay. If                                 the requested change is
 * smaller than the delay-line resolution, then                                 no change will
 * occur.
 */

#define BP_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET1      8
#define BM_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET1      0x00007f00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET1(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET1)
#else
#define BF_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET1(v)   (((v) << 8) & BM_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET1(v)   BF_CS1(MMDC_MPRDDLCTL, RD_DL_ABS_OFFSET1, v)
#endif

/* --- Register HW_MMDC_MPRDDLCTL, field RD_DL_ABS_OFFSET2
 *
 * Absolute read delay offset for Byte2. This field indicates the
 * absolute delay between read DQS strobe and the read data of Byte2
 * with fractions of a clock period and up to half cycle. The fraction
 * is process and frequency independent. The delay of the delay-line
 * would be (RD_DL_ABS_OFFSET2 / 256) * fast_clk. So for the default
 * value of 64 we get a quarter cycle delay.  This field can also bit written by HW. Upon completion
 * of the read                                 delay-line HW calibration this field gets the value
 * of                                 (HW_RD_DL_LOW2 + HW_RD_DL_UP2) /2  Note that not all changes
 * will have effect on the actual delay. If                                 the requested change is
 * smaller than the delay-line resolution, then                                 no change will
 * occur.
 */

#define BP_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET2      16
#define BM_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET2      0x007f0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET2(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET2)
#else
#define BF_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET2(v)   (((v) << 16) & BM_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET2(v)   BF_CS1(MMDC_MPRDDLCTL, RD_DL_ABS_OFFSET2, v)
#endif

/* --- Register HW_MMDC_MPRDDLCTL, field RD_DL_ABS_OFFSET3
 *
 * Absolute read delay offset for Byte3. This field indicates the
 * absolute delay between read DQS strobe and the read data of Byte3
 * with fractions of a clock period and up to half cycle. The fraction
 * is process and frequency independent. The delay of the delay-line
 * would be (RD_DL_ABS_OFFSET3 / 256) * fast_clk. So for the default
 * value of 64 we get a quarter cycle delay.  This field can also bit written by HW. Upon completion
 * of the read                                 delay-line HW calibration this field gets the value
 * of                                 (HW_RD_DL_LOW3 + HW_RD_DL_UP3) /2  Note that not all changes
 * will have effect on the actual delay. If                                 the requested change is
 * smaller than the delay-line resolution, then                                 no change will
 * occur.
 */

#define BP_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET3      24
#define BM_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET3      0x7f000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET3(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET3)
#else
#define BF_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET3(v)   (((v) << 24) & BM_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDLCTL_RD_DL_ABS_OFFSET3(v)   BF_CS1(MMDC_MPRDDLCTL, RD_DL_ABS_OFFSET3, v)
#endif

/*!
 * @brief HW_MMDC_MPRDDLST - MMDC PHY Read delay-lines Status Register
 *
 * This register holds the status of the 4 read delay-lines.  Supported Mode Of Operations:  For
 * Channel 0: All  For Channel 1: DDR3_x64, LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RD_DL_UNIT_NUM0 : 7; //!< This field reflects the number of delay units that are actually used by read delay-line 0.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned RD_DL_UNIT_NUM1 : 7; //!< This field reflects the number of delay units that are actually used by read delay-line 1.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned RD_DL_UNIT_NUM2 : 7; //!< This field reflects the number of delay units that are actually used by read delay-line 2.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned RD_DL_UNIT_NUM3 : 7; //!< This field reflects the number of delay units that are actually used by read delay-line 3.
        unsigned RESERVED3 : 1; //!< Reserved
    } B;
} hw_mmdc_mprddlst_t;
#endif

/*
 * constants & macros for entire MMDC_MPRDDLST register
 */
#define HW_MMDC_MPRDDLST_ADDR      (REGS_MMDC_BASE + 0x84c)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPRDDLST           (*(volatile hw_mmdc_mprddlst_t *) HW_MMDC_MPRDDLST_ADDR)
#define HW_MMDC_MPRDDLST_RD()      (HW_MMDC_MPRDDLST.U)
#define HW_MMDC_MPRDDLST_WR(v)     (HW_MMDC_MPRDDLST.U = (v))
#define HW_MMDC_MPRDDLST_SET(v)    (HW_MMDC_MPRDDLST_WR(HW_MMDC_MPRDDLST_RD() |  (v)))
#define HW_MMDC_MPRDDLST_CLR(v)    (HW_MMDC_MPRDDLST_WR(HW_MMDC_MPRDDLST_RD() & ~(v)))
#define HW_MMDC_MPRDDLST_TOG(v)    (HW_MMDC_MPRDDLST_WR(HW_MMDC_MPRDDLST_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPRDDLST bitfields
 */

/* --- Register HW_MMDC_MPRDDLST, field RD_DL_UNIT_NUM0
 *
 * This field reflects the number of delay units that are actually used
 * by read delay-line 0.
 */

#define BP_MMDC_MPRDDLST_RD_DL_UNIT_NUM0      0
#define BM_MMDC_MPRDDLST_RD_DL_UNIT_NUM0      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDLST_RD_DL_UNIT_NUM0(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPRDDLST_RD_DL_UNIT_NUM0)
#else
#define BF_MMDC_MPRDDLST_RD_DL_UNIT_NUM0(v)   (((v) << 0) & BM_MMDC_MPRDDLST_RD_DL_UNIT_NUM0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDLST_RD_DL_UNIT_NUM0(v)   BF_CS1(MMDC_MPRDDLST, RD_DL_UNIT_NUM0, v)
#endif

/* --- Register HW_MMDC_MPRDDLST, field RD_DL_UNIT_NUM1
 *
 * This field reflects the number of delay units that are actually used
 * by read delay-line 1.
 */

#define BP_MMDC_MPRDDLST_RD_DL_UNIT_NUM1      8
#define BM_MMDC_MPRDDLST_RD_DL_UNIT_NUM1      0x00007f00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDLST_RD_DL_UNIT_NUM1(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPRDDLST_RD_DL_UNIT_NUM1)
#else
#define BF_MMDC_MPRDDLST_RD_DL_UNIT_NUM1(v)   (((v) << 8) & BM_MMDC_MPRDDLST_RD_DL_UNIT_NUM1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDLST_RD_DL_UNIT_NUM1(v)   BF_CS1(MMDC_MPRDDLST, RD_DL_UNIT_NUM1, v)
#endif

/* --- Register HW_MMDC_MPRDDLST, field RD_DL_UNIT_NUM2
 *
 * This field reflects the number of delay units that are actually used
 * by read delay-line 2.
 */

#define BP_MMDC_MPRDDLST_RD_DL_UNIT_NUM2      16
#define BM_MMDC_MPRDDLST_RD_DL_UNIT_NUM2      0x007f0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDLST_RD_DL_UNIT_NUM2(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPRDDLST_RD_DL_UNIT_NUM2)
#else
#define BF_MMDC_MPRDDLST_RD_DL_UNIT_NUM2(v)   (((v) << 16) & BM_MMDC_MPRDDLST_RD_DL_UNIT_NUM2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDLST_RD_DL_UNIT_NUM2(v)   BF_CS1(MMDC_MPRDDLST, RD_DL_UNIT_NUM2, v)
#endif

/* --- Register HW_MMDC_MPRDDLST, field RD_DL_UNIT_NUM3
 *
 * This field reflects the number of delay units that are actually used
 * by read delay-line 3.
 */

#define BP_MMDC_MPRDDLST_RD_DL_UNIT_NUM3      24
#define BM_MMDC_MPRDDLST_RD_DL_UNIT_NUM3      0x7f000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDLST_RD_DL_UNIT_NUM3(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPRDDLST_RD_DL_UNIT_NUM3)
#else
#define BF_MMDC_MPRDDLST_RD_DL_UNIT_NUM3(v)   (((v) << 24) & BM_MMDC_MPRDDLST_RD_DL_UNIT_NUM3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDLST_RD_DL_UNIT_NUM3(v)   BF_CS1(MMDC_MPRDDLST, RD_DL_UNIT_NUM3, v)
#endif

/*!
 * @brief HW_MMDC_MPWRDLCTL - MMDC PHY Write delay-lines Configuration                        Register
 *
 * This register controls write delay-lines functionality, it determines
 * DQ/DM delay relative to the associated DQS in write access. The
 * delay-line compensates for process variations, and produces a constant
 * delay regardless of the process, temperature and voltage.  Supported Mode Of Operations:  For
 * Channel 0: All  For Channel 1: DDR3_x64, LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WR_DL_ABS_OFFSET0 : 7; //!< Absolute write delay offset for Byte0. This field indicates the absolute delay between write DQS strobe and the write data of Byte3 with fractions of a clock period and up to half cycle. The fraction is process and frequency independent. The delay of the delay-line would be (WR_DL_ABS_OFFSET0 / 256) * fast_clk. So for the default value of 64 we get a quarter cycle delay.  This field can also bit written by HW. Upon completion of the write delay-line HW calibration this field gets the value of (HW_WR_DL_LOW0 + HW_WR_DL_UP0) /2  Note that not all changes of this value will affect the actual delay. If the requested change is smaller than the delay-line resolution, then no change will occur.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned WR_DL_ABS_OFFSET1 : 7; //!< Absolute write delay offset for Byte1. This field indicates the absolute delay between write DQS strobe and the write data of Byte1 with fractions of a clock period and up to half cycle. The fraction is process and frequency independent. The delay of the delay-line would be (WR_DL_ABS_OFFSET1 / 256) * fast_clk. So for the default value of 64 we get a quarter cycle delay.  This field can also bit written by HW. Upon completion of the write delay-line HW calibration this field gets the value of (HW_WR_DL_LOW1 + HW_WR_DL_UP1) /2  Note that not all changes of this value will affect the actual delay. If the requested change is smaller than the delay-line resolution, then no change will occur.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned WR_DL_ABS_OFFSET2 : 7; //!< Absolute write delay offset for Byte2. This field indicates the absolute delay between write DQS strobe and the write data of Byte2 with fractions of a clock period and up to half cycle. The fraction is process and frequency independent. The delay of the delay-line would be (WR_DL_ABS_OFFSET2/ 256) * fast_clk. So for the default value of 64 we get a quarter cycle delay.  This field can also bit written by HW. Upon completion of the write delay-line HW calibration this field gets the value of (HW_WR_DL_LOW2 + HW_WR_DL_UP2) /2  Note that not all changes will have effect on the actual delay. If the requested change is smaller than the delay-line resolution, then no change will occur.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned WR_DL_ABS_OFFSET3 : 7; //!< Absolute write delay offset for Byte3. This field indicates the absolute delay between write DQS strobe and the write data of Byte3 with fractions of a clock period and up to half cycle. The fraction is process and frequency independent. The delay of the delay-line would be (WR_DL_ABS_OFFSET3 / 256) * fast_clk. So for the default value of 64 we get a quarter cycle delay.  This field can also bit written by HW. Upon completion of the write delay-line HW calibration this field gets the value of (HW_WR_DL_LOW3 + HW_WR_DL_UP3) /2  Note that not all changes will have effect on the actual delay. If the requested change is smaller than the delay-line resolution, then no change will occur.
        unsigned RESERVED3 : 1; //!< Reserved
    } B;
} hw_mmdc_mpwrdlctl_t;
#endif

/*
 * constants & macros for entire MMDC_MPWRDLCTL register
 */
#define HW_MMDC_MPWRDLCTL_ADDR      (REGS_MMDC_BASE + 0x850)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPWRDLCTL           (*(volatile hw_mmdc_mpwrdlctl_t *) HW_MMDC_MPWRDLCTL_ADDR)
#define HW_MMDC_MPWRDLCTL_RD()      (HW_MMDC_MPWRDLCTL.U)
#define HW_MMDC_MPWRDLCTL_WR(v)     (HW_MMDC_MPWRDLCTL.U = (v))
#define HW_MMDC_MPWRDLCTL_SET(v)    (HW_MMDC_MPWRDLCTL_WR(HW_MMDC_MPWRDLCTL_RD() |  (v)))
#define HW_MMDC_MPWRDLCTL_CLR(v)    (HW_MMDC_MPWRDLCTL_WR(HW_MMDC_MPWRDLCTL_RD() & ~(v)))
#define HW_MMDC_MPWRDLCTL_TOG(v)    (HW_MMDC_MPWRDLCTL_WR(HW_MMDC_MPWRDLCTL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPWRDLCTL bitfields
 */

/* --- Register HW_MMDC_MPWRDLCTL, field WR_DL_ABS_OFFSET0
 *
 * Absolute write delay offset for Byte0. This field indicates the
 * absolute delay between write DQS strobe and the write data of Byte3
 * with fractions of a clock period and up to half cycle. The fraction
 * is process and frequency independent. The delay of the delay-line
 * would be (WR_DL_ABS_OFFSET0 / 256) * fast_clk. So for the default
 * value of 64 we get a quarter cycle delay.  This field can also bit written by HW. Upon completion
 * of the write                                 delay-line HW calibration this field gets the value
 * of                                 (HW_WR_DL_LOW0 + HW_WR_DL_UP0) /2  Note that not all changes
 * of this value will affect the actual delay.                                 If the requested
 * change is smaller than the delay-line resolution,                                 then no change
 * will occur.
 */

#define BP_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET0      0
#define BM_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET0      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET0(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET0)
#else
#define BF_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET0(v)   (((v) << 0) & BM_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET0(v)   BF_CS1(MMDC_MPWRDLCTL, WR_DL_ABS_OFFSET0, v)
#endif

/* --- Register HW_MMDC_MPWRDLCTL, field WR_DL_ABS_OFFSET1
 *
 * Absolute write delay offset for Byte1. This field indicates the
 * absolute delay between write DQS strobe and the write data of Byte1
 * with fractions of a clock period and up to half cycle. The fraction
 * is process and frequency independent. The delay of the delay-line
 * would be (WR_DL_ABS_OFFSET1 / 256) * fast_clk. So for the default
 * value of 64 we get a quarter cycle delay.  This field can also bit written by HW. Upon completion
 * of the write                                 delay-line HW calibration this field gets the value
 * of                                 (HW_WR_DL_LOW1 + HW_WR_DL_UP1) /2  Note that not all changes
 * of this value will affect the actual delay.                                 If the requested
 * change is smaller than the delay-line resolution,                                 then no change
 * will occur.
 */

#define BP_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET1      8
#define BM_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET1      0x00007f00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET1(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET1)
#else
#define BF_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET1(v)   (((v) << 8) & BM_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET1(v)   BF_CS1(MMDC_MPWRDLCTL, WR_DL_ABS_OFFSET1, v)
#endif

/* --- Register HW_MMDC_MPWRDLCTL, field WR_DL_ABS_OFFSET2
 *
 * Absolute write delay offset for Byte2. This field indicates the
 * absolute delay between write DQS strobe and the write data of Byte2
 * with fractions of a clock period and up to half cycle. The fraction
 * is process and frequency independent. The delay of the delay-line
 * would be (WR_DL_ABS_OFFSET2/ 256) * fast_clk. So for the default
 * value of 64 we get a quarter cycle delay.  This field can also bit written by HW. Upon completion
 * of the write                                 delay-line HW calibration this field gets the value
 * of                                 (HW_WR_DL_LOW2 + HW_WR_DL_UP2) /2  Note that not all changes
 * will have effect on the actual delay. If                                 the requested change is
 * smaller than the delay-line resolution, then                                 no change will
 * occur.
 */

#define BP_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET2      16
#define BM_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET2      0x007f0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET2(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET2)
#else
#define BF_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET2(v)   (((v) << 16) & BM_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET2(v)   BF_CS1(MMDC_MPWRDLCTL, WR_DL_ABS_OFFSET2, v)
#endif

/* --- Register HW_MMDC_MPWRDLCTL, field WR_DL_ABS_OFFSET3
 *
 * Absolute write delay offset for Byte3. This field indicates the
 * absolute delay between write DQS strobe and the write data of Byte3
 * with fractions of a clock period and up to half cycle. The fraction
 * is process and frequency independent. The delay of the delay-line
 * would be (WR_DL_ABS_OFFSET3 / 256) * fast_clk. So for the default
 * value of 64 we get a quarter cycle delay.  This field can also bit written by HW. Upon completion
 * of the write                                 delay-line HW calibration this field gets the value
 * of                                 (HW_WR_DL_LOW3 + HW_WR_DL_UP3) /2  Note that not all changes
 * will have effect on the actual delay. If                                 the requested change is
 * smaller than the delay-line resolution, then                                 no change will
 * occur.
 */

#define BP_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET3      24
#define BM_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET3      0x7f000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET3(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET3)
#else
#define BF_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET3(v)   (((v) << 24) & BM_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDLCTL_WR_DL_ABS_OFFSET3(v)   BF_CS1(MMDC_MPWRDLCTL, WR_DL_ABS_OFFSET3, v)
#endif

/*!
 * @brief HW_MMDC_MPWRDLST - MMDC PHY Write delay-lines Status Register
 *
 * This register holds the status of the 4 write delay-line.  Supported Mode Of Operations:  For
 * Channel 0: All  For Channel 1: DDR3_x64, LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WR_DL_UNIT_NUM0 : 7; //!< This field reflects the number of delay units that are actually used by write delay-line 0.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned WR_DL_UNIT_NUM1 : 7; //!< This field reflects the number of delay units that are actually used by write delay-line 1.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned WR_DL_UNIT_NUM2 : 7; //!< This field reflects the number of delay units that are actually used by write delay-line 2.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned WR_DL_UNIT_NUM3 : 7; //!< This field reflects the number of delay units that are actually used by write delay-line 3.
        unsigned RESERVED3 : 1; //!< Reserved
    } B;
} hw_mmdc_mpwrdlst_t;
#endif

/*
 * constants & macros for entire MMDC_MPWRDLST register
 */
#define HW_MMDC_MPWRDLST_ADDR      (REGS_MMDC_BASE + 0x854)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPWRDLST           (*(volatile hw_mmdc_mpwrdlst_t *) HW_MMDC_MPWRDLST_ADDR)
#define HW_MMDC_MPWRDLST_RD()      (HW_MMDC_MPWRDLST.U)
#define HW_MMDC_MPWRDLST_WR(v)     (HW_MMDC_MPWRDLST.U = (v))
#define HW_MMDC_MPWRDLST_SET(v)    (HW_MMDC_MPWRDLST_WR(HW_MMDC_MPWRDLST_RD() |  (v)))
#define HW_MMDC_MPWRDLST_CLR(v)    (HW_MMDC_MPWRDLST_WR(HW_MMDC_MPWRDLST_RD() & ~(v)))
#define HW_MMDC_MPWRDLST_TOG(v)    (HW_MMDC_MPWRDLST_WR(HW_MMDC_MPWRDLST_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPWRDLST bitfields
 */

/* --- Register HW_MMDC_MPWRDLST, field WR_DL_UNIT_NUM0
 *
 * This field reflects the number of delay units that are actually used
 * by write delay-line 0.
 */

#define BP_MMDC_MPWRDLST_WR_DL_UNIT_NUM0      0
#define BM_MMDC_MPWRDLST_WR_DL_UNIT_NUM0      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDLST_WR_DL_UNIT_NUM0(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPWRDLST_WR_DL_UNIT_NUM0)
#else
#define BF_MMDC_MPWRDLST_WR_DL_UNIT_NUM0(v)   (((v) << 0) & BM_MMDC_MPWRDLST_WR_DL_UNIT_NUM0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDLST_WR_DL_UNIT_NUM0(v)   BF_CS1(MMDC_MPWRDLST, WR_DL_UNIT_NUM0, v)
#endif

/* --- Register HW_MMDC_MPWRDLST, field WR_DL_UNIT_NUM1
 *
 * This field reflects the number of delay units that are actually used
 * by write delay-line 1.
 */

#define BP_MMDC_MPWRDLST_WR_DL_UNIT_NUM1      8
#define BM_MMDC_MPWRDLST_WR_DL_UNIT_NUM1      0x00007f00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDLST_WR_DL_UNIT_NUM1(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPWRDLST_WR_DL_UNIT_NUM1)
#else
#define BF_MMDC_MPWRDLST_WR_DL_UNIT_NUM1(v)   (((v) << 8) & BM_MMDC_MPWRDLST_WR_DL_UNIT_NUM1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDLST_WR_DL_UNIT_NUM1(v)   BF_CS1(MMDC_MPWRDLST, WR_DL_UNIT_NUM1, v)
#endif

/* --- Register HW_MMDC_MPWRDLST, field WR_DL_UNIT_NUM2
 *
 * This field reflects the number of delay units that are actually used
 * by write delay-line 2.
 */

#define BP_MMDC_MPWRDLST_WR_DL_UNIT_NUM2      16
#define BM_MMDC_MPWRDLST_WR_DL_UNIT_NUM2      0x007f0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDLST_WR_DL_UNIT_NUM2(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPWRDLST_WR_DL_UNIT_NUM2)
#else
#define BF_MMDC_MPWRDLST_WR_DL_UNIT_NUM2(v)   (((v) << 16) & BM_MMDC_MPWRDLST_WR_DL_UNIT_NUM2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDLST_WR_DL_UNIT_NUM2(v)   BF_CS1(MMDC_MPWRDLST, WR_DL_UNIT_NUM2, v)
#endif

/* --- Register HW_MMDC_MPWRDLST, field WR_DL_UNIT_NUM3
 *
 * This field reflects the number of delay units that are actually used
 * by write delay-line 3.
 */

#define BP_MMDC_MPWRDLST_WR_DL_UNIT_NUM3      24
#define BM_MMDC_MPWRDLST_WR_DL_UNIT_NUM3      0x7f000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDLST_WR_DL_UNIT_NUM3(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPWRDLST_WR_DL_UNIT_NUM3)
#else
#define BF_MMDC_MPWRDLST_WR_DL_UNIT_NUM3(v)   (((v) << 24) & BM_MMDC_MPWRDLST_WR_DL_UNIT_NUM3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDLST_WR_DL_UNIT_NUM3(v)   BF_CS1(MMDC_MPWRDLST, WR_DL_UNIT_NUM3, v)
#endif

/*!
 * @brief HW_MMDC_MPSDCTRL - MMDC PHY CK Control Register
 *
 * This register controls the fine tuning of the primary clock (CK0).  Supported Mode Of Operations:
 * For Channel 0: All  For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned SDCLK0_DEL : 2; //!< DDR clock0 delay fine tuning. This field holds the number of delay units that are added to DDR clock (CK0).  Note:  In case of LPDDR2 2-ch mode this registers controls the fine tuning of the clock that is driven to channel0  In case of DDR3 the fine tuning of the secondary clock is controlled by 0x021B_4858[SDCLK]
        unsigned RESERVED1 : 22; //!< Reserved
    } B;
} hw_mmdc_mpsdctrl_t;
#endif

/*
 * constants & macros for entire MMDC_MPSDCTRL register
 */
#define HW_MMDC_MPSDCTRL_ADDR      (REGS_MMDC_BASE + 0x858)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPSDCTRL           (*(volatile hw_mmdc_mpsdctrl_t *) HW_MMDC_MPSDCTRL_ADDR)
#define HW_MMDC_MPSDCTRL_RD()      (HW_MMDC_MPSDCTRL.U)
#define HW_MMDC_MPSDCTRL_WR(v)     (HW_MMDC_MPSDCTRL.U = (v))
#define HW_MMDC_MPSDCTRL_SET(v)    (HW_MMDC_MPSDCTRL_WR(HW_MMDC_MPSDCTRL_RD() |  (v)))
#define HW_MMDC_MPSDCTRL_CLR(v)    (HW_MMDC_MPSDCTRL_WR(HW_MMDC_MPSDCTRL_RD() & ~(v)))
#define HW_MMDC_MPSDCTRL_TOG(v)    (HW_MMDC_MPSDCTRL_WR(HW_MMDC_MPSDCTRL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPSDCTRL bitfields
 */

/* --- Register HW_MMDC_MPSDCTRL, field SDCLK0_DEL
 *
 * DDR clock0 delay fine tuning. This field holds the number of delay
 * units that are added to DDR clock (CK0).  Note:  In case of LPDDR2 2-ch mode this registers
 * controls the fine tuning of the clock that is driven to channel0  In case of DDR3 the fine tuning
 * of the                                 secondary clock is controlled by 0x021B_4858[SDCLK]
 */

#define BP_MMDC_MPSDCTRL_SDCLK0_DEL      8
#define BM_MMDC_MPSDCTRL_SDCLK0_DEL      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPSDCTRL_SDCLK0_DEL(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPSDCTRL_SDCLK0_DEL)
#else
#define BF_MMDC_MPSDCTRL_SDCLK0_DEL(v)   (((v) << 8) & BM_MMDC_MPSDCTRL_SDCLK0_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPSDCTRL_SDCLK0_DEL(v)   BF_CS1(MMDC_MPSDCTRL, SDCLK0_DEL, v)
#endif

/*!
 * @brief HW_MMDC_MPZQLP2CTL - MMDC ZQ LPDDR2 HW Control Register
 *
 * This register controls the idle time that takes the LPDDR2 device to
 * perform ZQ calibration  Supported Mode Of Operations:  For Channel 0: LP2_2ch_x16, LP2_2ch_x32
 * For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ZQ_LP2_HW_ZQINIT : 9; //!< This register defines the period in cycles that it takes the memory device to perform a Init ZQ calibration.  This is the period of time that the MMDC has to wait after sending a init ZQ calibration and before sending other commands.
        unsigned RESERVED0 : 7; //!< Reserved
        unsigned ZQ_LP2_HW_ZQCL : 8; //!< This register defines the period in cycles that it takes the memory device to perform a long ZQ calibration.  This is the period of time that the MMDC has to wait after sending a Short ZQ calibration and before sending other commands.
        unsigned ZQ_LP2_HW_ZQCS : 7; //!< This register defines the period in cycles that it takes the memory device to perform a Short ZQ calibration.  This is the period of time that the MMDC has to wait after sending a long ZQ calibration and before sending other commands.  This delay will also be used if ZQ reset is sent.
        unsigned RESERVED1 : 1; //!< Reserved
    } B;
} hw_mmdc_mpzqlp2ctl_t;
#endif

/*
 * constants & macros for entire MMDC_MPZQLP2CTL register
 */
#define HW_MMDC_MPZQLP2CTL_ADDR      (REGS_MMDC_BASE + 0x85c)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPZQLP2CTL           (*(volatile hw_mmdc_mpzqlp2ctl_t *) HW_MMDC_MPZQLP2CTL_ADDR)
#define HW_MMDC_MPZQLP2CTL_RD()      (HW_MMDC_MPZQLP2CTL.U)
#define HW_MMDC_MPZQLP2CTL_WR(v)     (HW_MMDC_MPZQLP2CTL.U = (v))
#define HW_MMDC_MPZQLP2CTL_SET(v)    (HW_MMDC_MPZQLP2CTL_WR(HW_MMDC_MPZQLP2CTL_RD() |  (v)))
#define HW_MMDC_MPZQLP2CTL_CLR(v)    (HW_MMDC_MPZQLP2CTL_WR(HW_MMDC_MPZQLP2CTL_RD() & ~(v)))
#define HW_MMDC_MPZQLP2CTL_TOG(v)    (HW_MMDC_MPZQLP2CTL_WR(HW_MMDC_MPZQLP2CTL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPZQLP2CTL bitfields
 */

/* --- Register HW_MMDC_MPZQLP2CTL, field ZQ_LP2_HW_ZQINIT
 *
 * This register defines the period in cycles that it takes the memory
 * device to perform a Init ZQ calibration.  This is the period of time that the MMDC has to wait
 * after sending a                                 init ZQ calibration and before sending other
 * commands.
 */

#define BP_MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQINIT      0
#define BM_MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQINIT      0x000001ff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQINIT(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQINIT)
#else
#define BF_MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQINIT(v)   (((v) << 0) & BM_MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQINIT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQINIT(v)   BF_CS1(MMDC_MPZQLP2CTL, ZQ_LP2_HW_ZQINIT, v)
#endif

/* --- Register HW_MMDC_MPZQLP2CTL, field ZQ_LP2_HW_ZQCL
 *
 * This register defines the period in cycles that it takes the memory
 * device to perform a long ZQ calibration.  This is the period of time that the MMDC has to wait
 * after sending a                                 Short ZQ calibration and before sending other
 * commands.
 */

#define BP_MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCL      16
#define BM_MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCL      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCL(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCL)
#else
#define BF_MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCL(v)   (((v) << 16) & BM_MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCL(v)   BF_CS1(MMDC_MPZQLP2CTL, ZQ_LP2_HW_ZQCL, v)
#endif

/* --- Register HW_MMDC_MPZQLP2CTL, field ZQ_LP2_HW_ZQCS
 *
 * This register defines the period in cycles that it takes the memory
 * device to perform a Short ZQ calibration.  This is the period of time that the MMDC has to wait
 * after sending a                                 long ZQ calibration and before sending other
 * commands.  This delay will also be used if ZQ reset is sent.
 */

#define BP_MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCS      24
#define BM_MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCS      0x7f000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCS(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCS)
#else
#define BF_MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCS(v)   (((v) << 24) & BM_MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPZQLP2CTL_ZQ_LP2_HW_ZQCS(v)   BF_CS1(MMDC_MPZQLP2CTL, ZQ_LP2_HW_ZQCS, v)
#endif

/*!
 * @brief HW_MMDC_MPRDDLHWCTL - MMDC PHY Read Delay HW Calibration Control                        Register
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: DDR3_x64, LP2_2ch_x16,
 * LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned HW_RD_DL_ERR0 : 1; //!< Automatic (HW) read calibration error of Byte0. If this bit is asserted then it indicates that an error was found during the HW calibration process of read delay-line 0. In case this bit is zero at the end of the calibration process then the boundary results can be found at MPRDDLHWST0 register. This bit is valid only after HW_RD_DL_EN is de-asserted.
        unsigned HW_RD_DL_ERR1 : 1; //!< Automatic (HW) read calibration error of Byte1. If this bit is asserted then it indicates that an error was found during the HW calibration process of read delay-line 1. In case this bit is zero at the end of the calibration process then the boundary results can be found at MPRDDLHWST0 register. This bit is valid only after HW_RD_DL_EN is de-asserted.
        unsigned HW_RD_DL_ERR2 : 1; //!< Automatic (HW) read calibration error of Byte2. If this bit is asserted then it indicates that an error was found during the HW calibration process of read delay-line 2. In case this bit is zero at the end of the calibration process then the boundary results can be found at MPRDDLHWST1 register. This bit is valid only after HW_RD_DL_EN is de-asserted.
        unsigned HW_RD_DL_ERR3 : 1; //!< Automatic (HW) read calibration error of Byte3. If this bit is asserted then it indicates that an error was found during the HW calibration process of read delay-line 3. In case this bit is zero at the end of the calibration process then the boundary results can be found at MPRDDLHWST1 register. This bit is valid only after HW_RD_DL_EN is de-asserted.
        unsigned HW_RD_DL_EN : 1; //!< Enable automatic (HW) read calibration. If this bit is asserted then the MMDC will perform an automatic read calibration. HW should negate this bit upon completion of the calibration. Negation of this bit also points that the read calibration results are valid  Note: Before issuing the first read command MMDC counts 12 cycles.
        unsigned HW_RD_DL_CMP_CYC : 1; //!< Automatic (HW) read sample cycle. If this bit is asserted then the MMDC will compare the read data 32 cycles after the MMDC sent the read command enable pulse else it compares the data after 16 cycles.
        unsigned RESERVED0 : 26; //!< Reserved
    } B;
} hw_mmdc_mprddlhwctl_t;
#endif

/*
 * constants & macros for entire MMDC_MPRDDLHWCTL register
 */
#define HW_MMDC_MPRDDLHWCTL_ADDR      (REGS_MMDC_BASE + 0x860)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPRDDLHWCTL           (*(volatile hw_mmdc_mprddlhwctl_t *) HW_MMDC_MPRDDLHWCTL_ADDR)
#define HW_MMDC_MPRDDLHWCTL_RD()      (HW_MMDC_MPRDDLHWCTL.U)
#define HW_MMDC_MPRDDLHWCTL_WR(v)     (HW_MMDC_MPRDDLHWCTL.U = (v))
#define HW_MMDC_MPRDDLHWCTL_SET(v)    (HW_MMDC_MPRDDLHWCTL_WR(HW_MMDC_MPRDDLHWCTL_RD() |  (v)))
#define HW_MMDC_MPRDDLHWCTL_CLR(v)    (HW_MMDC_MPRDDLHWCTL_WR(HW_MMDC_MPRDDLHWCTL_RD() & ~(v)))
#define HW_MMDC_MPRDDLHWCTL_TOG(v)    (HW_MMDC_MPRDDLHWCTL_WR(HW_MMDC_MPRDDLHWCTL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPRDDLHWCTL bitfields
 */

/* --- Register HW_MMDC_MPRDDLHWCTL, field HW_RD_DL_ERR0
 *
 * Automatic (HW) read calibration error of Byte0. If this bit is
 * asserted then it indicates that an error was found during the HW
 * calibration process of read delay-line 0. In case this bit is zero
 * at the end of the calibration process then the boundary results can
 * be found at MPRDDLHWST0 register. This bit is valid only after
 * HW_RD_DL_EN is de-asserted.
 */

#define BP_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR0      0
#define BM_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR0      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR0(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR0)
#else
#define BF_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR0(v)   (((v) << 0) & BM_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR0(v)   BF_CS1(MMDC_MPRDDLHWCTL, HW_RD_DL_ERR0, v)
#endif

/* --- Register HW_MMDC_MPRDDLHWCTL, field HW_RD_DL_ERR1
 *
 * Automatic (HW) read calibration error of Byte1. If this bit is
 * asserted then it indicates that an error was found during the HW
 * calibration process of read delay-line 1. In case this bit is zero
 * at the end of the calibration process then the boundary results can
 * be found at MPRDDLHWST0 register. This bit is valid only after
 * HW_RD_DL_EN is de-asserted.
 */

#define BP_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR1      1
#define BM_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR1(v)   ((((reg32_t) v) << 1) & BM_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR1)
#else
#define BF_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR1(v)   (((v) << 1) & BM_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR1(v)   BF_CS1(MMDC_MPRDDLHWCTL, HW_RD_DL_ERR1, v)
#endif

/* --- Register HW_MMDC_MPRDDLHWCTL, field HW_RD_DL_ERR2
 *
 * Automatic (HW) read calibration error of Byte2. If this bit is
 * asserted then it indicates that an error was found during the HW
 * calibration process of read delay-line 2. In case this bit is zero
 * at the end of the calibration process then the boundary results can
 * be found at MPRDDLHWST1 register. This bit is valid only after
 * HW_RD_DL_EN is de-asserted.
 */

#define BP_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR2      2
#define BM_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR2      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR2(v)   ((((reg32_t) v) << 2) & BM_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR2)
#else
#define BF_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR2(v)   (((v) << 2) & BM_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR2(v)   BF_CS1(MMDC_MPRDDLHWCTL, HW_RD_DL_ERR2, v)
#endif

/* --- Register HW_MMDC_MPRDDLHWCTL, field HW_RD_DL_ERR3
 *
 * Automatic (HW) read calibration error of Byte3. If this bit is
 * asserted then it indicates that an error was found during the HW
 * calibration process of read delay-line 3. In case this bit is zero
 * at the end of the calibration process then the boundary results can
 * be found at MPRDDLHWST1 register. This bit is valid only after
 * HW_RD_DL_EN is de-asserted.
 */

#define BP_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR3      3
#define BM_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR3      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR3(v)   ((((reg32_t) v) << 3) & BM_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR3)
#else
#define BF_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR3(v)   (((v) << 3) & BM_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDLHWCTL_HW_RD_DL_ERR3(v)   BF_CS1(MMDC_MPRDDLHWCTL, HW_RD_DL_ERR3, v)
#endif

/* --- Register HW_MMDC_MPRDDLHWCTL, field HW_RD_DL_EN
 *
 * Enable automatic (HW) read calibration. If this bit is asserted then
 * the MMDC will perform an automatic read calibration. HW should
 * negate this bit upon completion of the calibration. Negation of this
 * bit also points that the read calibration results are valid  Note: Before issuing the first read
 * command MMDC counts 12                                 cycles.
 */

#define BP_MMDC_MPRDDLHWCTL_HW_RD_DL_EN      4
#define BM_MMDC_MPRDDLHWCTL_HW_RD_DL_EN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDLHWCTL_HW_RD_DL_EN(v)   ((((reg32_t) v) << 4) & BM_MMDC_MPRDDLHWCTL_HW_RD_DL_EN)
#else
#define BF_MMDC_MPRDDLHWCTL_HW_RD_DL_EN(v)   (((v) << 4) & BM_MMDC_MPRDDLHWCTL_HW_RD_DL_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDLHWCTL_HW_RD_DL_EN(v)   BF_CS1(MMDC_MPRDDLHWCTL, HW_RD_DL_EN, v)
#endif

/* --- Register HW_MMDC_MPRDDLHWCTL, field HW_RD_DL_CMP_CYC
 *
 * Automatic (HW) read sample cycle. If this bit is asserted then the
 * MMDC will compare the read data 32 cycles after the MMDC sent the
 * read command enable pulse else it compares the data after 16
 * cycles.
 */

#define BP_MMDC_MPRDDLHWCTL_HW_RD_DL_CMP_CYC      5
#define BM_MMDC_MPRDDLHWCTL_HW_RD_DL_CMP_CYC      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDLHWCTL_HW_RD_DL_CMP_CYC(v)   ((((reg32_t) v) << 5) & BM_MMDC_MPRDDLHWCTL_HW_RD_DL_CMP_CYC)
#else
#define BF_MMDC_MPRDDLHWCTL_HW_RD_DL_CMP_CYC(v)   (((v) << 5) & BM_MMDC_MPRDDLHWCTL_HW_RD_DL_CMP_CYC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDLHWCTL_HW_RD_DL_CMP_CYC(v)   BF_CS1(MMDC_MPRDDLHWCTL, HW_RD_DL_CMP_CYC, v)
#endif

/*!
 * @brief HW_MMDC_MPWRDLHWCTL - MMDC PHY Write Delay HW Calibration Control                        Register
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: DDR3_x64, LP2_2ch_x16,
 * LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned HW_WR_DL_ERR0 : 1; //!< Automatic (HW) write calibration error of Byte0. If this bit is asserted then it indicates that an error was found during the HW calibration process of write delay-line 0. In case this bit is zero at the end of the calibration process then the boundary results can be found at MPWRDLHWST0 register. This bit is valid only after HW_WR_DL_EN is de-asserted.
        unsigned HW_WR_DL_ERR1 : 1; //!< Automatic (HW) write calibration error of Byte1. If this bit is asserted then it indicates that an error was found during the HW calibration process of write delay-line 1. In case this bit is zero at the end of the calibration process then the boundary results can be found at MPWRDLHWST0 register. This bit is valid only after HW_WR_DL_EN is de-asserted.
        unsigned HW_WR_DL_ERR2 : 1; //!< Automatic (HW) write calibration error of Byte2. If this bit is asserted then it indicates that an error was found during the HW calibration process of write delay-line 2. T In case this bit is zero at the end of the calibration process then the boundary results can be found at MPWRDLHWST1 register. This bit is valid only after HW_WR_DL_EN is de-asserted.
        unsigned HW_WR_DL_ERR3 : 1; //!< Automatic (HW) write calibration error of Byte3. If this bit is asserted then it indicates that an error was found during the HW calibration process of write delay-line 3. In case this bit is zero at the end of the calibration process then the boundary results can be found at MPWRDLHWST1 register. This bit is valid only after HW_WR_DL_EN is de-asserted.
        unsigned HW_WR_DL_EN : 1; //!< Enable automatic (HW) write calibration. If this bit is asserted then the MMDC will perform an automatic write calibration. HW should negate this bit upon completion of the calibration. Negation of this bit also indicates that the write calibration results are valid  Note: Before issuing the first read command MMDC counts 12 cycles.
        unsigned HW_WR_DL_CMP_CYC : 1; //!< Write sample cycle. If this bit is asserted then the MMDC will compare the data 32 cycles after the MMDC sent the read command enable pulse else it compares the data after 16 cycles.
        unsigned RESERVED0 : 26; //!< Reserved
    } B;
} hw_mmdc_mpwrdlhwctl_t;
#endif

/*
 * constants & macros for entire MMDC_MPWRDLHWCTL register
 */
#define HW_MMDC_MPWRDLHWCTL_ADDR      (REGS_MMDC_BASE + 0x864)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPWRDLHWCTL           (*(volatile hw_mmdc_mpwrdlhwctl_t *) HW_MMDC_MPWRDLHWCTL_ADDR)
#define HW_MMDC_MPWRDLHWCTL_RD()      (HW_MMDC_MPWRDLHWCTL.U)
#define HW_MMDC_MPWRDLHWCTL_WR(v)     (HW_MMDC_MPWRDLHWCTL.U = (v))
#define HW_MMDC_MPWRDLHWCTL_SET(v)    (HW_MMDC_MPWRDLHWCTL_WR(HW_MMDC_MPWRDLHWCTL_RD() |  (v)))
#define HW_MMDC_MPWRDLHWCTL_CLR(v)    (HW_MMDC_MPWRDLHWCTL_WR(HW_MMDC_MPWRDLHWCTL_RD() & ~(v)))
#define HW_MMDC_MPWRDLHWCTL_TOG(v)    (HW_MMDC_MPWRDLHWCTL_WR(HW_MMDC_MPWRDLHWCTL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPWRDLHWCTL bitfields
 */

/* --- Register HW_MMDC_MPWRDLHWCTL, field HW_WR_DL_ERR0
 *
 * Automatic (HW) write calibration error of Byte0. If this bit is
 * asserted then it indicates that an error was found during the HW
 * calibration process of write delay-line 0. In case this bit is zero
 * at the end of the calibration process then the boundary results can
 * be found at MPWRDLHWST0 register. This bit is valid only after
 * HW_WR_DL_EN is de-asserted.
 */

#define BP_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR0      0
#define BM_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR0      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR0(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR0)
#else
#define BF_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR0(v)   (((v) << 0) & BM_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR0(v)   BF_CS1(MMDC_MPWRDLHWCTL, HW_WR_DL_ERR0, v)
#endif

/* --- Register HW_MMDC_MPWRDLHWCTL, field HW_WR_DL_ERR1
 *
 * Automatic (HW) write calibration error of Byte1. If this bit is
 * asserted then it indicates that an error was found during the HW
 * calibration process of write delay-line 1. In case this bit is zero
 * at the end of the calibration process then the boundary results can
 * be found at MPWRDLHWST0 register. This bit is valid only after
 * HW_WR_DL_EN is de-asserted.
 */

#define BP_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR1      1
#define BM_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR1(v)   ((((reg32_t) v) << 1) & BM_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR1)
#else
#define BF_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR1(v)   (((v) << 1) & BM_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR1(v)   BF_CS1(MMDC_MPWRDLHWCTL, HW_WR_DL_ERR1, v)
#endif

/* --- Register HW_MMDC_MPWRDLHWCTL, field HW_WR_DL_ERR2
 *
 * Automatic (HW) write calibration error of Byte2. If this bit is
 * asserted then it indicates that an error was found during the HW
 * calibration process of write delay-line 2. T In case this bit is
 * zero at the end of the calibration process then the boundary results
 * can be found at MPWRDLHWST1 register. This bit is valid only after
 * HW_WR_DL_EN is de-asserted.
 */

#define BP_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR2      2
#define BM_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR2      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR2(v)   ((((reg32_t) v) << 2) & BM_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR2)
#else
#define BF_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR2(v)   (((v) << 2) & BM_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR2(v)   BF_CS1(MMDC_MPWRDLHWCTL, HW_WR_DL_ERR2, v)
#endif

/* --- Register HW_MMDC_MPWRDLHWCTL, field HW_WR_DL_ERR3
 *
 * Automatic (HW) write calibration error of Byte3. If this bit is
 * asserted then it indicates that an error was found during the HW
 * calibration process of write delay-line 3. In case this bit is zero
 * at the end of the calibration process then the boundary results can
 * be found at MPWRDLHWST1 register. This bit is valid only after
 * HW_WR_DL_EN is de-asserted.
 */

#define BP_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR3      3
#define BM_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR3      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR3(v)   ((((reg32_t) v) << 3) & BM_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR3)
#else
#define BF_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR3(v)   (((v) << 3) & BM_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDLHWCTL_HW_WR_DL_ERR3(v)   BF_CS1(MMDC_MPWRDLHWCTL, HW_WR_DL_ERR3, v)
#endif

/* --- Register HW_MMDC_MPWRDLHWCTL, field HW_WR_DL_EN
 *
 * Enable automatic (HW) write calibration. If this bit is asserted then
 * the MMDC will perform an automatic write calibration. HW should
 * negate this bit upon completion of the calibration. Negation of this
 * bit also indicates that the write calibration results are valid  Note: Before issuing the first
 * read command MMDC counts 12                                 cycles.
 */

#define BP_MMDC_MPWRDLHWCTL_HW_WR_DL_EN      4
#define BM_MMDC_MPWRDLHWCTL_HW_WR_DL_EN      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDLHWCTL_HW_WR_DL_EN(v)   ((((reg32_t) v) << 4) & BM_MMDC_MPWRDLHWCTL_HW_WR_DL_EN)
#else
#define BF_MMDC_MPWRDLHWCTL_HW_WR_DL_EN(v)   (((v) << 4) & BM_MMDC_MPWRDLHWCTL_HW_WR_DL_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDLHWCTL_HW_WR_DL_EN(v)   BF_CS1(MMDC_MPWRDLHWCTL, HW_WR_DL_EN, v)
#endif

/* --- Register HW_MMDC_MPWRDLHWCTL, field HW_WR_DL_CMP_CYC
 *
 * Write sample cycle. If this bit is asserted then the MMDC will
 * compare the data 32 cycles after the MMDC sent the read command
 * enable pulse else it compares the data after 16 cycles.
 */

#define BP_MMDC_MPWRDLHWCTL_HW_WR_DL_CMP_CYC      5
#define BM_MMDC_MPWRDLHWCTL_HW_WR_DL_CMP_CYC      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDLHWCTL_HW_WR_DL_CMP_CYC(v)   ((((reg32_t) v) << 5) & BM_MMDC_MPWRDLHWCTL_HW_WR_DL_CMP_CYC)
#else
#define BF_MMDC_MPWRDLHWCTL_HW_WR_DL_CMP_CYC(v)   (((v) << 5) & BM_MMDC_MPWRDLHWCTL_HW_WR_DL_CMP_CYC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDLHWCTL_HW_WR_DL_CMP_CYC(v)   BF_CS1(MMDC_MPWRDLHWCTL, HW_WR_DL_CMP_CYC, v)
#endif

/*!
 * @brief HW_MMDC_MPRDDLHWST0 - MMDC PHY Read Delay HW Calibration Status Register                        0
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: DDR3_x64, LP2_2ch_x16,
 * LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned HW_RD_DL_LOW0 : 7; //!< Automatic (HW) read calibration result of the lower boundary of Byte0. This field holds the automatic (HW) read calibration result of the lower boundary of Byte0.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned HW_RD_DL_UP0 : 7; //!< Automatic (HW) read calibration result of the upper boundary of Byte0. This field holds the automatic (HW) read calibration result of the upper boundary of Byte0.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned HW_RD_DL_LOW1 : 7; //!< Automatic (HW) read calibration result of the lower boundary of Byte1. This field holds the automatic (HW) read calibration result of the lower boundary of Byte1
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned HW_RD_DL_UP1 : 7; //!< Automatic (HW) read calibration result of the upper boundary of Byte1. This field holds the automatic (HW) read calibration result of the upper boundary of Byte1
        unsigned RESERVED3 : 1; //!< Reserved
    } B;
} hw_mmdc_mprddlhwst0_t;
#endif

/*
 * constants & macros for entire MMDC_MPRDDLHWST0 register
 */
#define HW_MMDC_MPRDDLHWST0_ADDR      (REGS_MMDC_BASE + 0x868)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPRDDLHWST0           (*(volatile hw_mmdc_mprddlhwst0_t *) HW_MMDC_MPRDDLHWST0_ADDR)
#define HW_MMDC_MPRDDLHWST0_RD()      (HW_MMDC_MPRDDLHWST0.U)
#define HW_MMDC_MPRDDLHWST0_WR(v)     (HW_MMDC_MPRDDLHWST0.U = (v))
#define HW_MMDC_MPRDDLHWST0_SET(v)    (HW_MMDC_MPRDDLHWST0_WR(HW_MMDC_MPRDDLHWST0_RD() |  (v)))
#define HW_MMDC_MPRDDLHWST0_CLR(v)    (HW_MMDC_MPRDDLHWST0_WR(HW_MMDC_MPRDDLHWST0_RD() & ~(v)))
#define HW_MMDC_MPRDDLHWST0_TOG(v)    (HW_MMDC_MPRDDLHWST0_WR(HW_MMDC_MPRDDLHWST0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPRDDLHWST0 bitfields
 */

/* --- Register HW_MMDC_MPRDDLHWST0, field HW_RD_DL_LOW0
 *
 * Automatic (HW) read calibration result of the lower boundary of
 * Byte0. This field holds the automatic (HW) read calibration result
 * of the lower boundary of Byte0.
 */

#define BP_MMDC_MPRDDLHWST0_HW_RD_DL_LOW0      0
#define BM_MMDC_MPRDDLHWST0_HW_RD_DL_LOW0      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDLHWST0_HW_RD_DL_LOW0(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPRDDLHWST0_HW_RD_DL_LOW0)
#else
#define BF_MMDC_MPRDDLHWST0_HW_RD_DL_LOW0(v)   (((v) << 0) & BM_MMDC_MPRDDLHWST0_HW_RD_DL_LOW0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDLHWST0_HW_RD_DL_LOW0(v)   BF_CS1(MMDC_MPRDDLHWST0, HW_RD_DL_LOW0, v)
#endif

/* --- Register HW_MMDC_MPRDDLHWST0, field HW_RD_DL_UP0
 *
 * Automatic (HW) read calibration result of the upper boundary of
 * Byte0. This field holds the automatic (HW) read calibration result
 * of the upper boundary of Byte0.
 */

#define BP_MMDC_MPRDDLHWST0_HW_RD_DL_UP0      8
#define BM_MMDC_MPRDDLHWST0_HW_RD_DL_UP0      0x00007f00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDLHWST0_HW_RD_DL_UP0(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPRDDLHWST0_HW_RD_DL_UP0)
#else
#define BF_MMDC_MPRDDLHWST0_HW_RD_DL_UP0(v)   (((v) << 8) & BM_MMDC_MPRDDLHWST0_HW_RD_DL_UP0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDLHWST0_HW_RD_DL_UP0(v)   BF_CS1(MMDC_MPRDDLHWST0, HW_RD_DL_UP0, v)
#endif

/* --- Register HW_MMDC_MPRDDLHWST0, field HW_RD_DL_LOW1
 *
 * Automatic (HW) read calibration result of the lower boundary of
 * Byte1. This field holds the automatic (HW) read calibration result
 * of the lower boundary of Byte1
 */

#define BP_MMDC_MPRDDLHWST0_HW_RD_DL_LOW1      16
#define BM_MMDC_MPRDDLHWST0_HW_RD_DL_LOW1      0x007f0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDLHWST0_HW_RD_DL_LOW1(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPRDDLHWST0_HW_RD_DL_LOW1)
#else
#define BF_MMDC_MPRDDLHWST0_HW_RD_DL_LOW1(v)   (((v) << 16) & BM_MMDC_MPRDDLHWST0_HW_RD_DL_LOW1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDLHWST0_HW_RD_DL_LOW1(v)   BF_CS1(MMDC_MPRDDLHWST0, HW_RD_DL_LOW1, v)
#endif

/* --- Register HW_MMDC_MPRDDLHWST0, field HW_RD_DL_UP1
 *
 * Automatic (HW) read calibration result of the upper boundary of
 * Byte1. This field holds the automatic (HW) read calibration result
 * of the upper boundary of Byte1
 */

#define BP_MMDC_MPRDDLHWST0_HW_RD_DL_UP1      24
#define BM_MMDC_MPRDDLHWST0_HW_RD_DL_UP1      0x7f000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDLHWST0_HW_RD_DL_UP1(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPRDDLHWST0_HW_RD_DL_UP1)
#else
#define BF_MMDC_MPRDDLHWST0_HW_RD_DL_UP1(v)   (((v) << 24) & BM_MMDC_MPRDDLHWST0_HW_RD_DL_UP1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDLHWST0_HW_RD_DL_UP1(v)   BF_CS1(MMDC_MPRDDLHWST0, HW_RD_DL_UP1, v)
#endif

/*!
 * @brief HW_MMDC_MPRDDLHWST1 - MMDC PHY Read Delay HW Calibration Status Register                        1
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: DDR3_x64, LP2_2ch_x16,
 * LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned HW_RD_DL_LOW2 : 7; //!< Automatic (HW) read calibration result of the lower boundary of Byte2. This field holds the automatic (HW) read calibration result of the lower boundary of Byte2.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned HW_RD_DL_UP2 : 7; //!< Automatic (HW) read calibration result of the upper boundary of Byte2. This field holds the automatic (HW) read calibration result of the upper boundary of Byte2.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned HW_RD_DL_LOW3 : 7; //!< Automatic (HW) read calibration result of the lower boundary of Byte3. This field holds the automatic (HW) read calibration result of the lower boundary of Byte3
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned HW_RD_DL_UP3 : 7; //!< Automatic (HW) read calibration result of the upper boundary of Byte3. This field holds the automatic (HW) read calibration result of the upper boundary of Byte3
        unsigned RESERVED3 : 1; //!< Reserved
    } B;
} hw_mmdc_mprddlhwst1_t;
#endif

/*
 * constants & macros for entire MMDC_MPRDDLHWST1 register
 */
#define HW_MMDC_MPRDDLHWST1_ADDR      (REGS_MMDC_BASE + 0x86c)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPRDDLHWST1           (*(volatile hw_mmdc_mprddlhwst1_t *) HW_MMDC_MPRDDLHWST1_ADDR)
#define HW_MMDC_MPRDDLHWST1_RD()      (HW_MMDC_MPRDDLHWST1.U)
#define HW_MMDC_MPRDDLHWST1_WR(v)     (HW_MMDC_MPRDDLHWST1.U = (v))
#define HW_MMDC_MPRDDLHWST1_SET(v)    (HW_MMDC_MPRDDLHWST1_WR(HW_MMDC_MPRDDLHWST1_RD() |  (v)))
#define HW_MMDC_MPRDDLHWST1_CLR(v)    (HW_MMDC_MPRDDLHWST1_WR(HW_MMDC_MPRDDLHWST1_RD() & ~(v)))
#define HW_MMDC_MPRDDLHWST1_TOG(v)    (HW_MMDC_MPRDDLHWST1_WR(HW_MMDC_MPRDDLHWST1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPRDDLHWST1 bitfields
 */

/* --- Register HW_MMDC_MPRDDLHWST1, field HW_RD_DL_LOW2
 *
 * Automatic (HW) read calibration result of the lower boundary of
 * Byte2. This field holds the automatic (HW) read calibration result
 * of the lower boundary of Byte2.
 */

#define BP_MMDC_MPRDDLHWST1_HW_RD_DL_LOW2      0
#define BM_MMDC_MPRDDLHWST1_HW_RD_DL_LOW2      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDLHWST1_HW_RD_DL_LOW2(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPRDDLHWST1_HW_RD_DL_LOW2)
#else
#define BF_MMDC_MPRDDLHWST1_HW_RD_DL_LOW2(v)   (((v) << 0) & BM_MMDC_MPRDDLHWST1_HW_RD_DL_LOW2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDLHWST1_HW_RD_DL_LOW2(v)   BF_CS1(MMDC_MPRDDLHWST1, HW_RD_DL_LOW2, v)
#endif

/* --- Register HW_MMDC_MPRDDLHWST1, field HW_RD_DL_UP2
 *
 * Automatic (HW) read calibration result of the upper boundary of
 * Byte2. This field holds the automatic (HW) read calibration result
 * of the upper boundary of Byte2.
 */

#define BP_MMDC_MPRDDLHWST1_HW_RD_DL_UP2      8
#define BM_MMDC_MPRDDLHWST1_HW_RD_DL_UP2      0x00007f00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDLHWST1_HW_RD_DL_UP2(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPRDDLHWST1_HW_RD_DL_UP2)
#else
#define BF_MMDC_MPRDDLHWST1_HW_RD_DL_UP2(v)   (((v) << 8) & BM_MMDC_MPRDDLHWST1_HW_RD_DL_UP2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDLHWST1_HW_RD_DL_UP2(v)   BF_CS1(MMDC_MPRDDLHWST1, HW_RD_DL_UP2, v)
#endif

/* --- Register HW_MMDC_MPRDDLHWST1, field HW_RD_DL_LOW3
 *
 * Automatic (HW) read calibration result of the lower boundary of
 * Byte3. This field holds the automatic (HW) read calibration result
 * of the lower boundary of Byte3
 */

#define BP_MMDC_MPRDDLHWST1_HW_RD_DL_LOW3      16
#define BM_MMDC_MPRDDLHWST1_HW_RD_DL_LOW3      0x007f0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDLHWST1_HW_RD_DL_LOW3(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPRDDLHWST1_HW_RD_DL_LOW3)
#else
#define BF_MMDC_MPRDDLHWST1_HW_RD_DL_LOW3(v)   (((v) << 16) & BM_MMDC_MPRDDLHWST1_HW_RD_DL_LOW3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDLHWST1_HW_RD_DL_LOW3(v)   BF_CS1(MMDC_MPRDDLHWST1, HW_RD_DL_LOW3, v)
#endif

/* --- Register HW_MMDC_MPRDDLHWST1, field HW_RD_DL_UP3
 *
 * Automatic (HW) read calibration result of the upper boundary of
 * Byte3. This field holds the automatic (HW) read calibration result
 * of the upper boundary of Byte3
 */

#define BP_MMDC_MPRDDLHWST1_HW_RD_DL_UP3      24
#define BM_MMDC_MPRDDLHWST1_HW_RD_DL_UP3      0x7f000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPRDDLHWST1_HW_RD_DL_UP3(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPRDDLHWST1_HW_RD_DL_UP3)
#else
#define BF_MMDC_MPRDDLHWST1_HW_RD_DL_UP3(v)   (((v) << 24) & BM_MMDC_MPRDDLHWST1_HW_RD_DL_UP3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPRDDLHWST1_HW_RD_DL_UP3(v)   BF_CS1(MMDC_MPRDDLHWST1, HW_RD_DL_UP3, v)
#endif

/*!
 * @brief HW_MMDC_MPWRDLHWST0 - MMDC PHY Write Delay HW Calibration Status Register                        0
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: DDR3_x64, LP2_2ch_x16,
 * LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned HW_WR_DL_LOW0 : 7; //!< Automatic (HW) write calibration result of the lower boundary of Byte0. This field holds the automatic (HW) write calibration result of the lower boundary of Byte0.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned HW_WR_DL_UP0 : 7; //!< Automatic (HW) write calibration result of the upper boundary of Byte0. This field holds the automatic (HW) write calibration result of the upper boundary of Byte0.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned HW_WR_DL_LOW1 : 7; //!< Automatic (HW) write calibration result of the lower boundary of Byte1. This field holds the automatic (HW) write calibration result of the lower boundary of Byte1.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned HW_WR_DL_UP1 : 7; //!< Aautomatic (HW) write utomatic (HW) write calibration result of the upper boundary of Byte1. This field holds the automatic (HW) write calibration result of the upper boundary of Byte1.
        unsigned RESERVED3 : 1; //!< Reserved
    } B;
} hw_mmdc_mpwrdlhwst0_t;
#endif

/*
 * constants & macros for entire MMDC_MPWRDLHWST0 register
 */
#define HW_MMDC_MPWRDLHWST0_ADDR      (REGS_MMDC_BASE + 0x870)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPWRDLHWST0           (*(volatile hw_mmdc_mpwrdlhwst0_t *) HW_MMDC_MPWRDLHWST0_ADDR)
#define HW_MMDC_MPWRDLHWST0_RD()      (HW_MMDC_MPWRDLHWST0.U)
#define HW_MMDC_MPWRDLHWST0_WR(v)     (HW_MMDC_MPWRDLHWST0.U = (v))
#define HW_MMDC_MPWRDLHWST0_SET(v)    (HW_MMDC_MPWRDLHWST0_WR(HW_MMDC_MPWRDLHWST0_RD() |  (v)))
#define HW_MMDC_MPWRDLHWST0_CLR(v)    (HW_MMDC_MPWRDLHWST0_WR(HW_MMDC_MPWRDLHWST0_RD() & ~(v)))
#define HW_MMDC_MPWRDLHWST0_TOG(v)    (HW_MMDC_MPWRDLHWST0_WR(HW_MMDC_MPWRDLHWST0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPWRDLHWST0 bitfields
 */

/* --- Register HW_MMDC_MPWRDLHWST0, field HW_WR_DL_LOW0
 *
 * Automatic (HW) write calibration result of the lower boundary of
 * Byte0. This field holds the automatic (HW) write calibration result
 * of the lower boundary of Byte0.
 */

#define BP_MMDC_MPWRDLHWST0_HW_WR_DL_LOW0      0
#define BM_MMDC_MPWRDLHWST0_HW_WR_DL_LOW0      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDLHWST0_HW_WR_DL_LOW0(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPWRDLHWST0_HW_WR_DL_LOW0)
#else
#define BF_MMDC_MPWRDLHWST0_HW_WR_DL_LOW0(v)   (((v) << 0) & BM_MMDC_MPWRDLHWST0_HW_WR_DL_LOW0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDLHWST0_HW_WR_DL_LOW0(v)   BF_CS1(MMDC_MPWRDLHWST0, HW_WR_DL_LOW0, v)
#endif

/* --- Register HW_MMDC_MPWRDLHWST0, field HW_WR_DL_UP0
 *
 * Automatic (HW) write calibration result of the upper boundary of
 * Byte0. This field holds the automatic (HW) write calibration result
 * of the upper boundary of Byte0.
 */

#define BP_MMDC_MPWRDLHWST0_HW_WR_DL_UP0      8
#define BM_MMDC_MPWRDLHWST0_HW_WR_DL_UP0      0x00007f00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDLHWST0_HW_WR_DL_UP0(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPWRDLHWST0_HW_WR_DL_UP0)
#else
#define BF_MMDC_MPWRDLHWST0_HW_WR_DL_UP0(v)   (((v) << 8) & BM_MMDC_MPWRDLHWST0_HW_WR_DL_UP0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDLHWST0_HW_WR_DL_UP0(v)   BF_CS1(MMDC_MPWRDLHWST0, HW_WR_DL_UP0, v)
#endif

/* --- Register HW_MMDC_MPWRDLHWST0, field HW_WR_DL_LOW1
 *
 * Automatic (HW) write calibration result of the lower boundary of
 * Byte1. This field holds the automatic (HW) write calibration result
 * of the lower boundary of Byte1.
 */

#define BP_MMDC_MPWRDLHWST0_HW_WR_DL_LOW1      16
#define BM_MMDC_MPWRDLHWST0_HW_WR_DL_LOW1      0x007f0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDLHWST0_HW_WR_DL_LOW1(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPWRDLHWST0_HW_WR_DL_LOW1)
#else
#define BF_MMDC_MPWRDLHWST0_HW_WR_DL_LOW1(v)   (((v) << 16) & BM_MMDC_MPWRDLHWST0_HW_WR_DL_LOW1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDLHWST0_HW_WR_DL_LOW1(v)   BF_CS1(MMDC_MPWRDLHWST0, HW_WR_DL_LOW1, v)
#endif

/* --- Register HW_MMDC_MPWRDLHWST0, field HW_WR_DL_UP1
 *
 * Aautomatic (HW) write utomatic (HW) write calibration result of the
 * upper boundary of Byte1. This field holds the automatic (HW) write
 * calibration result of the upper boundary of Byte1.
 */

#define BP_MMDC_MPWRDLHWST0_HW_WR_DL_UP1      24
#define BM_MMDC_MPWRDLHWST0_HW_WR_DL_UP1      0x7f000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDLHWST0_HW_WR_DL_UP1(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPWRDLHWST0_HW_WR_DL_UP1)
#else
#define BF_MMDC_MPWRDLHWST0_HW_WR_DL_UP1(v)   (((v) << 24) & BM_MMDC_MPWRDLHWST0_HW_WR_DL_UP1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDLHWST0_HW_WR_DL_UP1(v)   BF_CS1(MMDC_MPWRDLHWST0, HW_WR_DL_UP1, v)
#endif

/*!
 * @brief HW_MMDC_MPWRDLHWST1 - MMDC PHY Write Delay HW Calibration Status Register                        1
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: DDR3_x64, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned HW_WR_DL_LOW2 : 7; //!< Automatic (HW) write calibration result of the lower boundary of Byte2. This field holds the automatic (HW) write calibration result of the lower boundary of Byte2.
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned HW_WR_DL_UP2 : 7; //!< Automatic (HW) write calibration result of the upper boundary of Byte2. This field holds the automatic (HW) write calibration result of the upper boundary of Byte2.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned HW_WR_DL_LOW3 : 7; //!< Automatic (HW) write calibration result of the lower boundary of Byte3. This field holds the automatic (HW) write calibration result of the lower boundary of Byte3.
        unsigned RESERVED2 : 1; //!< Reserved
        unsigned HW_WR_DL_UP3 : 7; //!< Automatic (HW) write calibration result of the upper boundary of Byte3. This field holds the automatic (HW) write calibration result of the upper boundary of Byte3.
        unsigned RESERVED3 : 1; //!< Reserved
    } B;
} hw_mmdc_mpwrdlhwst1_t;
#endif

/*
 * constants & macros for entire MMDC_MPWRDLHWST1 register
 */
#define HW_MMDC_MPWRDLHWST1_ADDR      (REGS_MMDC_BASE + 0x874)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPWRDLHWST1           (*(volatile hw_mmdc_mpwrdlhwst1_t *) HW_MMDC_MPWRDLHWST1_ADDR)
#define HW_MMDC_MPWRDLHWST1_RD()      (HW_MMDC_MPWRDLHWST1.U)
#define HW_MMDC_MPWRDLHWST1_WR(v)     (HW_MMDC_MPWRDLHWST1.U = (v))
#define HW_MMDC_MPWRDLHWST1_SET(v)    (HW_MMDC_MPWRDLHWST1_WR(HW_MMDC_MPWRDLHWST1_RD() |  (v)))
#define HW_MMDC_MPWRDLHWST1_CLR(v)    (HW_MMDC_MPWRDLHWST1_WR(HW_MMDC_MPWRDLHWST1_RD() & ~(v)))
#define HW_MMDC_MPWRDLHWST1_TOG(v)    (HW_MMDC_MPWRDLHWST1_WR(HW_MMDC_MPWRDLHWST1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPWRDLHWST1 bitfields
 */

/* --- Register HW_MMDC_MPWRDLHWST1, field HW_WR_DL_LOW2
 *
 * Automatic (HW) write calibration result of the lower boundary of
 * Byte2. This field holds the automatic (HW) write calibration result
 * of the lower boundary of Byte2.
 */

#define BP_MMDC_MPWRDLHWST1_HW_WR_DL_LOW2      0
#define BM_MMDC_MPWRDLHWST1_HW_WR_DL_LOW2      0x0000007f

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDLHWST1_HW_WR_DL_LOW2(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPWRDLHWST1_HW_WR_DL_LOW2)
#else
#define BF_MMDC_MPWRDLHWST1_HW_WR_DL_LOW2(v)   (((v) << 0) & BM_MMDC_MPWRDLHWST1_HW_WR_DL_LOW2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDLHWST1_HW_WR_DL_LOW2(v)   BF_CS1(MMDC_MPWRDLHWST1, HW_WR_DL_LOW2, v)
#endif

/* --- Register HW_MMDC_MPWRDLHWST1, field HW_WR_DL_UP2
 *
 * Automatic (HW) write calibration result of the upper boundary of
 * Byte2. This field holds the automatic (HW) write calibration result
 * of the upper boundary of Byte2.
 */

#define BP_MMDC_MPWRDLHWST1_HW_WR_DL_UP2      8
#define BM_MMDC_MPWRDLHWST1_HW_WR_DL_UP2      0x00007f00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDLHWST1_HW_WR_DL_UP2(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPWRDLHWST1_HW_WR_DL_UP2)
#else
#define BF_MMDC_MPWRDLHWST1_HW_WR_DL_UP2(v)   (((v) << 8) & BM_MMDC_MPWRDLHWST1_HW_WR_DL_UP2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDLHWST1_HW_WR_DL_UP2(v)   BF_CS1(MMDC_MPWRDLHWST1, HW_WR_DL_UP2, v)
#endif

/* --- Register HW_MMDC_MPWRDLHWST1, field HW_WR_DL_LOW3
 *
 * Automatic (HW) write calibration result of the lower boundary of
 * Byte3. This field holds the automatic (HW) write calibration result
 * of the lower boundary of Byte3.
 */

#define BP_MMDC_MPWRDLHWST1_HW_WR_DL_LOW3      16
#define BM_MMDC_MPWRDLHWST1_HW_WR_DL_LOW3      0x007f0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDLHWST1_HW_WR_DL_LOW3(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPWRDLHWST1_HW_WR_DL_LOW3)
#else
#define BF_MMDC_MPWRDLHWST1_HW_WR_DL_LOW3(v)   (((v) << 16) & BM_MMDC_MPWRDLHWST1_HW_WR_DL_LOW3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDLHWST1_HW_WR_DL_LOW3(v)   BF_CS1(MMDC_MPWRDLHWST1, HW_WR_DL_LOW3, v)
#endif

/* --- Register HW_MMDC_MPWRDLHWST1, field HW_WR_DL_UP3
 *
 * Automatic (HW) write calibration result of the upper boundary of
 * Byte3. This field holds the automatic (HW) write calibration result
 * of the upper boundary of Byte3.
 */

#define BP_MMDC_MPWRDLHWST1_HW_WR_DL_UP3      24
#define BM_MMDC_MPWRDLHWST1_HW_WR_DL_UP3      0x7f000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRDLHWST1_HW_WR_DL_UP3(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPWRDLHWST1_HW_WR_DL_UP3)
#else
#define BF_MMDC_MPWRDLHWST1_HW_WR_DL_UP3(v)   (((v) << 24) & BM_MMDC_MPWRDLHWST1_HW_WR_DL_UP3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRDLHWST1_HW_WR_DL_UP3(v)   BF_CS1(MMDC_MPWRDLHWST1, HW_WR_DL_UP3, v)
#endif

/*!
 * @brief HW_MMDC_MPWLHWERR - MMDC PHY Write Leveling HW Error Register
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: DDR3_x64, LP2_2ch_x16,
 * LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned HW_WL0_DQ : 8; //!< HW write-leveling calibration result of Byte0. This field holds the results for all the 8 write-leveling steps of Byte0. i.e bit 0 holds the result of the write-leveling calibration of 0 delay, bit 1holds the result of the write-leveling calibration of 1/8delay till bit 7 that holds the result of the write-leveling calibration of 7/8 delay
        unsigned HW_WL1_DQ : 8; //!< HW write-leveling calibration result of Byte1. This field holds the results for all the 8 write-leveling steps of Byte1. i.e bit 0 holds the result of the write-leveling calibration of 0 delay, bit 1holds the result of the write-leveling calibration of 1/8delay till bit 7 that holds the result of the write-leveling calibration of 7/8 delay
        unsigned HW_WL2_DQ : 8; //!< HW write-leveling calibration result of Byte2. This field holds the results for all the 8 write-leveling steps of Byte2. i.e bit 0 holds the result of the write-leveling calibration of 0 delay, bit 1holds the result of the write-leveling calibration of 1/8delay till bit 7 that holds the result of the write-leveling calibration of 7/8 delay
        unsigned HW_WL3_DQ : 8; //!< HW write-leveling calibration result of Byte3. This field holds the results for all the 8 write-leveling steps of Byte3. i.e bit 0 holds the result of the write-leveling calibration of 0 delay, bit 1holds the result of the write-leveling calibration of 1/8delay till bit 7 that holdsthe result of the write-leveling calibration of 7/8 delay
    } B;
} hw_mmdc_mpwlhwerr_t;
#endif

/*
 * constants & macros for entire MMDC_MPWLHWERR register
 */
#define HW_MMDC_MPWLHWERR_ADDR      (REGS_MMDC_BASE + 0x878)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPWLHWERR           (*(volatile hw_mmdc_mpwlhwerr_t *) HW_MMDC_MPWLHWERR_ADDR)
#define HW_MMDC_MPWLHWERR_RD()      (HW_MMDC_MPWLHWERR.U)
#define HW_MMDC_MPWLHWERR_WR(v)     (HW_MMDC_MPWLHWERR.U = (v))
#define HW_MMDC_MPWLHWERR_SET(v)    (HW_MMDC_MPWLHWERR_WR(HW_MMDC_MPWLHWERR_RD() |  (v)))
#define HW_MMDC_MPWLHWERR_CLR(v)    (HW_MMDC_MPWLHWERR_WR(HW_MMDC_MPWLHWERR_RD() & ~(v)))
#define HW_MMDC_MPWLHWERR_TOG(v)    (HW_MMDC_MPWLHWERR_WR(HW_MMDC_MPWLHWERR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPWLHWERR bitfields
 */

/* --- Register HW_MMDC_MPWLHWERR, field HW_WL0_DQ
 *
 * HW write-leveling calibration result of Byte0. This field holds the
 * results for all the 8 write-leveling steps of Byte0. i.e bit 0 holds
 * the result of the write-leveling calibration of 0 delay, bit 1holds
 * the result of the write-leveling calibration of 1/8delay till bit 7
 * that holds the result of the write-leveling calibration of 7/8
 * delay
 */

#define BP_MMDC_MPWLHWERR_HW_WL0_DQ      0
#define BM_MMDC_MPWLHWERR_HW_WL0_DQ      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLHWERR_HW_WL0_DQ(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPWLHWERR_HW_WL0_DQ)
#else
#define BF_MMDC_MPWLHWERR_HW_WL0_DQ(v)   (((v) << 0) & BM_MMDC_MPWLHWERR_HW_WL0_DQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLHWERR_HW_WL0_DQ(v)   BF_CS1(MMDC_MPWLHWERR, HW_WL0_DQ, v)
#endif

/* --- Register HW_MMDC_MPWLHWERR, field HW_WL1_DQ
 *
 * HW write-leveling calibration result of Byte1. This field holds the
 * results for all the 8 write-leveling steps of Byte1. i.e bit 0 holds
 * the result of the write-leveling calibration of 0 delay, bit 1holds
 * the result of the write-leveling calibration of 1/8delay till bit 7
 * that holds the result of the write-leveling calibration of 7/8
 * delay
 */

#define BP_MMDC_MPWLHWERR_HW_WL1_DQ      8
#define BM_MMDC_MPWLHWERR_HW_WL1_DQ      0x0000ff00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLHWERR_HW_WL1_DQ(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPWLHWERR_HW_WL1_DQ)
#else
#define BF_MMDC_MPWLHWERR_HW_WL1_DQ(v)   (((v) << 8) & BM_MMDC_MPWLHWERR_HW_WL1_DQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLHWERR_HW_WL1_DQ(v)   BF_CS1(MMDC_MPWLHWERR, HW_WL1_DQ, v)
#endif

/* --- Register HW_MMDC_MPWLHWERR, field HW_WL2_DQ
 *
 * HW write-leveling calibration result of Byte2. This field holds the
 * results for all the 8 write-leveling steps of Byte2. i.e bit 0 holds
 * the result of the write-leveling calibration of 0 delay, bit 1holds
 * the result of the write-leveling calibration of 1/8delay till bit 7
 * that holds the result of the write-leveling calibration of 7/8
 * delay
 */

#define BP_MMDC_MPWLHWERR_HW_WL2_DQ      16
#define BM_MMDC_MPWLHWERR_HW_WL2_DQ      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLHWERR_HW_WL2_DQ(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPWLHWERR_HW_WL2_DQ)
#else
#define BF_MMDC_MPWLHWERR_HW_WL2_DQ(v)   (((v) << 16) & BM_MMDC_MPWLHWERR_HW_WL2_DQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLHWERR_HW_WL2_DQ(v)   BF_CS1(MMDC_MPWLHWERR, HW_WL2_DQ, v)
#endif

/* --- Register HW_MMDC_MPWLHWERR, field HW_WL3_DQ
 *
 * HW write-leveling calibration result of Byte3. This field holds the
 * results for all the 8 write-leveling steps of Byte3. i.e bit 0 holds
 * the result of the write-leveling calibration of 0 delay, bit 1holds
 * the result of the write-leveling calibration of 1/8delay till bit 7
 * that holdsthe result of the write-leveling calibration of 7/8
 * delay
 */

#define BP_MMDC_MPWLHWERR_HW_WL3_DQ      24
#define BM_MMDC_MPWLHWERR_HW_WL3_DQ      0xff000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWLHWERR_HW_WL3_DQ(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPWLHWERR_HW_WL3_DQ)
#else
#define BF_MMDC_MPWLHWERR_HW_WL3_DQ(v)   (((v) << 24) & BM_MMDC_MPWLHWERR_HW_WL3_DQ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWLHWERR_HW_WL3_DQ(v)   BF_CS1(MMDC_MPWLHWERR, HW_WL3_DQ, v)
#endif

/*!
 * @brief HW_MMDC_MPDGHWST0 - MMDC PHY Read DQS Gating HW Status Register                        0
 *
 * Supported Mode Of Operations:  For Channel 0: DDR3_x16, DDR3_x32, DDR3_x64  For Channel 1:
 * DDR3_x64
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned HW_DG_LOW0 : 11; //!< HW DQS gating calibration result of the lower boundary of Byte0. This field holds the HW DQS gating calibration result of the lower boundary of Byte0.
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned HW_DG_UP0 : 11; //!< HW DQS gating calibration result of the upper boundary of Byte0. This field holds the HW DQS gating calibration result of the upper boundary of Byte0.
        unsigned RESERVED1 : 5; //!< Reserved
    } B;
} hw_mmdc_mpdghwst0_t;
#endif

/*
 * constants & macros for entire MMDC_MPDGHWST0 register
 */
#define HW_MMDC_MPDGHWST0_ADDR      (REGS_MMDC_BASE + 0x87c)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPDGHWST0           (*(volatile hw_mmdc_mpdghwst0_t *) HW_MMDC_MPDGHWST0_ADDR)
#define HW_MMDC_MPDGHWST0_RD()      (HW_MMDC_MPDGHWST0.U)
#define HW_MMDC_MPDGHWST0_WR(v)     (HW_MMDC_MPDGHWST0.U = (v))
#define HW_MMDC_MPDGHWST0_SET(v)    (HW_MMDC_MPDGHWST0_WR(HW_MMDC_MPDGHWST0_RD() |  (v)))
#define HW_MMDC_MPDGHWST0_CLR(v)    (HW_MMDC_MPDGHWST0_WR(HW_MMDC_MPDGHWST0_RD() & ~(v)))
#define HW_MMDC_MPDGHWST0_TOG(v)    (HW_MMDC_MPDGHWST0_WR(HW_MMDC_MPDGHWST0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPDGHWST0 bitfields
 */

/* --- Register HW_MMDC_MPDGHWST0, field HW_DG_LOW0
 *
 * HW DQS gating calibration result of the lower boundary of Byte0. This
 * field holds the HW DQS gating calibration result of the lower
 * boundary of Byte0.
 */

#define BP_MMDC_MPDGHWST0_HW_DG_LOW0      0
#define BM_MMDC_MPDGHWST0_HW_DG_LOW0      0x000007ff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGHWST0_HW_DG_LOW0(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPDGHWST0_HW_DG_LOW0)
#else
#define BF_MMDC_MPDGHWST0_HW_DG_LOW0(v)   (((v) << 0) & BM_MMDC_MPDGHWST0_HW_DG_LOW0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGHWST0_HW_DG_LOW0(v)   BF_CS1(MMDC_MPDGHWST0, HW_DG_LOW0, v)
#endif

/* --- Register HW_MMDC_MPDGHWST0, field HW_DG_UP0
 *
 * HW DQS gating calibration result of the upper boundary of Byte0. This
 * field holds the HW DQS gating calibration result of the upper
 * boundary of Byte0.
 */

#define BP_MMDC_MPDGHWST0_HW_DG_UP0      16
#define BM_MMDC_MPDGHWST0_HW_DG_UP0      0x07ff0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGHWST0_HW_DG_UP0(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPDGHWST0_HW_DG_UP0)
#else
#define BF_MMDC_MPDGHWST0_HW_DG_UP0(v)   (((v) << 16) & BM_MMDC_MPDGHWST0_HW_DG_UP0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGHWST0_HW_DG_UP0(v)   BF_CS1(MMDC_MPDGHWST0, HW_DG_UP0, v)
#endif

/*!
 * @brief HW_MMDC_MPDGHWST1 - MMDC PHY Read DQS Gating HW Status Register                        1
 *
 * Supported Mode Of Operations:  For Channel 0: DDR3_x16, DDR3_x32, DDR3_x64  For Channel 1:
 * DDR3_x64
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned HW_DG_LOW1 : 11; //!< HW DQS gating calibration result of the lower boundary of Byte1. This field holds the HW DQS gating calibration result of the lower boundary of Byte1.
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned HW_DG_UP1 : 11; //!< HW DQS gating calibration result of the upper boundary of Byte1. This field holds the HW DQS gating calibration result of the upper boundary of Byte1.
        unsigned RESERVED1 : 5; //!< Reserved
    } B;
} hw_mmdc_mpdghwst1_t;
#endif

/*
 * constants & macros for entire MMDC_MPDGHWST1 register
 */
#define HW_MMDC_MPDGHWST1_ADDR      (REGS_MMDC_BASE + 0x880)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPDGHWST1           (*(volatile hw_mmdc_mpdghwst1_t *) HW_MMDC_MPDGHWST1_ADDR)
#define HW_MMDC_MPDGHWST1_RD()      (HW_MMDC_MPDGHWST1.U)
#define HW_MMDC_MPDGHWST1_WR(v)     (HW_MMDC_MPDGHWST1.U = (v))
#define HW_MMDC_MPDGHWST1_SET(v)    (HW_MMDC_MPDGHWST1_WR(HW_MMDC_MPDGHWST1_RD() |  (v)))
#define HW_MMDC_MPDGHWST1_CLR(v)    (HW_MMDC_MPDGHWST1_WR(HW_MMDC_MPDGHWST1_RD() & ~(v)))
#define HW_MMDC_MPDGHWST1_TOG(v)    (HW_MMDC_MPDGHWST1_WR(HW_MMDC_MPDGHWST1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPDGHWST1 bitfields
 */

/* --- Register HW_MMDC_MPDGHWST1, field HW_DG_LOW1
 *
 * HW DQS gating calibration result of the lower boundary of Byte1. This
 * field holds the HW DQS gating calibration result of the lower
 * boundary of Byte1.
 */

#define BP_MMDC_MPDGHWST1_HW_DG_LOW1      0
#define BM_MMDC_MPDGHWST1_HW_DG_LOW1      0x000007ff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGHWST1_HW_DG_LOW1(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPDGHWST1_HW_DG_LOW1)
#else
#define BF_MMDC_MPDGHWST1_HW_DG_LOW1(v)   (((v) << 0) & BM_MMDC_MPDGHWST1_HW_DG_LOW1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGHWST1_HW_DG_LOW1(v)   BF_CS1(MMDC_MPDGHWST1, HW_DG_LOW1, v)
#endif

/* --- Register HW_MMDC_MPDGHWST1, field HW_DG_UP1
 *
 * HW DQS gating calibration result of the upper boundary of Byte1. This
 * field holds the HW DQS gating calibration result of the upper
 * boundary of Byte1.
 */

#define BP_MMDC_MPDGHWST1_HW_DG_UP1      16
#define BM_MMDC_MPDGHWST1_HW_DG_UP1      0x07ff0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGHWST1_HW_DG_UP1(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPDGHWST1_HW_DG_UP1)
#else
#define BF_MMDC_MPDGHWST1_HW_DG_UP1(v)   (((v) << 16) & BM_MMDC_MPDGHWST1_HW_DG_UP1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGHWST1_HW_DG_UP1(v)   BF_CS1(MMDC_MPDGHWST1, HW_DG_UP1, v)
#endif

/*!
 * @brief HW_MMDC_MPDGHWST2 - MMDC PHY Read DQS Gating HW Status Register                        2
 *
 * Supported Mode Of Operations:  For Channel 0: DDR3_x16, DDR3_x32, DDR3_x64  For Channel 1:
 * DDR3_x64
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned HW_DG_LOW2 : 11; //!< HW DQS gating calibration result of the lower boundary of Byte2. This field holds the HW DQS gating calibration result of the lower boundary of Byte2.
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned HW_DG_UP2 : 11; //!< HW DQS gating calibration result of the upper boundary of Byte2. This field holds the HW DQS gating calibration result of the upper boundary of Byte2.
        unsigned RESERVED1 : 5; //!< Reserved
    } B;
} hw_mmdc_mpdghwst2_t;
#endif

/*
 * constants & macros for entire MMDC_MPDGHWST2 register
 */
#define HW_MMDC_MPDGHWST2_ADDR      (REGS_MMDC_BASE + 0x884)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPDGHWST2           (*(volatile hw_mmdc_mpdghwst2_t *) HW_MMDC_MPDGHWST2_ADDR)
#define HW_MMDC_MPDGHWST2_RD()      (HW_MMDC_MPDGHWST2.U)
#define HW_MMDC_MPDGHWST2_WR(v)     (HW_MMDC_MPDGHWST2.U = (v))
#define HW_MMDC_MPDGHWST2_SET(v)    (HW_MMDC_MPDGHWST2_WR(HW_MMDC_MPDGHWST2_RD() |  (v)))
#define HW_MMDC_MPDGHWST2_CLR(v)    (HW_MMDC_MPDGHWST2_WR(HW_MMDC_MPDGHWST2_RD() & ~(v)))
#define HW_MMDC_MPDGHWST2_TOG(v)    (HW_MMDC_MPDGHWST2_WR(HW_MMDC_MPDGHWST2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPDGHWST2 bitfields
 */

/* --- Register HW_MMDC_MPDGHWST2, field HW_DG_LOW2
 *
 * HW DQS gating calibration result of the lower boundary of Byte2. This
 * field holds the HW DQS gating calibration result of the lower
 * boundary of Byte2.
 */

#define BP_MMDC_MPDGHWST2_HW_DG_LOW2      0
#define BM_MMDC_MPDGHWST2_HW_DG_LOW2      0x000007ff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGHWST2_HW_DG_LOW2(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPDGHWST2_HW_DG_LOW2)
#else
#define BF_MMDC_MPDGHWST2_HW_DG_LOW2(v)   (((v) << 0) & BM_MMDC_MPDGHWST2_HW_DG_LOW2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGHWST2_HW_DG_LOW2(v)   BF_CS1(MMDC_MPDGHWST2, HW_DG_LOW2, v)
#endif

/* --- Register HW_MMDC_MPDGHWST2, field HW_DG_UP2
 *
 * HW DQS gating calibration result of the upper boundary of Byte2. This
 * field holds the HW DQS gating calibration result of the upper
 * boundary of Byte2.
 */

#define BP_MMDC_MPDGHWST2_HW_DG_UP2      16
#define BM_MMDC_MPDGHWST2_HW_DG_UP2      0x07ff0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGHWST2_HW_DG_UP2(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPDGHWST2_HW_DG_UP2)
#else
#define BF_MMDC_MPDGHWST2_HW_DG_UP2(v)   (((v) << 16) & BM_MMDC_MPDGHWST2_HW_DG_UP2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGHWST2_HW_DG_UP2(v)   BF_CS1(MMDC_MPDGHWST2, HW_DG_UP2, v)
#endif

/*!
 * @brief HW_MMDC_MPDGHWST3 - MMDC PHY Read DQS Gating HW Status Register                        3
 *
 * Supported Mode Of Operations:  For Channel 0: DDR3_x16, DDR3_x32, DDR3_x64  For Channel 1:
 * DDR3_x64
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned HW_DG_LOW3 : 11; //!< HW DQS gating calibration result of the lower boundary of Byte3. This field holds the HW DQS gating calibration result of the lower boundary of Byte3.
        unsigned RESERVED0 : 5; //!< Reserved
        unsigned HW_DG_UP3 : 11; //!< HW DQS gating calibration result of the upper boundary of Byte3. This field holds the HW DQS gating calibration result of the upper boundary of Byte3.
        unsigned RESERVED1 : 5; //!< Reserved
    } B;
} hw_mmdc_mpdghwst3_t;
#endif

/*
 * constants & macros for entire MMDC_MPDGHWST3 register
 */
#define HW_MMDC_MPDGHWST3_ADDR      (REGS_MMDC_BASE + 0x888)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPDGHWST3           (*(volatile hw_mmdc_mpdghwst3_t *) HW_MMDC_MPDGHWST3_ADDR)
#define HW_MMDC_MPDGHWST3_RD()      (HW_MMDC_MPDGHWST3.U)
#define HW_MMDC_MPDGHWST3_WR(v)     (HW_MMDC_MPDGHWST3.U = (v))
#define HW_MMDC_MPDGHWST3_SET(v)    (HW_MMDC_MPDGHWST3_WR(HW_MMDC_MPDGHWST3_RD() |  (v)))
#define HW_MMDC_MPDGHWST3_CLR(v)    (HW_MMDC_MPDGHWST3_WR(HW_MMDC_MPDGHWST3_RD() & ~(v)))
#define HW_MMDC_MPDGHWST3_TOG(v)    (HW_MMDC_MPDGHWST3_WR(HW_MMDC_MPDGHWST3_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPDGHWST3 bitfields
 */

/* --- Register HW_MMDC_MPDGHWST3, field HW_DG_LOW3
 *
 * HW DQS gating calibration result of the lower boundary of Byte3. This
 * field holds the HW DQS gating calibration result of the lower
 * boundary of Byte3.
 */

#define BP_MMDC_MPDGHWST3_HW_DG_LOW3      0
#define BM_MMDC_MPDGHWST3_HW_DG_LOW3      0x000007ff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGHWST3_HW_DG_LOW3(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPDGHWST3_HW_DG_LOW3)
#else
#define BF_MMDC_MPDGHWST3_HW_DG_LOW3(v)   (((v) << 0) & BM_MMDC_MPDGHWST3_HW_DG_LOW3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGHWST3_HW_DG_LOW3(v)   BF_CS1(MMDC_MPDGHWST3, HW_DG_LOW3, v)
#endif

/* --- Register HW_MMDC_MPDGHWST3, field HW_DG_UP3
 *
 * HW DQS gating calibration result of the upper boundary of Byte3. This
 * field holds the HW DQS gating calibration result of the upper
 * boundary of Byte3.
 */

#define BP_MMDC_MPDGHWST3_HW_DG_UP3      16
#define BM_MMDC_MPDGHWST3_HW_DG_UP3      0x07ff0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDGHWST3_HW_DG_UP3(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPDGHWST3_HW_DG_UP3)
#else
#define BF_MMDC_MPDGHWST3_HW_DG_UP3(v)   (((v) << 16) & BM_MMDC_MPDGHWST3_HW_DG_UP3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDGHWST3_HW_DG_UP3(v)   BF_CS1(MMDC_MPDGHWST3, HW_DG_UP3, v)
#endif

/*!
 * @brief HW_MMDC_MPPDCMPR1 - MMDC PHY Pre-defined Compare Register 1
 *
 * This register holds the MMDC pre-defined compare value that will be used
 * during automatic read, read DQS gating and write calibration process.
 * The compare value can be the MPR value (as defined in the JEDEC) or can
 * be programmed by the PDV1 and PDV2 fields. In case of DDR3 (BL=8) the
 * MMDC will duplicate PDV1,PDV2 and drive that data on Beat4-7 of the same
 * byte  Supported Mode Of Operations:  For Channel 0: All  For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PDV1 : 16; //!< MMDC Pre defined comapre value2. This field holds the 2 LSB of the data that will be driven to the DDR device during automatic read, read DQS gating and write calibrations in case MPR(DDR3)/ DQ calibration (LPDDR2) mode are disabled (MPR_CMP is disabled). Upon read access during the calibration the MMDC will compare the read data with the data that is stored in this field.  Note : Before issue the read access the MMDC will invert the value of this field and drive it to the associate entry in the read comparison FIFO. For further information see Section 19.14.3.1.2, "Calibration with pre-defined value , Section 19.14.4.1.2, "Calibration with pre-defined value and Section 19.14.5.1, "HW (automatic) Write Calibraion
        unsigned PDV2 : 16; //!< MMDC Pre defined comapre value2. This field holds the 2 MSB of the data that will be driven to the DDR device during automatic read, read DQS gating and write calibrations in case MPR(DDR3)/ DQ calibration (LPDDR2) mode are disabled (MPR_CMP is disabled). Upon read access during the calibration the MMDC will compare the read data with the data that is stored in this field.  Note : Before issue the read access the MMDC will invert the value of this field and drive it to the associate entry in the read comparison FIFO. For further information see Section 19.14.3.1.2, "Calibration with pre-defined value , Section 19.14.4.1.2, "Calibration with pre-defined value and Section 19.14.5.1, "HW (automatic) Write Calibraion
    } B;
} hw_mmdc_mppdcmpr1_t;
#endif

/*
 * constants & macros for entire MMDC_MPPDCMPR1 register
 */
#define HW_MMDC_MPPDCMPR1_ADDR      (REGS_MMDC_BASE + 0x88c)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPPDCMPR1           (*(volatile hw_mmdc_mppdcmpr1_t *) HW_MMDC_MPPDCMPR1_ADDR)
#define HW_MMDC_MPPDCMPR1_RD()      (HW_MMDC_MPPDCMPR1.U)
#define HW_MMDC_MPPDCMPR1_WR(v)     (HW_MMDC_MPPDCMPR1.U = (v))
#define HW_MMDC_MPPDCMPR1_SET(v)    (HW_MMDC_MPPDCMPR1_WR(HW_MMDC_MPPDCMPR1_RD() |  (v)))
#define HW_MMDC_MPPDCMPR1_CLR(v)    (HW_MMDC_MPPDCMPR1_WR(HW_MMDC_MPPDCMPR1_RD() & ~(v)))
#define HW_MMDC_MPPDCMPR1_TOG(v)    (HW_MMDC_MPPDCMPR1_WR(HW_MMDC_MPPDCMPR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPPDCMPR1 bitfields
 */

/* --- Register HW_MMDC_MPPDCMPR1, field PDV1
 *
 * MMDC Pre defined comapre value2. This field holds the 2 LSB of the
 * data that will be driven to the DDR device during automatic read,
 * read DQS gating and write calibrations in case MPR(DDR3)/ DQ
 * calibration (LPDDR2) mode are disabled (MPR_CMP is disabled). Upon
 * read access during the calibration the MMDC will compare the read
 * data with the data that is stored in this field.  Note : Before issue the read access the MMDC
 * will invert the value of                                 this field and drive it to the associate
 * entry in the read                                 comparison FIFO. For further information see
 * Section 19.14.3.1.2,                                 "Calibration with pre-defined value ,
 * Section 19.14.4.1.2,                                 "Calibration with pre-defined value and
 * Section 19.14.5.1, "HW                                 (automatic) Write Calibraion
 */

#define BP_MMDC_MPPDCMPR1_PDV1      0
#define BM_MMDC_MPPDCMPR1_PDV1      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPPDCMPR1_PDV1(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPPDCMPR1_PDV1)
#else
#define BF_MMDC_MPPDCMPR1_PDV1(v)   (((v) << 0) & BM_MMDC_MPPDCMPR1_PDV1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPPDCMPR1_PDV1(v)   BF_CS1(MMDC_MPPDCMPR1, PDV1, v)
#endif

/* --- Register HW_MMDC_MPPDCMPR1, field PDV2
 *
 * MMDC Pre defined comapre value2. This field holds the 2 MSB of the
 * data that will be driven to the DDR device during automatic read,
 * read DQS gating and write calibrations in case MPR(DDR3)/ DQ
 * calibration (LPDDR2) mode are disabled (MPR_CMP is disabled). Upon
 * read access during the calibration the MMDC will compare the read
 * data with the data that is stored in this field.  Note : Before issue the read access the MMDC
 * will invert the value of                                 this field and drive it to the associate
 * entry in the read                                 comparison FIFO. For further information see
 * Section 19.14.3.1.2,                                 "Calibration with pre-defined value ,
 * Section 19.14.4.1.2,                                 "Calibration with pre-defined value and
 * Section 19.14.5.1, "HW                                 (automatic) Write Calibraion
 */

#define BP_MMDC_MPPDCMPR1_PDV2      16
#define BM_MMDC_MPPDCMPR1_PDV2      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPPDCMPR1_PDV2(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPPDCMPR1_PDV2)
#else
#define BF_MMDC_MPPDCMPR1_PDV2(v)   (((v) << 16) & BM_MMDC_MPPDCMPR1_PDV2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPPDCMPR1_PDV2(v)   BF_CS1(MMDC_MPPDCMPR1, PDV2, v)
#endif

/*!
 * @brief HW_MMDC_MPPDCMPR2 - MMDC PHY Pre-defined Compare and CA delay-line Configuration                        Register
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MPR_CMP : 1; //!< MPR(DDR3)/DQ calibration (LPDDR2) comapre enable. This bit indicates whether the MMDC will compare the read data during automatic read and read DQS calibration processes to the pre-defined patterns that are driven by the DDR deivce (READ_LEVEL_PATTERN as defined by JEDEC) or general pre-defined value that are stored in PDV1 and PDV2. When this bit is disabled data is compared to the data of the pre defined compare value field  For further information see and .
        unsigned MPR_FULL_CMP : 1; //!< MPR(DDR3)/DQ calibration (LPDDR2) full compare enable. In case MPR(DDR3)/DQ calibration(LPDDR2) modes are used during the calibration process (MPR_CMP is asserted) then this field indicates whether the MMDC will compare all the bits of the data that is read from the DDR device to the MPR pre-defined pattern. When this bit is de-asserted only LSB of each byte is compared.
        unsigned READ_LEVEL_PATTERN : 1; //!< MPR(DDR3)/DQ calibration(LPDDR2) read compare pattern. In case MPR(DDR3)/DQ calibration(LPDDR2) modes are used during the calibration process (MPR_CMP is asserted) then this field indicates the read pattern for the comparison.
        unsigned RESERVED0 : 13; //!< Reserved
        unsigned CA_DL_ABS_OFFSET : 7; //!< Absolute CA (Command/Address of LPDDRR2) offset. This field indicates the absolute delay between CA (Command/Address) bus and the DDR clock (CK) with fractions of a clock period and up to half cycle. The fraction is process and frequency independent. The delay of the delay-line would be (CA_DL_ABS_OFFSET / 256) * fast_clk. So for the default value of 64 we get a quarter cycle delay.
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned PHY_CA_DL_UNIT : 7; //!< This field reflects the number of delay units that are actually used by CA (Command/Address of LPDDR2) delay-line
        unsigned RESERVED2 : 1; //!< Reserved
    } B;
} hw_mmdc_mppdcmpr2_t;
#endif

/*
 * constants & macros for entire MMDC_MPPDCMPR2 register
 */
#define HW_MMDC_MPPDCMPR2_ADDR      (REGS_MMDC_BASE + 0x890)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPPDCMPR2           (*(volatile hw_mmdc_mppdcmpr2_t *) HW_MMDC_MPPDCMPR2_ADDR)
#define HW_MMDC_MPPDCMPR2_RD()      (HW_MMDC_MPPDCMPR2.U)
#define HW_MMDC_MPPDCMPR2_WR(v)     (HW_MMDC_MPPDCMPR2.U = (v))
#define HW_MMDC_MPPDCMPR2_SET(v)    (HW_MMDC_MPPDCMPR2_WR(HW_MMDC_MPPDCMPR2_RD() |  (v)))
#define HW_MMDC_MPPDCMPR2_CLR(v)    (HW_MMDC_MPPDCMPR2_WR(HW_MMDC_MPPDCMPR2_RD() & ~(v)))
#define HW_MMDC_MPPDCMPR2_TOG(v)    (HW_MMDC_MPPDCMPR2_WR(HW_MMDC_MPPDCMPR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPPDCMPR2 bitfields
 */

/* --- Register HW_MMDC_MPPDCMPR2, field MPR_CMP
 *
 * MPR(DDR3)/DQ calibration (LPDDR2) comapre enable. This bit indicates
 * whether the MMDC will compare the read data during automatic read
 * and read DQS calibration processes to the pre-defined patterns that
 * are driven by the DDR deivce (READ_LEVEL_PATTERN as defined by
 * JEDEC) or general pre-defined value that are stored in PDV1 and
 * PDV2. When this bit is disabled data is compared to the data of the
 * pre defined compare value field  For further information see and .
 */

#define BP_MMDC_MPPDCMPR2_MPR_CMP      0
#define BM_MMDC_MPPDCMPR2_MPR_CMP      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPPDCMPR2_MPR_CMP(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPPDCMPR2_MPR_CMP)
#else
#define BF_MMDC_MPPDCMPR2_MPR_CMP(v)   (((v) << 0) & BM_MMDC_MPPDCMPR2_MPR_CMP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPPDCMPR2_MPR_CMP(v)   BF_CS1(MMDC_MPPDCMPR2, MPR_CMP, v)
#endif

/* --- Register HW_MMDC_MPPDCMPR2, field MPR_FULL_CMP
 *
 * MPR(DDR3)/DQ calibration (LPDDR2) full compare enable. In case
 * MPR(DDR3)/DQ calibration(LPDDR2) modes are used during the
 * calibration process (MPR_CMP is asserted) then this field indicates
 * whether the MMDC will compare all the bits of the data that is read
 * from the DDR device to the MPR pre-defined pattern. When this bit is
 * de-asserted only LSB of each byte is compared.
 */

#define BP_MMDC_MPPDCMPR2_MPR_FULL_CMP      1
#define BM_MMDC_MPPDCMPR2_MPR_FULL_CMP      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPPDCMPR2_MPR_FULL_CMP(v)   ((((reg32_t) v) << 1) & BM_MMDC_MPPDCMPR2_MPR_FULL_CMP)
#else
#define BF_MMDC_MPPDCMPR2_MPR_FULL_CMP(v)   (((v) << 1) & BM_MMDC_MPPDCMPR2_MPR_FULL_CMP)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPPDCMPR2_MPR_FULL_CMP(v)   BF_CS1(MMDC_MPPDCMPR2, MPR_FULL_CMP, v)
#endif

/* --- Register HW_MMDC_MPPDCMPR2, field READ_LEVEL_PATTERN
 *
 * MPR(DDR3)/DQ calibration(LPDDR2) read compare pattern. In case
 * MPR(DDR3)/DQ calibration(LPDDR2) modes are used during the
 * calibration process (MPR_CMP is asserted) then this field indicates
 * the read pattern for the comparison.
 */

#define BP_MMDC_MPPDCMPR2_READ_LEVEL_PATTERN      2
#define BM_MMDC_MPPDCMPR2_READ_LEVEL_PATTERN      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPPDCMPR2_READ_LEVEL_PATTERN(v)   ((((reg32_t) v) << 2) & BM_MMDC_MPPDCMPR2_READ_LEVEL_PATTERN)
#else
#define BF_MMDC_MPPDCMPR2_READ_LEVEL_PATTERN(v)   (((v) << 2) & BM_MMDC_MPPDCMPR2_READ_LEVEL_PATTERN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPPDCMPR2_READ_LEVEL_PATTERN(v)   BF_CS1(MMDC_MPPDCMPR2, READ_LEVEL_PATTERN, v)
#endif

/* --- Register HW_MMDC_MPPDCMPR2, field CA_DL_ABS_OFFSET
 *
 * Absolute CA (Command/Address of LPDDRR2) offset. This field indicates
 * the absolute delay between CA (Command/Address) bus and the DDR
 * clock (CK) with fractions of a clock period and up to half cycle.
 * The fraction is process and frequency independent. The delay of the
 * delay-line would be (CA_DL_ABS_OFFSET / 256) * fast_clk. So for the
 * default value of 64 we get a quarter cycle delay.
 */

#define BP_MMDC_MPPDCMPR2_CA_DL_ABS_OFFSET      16
#define BM_MMDC_MPPDCMPR2_CA_DL_ABS_OFFSET      0x007f0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPPDCMPR2_CA_DL_ABS_OFFSET(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPPDCMPR2_CA_DL_ABS_OFFSET)
#else
#define BF_MMDC_MPPDCMPR2_CA_DL_ABS_OFFSET(v)   (((v) << 16) & BM_MMDC_MPPDCMPR2_CA_DL_ABS_OFFSET)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPPDCMPR2_CA_DL_ABS_OFFSET(v)   BF_CS1(MMDC_MPPDCMPR2, CA_DL_ABS_OFFSET, v)
#endif

/* --- Register HW_MMDC_MPPDCMPR2, field PHY_CA_DL_UNIT
 *
 * This field reflects the number of delay units that are actually used
 * by CA (Command/Address of LPDDR2) delay-line
 */

#define BP_MMDC_MPPDCMPR2_PHY_CA_DL_UNIT      24
#define BM_MMDC_MPPDCMPR2_PHY_CA_DL_UNIT      0x7f000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPPDCMPR2_PHY_CA_DL_UNIT(v)   ((((reg32_t) v) << 24) & BM_MMDC_MPPDCMPR2_PHY_CA_DL_UNIT)
#else
#define BF_MMDC_MPPDCMPR2_PHY_CA_DL_UNIT(v)   (((v) << 24) & BM_MMDC_MPPDCMPR2_PHY_CA_DL_UNIT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPPDCMPR2_PHY_CA_DL_UNIT(v)   BF_CS1(MMDC_MPPDCMPR2, PHY_CA_DL_UNIT, v)
#endif

/*!
 * @brief HW_MMDC_MPSWDAR0 - MMDC PHY SW Dummy Access Register
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: DDR3_x64, LP2_2ch_x16,
 * LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned SW_DUMMY_WR : 1; //!< SW dummy write. When this bit is asserted the MMDC will generate internally write access without intervention of the system toward bank 0, row 0, column 0, while the data is driven from MPPDCMPR1[PDV1] and MPPDCMPR1[PDV2]. The bit is de-asserted automatically upon completion of the access.
        unsigned SW_DUMMY_RD : 1; //!< SW dummy read. When this bit is asserted the MMDC will generate internally read access without intervention of the system toward bank 0, row 0, column 0. If MPR_CMP = 1then the read data will be compared to MPPDCMPR2[READ_LEVEL_PATTERN] . If MPR_CMP =0 then the read data will be compared to MPPDCMPR1[PDV1], MPPDCMPR1[PDV2]. Upon completion of the access this bit is de-asserted automatically and the read data and comparison results are valid at MPSWDAR0[SW_DUM_CMP#] and MPSWDRDR0-MPSWDRDR7 respectively.
        unsigned SW_DUM_CMP0 : 1; //!< SW dummy read byte0 compare results. This bit indicates the result of the read data comparison of Byte0 at the completion of SW_DUMMY_RD. This bit is valid only when SW_DUMMY_RD is de-assrted.
        unsigned SW_DUM_CMP1 : 1; //!< SW dummy read byte1 compare results. This bit indicates the result of the read data comparison of Byte1 at the completion of SW_DUMMY_RD. This bit is valid only when SW_DUMMY_RD is de-assrted.
        unsigned SW_DUM_CMP2 : 1; //!< SW dummy read byte2 compare results. This bit indicates the result of the read data comparison of Byte2 at the completion of SW_DUMMY_RD. This bit is valid only when SW_DUMMY_RD is de-assrted.
        unsigned SW_DUM_CMP3 : 1; //!< SW dummy read byte3 compare results. This bit indicates the result of the read data comparison of Byte3 at the completion of SW_DUMMY_RD. This bit is valid only when SW_DUMMY_RD is de-assrted.
        unsigned RESERVED0 : 26; //!< Reserved
    } B;
} hw_mmdc_mpswdar0_t;
#endif

/*
 * constants & macros for entire MMDC_MPSWDAR0 register
 */
#define HW_MMDC_MPSWDAR0_ADDR      (REGS_MMDC_BASE + 0x894)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPSWDAR0           (*(volatile hw_mmdc_mpswdar0_t *) HW_MMDC_MPSWDAR0_ADDR)
#define HW_MMDC_MPSWDAR0_RD()      (HW_MMDC_MPSWDAR0.U)
#define HW_MMDC_MPSWDAR0_WR(v)     (HW_MMDC_MPSWDAR0.U = (v))
#define HW_MMDC_MPSWDAR0_SET(v)    (HW_MMDC_MPSWDAR0_WR(HW_MMDC_MPSWDAR0_RD() |  (v)))
#define HW_MMDC_MPSWDAR0_CLR(v)    (HW_MMDC_MPSWDAR0_WR(HW_MMDC_MPSWDAR0_RD() & ~(v)))
#define HW_MMDC_MPSWDAR0_TOG(v)    (HW_MMDC_MPSWDAR0_WR(HW_MMDC_MPSWDAR0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPSWDAR0 bitfields
 */

/* --- Register HW_MMDC_MPSWDAR0, field SW_DUMMY_WR
 *
 * SW dummy write. When this bit is asserted the MMDC will generate
 * internally write access without intervention of the system toward
 * bank 0, row 0, column 0, while the data is driven from
 * MPPDCMPR1[PDV1] and MPPDCMPR1[PDV2]. The bit is de-asserted
 * automatically upon completion of the access.
 */

#define BP_MMDC_MPSWDAR0_SW_DUMMY_WR      0
#define BM_MMDC_MPSWDAR0_SW_DUMMY_WR      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPSWDAR0_SW_DUMMY_WR(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPSWDAR0_SW_DUMMY_WR)
#else
#define BF_MMDC_MPSWDAR0_SW_DUMMY_WR(v)   (((v) << 0) & BM_MMDC_MPSWDAR0_SW_DUMMY_WR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPSWDAR0_SW_DUMMY_WR(v)   BF_CS1(MMDC_MPSWDAR0, SW_DUMMY_WR, v)
#endif

/* --- Register HW_MMDC_MPSWDAR0, field SW_DUMMY_RD
 *
 * SW dummy read. When this bit is asserted the MMDC will generate
 * internally read access without intervention of the system toward
 * bank 0, row 0, column 0. If MPR_CMP = 1then the read data will be
 * compared to MPPDCMPR2[READ_LEVEL_PATTERN] . If MPR_CMP =0 then the
 * read data will be compared to MPPDCMPR1[PDV1], MPPDCMPR1[PDV2]. Upon
 * completion of the access this bit is de-asserted automatically and
 * the read data and comparison results are valid at
 * MPSWDAR0[SW_DUM_CMP#] and MPSWDRDR0-MPSWDRDR7 respectively.
 */

#define BP_MMDC_MPSWDAR0_SW_DUMMY_RD      1
#define BM_MMDC_MPSWDAR0_SW_DUMMY_RD      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPSWDAR0_SW_DUMMY_RD(v)   ((((reg32_t) v) << 1) & BM_MMDC_MPSWDAR0_SW_DUMMY_RD)
#else
#define BF_MMDC_MPSWDAR0_SW_DUMMY_RD(v)   (((v) << 1) & BM_MMDC_MPSWDAR0_SW_DUMMY_RD)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPSWDAR0_SW_DUMMY_RD(v)   BF_CS1(MMDC_MPSWDAR0, SW_DUMMY_RD, v)
#endif

/* --- Register HW_MMDC_MPSWDAR0, field SW_DUM_CMP0
 *
 * SW dummy read byte0 compare results. This bit indicates the result of
 * the read data comparison of Byte0 at the completion of SW_DUMMY_RD.
 * This bit is valid only when SW_DUMMY_RD is de-assrted.
 */

#define BP_MMDC_MPSWDAR0_SW_DUM_CMP0      2
#define BM_MMDC_MPSWDAR0_SW_DUM_CMP0      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPSWDAR0_SW_DUM_CMP0(v)   ((((reg32_t) v) << 2) & BM_MMDC_MPSWDAR0_SW_DUM_CMP0)
#else
#define BF_MMDC_MPSWDAR0_SW_DUM_CMP0(v)   (((v) << 2) & BM_MMDC_MPSWDAR0_SW_DUM_CMP0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPSWDAR0_SW_DUM_CMP0(v)   BF_CS1(MMDC_MPSWDAR0, SW_DUM_CMP0, v)
#endif

/* --- Register HW_MMDC_MPSWDAR0, field SW_DUM_CMP1
 *
 * SW dummy read byte1 compare results. This bit indicates the result of
 * the read data comparison of Byte1 at the completion of SW_DUMMY_RD.
 * This bit is valid only when SW_DUMMY_RD is de-assrted.
 */

#define BP_MMDC_MPSWDAR0_SW_DUM_CMP1      3
#define BM_MMDC_MPSWDAR0_SW_DUM_CMP1      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPSWDAR0_SW_DUM_CMP1(v)   ((((reg32_t) v) << 3) & BM_MMDC_MPSWDAR0_SW_DUM_CMP1)
#else
#define BF_MMDC_MPSWDAR0_SW_DUM_CMP1(v)   (((v) << 3) & BM_MMDC_MPSWDAR0_SW_DUM_CMP1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPSWDAR0_SW_DUM_CMP1(v)   BF_CS1(MMDC_MPSWDAR0, SW_DUM_CMP1, v)
#endif

/* --- Register HW_MMDC_MPSWDAR0, field SW_DUM_CMP2
 *
 * SW dummy read byte2 compare results. This bit indicates the result of
 * the read data comparison of Byte2 at the completion of SW_DUMMY_RD.
 * This bit is valid only when SW_DUMMY_RD is de-assrted.
 */

#define BP_MMDC_MPSWDAR0_SW_DUM_CMP2      4
#define BM_MMDC_MPSWDAR0_SW_DUM_CMP2      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPSWDAR0_SW_DUM_CMP2(v)   ((((reg32_t) v) << 4) & BM_MMDC_MPSWDAR0_SW_DUM_CMP2)
#else
#define BF_MMDC_MPSWDAR0_SW_DUM_CMP2(v)   (((v) << 4) & BM_MMDC_MPSWDAR0_SW_DUM_CMP2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPSWDAR0_SW_DUM_CMP2(v)   BF_CS1(MMDC_MPSWDAR0, SW_DUM_CMP2, v)
#endif

/* --- Register HW_MMDC_MPSWDAR0, field SW_DUM_CMP3
 *
 * SW dummy read byte3 compare results. This bit indicates the result of
 * the read data comparison of Byte3 at the completion of SW_DUMMY_RD.
 * This bit is valid only when SW_DUMMY_RD is de-assrted.
 */

#define BP_MMDC_MPSWDAR0_SW_DUM_CMP3      5
#define BM_MMDC_MPSWDAR0_SW_DUM_CMP3      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPSWDAR0_SW_DUM_CMP3(v)   ((((reg32_t) v) << 5) & BM_MMDC_MPSWDAR0_SW_DUM_CMP3)
#else
#define BF_MMDC_MPSWDAR0_SW_DUM_CMP3(v)   (((v) << 5) & BM_MMDC_MPSWDAR0_SW_DUM_CMP3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPSWDAR0_SW_DUM_CMP3(v)   BF_CS1(MMDC_MPSWDAR0, SW_DUM_CMP3, v)
#endif

/*!
 * @brief HW_MMDC_MPSWDRDR0 - MMDC PHY SW Dummy Read Data Register 0
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: DDR3_x64, LP2_2ch_x16,
 * LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DUM_RD0 : 32; //!< Dummy read data0. This field holds the first data that is read from the DDR during SW dummy read access (i.e when SW_DUMMY_RD = 1). This field is valid only when SW_DUMMY_RD is de-assrted
    } B;
} hw_mmdc_mpswdrdr0_t;
#endif

/*
 * constants & macros for entire MMDC_MPSWDRDR0 register
 */
#define HW_MMDC_MPSWDRDR0_ADDR      (REGS_MMDC_BASE + 0x898)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPSWDRDR0           (*(volatile hw_mmdc_mpswdrdr0_t *) HW_MMDC_MPSWDRDR0_ADDR)
#define HW_MMDC_MPSWDRDR0_RD()      (HW_MMDC_MPSWDRDR0.U)
#define HW_MMDC_MPSWDRDR0_WR(v)     (HW_MMDC_MPSWDRDR0.U = (v))
#define HW_MMDC_MPSWDRDR0_SET(v)    (HW_MMDC_MPSWDRDR0_WR(HW_MMDC_MPSWDRDR0_RD() |  (v)))
#define HW_MMDC_MPSWDRDR0_CLR(v)    (HW_MMDC_MPSWDRDR0_WR(HW_MMDC_MPSWDRDR0_RD() & ~(v)))
#define HW_MMDC_MPSWDRDR0_TOG(v)    (HW_MMDC_MPSWDRDR0_WR(HW_MMDC_MPSWDRDR0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPSWDRDR0 bitfields
 */

/* --- Register HW_MMDC_MPSWDRDR0, field DUM_RD0
 *
 * Dummy read data0. This field holds the first data that is read from
 * the DDR during SW dummy read access (i.e when SW_DUMMY_RD = 1). This
 * field is valid only when SW_DUMMY_RD is de-assrted
 */

#define BP_MMDC_MPSWDRDR0_DUM_RD0      0
#define BM_MMDC_MPSWDRDR0_DUM_RD0      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPSWDRDR0_DUM_RD0(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPSWDRDR0_DUM_RD0)
#else
#define BF_MMDC_MPSWDRDR0_DUM_RD0(v)   (((v) << 0) & BM_MMDC_MPSWDRDR0_DUM_RD0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPSWDRDR0_DUM_RD0(v)   BF_CS1(MMDC_MPSWDRDR0, DUM_RD0, v)
#endif

/*!
 * @brief HW_MMDC_MPSWDRDR1 - MMDC PHY SW Dummy Read Data Register 1
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: DDR3_x64, LP2_2ch_x16,
 * LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DUM_RD1 : 32; //!< Dummy read data1. This field holds the second data that is read from the DDR during SW dummy read access (i.e when SW_DUMMY_RD = 1). This field is valid only when SW_DUMMY_RD is de-assrted
    } B;
} hw_mmdc_mpswdrdr1_t;
#endif

/*
 * constants & macros for entire MMDC_MPSWDRDR1 register
 */
#define HW_MMDC_MPSWDRDR1_ADDR      (REGS_MMDC_BASE + 0x89c)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPSWDRDR1           (*(volatile hw_mmdc_mpswdrdr1_t *) HW_MMDC_MPSWDRDR1_ADDR)
#define HW_MMDC_MPSWDRDR1_RD()      (HW_MMDC_MPSWDRDR1.U)
#define HW_MMDC_MPSWDRDR1_WR(v)     (HW_MMDC_MPSWDRDR1.U = (v))
#define HW_MMDC_MPSWDRDR1_SET(v)    (HW_MMDC_MPSWDRDR1_WR(HW_MMDC_MPSWDRDR1_RD() |  (v)))
#define HW_MMDC_MPSWDRDR1_CLR(v)    (HW_MMDC_MPSWDRDR1_WR(HW_MMDC_MPSWDRDR1_RD() & ~(v)))
#define HW_MMDC_MPSWDRDR1_TOG(v)    (HW_MMDC_MPSWDRDR1_WR(HW_MMDC_MPSWDRDR1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPSWDRDR1 bitfields
 */

/* --- Register HW_MMDC_MPSWDRDR1, field DUM_RD1
 *
 * Dummy read data1. This field holds the second data that is read from
 * the DDR during SW dummy read access (i.e when SW_DUMMY_RD = 1). This
 * field is valid only when SW_DUMMY_RD is de-assrted
 */

#define BP_MMDC_MPSWDRDR1_DUM_RD1      0
#define BM_MMDC_MPSWDRDR1_DUM_RD1      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPSWDRDR1_DUM_RD1(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPSWDRDR1_DUM_RD1)
#else
#define BF_MMDC_MPSWDRDR1_DUM_RD1(v)   (((v) << 0) & BM_MMDC_MPSWDRDR1_DUM_RD1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPSWDRDR1_DUM_RD1(v)   BF_CS1(MMDC_MPSWDRDR1, DUM_RD1, v)
#endif

/*!
 * @brief HW_MMDC_MPSWDRDR2 - MMDC PHY SW Dummy Read Data Register 2
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: DDR3_x64, LP2_2ch_x16,
 * LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DUM_RD2 : 32; //!< Dummy read data2. This field holds the third data that is read from the DDR during SW dummy read access (i.e when SW_DUMMY_RD = 1). This field is valid only when SW_DUMMY_RD is de-assrted.
    } B;
} hw_mmdc_mpswdrdr2_t;
#endif

/*
 * constants & macros for entire MMDC_MPSWDRDR2 register
 */
#define HW_MMDC_MPSWDRDR2_ADDR      (REGS_MMDC_BASE + 0x8a0)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPSWDRDR2           (*(volatile hw_mmdc_mpswdrdr2_t *) HW_MMDC_MPSWDRDR2_ADDR)
#define HW_MMDC_MPSWDRDR2_RD()      (HW_MMDC_MPSWDRDR2.U)
#define HW_MMDC_MPSWDRDR2_WR(v)     (HW_MMDC_MPSWDRDR2.U = (v))
#define HW_MMDC_MPSWDRDR2_SET(v)    (HW_MMDC_MPSWDRDR2_WR(HW_MMDC_MPSWDRDR2_RD() |  (v)))
#define HW_MMDC_MPSWDRDR2_CLR(v)    (HW_MMDC_MPSWDRDR2_WR(HW_MMDC_MPSWDRDR2_RD() & ~(v)))
#define HW_MMDC_MPSWDRDR2_TOG(v)    (HW_MMDC_MPSWDRDR2_WR(HW_MMDC_MPSWDRDR2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPSWDRDR2 bitfields
 */

/* --- Register HW_MMDC_MPSWDRDR2, field DUM_RD2
 *
 * Dummy read data2. This field holds the third data that is read from
 * the DDR during SW dummy read access (i.e when SW_DUMMY_RD = 1). This
 * field is valid only when SW_DUMMY_RD is de-assrted.
 */

#define BP_MMDC_MPSWDRDR2_DUM_RD2      0
#define BM_MMDC_MPSWDRDR2_DUM_RD2      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPSWDRDR2_DUM_RD2(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPSWDRDR2_DUM_RD2)
#else
#define BF_MMDC_MPSWDRDR2_DUM_RD2(v)   (((v) << 0) & BM_MMDC_MPSWDRDR2_DUM_RD2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPSWDRDR2_DUM_RD2(v)   BF_CS1(MMDC_MPSWDRDR2, DUM_RD2, v)
#endif

/*!
 * @brief HW_MMDC_MPSWDRDR3 - MMDC PHY SW Dummy Read Data Register 3
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: DDR3_x64, LP2_2ch_x16,
 * LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DUM_RD3 : 32; //!< Dummy read data3. This field holds the forth data that is read from the DDR during SW dummy read access (i.e when SW_DUMMY_RD = 1). This field is valid only when SW_DUMMY_RD is de-assrted.
    } B;
} hw_mmdc_mpswdrdr3_t;
#endif

/*
 * constants & macros for entire MMDC_MPSWDRDR3 register
 */
#define HW_MMDC_MPSWDRDR3_ADDR      (REGS_MMDC_BASE + 0x8a4)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPSWDRDR3           (*(volatile hw_mmdc_mpswdrdr3_t *) HW_MMDC_MPSWDRDR3_ADDR)
#define HW_MMDC_MPSWDRDR3_RD()      (HW_MMDC_MPSWDRDR3.U)
#define HW_MMDC_MPSWDRDR3_WR(v)     (HW_MMDC_MPSWDRDR3.U = (v))
#define HW_MMDC_MPSWDRDR3_SET(v)    (HW_MMDC_MPSWDRDR3_WR(HW_MMDC_MPSWDRDR3_RD() |  (v)))
#define HW_MMDC_MPSWDRDR3_CLR(v)    (HW_MMDC_MPSWDRDR3_WR(HW_MMDC_MPSWDRDR3_RD() & ~(v)))
#define HW_MMDC_MPSWDRDR3_TOG(v)    (HW_MMDC_MPSWDRDR3_WR(HW_MMDC_MPSWDRDR3_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPSWDRDR3 bitfields
 */

/* --- Register HW_MMDC_MPSWDRDR3, field DUM_RD3
 *
 * Dummy read data3. This field holds the forth data that is read from
 * the DDR during SW dummy read access (i.e when SW_DUMMY_RD = 1). This
 * field is valid only when SW_DUMMY_RD is de-assrted.
 */

#define BP_MMDC_MPSWDRDR3_DUM_RD3      0
#define BM_MMDC_MPSWDRDR3_DUM_RD3      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPSWDRDR3_DUM_RD3(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPSWDRDR3_DUM_RD3)
#else
#define BF_MMDC_MPSWDRDR3_DUM_RD3(v)   (((v) << 0) & BM_MMDC_MPSWDRDR3_DUM_RD3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPSWDRDR3_DUM_RD3(v)   BF_CS1(MMDC_MPSWDRDR3, DUM_RD3, v)
#endif

/*!
 * @brief HW_MMDC_MPSWDRDR4 - MMDC PHY SW Dummy Read Data Register 4
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: DDR3_x64, LP2_2ch_x16,
 * LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DUM_RD4 : 32; //!< Dummy read data4. This field holds the fifth data (only in case of burst length 8 (BL =1 )) that is read from the DDR during SW dummy read access (i.e when SW_DUMMY_RD = 1). This field is valid only when SW_DUMMY_RD is de-assrted.
    } B;
} hw_mmdc_mpswdrdr4_t;
#endif

/*
 * constants & macros for entire MMDC_MPSWDRDR4 register
 */
#define HW_MMDC_MPSWDRDR4_ADDR      (REGS_MMDC_BASE + 0x8a8)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPSWDRDR4           (*(volatile hw_mmdc_mpswdrdr4_t *) HW_MMDC_MPSWDRDR4_ADDR)
#define HW_MMDC_MPSWDRDR4_RD()      (HW_MMDC_MPSWDRDR4.U)
#define HW_MMDC_MPSWDRDR4_WR(v)     (HW_MMDC_MPSWDRDR4.U = (v))
#define HW_MMDC_MPSWDRDR4_SET(v)    (HW_MMDC_MPSWDRDR4_WR(HW_MMDC_MPSWDRDR4_RD() |  (v)))
#define HW_MMDC_MPSWDRDR4_CLR(v)    (HW_MMDC_MPSWDRDR4_WR(HW_MMDC_MPSWDRDR4_RD() & ~(v)))
#define HW_MMDC_MPSWDRDR4_TOG(v)    (HW_MMDC_MPSWDRDR4_WR(HW_MMDC_MPSWDRDR4_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPSWDRDR4 bitfields
 */

/* --- Register HW_MMDC_MPSWDRDR4, field DUM_RD4
 *
 * Dummy read data4. This field holds the fifth data (only in case of
 * burst length 8 (BL =1 )) that is read from the DDR during SW dummy
 * read access (i.e when SW_DUMMY_RD = 1). This field is valid only
 * when SW_DUMMY_RD is de-assrted.
 */

#define BP_MMDC_MPSWDRDR4_DUM_RD4      0
#define BM_MMDC_MPSWDRDR4_DUM_RD4      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPSWDRDR4_DUM_RD4(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPSWDRDR4_DUM_RD4)
#else
#define BF_MMDC_MPSWDRDR4_DUM_RD4(v)   (((v) << 0) & BM_MMDC_MPSWDRDR4_DUM_RD4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPSWDRDR4_DUM_RD4(v)   BF_CS1(MMDC_MPSWDRDR4, DUM_RD4, v)
#endif

/*!
 * @brief HW_MMDC_MPSWDRDR5 - MMDC PHY SW Dummy Read Data Register 5
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: DDR3_x64, LP2_2ch_x16,
 * LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DUM_RD5 : 32; //!< Dummy read data5. This field holds the sixth data (only in case of burst length 8 (BL =1 )) that is read from the DDR during SW dummy read access (i.e when SW_DUMMY_RD = 1). This field is valid only when SW_DUMMY_RD is de-assrted.
    } B;
} hw_mmdc_mpswdrdr5_t;
#endif

/*
 * constants & macros for entire MMDC_MPSWDRDR5 register
 */
#define HW_MMDC_MPSWDRDR5_ADDR      (REGS_MMDC_BASE + 0x8ac)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPSWDRDR5           (*(volatile hw_mmdc_mpswdrdr5_t *) HW_MMDC_MPSWDRDR5_ADDR)
#define HW_MMDC_MPSWDRDR5_RD()      (HW_MMDC_MPSWDRDR5.U)
#define HW_MMDC_MPSWDRDR5_WR(v)     (HW_MMDC_MPSWDRDR5.U = (v))
#define HW_MMDC_MPSWDRDR5_SET(v)    (HW_MMDC_MPSWDRDR5_WR(HW_MMDC_MPSWDRDR5_RD() |  (v)))
#define HW_MMDC_MPSWDRDR5_CLR(v)    (HW_MMDC_MPSWDRDR5_WR(HW_MMDC_MPSWDRDR5_RD() & ~(v)))
#define HW_MMDC_MPSWDRDR5_TOG(v)    (HW_MMDC_MPSWDRDR5_WR(HW_MMDC_MPSWDRDR5_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPSWDRDR5 bitfields
 */

/* --- Register HW_MMDC_MPSWDRDR5, field DUM_RD5
 *
 * Dummy read data5. This field holds the sixth data (only in case of
 * burst length 8 (BL =1 )) that is read from the DDR during SW dummy
 * read access (i.e when SW_DUMMY_RD = 1). This field is valid only
 * when SW_DUMMY_RD is de-assrted.
 */

#define BP_MMDC_MPSWDRDR5_DUM_RD5      0
#define BM_MMDC_MPSWDRDR5_DUM_RD5      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPSWDRDR5_DUM_RD5(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPSWDRDR5_DUM_RD5)
#else
#define BF_MMDC_MPSWDRDR5_DUM_RD5(v)   (((v) << 0) & BM_MMDC_MPSWDRDR5_DUM_RD5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPSWDRDR5_DUM_RD5(v)   BF_CS1(MMDC_MPSWDRDR5, DUM_RD5, v)
#endif

/*!
 * @brief HW_MMDC_MPSWDRDR6 - MMDC PHY SW Dummy Read Data Register 6
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: DDR3_x64, LP2_2ch_x16,
 * LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DUM_RD6 : 32; //!< Dummy read data6. This field holds the seventh data (only in case of burst length 8 (BL =1 )) that is read from the DDR during SW dummy read access (i.e when SW_DUMMY_RD = 1). This field is valid only when SW_DUMMY_RD is de-assrted.
    } B;
} hw_mmdc_mpswdrdr6_t;
#endif

/*
 * constants & macros for entire MMDC_MPSWDRDR6 register
 */
#define HW_MMDC_MPSWDRDR6_ADDR      (REGS_MMDC_BASE + 0x8b0)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPSWDRDR6           (*(volatile hw_mmdc_mpswdrdr6_t *) HW_MMDC_MPSWDRDR6_ADDR)
#define HW_MMDC_MPSWDRDR6_RD()      (HW_MMDC_MPSWDRDR6.U)
#define HW_MMDC_MPSWDRDR6_WR(v)     (HW_MMDC_MPSWDRDR6.U = (v))
#define HW_MMDC_MPSWDRDR6_SET(v)    (HW_MMDC_MPSWDRDR6_WR(HW_MMDC_MPSWDRDR6_RD() |  (v)))
#define HW_MMDC_MPSWDRDR6_CLR(v)    (HW_MMDC_MPSWDRDR6_WR(HW_MMDC_MPSWDRDR6_RD() & ~(v)))
#define HW_MMDC_MPSWDRDR6_TOG(v)    (HW_MMDC_MPSWDRDR6_WR(HW_MMDC_MPSWDRDR6_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPSWDRDR6 bitfields
 */

/* --- Register HW_MMDC_MPSWDRDR6, field DUM_RD6
 *
 * Dummy read data6. This field holds the seventh data (only in case of
 * burst length 8 (BL =1 )) that is read from the DDR during SW dummy
 * read access (i.e when SW_DUMMY_RD = 1). This field is valid only
 * when SW_DUMMY_RD is de-assrted.
 */

#define BP_MMDC_MPSWDRDR6_DUM_RD6      0
#define BM_MMDC_MPSWDRDR6_DUM_RD6      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPSWDRDR6_DUM_RD6(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPSWDRDR6_DUM_RD6)
#else
#define BF_MMDC_MPSWDRDR6_DUM_RD6(v)   (((v) << 0) & BM_MMDC_MPSWDRDR6_DUM_RD6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPSWDRDR6_DUM_RD6(v)   BF_CS1(MMDC_MPSWDRDR6, DUM_RD6, v)
#endif

/*!
 * @brief HW_MMDC_MPSWDRDR7 - MMDC PHY SW Dummy Read Data Register 7
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: DDR3_x64, LP2_2ch_x16,
 * LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DUM_RD7 : 32; //!< Dummy read data7. This field holds the eigth data (only in case of burst length 8 (BL =1 )) that is read from the DDR during SW dummy read access (i.e when SW_DUMMY_RD = 1). This field is valid only when SW_DUMMY_RD is de-assrted.
    } B;
} hw_mmdc_mpswdrdr7_t;
#endif

/*
 * constants & macros for entire MMDC_MPSWDRDR7 register
 */
#define HW_MMDC_MPSWDRDR7_ADDR      (REGS_MMDC_BASE + 0x8b4)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPSWDRDR7           (*(volatile hw_mmdc_mpswdrdr7_t *) HW_MMDC_MPSWDRDR7_ADDR)
#define HW_MMDC_MPSWDRDR7_RD()      (HW_MMDC_MPSWDRDR7.U)
#define HW_MMDC_MPSWDRDR7_WR(v)     (HW_MMDC_MPSWDRDR7.U = (v))
#define HW_MMDC_MPSWDRDR7_SET(v)    (HW_MMDC_MPSWDRDR7_WR(HW_MMDC_MPSWDRDR7_RD() |  (v)))
#define HW_MMDC_MPSWDRDR7_CLR(v)    (HW_MMDC_MPSWDRDR7_WR(HW_MMDC_MPSWDRDR7_RD() & ~(v)))
#define HW_MMDC_MPSWDRDR7_TOG(v)    (HW_MMDC_MPSWDRDR7_WR(HW_MMDC_MPSWDRDR7_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPSWDRDR7 bitfields
 */

/* --- Register HW_MMDC_MPSWDRDR7, field DUM_RD7
 *
 * Dummy read data7. This field holds the eigth data (only in case of
 * burst length 8 (BL =1 )) that is read from the DDR during SW dummy
 * read access (i.e when SW_DUMMY_RD = 1). This field is valid only
 * when SW_DUMMY_RD is de-assrted.
 */

#define BP_MMDC_MPSWDRDR7_DUM_RD7      0
#define BM_MMDC_MPSWDRDR7_DUM_RD7      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPSWDRDR7_DUM_RD7(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPSWDRDR7_DUM_RD7)
#else
#define BF_MMDC_MPSWDRDR7_DUM_RD7(v)   (((v) << 0) & BM_MMDC_MPSWDRDR7_DUM_RD7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPSWDRDR7_DUM_RD7(v)   BF_CS1(MMDC_MPSWDRDR7, DUM_RD7, v)
#endif

/*!
 * @brief HW_MMDC_MPMUR0 - MMDC PHY Measure Unit Register
 *
 * Supported Mode Of Operations:  For Channel 0: All  For Channel 1: LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MU_BYP_VAL : 10; //!< Number of delay units for measurement bypass. This field is used in debug mode and holds the number of delay units that will be used by the delay-lines when MU_BYP_EN is asserted.
        unsigned MU_BYP_EN : 1; //!< Measure unit bypass enable. This field is used in debug mode and when it is asserted then the delay-lines will use the number of delay units that are indicated at MU_BYP_VAL, otherwise the delay-lines will use the number of delay units that was measured by the measurement unit and are indicated at MU_UNIT_DEL_NUM
        unsigned FRC_MSR : 1; //!< Force measuement on delay-lines. When this bit is asserted then a measurement process will be performed, where at the completion of the process the delay-lines will issue the desired delay. Upon completion of the measurement process the measure unit and the delay-lines will return to functional more. This bit is self cleared.  This bit should be used only during manual (SW) calibration and not while the DDR is functional (being accessed). After initial calibration is done the hardware performs periodic measurements to track any operating conditions changes. Hence, force measurements (FRC_MSR) should not be used. See for more information.  User should make sure that there is no active accesses to/from DDR before asserting this bit.
        unsigned RESERVED0 : 4; //!< Reserved
        unsigned MU_UNIT_DEL_NUM : 10; //!< Number of delay units measured per cycle. This field is used in debug mode and holds the number of delay units that were measured by the measure unit per DDR clock cycle. The delay-lines that are used in every calibration process use that number for generating the desired delay.
        unsigned RESERVED1 : 6; //!< Reserved
    } B;
} hw_mmdc_mpmur0_t;
#endif

/*
 * constants & macros for entire MMDC_MPMUR0 register
 */
#define HW_MMDC_MPMUR0_ADDR      (REGS_MMDC_BASE + 0x8b8)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPMUR0           (*(volatile hw_mmdc_mpmur0_t *) HW_MMDC_MPMUR0_ADDR)
#define HW_MMDC_MPMUR0_RD()      (HW_MMDC_MPMUR0.U)
#define HW_MMDC_MPMUR0_WR(v)     (HW_MMDC_MPMUR0.U = (v))
#define HW_MMDC_MPMUR0_SET(v)    (HW_MMDC_MPMUR0_WR(HW_MMDC_MPMUR0_RD() |  (v)))
#define HW_MMDC_MPMUR0_CLR(v)    (HW_MMDC_MPMUR0_WR(HW_MMDC_MPMUR0_RD() & ~(v)))
#define HW_MMDC_MPMUR0_TOG(v)    (HW_MMDC_MPMUR0_WR(HW_MMDC_MPMUR0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPMUR0 bitfields
 */

/* --- Register HW_MMDC_MPMUR0, field MU_BYP_VAL
 *
 * Number of delay units for measurement bypass. This field is used in
 * debug mode and holds the number of delay units that will be used by
 * the delay-lines when MU_BYP_EN is asserted.
 */

#define BP_MMDC_MPMUR0_MU_BYP_VAL      0
#define BM_MMDC_MPMUR0_MU_BYP_VAL      0x000003ff

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPMUR0_MU_BYP_VAL(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPMUR0_MU_BYP_VAL)
#else
#define BF_MMDC_MPMUR0_MU_BYP_VAL(v)   (((v) << 0) & BM_MMDC_MPMUR0_MU_BYP_VAL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPMUR0_MU_BYP_VAL(v)   BF_CS1(MMDC_MPMUR0, MU_BYP_VAL, v)
#endif

/* --- Register HW_MMDC_MPMUR0, field MU_BYP_EN
 *
 * Measure unit bypass enable. This field is used in debug mode and when
 * it is asserted then the delay-lines will use the number of delay
 * units that are indicated at MU_BYP_VAL, otherwise the delay-lines
 * will use the number of delay units that was measured by the
 * measurement unit and are indicated at MU_UNIT_DEL_NUM
 */

#define BP_MMDC_MPMUR0_MU_BYP_EN      10
#define BM_MMDC_MPMUR0_MU_BYP_EN      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPMUR0_MU_BYP_EN(v)   ((((reg32_t) v) << 10) & BM_MMDC_MPMUR0_MU_BYP_EN)
#else
#define BF_MMDC_MPMUR0_MU_BYP_EN(v)   (((v) << 10) & BM_MMDC_MPMUR0_MU_BYP_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPMUR0_MU_BYP_EN(v)   BF_CS1(MMDC_MPMUR0, MU_BYP_EN, v)
#endif

/* --- Register HW_MMDC_MPMUR0, field FRC_MSR
 *
 * Force measuement on delay-lines. When this bit is asserted then a
 * measurement process will be performed, where at the completion of
 * the process the delay-lines will issue the desired delay. Upon
 * completion of the measurement process the measure unit and the
 * delay-lines will return to functional more. This bit is self
 * cleared.  This bit should be used only during manual (SW) calibration and not while the DDR is
 * functional (being accessed).  After initial calibration is done the hardware performs periodic
 * measurements to track any operating conditions changes. Hence, force measurements (FRC_MSR)
 * should not be used. See for more information.  User should make sure that there is no active
 * accesses to/from DDR                                 before asserting this bit.
 */

#define BP_MMDC_MPMUR0_FRC_MSR      11
#define BM_MMDC_MPMUR0_FRC_MSR      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPMUR0_FRC_MSR(v)   ((((reg32_t) v) << 11) & BM_MMDC_MPMUR0_FRC_MSR)
#else
#define BF_MMDC_MPMUR0_FRC_MSR(v)   (((v) << 11) & BM_MMDC_MPMUR0_FRC_MSR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPMUR0_FRC_MSR(v)   BF_CS1(MMDC_MPMUR0, FRC_MSR, v)
#endif

/* --- Register HW_MMDC_MPMUR0, field MU_UNIT_DEL_NUM
 *
 * Number of delay units measured per cycle. This field is used in debug
 * mode and holds the number of delay units that were measured by the
 * measure unit per DDR clock cycle. The delay-lines that are used in
 * every calibration process use that number for generating the desired
 * delay.
 */

#define BP_MMDC_MPMUR0_MU_UNIT_DEL_NUM      16
#define BM_MMDC_MPMUR0_MU_UNIT_DEL_NUM      0x03ff0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPMUR0_MU_UNIT_DEL_NUM(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPMUR0_MU_UNIT_DEL_NUM)
#else
#define BF_MMDC_MPMUR0_MU_UNIT_DEL_NUM(v)   (((v) << 16) & BM_MMDC_MPMUR0_MU_UNIT_DEL_NUM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPMUR0_MU_UNIT_DEL_NUM(v)   BF_CS1(MMDC_MPMUR0, MU_UNIT_DEL_NUM, v)
#endif

/*!
 * @brief HW_MMDC_MPWRCADL - MMDC Write CA delay-line controller
 *
 * This register is used to add fine-tuning adjustment to the CA
 * (command/Address of LPDDR2 bus) relative to the DDR clock  Supported Mode Of Operations:  For
 * Channel 0:  LP2_2ch_x16, LP2_2ch_x32  For Channel 1:  LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WR_CA0_DEL : 2; //!< CA (Command/Address LPDDR2 bus) bit 0 delay fine tuning. This field holds the number of delay units that are added to CA (Command/Address bus) bit 0 relative to the clock.
        unsigned WR_CA1_DEL : 2; //!< CA (Command/Address LPDDR2 bus) bit 1 delay fine tuning. This field holds the number of delay units that are added to CA (Command/Address bus) bit 1 relative to the clock.
        unsigned WR_CA2_DEL : 2; //!< CA (Command/Address LPDDR2 bus) bit 2 delay fine tuning. This field holds the number of delay units that are added to CA (Command/Address bus) bit 2 relative to the clock.
        unsigned WR_CA3_DEL : 2; //!< CA (Command/Address LPDDR2 bus) bit 3 delay fine tuning. This field holds the number of delay units that are added to CA (Command/Address bus) bit 3 relative to the clock.
        unsigned WR_CA4_DEL : 2; //!< CA (Command/Address LPDDR2 bus) bit 4 delay fine tuning. This field holds the number of delay units that are added to CA (Command/Address bus) bit 4 relative to the clock.
        unsigned WR_CA5_DEL : 2; //!< CA (Command/Address LPDDR2 bus) bit 5 delay fine tuning. This field holds the number of delay units that are added to CA (Command/Address bus) bit 5 relative to the clock.
        unsigned WR_CA6_DEL : 2; //!< CA (Command/Address LPDDR2 bus) bit 6 delay fine tuning. This field holds the number of delay units that are added to CA (Command/Address bus) bit 6 relative to the clock.
        unsigned WR_CA7_DEL : 2; //!< CA (Command/Address LPDDR2 bus) bit 7 delay fine tuning. This field holds the number of delay units that are added to CA (Command/Address bus) bit 7 relative to the clock.
        unsigned WR_CA8_DEL : 2; //!< CA (Command/Address LPDDR2 bus) bit 8 delay fine tuning. This field holds the number of delay units that are added to CA (Command/Address bus) bit 8 relative to the clock.
        unsigned WR_CA9_DEL : 2; //!< CA (Command/Address LPDDR2 bus) bit 9 delay fine tuning. This field holds the number of delay units that are added to CA (Command/Address bus) bit 9 relative to the clock.
        unsigned RESERVED0 : 12; //!< Reserved
    } B;
} hw_mmdc_mpwrcadl_t;
#endif

/*
 * constants & macros for entire MMDC_MPWRCADL register
 */
#define HW_MMDC_MPWRCADL_ADDR      (REGS_MMDC_BASE + 0x8bc)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPWRCADL           (*(volatile hw_mmdc_mpwrcadl_t *) HW_MMDC_MPWRCADL_ADDR)
#define HW_MMDC_MPWRCADL_RD()      (HW_MMDC_MPWRCADL.U)
#define HW_MMDC_MPWRCADL_WR(v)     (HW_MMDC_MPWRCADL.U = (v))
#define HW_MMDC_MPWRCADL_SET(v)    (HW_MMDC_MPWRCADL_WR(HW_MMDC_MPWRCADL_RD() |  (v)))
#define HW_MMDC_MPWRCADL_CLR(v)    (HW_MMDC_MPWRCADL_WR(HW_MMDC_MPWRCADL_RD() & ~(v)))
#define HW_MMDC_MPWRCADL_TOG(v)    (HW_MMDC_MPWRCADL_WR(HW_MMDC_MPWRCADL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPWRCADL bitfields
 */

/* --- Register HW_MMDC_MPWRCADL, field WR_CA0_DEL
 *
 * CA (Command/Address LPDDR2 bus) bit 0 delay fine tuning. This field
 * holds the number of delay units that are added to CA
 * (Command/Address bus) bit 0 relative to the clock.
 */

#define BP_MMDC_MPWRCADL_WR_CA0_DEL      0
#define BM_MMDC_MPWRCADL_WR_CA0_DEL      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRCADL_WR_CA0_DEL(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPWRCADL_WR_CA0_DEL)
#else
#define BF_MMDC_MPWRCADL_WR_CA0_DEL(v)   (((v) << 0) & BM_MMDC_MPWRCADL_WR_CA0_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRCADL_WR_CA0_DEL(v)   BF_CS1(MMDC_MPWRCADL, WR_CA0_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRCADL, field WR_CA1_DEL
 *
 * CA (Command/Address LPDDR2 bus) bit 1 delay fine tuning. This field
 * holds the number of delay units that are added to CA
 * (Command/Address bus) bit 1 relative to the clock.
 */

#define BP_MMDC_MPWRCADL_WR_CA1_DEL      2
#define BM_MMDC_MPWRCADL_WR_CA1_DEL      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRCADL_WR_CA1_DEL(v)   ((((reg32_t) v) << 2) & BM_MMDC_MPWRCADL_WR_CA1_DEL)
#else
#define BF_MMDC_MPWRCADL_WR_CA1_DEL(v)   (((v) << 2) & BM_MMDC_MPWRCADL_WR_CA1_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRCADL_WR_CA1_DEL(v)   BF_CS1(MMDC_MPWRCADL, WR_CA1_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRCADL, field WR_CA2_DEL
 *
 * CA (Command/Address LPDDR2 bus) bit 2 delay fine tuning. This field
 * holds the number of delay units that are added to CA
 * (Command/Address bus) bit 2 relative to the clock.
 */

#define BP_MMDC_MPWRCADL_WR_CA2_DEL      4
#define BM_MMDC_MPWRCADL_WR_CA2_DEL      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRCADL_WR_CA2_DEL(v)   ((((reg32_t) v) << 4) & BM_MMDC_MPWRCADL_WR_CA2_DEL)
#else
#define BF_MMDC_MPWRCADL_WR_CA2_DEL(v)   (((v) << 4) & BM_MMDC_MPWRCADL_WR_CA2_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRCADL_WR_CA2_DEL(v)   BF_CS1(MMDC_MPWRCADL, WR_CA2_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRCADL, field WR_CA3_DEL
 *
 * CA (Command/Address LPDDR2 bus) bit 3 delay fine tuning. This field
 * holds the number of delay units that are added to CA
 * (Command/Address bus) bit 3 relative to the clock.
 */

#define BP_MMDC_MPWRCADL_WR_CA3_DEL      6
#define BM_MMDC_MPWRCADL_WR_CA3_DEL      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRCADL_WR_CA3_DEL(v)   ((((reg32_t) v) << 6) & BM_MMDC_MPWRCADL_WR_CA3_DEL)
#else
#define BF_MMDC_MPWRCADL_WR_CA3_DEL(v)   (((v) << 6) & BM_MMDC_MPWRCADL_WR_CA3_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRCADL_WR_CA3_DEL(v)   BF_CS1(MMDC_MPWRCADL, WR_CA3_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRCADL, field WR_CA4_DEL
 *
 * CA (Command/Address LPDDR2 bus) bit 4 delay fine tuning. This field
 * holds the number of delay units that are added to CA
 * (Command/Address bus) bit 4 relative to the clock.
 */

#define BP_MMDC_MPWRCADL_WR_CA4_DEL      8
#define BM_MMDC_MPWRCADL_WR_CA4_DEL      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRCADL_WR_CA4_DEL(v)   ((((reg32_t) v) << 8) & BM_MMDC_MPWRCADL_WR_CA4_DEL)
#else
#define BF_MMDC_MPWRCADL_WR_CA4_DEL(v)   (((v) << 8) & BM_MMDC_MPWRCADL_WR_CA4_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRCADL_WR_CA4_DEL(v)   BF_CS1(MMDC_MPWRCADL, WR_CA4_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRCADL, field WR_CA5_DEL
 *
 * CA (Command/Address LPDDR2 bus) bit 5 delay fine tuning. This field
 * holds the number of delay units that are added to CA
 * (Command/Address bus) bit 5 relative to the clock.
 */

#define BP_MMDC_MPWRCADL_WR_CA5_DEL      10
#define BM_MMDC_MPWRCADL_WR_CA5_DEL      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRCADL_WR_CA5_DEL(v)   ((((reg32_t) v) << 10) & BM_MMDC_MPWRCADL_WR_CA5_DEL)
#else
#define BF_MMDC_MPWRCADL_WR_CA5_DEL(v)   (((v) << 10) & BM_MMDC_MPWRCADL_WR_CA5_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRCADL_WR_CA5_DEL(v)   BF_CS1(MMDC_MPWRCADL, WR_CA5_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRCADL, field WR_CA6_DEL
 *
 * CA (Command/Address LPDDR2 bus) bit 6 delay fine tuning. This field
 * holds the number of delay units that are added to CA
 * (Command/Address bus) bit 6 relative to the clock.
 */

#define BP_MMDC_MPWRCADL_WR_CA6_DEL      12
#define BM_MMDC_MPWRCADL_WR_CA6_DEL      0x00003000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRCADL_WR_CA6_DEL(v)   ((((reg32_t) v) << 12) & BM_MMDC_MPWRCADL_WR_CA6_DEL)
#else
#define BF_MMDC_MPWRCADL_WR_CA6_DEL(v)   (((v) << 12) & BM_MMDC_MPWRCADL_WR_CA6_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRCADL_WR_CA6_DEL(v)   BF_CS1(MMDC_MPWRCADL, WR_CA6_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRCADL, field WR_CA7_DEL
 *
 * CA (Command/Address LPDDR2 bus) bit 7 delay fine tuning. This field
 * holds the number of delay units that are added to CA
 * (Command/Address bus) bit 7 relative to the clock.
 */

#define BP_MMDC_MPWRCADL_WR_CA7_DEL      14
#define BM_MMDC_MPWRCADL_WR_CA7_DEL      0x0000c000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRCADL_WR_CA7_DEL(v)   ((((reg32_t) v) << 14) & BM_MMDC_MPWRCADL_WR_CA7_DEL)
#else
#define BF_MMDC_MPWRCADL_WR_CA7_DEL(v)   (((v) << 14) & BM_MMDC_MPWRCADL_WR_CA7_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRCADL_WR_CA7_DEL(v)   BF_CS1(MMDC_MPWRCADL, WR_CA7_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRCADL, field WR_CA8_DEL
 *
 * CA (Command/Address LPDDR2 bus) bit 8 delay fine tuning. This field
 * holds the number of delay units that are added to CA
 * (Command/Address bus) bit 8 relative to the clock.
 */

#define BP_MMDC_MPWRCADL_WR_CA8_DEL      16
#define BM_MMDC_MPWRCADL_WR_CA8_DEL      0x00030000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRCADL_WR_CA8_DEL(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPWRCADL_WR_CA8_DEL)
#else
#define BF_MMDC_MPWRCADL_WR_CA8_DEL(v)   (((v) << 16) & BM_MMDC_MPWRCADL_WR_CA8_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRCADL_WR_CA8_DEL(v)   BF_CS1(MMDC_MPWRCADL, WR_CA8_DEL, v)
#endif

/* --- Register HW_MMDC_MPWRCADL, field WR_CA9_DEL
 *
 * CA (Command/Address LPDDR2 bus) bit 9 delay fine tuning. This field
 * holds the number of delay units that are added to CA
 * (Command/Address bus) bit 9 relative to the clock.
 */

#define BP_MMDC_MPWRCADL_WR_CA9_DEL      18
#define BM_MMDC_MPWRCADL_WR_CA9_DEL      0x000c0000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPWRCADL_WR_CA9_DEL(v)   ((((reg32_t) v) << 18) & BM_MMDC_MPWRCADL_WR_CA9_DEL)
#else
#define BF_MMDC_MPWRCADL_WR_CA9_DEL(v)   (((v) << 18) & BM_MMDC_MPWRCADL_WR_CA9_DEL)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPWRCADL_WR_CA9_DEL(v)   BF_CS1(MMDC_MPWRCADL, WR_CA9_DEL, v)
#endif

/*!
 * @brief HW_MMDC_MPDCCR - MMDC Duty Cycle Control Register
 *
 * This register is used to control the duty cycle of the DQS and the
 * primary clock (CK0) . Programming of that register is permitted by
 * entering the DDR device into self-refresh mode through LPMD/DVFS
 * mechanism  Supported Mode Of Operations:  For Channel 0: All  For Channel 1: DDR3_x64,
 * LP2_2ch_x16, LP2_2ch_x32
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WR_DQS0_FT_DCC : 3; //!< Write DQS duty cycle fine tuning control of Byte0. This field controls the duty cycle of write DQS of Byte0  Note all the other options are not allowed
        unsigned WR_DQS1_FT_DCC : 3; //!< Write DQS duty cycle fine tuning control of Byte1. This field controls the duty cycle of write DQS of Byte1  Note all the other options are not allowed
        unsigned WR_DQS2_FT_DCC : 3; //!< Write DQS duty cycle fine tuning control of Byte1. This field controls the duty cycle of write DQS of Byte1  Note all the other options are not allowed
        unsigned WR_DQS3_FT_DCC : 3; //!< Write DQS duty cycle fine tuning control of Byte0. This field controls the duty cycle of write DQS of Byte0  Note all the other options are not allowed
        unsigned CK_FT0_DCC : 3; //!< Primary duty cycle fine tuning control of DDR clock. This field controls the duty cycle of the DDR clock  Note all the other options are not allowed
        unsigned RESERVED0 : 1; //!< Reserved
        unsigned CK_FT1_DCC : 3; //!< Secondary duty cycle fine tuning control of DDR clock. This field controls the duty cycle of the DDR clock and is cascaded to CK_FT0_DCC  Note all the other options are not allowed
        unsigned RD_DQS0_FT_DCC : 3; //!< Read DQS duty cycle fine tuning control of Byte0. This field controls the duty cycle of read DQS of Byte0  Note all the other options are not allowed
        unsigned RD_DQS1_FT_DCC : 3; //!< Read DQS duty cycle fine tuning control of Byte1. This field controls the duty cycle of read DQS of Byte1  Note all the other options are not allowed
        unsigned RD_DQS2_FT_DCC : 3; //!< Read DQS duty cycle fine tuning control of Byte2. This field controls the duty cycle of read DQS of Byte2  Note all the other options are not allowed
        unsigned RD_DQS3_FT_DCC : 3; //!< Read DQS duty cycle fine tuning control of Byte3. This field controls the duty cycle of read DQS of Byte3  Note all the other options are not allowed
        unsigned RESERVED1 : 1; //!< reserved
    } B;
} hw_mmdc_mpdccr_t;
#endif

/*
 * constants & macros for entire MMDC_MPDCCR register
 */
#define HW_MMDC_MPDCCR_ADDR      (REGS_MMDC_BASE + 0x8c0)

#ifndef __LANGUAGE_ASM__
#define HW_MMDC_MPDCCR           (*(volatile hw_mmdc_mpdccr_t *) HW_MMDC_MPDCCR_ADDR)
#define HW_MMDC_MPDCCR_RD()      (HW_MMDC_MPDCCR.U)
#define HW_MMDC_MPDCCR_WR(v)     (HW_MMDC_MPDCCR.U = (v))
#define HW_MMDC_MPDCCR_SET(v)    (HW_MMDC_MPDCCR_WR(HW_MMDC_MPDCCR_RD() |  (v)))
#define HW_MMDC_MPDCCR_CLR(v)    (HW_MMDC_MPDCCR_WR(HW_MMDC_MPDCCR_RD() & ~(v)))
#define HW_MMDC_MPDCCR_TOG(v)    (HW_MMDC_MPDCCR_WR(HW_MMDC_MPDCCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual MMDC_MPDCCR bitfields
 */

/* --- Register HW_MMDC_MPDCCR, field WR_DQS0_FT_DCC
 *
 * Write DQS duty cycle fine tuning control of Byte0. This field
 * controls the duty cycle of write DQS of Byte0  Note all the other options are not allowed
 */

#define BP_MMDC_MPDCCR_WR_DQS0_FT_DCC      0
#define BM_MMDC_MPDCCR_WR_DQS0_FT_DCC      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDCCR_WR_DQS0_FT_DCC(v)   ((((reg32_t) v) << 0) & BM_MMDC_MPDCCR_WR_DQS0_FT_DCC)
#else
#define BF_MMDC_MPDCCR_WR_DQS0_FT_DCC(v)   (((v) << 0) & BM_MMDC_MPDCCR_WR_DQS0_FT_DCC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDCCR_WR_DQS0_FT_DCC(v)   BF_CS1(MMDC_MPDCCR, WR_DQS0_FT_DCC, v)
#endif

/* --- Register HW_MMDC_MPDCCR, field WR_DQS1_FT_DCC
 *
 * Write DQS duty cycle fine tuning control of Byte1. This field
 * controls the duty cycle of write DQS of Byte1  Note all the other options are not allowed
 */

#define BP_MMDC_MPDCCR_WR_DQS1_FT_DCC      3
#define BM_MMDC_MPDCCR_WR_DQS1_FT_DCC      0x00000038

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDCCR_WR_DQS1_FT_DCC(v)   ((((reg32_t) v) << 3) & BM_MMDC_MPDCCR_WR_DQS1_FT_DCC)
#else
#define BF_MMDC_MPDCCR_WR_DQS1_FT_DCC(v)   (((v) << 3) & BM_MMDC_MPDCCR_WR_DQS1_FT_DCC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDCCR_WR_DQS1_FT_DCC(v)   BF_CS1(MMDC_MPDCCR, WR_DQS1_FT_DCC, v)
#endif

/* --- Register HW_MMDC_MPDCCR, field WR_DQS2_FT_DCC
 *
 * Write DQS duty cycle fine tuning control of Byte1. This field
 * controls the duty cycle of write DQS of Byte1  Note all the other options are not allowed
 */

#define BP_MMDC_MPDCCR_WR_DQS2_FT_DCC      6
#define BM_MMDC_MPDCCR_WR_DQS2_FT_DCC      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDCCR_WR_DQS2_FT_DCC(v)   ((((reg32_t) v) << 6) & BM_MMDC_MPDCCR_WR_DQS2_FT_DCC)
#else
#define BF_MMDC_MPDCCR_WR_DQS2_FT_DCC(v)   (((v) << 6) & BM_MMDC_MPDCCR_WR_DQS2_FT_DCC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDCCR_WR_DQS2_FT_DCC(v)   BF_CS1(MMDC_MPDCCR, WR_DQS2_FT_DCC, v)
#endif

/* --- Register HW_MMDC_MPDCCR, field WR_DQS3_FT_DCC
 *
 * Write DQS duty cycle fine tuning control of Byte0. This field
 * controls the duty cycle of write DQS of Byte0  Note all the other options are not allowed
 */

#define BP_MMDC_MPDCCR_WR_DQS3_FT_DCC      9
#define BM_MMDC_MPDCCR_WR_DQS3_FT_DCC      0x00000e00

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDCCR_WR_DQS3_FT_DCC(v)   ((((reg32_t) v) << 9) & BM_MMDC_MPDCCR_WR_DQS3_FT_DCC)
#else
#define BF_MMDC_MPDCCR_WR_DQS3_FT_DCC(v)   (((v) << 9) & BM_MMDC_MPDCCR_WR_DQS3_FT_DCC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDCCR_WR_DQS3_FT_DCC(v)   BF_CS1(MMDC_MPDCCR, WR_DQS3_FT_DCC, v)
#endif

/* --- Register HW_MMDC_MPDCCR, field CK_FT0_DCC
 *
 * Primary duty cycle fine tuning control of DDR clock. This field
 * controls the duty cycle of the DDR clock  Note all the other options are not allowed
 */

#define BP_MMDC_MPDCCR_CK_FT0_DCC      12
#define BM_MMDC_MPDCCR_CK_FT0_DCC      0x00007000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDCCR_CK_FT0_DCC(v)   ((((reg32_t) v) << 12) & BM_MMDC_MPDCCR_CK_FT0_DCC)
#else
#define BF_MMDC_MPDCCR_CK_FT0_DCC(v)   (((v) << 12) & BM_MMDC_MPDCCR_CK_FT0_DCC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDCCR_CK_FT0_DCC(v)   BF_CS1(MMDC_MPDCCR, CK_FT0_DCC, v)
#endif

/* --- Register HW_MMDC_MPDCCR, field CK_FT1_DCC
 *
 * Secondary duty cycle fine tuning control of DDR clock. This field
 * controls the duty cycle of the DDR clock and is cascaded to
 * CK_FT0_DCC  Note all the other options are not allowed
 */

#define BP_MMDC_MPDCCR_CK_FT1_DCC      16
#define BM_MMDC_MPDCCR_CK_FT1_DCC      0x00070000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDCCR_CK_FT1_DCC(v)   ((((reg32_t) v) << 16) & BM_MMDC_MPDCCR_CK_FT1_DCC)
#else
#define BF_MMDC_MPDCCR_CK_FT1_DCC(v)   (((v) << 16) & BM_MMDC_MPDCCR_CK_FT1_DCC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDCCR_CK_FT1_DCC(v)   BF_CS1(MMDC_MPDCCR, CK_FT1_DCC, v)
#endif

/* --- Register HW_MMDC_MPDCCR, field RD_DQS0_FT_DCC
 *
 * Read DQS duty cycle fine tuning control of Byte0. This field controls
 * the duty cycle of read DQS of Byte0  Note all the other options are not allowed
 */

#define BP_MMDC_MPDCCR_RD_DQS0_FT_DCC      19
#define BM_MMDC_MPDCCR_RD_DQS0_FT_DCC      0x00380000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDCCR_RD_DQS0_FT_DCC(v)   ((((reg32_t) v) << 19) & BM_MMDC_MPDCCR_RD_DQS0_FT_DCC)
#else
#define BF_MMDC_MPDCCR_RD_DQS0_FT_DCC(v)   (((v) << 19) & BM_MMDC_MPDCCR_RD_DQS0_FT_DCC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDCCR_RD_DQS0_FT_DCC(v)   BF_CS1(MMDC_MPDCCR, RD_DQS0_FT_DCC, v)
#endif

/* --- Register HW_MMDC_MPDCCR, field RD_DQS1_FT_DCC
 *
 * Read DQS duty cycle fine tuning control of Byte1. This field controls
 * the duty cycle of read DQS of Byte1  Note all the other options are not allowed
 */

#define BP_MMDC_MPDCCR_RD_DQS1_FT_DCC      22
#define BM_MMDC_MPDCCR_RD_DQS1_FT_DCC      0x01c00000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDCCR_RD_DQS1_FT_DCC(v)   ((((reg32_t) v) << 22) & BM_MMDC_MPDCCR_RD_DQS1_FT_DCC)
#else
#define BF_MMDC_MPDCCR_RD_DQS1_FT_DCC(v)   (((v) << 22) & BM_MMDC_MPDCCR_RD_DQS1_FT_DCC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDCCR_RD_DQS1_FT_DCC(v)   BF_CS1(MMDC_MPDCCR, RD_DQS1_FT_DCC, v)
#endif

/* --- Register HW_MMDC_MPDCCR, field RD_DQS2_FT_DCC
 *
 * Read DQS duty cycle fine tuning control of Byte2. This field controls
 * the duty cycle of read DQS of Byte2  Note all the other options are not allowed
 */

#define BP_MMDC_MPDCCR_RD_DQS2_FT_DCC      25
#define BM_MMDC_MPDCCR_RD_DQS2_FT_DCC      0x0e000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDCCR_RD_DQS2_FT_DCC(v)   ((((reg32_t) v) << 25) & BM_MMDC_MPDCCR_RD_DQS2_FT_DCC)
#else
#define BF_MMDC_MPDCCR_RD_DQS2_FT_DCC(v)   (((v) << 25) & BM_MMDC_MPDCCR_RD_DQS2_FT_DCC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDCCR_RD_DQS2_FT_DCC(v)   BF_CS1(MMDC_MPDCCR, RD_DQS2_FT_DCC, v)
#endif

/* --- Register HW_MMDC_MPDCCR, field RD_DQS3_FT_DCC
 *
 * Read DQS duty cycle fine tuning control of Byte3. This field controls
 * the duty cycle of read DQS of Byte3  Note all the other options are not allowed
 */

#define BP_MMDC_MPDCCR_RD_DQS3_FT_DCC      28
#define BM_MMDC_MPDCCR_RD_DQS3_FT_DCC      0x70000000

#ifndef __LANGUAGE_ASM__
#define BF_MMDC_MPDCCR_RD_DQS3_FT_DCC(v)   ((((reg32_t) v) << 28) & BM_MMDC_MPDCCR_RD_DQS3_FT_DCC)
#else
#define BF_MMDC_MPDCCR_RD_DQS3_FT_DCC(v)   (((v) << 28) & BM_MMDC_MPDCCR_RD_DQS3_FT_DCC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_MMDC_MPDCCR_RD_DQS3_FT_DCC(v)   BF_CS1(MMDC_MPDCCR, RD_DQS3_FT_DCC, v)
#endif



/*!
 * @brief All MMDC module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_mmdc_mdctl_t MDCTL; //!< MMDC Core Control Register
    volatile hw_mmdc_mdpdc_t MDPDC; //!< MMDC Core Power Down Control Register
    volatile hw_mmdc_mdotc_t MDOTC; //!< MMDC Core ODT Timing Control Register
    volatile hw_mmdc_mdcfg0_t MDCFG0; //!< MMDC Core Timing Configuration Register 0
    volatile hw_mmdc_mdcfg1_t MDCFG1; //!< MMDC Core Timing Configuration Register 1
    volatile hw_mmdc_mdcfg2_t MDCFG2; //!< MMDC Core Timing Configuration Register 2
    volatile hw_mmdc_mdmisc_t MDMISC; //!< MMDC Core Miscellaneous Register
    volatile hw_mmdc_mdscr_t MDSCR; //!< MMDC Core Special Command Register
    volatile hw_mmdc_mdref_t MDREF; //!< MMDC Core Refresh Control Register
    reg32_t _reserved0[2];
    volatile hw_mmdc_mdrwd_t MDRWD; //!< MMDC Core Read/Write Command Delay Register
    volatile hw_mmdc_mdor_t MDOR; //!< MMDC Core Out of Reset Delays Register
    volatile hw_mmdc_mdmrr_t MDMRR; //!< MMDC Core MRR Data Register
    volatile hw_mmdc_mdcfg3lp_t MDCFG3LP; //!< MMDC Core Timing Configuration Register 3
    volatile hw_mmdc_mdmr4_t MDMR4; //!< MMDC Core MR4 Derating Register
    volatile hw_mmdc_mdasp_t MDASP; //!< MMDC Core Address Space Partition Register
    reg32_t _reserved1[239];
    volatile hw_mmdc_maarcr_t MAARCR; //!< MMDC Core AXI Reordering Control Regsiter
    volatile hw_mmdc_mapsr_t MAPSR; //!< MMDC Core Power Saving Control and Status                        Register
    volatile hw_mmdc_maexidr0_t MAEXIDR0; //!< MMDC Core Exclusive ID Monitor Register0
    volatile hw_mmdc_maexidr1_t MAEXIDR1; //!< MMDC Core Exclusive ID Monitor Register1
    volatile hw_mmdc_madpcr0_t MADPCR0; //!< MMDC Core Debug and Profiling Control Register                        0
    volatile hw_mmdc_madpcr1_t MADPCR1; //!< MMDC Core Debug and Profiling Control Register                        1
    volatile hw_mmdc_madpsr0_t MADPSR0; //!< MMDC Core Debug and Profiling Status Register                        0
    volatile hw_mmdc_madpsr1_t MADPSR1; //!< MMDC Core Debug and Profiling Status Register                        1
    volatile hw_mmdc_madpsr2_t MADPSR2; //!< MMDC Core Debug and Profiling Status Register                        2
    volatile hw_mmdc_madpsr3_t MADPSR3; //!< MMDC Core Debug and Profiling Status Register                        3
    volatile hw_mmdc_madpsr4_t MADPSR4; //!< MMDC Core Debug and Profiling Status Register                        4
    volatile hw_mmdc_madpsr5_t MADPSR5; //!< MMDC Core Debug and Profiling Status Register                        5
    volatile hw_mmdc_masbs0_t MASBS0; //!< MMDC Core Step By Step Address Register
    volatile hw_mmdc_masbs1_t MASBS1; //!< MMDC Core Step By Step Address Attributes                        Register
    reg32_t _reserved2[2];
    volatile hw_mmdc_magenp_t MAGENP; //!< MMDC Core General Purpose Register
    reg32_t _reserved3[239];
    volatile hw_mmdc_mpzqhwctrl_t MPZQHWCTRL; //!< MMDC PHY ZQ HW control register
    volatile hw_mmdc_mpzqswctrl_t MPZQSWCTRL; //!< MMDC PHY ZQ SW control register
    volatile hw_mmdc_mpwlgcr_t MPWLGCR; //!< MMDC PHY Write Leveling Configuration and Error Status                        Register
    volatile hw_mmdc_mpwldectrl0_t MPWLDECTRL0; //!< MMDC PHY Write Leveling Delay Control Register                        0
    volatile hw_mmdc_mpwldectrl1_t MPWLDECTRL1; //!< MMDC PHY Write Leveling Delay Control Register                        1
    volatile hw_mmdc_mpwldlst_t MPWLDLST; //!< MMDC PHY Write Leveling delay-line Status                        Register
    volatile hw_mmdc_mpodtctrl_t MPODTCTRL; //!< MMDC PHY ODT control register
    volatile hw_mmdc_mprddqby0dl_t MPRDDQBY0DL; //!< MMDC PHY Read DQ Byte0 Delay Register
    volatile hw_mmdc_mprddqby1dl_t MPRDDQBY1DL; //!< MMDC PHY Read DQ Byte1 Delay Register
    volatile hw_mmdc_mprddqby2dl_t MPRDDQBY2DL; //!< MMDC PHY Read DQ Byte2 Delay Register
    volatile hw_mmdc_mprddqby3dl_t MPRDDQBY3DL; //!< MMDC PHY Read DQ Byte3 Delay Register
    volatile hw_mmdc_mpwrdqby0dl_t MPWRDQBY0DL; //!< MMDC PHY Write DQ Byte0 Delay Register
    volatile hw_mmdc_mpwrdqby1dl_t MPWRDQBY1DL; //!< MMDC PHY Write DQ Byte1 Delay Register
    volatile hw_mmdc_mpwrdqby2dl_t MPWRDQBY2DL; //!< MMDC PHY Write DQ Byte2 Delay Register
    volatile hw_mmdc_mpwrdqby3dl_t MPWRDQBY3DL; //!< MMDC PHY Write DQ Byte3 Delay Register
    volatile hw_mmdc_mpdgctrl0_t MPDGCTRL0; //!< MMDC PHY Read DQS Gating Control Register 0
    volatile hw_mmdc_mpdgctrl1_t MPDGCTRL1; //!< MMDC PHY Read DQS Gating Control Register 1
    volatile hw_mmdc_mpdgdlst0_t MPDGDLST0; //!< MMDC PHY Read DQS Gating delay-line Status                        Register
    volatile hw_mmdc_mprddlctl_t MPRDDLCTL; //!< MMDC PHY Read delay-lines Configuration                        Register
    volatile hw_mmdc_mprddlst_t MPRDDLST; //!< MMDC PHY Read delay-lines Status Register
    volatile hw_mmdc_mpwrdlctl_t MPWRDLCTL; //!< MMDC PHY Write delay-lines Configuration                        Register
    volatile hw_mmdc_mpwrdlst_t MPWRDLST; //!< MMDC PHY Write delay-lines Status Register
    volatile hw_mmdc_mpsdctrl_t MPSDCTRL; //!< MMDC PHY CK Control Register
    volatile hw_mmdc_mpzqlp2ctl_t MPZQLP2CTL; //!< MMDC ZQ LPDDR2 HW Control Register
    volatile hw_mmdc_mprddlhwctl_t MPRDDLHWCTL; //!< MMDC PHY Read Delay HW Calibration Control                        Register
    volatile hw_mmdc_mpwrdlhwctl_t MPWRDLHWCTL; //!< MMDC PHY Write Delay HW Calibration Control                        Register
    volatile hw_mmdc_mprddlhwst0_t MPRDDLHWST0; //!< MMDC PHY Read Delay HW Calibration Status Register                        0
    volatile hw_mmdc_mprddlhwst1_t MPRDDLHWST1; //!< MMDC PHY Read Delay HW Calibration Status Register                        1
    volatile hw_mmdc_mpwrdlhwst0_t MPWRDLHWST0; //!< MMDC PHY Write Delay HW Calibration Status Register                        0
    volatile hw_mmdc_mpwrdlhwst1_t MPWRDLHWST1; //!< MMDC PHY Write Delay HW Calibration Status Register                        1
    volatile hw_mmdc_mpwlhwerr_t MPWLHWERR; //!< MMDC PHY Write Leveling HW Error Register
    volatile hw_mmdc_mpdghwst0_t MPDGHWST0; //!< MMDC PHY Read DQS Gating HW Status Register                        0
    volatile hw_mmdc_mpdghwst1_t MPDGHWST1; //!< MMDC PHY Read DQS Gating HW Status Register                        1
    volatile hw_mmdc_mpdghwst2_t MPDGHWST2; //!< MMDC PHY Read DQS Gating HW Status Register                        2
    volatile hw_mmdc_mpdghwst3_t MPDGHWST3; //!< MMDC PHY Read DQS Gating HW Status Register                        3
    volatile hw_mmdc_mppdcmpr1_t MPPDCMPR1; //!< MMDC PHY Pre-defined Compare Register 1
    volatile hw_mmdc_mppdcmpr2_t MPPDCMPR2; //!< MMDC PHY Pre-defined Compare and CA delay-line Configuration                        Register
    volatile hw_mmdc_mpswdar0_t MPSWDAR0; //!< MMDC PHY SW Dummy Access Register
    volatile hw_mmdc_mpswdrdr0_t MPSWDRDR0; //!< MMDC PHY SW Dummy Read Data Register 0
    volatile hw_mmdc_mpswdrdr1_t MPSWDRDR1; //!< MMDC PHY SW Dummy Read Data Register 1
    volatile hw_mmdc_mpswdrdr2_t MPSWDRDR2; //!< MMDC PHY SW Dummy Read Data Register 2
    volatile hw_mmdc_mpswdrdr3_t MPSWDRDR3; //!< MMDC PHY SW Dummy Read Data Register 3
    volatile hw_mmdc_mpswdrdr4_t MPSWDRDR4; //!< MMDC PHY SW Dummy Read Data Register 4
    volatile hw_mmdc_mpswdrdr5_t MPSWDRDR5; //!< MMDC PHY SW Dummy Read Data Register 5
    volatile hw_mmdc_mpswdrdr6_t MPSWDRDR6; //!< MMDC PHY SW Dummy Read Data Register 6
    volatile hw_mmdc_mpswdrdr7_t MPSWDRDR7; //!< MMDC PHY SW Dummy Read Data Register 7
    volatile hw_mmdc_mpmur0_t MPMUR0; //!< MMDC PHY Measure Unit Register
    volatile hw_mmdc_mpwrcadl_t MPWRCADL; //!< MMDC Write CA delay-line controller
    volatile hw_mmdc_mpdccr_t MPDCCR; //!< MMDC Duty Cycle Control Register
} hw_mmdc_t
#endif

//! @brief Macro to access all MMDC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_MMDC(0)</code>.
#define HW_MMDC     (*(volatile hw_mmdc_t *) REGS_MMDC_BASE)


#endif // _MMDC_H
