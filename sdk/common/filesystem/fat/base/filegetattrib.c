/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/base/filegetattrib.c $
 $Revision: 7 $                                       
 $Date: 9/13/03 12:20p $
 Description: filegetattrib.c
 Notes:	This file read provides base api functon to get the attribute of the file.
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include <error.h>
#include <filesystem/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "fat_internal.h"
#include "diroffset.h"

/*----------------------------------------------------------------------------

>  Function Name:  RtStatus_t filegetattrib(uint8_t *FilePath)

   FunctionType:  Reentrant

   Inputs:        1)Pointer to the filepath

   Outputs:       Returns directory attributes for a file, or ERROR Code if  Error Occurs

   Description:   Gets directory attributes for a file

<
----------------------------------------------------------------------------*/
RtStatus_t filegetattrib(uint8_t *FilePath)
{
    int32_t dirattribute,HandleNumber;
    uint8_t *buf;
    uint32_t cacheToken;

    if((HandleNumber = Fopen(FilePath,(uint8_t *)"r")) <0)
    {
        return HandleNumber;
    }
    
	EnterNonReentrantSection();
    if((buf = (uint8_t *)FSReadSector(Handle[HandleNumber].Device,Handle[HandleNumber].DirSector,WRITE_TYPE_RANDOM, &cacheToken)) ==(uint8_t*)0)
	{
    	    LeaveNonReentrantSection();
		return ERROR_OS_FILESYSTEM_READSECTOR_FAIL;
	}
    dirattribute = FSGetByte((uint8_t*)buf,(DIR_ATTRIBUTEOFFSET + Handle[HandleNumber].diroffset));
    FSReleaseSector(cacheToken);
	LeaveNonReentrantSection();
    
	Freehandle(HandleNumber);
    return  dirattribute;
}
