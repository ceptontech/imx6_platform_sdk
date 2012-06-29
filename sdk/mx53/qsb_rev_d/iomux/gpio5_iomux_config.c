/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: gpio5_iomux_config.c

/* ------------------------------------------------------------------------------
 * <auto-generated>
 *     This code was generated by a tool.
 *     Runtime Version:3.3.2.1
 *
 *     Changes to this file may cause incorrect behavior and will be lost if
 *     the code is regenerated.
 * </auto-generated>
 * ------------------------------------------------------------------------------
*/

#include "iomux_config.h"
#include "iomux_define.h"
#include "registers/regsiomuxc.h"

// Function to configure IOMUXC for gpio5 module.
void gpio5_iomux_config(void)
{
    // Config gpio5.GPIO[0] to pad EIM_WAIT(AB9)
    // HW_IOMUXC_SW_MUX_CTL_PAD_EIM_WAIT_WR(0x00000001);
    // HW_IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT_WR(0x000001E0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_WAIT(0x53FA81E4)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_WAIT.
    //   MUX_MODE [1:0] - MUX Mode Select Field Reset: ALT1
    //                    Select 1 of 3 iomux modes to be used for pad: EIM_WAIT.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_WAIT of instance: emi.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: GPIO[0] of instance: gpio5.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: WEIM_DTACK_B of instance: emi.
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_WAIT_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_WAIT_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_WAIT_MUX_MODE(ALT1));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT(0x53FA8534)
    //   HVE [13] - Low / High Output Voltage Field Reset: HVE_RES0
    //              Read Only Field
    //     HVE_RES0 (0) - Reserved
    //   TEST_TS [12] - Test TS Field Reset: TEST_TS_DISABLED
    //                  Read Only Field
    //     TEST_TS_DISABLED (0) - Disabled
    //   DSE_TEST [11] - DSE Test Field Reset: DSE_TEST_NORMAL
    //                   Read Only Field
    //     DSE_TEST_NORMAL (0) - Normal
    //   HYS [8] - Hysteresis Enable Field Reset: HYS_ENABLED
    //             Select one out of next values for pad: EIM_WAIT.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: EIM_WAIT.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: EIM_WAIT.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: EIM_WAIT.
    //     PUS_360KOHM_PD (0) - 360K Ohm Pull Down
    //     PUS_75KOHM_PU (1) - 75K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_DISABLED
    //             Select one out of next values for pad: EIM_WAIT.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_DISABLED
    //               Select one out of next values for pad: EIM_WAIT.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    HW_IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT_DSE(DSE_DISABLED));
}