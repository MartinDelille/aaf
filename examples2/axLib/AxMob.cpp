//=---------------------------------------------------------------------=
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
// The Original Code of this file is Copyright 1998-2001, Licensor of the
// AAF Association.
// 
//=---------------------------------------------------------------------=

#include "AxMob.h"

#include "AxUtil.h"

//=---------------------------------------------------------------------=

AxMob::AxMob( IAAFMobSP spIaafMob )
: AxObject( AxQueryInterface<IAAFMob, IAAFObject>(
		   spIaafMob, IID_IAAFObject ) ),
	_spIaafMob( spIaafMob )
{}

AxMob::~AxMob()
{}

aafNumSlots_t AxMob::CountSlots()
{
	aafNumSlots_t numSlots;
	
	CHECK_HRESULT( _spIaafMob->CountSlots( &numSlots ) );

	return numSlots;
}


aafMobID_t AxMob::GetMobID()
{
	aafMobID_t id;

	CHECK_HRESULT( _spIaafMob->GetMobID( &id ) );

	return id;
}

AxString AxMob::GetName()
{
	// FIXME - This pattern appears in several places, it should be factored out.
	
	aafUInt32 sizeInBytes;

	CHECK_HRESULT( _spIaafMob->GetNameBufLen( &sizeInBytes ) );

	int sizeInChars = sizeInBytes/sizeof( aafCharacter ) + 1;

	array_ptr<aafCharacter> buf( new aafCharacter[ sizeInChars ] );

	CHECK_HRESULT( _spIaafMob->GetName( buf.get(), sizeInBytes ) );

	return AxString( buf.get() );
}

void AxMob::SetName( const AxString& name )
{
	CHECK_HRESULT( _spIaafMob->SetName( name.c_str() ) );
}

void AxMob::AppendComment( const AxString& category,
				  		   const AxString& comment )
{
	CHECK_HRESULT( _spIaafMob->AppendComment(
		const_cast<aafCharacter*>( category.c_str() ),
		comment.c_str() ) );
}

void AxMob::AppendKLVData( const IAAFKLVDataSP& spIaafKLVData )
{
	CHECK_HRESULT( _spIaafMob->AppendKLVData( spIaafKLVData ) );
}


IAAFTimelineMobSlotSP AxMob::AppendNewTimelineSlot(
	aafRational_t  editRate,
	IAAFSegmentSP spIaafSegment,
	aafSlotID_t  slotID,
	const AxString& slotName,
	aafPosition_t  origin )
{
	IAAFTimelineMobSlotSP spSlot;

	CHECK_HRESULT( _spIaafMob->AppendNewTimelineSlot( editRate,
							  spIaafSegment,
							  slotID,
							  slotName.c_str(),
							  origin,
							  &spSlot ) );

	return spSlot;
}

IEnumAAFMobSlotsSP AxMob::GetSlots()
{
	IEnumAAFMobSlotsSP spIEnumAAFMobSlots;

	CHECK_HRESULT( _spIaafMob->GetSlots( &spIEnumAAFMobSlots ) );

	return spIEnumAAFMobSlots;
}

//=---------------------------------------------------------------------=

AxSearchSource::AxSearchSource( IAAFSearchSourceSP spIaafSearchSource )
: _spIaafSearchSource( spIaafSearchSource )
{}

AxSearchSource::~AxSearchSource()
{}

//=---------------------------------------------------------------------=

AxMasterMob::AxMasterMob( IAAFMasterMobSP spIaafMasterMob )
:	AxMob( AxQueryInterface<IAAFMasterMob,IAAFMob>(
		  spIaafMasterMob, IID_IAAFMob ) ),
    AxSearchSource( AxQueryInterface<IAAFMasterMob, IAAFSearchSource>(
			spIaafMasterMob, IID_IAAFSearchSource ) ),
	_spIaafMasterMob( spIaafMasterMob )
{}


AxMasterMob::~AxMasterMob()
{}

void AxMasterMob::Initialize()
{
	CHECK_HRESULT( _spIaafMasterMob->Initialize() );
}

