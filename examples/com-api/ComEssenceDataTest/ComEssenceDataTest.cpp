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
// @doc INTERNAL
// @com This file implements the module test for CAAFDefinitionObject
/******************************************\
*                                          *
* Advanced Authoring Format                *
*                                          *
* Copyright (c) 1998 Avid Technology, Inc. *
* Copyright (c) 1998 Microsoft Corporation *
*                                          *
\******************************************/



/******************************************\
*                                          *
* Advanced Authoring Format                *
*                                          *
* Copyright (c) 1998 Avid Technology, Inc. *
* Copyright (c) 1998 Microsoft Corporation *
*                                          *
\******************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//#include "AAFPluginManager.h"

#include "AAFTypes.h"
#include "AAFResult.h"
#include "AAFDefUIDs.h"

// Include the AAF interface declarations.
#include "AAF.h"




// Include the defintions for the AAF Stored Object identifiers.
#define INIT_AUID
#include "AAFStoredObjectIDs.h"




// This static variables are here so they can be referenced 
// thru out the whole program.

static aafSourceRef_t sourceRef; 

#define assert(b, msg) \
  if (!(b)) {fprintf(stderr, "ASSERT: %s\n\n", msg); exit(1);}


static aafBool	EqualAUID(aafUID_t *uid1, aafUID_t *uid2)
{
	return(memcmp((char *)uid1, (char *)uid2, sizeof(aafUID_t)) == 0 ? AAFTrue : AAFFalse);
}

#define TEST_PATH	L"SomeFile.dat"

static void     LogError(HRESULT errcode, int line, char *file)
{
  printf("Error '%0x' returned at line %d in %s\n", errcode, line, file);
}

static HRESULT moduleErrorTmp = S_OK; /* note usage in macro */
#define check(a)  \
{ moduleErrorTmp = a; \
	if (!SUCCEEDED(moduleErrorTmp)) \
	{ \
	    LogError(moduleErrorTmp, __LINE__, __FILE__);\
		goto cleanup; \
	} \
}

#define checkFatal(a)  \
{ moduleErrorTmp = a; \
  if (!SUCCEEDED(moduleErrorTmp)) \
     exit(1);\
}

static void convert(char* cName, size_t length, const wchar_t* name)
{
  assert((name && *name), "Valid input name");
  assert(cName != 0, "Valid output buffer");
  assert(length > 0, "Valid output buffer size");

  size_t status = wcstombs(cName, name, length);
  if (status == (size_t)-1) {
    fprintf(stderr, ": Error : Conversion failed.\n\n");
    exit(1);  
  }
}

static void AUIDtoString(aafUID_t *uid, char *buf)
{
	sprintf(buf, "%08lx-%04x-%04x-%02x%02x%02x%02x%02x%02x%02x%02x",
			uid->Data1, uid->Data2, uid->Data3, (int)uid->Data4[0],
			(int)uid->Data4[1], (int)uid->Data4[2], (int)uid->Data4[3], (int)uid->Data4[4],
			(int)uid->Data4[5], (int)uid->Data4[6], (int)uid->Data4[7]);
}

typedef enum { testRawCalls, testStandardCalls, testMultiCalls, testFractionalCalls } testType_t;

typedef aafInt16	AAFByteOrder;
const AAFByteOrder INTEL_ORDER		      = 0x4949; // 'II' for Intel
const AAFByteOrder MOTOROLA_ORDER         = 0x4d4d; // 'MM' for Motorola


AAFByteOrder GetNativeByteOrder(void);
void AAFByteSwap32(
			aafInt32 *lp);	/* IN/OUT -- Byte swap this value */
void AAFByteSwap16(
			aafInt16 * wp);	/* IN/OUT -- Byte swap this value */
void scanSwappedWAVEData(aafUInt8 **srcBufHdl, aafInt32 maxsize, void *data);
AAFRESULT loadWAVEHeader(aafUInt8 *buf,
										aafUInt16 *bitsPerSample,
										aafUInt16 *numCh,
										aafRational_t *sampleRate,
										aafUInt32 *dataOffset,
										aafUInt32 *dataLen);

typedef struct
{
	aafWChar	*dataFilename;
	aafUID_t	dataFormat;
} testDataFile_t;

