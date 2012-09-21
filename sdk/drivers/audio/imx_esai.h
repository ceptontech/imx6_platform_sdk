/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __IMX_ESAI_H__
#define __IMX_ESAI_H__

#define ESAI_TFCR_TE(x) ((0x3f >> (6 - (((x) + 1) >> 1))) << 2)
#define ESAI_TFCR_TFWM(x)	(((x) - 1) << 8)

#define ESAI_RFCR_RE(x) ((0xf >> (4 - (((x) + 1) >> 1))) << 2)
#define ESAI_RFCR_RFWM(x)       (((x)-1) << 8)

#define ESAI_WORD_LEN_32	(0x00 << 16)
#define ESAI_WORD_LEN_28	(0x01 << 16)
#define ESAI_WORD_LEN_24	(0x02 << 16)
#define ESAI_WORD_LEN_20	(0x03 << 16)
#define ESAI_WORD_LEN_16	(0x04 << 16)
#define ESAI_WORD_LEN_12	(0x05 << 16)
#define ESAI_WORD_LEN_8		(0x06 << 16)
#define ESAI_WORD_LEN_4		(0x07 << 16)
#define ESAI_WORD_LEN_MSK	(0x7 << 16)
#define ESAI_WORD_LEN_SHT	16

#define ESAI_TCR_TE(x) (0x3f >> (6 - (((x) + 1) >> 1)))

#define ESAI_TCR_TSWS_STL8_WDL8	(0x00 << 10)
#define ESAI_TCR_TSWS_STL12_WDL8	(0x04 << 10)
#define ESAI_TCR_TSWS_STL12_WDL12	(0x01 << 10)
#define ESAI_TCR_TSWS_STL16_WDL8	(0x08 << 10)
#define ESAI_TCR_TSWS_STL16_WDL12	(0x05 << 10)
#define ESAI_TCR_TSWS_STL16_WDL16	(0x02 << 10)
#define ESAI_TCR_TSWS_STL20_WDL8	(0x0c << 10)
#define ESAI_TCR_TSWS_STL20_WDL12	(0x09 << 10)
#define ESAI_TCR_TSWS_STL20_WDL16	(0x06 << 10)
#define ESAI_TCR_TSWS_STL20_WDL20	(0x03 << 10)
#define ESAI_TCR_TSWS_STL24_WDL8	(0x10 << 10)
#define ESAI_TCR_TSWS_STL24_WDL12	(0x0d << 10)
#define ESAI_TCR_TSWS_STL24_WDL16	(0x0a << 10)
#define ESAI_TCR_TSWS_STL24_WDL20	(0x07 << 10)
#define ESAI_TCR_TSWS_STL24_WDL24	(0x1e << 10)
#define ESAI_TCR_TSWS_STL32_WDL8	(0x18 << 10)
#define ESAI_TCR_TSWS_STL32_WDL12	(0x15 << 10)
#define ESAI_TCR_TSWS_STL32_WDL16	(0x12 << 10)
#define ESAI_TCR_TSWS_STL32_WDL20	(0x0f << 10)
#define ESAI_TCR_TSWS_STL32_WDL24	(0x1f << 10)

#define ESAI_TCR_TMOD_NORMAL	(0x00 << 8)
#define ESAI_TCR_TMOD_ONDEMAND	(0x01 << 8)
#define ESAI_TCR_TMOD_NETWORK	(0x01 << 8)
#define ESAI_TCR_TMOD_RESERVED (0x02 << 8)
#define ESAI_TCR_TMOD_AC97	(0x03 << 8)

#define ESAI_TCCR_TPSR_BYPASS (1 << 8)
#define ESAI_TCCR_TPSR_DIV8 (0 << 8)

#define ESAI_TCCR_TFP(x)	((x & 0xf) << 14)

#define ESAI_TCCR_TDC(x)	(((x) & 0x1f) << 9)

#define ESAI_TCCR_TPM(x)	(x & 0xff)

