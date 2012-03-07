/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _DCIC_H
#define _DCIC_H

#include "regs.h"

/*
 * i.MX6SDL DCIC registers defined in this header file.
 *
 * - HW_DCIC_DCICC - DCIC Control Register
 * - HW_DCIC_DCICIC - DCIC Interrupt Control Register
 * - HW_DCIC_DCICS - DCIC Status Register
 * - HW_DCIC_DCICRC - DCIC ROI Config Register m
 * - HW_DCIC_DCICRS - DCIC ROI Size Register m
 * - HW_DCIC_DCICRRS - DCIC ROI Reference Signature Register m
 * - HW_DCIC_DCICRCS - DCIC ROI Calculated Signature m
 *
 * hw_dcic_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_DCIC_BASE
#define REGS_DCIC1_BASE (0x020e4000) //!< Base address for DCIC instance number 1.
#define REGS_DCIC2_BASE (0x020e8000) //!< Base address for DCIC instance number 2.

//! @brief Get the base address of DCIC by instance number.
//! @param x DCIC instance number, from 0 through 2.
#define REGS_DCIC_BASE(x) ( x == 1 ? REGS_DCIC1_BASE : x == 2 ? REGS_DCIC2_BASE : 0xffff0000)
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCIC_DCICC - DCIC Control Register (RW)
 *
 * Reset value: 0x00000070
 *

 */
typedef union _hw_dcic_dcicc
{
    reg32_t U;
    struct _hw_dcic_dcicc_bitfields
    {
        unsigned IC_EN : 1; //!< [0] Integrity Check enable. Main enable switch.
        unsigned RESERVED0 : 3; //!< [3:1] Reserved
        unsigned DE_POL : 1; //!< [4] DATA_EN_IN signal polarity.
        unsigned HSYNC_POL : 1; //!< [5] HSYNC_IN signal polarity.
        unsigned VSYNC_POL : 1; //!< [6] VSYNC_IN signal polarity.
        unsigned CLK_POL : 1; //!< [7] DISP_CLK signal polarity.
        unsigned RESERVED1 : 24; //!< [31:8] Reserved
    } B;
} hw_dcic_dcicc_t;
#endif

/*
 * constants & macros for entire multi-block DCIC_DCICC register
 */
#define HW_DCIC_DCICC_ADDR(x)      (REGS_DCIC_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_DCIC_DCICC(x)           (*(volatile hw_dcic_dcicc_t *) HW_DCIC_DCICC_ADDR(x))
#define HW_DCIC_DCICC_RD(x)        (HW_DCIC_DCICC(x).U)
#define HW_DCIC_DCICC_WR(x, v)     (HW_DCIC_DCICC(x).U = (v))
#define HW_DCIC_DCICC_SET(x, v)    (HW_DCIC_DCICC_WR(x, HW_DCIC_DCICC_RD(x) |  (v)))
#define HW_DCIC_DCICC_CLR(x, v)    (HW_DCIC_DCICC_WR(x, HW_DCIC_DCICC_RD(x) & ~(v)))
#define HW_DCIC_DCICC_TOG(x, v)    (HW_DCIC_DCICC_WR(x, HW_DCIC_DCICC_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual DCIC_DCICC bitfields
 */

/* --- Register HW_DCIC_DCICC, field IC_EN[0] (RW)
 *
 * Integrity Check enable. Main enable switch.
 *
 * Values:
 * 0 - Disabled
 * 1 - Enabled
 */

#define BP_DCIC_DCICC_IC_EN      (0)      //!< Bit position for DCIC_DCICC_IC_EN.
#define BM_DCIC_DCICC_IC_EN      (0x00000001)  //!< Bit mask for DCIC_DCICC_IC_EN.

//! @brief Get value of DCIC_DCICC_IC_EN from a register value.
#define BG_DCIC_DCICC_IC_EN(r)   (((r) & BM_DCIC_DCICC_IC_EN) >> BP_DCIC_DCICC_IC_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield DCIC_DCICC_IC_EN.
#define BF_DCIC_DCICC_IC_EN(v)   ((((reg32_t) v) << BP_DCIC_DCICC_IC_EN) & BM_DCIC_DCICC_IC_EN)
#else
//! @brief Format value for bitfield DCIC_DCICC_IC_EN.
#define BF_DCIC_DCICC_IC_EN(v)   (((v) << BP_DCIC_DCICC_IC_EN) & BM_DCIC_DCICC_IC_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IC_EN field to a new value.
#define BW_DCIC_DCICC_IC_EN(x, v)   (HW_DCIC_DCICC_WR(x, (HW_DCIC_DCICC_RD(x) & ~BM_DCIC_DCICC_IC_EN) | BF_DCIC_DCICC_IC_EN(v)))
#endif


/* --- Register HW_DCIC_DCICC, field DE_POL[4] (RW)
 *
 * DATA_EN_IN signal polarity.
 *
 * Values:
 * 0 - Active High.
 * 1 - Active Low (default).
 */

#define BP_DCIC_DCICC_DE_POL      (4)      //!< Bit position for DCIC_DCICC_DE_POL.
#define BM_DCIC_DCICC_DE_POL      (0x00000010)  //!< Bit mask for DCIC_DCICC_DE_POL.

//! @brief Get value of DCIC_DCICC_DE_POL from a register value.
#define BG_DCIC_DCICC_DE_POL(r)   (((r) & BM_DCIC_DCICC_DE_POL) >> BP_DCIC_DCICC_DE_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield DCIC_DCICC_DE_POL.
#define BF_DCIC_DCICC_DE_POL(v)   ((((reg32_t) v) << BP_DCIC_DCICC_DE_POL) & BM_DCIC_DCICC_DE_POL)
#else
//! @brief Format value for bitfield DCIC_DCICC_DE_POL.
#define BF_DCIC_DCICC_DE_POL(v)   (((v) << BP_DCIC_DCICC_DE_POL) & BM_DCIC_DCICC_DE_POL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DE_POL field to a new value.
#define BW_DCIC_DCICC_DE_POL(x, v)   (HW_DCIC_DCICC_WR(x, (HW_DCIC_DCICC_RD(x) & ~BM_DCIC_DCICC_DE_POL) | BF_DCIC_DCICC_DE_POL(v)))
#endif


