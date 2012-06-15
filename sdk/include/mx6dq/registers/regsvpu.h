/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_VPU_REGISTERS_H__
#define __HW_VPU_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6DQ VPU registers defined in this header file.
 *
 * - HW_VPU_CODERUN - BIT Processor run start
 * - HW_VPU_CODEDOWN - BIT Boot Code Download Data register
 * - HW_VPU_HOSTINTREQ - Host Interrupt Request to BIT
 * - HW_VPU_BITINTCLEAR - BIT Interrupt Clear
 * - HW_VPU_BITINTSTS - BIT Interrupt Status
 * - HW_VPU_BITCURPC - BIT Current PC
 * - HW_VPU_BITCODECBUSY - BIT CODEC Busy
 *
 * - hw_vpu_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_VPU_BASE
#define HW_VPU_INSTANCE_COUNT (1) //!< Number of instances of the VPU module.
#define REGS_VPU_BASE (0x02040000) //!< Base address for VPU.
#endif
//@}


//-------------------------------------------------------------------------------------------
// HW_VPU_CODERUN - BIT Processor run start
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VPU_CODERUN - BIT Processor run start (WO)
 *
 * Reset value: 0x00000000
 *
 * See the figure below for illustration of valid bits in VPU Code Run Register and the table below
 * for description of the bit fields in the register.
 */
typedef union _hw_vpu_coderun
{
    reg32_t U;
    struct _hw_vpu_coderun_bitfields
    {
        unsigned VPU_CODERUN : 1; //!< [0] VPU_CodeRun.
        unsigned RESERVED0 : 31; //!< [31:1] Reserved
    } B;
} hw_vpu_coderun_t;
#endif

/*
 * constants & macros for entire VPU_CODERUN register
 */
#define HW_VPU_CODERUN_ADDR      (REGS_VPU_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_VPU_CODERUN           (*(volatile hw_vpu_coderun_t *) HW_VPU_CODERUN_ADDR)
#define HW_VPU_CODERUN_WR(v)     (HW_VPU_CODERUN.U = (v))
#endif

/*
 * constants & macros for individual VPU_CODERUN bitfields
 */

/* --- Register HW_VPU_CODERUN, field VPU_CODERUN[0] (WO)
 *
 * VPU_CodeRun. BIT processor run start bit.
 *
 * Values:
 * 0 - BIT Processor stop execution.
 * 1 - BIT Processor start execution.
 */

#define BP_VPU_CODERUN_VPU_CODERUN      (0)      //!< Bit position for VPU_CODERUN_VPU_CODERUN.
#define BM_VPU_CODERUN_VPU_CODERUN      (0x00000001)  //!< Bit mask for VPU_CODERUN_VPU_CODERUN.

//! @brief Get value of VPU_CODERUN_VPU_CODERUN from a register value.
#define BG_VPU_CODERUN_VPU_CODERUN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_VPU_CODERUN_VPU_CODERUN) >> BP_VPU_CODERUN_VPU_CODERUN)

//! @brief Format value for bitfield VPU_CODERUN_VPU_CODERUN.
#define BF_VPU_CODERUN_VPU_CODERUN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_VPU_CODERUN_VPU_CODERUN) & BM_VPU_CODERUN_VPU_CODERUN)


//-------------------------------------------------------------------------------------------
// HW_VPU_CODEDOWN - BIT Boot Code Download Data register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VPU_CODEDOWN - BIT Boot Code Download Data register (WO)
 *
 * Reset value: 0x00000000
 *
 * See the figure below for illustration of valid bits in VPU BIT Boot Code Download Data Register
 * and the following table for description of the bit fields in the register.
 */
typedef union _hw_vpu_codedown
{
    reg32_t U;
    struct _hw_vpu_codedown_bitfields
    {
        unsigned CODEDATA : 16; //!< [15:0] CodeData[15:0] Download data of VPU BIT boot code.
        unsigned CODEADDR : 13; //!< [28:16] CodeAddr[12:0] Download address of VPU BIT boot code, which is VPU internal address of BIT processor.
        unsigned RESERVED0 : 3; //!< [31:29] Reserved
    } B;
} hw_vpu_codedown_t;
#endif

/*
 * constants & macros for entire VPU_CODEDOWN register
 */
#define HW_VPU_CODEDOWN_ADDR      (REGS_VPU_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_VPU_CODEDOWN           (*(volatile hw_vpu_codedown_t *) HW_VPU_CODEDOWN_ADDR)
#define HW_VPU_CODEDOWN_WR(v)     (HW_VPU_CODEDOWN.U = (v))
#endif

/*
 * constants & macros for individual VPU_CODEDOWN bitfields
 */