#define ESAI_RCR_RE_MSK	(0xF << 0)
#define ESAI_RCR_RE(x) (0xf >> (4 - ((x + 1) >> 1)))

#define ESAI_RCR_RSWS_STL8_WDL8	(0x00 << 10)
#define ESAI_RCR_RSWS_STL12_WDL8	(0x04 << 10)
#define ESAI_RCR_RSWS_STL12_WDL12	(0x01 << 10)
#define ESAI_RCR_RSWS_STL16_WDL8	(0x08 << 10)
#define ESAI_RCR_RSWS_STL16_WDL12	(0x05 << 10)
#define ESAI_RCR_RSWS_STL16_WDL16	(0x02 << 10)
#define ESAI_RCR_RSWS_STL20_WDL8	(0x0c << 10)
#define ESAI_RCR_RSWS_STL20_WDL12	(0x09 << 10)
#define ESAI_RCR_RSWS_STL20_WDL16	(0x06 << 10)
#define ESAI_RCR_RSWS_STL20_WDL20	(0x03 << 10)
#define ESAI_RCR_RSWS_STL24_WDL8	(0x10 << 10)
#define ESAI_RCR_RSWS_STL24_WDL12	(0x0d << 10)
#define ESAI_RCR_RSWS_STL24_WDL16	(0x0a << 10)
#define ESAI_RCR_RSWS_STL24_WDL20	(0x07 << 10)
#define ESAI_RCR_RSWS_STL24_WDL24	(0x1e << 10)
#define ESAI_RCR_RSWS_STL32_WDL8	(0x18 << 10)
#define ESAI_RCR_RSWS_STL32_WDL12	(0x15 << 10)
#define ESAI_RCR_RSWS_STL32_WDL16	(0x12 << 10)
#define ESAI_RCR_RSWS_STL32_WDL20	(0x0f << 10)
#define ESAI_RCR_RSWS_STL32_WDL24	(0x1f << 10)

#define ESAI_RCCR_RPSR_BYPASS (1 << 8)
#define ESAI_RCCR_RPSR_DIV8 (0 << 8)

#define ESAI_RCCR_RFP(x)	((x & 0xf) << 14)

#define ESAI_RCCR_RDC(x)	(((x) & 0x1f) << 9)

#define ESAI_RCCR_RPM(x)	(x & 0xff)

#define ESAI_TSM_NUM(x)  (0xffffffff >> (32-x))

#define ESAI_GPIO_ESAI		0xfff

#define ESAI_WATERMARK 		64
/////////////////////////////////
typedef enum {
    ESAI_HW_PARA_ECR,
    ESAI_HW_PARA_TCR,
    ESAI_HW_PARA_RCR,
    ESAI_HW_PARA_TCCR,
    ESAI_HW_PARA_RCCR,
    ESAI_HW_PARA_TFCR,
    ESAI_HW_PARA_RFCR,
    ESAI_HW_PARA_TSR,
    ESAI_HW_PARA_SAICR,
    ESAI_HW_PARA_TSM,           //time slot mask
    ESAI_HW_PARA_RSM,           //time slot mask
    ESAI_HW_PARA_TX_WL,         //word len in bits
    ESAI_HW_PARA_RX_WL,         //word len in bits
} esai_hw_para_type_e;

typedef enum {
    ESAI_STATUS_ESR,
    ESAI_STATUS_TFSR,
    ESAI_STATUS_RFSR,
    ESAI_STATUS_SAISR,
} esai_status_e;

typedef enum {
    ESAI_SUB_ENABLE_TYPE_ESAI,
    ESAI_SUB_ENABLE_TYPE_TX,
    ESAI_SUB_ENABLE_TYPE_RX,
    ESAI_SUB_ENABLE_TYPE_TXFIFO,
    ESAI_SUB_ENABLE_TYPE_RXFIFO,
} esai_sub_enable_type_e;

#endif
