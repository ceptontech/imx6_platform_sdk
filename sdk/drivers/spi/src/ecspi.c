/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
#include "ecspi.h"
#include "spi/ecspi_ifc.h"
#include "iomux_config.h"
#include "registers/regsecspi.h"
#include "timer/timer.h"

static void ecspi_start_transfer(unsigned instance, uint16_t brs_bts);
static int ecspi_xfer_slv(unsigned instance, const uint8_t * tx_buf, uint8_t * rx_buf, int bytes);
static int ecspi_xfer_mst(unsigned instance, const uint8_t * tx_buf, uint8_t * rx_buf, int bytes);

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

static void ecspi_start_transfer(unsigned instance, uint16_t brs_bts)
{
    // Set burst length 
    HW_ECSPI_CONREG(instance).B.BURST_LENGTH = brs_bts - 1;

    // Clear status 
    HW_ECSPI_STATREG_WR(instance, BM_ECSPI_STATREG_RO | BM_ECSPI_STATREG_TC);
}

static int ecspi_xfer_slv(unsigned instance, const uint8_t * tx_buf, uint8_t * rx_buf, int bytes)
{
    printf("Slave mode transfer code not implemented yet.\n");
    return FAIL;
}

//! @brief Perform a SPI master transfer.
//!
//! @param instance ECSPI module instance number starting at 1.
//! @param tx_buf
//! @param rx_buf
//! @param bytes Number of bytes to transfer.
//!
//! @todo Use interrupts to get notification of transfer completion instead of
//!     polling the ECSPI STATREG and pausing 500 µs.
static int ecspi_xfer_mst(unsigned instance, const uint8_t * tx_buf, uint8_t * rx_buf, int bytes)
{
    uint32_t val;
    uint32_t idx;

    // Start burst 
    HW_ECSPI_CONREG_SET(instance, BM_ECSPI_CONREG_SMC);

    // Write to Tx FIFO 
    val = 0;
    for (idx = 0; idx < bytes; idx += 4)
    {
        // Only read from the buffer if it is not NULL. If a tx_buf is not provided,
        // then transfer 0 bytes.
        if (tx_buf)
        {
            val = tx_buf[idx] + (tx_buf[idx + 1] << 8) + (tx_buf[idx + 2] << 16) + (tx_buf[idx + 3] << 24);
        }

        HW_ECSPI_TXDATA_WR(instance, val);
    }

    // Wait for transfer complete 
    val = SPI_RETRY_TIMES;
    while (!HW_ECSPI_STATREG(instance).B.TC)
    {
        val--;
        if (val == 0)
        {
#if DEBUG
            printf("ecspi_xfer: Transfer timeout.\n");
#endif
            return FAIL;
        }

        hal_delay_us(500);
    }

    // Read from Rx FIFO 
    for (idx = 0; bytes > 0; bytes -= 4, idx += 4)
    {
        val = HW_ECSPI_RXDATA_RD(instance);

        if (rx_buf)
        {
            switch (bytes)
            {
                default:
                    rx_buf[idx + 3] = val >> 24;
                case 3:
                    rx_buf[idx + 2] = (val >> 16) & 0xFF;
                case 2:
                    rx_buf[idx + 1] = (val >> 8) & 0xFF;
                case 1:
                    rx_buf[idx] = val & 0xFF;
                    break;
            }
        }
    }

    // Clear status 
    HW_ECSPI_STATREG_WR(instance, BM_ECSPI_STATREG_TC);

    return SUCCESS;
}

int ecspi_configure(dev_ecspi_e instance, const param_ecspi_t * param)
{
    // Reset eCSPI controller 
    HW_ECSPI_CONREG(instance).B.EN = 0;

    // Setup chip select 
    HW_ECSPI_CONREG(instance).B.CHANNEL_SELECT = param->channel;

    // Setup mode 
    uint32_t channelMask = 1 << param->channel;
    uint32_t value = HW_ECSPI_CONREG(instance).B.CHANNEL_MODE;
    BW_ECSPI_CONREG_CHANNEL_MODE(instance, param->mode ? (value | channelMask) : (value & ~channelMask));

    // Setup pre & post clock divider 
    HW_ECSPI_CONREG(instance).B.PRE_DIVIDER = (param->pre_div == 0) ? 0 : (param->pre_div - 1);
    HW_ECSPI_CONREG(instance).B.POST_DIVIDER = (param->post_div == 0) ? 0 : (param->post_div - 1);

    // Enable eCSPI 
    HW_ECSPI_CONREG(instance).B.EN = 1;

    // Setup SCLK_PHA, SCLK_POL, SS_POL 
    value = HW_ECSPI_CONFIGREG(instance).B.SCLK_PHA;
    HW_ECSPI_CONFIGREG(instance).B.SCLK_PHA = param->sclk_pha ? (value | channelMask) : (value & ~channelMask);
    
    value = HW_ECSPI_CONFIGREG(instance).B.SCLK_POL;
    HW_ECSPI_CONFIGREG(instance).B.SCLK_POL = param->sclk_pol ? (value | channelMask) : (value & ~channelMask);
    
    value = HW_ECSPI_CONFIGREG(instance).B.SS_POL;
    HW_ECSPI_CONFIGREG(instance).B.SS_POL = param->ss_pol ? (value | channelMask) : (value & ~channelMask);
    
    HW_ECSPI_CONFIGREG(instance).B.SS_CTL |= channelMask;
    
    return SUCCESS;
}

//! @todo Validate @a dev value for the chip, since not all chips will have all 5 instances.
int ecspi_open(dev_ecspi_e dev, const param_ecspi_t * param)
{
    // Configure clock gating here if necessary 

    // Configure IO signals 
    ecspi_iomux_config(dev);

    // Configure eCSPI registers 
    ecspi_configure(dev, param);

    return SUCCESS;
}

int ecspi_close(dev_ecspi_e dev)
{
    // Disable controller 
    HW_ECSPI_CONREG(dev).B.EN = 0;

    return SUCCESS;
}

//! @todo Handle tranfers larger than the FIFO length!
int ecspi_xfer(dev_ecspi_e dev, const uint8_t * tx_buf, uint8_t * rx_buf, uint16_t brs_bts)
{
    uint32_t retv = SUCCESS;

    // Set bytes for burst 
    int bytes = brs_bts >> 3;

    // Handle non-byte-aligned bits 
    if ((brs_bts & 0x7) != 0)
    {
        bytes++;
    }

    // Check burst length 
    if (bytes > ECSPI_FIFO_SIZE * 4)
    {
#if DEBUG
        printf("ecspi_xfer: Burst out of length.\n");
#endif
        retv = FAIL;
    }

    if (retv == SUCCESS)
    {
        // Prepare transfer 
        ecspi_start_transfer(dev, brs_bts);

        // Initiate transfer  
        uint32_t channel = HW_ECSPI_CONREG(dev).B.CHANNEL_SELECT;

        // Handle different mode transfer 
        if ((HW_ECSPI_CONREG(dev).B.CHANNEL_MODE & (1 << channel)) == 0)
        {
            retv = ecspi_xfer_slv(dev, tx_buf, rx_buf, bytes);
        }
        else
        {
            retv = ecspi_xfer_mst(dev, tx_buf, rx_buf, bytes);
        }
    }

    return retv;
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