IAAFEssenceAccessSP AxMasterMob::CreateEssence(	aafSlotID_t  masterSlotID,
						IAAFDataDefSP pMediaKind,
						aafUID_constref  codecID,
						aafRational_t  editRate,
						aafRational_t  samplerate,
						aafCompressEnable_t  Enable,
						IAAFLocatorSP destination,
						aafUID_constref fileFormat )
{
	IAAFEssenceAccessSP spIaafEssenceAccess;

	CHECK_HRESULT( _spIaafMasterMob->CreateEssence( masterSlotID, pMediaKind, codecID,
							editRate, samplerate, Enable,
							destination, fileFormat,
							&spIaafEssenceAccess ) );

	return spIaafEssenceAccess;
}

//=---------------------------------------------------------------------=

AxMasterMobEx::AxMasterMobEx( IAAFMasterMobExSP spIaafMasterMobEx )
:	AxMasterMob( AxQueryInterface<IAAFMasterMobEx, IAAFMasterMob>(
			spIaafMasterMobEx, IID_IAAFMasterMob ) ),
	_spIaafMasterMobEx( spIaafMasterMobEx )
{}

AxMasterMobEx::~AxMasterMobEx()
{}

IAAFEssenceAccessSP AxMasterMobEx::ExtendEssence( aafSlotID_t  masterSlotID,
						  IAAFDataDefSP pMediaKind,
						  aafUID_constref  codecID,
						  aafRational_t  editRate,
						  aafRational_t  samplerate,
						  aafCompressEnable_t  Enable,
						  IAAFLocatorSP destination,
						  aafUID_constref fileFormat )
{
	IAAFEssenceAccessSP spIaafEssenceAccess;

	CHECK_HRESULT( _spIaafMasterMobEx->ExtendEssence( masterSlotID, pMediaKind, codecID,
							  editRate, samplerate, Enable,
							  destination, fileFormat,
							  &spIaafEssenceAccess ) );

	return spIaafEssenceAccess;
}
							 
//=---------------------------------------------------------------------=

IAAFEssenceAccessSP AxMasterMob::OpenEssence( aafSlotID_t		slotId,
					      aafMediaCriteria_t*	mediaCrit,	
					      aafMediaOpenMode_t	openMode,
					      aafCompressEnable_t	compEnable )
{
	IAAFEssenceAccessSP spIaafEssenceAccess;

	CHECK_HRESULT( _spIaafMasterMob->OpenEssence( slotId, mediaCrit,
						      openMode, compEnable,
						      &spIaafEssenceAccess ) );

	return spIaafEssenceAccess;
}


AxCompositionMob::AxCompositionMob( IAAFCompositionMobSP spIaafCompositionMob )
:	AxMob( AxQueryInterface<IAAFCompositionMob,IAAFMob>(
		  spIaafCompositionMob, IID_IAAFMob ) ),
 	_spIaafCompositionMob( spIaafCompositionMob )
{}

AxCompositionMob::~AxCompositionMob()
{}

//=---------------------------------------------------------------------=


AxSourceMob::AxSourceMob( IAAFSourceMobSP spIaafSourceMob )
:	AxMob( AxQueryInterface<IAAFSourceMob,IAAFMob>(
		  spIaafSourceMob, IID_IAAFMob ) ),
    AxSearchSource( AxQueryInterface<IAAFSourceMob, IAAFSearchSource>(
			spIaafSourceMob, IID_IAAFSearchSource ) ),
	_spIaafSourceMob( spIaafSourceMob )
{}

AxSourceMob::~AxSourceMob()
{}

IAAFEssenceDescriptorSP AxSourceMob::GetEssenceDescriptor()
{
	IAAFEssenceDescriptorSP spIaafEssenceDescriptor;

	CHECK_HRESULT( _spIaafSourceMob->GetEssenceDescriptor( &spIaafEssenceDescriptor ) );

	return spIaafEssenceDescriptor;
}


//=---------------------------------------------------------------------=