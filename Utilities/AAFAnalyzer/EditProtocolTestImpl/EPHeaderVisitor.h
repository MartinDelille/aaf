//=---------------------------------------------------------------------=
//
// $Id$
//
// The contents of this file are subject to the AAF SDK Public
// Source License Agreement (the "License"); You may not use this file
// except in compliance with the License.  The License is available in
// AAFSDKPSL.TXT, or you may obtain a copy of the License from the AAF
// Association or its successor.
//
// Software distributed under the License is distributed on an "AS IS"
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See
// the License for the specific language governing rights and limitations
// under the License.
//
// The Original Code of this file is Copyright 1998-2004, Licensor of the
// AAF Association.
//
//=---------------------------------------------------------------------=

#ifndef __EPHeaderVisitor_h_
#define __EPHeaderVisitor_h_

//AAF Analyzer Base files
#include <TypedVisitor.h>
#include <AAFTypedObjNode.h>

//Ax files
#include <AxTypes.h>

namespace aafanalyzer {

using namespace boost;

class DetailLevelTestResult;

class EPHeaderVisitor : public TypedVisitor
{

  public:
  
    EPHeaderVisitor( wostream& log );
    
    virtual ~EPHeaderVisitor();
   
    virtual bool PreOrderVisit( AAFTypedObjNode<IAAFHeader>& node );
       
    shared_ptr<DetailLevelTestResult> GetResult();
    
  private:
   
    wostream& _log;
    shared_ptr<DetailLevelTestResult> _spResult;

    // prohibited
    EPHeaderVisitor();
    EPHeaderVisitor( const EPHeaderVisitor& );
    EPHeaderVisitor& operator=( const EPHeaderVisitor& );
  
};

} // end of namespace diskstream

#endif /*__EPHeaderVisitor_h_*/
