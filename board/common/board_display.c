/*
 * Copyright (c) 2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "sdk.h"
#include "registers/regsccmanalog.h"
#include "registers/regsccm.h"
#include "registers/regsiomuxc.h"

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

/*!
 * Provide the LVDS power through GPIO pins
 */
void lvds_power_on(void)
{
#if defined(BOARD_EVB)
    /*3.3V power supply through the load switch FDC6331L */
    max7310_set_gpio_output(0, 0, GPIO_HIGH_LEVEL);
    max7310_set_gpio_output(1, 1, GPIO_HIGH_LEVEL);

    /*lvds backlight enable, GPIO_9 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_GPIO_9, ALT5);
    gpio_set_direction(GPIO_PORT1, 9, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT1, 9, GPIO_HIGH_LEVEL);
#endif

#ifdef BOARD_SMART_DEVICE
    // 3v3 on by default
    // AUX_5V_EN LVDS0 power
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0, ALT5);
    gpio_set_direction(GPIO_PORT6, 10, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT6, 10, GPIO_HIGH_LEVEL);
    // PMIC_5V LVDS1 power on by default
    // backlight both lvds1/0, disp0_contrast/disp0_pwm, gpio1[21]
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD1_DAT3, ALT5);
    gpio_set_direction(GPIO_PORT1, 21, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT1, 21, GPIO_HIGH_LEVEL);
#endif

#ifdef BOARD_SABRE_AI
    /*3.3V power supply through IOexpander */
    max7310_set_gpio_output(0, 0, GPIO_HIGH_LEVEL);

    /*lvds backlight enable, GPIO_9 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD4_DAT1, ALT5);
    gpio_set_direction(GPIO_PORT2, 9, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT2, 9, GPIO_HIGH_LEVEL);

#endif
}

/*! From obds
 * Disable the display panel
 */
void disable_para_panel(void)
{
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_EB3, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_EB3, 0x1B0B0);
    gpio_set_direction(GPIO_PORT2, 31, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT2, 31, GPIO_LOW_LEVEL);
}

/*! Copy from OBDS
 * Provide the power for TFT LCD backlight
 */
void tftlcd_backlight_en(char *panel_name)
{
    if (!strcmp(panel_name, "CLAA 070VC01")) {
        /*GPIO to provide backlight */
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_DI0_PIN4, ALT5);
        gpio_set_direction(GPIO_PORT4, 20, GPIO_GDIR_OUTPUT);
        gpio_set_level(GPIO_PORT4, 20, GPIO_HIGH_LEVEL);
    } else if (!strcmp(panel_name, "BoundaryDev WVGA")) {
#if defined (BOARD_REV_A)
        /*lvds/parallel display backlight enable, GPIO2_0 */
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD4_DAT1, ALT5);
        gpio_set_direction(GPIO_PORT2, 9, GPIO_GDIR_OUTPUT);
        gpio_set_level(GPIO_PORT2, 9, GPIO_HIGH_LEVEL);

        // lcd_contrast conflict with actual BoundaryDev display so seeting to input
        // since TSC not used on SABRE AI
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_DI0_PIN4, ALT5);
        gpio_set_direction(GPIO_PORT4, 20, GPIO_GDIR_INPUT);
#elif defined (BOARD_REV_B) || defined(BOARD_REV_C)
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_DI0_PIN4, ALT5);
        gpio_set_direction(GPIO_PORT4, 20, GPIO_GDIR_OUTPUT);
        gpio_set_level(GPIO_PORT4, 20, GPIO_HIGH_LEVEL);
#endif
    } else {
        printf("Unsupported panel!\n");
    }
#if 0
#ifdef BOARD_SABRE_AI
    /*lvds/parallel display backlight enable, GPIO2_0 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD4_DAT1, ALT5);
    gpio_set_direction(GPIO_PORT2, 9, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT2, 9, GPIO_LOW_LEVEL);

    // lcd_contrast conflict with actual BoundaryDev display so seeting to input
    // since TSC not used on SABRE AI
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_DI0_PIN4, ALT5);
    gpio_set_direction(GPIO_PORT4, 20, GPIO_GDIR_INPUT);
#endif
#ifdef BOARD_SMART_DEVICE
    /* AUX_3V15 */
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_WP_B, ALT5);
    reg32_write(IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B, 0x1B0B0);
    gpio_set_direction(GPIO_PORT6, 9, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT6, 9, GPIO_HIGH_LEVEL);
    // backlight both lvds1/0, disp0_contrast/disp0_pwm, gpio1[21]
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_SD1_DAT3, ALT5);
    gpio_set_direction(GPIO_PORT1, 21, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT1, 21, GPIO_HIGH_LEVEL);
    // AUX_5V_EN LVDS0 power
    reg32_write(IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0, ALT5);
    gpio_set_direction(GPIO_PORT6, 10, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT6, 10, GPIO_HIGH_LEVEL);
#endif
#endif

}

/*! Copy from OBDS
 * Reset the TFT LCD
 */
void tftlcd_reset(char *panel_name)
{
    if (!strcmp(panel_name, "CLAA 070VC01")) {
#ifdef BOARD_EVB
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_EB3, ALT5);
        reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_EB3, 0x1B0B0);
        gpio_set_direction(GPIO_PORT2, 31, GPIO_GDIR_OUTPUT);
        gpio_set_level(GPIO_PORT2, 31, GPIO_LOW_LEVEL);
        hal_delay_us(1000);
        gpio_set_level(GPIO_PORT2, 31, GPIO_HIGH_LEVEL);
        hal_delay_us(1000);
