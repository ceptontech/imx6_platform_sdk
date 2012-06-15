/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_PGC_REGISTERS_H__
#define __HW_PGC_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6DQ PGC registers defined in this header file.
 *
 * - HW_PGC_DISPLAY_CTRL - PGC Control Register
 * - HW_PGC_DISPLAY_PUPSCR - Power Up Sequence Control Register
 * - HW_PGC_DISPLAY_PDNSCR - Pull Down Sequence Control Register
 * - HW_PGC_DISPLAY_SR - Power Gating Controller Status Register
 * - HW_PGC_GPU_CTRL - PGC Control Register
 * - HW_PGC_GPU_PUPSCR - Power Up Sequence Control Register
 * - HW_PGC_GPU_PDNSCR - Pull Down Sequence Control Register
 * - HW_PGC_GPU_SR - Power Gating Controller Status Register
 * - HW_PGC_CPU_CTRL - PGC Control Register
 * - HW_PGC_CPU_PUPSCR - Power Up Sequence Control Register
 * - HW_PGC_CPU_PDNSCR - Pull Down Sequence Control Register
 * - HW_PGC_CPU_SR - Power Gating Controller Status Register
 *
 * - hw_pgc_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_PGC_BASE
#define HW_PGC_INSTANCE_COUNT (1) //!< Number of instances of the PGC module.
#define REGS_PGC_BASE (0x020dc000) //!< Base address for PGC.
#endif
//@}


//-------------------------------------------------------------------------------------------
// HW_PGC_DISPLAY_CTRL - PGC Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PGC_DISPLAY_CTRL - PGC Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The PGCR enables the response to a power-down request.
 */
typedef union _hw_pgc_display_ctrl
{
    reg32_t U;
    struct _hw_pgc_display_ctrl_bitfields
    {
        unsigned PCR : 1; //!< [0] Power Control PCR must not change from power-down request (pdn_req) assertion until the target subsystem is completely powered up.
        unsigned RESERVED0 : 31; //!< [31:1] Reserved.
    } B;
} hw_pgc_display_ctrl_t;
#endif

/*
 * constants & macros for entire PGC_DISPLAY_CTRL register
 */
#define HW_PGC_DISPLAY_CTRL_ADDR      (REGS_PGC_BASE + 0x240)

#ifndef __LANGUAGE_ASM__
#define HW_PGC_DISPLAY_CTRL           (*(volatile hw_pgc_display_ctrl_t *) HW_PGC_DISPLAY_CTRL_ADDR)
#define HW_PGC_DISPLAY_CTRL_RD()      (HW_PGC_DISPLAY_CTRL.U)
#define HW_PGC_DISPLAY_CTRL_WR(v)     (HW_PGC_DISPLAY_CTRL.U = (v))
#define HW_PGC_DISPLAY_CTRL_SET(v)    (HW_PGC_DISPLAY_CTRL_WR(HW_PGC_DISPLAY_CTRL_RD() |  (v)))
#define HW_PGC_DISPLAY_CTRL_CLR(v)    (HW_PGC_DISPLAY_CTRL_WR(HW_PGC_DISPLAY_CTRL_RD() & ~(v)))
#define HW_PGC_DISPLAY_CTRL_TOG(v)    (HW_PGC_DISPLAY_CTRL_WR(HW_PGC_DISPLAY_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PGC_DISPLAY_CTRL bitfields
 */

/* --- Register HW_PGC_DISPLAY_CTRL, field PCR[0] (RW)
 *
 * Power Control PCR must not change from power-down request (pdn_req) assertion until the target
 * subsystem is completely powered up.
 *
 * Values:
 * 0 - Do not switch off power even if pdn_req is asserted.
 * 1 - Switch off power when pdn_req is asserted.
 */

#define BP_PGC_DISPLAY_CTRL_PCR      (0)      //!< Bit position for PGC_DISPLAY_CTRL_PCR.
#define BM_PGC_DISPLAY_CTRL_PCR      (0x00000001)  //!< Bit mask for PGC_DISPLAY_CTRL_PCR.

//! @brief Get value of PGC_DISPLAY_CTRL_PCR from a register value.
#define BG_PGC_DISPLAY_CTRL_PCR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PGC_DISPLAY_CTRL_PCR) >> BP_PGC_DISPLAY_CTRL_PCR)

//! @brief Format value for bitfield PGC_DISPLAY_CTRL_PCR.
#define BF_PGC_DISPLAY_CTRL_PCR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PGC_DISPLAY_CTRL_PCR) & BM_PGC_DISPLAY_CTRL_PCR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PCR field to a new value.
#define BW_PGC_DISPLAY_CTRL_PCR(v)   (HW_PGC_DISPLAY_CTRL_WR((HW_PGC_DISPLAY_CTRL_RD() & ~BM_PGC_DISPLAY_CTRL_PCR) | BF_PGC_DISPLAY_CTRL_PCR(v)))
#endif


//-------------------------------------------------------------------------------------------
// HW_PGC_DISPLAY_PUPSCR - Power Up Sequence Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PGC_DISPLAY_PUPSCR - Power Up Sequence Control Register (RW)
 *
 * Reset value: 0x00000f01
 *
 * The PUPSCR contains the power-up timing parameters. See .
 */
typedef union _hw_pgc_display_pupscr
{
    reg32_t U;
    struct _hw_pgc_display_pupscr_bitfields
    {
        unsigned SW : 6; //!< [5:0] After a power-up request (pup_req assertion), the PGC waits a number of clocks equal to the value of SW before asserting switch_b.
        unsigned RESERVED0 : 2; //!< [7:6] Reserved.
        unsigned SW2ISO : 6; //!< [13:8] After asserting switch_b, the PGC waits a number of clocks equal to the value of SW2ISO before negating isolation.
        unsigned RESERVED1 : 18; //!< [31:14] Reserved.
    } B;
} hw_pgc_display_pupscr_t;
#endif

/*
 * constants & macros for entire PGC_DISPLAY_PUPSCR register
 */
#define HW_PGC_DISPLAY_PUPSCR_ADDR      (REGS_PGC_BASE + 0x244)

#ifndef __LANGUAGE_ASM__
#define HW_PGC_DISPLAY_PUPSCR           (*(volatile hw_pgc_display_pupscr_t *) HW_PGC_DISPLAY_PUPSCR_ADDR)
#define HW_PGC_DISPLAY_PUPSCR_RD()      (HW_PGC_DISPLAY_PUPSCR.U)
#define HW_PGC_DISPLAY_PUPSCR_WR(v)     (HW_PGC_DISPLAY_PUPSCR.U = (v))
#define HW_PGC_DISPLAY_PUPSCR_SET(v)    (HW_PGC_DISPLAY_PUPSCR_WR(HW_PGC_DISPLAY_PUPSCR_RD() |  (v)))
#define HW_PGC_DISPLAY_PUPSCR_CLR(v)    (HW_PGC_DISPLAY_PUPSCR_WR(HW_PGC_DISPLAY_PUPSCR_RD() & ~(v)))
#define HW_PGC_DISPLAY_PUPSCR_TOG(v)    (HW_PGC_DISPLAY_PUPSCR_WR(HW_PGC_DISPLAY_PUPSCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PGC_DISPLAY_PUPSCR bitfields
 */