/* --- Register HW_DCIC_DCICC, field HSYNC_POL[5] (RW)
 *
 * HSYNC_IN signal polarity.
 *
 * Values:
 * 0 - Active High.
 * 1 - Active Low (default).
 */

#define BP_DCIC_DCICC_HSYNC_POL      (5)      //!< Bit position for DCIC_DCICC_HSYNC_POL.
#define BM_DCIC_DCICC_HSYNC_POL      (0x00000020)  //!< Bit mask for DCIC_DCICC_HSYNC_POL.

//! @brief Get value of DCIC_DCICC_HSYNC_POL from a register value.
#define BG_DCIC_DCICC_HSYNC_POL(r)   (((r) & BM_DCIC_DCICC_HSYNC_POL) >> BP_DCIC_DCICC_HSYNC_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield DCIC_DCICC_HSYNC_POL.
#define BF_DCIC_DCICC_HSYNC_POL(v)   ((((reg32_t) v) << BP_DCIC_DCICC_HSYNC_POL) & BM_DCIC_DCICC_HSYNC_POL)
#else
//! @brief Format value for bitfield DCIC_DCICC_HSYNC_POL.
#define BF_DCIC_DCICC_HSYNC_POL(v)   (((v) << BP_DCIC_DCICC_HSYNC_POL) & BM_DCIC_DCICC_HSYNC_POL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HSYNC_POL field to a new value.
#define BW_DCIC_DCICC_HSYNC_POL(x, v)   (HW_DCIC_DCICC_WR(x, (HW_DCIC_DCICC_RD(x) & ~BM_DCIC_DCICC_HSYNC_POL) | BF_DCIC_DCICC_HSYNC_POL(v)))
#endif


/* --- Register HW_DCIC_DCICC, field VSYNC_POL[6] (RW)
 *
 * VSYNC_IN signal polarity.
 *
 * Values:
 * 0 - Active High.
 * 1 - Active Low (default).
 */

#define BP_DCIC_DCICC_VSYNC_POL      (6)      //!< Bit position for DCIC_DCICC_VSYNC_POL.
#define BM_DCIC_DCICC_VSYNC_POL      (0x00000040)  //!< Bit mask for DCIC_DCICC_VSYNC_POL.

//! @brief Get value of DCIC_DCICC_VSYNC_POL from a register value.
#define BG_DCIC_DCICC_VSYNC_POL(r)   (((r) & BM_DCIC_DCICC_VSYNC_POL) >> BP_DCIC_DCICC_VSYNC_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield DCIC_DCICC_VSYNC_POL.
#define BF_DCIC_DCICC_VSYNC_POL(v)   ((((reg32_t) v) << BP_DCIC_DCICC_VSYNC_POL) & BM_DCIC_DCICC_VSYNC_POL)
#else
//! @brief Format value for bitfield DCIC_DCICC_VSYNC_POL.
#define BF_DCIC_DCICC_VSYNC_POL(v)   (((v) << BP_DCIC_DCICC_VSYNC_POL) & BM_DCIC_DCICC_VSYNC_POL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VSYNC_POL field to a new value.
#define BW_DCIC_DCICC_VSYNC_POL(x, v)   (HW_DCIC_DCICC_WR(x, (HW_DCIC_DCICC_RD(x) & ~BM_DCIC_DCICC_VSYNC_POL) | BF_DCIC_DCICC_VSYNC_POL(v)))
#endif


/* --- Register HW_DCIC_DCICC, field CLK_POL[7] (RW)
 *
 * DISP_CLK signal polarity.
 *
 * Values:
 * 0 - Not inverted (default).
 * 1 - Inverted.
 */

#define BP_DCIC_DCICC_CLK_POL      (7)      //!< Bit position for DCIC_DCICC_CLK_POL.
#define BM_DCIC_DCICC_CLK_POL      (0x00000080)  //!< Bit mask for DCIC_DCICC_CLK_POL.

//! @brief Get value of DCIC_DCICC_CLK_POL from a register value.
#define BG_DCIC_DCICC_CLK_POL(r)   (((r) & BM_DCIC_DCICC_CLK_POL) >> BP_DCIC_DCICC_CLK_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield DCIC_DCICC_CLK_POL.
#define BF_DCIC_DCICC_CLK_POL(v)   ((((reg32_t) v) << BP_DCIC_DCICC_CLK_POL) & BM_DCIC_DCICC_CLK_POL)
#else
//! @brief Format value for bitfield DCIC_DCICC_CLK_POL.
#define BF_DCIC_DCICC_CLK_POL(v)   (((v) << BP_DCIC_DCICC_CLK_POL) & BM_DCIC_DCICC_CLK_POL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLK_POL field to a new value.
#define BW_DCIC_DCICC_CLK_POL(x, v)   (HW_DCIC_DCICC_WR(x, (HW_DCIC_DCICC_RD(x) & ~BM_DCIC_DCICC_CLK_POL) | BF_DCIC_DCICC_CLK_POL(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCIC_DCICIC - DCIC Interrupt Control Register (RW)
 *
 * Reset value: 0x00000003
 *

 */
typedef union _hw_dcic_dcicic
{
    reg32_t U;
    struct _hw_dcic_dcicic_bitfields
    {
        unsigned EI_MASK : 1; //!< [0] Error Interrupt mask. Can be changed only while FREEZE_MASK = 0.
        unsigned FI_MASK : 1; //!< [1] Functional Interrupt mask. Can be changed only while FREEZE_MASK = 0.
        unsigned RESERVED0 : 1; //!< [2] Reserved
        unsigned FREEZE_MASK : 1; //!< [3] Disable change of interrupt masks. "Sticky" bit which can be set once and cleared by reset only.
        unsigned RESERVED1 : 12; //!< [15:4] Reserved
        unsigned EXT_SIG_EN : 1; //!< [16] External controller mismatch indication signal.
        unsigned RESERVED2 : 15; //!< [31:17] Reserved
    } B;
} hw_dcic_dcicic_t;
#endif

