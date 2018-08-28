###############################################################################
#
# $Id$ $Name$
#
# The contents of this file are subject to the AAF SDK Public Source
# License Agreement Version 2.0 (the "License"); You may not use this
# file except in compliance with the License.  The License is available
# in AAFSDKPSL.TXT, or you may obtain a copy of the License from the
# Advanced Media Workflow Association, Inc., or its successor.
#
# Software distributed under the License is distributed on an "AS IS"
# basis, WITHOUT WARRANTY OF ANY KIND, either express or implied.  See
# the License for the specific language governing rights and limitations
# under the License.  Refer to Section 3.3 of the License for proper use
# of this Exhibit.
#
# WARNING:  Please contact the Advanced Media Workflow Association,
# Inc., for more information about any additional licenses to
# intellectual property covering the AAF Standard that may be required
# to create and distribute AAF compliant products.
# (http://www.amwa.tv/policies).
#
# Copyright Notices:
# The Original Code of this file is Copyright 1998-2009, licensor of the
# Advanced Media Workflow Association.  All rights reserved.
#
# The Initial Developer of the Original Code of this file and the
# licensor of the Advanced Media Workflow Association is
# Avid Technology.
# All rights reserved.
#
###############################################################################
AAFPERSISTENTOBJECTS=""

# These are all of the other non-persistent objects:
AAFNONPERSISTENTOBJECTS=""


# These are files which specify COM interfaces, but which are
# implemented in other objects.
AAFCOMINTERFACESONLY="\
	AAFFindSourceInfo2 \
	AAFMob3 \
	AAFSaveIntermediate \
	AAFSearchSource2 \
	AAFSearchSource3 \
	AAFPlainStreamData2 \
	AAFAES3PCMDescriptor2 \
	AAFCDCIDescriptor2 \
	AAFComponent2 \
	AAFCompositionMob2 \
	AAFDataDef2 \
	AAFDataDef3 \
	AAFDataDef4 \
	AAFDiagnosticOutput \
	AAFDictionary2 \
	AAFDigitalImageDescriptor2 \
	AAFEndian \
	AAFEssenceDataEx \
	AAFEssenceData2 \
	AAFEssenceDescriptor2 \
	AAFEssenceMultiAccess \
	AAFEventMobSlot2 \
	AAFFileDescriptor2 \
	AAFHeader2 \
	AAFHeader3 \
    AAFJPEG2000SubDescriptor2 \
	AAFKLVEssenceDataParameters \
	AAFKLVStreamParameters \
	AAFMasterMob2 \
	AAFMasterMob3 \
	AAFMasterMobEx \
	AAFMob2 \
	AAFProgress \
	AAFCopyByte \
	AAFRGBADescriptor2 \
	AAFSearchSource \
	AAFSourceReference2 \
	AAFStreamAccess \
	AAFTimelineMobSlot2 \
	AAFTypeDefStream2 \
	AAFTypeDefStreamEx \
	AAFTypeDefStream3 \
	AAFTypeDefVariableArrayEx "