/* --- Register HW_PGC_DISPLAY_PUPSCR, field SW[5:0] (RW)
 *
 * After a power-up request (pup_req assertion), the PGC waits a number of clocks equal to the value
 * of SW before asserting switch_b. SW must not be programmed to zero. The PGC clock is generated
 * from the IPG_CLK_ROOT. for frequency configuration of the IPG_CLK_ROOT, see CCM chapter.
 */

#define BP_PGC_DISPLAY_PUPSCR_SW      (0)      //!< Bit position for PGC_DISPLAY_PUPSCR_SW.
#define BM_PGC_DISPLAY_PUPSCR_SW      (0x0000003f)  //!< Bit mask for PGC_DISPLAY_PUPSCR_SW.

//! @brief Get value of PGC_DISPLAY_PUPSCR_SW from a register value.
#define BG_PGC_DISPLAY_PUPSCR_SW(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PGC_DISPLAY_PUPSCR_SW) >> BP_PGC_DISPLAY_PUPSCR_SW)

//! @brief Format value for bitfield PGC_DISPLAY_PUPSCR_SW.
#define BF_PGC_DISPLAY_PUPSCR_SW(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PGC_DISPLAY_PUPSCR_SW) & BM_PGC_DISPLAY_PUPSCR_SW)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SW field to a new value.
#define BW_PGC_DISPLAY_PUPSCR_SW(v)   (HW_PGC_DISPLAY_PUPSCR_WR((HW_PGC_DISPLAY_PUPSCR_RD() & ~BM_PGC_DISPLAY_PUPSCR_SW) | BF_PGC_DISPLAY_PUPSCR_SW(v)))
#endif

/* --- Register HW_PGC_DISPLAY_PUPSCR, field SW2ISO[13:8] (RW)
 *
 * After asserting switch_b, the PGC waits a number of clocks equal to the value of SW2ISO before
 * negating isolation. SW2ISO must not be programmed to zero.
 */

#define BP_PGC_DISPLAY_PUPSCR_SW2ISO      (8)      //!< Bit position for PGC_DISPLAY_PUPSCR_SW2ISO.
#define BM_PGC_DISPLAY_PUPSCR_SW2ISO      (0x00003f00)  //!< Bit mask for PGC_DISPLAY_PUPSCR_SW2ISO.

//! @brief Get value of PGC_DISPLAY_PUPSCR_SW2ISO from a register value.
#define BG_PGC_DISPLAY_PUPSCR_SW2ISO(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PGC_DISPLAY_PUPSCR_SW2ISO) >> BP_PGC_DISPLAY_PUPSCR_SW2ISO)

//! @brief Format value for bitfield PGC_DISPLAY_PUPSCR_SW2ISO.
#define BF_PGC_DISPLAY_PUPSCR_SW2ISO(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PGC_DISPLAY_PUPSCR_SW2ISO) & BM_PGC_DISPLAY_PUPSCR_SW2ISO)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SW2ISO field to a new value.
#define BW_PGC_DISPLAY_PUPSCR_SW2ISO(v)   (HW_PGC_DISPLAY_PUPSCR_WR((HW_PGC_DISPLAY_PUPSCR_RD() & ~BM_PGC_DISPLAY_PUPSCR_SW2ISO) | BF_PGC_DISPLAY_PUPSCR_SW2ISO(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PGC_DISPLAY_PDNSCR - Pull Down Sequence Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PGC_DISPLAY_PDNSCR - Pull Down Sequence Control Register (RW)
 *
 * Reset value: 0x00000101
 *
 * The PDNSCR contains the power-down timing parameters. See .
 */
typedef union _hw_pgc_display_pdnscr
{
    reg32_t U;
    struct _hw_pgc_display_pdnscr_bitfields
    {
        unsigned ISO : 6; //!< [5:0] After a power-down request (pdn_req assertion), the PGC waits a number of clocks equal to the value of ISO before asserting isolation.
        unsigned RESERVED0 : 2; //!< [7:6] Reserved.
        unsigned ISO2SW : 6; //!< [13:8] After asserting isolation, the PGC waits a number of clocks equal to the value of ISO2SW before negating switch_b.
        unsigned RESERVED1 : 18; //!< [31:14] Reserved.
    } B;
} hw_pgc_display_pdnscr_t;
#endif

/*
 * constants & macros for entire PGC_DISPLAY_PDNSCR register
 */
#define HW_PGC_DISPLAY_PDNSCR_ADDR      (REGS_PGC_BASE + 0x248)

#ifndef __LANGUAGE_ASM__
#define HW_PGC_DISPLAY_PDNSCR           (*(volatile hw_pgc_display_pdnscr_t *) HW_PGC_DISPLAY_PDNSCR_ADDR)
#define HW_PGC_DISPLAY_PDNSCR_RD()      (HW_PGC_DISPLAY_PDNSCR.U)
#define HW_PGC_DISPLAY_PDNSCR_WR(v)     (HW_PGC_DISPLAY_PDNSCR.U = (v))
#define HW_PGC_DISPLAY_PDNSCR_SET(v)    (HW_PGC_DISPLAY_PDNSCR_WR(HW_PGC_DISPLAY_PDNSCR_RD() |  (v)))
#define HW_PGC_DISPLAY_PDNSCR_CLR(v)    (HW_PGC_DISPLAY_PDNSCR_WR(HW_PGC_DISPLAY_PDNSCR_RD() & ~(v)))
#define HW_PGC_DISPLAY_PDNSCR_TOG(v)    (HW_PGC_DISPLAY_PDNSCR_WR(HW_PGC_DISPLAY_PDNSCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PGC_DISPLAY_PDNSCR bitfields
 */

/* --- Register HW_PGC_DISPLAY_PDNSCR, field ISO[5:0] (RW)
 *
 * After a power-down request (pdn_req assertion), the PGC waits a number of clocks equal to the
 * value of ISO before asserting isolation. ISO must not be programmed to zero.
 */

#define BP_PGC_DISPLAY_PDNSCR_ISO      (0)      //!< Bit position for PGC_DISPLAY_PDNSCR_ISO.
#define BM_PGC_DISPLAY_PDNSCR_ISO      (0x0000003f)  //!< Bit mask for PGC_DISPLAY_PDNSCR_ISO.

