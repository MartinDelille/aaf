//=---------------------------------------------------------------------=
//
// This file was GENERATED for the AAF SDK
//
// $Id$ $Name$
//
// The contents of this file are subject to the AAF SDK Public Source
// License Agreement Version 2.0 (the "License"); You may not use this
// file except in compliance with the License.  The License is available
// in AAFSDKPSL.TXT, or you may obtain a copy of the License from the
// Advanced Media Workflow Association, Inc., or its successor.
//
// Software distributed under the License is distributed on an "AS IS"
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See
// the License for the specific language governing rights and limitations
// under the License.  Refer to Section 3.3 of the License for proper use
// of this Exhibit.
//
// WARNING:  Please contact the Advanced Media Workflow Association,
// Inc., for more information about any additional licenses to
// intellectual property covering the AAF Standard that may be required
// to create and distribute AAF compliant products.
// (http://www.amwa.tv/policies).
//
// Copyright Notices:
// The Original Code of this file is Copyright 1998-2012, licensor of the
// Advanced Media Workflow Association.  All rights reserved.
//
// The Initial Developer of the Original Code of this file and the
// licensor of the Advanced Media Workflow Association is
// Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=



#include "CEnumAAFKLVData.h"
#include "ImplEnumAAFKLVData.h"
#include "AAFResult.h"
#include "CAAFEnumValidation.h"

#include "OMAssertions.h"
#include "OMExceptions.h"

#include <assert.h>
#include <string.h>

#include "CAAFKLVData.h"
#include "ImplAAFKLVData.h"

// CLSID for EnumAAFKLVData 
// {46114415-0676-11d4-A356-009027DFCA6A}
EXTERN_C const CLSID CLSID_EnumAAFKLVData = { 0x46114415, 0x0676, 0x11d4, { 0xA3, 0x56, 0x00, 0x90, 0x27, 0xDF, 0xCA, 0x6A } };





CEnumAAFKLVData::CEnumAAFKLVData (IUnknown * pControllingUnknown, aafBool doInit)
  : CAAFRoot (pControllingUnknown, kAAFFalse)
{
  if (doInit)
    {
      ImplEnumAAFKLVData * newRep;
      newRep = new ImplEnumAAFKLVData;
      assert (newRep);
      InitRep (newRep);
    }
}


CEnumAAFKLVData::~CEnumAAFKLVData ()
{
}


HRESULT STDMETHODCALLTYPE
    CEnumAAFKLVData::NextOne (IAAFKLVData ** ppKLVData)
{
  HRESULT hr;

  ImplEnumAAFKLVData * ptr;
  ImplAAFRoot * pO;
  pO = GetRepObject ();
  assert (pO);
  ptr = static_cast<ImplEnumAAFKLVData*> (pO);
  assert (ptr);

  //
  // set up for ppKLVData
  //
  ImplAAFKLVData * internalppKLVData = NULL;
  ImplAAFKLVData ** pinternalppKLVData = NULL;
  if (ppKLVData)
    {
      pinternalppKLVData = &internalppKLVData;
    }

  try
    {
      hr = ptr->NextOne
       (pinternalppKLVData);
    }
  catch (OMException& e)
    {
      // OMExceptions should be handled by the impl code. However, if an
      // unhandled OMException occurs, control reaches here. We must not
      // allow the unhandled exception to reach the client code, so we
      // turn it into a failure status code.
      //
      // If the OMException contains an HRESULT, it is returned to the
      // client, if not, AAFRESULT_UHANDLED_EXCEPTION is returned.
      //
      hr = OMExceptionToResult(e, AAFRESULT_UNHANDLED_EXCEPTION);
    }
  catch (OMAssertionViolation &)
    {
      // Control reaches here if there is a programming error in the
      // impl code that was detected by an assertion violation.
      // We must not allow the assertion to reach the client code so
      // here we turn it into a failure status code.
      //
      hr = AAFRESULT_ASSERTION_VIOLATION;
    }
  catch (...)
    {
      // We CANNOT throw an exception out of a COM interface method!
      // Return a reasonable exception code.
      //
      hr = AAFRESULT_UNEXPECTED_EXCEPTION;
    }

  //
  // cleanup for ppKLVData
  //
  if (SUCCEEDED(hr))
    {
      IUnknown *pUnknown;
      HRESULT hStat;

      if (internalppKLVData)
        {
          pUnknown = static_cast<IUnknown *> (internalppKLVData->GetContainer());
          hStat = pUnknown->QueryInterface(IID_IAAFKLVData, (void **)ppKLVData);
          assert (SUCCEEDED (hStat));
          //pUnknown->Release();
          internalppKLVData->ReleaseReference(); // We are through with this pointer.
          internalppKLVData = 0;
        }
    }

  // If the call to the Impl method above fails, internalppKLVData should
  // not be modified, check this with an assertion.
  //
  // If this assertion fails there's a programming error in the Impl
  // method above. Such a programming error also indicates a potential
  // memory leak.
  //
  assert (SUCCEEDED(hr) || internalppKLVData == 0);

  return hr;
}



