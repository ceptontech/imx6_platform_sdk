/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: pata_iomux_config.c

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

// Function to configure IOMUXC for pata module.
void pata_iomux_config(void)
{
    // Config pata.DA_0 to pad PATA_DA_0(K6)
    // CAN_EN
    // HW_IOMUXC_SW_MUX_CTL_PAD_PATA_DA_0_WR(0x00000000);
    // HW_IOMUXC_SW_PAD_CTL_PAD_PATA_DA_0_WR(0x000001E4);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_PATA_DA_0(0x53FA8290)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad PATA_DA_0.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT1
    //                    Select 1 of 5 iomux modes to be used for pad: PATA_DA_0.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DA_0 of instance: pata.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: GPIO[6] of instance: gpio7.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: RST of instance: esdhc3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: LINE of instance: owire.
    //                NOTE: - Config Register IOMUXC_OWIRE_BATTERY_LINE_IN_SELECT_INPUT for mode ALT4.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: DATAOUT[2] of instance: usbphy1.
    HW_IOMUXC_SW_MUX_CTL_PAD_PATA_DA_0_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_PATA_DA_0_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_PATA_DA_0_MUX_MODE(ALT0));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_PATA_DA_0(0x53FA8610)
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
    //             Select one out of next values for pad: PATA_DA_0.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: PATA_DA_0.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: PATA_DA_0.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: PATA_DA_0.
    //     PUS_360KOHM_PD (0) - 360K Ohm Pull Down
    //     PUS_75KOHM_PU (1) - 75K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_DISABLED
    //             Select one out of next values for pad: PATA_DA_0.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: PATA_DA_0.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    HW_IOMUXC_SW_PAD_CTL_PAD_PATA_DA_0_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DA_0_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DA_0_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DA_0_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DA_0_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DA_0_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DA_0_DSE(DSE_120OHM));

    // Config pata.PATA_DATA[0] to pad PATA_DATA0(L1)
    // CAN1_NERR_B
    // HW_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA0_WR(0x00000000);
    // HW_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA0_WR(0x000001E4);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_PATA_DATA0(0x53FA82A4)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad PATA_DATA0.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT1
    //                    Select 1 of 7 iomux modes to be used for pad: PATA_DATA0.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: PATA_DATA[0] of instance: pata.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: GPIO[0] of instance: gpio2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: NANDF_D[0] of instance: emi.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DAT4 of instance: esdhc3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPU_DEBUG_OUT[0] of instance: gpu3d.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: IPU_DIAG_BUS[0] of instance: ipu.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: DATAOUT[7] of instance: usbphy1.
    HW_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA0_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA0_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA0_MUX_MODE(ALT0));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_PATA_DATA0(0x53FA8628)
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
    //             Select one out of next values for pad: PATA_DATA0.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: PATA_DATA0.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: PATA_DATA0.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: PATA_DATA0.
    //     PUS_360KOHM_PD (0) - 360K Ohm Pull Down
    //     PUS_75KOHM_PU (1) - 75K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_DISABLED
    //             Select one out of next values for pad: PATA_DATA0.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: PATA_DATA0.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    HW_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA0_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA0_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA0_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA0_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA0_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA0_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA0_DSE(DSE_120OHM));

    // Config pata.PATA_DATA[1] to pad PATA_DATA1(M1)
    // CAN2_NERR_B
    // HW_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA1_WR(0x00000000);
    // HW_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA1_WR(0x000001E4);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_PATA_DATA1(0x53FA82A8)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad PATA_DATA1.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT1
    //                    Select 1 of 6 iomux modes to be used for pad: PATA_DATA1.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: PATA_DATA[1] of instance: pata.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: GPIO[1] of instance: gpio2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: NANDF_D[1] of instance: emi.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DAT5 of instance: esdhc3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPU_DEBUG_OUT[1] of instance: gpu3d.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: IPU_DIAG_BUS[1] of instance: ipu.
    HW_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA1_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA1_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA1_MUX_MODE(ALT0));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_PATA_DATA1(0x53FA862C)
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
    //             Select one out of next values for pad: PATA_DATA1.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: PATA_DATA1.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: PATA_DATA1.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: PATA_DATA1.
    //     PUS_360KOHM_PD (0) - 360K Ohm Pull Down
    //     PUS_75KOHM_PU (1) - 75K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_DISABLED
    //             Select one out of next values for pad: PATA_DATA1.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: PATA_DATA1.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    HW_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA1_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA1_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA1_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA1_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA1_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA1_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA1_DSE(DSE_120OHM));

    // Config pata.PATA_DATA[2] to pad PATA_DATA2(L6)
    // VIDEO_ADC_PWRDN_B
    // HW_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA2_WR(0x00000000);
    // HW_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA2_WR(0x000001E4);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_PATA_DATA2(0x53FA82AC)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad PATA_DATA2.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT1
    //                    Select 1 of 6 iomux modes to be used for pad: PATA_DATA2.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: PATA_DATA[2] of instance: pata.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: GPIO[2] of instance: gpio2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: NANDF_D[2] of instance: emi.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DAT6 of instance: esdhc3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPU_DEBUG_OUT[2] of instance: gpu3d.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: IPU_DIAG_BUS[2] of instance: ipu.
    HW_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA2_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA2_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA2_MUX_MODE(ALT0));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_PATA_DATA2(0x53FA8630)
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
    //             Select one out of next values for pad: PATA_DATA2.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: PATA_DATA2.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: PATA_DATA2.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: PATA_DATA2.
    //     PUS_360KOHM_PD (0) - 360K Ohm Pull Down
    //     PUS_75KOHM_PU (1) - 75K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_DISABLED
    //             Select one out of next values for pad: PATA_DATA2.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: PATA_DATA2.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    HW_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA2_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA2_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA2_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA2_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA2_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA2_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA2_DSE(DSE_120OHM));

    // Config pata.PATA_DATA[3] to pad PATA_DATA3(M2)
    // I2CPORTEXP_RST_B
    // HW_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA3_WR(0x00000000);
    // HW_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA3_WR(0x000001E4);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_PATA_DATA3(0x53FA82B0)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad PATA_DATA3.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT1
    //                    Select 1 of 6 iomux modes to be used for pad: PATA_DATA3.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: PATA_DATA[3] of instance: pata.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: GPIO[3] of instance: gpio2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: NANDF_D[3] of instance: emi.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DAT7 of instance: esdhc3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPU_DEBUG_OUT[3] of instance: gpu3d.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: IPU_DIAG_BUS[3] of instance: ipu.
    HW_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA3_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA3_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA3_MUX_MODE(ALT0));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_PATA_DATA3(0x53FA8634)
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
    //             Select one out of next values for pad: PATA_DATA3.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: PATA_DATA3.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: PATA_DATA3.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: PATA_DATA3.
    //     PUS_360KOHM_PD (0) - 360K Ohm Pull Down
    //     PUS_75KOHM_PU (1) - 75K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_DISABLED
    //             Select one out of next values for pad: PATA_DATA3.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: PATA_DATA3.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    HW_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA3_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA3_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA3_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA3_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA3_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA3_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA3_DSE(DSE_120OHM));

    // Config pata.PATA_DATA[4] to pad PATA_DATA4(M3)
    // ESAI_INT
    // HW_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA4_WR(0x00000000);
    // HW_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA4_WR(0x000001E4);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_PATA_DATA4(0x53FA82B4)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad PATA_DATA4.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT1
    //                    Select 1 of 6 iomux modes to be used for pad: PATA_DATA4.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: PATA_DATA[4] of instance: pata.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: GPIO[4] of instance: gpio2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: NANDF_D[4] of instance: emi.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DAT4 of instance: esdhc4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPU_DEBUG_OUT[4] of instance: gpu3d.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: IPU_DIAG_BUS[4] of instance: ipu.
    HW_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA4_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA4_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA4_MUX_MODE(ALT0));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_PATA_DATA4(0x53FA8638)
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
    //             Select one out of next values for pad: PATA_DATA4.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: PATA_DATA4.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: PATA_DATA4.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: PATA_DATA4.
    //     PUS_360KOHM_PD (0) - 360K Ohm Pull Down
    //     PUS_75KOHM_PU (1) - 75K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_DISABLED
    //             Select one out of next values for pad: PATA_DATA4.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: PATA_DATA4.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    HW_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA4_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA4_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA4_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA4_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA4_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA4_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA4_DSE(DSE_120OHM));

    // Config pata.PATA_DATA[5] to pad PATA_DATA5(M4)
    // GPS_PWREN
    // HW_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA5_WR(0x00000000);
    // HW_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA5_WR(0x000001E4);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_PATA_DATA5(0x53FA82B8)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad PATA_DATA5.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT1
    //                    Select 1 of 6 iomux modes to be used for pad: PATA_DATA5.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: PATA_DATA[5] of instance: pata.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: GPIO[5] of instance: gpio2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: NANDF_D[5] of instance: emi.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DAT5 of instance: esdhc4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPU_DEBUG_OUT[5] of instance: gpu3d.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: IPU_DIAG_BUS[5] of instance: ipu.
    HW_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA5_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA5_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA5_MUX_MODE(ALT0));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_PATA_DATA5(0x53FA863C)
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
    //             Select one out of next values for pad: PATA_DATA5.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: PATA_DATA5.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: PATA_DATA5.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: PATA_DATA5.
    //     PUS_360KOHM_PD (0) - 360K Ohm Pull Down
    //     PUS_75KOHM_PU (1) - 75K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_DISABLED
    //             Select one out of next values for pad: PATA_DATA5.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: PATA_DATA5.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    HW_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA5_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA5_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA5_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA5_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA5_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA5_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA5_DSE(DSE_120OHM));

    // Config pata.PATA_DATA[6] to pad PATA_DATA6(N1)
    // GPS_INT_B
    // HW_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA6_WR(0x00000000);
    // HW_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA6_WR(0x000001E4);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_PATA_DATA6(0x53FA82BC)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad PATA_DATA6.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT1
    //                    Select 1 of 6 iomux modes to be used for pad: PATA_DATA6.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: PATA_DATA[6] of instance: pata.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: GPIO[6] of instance: gpio2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: NANDF_D[6] of instance: emi.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DAT6 of instance: esdhc4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPU_DEBUG_OUT[6] of instance: gpu3d.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: IPU_DIAG_BUS[6] of instance: ipu.
    HW_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA6_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA6_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA6_MUX_MODE(ALT0));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_PATA_DATA6(0x53FA8640)
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
    //             Select one out of next values for pad: PATA_DATA6.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: PATA_DATA6.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: PATA_DATA6.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: PATA_DATA6.
    //     PUS_360KOHM_PD (0) - 360K Ohm Pull Down
    //     PUS_75KOHM_PU (1) - 75K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_DISABLED
    //             Select one out of next values for pad: PATA_DATA6.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: PATA_DATA6.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    HW_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA6_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA6_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA6_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA6_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA6_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA6_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA6_DSE(DSE_120OHM));

    // Config pata.PATA_DATA[7] to pad PATA_DATA7(M5)
    // MLB_INT_B
    // HW_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA7_WR(0x00000000);
    // HW_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA7_WR(0x000001E4);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_PATA_DATA7(0x53FA82C0)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad PATA_DATA7.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT1
    //                    Select 1 of 6 iomux modes to be used for pad: PATA_DATA7.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: PATA_DATA[7] of instance: pata.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: GPIO[7] of instance: gpio2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: NANDF_D[7] of instance: emi.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DAT7 of instance: esdhc4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPU_DEBUG_OUT[7] of instance: gpu3d.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: IPU_DIAG_BUS[7] of instance: ipu.
    HW_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA7_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA7_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_PATA_DATA7_MUX_MODE(ALT0));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_PATA_DATA7(0x53FA8644)
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
    //             Select one out of next values for pad: PATA_DATA7.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: PATA_DATA7.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: PATA_DATA7.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: PATA_DATA7.
    //     PUS_360KOHM_PD (0) - 360K Ohm Pull Down
    //     PUS_75KOHM_PU (1) - 75K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_DISABLED
    //             Select one out of next values for pad: PATA_DATA7.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: PATA_DATA7.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    HW_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA7_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA7_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA7_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA7_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA7_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA7_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PATA_DATA7_DSE(DSE_120OHM));
}