//! @brief Get value of PGC_DISPLAY_PDNSCR_ISO from a register value.
#define BG_PGC_DISPLAY_PDNSCR_ISO(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PGC_DISPLAY_PDNSCR_ISO) >> BP_PGC_DISPLAY_PDNSCR_ISO)

//! @brief Format value for bitfield PGC_DISPLAY_PDNSCR_ISO.
#define BF_PGC_DISPLAY_PDNSCR_ISO(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PGC_DISPLAY_PDNSCR_ISO) & BM_PGC_DISPLAY_PDNSCR_ISO)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ISO field to a new value.
#define BW_PGC_DISPLAY_PDNSCR_ISO(v)   (HW_PGC_DISPLAY_PDNSCR_WR((HW_PGC_DISPLAY_PDNSCR_RD() & ~BM_PGC_DISPLAY_PDNSCR_ISO) | BF_PGC_DISPLAY_PDNSCR_ISO(v)))
#endif

/* --- Register HW_PGC_DISPLAY_PDNSCR, field ISO2SW[13:8] (RW)
 *
 * After asserting isolation, the PGC waits a number of clocks equal to the value of ISO2SW before
 * negating switch_b. ISO2SW must not be programmed to zero.
 */

#define BP_PGC_DISPLAY_PDNSCR_ISO2SW      (8)      //!< Bit position for PGC_DISPLAY_PDNSCR_ISO2SW.
#define BM_PGC_DISPLAY_PDNSCR_ISO2SW      (0x00003f00)  //!< Bit mask for PGC_DISPLAY_PDNSCR_ISO2SW.

//! @brief Get value of PGC_DISPLAY_PDNSCR_ISO2SW from a register value.
#define BG_PGC_DISPLAY_PDNSCR_ISO2SW(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PGC_DISPLAY_PDNSCR_ISO2SW) >> BP_PGC_DISPLAY_PDNSCR_ISO2SW)

//! @brief Format value for bitfield PGC_DISPLAY_PDNSCR_ISO2SW.
#define BF_PGC_DISPLAY_PDNSCR_ISO2SW(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PGC_DISPLAY_PDNSCR_ISO2SW) & BM_PGC_DISPLAY_PDNSCR_ISO2SW)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ISO2SW field to a new value.
#define BW_PGC_DISPLAY_PDNSCR_ISO2SW(v)   (HW_PGC_DISPLAY_PDNSCR_WR((HW_PGC_DISPLAY_PDNSCR_RD() & ~BM_PGC_DISPLAY_PDNSCR_ISO2SW) | BF_PGC_DISPLAY_PDNSCR_ISO2SW(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PGC_DISPLAY_SR - Power Gating Controller Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PGC_DISPLAY_SR - Power Gating Controller Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The PDNSCR contains the power-down timing parameters. See .
 */
typedef union _hw_pgc_display_sr
{
    reg32_t U;
    struct _hw_pgc_display_sr_bitfields
    {
        unsigned PSR : 1; //!< [0] Power status.
        unsigned RESERVED0 : 31; //!< [31:1] Reserved.
    } B;
} hw_pgc_display_sr_t;
#endif

/*
 * constants & macros for entire PGC_DISPLAY_SR register
 */
#define HW_PGC_DISPLAY_SR_ADDR      (REGS_PGC_BASE + 0x24c)

#ifndef __LANGUAGE_ASM__
#define HW_PGC_DISPLAY_SR           (*(volatile hw_pgc_display_sr_t *) HW_PGC_DISPLAY_SR_ADDR)
#define HW_PGC_DISPLAY_SR_RD()      (HW_PGC_DISPLAY_SR.U)
#define HW_PGC_DISPLAY_SR_WR(v)     (HW_PGC_DISPLAY_SR.U = (v))
#define HW_PGC_DISPLAY_SR_SET(v)    (HW_PGC_DISPLAY_SR_WR(HW_PGC_DISPLAY_SR_RD() |  (v)))
#define HW_PGC_DISPLAY_SR_CLR(v)    (HW_PGC_DISPLAY_SR_WR(HW_PGC_DISPLAY_SR_RD() & ~(v)))
#define HW_PGC_DISPLAY_SR_TOG(v)    (HW_PGC_DISPLAY_SR_WR(HW_PGC_DISPLAY_SR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PGC_DISPLAY_SR bitfields
 */

/* --- Register HW_PGC_DISPLAY_SR, field PSR[0] (RW)
 *
 * Power status. When in functional (or software-controlled debug) mode, PGC hardware sets PSR as
 * soon as any of the power control output changes its state to one. Write one to clear this bit.
 * Software should clear this bit after power up; otherwise, PSR continues to reflect the power
 * status of the initial power down.
 *
 * Values:
 * 0 - The target subsystem was not powered down for the previous power-down request.
 * 1 - The target subsystem was powered down for the previous power-down request.
 */

#define BP_PGC_DISPLAY_SR_PSR      (0)      //!< Bit position for PGC_DISPLAY_SR_PSR.
#define BM_PGC_DISPLAY_SR_PSR      (0x00000001)  //!< Bit mask for PGC_DISPLAY_SR_PSR.

//! @brief Get value of PGC_DISPLAY_SR_PSR from a register value.
#define BG_PGC_DISPLAY_SR_PSR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PGC_DISPLAY_SR_PSR) >> BP_PGC_DISPLAY_SR_PSR)

//! @brief Format value for bitfield PGC_DISPLAY_SR_PSR.
#define BF_PGC_DISPLAY_SR_PSR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PGC_DISPLAY_SR_PSR) & BM_PGC_DISPLAY_SR_PSR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PSR field to a new value.
#define BW_PGC_DISPLAY_SR_PSR(v)   (HW_PGC_DISPLAY_SR_WR((HW_PGC_DISPLAY_SR_RD() & ~BM_PGC_DISPLAY_SR_PSR) | BF_PGC_DISPLAY_SR_PSR(v)))
#endif


//-------------------------------------------------------------------------------------------
// HW_PGC_GPU_CTRL - PGC Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PGC_GPU_CTRL - PGC Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The PGCR enables the response to a power-down request.
 */
typedef union _hw_pgc_gpu_ctrl
{
    reg32_t U;
    struct _hw_pgc_gpu_ctrl_bitfields
    {
        unsigned PCR : 1; //!< [0] Power Control PCR must not change from power-down request (pdn_req) assertion until the target subsystem is completely powered up.
        unsigned RESERVED0 : 31; //!< [31:1] Reserved.
    } B;
} hw_pgc_gpu_ctrl_t;
#endif

/*
 * constants & macros for entire PGC_GPU_CTRL register
 */
#define HW_PGC_GPU_CTRL_ADDR      (REGS_PGC_BASE + 0x260)