static HRESULT CreateAAFFile(aafWChar * pFileName, testDataFile_t *dataFile, testType_t testType)
{
	IAAFFile*					pFile = NULL;
	IAAFHeader*					pHeader = NULL;
	IAAFDictionary*					pDictionary = NULL;
	IAAFMob*					pMob = NULL;
	IAAFEssenceDescriptor*		aDesc = NULL;
	IAAFMasterMob*				pMasterMob = NULL;
	IAAFEssenceAccess*			pEssenceAccess = NULL;
	IAAFEssenceFormat*			pFormat;
	// !!!Previous revisions of this file contained variables here required to handle external essence
	aafUID_t					masterMobID;
	aafProductIdentification_t	ProductInfo;
	aafRational_t				editRate = {44100, 1};
	aafRational_t				sampleRate = {44100, 1};
	FILE*						pWavFile = NULL;
	unsigned char				dataBuff[4096], *dataPtr;
	size_t						bytesRead;
	aafUInt32					bytesWritten, dataOffset, dataLen;
	aafUInt16					bitsPerSample, numCh;
		IAAFEssenceFormat	*format;
		aafInt32			n, numSpecifiers;
		aafUID_t			essenceFormatCode, testContainer;
	IAAFLocator	*pLocator;
		  
  // delete any previous test file before continuing...
  char chFileName[1000];
  convert(chFileName, sizeof(chFileName), pFileName);
  remove(chFileName);
  if(dataFile != NULL)
  {
	// delete any previous test file before continuing...
	char chFileName[1000];
	convert(chFileName, sizeof(chFileName), dataFile->dataFilename);
	remove(chFileName);
  }


	ProductInfo.companyName = L"AAF Developers Desk";
	ProductInfo.productName = L"Essence Data Test";
	ProductInfo.productVersion.major = 1;
	ProductInfo.productVersion.minor = 0;
	ProductInfo.productVersion.tertiary = 0;
	ProductInfo.productVersion.patchLevel = 0;
	ProductInfo.productVersion.type = kVersionUnknown;
	ProductInfo.productVersionString = NULL;
	ProductInfo.productID = -1;
	ProductInfo.platform = NULL;

	check(CoCreateInstance(CLSID_AAFFile,
               NULL, 
               CLSCTX_INPROC_SERVER, 
               IID_IAAFFile, 
               (void **)&pFile));

	// Create and open new AAF File
	check(pFile->Initialize());
	check(pFile->OpenNewModify(pFileName, 0, &ProductInfo));
	check(pFile->GetHeader(&pHeader));

  // Get the AAF Dictionary so that we can create valid AAF objects.
  check(pHeader->GetDictionary(&pDictionary));

	// !!!Previous revisions of this file contained code here required to handle external essence

  // Get a Master MOB Interface
	check(pDictionary->CreateInstance( &AUID_AAFMasterMob,
						   IID_IAAFMasterMob, 
						   (IUnknown **)&pMasterMob));
	// Get a Mob interface and set its variables.
	check(pMasterMob->QueryInterface(IID_IAAFMob, (void **)&pMob));
	check(pMob->GetMobID(&masterMobID));
	check(pMob->SetName(L"A Master Mob"));
	
	// Add it to the file 
	check(pHeader->AppendMob(pMob));

	// !!!Previous revisions of this file contained code here required to handle external essence

	if(dataFile != NULL)
	{
		// Make a locator, and attach it to the EssenceDescriptor
		check(pDictionary->CreateInstance(&AUID_AAFNetworkLocator,
								IID_IAAFLocator, 
								(IUnknown **)&pLocator));		
		check(pLocator->SetPath (dataFile->dataFilename));
		testContainer = dataFile->dataFormat;
	}
	else
	{
		pLocator = NULL;
		testContainer = ContainerAAF;
	}


	// open the Essence file to be included in this AAF file("Laser.wav")
	pWavFile = fopen("Laser.wav", "r");
	if (pWavFile)
	{
		// read in the essence data
		bytesRead = fread(dataBuff, sizeof(unsigned char), sizeof(dataBuff), pWavFile);
		check(loadWAVEHeader(dataBuff,
										&bitsPerSample,
										&numCh,
										&sampleRate,
										&dataOffset,
										&dataLen));
		if(testType != testRawCalls)
		{
			dataPtr = dataBuff + dataOffset;
		}
		else
		{	
			dataPtr = dataBuff;
			dataLen = bytesRead;
		}

		// now create the Essence data file
		check(pMasterMob->CreateEssence(1,				// Slot ID
									DDEF_Audio,		// MediaKind
									CodecWave,		// codecID
									editRate,		// edit rate
									sampleRate,		// sample rate
									kSDKCompressionDisable,
									pLocator,	// In current file
									testContainer,	// In AAF Format
									&pEssenceAccess));// Compress disabled

		check(pEssenceAccess->GetFileFormatParameterList (&format));
		check(format->NumFormatSpecifiers (&numSpecifiers));
		for(n = 0; n < numSpecifiers; n++)
		{
			check(format->GetIndexedFormatSpecifier (n, &essenceFormatCode, 0, NULL, NULL));
		}

		// Tell the AAFEssenceAccess what the format is.
		check(pEssenceAccess->GetEmptyFileFormat (&pFormat));
		check(pFormat->NumFormatSpecifiers (&numSpecifiers));

		aafInt32	sampleSize = bitsPerSample;
		check(pFormat->AddFormatSpecifier (kAAFAudioSampleBits, sizeof(sampleSize), (aafUInt8 *)&sampleSize));
		check(pEssenceAccess->PutFileFormat (pFormat));
		
		// write out the data
		if(testType == testRawCalls)
		{
			check(pEssenceAccess->WriteRawData(	dataLen,	// Number of Samples
											dataPtr,	// THE Raw data
											sizeof(dataBuff)));// buffer size
		}
		else if(testType == testStandardCalls)
		{
			check(pEssenceAccess->WriteSamples(	dataLen,	//!!! hardcoded bytes/sample ==1// Number of Samples
											dataPtr,	// THE Raw data
											sizeof(dataBuff)));// buffer size
		}
		else if(testType == testFractionalCalls)
		{
			check(pEssenceAccess->WriteFractionalSample(
											dataLen,			// number of bytes
											dataPtr,			// THE data	
											&bytesWritten));	// !!!Check this when it works
		}
		else if(testType == testMultiCalls)
		{
			aafmMultiXfer_t xfer;

//!!!		xfer.subTrackNum = _channels[0].physicalOutChan;
			xfer.numSamples = dataLen;	//!!! hardcoded bytes/sample ==1
			xfer.buflen = sizeof(dataBuff);
			xfer.buffer = dataPtr;
			xfer.bytesXfered = 0;
	
			check(pEssenceAccess->WriteMultiSamples(1, &xfer));
		}

		// close essence data file
		fclose(pWavFile);

		// Finish writing the destination
		pEssenceAccess->CompleteWrite();
	}
	else
	{
		printf("***Failed to open Wave file Laser.wav\n");
	}

	// Release all unnecesary interfaces
	pEssenceAccess->Release();
	pEssenceAccess= NULL;

	pMasterMob->Release();
	pMasterMob = NULL;
	pMob->Release();
	pMob = NULL;

  pDictionary->Release();
  pDictionary = NULL;
	pHeader->Release();
	pHeader = NULL;
	pFile->Close();
	pFile->Release();
	pFile = NULL;

cleanup:
	// Cleanup and return
	if (pEssenceAccess)
		pEssenceAccess->Release();
	
	if (pMasterMob)
		pMasterMob->Release();

	if (pMob)
		pMob->Release();

	if (pDictionary)
		pDictionary->Release();

	if (pHeader)
		pHeader->Release();

	if (pFile)
		pFile->Release();

	return moduleErrorTmp;
}