/*
 * constants & macros for entire multi-block DCIC_DCICIC register
 */
#define HW_DCIC_DCICIC_ADDR(x)      (REGS_DCIC_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_DCIC_DCICIC(x)           (*(volatile hw_dcic_dcicic_t *) HW_DCIC_DCICIC_ADDR(x))
#define HW_DCIC_DCICIC_RD(x)        (HW_DCIC_DCICIC(x).U)
#define HW_DCIC_DCICIC_WR(x, v)     (HW_DCIC_DCICIC(x).U = (v))
#define HW_DCIC_DCICIC_SET(x, v)    (HW_DCIC_DCICIC_WR(x, HW_DCIC_DCICIC_RD(x) |  (v)))
#define HW_DCIC_DCICIC_CLR(x, v)    (HW_DCIC_DCICIC_WR(x, HW_DCIC_DCICIC_RD(x) & ~(v)))
#define HW_DCIC_DCICIC_TOG(x, v)    (HW_DCIC_DCICIC_WR(x, HW_DCIC_DCICIC_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual DCIC_DCICIC bitfields
 */

/* --- Register HW_DCIC_DCICIC, field EI_MASK[0] (RW)
 *
 * Error Interrupt mask. Can be changed only while FREEZE_MASK = 0.
 *
 * Values:
 * 0 - Mask disabled - Interrupt assertion enabled
 * 1 - Mask enabled - Interrupt assertion disabled (default)
 */

#define BP_DCIC_DCICIC_EI_MASK      (0)      //!< Bit position for DCIC_DCICIC_EI_MASK.
#define BM_DCIC_DCICIC_EI_MASK      (0x00000001)  //!< Bit mask for DCIC_DCICIC_EI_MASK.

//! @brief Get value of DCIC_DCICIC_EI_MASK from a register value.
#define BG_DCIC_DCICIC_EI_MASK(r)   (((r) & BM_DCIC_DCICIC_EI_MASK) >> BP_DCIC_DCICIC_EI_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield DCIC_DCICIC_EI_MASK.
#define BF_DCIC_DCICIC_EI_MASK(v)   ((((reg32_t) v) << BP_DCIC_DCICIC_EI_MASK) & BM_DCIC_DCICIC_EI_MASK)
#else
//! @brief Format value for bitfield DCIC_DCICIC_EI_MASK.
#define BF_DCIC_DCICIC_EI_MASK(v)   (((v) << BP_DCIC_DCICIC_EI_MASK) & BM_DCIC_DCICIC_EI_MASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EI_MASK field to a new value.
#define BW_DCIC_DCICIC_EI_MASK(x, v)   (HW_DCIC_DCICIC_WR(x, (HW_DCIC_DCICIC_RD(x) & ~BM_DCIC_DCICIC_EI_MASK) | BF_DCIC_DCICIC_EI_MASK(v)))
#endif


/* --- Register HW_DCIC_DCICIC, field FI_MASK[1] (RW)
 *
 * Functional Interrupt mask. Can be changed only while FREEZE_MASK = 0.
 *
 * Values:
 * 0 - Mask disabled - Interrupt assertion enabled
 * 1 - Mask enabled - Interrupt assertion disabled (default)
 */

#define BP_DCIC_DCICIC_FI_MASK      (1)      //!< Bit position for DCIC_DCICIC_FI_MASK.
#define BM_DCIC_DCICIC_FI_MASK      (0x00000002)  //!< Bit mask for DCIC_DCICIC_FI_MASK.

//! @brief Get value of DCIC_DCICIC_FI_MASK from a register value.
#define BG_DCIC_DCICIC_FI_MASK(r)   (((r) & BM_DCIC_DCICIC_FI_MASK) >> BP_DCIC_DCICIC_FI_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield DCIC_DCICIC_FI_MASK.
#define BF_DCIC_DCICIC_FI_MASK(v)   ((((reg32_t) v) << BP_DCIC_DCICIC_FI_MASK) & BM_DCIC_DCICIC_FI_MASK)
#else
//! @brief Format value for bitfield DCIC_DCICIC_FI_MASK.
#define BF_DCIC_DCICIC_FI_MASK(v)   (((v) << BP_DCIC_DCICIC_FI_MASK) & BM_DCIC_DCICIC_FI_MASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FI_MASK field to a new value.
#define BW_DCIC_DCICIC_FI_MASK(x, v)   (HW_DCIC_DCICIC_WR(x, (HW_DCIC_DCICIC_RD(x) & ~BM_DCIC_DCICIC_FI_MASK) | BF_DCIC_DCICIC_FI_MASK(v)))
#endif


/* --- Register HW_DCIC_DCICIC, field FREEZE_MASK[3] (RW)
 *
 * Disable change of interrupt masks. "Sticky" bit which can be set once and cleared by reset only.
 *
 * Values:
 * 0 - Masks change allowed (default)
 * 1 - Masks are frozen
 */

#define BP_DCIC_DCICIC_FREEZE_MASK      (3)      //!< Bit position for DCIC_DCICIC_FREEZE_MASK.
#define BM_DCIC_DCICIC_FREEZE_MASK      (0x00000008)  //!< Bit mask for DCIC_DCICIC_FREEZE_MASK.

//! @brief Get value of DCIC_DCICIC_FREEZE_MASK from a register value.
#define BG_DCIC_DCICIC_FREEZE_MASK(r)   (((r) & BM_DCIC_DCICIC_FREEZE_MASK) >> BP_DCIC_DCICIC_FREEZE_MASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield DCIC_DCICIC_FREEZE_MASK.
#define BF_DCIC_DCICIC_FREEZE_MASK(v)   ((((reg32_t) v) << BP_DCIC_DCICIC_FREEZE_MASK) & BM_DCIC_DCICIC_FREEZE_MASK)
#else
//! @brief Format value for bitfield DCIC_DCICIC_FREEZE_MASK.
#define BF_DCIC_DCICIC_FREEZE_MASK(v)   (((v) << BP_DCIC_DCICIC_FREEZE_MASK) & BM_DCIC_DCICIC_FREEZE_MASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FREEZE_MASK field to a new value.
#define BW_DCIC_DCICIC_FREEZE_MASK(x, v)   (HW_DCIC_DCICIC_WR(x, (HW_DCIC_DCICIC_RD(x) & ~BM_DCIC_DCICIC_FREEZE_MASK) | BF_DCIC_DCICIC_FREEZE_MASK(v)))
#endif


