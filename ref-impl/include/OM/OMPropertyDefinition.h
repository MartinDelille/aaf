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
#ifndef OMPROPERTYDEFINITION_H
#define OMPROPERTYDEFINITION_H

#include "OMDataTypes.h"

class OMType;

  // @class Abstract base class used to define persistent properties
  //        supported by the Object Manager.
  //   @cauthor Tim Bingham | tjb | Avid Technology, Inc.
class OMPropertyDefinition {
public:
  // @access Public members.

    // @cmember Destructor.
  virtual ~OMPropertyDefinition(void) {}

    // @cmember The type of the <c OMProperty> defined by this
    //          <c OMPropertyDefinition>.
  virtual const OMType* type(void) const = 0;

    // @cmember The name of the <c OMProperty> defined by this
    //          <c OMPropertyDefinition>.
  virtual const wchar_t* name(void) const = 0;

    // @cmember The locally unique identification of the <c OMProperty>
    //          defined by this <c OMPropertyDefinition>.
  virtual OMPropertyId localIdentification(void) const = 0;

    // @cmember Is the <c OMProperty> defined by this
    //          <c OMPropertyDefinition> optional? 
  virtual bool isOptional(void) const = 0;

};

  // @class Definitions of persistent properties supported by
  //        the Object Manager.
  //   @cauthor Tim Bingham | tjb | Avid Technology, Inc.
  //   @devnote This is a temporary class and will be merged into
  //            <c OMPropertyDefinition>. This will require changes
  //            to code in Object Manager clients.
class OMBuiltinPropertyDefinition : public OMPropertyDefinition {
public:
  // @access Public members.

    // @cmember Constructor.
  OMBuiltinPropertyDefinition(const OMType* type,
                              const wchar_t* name,
                              const OMPropertyId propertyId,
                              const bool isOptional);

    // @cmember Destructor.
  ~OMBuiltinPropertyDefinition(void);

    // @cmember The type of the <c OMProperty> defined by this
    //          <c OMBuiltinPropertyDefinition>.
  virtual const OMType* type(void) const;

    // @cmember The name of the <c OMProperty> defined by this
    //          <c OMBuiltinPropertyDefinition>.
  virtual const wchar_t* name(void) const;

    // @cmember The locally unique identification of the <c OMProperty>
    //          defined by this <c OMBuiltinPropertyDefinition>.
  virtual OMPropertyId localIdentification(void) const;

    // @cmember Is the <c OMProperty> defined by this
    //          <c OMBuiltinPropertyDefinition> optional? 
  virtual bool isOptional(void) const;

private:
  // @access Private members.

  const OMType* _type;
  const wchar_t* _name;
  const OMPropertyId _propertyId;
  const bool _isOptional;

};

#endif
