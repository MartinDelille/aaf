/******************************************\
*                                          *
* Advanced Authoring Format                *
*                                          *
* Copyright (c) 1998 Avid Technology, Inc. *
* Copyright (c) 1998 Microsoft Corporation *
*                                          *
\******************************************/


#ifndef __ImplAAFIdentification_h__
#include "ImplAAFIdentification.h"
#endif




#ifndef __ImplEnumAAFIdentifications_h__
#include "ImplEnumAAFIdentifications.h"
#endif

#include "ImplAAFHeader.h"
#include "ImplAAFDictionary.h"
#include "ImplAAFObjectCreation.h"

#include <assert.h>
#include <string.h>
#include "aafErr.h"

extern "C" const aafClassID_t CLSID_EnumAAFIdentifications;

ImplEnumAAFIdentifications::ImplEnumAAFIdentifications ()
{
	_current = 0;
	_enumObj = NULL;
	_enumProp = NULL;
	_enumStrongProp = NULL;
}


ImplEnumAAFIdentifications::~ImplEnumAAFIdentifications ()
{
	if (_enumObj)
	{
		_enumObj->ReleaseReference();
		_enumObj = NULL;
	}
}

AAFRESULT STDMETHODCALLTYPE
    ImplEnumAAFIdentifications::NextOne (
      ImplAAFIdentification **ppIdentification)
{
	aafUInt32			numElem;
//	aafUID_t			value;
	ImplAAFHeader		*head = NULL;
	ImplAAFDictionary	*dict = NULL;

	if(_enumProp != NULL)
		numElem = _enumProp->size() / sizeof(aafUID_t);
	else if(_enumStrongProp != NULL)
	{
		size_t	siz;
		
		_enumStrongProp->getSize(siz);
		numElem = siz;
	}
	else
		return(AAFRESULT_INCONSISTANCY);

	if(ppIdentification == NULL)
		return(AAFRESULT_NULL_PARAM);
	if(_current >= numElem)
		return AAFRESULT_NO_MORE_OBJECTS;
	XPROTECT()
	{
//!!!		if(_enumProp != NULL)
//		{
//			_enumProp->getValueAt(&value, _current);
//			CHECK(_enumObj->MyHeadObject(&head));
//			CHECK(head->GetDictionary (&dict));
//			CHECK(dict->LookupParameterDefinition(&value, ppIdentification));
//			head->ReleaseReference();
//			head = NULL;
//			dict->ReleaseReference();
//			dict = NULL;
//		}
//		else
			if(_enumStrongProp != NULL)
		{
			_enumStrongProp->getValueAt(*ppIdentification, _current);
			(*ppIdentification)->AcquireReference();
		}
		else
			RAISE(AAFRESULT_INCONSISTANCY);
		_current++;
		if (head) {
			head->ReleaseReference();
			head = NULL;
		}
		if (dict) {
			dict->ReleaseReference();
			dict = NULL;
		}
	}
	XEXCEPT
	{
		if(head)
			head->ReleaseReference();
		if(dict)
			dict->ReleaseReference();
	}
	XEND;

	return(AAFRESULT_SUCCESS); 
}



AAFRESULT STDMETHODCALLTYPE
    ImplEnumAAFIdentifications::Next (
      aafInt32  count,
      ImplAAFIdentification ** ppIdentifications,
      aafInt32 * pNumFetched)
{
	ImplAAFIdentification**	ppDef;
	aafInt32				numDefs;
	HRESULT					hr;

	if ((pNumFetched == NULL && count != 1) || (pNumFetched != NULL && count == 1))
		return E_INVALIDARG;

	// Point at the first component in the array.
	ppDef = ppIdentifications;
	for (numDefs = 0; numDefs < count; numDefs++)
	{
		hr = NextOne(ppDef);
		if (FAILED(hr))
			break;

		// Point at the next component in the array.  This
		// will increment off the end of the array when
		// numComps == count-1, but the for loop should
		// prevent access to this location.
		ppDef++;
	}
	
	if (pNumFetched)
		*pNumFetched = numDefs;

	return hr;
}



AAFRESULT STDMETHODCALLTYPE
    ImplEnumAAFIdentifications::Skip (
      aafUInt32 count)
{
	AAFRESULT	hr;
	aafUInt32	newCurrent;
	aafUInt32	numElem;

//!!!	if(_enumProp != NULL)
//		numElem = _enumProp->size() / sizeof(aafUID_t);
//	else
		if(_enumStrongProp != NULL)
	{
		size_t	siz;
		
		_enumStrongProp->getSize(siz);
		numElem = siz;
	}
	else
		return(AAFRESULT_INCONSISTANCY);

	newCurrent = _current + count;

	if(newCurrent < numElem)
	{
		_current = newCurrent;
		hr = AAFRESULT_SUCCESS;
	}
	else
	{
		hr = E_FAIL;
	}

	return hr;
}



AAFRESULT STDMETHODCALLTYPE
    ImplEnumAAFIdentifications::Reset ()
{
	_current = 0;
	return AAFRESULT_SUCCESS;
}



AAFRESULT STDMETHODCALLTYPE
    ImplEnumAAFIdentifications::Clone (
      ImplEnumAAFIdentifications **ppEnum)
{
	ImplEnumAAFIdentifications	*result;
	AAFRESULT					hr;

	result = (ImplEnumAAFIdentifications *)CreateImpl(CLSID_EnumAAFIdentifications);
	if (result == NULL)
		return E_FAIL;

//!!!	if(_enumProp != NULL)
//		hr = result->SetEnumProperty(_enumObj, _enumProp);
//	else
		if(_enumStrongProp != NULL)
		hr = result->SetEnumStrongProperty(_enumObj, _enumStrongProp);
	if (SUCCEEDED(hr))
	{
		result->_current = _current;
		*ppEnum = result;
	}
	else
	{
		result->ReleaseReference();
		*ppEnum = NULL;
	}
	
	return hr;
}



AAFRESULT STDMETHODCALLTYPE
    ImplEnumAAFIdentifications::SetEnumProperty( ImplAAFObject *pObj, identWeakRefArrayProp_t *pProp)
{
	if (_enumObj)
		_enumObj->ReleaseReference();
	_enumObj = pObj;
	if (pObj)
		pObj->AcquireReference();
	_enumProp = pProp;				// Don't refcount, same lifetime as the object.
	_enumStrongProp = NULL;

	return AAFRESULT_SUCCESS;
}

AAFRESULT STDMETHODCALLTYPE
    ImplEnumAAFIdentifications::SetEnumStrongProperty( ImplAAFObject *pObj, identStrongRefArrayProp_t *pProp)
{
	if (_enumObj)
		_enumObj->ReleaseReference();
	_enumObj = pObj;
	if (pObj)
		pObj->AcquireReference();
	/**/
	_enumStrongProp = pProp;		// Don't refcount, same lifetime as the object.
	_enumProp = NULL;

	return AAFRESULT_SUCCESS;
}