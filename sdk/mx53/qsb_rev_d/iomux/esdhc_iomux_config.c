/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: esdhc_iomux_config.c

/* ------------------------------------------------------------------------------
 * <auto-generated>
 *     This code was generated by a tool.
 *     Runtime Version:3.3.2.0
 *
 *     Changes to this file may cause incorrect behavior and will be lost if
 *     the code is regenerated.
 * </auto-generated>
 * ------------------------------------------------------------------------------
*/

#include "iomux_config.h"
#include "iomux_define.h"
#include "registers/regsiomuxc.h"
#include "registers/regsesdhc.h"
#include <assert.h>

void can_iomux_config(int instance)
{
    switch (instance)
    {
        case HW_ESDHC1:
            return esdhc1_iomux_config();

        case HW_ESDHC2:
            return esdhc2_iomux_config();

        case HW_ESDHC3:
            return esdhc3_iomux_config();

        case HW_ESDHC4:
            return esdhc4_iomux_config();

        default:
            assert(false);
    }
}
