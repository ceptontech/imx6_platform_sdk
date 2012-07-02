/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/common/Fsinit.c $              
 $Revision: 4 $                                       
 $Date: 9/18/03 10:37a $      
 Description: Fsinit.c
 Notes:
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include "types.h"
#include "fstypes.h"
#include "errordefs.h"
#include "platform.h"
#include "handletable.h"
#include "filesystem/fat/include/devicetable.h"
#include "filesystem/filesystem.h"
#include "filesystem/fat/include/fat_internal.h"

/*----------------------------------------------------------------------------

>  Function Name:  int32_t FSInit(int32_t _X *bufx, int32_t _Y *bufy, int32_t maxdevices, int32_t maxhandles, int32_t maxcaches)

   FunctionType:  

   Inputs:         a) Pointer to X buffer for allocation of cache buffers
                   b) Pointer to Y buffer for allocation of handles, descriptors, etc
                   c) Max number of internal + external media supported.
                   d) Max handles supported.
                   e) Max cache buffers supported.

   Outputs:        Returns 0, if Success, else ERROR CODE

   Description:    Initialization of FileSystem.
<
--------- -------------------------------------------------------------------*/
void  FSClearDriveBuf(int32_t DriveNumber,int32_t maxhandles)
{
    int32_t i;
    
    // setup handle
    for (i=0; i < maxhandles; i++)
    {
        if(Handle[i].Device == DriveNumber)
            Handle[i].HandleActive=0;
    }

}