static HRESULT ReadAAFFile(aafWChar * pFileName, testType_t testType)
{
	IAAFFile *					pFile = NULL;
	IAAFHeader *				pHeader = NULL;
	IAAFDictionary*					pDictionary = NULL;
	IEnumAAFMobs*				pMobIter = NULL;
	IAAFMob*					pMob = NULL;
	IAAFMasterMob*				pMasterMob = NULL;
	IAAFEssenceAccess*			pEssenceAccess = NULL;
	IAAFEssenceFormat*			pFormat = NULL;

	aafNumSlots_t				numMobs, numSlots;
	aafSearchCrit_t				criteria;
	aafRational_t				readSampleRate;
	aafUID_t					mobID;
	aafWChar					namebuf[1204];
	unsigned char				AAFDataBuf[4096];
	aafUInt32					AAFBytesRead, samplesRead;
	FILE*						pWavFile = NULL;
	unsigned char				WAVDataBuf[4096], *dataPtr;
	size_t						WAVBytesRead;
	aafUInt32					dataOffset, dataLen;
	aafUInt16					bitsPerSample, numCh;

	check(CoCreateInstance(CLSID_AAFFile,
               NULL, 
               CLSCTX_INPROC_SERVER, 
               IID_IAAFFile, 
                (void **)&pFile));
	check(pFile->Initialize());
	check(pFile->OpenExistingRead(pFileName, 0));
	check(pFile->GetHeader(&pHeader));

	// Get the AAF Dictionary so that we can create valid AAF objects.
	check(pHeader->GetDictionary(&pDictionary));


	// Here we check on the number of mobs in the file. 
	// Get the number of master mobs in the file (should be one)
	check(pHeader->GetNumMobs(kMasterMob, &numMobs));
	if (1 == numMobs )
	{
		printf("Found %ld Master Mobs\n", numMobs);
		criteria.searchTag = kByMobKind;
		criteria.tags.mobKind = kMasterMob;
		check(pHeader->EnumAAFAllMobs(&criteria, &pMobIter));
		while(AAFRESULT_SUCCESS == pMobIter->NextOne(&pMob))
		{
			char mobIDstr[256];
			char mobName[256];


			check(pMob->GetMobID (&mobID));
			check(pMob->GetName (namebuf, sizeof(namebuf)));
			convert(mobName, sizeof(mobName), namebuf);
			AUIDtoString(&mobID, mobIDstr);
			printf("    MasterMob Name = '%s'\n", mobName);
			printf("        (mobID %s)\n", mobIDstr);
			// Make sure we have one slot 
			check(pMob->GetNumSlots(&numSlots));
			if (1 == numSlots)
			{
				// The essence data is in SlotID 1
				// Get a Master Mob interface
				check(pMob->QueryInterface(IID_IAAFMasterMob, (void **)&pMasterMob));

				// Open the Essence Data
					check(pMasterMob->OpenEssence(	1,						// SlotID 1
											NULL,				// mediaCriteria (Don't care)
											kMediaOpenReadOnly,	// Open mode
											kSDKCompressionDisable,// Compress disabled
											&pEssenceAccess));

				// Open and read the Wave file (for comparison)
				pWavFile = fopen("Laser.wav", "r");
				if (pWavFile)
				{
					// read in the essence data
					WAVBytesRead = fread(WAVDataBuf, sizeof(unsigned char), sizeof(WAVDataBuf), pWavFile);
					fclose(pWavFile);
					check(loadWAVEHeader(WAVDataBuf,
										&bitsPerSample,
										&numCh,
										&readSampleRate,
										&dataOffset,
										&dataLen));
					if(testType != testRawCalls)
					{
						dataPtr = WAVDataBuf + dataOffset;
					}
					else
					{	
						dataPtr = WAVDataBuf;
						dataLen = WAVBytesRead;
					}

					aafUInt32			sampleBits;
					aafInt32			bytesRead;
					IAAFEssenceFormat	*fmtTemplate;
					
					check(pEssenceAccess->GetEmptyFileFormat (&fmtTemplate));
					check(fmtTemplate->AddFormatSpecifier (kAAFAudioSampleBits, 0, NULL));
					check(pEssenceAccess->GetFileFormat (fmtTemplate, &pFormat));
					check(pFormat->GetFormatSpecifier (kAAFAudioSampleBits, sizeof(sampleBits),
                           (aafDataBuffer_t)&sampleBits, &bytesRead));
					if(sampleBits != bitsPerSample)
					{
						printf("***Wrong sample size read ( was %ld , should be %ld)\n",
							sampleBits, bitsPerSample);
					}

					// Read the Raw Data from the AAF file
					if(testType == testRawCalls)
					{
						check(pEssenceAccess->ReadRawData(	dataLen,		// Number of Samples 
														sizeof(AAFDataBuf),	// Maximum buffer size
														AAFDataBuf,			// Buffer for the data
														&AAFBytesRead,	// Actual number of bytes read
														&samplesRead));		// Actual number of samples read
					}
					else if(testType == testStandardCalls)
					{
						check(pEssenceAccess->ReadSamples(	dataLen,	//!!! Hardcoded	// Number of Samples 
														sizeof(AAFDataBuf),	// Maximum buffer size
														AAFDataBuf,			// Buffer for the data
														&samplesRead,		// Actual number of samples read
														&AAFBytesRead));	// Actual number of bytes read
					}
					else if(testType == testFractionalCalls)
					{
						check(pEssenceAccess->ReadFractionalSample(dataLen,	// bytes to read
														sizeof(AAFDataBuf),	// Maximum buffer size
														AAFDataBuf,			// Buffer for the data
														&AAFBytesRead));	// Actual number of bytes read
					}
					else if(testType == testMultiCalls)
					{
						aafmMultiXfer_t xfer;

						xfer.numSamples = dataLen;	//!!! Hardcoded	// Number of Samples 
						xfer.buflen = sizeof(AAFDataBuf);
						xfer.buffer = AAFDataBuf;
						xfer.bytesXfered = 0;
						check(pEssenceAccess->ReadMultiSamples(1, &xfer));
						samplesRead = xfer.samplesXfered;
						AAFBytesRead = xfer.bytesXfered;
					}

					// Now compare the data read from the AAF file to the actual WAV file
					if (dataLen != AAFBytesRead)
					{
						printf("***Wrong number of bytes read ( was %ld , should be %ld)\n",
							AAFBytesRead, WAVBytesRead);
					}
					if (memcmp( dataPtr, AAFDataBuf, dataLen) != 0)
					{
						printf("*** Data Read is different than the data in the WAV file ***\n");
					}
				}
				else
				{
					printf("***Failed to open Wave file Laser.wav for comparison\n");
				}
			}
			else
			{
				printf("***Wrong number of slots in the Master Mob (was %ld should be %ld)\n",
					numSlots, 1L);
			}
			if (pEssenceAccess)
			{
				pEssenceAccess->Release();
				pEssenceAccess = NULL;
			}
			if (pMasterMob)
			{
				pMasterMob->Release();
				pMasterMob = NULL;
			}

			pMob->Release();
			pMob = NULL;
		}

		pMobIter->Release();
		pMobIter = NULL;
	}
	else
	{
		printf("***Wrong number of Master mobs in the file (was %ld should be %ld)\n",
			numMobs, 1L);
	}

	printf("--------\n");

cleanup:
	// Cleanup and return


	if (pDictionary)
		pDictionary->Release();

	if (pHeader)
		pHeader->Release();

	if (pFile) 
	{
		pFile->Close();
		pFile->Release();
	}

	return moduleErrorTmp;
}


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


