/******************************************\
*                                          *
* Advanced Authoring Format                *
*                                          *
* Copyright (c) 1998 Avid Technology, Inc. *
* Copyright (c) 1998 Microsoft Corporation *
*                                          *
\******************************************/
/***********************************************************************
 *
 *              Copyright (c) 1996 Avid Technology, Inc.
 *
 * Permission to use, copy and modify this software and to distribute
 * and sublicense application software incorporating this software for
 * any purpose is hereby granted, provided that (i) the above
 * copyright notice and this permission notice appear in all copies of
 * the software and related documentation, and (ii) the name Avid
 * Technology, Inc. may not be used in any advertising or publicity
 * relating to the software without the specific, prior written
 * permission of Avid Technology, Inc.
 *
 * THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY
 * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
 * IN NO EVENT SHALL AVID TECHNOLOGY, INC. BE LIABLE FOR ANY DIRECT,
 * SPECIAL, INCIDENTAL, INDIRECT, CONSEQUENTIAL OR OTHER DAMAGES OF
 * ANY KIND, OR ANY DAMAGES WHATSOEVER ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE, INCLUDING, 
 * WITHOUT  LIMITATION, DAMAGES RESULTING FROM LOSS OF USE,
 * DATA OR PROFITS, AND WHETHER OR NOT ADVISED OF THE POSSIBILITY OF
 * DAMAGE, REGARDLESS OF THE THEORY OF LIABILITY.
 *
 ************************************************************************/
/************************************************************************
 *
 * Omf2Aaf.h Describes structures and prototypes for the OMF to AAF 
 *          conversion utility.
 *
 ************************************************************************/

  
#if defined(_MAC) || defined(macintosh)
#include <initguid.h> // define all of the AAF guids.
#include "AAF.h"
#else
#include "AAF.h"

#endif


#include "AAFTypes.h"
//#include "aafCvt.h"
#include "AAFResult.h"
#include "AAFDefUIDs.h"

const int MAX_INDENT = 8;

// ============================================================================
// simple helper class to initialize and cleanup COM library.
// ============================================================================
struct CComInitialize
{
	CComInitialize()
	{
		CoInitialize(NULL);
	}

	~CComInitialize()
	{
		CoUninitialize();
	}
};

typedef struct _AafOmfGlobals
{
	aafInt16		numIndents;
	char			indentLeader[MAX_INDENT+1];	

	aafBool			bVerboseMode;
	aafBool			bCreateTOCFile;
	aafBool			bConvertAllObjects;
	aafBool			bOMFFileOpen;
	aafBool			bAAFFileOpen;
	aafBool			bLogFile;
	aafBool			bDefFile;

	// For Statistical summary
	aafInt32		nNumOMFMobs;
	aafInt32		nNumAAFMobs;
	aafInt32		nNumOMFObjects;
	aafInt32		nNumAAFObjects;
	aafInt32		nNumOMFProperties;
	aafInt32		nNumAAFProperties;
	aafInt32		nNumUndefinedOMFObjects;
	aafInt32		nNumUndefinedOMFProperties;
	aafInt32		nNumUndefinedAAFObjects;
	aafInt32		nNumUndefinedAAFProperties;

	char			sInFileName[256];
	char			sTOCFileName[256];
	char			sDefinitionFileName[256];
	char			sOutFileName[256];
	char			sLogFileName[256];
	char*			pProgramName;
} AafOmfGlobals;

void deleteFile( char* fileName );
void IncIndentLevel( void );
void DecIndentLevel( void );
void AUIDtoString(aafUID_t *uid, char *buf);
