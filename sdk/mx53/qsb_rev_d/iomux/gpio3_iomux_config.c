/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: gpio3_iomux_config.c

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

// Function to configure IOMUXC for gpio3 module.
void gpio3_iomux_config(void)
{
    // Config gpio3.GPIO[11] to pad EIM_DA11(AC6)
    // HW_IOMUXC_SW_MUX_CTL_PAD_EIM_DA11_WR(0x00000001);
    // HW_IOMUXC_SW_PAD_CTL_PAD_EIM_DA11_WR(0x000000E4);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DA11(0x53FA81C8)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_DA11.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 4 iomux modes to be used for pad: EIM_DA11.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: NAND_WEIM_DA[11] of instance: emi.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: GPIO[11] of instance: gpio3.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: DI1_PIN2 of instance: ipu.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: CSI1_HSYNC of instance: ipu.
    //                NOTE: - Config Register IOMUXC_IPU_IPP_IND_SENS1_HSYNC_SELECT_INPUT for mode ALT4.
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_DA11_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_DA11_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_DA11_MUX_MODE(ALT1));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DA11(0x53FA8518)
    //   HVE [13] - Low / High Output Voltage Field Reset: HVE_RES0
    //              Read Only Field
    //     HVE_RES0 (0) - Reserved
    //   TEST_TS [12] - Test TS Field Reset: TEST_TS_DISABLED
    //                  Read Only Field
    //     TEST_TS_DISABLED (0) - Disabled
    //   DSE_TEST [11] - DSE Test Field Reset: DSE_TEST_NORMAL
    //                   Read Only Field
    //     DSE_TEST_NORMAL (0) - Normal
    //   HYS [8] - Hysteresis Enable Field Reset: HYS_DISABLED
    //             Select one out of next values for pad: EIM_DA11.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: EIM_DA11.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: EIM_DA11.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: EIM_DA11.
    //     PUS_360KOHM_PD (0) - 360K Ohm Pull Down
    //     PUS_75KOHM_PU (1) - 75K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_DISABLED
    //             Select one out of next values for pad: EIM_DA11.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: EIM_DA11.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    HW_IOMUXC_SW_PAD_CTL_PAD_EIM_DA11_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DA11_HYS(HYS_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DA11_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DA11_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DA11_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DA11_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DA11_DSE(DSE_120OHM));

    // Config gpio3.GPIO[12] to pad EIM_DA12(V10)
    // HW_IOMUXC_SW_MUX_CTL_PAD_EIM_DA12_WR(0x00000001);
    // HW_IOMUXC_SW_PAD_CTL_PAD_EIM_DA12_WR(0x000000E4);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DA12(0x53FA81CC)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_DA12.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 4 iomux modes to be used for pad: EIM_DA12.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: NAND_WEIM_DA[12] of instance: emi.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: GPIO[12] of instance: gpio3.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: DI1_PIN3 of instance: ipu.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: CSI1_VSYNC of instance: ipu.
    //                NOTE: - Config Register IOMUXC_IPU_IPP_IND_SENS1_VSYNC_SELECT_INPUT for mode ALT4.
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_DA12_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_DA12_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_DA12_MUX_MODE(ALT1));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DA12(0x53FA851C)
    //   HVE [13] - Low / High Output Voltage Field Reset: HVE_RES0
    //              Read Only Field
    //     HVE_RES0 (0) - Reserved
    //   TEST_TS [12] - Test TS Field Reset: TEST_TS_DISABLED
    //                  Read Only Field
    //     TEST_TS_DISABLED (0) - Disabled
    //   DSE_TEST [11] - DSE Test Field Reset: DSE_TEST_NORMAL
    //                   Read Only Field
    //     DSE_TEST_NORMAL (0) - Normal
    //   HYS [8] - Hysteresis Enable Field Reset: HYS_DISABLED
    //             Select one out of next values for pad: EIM_DA12.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: EIM_DA12.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: EIM_DA12.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: EIM_DA12.
    //     PUS_360KOHM_PD (0) - 360K Ohm Pull Down
    //     PUS_75KOHM_PU (1) - 75K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_DISABLED
    //             Select one out of next values for pad: EIM_DA12.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: EIM_DA12.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    HW_IOMUXC_SW_PAD_CTL_PAD_EIM_DA12_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DA12_HYS(HYS_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DA12_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DA12_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DA12_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DA12_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DA12_DSE(DSE_120OHM));

    // Config gpio3.GPIO[13] to pad EIM_DA13(AC7)
    // HW_IOMUXC_SW_MUX_CTL_PAD_EIM_DA13_WR(0x00000001);
    // HW_IOMUXC_SW_PAD_CTL_PAD_EIM_DA13_WR(0x000000E4);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_DA13(0x53FA81D0)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_DA13.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 4 iomux modes to be used for pad: EIM_DA13.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: NAND_WEIM_DA[13] of instance: emi.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: GPIO[13] of instance: gpio3.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: DI1_D0_CS of instance: ipu.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DI1_EXT_CLK of instance: ccm.
    //                NOTE: - Config Register IOMUXC_CCM_IPP_DI1_CLK_SELECT_INPUT for mode ALT4.
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_DA13_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_DA13_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_DA13_MUX_MODE(ALT1));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_DA13(0x53FA8520)
    //   HVE [13] - Low / High Output Voltage Field Reset: HVE_RES0
    //              Read Only Field
    //     HVE_RES0 (0) - Reserved
    //   TEST_TS [12] - Test TS Field Reset: TEST_TS_DISABLED
    //                  Read Only Field
    //     TEST_TS_DISABLED (0) - Disabled
    //   DSE_TEST [11] - DSE Test Field Reset: DSE_TEST_NORMAL
    //                   Read Only Field
    //     DSE_TEST_NORMAL (0) - Normal
    //   HYS [8] - Hysteresis Enable Field Reset: HYS_DISABLED
    //             Select one out of next values for pad: EIM_DA13.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: EIM_DA13.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: EIM_DA13.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: EIM_DA13.
    //     PUS_360KOHM_PD (0) - 360K Ohm Pull Down
    //     PUS_75KOHM_PU (1) - 75K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_DISABLED
    //             Select one out of next values for pad: EIM_DA13.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: EIM_DA13.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    HW_IOMUXC_SW_PAD_CTL_PAD_EIM_DA13_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DA13_HYS(HYS_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DA13_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DA13_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DA13_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DA13_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_DA13_DSE(DSE_120OHM));

    // Config gpio3.GPIO[24] to pad EIM_D24(Y2)
    // HW_IOMUXC_SW_MUX_CTL_PAD_EIM_D24_WR(0x00000001);
    // HW_IOMUXC_SW_PAD_CTL_PAD_EIM_D24_WR(0x000001E4);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_D24(0x53FA813C)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_D24.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT1
    //                    Select 1 of 8 iomux modes to be used for pad: EIM_D24.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_D[24] of instance: emi.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: GPIO[24] of instance: gpio3.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: TXD_MUX of instance: uart3.
    //                NOTE: - Config Register IOMUXC_UART3_IPP_UART_RXD_MUX_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: SS2 of instance: ecspi1.
    //                NOTE: - Config Register IOMUXC_ECSPI1_IPP_IND_SS_B_2_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: SS2 of instance: cspi.
    //                NOTE: - Config Register IOMUXC_CSPI_IPP_IND_SS2_B_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: AUD5_RXFS of instance: audmux.
    //                NOTE: - Config Register IOMUXC_AUDMUX_P5_INPUT_RXFS_AMX_SELECT_INPUT for mode ALT5.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: SS2 of instance: ecspi2.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: DTR of instance: uart1.
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_D24_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_D24_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_D24_MUX_MODE(ALT1));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_D24(0x53FA8484)
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
    //             Select one out of next values for pad: EIM_D24.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: EIM_D24.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: EIM_D24.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: EIM_D24.
    //     PUS_360KOHM_PD (0) - 360K Ohm Pull Down
    //     PUS_75KOHM_PU (1) - 75K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_DISABLED
    //             Select one out of next values for pad: EIM_D24.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: EIM_D24.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    HW_IOMUXC_SW_PAD_CTL_PAD_EIM_D24_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D24_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D24_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D24_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D24_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D24_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_D24_DSE(DSE_120OHM));
}