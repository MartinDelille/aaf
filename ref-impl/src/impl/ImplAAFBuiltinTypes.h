/***********************************************************************
 *
 *              Copyright (c) 1998-1999 Avid Technology, Inc.
 *
 * Permission to use, copy and modify this software and accompanying 
 * documentation, and to distribute and sublicense application software
 * incorporating this software for any purpose is hereby granted, 
 * provided that (i) the above copyright notice and this permission
 * notice appear in all copies of the software and related documentation,
 * and (ii) the name Avid Technology, Inc. may not be used in any
 * advertising or publicity relating to the software without the specific,
 *  prior written permission of Avid Technology, Inc.
 *
 * THE SOFTWARE IS PROVIDED AS-IS AND WITHOUT WARRANTY OF ANY KIND,
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

#ifndef __ImplAAFBuiltinTypes_h__
#define __ImplAAFBuiltinTypes_h__

//
// Support for built-in type definitions.
//


#include "AAFTypes.h"

#ifndef __ImplAAFSearchableStack_h__
#include "ImplAAFSearchableStack.h"
#endif

#ifndef __ImplAAFUID_h__
#include "ImplAAFUID.h"
#endif

class ImplAAFDictionary;
class ImplAAFTypeDef;
class ImplAAFTypeDefEnum;
class ImplAAFTypeDefRecord;


class ImplAAFBuiltinTypes
{
public:
  ImplAAFBuiltinTypes (ImplAAFDictionary* dictionary);

  //
  // Creates the requested type def object, registers it in the
  // dictionary, and initializes the OM properties therein.
  //
  AAFRESULT ImportBuiltinTypeDef (const aafUID_t & rTypeID,
								  ImplAAFTypeDef ** ppResult);


  //
  // Creates the requested type def object and initializes the OM
  // properties therein.
  //
  AAFRESULT NewBuiltinTypeDef (const aafUID_t & rTypeID,
							   ImplAAFTypeDef ** ppResult);

  //
  // If the given type defs are built-in, will register their
  // offsets/sizes.
  //
  static void RegisterExistingType (ImplAAFTypeDefEnum * ptde);
  static void RegisterExistingType (ImplAAFTypeDefRecord * ptdr);

private:

  ImplAAFDictionary* _dictionary; // pointer back to associated dictionary (temp)

  ImplAAFSearchableStack<ImplAAFUID> _lookupStack;
};

#endif // ! __ImplAAFBuiltinTypes_h__