#ifndef __LANGUAGE_ASM__
#define HW_PGC_GPU_CTRL           (*(volatile hw_pgc_gpu_ctrl_t *) HW_PGC_GPU_CTRL_ADDR)
#define HW_PGC_GPU_CTRL_RD()      (HW_PGC_GPU_CTRL.U)
#define HW_PGC_GPU_CTRL_WR(v)     (HW_PGC_GPU_CTRL.U = (v))
#define HW_PGC_GPU_CTRL_SET(v)    (HW_PGC_GPU_CTRL_WR(HW_PGC_GPU_CTRL_RD() |  (v)))
#define HW_PGC_GPU_CTRL_CLR(v)    (HW_PGC_GPU_CTRL_WR(HW_PGC_GPU_CTRL_RD() & ~(v)))
#define HW_PGC_GPU_CTRL_TOG(v)    (HW_PGC_GPU_CTRL_WR(HW_PGC_GPU_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PGC_GPU_CTRL bitfields
 */

/* --- Register HW_PGC_GPU_CTRL, field PCR[0] (RW)
 *
 * Power Control PCR must not change from power-down request (pdn_req) assertion until the target
 * subsystem is completely powered up.
 *
 * Values:
 * 0 - Do not switch off power even if pdn_req is asserted.
 * 1 - Switch off power when pdn_req is asserted.
 */

#define BP_PGC_GPU_CTRL_PCR      (0)      //!< Bit position for PGC_GPU_CTRL_PCR.
#define BM_PGC_GPU_CTRL_PCR      (0x00000001)  //!< Bit mask for PGC_GPU_CTRL_PCR.

//! @brief Get value of PGC_GPU_CTRL_PCR from a register value.
#define BG_PGC_GPU_CTRL_PCR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PGC_GPU_CTRL_PCR) >> BP_PGC_GPU_CTRL_PCR)

//! @brief Format value for bitfield PGC_GPU_CTRL_PCR.
#define BF_PGC_GPU_CTRL_PCR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PGC_GPU_CTRL_PCR) & BM_PGC_GPU_CTRL_PCR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PCR field to a new value.
#define BW_PGC_GPU_CTRL_PCR(v)   (HW_PGC_GPU_CTRL_WR((HW_PGC_GPU_CTRL_RD() & ~BM_PGC_GPU_CTRL_PCR) | BF_PGC_GPU_CTRL_PCR(v)))
#endif


//-------------------------------------------------------------------------------------------
// HW_PGC_GPU_PUPSCR - Power Up Sequence Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PGC_GPU_PUPSCR - Power Up Sequence Control Register (RW)
 *
 * Reset value: 0x00000f01
 *
 * The PUPSCR contains the power-up timing parameters. See .
 */
typedef union _hw_pgc_gpu_pupscr
{
    reg32_t U;
    struct _hw_pgc_gpu_pupscr_bitfields
    {
        unsigned SW : 6; //!< [5:0] After a power-up request (pup_req assertion), the PGC waits a number of clocks equal to the value of SW before asserting switch_b.
        unsigned RESERVED0 : 2; //!< [7:6] Reserved.
        unsigned SW2ISO : 6; //!< [13:8] After asserting switch_b, the PGC waits a number of clocks equal to the value of SW2ISO before negating isolation.
        unsigned RESERVED1 : 18; //!< [31:14] Reserved.
    } B;
} hw_pgc_gpu_pupscr_t;
#endif

/*
 * constants & macros for entire PGC_GPU_PUPSCR register
 */
#define HW_PGC_GPU_PUPSCR_ADDR      (REGS_PGC_BASE + 0x264)

#ifndef __LANGUAGE_ASM__
#define HW_PGC_GPU_PUPSCR           (*(volatile hw_pgc_gpu_pupscr_t *) HW_PGC_GPU_PUPSCR_ADDR)
#define HW_PGC_GPU_PUPSCR_RD()      (HW_PGC_GPU_PUPSCR.U)
#define HW_PGC_GPU_PUPSCR_WR(v)     (HW_PGC_GPU_PUPSCR.U = (v))
#define HW_PGC_GPU_PUPSCR_SET(v)    (HW_PGC_GPU_PUPSCR_WR(HW_PGC_GPU_PUPSCR_RD() |  (v)))
#define HW_PGC_GPU_PUPSCR_CLR(v)    (HW_PGC_GPU_PUPSCR_WR(HW_PGC_GPU_PUPSCR_RD() & ~(v)))
#define HW_PGC_GPU_PUPSCR_TOG(v)    (HW_PGC_GPU_PUPSCR_WR(HW_PGC_GPU_PUPSCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PGC_GPU_PUPSCR bitfields
 */

/* --- Register HW_PGC_GPU_PUPSCR, field SW[5:0] (RW)
 *
 * After a power-up request (pup_req assertion), the PGC waits a number of clocks equal to the value
 * of SW before asserting switch_b. SW must not be programmed to zero. The PGC clock is generated
 * from the IPG_CLK_ROOT. for frequency configuration of the IPG_CLK_ROOT, see CCM chapter.
 */

#define BP_PGC_GPU_PUPSCR_SW      (0)      //!< Bit position for PGC_GPU_PUPSCR_SW.
#define BM_PGC_GPU_PUPSCR_SW      (0x0000003f)  //!< Bit mask for PGC_GPU_PUPSCR_SW.

//! @brief Get value of PGC_GPU_PUPSCR_SW from a register value.
#define BG_PGC_GPU_PUPSCR_SW(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PGC_GPU_PUPSCR_SW) >> BP_PGC_GPU_PUPSCR_SW)

//! @brief Format value for bitfield PGC_GPU_PUPSCR_SW.
#define BF_PGC_GPU_PUPSCR_SW(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PGC_GPU_PUPSCR_SW) & BM_PGC_GPU_PUPSCR_SW)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SW field to a new value.
#define BW_PGC_GPU_PUPSCR_SW(v)   (HW_PGC_GPU_PUPSCR_WR((HW_PGC_GPU_PUPSCR_RD() & ~BM_PGC_GPU_PUPSCR_SW) | BF_PGC_GPU_PUPSCR_SW(v)))
#endif

/* --- Register HW_PGC_GPU_PUPSCR, field SW2ISO[13:8] (RW)
 *
 * After asserting switch_b, the PGC waits a number of clocks equal to the value of SW2ISO before
 * negating isolation. SW2ISO must not be programmed to zero.
 */

#define BP_PGC_GPU_PUPSCR_SW2ISO      (8)      //!< Bit position for PGC_GPU_PUPSCR_SW2ISO.
#define BM_PGC_GPU_PUPSCR_SW2ISO      (0x00003f00)  //!< Bit mask for PGC_GPU_PUPSCR_SW2ISO.

//! @brief Get value of PGC_GPU_PUPSCR_SW2ISO from a register value.
#define BG_PGC_GPU_PUPSCR_SW2ISO(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PGC_GPU_PUPSCR_SW2ISO) >> BP_PGC_GPU_PUPSCR_SW2ISO)

