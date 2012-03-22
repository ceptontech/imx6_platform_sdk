/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file sdk_ipu_common.c.c
 * @brief IPU routines.
 *
 * @ingroup diag_enet
 */

#include "gpu/inc/sdk_ipu_common.h"

/* global IPU variables */
int channel;
int xv;
int yv;
int xb;
int yb;
int nsb_b;
int cf;
int sx;
int sy;
int ns;
int sdx;
int sm;
int scc;
int sce;
int sdy;
int sdrx;
int sdry;
int bpp;
int dec_sel;
int dim;
int so;
int bndm;
int bm;
int rot;
int hf;
int vf;
int the;
int cap;
int cae;
int fw;
int fh;
int eba0;
int eba1;
int ilo;
int npb;
int pfs;
int alu;
int albm;
int id;
int th;
int sl;
int wid0;
int wid1;
int wid2;
int wid3;
int ofs0;
int ofs1;
int ofs2;
int ofs3;
int ubo;
int vbo;
int rdrw;
int sly;
int sluv;
int ipu_num;

void sdk_ipu_write_field(WORD IPU, WORD ID_addr, WORD ID_mask, WORD data)
{

    WORD rdata;
    WORD IPU_BASE_ADDRE=0;

    if (IPU == 1)
        IPU_BASE_ADDRE = IPU1_BASE_ADDR;
    else if (IPU == 2)
        IPU_BASE_ADDRE = IPU2_BASE_ADDR;

    ID_addr += IPU_BASE_ADDRE;
    rdata = reg32_read(ID_addr);
    rdata &= ~ID_mask;
    rdata |= (data * (ID_mask & -ID_mask)) & ID_mask;
    reg32_write(ID_addr, rdata);
}

static void init_idmac_parameters()
{
    ipu_num = 1;
    channel = 0;
    xv = 0;
    yv = 0;
    xb = 0;
    yb = 0;
    nsb_b = 0;
    cf = 0;
    sx = 0;
    sy = 0;
    ns = 0;
    sdx = 0;
    sm = 0;
    scc = 0;
    sce = 0;
    sdy = 0;
    sdrx = 0;
    sdry = 0;
    bpp = 0;
    dec_sel = 0;
    dim = 0;
    so = 0;
    bndm = 0;
    bm = 0;
    rot = 0;
    hf = 0;
    vf = 0;
    the = 0;
    cap = 0;
    cae = 0;
    fw = 0;
    fh = 0;
    eba0 = 0;
    eba1 = 0;
    ilo = 0;
    npb = 0;
    pfs = 0;
    alu = 0;
    albm = 0;
    id = 0;
    th = 0;
    sl = 0;
    wid0 = 0;
    wid1 = 0;
    wid2 = 0;
    wid3 = 0;
    ofs0 = 0;
    ofs1 = 0;
    ofs2 = 0;
    ofs3 = 0;
    ubo = 0;
    vbo = 0;
    rdrw = 0;
    sly = 0;
    sluv = 0;
}

static void config_idmac_interleaved_channel()
{
    WORD IPU_BASE_ADDRE=0;
    int w0_d0 = 0, w0_d1 = 0, w0_d2 = 0, w0_d3 = 0, w0_d4 = 0, w1_d0 = 0, w1_d1 = 0, w1_d2 =
        0, w1_d3 = 0, w1_d4 = 0;

    if (ipu_num == 1)
        IPU_BASE_ADDRE = IPU1_BASE_ADDR;
    else if (ipu_num == 2)
        IPU_BASE_ADDRE = IPU2_BASE_ADDR;

    w0_d0 = xb << 19 | yv << 10 | xv;
    w0_d1 = sy << 26 | sx << 14 | cf << 13 | nsb_b << 12 | yb;
    w0_d2 = sm << 22 | sdx << 15 | ns << 5 | sy >> 6;
    w0_d3 =
        fw << 29 | cae << 28 | cap << 27 | the << 26 | vf << 25 | hf << 24 | rot << 23 | bm << 21 |
        bndm << 18 | so << 17 | dim << 16 | dec_sel << 14 | bpp << 11 | sdry << 10 | sdrx << 9 | sdy
        << 2 | sce << 1 | scc;
    w0_d4 = fh << 10 | fw >> 3;

    w1_d0 = eba1 << 29 | eba0;
    w1_d1 = ilo << 26 | eba1 >> 3;
    w1_d2 = th << 31 | id << 29 | albm << 26 | alu << 25 | pfs << 21 | npb << 14 | ilo >> 6;
    w1_d3 = wid3 << 29 | wid2 << 26 | wid1 << 23 | wid0 << 20 | sl << 6 | th >> 1;
    w1_d4 = ofs3 << 15 | ofs2 << 10 | ofs1 << 5 | ofs0;

    reg32_write(IPU_BASE_ADDRE + CPMEM_WORD0_DATA0_INT__ADDR + (channel << 6), w0_d0);
    reg32_write(IPU_BASE_ADDRE + CPMEM_WORD0_DATA1_INT__ADDR + (channel << 6), w0_d1);
    reg32_write(IPU_BASE_ADDRE + CPMEM_WORD0_DATA2_INT__ADDR + (channel << 6), w0_d2);
    reg32_write(IPU_BASE_ADDRE + CPMEM_WORD0_DATA3_INT__ADDR + (channel << 6), w0_d3);
    reg32_write(IPU_BASE_ADDRE + CPMEM_WORD0_DATA4_INT__ADDR + (channel << 6), w0_d4);

    reg32_write(IPU_BASE_ADDRE + CPMEM_WORD1_DATA0_INT__ADDR + (channel << 6), w1_d0);
    reg32_write(IPU_BASE_ADDRE + CPMEM_WORD1_DATA1_INT__ADDR + (channel << 6), w1_d1);
    reg32_write(IPU_BASE_ADDRE + CPMEM_WORD1_DATA2_INT__ADDR + (channel << 6), w1_d2);
    reg32_write(IPU_BASE_ADDRE + CPMEM_WORD1_DATA3_INT__ADDR + (channel << 6), w1_d3);
    reg32_write(IPU_BASE_ADDRE + CPMEM_WORD1_DATA4_INT__ADDR + (channel << 6), w1_d4);
}

static void microcode_event(int ipu_num, int channel, int event, int priority, int address)
{

//*************************************************************************************   
    if (channel == 0) {
        switch (event) {
        case NL:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL0_CH_0__COD_NL_START_CHAN_0, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL0_CH_0__COD_NL_PRIORITY_CHAN_0, priority);
            break;              //NL
        case NF:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL0_CH_0__COD_NF_START_CHAN_0, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL0_CH_0__COD_NF_PRIORITY_CHAN_0, priority);
            break;              //NF
        case NFIELD:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL1_CH_0__COD_NFIELD_START_CHAN_0, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL1_CH_0__COD_NFIELD_PRIORITY_CHAN_0, priority);
            break;              //NFIELD
        case EOF_:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL1_CH_0__COD_EOF_START_CHAN_0, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL1_CH_0__COD_EOF_PRIORITY_CHAN_0, priority);
            break;              //EOF_
        case EOFIELD:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL2_CH_0__COD_EOFIELD_START_CHAN_0, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL2_CH_0__COD_EOFIELD_PRIORITY_CHAN_0, priority);
            break;              //EOFIELD
        case EOL:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL2_CH_0__COD_EOL_START_CHAN_0, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL2_CH_0__COD_EOL_PRIORITY_CHAN_0, priority);
            break;              //EOL
        case NEW_CHAN:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL3_CH_0__COD_NEW_CHAN_START_CHAN_0, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL3_CH_0__COD_NEW_CHAN_PRIORITY_CHAN_0, priority);
            break;              //NEW_CHAN
        case NEW_ADDR:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL3_CH_0__COD_NEW_ADDR_START_CHAN_0, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL3_CH_0__COD_NEW_ADDR_PRIORITY_CHAN_0, priority);
            break;              //NEW_ADDR
        case NEW_DATA:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL4_CH_0__COD_NEW_DATA_START_CHAN_0, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL4_CH_0__COD_NEW_DATA_PRIORITY_CHAN_0, priority);
            break;              //NEW_DATA
        }
        return;
    }                           //channel 0 ******************************************************************************

//*************************************************************************************   
    if (channel == 1) {
        switch (event) {
        case NL:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL0_CH_1__COD_NL_START_CHAN_1, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL0_CH_1__COD_NL_PRIORITY_CHAN_1, priority);
            break;              //NL
        case NF:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL0_CH_1__COD_NF_START_CHAN_1, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL0_CH_1__COD_NF_PRIORITY_CHAN_1, priority);
            break;              //NF
        case NFIELD:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL1_CH_1__COD_NFIELD_START_CHAN_1, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL1_CH_1__COD_NFIELD_PRIORITY_CHAN_1, priority);
            break;              //NFIELD
        case EOF_:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL1_CH_1__COD_EOF_START_CHAN_1, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL1_CH_1__COD_EOF_PRIORITY_CHAN_1, priority);
            break;              //EOF_
        case EOFIELD:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL2_CH_1__COD_EOFIELD_START_CHAN_1, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL2_CH_1__COD_EOFIELD_PRIORITY_CHAN_1, priority);
            break;              //EOFIELD
        case EOL:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL2_CH_1__COD_EOL_START_CHAN_1, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL2_CH_1__COD_EOL_PRIORITY_CHAN_1, priority);
            break;              //EOL
        case NEW_CHAN:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL3_CH_1__COD_NEW_CHAN_START_CHAN_1, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL3_CH_1__COD_NEW_CHAN_PRIORITY_CHAN_1, priority);
            break;              //NEW_CHAN
        case NEW_ADDR:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL3_CH_1__COD_NEW_ADDR_START_CHAN_1, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL3_CH_1__COD_NEW_ADDR_PRIORITY_CHAN_1, priority);
            break;              //NEW_ADDR
        case NEW_DATA:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL4_CH_1__COD_NEW_DATA_START_CHAN_1, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL4_CH_1__COD_NEW_DATA_PRIORITY_CHAN_1, priority);
            break;              //NEW_DATA
        }                       //channel 1 ****************************************************************************************
        return;
    }
//*************************************************************************************   
    if (channel == 2) {

        switch (event) {
        case NL:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL0_CH_2__COD_NL_START_CHAN_2, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL0_CH_2__COD_NL_PRIORITY_CHAN_2, priority);
            break;              //NL
        case NF:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL0_CH_2__COD_NF_START_CHAN_2, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL0_CH_2__COD_NF_PRIORITY_CHAN_2, priority);
            break;              //NF
        case NFIELD:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL1_CH_2__COD_NFIELD_START_CHAN_2, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL1_CH_2__COD_NFIELD_PRIORITY_CHAN_2, priority);
            break;              //NFIELD
        case EOF_:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL1_CH_2__COD_EOF_START_CHAN_2, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL1_CH_2__COD_EOF_PRIORITY_CHAN_2, priority);
            break;              //EOF_
        case EOFIELD:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL2_CH_2__COD_EOFIELD_START_CHAN_2, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL2_CH_2__COD_EOFIELD_PRIORITY_CHAN_2, priority);
            break;              //EOFIELD
        case EOL:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL2_CH_2__COD_EOL_START_CHAN_2, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL2_CH_2__COD_EOL_PRIORITY_CHAN_2, priority);
            break;              //EOL
        case NEW_CHAN:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL3_CH_2__COD_NEW_CHAN_START_CHAN_2, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL3_CH_2__COD_NEW_CHAN_PRIORITY_CHAN_2, priority);
            break;              //NEW_CHAN
        case NEW_ADDR:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL3_CH_2__COD_NEW_ADDR_START_CHAN_2, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL3_CH_2__COD_NEW_ADDR_PRIORITY_CHAN_2, priority);
            break;              //NEW_ADDR
        case NEW_DATA:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL4_CH_2__COD_NEW_DATA_START_CHAN_2, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL4_CH_2__COD_NEW_DATA_PRIORITY_CHAN_2, priority);
            break;              //NEW_DATA
        }                       //channel 2 ****************************************************************************************
    }
//*************************************************************************************   
    if (channel == 5) {
        switch (event) {
        case NL:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL0_CH_5__COD_NL_START_CHAN_5, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL0_CH_5__COD_NL_PRIORITY_CHAN_5, priority);
            break;              //NL
        case NF:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL0_CH_5__COD_NF_START_CHAN_5, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL0_CH_5__COD_NF_PRIORITY_CHAN_5, priority);
            break;              //NF
        case NFIELD:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL1_CH_5__COD_NFIELD_START_CHAN_5, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL1_CH_5__COD_NFIELD_PRIORITY_CHAN_5, priority);
            break;              //NFIELD
        case EOF_:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL1_CH_5__COD_EOF_START_CHAN_5, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL1_CH_5__COD_EOF_PRIORITY_CHAN_5, priority);
            break;              //EOF_
        case EOFIELD:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL2_CH_5__COD_EOFIELD_START_CHAN_5, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL2_CH_5__COD_EOFIELD_PRIORITY_CHAN_5, priority);
            break;              //EOFIELD
        case EOL:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL2_CH_5__COD_EOL_START_CHAN_5, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL2_CH_5__COD_EOL_PRIORITY_CHAN_5, priority);
            break;              //EOL
        case NEW_CHAN:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL3_CH_5__COD_NEW_CHAN_START_CHAN_5, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL3_CH_5__COD_NEW_CHAN_PRIORITY_CHAN_5, priority);
            break;              //NEW_CHAN
        case NEW_ADDR:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL3_CH_5__COD_NEW_ADDR_START_CHAN_5, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL3_CH_5__COD_NEW_ADDR_PRIORITY_CHAN_5, priority);
            break;              //NEW_ADDR
        case NEW_DATA:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL4_CH_5__COD_NEW_DATA_START_CHAN_5, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL4_CH_5__COD_NEW_DATA_PRIORITY_CHAN_5, priority);
            break;              //NEW_DATA
        }                       //channel 5 ****************************************************************************************
    }