//**********************
// Extra code required to scan the original WAVE headers and extract metadata parameters & data offset
AAFByteOrder GetNativeByteOrder(void)
{
  aafInt16 word = 0x1234;
  aafInt8  byte = *((aafInt8*)&word);
  AAFByteOrder result;

//  ASSERT("Valid byte order", ((byte == 0x12) || (byte == 0x34)));

  if (byte == 0x12) {
    result = MOTOROLA_ORDER;
  } else {
    result = INTEL_ORDER;
  }
  return result;
}

void AAFByteSwap32(
			aafInt32 *lp)	/* IN/OUT -- Byte swap this value */
{
	register unsigned char *cp = (unsigned char *) lp;
	int             t;

	t = cp[3];
	cp[3] = cp[0];
	cp[0] = t;
	t = cp[2];
	cp[2] = cp[1];
	cp[1] = t;
}

void AAFByteSwap16(
			aafInt16 * wp)	/* IN/OUT -- Byte swap this value */
{
	register unsigned char *cp = (unsigned char *) wp;
	int             t;

	t = cp[1];
	cp[1] = cp[0];
	cp[0] = t;
}

// app work on all WAVE files, not just laser.wav.
void scanSwappedWAVEData(aafUInt8 **srcBufHdl, aafInt32 maxsize, void *data)
{
	AAFByteOrder	nativeByteOrder = GetNativeByteOrder()
		;
	memcpy(data, *srcBufHdl, maxsize);
	(*srcBufHdl) += maxsize;
	
	if ((maxsize == sizeof(aafInt32)) && (INTEL_ORDER != nativeByteOrder))
			AAFByteSwap32((aafInt32 *) data);
	else if ((maxsize == sizeof(aafInt16)) && (INTEL_ORDER != nativeByteOrder))
			AAFByteSwap16((aafInt16 *) data);
}

