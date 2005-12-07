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

#ifndef __EPContainedTrackVisitor_h_
#define __EPContainedTrackVisitor_h_

//Edit Protocol Analyzer Base files
#include <EPTypedVisitor.h>
#include <EPTypedObjNode.h>

//Ax files
#include <AxTypes.h>

//AAF files
#include <AAFClassDefUIDs.h>

//STL files
#include <map>

//Not in the aafanalyzer namespace so the forward declaration must be made
//outside of the namespace.
class AxMob;

namespace aafanalyzer {

using namespace boost;

class DetailLevelTestResult;

class EPContainedTrackVisitor : public EPTypedVisitor
{

  public:

    EPContainedTrackVisitor( wostream& log, shared_ptr<EdgeMap> spEdgeMap );
    
    virtual ~EPContainedTrackVisitor();

    virtual bool PreOrderVisit( EPTypedObjNode<IAAFCompositionMob, EPTopLevelComposition>& node );
    virtual bool PreOrderVisit( EPTypedObjNode<IAAFCompositionMob, EPLowerLevelComposition>& node );
    virtual bool PreOrderVisit( EPTypedObjNode<IAAFCompositionMob, EPSubClipComposition>& node );
    virtual bool PreOrderVisit( EPTypedObjNode<IAAFCompositionMob, EPAdjustedClipComposition>& node );
    virtual bool PreOrderVisit( EPTypedObjNode<IAAFSourceMob, EPTapeSource>& node );
    virtual bool PreOrderVisit( EPTypedObjNode<IAAFSourceMob, EPFilmSource>& node );
    virtual bool PreOrderVisit( EPTypedObjNode<IAAFSourceMob, EPAuxiliarySource>& node );
    
    shared_ptr<DetailLevelTestResult> GetResult();
    
  private:

    typedef map<aafUInt32, aafUInt32> TrackNumberMap;
     
    wostream& _log;
    shared_ptr<EdgeMap> _spEdgeMap;
    shared_ptr<DetailLevelTestResult> _spResult;

    shared_ptr<TrackNumberMap> CountTrackCodes( shared_ptr<EPTypedVisitor::MobSlotSet> tracks, unsigned int& unnumberedTracks );

    template<typename SegmentTypeSP>
    unsigned int CountSegments( AxMobSlot& track );

    bool CheckPrimaryTimecodeTracks( shared_ptr<EPTypedVisitor::MobSlotSet> tracks, Node& node );

    // prohibited
    EPContainedTrackVisitor();
    EPContainedTrackVisitor( const EPContainedTrackVisitor& );
    EPContainedTrackVisitor& operator=( const EPContainedTrackVisitor& );
  
};

} // end of namespace diskstream

#endif /*__EPContainedTrackVisitor_h_*/