//! @brief Format value for bitfield PGC_GPU_PUPSCR_SW2ISO.
#define BF_PGC_GPU_PUPSCR_SW2ISO(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PGC_GPU_PUPSCR_SW2ISO) & BM_PGC_GPU_PUPSCR_SW2ISO)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SW2ISO field to a new value.
#define BW_PGC_GPU_PUPSCR_SW2ISO(v)   (HW_PGC_GPU_PUPSCR_WR((HW_PGC_GPU_PUPSCR_RD() & ~BM_PGC_GPU_PUPSCR_SW2ISO) | BF_PGC_GPU_PUPSCR_SW2ISO(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PGC_GPU_PDNSCR - Pull Down Sequence Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PGC_GPU_PDNSCR - Pull Down Sequence Control Register (RW)
 *
 * Reset value: 0x00000101
 *
 * The PDNSCR contains the power-down timing parameters. See .
 */
typedef union _hw_pgc_gpu_pdnscr
{
    reg32_t U;
    struct _hw_pgc_gpu_pdnscr_bitfields
    {
        unsigned ISO : 6; //!< [5:0] After a power-down request (pdn_req assertion), the PGC waits a number of clocks equal to the value of ISO before asserting isolation.
        unsigned RESERVED0 : 2; //!< [7:6] Reserved.
        unsigned ISO2SW : 6; //!< [13:8] After asserting isolation, the PGC waits a number of clocks equal to the value of ISO2SW before negating switch_b.
        unsigned RESERVED1 : 18; //!< [31:14] Reserved.
    } B;
} hw_pgc_gpu_pdnscr_t;
#endif

/*
 * constants & macros for entire PGC_GPU_PDNSCR register
 */
#define HW_PGC_GPU_PDNSCR_ADDR      (REGS_PGC_BASE + 0x268)

#ifndef __LANGUAGE_ASM__
#define HW_PGC_GPU_PDNSCR           (*(volatile hw_pgc_gpu_pdnscr_t *) HW_PGC_GPU_PDNSCR_ADDR)
#define HW_PGC_GPU_PDNSCR_RD()      (HW_PGC_GPU_PDNSCR.U)
#define HW_PGC_GPU_PDNSCR_WR(v)     (HW_PGC_GPU_PDNSCR.U = (v))
#define HW_PGC_GPU_PDNSCR_SET(v)    (HW_PGC_GPU_PDNSCR_WR(HW_PGC_GPU_PDNSCR_RD() |  (v)))
#define HW_PGC_GPU_PDNSCR_CLR(v)    (HW_PGC_GPU_PDNSCR_WR(HW_PGC_GPU_PDNSCR_RD() & ~(v)))
#define HW_PGC_GPU_PDNSCR_TOG(v)    (HW_PGC_GPU_PDNSCR_WR(HW_PGC_GPU_PDNSCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PGC_GPU_PDNSCR bitfields
 */

/* --- Register HW_PGC_GPU_PDNSCR, field ISO[5:0] (RW)
 *
 * After a power-down request (pdn_req assertion), the PGC waits a number of clocks equal to the
 * value of ISO before asserting isolation. ISO must not be programmed to zero.
 */

#define BP_PGC_GPU_PDNSCR_ISO      (0)      //!< Bit position for PGC_GPU_PDNSCR_ISO.
#define BM_PGC_GPU_PDNSCR_ISO      (0x0000003f)  //!< Bit mask for PGC_GPU_PDNSCR_ISO.

//! @brief Get value of PGC_GPU_PDNSCR_ISO from a register value.
#define BG_PGC_GPU_PDNSCR_ISO(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PGC_GPU_PDNSCR_ISO) >> BP_PGC_GPU_PDNSCR_ISO)

//! @brief Format value for bitfield PGC_GPU_PDNSCR_ISO.
#define BF_PGC_GPU_PDNSCR_ISO(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PGC_GPU_PDNSCR_ISO) & BM_PGC_GPU_PDNSCR_ISO)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ISO field to a new value.
#define BW_PGC_GPU_PDNSCR_ISO(v)   (HW_PGC_GPU_PDNSCR_WR((HW_PGC_GPU_PDNSCR_RD() & ~BM_PGC_GPU_PDNSCR_ISO) | BF_PGC_GPU_PDNSCR_ISO(v)))
#endif

/* --- Register HW_PGC_GPU_PDNSCR, field ISO2SW[13:8] (RW)
 *
 * After asserting isolation, the PGC waits a number of clocks equal to the value of ISO2SW before
 * negating switch_b. ISO2SW must not be programmed to zero.
 */

#define BP_PGC_GPU_PDNSCR_ISO2SW      (8)      //!< Bit position for PGC_GPU_PDNSCR_ISO2SW.
#define BM_PGC_GPU_PDNSCR_ISO2SW      (0x00003f00)  //!< Bit mask for PGC_GPU_PDNSCR_ISO2SW.

//! @brief Get value of PGC_GPU_PDNSCR_ISO2SW from a register value.
#define BG_PGC_GPU_PDNSCR_ISO2SW(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PGC_GPU_PDNSCR_ISO2SW) >> BP_PGC_GPU_PDNSCR_ISO2SW)

//! @brief Format value for bitfield PGC_GPU_PDNSCR_ISO2SW.
#define BF_PGC_GPU_PDNSCR_ISO2SW(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PGC_GPU_PDNSCR_ISO2SW) & BM_PGC_GPU_PDNSCR_ISO2SW)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ISO2SW field to a new value.
#define BW_PGC_GPU_PDNSCR_ISO2SW(v)   (HW_PGC_GPU_PDNSCR_WR((HW_PGC_GPU_PDNSCR_RD() & ~BM_PGC_GPU_PDNSCR_ISO2SW) | BF_PGC_GPU_PDNSCR_ISO2SW(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PGC_GPU_SR - Power Gating Controller Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PGC_GPU_SR - Power Gating Controller Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The PDNSCR contains the power-down timing parameters. See .
 */
typedef union _hw_pgc_gpu_sr
{
    reg32_t U;
    struct _hw_pgc_gpu_sr_bitfields
    {
        unsigned PSR : 1; //!< [0] Power status.
        unsigned RESERVED0 : 31; //!< [31:1] Reserved.
    } B;
} hw_pgc_gpu_sr_t;
#endif

/*
 * constants & macros for entire PGC_GPU_SR register
 */
#define HW_PGC_GPU_SR_ADDR      (REGS_PGC_BASE + 0x26c)