/* --- Register HW_VPU_CODEDOWN, field CODEDATA[15:0] (WO)
 *
 * CodeData[15:0] Download data of VPU BIT boot code.
 */

#define BP_VPU_CODEDOWN_CODEDATA      (0)      //!< Bit position for VPU_CODEDOWN_CODEDATA.
#define BM_VPU_CODEDOWN_CODEDATA      (0x0000ffff)  //!< Bit mask for VPU_CODEDOWN_CODEDATA.

//! @brief Get value of VPU_CODEDOWN_CODEDATA from a register value.
#define BG_VPU_CODEDOWN_CODEDATA(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_VPU_CODEDOWN_CODEDATA) >> BP_VPU_CODEDOWN_CODEDATA)

//! @brief Format value for bitfield VPU_CODEDOWN_CODEDATA.
#define BF_VPU_CODEDOWN_CODEDATA(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_VPU_CODEDOWN_CODEDATA) & BM_VPU_CODEDOWN_CODEDATA)

/* --- Register HW_VPU_CODEDOWN, field CODEADDR[28:16] (WO)
 *
 * CodeAddr[12:0] Download address of VPU BIT boot code, which is VPU internal address of BIT
 * processor.
 */

#define BP_VPU_CODEDOWN_CODEADDR      (16)      //!< Bit position for VPU_CODEDOWN_CODEADDR.
#define BM_VPU_CODEDOWN_CODEADDR      (0x1fff0000)  //!< Bit mask for VPU_CODEDOWN_CODEADDR.

//! @brief Get value of VPU_CODEDOWN_CODEADDR from a register value.
#define BG_VPU_CODEDOWN_CODEADDR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_VPU_CODEDOWN_CODEADDR) >> BP_VPU_CODEDOWN_CODEADDR)

//! @brief Format value for bitfield VPU_CODEDOWN_CODEADDR.
#define BF_VPU_CODEDOWN_CODEADDR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_VPU_CODEDOWN_CODEADDR) & BM_VPU_CODEDOWN_CODEADDR)

//-------------------------------------------------------------------------------------------
// HW_VPU_HOSTINTREQ - Host Interrupt Request to BIT
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VPU_HOSTINTREQ - Host Interrupt Request to BIT (WO)
 *
 * Reset value: 0x00000000
 *
 * See the figure below for illustration of valid bits in VPU Host Interrupt Request Register and
 * the following table for description of the bit fields in the register.
 */
typedef union _hw_vpu_hostintreq
{
    reg32_t U;
    struct _hw_vpu_hostintreq_bitfields
    {
        unsigned INTREQ : 1; //!< [0] IntReq.
        unsigned RESERVED0 : 31; //!< [31:1] Reserved
    } B;
} hw_vpu_hostintreq_t;
#endif

/*
 * constants & macros for entire VPU_HOSTINTREQ register
 */
#define HW_VPU_HOSTINTREQ_ADDR      (REGS_VPU_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_VPU_HOSTINTREQ           (*(volatile hw_vpu_hostintreq_t *) HW_VPU_HOSTINTREQ_ADDR)
#define HW_VPU_HOSTINTREQ_WR(v)     (HW_VPU_HOSTINTREQ.U = (v))
#endif

/*
 * constants & macros for individual VPU_HOSTINTREQ bitfields
 */

/* --- Register HW_VPU_HOSTINTREQ, field INTREQ[0] (WO)
 *
 * IntReq. The host interrupt request bit.
 *
 * Values:
 * 0 - No host interrupt is requested.
 * 1 - The host processor request interrupt to the BIT processor.
 */

#define BP_VPU_HOSTINTREQ_INTREQ      (0)      //!< Bit position for VPU_HOSTINTREQ_INTREQ.
#define BM_VPU_HOSTINTREQ_INTREQ      (0x00000001)  //!< Bit mask for VPU_HOSTINTREQ_INTREQ.

//! @brief Get value of VPU_HOSTINTREQ_INTREQ from a register value.
#define BG_VPU_HOSTINTREQ_INTREQ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_VPU_HOSTINTREQ_INTREQ) >> BP_VPU_HOSTINTREQ_INTREQ)

//! @brief Format value for bitfield VPU_HOSTINTREQ_INTREQ.
#define BF_VPU_HOSTINTREQ_INTREQ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_VPU_HOSTINTREQ_INTREQ) & BM_VPU_HOSTINTREQ_INTREQ)


//-------------------------------------------------------------------------------------------
// HW_VPU_BITINTCLEAR - BIT Interrupt Clear
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VPU_BITINTCLEAR - BIT Interrupt Clear (WO)
 *
 * Reset value: 0x00000000
 *
 * See the figure below for illustration of valid bits in VPU BIT Interrupt Clear Register and the
 * following table for description of the bit fields in the register.
 */
