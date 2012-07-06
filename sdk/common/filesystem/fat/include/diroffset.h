/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
/* Fields of Directory Record and their offset in Byte */



#define DIR_NAMEOFFSET					0
 
#define DIR_EXTOFFSET					8

#define DIR_ATTRIBUTEOFFSET				11

#define DIR_CRTTIMEOFFSET				14

#define DIR_CRTDATEOFFSET				16

#define DIR_LSTACCDATEOFFSET			18

#define DIR_FSTCLUSHIOFFSET				20

#define DIR_WRTTIMEOFFSET				22

#define DIR_WRTDATEOFFSET				24

#define DIR_FSTCLUSLOOFFSET				26

#define DIR_FILESIZEOFFSET				28



/* Fields of Long Directory record and their offset in byte */

#define    LDIRORDOFFSET				0

#define    LDIRNAME1OFFSET				1

#define    LDIRATTRIOFFSET				11

#define    LDIRTYPEOFFSET				12

#define    LDIRCHKSUMOFFSET				13

#define    LDIRNAME2OFFSET				14

#define    LDIRFSTCLUSNOOFFSET			26

#define    LDIRNAME3OFFSET				28



#define DIRRECORDSIZE					32 

#define LDIRNAME1SIZE					10

#define LDIRNAME2SIZE					14 

#define LDIRNAME3SIZE					 4 

#define DIR_NAME_SIZE					11

#define DELETEDDIRRECORDCHARA			0xE5

#define FIRSTSUBDIRNAME                 0x20202E

#define SECONDSUBDIRNAME                0x202E2E

#define DIR_RECORD_PERSECTOR			16

#define LONGDIRATTRIBUTE				0x0F

#define LONGDIRCH_PER_RECORD		   	13