//*************************************************************************************   
    if (channel == 6) {
        switch (event) {
        case NL:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL0_CH_6__COD_NL_START_CHAN_6, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL0_CH_6__COD_NL_PRIORITY_CHAN_6, priority);
            break;              //NL
        case NF:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL0_CH_6__COD_NF_START_CHAN_6, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL0_CH_6__COD_NF_PRIORITY_CHAN_6, priority);
            break;              //NF
        case NFIELD:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL1_CH_6__COD_NFIELD_START_CHAN_6, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL1_CH_6__COD_NFIELD_PRIORITY_CHAN_6, priority);
            break;              //NFIELD
        case EOF_:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL1_CH_6__COD_EOF_START_CHAN_6, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL1_CH_6__COD_EOF_PRIORITY_CHAN_6, priority);
            break;              //EOF_
        case EOFIELD:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL2_CH_6__COD_EOFIELD_START_CHAN_6, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL2_CH_6__COD_EOFIELD_PRIORITY_CHAN_6, priority);
            break;              //EOFIELD
        case EOL:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL2_CH_6__COD_EOL_START_CHAN_6, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL2_CH_6__COD_EOL_PRIORITY_CHAN_6, priority);
            break;              //EOL
        case NEW_CHAN:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL3_CH_6__COD_NEW_CHAN_START_CHAN_6, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL3_CH_6__COD_NEW_CHAN_PRIORITY_CHAN_6, priority);
            break;              //NEW_CHAN
        case NEW_ADDR:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL3_CH_6__COD_NEW_ADDR_START_CHAN_6, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL3_CH_6__COD_NEW_ADDR_PRIORITY_CHAN_6, priority);
            break;              //NEW_ADDR
        case NEW_DATA:
            sdk_ipu_write_field(ipu_num, IPU_DC_RL4_CH_6__COD_NEW_DATA_START_CHAN_6, address);
            sdk_ipu_write_field(ipu_num, IPU_DC_RL4_CH_6__COD_NEW_DATA_PRIORITY_CHAN_6, priority);
            break;              //NEW_DATA
        }                       //channel 6 ****************************************************************************************
    }

}                               //microcode_event

static void lpm_microcode_event(int ipu_num, char channel[1], char event[8], int priority,
                                int address)
{

//*************************************************************************************   
    if (!strcmp(channel, "0")) {

        if (!strcmp(event, "NL")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL0_CH_0__COD_NL_START_CHAN_0, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL0_CH_0__COD_NL_PRIORITY_CHAN_0, priority);
            //ip_rmwf_tb(0);
        }                       //NL
        if (!strcmp(event, "NF")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL0_CH_0__COD_NF_START_CHAN_0, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL0_CH_0__COD_NF_PRIORITY_CHAN_0, priority);
            //ip_rmwf_tb(0);
        }                       //NF
        if (!strcmp(event, "NFIELD")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL1_CH_0__COD_NFIELD_START_CHAN_0, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL1_CH_0__COD_NFIELD_PRIORITY_CHAN_0, priority);
            //ip_rmwf_tb(0);
        }                       //NFIELD
        if (!strcmp(event, "EOF_")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL1_CH_0__COD_EOF_START_CHAN_0, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL1_CH_0__COD_EOF_PRIORITY_CHAN_0, priority);
            //ip_rmwf_tb(0);
        }                       //EOF_
        if (!strcmp(event, "EOFIELD")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL2_CH_0__COD_EOFIELD_START_CHAN_0, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL2_CH_0__COD_EOFIELD_PRIORITY_CHAN_0,
                                priority);
            //ip_rmwf_tb(0);
        }                       //EOFIELD
        if (!strcmp(event, "EOL")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL2_CH_0__COD_EOL_START_CHAN_0, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL2_CH_0__COD_EOL_PRIORITY_CHAN_0, priority);
            //ip_rmwf_tb(0);
        }                       //EOL
        if (!strcmp(event, "NEW_CHAN")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL3_CH_0__COD_NEW_CHAN_START_CHAN_0, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL3_CH_0__COD_NEW_CHAN_PRIORITY_CHAN_0,
                                priority);
            //ip_rmwf_tb(0);
        }                       //NEW_CHAN
        if (!strcmp(event, "NEW_ADDR")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL3_CH_0__COD_NEW_ADDR_START_CHAN_0, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL3_CH_0__COD_NEW_ADDR_PRIORITY_CHAN_0,
                                priority);
            //ip_rmwf_tb(0);
        }                       //NEW_ADDR
        if (!strcmp(event, "NEW_DATA")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL4_CH_0__COD_NEW_DATA_START_CHAN_0, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL4_CH_0__COD_NEW_DATA_PRIORITY_CHAN_0,
                                priority);
            //ip_rmwf_tb(0);
        }                       //NEW_DATA
    }                           //channel 0 ******************************************************************************

//*************************************************************************************   
    if (!strcmp(channel, "1")) {

        if (!strcmp(event, "NL")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL0_CH_1__COD_NL_START_CHAN_1, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL0_CH_1__COD_NL_PRIORITY_CHAN_1, priority);
            //ip_rmwf_tb(0);
        }                       //NL
        if (!strcmp(event, "NF")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL0_CH_1__COD_NF_START_CHAN_1, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL0_CH_1__COD_NF_PRIORITY_CHAN_1, priority);
            //ip_rmwf_tb(0);
        }                       //NF
        if (!strcmp(event, "NFIELD")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL1_CH_1__COD_NFIELD_START_CHAN_1, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL1_CH_1__COD_NFIELD_PRIORITY_CHAN_1, priority);
            //ip_rmwf_tb(0);
        }                       //NFIELD
        if (!strcmp(event, "EOF_")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL1_CH_1__COD_EOF_START_CHAN_1, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL1_CH_1__COD_EOF_PRIORITY_CHAN_1, priority);
            //ip_rmwf_tb(0);
        }                       //EOF_
        if (!strcmp(event, "EOFIELD")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL2_CH_1__COD_EOFIELD_START_CHAN_1, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL2_CH_1__COD_EOFIELD_PRIORITY_CHAN_1,
                                priority);
            //ip_rmwf_tb(0);
        }                       //EOFIELD
        if (!strcmp(event, "EOL")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL2_CH_1__COD_EOL_START_CHAN_1, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL2_CH_1__COD_EOL_PRIORITY_CHAN_1, priority);
            //ip_rmwf_tb(0);
        }                       //EOL
        if (!strcmp(event, "NEW_CHAN")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL3_CH_1__COD_NEW_CHAN_START_CHAN_1, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL3_CH_1__COD_NEW_CHAN_PRIORITY_CHAN_1,
                                priority);
            //ip_rmwf_tb(0);
        }                       //NEW_CHAN
        if (!strcmp(event, "NEW_ADDR")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL3_CH_1__COD_NEW_ADDR_START_CHAN_1, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL3_CH_1__COD_NEW_ADDR_PRIORITY_CHAN_1,
                                priority);
            //ip_rmwf_tb(0);
        }                       //NEW_ADDR
        if (!strcmp(event, "NEW_DATA")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL4_CH_1__COD_NEW_DATA_START_CHAN_1, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL4_CH_1__COD_NEW_DATA_PRIORITY_CHAN_1,
                                priority);
            //ip_rmwf_tb(0);
        }                       //NEW_DATA
    }                           //channel 1 ****************************************************************************************

//*************************************************************************************   
    if (!strcmp(channel, "2")) {

        if (!strcmp(event, "NL")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL0_CH_2__COD_NL_START_CHAN_2, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL0_CH_2__COD_NL_PRIORITY_CHAN_2, priority);
            //ip_rmwf_tb(0);
        }                       //NL
        if (!strcmp(event, "NF")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL0_CH_2__COD_NF_START_CHAN_2, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL0_CH_2__COD_NF_PRIORITY_CHAN_2, priority);
            //ip_rmwf_tb(0);
        }                       //NF
        if (!strcmp(event, "NFIELD")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL1_CH_2__COD_NFIELD_START_CHAN_2, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL1_CH_2__COD_NFIELD_PRIORITY_CHAN_2, priority);
            //ip_rmwf_tb(0);
        }                       //NFIELD
        if (!strcmp(event, "EOF_")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL1_CH_2__COD_EOF_START_CHAN_2, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL1_CH_2__COD_EOF_PRIORITY_CHAN_2, priority);
            //ip_rmwf_tb(0);
        }                       //EOF_
        if (!strcmp(event, "EOFIELD")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL2_CH_2__COD_EOFIELD_START_CHAN_2, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL2_CH_2__COD_EOFIELD_PRIORITY_CHAN_2,
                                priority);
            //ip_rmwf_tb(0);
        }                       //EOFIELD
        if (!strcmp(event, "EOL")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL2_CH_2__COD_EOL_START_CHAN_2, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL2_CH_2__COD_EOL_PRIORITY_CHAN_2, priority);
            //ip_rmwf_tb(0);
        }                       //EOL
        if (!strcmp(event, "NEW_CHAN")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL3_CH_2__COD_NEW_CHAN_START_CHAN_2, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL3_CH_2__COD_NEW_CHAN_PRIORITY_CHAN_2,
                                priority);
            //ip_rmwf_tb(0);
        }                       //NEW_CHAN
        if (!strcmp(event, "NEW_ADDR")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL3_CH_2__COD_NEW_ADDR_START_CHAN_2, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL3_CH_2__COD_NEW_ADDR_PRIORITY_CHAN_2,
                                priority);
            //ip_rmwf_tb(0);
        }                       //NEW_ADDR
        if (!strcmp(event, "NEW_DATA")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL4_CH_2__COD_NEW_DATA_START_CHAN_2, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL4_CH_2__COD_NEW_DATA_PRIORITY_CHAN_2,
                                priority);
            //ip_rmwf_tb(0);
        }                       //NEW_DATA
    }                           //channel 2 ****************************************************************************************

//*************************************************************************************   
    if (!strcmp(channel, "5")) {

        if (!strcmp(event, "NL")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL0_CH_5__COD_NL_START_CHAN_5, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL0_CH_5__COD_NL_PRIORITY_CHAN_5, priority);
            //ip_rmwf_tb(0);
        }                       //NL
        if (!strcmp(event, "NF")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL0_CH_5__COD_NF_START_CHAN_5, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL0_CH_5__COD_NF_PRIORITY_CHAN_5, priority);
            //ip_rmwf_tb(0);
        }                       //NF
        if (!strcmp(event, "NFIELD")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL1_CH_5__COD_NFIELD_START_CHAN_5, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL1_CH_5__COD_NFIELD_PRIORITY_CHAN_5, priority);
            //ip_rmwf_tb(0);
        }                       //NFIELD
        if (!strcmp(event, "EOF_")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL1_CH_5__COD_EOF_START_CHAN_5, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL1_CH_5__COD_EOF_PRIORITY_CHAN_5, priority);
            //ip_rmwf_tb(0);
        }                       //EOF_
        if (!strcmp(event, "EOFIELD")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL2_CH_5__COD_EOFIELD_START_CHAN_5, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL2_CH_5__COD_EOFIELD_PRIORITY_CHAN_5,
                                priority);
            //ip_rmwf_tb(0);
        }                       //EOFIELD
        if (!strcmp(event, "EOL")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL2_CH_5__COD_EOL_START_CHAN_5, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL2_CH_5__COD_EOL_PRIORITY_CHAN_5, priority);
            //ip_rmwf_tb(0);
        }                       //EOL
        if (!strcmp(event, "NEW_CHAN")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL3_CH_5__COD_NEW_CHAN_START_CHAN_5, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL3_CH_5__COD_NEW_CHAN_PRIORITY_CHAN_5,
                                priority);
            //ip_rmwf_tb(0);
        }                       //NEW_CHAN
        if (!strcmp(event, "NEW_ADDR")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL3_CH_5__COD_NEW_ADDR_START_CHAN_5, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL3_CH_5__COD_NEW_ADDR_PRIORITY_CHAN_5,
                                priority);
            //ip_rmwf_tb(0);
        }                       //NEW_ADDR
        if (!strcmp(event, "NEW_DATA")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL4_CH_5__COD_NEW_DATA_START_CHAN_5, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL4_CH_5__COD_NEW_DATA_PRIORITY_CHAN_5,
                                priority);
            //ip_rmwf_tb(0);
        }                       //NEW_DATA
    }                           //channel 5 ****************************************************************************************