/* --- Register HW_DCIC_DCICIC, field EXT_SIG_EN[16] (RW)
 *
 * External controller mismatch indication signal.
 *
 * Values:
 * 0 - Disabled (default)
 * 1 - Enabled
 */

#define BP_DCIC_DCICIC_EXT_SIG_EN      (16)      //!< Bit position for DCIC_DCICIC_EXT_SIG_EN.
#define BM_DCIC_DCICIC_EXT_SIG_EN      (0x00010000)  //!< Bit mask for DCIC_DCICIC_EXT_SIG_EN.

//! @brief Get value of DCIC_DCICIC_EXT_SIG_EN from a register value.
#define BG_DCIC_DCICIC_EXT_SIG_EN(r)   (((r) & BM_DCIC_DCICIC_EXT_SIG_EN) >> BP_DCIC_DCICIC_EXT_SIG_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield DCIC_DCICIC_EXT_SIG_EN.
#define BF_DCIC_DCICIC_EXT_SIG_EN(v)   ((((reg32_t) v) << BP_DCIC_DCICIC_EXT_SIG_EN) & BM_DCIC_DCICIC_EXT_SIG_EN)
#else
//! @brief Format value for bitfield DCIC_DCICIC_EXT_SIG_EN.
#define BF_DCIC_DCICIC_EXT_SIG_EN(v)   (((v) << BP_DCIC_DCICIC_EXT_SIG_EN) & BM_DCIC_DCICIC_EXT_SIG_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EXT_SIG_EN field to a new value.
#define BW_DCIC_DCICIC_EXT_SIG_EN(x, v)   (HW_DCIC_DCICIC_WR(x, (HW_DCIC_DCICIC_RD(x) & ~BM_DCIC_DCICIC_EXT_SIG_EN) | BF_DCIC_DCICIC_EXT_SIG_EN(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCIC_DCICS - DCIC Status Register (W1C)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_dcic_dcics
{
    reg32_t U;
    struct _hw_dcic_dcics_bitfields
    {
        unsigned ROI_MATCH_STAT : 16; //!< [15:0] Each set bit of this field indicates there was a mismatch at appropriate ROIs signature during the last frame. Valid only for active ROIs. Write "1" to clear.
        unsigned EI_STAT : 1; //!< [16] Error Interrupt status. Result of "OR" operation on ROI_MATCH_STAT[15:0] bits. Cleared when these bits are clear.
        unsigned FI_STAT : 1; //!< [17] Functional Interrupt status. Write "1" to clear.
        unsigned RESERVED0 : 14; //!< [31:18] Reserved
    } B;
} hw_dcic_dcics_t;
#endif

/*
 * constants & macros for entire multi-block DCIC_DCICS register
 */
#define HW_DCIC_DCICS_ADDR(x)      (REGS_DCIC_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_DCIC_DCICS(x)           (*(volatile hw_dcic_dcics_t *) HW_DCIC_DCICS_ADDR(x))
#define HW_DCIC_DCICS_RD(x)        (HW_DCIC_DCICS(x).U)
#define HW_DCIC_DCICS_WR(x, v)     (HW_DCIC_DCICS(x).U = (v))
#define HW_DCIC_DCICS_SET(x, v)    (HW_DCIC_DCICS_WR(x, HW_DCIC_DCICS_RD(x) |  (v)))
#define HW_DCIC_DCICS_CLR(x, v)    (HW_DCIC_DCICS_WR(x, HW_DCIC_DCICS_RD(x) & ~(v)))
#define HW_DCIC_DCICS_TOG(x, v)    (HW_DCIC_DCICS_WR(x, HW_DCIC_DCICS_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual DCIC_DCICS bitfields
 */

/* --- Register HW_DCIC_DCICS, field ROI_MATCH_STAT[15:0] (W1C)
 *
 * Each set bit of this field indicates there was a mismatch at appropriate ROIs signature during
 * the last frame. Valid only for active ROIs. Write "1" to clear.
 *
 * Values:
 * 0 - ROI calculated CRC matches expected signature
 * 1 - Mismatch at ROI calculated CRC
 */

#define BP_DCIC_DCICS_ROI_MATCH_STAT      (0)      //!< Bit position for DCIC_DCICS_ROI_MATCH_STAT.
#define BM_DCIC_DCICS_ROI_MATCH_STAT      (0x0000ffff)  //!< Bit mask for DCIC_DCICS_ROI_MATCH_STAT.

//! @brief Get value of DCIC_DCICS_ROI_MATCH_STAT from a register value.
#define BG_DCIC_DCICS_ROI_MATCH_STAT(r)   (((r) & BM_DCIC_DCICS_ROI_MATCH_STAT) >> BP_DCIC_DCICS_ROI_MATCH_STAT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield DCIC_DCICS_ROI_MATCH_STAT.
#define BF_DCIC_DCICS_ROI_MATCH_STAT(v)   ((((reg32_t) v) << BP_DCIC_DCICS_ROI_MATCH_STAT) & BM_DCIC_DCICS_ROI_MATCH_STAT)
#else
//! @brief Format value for bitfield DCIC_DCICS_ROI_MATCH_STAT.
#define BF_DCIC_DCICS_ROI_MATCH_STAT(v)   (((v) << BP_DCIC_DCICS_ROI_MATCH_STAT) & BM_DCIC_DCICS_ROI_MATCH_STAT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ROI_MATCH_STAT field to a new value.
#define BW_DCIC_DCICS_ROI_MATCH_STAT(x, v)   (HW_DCIC_DCICS_WR(x, (HW_DCIC_DCICS_RD(x) & ~BM_DCIC_DCICS_ROI_MATCH_STAT) | BF_DCIC_DCICS_ROI_MATCH_STAT(v)))
#endif