HRESULT STDMETHODCALLTYPE
    CEnumAAFKLVData::Next (aafUInt32  count,
        IAAFKLVData ** ppKLVData,
        aafUInt32 *  pNumFetched)
{
  HRESULT hr;

  ImplEnumAAFKLVData * ptr;
  ImplAAFRoot * pO;
  pO = GetRepObject ();
  assert (pO);
  ptr = static_cast<ImplEnumAAFKLVData*> (pO);
  assert (ptr);

  //
  // set up for ppKLVData
  //
  ImplAAFKLVData ** internalppKLVData = NULL;
  assert (count >= 0);
  internalppKLVData = new ImplAAFKLVData*[count];
  assert (internalppKLVData);

  ImplAAFKLVData ** pinternalppKLVData = NULL;
  if (ppKLVData)
    {
      pinternalppKLVData = internalppKLVData;
    }

  try
    {
      hr = ptr->Next
       (count,
        pinternalppKLVData,
        pNumFetched);
    }
  catch (OMException& e)
    {
      // OMExceptions should be handled by the impl code. However, if an
      // unhandled OMException occurs, control reaches here. We must not
      // allow the unhandled exception to reach the client code, so we
      // turn it into a failure status code.
      //
      // If the OMException contains an HRESULT, it is returned to the
      // client, if not, AAFRESULT_UHANDLED_EXCEPTION is returned.
      //
      hr = OMExceptionToResult(e, AAFRESULT_UNHANDLED_EXCEPTION);
    }
  catch (OMAssertionViolation &)
    {
      // Control reaches here if there is a programming error in the
      // impl code that was detected by an assertion violation.
      // We must not allow the assertion to reach the client code so
      // here we turn it into a failure status code.
      //
      hr = AAFRESULT_ASSERTION_VIOLATION;
    }
  catch (...)
    {
      // We CANNOT throw an exception out of a COM interface method!
      // Return a reasonable exception code.
      //
      hr = AAFRESULT_UNEXPECTED_EXCEPTION;
    }

  //
  // cleanup for ppKLVData
  //
  if (SUCCEEDED(hr)||hr==AAFRESULT_NO_MORE_OBJECTS)
    {
      IUnknown *pUnknown;
      HRESULT hStat;
      aafUInt32 localIdx;
	  assert (count >= 0);
	  for (localIdx = 0; localIdx < *pNumFetched; localIdx++)
		{
		  pUnknown = static_cast<IUnknown *> (internalppKLVData[localIdx]->GetContainer());
		  hStat = pUnknown->QueryInterface(IID_IAAFKLVData, (void **)(ppKLVData+localIdx));
		  assert (SUCCEEDED (hStat));
		  //pUnknown->Release();
		  internalppKLVData[localIdx]->ReleaseReference(); // We are through with this pointer.
		}
    }
  delete[] internalppKLVData;
  internalppKLVData = 0;
  return hr;
}



HRESULT STDMETHODCALLTYPE
    CEnumAAFKLVData::Skip (aafUInt32  count)
{
  HRESULT hr;

  ImplEnumAAFKLVData * ptr;
  ImplAAFRoot * pO;
  pO = GetRepObject ();
  assert (pO);
  ptr = static_cast<ImplEnumAAFKLVData*> (pO);
  assert (ptr);


  try
    {
      hr = ptr->Skip
       (count);
    }
  catch (OMException& e)
    {
      // OMExceptions should be handled by the impl code. However, if an
      // unhandled OMException occurs, control reaches here. We must not
      // allow the unhandled exception to reach the client code, so we
      // turn it into a failure status code.
      //
      // If the OMException contains an HRESULT, it is returned to the
      // client, if not, AAFRESULT_UHANDLED_EXCEPTION is returned.
      //
      hr = OMExceptionToResult(e, AAFRESULT_UNHANDLED_EXCEPTION);
    }
  catch (OMAssertionViolation &)
    {
      // Control reaches here if there is a programming error in the
      // impl code that was detected by an assertion violation.
      // We must not allow the assertion to reach the client code so
      // here we turn it into a failure status code.
      //
      hr = AAFRESULT_ASSERTION_VIOLATION;
    }
  catch (...)
    {
      // We CANNOT throw an exception out of a COM interface method!
      // Return a reasonable exception code.
      //
      hr = AAFRESULT_UNEXPECTED_EXCEPTION;
    }

  return hr;
}