typedef union _hw_vpu_bitintclear
{
    reg32_t U;
    struct _hw_vpu_bitintclear_bitfields
    {
        unsigned INTCLEAR : 1; //!< [0] IntClear.
        unsigned RESERVED0 : 31; //!< [31:1] Reserved
    } B;
} hw_vpu_bitintclear_t;
#endif

/*
 * constants & macros for entire VPU_BITINTCLEAR register
 */
#define HW_VPU_BITINTCLEAR_ADDR      (REGS_VPU_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_VPU_BITINTCLEAR           (*(volatile hw_vpu_bitintclear_t *) HW_VPU_BITINTCLEAR_ADDR)
#define HW_VPU_BITINTCLEAR_WR(v)     (HW_VPU_BITINTCLEAR.U = (v))
#endif

/*
 * constants & macros for individual VPU_BITINTCLEAR bitfields
 */

/* --- Register HW_VPU_BITINTCLEAR, field INTCLEAR[0] (WO)
 *
 * IntClear. BIT interrupt clear bit.
 *
 * Values:
 * 0 - No operation is issued.
 * 1 - Clear the BIT interrupt to the host.
 */

#define BP_VPU_BITINTCLEAR_INTCLEAR      (0)      //!< Bit position for VPU_BITINTCLEAR_INTCLEAR.
#define BM_VPU_BITINTCLEAR_INTCLEAR      (0x00000001)  //!< Bit mask for VPU_BITINTCLEAR_INTCLEAR.

//! @brief Get value of VPU_BITINTCLEAR_INTCLEAR from a register value.
#define BG_VPU_BITINTCLEAR_INTCLEAR(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_VPU_BITINTCLEAR_INTCLEAR) >> BP_VPU_BITINTCLEAR_INTCLEAR)

//! @brief Format value for bitfield VPU_BITINTCLEAR_INTCLEAR.
#define BF_VPU_BITINTCLEAR_INTCLEAR(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_VPU_BITINTCLEAR_INTCLEAR) & BM_VPU_BITINTCLEAR_INTCLEAR)


//-------------------------------------------------------------------------------------------
// HW_VPU_BITINTSTS - BIT Interrupt Status
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VPU_BITINTSTS - BIT Interrupt Status (RO)
 *
 * Reset value: 0x00000000
 *
 * See the figure below for illustration of valid bits in VPU BIT Interrupt Status Register and the
 * following table for description of the bit fields in the register.
 */
typedef union _hw_vpu_bitintsts
{
    reg32_t U;
    struct _hw_vpu_bitintsts_bitfields
    {
        unsigned INTSTS : 1; //!< [0] IntSts.
        unsigned RESERVED0 : 31; //!< [31:1] Reserved
    } B;
} hw_vpu_bitintsts_t;
#endif

/*
 * constants & macros for entire VPU_BITINTSTS register
 */
#define HW_VPU_BITINTSTS_ADDR      (REGS_VPU_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_VPU_BITINTSTS           (*(volatile hw_vpu_bitintsts_t *) HW_VPU_BITINTSTS_ADDR)
#define HW_VPU_BITINTSTS_RD()      (HW_VPU_BITINTSTS.U)
#endif

/*
 * constants & macros for individual VPU_BITINTSTS bitfields
 */

/* --- Register HW_VPU_BITINTSTS, field INTSTS[0] (RO)
 *
 * IntSts. BIT interrupt status bit.
 *
 * Values:
 * 0 - No BIT interrupt is asserted.
 * 1 - The BIT interrupt is asserted to the host. It is cleared when the host processor write "1" to
 *     VPU_BitIntClear register.
 */

#define BP_VPU_BITINTSTS_INTSTS      (0)      //!< Bit position for VPU_BITINTSTS_INTSTS.
#define BM_VPU_BITINTSTS_INTSTS      (0x00000001)  //!< Bit mask for VPU_BITINTSTS_INTSTS.

//! @brief Get value of VPU_BITINTSTS_INTSTS from a register value.
#define BG_VPU_BITINTSTS_INTSTS(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_VPU_BITINTSTS_INTSTS) >> BP_VPU_BITINTSTS_INTSTS)


//-------------------------------------------------------------------------------------------
// HW_VPU_BITCURPC - BIT Current PC
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VPU_BITCURPC - BIT Current PC (RO)
 *
 * Reset value: 0x00000000
 *
 * See the figure below for illustration of valid bits in VPU BIT Current PC Register and the
 * following table for description of the bit fields in the register.
 */
typedef union _hw_vpu_bitcurpc
{
    reg32_t U;
    struct _hw_vpu_bitcurpc_bitfields
    {
        unsigned CURPC : 14; //!< [13:0] CurPc[13:0].
        unsigned RESERVED0 : 18; //!< [31:14] Reserved
    } B;
} hw_vpu_bitcurpc_t;
#endif

