/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: gpio4_iomux_config.c

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

// Function to configure IOMUXC for gpio4 module.
void gpio4_iomux_config(void)
{
    // Config gpio4.GPIO[0] to pad GPIO_10(W16)
    // SATELLITE_REQ, GPIO_10
    // HW_IOMUXC_SW_MUX_CTL_PAD_GPIO_10_WR(0x00000000);
    // HW_IOMUXC_SW_PAD_CTL_PAD_GPIO_10_WR(0x000005ED);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_GPIO_10(0x53FA8214)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad GPIO_10.
    //   MUX_MODE [0] - MUX Mode Select Field Reset: ALT0
    //                  Select 1 of 2 iomux modes to be used for pad: GPIO_10.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: GPIO[0] of instance: gpio4.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: 32K_OUT of instance: osc32k.
    HW_IOMUXC_SW_MUX_CTL_PAD_GPIO_10_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO_10_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO_10_MUX_MODE(ALT0));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO_10(0x53FA8540)
    //   TEST_TS [12] - Test TS Field Reset: TEST_TS_DISABLED
    //                  Read Only Field
    //     TEST_TS_DISABLED (0) - Disabled
    //   DSE_TEST [11] - DSE Test Field Reset: DSE_TEST_NORMAL
    //                   Read Only Field
    //     DSE_TEST_NORMAL (0) - Normal
    //   STRENGTH_MODE [10] - Strength Mode Field Reset: STRENGTH_MODE_FOUR_LEVEL
    //                        Read Only Field
    //     STRENGTH_MODE_FOUR_LEVEL (1) - 4 Level Mode
    //   HYS [8] - Hysteresis Enable Field Reset: HYS_ENABLED
    //             Select one out of next values for pad: GPIO_10.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: GPIO_10.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: GPIO_10.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: GPIO_10.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_ENABLED
    //             Select one out of next values for pad: GPIO_10.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: GPIO_10.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: GPIO_10.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_GPIO_10_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_10_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_10_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_10_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_10_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_10_ODE(ODE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_10_DSE(DSE_120OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_10_SRE(SRE_FAST));

    // Config gpio4.GPIO[1] to pad GPIO_11(V17)
    // HW_IOMUXC_SW_PAD_CTL_PAD_GPIO_11_WR(0x000005ED);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO_11(0x53FA8544)
    //   TEST_TS [12] - Test TS Field Reset: TEST_TS_DISABLED
    //                  Read Only Field
    //     TEST_TS_DISABLED (0) - Disabled
    //   DSE_TEST [11] - DSE Test Field Reset: DSE_TEST_NORMAL
    //                   Read Only Field
    //     DSE_TEST_NORMAL (0) - Normal
    //   STRENGTH_MODE [10] - Strength Mode Field Reset: STRENGTH_MODE_FOUR_LEVEL
    //                        Read Only Field
    //     STRENGTH_MODE_FOUR_LEVEL (1) - 4 Level Mode
    //   HYS [8] - Hysteresis Enable Field Reset: HYS_ENABLED
    //             Select one out of next values for pad: GPIO_11.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: GPIO_11.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: GPIO_11.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: GPIO_11.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_ENABLED
    //             Select one out of next values for pad: GPIO_11.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: GPIO_11.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: GPIO_11.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_GPIO_11_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_11_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_11_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_11_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_11_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_11_ODE(ODE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_11_DSE(DSE_120OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_11_SRE(SRE_FAST));

    // Config gpio4.GPIO[14] to pad KEY_COL4(E5)
    // USB_H2_PHY_RST_B and KEY_COL4
    // HW_IOMUXC_SW_MUX_CTL_PAD_KEY_COL4_WR(0x00000001);
    // HW_IOMUXC_SW_PAD_CTL_PAD_KEY_COL4_WR(0x000001E4);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_KEY_COL4(0x53FA8044)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad KEY_COL4.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT1
    //                    Select 1 of 7 iomux modes to be used for pad: KEY_COL4.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: COL[4] of instance: kpp.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: GPIO[14] of instance: gpio4.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: TXCAN of instance: can2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: SISG[4] of instance: ipu.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: RTS of instance: uart5.
    //                NOTE: - Config Register IOMUXC_UART5_IPP_UART_RTS_B_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: USBOTG_OC of instance: usboh3.
    //                NOTE: - Config Register IOMUXC_USBOH3_IPP_IND_OTG_OC_SELECT_INPUT for mode ALT5.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: LINESTATE[1] of instance: usbphy1.
    HW_IOMUXC_SW_MUX_CTL_PAD_KEY_COL4_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_KEY_COL4_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_KEY_COL4_MUX_MODE(ALT1));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_KEY_COL4(0x53FA836C)
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
    //             Select one out of next values for pad: KEY_COL4.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: KEY_COL4.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: KEY_COL4.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: KEY_COL4.
    //     PUS_360KOHM_PD (0) - 360K Ohm Pull Down
    //     PUS_75KOHM_PU (1) - 75K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_DISABLED
    //             Select one out of next values for pad: KEY_COL4.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: KEY_COL4.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    HW_IOMUXC_SW_PAD_CTL_PAD_KEY_COL4_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL4_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL4_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL4_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL4_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL4_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL4_DSE(DSE_120OHM));

    // Config gpio4.GPIO[15] to pad KEY_ROW4(E6)
    // CAN_STBY and KEY_ROW4
    // HW_IOMUXC_SW_MUX_CTL_PAD_KEY_ROW4_WR(0x00000001);
    // HW_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW4_WR(0x000001C4);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_KEY_ROW4(0x53FA8048)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad KEY_ROW4.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT1
    //                    Select 1 of 7 iomux modes to be used for pad: KEY_ROW4.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: ROW[4] of instance: kpp.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: GPIO[15] of instance: gpio4.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: RXCAN of instance: can2.
    //                NOTE: - Config Register IOMUXC_CAN2_IPP_IND_CANRX_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: SISG[5] of instance: ipu.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: CTS of instance: uart5.
    //                NOTE: - Config Register IOMUXC_UART5_IPP_UART_RTS_B_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: USBOTG_PWR of instance: usboh3.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: VBUSVALID of instance: usbphy1.
    HW_IOMUXC_SW_MUX_CTL_PAD_KEY_ROW4_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_KEY_ROW4_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_KEY_ROW4_MUX_MODE(ALT1));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_KEY_ROW4(0x53FA8370)
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
    //             Select one out of next values for pad: KEY_ROW4.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: KEY_ROW4.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: KEY_ROW4.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_360KOHM_PD
    //               Select one out of next values for pad: KEY_ROW4.
    //     PUS_360KOHM_PD (0) - 360K Ohm Pull Down
    //     PUS_75KOHM_PU (1) - 75K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_DISABLED
    //             Select one out of next values for pad: KEY_ROW4.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: KEY_ROW4.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    HW_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW4_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW4_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW4_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW4_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW4_PUS(PUS_360KOHM_PD) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW4_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW4_DSE(DSE_120OHM));

    // Config gpio4.GPIO[18] to pad DI0_PIN2(D3)
    // DIO_PIN2, routed to finger as spare
    // HW_IOMUXC_SW_MUX_CTL_PAD_DI0_PIN2_WR(0x00000001);
    // HW_IOMUXC_SW_PAD_CTL_PAD_DI0_PIN2_WR(0x000005E5);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_DI0_PIN2(0x53FA8054)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad DI0_PIN2.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT1
    //                    Select 1 of 6 iomux modes to be used for pad: DI0_PIN2.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DI0_PIN2 of instance: ipu.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: GPIO[18] of instance: gpio4.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: AUD6_TXD of instance: audmux.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: DEBUG_CORE_STATE[2] of instance: sdma.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: EMI_DEBUG[2] of instance: emi.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: ENDSESSION of instance: usbphy1.
    HW_IOMUXC_SW_MUX_CTL_PAD_DI0_PIN2_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_DI0_PIN2_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_DI0_PIN2_MUX_MODE(ALT1));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_DI0_PIN2(0x53FA8380)
    //   TEST_TS [12] - Test TS Field Reset: TEST_TS_DISABLED
    //                  Read Only Field
    //     TEST_TS_DISABLED (0) - Disabled
    //   DSE_TEST [11] - DSE Test Field Reset: DSE_TEST_NORMAL
    //                   Read Only Field
    //     DSE_TEST_NORMAL (0) - Normal
    //   STRENGTH_MODE [10] - Strength Mode Field Reset: STRENGTH_MODE_FOUR_LEVEL
    //                        Read Only Field
    //     STRENGTH_MODE_FOUR_LEVEL (1) - 4 Level Mode
    //   HYS [8] - Hysteresis Enable Field Reset: HYS_ENABLED
    //             Select one out of next values for pad: DI0_PIN2.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: DI0_PIN2.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: DI0_PIN2.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: DI0_PIN2.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_DISABLED
    //             Select one out of next values for pad: DI0_PIN2.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: DI0_PIN2.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: DI0_PIN2.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_DI0_PIN2_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_DI0_PIN2_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DI0_PIN2_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DI0_PIN2_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DI0_PIN2_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DI0_PIN2_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DI0_PIN2_DSE(DSE_120OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_DI0_PIN2_SRE(SRE_FAST));

    // Config gpio4.GPIO[2] to pad GPIO_12(W17)
    // HW_IOMUXC_SW_PAD_CTL_PAD_GPIO_12_WR(0x000005ED);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO_12(0x53FA8548)
    //   TEST_TS [12] - Test TS Field Reset: TEST_TS_DISABLED
    //                  Read Only Field
    //     TEST_TS_DISABLED (0) - Disabled
    //   DSE_TEST [11] - DSE Test Field Reset: DSE_TEST_NORMAL
    //                   Read Only Field
    //     DSE_TEST_NORMAL (0) - Normal
    //   STRENGTH_MODE [10] - Strength Mode Field Reset: STRENGTH_MODE_FOUR_LEVEL
    //                        Read Only Field
    //     STRENGTH_MODE_FOUR_LEVEL (1) - 4 Level Mode
    //   HYS [8] - Hysteresis Enable Field Reset: HYS_ENABLED
    //             Select one out of next values for pad: GPIO_12.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: GPIO_12.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: GPIO_12.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: GPIO_12.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_ENABLED
    //             Select one out of next values for pad: GPIO_12.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: GPIO_12.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: GPIO_12.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_GPIO_12_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_12_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_12_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_12_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_12_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_12_ODE(ODE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_12_DSE(DSE_120OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_12_SRE(SRE_FAST));

    // Config gpio4.GPIO[3] to pad GPIO_13(AA18)
    // HW_IOMUXC_SW_PAD_CTL_PAD_GPIO_13_WR(0x000005ED);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO_13(0x53FA854C)
    //   TEST_TS [12] - Test TS Field Reset: TEST_TS_DISABLED
    //                  Read Only Field
    //     TEST_TS_DISABLED (0) - Disabled
    //   DSE_TEST [11] - DSE Test Field Reset: DSE_TEST_NORMAL
    //                   Read Only Field
    //     DSE_TEST_NORMAL (0) - Normal
    //   STRENGTH_MODE [10] - Strength Mode Field Reset: STRENGTH_MODE_FOUR_LEVEL
    //                        Read Only Field
    //     STRENGTH_MODE_FOUR_LEVEL (1) - 4 Level Mode
    //   HYS [8] - Hysteresis Enable Field Reset: HYS_ENABLED
    //             Select one out of next values for pad: GPIO_13.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: GPIO_13.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: GPIO_13.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: GPIO_13.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_ENABLED
    //             Select one out of next values for pad: GPIO_13.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: GPIO_13.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: GPIO_13.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_GPIO_13_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_13_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_13_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_13_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_13_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_13_ODE(ODE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_13_DSE(DSE_120OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_13_SRE(SRE_FAST));

    // Config gpio4.GPIO[4] to pad GPIO_14(W18)
    // HW_IOMUXC_SW_PAD_CTL_PAD_GPIO_14_WR(0x000005ED);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO_14(0x53FA8550)
    //   TEST_TS [12] - Test TS Field Reset: TEST_TS_DISABLED
    //                  Read Only Field
    //     TEST_TS_DISABLED (0) - Disabled
    //   DSE_TEST [11] - DSE Test Field Reset: DSE_TEST_NORMAL
    //                   Read Only Field
    //     DSE_TEST_NORMAL (0) - Normal
    //   STRENGTH_MODE [10] - Strength Mode Field Reset: STRENGTH_MODE_FOUR_LEVEL
    //                        Read Only Field
    //     STRENGTH_MODE_FOUR_LEVEL (1) - 4 Level Mode
    //   HYS [8] - Hysteresis Enable Field Reset: HYS_ENABLED
    //             Select one out of next values for pad: GPIO_14.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //             Select one out of next values for pad: GPIO_14.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //             Select one out of next values for pad: GPIO_14.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //               Select one out of next values for pad: GPIO_14.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_ENABLED
    //             Select one out of next values for pad: GPIO_14.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //               Select one out of next values for pad: GPIO_14.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: GPIO_14.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_GPIO_14_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_14_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_14_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_14_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_14_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_14_ODE(ODE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_14_DSE(DSE_120OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_14_SRE(SRE_FAST));

    // Config gpio4.GPIO[5] to pad GPIO_19(B4)
    // FPGA_INT_B, GPIO_19
    // HW_IOMUXC_SW_MUX_CTL_PAD_GPIO_19_WR(0x00000001);
    // HW_IOMUXC_SW_PAD_CTL_PAD_GPIO_19_WR(0x000001E4);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_GPIO_19(0x53FA8020)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad GPIO_19.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT1
    //                    Select 1 of 8 iomux modes to be used for pad: GPIO_19.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: COL[5] of instance: kpp.
    //                NOTE: - Config Register IOMUXC_KPP_IPP_IND_COL_5_SELECT_INPUT for mode ALT0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: GPIO[5] of instance: gpio4.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: CLKO of instance: ccm.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: OUT1 of instance: spdif.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: CE_RTC_EXT_TRIG2 of instance: rtc.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: RDY of instance: ecspi1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: TDATA[3] of instance: fec.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: INT_BOOT of instance: src.
    HW_IOMUXC_SW_MUX_CTL_PAD_GPIO_19_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO_19_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_GPIO_19_MUX_MODE(ALT1));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_GPIO_19(0x53FA8348)
    //   HVE [13] - Low / High Output Voltage Field Reset: HVE_RES0
    //     HVE_RES0 (0) - Reserved
    //     HVE_RES1 (1) - Reserved
    //   TEST_TS [12] - Test TS Field Reset: TEST_TS_DISABLED
    //     TEST_TS_DISABLED (0) - Disabled
    //     TEST_TS_ENABLED (1) - Enabled
    //   DSE_TEST [11] - DSE Test Field Reset: DSE_TEST_NORMAL
    //     DSE_TEST_NORMAL (0) - Normal
    //     DSE_TEST_TEST (1) - Test
    //   HYS [8] - Hysteresis Enable Field Reset: HYS_ENABLED
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PKE [7] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   PUE [6] - Pull / Keep Select Field Reset: PUE_PULL
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PUS [5:4] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //     PUS_360KOHM_PD (0) - 360K Ohm Pull Down
    //     PUS_75KOHM_PU (1) - 75K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   ODE [3] - Open Drain Enable Field Reset: ODE_DISABLED
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   DSE [2:1] - Drive Strength Field Reset: DSE_120OHM
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    HW_IOMUXC_SW_PAD_CTL_PAD_GPIO_19_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_19_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_19_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_19_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_19_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_19_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_GPIO_19_DSE(DSE_120OHM));
}