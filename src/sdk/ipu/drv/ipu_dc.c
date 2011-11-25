/*
 * Copyright (C) 2010-2011, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ipu_dc.c
 * @brief display controller configuration of IPU.
 * @ingroup diag_ipu
 */
#include "ipu_common.h"

extern inline int need_csc(int i, int o);

/*!
 * DC submodule configuration.
 * DC submodule is to control the data, and tranfer them to display.
 * @param	ipu_index:	ipu index
 * @param	conf:		ipu configuration data structure
 */
void ipu_dc_config(uint32_t ipu_index, uint32_t channel, uint32_t di, uint32_t width,
                   uint32_t colorimetry)
{
    dc_microcode_t microcode = { 0 };
    uint32_t de_pointer = 0;
    uint32_t disp_port = 2;     //up to 4 display is supported by one IPU.

    microcode.addr = 1;
    microcode.stop = 1;
    microcode.opcode = WROD;
    microcode.lf = 0;
    microcode.af = 0;
    microcode.operand = 0;
    microcode.mapping = 2;      //select map conf 2
    microcode.waveform = de_pointer + 1;    //DI#_DE_GEN_#de_pointer
    microcode.gluelogic = 0;    //cs mode
    microcode.sync = 5;         //sync with unit #5
    ipu_dc_microcode_config(ipu_index, microcode);

    /*link event to routines */
    ipu_dc_microcode_event(ipu_index, 5, NEW_DATA, 1, 1);
    ipu_dc_microcode_event(ipu_index, 5, NL, 3, 2);
    ipu_dc_microcode_event(ipu_index, 5, EOL, 2, 3);

    /*new line event */
    microcode.addr = 2;
    microcode.stop = 1;
    microcode.opcode = WROD;
    microcode.lf = 0;
    microcode.af = 0;
    microcode.operand = 0;
    microcode.mapping = 2;
    microcode.waveform = de_pointer + 1;
    microcode.gluelogic = 8;
    microcode.sync = 5;
    ipu_dc_microcode_config(ipu_index, microcode);

    /*end of line event */
    microcode.addr = 3;
    microcode.stop = 1;
    microcode.opcode = WROD;
    microcode.lf = 0;
    microcode.af = 0;
    microcode.operand = 0;
    microcode.mapping = 2;
    microcode.waveform = de_pointer + 1;
    microcode.gluelogic = 4;
    microcode.sync = 5;
    ipu_dc_microcode_config(ipu_index, microcode);

    /*WRITE_CHAN configuration */
    ipu_dc_write_channel_config(ipu_index, channel, disp_port, di, 0);

    /*DISP_CONF configuration */
    //paralell display without enable support, address auto incremented by 1
    ipu_dc_display_config(ipu_index, disp_port, 2, 0, width - 1);

    /*DC_MAP configuration */
    ipu_dc_map(ipu_index, 1, colorimetry);

}

/*
* config the write channel for display.
* different channels linked to different display port
*/
int ipu_dc_write_channel_config(int ipu_index, int dma_channel, int disp_port, int link_di_index,
                                int field_mode_enable)
{
    switch (dma_channel) {
    case 23:
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__PROG_START_TIME_5, 0);
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__CHAN_MASK_DEFAULT_5, 0);
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__PROG_CHAN_TYP_5, 4);    //Normal mode without anti-tearing
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__PROG_DISP_ID_5, disp_port);
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__PROG_DI_ID_5, link_di_index);

        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__W_SIZE_5, 2);   //Component size access to DC set to 24bit
        ipu_write_field(ipu_index, IPU_DC_WR_CH_ADDR_5__ST_ADDR_5, 0);
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__FIELD_MODE_5, field_mode_enable);

        ipu_write_field(ipu_index, IPU_DC_GEN__SYNC_PRIORITY_1, 1); //sets the priority of channel #5 to high.
        ipu_write_field(ipu_index, IPU_DC_GEN__SYNC_PRIORITY_5, 1); //sets the priority of channel #5 to high.
        ipu_write_field(ipu_index, IPU_DC_GEN__SYNC_1_6, 2);    //Channel 1 of the DC handless sync flow
        ipu_write_field(ipu_index, IPU_DC_GEN__MASK_EN, 0); // mask channel is disabled
        ipu_write_field(ipu_index, IPU_DC_GEN__DC_CH5_TYPE, 0); // alternate sync or asyn flow
        break;
    case 28:
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_1__PROG_START_TIME_1, 0);
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_1__CHAN_MASK_DEFAULT_1, 0);
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_1__PROG_CHAN_TYP_1, 4);    //Normal mode without anti-tearing
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_1__PROG_DISP_ID_1, disp_port);
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_1__PROG_DI_ID_1, link_di_index);

        /* if CH28 is connected to DI0, CH23 must connect to DI1 even if it is not used. */
        if (link_di_index == 0)
            ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_5__PROG_DI_ID_5, 1);

        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_1__W_SIZE_1, 2);   //Component size access to DC set to 24bit
        ipu_write_field(ipu_index, IPU_DC_WR_CH_ADDR_1__ST_ADDR_1, 0);  //START ADDRESS OF CHANNEL
        ipu_write_field(ipu_index, IPU_DC_WR_CH_CONF_1__FIELD_MODE_1, field_mode_enable);

        ipu_write_field(ipu_index, IPU_DC_GEN__SYNC_PRIORITY_1, 1); //sets the priority of channel #5 to high.
        ipu_write_field(ipu_index, IPU_DC_GEN__SYNC_1_6, 2);    //Channel 1 of the DC handless sync flow
        break;
    default:
        printf("Display channel wrong!\n");
        return -1;
    }

    return 0;
}

