
/*
 *      Copyright (c) 2003, Philip de Nier (philipn@users.sourceforge.net)
 *
 *
 *      This file is part of aaf2dot.
 *
 *  aaf2dot is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation; either version 2.1 of the License, or
 *  (at your option) any later version.
 *
 *  aaf2dot is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with aaf2dot; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#pragma warning (disable:4786)

#include <AxMetaDef.h>
#include <AxMob.h>
#include <AAFTypeDefUIDs.h>

#include <iostream>
#include <sstream>
#include <assert.h>
#include <fstream>
using namespace std;

#include <AAFDotInstanceMapper.h>
#include <MapperSettings.h>
#include <Utilities.h>
#include <Logging.h>



//-----------------------------------------------------------------------------
PropertyValueStalker::PropertyValueStalker( string name ) 
   :	_name( name ),
	_reference( 0 ),
	_arrayIndex( 0 )
{
}


//-----------------------------------------------------------------------------
void
PropertyValueStalker::IncreaseArrayIndex()
{
   _arrayIndex++;
}


//-----------------------------------------------------------------------------
void
PropertyValueStalker::InitArrayIndex()
{
   _arrayIndex = 0;
}


//-----------------------------------------------------------------------------
void
PropertyValueStalker::CompleteReference( DotRecordNode *referencedNode )
{
   if ( _reference == 0 )
   {
      cerr << "Error: unexpected completion of reference on non-reference property." << endl;
      throw;
   }

   _reference->SetReference( referencedNode );
}


//-----------------------------------------------------------------------------
AAFDotInstanceMapper::AAFDotInstanceMapper( InstanceMapperProfile profile )
   : _profile( profile )
{
}


//-----------------------------------------------------------------------------
AAFDotInstanceMapper::~AAFDotInstanceMapper()
{
}


//-----------------------------------------------------------------------------
void 
AAFDotInstanceMapper::SetDotFactory( DotFactory *dotFactory )
{
   _dotFactory = dotFactory;
}


//-----------------------------------------------------------------------------
void 
AAFDotInstanceMapper::SetDotGraph( DotGraph *dotGraph )
{
   _dotGraph = dotGraph;
}


//-----------------------------------------------------------------------------
void
AAFDotInstanceMapper::MapAAFObject( AxObject axObject, bool &popStack )
{
   popStack = false;

   DotSubGraph *subGraph = 0;

   if ( FilterAAFObject( axObject, popStack ) )
   {
      return;
   }

   IAAFObjectSP spIAAFObject( axObject );
   IUnknownSP spIUnknown;
   AxQueryInterface( spIAAFObject, spIUnknown );
   IAAFMobSP spIaafMob;
   IAAFDictionarySP spIaafDictionary;

   if ( _profile.GetCluster() )
   {
      // if it is a mob, then create a sub graph for all elements below
      if ( AxIsA( spIUnknown, spIaafMob ) )
      {
	 string uid = _dotFactory->CreateSubGraphUID();
	 subGraph = _dotFactory->CreateSubGraph( "cluster" + uid, uid );
	 _dotGraph->AddSubGraph( subGraph );
      }
      else // inherit the parents subgraph
      {
	 Stalker *stalker1 = PopStalker();
	 Stalker *stalker2 = PopStalker();
			
	 PropertyValueStalker *pStalker = dynamic_cast< PropertyValueStalker* > ( stalker1 );
	 ObjectStalker *oStalker = dynamic_cast< ObjectStalker* > ( stalker2 );
	 if ( pStalker != 0 && oStalker != 0 )
	 {
	    subGraph = oStalker->GetSubGraph();
	 }
			
	 if ( stalker2 != 0 )
	 {
	    PushStalker( stalker2 );
	 }
	 if ( stalker1 != 0 )
	 {
	    PushStalker( stalker1 );
	 }
      }
   }

   string className  = AxStringToString( axObject.GetClassName() );
   DotRecordNode *node = _dotFactory->CreateRecordNode( className, 
							_dotFactory->CreateRecordNodeUID() );
   if ( subGraph == 0 )
   {
      _dotGraph->AddRecordNode( node );
   }
   else
   {
      subGraph->AddRecordNode( node );
   }


   // if object is a definition object, then record AUID for weak references
   IAAFDefObjectSP spIaafDefObject;
   if ( AxIsA( spIUnknown, spIaafDefObject ) )
   {
      AxQueryInterface( spIUnknown, spIaafDefObject );
		
      aafUID_t uid;
      CHECK_HRESULT( spIaafDefObject->GetAUID( &uid ) );
		
      node->AddID( DotThingID( "aafuid", UIDToString( uid ) ) );
   }

   // if it is a mob, the record the mob ID
   if ( AxIsA( spIUnknown, spIaafMob ) )
   {
      aafMobID_t mobID;
		
      CHECK_HRESULT( spIaafMob->GetMobID( &mobID ) );

      node->AddID( DotThingID( "mobid", MobIDToString( mobID ) ) );
   }

   // if it is a mob slot, the record the mob slot ID
   IAAFMobSlotSP spIaafMobSlot;
   if ( AxIsA( spIUnknown, spIaafMobSlot ) )
   {
      aafSlotID_t slotID;
		
      CHECK_HRESULT( spIaafMobSlot->GetSlotID( &slotID ) );

      ostringstream tmp;
      tmp << slotID;

      node->AddID( DotThingID( "mobslotid", tmp.str() ) );
   }

   // if it is a source reference, then create an association for the reference
   IAAFSourceReferenceSP spIaafSourceReference;
   if ( AxIsA( spIUnknown, spIaafSourceReference ) )
   {
      aafMobID_t mobID;
      CHECK_HRESULT( spIaafSourceReference->GetSourceID( &mobID ) );

      aafSlotID_t slotID;
      CHECK_HRESULT( spIaafSourceReference->GetSourceMobSlotID( &slotID ) );
      ostringstream slotIDStr;
      slotIDStr << slotID;


      DotEdge *edge = _dotFactory->CreateEdge( "source reference", _dotFactory->CreateEdgeUID() );
      edge->SetElementAttribute( "color", "orange" );
      edge->SetElementAttribute( "weight", _profile.GetSourceRefEdgeWeight() );
      DotEdgeEnd *sourceEdgeEnd = new DotEdgeEnd();
      sourceEdgeEnd->SetReference( node );
      edge->SetSource( sourceEdgeEnd );
      DotEdgeEnd *targetEdgeEnd = new DotEdgeEnd();
      // don't know reference yet
      targetEdgeEnd->SetMobIDReference( MobIDToString( mobID ) );
      targetEdgeEnd->SetMobSlotIDReference( slotIDStr.str() );
      edge->SetTarget( targetEdgeEnd );

      _dotGraph->AddEdge( edge ); // source references are always in the graph scope rather than subgraph
   }

   CompleteStrongReferences( node );

   ObjectStalker *stalker = new ObjectStalker( node, className );

   if ( _profile.GetCluster() )
   {
      stalker->SetSubGraph( subGraph );
   }


   PushStalker( stalker );
}


//-----------------------------------------------------------------------------
void 
AAFDotInstanceMapper::CompleteStrongReferences( DotRecordNode *referencedNode )
{
   if ( _stalkers.size() > 0 )
   {
      PropertyValueStalker *stalker = dynamic_cast< PropertyValueStalker* > ( PopStalker() );
		
      if ( stalker == 0 )
      {
	 cerr << "Error: Property value stalker expected." << endl;
	 throw;
      }
		
      stalker->CompleteReference( referencedNode );
		
      PushStalker( stalker );
   }
}


//-----------------------------------------------------------------------------
void 
AAFDotInstanceMapper::MapAAFProperty( AxProperty axProperty, bool &popStack )
{
   popStack = false;

   AxString name = axProperty.GetName();
   PropertyValueStalker *pStalker = new PropertyValueStalker( AxStringToString( name ) );

   MapKnownAAFRecordTypes( axProperty, popStack );
	
   PushStalker( pStalker );

}


//-----------------------------------------------------------------------------
void 
AAFDotInstanceMapper::MapKnownAAFRecordTypes( AxProperty axProperty, bool &popStack )
{
   string propertyName = AxStringToString( axProperty.GetName() );

   AxPropertyDef propertyDef( axProperty.GetDefinition() );
   AxTypeDef typeDef( propertyDef.GetTypeDef() );

   if ( typeDef.GetAUID() == kAAFTypeID_MobID )	// MobID
   {
      ObjectStalker *oStalker = dynamic_cast< ObjectStalker* > ( PopStalker() );
      if ( oStalker == 0 )
      {
	 cerr << "Error: Object stalker expected." << endl;
	 throw;
      }
		
      aafMobID_t mobID = GetMobID( axProperty.GetValue() ); 
      string mobIDStr = MobIDToString( mobID );
      DotRecordNodeAttribute attribute( propertyName, mobIDStr );

      oStalker->GetNode()->AddAttribute( attribute );
		
      PushStalker( oStalker );
		
      popStack = true;
   }
	
   if ( typeDef.GetAUID() == kAAFTypeID_AUID )	// AUID
   {
      ObjectStalker *oStalker = dynamic_cast< ObjectStalker* > ( PopStalker() );
      if ( oStalker == 0 )
      {
	 cerr << "Error: Object stalker expected." << endl;
	 throw;
      }
		
      aafUID_t uid = GetUID( axProperty.GetValue() ); 
      string uidStr = UIDToString( uid );
      DotRecordNodeAttribute attribute( propertyName, uidStr );

      oStalker->GetNode()->AddAttribute( attribute );
		
      PushStalker( oStalker );
		
      popStack = true;
   }
	
   if ( typeDef.GetAUID() == kAAFTypeID_DateStruct )	// Date
   {
      ObjectStalker *oStalker = dynamic_cast< ObjectStalker* > ( PopStalker() );
      if ( oStalker == 0 )
      {
	 cerr << "Error: Object stalker expected." << endl;
	 throw;
      }

      _aafDateStruct_t date = GetDate( axProperty.GetValue() );
      string dateStr = DateToString( date );
      DotRecordNodeAttribute attribute( propertyName, dateStr );

      oStalker->GetNode()->AddAttribute( attribute );
		
      PushStalker( oStalker );
		
      popStack = true;
   }
	
   if ( typeDef.GetAUID() == kAAFTypeID_TimeStruct )	// Time
   {
      ObjectStalker *oStalker = dynamic_cast< ObjectStalker* > ( PopStalker() );
      if ( oStalker == 0 )
      {
	 cerr << "Error: Object stalker expected." << endl;
	 throw;
      }

      _aafTimeStruct_t time = GetTime( axProperty.GetValue() );
      string timeStr = TimeToString( time );
      DotRecordNodeAttribute attribute( propertyName, timeStr );

      oStalker->GetNode()->AddAttribute( attribute );
		
      PushStalker( oStalker );
		
      popStack = true;
   }
	
   if ( typeDef.GetAUID() == kAAFTypeID_TimeStamp )	// TimeStamp
   {
      ObjectStalker *oStalker = dynamic_cast< ObjectStalker* > ( PopStalker() );
      if ( oStalker == 0 )
      {
	 cerr << "Error: Object stalker expected." << endl;
	 throw;
      }

      _aafTimeStamp_t timeStamp = GetTimeStamp( axProperty.GetValue() );
      string timeStampStr = TimeStampToString( timeStamp );
      DotRecordNodeAttribute attribute( propertyName, timeStampStr );

      oStalker->GetNode()->AddAttribute( attribute );
		
      PushStalker( oStalker );
		
      popStack = true;
   }

   if ( typeDef.GetAUID() == kAAFTypeID_VersionType )	// Version
   {
      ObjectStalker *oStalker = dynamic_cast< ObjectStalker* > ( PopStalker() );
      if ( oStalker == 0 )
      {
	 cerr << "Error: Object stalker expected." << endl;
	 throw;
      }

      string version = VersionToString( GetVersion( axProperty.GetValue() ) );
      DotRecordNodeAttribute attribute( propertyName, version );

      oStalker->GetNode()->AddAttribute( attribute );

      PushStalker( oStalker );
		
      popStack = true;
   }
	
   if ( typeDef.GetAUID() == kAAFTypeID_ProductVersion )	// Product Version
   {
      ObjectStalker *oStalker = dynamic_cast< ObjectStalker* > ( PopStalker() );
      if ( oStalker == 0 )
      {
	 cerr << "Error: Object stalker expected." << endl;
	 throw;
      }

      string productVersion = ProductVersionToString( GetProductVersion( axProperty.GetValue() ) );
      DotRecordNodeAttribute attribute( propertyName, productVersion );

      oStalker->GetNode()->AddAttribute( attribute );
		
      PushStalker( oStalker );
		
      popStack = true;
   }
	
}


//-----------------------------------------------------------------------------
void 
AAFDotInstanceMapper::MapAAFPropertyValue( AxPropertyValue axPropertyValue, bool &popStack )
{
   popStack = false;

   AxTypeDef axTypeDef( axPropertyValue.GetType() );

   if ( axTypeDef.GetTypeCategory() == kAAFTypeCatRename )
   {
      // iterator will take us to the base type, so skip this iteration level
   }
   else
   {
      if ( AxStringToString( axTypeDef.GetName() ).compare( "Rational" ) == 0 )
      {
	 popStack = true;

	 PropertyValueStalker *pStalker = dynamic_cast< PropertyValueStalker* > ( PopStalker() );
	 if ( pStalker == 0 )
	 {
	    cerr << "Error: Property value stalker expected." << endl;
	    throw;
	 }
	 ObjectStalker *oStalker = dynamic_cast< ObjectStalker* > ( PopStalker() );
	 if ( oStalker == 0 )
	 {
	    cerr << "Error: Object stalker expected." << endl;
	    throw;
	 }

			
	 AxTypeDefRecord axTypeDefRecord(
	    AxQueryInterface< IAAFTypeDef,IAAFTypeDefRecord > (
	       axTypeDef ) );
	 string numeratorValue;
	 string denominatorValue;
	 if ( AxStringToString( axTypeDefRecord.GetMemberName( 0 ) ).compare( "Numerator" ) == 0 )
	 {
	    IAAFPropertyValueSP propValue( axPropertyValue.GetValue() );
	    AxPropertyValue numerator( axTypeDefRecord.GetValue( propValue , 0 ) );
	    AxPropertyValue denominator( axTypeDefRecord.GetValue( propValue, 1 ) );

	    AxTypeDefInt numeratorIntType(
	       AxQueryInterface< IAAFTypeDef,IAAFTypeDefInt > (
		  numerator.GetType() ) );
	    AxTypeDefInt denominatorIntType(
	       AxQueryInterface< IAAFTypeDef,IAAFTypeDefInt > (
		  denominator.GetType() ) );
	    numeratorValue = GetIntValue( numeratorIntType, numerator, 
					  oStalker->GetName(), pStalker->GetName() );
	    denominatorValue = GetIntValue( denominatorIntType, denominator,
					    oStalker->GetName(), pStalker->GetName() );
	 }
	 else
	 {
	    IAAFPropertyValueSP propValue( axPropertyValue.GetValue() );
	    AxPropertyValue numerator( axTypeDefRecord.GetValue( propValue, 1 ) );
	    AxPropertyValue denominator( axTypeDefRecord.GetValue( propValue, 0 ) );

	    AxTypeDefInt numeratorIntType(
	       AxQueryInterface< IAAFTypeDef,IAAFTypeDefInt > (
		  numerator.GetType() ) );
	    AxTypeDefInt denominatorIntType(
	       AxQueryInterface< IAAFTypeDef,IAAFTypeDefInt > (
		  denominator.GetType() ) );
	    numeratorValue = GetIntValue( numeratorIntType, numerator,
					  oStalker->GetName(), pStalker->GetName() );
	    denominatorValue = GetIntValue( denominatorIntType, denominator,
					    oStalker->GetName(), pStalker->GetName() );
	 }

	 string value;
	 value.append( numeratorValue );
	 value.append( "/" );
	 value.append( denominatorValue );

			
	 DotRecordNodeAttribute attribute( pStalker->GetName(), value );
			
	 oStalker->GetNode()->AddAttribute( attribute );

	 PushStalker( oStalker );
	 PushStalker( pStalker );
      }

      else
      {
	 MapAAFPropertyValueGeneric( axTypeDef, axPropertyValue, popStack );
      }
   }
}


//-----------------------------------------------------------------------------
void 
AAFDotInstanceMapper::MapAAFPropertyValueGeneric( AxTypeDef &axTypeDef,
						  AxPropertyValue axPropertyValue, bool &popStack )
{
   popStack = false;

   IAAFPropertyValueSP propValue( axPropertyValue.GetValue() );

   if ( axTypeDef.GetTypeCategory() == kAAFTypeCatFixedArray )
   {
      AxTypeDefFixedArray axTypeDefFixedArray(
	 AxQueryInterface< IAAFTypeDef,IAAFTypeDefFixedArray > (
	    axTypeDef ) );
      AxTypeDef elementAxTypeDef( axTypeDefFixedArray.GetType() );
      if ( elementAxTypeDef.GetTypeCategory() != kAAFTypeCatStrongObjRef &&
	   elementAxTypeDef.GetTypeCategory() != kAAFTypeCatWeakObjRef )
      {
	 MapEmptyPropertyValue();
	 popStack = true;
      }
      else
      {
	 PropertyValueStalker *pStalker = dynamic_cast< PropertyValueStalker* > ( PopStalker() );
	 if ( pStalker == 0 )
	 {
	    cerr << "Error: Property value stalker expected." << endl;
	    throw;
	 }
	 pStalker->InitArrayIndex();
	 PushStalker( pStalker );
      }
   }

   else if ( axTypeDef.GetTypeCategory() == kAAFTypeCatVariableArray )
   {
      AxTypeDefVariableArray axTypeDefVariableArray(
	 AxQueryInterface< IAAFTypeDef,IAAFTypeDefVariableArray > (
	    axTypeDef ) );
      AxTypeDef elementAxTypeDef( axTypeDefVariableArray.GetType() );
      if ( elementAxTypeDef.GetTypeCategory() != kAAFTypeCatStrongObjRef &&
	   elementAxTypeDef.GetTypeCategory() != kAAFTypeCatWeakObjRef )
      {
	 MapEmptyPropertyValue();
	 popStack = true;
      }
      else
      {
	 PropertyValueStalker *pStalker = dynamic_cast< PropertyValueStalker* > ( PopStalker() );
	 if ( pStalker == 0 )
	 {
	    cerr << "Error: Property value stalker expected." << endl;
	    throw;
	 }
	 pStalker->InitArrayIndex();
	 PushStalker( pStalker );
      }
   }

   else if ( axTypeDef.GetTypeCategory() == kAAFTypeCatSet )
   {
      AxTypeDefSet axTypeDefSet(
	 AxQueryInterface< IAAFTypeDef,IAAFTypeDefSet > (
	    axTypeDef ) );
      AxTypeDef elementAxTypeDef( axTypeDefSet.GetElementType() );
      if ( elementAxTypeDef.GetTypeCategory() != kAAFTypeCatStrongObjRef &&
	   elementAxTypeDef.GetTypeCategory() != kAAFTypeCatWeakObjRef )
      {
	 MapEmptyPropertyValue();
	 popStack = true;
      }
   }

   else if ( axTypeDef.GetTypeCategory() == kAAFTypeCatString)
   {
      PropertyValueStalker *pStalker = dynamic_cast< PropertyValueStalker* > ( PopStalker() );
      if ( pStalker == 0 )
      {
	 cerr << "Error: Property value stalker expected." << endl;
	 throw;
      }
      ObjectStalker *oStalker = dynamic_cast< ObjectStalker* > ( PopStalker() );
      if ( oStalker == 0 )
      {
	 cerr << "Error: Object stalker expected." << endl;
	 throw;
      }

      AxTypeDefString axTypeDefString(
	 AxQueryInterface< IAAFTypeDef,IAAFTypeDefString > (
	    axTypeDef ) );
      AxString value = axTypeDefString.GetElements( propValue );
      DotRecordNodeAttribute attribute( pStalker->GetName(), AxStringToString( value ) );

      oStalker->GetNode()->AddAttribute( attribute );

      PushStalker( oStalker );
      PushStalker( pStalker );
   }


   else if ( axTypeDef.GetTypeCategory() == kAAFTypeCatInt)
   {
      PropertyValueStalker *pStalker = dynamic_cast< PropertyValueStalker* > ( PopStalker() );
      if ( pStalker == 0 )
      {
	 cerr << "Error: Property value stalker expected." << endl;
	 throw;
      }
      ObjectStalker *oStalker = dynamic_cast< ObjectStalker* > ( PopStalker() );
      if ( oStalker == 0 )
      {
	 cerr << "Error: Object stalker expected." << endl;
	 throw;
      }

      AxTypeDefInt axTypeDefInt(
	 AxQueryInterface< IAAFTypeDef,IAAFTypeDefInt > (
	    axTypeDef ) );
      string value = GetIntValue( axTypeDefInt, axPropertyValue,
				  oStalker->GetName(), pStalker->GetName() );
      DotRecordNodeAttribute attribute( pStalker->GetName(), value );

      oStalker->GetNode()->AddAttribute( attribute );


      PushStalker( oStalker );
      PushStalker( pStalker );
   }

   else if ( axTypeDef.GetTypeCategory() == kAAFTypeCatEnum)
   {
      PropertyValueStalker *pStalker = dynamic_cast< PropertyValueStalker* > ( PopStalker() );
      if ( pStalker == 0 )
      {
	 cerr << "Error: Property value stalker expected." << endl;
	 throw;
      }
      ObjectStalker *oStalker = dynamic_cast< ObjectStalker* > ( PopStalker() );
      if ( oStalker == 0 )
      {
	 cerr << "Error: Object stalker expected." << endl;
	 throw;
      }

      AxTypeDefEnum axTypeDefEnum(
	 AxQueryInterface< IAAFTypeDef,IAAFTypeDefEnum > (
	    axTypeDef ) );
      string value = AxStringToString( axTypeDefEnum.GetNameFromValue( propValue ) );
      DotRecordNodeAttribute attribute( pStalker->GetName(), value );

      oStalker->GetNode()->AddAttribute( attribute );


      PushStalker( oStalker );
      PushStalker( pStalker );
   }

   else if ( axTypeDef.GetTypeCategory() == kAAFTypeCatStrongObjRef )
   { 
      PropertyValueStalker *pStalker = dynamic_cast< PropertyValueStalker* > ( PopStalker() );
      if ( pStalker == 0 )
      {
	 cerr << "Error: Property value stalker expected." << endl;
	 throw;
      }
      ObjectStalker *oStalker = dynamic_cast< ObjectStalker* > ( PopStalker() );
      if ( oStalker == 0 )
      {
	 cerr << "Error: Object stalker expected." << endl;
	 throw;
      }

      pStalker->IncreaseArrayIndex();


      DotEdge *edge = _dotFactory->CreateEdge( pStalker->GetName(), _dotFactory->CreateEdgeUID() );
      edge->SetElementAttribute( "weight", _profile.GetStrongRefEdgeWeight() );
      if ( pStalker->GetArrayIndex() > 0 )
      {
	 ostringstream sstr;
	 sstr << pStalker->GetArrayIndex();
	 edge->SetElementAttribute( "label", sstr.str() );
      }
      DotEdgeEnd *sourceEdgeEnd = new DotEdgeEnd();
      sourceEdgeEnd->SetReference( oStalker->GetNode() );
      edge->SetSource( sourceEdgeEnd );
      DotEdgeEnd *targetEdgeEnd = new DotEdgeEnd();
      // don't know reference yet
      edge->SetTarget( targetEdgeEnd );
      // set the reference in the pstalker so that it will be resolved later
      pStalker->SetReference( targetEdgeEnd );

      if ( _profile.GetCluster() && oStalker->HasSubGraph() )
      {
	 oStalker->GetSubGraph()->AddEdge( edge );
      }
      else
      {
	 _dotGraph->AddEdge( edge );
      }

      PushStalker( oStalker );
      PushStalker( pStalker );
   }

   else if ( axTypeDef.GetTypeCategory() == kAAFTypeCatWeakObjRef )
   { 
      PropertyValueStalker *pStalker = dynamic_cast< PropertyValueStalker* > ( PopStalker() );
      if ( pStalker == 0 )
      {
	 cerr << "Error: Property value stalker expected." << endl;
	 throw;
      }
      ObjectStalker *oStalker = dynamic_cast< ObjectStalker* > ( PopStalker() );
      if ( oStalker == 0 )
      {
	 cerr << "Error: Object stalker expected." << endl;
	 throw;
      }

      pStalker->IncreaseArrayIndex();


      DotEdge *edge = _dotFactory->CreateEdge( pStalker->GetName(), _dotFactory->CreateEdgeUID() );
      edge->SetElementAttribute( "color", "blue" );
      edge->SetElementAttribute( "weight", _profile.GetWeakRefEdgeWeight() );
      if ( pStalker->GetArrayIndex() > 0 )
      {
	 ostringstream sstr;
	 sstr << pStalker->GetArrayIndex();
	 edge->SetElementAttribute( "label", sstr.str() );
      }
      DotEdgeEnd *sourceEdgeEnd = new DotEdgeEnd();
      sourceEdgeEnd->SetReference( oStalker->GetNode() );
      edge->SetSource( sourceEdgeEnd );
      DotEdgeEnd *targetEdgeEnd = new DotEdgeEnd();
      // don't know reference yet
      edge->SetTarget( targetEdgeEnd );

      AxTypeDefWeakObjRef axTypeDefWeakObjRef(
	 AxQueryInterface< IAAFTypeDef,IAAFTypeDefWeakObjRef > (
	    axPropertyValue.GetType() ) );

      bool abort = false;
      IUnknownSP spIUnknown;
      try
      {
	 spIUnknown = axTypeDefWeakObjRef.GetObject( propValue, IID_IAAFObject );
      }
      catch (...)
      {
	 Logging::DebugLogStream() << "Note: Unknown weak reference type encountered. Probably a meta definition reference." << endl;
	 _dotFactory->RemoveDotElement( edge );
	 abort = true;
      }

      if ( !abort )
      {
	 IAAFDefObjectSP spIaafDefObject;
	 if ( AxIsA( spIUnknown, spIaafDefObject ) )
	 {
	    IAAFDataDefSP spIaafDataDef;
	    if ( _profile.GetDataDefs() || !AxIsA( spIUnknown, spIaafDataDef ) )
	    {
	       AxQueryInterface( spIUnknown, spIaafDefObject );
					
	       aafUID_t uid;
	       CHECK_HRESULT( spIaafDefObject->GetAUID( &uid ) );
					
	       targetEdgeEnd->SetAAFUIDReference( UIDToString( uid ) );
	    }
	    else
	    {
	       Logging::DebugLogStream() << "Note: Data definition object reference not exported." << endl;
	       _dotFactory->RemoveDotElement( edge );
	       abort = true;
	    }
	 }
	 else
	 {
	    // not implemented
	    assert( false );
	 }
      }

      if ( !abort )
      {
	 _dotGraph->AddEdge( edge );
      }

      PushStalker( oStalker );
      PushStalker( pStalker );
   }

   else
   {
      MapEmptyPropertyValue();
      popStack = true;
   }

}


//-----------------------------------------------------------------------------
void
AAFDotInstanceMapper::MapEmptyPropertyValue()
{
   PropertyValueStalker *pStalker = dynamic_cast< PropertyValueStalker* > ( PopStalker() );
   if ( pStalker == 0 )
   {
      cerr << "Error: Property value stalker expected." << endl;
      throw;
   }
   ObjectStalker *oStalker = dynamic_cast< ObjectStalker* > ( PopStalker() );
   if ( oStalker == 0 )
   {
      cerr << "Error: Object stalker expected." << endl;
      throw;
   }

   DotRecordNodeAttribute attribute( pStalker->GetName(), "?" );
   DotRecordNode *node = oStalker->GetNode();
   node->AddAttribute( attribute );

   PushStalker( oStalker );
   PushStalker( pStalker );
}


//-----------------------------------------------------------------------------
string
AAFDotInstanceMapper::GetIntValue( AxTypeDefInt &axTypeDefInt, AxPropertyValue axPropertyValue,
				   string objectName, string propertyName )
{
   bool fault = false;
   IAAFPropertyValueSP propValue( axPropertyValue.GetValue() );
   string value;
   if ( axTypeDefInt.IsSigned() ) {
      switch ( axTypeDefInt.GetSize() ) {
	 case sizeof( aafInt8 ) :
	 { 
	    aafInt8 i;
	    axTypeDefInt.GetInteger( propValue, &i );
	    ostringstream ostrs;
	    if ( DisplayHex( objectName, propertyName ) )
	    {
	       ostrs << hex << "0x" << (int)i;
	    }
	    else
	    {
	       ostrs << dec << (int)i;
	    }
	    value = ostrs.str();
	    break;
	 }
	 case sizeof( aafInt16 ) :
	 { 
	    aafInt16 i;
	    axTypeDefInt.GetInteger( propValue, &i );
	    ostringstream ostrs;
	    if ( DisplayHex( objectName, propertyName ) )
	    {
	       ostrs << hex << "0x" << i;
	    }
	    else
	    {
	       ostrs << dec << i;
	    }
	    value = ostrs.str();
	    break;
	 }
	 case sizeof( aafInt32 ) :
	 { 
	    aafInt32 i;
	    axTypeDefInt.GetInteger( propValue, &i );
	    ostringstream ostrs;
	    if ( DisplayHex( objectName, propertyName ) )
	    {
	       ostrs << hex << "0x" << i;
	    }
	    else
	    {
	       ostrs << dec << i;
	    }
	    value = ostrs.str();
	    break;
	 }
	 case sizeof( aafInt64 ) :
	 { 
	    aafInt64 i;
	    axTypeDefInt.GetInteger( propValue, &i );
	    ostringstream ostrs;
	    if ( DisplayHex( objectName, propertyName ) )
	    {
	       ostrs << hex << "0x" << (long int)i;
	    }
	    else
	    {
	       ostrs << dec << (long int)i;
	    }
	    value = ostrs.str();
	    break;
	 }
	 default:
	    fault = true;
      }
   }
   else {
      switch ( axTypeDefInt.GetSize() ) {
	 case sizeof( aafUInt8 ) :
	 { 
	    aafUInt8 i;
	    axTypeDefInt.GetInteger( propValue, &i );
	    ostringstream ostrs;
	    if ( DisplayHex( objectName, propertyName ) )
	    {
	       ostrs << hex << "0x" << (int)i;
	    }
	    else
	    {
	       ostrs << dec << (int)i;
	    }
	    value = ostrs.str();
	    break;
	 }
	 case sizeof( aafUInt16 ) :
	 { 
	    aafUInt16 i;
	    axTypeDefInt.GetInteger( propValue, &i );
	    ostringstream ostrs;
	    if ( DisplayHex( objectName, propertyName ) )
	    {
	       ostrs << hex << "0x" << i;
	    }
	    else
	    {
	       ostrs << dec << i;
	    }
	    value = ostrs.str();
	    break;
	 }
	 case sizeof( aafUInt32 ) :
	 { 
	    aafUInt32 i;
	    axTypeDefInt.GetInteger( propValue, &i );
	    ostringstream ostrs;
	    if ( DisplayHex( objectName, propertyName ) )
	    {
	       ostrs << hex << "0x" << i;
	    }
	    else
	    {
	       ostrs << dec << i;
	    }
	    value = ostrs.str();
	    break;
	 }
	 case sizeof( aafUInt64 ) :
	 { 
	    aafUInt64 i;
	    axTypeDefInt.GetInteger( propValue, &i );
	    ostringstream ostrs;
	    if ( DisplayHex( objectName, propertyName ) )
	    {
	       ostrs << hex << "0x" << (long int)i;
	    }
	    else
	    {
	       ostrs << dec << (long int)i;
	    }
	    value = ostrs.str();
	    break;
	 }
	 default:
	    fault = true;
      }
   }
	
   if ( fault ) 
   {
      throw;
   }

   return value;
}


//-----------------------------------------------------------------------------
bool
AAFDotInstanceMapper::FilterAAFObject( AxObject axObject, bool &popStack )
{
   if ( !_profile.GetDictionary() )
   {
      IAAFObjectSP spIAAFObject( axObject );
      IUnknownSP spIUnknown;
      AxQueryInterface( spIAAFObject, spIUnknown );
      IAAFDictionarySP spIaafDictionary;
      if ( AxIsA( spIUnknown, spIaafDictionary ) )
      {
	 ObjectStalker *dummy = new ObjectStalker( 0, "" );
	 PushStalker( dummy );
	 popStack = true;
	 Logging::DebugLogStream() << "Note: Dictionary object not exported." << endl;
	 return true;
      }
   }
   if ( !_profile.GetTaggedValues() )
   {
      IAAFObjectSP spIAAFObject( axObject );
      IUnknownSP spIUnknown;
      AxQueryInterface( spIAAFObject, spIUnknown );
      IAAFTaggedValueSP spIaafTaggedValue;
      if ( AxIsA( spIUnknown, spIaafTaggedValue ) )
      {
	 ObjectStalker *dummy = new ObjectStalker( 0, "" );
	 PushStalker( dummy );
	 popStack = true;
	 Logging::DebugLogStream() << "Note: Tagged value object not exported." << endl;
	 return true;
      }
   }

   if ( !_profile.GetKLVData() )
   {
      IAAFObjectSP spIAAFObject( axObject );
      IUnknownSP spIUnknown;
      AxQueryInterface( spIAAFObject, spIUnknown );
      IAAFKLVDataSP spIaafKLVData;
      if ( AxIsA( spIUnknown, spIaafKLVData ) )
      {
	 ObjectStalker *dummy = new ObjectStalker( 0, "" );
	 PushStalker( dummy );
	 popStack = true;
	 Logging::DebugLogStream() << "Note: KLV data object not exported." << endl;
	 return true;
      }
   }

   if ( !_profile.GetEssenceData() )
   {
      IAAFObjectSP spIAAFObject( axObject );
      IUnknownSP spIUnknown;
      AxQueryInterface( spIAAFObject, spIUnknown );
      IAAFEssenceDataSP spIaafEssenceData;
      if ( AxIsA( spIUnknown, spIaafEssenceData ) )
      {
	 ObjectStalker *dummy = new ObjectStalker( 0, "" );
	 PushStalker( dummy );
	 popStack = true;
	 Logging::DebugLogStream() << "Note: Essence data object not exported." << endl;
	 return true;
      }
   }

   return false;
}


//-----------------------------------------------------------------------------
Stalker* 
AAFDotInstanceMapper::PopStalker()
{
   if ( _stalkers.size() == 0 )
   {
      return 0;
   }
   StalkerStack::iterator iter;
   iter = _stalkers.begin();
   Stalker *ret = *iter;
   _stalkers.pop_front();
   return ret;
}


//-----------------------------------------------------------------------------
void
AAFDotInstanceMapper::PushStalker( Stalker *stalker )
{
   _stalkers.push_front( stalker );
}


//-----------------------------------------------------------------------------
void
AAFDotInstanceMapper::ObjectPop()
{
   Stalker *stalker = PopStalker();
   if ( stalker != 0 )
   {
      if ( dynamic_cast< ObjectStalker* > ( stalker ) == 0 )
      {
	 cerr << "Error: Object stalker expected. (ObjectPop)" << endl;
	 throw;
      }
      delete stalker;
   }
}


//-----------------------------------------------------------------------------
void
AAFDotInstanceMapper::PropertyPop()
{
   Stalker *stalker = PopStalker();
   if ( stalker != 0 )
   {
      if ( dynamic_cast< PropertyValueStalker* > ( stalker ) == 0 )
      {
	 cerr << "Error: Property value stalker expected. (PropertyPop) " << endl;
	 throw;
      }
      delete stalker;
   }

}