/* --- Register HW_DCIC_DCICS, field EI_STAT[16] (RO)
 *
 * Error Interrupt status. Result of "OR" operation on ROI_MATCH_STAT[15:0] bits. Cleared when these
 * bits are clear.
 *
 * Values:
 * 0 - No pending Interrupt
 * 1 - Pending Interrupt
 */

#define BP_DCIC_DCICS_EI_STAT      (16)      //!< Bit position for DCIC_DCICS_EI_STAT.
#define BM_DCIC_DCICS_EI_STAT      (0x00010000)  //!< Bit mask for DCIC_DCICS_EI_STAT.

//! @brief Get value of DCIC_DCICS_EI_STAT from a register value.
#define BG_DCIC_DCICS_EI_STAT(r)   (((r) & BM_DCIC_DCICS_EI_STAT) >> BP_DCIC_DCICS_EI_STAT)


/* --- Register HW_DCIC_DCICS, field FI_STAT[17] (W1C)
 *
 * Functional Interrupt status. Write "1" to clear.
 *
 * Values:
 * 0 - No pending Interrupt
 * 1 - Pending Interrupt
 */

#define BP_DCIC_DCICS_FI_STAT      (17)      //!< Bit position for DCIC_DCICS_FI_STAT.
#define BM_DCIC_DCICS_FI_STAT      (0x00020000)  //!< Bit mask for DCIC_DCICS_FI_STAT.

//! @brief Get value of DCIC_DCICS_FI_STAT from a register value.
#define BG_DCIC_DCICS_FI_STAT(r)   (((r) & BM_DCIC_DCICS_FI_STAT) >> BP_DCIC_DCICS_FI_STAT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield DCIC_DCICS_FI_STAT.
#define BF_DCIC_DCICS_FI_STAT(v)   ((((reg32_t) v) << BP_DCIC_DCICS_FI_STAT) & BM_DCIC_DCICS_FI_STAT)
#else
//! @brief Format value for bitfield DCIC_DCICS_FI_STAT.
#define BF_DCIC_DCICS_FI_STAT(v)   (((v) << BP_DCIC_DCICS_FI_STAT) & BM_DCIC_DCICS_FI_STAT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FI_STAT field to a new value.
#define BW_DCIC_DCICS_FI_STAT(x, v)   (HW_DCIC_DCICS_WR(x, (HW_DCIC_DCICS_RD(x) & ~BM_DCIC_DCICS_FI_STAT) | BF_DCIC_DCICS_FI_STAT(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCIC_DCICRC - DCIC ROI Config Register m (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_dcic_dcicrc
{
    reg32_t U;
    struct _hw_dcic_dcicrc_bitfields
    {
        unsigned START_OFFSET_X : 13; //!< [12:0] Column number of ROIs upper-left corner (X coordinate) Range: 0 to 2^ 13 -1
        unsigned RESERVED0 : 3; //!< [15:13] Reserved
        unsigned START_OFFSET_Y : 12; //!< [27:16] Row number of ROIs upper-left corner (Y coordinate) Range: 0 to 2^ 12 -1
        unsigned RESERVED1 : 2; //!< [29:28] Reserved
        unsigned ROI_FREEZE : 1; //!< [30] When set, the only parameter of ROI #m that can be changed is reference signature. "Sticky" bit - can be set once and cleared by reset only.
        unsigned ROI_EN : 1; //!< [31] ROI #m tracking enable
    } B;
} hw_dcic_dcicrc_t;
#endif

/*
 * constants & macros for entire multi-block DCIC_DCICRC register
 */
#define HW_DCIC_DCICRC_ADDR(x)      (REGS_DCIC_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_DCIC_DCICRC(x)           (*(volatile hw_dcic_dcicrc_t *) HW_DCIC_DCICRC_ADDR(x))
#define HW_DCIC_DCICRC_RD(x)        (HW_DCIC_DCICRC(x).U)
#define HW_DCIC_DCICRC_WR(x, v)     (HW_DCIC_DCICRC(x).U = (v))
#define HW_DCIC_DCICRC_SET(x, v)    (HW_DCIC_DCICRC_WR(x, HW_DCIC_DCICRC_RD(x) |  (v)))
#define HW_DCIC_DCICRC_CLR(x, v)    (HW_DCIC_DCICRC_WR(x, HW_DCIC_DCICRC_RD(x) & ~(v)))
#define HW_DCIC_DCICRC_TOG(x, v)    (HW_DCIC_DCICRC_WR(x, HW_DCIC_DCICRC_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual DCIC_DCICRC bitfields
 */

/* --- Register HW_DCIC_DCICRC, field START_OFFSET_X[12:0] (RW)
 *
 * Column number of ROIs upper-left corner (X coordinate) Range: 0 to 2^ 13 -1
 */

#define BP_DCIC_DCICRC_START_OFFSET_X      (0)      //!< Bit position for DCIC_DCICRC_START_OFFSET_X.
#define BM_DCIC_DCICRC_START_OFFSET_X      (0x00001fff)  //!< Bit mask for DCIC_DCICRC_START_OFFSET_X.

//! @brief Get value of DCIC_DCICRC_START_OFFSET_X from a register value.
#define BG_DCIC_DCICRC_START_OFFSET_X(r)   (((r) & BM_DCIC_DCICRC_START_OFFSET_X) >> BP_DCIC_DCICRC_START_OFFSET_X)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield DCIC_DCICRC_START_OFFSET_X.
#define BF_DCIC_DCICRC_START_OFFSET_X(v)   ((((reg32_t) v) << BP_DCIC_DCICRC_START_OFFSET_X) & BM_DCIC_DCICRC_START_OFFSET_X)
#else
//! @brief Format value for bitfield DCIC_DCICRC_START_OFFSET_X.
#define BF_DCIC_DCICRC_START_OFFSET_X(v)   (((v) << BP_DCIC_DCICRC_START_OFFSET_X) & BM_DCIC_DCICRC_START_OFFSET_X)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the START_OFFSET_X field to a new value.
#define BW_DCIC_DCICRC_START_OFFSET_X(x, v)   (HW_DCIC_DCICRC_WR(x, (HW_DCIC_DCICRC_RD(x) & ~BM_DCIC_DCICRC_START_OFFSET_X) | BF_DCIC_DCICRC_START_OFFSET_X(v)))
#endif