# These are the impl files that are typed by humans.  Be sure to
# remove them from the other list.  As you check each one in, just add
# its name here and remove it from either list above where it occurs.
# Do not add the 'Impl'prefix here.
HUMAN_TYPED_IMPL="\
	AAFAES3PCMDescriptor \
	AAFAIFCDescriptor \
	AAFAsyncStreamRawStorage \
	AAFAudioChannelLabelSubDescriptor \
	AAFAuxiliaryDescriptor \
	AAFAVCSubDescriptor \
	AAFBWFImportDescriptor \
	AAFCDCIDescriptor \
	AAFCachePageAllocator \
	AAFClassDef \
	AAFCodecDef \
	AAFCommentMarker \
	AAFComponent \
	AAFCompositionMob \
	AAFConstantValue \
	AAFContainerDef \
	AAFContentStorage \
	AAFControlPoint \
	AAFDataDef \
	AAFDataEssenceDescriptor \
	AAFDefObject \
	AAFDescriptiveClip \
	AAFDescriptiveFramework \
	AAFDescriptiveMarker \
	AAFDescriptiveObject \
	AAFDictionary \
	AAFDigitalImageDescriptor \
	AAFEdgecode \
	AAFEssenceAccess \
	AAFEssenceData \
	AAFEssenceDescriptor \
	AAFEssenceFormat \
	AAFEssenceGroup \
	AAFEvent \
	AAFEventMobSlot \
	AAFFile \
	AAFFileDescriptor \
	AAFFileEncoding \
	AAFFiller \
	AAFFilmDescriptor \
	AAFFindSourceInfo \
	AAFGPITrigger \
	AAFGetFileBits \
    AAFGroupOfSoundfieldGroupsLabelSubDescriptor \
	AAFHeader \
	AAFIOCompletion \
	AAFIdentification \
	AAFImportDescriptor \
	AAFInterpolationDef \
	AAFJPEG2000SubDescriptor \
	AAFKLVData \
	AAFKLVDataDefinition \
	AAFLocator \
	AAFMasterMob \
	AAFMCALabelSubDescriptor \
	AAFMetaDefinition \
	AAFMob  \
	AAFMobSlot \
	AAFMPEG4VisualSubDescriptor \
	AAFMPEGAudioDescriptor \
	AAFMPEGVideoDescriptor \
	AAFMultipleDescriptor \
	AAFNestedScope\
	AAFNetworkLocator \
	AAFObject \
	AAFOperationDef \
	AAFOperationGroup \
	AAFPCMDescriptor \
	AAFParameter \
	AAFParameterDef \
	AAFPhysicalDescriptor \
	AAFPlainEssenceData \
	AAFPlainStreamData \
	AAFPluginDef \
	AAFPluginManager \
	AAFProperty \
	AAFPropertyDef \
	AAFPropertyValue \
	AAFPulldown \
	AAFRGBADescriptor \
	AAFRandomFile \
	AAFRandomRawStorage \
	AAFRawStorage \
	AAFRIFFChunk \
	AAFRecordingDescriptor \
	AAFScopeReference \
	AAFSegment \
	AAFSelector \
	AAFSequence \
	AAFSetFileBits \
	AAFSoundDescriptor \
    AAFSoundfieldGroupLabelSubDescriptor \
	AAFSourceClip \
	AAFSourceMob \
	AAFSourceReference \
	AAFStaticMobSlot \
	AAFStreamRawStorage \
	AAFSubDescriptor \
	AAFTIFFDescriptor \
	AAFTaggedValue \
	AAFTaggedValueDefinition \
	AAFTapeDescriptor \
	AAFTextLocator \
	AAFTimecode \
	AAFTimecodeStream \
	AAFTimecodeStream12M \
	AAFTimelineMobSlot \
	AAFTransition \
	AAFTypeDef \
	AAFTypeDefGenericCharacter \
	AAFTypeDefCharacter \
	AAFTypeDefEnum \
	AAFTypeDefExtEnum \
	AAFTypeDefFixedArray \
	AAFTypeDefIndirect \
	AAFTypeDefInt \
	AAFTypeDefObjectRef \
	AAFTypeDefOpaque \
	AAFTypeDefRecord \
	AAFTypeDefRename \
	AAFTypeDefSet \
	AAFTypeDefStream \
	AAFTypeDefString \
	AAFTypeDefStrongObjRef \
	AAFTypeDefVariableArray \
	AAFTypeDefWeakObjRef \
	AAFVaryingValue \
	AAFWAVEDescriptor \
	EnumAAFClassDefs \
	EnumAAFCodecDefs \
	EnumAAFCodecFlavours \
	EnumAAFComponents \
	EnumAAFContainerDefs \
	EnumAAFControlPoints \
	EnumAAFDataDefs \
	EnumAAFEssenceData \
	EnumAAFFileDescriptors \
	EnumAAFFileEncodings \
	EnumAAFIdentifications \
	EnumAAFInterpolationDefs \
	EnumAAFKLVData \
	EnumAAFKLVDataDefs \
	EnumAAFLoadedPlugins \
	EnumAAFLocators \
	EnumAAFMobSlots \
	EnumAAFMobs \
	EnumAAFOperationDefs \
	EnumAAFParameterDefs \
	EnumAAFParameters \
	EnumAAFPluginDefs \
	EnumAAFPluginLocators \
	EnumAAFProperties \
	EnumAAFPropertyDefs \
	EnumAAFPropertyValues \
	EnumAAFRIFFChunks \
	EnumAAFSegments \
	EnumAAFSubDescriptors \
	EnumAAFTaggedValueDefs \
	EnumAAFTaggedValues \
	EnumAAFTypeDefs "

# Defered interfaces
#	AAFIntraFrameMarker \

# The list of standard dodo targets.
# AAFTypes have to be handled separately since no object is to be created.
DODO_TARGET_NAMES="\
	${AAFPERSISTENTOBJECTS} \
	${AAFNONPERSISTENTOBJECTS} \
	${HUMAN_TYPED_IMPL} "

# Build the list of all public objects that need to be built into the COM DLL
AAFOBJECTS="\
	${AAFPERSISTENTOBJECTS} \
	${AAFNONPERSISTENTOBJECTS} \
	${HUMAN_TYPED_IMPL} "

# Build the list of all private objects that need to be built into the COM DLL
# These objects will 
PRIVATE_AAFOBJECTS="\
	AAFHTMLClip \
	AAFHTMLDescriptor \
	AAFMetaDictionary \
	AAFPropValData \
	AAFStreamPropertyValue \
	AAFStrongRefArrayValue \
	AAFStrongRefSetValue \
	AAFStrongRefValue \
	AAFTextClip \
	AAFWeakRefArrayValue \
	AAFWeakRefSetValue \
	AAFWeakRefValue \
	EnumAAFStorablePropVals "

# Build the list of all objects that have automatically-generated
# implementation classes.
AUTO_GEN_IMPL="\
	${AAFPERSISTENTOBJECTS} \
	${AAFNONPERSISTENTOBJECTS} "

#---------------------------------------------
# Build the list of all objects which are built into plugin.idl and
# NOT into AAF.idl.

PLUGIN_OBJECTS="\
	AAFClassExtension \
	AAFDictionaryExtension \
	AAFEssenceCodec \
	AAFEssenceCodec2 \
	AAFEssenceCodec3 \
	AAFEssenceContainer \
	AAFEssenceDataStream \
	AAFEssenceDataStream2 \
	AAFEssenceDataStreamEx \
	AAFEssenceStream \
	AAFInterpolator \
	AAFMultiEssenceCodec \
	AAFPlugin "

# objects in PLUGIN_OBJECTS are NOT built into the main interface IDL
#---------------------------------------------
