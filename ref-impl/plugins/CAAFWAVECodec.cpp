/******************************************\
*                                          *
* Advanced Authoring Format                *
*                                          *
* Copyright (c) 1998 Avid Technology, Inc. *
* Copyright (c) 1998 Microsoft Corporation *
*                                          *
\******************************************/

#include "CAAFWAVECodec.h"

#include <assert.h>
#include "AAFResult.h"

#include "AAF.h"

//#include "CAAFEssenceFormat.h"
//#include "ImplAAFEssenceFormat.h"
#include "aafErr.h"
#include "aafUtils.h"
#include "aafCvt.h"
#include "aafDefUIDs.h"

#define STD_HDRSIZE_DATA		42
#define STD_HDRSIZE_NODATA		36

const aafProductVersion_t AAFPluginImplementationVersion = {1, 0, 0, 1, kVersionBeta};

// CLSID for AAFEssenceCodec 
//{8D7B04B1-95E1-11d2-8089-006008143E6F}
const CLSID CLSID_AAFWaveCodec = { 0x8D7B04B1, 0x95E1, 0x11d2, { 0x80, 0x89, 0x00, 0x60, 0x08, 0x14, 0x3e, 0x6f } };

const IID IID_IAAFSourceMob = { 0xB1A2137C, 0x1A7D, 0x11D2, { 0xBF, 0x78, 0x00, 0x10, 0x4B, 0xC9, 0x15, 0x6D } };
const IID IID_IAAFWAVEDescriptor = { 0x4c2e1692, 0x8ae6, 0x11d2, { 0x81, 0x3c, 0x00, 0x60, 0x97, 0x31, 0x01, 0x72 } };
const IID IID_IAAFFileDescriptor = { 0xe58a8561, 0x2a3e, 0x11D2, { 0xbf, 0xa4, 0x00, 0x60, 0x97, 0x11, 0x62, 0x12 } };

HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::Start (void)
{
	return AAFRESULT_SUCCESS;
}

HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::Finish (void)
{
	return AAFRESULT_SUCCESS;
}

static void SplitBuffers(void *original, aafInt32 srcSamples, aafInt16 sampleSize, aafInt16 numDest, interleaveBuf_t *destPtr);

CAAFWaveCodec::CAAFWaveCodec (IUnknown * pControllingUnknown, aafBool doInit)
  : CAAFUnknown (pControllingUnknown)
{
	_headerLoaded = AAFFalse;
	_nativeByteOrder = GetNativeByteOrder();
	_sampleRate.numerator = 44100;
	_sampleRate.denominator = 1;
	_bitsPerSample = 8;
	_numCh = 0;
	_bytesPerFrame = 1;
	_sampleFrames = 0;
	_interleaveBuf = NULL;
	_dataStartOffset = 0;
	_dataSizeOffset = 0;
	_readOnly = AAFFalse;
	_stream = NULL;
	_sampleDataHeaderWritten = AAFFalse;
	_initialSeekPerformed = AAFFalse;
}


CAAFWaveCodec::~CAAFWaveCodec ()
{
}




HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::GetIndexedVariantID (aafInt32  index,
        aafUID_t *  pVariant)
{
  return HRESULT_NOT_IMPLEMENTED;
}


	
HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::SetCompression (aafCompressEnable_t  enable)
{
  return HRESULT_SUCCESS;
}


HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::GetIndexedDataDefinition (aafInt32  index,
        aafUID_t *  pVariant)
{
  return HRESULT_NOT_IMPLEMENTED;
}

//!!!Need a way to convert between CLSID and aafUID_t
const aafUID_t LOCAL_AAFWAVEDescriptor = { 0x4c2e1691, 0x8ae6, 0x11d2, { 0x81, 0x3c, 0x00, 0x60, 0x97, 0x31, 0x01, 0x72 } };
const aafUID_t LOCAL_AAFEssenceData = { 0x6a33f4e1, 0x8ed6, 0x11d2, { 0xbf, 0x9d, 0x00, 0x10, 0x4b, 0xc9, 0x15, 0x6d } };

HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::GetMetaInfo (aafCodecMetaInfo_t *  pInfo)
{
	pInfo->mdesClassID = LOCAL_AAFWAVEDescriptor;
    pInfo->dataClassID = LOCAL_AAFEssenceData;		//!!!Isn't this a subclas still?
//!!!	aafUID_t    			pInfo->plugin.pluginID;					/* OUT */
	pInfo->plugin.pluginInterfaceRevision = kPluginRev1;	/* IN/OUT */
	pInfo->plugin.pluginCodeRevision = AAFPluginImplementationVersion;
	pInfo->plugin.minimumFileRevision = kAAFRev1;		/* OUT - (revs lower than this will be private */
	pInfo->plugin.validMaximumFileRevision = AAFFalse;	/* OUT - Is there a maximum rev? */
//	pInfo->plugin.maximumFileRevision;		/* OUT - (revs higher than this will be private */
	pInfo->plugin.minimumSDKRevision = AAFPluginImplementationVersion;
    pInfo->numVariants = 0;
    pInfo->numDataDefinitions = 1;

	return AAFRESULT_SUCCESS;
}

HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::GetCodecDisplayName (aafUID_t  variant,
        wchar_t *  pName,
        aafInt32  bufSize)
{
	wchar_t	name[] = L"WAVE Codec";
	aafInt32	len = sizeof(name);
	if(len > bufSize)
		len = bufSize;
	memcpy(pName, "WAVE Codec", len);
	return AAFRESULT_SUCCESS;
}


HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::GetSelectInfo (IUnknown *fileMob,
        aafCodecSelectInfo_t *  pInfo)
{
	XPROTECT()
	{
	    if(!_headerLoaded)
		{
			CHECK(loadWAVEHeader());
		}
		pInfo->willHandleMDES = AAFTrue;
		pInfo->isNative = (_nativeByteOrder == INTEL_ORDER ? AAFTrue : AAFFalse);
		pInfo->hwAssisted = AAFFalse;
        pInfo->relativeLoss = 0;
        pInfo->avgBitsPerSec = (_bitsPerSample * _sampleRate.numerator) / _sampleRate.denominator;
    }
    XEXCEPT
    XEND

	return(AAFRESULT_SUCCESS);
}

	

	
HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::GetNumChannels (IUnknown *fileMob,
        aafUID_t  essenceKind,
        IAAFEssenceStream *stream,
        aafInt16 *  pNumChannels)
{
	XPROTECT()
	{
		if(EqualAUID(&essenceKind, &DDEF_Audio))
		{
			if(!_headerLoaded)
			{
				_stream = stream;
				CHECK(loadWAVEHeader());
			}
			*pNumChannels = _numCh;
		}
		else
			*pNumChannels = 0;
    }
    XEXCEPT
    XEND;
	
	return AAFRESULT_SUCCESS;
}


HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::SemanticCheck (IUnknown *fileMob,
        aafCheckVerbose_t  verbose,
        aafCheckWarnings_t *  warning,
        wchar_t *  pName,
        aafInt32  bufSize)
{
#if FULL_TOOLKIT
	omfHdl_t			file;
	omfCodecStream_t	streamData;
	omfType_t			dataType = (parmblk->fileRev == kOmfRev2x ? OMDataValue : OMVarLenBytes);
	omfDDefObj_t		dataKind;
	aafInt16			mdesNumCh, dataNumCh;
	omfObject_t			mdes, dataObj;
	userDataWAVE_t		mdesPD, dataPD;
	AAFRESULT			status;
	aafBool				getWarnings;
	
#ifdef OMFI_ENABLE_STREAM_CACHE
	streamData.cachePtr = NULL;
#endif
	streamData.procData = NULL;

	mdes = parmblk->spc.semCheck.mdes;
	dataObj = parmblk->spc.semCheck.dataObj;
	
	/* There is nothing to semantic check if just a media descriptor is poresent
	 */
	if(dataObj == NULL)
		return(OM_ERR_NONE);
		
	file = parmblk->spc.semCheck.file;
	parmblk->spc.semCheck.message = NULL;
	getWarnings = (parmblk->spc.semCheck.warn == kCheckPrintWarnings);
	XPROTECT(file)
	{
		omfiDatakindLookup(file, SOUNDKIND, &dataKind, &status);
		CHECK(status);
		/* First read the metadata out of the MDES Summary */
		CHECK(omcOpenStream(file, file, &streamData, mdes,
							OMWAVDSummary, dataType));
		CHECK(setupStream(&streamData, dataKind, &mdesPD));
		CHECK(loadWAVEHeader(file, &streamData, dataKind, &mdesPD,
							NULL, &mdesNumCh, NULL, NULL));
		CHECK(omcCloseStream(&streamData));
		/* Next read the metadata out of the dataObject */
		CHECK(omcOpenStream(file, file, &streamData, dataObj,
							OMWAVEData, dataType));
		CHECK(setupStream(&streamData, dataKind, &dataPD));
		CHECK(loadWAVEHeader(file, &streamData, dataKind, &dataPD,
							NULL, &dataNumCh, NULL, NULL));
		CHECK(omcCloseStream(&streamData));
		/* Finally, make sure that the data agrees */
		if(mdesNumCh != dataNumCh)
		{
			parmblk->spc.semCheck.message = "Number of channels";
			RAISE(OM_ERR_DATA_MDES_DISAGREE);
		}
		if(mdesPD.fileBitsPerSample != dataPD.fileBitsPerSample)
		{
			parmblk->spc.semCheck.message = "Bits Per Sample";
			RAISE(OM_ERR_DATA_MDES_DISAGREE);
		}
		if((mdesPD.fileRate.numerator != dataPD.fileRate.numerator) ||
		   (mdesPD.fileRate.denominator != dataPD.fileRate.denominator))
		{
			parmblk->spc.semCheck.message = "Frame Rate";
			RAISE(OM_ERR_DATA_MDES_DISAGREE);
		}
	}
	XEXCEPT
	XEND
	
	return(OM_ERR_NONE);
#else
	return HRESULT_NOT_IMPLEMENTED;
#endif
}

		
HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::Create (IUnknown *unk,
        aafUID_t  variant,
        IAAFEssenceStream * stream,
        aafInt32 numParms,
        aafmMultiCreate_t *createParms)
{
	IAAFSourceMob			*fileMob;
	IAAFEssenceDescriptor	*mdes;
	IAAFFileDescriptor		*fileDesc;
	AAFRESULT				aafError;
	unsigned char			header[STD_HDRSIZE_NODATA];

	_stream = stream;
	_readOnly = AAFFalse;
	XPROTECT()
	{
		_sampleRate = createParms[0].sampleRate;	// !!!Assumes all sample rates are the same

		aafError = (unk->QueryInterface(IID_IAAFSourceMob, (void **)&fileMob));
		CHECK(fileMob->GetEssenceDescriptor(&mdes));
		aafError = (mdes->QueryInterface(IID_IAAFWAVEDescriptor, (void **)&_mdes));
		CHECK(CreateWAVEheader(header, STD_HDRSIZE_NODATA, (aafInt16)numParms));
		CHECK(_mdes->SetSummary (STD_HDRSIZE_NODATA, header));
		aafError = (mdes->QueryInterface(IID_IAAFFileDescriptor, (void **)&fileDesc));


//!!!		omfsCvtInt32toInt64(0, &pdata->formSizeOffset);
//		omfsCvtInt32toInt64(0, &pdata->numSamplesOffset);

	}
	XEXCEPT
	XEND;

	return AAFRESULT_SUCCESS;
}


HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::Open (IUnknown *unk,
        aafMediaOpenMode_t  openMode,
        IAAFEssenceStream * stream)
{
	AAFRESULT		aafError;
	IAAFSourceMob	*fileMob;
	IAAFEssenceDescriptor *edes;

	_stream = stream;
	_readOnly = openMode == kMediaOpenReadOnly ? AAFTrue : AAFFalse;
	XPROTECT()
	{
		aafError = (unk->QueryInterface(IID_IAAFSourceMob, (void **)&fileMob));
		CHECK(fileMob->GetEssenceDescriptor(&edes));
		aafError = (edes->QueryInterface(IID_IAAFWAVEDescriptor, (void **)&_mdes));

		if(!_headerLoaded)
		{
			CHECK(loadWAVEHeader());
		}
	}
	XEXCEPT
	XEND;
	return AAFRESULT_SUCCESS;
}


HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::WriteBlocks (aafDeinterleave_t  inter,
        aafInt16  xferBlockCount,
        aafmMultiXfer_t *  xferBlock)
{
	aafUInt32      	fileBytes;
	aafInt32      	bytesPerSample, n, xfers, samp;
	aafUInt32		maxSamplesLeft;
	aafmMultiXfer_t *xfer;
	interleaveBuf_t	*interPtr;
	aafUInt8		*destPtr;
	aafUInt32		zero = 0;
	aafUInt8		sampleBuf[256];
	unsigned char	header[STD_HDRSIZE_NODATA];

	XPROTECT()
	{
		XASSERT(_bitsPerSample != 0, OM_ERR_ZERO_SAMPLESIZE);

		if(!_sampleDataHeaderWritten)
		{
			CHECK(CreateWAVEheader(header, STD_HDRSIZE_NODATA, _numCh));

			_sampleDataHeaderWritten = AAFTrue;
			// The next four lines won't work for raw writes
			_stream->Write(header, STD_HDRSIZE_NODATA);
			_stream->Write((aafUInt8 *)"data", 4);
			_stream->GetPosition(&_dataSizeOffset);
			_stream->Write((aafUInt8 *)&zero, 4);		
		}

		bytesPerSample = ((_bitsPerSample + 7)/ 8);
		for (n = 0; n < xferBlockCount; n++)
		{
			xferBlock[n].bytesXfered = 0;
			xferBlock[n].samplesXfered = 0;
		}
		
		if(inter == leaveInterleaved)
		{
			for (n = 0; n < xferBlockCount; n++)
			{
				xfer = xferBlock + n;
		
				fileBytes = xfer->numSamples * bytesPerSample * _numCh;
				if (fileBytes > xfer->buflen)
					RAISE(AAFRESULT_SMALLBUF);
				
				CHECK(_stream->Write(xfer->buffer, fileBytes));
				
				xfer->bytesXfered = xfer->numSamples * bytesPerSample;
				xfer->samplesXfered += xfer->numSamples / bytesPerSample;
			}
		}
		else if(_numCh == 1)
		{
			for (n = 0; n < xferBlockCount; n++)
			{
				xfer = xferBlock + n;
		
				fileBytes = xfer->numSamples * bytesPerSample;
				if (fileBytes > xfer->buflen)
					RAISE(OM_ERR_SMALLBUF);
				
				CHECK(_stream->Write(xfer->buffer, fileBytes));
		
		
				xfer->bytesXfered = xfer->numSamples * bytesPerSample;
				xfer->samplesXfered += xfer->numSamples / bytesPerSample;
			}
		}
		else
		{
			if(_interleaveBuf == NULL)
				_interleaveBuf = new interleaveBuf_t[_numCh];
			if(_interleaveBuf == NULL)
				RAISE(AAFRESULT_NOMEMORY);
			bytesPerSample = ((_bitsPerSample+ 7) / 8);
			for (n = 0; n < _numCh; n++)
				_interleaveBuf[n].buf = NULL;
			
			maxSamplesLeft = 0;
			for (n = 0; n < xferBlockCount; n++)
			{
				xfer = xferBlock + n;
				xfer->bytesXfered = xfer->numSamples * bytesPerSample;
				xfer->samplesXfered = xfer->numSamples;
				
				XASSERT((xfer->subTrackNum >= 1) && xfer->subTrackNum <= _numCh, AAFRESULT_CODEC_CHANNELS);
				interPtr = _interleaveBuf + (xfer->subTrackNum-1);
				XASSERT(interPtr->buf == NULL, AAFRESULT_XFER_DUPCH);
				interPtr->buf = xfer->buffer;
				interPtr->samplesLeft = xfer->numSamples;
				interPtr->buflen = xfer->buflen;
				interPtr->bytesXfered = 0;
				if(maxSamplesLeft == 0)
					maxSamplesLeft = xfer->numSamples;
				else if(xfer->numSamples != maxSamplesLeft)
					RAISE(AAFRESULT_MULTI_WRITELEN);
			}
			
			while(maxSamplesLeft > 0)
			{
				xfers = sizeof(sampleBuf) / (bytesPerSample * xferBlockCount);
				if((aafUInt32) xfers > maxSamplesLeft)
					xfers = (aafInt32) maxSamplesLeft;
					
				destPtr = sampleBuf;
				for (samp = 0; samp < xfers; samp++)
				{
					for (n = 0; n < xferBlockCount; n++)
					{
						interPtr = _interleaveBuf+n;
						memcpy(destPtr, interPtr->buf, bytesPerSample);
						interPtr->buf = (char *)interPtr->buf + bytesPerSample;
						destPtr += bytesPerSample;
						interPtr->samplesLeft--;
						interPtr->bytesXfered += bytesPerSample;
					}
					maxSamplesLeft--;
				}
				
				fileBytes = xfers * bytesPerSample * xferBlockCount;
				CHECK(_stream->Write(sampleBuf, fileBytes));
			}
		}
	}
	XEXCEPT
	XEND
	
	return (OM_ERR_NONE);
}


HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::ReadBlocks (aafDeinterleave_t  inter,
        aafInt16  xferBlockCount,
        aafmMultiXfer_t *  xferBlock)
{
	aafUInt32       nbytes, fileBytes;
	aafInt32        bytesPerSample, n, startBuflen, xferSamples, sub;
	aafUInt32		maxSamplesLeft;
	aafUInt8		*start;
	aafmMultiXfer_t *xfer;
	aafInt16		ch, xf;
	aafUInt8		tmpBuf[256];
	

	XPROTECT()
	{
		if(!_initialSeekPerformed)
		{
			CHECK(_stream->Seek(_dataStartOffset));	// Not compatible with raw read
			_initialSeekPerformed = AAFTrue;
		}

		XASSERT(_bitsPerSample != 0, OM_ERR_ZERO_SAMPLESIZE);
		
		for (n = 0; n < xferBlockCount; n++)
		{
			xferBlock[n].bytesXfered = 0;
		}
		
		if(inter == leaveInterleaved)
		{
			bytesPerSample = ((_bitsPerSample + 7) / 8);
			for (n = 0; n < xferBlockCount; n++)
			{
				xfer = xferBlock + n;
				xfer->samplesXfered = 0;
		
				fileBytes = xfer->numSamples * bytesPerSample * _numCh;
				if (fileBytes > xfer->buflen)
					RAISE(AAFRESULT_SMALLBUF);
		
				CHECK(_stream->Read(fileBytes, xfer->buffer, &nbytes));
				xfer->bytesXfered = nbytes;
				xfer->samplesXfered = nbytes / (bytesPerSample * _numCh);
			}
		}
		else if(_numCh == 1)
		{
			bytesPerSample = ((_bitsPerSample + 7) / 8);
			for (n = 0; n < xferBlockCount; n++)
			{
				xfer = xferBlock + n;
				xfer->samplesXfered = 0;
		
				fileBytes = xfer->numSamples * bytesPerSample;
				if (fileBytes > xfer->buflen)
					RAISE(OM_ERR_SMALLBUF);
		
				CHECK(_stream->Read(fileBytes, xfer->buffer, &nbytes));
				xfer->bytesXfered = nbytes;
				xfer->samplesXfered = nbytes / bytesPerSample;
			}
		}
		else
		{
			if(_interleaveBuf == NULL)
				_interleaveBuf = new interleaveBuf_t[_numCh];
			if(_interleaveBuf == NULL)
				RAISE(AAFRESULT_NOMEMORY);
			bytesPerSample = ((_bitsPerSample + 7) / 8);
			for (n = 0; n < _numCh; n++)
			{
				_interleaveBuf[n].buf = NULL;
				_interleaveBuf[n].xfer = NULL;
			}
			
			maxSamplesLeft = 0;
			for (n = 0; n < xferBlockCount; n++)
			{
				xfer = xferBlock + n;
				xfer->samplesXfered = 0;
				
				if((xfer->subTrackNum <= 0) || (xfer->subTrackNum > _numCh))
					RAISE(AAFRESULT_CODEC_CHANNELS);

 				sub = xfer->subTrackNum-1;
 				if(_interleaveBuf[sub].buf != NULL)
					RAISE(AAFRESULT_XFER_DUPCH);

				_interleaveBuf[sub].buf = xfer->buffer;
				_interleaveBuf[sub].samplesLeft = xfer->numSamples;
				_interleaveBuf[sub].buflen = xfer->buflen;
				_interleaveBuf[sub].bytesXfered = 0;
				_interleaveBuf[sub].xfer = xfer;
				if(xfer->numSamples > maxSamplesLeft)
					maxSamplesLeft = xfer->numSamples;
			}
					
			for (n = 0, start = NULL; (n < _numCh) && (start == NULL); n++)
			{
				if(_interleaveBuf[n].buf != NULL)
				{
					start = (aafUInt8 *)_interleaveBuf[n].buf;
					startBuflen = _interleaveBuf[n].buflen;
				}
			}
			if(start == NULL)
				RAISE(AAFRESULT_BADDATAADDRESS);
			
			while(maxSamplesLeft > 0)
			{
				if(maxSamplesLeft * bytesPerSample  * _numCh >= sizeof(tmpBuf))
					xferSamples = maxSamplesLeft/ _numCh;
				else
				{
					xferSamples = maxSamplesLeft;
					start = tmpBuf;
				}
				fileBytes = xferSamples * bytesPerSample * _numCh;
				if ((aafInt32)fileBytes > startBuflen)
					RAISE(OM_ERR_SMALLBUF);
		
				CHECK(_stream->Read(fileBytes, start, &nbytes));
				
				SplitBuffers(start, xferSamples * _numCh, _bitsPerSample, 
							_numCh, _interleaveBuf);
				start += fileBytes / _numCh;
				maxSamplesLeft -= xferSamples;

				for (ch = 0; ch < _numCh; ch++)
				{
					xfer = _interleaveBuf[ch].xfer;
 					if(xfer != NULL)
					{
						xfer->bytesXfered = _interleaveBuf[ch].bytesXfered;
						xfer->samplesXfered = xfer->bytesXfered / bytesPerSample;
					}
				}
			}
		}
	}
	XEXCEPT
	{
		if((XCODE() == AAFRESULT_EOF) || (XCODE() == AAFRESULT_END_OF_DATA))
		{
			for (xf = 0; xf < xferBlockCount; xf++)
			{
				xfer = xferBlock + xf;
				xfer->bytesXfered = nbytes;
				xfer->samplesXfered = nbytes / (bytesPerSample * _numCh);
			}
		}
	}
	XEND

	return (AAFRESULT_SUCCESS);
}


HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::Seek (aafPosition_t  sampleFrame)
{
	aafInt64          nBytes;
	aafInt64          temp, offset, one;
	aafInt32           bytesPerFrame;

	XPROTECT()
	{
		CvtInt32toInt64(1, &one);
		temp = _sampleFrames;
		CHECK(AddInt32toInt64(1, &temp));
		if (Int64Greater(sampleFrame, temp))
			RAISE(AAFRESULT_BADSAMPLEOFFSET);
	
		nBytes = sampleFrame;
		
		/* Make the result zero-based (& check for bad frame numbers as well). */
		if(Int64Less(nBytes, one))
			RAISE(AAFRESULT_BADSAMPLEOFFSET);
		CHECK(SubInt64fromInt64(one, &nBytes));
		bytesPerFrame = ((_bitsPerSample + 7) / 8) * _numCh;
		CHECK(MultInt32byInt64(bytesPerFrame, nBytes, &nBytes));
		offset = _dataStartOffset;
		CHECK(AddInt64toInt64(nBytes, &offset));
	
		CHECK(_stream->Seek(offset));
	}
	XEXCEPT
	XEND

	return (OM_ERR_NONE);
}


HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::CompleteWrite ()
{
	aafInt64	byteLen, sampleLen;
	aafErr_t	aafError;
	IAAFFileDescriptor *fileDesc;

	XPROTECT()
	{
		CHECK(_stream->GetLength (&byteLen));
		sampleLen = byteLen / _bytesPerFrame;
		aafError = (_mdes->QueryInterface(IID_IAAFFileDescriptor, (void **)&fileDesc));
		CHECK(fileDesc->SetLength(sampleLen));

		if(!_readOnly && _sampleDataHeaderWritten)
			CHECK(CreateAudioDataEnd());	// Don't do this for raw calls?
		_stream = NULL;
		
		if(_interleaveBuf != NULL)
			delete _interleaveBuf;
	}
	XEXCEPT
	XEND;

	return HRESULT_SUCCESS;
}		


HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::WriteFractionalSample (aafDataBuffer_t  buffer,
        aafInt32  buflen)
{
//!!!		if(!_sampleDataHeaderWritten)
//		{
//			_sampleDataHeaderWritten = AAFTrue;
//			// The next four lines won't work for raw writes
//			_stream->Write(header, STD_HDRSIZE_NODATA);
//			_stream->Write((aafUInt8 *)"data", 4);
//			_stream->GetPosition(&_dataSizeOffset);
//			_stream->Write(0, 4);		
//		}
  return HRESULT_NOT_IMPLEMENTED;
}




HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::ReadFractionalSample (aafUInt32  buflen,
        aafDataBuffer_t  buffer,
        aafUInt32 *  bytesRead)
{
//!!!		if(!_initialSeekPerformed)
//		{
//			CHECK(_stream->Seek(_dataStartOffset));	// Not compatible with raw read
//			_initialSeekPerformed = AAFTrue;
//		}
  return HRESULT_NOT_IMPLEMENTED;
}




HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::WriteRawData (aafUInt32 nSamples, aafDataBuffer_t  buffer,
        aafUInt32  buflen)
{
	_stream->Write (buffer, nSamples * _bytesPerFrame);
	return HRESULT_SUCCESS;
}




HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::ReadRawData (aafUInt32 nSamples,
		aafUInt32  buflen,
        aafDataBuffer_t  buffer,
        aafUInt32 *  bytesRead,
        aafUInt32 *  samplesRead)
{
	HRESULT	hr;
	
	//!!!Later Check that buflen > nSamples * SAMPLE_SIZE;
	if(!_initialSeekPerformed)
	{
		hr = _stream->Seek(0L);
		if(hr != S_OK)
			return(hr);
		_initialSeekPerformed = AAFTrue;
	}

	_stream->Read (nSamples * _bytesPerFrame, buffer, bytesRead);
	*samplesRead = (*bytesRead)/_bytesPerFrame ;
	return HRESULT_SUCCESS;
}



	
HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::CreateDescriptorFromStream (IAAFEssenceStream * pStream,
        IUnknown *fileMob)
{
#if FULL_TOOLKIT
{
	omfHdl_t				file, rawFile;
	omfCodecStream_t	readStream, writeStream;
	omfType_t			dataType = (parmblk->fileRev == kOmfRev2x ? OMDataValue : OMVarLenBytes);
	userDataWAVE_t		pdataBlock;
	aafInt16			numCh;
	omfUInt16			bytesPerFrame;
	aafInt64			sampleFrames;
	omfObject_t			mdes;
	AAFRESULT				status;
	omfDDefObj_t			dataKind;
	
	file = parmblk->spc.rawImportInfo.main;
	rawFile = parmblk->spc.rawImportInfo.rawFile;
	
	XPROTECT(file)
	{
		omfiDatakindLookup(parmblk->spc.getChannels.file, SOUNDKIND, &dataKind, &status);
		CHECK(status);

		CHECK(omcOpenStream(file, rawFile, &readStream, NULL,
							OMNoProperty, OMNoType));
		CHECK(setupStream(&readStream, dataKind, &pdataBlock)); 
		CHECK(loadWAVEHeader(parmblk->spc.getChannels.file, &readStream,
							dataKind, &pdataBlock, NULL, &numCh, &sampleFrames,
							&bytesPerFrame));
		CHECK(omcCloseStream(&readStream));
		
		if(parmblk->fileRev == kOmfRev2x)
		{
			CHECK(omfsReadObjRef(file, parmblk->spc.rawImportInfo.fileMob,
										OMSMOBMediaDescription, &mdes));
		}
		else
		{
			CHECK(omfsReadObjRef(file, parmblk->spc.rawImportInfo.fileMob,
										OMMOBJPhysicalMedia, &mdes));
		}

		CHECK(omcOpenStream(file, file, &writeStream,  mdes, OMWAVDSummary, dataType));
		CHECK(setupStream(&writeStream, dataKind, &pdataBlock)); 
		CHECK(CreateWAVEheader(file, &writeStream, &pdataBlock, numCh, FALSE));
		CHECK(omcCloseStream(&writeStream));
	}
	XEXCEPT
	XEND
	
	return(OM_ERR_NONE);
}
#else
	return HRESULT_NOT_IMPLEMENTED;
#endif
}




HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::GetCurrentEssenceStream (IAAFEssenceStream ** ppStream)
{
	*ppStream = _stream;
	return AAFRESULT_SUCCESS;
}

		
HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::PutEssenceFormat (IAAFEssenceFormat * pFormat)
{
/*!!!!	aafInt32		numSpecifiers, n, bytesRead;
	aafUID_t		opcode;
	aafUInt8		buf[256];

	XPROTECT()
	{
		CHECK(pFormat->NumFormatSpecifiers (&numSpecifiers));

		for(n = 0; n < numSpecifiers; n++)
		{
			CHECK(pFormat->GetIndexedFormatSpecifier (n, &opcode, sizeof(buf), buf, &bytesRead));

			if(EqualAUID(&kAAFSampleSize, &opcode))
				_bitsPerSample = aparms->operand.sampleSize;
			else if(EqualAUID(&kAAFSampleRate, &opcode))
				_sampleRate = aparms->operand.sampleRate;
			else if(EqualAUID(&kAAFSampleFormat, &opcode))
				RAISE(OM_ERR_INVALID_OP_CODEC);
			else if(EqualAUID(&kAAFNumChannels, &opcode))
				_numCh = aparms->operand.numChannels;
			else

				RAISE(OM_ERR_INVALID_OP_CODEC);
			}
		}
		
		if(main->fmt == kOmfiMedia)
		{
			CHECK(CreateWAVEheader(main,  media->stream, pdata, _numCh, FALSE));
		}
		
		// This should also reset the stream position?
		_stream->Seek(0);
		CHECK(CreateWAVEheader(main,  media->stream, pdata, media->numChannels, TRUE));
	}
	XEXCEPT
	XEND
*/	
	return (AAFRESULT_SUCCESS);
#if FULL_TOOLKIT
	AAFRESULT	status = OM_ERR_NONE;
	userDataWAVE_t 		*pdata;
	aafInt16			numFmtOps, n;
	omfAudioMemOp_t 	*aparms;

	switch (parmblk->spc.mediaInfo.infoType)
	{
	case kAudioInfo:
		status = codecPutAudioInfoWAVE(parmblk, media);
		break;
	case kSetAudioMemFormat:
		pdata = (userDataWAVE_t *) media->userData;
		numFmtOps = 0;
		while((pdata->fmtOps[numFmtOps].opcode != kOmfAFmtEnd) && (numFmtOps <= MAX_FMT_OPS))
			numFmtOps++;
		
		if(numFmtOps >= MAX_FMT_OPS)
			status = OM_ERR_TOO_MANY_FMT_OPS;
		else
		{
			aparms = ((omfAudioMemOp_t *)parmblk->spc.mediaInfo.buf);
			for(n = 0 ; ; aparms++, n++)
			{
				pdata->fmtOps[n] =  *((omfAudioMemOp_t *)aparms);
				if(aparms->opcode == kOmfAFmtEnd)
					break;
			}
			status = setupStream(media->stream, media->soundKind, pdata);
		}
		break;
	default:
		status = ;
		break;
	}

	return(status);
#endif
}