HRESULT STDMETHODCALLTYPE
    CEnumAAFKLVData::Reset ()
{
  ImplEnumAAFKLVData * ptr;
  ImplAAFRoot * pO;
  pO = GetRepObject ();
  assert (pO);
  ptr = static_cast<ImplEnumAAFKLVData*> (pO);
  assert (ptr);
  HRESULT hr;

  try
    {
      hr = ptr->Reset();
    }
  catch (OMException& e)
    {
      // OMExceptions should be handled by the impl code. However, if an
      // unhandled OMException occurs, control reaches here. We must not
      // allow the unhandled exception to reach the client code, so we
      // turn it into a failure status code.
      //
      // If the OMException contains an HRESULT, it is returned to the
      // client, if not, AAFRESULT_UHANDLED_EXCEPTION is returned.
      //
      hr = OMExceptionToResult(e, AAFRESULT_UNHANDLED_EXCEPTION);
    }
  catch (OMAssertionViolation &)
    {
      // Control reaches here if there is a programming error in the
      // impl code that was detected by an assertion violation.
      // We must not allow the assertion to reach the client code so
      // here we turn it into a failure status code.
      //
      hr = AAFRESULT_ASSERTION_VIOLATION;
    }
  catch (...)
    {
      // We CANNOT throw an exception out of a COM interface method!
      // Return a reasonable exception code.
      //
      hr = AAFRESULT_UNEXPECTED_EXCEPTION;
    }

  return hr;
}



HRESULT STDMETHODCALLTYPE
    CEnumAAFKLVData::Clone (IEnumAAFKLVData ** ppEnum)
{
  HRESULT hr;

  ImplEnumAAFKLVData * ptr;
  ImplAAFRoot * pO;
  pO = GetRepObject ();
  assert (pO);
  ptr = static_cast<ImplEnumAAFKLVData*> (pO);
  assert (ptr);

  //
  // set up for ppEnum
  //
  ImplEnumAAFKLVData * internalppEnum = NULL;
  ImplEnumAAFKLVData ** pinternalppEnum = NULL;
  if (ppEnum)
    {
      pinternalppEnum = &internalppEnum;
    }

  try
    {
      hr = ptr->Clone
       (pinternalppEnum);
    }
  catch (OMException& e)
    {
      // OMExceptions should be handled by the impl code. However, if an
      // unhandled OMException occurs, control reaches here. We must not
      // allow the unhandled exception to reach the client code, so we
      // turn it into a failure status code.
      //
      // If the OMException contains an HRESULT, it is returned to the
      // client, if not, AAFRESULT_UHANDLED_EXCEPTION is returned.
      //
      hr = OMExceptionToResult(e, AAFRESULT_UNHANDLED_EXCEPTION);
    }
  catch (OMAssertionViolation &)
    {
      // Control reaches here if there is a programming error in the
      // impl code that was detected by an assertion violation.
      // We must not allow the assertion to reach the client code so
      // here we turn it into a failure status code.
      //
      hr = AAFRESULT_ASSERTION_VIOLATION;
    }
  catch (...)
    {
      // We CANNOT throw an exception out of a COM interface method!
      // Return a reasonable exception code.
      //
      hr = AAFRESULT_UNEXPECTED_EXCEPTION;
    }

  //
  // cleanup for ppEnum
  //
  if (SUCCEEDED(hr))
    {
      IUnknown *pUnknown;
      HRESULT hStat;

      if (internalppEnum)
        {
          pUnknown = static_cast<IUnknown *> (internalppEnum->GetContainer());
          hStat = pUnknown->QueryInterface(IID_IEnumAAFKLVData, (void **)ppEnum);
          assert (SUCCEEDED (hStat));
          //pUnknown->Release();
          internalppEnum->ReleaseReference(); // We are through with this pointer.
          internalppEnum = 0;
        }
    }

  // If the call to the Impl method above fails, internalppEnum should
  // not be modified, check this with an assertion.
  //
  // If this assertion fails there's a programming error in the Impl
  // method above. Such a programming error also indicates a potential
  // memory leak.
  //
  assert (SUCCEEDED(hr) || internalppEnum == 0);

  return hr;
}

//
// 
// 
inline int EQUAL_UID(const GUID & a, const GUID & b)
{
  return (0 == memcmp((&a), (&b), sizeof (aafUID_t)));
}
HRESULT CEnumAAFKLVData::InternalQueryInterface
(
    REFIID riid,
    void **ppvObj)
{
    if (NULL == ppvObj)
        return E_INVALIDARG;

    // We only support the IClassFactory interface 
    if (EQUAL_UID(riid,IID_IEnumAAFKLVData)) 
    { 
        *ppvObj = (IEnumAAFKLVData *)this; 
        ((IUnknown *)*ppvObj)->AddRef();
        return S_OK;
    }

    // Always delegate back to base implementation.
    return CAAFRoot::InternalQueryInterface(riid, ppvObj);
}

//
// Define the contrete object support implementation.
// 
AAF_DEFINE_FACTORY(EnumAAFKLVData)