#ifndef __LANGUAGE_ASM__
#define HW_PGC_GPU_SR           (*(volatile hw_pgc_gpu_sr_t *) HW_PGC_GPU_SR_ADDR)
#define HW_PGC_GPU_SR_RD()      (HW_PGC_GPU_SR.U)
#define HW_PGC_GPU_SR_WR(v)     (HW_PGC_GPU_SR.U = (v))
#define HW_PGC_GPU_SR_SET(v)    (HW_PGC_GPU_SR_WR(HW_PGC_GPU_SR_RD() |  (v)))
#define HW_PGC_GPU_SR_CLR(v)    (HW_PGC_GPU_SR_WR(HW_PGC_GPU_SR_RD() & ~(v)))
#define HW_PGC_GPU_SR_TOG(v)    (HW_PGC_GPU_SR_WR(HW_PGC_GPU_SR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PGC_GPU_SR bitfields
 */

/* --- Register HW_PGC_GPU_SR, field PSR[0] (RW)
 *
 * Power status. When in functional (or software-controlled debug) mode, PGC hardware sets PSR as
 * soon as any of the power control output changes its state to one. Write one to clear this bit.
 * Software should clear this bit after power up; otherwise, PSR continues to reflect the power
 * status of the initial power down.
 *
 * Values:
 * 0 - The target subsystem was not powered down for the previous power-down request.
 * 1 - The target subsystem was powered down for the previous power-down request.
 */

#define BP_PGC_GPU_SR_PSR      (0)      //!< Bit position for PGC_GPU_SR_PSR.
#define BM_PGC_GPU_SR_PSR      (0x00000001)  //!< Bit mask for PGC_GPU_SR_PSR.

//! @brief Get value of PGC_GPU_SR_PSR from a register value.
#define BG_PGC_GPU_SR_PSR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PGC_GPU_SR_PSR) >> BP_PGC_GPU_SR_PSR)

//! @brief Format value for bitfield PGC_GPU_SR_PSR.
#define BF_PGC_GPU_SR_PSR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PGC_GPU_SR_PSR) & BM_PGC_GPU_SR_PSR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PSR field to a new value.
#define BW_PGC_GPU_SR_PSR(v)   (HW_PGC_GPU_SR_WR((HW_PGC_GPU_SR_RD() & ~BM_PGC_GPU_SR_PSR) | BF_PGC_GPU_SR_PSR(v)))
#endif


//-------------------------------------------------------------------------------------------
// HW_PGC_CPU_CTRL - PGC Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PGC_CPU_CTRL - PGC Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The PGCR enables the response to a power-down request.
 */
typedef union _hw_pgc_cpu_ctrl
{
    reg32_t U;
    struct _hw_pgc_cpu_ctrl_bitfields
    {
        unsigned PCR : 1; //!< [0] Power Control PCR must not change from power-down request (pdn_req) assertion until the target subsystem is completely powered up.
        unsigned RESERVED0 : 31; //!< [31:1] Reserved.
    } B;
} hw_pgc_cpu_ctrl_t;
#endif

/*
 * constants & macros for entire PGC_CPU_CTRL register
 */
#define HW_PGC_CPU_CTRL_ADDR      (REGS_PGC_BASE + 0x2a0)

#ifndef __LANGUAGE_ASM__
#define HW_PGC_CPU_CTRL           (*(volatile hw_pgc_cpu_ctrl_t *) HW_PGC_CPU_CTRL_ADDR)
#define HW_PGC_CPU_CTRL_RD()      (HW_PGC_CPU_CTRL.U)
#define HW_PGC_CPU_CTRL_WR(v)     (HW_PGC_CPU_CTRL.U = (v))
#define HW_PGC_CPU_CTRL_SET(v)    (HW_PGC_CPU_CTRL_WR(HW_PGC_CPU_CTRL_RD() |  (v)))
#define HW_PGC_CPU_CTRL_CLR(v)    (HW_PGC_CPU_CTRL_WR(HW_PGC_CPU_CTRL_RD() & ~(v)))
#define HW_PGC_CPU_CTRL_TOG(v)    (HW_PGC_CPU_CTRL_WR(HW_PGC_CPU_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PGC_CPU_CTRL bitfields
 */

/* --- Register HW_PGC_CPU_CTRL, field PCR[0] (RW)
 *
 * Power Control PCR must not change from power-down request (pdn_req) assertion until the target
 * subsystem is completely powered up.
 *
 * Values:
 * 0 - Do not switch off power even if pdn_req is asserted.
 * 1 - Switch off power when pdn_req is asserted.
 */

#define BP_PGC_CPU_CTRL_PCR      (0)      //!< Bit position for PGC_CPU_CTRL_PCR.
#define BM_PGC_CPU_CTRL_PCR      (0x00000001)  //!< Bit mask for PGC_CPU_CTRL_PCR.

//! @brief Get value of PGC_CPU_CTRL_PCR from a register value.
#define BG_PGC_CPU_CTRL_PCR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PGC_CPU_CTRL_PCR) >> BP_PGC_CPU_CTRL_PCR)

//! @brief Format value for bitfield PGC_CPU_CTRL_PCR.
#define BF_PGC_CPU_CTRL_PCR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PGC_CPU_CTRL_PCR) & BM_PGC_CPU_CTRL_PCR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PCR field to a new value.
#define BW_PGC_CPU_CTRL_PCR(v)   (HW_PGC_CPU_CTRL_WR((HW_PGC_CPU_CTRL_RD() & ~BM_PGC_CPU_CTRL_PCR) | BF_PGC_CPU_CTRL_PCR(v)))
#endif


//-------------------------------------------------------------------------------------------
// HW_PGC_CPU_PUPSCR - Power Up Sequence Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PGC_CPU_PUPSCR - Power Up Sequence Control Register (RW)
 *
 * Reset value: 0x00000f01
 *
 * The PUPSCR contains the power-up timing parameters. See .
 */
typedef union _hw_pgc_cpu_pupscr
{
    reg32_t U;
    struct _hw_pgc_cpu_pupscr_bitfields
    {
        unsigned SW : 6; //!< [5:0] After a power-up request (pup_req assertion), the PGC waits a number of clocks equal to the value of SW before asserting switch_b.
        unsigned RESERVED0 : 2; //!< [7:6] Reserved.
        unsigned SW2ISO : 6; //!< [13:8] After asserting switch_b, the PGC waits a number of clocks equal to the value of SW2ISO before negating isolation.
        unsigned RESERVED1 : 18; //!< [31:14] Reserved.
    } B;
} hw_pgc_cpu_pupscr_t;
#endif

/*
 * constants & macros for entire PGC_CPU_PUPSCR register
 */
#define HW_PGC_CPU_PUPSCR_ADDR      (REGS_PGC_BASE + 0x2a4)