HRESULT STDMETHODCALLTYPE
    CAAFWaveCodec::GetEssenceFormat (IAAFEssenceFormat ** ppFormat)
{
#if FULL_TOOLKIT
	userDataWAVE_t *pdata;
	omfAudioMemOp_t *aparms;

	omfAssertMediaHdl(media);

	pdata = (userDataWAVE_t *) media->userData;
	aparms = *((omfAudioMemOp_t **)parmblk->spc.mediaInfo.buf);
	for( ; aparms->opcode != kOmfAFmtEnd; aparms++)
	  {
		switch(aparms->opcode)
		  {
		  case kOmfSampleSize:
			aparms->operand.sampleSize = _bitsPerSample;
			break;
		  case kOmfSampleRate:
			aparms->operand.sampleRate = _sampleRate;
			break;
			
		  case kOmfSampleFormat:
			aparms->operand.format = kOmfSignedMagnitude;
			break;
	
		  case kOmfNumChannels:
			aparms->operand.numChannels = media->numChannels;
			break;
		  }
	  }

	return (OM_ERR_NONE);
	AAFRESULT			status = OM_ERR_NONE;
	omfType_t			dataType;
	omfMaxSampleSize_t	*samplePtr;
	userDataWAVE_t 		*pdata;

	switch (parmblk->spc.mediaInfo.infoType)
	{
	case kMediaIsContiguous:
		dataType = (parmblk->fileRev == kOmfRev2x ? OMDataValue : OMVarLenBytes);
		status = OMIsPropertyContiguous(main, media->dataObj,OMWAVEData,
										dataType, (aafBool *)parmblk->spc.mediaInfo.buf);
		break;
	case kAudioInfo:
		status = codecGetAudioInfoWAVE(parmblk, media);
		break;

	case kMaxSampleSize:
		samplePtr = (omfMaxSampleSize_t *) parmblk->spc.mediaInfo.buf;
		if(samplePtr->mediaKind == media->soundKind)
		{
			pdata = (userDataWAVE_t *)media->userData;
			samplePtr->largestSampleSize = (_bitsPerSample + 7)/ 8;
		}
		else
			status = OM_ERR_CODEC_CHANNELS;
		break;

	default:
		status = OM_ERR_INVALID_OP_CODEC;
		break;
	}

	return(status);
#else
	return HRESULT_NOT_IMPLEMENTED;
#endif
}

/************************
 * name
 *
 * 		WhatIt(Internal)Does
 *
 * Argument Notes:
 *		StuffNeededBeyondNotesInDefinition.
 *
 * ReturnValue:
 *		Error code (see below).
 *
 * Possible Errors:
 *		Standard errors (see top of file).
 */
AAFRESULT CAAFWaveCodec::writeSwappedWAVEData(aafUInt8 **destBufHdl, aafInt32 maxsize, void *data)
{
	aafInt32        dataL;
	aafInt16        dataS;
	aafUInt8		*destBufPtr = *destBufHdl;

	if ((maxsize == sizeof(aafInt32)) && (INTEL_ORDER != _nativeByteOrder))
	{
		dataL = *((aafInt32 *) data);
		AAFByteSwap32(&dataL);
		data = &dataL;
	} else if ((maxsize == sizeof(aafInt16)) && (INTEL_ORDER != _nativeByteOrder))
	{
		dataS = *((aafInt16 *) data);
		AAFByteSwap16(&dataS);
		data = &dataS;
	}
	memcpy(destBufPtr, data, maxsize);
	*destBufHdl = destBufPtr + maxsize;

	return (AAFRESULT_SUCCESS);
}

AAFRESULT CAAFWaveCodec::readSwappedWAVEData(aafUInt8 **srcBufHdl, aafInt32 maxsize, void *data)
{
	memcpy(data, *srcBufHdl, maxsize);
	(*srcBufHdl) += maxsize;
	
	if ((maxsize == sizeof(aafInt32)) && (INTEL_ORDER != _nativeByteOrder))
			AAFByteSwap32((aafInt32 *) data);
	else if ((maxsize == sizeof(aafInt16)) && (INTEL_ORDER != _nativeByteOrder))
			AAFByteSwap16((aafInt16 *) data);

	return (AAFRESULT_SUCCESS);
}

AAFRESULT CAAFWaveCodec::GetWAVEData(aafUInt32 len, void *buf)
{
	aafUInt32	bytesRead;
	
	XPROTECT()
	{
		CHECK(_stream->Read(len, (aafUInt8 *)buf, &bytesRead));
		if(bytesRead != len)
			RAISE(AAFRESULT_END_OF_DATA);
		if ((len == sizeof(aafInt32)) && (INTEL_ORDER != _nativeByteOrder))
			AAFByteSwap32((aafInt32 *) buf);
		else if ((len == sizeof(aafInt16)) && (INTEL_ORDER != _nativeByteOrder))
			AAFByteSwap16((aafInt16 *) buf);
	}
	XEXCEPT
	XEND;

	return(AAFRESULT_SUCCESS);
}

/************************
 * name
 *
 * 		WhatIt(Internal)Does
 *
 * Argument Notes:
 *		StuffNeededBeyondNotesInDefinition.
 *
 * ReturnValue:
 *		Error code (see below).
 *
 * Possible Errors:
 *		Standard errors (see top of file).
 */
/*
 * Creates WAVE information in the given object. If the object is a
 * descriptor (WAVD), don't create the sound data chunk.
 * 
 */