//*************************************************************************************   
    if (!strcmp(channel, "6")) {

        if (!strcmp(event, "NL")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL0_CH_6__COD_NL_START_CHAN_6, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL0_CH_6__COD_NL_PRIORITY_CHAN_6, priority);
            //ip_rmwf_tb(0);
        }                       //NL
        if (!strcmp(event, "NF")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL0_CH_6__COD_NF_START_CHAN_6, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL0_CH_6__COD_NF_PRIORITY_CHAN_6, priority);
            //ip_rmwf_tb(0);
        }                       //NF
        if (!strcmp(event, "NFIELD")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL1_CH_6__COD_NFIELD_START_CHAN_6, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL1_CH_6__COD_NFIELD_PRIORITY_CHAN_6, priority);
            //ip_rmwf_tb(0);
        }                       //NFIELD
        if (!strcmp(event, "EOF_")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL1_CH_6__COD_EOF_START_CHAN_6, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL1_CH_6__COD_EOF_PRIORITY_CHAN_6, priority);
            //ip_rmwf_tb(0);
        }                       //EOF_
        if (!strcmp(event, "EOFIELD")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL2_CH_6__COD_EOFIELD_START_CHAN_6, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL2_CH_6__COD_EOFIELD_PRIORITY_CHAN_6,
                                priority);
            //ip_rmwf_tb(0);
        }                       //EOFIELD
        if (!strcmp(event, "EOL")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL2_CH_6__COD_EOL_START_CHAN_6, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL2_CH_6__COD_EOL_PRIORITY_CHAN_6, priority);
            //ip_rmwf_tb(0);
        }                       //EOL
        if (!strcmp(event, "NEW_CHAN")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL3_CH_6__COD_NEW_CHAN_START_CHAN_6, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL3_CH_6__COD_NEW_CHAN_PRIORITY_CHAN_6,
                                priority);
            //ip_rmwf_tb(0);
        }                       //NEW_CHAN
        if (!strcmp(event, "NEW_ADDR")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL3_CH_6__COD_NEW_ADDR_START_CHAN_6, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL3_CH_6__COD_NEW_ADDR_PRIORITY_CHAN_6,
                                priority);
            //ip_rmwf_tb(0);
        }                       //NEW_ADDR
        if (!strcmp(event, "NEW_DATA")) {
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL4_CH_6__COD_NEW_DATA_START_CHAN_6, address);
            sdk_ipu_write_field(ipu_num, LPM_MEM_DC_RL4_CH_6__COD_NEW_DATA_PRIORITY_CHAN_6,
                                priority);
            //ip_rmwf_tb(0);
        }                       //NEW_DATA
    }                           //channel 6 ****************************************************************************************

}                               //lpm_microcode_event

static void microcode_config(int ipu_num, int word, int stop, int opcode, int lf, int af,
                             int operand, int mapping, int waveform, int gluelogic, int sync)
{
    WORD IPU_BASE_ADDRE;
    WORD LowWord = 0;
    WORD HighWord = 0;
    WORD opcode_fixed;
//========================================================================================================= 
    //HLG - HOLD WORD GENERIC:  hold operand in register for next operating, without display access 
    switch (opcode) {
    case HLG:
        //[4:0] = 15'b0
        LowWord = LowWord | (operand << 5); //[31:5]

        HighWord = HighWord | (operand >> 27);  //[36:32]
        opcode_fixed = 0x0;     //0-0
        HighWord = HighWord | (opcode_fixed << 5);  //[40:37]
        HighWord = HighWord | (stop << 9);  //[41]
        break;
//========================================================================================================= 
        //WRITE DATA to display
    case WROD:
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        //Generic data, this data is attached with OR to 16 MSB of mapped address   
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[35:32]
        opcode_fixed = 0x18 | (lf << 1);    //1-1-0-lf-0
        HighWord = HighWord | (opcode_fixed << 4);  //[40:36]
        HighWord = HighWord | (stop << 9);  //[41]
        break;
//========================================================================================================= 
        //ATTACH AND HOLD ADDRESS in REGISTER, Adding Mapped Address to held data and hold in register
    case HLOAR:
        sync = 0;               //fixed
        gluelogic = 0;          //fixed
        waveform = 0;           //fixed
        operand = 0;            //fixed
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[32]
        //1 0 0 0 1 1 1 AF:  AF - Address shift flag is defined by user:
        //0: 24bit LSB operating or no operating,
        //1: 8 bit right shift, 24 MSB operating,
        opcode_fixed = 0x8E | (af << 0);    //1-0-0-0-1-1-1-AF
        HighWord = HighWord | (opcode_fixed << 1);  //[40:33]
        HighWord = HighWord | (stop << 9);  //[41]
        break;
//========================================================================================================= 
        //ATTACH AND WRITE ADDRESS to DISPLAY, Adding Mapped Address to held data and write to display
    case WROAR:
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[32]
        //1 1 0 0 1 1 1 AF:  AF - Address shift flag is defined by user:
        //0: 24bit LSB operating or no operating,
        //1: 8 bit right shift, 24 MSB operating,
        opcode_fixed = 0xCE | (af << 0);    //1-1-0-0-1-1-1-AF
        HighWord = HighWord | (opcode_fixed << 1);  //[40:33]
        HighWord = HighWord | (stop << 9);  //[41]
        break;
//========================================================================================================= 
        //ATTACH AND HOLD DATA in REGISTER, Adding Mapped Address to held data and hold in register
    case HLODR:
        sync = 0;               //fixed
        gluelogic = 0;          //fixed
        waveform = 0;           //fixed
        operand = 0;            //fixed
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[32]
        opcode_fixed = 0x8C;    //
        HighWord = HighWord | (opcode_fixed << 1);  //[40:33]
        HighWord = HighWord | (stop << 9);  //[41]
        break;
//========================================================================================================= 
        //WRODR -  WRITE_DATA_OPCODE - ATTACH AND WRITE DATA to DISPLAY, 
        //Adding Mapped Data to hold data in internal register and write to display
    case WRODR:
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[32]
        opcode_fixed = 0xCC;    //
        HighWord = HighWord | (opcode_fixed << 1);  //[40:33]
        HighWord = HighWord | (stop << 9);  //[41]
        break;
//========================================================================================================= 
        //WRITE BIT CHANNEL. merging 1bit mask from IDMAC mask channel with data and write to display
    case WRBC:
        operand = 0;            //fixed
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        LowWord = LowWord | (operand << 20);    //[31:20]

        opcode_fixed = 0x19B;   //
        HighWord = HighWord | (opcode_fixed << 0);  //[40:32]
        HighWord = HighWord | (stop << 9);  //[41]
        break;
//========================================================================================================= 
        //WAIT CLOCK - Waiting N clocks
    case WCLK:
        sync = 0;               //fixed
        gluelogic = 0;          //fixed
        waveform = 0;           //fixed
        mapping = 0;            //fixed
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[32]
        opcode_fixed = 0xC9;    //
        HighWord = HighWord | (opcode_fixed << 1);  //[40:33]
        HighWord = HighWord | (stop << 9);  //[41]
        break;
//========================================================================================================= 
        //WAIT STATUS - 3 microcodes command loop for  checking display status by POLLING READ. THE WSTS_II has to be used immediately after WSTS _III
    case WSTS_III:
        stop = 0;               //fixed
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        //number of IPU's clock to latch data from DI. after WSTS cycle start, defined by user
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[32]
        opcode_fixed = 0x8B;    //
        HighWord = HighWord | (opcode_fixed << 1);  //[40:33]
        HighWord = HighWord | (stop << 9);  //[41]
        break;
//========================================================================================================= 
        //WAIT STATUS - second command in  3 microcode commands loop or first command in 2 microcode commands loop for  checking display status by POLLING READ. THE WSTS_I has to be used immediately after WSTS_II
    case WSTS_II:
        stop = 0;               //fixed
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        //number of IPU's clock to latch data from DI. after WSTS cycle start, defined by user
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[32]
        opcode_fixed = 0x8A;    //
        HighWord = HighWord | (opcode_fixed << 1);  //[40:33]
        HighWord = HighWord | (stop << 9);  //[41]
        break;
//========================================================================================================= 
        //WAIT STATUS - third command in  3 microcode commands loop or second command in 2 microcode commands loop or first command in one command loop for  checking display status by POLLING READ.
    case WSTS_I:
        stop = 0;               //fixed
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        //number of IPU's clock to latch data from DI. after WSTS cycle start, defined by user
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[32]
        opcode_fixed = 0x89;    //
        HighWord = HighWord | (opcode_fixed << 1);  //[40:33]
        HighWord = HighWord | (stop << 9);  //[41]
        break;
//========================================================================================================= 
        //HOLD ADDRESS in REGISTER: display's address which is calculated by IPU, is stored in register
    case HLOA:
        sync = 0;               //fixed
        gluelogic = 0;          //fixed
        waveform = 0;           //fixed
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        //Generic data, this data is attached with OR to 16 MSB of mapped address   
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[35:32]
        //1 0 1 0 AF:  AF - Address shift flag is defined by user: 
        //0: 24bit LSB operating or no operating, 
        //1: 8 bit right shift, 24 MSB operating,
        opcode_fixed = 0x14 | (af << 0);    //1-0-1-0-AF
        HighWord = HighWord | (opcode_fixed << 4);  //[40:36]
        HighWord = HighWord | (stop << 9);  //[41]
        break;
//========================================================================================================= 
        //HOLD ADDRESS in REGISTER: display's address which is calculated by IPU, is stored in register
    case WROA:
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        //Generic data, this data is attached with OR to 16 MSB of mapped address   
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[35:32]
        //1 0 1 0 AF:  AF - Address shift flag is defined by user: 
        //0: 24bit LSB operating or no operating, 
        //1: 8 bit right shift, 24 MSB operating,
        opcode_fixed = 0x1C | (af << 0);    //1-1-1-0-AF
        HighWord = HighWord | (opcode_fixed << 4);  //[40:36]
        HighWord = HighWord | (stop << 9);  //[41]
        break;
//========================================================================================================= 
        //HOLD DATA in REGISTER
    case HLOD:
        sync = 0;               //fixed
        gluelogic = 0;          //fixed
        waveform = 0;           //fixed
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (mapping << 15);    //[19:15]
        //Generic data, this data is attached with OR to 16 MSB of mapped address   
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[35:32]
        opcode_fixed = 0x10;    //1-0-0-0-0
        HighWord = HighWord | (opcode_fixed << 4);  //[40:36]
        HighWord = HighWord | (stop << 9);  //[41]
        break;
//========================================================================================================= 
        //WRG - Write 24bit word to DI and Hold the word in register
        //WRITE WORD GENERIC
        //This opcode is used for sending "a user's code", which is stored in microcode memory  to  a display
        //NO MAPPING
    case WRG:
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11]
        LowWord = LowWord | (operand << 15);    //[31:15]

        HighWord = HighWord | (operand >> 17);  //[38:32]
        opcode_fixed = 1;       //0-1
        HighWord = HighWord | (opcode_fixed << 7);  //[40:39]
        HighWord = HighWord | (stop << 9);  //[41]      
        break;
//========================================================================================================= 
        //RD - Read command parameters:
    case RD:
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11] = synchronization
        LowWord = LowWord | (mapping << 15);    //[19:15]
        //operand - means delay value in DI_CLK for display's data latching by DI, defined by user
        //number of IPU's clock to latch data from DI. after WSTS cycle start
        LowWord = LowWord | (operand << 20);    //[31:20]

        HighWord = HighWord | (operand >> 12);  //[32]
        opcode_fixed = 0x88;    //
        HighWord = HighWord | (opcode_fixed << 1);  //[40:33]
        HighWord = HighWord | (stop << 9);  //[41]
        break;
//========================================================================================================= 
        //WAIT FOR ACKNOWLEDGE
    case WACK:
        mapping = 0;            //fixed
        operand = 0;            //fixed
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11] = synchronization
        LowWord = LowWord | (mapping << 15);    //[19:15]
        //operand - means delay value in DI_CLK for display's data latching by DI, defined by user
        //number of IPU's clock to latch data from DI. after WSTS cycle start
        LowWord = LowWord | (operand << 20);    //[31:20]

        opcode_fixed = 0x11A;   //
        HighWord = HighWord | (opcode_fixed << 0);  //[40:32]
        HighWord = HighWord | (stop << 9);  //[41]
        break;
//========================================================================================================= 
        //HMA  - HOLD_MICROCODE_ADDRESS - hold operand in special Microcode address register
    case HMA:
        //[4:0]
        //Microcode address defined by user
        LowWord = LowWord | (operand << 5); //[12:5]
        opcode_fixed = 0x2;     //
        HighWord = HighWord | (opcode_fixed << 5);  //[40:37]
        HighWord = HighWord | (stop << 9);  //[41]      
        break;
//========================================================================================================= 
        //BMA  - BRANCH_MICROCODE_ADDRESS jump to Microcode address which is stored at 
        //special Microcode address register
    case BMA:
        LowWord = LowWord | (sync); //[3:0] //used for display_id choice
        // 0 0 0 - current display
        // 0 0 1 - previous display
        // 1 0 0 - display 0
        // 1 0 1 - display 1
        // 1 1 0 - display 2
        // 1 1 1 - display 3
        //Additional BMA should be run to change display_id again

        LowWord = LowWord | (operand << 5); //[12:5]
        opcode_fixed = 0x3;     //
        HighWord = HighWord | (opcode_fixed << 5);  //[40:37]
        HighWord = HighWord | (stop << 9);  //[41]
        HighWord = HighWord | (lf << 4);    //[36] CF //counter unit for downcounting
        HighWord = HighWord | (af << 3);    //[35] JF //PC_address register to jump when return    
        break;
//========================================================================================================= 
        //Additional information for event masking
    case MSK:
        sync = 0;               //fixed
        gluelogic = 0;          //fixed
        waveform = 0;           //fixed
        stop = 0;               //fixed 
        //(no mapping)
        LowWord = LowWord | sync;   //[3:0]
        LowWord = LowWord | (gluelogic << 4);   //[10:4]
        LowWord = LowWord | (waveform << 11);   //[14:11] = synchronization
        //[32-28] - 0
        //[27] e0m- event 0 mask, defined by user
        //[26] e1m - event 1 mask, defined by user
        //[25] e2m - event 2 mask, defined by user
        //[24] e3m - event 3 mask, defined by user
        //[23] nfm- new frame mask , defined by user
        //[22] nlm- new line mask , defined by user
        //[21] nfldm- new field mask , defined by user
        //[20] eofm- end of frame mask, defined by user
        //[19] eolm- end of line mask, defined by user
        //[18] eofldm-  end of field mask, defined by user
        //[17] nadm- new address mask, defined by user
        //[16] ncm- new channel mask, defined by user
        //[15] dm - data mask, defined by user 
        LowWord = LowWord | (operand << 15);    //[19:15]

        HighWord = HighWord | (operand >> 17);  //[32]
        opcode_fixed = 0xC8;    //
        HighWord = HighWord | (opcode_fixed << 1);  //[40:33]
        HighWord = HighWord | (stop << 9);  //[41]
        break;
