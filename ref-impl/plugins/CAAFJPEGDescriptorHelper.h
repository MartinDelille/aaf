//@doc
//@class    CAAFJPEGDescriptorHelper | class that wraps all of the descriptor interfaces
// needed by the JPEG codec. This class should be replaced by a future
// set of wrapper classed to be provided with the AAF Toolkit.

#ifndef __CAAFJPEGDescriptorHelper_h__
#define __CAAFJPEGDescriptorHelper_h__

// Include the interfaces that our plugin needs to support.
#ifndef __AAFPlugin_h__
#include "AAFPlugin.h"
#endif


class CAAFJPEGDescriptorHelper
{
public:
	CAAFJPEGDescriptorHelper();
	~CAAFJPEGDescriptorHelper();
	
	// Initialize all of the internal interfaces required by the JPEG Codec.
	// This method must be called before any other method (except Clear()).
	HRESULT Initialize(IAAFSourceMob *filemob);

	// Release all of the internal interfaces and reset the object.
	// Called by destructor and Initialize method.
	void Clear(void);

	// Comparison operators to check for initialization by the same file mob.
	bool operator==(const CAAFJPEGDescriptorHelper& rhs);
	bool operator!=(const CAAFJPEGDescriptorHelper& rhs);

	//
	// EssenceDescriptor methods:
	//
	STDMETHOD (GetNumLocators) (aafInt32 *  pCount);
	STDMETHOD (AppendLocator) (IAAFLocator * pLocator);
	STDMETHOD (PrependLocator) (IAAFLocator * pLocator);
	STDMETHOD (EnumAAFAllLocators) (IEnumAAFLocators ** ppEnum);
	//
	// FileDescriptor methods:
	//
	STDMETHOD (SetLength) (aafLength_t  length);
	STDMETHOD (GetLength) (aafLength_t *  pLength);
	STDMETHOD (SetIsInContainer) (aafBool  isAAF);
	STDMETHOD (GetIsInContainer) (aafBool *  pIsAAF);
	STDMETHOD (SetSampleRate) (aafRational_t *  pRate);
	STDMETHOD (GetSampleRate) (aafRational_t*  pRate);
	STDMETHOD (SetContainerFormat) (aafUID_t *  pFormat);
	STDMETHOD (GetContainerFormat) (aafUID_t *  pFormat);
	//
	// DigitalImageDescriptor methods:
	//
	STDMETHOD (SetCompression) (aafUID_t *  pCodecID);
	STDMETHOD (GetCompression) (aafUID_t *  pCompression);
	STDMETHOD (SetStoredView) (aafUInt32  StoredHeight, aafUInt32  StoredWidth);
	STDMETHOD (GetStoredView) (aafUInt32 *  pStoredHeight, aafUInt32 *  pStoredWidth);
	STDMETHOD (SetSampledView) (aafUInt32  SampledHeight, aafUInt32  SampledWidth, aafInt32  SampledXOffset, aafInt32  SampledYOffset);
	STDMETHOD (GetSampledView) (aafUInt32 *  pSampledHeight, aafUInt32 *  pSampledWidth, aafInt32 *  pSampledXOffset, aafInt32 *  pSampledYOffset);
	STDMETHOD (SetDisplayView) (aafUInt32  DisplayHeight, aafUInt32  DisplayWidth, aafInt32  DisplayXOffset, aafInt32  DisplayYOffset);
	STDMETHOD (GetDisplayView) (aafUInt32 *  pDisplayHeight, aafUInt32 *  pDisplayWidth, aafInt32 *  pDisplayXOffset, aafInt32 *  pDisplayYOffset);
	STDMETHOD (SetFrameLayout) (aafFrameLayout_t  FrameLayout);
	STDMETHOD (GetFrameLayout) (aafFrameLayout_t *  pFrameLayout);
	STDMETHOD (SetVideoLineMap) (aafUInt32  numberElements, aafInt32 *  pVideoLineMap);
	STDMETHOD (GetVideoLineMap) (aafUInt32  numberElements, aafInt32 *  pVideoLineMap);
	STDMETHOD (GetVideoLineMapSize) (aafUInt32 *  pNumberElements);
	STDMETHOD (SetImageAspectRatio) (aafRational_t  ImageAspectRatio);
	STDMETHOD (GetImageAspectRatio) (aafRational_t *  pImageAspectRatio);
	STDMETHOD (SetAlphaTransparency) (aafAlphaTransparency_t  AlphaTransparency);
	STDMETHOD (GetAlphaTransparency) (aafAlphaTransparency_t *  pAlphaTransparency);
	STDMETHOD (SetGamma) (aafRational_t  Gamma);
	STDMETHOD (GetGamma) (aafRational_t *  pGamma);
	STDMETHOD (SetImageAlignmentFactor) (aafInt32  ImageAlignmentFactor);
	STDMETHOD (GetImageAlignmentFactor) (aafInt32 *  pImageAlignmentFactor);
	//
	// CDCIDescriptor methods:
	//
	STDMETHOD (SetComponentWidth) (aafInt32  ComponentWidth);
	STDMETHOD (GetComponentWidth) (aafInt32 *  pComponentWidth);
	STDMETHOD (SetHorizontalSubsampling) (aafUInt32  HorizontalSubsampling);
	STDMETHOD (GetHorizontalSubsampling) (aafUInt32 *  pHorizontalSubsampling);
	STDMETHOD (SetColorSiting) (aafColorSiting_t  ColorSiting);
	STDMETHOD (GetColorSiting) (aafColorSiting_t *  pColorSiting);
	STDMETHOD (SetBlackReferenceLevel) (aafUInt32  BlackReferenceLevel);
	STDMETHOD (GetBlackReferenceLevel) (aafUInt32 *  pBlackReferenceLevel);
	STDMETHOD (SetWhiteReferenceLevel) (aafUInt32  WhiteReferenceLevel);
	STDMETHOD (GetWhiteReferenceLevel) (aafUInt32 *  pWhiteReferenceLevel);
	STDMETHOD (SetColorRange) (aafUInt32  ColorRange);
	STDMETHOD (GetColorRange) (aafUInt32 *  pColorRange);
	STDMETHOD (SetPaddingBits) (aafInt16  PaddingBits);
	STDMETHOD (GetPaddingBits) ( aafInt16 *  pPaddingBits);


private:
	IUnknown *_filemob_unk; // used for equality testing.
	IAAFSourceMob *_filemob;
	IAAFEssenceDescriptor *_edes;
	IAAFFileDescriptor *_filedes;
	IAAFDigitalImageDescriptor *_dides;
	IAAFCDCIDescriptor *_cdcides;  // Compressed digital image descriptor
};



#endif // #ifndef __CAAFJPEGDescriptorHelper_h__