AAFRESULT CAAFWaveCodec::CreateWAVEheader(aafUInt8		*buffer,
								aafInt32	bufsize,
								aafInt16	numCh)

{
	aafInt32           chunksize, avgBytesPerSec, samplesPerSec;
	aafInt32           zero = 0, len;
	aafInt16           bytesPerFrame;
	aafInt16           pcm_format = 1;
	aafUInt8			*ptr = buffer;

	XPROTECT()
	{	
		_numCh = numCh;
		if(bufsize < STD_HDRSIZE_NODATA)
			RAISE(AAFRESULT_SMALLBUF);

		*ptr++ = 'R';		// Make sure that this is NOT byte-swapped
		*ptr++ = 'I';
		*ptr++ = 'F';
		*ptr++ = 'F';
	
		ptr += 4;			// Patch form length in later

		*ptr++ = 'W';
		*ptr++ = 'A';
		*ptr++ = 'V';
		*ptr++ = 'E';
		*ptr++ = 'f';
		*ptr++ = 'm';
		*ptr++ = 't';
		*ptr++ = ' ';

		chunksize = 16;		/* WAVE format size is fixed */
		CHECK(writeSwappedWAVEData(&ptr, 4L, (void *) &chunksize));
		CHECK(writeSwappedWAVEData(&ptr, 2L, (void *) &pcm_format));
		CHECK(writeSwappedWAVEData(&ptr, 2L, (void *) &numCh));
	
		if (_sampleRate.denominator != 0)
			samplesPerSec = (long) FloatFromRational(_sampleRate);
		else
			samplesPerSec = 0;
		CHECK(writeSwappedWAVEData(&ptr, 4L, (void *) &samplesPerSec));
	
		bytesPerFrame = ((_bitsPerSample + 7) / 8) * numCh;
		avgBytesPerSec = samplesPerSec * bytesPerFrame;
		CHECK(writeSwappedWAVEData(&ptr, 4L, (void *) &avgBytesPerSec));
	
		CHECK(writeSwappedWAVEData(&ptr, 2L, (void *) &bytesPerFrame));
		CHECK(writeSwappedWAVEData(&ptr, 2L, (void *) &_bitsPerSample));
		// !!!Postcondition to make sure that offset within

		/* patch FORM size here. */
		len = ptr - buffer;
		ptr = buffer+ 4;
		CHECK(writeSwappedWAVEData(&ptr, 4L, &len));	// Patch in
	}
	XEXCEPT
	XEND

	return (AAFRESULT_SUCCESS);
}

/************************
 * name
 *
 * 		WhatIt(Internal)Does
 *
 * Argument Notes:
 *		StuffNeededBeyondNotesInDefinition.
 *
 * ReturnValue:
 *		Error code (see below).
 *
 * Possible Errors:
 *		Standard errors (see top of file).
 */
#define DEBUG_READ 1
AAFRESULT CAAFWaveCodec::loadWAVEHeader(void)
{
	aafInt32			offset, chunkStart, formSize;
	aafInt64			chunkStart64;
	aafInt16			pcm_format;
	aafUInt8            chunkID[4];
	aafUInt32			chunkSize, bytesRead;
	aafBool				fmtFound = AAFFalse, dataFound = AAFFalse;
 	aafInt32			junk32, rate;
	aafInt64			savePos;
#if DEBUG_READ
	aafUInt8			debugBuf[64];
#endif

	if(_headerLoaded)
		return AAFRESULT_SUCCESS;
//!!!	pdata->fmtOps[0].opcode = kOmfAFmtEnd;
//!!!	_interleaveBuf = NULL;
	
	XPROTECT()
	{
//!!!		CvtInt32toInt64(0, &pdata->formSizeOffset);
//!!!		CvtInt32toInt64(0, &pdata->dataSizeOffset);
//!!!		CvtInt32toInt64(0, &pdata->numSamplesOffset);
		CHECK(_stream->GetPosition (&savePos));
	
#if DEBUG_READ
		CHECK(_stream->Seek(0L));
		_stream->Read(64L, debugBuf, &bytesRead);
#endif
		CHECK(_stream->Seek(0L));
		CHECK(_stream->Read(4L, chunkID, &bytesRead));
		if (memcmp(&chunkID, "RIFF", (size_t) 4) != 0)
			RAISE(OM_ERR_BADWAVEDATA);
		CHECK(GetWAVEData(4L, (void *) &formSize));	
		CHECK(_stream->Read(4L, chunkID, &bytesRead));
		if (memcmp(&chunkID, "WAVE", (size_t) 4) != 0)
			RAISE(OM_ERR_BADWAVEDATA);
		CHECK(_stream->GetPosition(&chunkStart64));
		CHECK(TruncInt64toInt32(chunkStart64, &offset));	// OK - 32-bit format
	
		while ((offset < formSize) && _stream->Read(4L, chunkID, &bytesRead) == AAFRESULT_SUCCESS)
		{
			CHECK(GetWAVEData(4L, (void *) &chunkSize));	
			CHECK(_stream->GetPosition(&chunkStart64));
	
			if (memcmp(&chunkID, "fmt ", (size_t) 4) == 0)
			{
				/* WAVE field: wFormatTag */
				CHECK(GetWAVEData(2L, &pcm_format));
				if (pcm_format != 1)
					RAISE(OM_ERR_BADWAVEDATA);
	
				/* WAVE field: wChannels */
				CHECK(GetWAVEData(2L, &_numCh));
	
				/* WAVE field: wSamplesPerSec */
				CHECK(GetWAVEData(4L, &rate));
				_sampleRate.numerator = rate;
				_sampleRate.denominator = 1;
	
				/* Skip WAVE field: avgBytesPerSec (4 bytes) */
				CHECK(GetWAVEData(4L, &junk32));
	
				/* WAVE field wBlockAlign */
				CHECK(GetWAVEData(2L, &_bytesPerFrame));
	
				/* WAVE field Sample Width */
				CHECK(GetWAVEData(2L, &_bitsPerSample));
	
				_bytesPerFrame = ((_bitsPerSample + 7) / 8) * _numCh;
	
				fmtFound = AAFTrue;
			} else if (memcmp(&chunkID, "data", (size_t) 4) == 0)
			{
				CvtInt32toInt64(chunkSize / _bytesPerFrame, &_sampleFrames);
				/* Positioned at beginning of audio data */
				CHECK(_stream->GetPosition(&_dataStartOffset));
	
				dataFound = AAFTrue;
			}
			CHECK(TruncInt64toInt32(chunkStart64, &chunkStart));	// OK - 32-bit format
			offset = chunkStart + chunkSize;
	
			if(offset > formSize)
				break;
			if (fmtFound && dataFound)	/* Do we have all information yet? */
				break;
			CHECK(_stream->Seek(offset));
		}
		_headerLoaded = AAFTrue;
		CHECK(_stream->Seek (savePos));
	}
	XEXCEPT
	{
		RERAISE(OM_ERR_BADWAVEDATA);
	}
	XEND
	
	
	return(AAFRESULT_SUCCESS);
}