/* --- Register HW_DCIC_DCICRC, field START_OFFSET_Y[27:16] (RW)
 *
 * Row number of ROIs upper-left corner (Y coordinate) Range: 0 to 2^ 12 -1
 */

#define BP_DCIC_DCICRC_START_OFFSET_Y      (16)      //!< Bit position for DCIC_DCICRC_START_OFFSET_Y.
#define BM_DCIC_DCICRC_START_OFFSET_Y      (0x0fff0000)  //!< Bit mask for DCIC_DCICRC_START_OFFSET_Y.

//! @brief Get value of DCIC_DCICRC_START_OFFSET_Y from a register value.
#define BG_DCIC_DCICRC_START_OFFSET_Y(r)   (((r) & BM_DCIC_DCICRC_START_OFFSET_Y) >> BP_DCIC_DCICRC_START_OFFSET_Y)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield DCIC_DCICRC_START_OFFSET_Y.
#define BF_DCIC_DCICRC_START_OFFSET_Y(v)   ((((reg32_t) v) << BP_DCIC_DCICRC_START_OFFSET_Y) & BM_DCIC_DCICRC_START_OFFSET_Y)
#else
//! @brief Format value for bitfield DCIC_DCICRC_START_OFFSET_Y.
#define BF_DCIC_DCICRC_START_OFFSET_Y(v)   (((v) << BP_DCIC_DCICRC_START_OFFSET_Y) & BM_DCIC_DCICRC_START_OFFSET_Y)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the START_OFFSET_Y field to a new value.
#define BW_DCIC_DCICRC_START_OFFSET_Y(x, v)   (HW_DCIC_DCICRC_WR(x, (HW_DCIC_DCICRC_RD(x) & ~BM_DCIC_DCICRC_START_OFFSET_Y) | BF_DCIC_DCICRC_START_OFFSET_Y(v)))
#endif

/* --- Register HW_DCIC_DCICRC, field ROI_FREEZE[30] (RW)
 *
 * When set, the only parameter of ROI #m that can be changed is reference signature. "Sticky" bit -
 * can be set once and cleared by reset only.
 *
 * Values:
 * 0 - ROI configuration can be changed
 * 1 - ROI configuration is frozen
 */

#define BP_DCIC_DCICRC_ROI_FREEZE      (30)      //!< Bit position for DCIC_DCICRC_ROI_FREEZE.
#define BM_DCIC_DCICRC_ROI_FREEZE      (0x40000000)  //!< Bit mask for DCIC_DCICRC_ROI_FREEZE.

//! @brief Get value of DCIC_DCICRC_ROI_FREEZE from a register value.
#define BG_DCIC_DCICRC_ROI_FREEZE(r)   (((r) & BM_DCIC_DCICRC_ROI_FREEZE) >> BP_DCIC_DCICRC_ROI_FREEZE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield DCIC_DCICRC_ROI_FREEZE.
#define BF_DCIC_DCICRC_ROI_FREEZE(v)   ((((reg32_t) v) << BP_DCIC_DCICRC_ROI_FREEZE) & BM_DCIC_DCICRC_ROI_FREEZE)
#else
//! @brief Format value for bitfield DCIC_DCICRC_ROI_FREEZE.
#define BF_DCIC_DCICRC_ROI_FREEZE(v)   (((v) << BP_DCIC_DCICRC_ROI_FREEZE) & BM_DCIC_DCICRC_ROI_FREEZE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ROI_FREEZE field to a new value.
#define BW_DCIC_DCICRC_ROI_FREEZE(x, v)   (HW_DCIC_DCICRC_WR(x, (HW_DCIC_DCICRC_RD(x) & ~BM_DCIC_DCICRC_ROI_FREEZE) | BF_DCIC_DCICRC_ROI_FREEZE(v)))
#endif


/* --- Register HW_DCIC_DCICRC, field ROI_EN[31] (RW)
 *
 * ROI #m tracking enable
 *
 * Values:
 * 0 - Disabled
 * 1 - Enabled
 */

#define BP_DCIC_DCICRC_ROI_EN      (31)      //!< Bit position for DCIC_DCICRC_ROI_EN.
#define BM_DCIC_DCICRC_ROI_EN      (0x80000000)  //!< Bit mask for DCIC_DCICRC_ROI_EN.

//! @brief Get value of DCIC_DCICRC_ROI_EN from a register value.
#define BG_DCIC_DCICRC_ROI_EN(r)   (((r) & BM_DCIC_DCICRC_ROI_EN) >> BP_DCIC_DCICRC_ROI_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield DCIC_DCICRC_ROI_EN.
#define BF_DCIC_DCICRC_ROI_EN(v)   ((((reg32_t) v) << BP_DCIC_DCICRC_ROI_EN) & BM_DCIC_DCICRC_ROI_EN)
#else
//! @brief Format value for bitfield DCIC_DCICRC_ROI_EN.
#define BF_DCIC_DCICRC_ROI_EN(v)   (((v) << BP_DCIC_DCICRC_ROI_EN) & BM_DCIC_DCICRC_ROI_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ROI_EN field to a new value.
#define BW_DCIC_DCICRC_ROI_EN(x, v)   (HW_DCIC_DCICRC_WR(x, (HW_DCIC_DCICRC_RD(x) & ~BM_DCIC_DCICRC_ROI_EN) | BF_DCIC_DCICRC_ROI_EN(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCIC_DCICRS - DCIC ROI Size Register m (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_dcic_dcicrs
{
    reg32_t U;
    struct _hw_dcic_dcicrs_bitfields
    {
        unsigned END_OFFSET_X : 13; //!< [12:0] Column number of ROIs lower-right corner (X coordinate) Range: 1 to 2^ 13 -1
        unsigned RESERVED0 : 3; //!< [15:13] Reserved
        unsigned END_OFFSET_Y : 12; //!< [27:16] Row number of ROIs lower-right corner (Y coordinate) Range: 1 to 2^ 12 -1
        unsigned RESERVED1 : 4; //!< [31:28] Reserved
    } B;
} hw_dcic_dcicrs_t;
#endif