//========================================================================================================= 
    }

    if (ipu_num == 1)
        IPU_BASE_ADDRE = IPU1_BASE_ADDR;
    else if (ipu_num == 2)
        IPU_BASE_ADDRE = IPU2_BASE_ADDR;
    reg32_write(IPU_BASE_ADDRE + IPU_MEM_DC_MICROCODE_BASE_ADDR + word * 8, LowWord);
    //ip_rmwf_tb(0);
    reg32_write(IPU_BASE_ADDRE + IPU_MEM_DC_MICROCODE_BASE_ADDR + word * 8 + 4, HighWord);
    //ip_rmwf_tb(0);
}

static void di_sync_config(int di,
                           int pointer,
                           int run_value_m1,
                           int run_resolution,
                           int offset_value,
                           int offset_resolution,
                           int cnt_auto_reload,
                           int step_repeat,
                           int cnt_clr_sel,
                           int cnt_polarity_gen_en,
                           int cnt_polarity_trigger_sel,
                           int cnt_polarity_clr_sel, int cnt_up, int cnt_down)
{
    if (di == 0) {
        switch (pointer) {
        case 1:{
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_1__DI0_RUN_VALUE_M1_1, run_value_m1);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_1__DI0_RUN_RESOLUTION_1,
                                    run_resolution);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_1__DI0_OFFSET_VALUE_1, offset_value);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_1__DI0_OFFSET_RESOLUTION_1,
                                    offset_resolution);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_1__DI0_CNT_POLARITY_GEN_EN_1,
                                    cnt_polarity_gen_en);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_1__DI0_CNT_AUTO_RELOAD_1,
                                    cnt_auto_reload);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_1__DI0_CNT_CLR_SEL_1, cnt_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_1__DI0_CNT_DOWN_1, cnt_down);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_1__DI0_CNT_POLARITY_TRIGGER_SEL_1,
                                    cnt_polarity_trigger_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_1__DI0_CNT_POLARITY_CLR_SEL_1,
                                    cnt_polarity_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_1__DI0_CNT_UP_1, cnt_up);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI0_STP_REP_1__DI0_STEP_REPEAT_1, step_repeat);
                //ip_rmwf_tb(0);
                break;
            }
        case 2:{
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_2__DI0_RUN_VALUE_M1_2, run_value_m1);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_2__DI0_RUN_RESOLUTION_2,
                                    run_resolution);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_2__DI0_OFFSET_VALUE_2, offset_value);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_2__DI0_OFFSET_RESOLUTION_2,
                                    offset_resolution);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_2__DI0_CNT_POLARITY_GEN_EN_2,
                                    cnt_polarity_gen_en);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_2__DI0_CNT_AUTO_RELOAD_2,
                                    cnt_auto_reload);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_2__DI0_CNT_CLR_SEL_2, cnt_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_2__DI0_CNT_DOWN_2, cnt_down);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_2__DI0_CNT_POLARITY_TRIGGER_SEL_2,
                                    cnt_polarity_trigger_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_2__DI0_CNT_POLARITY_CLR_SEL_2,
                                    cnt_polarity_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_2__DI0_CNT_UP_2, cnt_up);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI0_STP_REP_1__DI0_STEP_REPEAT_2, step_repeat);
                //ip_rmwf_tb(0);
                break;
            }
        case 3:{
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_3__DI0_RUN_VALUE_M1_3, run_value_m1);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_3__DI0_RUN_RESOLUTION_3,
                                    run_resolution);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_3__DI0_OFFSET_VALUE_3, offset_value);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_3__DI0_OFFSET_RESOLUTION_3,
                                    offset_resolution);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_3__DI0_CNT_POLARITY_GEN_EN_3,
                                    cnt_polarity_gen_en);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_3__DI0_CNT_AUTO_RELOAD_3,
                                    cnt_auto_reload);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_3__DI0_CNT_CLR_SEL_3, cnt_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_3__DI0_CNT_DOWN_3, cnt_down);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_3__DI0_CNT_POLARITY_TRIGGER_SEL_3,
                                    cnt_polarity_trigger_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_3__DI0_CNT_POLARITY_CLR_SEL_3,
                                    cnt_polarity_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_3__DI0_CNT_UP_3, cnt_up);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI0_STP_REP_2__DI0_STEP_REPEAT_3, step_repeat);
                //ip_rmwf_tb(0);
                break;
            }
        case 4:{
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_4__DI0_RUN_VALUE_M1_4, run_value_m1);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_4__DI0_RUN_RESOLUTION_4,
                                    run_resolution);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_4__DI0_OFFSET_VALUE_4, offset_value);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_4__DI0_OFFSET_RESOLUTION_4,
                                    offset_resolution);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_4__DI0_CNT_POLARITY_GEN_EN_4,
                                    cnt_polarity_gen_en);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_4__DI0_CNT_AUTO_RELOAD_4,
                                    cnt_auto_reload);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_4__DI0_CNT_CLR_SEL_4, cnt_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_4__DI0_CNT_DOWN_4, cnt_down);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_4__DI0_CNT_POLARITY_TRIGGER_SEL_4,
                                    cnt_polarity_trigger_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_4__DI0_CNT_POLARITY_CLR_SEL_4,
                                    cnt_polarity_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_4__DI0_CNT_UP_4, cnt_up);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI0_STP_REP_2__DI0_STEP_REPEAT_4, step_repeat);
                //ip_rmwf_tb(0);
                break;
            }
        case 5:{
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_5__DI0_RUN_VALUE_M1_5, run_value_m1);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_5__DI0_RUN_RESOLUTION_5,
                                    run_resolution);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_5__DI0_OFFSET_VALUE_5, offset_value);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_5__DI0_OFFSET_RESOLUTION_5,
                                    offset_resolution);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_5__DI0_CNT_POLARITY_GEN_EN_5,
                                    cnt_polarity_gen_en);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_5__DI0_CNT_AUTO_RELOAD_5,
                                    cnt_auto_reload);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_5__DI0_CNT_CLR_SEL_5, cnt_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_5__DI0_CNT_DOWN_5, cnt_down);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_5__DI0_CNT_POLARITY_TRIGGER_SEL_5,
                                    cnt_polarity_trigger_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_5__DI0_CNT_POLARITY_CLR_SEL_5,
                                    cnt_polarity_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_5__DI0_CNT_UP_5, cnt_up);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI0_STP_REP_3__DI0_STEP_REPEAT_5, step_repeat);
                //ip_rmwf_tb(0);
                break;
            }
        case 6:{
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_6__DI0_RUN_VALUE_M1_6, run_value_m1);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_6__DI0_RUN_RESOLUTION_6,
                                    run_resolution);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_6__DI0_OFFSET_VALUE_6, offset_value);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_6__DI0_OFFSET_RESOLUTION_6,
                                    offset_resolution);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_6__DI0_CNT_POLARITY_GEN_EN_6,
                                    cnt_polarity_gen_en);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_6__DI0_CNT_AUTO_RELOAD_6,
                                    cnt_auto_reload);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_6__DI0_CNT_CLR_SEL_6, cnt_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_6__DI0_CNT_DOWN_6, cnt_down);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_6__DI0_CNT_POLARITY_TRIGGER_SEL_6,
                                    cnt_polarity_trigger_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_6__DI0_CNT_POLARITY_CLR_SEL_6,
                                    cnt_polarity_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_6__DI0_CNT_UP_6, cnt_up);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI0_STP_REP_3__DI0_STEP_REPEAT_6, step_repeat);
                //ip_rmwf_tb(0);
                break;
            }
        case 7:{
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_7__DI0_RUN_VALUE_M1_7, run_value_m1);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_7__DI0_RUN_RESOLUTION_7,
                                    run_resolution);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_7__DI0_OFFSET_VALUE_7, offset_value);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_7__DI0_OFFSET_RESOLUTION_7,
                                    offset_resolution);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_7__DI0_CNT_POLARITY_GEN_EN_7,
                                    cnt_polarity_gen_en);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_7__DI0_CNT_AUTO_RELOAD_7,
                                    cnt_auto_reload);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_7__DI0_CNT_CLR_SEL_7, cnt_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_7__DI0_CNT_DOWN_7, cnt_down);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_7__DI0_CNT_POLARITY_TRIGGER_SEL_7,
                                    cnt_polarity_trigger_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_7__DI0_CNT_POLARITY_CLR_SEL_7,
                                    cnt_polarity_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_7__DI0_CNT_UP_7, cnt_up);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI0_STP_REP_4__DI0_STEP_REPEAT_7, step_repeat);
                //ip_rmwf_tb(0);
                break;
            }
        case 8:{
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_8__DI0_RUN_VALUE_M1_8, run_value_m1);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_8__DI0_RUN_RESOLUTION_8,
                                    run_resolution);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_8__DI0_OFFSET_VALUE_8, offset_value);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN0_8__DI0_OFFSET_RESOLUTION_8,
                                    offset_resolution);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_8__DI0_CNT_POLARITY_GEN_EN_8,
                                    cnt_polarity_gen_en);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_8__DI0_CNT_AUTO_RELOAD_8,
                                    cnt_auto_reload);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_8__DI0_CNT_CLR_SEL_8, cnt_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_8__DI0_CNT_DOWN_8, cnt_down);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_8__DI0_CNT_POLARITY_TRIGGER_SEL_8,
                                    cnt_polarity_trigger_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_8__DI0_CNT_POLARITY_CLR_SEL_8,
                                    cnt_polarity_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI0_SW_GEN1_8__DI0_CNT_UP_8, cnt_up);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI0_STP_REP_4__DI0_STEP_REPEAT_8, step_repeat);
                //ip_rmwf_tb(0);
                break;
            }
        }
    } else {
        switch (pointer) {
        case 1:{
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_1__DI1_RUN_VALUE_M1_1, run_value_m1);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_1__DI1_RUN_RESOLUTION_1,
                                    run_resolution);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_1__DI1_OFFSET_VALUE_1, offset_value);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_1__DI1_OFFSET_RESOLUTION_1,
                                    offset_resolution);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_1__DI1_CNT_POLARITY_GEN_EN_1,
                                    cnt_polarity_gen_en);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_1__DI1_CNT_AUTO_RELOAD_1,
                                    cnt_auto_reload);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_1__DI1_CNT_CLR_SEL_1, cnt_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_1__DI1_CNT_DOWN_1, cnt_down);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_1__DI1_CNT_POLARITY_TRIGGER_SEL_1,
                                    cnt_polarity_trigger_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_1__DI1_CNT_POLARITY_CLR_SEL_1,
                                    cnt_polarity_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_1__DI1_CNT_UP_1, cnt_up);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI1_STP_REP_1__DI1_STEP_REPEAT_1, step_repeat);
                //ip_rmwf_tb(0);
                break;
            }
        case 2:{
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_2__DI1_RUN_VALUE_M1_2, run_value_m1);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_2__DI1_RUN_RESOLUTION_2,
                                    run_resolution);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_2__DI1_OFFSET_VALUE_2, offset_value);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_2__DI1_OFFSET_RESOLUTION_2,
                                    offset_resolution);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_2__DI1_CNT_POLARITY_GEN_EN_2,
                                    cnt_polarity_gen_en);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_2__DI1_CNT_AUTO_RELOAD_2,
                                    cnt_auto_reload);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_2__DI1_CNT_CLR_SEL_2, cnt_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_2__DI1_CNT_DOWN_2, cnt_down);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_2__DI1_CNT_POLARITY_TRIGGER_SEL_2,
                                    cnt_polarity_trigger_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_2__DI1_CNT_POLARITY_CLR_SEL_2,
                                    cnt_polarity_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_2__DI1_CNT_UP_2, cnt_up);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI1_STP_REP_1__DI1_STEP_REPEAT_2, step_repeat);
                //ip_rmwf_tb(0);
                break;
            }
        case 3:{
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_3__DI1_RUN_VALUE_M1_3, run_value_m1);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_3__DI1_RUN_RESOLUTION_3,
                                    run_resolution);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_3__DI1_OFFSET_VALUE_3, offset_value);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_3__DI1_OFFSET_RESOLUTION_3,
                                    offset_resolution);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_3__DI1_CNT_POLARITY_GEN_EN_3,
                                    cnt_polarity_gen_en);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_3__DI1_CNT_AUTO_RELOAD_3,
                                    cnt_auto_reload);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_3__DI1_CNT_CLR_SEL_3, cnt_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_3__DI1_CNT_DOWN_3, cnt_down);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_3__DI1_CNT_POLARITY_TRIGGER_SEL_3,
                                    cnt_polarity_trigger_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_3__DI1_CNT_POLARITY_CLR_SEL_3,
                                    cnt_polarity_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_3__DI1_CNT_UP_3, cnt_up);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI1_STP_REP_2__DI1_STEP_REPEAT_3, step_repeat);
                //ip_rmwf_tb(0);
                break;
            }
        case 4:{
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_4__DI1_RUN_VALUE_M1_4, run_value_m1);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_4__DI1_RUN_RESOLUTION_4,
                                    run_resolution);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_4__DI1_OFFSET_VALUE_4, offset_value);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_4__DI1_OFFSET_RESOLUTION_4,
                                    offset_resolution);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_4__DI1_CNT_POLARITY_GEN_EN_4,
                                    cnt_polarity_gen_en);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_4__DI1_CNT_AUTO_RELOAD_4,
                                    cnt_auto_reload);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_4__DI1_CNT_CLR_SEL_4, cnt_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_4__DI1_CNT_DOWN_4, cnt_down);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_4__DI1_CNT_POLARITY_TRIGGER_SEL_4,
                                    cnt_polarity_trigger_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_4__DI1_CNT_POLARITY_CLR_SEL_4,
                                    cnt_polarity_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_4__DI1_CNT_UP_4, cnt_up);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI1_STP_REP_2__DI1_STEP_REPEAT_4, step_repeat);
                //ip_rmwf_tb(0);
                break;
            }
        case 5:{
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_5__DI1_RUN_VALUE_M1_5, run_value_m1);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_5__DI1_RUN_RESOLUTION_5,
                                    run_resolution);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_5__DI1_OFFSET_VALUE_5, offset_value);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_5__DI1_OFFSET_RESOLUTION_5,
                                    offset_resolution);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_5__DI1_CNT_POLARITY_GEN_EN_5,
                                    cnt_polarity_gen_en);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_5__DI1_CNT_AUTO_RELOAD_5,
                                    cnt_auto_reload);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_5__DI1_CNT_CLR_SEL_5, cnt_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_5__DI1_CNT_DOWN_5, cnt_down);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_5__DI1_CNT_POLARITY_TRIGGER_SEL_5,
                                    cnt_polarity_trigger_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_5__DI1_CNT_POLARITY_CLR_SEL_5,
                                    cnt_polarity_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_5__DI1_CNT_UP_5, cnt_up);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI1_STP_REP_3__DI1_STEP_REPEAT_5, step_repeat);
                //ip_rmwf_tb(0);
                break;
            }
        case 6:{
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_6__DI1_RUN_VALUE_M1_6, run_value_m1);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_6__DI1_RUN_RESOLUTION_6,
                                    run_resolution);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_6__DI1_OFFSET_VALUE_6, offset_value);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_6__DI1_OFFSET_RESOLUTION_6,
                                    offset_resolution);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_6__DI1_CNT_POLARITY_GEN_EN_6,
                                    cnt_polarity_gen_en);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_6__DI1_CNT_AUTO_RELOAD_6,
                                    cnt_auto_reload);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_6__DI1_CNT_CLR_SEL_6, cnt_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_6__DI1_CNT_DOWN_6, cnt_down);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_6__DI1_CNT_POLARITY_TRIGGER_SEL_6,
                                    cnt_polarity_trigger_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_6__DI1_CNT_POLARITY_CLR_SEL_6,
                                    cnt_polarity_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_6__DI1_CNT_UP_6, cnt_up);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI1_STP_REP_3__DI1_STEP_REPEAT_6, step_repeat);
                //ip_rmwf_tb(0);
                break;
            }
        case 7:{
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_7__DI1_RUN_VALUE_M1_7, run_value_m1);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_7__DI1_RUN_RESOLUTION_7,
                                    run_resolution);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_7__DI1_OFFSET_VALUE_7, offset_value);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_7__DI1_OFFSET_RESOLUTION_7,
                                    offset_resolution);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_7__DI1_CNT_POLARITY_GEN_EN_7,
                                    cnt_polarity_gen_en);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_7__DI1_CNT_AUTO_RELOAD_7,
                                    cnt_auto_reload);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_7__DI1_CNT_CLR_SEL_7, cnt_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_7__DI1_CNT_DOWN_7, cnt_down);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_7__DI1_CNT_POLARITY_TRIGGER_SEL_7,
                                    cnt_polarity_trigger_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_7__DI1_CNT_POLARITY_CLR_SEL_7,
                                    cnt_polarity_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_7__DI1_CNT_UP_7, cnt_up);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI1_STP_REP_4__DI1_STEP_REPEAT_7, step_repeat);
                //ip_rmwf_tb(0);
            }
        case 8:{
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_8__DI1_RUN_VALUE_M1_8, run_value_m1);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_8__DI1_RUN_RESOLUTION_8,
                                    run_resolution);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_8__DI1_OFFSET_VALUE_8, offset_value);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN0_8__DI1_OFFSET_RESOLUTION_8,
                                    offset_resolution);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_8__DI1_CNT_POLARITY_GEN_EN_8,
                                    cnt_polarity_gen_en);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_8__DI1_CNT_AUTO_RELOAD_8,
                                    cnt_auto_reload);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_8__DI1_CNT_CLR_SEL_8, cnt_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_8__DI1_CNT_DOWN_8, cnt_down);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_8__DI1_CNT_POLARITY_TRIGGER_SEL_8,
                                    cnt_polarity_trigger_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_8__DI1_CNT_POLARITY_CLR_SEL_8,
                                    cnt_polarity_clr_sel);
                sdk_ipu_write_field(ipu_num, IPU_DI1_SW_GEN1_8__DI1_CNT_UP_8, cnt_up);
                //ip_rmwf_tb(0);                                                                               
                sdk_ipu_write_field(ipu_num, IPU_DI1_STP_REP_4__DI1_STEP_REPEAT_8, step_repeat);
                //ip_rmwf_tb(0);
                break;
            }
        }
    }
    return;
}