#endif
#ifdef BOARD_SMART_DEVICE
        reg32_write(IOMUXC_SW_MUX_CTL_PAD_EIM_DA8, ALT5);
        reg32_write(IOMUXC_SW_PAD_CTL_PAD_EIM_DA8, 0x1B0B0);
        gpio_set_direction(GPIO_PORT3, 8, GPIO_GDIR_OUTPUT);
        gpio_set_level(GPIO_PORT3, 8, GPIO_LOW_LEVEL);
        hal_delay_us(1000);
        gpio_set_level(GPIO_PORT3, 8, GPIO_HIGH_LEVEL);
        hal_delay_us(1000);
#endif
    }
}

/*!
 * @brief Configure ldb clock as per the display resolution.
 *
 * ldb clock is derived from PLL5, ldb on ipu1
 */
void ldb_clock_config(int freq, int ipu_index)
{
    if (freq == 65000000)       //for XGA resolution
    {
        //config pll3 PFD1 to 455M. pll3 is 480M 
        BW_CCM_ANALOG_PFD_480_PFD1_FRAC(19);

        // set ldb_di0_clk_sel to PLL3 PFD1
        HW_CCM_CS2CDR.B.LDB_DI0_CLK_SEL = 3;
        HW_CCM_CS2CDR.B.LDB_DI1_CLK_SEL = 3;

        // set clk_div to 7
        HW_CCM_CSCMR2.B.LDB_DI0_IPU_DIV = 1;
        HW_CCM_CSCMR2.B.LDB_DI1_IPU_DIV = 1;

        if (ipu_index == 1) {
            //set ipu1_di0_clk_sel from ldb_di0_clk 
            HW_CCM_CHSCCDR.B.IPU1_DI0_CLK_SEL = 3;  // ldb_di0_clk
            HW_CCM_CHSCCDR.B.IPU1_DI1_CLK_SEL = 3;  // ldb_di0_clk
        }
#if CHIP_MX6DQ
        else {
            //set ipu2_di0_clk_sel from ldb_di0_clk 
            HW_CCM_CSCDR2.B.IPU2_DI0_CLK_SEL = 3;
            HW_CCM_CSCDR2.B.IPU2_DI1_CLK_SEL = 3;
        }
#endif // CHIP_MX6DQ
    } else {
        printf("The frequency %d for LDB is not supported yet.", freq);
    }
}

void epdc_clock_setting(int freq)
{
#if defined(CHIP_MX6SDL)
    HW_CCM_CSCDR2.B.EPDC_PIX_PRE_CLK_SEL = 0x3; // 307M PFD

    HW_CCM_CSCDR2.B.EPDC_PIX_CLK_SEL = 0x0;

    /*set the output as 271M */
    BW_CCM_ANALOG_PFD_528_PFD0_FRAC(0x23);

    HW_CCM_CSCDR2.B.EPDC_PIX_PODF = 0x7;    // post divider

//  HW_IOMUXC_SW_MUX_CTL_PAD_GPIO_3.B.MUX_MODE = 0x4; //set as clko
#endif

#if defined(CHIP_MX6SL)
    HW_CCM_CSCDR2.B.EPDC_PIX_CLK_SEL = 0x5; //Use 540MPFD

    HW_CCM_CSCDR2.B.EPDC_PIX_PRED = 0x5;    //pred for EPDC

    HW_CCM_CBCMR.B.EPDC_PIX_PODF = 0x4;

    /*set the AXI clock, divided from MMDC clock */
    HW_CCM_CHSCCDR.B.EPDC_AXI_CLK_SEL = 0x0;
    HW_CCM_CHSCCDR.B.EPDC_AXI_PODF = 0x1;
#endif
}

void epdc_power_supply(void)
{
    int i = 0;
#if defined(CHIP_MX6SDL)
#if defined(BOARD_EVB)
    /*PMIC wakeup */
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_EB3.B.MUX_MODE = 0x5;
    gpio_set_direction(GPIO_PORT2, 31, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT2, 31, GPIO_HIGH_LEVEL);

    /*PMIC vcom */
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_DATA17.B.MUX_MODE = 0x5;
    gpio_set_direction(GPIO_PORT3, 17, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT3, 17, GPIO_HIGH_LEVEL);
#elif defined(BOARD_SMART_DEVICE)
    /*PMIC wakeup */
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_DATA20.B.MUX_MODE = 0x5;
    gpio_set_direction(GPIO_PORT3, 20, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT3, 20, GPIO_HIGH_LEVEL);

    /*PMIC vcom */
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_DATA17.B.MUX_MODE = 0x5;
    gpio_set_direction(GPIO_PORT3, 17, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT3, 17, GPIO_HIGH_LEVEL);
#endif
#endif

#if defined(CHIP_MX6SL)
    //EN : pmic_wakeup gpio2.14
    HW_IOMUXC_SW_MUX_CTL_PAD_EPDC_PWR_WAKE.B.MUX_MODE = 0x5;
    gpio_set_direction(GPIO_PORT2, 14, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT2, 14, GPIO_HIGH_LEVEL);

    //CEN : pmic_vcom gpio2.3
    HW_IOMUXC_SW_MUX_CTL_PAD_EPDC_VCOM0.B.MUX_MODE = 0x5;
    gpio_set_direction(GPIO_PORT2, 3, GPIO_GDIR_OUTPUT);
    gpio_set_level(GPIO_PORT2, 3, GPIO_HIGH_LEVEL);
#endif
    for (i = 0; i < 1000000; i++)
        __asm("nop");
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