/*
 * constants & macros for entire multi-block DCIC_DCICRS register
 */
#define HW_DCIC_DCICRS_ADDR(x)      (REGS_DCIC_BASE(x) + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_DCIC_DCICRS(x)           (*(volatile hw_dcic_dcicrs_t *) HW_DCIC_DCICRS_ADDR(x))
#define HW_DCIC_DCICRS_RD(x)        (HW_DCIC_DCICRS(x).U)
#define HW_DCIC_DCICRS_WR(x, v)     (HW_DCIC_DCICRS(x).U = (v))
#define HW_DCIC_DCICRS_SET(x, v)    (HW_DCIC_DCICRS_WR(x, HW_DCIC_DCICRS_RD(x) |  (v)))
#define HW_DCIC_DCICRS_CLR(x, v)    (HW_DCIC_DCICRS_WR(x, HW_DCIC_DCICRS_RD(x) & ~(v)))
#define HW_DCIC_DCICRS_TOG(x, v)    (HW_DCIC_DCICRS_WR(x, HW_DCIC_DCICRS_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual DCIC_DCICRS bitfields
 */

/* --- Register HW_DCIC_DCICRS, field END_OFFSET_X[12:0] (RW)
 *
 * Column number of ROIs lower-right corner (X coordinate) Range: 1 to 2^ 13 -1
 */

#define BP_DCIC_DCICRS_END_OFFSET_X      (0)      //!< Bit position for DCIC_DCICRS_END_OFFSET_X.
#define BM_DCIC_DCICRS_END_OFFSET_X      (0x00001fff)  //!< Bit mask for DCIC_DCICRS_END_OFFSET_X.

//! @brief Get value of DCIC_DCICRS_END_OFFSET_X from a register value.
#define BG_DCIC_DCICRS_END_OFFSET_X(r)   (((r) & BM_DCIC_DCICRS_END_OFFSET_X) >> BP_DCIC_DCICRS_END_OFFSET_X)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield DCIC_DCICRS_END_OFFSET_X.
#define BF_DCIC_DCICRS_END_OFFSET_X(v)   ((((reg32_t) v) << BP_DCIC_DCICRS_END_OFFSET_X) & BM_DCIC_DCICRS_END_OFFSET_X)
#else
//! @brief Format value for bitfield DCIC_DCICRS_END_OFFSET_X.
#define BF_DCIC_DCICRS_END_OFFSET_X(v)   (((v) << BP_DCIC_DCICRS_END_OFFSET_X) & BM_DCIC_DCICRS_END_OFFSET_X)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the END_OFFSET_X field to a new value.
#define BW_DCIC_DCICRS_END_OFFSET_X(x, v)   (HW_DCIC_DCICRS_WR(x, (HW_DCIC_DCICRS_RD(x) & ~BM_DCIC_DCICRS_END_OFFSET_X) | BF_DCIC_DCICRS_END_OFFSET_X(v)))
#endif

/* --- Register HW_DCIC_DCICRS, field END_OFFSET_Y[27:16] (RW)
 *
 * Row number of ROIs lower-right corner (Y coordinate) Range: 1 to 2^ 12 -1
 */

#define BP_DCIC_DCICRS_END_OFFSET_Y      (16)      //!< Bit position for DCIC_DCICRS_END_OFFSET_Y.
#define BM_DCIC_DCICRS_END_OFFSET_Y      (0x0fff0000)  //!< Bit mask for DCIC_DCICRS_END_OFFSET_Y.

//! @brief Get value of DCIC_DCICRS_END_OFFSET_Y from a register value.
#define BG_DCIC_DCICRS_END_OFFSET_Y(r)   (((r) & BM_DCIC_DCICRS_END_OFFSET_Y) >> BP_DCIC_DCICRS_END_OFFSET_Y)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield DCIC_DCICRS_END_OFFSET_Y.
#define BF_DCIC_DCICRS_END_OFFSET_Y(v)   ((((reg32_t) v) << BP_DCIC_DCICRS_END_OFFSET_Y) & BM_DCIC_DCICRS_END_OFFSET_Y)
#else
//! @brief Format value for bitfield DCIC_DCICRS_END_OFFSET_Y.
#define BF_DCIC_DCICRS_END_OFFSET_Y(v)   (((v) << BP_DCIC_DCICRS_END_OFFSET_Y) & BM_DCIC_DCICRS_END_OFFSET_Y)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the END_OFFSET_Y field to a new value.
#define BW_DCIC_DCICRS_END_OFFSET_Y(x, v)   (HW_DCIC_DCICRS_WR(x, (HW_DCIC_DCICRS_RD(x) & ~BM_DCIC_DCICRS_END_OFFSET_Y) | BF_DCIC_DCICRS_END_OFFSET_Y(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCIC_DCICRRS - DCIC ROI Reference Signature Register m (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_dcic_dcicrrs
{
    reg32_t U;
    struct _hw_dcic_dcicrrs_bitfields
    {
        unsigned REFERENCE_SIGNATURE : 32; //!< [31:0] 32-bit expected signature (CRC calculation result) for ROI #m
    } B;
} hw_dcic_dcicrrs_t;
#endif

/*
 * constants & macros for entire multi-block DCIC_DCICRRS register
 */