static void di_up_down_config(int ipu_num, int di, int pointer, int set, int up, int down)
{
    if (di == 0) {
        switch (pointer) {
        case 0:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_0__DI0_DATA_CNT_UP0_0, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_0__DI0_DATA_CNT_DOWN0_0, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_0__DI0_DATA_CNT_UP1_0, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_0__DI0_DATA_CNT_DOWN1_0, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_0__DI0_DATA_CNT_UP2_0, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_0__DI0_DATA_CNT_DOWN2_0, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_0__DI0_DATA_CNT_UP3_0, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_0__DI0_DATA_CNT_DOWN3_0, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        case 1:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_1__DI0_DATA_CNT_UP0_1, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_1__DI0_DATA_CNT_DOWN0_1, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_1__DI0_DATA_CNT_UP1_1, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_1__DI0_DATA_CNT_DOWN1_1, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_1__DI0_DATA_CNT_UP2_1, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_1__DI0_DATA_CNT_DOWN2_1, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_1__DI0_DATA_CNT_UP3_1, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_1__DI0_DATA_CNT_DOWN3_1, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        case 2:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_2__DI0_DATA_CNT_UP0_2, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_2__DI0_DATA_CNT_DOWN0_2, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_2__DI0_DATA_CNT_UP1_2, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_2__DI0_DATA_CNT_DOWN1_2, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_2__DI0_DATA_CNT_UP2_2, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_2__DI0_DATA_CNT_DOWN2_2, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_2__DI0_DATA_CNT_UP3_2, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_2__DI0_DATA_CNT_DOWN3_2, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        case 3:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_3__DI0_DATA_CNT_UP0_3, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_3__DI0_DATA_CNT_DOWN0_3, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_3__DI0_DATA_CNT_UP1_3, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_3__DI0_DATA_CNT_DOWN1_3, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_3__DI0_DATA_CNT_UP2_3, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_3__DI0_DATA_CNT_DOWN2_3, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_3__DI0_DATA_CNT_UP3_3, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_3__DI0_DATA_CNT_DOWN3_3, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        case 4:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_4__DI0_DATA_CNT_UP0_4, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_4__DI0_DATA_CNT_DOWN0_4, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_4__DI0_DATA_CNT_UP1_4, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_4__DI0_DATA_CNT_DOWN1_4, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_4__DI0_DATA_CNT_UP2_4, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_4__DI0_DATA_CNT_DOWN2_4, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_4__DI0_DATA_CNT_UP3_4, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_4__DI0_DATA_CNT_DOWN3_4, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        case 5:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_5__DI0_DATA_CNT_UP0_5, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_5__DI0_DATA_CNT_DOWN0_5, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_5__DI0_DATA_CNT_UP1_5, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_5__DI0_DATA_CNT_DOWN1_5, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_5__DI0_DATA_CNT_UP2_5, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_5__DI0_DATA_CNT_DOWN2_5, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_5__DI0_DATA_CNT_UP3_5, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_5__DI0_DATA_CNT_DOWN3_5, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        case 6:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_6__DI0_DATA_CNT_UP0_6, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_6__DI0_DATA_CNT_DOWN0_6, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_6__DI0_DATA_CNT_UP1_6, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_6__DI0_DATA_CNT_DOWN1_6, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_6__DI0_DATA_CNT_UP2_6, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_6__DI0_DATA_CNT_DOWN2_6, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_6__DI0_DATA_CNT_UP3_6, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_6__DI0_DATA_CNT_DOWN3_6, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        case 7:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_7__DI0_DATA_CNT_UP0_7, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_7__DI0_DATA_CNT_DOWN0_7, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_7__DI0_DATA_CNT_UP1_7, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_7__DI0_DATA_CNT_DOWN1_7, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_7__DI0_DATA_CNT_UP2_7, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_7__DI0_DATA_CNT_DOWN2_7, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_7__DI0_DATA_CNT_UP3_7, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_7__DI0_DATA_CNT_DOWN3_7, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        case 8:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_8__DI0_DATA_CNT_UP0_8, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_8__DI0_DATA_CNT_DOWN0_8, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_8__DI0_DATA_CNT_UP1_8, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_8__DI0_DATA_CNT_DOWN1_8, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_8__DI0_DATA_CNT_UP2_8, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_8__DI0_DATA_CNT_DOWN2_8, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_8__DI0_DATA_CNT_UP3_8, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_8__DI0_DATA_CNT_DOWN3_8, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        case 9:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_9__DI0_DATA_CNT_UP0_9, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_9__DI0_DATA_CNT_DOWN0_9, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_9__DI0_DATA_CNT_UP1_9, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_9__DI0_DATA_CNT_DOWN1_9, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_9__DI0_DATA_CNT_UP2_9, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_9__DI0_DATA_CNT_DOWN2_9, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_9__DI0_DATA_CNT_UP3_9, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_9__DI0_DATA_CNT_DOWN3_9, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        case 10:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_10__DI0_DATA_CNT_UP0_10, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_10__DI0_DATA_CNT_DOWN0_10, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_10__DI0_DATA_CNT_UP1_10, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_10__DI0_DATA_CNT_DOWN1_10, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_10__DI0_DATA_CNT_UP2_10, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_10__DI0_DATA_CNT_DOWN2_10, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_10__DI0_DATA_CNT_UP3_10, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_10__DI0_DATA_CNT_DOWN3_10, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        case 11:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_11__DI0_DATA_CNT_UP0_11, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET0_11__DI0_DATA_CNT_DOWN0_11, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_11__DI0_DATA_CNT_UP1_11, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET1_11__DI0_DATA_CNT_DOWN1_11, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_11__DI0_DATA_CNT_UP2_11, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET2_11__DI0_DATA_CNT_DOWN2_11, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_11__DI0_DATA_CNT_UP3_11, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI0_DW_SET3_11__DI0_DATA_CNT_DOWN3_11, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        default:{
                break;
            }
        }
    } else {
        switch (pointer) {
        case 0:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_0__DI1_DATA_CNT_UP0_0, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_0__DI1_DATA_CNT_DOWN0_0, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_0__DI1_DATA_CNT_UP1_0, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_0__DI1_DATA_CNT_DOWN1_0, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_0__DI1_DATA_CNT_UP2_0, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_0__DI1_DATA_CNT_DOWN2_0, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_0__DI1_DATA_CNT_UP3_0, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_0__DI1_DATA_CNT_DOWN3_0, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        case 1:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_1__DI1_DATA_CNT_UP0_1, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_1__DI1_DATA_CNT_DOWN0_1, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_1__DI1_DATA_CNT_UP1_1, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_1__DI1_DATA_CNT_DOWN1_1, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_1__DI1_DATA_CNT_UP2_1, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_1__DI1_DATA_CNT_DOWN2_1, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_1__DI1_DATA_CNT_UP3_1, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_1__DI1_DATA_CNT_DOWN3_1, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        case 2:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_2__DI1_DATA_CNT_UP0_2, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_2__DI1_DATA_CNT_DOWN0_2, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_2__DI1_DATA_CNT_UP1_2, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_2__DI1_DATA_CNT_DOWN1_2, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_2__DI1_DATA_CNT_UP2_2, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_2__DI1_DATA_CNT_DOWN2_2, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_2__DI1_DATA_CNT_UP3_2, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_2__DI1_DATA_CNT_DOWN3_2, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        case 3:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_3__DI1_DATA_CNT_UP0_3, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_3__DI1_DATA_CNT_DOWN0_3, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_3__DI1_DATA_CNT_UP1_3, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_3__DI1_DATA_CNT_DOWN1_3, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_3__DI1_DATA_CNT_UP2_3, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_3__DI1_DATA_CNT_DOWN2_3, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_3__DI1_DATA_CNT_UP3_3, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_3__DI1_DATA_CNT_DOWN3_3, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        case 4:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_4__DI1_DATA_CNT_UP0_4, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_4__DI1_DATA_CNT_DOWN0_4, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_4__DI1_DATA_CNT_UP1_4, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_4__DI1_DATA_CNT_DOWN1_4, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_4__DI1_DATA_CNT_UP2_4, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_4__DI1_DATA_CNT_DOWN2_4, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_4__DI1_DATA_CNT_UP3_4, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_4__DI1_DATA_CNT_DOWN3_4, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        case 5:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_5__DI1_DATA_CNT_UP0_5, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_5__DI1_DATA_CNT_DOWN0_5, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_5__DI1_DATA_CNT_UP1_5, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_5__DI1_DATA_CNT_DOWN1_5, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_5__DI1_DATA_CNT_UP2_5, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_5__DI1_DATA_CNT_DOWN2_5, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_5__DI1_DATA_CNT_UP3_5, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_5__DI1_DATA_CNT_DOWN3_5, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        case 6:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_6__DI1_DATA_CNT_UP0_6, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_6__DI1_DATA_CNT_DOWN0_6, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_6__DI1_DATA_CNT_UP1_6, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_6__DI1_DATA_CNT_DOWN1_6, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_6__DI1_DATA_CNT_UP2_6, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_6__DI1_DATA_CNT_DOWN2_6, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_6__DI1_DATA_CNT_UP3_6, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_6__DI1_DATA_CNT_DOWN3_6, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        case 7:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_7__DI1_DATA_CNT_UP0_7, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_7__DI1_DATA_CNT_DOWN0_7, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_7__DI1_DATA_CNT_UP1_7, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_7__DI1_DATA_CNT_DOWN1_7, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_7__DI1_DATA_CNT_UP2_7, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_7__DI1_DATA_CNT_DOWN2_7, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_7__DI1_DATA_CNT_UP3_7, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_7__DI1_DATA_CNT_DOWN3_7, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        case 8:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_8__DI1_DATA_CNT_UP0_8, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_8__DI1_DATA_CNT_DOWN0_8, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_8__DI1_DATA_CNT_UP1_8, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_8__DI1_DATA_CNT_DOWN1_8, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_8__DI1_DATA_CNT_UP2_8, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_8__DI1_DATA_CNT_DOWN2_8, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_8__DI1_DATA_CNT_UP3_8, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_8__DI1_DATA_CNT_DOWN3_8, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        case 9:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_9__DI1_DATA_CNT_UP0_9, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_9__DI1_DATA_CNT_DOWN0_9, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_9__DI1_DATA_CNT_UP1_9, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_9__DI1_DATA_CNT_DOWN1_9, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_9__DI1_DATA_CNT_UP2_9, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_9__DI1_DATA_CNT_DOWN2_9, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_9__DI1_DATA_CNT_UP3_9, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_9__DI1_DATA_CNT_DOWN3_9, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        case 10:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_10__DI1_DATA_CNT_UP0_10, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_10__DI1_DATA_CNT_DOWN0_10, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_10__DI1_DATA_CNT_UP1_10, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_10__DI1_DATA_CNT_DOWN1_10, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_10__DI1_DATA_CNT_UP2_10, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_10__DI1_DATA_CNT_DOWN2_10, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_10__DI1_DATA_CNT_UP3_10, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_10__DI1_DATA_CNT_DOWN3_10, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        case 11:{
                if (set == 0) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_11__DI1_DATA_CNT_UP0_11, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET0_11__DI1_DATA_CNT_DOWN0_11, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 1) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_11__DI1_DATA_CNT_UP1_11, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET1_11__DI1_DATA_CNT_DOWN1_11, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 2) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_11__DI1_DATA_CNT_UP2_11, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET2_11__DI1_DATA_CNT_DOWN2_11, down);
                    //ip_rmwf_tb(0);                                                
                }
                if (set == 3) {
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_11__DI1_DATA_CNT_UP3_11, up);
                    sdk_ipu_write_field(ipu_num, IPU_DI1_DW_SET3_11__DI1_DATA_CNT_DOWN3_11, down);
                    //ip_rmwf_tb(0);                                                
                }
                break;
            }
        default:{
                break;
            }
        }
    }
    return;
}