/*
*  config the display port in the DC
*/
int ipu_dc_display_config(int ipu_index, int display_port, int type, int increment, int strideline)
{
    switch (display_port) {
    case 0:
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF1_0__DISP_TYP_0, type);  //paralel display without byte enable
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF1_0__ADDR_INCREMENT_0, increment);   //automatical address increase by 1
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF2_0__SL_0, strideline);  //stride line
        break;
    case 1:
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF1_1__DISP_TYP_1, type);  //paralel display without byte enable
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF1_1__ADDR_INCREMENT_1, increment);   //automatical address increase by 1
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF2_1__SL_1, strideline);  //stride line
        break;
    case 2:
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF1_2__DISP_TYP_2, type);  //paralel display without byte enable
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF1_2__ADDR_INCREMENT_2, increment);   //automatical address increase by 1
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF2_2__SL_2, strideline);  //stride line
        break;
    case 3:
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF1_3__DISP_TYP_3, type);  //paralel display without byte enable
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF1_3__ADDR_INCREMENT_3, increment);   //automatical address increase by 1
        ipu_write_field(ipu_index, IPU_DC_DISP_CONF2_3__SL_3, strideline);  //stride line
        break;
    default:
        printf("Display port wrong!\n");
        return false;
    }
    return true;
}

int ipu_dc_map(int ipu_index, int map, int format)
{
    int offset[3], mask[3];

    switch (format) {
    case DCMAP_RGB565:
        offset[0] = 15;
        mask[0] = 0xF8;
        offset[1] = 10;
        mask[1] = 0xFC;
        offset[2] = 4;
        mask[2] = 0xF8;
        break;
    case DCMAP_RGB666:
        offset[0] = 17;
        mask[0] = 0xFC;
        offset[1] = 11;
        mask[1] = 0xFC;
        offset[2] = 5;
        mask[2] = 0xFC;
        break;
    case DCMAP_RGB666H:
        offset[0] = 21;
        mask[0] = 0xFC;
        offset[1] = 13;
        mask[1] = 0xFC;
        offset[2] = 5;
        mask[2] = 0xFC;
        break;
    case DCMAP_RGB888:
    case DCMAP_YUV888:
        offset[0] = 23;
        mask[0] = 0xFF;
        offset[1] = 15;
        mask[1] = 0xFF;
        offset[2] = 7;
        mask[2] = 0xFF;
        break;
    case DCMAP_GBR888:
    case DCMAP_UVY888:
        offset[0] = 15;
        mask[0] = 0xFF;
        offset[1] = 7;
        mask[1] = 0xFF;
        offset[2] = 23;
        mask[2] = 0xFF;
        break;
    case DCMAP_BRG888:
    case DCMAP_VYU888:
        offset[0] = 7;
        mask[0] = 0xFF;
        offset[1] = 23;
        mask[1] = 0xFF;
        offset[2] = 15;
        mask[2] = 0xFF;
        break;
    default:
        printf("Unkown data type!!\n");
        return -1;
    }

    switch (map) {
    case 0:
        //DC_MAP, should be RGB666 mode
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_16__MD_OFFSET_2, offset[0]);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_16__MD_MASK_2, mask[0]);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_15__MD_OFFSET_1, offset[1]);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_15__MD_MASK_1, mask[1]);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_15__MD_OFFSET_0, offset[2]);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_15__MD_MASK_0, mask[2]);

        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_0__MAPPING_PNTR_BYTE2_0, 2);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_0__MAPPING_PNTR_BYTE1_0, 1);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_0__MAPPING_PNTR_BYTE0_0, 0);
        break;

    case 1:
        //DC_MAP
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_18__MD_OFFSET_6, offset[0]);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_18__MD_MASK_6, mask[0]);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_17__MD_OFFSET_5, offset[1]);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_17__MD_MASK_5, mask[1]);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_17__MD_OFFSET_4, offset[2]);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_17__MD_MASK_4, mask[2]);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_0__MAPPING_PNTR_BYTE2_1, 6);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_0__MAPPING_PNTR_BYTE1_1, 5);
        ipu_write_field(ipu_index, IPU_DC_MAP_CONF_0__MAPPING_PNTR_BYTE0_1, 4);
        break;

    default:
        printf("Map pointer not support yet!\n");
        return -1;
    }

    return 0;
}

