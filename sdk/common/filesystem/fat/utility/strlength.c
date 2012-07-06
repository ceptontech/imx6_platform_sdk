/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/Utility/Strlength.c $                                        
 $Revision: 4 $                                       
 $Date: 9/13/03 12:23p $                                           
 Description: Strlength.c
 Notes:	This file read provides utility function to find string length.
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include "fat_internal.h"
#include <error.h>
#include <filesystem/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "bootsecoffset.h" 
/*----------------------------------------------------------------------------
>  Function Name:  int32_t StrlengthW(uint8_t *filepath)

   FunctionType:   Reentrant

   Inputs:         pointer to filepath
                   
   Outputs:        Returns no. of characters in the string.(It considers the 
                   string as UNICODE.)
   
   Description:    Finds the no. of characters in the string i.e. length of the string. 
<
----------------------------------------------------------------------------*/
int32_t StrlengthW(uint8_t *filepath)
{
    int32_t strlength=0, word,offset=0;      

    while(1)
    {
        if((word =FSGetWord(filepath,offset))=='\0')
            break;
        offset+=2;
        strlength++;
    }
    (void)word;
    return (strlength);
}

/*----------------------------------------------------------------------------
>  Function Name:  int32_t Strlength(uint8_t *filepath)

   FunctionType:   Reentrant

   Inputs:         pointer to filepath
                   
   Outputs:        Returns the no. of characters in the string.(It considers the 
                   string as DBCS.)
   
   Description:    Finds the no. of characters in the string i.e. length of the string.
<
----------------------------------------------------------------------------*/
int32_t Strlength(uint8_t *filepath)
{
    int32_t strlength=0, offset=0;     
    int32_t Char;

    while(1)
    {
        Char = GetChar(filepath,&offset);
        if(Char == '\0')
            break;
        strlength++;
    }
    return (strlength);
}



       	