#define HW_DCIC_DCICRRS_ADDR(x)      (REGS_DCIC_BASE(x) + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_DCIC_DCICRRS(x)           (*(volatile hw_dcic_dcicrrs_t *) HW_DCIC_DCICRRS_ADDR(x))
#define HW_DCIC_DCICRRS_RD(x)        (HW_DCIC_DCICRRS(x).U)
#define HW_DCIC_DCICRRS_WR(x, v)     (HW_DCIC_DCICRRS(x).U = (v))
#define HW_DCIC_DCICRRS_SET(x, v)    (HW_DCIC_DCICRRS_WR(x, HW_DCIC_DCICRRS_RD(x) |  (v)))
#define HW_DCIC_DCICRRS_CLR(x, v)    (HW_DCIC_DCICRRS_WR(x, HW_DCIC_DCICRRS_RD(x) & ~(v)))
#define HW_DCIC_DCICRRS_TOG(x, v)    (HW_DCIC_DCICRRS_WR(x, HW_DCIC_DCICRRS_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual DCIC_DCICRRS bitfields
 */

/* --- Register HW_DCIC_DCICRRS, field REFERENCE_SIGNATURE[31:0] (RW)
 *
 * 32-bit expected signature (CRC calculation result) for ROI #m
 */

#define BP_DCIC_DCICRRS_REFERENCE_SIGNATURE      (0)      //!< Bit position for DCIC_DCICRRS_REFERENCE_SIGNATURE.
#define BM_DCIC_DCICRRS_REFERENCE_SIGNATURE      (0xffffffff)  //!< Bit mask for DCIC_DCICRRS_REFERENCE_SIGNATURE.

//! @brief Get value of DCIC_DCICRRS_REFERENCE_SIGNATURE from a register value.
#define BG_DCIC_DCICRRS_REFERENCE_SIGNATURE(r)   (((r) & BM_DCIC_DCICRRS_REFERENCE_SIGNATURE) >> BP_DCIC_DCICRRS_REFERENCE_SIGNATURE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield DCIC_DCICRRS_REFERENCE_SIGNATURE.
#define BF_DCIC_DCICRRS_REFERENCE_SIGNATURE(v)   ((((reg32_t) v) << BP_DCIC_DCICRRS_REFERENCE_SIGNATURE) & BM_DCIC_DCICRRS_REFERENCE_SIGNATURE)
#else
//! @brief Format value for bitfield DCIC_DCICRRS_REFERENCE_SIGNATURE.
#define BF_DCIC_DCICRRS_REFERENCE_SIGNATURE(v)   (((v) << BP_DCIC_DCICRRS_REFERENCE_SIGNATURE) & BM_DCIC_DCICRRS_REFERENCE_SIGNATURE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REFERENCE_SIGNATURE field to a new value.
#define BW_DCIC_DCICRRS_REFERENCE_SIGNATURE(x, v)   (HW_DCIC_DCICRRS_WR(x, (HW_DCIC_DCICRRS_RD(x) & ~BM_DCIC_DCICRRS_REFERENCE_SIGNATURE) | BF_DCIC_DCICRRS_REFERENCE_SIGNATURE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCIC_DCICRCS - DCIC ROI Calculated Signature m (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_dcic_dcicrcs
{
    reg32_t U;
    struct _hw_dcic_dcicrcs_bitfields
    {
        unsigned CALCULATED_SIGNATURE : 32; //!< [31:0] 32-bit actual signature (CRC calculation result) for ROI #m during the last frame. Updated automatically at the beginning of a next frame.
    } B;
} hw_dcic_dcicrcs_t;
#endif

/*
 * constants & macros for entire multi-block DCIC_DCICRCS register
 */
#define HW_DCIC_DCICRCS_ADDR(x)      (REGS_DCIC_BASE(x) + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_DCIC_DCICRCS(x)           (*(volatile hw_dcic_dcicrcs_t *) HW_DCIC_DCICRCS_ADDR(x))
#define HW_DCIC_DCICRCS_RD(x)        (HW_DCIC_DCICRCS(x).U)
#endif

/*
 * constants & macros for individual DCIC_DCICRCS bitfields
 */

/* --- Register HW_DCIC_DCICRCS, field CALCULATED_SIGNATURE[31:0] (RO)
 *
 * 32-bit actual signature (CRC calculation result) for ROI #m during the last frame. Updated
 * automatically at the beginning of a next frame.
 */

#define BP_DCIC_DCICRCS_CALCULATED_SIGNATURE      (0)      //!< Bit position for DCIC_DCICRCS_CALCULATED_SIGNATURE.
#define BM_DCIC_DCICRCS_CALCULATED_SIGNATURE      (0xffffffff)  //!< Bit mask for DCIC_DCICRCS_CALCULATED_SIGNATURE.

//! @brief Get value of DCIC_DCICRCS_CALCULATED_SIGNATURE from a register value.
#define BG_DCIC_DCICRCS_CALCULATED_SIGNATURE(r)   (((r) & BM_DCIC_DCICRCS_CALCULATED_SIGNATURE) >> BP_DCIC_DCICRCS_CALCULATED_SIGNATURE)


/*!
 * @brief All DCIC module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_dcic
{
    volatile hw_dcic_dcicc_t DCICC; //!< DCIC Control Register
    volatile hw_dcic_dcicic_t DCICIC; //!< DCIC Interrupt Control Register
    volatile hw_dcic_dcics_t DCICS; //!< DCIC Status Register
    reg32_t _reserved0;
    volatile hw_dcic_dcicrc_t DCICRC; //!< DCIC ROI Config Register m
    volatile hw_dcic_dcicrs_t DCICRS; //!< DCIC ROI Size Register m
    volatile hw_dcic_dcicrrs_t DCICRRS; //!< DCIC ROI Reference Signature Register m
    volatile hw_dcic_dcicrcs_t DCICRCS; //!< DCIC ROI Calculated Signature m
} hw_dcic_t;
#pragma pack()
#endif

//! @brief Macro to access all DCIC registers.
//! @param x DCIC instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_DCIC(0)</code>.
#define HW_DCIC(x)     (*(volatile hw_dcic_t *) REGS_DCIC_BASE(x))


#endif // _DCIC_H