/*
* microcode configuration, refer to ipuv3 spec
*/
void ipu_dc_microcode_config(int ipu_index, dc_microcode_t microcode)
{
    unsigned int LowWord = 0;
    unsigned int HighWord = 0;
    unsigned int opcode_fixed;
    unsigned int ipu_base_addr = 0;

    if (ipu_index == 1)
        ipu_base_addr = IPU1_CTRL_BASE_ADDR;
    else
        ipu_base_addr = IPU2_CTRL_BASE_ADDR;

    switch (microcode.opcode) {
    case HLG:
        LowWord = LowWord | (microcode.operand << 5);

        HighWord = HighWord | (microcode.operand >> 27);
        opcode_fixed = 0x0;
        HighWord = HighWord | (opcode_fixed << 5);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case WROD:
        /*write data to display */
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0x18 | (microcode.lf << 1);
        HighWord = HighWord | (opcode_fixed << 4);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case HLOAR:
        microcode.sync = 0;
        microcode.gluelogic = 0;
        microcode.waveform = 0;
        microcode.operand = 0;
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0x8E | (microcode.af << 0);
        HighWord = HighWord | (opcode_fixed << 1);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case WROAR:
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0xCE | (microcode.af << 0);
        HighWord = HighWord | (opcode_fixed << 1);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case HLODR:
        microcode.sync = 0;
        microcode.gluelogic = 0;
        microcode.waveform = 0;
        microcode.operand = 0;
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0x8C;
        HighWord = HighWord | (opcode_fixed << 1);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case WRODR:
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0xCC;
        HighWord = HighWord | (opcode_fixed << 1);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case WRBC:
        microcode.operand = 0;
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        opcode_fixed = 0x19B;
        HighWord = HighWord | (opcode_fixed << 0);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case WCLK:
        microcode.sync = 0;
        microcode.gluelogic = 0;
        microcode.waveform = 0;
        microcode.mapping = 0;
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0xC9;
        HighWord = HighWord | (opcode_fixed << 1);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case WSTSIII:
        microcode.stop = 0;
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0x8B;
        HighWord = HighWord | (opcode_fixed << 1);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case WSTSII:
        microcode.stop = 0;
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0x8A;
        HighWord = HighWord | (opcode_fixed << 1);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case WSTSI:
        microcode.stop = 0;
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0x89;
        HighWord = HighWord | (opcode_fixed << 1);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case HLOA:
        microcode.sync = 0;
        microcode.gluelogic = 0;
        microcode.waveform = 0;
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0x14 | (microcode.af << 0);
        HighWord = HighWord | (opcode_fixed << 4);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case WROA:
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0x1C | (microcode.af << 0);
        HighWord = HighWord | (opcode_fixed << 4);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case HLOD:
        microcode.sync = 0;
        microcode.gluelogic = 0;
        microcode.waveform = 0;
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0x10;
        HighWord = HighWord | (opcode_fixed << 4);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case WRG:
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.operand << 15);

        HighWord = HighWord | (microcode.operand >> 17);
        opcode_fixed = 1;
        HighWord = HighWord | (opcode_fixed << 7);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case RD:
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        HighWord = HighWord | (microcode.operand >> 12);
        opcode_fixed = 0x88;
        HighWord = HighWord | (opcode_fixed << 1);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case WACK:
        microcode.mapping = 0;
        microcode.operand = 0;
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.mapping << 15);
        LowWord = LowWord | (microcode.operand << 20);

        opcode_fixed = 0x11A;
        HighWord = HighWord | (opcode_fixed << 0);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case HMA:
        LowWord = LowWord | (microcode.operand << 5);
        opcode_fixed = 0x2;
        HighWord = HighWord | (opcode_fixed << 5);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case BMA:
        opcode_fixed = 0x3;
        HighWord = HighWord | (opcode_fixed << 5);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    case MSK:
        microcode.sync = 0;
        microcode.gluelogic = 0;
        microcode.waveform = 0;
        microcode.stop = 0;
        LowWord = LowWord | microcode.sync;
        LowWord = LowWord | (microcode.gluelogic << 4);
        LowWord = LowWord | (microcode.waveform << 11);
        LowWord = LowWord | (microcode.operand << 15);

        HighWord = HighWord | (microcode.operand >> 17);
        opcode_fixed = 0xC8;
        HighWord = HighWord | (opcode_fixed << 1);
        HighWord = HighWord | (microcode.stop << 9);
        break;

    default:
        printf("Wrong opcode type of DC!!\n");
        return;
    }

    writel(LowWord, ipu_base_addr + IPU_MEM_DC_MICROCODE_BASE_ADDR + microcode.addr * 8);
    writel(HighWord, ipu_base_addr + IPU_MEM_DC_MICROCODE_BASE_ADDR + microcode.addr * 8 + 4);
}