/*
 * constants & macros for entire VPU_BITCURPC register
 */
#define HW_VPU_BITCURPC_ADDR      (REGS_VPU_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_VPU_BITCURPC           (*(volatile hw_vpu_bitcurpc_t *) HW_VPU_BITCURPC_ADDR)
#define HW_VPU_BITCURPC_RD()      (HW_VPU_BITCURPC.U)
#endif

/*
 * constants & macros for individual VPU_BITCURPC bitfields
 */

/* --- Register HW_VPU_BITCURPC, field CURPC[13:0] (RO)
 *
 * CurPc[13:0]. BIT current PC value. Returns the current program counter of BIT processor by
 * reading this register.
 */

#define BP_VPU_BITCURPC_CURPC      (0)      //!< Bit position for VPU_BITCURPC_CURPC.
#define BM_VPU_BITCURPC_CURPC      (0x00003fff)  //!< Bit mask for VPU_BITCURPC_CURPC.

//! @brief Get value of VPU_BITCURPC_CURPC from a register value.
#define BG_VPU_BITCURPC_CURPC(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_VPU_BITCURPC_CURPC) >> BP_VPU_BITCURPC_CURPC)

//-------------------------------------------------------------------------------------------
// HW_VPU_BITCODECBUSY - BIT CODEC Busy
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_VPU_BITCODECBUSY - BIT CODEC Busy (RO)
 *
 * Reset value: 0x00000000
 *
 * See the figure below for illustration of valid bits in VPU BIT Codec Busy Register and the
 * following table for description of the bit fields in the register.
 */
typedef union _hw_vpu_bitcodecbusy
{
    reg32_t U;
    struct _hw_vpu_bitcodecbusy_bitfields
    {
        unsigned CODECBUSY : 1; //!< [0] Codec busy flag for Bit processor.BIT processor write "1"to this register when the processor is running."0"means processor is waiting for a command.This value is connected to the o_vpu_idle.
        unsigned RESERVED0 : 31; //!< [31:1] Reserved
    } B;
} hw_vpu_bitcodecbusy_t;
#endif

/*
 * constants & macros for entire VPU_BITCODECBUSY register
 */
#define HW_VPU_BITCODECBUSY_ADDR      (REGS_VPU_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_VPU_BITCODECBUSY           (*(volatile hw_vpu_bitcodecbusy_t *) HW_VPU_BITCODECBUSY_ADDR)
#define HW_VPU_BITCODECBUSY_RD()      (HW_VPU_BITCODECBUSY.U)
#endif

/*
 * constants & macros for individual VPU_BITCODECBUSY bitfields
 */

/* --- Register HW_VPU_BITCODECBUSY, field CODECBUSY[0] (RO)
 *
 * Codec busy flag for Bit processor.BIT processor write "1"to this register when the processor is
 * running."0"means processor is waiting for a command.This value is connected to the o_vpu_idle.
 */

#define BP_VPU_BITCODECBUSY_CODECBUSY      (0)      //!< Bit position for VPU_BITCODECBUSY_CODECBUSY.
#define BM_VPU_BITCODECBUSY_CODECBUSY      (0x00000001)  //!< Bit mask for VPU_BITCODECBUSY_CODECBUSY.

//! @brief Get value of VPU_BITCODECBUSY_CODECBUSY from a register value.
#define BG_VPU_BITCODECBUSY_CODECBUSY(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_VPU_BITCODECBUSY_CODECBUSY) >> BP_VPU_BITCODECBUSY_CODECBUSY)


/*!
 * @brief All VPU module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_vpu
{
    volatile hw_vpu_coderun_t CODERUN; //!< BIT Processor run start
    volatile hw_vpu_codedown_t CODEDOWN; //!< BIT Boot Code Download Data register
    volatile hw_vpu_hostintreq_t HOSTINTREQ; //!< Host Interrupt Request to BIT
    volatile hw_vpu_bitintclear_t BITINTCLEAR; //!< BIT Interrupt Clear
    volatile hw_vpu_bitintsts_t BITINTSTS; //!< BIT Interrupt Status
    reg32_t _reserved0;
    volatile hw_vpu_bitcurpc_t BITCURPC; //!< BIT Current PC
    reg32_t _reserved1;
    volatile hw_vpu_bitcodecbusy_t BITCODECBUSY; //!< BIT CODEC Busy
} hw_vpu_t;
#pragma pack()

//! @brief Macro to access all VPU registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_VPU(0)</code>.
#define HW_VPU     (*(volatile hw_vpu_t *) REGS_VPU_BASE)

#endif


#endif // __HW_VPU_REGISTERS_H__