static void di_pointer_config(int ipu_num, int di, int pointer, int access, int componnent, int cst,
                              int pt0, int pt1, int pt2, int pt3, int pt4, int pt5, int pt6)
{
    if (di == 0) {
        switch (pointer) {
        case 0:{
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_0__DI0_ACCESS_SIZE_0, access);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_0__DI0_COMPONNENT_SIZE_0, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_0__DI0_CST_0, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_0__DI0_PT_0_0, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_0__DI0_PT_1_0, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_0__DI0_PT_2_0, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_0__DI0_PT_3_0, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_0__DI0_PT_4_0, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_0__DI0_PT_5_0, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_0__DI0_PT_6_0, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        case 1:{
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_1__DI0_ACCESS_SIZE_1, access);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_1__DI0_COMPONNENT_SIZE_1, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_1__DI0_CST_1, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_1__DI0_PT_0_1, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_1__DI0_PT_1_1, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_1__DI0_PT_2_1, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_1__DI0_PT_3_1, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_1__DI0_PT_4_1, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_1__DI0_PT_5_1, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_1__DI0_PT_6_1, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        case 2:{
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_2__DI0_ACCESS_SIZE_2, access);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_2__DI0_COMPONNENT_SIZE_2, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_2__DI0_CST_2, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_2__DI0_PT_0_2, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_2__DI0_PT_1_2, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_2__DI0_PT_2_2, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_2__DI0_PT_3_2, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_2__DI0_PT_4_2, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_2__DI0_PT_5_2, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_2__DI0_PT_6_2, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        case 3:{
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_3__DI0_ACCESS_SIZE_3, access);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_3__DI0_COMPONNENT_SIZE_3, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_3__DI0_CST_3, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_3__DI0_PT_0_3, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_3__DI0_PT_1_3, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_3__DI0_PT_2_3, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_3__DI0_PT_3_3, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_3__DI0_PT_4_3, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_3__DI0_PT_5_3, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_3__DI0_PT_6_3, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        case 4:{
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_4__DI0_ACCESS_SIZE_4, access);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_4__DI0_COMPONNENT_SIZE_4, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_4__DI0_CST_4, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_4__DI0_PT_0_4, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_4__DI0_PT_1_4, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_4__DI0_PT_2_4, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_4__DI0_PT_3_4, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_4__DI0_PT_4_4, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_4__DI0_PT_5_4, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_4__DI0_PT_6_4, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        case 5:{
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_5__DI0_ACCESS_SIZE_5, access);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_5__DI0_COMPONNENT_SIZE_5, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_5__DI0_CST_5, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_5__DI0_PT_0_5, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_5__DI0_PT_1_5, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_5__DI0_PT_2_5, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_5__DI0_PT_3_5, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_5__DI0_PT_4_5, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_5__DI0_PT_5_5, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_5__DI0_PT_6_5, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        case 6:{
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_6__DI0_ACCESS_SIZE_6, access);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_6__DI0_COMPONNENT_SIZE_6, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_6__DI0_CST_6, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_6__DI0_PT_0_6, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_6__DI0_PT_1_6, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_6__DI0_PT_2_6, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_6__DI0_PT_3_6, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_6__DI0_PT_4_6, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_6__DI0_PT_5_6, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_6__DI0_PT_6_6, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        case 7:{
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_7__DI0_ACCESS_SIZE_7, access);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_7__DI0_COMPONNENT_SIZE_7, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_7__DI0_CST_7, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_7__DI0_PT_0_7, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_7__DI0_PT_1_7, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_7__DI0_PT_2_7, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_7__DI0_PT_3_7, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_7__DI0_PT_4_7, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_7__DI0_PT_5_7, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_7__DI0_PT_6_7, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        case 8:{
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_8__DI0_ACCESS_SIZE_8, access);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_8__DI0_COMPONNENT_SIZE_8, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_8__DI0_CST_8, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_8__DI0_PT_0_8, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_8__DI0_PT_1_8, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_8__DI0_PT_2_8, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_8__DI0_PT_3_8, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_8__DI0_PT_4_8, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_8__DI0_PT_5_8, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_8__DI0_PT_6_8, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        case 9:{
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_9__DI0_ACCESS_SIZE_9, access);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_9__DI0_COMPONNENT_SIZE_9, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_9__DI0_CST_9, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_9__DI0_PT_0_9, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_9__DI0_PT_1_9, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_9__DI0_PT_2_9, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_9__DI0_PT_3_9, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_9__DI0_PT_4_9, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_9__DI0_PT_5_9, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_9__DI0_PT_6_9, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        case 10:{
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_10__DI0_ACCESS_SIZE_10, access);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_10__DI0_COMPONNENT_SIZE_10, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_10__DI0_CST_10, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_10__DI0_PT_0_10, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_10__DI0_PT_1_10, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_10__DI0_PT_2_10, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_10__DI0_PT_3_10, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_10__DI0_PT_4_10, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_10__DI0_PT_5_10, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_10__DI0_PT_6_10, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        case 11:{
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_11__DI0_ACCESS_SIZE_11, access);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_11__DI0_COMPONNENT_SIZE_11, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_11__DI0_CST_11, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_11__DI0_PT_0_11, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_11__DI0_PT_1_11, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_11__DI0_PT_2_11, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_11__DI0_PT_3_11, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_11__DI0_PT_4_11, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_11__DI0_PT_5_11, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI0_DW_GEN_11__DI0_PT_6_11, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        }
    } else {
        switch (pointer) {
        case 0:{
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_0__DI1_ACCESS_SIZE_0, access);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_0__DI1_COMPONNENT_SIZE_0, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_0__DI1_CST_0, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_0__DI1_PT_0_0, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_0__DI1_PT_1_0, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_0__DI1_PT_2_0, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_0__DI1_PT_3_0, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_0__DI1_PT_4_0, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_0__DI1_PT_5_0, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_0__DI1_PT_6_0, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        case 1:{
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_1__DI1_ACCESS_SIZE_1, access);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_1__DI1_COMPONNENT_SIZE_1, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_1__DI1_CST_1, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_1__DI1_PT_0_1, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_1__DI1_PT_1_1, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_1__DI1_PT_2_1, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_1__DI1_PT_3_1, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_1__DI1_PT_4_1, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_1__DI1_PT_5_1, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_1__DI1_PT_6_1, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        case 2:{
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_2__DI1_ACCESS_SIZE_2, access);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_2__DI1_COMPONNENT_SIZE_2, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_2__DI1_CST_2, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_2__DI1_PT_0_2, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_2__DI1_PT_1_2, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_2__DI1_PT_2_2, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_2__DI1_PT_3_2, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_2__DI1_PT_4_2, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_2__DI1_PT_5_2, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_2__DI1_PT_6_2, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        case 3:{
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_3__DI1_ACCESS_SIZE_3, access);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_3__DI1_COMPONNENT_SIZE_3, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_3__DI1_CST_3, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_3__DI1_PT_0_3, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_3__DI1_PT_1_3, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_3__DI1_PT_2_3, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_3__DI1_PT_3_3, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_3__DI1_PT_4_3, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_3__DI1_PT_5_3, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_3__DI1_PT_6_3, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        case 4:{
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_4__DI1_ACCESS_SIZE_4, access);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_4__DI1_COMPONNENT_SIZE_4, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_4__DI1_CST_4, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_4__DI1_PT_0_4, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_4__DI1_PT_1_4, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_4__DI1_PT_2_4, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_4__DI1_PT_3_4, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_4__DI1_PT_4_4, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_4__DI1_PT_5_4, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_4__DI1_PT_6_4, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        case 5:{
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_5__DI1_ACCESS_SIZE_5, access);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_5__DI1_COMPONNENT_SIZE_5, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_5__DI1_CST_5, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_5__DI1_PT_0_5, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_5__DI1_PT_1_5, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_5__DI1_PT_2_5, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_5__DI1_PT_3_5, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_5__DI1_PT_4_5, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_5__DI1_PT_5_5, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_5__DI1_PT_6_5, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        case 6:{
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_6__DI1_ACCESS_SIZE_6, access);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_6__DI1_COMPONNENT_SIZE_6, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_6__DI1_CST_6, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_6__DI1_PT_0_6, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_6__DI1_PT_1_6, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_6__DI1_PT_2_6, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_6__DI1_PT_3_6, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_6__DI1_PT_4_6, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_6__DI1_PT_5_6, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_6__DI1_PT_6_6, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        case 7:{
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_7__DI1_ACCESS_SIZE_7, access);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_7__DI1_COMPONNENT_SIZE_7, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_7__DI1_CST_7, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_7__DI1_PT_0_7, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_7__DI1_PT_1_7, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_7__DI1_PT_2_7, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_7__DI1_PT_3_7, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_7__DI1_PT_4_7, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_7__DI1_PT_5_7, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_7__DI1_PT_6_7, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        case 8:{
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_8__DI1_ACCESS_SIZE_8, access);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_8__DI1_COMPONNENT_SIZE_8, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_8__DI1_CST_8, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_8__DI1_PT_0_8, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_8__DI1_PT_1_8, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_8__DI1_PT_2_8, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_8__DI1_PT_3_8, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_8__DI1_PT_4_8, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_8__DI1_PT_5_8, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_8__DI1_PT_6_8, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        case 9:{
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_9__DI1_ACCESS_SIZE_9, access);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_9__DI1_COMPONNENT_SIZE_9, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_9__DI1_CST_9, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_9__DI1_PT_0_9, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_9__DI1_PT_1_9, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_9__DI1_PT_2_9, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_9__DI1_PT_3_9, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_9__DI1_PT_4_9, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_9__DI1_PT_5_9, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_9__DI1_PT_6_9, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        case 10:{
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_10__DI1_ACCESS_SIZE_10, access);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_10__DI1_COMPONNENT_SIZE_10, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_10__DI1_CST_10, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_10__DI1_PT_0_10, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_10__DI1_PT_1_10, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_10__DI1_PT_2_10, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_10__DI1_PT_3_10, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_10__DI1_PT_4_10, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_10__DI1_PT_5_10, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_10__DI1_PT_6_10, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        case 11:{
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_11__DI1_ACCESS_SIZE_11, access);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_11__DI1_COMPONNENT_SIZE_11, componnent);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_11__DI1_CST_11, cst);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_11__DI1_PT_0_11, pt0);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_11__DI1_PT_1_11, pt1);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_11__DI1_PT_2_11, pt2);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_11__DI1_PT_3_11, pt3);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_11__DI1_PT_4_11, pt4);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_11__DI1_PT_5_11, pt5);
                sdk_ipu_write_field(ipu_num, IPU_DI1_DW_GEN_11__DI1_PT_6_11, pt6);
                //ip_rmwf_tb(0); 
                break;
            }
        }
    }
    return;
}

#define CH23_FW         (1024)
#define CH23_FH         (768)