/*
* microcode event configuration, to handle different event
*/
void ipu_dc_microcode_event(int ipu_index, int channel, int event, int priority, int address)
{
    int channel_offset = (channel >= 5) ? (0x5C + (channel - 5) * 0x1C) : channel * 0x1C;

    switch (event) {
    case NL:
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL0_CH_0__COD_NL_START_CHAN_0, address);
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL0_CH_0__COD_NL_PRIORITY_CHAN_0,
                        priority);
        break;

    case NF:
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL0_CH_0__COD_NF_START_CHAN_0, address);
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL0_CH_0__COD_NF_PRIORITY_CHAN_0,
                        priority);
        break;

    case NFIELD:
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL1_CH_0__COD_NFIELD_START_CHAN_0,
                        address);
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL1_CH_0__COD_NFIELD_PRIORITY_CHAN_0,
                        priority);
        break;

    case DCEOF:
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL1_CH_0__COD_EOF_START_CHAN_0, address);
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL1_CH_0__COD_EOF_PRIORITY_CHAN_0,
                        priority);
        break;

    case EOFIELD:
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL2_CH_0__COD_EOFIELD_START_CHAN_0,
                        address);
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL2_CH_0__COD_EOFIELD_PRIORITY_CHAN_0,
                        priority);
        break;

    case EOL:
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL2_CH_0__COD_EOL_START_CHAN_0, address);
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL2_CH_0__COD_EOL_PRIORITY_CHAN_0,
                        priority);
        break;

    case NEW_CHAN:
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL3_CH_0__COD_NEW_CHAN_START_CHAN_0,
                        address);
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL3_CH_0__COD_NEW_CHAN_PRIORITY_CHAN_0,
                        priority);
        break;

    case NEW_ADDR:
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL3_CH_0__COD_NEW_ADDR_START_CHAN_0,
                        address);
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL3_CH_0__COD_NEW_ADDR_PRIORITY_CHAN_0,
                        priority);
        break;

    case NEW_DATA:
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL4_CH_0__COD_NEW_DATA_START_CHAN_0,
                        address);
        ipu_write_field(ipu_index, channel_offset + IPU_DC_RL4_CH_0__COD_NEW_DATA_PRIORITY_CHAN_0,
                        priority);
        break;

    default:
        printf("Wrong DC microcode event!!\n");
        return;
    }

    return;
}