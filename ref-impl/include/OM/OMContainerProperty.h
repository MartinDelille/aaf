/***********************************************************************
*
*              Copyright (c) 1998-2000 Avid Technology, Inc.
*
* Permission to use, copy and modify this software and accompanying
* documentation, and to distribute and sublicense application software
* incorporating this software for any purpose is hereby granted,
* provided that (i) the above copyright notice and this permission
* notice appear in all copies of the software and related documentation,
* and (ii) the name Avid Technology, Inc. may not be used in any
* advertising or publicity relating to the software without the specific,
* prior written permission of Avid Technology, Inc.
*
* THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,
* EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY
* WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
* IN NO EVENT SHALL AVID TECHNOLOGY, INC. BE LIABLE FOR ANY DIRECT,
* SPECIAL, INCIDENTAL, PUNITIVE, INDIRECT, ECONOMIC, CONSEQUENTIAL OR
* OTHER DAMAGES OF ANY KIND, OR ANY DAMAGES WHATSOEVER ARISING OUT OF
* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE AND
* ACCOMPANYING DOCUMENTATION, INCLUDING, WITHOUT LIMITATION, DAMAGES
* RESULTING FROM LOSS OF USE, DATA OR PROFITS, AND WHETHER OR NOT
* ADVISED OF THE POSSIBILITY OF DAMAGE, REGARDLESS OF THE THEORY OF
* LIABILITY.
*
************************************************************************/

// @doc OMEXTERNAL
#ifndef OMCONTAINERPROPERTY_H
#define OMCONTAINERPROPERTY_H

#include "OMProperty.h"

  // @class Abstract base class for persistent container properties
  //        supported by the Object Manager.
  //   @tcarg class | ReferencedObject | The type of the referenced
  //          (contained) object. This type must be a descendant of
  //          <c OMStorable>.
  //   @base public | <c OMProperty>
template <typename ReferencedObject>
class OMContainerProperty : public OMProperty {
public:
  // @access Public members.

    // @cmember Constructor.
  OMContainerProperty(const OMPropertyId propertyId,
                      const OMStoredForm storedForm,
                      const wchar_t* name);

    // @cmember Destructor.
  virtual ~OMContainerProperty(void);

    // @cmember Insert <p object> into this <c OMContainerProperty>.
  virtual void insert(const ReferencedObject* object) = 0;

    // @cmember Does this <c OMContainerProperty> contain <p object> ?
  virtual bool containsValue(const ReferencedObject* object) const = 0;

    // @cmember The number of <p ReferencedObject>s in this
    //          <c OMContainerProperty>. <mf OMContainerProperty::count>
    //          returns the actual number of <p ReferencedObject>s in the
    //          <c OMContainerProperty>.
  virtual size_t count(void) const = 0;

    // @cmember Remove <p object> from this <c OMContainerProperty>.
  virtual void removeValue(const ReferencedObject* object) = 0;

protected:
  // @access Protected members.

    // @cmember Compute the name of an element in this <c OMContainter>
    //          given the element's <p localKey>.
  wchar_t* elementName(OMUInt32 localKey);

    // @cmember Obtain the next available local key.
  OMUInt32 nextLocalKey(void);

    // @cmember The current local key.
  OMUInt32 localKey(void) const;

    // @cmember Set the current local key. Used on restore to restart
    //          local key assignment.
  void setLocalKey(OMUInt32 newLocalKey);

  virtual const wchar_t* storedName(void) const;

private:
  // @access Private members.

    // @cmember The next available local key.
    //
  OMUInt32 _localKey;

};

#include "OMContainerPropertyT.h"

#endif