void ipu_setup_xga(WORD ch23_eba, WORD overlay, WORD ch27_fw, WORD ch27_fh, WORD ch27_eba0,
                   WORD ch27_eba1, WORD ch27_x, WORD ch27_y, WORD global_alpha)
{

    //******************************************************************/
    //IDMAC part 
    //******************************************************************/
    init_idmac_parameters();
    ipu_num = 2;
    channel = 23;
    eba0 = ch23_eba / 8;        //1st double buffer address
    //ubo     =   CH23_UBO/8;  //u buffer address offset
    //vbo     =   CH23_VBO/8;  //v buffer address offset
    fw = CH23_FW - 1;           //frame width
    fh = CH23_FH - 1;           //frame hight
    npb = 15;                   //16 pixels per burst
    pfs = 7;                    //1->4:2:2 non-interleaved, 7->rgb
    bpp = 0;
    //sly     =   CH23_SL-1;   //stride line for Y
    //sluv    =   CH23_SL/2-1; //stride line for U/V
    //so      =   1;           //scan order set to interlaced
    //ilo     =   0x100000/8;  //2nd double buffer address offset
    sl = (CH23_FW + (CH23_FW % 2)) * 4 - 1;
    wid0 = 8 - 1;               //bits
    wid1 = 8 - 1;               //bits;
    wid2 = 8 - 1;               //bits;
    wid3 = 8 - 1;               //bits;
    ofs0 = 0;
    ofs1 = 8;
    ofs2 = 16;
    ofs3 = 24;
    //config_idmac_non_interleaved_channel();
    config_idmac_interleaved_channel();

    if (overlay) {
        init_idmac_parameters();
        ipu_num = 2;
        channel = 27;
        eba0 = ch27_eba0 / 8;   //1st double buffer address
        eba1 = ch27_eba1 / 8;   //2nd double buffer address
        //ubo     =   CH23_UBO/8;  //u buffer address offset
        //vbo     =   CH23_VBO/8;  //v buffer address offset
        fw = ch27_fw - 1;       //frame width
        fh = ch27_fh - 1;       //frame hight
        npb = 15;               //8 pixels per burst
        pfs = 7;                //2->4:2:0 non-interleaved, 7->rgb
        bpp = 0;
        //sly     =   CH23_FW-1;   //stride line for Y
        //sluv    =   CH23_FW/2-1; //stride line for U/V
        //so      =   1;           //scan order set to interlaced
        //ilo     =   0x100000/8;  //2nd double buffer address offset
        //sl = (CH27_FW + (CH27_FW % 2))*4-1;
        sl = (ch27_fw) * 4 - 1;
        wid0 = 8 - 1;           //bits
        wid1 = 8 - 1;           //bits;
        wid2 = 8 - 1;           //bits;
        //wid3 = 8-1;//bits;
        ofs0 = 8;
        ofs1 = 16;
        ofs2 = 24;
        //ofs3 = 0;
        //bm            =       1;  // block size is 8x8 pixels
        rot = 0;                // 0 - 90 degree rot disable
        hf = 0;                 // 0 - horizontal flip disable
        vf = 0;                 // 0 - vertical flip disable
        id = 1;
        //config_idmac_non_interleaved_channel();
        config_idmac_interleaved_channel();

        sdk_ipu_write_field(2, IPU_IDMAC_CH_PRI_1__IDMAC_CH_PRI_27, 1);
    }
    //******************************************************************/
    //DMFC part 
    //******************************************************************/
    //sdk_ipu_write_field(2, IPU_DMFC_IC_CTRL__DMFC_IC_IN_PORT, 7);

    sdk_ipu_write_field(2, IPU_DMFC_DP_CHAN__DMFC_FIFO_SIZE_5B, 2); //Table of fifo_size 000-2^9,001-2^8,010-2^7,
    //011-2^6,100-2^5,101-2^4,110-2^3,111-2^2
    sdk_ipu_write_field(2, IPU_DMFC_DP_CHAN__DMFC_BURST_SIZE_5B, 3);    //Table of dmfc_burst_size codes 
    //00:32x128 01:16x128 10:8x128 11:4x128
    sdk_ipu_write_field(2, IPU_DMFC_DP_CHAN__DMFC_ST_ADDR_5B, 0);   //start address
    sdk_ipu_write_field(2, IPU_DMFC_WR_CHAN_DEF__DMFC_WM_CLR_1, 0); //clr water mark value possible Value: 0-7 (Number of burst)
    sdk_ipu_write_field(2, IPU_DMFC_WR_CHAN_DEF__DMFC_WM_SET_1, 0); //set water mark value possible Value: 0-7 (Number of burst)
    sdk_ipu_write_field(2, IPU_DMFC_WR_CHAN_DEF__DMFC_WM_EN_1, 0);  //Enable/Disable water mark logic
    sdk_ipu_write_field(2, IPU_DMFC_GENERAL1__WAIT4EOT_1, 0);

    if (overlay) {
        // for foreground channel
        sdk_ipu_write_field(2, IPU_DMFC_DP_CHAN__DMFC_FIFO_SIZE_5F, 4); //Table of fifo_size 000-29,001-28,010-27,
        //sdk_ipu_write_field(2, IPU_DMFC_DP_CHAN__DMFC_FIFO_SIZE_5F, 1);//26_10_09
        //011-26,100-25,101-24,110-23,111-22
        sdk_ipu_write_field(2, IPU_DMFC_DP_CHAN__DMFC_BURST_SIZE_5F, 3);    //Table of dmfc_burst_size codes 
        //00:32x128 01:16x128 10:8x128 11:4x128
        sdk_ipu_write_field(2, IPU_DMFC_DP_CHAN__DMFC_ST_ADDR_5F, 4);   //start address

        sdk_ipu_write_field(2, IPU_DMFC_DP_CHAN_DEF__DMFC_WM_CLR_5F, 0);    //clr water mark value possible Value: 0-7 (Number of burst)
        sdk_ipu_write_field(2, IPU_DMFC_DP_CHAN_DEF__DMFC_WM_SET_5F, 0);    //set water mark value possible Value: 0-7 (Number of burst)
        sdk_ipu_write_field(2, IPU_DMFC_DP_CHAN_DEF__DMFC_WM_EN_5F, 0); //Enable/Disable water mark logic

        sdk_ipu_write_field(2, IPU_DMFC_GENERAL1__WAIT4EOT_5F, 0);  //If line is shorter then FIFO size (cm_dmfc_fifo_size_5b) the "wait" has to be ON

        reg32_write(IPU2_BASE_ADDR + SRM_DP_COM_CONF_SYNC__ADDR, 0x0);
        sdk_ipu_write_field(2, SRM_DP_COM_CONF_SYNC__DP_FG_EN_SYNC, 1); //1=FG channel enabled,0=FG channel disabled
        if (global_alpha)
            sdk_ipu_write_field(2, SRM_DP_COM_CONF_SYNC__DP_GWAM_SYNC, 1);
        else
            sdk_ipu_write_field(2, SRM_DP_COM_CONF_SYNC__DP_GWAM_SYNC, 0);
        sdk_ipu_write_field(2, SRM_DP_COM_CONF_SYNC__DP_GWSEL_SYNC, 1);

        reg32_write(IPU2_BASE_ADDR + SRM_DP_FG_POS_SYNC__ADDR, 0x0);
        sdk_ipu_write_field(2, SRM_DP_FG_POS_SYNC__DP_FGXP_SYNC, ch27_x);   //40);
        sdk_ipu_write_field(2, SRM_DP_FG_POS_SYNC__DP_FGYP_SYNC, ch27_y);   //250);

        reg32_write(IPU2_BASE_ADDR + SRM_DP_GRAPH_WIND_CTRL_SYNC__ADDR, 0x0);
        //sdk_ipu_write_field(2,  IPU_DP_GRAPH_WIND_CTRL_SYNC__DP_GWAV_SYNC, 0x7F);
        sdk_ipu_write_field(2, SRM_DP_GRAPH_WIND_CTRL_SYNC__DP_GWAV_SYNC, 0xfe);
        //sdk_ipu_write_field(2,  IPU_DP_GRAPH_WIND_CTRL_SYNC__DP_GWAV_SYNC, 0xf0);
    }
    //***************************************************/
    //DI CONFIGURATION
    //****************************************************/

    //-------------------------------------------------------------
    //MICROCODE 
    microcode_config(2, 1,      //word address
                     1,         //stop
                     WROD,      //OPCODE
                     0,         //LF
                     0,         //AF
                     0,         //OPERAND
                     1,         //MAPPING
                     1,         //WAVEFORM
                     0,         //GLUELOGIC
                     5);        //SYNC

    microcode_config(2, 5,      //word address
                     1,         //stop
                     WROD,      //OPCODE
                     0,         //LF
                     0,         //AF
                     0,         //OPERAND
                     1,         //MAPPING
                     1,         //WAVEFORM
                     0,         //GLUELOGIC
                     5);        //SYNC

    //NL                 
    microcode_config(2, 2,      //word address
                     1,         //stop
                     WROD,      //OPCODE
                     0,         //LF
                     0,         //AF
                     0,         //OPERAND
                     1,         //MAPPING
                     1,         //WAVEFORM
                     8,         //GLUELOGIC
                     5);        //SYNC
    //EOL        
    microcode_config(2, 3,      //word address
                     1,         //stop
                     WROD,      //OPCODE
                     0,         //LF
                     0,         //AF
                     0,         //OPERAND
                     1,         //MAPPING
                     1,         //WAVEFORM
                     4,         //GLUELOGIC
                     5);        //SYNC
    //DATA
    microcode_config(2, 4,      //word address
                     1,         //stop
                     WROD,      //OPCODE
                     0,         //LF
                     0,         //AF
                     0,         //OPERAND
                     1,         //MAPPING
                     1,         //WAVEFORM //pointer
                     0,         //GLUELOGIC
                     5);        //SYNC

    microcode_event(2, 5, NL, 3, 2);    //prior=3, addr=2
    microcode_event(2, 5, NF, 0, 0);
    microcode_event(2, 5, NFIELD, 0, 0);
    microcode_event(2, 5, EOF_, 0, 0);
    microcode_event(2, 5, EOFIELD, 0, 0);
    microcode_event(2, 5, EOL, 2, 3);
    microcode_event(2, 5, NEW_CHAN, 0, 0);
    microcode_event(2, 5, NEW_ADDR, 0, 0);
    microcode_event(2, 5, NEW_DATA, 1, 4);

    //-------------------------------------------------------------
    //WR_CH_CONF_1  

    sdk_ipu_write_field(2, IPU_DC_WR_CH_CONF_1__PROG_START_TIME_1, 0);  //ANTITEARING START TIME
    sdk_ipu_write_field(2, IPU_DC_WR_CH_CONF_1__CHAN_MASK_DEFAULT_1, 0);    //just higher priority event will be served
    sdk_ipu_write_field(2, IPU_DC_WR_CH_CONF_1__PROG_CHAN_TYP_1, 0);    //Normal mode without anti-tearing
    sdk_ipu_write_field(2, IPU_DC_WR_CH_CONF_1__PROG_DISP_ID_1, 3); //select display 3 
    sdk_ipu_write_field(2, IPU_DC_WR_CH_CONF_1__PROG_DI_ID_1, 0);   // channel associated to DI0 
    sdk_ipu_write_field(2, IPU_DC_WR_CH_CONF_1__W_SIZE_1, 2);   //Component size access to DC set to 24bit
    sdk_ipu_write_field(2, IPU_DC_WR_CH_CONF_1__FIELD_MODE_1, 0);   //field mode enable

    sdk_ipu_write_field(2, IPU_DC_WR_CH_ADDR_1__ST_ADDR_1, 0);  //START ADDRESS OF CHANNEL
    /////////////////////////////////////////////////////////////////////////////////
    //WR_CH_CONF_1  

    sdk_ipu_write_field(2, IPU_DC_WR_CH_CONF_5__PROG_START_TIME_5, 0);  //ANTITEARING START TIME
    sdk_ipu_write_field(2, IPU_DC_WR_CH_CONF_5__CHAN_MASK_DEFAULT_5, 0);    //just higher priority event will be served
    sdk_ipu_write_field(2, IPU_DC_WR_CH_CONF_5__PROG_CHAN_TYP_5, 4);    //Normal mode without anti-tearing
    sdk_ipu_write_field(2, IPU_DC_WR_CH_CONF_5__PROG_DISP_ID_5, 3); //select display 3 
    sdk_ipu_write_field(2, IPU_DC_WR_CH_CONF_5__PROG_DI_ID_5, 0);   // channel associated to DI0 
    sdk_ipu_write_field(2, IPU_DC_WR_CH_CONF_5__W_SIZE_5, 2);   //Component size access to DC set to 24bit
    sdk_ipu_write_field(2, IPU_DC_WR_CH_CONF_5__FIELD_MODE_5, 0);   //field mode enable

    sdk_ipu_write_field(2, IPU_DC_WR_CH_ADDR_5__ST_ADDR_5, 0);  //START ADDRESS OF CHANNEL
    //-------------------------------------------------------------
    //GENERAL 

    sdk_ipu_write_field(2, IPU_DC_GEN__SYNC_PRIORITY_5, 1); //sets the priority of channel #5 to high.
    sdk_ipu_write_field(2, IPU_DC_GEN__MASK4CHAN_5, 0); // mask channel is associated to the sync flow via DC (without DP) 
    sdk_ipu_write_field(2, IPU_DC_GEN__MASK_EN, 0); // mask channel is disabled
    sdk_ipu_write_field(2, IPU_DC_GEN__DC_CH5_TYPE, 0); // alternate sync or asyn flow
    sdk_ipu_write_field(2, IPU_DC_GEN__SYNC_1_6, 2);    //Channel 1 of the DC handless sync flow
    //sdk_ipu_write_field(2, IPU_DC_WR_CH_CONF_5__PROG_DISP_ID_5, 0);//select display 3 
    //sdk_ipu_write_field(2, IPU_DC_WR_CH_CONF_5__PROG_DI_ID_5, 1);// channel associated to DI0 
    //-------------------------------------------------------------
    //DISP_CONF  

    sdk_ipu_write_field(2, IPU_DC_DISP_CONF1_3__ADDR_INCREMENT_3, 0);   //automatical address increase by 1
    sdk_ipu_write_field(2, IPU_DC_DISP_CONF1_3__DISP_TYP_3, 2); //paralel display without byte enable

    sdk_ipu_write_field(2, IPU_DC_DISP_CONF2_3__SL_3, CH23_FW); //stride line

    //-------------------------------------------------------------
    //DC_UGDE 

    sdk_ipu_write_field(2, IPU_DC_UGDE0_0__NF_NL_0, 0); //NL->0,NF->1,NFIELD->2                    
    sdk_ipu_write_field(2, IPU_DC_UGDE0_0__AUTORESTART_0, 0);   //no autorestart
    sdk_ipu_write_field(2, IPU_DC_UGDE0_0__ODD_EN_0, 1);    //diffrentiate between 'even' and 'odd'
    sdk_ipu_write_field(2, IPU_DC_UGDE0_0__COD_ODD_START_0, 1); //words 1,2,3 1st part
    sdk_ipu_write_field(2, IPU_DC_UGDE0_0__COD_EV_START_0, 5);  //word  5 2nd part
    //sdk_ipu_write_field(2, IPU_DC_UGDE0_0__COD_EV_PRIORITY_0,  1);//enabled. all others are disabled.
    sdk_ipu_write_field(2, IPU_DC_UGDE0_0__COD_EV_PRIORITY_0, 0);   //enabled. all others are disabled.
    sdk_ipu_write_field(2, IPU_DC_UGDE0_0__ID_CODED_0, 1);  //- idmac ch 28 !!!                    

    sdk_ipu_write_field(2, IPU_DC_UGDE0_1__STEP_0, 0);  //every data

    sdk_ipu_write_field(2, IPU_DC_UGDE0_2__OFFSET_DT_0, 0); //no offset

    sdk_ipu_write_field(2, IPU_DC_UGDE0_3__STEP_REPEAT_0, (CH23_FW - 1));

    sdk_ipu_write_field(2, IPU_DC_UGDE1_0__COD_EV_PRIORITY_1, 0);   //disable event 1
    sdk_ipu_write_field(2, IPU_DC_UGDE2_0__COD_EV_PRIORITY_2, 0);   //disable event 2
    sdk_ipu_write_field(2, IPU_DC_UGDE3_0__COD_EV_PRIORITY_3, 0);   //disable event 3

    //-------------------------------------------------------------
    //DC_MAP  
    sdk_ipu_write_field(2, IPU_DC_MAP_CONF_16__MD_OFFSET_2, 17);
    sdk_ipu_write_field(2, IPU_DC_MAP_CONF_16__MD_MASK_2, 0xFC);
    sdk_ipu_write_field(2, IPU_DC_MAP_CONF_15__MD_OFFSET_1, 11);
    sdk_ipu_write_field(2, IPU_DC_MAP_CONF_15__MD_MASK_1, 0xFC);
    sdk_ipu_write_field(2, IPU_DC_MAP_CONF_15__MD_OFFSET_0, 5);
    sdk_ipu_write_field(2, IPU_DC_MAP_CONF_15__MD_MASK_0, 0xFC);

    sdk_ipu_write_field(2, IPU_DC_MAP_CONF_0__MAPPING_PNTR_BYTE2_0, 2);
    sdk_ipu_write_field(2, IPU_DC_MAP_CONF_0__MAPPING_PNTR_BYTE1_0, 1);
    sdk_ipu_write_field(2, IPU_DC_MAP_CONF_0__MAPPING_PNTR_BYTE0_0, 0);

    //***************************************************/
    //DI CONFIGURATION
    //****************************************************/
    //hsync   - DI0 pin 3
    //vsync   - DI0 pin 2
    //data_en - DI0 pin 15
    //clk     - DI0 disp clk
    //
    //COUNTER 2 VSYNC
    //COUNTER 3 HSYNC
    //COUNTER 4 FIELD SYNC
    //COUNTER 5 ACTIVE VIDEO
    //COUNTER 8 ACTIVE DATA SYNC

    //-------------------------------------------------------------
    //BS_CLKGEN  

    //-------------------------------------------------------------
    //SW_GEN0  

#define DISP_CLK_PERIOD (0x10)

    //DW_GEN & DW_SET  
    //di_pointer_config(di, pointer, access, componnent, cst, pt0, pt1, pt2, pt3, pt4, pt5, pt6);
    //                                                     CS   11  12  13    14  15    16    17
    di_pointer_config(2, 0, 0, DISP_CLK_PERIOD / 16 - 1, DISP_CLK_PERIOD / 16 - 1, 0, 0, 0, 0, 0, 3,
                      0, 0);
    //di_pointer_config(0,0,1,1,0,0,   0,   0,   0,   3,   0,   0);

    //di_up_down_config(di, pointer, set, up, down)
    di_up_down_config(2, 0, 0, 0, 0, 0);
    di_up_down_config(2, 0, 0, 1, 0, 0);
    di_up_down_config(2, 0, 0, 2, 0, 0);
    di_up_down_config(2, 0, 0, 3, 0, DISP_CLK_PERIOD / 16 * 2);

    //no offset, clk divided by 2 (27M input, 13.5M disp clk)
    sdk_ipu_write_field(2, IPU_DI0_BS_CLKGEN0__DI0_DISP_CLK_OFFSET, 0);
    sdk_ipu_write_field(2, IPU_DI0_BS_CLKGEN0__DI0_DISP_CLK_PERIOD, DISP_CLK_PERIOD);
    sdk_ipu_write_field(2, IPU_DI0_BS_CLKGEN1__DI0_DISP_CLK_DOWN, 0x2);
    sdk_ipu_write_field(2, IPU_DI0_BS_CLKGEN1__DI0_DISP_CLK_UP, 0x1);
    //-------------------------------------------------------------
    //DI0_SCR  

    //old sdk_ipu_write_field(2, IPU_DI0_SCR_CONF__DI0_SCREEN_HEIGHT, DI_SCREEN_HEIGHT_1);

    sdk_ipu_write_field(2, IPU_DI0_SCR_CONF__DI0_SCREEN_HEIGHT, 805);
    //internal HSYNC
    di_sync_config(0,           // di, 
                   1,           // pointer
                   1343,        // RUN_VALUE_M1           
                   1,           // RUN_RESOLUTION         
                   0,           // OFFSET_VALUE           
                   0,           // OFFSET_RESOLUTION      
                   1,           // CNT_AUTO_RELOAD        
                   0,           // STEP_REPEAT           
                   0,           // CNT_CLR_SEL            
                   0,           // CNT_POLARITY_GEN_EN    
                   0,           // CNT_POLARITY_TRIGGER_SEL
                   0,           // CNT_POLARITY_CLR_SEL   
                   0,           // CNT_UP                 
                   0            // CNT_DOWN               
        );
    //OUTPUT HSYNC
    di_sync_config(0,           // di, 
                   2,           // pointer
                   1343,        // RUN_VALUE_M1           
                   1,           // RUN_RESOLUTION         
                   0,           // OFFSET_VALUE           
                   0,           // OFFSET_RESOLUTION      
                   1,           // CNT_AUTO_RELOAD        
                   0,           // STEP_REPEAT           
                   0,           // CNT_CLR_SEL            
                   0,           // CNT_POLARITY_GEN_EN    
                   0,           // CNT_POLARITY_TRIGGER_SEL
                   0,           // CNT_POLARITY_CLR_SEL   
                   0,           // CNT_UP                 
                   272          // CNT_DOWN               
        );
    //Output Vsync
    di_sync_config(0,           // di, 
                   3,           // pointer
                   805,         // RUN_VALUE_M1           
                   2,           // RUN_RESOLUTION         
                   0,           // OFFSET_VALUE           
                   0,           // OFFSET_RESOLUTION      
                   1,           // CNT_AUTO_RELOAD        
                   0,           // STEP_REPEAT           
                   0,           // CNT_CLR_SEL            
                   1,           // CNT_POLARITY_GEN_EN    
                   2,           // CNT_POLARITY_TRIGGER_SEL
                   0,           // CNT_POLARITY_CLR_SEL   
                   0,           // CNT_UP                 
                   12           // CNT_DOWN               
        );

    //Active Lines start points
    di_sync_config(0,           // di, 
                   4,           // pointer
                   0,           // RUN_VALUE_M1           
                   3,           // RUN_RESOLUTION         
                   35,          // OFFSET_VALUE           
                   3,           // OFFSET_RESOLUTION      
                   0,           // CNT_AUTO_RELOAD        
                   768,         // STEP_REPEAT           
                   4,           // CNT_CLR_SEL            
                   0,           // CNT_POLARITY_GEN_EN    
                   0,           // CNT_POLARITY_TRIGGER_SEL
                   0,           // CNT_POLARITY_CLR_SEL   
                   0,           // CNT_UP                 
                   0            // CNT_DOWN               
        );
    di_sync_config(0,           // di, 
                   5,           // pointer
                   0,           // RUN_VALUE_M1           
                   1,           // RUN_RESOLUTION         
                   296,         // OFFSET_VALUE           
                   1,           // OFFSET_RESOLUTION      
                   0,           // CNT_AUTO_RELOAD        
                   1024,        // STEP_REPEAT           
                   5,           // CNT_CLR_SEL            
                   0,           // CNT_POLARITY_GEN_EN    
                   0,           // CNT_POLARITY_TRIGGER_SEL
                   0,           // CNT_POLARITY_CLR_SEL   
                   0,           // CNT_UP                 
                   0            // CNT_DOWN               
        );

    sdk_ipu_write_field(2, IPU_DI0_SYNC_AS_GEN__DI0_SYNC_START, 2); //2lines predictions
    sdk_ipu_write_field(2, IPU_DI0_SYNC_AS_GEN__DI0_VSYNC_SEL, 2);  //PIN3 as VSYNC
    //ip_rmwf_tb(0);

    //------------------------------------------------------------

    //GENERAL @@ 

    sdk_ipu_write_field(2, IPU_DI0_GENERAL__DI0_CLK_EXT, 1);    //select clock from TVE as display clock

    sdk_ipu_write_field(2, IPU_DI0_GENERAL__DI0_POLARITY_DISP_CLK, 1);  //VIDEO_DATA_CLK POLARITY
    sdk_ipu_write_field(2, IPU_DI0_GENERAL__DI0_POLARITY_8, 1);
    sdk_ipu_write_field(2, IPU_DI0_GENERAL__DI0_POLARITY_5, 1);
    sdk_ipu_write_field(2, IPU_DI0_GENERAL__DI0_POLARITY_4, 1);
    sdk_ipu_write_field(2, IPU_DI0_GENERAL__DI0_POLARITY_3, 0); //HSYNC POLARITY
    sdk_ipu_write_field(2, IPU_DI0_GENERAL__DI0_POLARITY_2, 0); //VSYNC POLARITY

    sdk_ipu_write_field(2, IPU_DI0_POL__DI0_DRDY_POLARITY_15, 1);   //VIDEO_DATA_EN POLARITY

    //-------------------------------------------------------------
    //DI0 config end
    //*********************************************************

    //*********************************************************
    //START DI OUTPUT 

    //enable DI0 (display interface 1)
    sdk_ipu_write_field(2, IPU_IPU_CONF__DI0_EN, 1);
    //disable DI1 (display interface 0)
    sdk_ipu_write_field(2, IPU_IPU_CONF__DI1_EN, 0);
    //disable DP (display processor)
    sdk_ipu_write_field(2, IPU_IPU_CONF__DP_EN, 1);
    //enble DC (display controller)
    sdk_ipu_write_field(2, IPU_IPU_CONF__DC_EN, 1);
    //enble DMFC (display multi-fifo controller)
    sdk_ipu_write_field(2, IPU_IPU_CONF__DMFC_EN, 1);

    sdk_ipu_write_field(2, IPU_IDMAC_LOCK_EN_1__IDMAC_LOCK_EN_23, 2);
    sdk_ipu_write_field(2, IPU_IDMAC_LOCK_EN_1__IDMAC_LOCK_EN_27, 2);

    sdk_ipu_write_field(2, IPU_IDMAC_CH_EN_1__IDMAC_CH_EN_23, 0x1); //enable channel 23 

    if (overlay) {
        sdk_ipu_write_field(2, IPU_IPU_CH_DB_MODE_SEL_0__DMA_CH_DB_MODE_SEL_27, 0x1);   //enable double buffer mode
        sdk_ipu_write_field(2, IPU_IDMAC_CH_EN_1__IDMAC_CH_EN_27, 0x1); //enable channel 27 - foreground

        sdk_ipu_write_field(2, IPU_IPU_SRM_PRI2__DP_S_SRM_MODE, 3);
        sdk_ipu_write_field(2, IPU_IPU_SRM_PRI2__DP_SRM_PRI, 0x7);
    }

    sdk_ipu_write_field(2, IPU_IPU_CH_BUF0_RDY0__DMA_CH_BUF0_RDY_27, 1);
    sdk_ipu_write_field(2, IPU_IPU_CH_BUF1_RDY0__DMA_CH_BUF1_RDY_27, 1);

    //start ipu DI0 output
    sdk_ipu_write_field(2, IPU_IPU_DISP_GEN__DI0_COUNTER_RELEASE, 1);
}