#ifndef __LANGUAGE_ASM__
#define HW_PGC_CPU_PUPSCR           (*(volatile hw_pgc_cpu_pupscr_t *) HW_PGC_CPU_PUPSCR_ADDR)
#define HW_PGC_CPU_PUPSCR_RD()      (HW_PGC_CPU_PUPSCR.U)
#define HW_PGC_CPU_PUPSCR_WR(v)     (HW_PGC_CPU_PUPSCR.U = (v))
#define HW_PGC_CPU_PUPSCR_SET(v)    (HW_PGC_CPU_PUPSCR_WR(HW_PGC_CPU_PUPSCR_RD() |  (v)))
#define HW_PGC_CPU_PUPSCR_CLR(v)    (HW_PGC_CPU_PUPSCR_WR(HW_PGC_CPU_PUPSCR_RD() & ~(v)))
#define HW_PGC_CPU_PUPSCR_TOG(v)    (HW_PGC_CPU_PUPSCR_WR(HW_PGC_CPU_PUPSCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PGC_CPU_PUPSCR bitfields
 */

/* --- Register HW_PGC_CPU_PUPSCR, field SW[5:0] (RW)
 *
 * After a power-up request (pup_req assertion), the PGC waits a number of clocks equal to the value
 * of SW before asserting switch_b. SW must not be programmed to zero. The PGC clock is generated
 * from the IPG_CLK_ROOT. for frequency configuration of the IPG_CLK_ROOT, see CCM chapter.
 */

#define BP_PGC_CPU_PUPSCR_SW      (0)      //!< Bit position for PGC_CPU_PUPSCR_SW.
#define BM_PGC_CPU_PUPSCR_SW      (0x0000003f)  //!< Bit mask for PGC_CPU_PUPSCR_SW.

//! @brief Get value of PGC_CPU_PUPSCR_SW from a register value.
#define BG_PGC_CPU_PUPSCR_SW(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PGC_CPU_PUPSCR_SW) >> BP_PGC_CPU_PUPSCR_SW)

//! @brief Format value for bitfield PGC_CPU_PUPSCR_SW.
#define BF_PGC_CPU_PUPSCR_SW(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PGC_CPU_PUPSCR_SW) & BM_PGC_CPU_PUPSCR_SW)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SW field to a new value.
#define BW_PGC_CPU_PUPSCR_SW(v)   (HW_PGC_CPU_PUPSCR_WR((HW_PGC_CPU_PUPSCR_RD() & ~BM_PGC_CPU_PUPSCR_SW) | BF_PGC_CPU_PUPSCR_SW(v)))
#endif

/* --- Register HW_PGC_CPU_PUPSCR, field SW2ISO[13:8] (RW)
 *
 * After asserting switch_b, the PGC waits a number of clocks equal to the value of SW2ISO before
 * negating isolation. SW2ISO must not be programmed to zero.
 */

#define BP_PGC_CPU_PUPSCR_SW2ISO      (8)      //!< Bit position for PGC_CPU_PUPSCR_SW2ISO.
#define BM_PGC_CPU_PUPSCR_SW2ISO      (0x00003f00)  //!< Bit mask for PGC_CPU_PUPSCR_SW2ISO.

//! @brief Get value of PGC_CPU_PUPSCR_SW2ISO from a register value.
#define BG_PGC_CPU_PUPSCR_SW2ISO(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PGC_CPU_PUPSCR_SW2ISO) >> BP_PGC_CPU_PUPSCR_SW2ISO)

//! @brief Format value for bitfield PGC_CPU_PUPSCR_SW2ISO.
#define BF_PGC_CPU_PUPSCR_SW2ISO(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PGC_CPU_PUPSCR_SW2ISO) & BM_PGC_CPU_PUPSCR_SW2ISO)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SW2ISO field to a new value.
#define BW_PGC_CPU_PUPSCR_SW2ISO(v)   (HW_PGC_CPU_PUPSCR_WR((HW_PGC_CPU_PUPSCR_RD() & ~BM_PGC_CPU_PUPSCR_SW2ISO) | BF_PGC_CPU_PUPSCR_SW2ISO(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PGC_CPU_PDNSCR - Pull Down Sequence Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PGC_CPU_PDNSCR - Pull Down Sequence Control Register (RW)
 *
 * Reset value: 0x00000101
 *
 * The PDNSCR contains the power-down timing parameters. See .
 */
typedef union _hw_pgc_cpu_pdnscr
{
    reg32_t U;
    struct _hw_pgc_cpu_pdnscr_bitfields
    {
        unsigned ISO : 6; //!< [5:0] After a power-down request (pdn_req assertion), the PGC waits a number of clocks equal to the value of ISO before asserting isolation.
        unsigned RESERVED0 : 2; //!< [7:6] Reserved.
        unsigned ISO2SW : 6; //!< [13:8] After asserting isolation, the PGC waits a number of clocks equal to the value of ISO2SW before negating switch_b.
        unsigned RESERVED1 : 18; //!< [31:14] Reserved.
    } B;
} hw_pgc_cpu_pdnscr_t;
#endif

/*
 * constants & macros for entire PGC_CPU_PDNSCR register
 */
#define HW_PGC_CPU_PDNSCR_ADDR      (REGS_PGC_BASE + 0x2a8)

#ifndef __LANGUAGE_ASM__
#define HW_PGC_CPU_PDNSCR           (*(volatile hw_pgc_cpu_pdnscr_t *) HW_PGC_CPU_PDNSCR_ADDR)
#define HW_PGC_CPU_PDNSCR_RD()      (HW_PGC_CPU_PDNSCR.U)
#define HW_PGC_CPU_PDNSCR_WR(v)     (HW_PGC_CPU_PDNSCR.U = (v))
#define HW_PGC_CPU_PDNSCR_SET(v)    (HW_PGC_CPU_PDNSCR_WR(HW_PGC_CPU_PDNSCR_RD() |  (v)))
#define HW_PGC_CPU_PDNSCR_CLR(v)    (HW_PGC_CPU_PDNSCR_WR(HW_PGC_CPU_PDNSCR_RD() & ~(v)))
#define HW_PGC_CPU_PDNSCR_TOG(v)    (HW_PGC_CPU_PDNSCR_WR(HW_PGC_CPU_PDNSCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PGC_CPU_PDNSCR bitfields
 */

/* --- Register HW_PGC_CPU_PDNSCR, field ISO[5:0] (RW)
 *
 * After a power-down request (pdn_req assertion), the PGC waits a number of clocks equal to the
 * value of ISO before asserting isolation. ISO must not be programmed to zero.
 */

#define BP_PGC_CPU_PDNSCR_ISO      (0)      //!< Bit position for PGC_CPU_PDNSCR_ISO.
#define BM_PGC_CPU_PDNSCR_ISO      (0x0000003f)  //!< Bit mask for PGC_CPU_PDNSCR_ISO.

//! @brief Get value of PGC_CPU_PDNSCR_ISO from a register value.
#define BG_PGC_CPU_PDNSCR_ISO(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PGC_CPU_PDNSCR_ISO) >> BP_PGC_CPU_PDNSCR_ISO)

