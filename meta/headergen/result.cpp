//=---------------------------------------------------------------------=
//
// $Id$ $Name$
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
// The Original Code of this file is Copyright 1998-2006, Licensor of the
// AAF Association.
//
// The Initial Developer of the Original Code of this file and the
// Licensor of the AAF Association is Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=

// Author : Tim Bingham (Tim_Bingham@avid.com)

#include "headerGenUtils.h"

#include <iostream>
#include <string>
using namespace std;
#include <assert.h>

void comment(const char* s)
{
  cout << "/* ";
  cout << s;
  cout << " */";
}

void section(const char* s)
{
  cout << endl;
  comment(s);
  cout << endl;
}

void genCode(const char* name, unsigned long int val, const char* desc)
{
  if (strlen(desc) != 0) {
    cout << "        ";
    comment(desc);
    cout << endl;
  }
  cout << "#define ";
  printName(name, 42, cout);
  cout << "((HRESULT)0x" << hex << val + 0x80000000 + 0x120000 <<")";
  cout << endl;
}

void success(const char* name, unsigned long int val)
{
  cout << "#define ";
  printName(name, 52, cout);
  cout << val << endl;
}

void alias(const char* fullOldName, const char* name)
{
  cout << "#define ";
  printName(fullOldName, 42, cout);
  printName(name, 0, cout);
  cout << endl;
}

void printBoilerPlate(ostream& s)
{
  s << "#define AAFRESULT_FAILED(Status) ((AAFRESULT)(Status)<0)";
  s << endl;
  s << "#define AAFRESULT_SUCCEEDED(Status) (!(AAFRESULT_FAILED(Status)))";
  s << endl;

  s << endl;

  s << "#define _FACILITY_AAF 0x12";
  s << endl;

  s << "#define MAKE_AAFHRESULT( code ) \\";
  s << endl;
  s << "    ((HRESULT) (((aafUInt32)(1)             <<31) | \\";
  s << endl;
  s << "                ((aafUInt32)(_FACILITY_AAF) <<16) | \\";
  s << endl;
  s << "                ((aafUInt32)(code))) )";
  s << endl;

  s << endl;

  s << "/* Non-AAF codes */";
  s << endl;
  s << "#define AAFRESULT_NOT_IMPLEMENTED                 ";
  s << "((HRESULT)0x80004001L)";
  s << endl;
}

static void doFile(const char* moduleName)
{
  assert(moduleName);
  printBeginGuard(moduleName, cout);
  printCopyright(cout);

  printBoilerPlate(cout);

#define AAF_ERROR_SECTION(s) section(s);
#define AAF_DEFINE_ERROR(name, val, desc) \
        genCode("AAFRESULT_"#name, val, desc);
#define AAF_DEFINE_SUCCESS(name, code) \
        success("AAFRESULT_"#name, code);
#define AAF_DEFINE_ERROR_ALIAS(fullOldName, name) \
        alias(#fullOldName, "AAFRESULT_"#name);
#include "AAFMetaResult.h"

  printEndGuard(moduleName, cout);
}

int main(int argc, char** argv)
{
  char* moduleName = 0;
  validateArgs(argc, argv, moduleName);
  assert(moduleName);
  doFile(moduleName);
  return 0;
}