/************************
 * name
 *
 * 		WhatIt(Internal)Does
 *
 * Argument Notes:
 *		StuffNeededBeyondNotesInDefinition.
 *
 * ReturnValue:
 *		Error code (see below).
 *
 * Possible Errors:
 *		Standard errors (see top of file).
 */
AAFRESULT CAAFWaveCodec::ComputeWriteChunkSize(
			aafInt64 sizeOff, 
			aafInt64 end)
{
	aafInt64          tmpOffset, savePos, result;
	aafUInt32          size;
	aafUInt8			*tmp, buf[4];
#if DEBUG_READ
	aafUInt8			debugBuf[64];
	aafUInt32			bytesRead;
#endif

	XPROTECT()
	{
		CHECK(_stream->GetPosition(&savePos));
	
		tmpOffset = sizeOff;
		CHECK(AddInt32toInt64(4L, &tmpOffset));
		result = end;
		CHECK(SubInt64fromInt64(tmpOffset, &result));
		CHECK(TruncInt64toUInt32(result, &size));	/* OK WAVE */
#if DEBUG_READ
		CHECK(_stream->Seek(0L));
		_stream->Read(64L, debugBuf, &bytesRead);
#endif
		CHECK(_stream->Seek(sizeOff));
		tmp = buf;
		CHECK(writeSwappedWAVEData(&tmp, 4L, &size));
		CHECK(_stream->Write(buf, 4L));
	
		CHECK(_stream->Seek(savePos));
	}
	XEXCEPT
	XEND

	return (OM_ERR_NONE);
}

AAFRESULT CAAFWaveCodec::CreateAudioDataEnd(void)
{
	aafInt64          curOffset;

	XPROTECT()
	{
		/* this routine will be called after sample data is written */
		/* Now set the patches for all the fields of the wave data */
		CHECK(_stream->GetPosition(&curOffset));
	
		CHECK(ComputeWriteChunkSize(4, curOffset));
		CHECK(ComputeWriteChunkSize(_dataSizeOffset, curOffset));
	}
	XEXCEPT
	XEND

	return (AAFRESULT_SUCCESS);
}


/*
 * Given a source buffer & an array of destination buffers, split the samples up in
 * round-robin fashion.  If a destination buffer in the array is NULL, then src is
 * incremented by one sample, but no data transfer occurs.  The first destination
 * buffer is allowed to be the same as the source buffer, but the other destination
 * buffers must be distinct to avoid corruption of the data.
 *
 * The number of entries in dest[] must be equal to numDest, and the dest array WILL
 * BE MODIFIED during execution, so it will have to be reloaded.
 */
static void SplitBuffers(void *original, aafInt32 srcSamples, aafInt16 sampleSize, aafInt16 numDest, interleaveBuf_t *destPtr)
{
	aafInt16	*src16, *srcEnd16, *dest16;
	char	*src8, *srcEnd8, *dest8;
	aafInt16	n, x, sampleBytes;
	
	sampleBytes = (sampleSize + 7) / 8;
	if(sampleSize == 16)
	{
		src16 = (aafInt16 *)original;
		srcEnd16 = src16 + srcSamples;
		while(src16 < srcEnd16)
		{
			for(n = 0; (n < numDest) && (src16 < srcEnd16) ; n++)
			{
				dest16 = (aafInt16 *)destPtr[n].buf;
				if(dest16 != NULL)
				{
					destPtr[n].bytesXfered += sampleBytes;
					*dest16++ = *src16++;
				}
				else
					src16++;
				destPtr[n].buf = (char *)dest16;
			}
		}
	}
	else
	{
		src8 = (char *)original;
		srcEnd8 = src8 + srcSamples;
		while(src8 < srcEnd8)
		{
			for(n = 0; (n < numDest) && (src8 < srcEnd8) ; n++, dest8++)
			{
				dest8 = (char *)destPtr[n].buf;
				if(dest8 != NULL)
				{
					destPtr[n].bytesXfered += sampleBytes;
					{	for(x = 0; x < sampleBytes; x++)
							*dest8++ = *src8++;
					}
				}
				else
					src8++;
				destPtr[n].buf = (char *)dest8;
			}
		}
	}
}

//
// 
// 
HRESULT CAAFWaveCodec::InternalQueryInterface
(
    REFIID riid,
    void **ppvObj)
{
    HRESULT hr = S_OK;

    if (NULL == ppvObj)
        return E_INVALIDARG;

    // We only support the IClassFactory interface 
    if (riid == IID_IAAFEssenceCodec) 
    { 
        *ppvObj = (IAAFEssenceCodec *)this; 
        ((IUnknown *)*ppvObj)->AddRef();
        return S_OK;
    }
    else if (riid == IID_IAAFEssenceSampleStream) 
    { 
        *ppvObj = (IAAFEssenceSampleStream *)this; 
        ((IUnknown *)*ppvObj)->AddRef();
        return S_OK;
    }

    // Always delegate back to base implementation.
    return CAAFUnknown::InternalQueryInterface(riid, ppvObj);
}

//
// Define the contrete object support implementation.
// 
HRESULT CAAFWaveCodec::COMCreate(IUnknown *pUnkOuter, void **ppvObjOut)
{
	*ppvObjOut = NULL;
 	CAAFWaveCodec *pAAFWaveCodec = new CAAFWaveCodec(pUnkOuter);
 	if (NULL == pAAFWaveCodec)
 		return E_OUTOFMEMORY;
 	*ppvObjOut = static_cast<IAAFEssenceCodec *>(pAAFWaveCodec);
 	((IUnknown *)(*ppvObjOut))->AddRef();
 	return S_OK;
 }