//! @brief Format value for bitfield PGC_CPU_PDNSCR_ISO.
#define BF_PGC_CPU_PDNSCR_ISO(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PGC_CPU_PDNSCR_ISO) & BM_PGC_CPU_PDNSCR_ISO)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ISO field to a new value.
#define BW_PGC_CPU_PDNSCR_ISO(v)   (HW_PGC_CPU_PDNSCR_WR((HW_PGC_CPU_PDNSCR_RD() & ~BM_PGC_CPU_PDNSCR_ISO) | BF_PGC_CPU_PDNSCR_ISO(v)))
#endif

/* --- Register HW_PGC_CPU_PDNSCR, field ISO2SW[13:8] (RW)
 *
 * After asserting isolation, the PGC waits a number of clocks equal to the value of ISO2SW before
 * negating switch_b. ISO2SW must not be programmed to zero.
 */

#define BP_PGC_CPU_PDNSCR_ISO2SW      (8)      //!< Bit position for PGC_CPU_PDNSCR_ISO2SW.
#define BM_PGC_CPU_PDNSCR_ISO2SW      (0x00003f00)  //!< Bit mask for PGC_CPU_PDNSCR_ISO2SW.

//! @brief Get value of PGC_CPU_PDNSCR_ISO2SW from a register value.
#define BG_PGC_CPU_PDNSCR_ISO2SW(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PGC_CPU_PDNSCR_ISO2SW) >> BP_PGC_CPU_PDNSCR_ISO2SW)

//! @brief Format value for bitfield PGC_CPU_PDNSCR_ISO2SW.
#define BF_PGC_CPU_PDNSCR_ISO2SW(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PGC_CPU_PDNSCR_ISO2SW) & BM_PGC_CPU_PDNSCR_ISO2SW)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ISO2SW field to a new value.
#define BW_PGC_CPU_PDNSCR_ISO2SW(v)   (HW_PGC_CPU_PDNSCR_WR((HW_PGC_CPU_PDNSCR_RD() & ~BM_PGC_CPU_PDNSCR_ISO2SW) | BF_PGC_CPU_PDNSCR_ISO2SW(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_PGC_CPU_SR - Power Gating Controller Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PGC_CPU_SR - Power Gating Controller Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The PDNSCR contains the power-down timing parameters. See .
 */
typedef union _hw_pgc_cpu_sr
{
    reg32_t U;
    struct _hw_pgc_cpu_sr_bitfields
    {
        unsigned PSR : 1; //!< [0] Power status.
        unsigned RESERVED0 : 31; //!< [31:1] Reserved.
    } B;
} hw_pgc_cpu_sr_t;
#endif

/*
 * constants & macros for entire PGC_CPU_SR register
 */
#define HW_PGC_CPU_SR_ADDR      (REGS_PGC_BASE + 0x2ac)

#ifndef __LANGUAGE_ASM__
#define HW_PGC_CPU_SR           (*(volatile hw_pgc_cpu_sr_t *) HW_PGC_CPU_SR_ADDR)
#define HW_PGC_CPU_SR_RD()      (HW_PGC_CPU_SR.U)
#define HW_PGC_CPU_SR_WR(v)     (HW_PGC_CPU_SR.U = (v))
#define HW_PGC_CPU_SR_SET(v)    (HW_PGC_CPU_SR_WR(HW_PGC_CPU_SR_RD() |  (v)))
#define HW_PGC_CPU_SR_CLR(v)    (HW_PGC_CPU_SR_WR(HW_PGC_CPU_SR_RD() & ~(v)))
#define HW_PGC_CPU_SR_TOG(v)    (HW_PGC_CPU_SR_WR(HW_PGC_CPU_SR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual PGC_CPU_SR bitfields
 */

/* --- Register HW_PGC_CPU_SR, field PSR[0] (RW)
 *
 * Power status. When in functional (or software-controlled debug) mode, PGC hardware sets PSR as
 * soon as any of the power control output changes its state to one. Write one to clear this bit.
 * Software should clear this bit after power up; otherwise, PSR continues to reflect the power
 * status of the initial power down.
 *
 * Values:
 * 0 - The target subsystem was not powered down for the previous power-down request.
 * 1 - The target subsystem was powered down for the previous power-down request.
 */

#define BP_PGC_CPU_SR_PSR      (0)      //!< Bit position for PGC_CPU_SR_PSR.
#define BM_PGC_CPU_SR_PSR      (0x00000001)  //!< Bit mask for PGC_CPU_SR_PSR.

//! @brief Get value of PGC_CPU_SR_PSR from a register value.
#define BG_PGC_CPU_SR_PSR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_PGC_CPU_SR_PSR) >> BP_PGC_CPU_SR_PSR)

//! @brief Format value for bitfield PGC_CPU_SR_PSR.
#define BF_PGC_CPU_SR_PSR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_PGC_CPU_SR_PSR) & BM_PGC_CPU_SR_PSR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PSR field to a new value.
#define BW_PGC_CPU_SR_PSR(v)   (HW_PGC_CPU_SR_WR((HW_PGC_CPU_SR_RD() & ~BM_PGC_CPU_SR_PSR) | BF_PGC_CPU_SR_PSR(v)))
#endif



/*!
 * @brief All PGC module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_pgc
{
    reg32_t _reserved0[144];
    volatile hw_pgc_display_ctrl_t DISPLAY_CTRL; //!< PGC Control Register
    volatile hw_pgc_display_pupscr_t DISPLAY_PUPSCR; //!< Power Up Sequence Control Register
    volatile hw_pgc_display_pdnscr_t DISPLAY_PDNSCR; //!< Pull Down Sequence Control Register
    volatile hw_pgc_display_sr_t DISPLAY_SR; //!< Power Gating Controller Status Register
    reg32_t _reserved1[4];
    volatile hw_pgc_gpu_ctrl_t GPU_CTRL; //!< PGC Control Register
    volatile hw_pgc_gpu_pupscr_t GPU_PUPSCR; //!< Power Up Sequence Control Register
    volatile hw_pgc_gpu_pdnscr_t GPU_PDNSCR; //!< Pull Down Sequence Control Register
    volatile hw_pgc_gpu_sr_t GPU_SR; //!< Power Gating Controller Status Register
    reg32_t _reserved2[12];
    volatile hw_pgc_cpu_ctrl_t CPU_CTRL; //!< PGC Control Register
    volatile hw_pgc_cpu_pupscr_t CPU_PUPSCR; //!< Power Up Sequence Control Register
    volatile hw_pgc_cpu_pdnscr_t CPU_PDNSCR; //!< Pull Down Sequence Control Register
    volatile hw_pgc_cpu_sr_t CPU_SR; //!< Power Gating Controller Status Register
} hw_pgc_t;
#pragma pack()

//! @brief Macro to access all PGC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_PGC(0)</code>.
#define HW_PGC     (*(volatile hw_pgc_t *) REGS_PGC_BASE)

#endif


#endif // __HW_PGC_REGISTERS_H__