AAFRESULT loadWAVEHeader(aafUInt8 *buf,
										aafUInt16 *bitsPerSample,
										aafUInt16 *numCh,
										aafRational_t *sampleRate,
										aafUInt32 *dataOffset,
										aafUInt32 *dataLen)
{
	aafInt32			formSize;
	aafInt16			pcm_format, junk16;
	aafUInt32			chunkSize;
	aafBool				fmtFound = AAFFalse, dataFound = AAFFalse;
	aafUInt8			chunkID[4];
 	aafInt32			junk32, rate, bytesPerFrame;
	aafUInt8			*ptr;

	ptr = buf;
	scanSwappedWAVEData(&ptr, sizeof(chunkID), &chunkID);	
	if (memcmp(&chunkID, "RIFF", (size_t) 4) != 0)
		return(AAFRESULT_BADWAVEDATA);
	scanSwappedWAVEData(&ptr, sizeof(formSize), &formSize);	
	scanSwappedWAVEData(&ptr, sizeof(chunkID), &chunkID);	
	if (memcmp(&chunkID, "WAVE", (size_t) 4) != 0)
		return(AAFRESULT_BADWAVEDATA);
	
	scanSwappedWAVEData(&ptr, sizeof(chunkID), &chunkID);	
	while ((ptr-buf) < formSize)
	{
		scanSwappedWAVEData(&ptr, sizeof(chunkSize), &chunkSize);	

		if (memcmp(&chunkID, "fmt ", (size_t) 4) == 0)
		{
			// WAVE field: wFormatTag
			scanSwappedWAVEData(&ptr, sizeof(aafUInt16), (aafUInt8 *)&pcm_format);
			if (pcm_format != 1)
				return(AAFRESULT_BADWAVEDATA);
	
			// WAVE field: wChannels
			scanSwappedWAVEData(&ptr, sizeof(aafUInt16), (aafUInt8 *)numCh);
	
			// WAVE field: wSamplesPerSec
			scanSwappedWAVEData(&ptr, sizeof(aafUInt32), (aafUInt8 *)&rate);
			sampleRate->numerator = rate;
			sampleRate->denominator = 1;
	
			// Skip WAVE field: avgBytesPerSec (4 bytes)
			scanSwappedWAVEData(&ptr, sizeof(junk32), (aafUInt8 *)&junk32);

			// WAVE field wBlockAlign
			scanSwappedWAVEData(&ptr, sizeof(aafUInt16), (aafUInt8 *)&junk16);
	
			// WAVE field Sample Width
			scanSwappedWAVEData(&ptr, sizeof(aafUInt16), (aafUInt8 *)bitsPerSample);
			bytesPerFrame = (((*bitsPerSample) + 7) / 8) * (*numCh);
			fmtFound = AAFTrue;
		} else if (memcmp(&chunkID, "data", (size_t) 4) == 0)
		{
			*dataLen = chunkSize / bytesPerFrame;
			// Positioned at beginning of audio data
			*dataOffset = ptr - buf;
	
			dataFound = AAFTrue;
		}
	
		if((ptr-buf) > formSize)
			break;
		if (fmtFound && dataFound)	// Do we have all information yet?
			break;
		scanSwappedWAVEData(&ptr, sizeof(chunkID), &chunkID);	
	}	
	
	return(AAFRESULT_SUCCESS);
}


main()
{
	CComInitialize comInit;
	aafWChar *		pwFileName = L"EssenceTest.aaf";
	const char *	pFileName = "EssenceTest.aaf";
	aafWChar *	rawData = L"EssenceTestRar.wav";
	testDataFile_t	dataFile;

	printf("***Creating file %s using writeRawData (Internal Media)\n", pFileName);
	checkFatal(CreateAAFFile(pwFileName, NULL, testRawCalls));
	printf("***Re-opening file %s using readRawData\n", pFileName);
	ReadAAFFile(pwFileName, testRawCalls);
	printf("***Creating file %s using WriteSamples (Internal Media)\n", pFileName);
	checkFatal(CreateAAFFile(pwFileName, NULL, testStandardCalls));
	printf("***Re-opening file %s using ReadSamples\n", pFileName);
	ReadAAFFile(pwFileName, testStandardCalls);
	printf("***Creating file %s using WriteMultiSamples (Internal Media)\n", pFileName);
	checkFatal(CreateAAFFile(pwFileName, NULL, testMultiCalls));
	printf("***Re-opening file %s using ReadMultiSamples\n", pFileName);
	ReadAAFFile(pwFileName, testMultiCalls);
	printf("***Creating file %s using WriteFractionalSample (Internal Media)\n", pFileName);
	checkFatal(CreateAAFFile(pwFileName, NULL, testFractionalCalls));
	printf("***Re-opening file %s using ReadFractionalSample\n", pFileName);
	ReadAAFFile(pwFileName, testFractionalCalls);
	dataFile.dataFilename = rawData;
	dataFile.dataFormat = ContainerFile;
	printf("***Creating file %s using WriteSamples (External Raw Media)\n", pFileName);
	checkFatal(CreateAAFFile(pwFileName, &dataFile, testStandardCalls));
	printf("***Re-opening file %s using ReadSamples\n", pFileName);
	ReadAAFFile(pwFileName, testStandardCalls);


	printf("Done\n");


	return(0);
}




