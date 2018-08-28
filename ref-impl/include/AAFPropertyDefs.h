#ifndef __AAFPropertyDefs_h__
#define __AAFPropertyDefs_h__

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
// The Original Code of this file is Copyright 1998-2009, licensor of the
// Advanced Media Workflow Association.  All rights reserved.
//
// The Initial Developer of the Original Code of this file and the
// licensor of the Advanced Media Workflow Association is
// Avid Technology.
// All rights reserved.
//
//=---------------------------------------------------------------------=


#include "AAFTypes.h"

// AAF property definition UIDs.
//

//{06010104-0101-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.01.01.00.00
const aafUID_t kAAFPropID_InterchangeObject_ObjClass =
{0x06010104, 0x0101, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05200701-0800-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.07.01.08.00.00.00
const aafUID_t kAAFPropID_InterchangeObject_Generation =
{0x05200701, 0x0800, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04070100-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.07.01.00.00.00.00.00
const aafUID_t kAAFPropID_Component_DataDefinition =
{0x04070100, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{07020201-0103-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.07.02.02.01.01.03.00.00
const aafUID_t kAAFPropID_Component_Length =
{0x07020201, 0x0103, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03010210-0400-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.01.02.10.04.00.00.00
const aafUID_t kAAFPropID_Component_KLVData =
{0x03010210, 0x0400, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03020102-1600-0000-060e-2b3401010107}
//06.0e.2b.34.01.01.01.07.03.02.01.02.16.00.00.00
const aafUID_t kAAFPropID_Component_UserComments =
{0x03020102, 0x1600, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x07}};

//{03010210-0800-0000-060e-2b3401010107}
//06.0e.2b.34.01.01.01.07.03.01.02.10.08.00.00.00
const aafUID_t kAAFPropID_Component_Attributes =
{0x03010210, 0x0800, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x07}};

//{01040901-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.01.04.09.01.00.00.00.00
const aafUID_t kAAFPropID_EdgeCode_Start =
{0x01040901, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04100103-0109-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.10.01.03.01.09.00.00
const aafUID_t kAAFPropID_EdgeCode_FilmKind =
{0x04100103, 0x0109, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04100103-0102-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.10.01.03.01.02.00.00
const aafUID_t kAAFPropID_EdgeCode_CodeFormat =
{0x04100103, 0x0102, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{01030201-0200-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.01.03.02.01.02.00.00.00
const aafUID_t kAAFPropID_EdgeCode_Header =
{0x01030201, 0x0200, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0601-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.06.01.00.00
const aafUID_t kAAFPropID_EssenceGroup_Choices =
{0x06010104, 0x0601, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0208-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.02.08.00.00
const aafUID_t kAAFPropID_EssenceGroup_StillFrame =
{0x06010104, 0x0208, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{07020103-0303-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.07.02.01.03.03.03.00.00
const aafUID_t kAAFPropID_Event_Position =
{0x07020103, 0x0303, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05300404-0100-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.30.04.04.01.00.00.00
const aafUID_t kAAFPropID_Event_Comment =
{0x05300404, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05300401-0000-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.05.30.04.01.00.00.00.00
const aafUID_t kAAFPropID_GPITrigger_ActiveState =
{0x05300401, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{06010104-020a-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.02.0a.00.00
const aafUID_t kAAFPropID_CommentMarker_Annotation =
{0x06010104, 0x020a, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05300506-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.30.05.06.00.00.00.00
const aafUID_t kAAFPropID_OperationGroup_Operation =
{0x05300506, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0602-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.06.02.00.00
const aafUID_t kAAFPropID_OperationGroup_InputSegments =
{0x06010104, 0x0602, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-060a-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.06.0a.00.00
const aafUID_t kAAFPropID_OperationGroup_Parameters =
{0x06010104, 0x060a, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{0530050c-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.30.05.0c.00.00.00.00
const aafUID_t kAAFPropID_OperationGroup_BypassOverride =
{0x0530050c, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0206-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.02.06.00.00
const aafUID_t kAAFPropID_OperationGroup_Rendering =
{0x06010104, 0x0206, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0607-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.06.07.00.00
const aafUID_t kAAFPropID_NestedScope_Slots =
{0x06010104, 0x0607, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0207-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.02.07.00.00
const aafUID_t kAAFPropID_Pulldown_InputSegment =
{0x06010104, 0x0207, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05401001-0200-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.40.10.01.02.00.00.00
const aafUID_t kAAFPropID_Pulldown_PulldownKind =
{0x05401001, 0x0200, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05401001-0100-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.40.10.01.01.00.00.00
const aafUID_t kAAFPropID_Pulldown_PulldownDirection =
{0x05401001, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05401001-0300-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.40.10.01.03.00.00.00
const aafUID_t kAAFPropID_Pulldown_PhaseFrame =
{0x05401001, 0x0300, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010103-0300-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.03.03.00.00.00
const aafUID_t kAAFPropID_ScopeReference_RelativeScope =
{0x06010103, 0x0300, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010103-0400-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.03.04.00.00.00
const aafUID_t kAAFPropID_ScopeReference_RelativeSlot =
{0x06010103, 0x0400, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0209-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.02.09.00.00
const aafUID_t kAAFPropID_Selector_Selected =
{0x06010104, 0x0209, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0608-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.06.08.00.00
const aafUID_t kAAFPropID_Selector_Alternates =
{0x06010104, 0x0608, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0609-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.06.09.00.00
const aafUID_t kAAFPropID_Sequence_Components =
{0x06010104, 0x0609, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010103-0100-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.03.01.00.00.00
const aafUID_t kAAFPropID_SourceReference_SourceID =
{0x06010103, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010103-0200-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.03.02.00.00.00
const aafUID_t kAAFPropID_SourceReference_SourceMobSlotID =
{0x06010103, 0x0200, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010103-0700-0000-060e-2b3401010107}
//06.0e.2b.34.01.01.01.07.06.01.01.03.07.00.00.00
const aafUID_t kAAFPropID_SourceReference_ChannelIDs =
{0x06010103, 0x0700, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x07}};

//{06010103-0800-0000-060e-2b3401010108}
//06.0e.2b.34.01.01.01.08.06.01.01.03.08.00.00.00
const aafUID_t kAAFPropID_SourceReference_MonoSourceSlotIDs =
{0x06010103, 0x0800, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x08}};

//{07020103-0104-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.07.02.01.03.01.04.00.00
const aafUID_t kAAFPropID_SourceClip_StartTime =
{0x07020103, 0x0104, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{07020201-0105-0200-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.07.02.02.01.01.05.02.00
const aafUID_t kAAFPropID_SourceClip_FadeInLength =
{0x07020201, 0x0105, 0x0200, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05300501-0000-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.05.30.05.01.00.00.00.00
const aafUID_t kAAFPropID_SourceClip_FadeInType =
{0x05300501, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{07020201-0105-0300-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.07.02.02.01.01.05.03.00
const aafUID_t kAAFPropID_SourceClip_FadeOutLength =
{0x07020201, 0x0105, 0x0300, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05300502-0000-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.05.30.05.02.00.00.00.00
const aafUID_t kAAFPropID_SourceClip_FadeOutType =
{0x05300502, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{05300601-0100-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.30.06.01.01.00.00.00
const aafUID_t kAAFPropID_HTMLClip_BeginAnchor =
{0x05300601, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05300602-0100-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.30.06.02.01.00.00.00
const aafUID_t kAAFPropID_HTMLClip_EndAnchor =
{0x05300602, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{07020103-0105-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.07.02.01.03.01.05.00.00
const aafUID_t kAAFPropID_Timecode_Start =
{0x07020103, 0x0105, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04040101-0206-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.04.01.01.02.06.00.00
const aafUID_t kAAFPropID_Timecode_FPS =
{0x04040101, 0x0206, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04040101-0500-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.04.01.01.05.00.00.00
const aafUID_t kAAFPropID_Timecode_Drop =
{0x04040101, 0x0500, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{04040101-0201-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.04.01.01.02.01.00.00
const aafUID_t kAAFPropID_TimecodeStream_SampleRate =
{0x04040101, 0x0201, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04070300-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.07.03.00.00.00.00.00
const aafUID_t kAAFPropID_TimecodeStream_Source =
{0x04070300, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04040201-0000-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.04.02.01.00.00.00.00
const aafUID_t kAAFPropID_TimecodeStream_SourceType =
{0x04040201, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{04040101-0400-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.04.01.01.04.00.00.00
const aafUID_t kAAFPropID_TimecodeStream12M_IncludeSync =
{0x04040101, 0x0400, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{06010104-0205-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.02.05.00.00
const aafUID_t kAAFPropID_Transition_OperationGroup =
{0x06010104, 0x0205, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{07020103-0106-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.07.02.01.03.01.06.00.00
const aafUID_t kAAFPropID_Transition_CutPoint =
{0x07020103, 0x0106, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0501-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.05.01.00.00
const aafUID_t kAAFPropID_ContentStorage_Mobs =
{0x06010104, 0x0501, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0502-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.05.02.00.00
const aafUID_t kAAFPropID_ContentStorage_EssenceData =
{0x06010104, 0x0502, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{0530050d-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.30.05.0d.00.00.00.00
const aafUID_t kAAFPropID_ControlPoint_Value =
{0x0530050d, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{07020103-1002-0100-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.07.02.01.03.10.02.01.00
const aafUID_t kAAFPropID_ControlPoint_Time =
{0x07020103, 0x1002, 0x0100, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05300508-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.30.05.08.00.00.00.00
const aafUID_t kAAFPropID_ControlPoint_EditHint =
{0x05300508, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{01011503-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.01.01.15.03.00.00.00.00
const aafUID_t kAAFPropID_DefinitionObject_Identification =
{0x01011503, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{01070102-0301-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.01.07.01.02.03.01.00.00
const aafUID_t kAAFPropID_DefinitionObject_Name =
{0x01070102, 0x0301, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03020301-0201-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.02.03.01.02.01.00.00
const aafUID_t kAAFPropID_DefinitionObject_Description =
{0x03020301, 0x0201, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05300509-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.30.05.09.00.00.00.00
const aafUID_t kAAFPropID_OperationDefinition_DataDefinition =
{0x05300509, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05300503-0000-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.05.30.05.03.00.00.00.00
const aafUID_t kAAFPropID_OperationDefinition_IsTimeWarp =
{0x05300503, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{06010104-0401-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.04.01.00.00
const aafUID_t kAAFPropID_OperationDefinition_DegradeTo =
{0x06010104, 0x0401, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{0530050a-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.30.05.0a.00.00.00.00
const aafUID_t kAAFPropID_OperationDefinition_OperationCategory =
{0x0530050a, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05300504-0000-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.05.30.05.04.00.00.00.00
const aafUID_t kAAFPropID_OperationDefinition_NumberInputs =
{0x05300504, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{05300505-0000-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.05.30.05.05.00.00.00.00
const aafUID_t kAAFPropID_OperationDefinition_Bypass =
{0x05300505, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{06010104-0302-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.03.02.00.00
const aafUID_t kAAFPropID_OperationDefinition_ParametersDefined =
{0x06010104, 0x0302, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0106-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.01.06.00.00
const aafUID_t kAAFPropID_ParameterDefinition_Type =
{0x06010104, 0x0106, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{0530050b-0100-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.30.05.0b.01.00.00.00
const aafUID_t kAAFPropID_ParameterDefinition_DisplayUnits =
{0x0530050b, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05200901-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.09.01.00.00.00.00
const aafUID_t kAAFPropID_PluginDefinition_PluginCategory =
{0x05200901, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03030301-0300-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.03.03.01.03.00.00.00
const aafUID_t kAAFPropID_PluginDefinition_VersionNumber =
{0x03030301, 0x0300, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03030301-0201-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.03.03.01.02.01.00.00
const aafUID_t kAAFPropID_PluginDefinition_VersionString =
{0x03030301, 0x0201, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{010a0101-0101-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.01.0a.01.01.01.01.00.00
const aafUID_t kAAFPropID_PluginDefinition_Manufacturer =
{0x010a0101, 0x0101, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-020b-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.02.0b.00.00
const aafUID_t kAAFPropID_PluginDefinition_ManufacturerInfo =
{0x06010104, 0x020b, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{010a0101-0300-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.01.0a.01.01.03.00.00.00
const aafUID_t kAAFPropID_PluginDefinition_ManufacturerID =
{0x010a0101, 0x0300, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05200902-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.09.02.00.00.00.00
const aafUID_t kAAFPropID_PluginDefinition_Platform =
{0x05200902, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05200903-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.09.03.00.00.00.00
const aafUID_t kAAFPropID_PluginDefinition_MinPlatformVersion =
{0x05200903, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05200904-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.09.04.00.00.00.00
const aafUID_t kAAFPropID_PluginDefinition_MaxPlatformVersion =
{0x05200904, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05200905-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.09.05.00.00.00.00
const aafUID_t kAAFPropID_PluginDefinition_Engine =
{0x05200905, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05200906-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.09.06.00.00.00.00
const aafUID_t kAAFPropID_PluginDefinition_MinEngineVersion =
{0x05200906, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05200907-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.09.07.00.00.00.00
const aafUID_t kAAFPropID_PluginDefinition_MaxEngineVersion =
{0x05200907, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05200908-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.09.08.00.00.00.00
const aafUID_t kAAFPropID_PluginDefinition_PluginAPI =
{0x05200908, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05200909-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.09.09.00.00.00.00
const aafUID_t kAAFPropID_PluginDefinition_MinPluginAPI =
{0x05200909, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{0520090a-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.09.0a.00.00.00.00
const aafUID_t kAAFPropID_PluginDefinition_MaxPluginAPI =
{0x0520090a, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{0520090b-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.09.0b.00.00.00.00
const aafUID_t kAAFPropID_PluginDefinition_SoftwareOnly =
{0x0520090b, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{0520090c-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.09.0c.00.00.00.00
const aafUID_t kAAFPropID_PluginDefinition_Accelerator =
{0x0520090c, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{0520090d-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.09.0d.00.00.00.00
const aafUID_t kAAFPropID_PluginDefinition_Locators =
{0x0520090d, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{0520090e-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.09.0e.00.00.00.00
const aafUID_t kAAFPropID_PluginDefinition_Authentication =
{0x0520090e, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{0520090f-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.09.0f.00.00.00.00
const aafUID_t kAAFPropID_PluginDefinition_DefinitionObject =
{0x0520090f, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0107-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.01.07.00.00
const aafUID_t kAAFPropID_CodecDefinition_FileDescriptorClass =
{0x06010104, 0x0107, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0301-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.03.01.00.00
const aafUID_t kAAFPropID_CodecDefinition_DataDefinitions =
{0x06010104, 0x0301, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03010201-0300-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.03.01.02.01.03.00.00.00
const aafUID_t kAAFPropID_ContainerDefinition_EssenceIsIdentified =
{0x03010201, 0x0300, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{06010104-0503-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.05.03.00.00
const aafUID_t kAAFPropID_Dictionary_OperationDefinitions =
{0x06010104, 0x0503, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0504-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.05.04.00.00
const aafUID_t kAAFPropID_Dictionary_ParameterDefinitions =
{0x06010104, 0x0504, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0505-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.05.05.00.00
const aafUID_t kAAFPropID_Dictionary_DataDefinitions =
{0x06010104, 0x0505, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0506-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.05.06.00.00
const aafUID_t kAAFPropID_Dictionary_PluginDefinitions =
{0x06010104, 0x0506, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0507-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.05.07.00.00
const aafUID_t kAAFPropID_Dictionary_CodecDefinitions =
{0x06010104, 0x0507, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0508-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.05.08.00.00
const aafUID_t kAAFPropID_Dictionary_ContainerDefinitions =
{0x06010104, 0x0508, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0509-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.05.09.00.00
const aafUID_t kAAFPropID_Dictionary_InterpolationDefinitions =
{0x06010104, 0x0509, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-050a-0000-060e-2b3401010107}
//06.0e.2b.34.01.01.01.07.06.01.01.04.05.0a.00.00
const aafUID_t kAAFPropID_Dictionary_KLVDataDefinitions =
{0x06010104, 0x050a, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x07}};

//{06010104-050b-0000-060e-2b3401010107}
//06.0e.2b.34.01.01.01.07.06.01.01.04.05.0b.00.00
const aafUID_t kAAFPropID_Dictionary_TaggedValueDefinitions =
{0x06010104, 0x050b, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x07}};

//{06010106-0100-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.06.01.00.00.00
const aafUID_t kAAFPropID_EssenceData_MobID =
{0x06010106, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04070200-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.07.02.00.00.00.00.00
const aafUID_t kAAFPropID_EssenceData_Data =
{0x04070200, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010102-0100-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.02.01.00.00.00
const aafUID_t kAAFPropID_EssenceData_SampleIndex =
{0x06010102, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0603-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.06.03.00.00
const aafUID_t kAAFPropID_EssenceDescriptor_Locator =
{0x06010104, 0x0603, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0610-0000-060e-2b3401010109}
//06.0e.2b.34.01.01.01.09.06.01.01.04.06.10.00.00
const aafUID_t kAAFPropID_EssenceDescriptor_SubDescriptors =
{0x06010104, 0x0610, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x09}};

//{04060101-0000-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.06.01.01.00.00.00.00
const aafUID_t kAAFPropID_FileDescriptor_SampleRate =
{0x04060101, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{04060102-0000-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.06.01.02.00.00.00.00
const aafUID_t kAAFPropID_FileDescriptor_Length =
{0x04060102, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{06010104-0102-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.01.02.00.00
const aafUID_t kAAFPropID_FileDescriptor_ContainerFormat =
{0x06010104, 0x0102, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0103-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.01.03.00.00
const aafUID_t kAAFPropID_FileDescriptor_CodecDefinition =
{0x06010104, 0x0103, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010103-0500-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.06.01.01.03.05.00.00.00
const aafUID_t kAAFPropID_FileDescriptor_LinkedSlotID =
{0x06010103, 0x0500, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{03030302-0200-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.03.03.02.02.00.00.00
const aafUID_t kAAFPropID_AIFCDescriptor_Summary =
{0x03030302, 0x0200, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04010601-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.01.06.01.00.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_Compression =
{0x04010601, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04010502-0100-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.01.05.02.01.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_StoredHeight =
{0x04010502, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{04010502-0200-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.01.05.02.02.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_StoredWidth =
{0x04010502, 0x0200, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{04010501-0700-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.01.05.01.07.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_SampledHeight =
{0x04010501, 0x0700, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{04010501-0800-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.01.05.01.08.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_SampledWidth =
{0x04010501, 0x0800, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{04010501-0900-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.01.05.01.09.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_SampledXOffset =
{0x04010501, 0x0900, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{04010501-0a00-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.01.05.01.0a.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_SampledYOffset =
{0x04010501, 0x0a00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{04010501-0b00-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.01.05.01.0b.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_DisplayHeight =
{0x04010501, 0x0b00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{04010501-0c00-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.01.05.01.0c.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_DisplayWidth =
{0x04010501, 0x0c00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{04010501-0d00-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.01.05.01.0d.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_DisplayXOffset =
{0x04010501, 0x0d00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{04010501-0e00-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.01.05.01.0e.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_DisplayYOffset =
{0x04010501, 0x0e00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{04010301-0400-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.01.03.01.04.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_FrameLayout =
{0x04010301, 0x0400, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{04010302-0500-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.01.03.02.05.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_VideoLineMap =
{0x04010302, 0x0500, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04010101-0100-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.01.01.01.01.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_ImageAspectRatio =
{0x04010101, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{05200102-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.01.02.00.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_AlphaTransparency =
{0x05200102, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04010201-0101-0200-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.01.02.01.01.01.02.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_TransferCharacteristic =
{0x04010201, 0x0101, 0x0200, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04010201-0106-0100-060e-2b3401010109}
//06.0e.2b.34.01.01.01.09.04.01.02.01.01.06.01.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_ColorPrimaries =
{0x04010201, 0x0106, 0x0100, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x09}};

//{04010201-0103-0100-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.01.02.01.01.03.01.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_CodingEquations =
{0x04010201, 0x0103, 0x0100, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04180101-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.18.01.01.00.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_ImageAlignmentFactor =
{0x04180101, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04010301-0600-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.01.03.01.06.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_FieldDominance =
{0x04010301, 0x0600, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04180102-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.18.01.02.00.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_FieldStartOffset =
{0x04180102, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04180103-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.18.01.03.00.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_FieldEndOffset =
{0x04180103, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04050113-0000-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.05.01.13.00.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_SignalStandard =
{0x04050113, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04010302-0800-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.01.03.02.08.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_StoredF2Offset =
{0x04010302, 0x0800, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04010302-0700-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.01.03.02.07.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_DisplayF2Offset =
{0x04010302, 0x0700, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04010302-0900-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.01.03.02.09.00.00.00
const aafUID_t kAAFPropID_DigitalImageDescriptor_ActiveFormatDescriptor =
{0x04010302, 0x0900, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04010503-0a00-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.01.05.03.0a.00.00.00
const aafUID_t kAAFPropID_CDCIDescriptor_ComponentWidth =
{0x04010503, 0x0a00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04010501-0500-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.01.05.01.05.00.00.00
const aafUID_t kAAFPropID_CDCIDescriptor_HorizontalSubsampling =
{0x04010501, 0x0500, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{04010501-0600-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.01.05.01.06.00.00.00
const aafUID_t kAAFPropID_CDCIDescriptor_ColorSiting =
{0x04010501, 0x0600, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{04010503-0300-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.01.05.03.03.00.00.00
const aafUID_t kAAFPropID_CDCIDescriptor_BlackReferenceLevel =
{0x04010503, 0x0300, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{04010503-0400-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.01.05.03.04.00.00.00
const aafUID_t kAAFPropID_CDCIDescriptor_WhiteReferenceLevel =
{0x04010503, 0x0400, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{04010503-0500-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.01.05.03.05.00.00.00
const aafUID_t kAAFPropID_CDCIDescriptor_ColorRange =
{0x04010503, 0x0500, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04180104-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.18.01.04.00.00.00.00
const aafUID_t kAAFPropID_CDCIDescriptor_PaddingBits =
{0x04180104, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04010501-1000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.01.05.01.10.00.00.00
const aafUID_t kAAFPropID_CDCIDescriptor_VerticalSubsampling =
{0x04010501, 0x1000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04010503-0700-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.01.05.03.07.00.00.00
const aafUID_t kAAFPropID_CDCIDescriptor_AlphaSamplingWidth =
{0x04010503, 0x0700, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03010201-0a00-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.03.01.02.01.0a.00.00.00
const aafUID_t kAAFPropID_CDCIDescriptor_ReversedByteOrder =
{0x03010201, 0x0a00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04010503-0600-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.01.05.03.06.00.00.00
const aafUID_t kAAFPropID_RGBADescriptor_PixelLayout =
{0x04010503, 0x0600, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04010503-0800-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.01.05.03.08.00.00.00
const aafUID_t kAAFPropID_RGBADescriptor_Palette =
{0x04010503, 0x0800, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04010503-0900-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.01.05.03.09.00.00.00
const aafUID_t kAAFPropID_RGBADescriptor_PaletteLayout =
{0x04010503, 0x0900, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04010404-0100-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.01.04.04.01.00.00.00
const aafUID_t kAAFPropID_RGBADescriptor_ScanningDirection =
{0x04010404, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04010503-0b00-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.01.05.03.0b.00.00.00
const aafUID_t kAAFPropID_RGBADescriptor_ComponentMaxRef =
{0x04010503, 0x0b00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04010503-0c00-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.01.05.03.0c.00.00.00
const aafUID_t kAAFPropID_RGBADescriptor_ComponentMinRef =
{0x04010503, 0x0c00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04010503-0d00-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.01.05.03.0d.00.00.00
const aafUID_t kAAFPropID_RGBADescriptor_AlphaMaxRef =
{0x04010503, 0x0d00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04010503-0e00-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.01.05.03.0e.00.00.00
const aafUID_t kAAFPropID_RGBADescriptor_AlphaMinRef =
{0x04010503, 0x0e00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{05020103-0101-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.02.01.03.01.01.00.00
const aafUID_t kAAFPropID_TIFFDescriptor_IsUniform =
{0x05020103, 0x0101, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06080201-0000-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.06.08.02.01.00.00.00.00
const aafUID_t kAAFPropID_TIFFDescriptor_IsContiguous =
{0x06080201, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{04010302-0300-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.01.03.02.03.00.00.00
const aafUID_t kAAFPropID_TIFFDescriptor_LeadingLines =
{0x04010302, 0x0300, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{04010302-0400-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.01.03.02.04.00.00.00
const aafUID_t kAAFPropID_TIFFDescriptor_TrailingLines =
{0x04010302, 0x0400, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{05020103-0102-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.02.01.03.01.02.00.00
const aafUID_t kAAFPropID_TIFFDescriptor_JPEGTableID =
{0x05020103, 0x0102, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03030302-0300-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.03.03.02.03.00.00.00
const aafUID_t kAAFPropID_TIFFDescriptor_Summary =
{0x03030302, 0x0300, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03030302-0100-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.03.03.02.01.00.00.00
const aafUID_t kAAFPropID_WAVEDescriptor_Summary =
{0x03030302, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04100103-0108-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.10.01.03.01.08.00.00
const aafUID_t kAAFPropID_FilmDescriptor_FilmFormat =
{0x04100103, 0x0108, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04010802-0300-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.01.08.02.03.00.00.00
const aafUID_t kAAFPropID_FilmDescriptor_FrameRate =
{0x04010802, 0x0300, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04100103-0103-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.10.01.03.01.03.00.00
const aafUID_t kAAFPropID_FilmDescriptor_PerforationsPerFrame =
{0x04100103, 0x0103, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04100103-0203-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.10.01.03.02.03.00.00
const aafUID_t kAAFPropID_FilmDescriptor_FilmAspectRatio =
{0x04100103, 0x0203, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04100103-0106-0100-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.10.01.03.01.06.01.00
const aafUID_t kAAFPropID_FilmDescriptor_Manufacturer =
{0x04100103, 0x0106, 0x0100, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04100103-0105-0100-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.10.01.03.01.05.01.00
const aafUID_t kAAFPropID_FilmDescriptor_Model =
{0x04100103, 0x0105, 0x0100, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04100103-0104-0100-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.10.01.03.01.04.01.00
const aafUID_t kAAFPropID_FilmDescriptor_FilmGaugeFormat =
{0x04100103, 0x0104, 0x0100, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04100103-0107-0100-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.10.01.03.01.07.01.00
const aafUID_t kAAFPropID_FilmDescriptor_FilmBatchNumber =
{0x04100103, 0x0107, 0x0100, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04100101-0101-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.10.01.01.01.01.00.00
const aafUID_t kAAFPropID_TapeDescriptor_FormFactor =
{0x04100101, 0x0101, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04010401-0100-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.01.04.01.01.00.00.00
const aafUID_t kAAFPropID_TapeDescriptor_VideoSignal =
{0x04010401, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{0d010101-0101-0100-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.0d.01.01.01.01.01.01.00
const aafUID_t kAAFPropID_TapeDescriptor_TapeFormat =
{0x0d010101, 0x0101, 0x0100, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04100101-0300-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.10.01.01.03.00.00.00
const aafUID_t kAAFPropID_TapeDescriptor_Length =
{0x04100101, 0x0300, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04100101-0401-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.10.01.01.04.01.00.00
const aafUID_t kAAFPropID_TapeDescriptor_ManufacturerID =
{0x04100101, 0x0401, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04100101-0201-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.10.01.01.02.01.00.00
const aafUID_t kAAFPropID_TapeDescriptor_Model =
{0x04100101, 0x0201, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04100101-0601-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.10.01.01.06.01.00.00
const aafUID_t kAAFPropID_TapeDescriptor_TapeBatchNumber =
{0x04100101, 0x0601, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04100101-0501-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.10.01.01.05.01.00.00
const aafUID_t kAAFPropID_TapeDescriptor_TapeStock =
{0x04100101, 0x0501, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03010201-0200-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.03.01.02.01.02.00.00.00
const aafUID_t kAAFPropID_Header_ByteOrder =
{0x03010201, 0x0200, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{07020110-0204-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.07.02.01.10.02.04.00.00
const aafUID_t kAAFPropID_Header_LastModified =
{0x07020110, 0x0204, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0201-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.02.01.00.00
const aafUID_t kAAFPropID_Header_Content =
{0x06010104, 0x0201, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0202-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.02.02.00.00
const aafUID_t kAAFPropID_Header_Dictionary =
{0x06010104, 0x0202, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03010201-0500-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.01.02.01.05.00.00.00
const aafUID_t kAAFPropID_Header_Version =
{0x03010201, 0x0500, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0604-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.06.04.00.00
const aafUID_t kAAFPropID_Header_IdentificationList =
{0x06010104, 0x0604, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03010201-0400-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.01.02.01.04.00.00.00
const aafUID_t kAAFPropID_Header_ObjectModelVersion =
{0x03010201, 0x0400, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0108-0000-060e-2b3401010104}
//06.0e.2b.34.01.01.01.04.06.01.01.04.01.08.00.00
const aafUID_t kAAFPropID_Header_PrimaryMob =
{0x06010104, 0x0108, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x04}};

//{01020203-0000-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.01.02.02.03.00.00.00.00
const aafUID_t kAAFPropID_Header_OperationalPattern =
{0x01020203, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{01020210-0201-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.01.02.02.10.02.01.00.00
const aafUID_t kAAFPropID_Header_EssenceContainers =
{0x01020210, 0x0201, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{01020210-0202-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.01.02.02.10.02.02.00.00
const aafUID_t kAAFPropID_Header_DescriptiveSchemes =
{0x01020210, 0x0202, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{05200701-0201-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.07.01.02.01.00.00
const aafUID_t kAAFPropID_Identification_CompanyName =
{0x05200701, 0x0201, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05200701-0301-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.07.01.03.01.00.00
const aafUID_t kAAFPropID_Identification_ProductName =
{0x05200701, 0x0301, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05200701-0400-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.07.01.04.00.00.00
const aafUID_t kAAFPropID_Identification_ProductVersion =
{0x05200701, 0x0400, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05200701-0501-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.07.01.05.01.00.00
const aafUID_t kAAFPropID_Identification_ProductVersionString =
{0x05200701, 0x0501, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05200701-0700-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.07.01.07.00.00.00
const aafUID_t kAAFPropID_Identification_ProductID =
{0x05200701, 0x0700, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{07020110-0203-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.07.02.01.10.02.03.00.00
const aafUID_t kAAFPropID_Identification_Date =
{0x07020110, 0x0203, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05200701-0a00-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.07.01.0a.00.00.00
const aafUID_t kAAFPropID_Identification_ToolkitVersion =
{0x05200701, 0x0a00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05200701-0601-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.07.01.06.01.00.00
const aafUID_t kAAFPropID_Identification_Platform =
{0x05200701, 0x0601, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05200701-0100-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.20.07.01.01.00.00.00
const aafUID_t kAAFPropID_Identification_GenerationAUID =
{0x05200701, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{01020101-0100-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.01.02.01.01.01.00.00.00
const aafUID_t kAAFPropID_NetworkLocator_URLString =
{0x01020101, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{01040102-0100-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.01.04.01.02.01.00.00.00
const aafUID_t kAAFPropID_TextLocator_Name =
{0x01040102, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{01011510-0000-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.01.01.15.10.00.00.00.00
const aafUID_t kAAFPropID_Mob_MobID =
{0x01011510, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{01030302-0100-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.01.03.03.02.01.00.00.00
const aafUID_t kAAFPropID_Mob_Name =
{0x01030302, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{06010104-0605-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.06.05.00.00
const aafUID_t kAAFPropID_Mob_Slots =
{0x06010104, 0x0605, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{07020110-0205-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.07.02.01.10.02.05.00.00
const aafUID_t kAAFPropID_Mob_LastModified =
{0x07020110, 0x0205, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{07020110-0103-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.07.02.01.10.01.03.00.00
const aafUID_t kAAFPropID_Mob_CreationTime =
{0x07020110, 0x0103, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03020102-0c00-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.02.01.02.0c.00.00.00
const aafUID_t kAAFPropID_Mob_UserComments =
{0x03020102, 0x0c00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03010210-0300-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.01.02.10.03.00.00.00
const aafUID_t kAAFPropID_Mob_KLVData =
{0x03010210, 0x0300, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03010210-0700-0000-060e-2b3401010107}
//06.0e.2b.34.01.01.01.07.03.01.02.10.07.00.00.00
const aafUID_t kAAFPropID_Mob_Attributes =
{0x03010210, 0x0700, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x07}};

//{05010108-0000-0000-060e-2b3401010107}
//06.0e.2b.34.01.01.01.07.05.01.01.08.00.00.00.00
const aafUID_t kAAFPropID_Mob_UsageCode =
{0x05010108, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x07}};

//{07020201-0105-0100-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.07.02.02.01.01.05.01.00
const aafUID_t kAAFPropID_CompositionMob_DefaultFadeLength =
{0x07020201, 0x0105, 0x0100, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05300201-0000-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.05.30.02.01.00.00.00.00
const aafUID_t kAAFPropID_CompositionMob_DefFadeType =
{0x05300201, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{05300403-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.30.04.03.00.00.00.00
const aafUID_t kAAFPropID_CompositionMob_DefFadeEditUnit =
{0x05300403, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-010a-0000-060e-2b3401010108}
//06.0e.2b.34.01.01.01.08.06.01.01.04.01.0a.00.00
const aafUID_t kAAFPropID_CompositionMob_Rendering =
{0x06010104, 0x010a, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x08}};

//{06010104-0203-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.02.03.00.00
const aafUID_t kAAFPropID_SourceMob_EssenceDescription =
{0x06010104, 0x0203, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{01070101-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.01.07.01.01.00.00.00.00
const aafUID_t kAAFPropID_MobSlot_SlotID =
{0x01070101, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{01070102-0100-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.01.07.01.02.01.00.00.00
const aafUID_t kAAFPropID_MobSlot_SlotName =
{0x01070102, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0204-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.02.04.00.00
const aafUID_t kAAFPropID_MobSlot_Segment =
{0x06010104, 0x0204, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{01040103-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.01.04.01.03.00.00.00.00
const aafUID_t kAAFPropID_MobSlot_PhysicalTrackNumber =
{0x01040103, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05300402-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.30.04.02.00.00.00.00
const aafUID_t kAAFPropID_EventMobSlot_EditRate =
{0x05300402, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{07020103-010b-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.07.02.01.03.01.0b.00.00
const aafUID_t kAAFPropID_EventMobSlot_EventSlotOrigin =
{0x07020103, 0x010b, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{05300405-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.30.04.05.00.00.00.00
const aafUID_t kAAFPropID_TimelineMobSlot_EditRate =
{0x05300405, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{07020103-0103-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.07.02.01.03.01.03.00.00
const aafUID_t kAAFPropID_TimelineMobSlot_Origin =
{0x07020103, 0x0103, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{07020103-010c-0000-060e-2b3401010107}
//06.0e.2b.34.01.01.01.07.07.02.01.03.01.0c.00.00
const aafUID_t kAAFPropID_TimelineMobSlot_MarkIn =
{0x07020103, 0x010c, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x07}};

//{07020103-0203-0000-060e-2b3401010107}
//06.0e.2b.34.01.01.01.07.07.02.01.03.02.03.00.00
const aafUID_t kAAFPropID_TimelineMobSlot_MarkOut =
{0x07020103, 0x0203, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x07}};

//{07020103-010d-0000-060e-2b3401010107}
//06.0e.2b.34.01.01.01.07.07.02.01.03.01.0d.00.00
const aafUID_t kAAFPropID_TimelineMobSlot_UserPos =
{0x07020103, 0x010d, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x07}};

//{06010104-0104-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.01.04.00.00
const aafUID_t kAAFPropID_Parameter_Definition =
{0x06010104, 0x0104, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{05300507-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.05.30.05.07.00.00.00.00
const aafUID_t kAAFPropID_ConstantValue_Value =
{0x05300507, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0105-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.01.05.00.00
const aafUID_t kAAFPropID_VaryingValue_Interpolation =
{0x06010104, 0x0105, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010104-0606-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.04.06.06.00.00
const aafUID_t kAAFPropID_VaryingValue_PointList =
{0x06010104, 0x0606, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03020102-0901-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.02.01.02.09.01.00.00
const aafUID_t kAAFPropID_TaggedValue_Name =
{0x03020102, 0x0901, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03020102-0a01-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.02.01.02.0a.01.00.00
const aafUID_t kAAFPropID_TaggedValue_Value =
{0x03020102, 0x0a01, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03010210-0200-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.01.02.10.02.00.00.00
const aafUID_t kAAFPropID_KLVData_Value =
{0x03010210, 0x0200, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{01070105-0000-0000-060e-2b3401010104}
//06.0e.2b.34.01.01.01.04.01.07.01.05.00.00.00.00
const aafUID_t kAAFPropID_DescriptiveMarker_DescribedSlots =
{0x01070105, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x04}};

//{06010104-020c-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.06.01.01.04.02.0c.00.00
const aafUID_t kAAFPropID_DescriptiveMarker_Description =
{0x06010104, 0x020c, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020301-0101-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.03.01.01.01.00.00
const aafUID_t kAAFPropID_SoundDescriptor_AudioSamplingRate =
{0x04020301, 0x0101, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020301-0400-0000-060e-2b3401010104}
//06.0e.2b.34.01.01.01.04.04.02.03.01.04.00.00.00
const aafUID_t kAAFPropID_SoundDescriptor_Locked =
{0x04020301, 0x0400, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x04}};

//{04020101-0300-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.02.01.01.03.00.00.00
const aafUID_t kAAFPropID_SoundDescriptor_AudioRefLevel =
{0x04020101, 0x0300, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{04020101-0100-0000-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.04.02.01.01.01.00.00.00
const aafUID_t kAAFPropID_SoundDescriptor_ElectroSpatial =
{0x04020101, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{04020101-0400-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.01.01.04.00.00.00
const aafUID_t kAAFPropID_SoundDescriptor_Channels =
{0x04020101, 0x0400, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020303-0400-0000-060e-2b3401010104}
//06.0e.2b.34.01.01.01.04.04.02.03.03.04.00.00.00
const aafUID_t kAAFPropID_SoundDescriptor_QuantizationBits =
{0x04020303, 0x0400, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x04}};

//{04020701-0000-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.07.01.00.00.00.00
const aafUID_t kAAFPropID_SoundDescriptor_DialNorm =
{0x04020701, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020402-0000-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.04.02.04.02.00.00.00.00
const aafUID_t kAAFPropID_SoundDescriptor_Compression =
{0x04020402, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04030302-0000-0000-060e-2b3401010103}
//06.0e.2b.34.01.01.01.03.04.03.03.02.00.00.00.00
const aafUID_t kAAFPropID_DataEssenceDescriptor_DataEssenceCoding =
{0x04030302, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x03}};

//{06010104-060b-0000-060e-2b3401010104}
//06.0e.2b.34.01.01.01.04.06.01.01.04.06.0b.00.00
const aafUID_t kAAFPropID_MultipleDescriptor_FileDescriptors =
{0x06010104, 0x060b, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x04}};

//{01070106-0000-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.01.07.01.06.00.00.00.00
const aafUID_t kAAFPropID_DescriptiveClip_DescribedSlotIDs =
{0x01070106, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020501-0600-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.05.01.06.00.00.00
const aafUID_t kAAFPropID_AES3PCMDescriptor_Emphasis =
{0x04020501, 0x0600, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020302-0300-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.03.02.03.00.00.00
const aafUID_t kAAFPropID_AES3PCMDescriptor_BlockStartOffset =
{0x04020302, 0x0300, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020501-0100-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.05.01.01.00.00.00
const aafUID_t kAAFPropID_AES3PCMDescriptor_AuxBitsMode =
{0x04020501, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020501-0200-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.05.01.02.00.00.00
const aafUID_t kAAFPropID_AES3PCMDescriptor_ChannelStatusMode =
{0x04020501, 0x0200, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020501-0300-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.05.01.03.00.00.00
const aafUID_t kAAFPropID_AES3PCMDescriptor_FixedChannelStatusData =
{0x04020501, 0x0300, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020501-0400-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.05.01.04.00.00.00
const aafUID_t kAAFPropID_AES3PCMDescriptor_UserDataMode =
{0x04020501, 0x0400, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020501-0500-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.05.01.05.00.00.00
const aafUID_t kAAFPropID_AES3PCMDescriptor_FixedUserData =
{0x04020501, 0x0500, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020302-0100-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.03.02.01.00.00.00
const aafUID_t kAAFPropID_PCMDescriptor_BlockAlign =
{0x04020302, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020302-0200-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.03.02.02.00.00.00
const aafUID_t kAAFPropID_PCMDescriptor_SequenceOffset =
{0x04020302, 0x0200, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020303-0500-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.03.03.05.00.00.00
const aafUID_t kAAFPropID_PCMDescriptor_AverageBPS =
{0x04020303, 0x0500, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020101-0500-0000-060e-2b3401010107}
//06.0e.2b.34.01.01.01.07.04.02.01.01.05.00.00.00
const aafUID_t kAAFPropID_PCMDescriptor_ChannelAssignment =
{0x04020101, 0x0500, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x07}};

//{04020301-0600-0000-060e-2b3401010108}
//06.0e.2b.34.01.01.01.08.04.02.03.01.06.00.00.00
const aafUID_t kAAFPropID_PCMDescriptor_PeakEnvelopeVersion =
{0x04020301, 0x0600, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x08}};

//{04020301-0700-0000-060e-2b3401010108}
//06.0e.2b.34.01.01.01.08.04.02.03.01.07.00.00.00
const aafUID_t kAAFPropID_PCMDescriptor_PeakEnvelopeFormat =
{0x04020301, 0x0700, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x08}};

//{04020301-0800-0000-060e-2b3401010108}
//06.0e.2b.34.01.01.01.08.04.02.03.01.08.00.00.00
const aafUID_t kAAFPropID_PCMDescriptor_PointsPerPeakValue =
{0x04020301, 0x0800, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x08}};

//{04020301-0900-0000-060e-2b3401010108}
//06.0e.2b.34.01.01.01.08.04.02.03.01.09.00.00.00
const aafUID_t kAAFPropID_PCMDescriptor_PeakEnvelopeBlockSize =
{0x04020301, 0x0900, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x08}};

//{04020301-0a00-0000-060e-2b3401010108}
//06.0e.2b.34.01.01.01.08.04.02.03.01.0a.00.00.00
const aafUID_t kAAFPropID_PCMDescriptor_PeakChannels =
{0x04020301, 0x0a00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x08}};

//{04020301-0b00-0000-060e-2b3401010108}
//06.0e.2b.34.01.01.01.08.04.02.03.01.0b.00.00.00
const aafUID_t kAAFPropID_PCMDescriptor_PeakFrames =
{0x04020301, 0x0b00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x08}};

//{04020301-0c00-0000-060e-2b3401010108}
//06.0e.2b.34.01.01.01.08.04.02.03.01.0c.00.00.00
const aafUID_t kAAFPropID_PCMDescriptor_PeakOfPeaksPosition =
{0x04020301, 0x0c00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x08}};

//{04020301-0d00-0000-060e-2b3401010108}
//06.0e.2b.34.01.01.01.08.04.02.03.01.0d.00.00.00
const aafUID_t kAAFPropID_PCMDescriptor_PeakEnvelopeTimestamp =
{0x04020301, 0x0d00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x08}};

//{04020301-0e00-0000-060e-2b3401010108}
//06.0e.2b.34.01.01.01.08.04.02.03.01.0e.00.00.00
const aafUID_t kAAFPropID_PCMDescriptor_PeakEnvelopeData =
{0x04020301, 0x0e00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x08}};

//{06010104-0109-0000-060e-2b3401010107}
//06.0e.2b.34.01.01.01.07.06.01.01.04.01.09.00.00
const aafUID_t kAAFPropID_KLVDataDefinition_KLVDataType =
{0x06010104, 0x0109, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x07}};

//{04090201-0000-0000-060e-2b3401010107}
//06.0e.2b.34.01.01.01.07.04.09.02.01.00.00.00.00
const aafUID_t kAAFPropID_AuxiliaryDescriptor_MimeType =
{0x04090201, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x07}};

//{04090300-0000-0000-060e-2b3401010108}
//06.0e.2b.34.01.01.01.08.04.09.03.00.00.00.00.00
const aafUID_t kAAFPropID_AuxiliaryDescriptor_CharSet =
{0x04090300, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x08}};

//{04060802-0000-0000-060e-2b3401010108}
//06.0e.2b.34.01.01.01.08.04.06.08.02.00.00.00.00
const aafUID_t kAAFPropID_RIFFChunk_ChunkID =
{0x04060802, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x08}};

//{04060903-0000-0000-060e-2b3401010108}
//06.0e.2b.34.01.01.01.08.04.06.09.03.00.00.00.00
const aafUID_t kAAFPropID_RIFFChunk_ChunkLength =
{0x04060903, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x08}};

//{04070400-0000-0000-060e-2b3401010108}
//06.0e.2b.34.01.01.01.08.04.07.04.00.00.00.00.00
const aafUID_t kAAFPropID_RIFFChunk_ChunkData =
{0x04070400, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x08}};

//{04020302-0500-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.03.02.05.00.00.00
const aafUID_t kAAFPropID_BWFImportDescriptor_QltyFileSecurityReport =
{0x04020302, 0x0500, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020302-0600-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.03.02.06.00.00.00
const aafUID_t kAAFPropID_BWFImportDescriptor_QltyFileSecurityWave =
{0x04020302, 0x0600, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020502-0101-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.05.02.01.01.00.00
const aafUID_t kAAFPropID_BWFImportDescriptor_BextCodingHistory =
{0x04020502, 0x0101, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020502-0201-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.05.02.02.01.00.00
const aafUID_t kAAFPropID_BWFImportDescriptor_QltyBasicData =
{0x04020502, 0x0201, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020502-0301-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.05.02.03.01.00.00
const aafUID_t kAAFPropID_BWFImportDescriptor_QltyStartOfModulation =
{0x04020502, 0x0301, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020502-0401-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.05.02.04.01.00.00
const aafUID_t kAAFPropID_BWFImportDescriptor_QltyQualityEvent =
{0x04020502, 0x0401, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020502-0501-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.05.02.05.01.00.00
const aafUID_t kAAFPropID_BWFImportDescriptor_QltyEndOfModulation =
{0x04020502, 0x0501, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020502-0601-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.05.02.06.01.00.00
const aafUID_t kAAFPropID_BWFImportDescriptor_QltyQualityParameter =
{0x04020502, 0x0601, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020502-0701-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.05.02.07.01.00.00
const aafUID_t kAAFPropID_BWFImportDescriptor_QltyOperatorComment =
{0x04020502, 0x0701, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04020502-0801-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.02.05.02.08.01.00.00
const aafUID_t kAAFPropID_BWFImportDescriptor_QltyCueSheet =
{0x04020502, 0x0801, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{06010104-060f-0000-060e-2b3401010108}
//06.0e.2b.34.01.01.01.08.06.01.01.04.06.0f.00.00
const aafUID_t kAAFPropID_BWFImportDescriptor_UnknownBWFChunks =
{0x06010104, 0x060f, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x08}};

//{04010602-0102-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.01.06.02.01.02.00.00
const aafUID_t kAAFPropID_MPEGVideoDescriptor_SingleSequence =
{0x04010602, 0x0102, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04010602-0103-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.01.06.02.01.03.00.00
const aafUID_t kAAFPropID_MPEGVideoDescriptor_ConstantBPictureCount =
{0x04010602, 0x0103, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04010602-0104-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.01.06.02.01.04.00.00
const aafUID_t kAAFPropID_MPEGVideoDescriptor_CodedContentScanning =
{0x04010602, 0x0104, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04010602-0105-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.01.06.02.01.05.00.00
const aafUID_t kAAFPropID_MPEGVideoDescriptor_LowDelay =
{0x04010602, 0x0105, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04010602-0106-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.01.06.02.01.06.00.00
const aafUID_t kAAFPropID_MPEGVideoDescriptor_ClosedGOP =
{0x04010602, 0x0106, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04010602-0107-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.01.06.02.01.07.00.00
const aafUID_t kAAFPropID_MPEGVideoDescriptor_IdenticalGOP =
{0x04010602, 0x0107, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04010602-0108-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.01.06.02.01.08.00.00
const aafUID_t kAAFPropID_MPEGVideoDescriptor_MaxGOP =
{0x04010602, 0x0108, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04010602-0109-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.01.06.02.01.09.00.00
const aafUID_t kAAFPropID_MPEGVideoDescriptor_MaxBPictureCount =
{0x04010602, 0x0109, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04010602-010b-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.01.06.02.01.0b.00.00
const aafUID_t kAAFPropID_MPEGVideoDescriptor_BitRate =
{0x04010602, 0x010b, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{04010602-010a-0000-060e-2b3401010105}
//06.0e.2b.34.01.01.01.05.04.01.06.02.01.0a.00.00
const aafUID_t kAAFPropID_MPEGVideoDescriptor_ProfileAndLevel =
{0x04010602, 0x010a, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x05}};

//{06010107-0100-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.07.01.00.00.00
const aafUID_t kAAFPropID_ClassDefinition_ParentClass =
{0x06010107, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010107-0200-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.07.02.00.00.00
const aafUID_t kAAFPropID_ClassDefinition_Properties =
{0x06010107, 0x0200, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010107-0300-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.07.03.00.00.00
const aafUID_t kAAFPropID_ClassDefinition_IsConcrete =
{0x06010107, 0x0300, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010107-0400-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.07.04.00.00.00
const aafUID_t kAAFPropID_PropertyDefinition_Type =
{0x06010107, 0x0400, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03010202-0100-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.01.02.02.01.00.00.00
const aafUID_t kAAFPropID_PropertyDefinition_IsOptional =
{0x03010202, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010107-0500-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.07.05.00.00.00
const aafUID_t kAAFPropID_PropertyDefinition_LocalIdentification =
{0x06010107, 0x0500, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010107-0600-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.07.06.00.00.00
const aafUID_t kAAFPropID_PropertyDefinition_IsUniqueIdentifier =
{0x06010107, 0x0600, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03010203-0100-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.01.02.03.01.00.00.00
const aafUID_t kAAFPropID_TypeDefinitionInteger_Size =
{0x03010203, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03010203-0200-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.01.02.03.02.00.00.00
const aafUID_t kAAFPropID_TypeDefinitionInteger_IsSigned =
{0x03010203, 0x0200, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010107-0900-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.07.09.00.00.00
const aafUID_t kAAFPropID_TypeDefinitionStrongObjectReference_ReferencedType =
{0x06010107, 0x0900, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010107-0a00-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.07.0a.00.00.00
const aafUID_t kAAFPropID_TypeDefinitionWeakObjectReference_ReferencedType =
{0x06010107, 0x0a00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03010203-0b00-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.01.02.03.0b.00.00.00
const aafUID_t kAAFPropID_TypeDefinitionWeakObjectReference_TargetSet =
{0x03010203, 0x0b00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010107-0b00-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.07.0b.00.00.00
const aafUID_t kAAFPropID_TypeDefinitionEnumeration_ElementType =
{0x06010107, 0x0b00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03010203-0400-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.01.02.03.04.00.00.00
const aafUID_t kAAFPropID_TypeDefinitionEnumeration_ElementNames =
{0x03010203, 0x0400, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03010203-0500-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.01.02.03.05.00.00.00
const aafUID_t kAAFPropID_TypeDefinitionEnumeration_ElementValues =
{0x03010203, 0x0500, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{04010603-0100-0000-060e-2b340101010a}
//06.0e.2b.34.01.01.01.0a.04.01.06.03.01.00.00.00
const aafUID_t kAAFPropID_JPEG2000SubDescriptor_Rsiz =
{0x04010603, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0a}};

//{04010603-0200-0000-060e-2b340101010a}
//06.0e.2b.34.01.01.01.0a.04.01.06.03.02.00.00.00
const aafUID_t kAAFPropID_JPEG2000SubDescriptor_Xsiz =
{0x04010603, 0x0200, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0a}};

//{04010603-0300-0000-060e-2b340101010a}
//06.0e.2b.34.01.01.01.0a.04.01.06.03.03.00.00.00
const aafUID_t kAAFPropID_JPEG2000SubDescriptor_Ysiz =
{0x04010603, 0x0300, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0a}};

//{04010603-0400-0000-060e-2b340101010a}
//06.0e.2b.34.01.01.01.0a.04.01.06.03.04.00.00.00
const aafUID_t kAAFPropID_JPEG2000SubDescriptor_XOsiz =
{0x04010603, 0x0400, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0a}};

//{04010603-0500-0000-060e-2b340101010a}
//06.0e.2b.34.01.01.01.0a.04.01.06.03.05.00.00.00
const aafUID_t kAAFPropID_JPEG2000SubDescriptor_YOsiz =
{0x04010603, 0x0500, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0a}};

//{04010603-0600-0000-060e-2b340101010a}
//06.0e.2b.34.01.01.01.0a.04.01.06.03.06.00.00.00
const aafUID_t kAAFPropID_JPEG2000SubDescriptor_XTsiz =
{0x04010603, 0x0600, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0a}};

//{04010603-0700-0000-060e-2b340101010a}
//06.0e.2b.34.01.01.01.0a.04.01.06.03.07.00.00.00
const aafUID_t kAAFPropID_JPEG2000SubDescriptor_YTsiz =
{0x04010603, 0x0700, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0a}};

//{04010603-0800-0000-060e-2b340101010a}
//06.0e.2b.34.01.01.01.0a.04.01.06.03.08.00.00.00
const aafUID_t kAAFPropID_JPEG2000SubDescriptor_XTOsiz =
{0x04010603, 0x0800, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0a}};

//{04010603-0900-0000-060e-2b340101010a}
//06.0e.2b.34.01.01.01.0a.04.01.06.03.09.00.00.00
const aafUID_t kAAFPropID_JPEG2000SubDescriptor_YTOsiz =
{0x04010603, 0x0900, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0a}};

//{04010603-0a00-0000-060e-2b340101010a}
//06.0e.2b.34.01.01.01.0a.04.01.06.03.0a.00.00.00
const aafUID_t kAAFPropID_JPEG2000SubDescriptor_Csiz =
{0x04010603, 0x0a00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0a}};

//{04010603-0b00-0000-060e-2b340101010a}
//06.0e.2b.34.01.01.01.0a.04.01.06.03.0b.00.00.00
const aafUID_t kAAFPropID_JPEG2000SubDescriptor_PictureComponentSizing =
{0x04010603, 0x0b00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0a}};

//{04010603-0c00-0000-060e-2b340101010a}
//06.0e.2b.34.01.01.01.0a.04.01.06.03.0c.00.00.00
const aafUID_t kAAFPropID_JPEG2000SubDescriptor_CodingStyleDefault =
{0x04010603, 0x0c00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0a}};

//{04010603-0d00-0000-060e-2b340101010a}
//06.0e.2b.34.01.01.01.0a.04.01.06.03.0d.00.00.00
const aafUID_t kAAFPropID_JPEG2000SubDescriptor_QuantizationDefault =
{0x04010603, 0x0d00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0a}};

//{04010603-0e00-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.04.01.06.03.0e.00.00.00
const aafUID_t kAAFPropID_JPEG2000SubDescriptor_J2CLayout =
{0x04010603, 0x0e00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{04010602-0202-0000-060e-2b340101010d}
//06.0e.2b.34.01.01.01.0d.04.01.06.02.02.02.00.00
const aafUID_t kAAFPropID_MPEG4VisualSubDescriptor_MPEG4VisualSingleSequence =
{0x04010602, 0x0202, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0d}};

//{04010602-0203-0000-060e-2b340101010d}
//06.0e.2b.34.01.01.01.0d.04.01.06.02.02.03.00.00
const aafUID_t kAAFPropID_MPEG4VisualSubDescriptor_MPEG4VisualConstantBVOPs =
{0x04010602, 0x0203, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0d}};

//{04010602-0204-0000-060e-2b340101010d}
//06.0e.2b.34.01.01.01.0d.04.01.06.02.02.04.00.00
const aafUID_t kAAFPropID_MPEG4VisualSubDescriptor_MPEG4VisualCodedContentType =
{0x04010602, 0x0204, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0d}};

//{04010602-0205-0000-060e-2b340101010d}
//06.0e.2b.34.01.01.01.0d.04.01.06.02.02.05.00.00
const aafUID_t kAAFPropID_MPEG4VisualSubDescriptor_MPEG4VisualLowDelay =
{0x04010602, 0x0205, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0d}};

//{04010602-0206-0000-060e-2b340101010d}
//06.0e.2b.34.01.01.01.0d.04.01.06.02.02.06.00.00
const aafUID_t kAAFPropID_MPEG4VisualSubDescriptor_MPEG4VisualClosedGOV =
{0x04010602, 0x0206, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0d}};

//{04010602-0207-0000-060e-2b340101010d}
//06.0e.2b.34.01.01.01.0d.04.01.06.02.02.07.00.00
const aafUID_t kAAFPropID_MPEG4VisualSubDescriptor_MPEG4VisualIdenticalGOV =
{0x04010602, 0x0207, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0d}};

//{04010602-0208-0000-060e-2b340101010d}
//06.0e.2b.34.01.01.01.0d.04.01.06.02.02.08.00.00
const aafUID_t kAAFPropID_MPEG4VisualSubDescriptor_MPEG4VisualMaxGOV =
{0x04010602, 0x0208, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0d}};

//{04010602-0209-0000-060e-2b340101010d}
//06.0e.2b.34.01.01.01.0d.04.01.06.02.02.09.00.00
const aafUID_t kAAFPropID_MPEG4VisualSubDescriptor_MPEG4VisualBVOPCount =
{0x04010602, 0x0209, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0d}};

//{04010602-020a-0000-060e-2b340101010d}
//06.0e.2b.34.01.01.01.0d.04.01.06.02.02.0a.00.00
const aafUID_t kAAFPropID_MPEG4VisualSubDescriptor_MPEG4VisualProfileAndLevel =
{0x04010602, 0x020a, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0d}};

//{04010602-020b-0000-060e-2b340101010d}
//06.0e.2b.34.01.01.01.0d.04.01.06.02.02.0b.00.00
const aafUID_t kAAFPropID_MPEG4VisualSubDescriptor_MPEG4VisualBitRate =
{0x04010602, 0x020b, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0d}};

//{01030701-0100-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.01.03.07.01.01.00.00.00
const aafUID_t kAAFPropID_MCALabelSubDescriptor_MCALabelDictionaryID =
{0x01030701, 0x0100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{01030701-0500-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.01.03.07.01.05.00.00.00
const aafUID_t kAAFPropID_MCALabelSubDescriptor_MCALinkID =
{0x01030701, 0x0500, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{01030701-0200-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.01.03.07.01.02.00.00.00
const aafUID_t kAAFPropID_MCALabelSubDescriptor_MCATagSymbol =
{0x01030701, 0x0200, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{01030701-0300-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.01.03.07.01.03.00.00.00
const aafUID_t kAAFPropID_MCALabelSubDescriptor_MCATagName =
{0x01030701, 0x0300, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{0103040a-0000-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.01.03.04.0a.00.00.00.00
const aafUID_t kAAFPropID_MCALabelSubDescriptor_MCAChannelID =
{0x0103040a, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{03010102-0315-0000-060e-2b340101010d}
//06.0e.2b.34.01.01.01.0d.03.01.01.02.03.15.00.00
const aafUID_t kAAFPropID_MCALabelSubDescriptor_RFC5646SpokenLanguage =
{0x03010102, 0x0315, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0d}};

//{01051000-0000-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.01.05.10.00.00.00.00.00
const aafUID_t kAAFPropID_MCALabelSubDescriptor_MCATitle =
{0x01051000, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{01051100-0000-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.01.05.11.00.00.00.00.00
const aafUID_t kAAFPropID_MCALabelSubDescriptor_MCATitleVersion =
{0x01051100, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{01051200-0000-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.01.05.12.00.00.00.00.00
const aafUID_t kAAFPropID_MCALabelSubDescriptor_MCATitleSubVersion =
{0x01051200, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{01051300-0000-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.01.05.13.00.00.00.00.00
const aafUID_t kAAFPropID_MCALabelSubDescriptor_MCAEpisode =
{0x01051300, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{01040105-0000-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.01.04.01.05.00.00.00.00
const aafUID_t kAAFPropID_MCALabelSubDescriptor_MCAPartitionKind =
{0x01040105, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{01040106-0000-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.01.04.01.06.00.00.00.00
const aafUID_t kAAFPropID_MCALabelSubDescriptor_MCAPartitionNumber =
{0x01040106, 0x0000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{03020102-2000-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.03.02.01.02.20.00.00.00
const aafUID_t kAAFPropID_MCALabelSubDescriptor_MCAAudioContentKind =
{0x03020102, 0x2000, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{03020102-2100-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.03.02.01.02.21.00.00.00
const aafUID_t kAAFPropID_MCALabelSubDescriptor_MCAAudioElementKind =
{0x03020102, 0x2100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{01030701-0600-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.01.03.07.01.06.00.00.00
const aafUID_t kAAFPropID_AudioChannelLabelSubDescriptor_SoundfieldGroupLinkID =
{0x01030701, 0x0600, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{01030701-0400-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.01.03.07.01.04.00.00.00
const aafUID_t kAAFPropID_SoundfieldGroupLabelSubDescriptor_GroupOfSoundfieldGroupsLinkID =
{0x01030701, 0x0400, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{04010606-0103-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.04.01.06.06.01.03.00.00
const aafUID_t kAAFPropID_AVCSubDescriptor_AVCConstantBPictureFlag =
{0x04010606, 0x0103, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{04010606-0104-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.04.01.06.06.01.04.00.00
const aafUID_t kAAFPropID_AVCSubDescriptor_AVCCodedContentKind =
{0x04010606, 0x0104, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{04010606-0106-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.04.01.06.06.01.06.00.00
const aafUID_t kAAFPropID_AVCSubDescriptor_AVCClosedGOPIndicator =
{0x04010606, 0x0106, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{04010606-0107-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.04.01.06.06.01.07.00.00
const aafUID_t kAAFPropID_AVCSubDescriptor_AVCIdenticalGOPIndicator =
{0x04010606, 0x0107, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{04010606-0108-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.04.01.06.06.01.08.00.00
const aafUID_t kAAFPropID_AVCSubDescriptor_AVCMaximumGOPSize =
{0x04010606, 0x0108, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{04010606-0109-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.04.01.06.06.01.09.00.00
const aafUID_t kAAFPropID_AVCSubDescriptor_AVCMaximumBPictureCount =
{0x04010606, 0x0109, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{04010606-010a-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.04.01.06.06.01.0a.00.00
const aafUID_t kAAFPropID_AVCSubDescriptor_AVCProfile =
{0x04010606, 0x010a, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{04010606-010b-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.04.01.06.06.01.0b.00.00
const aafUID_t kAAFPropID_AVCSubDescriptor_AVCMaximumBitRate =
{0x04010606, 0x010b, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{04010606-010c-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.04.01.06.06.01.0c.00.00
const aafUID_t kAAFPropID_AVCSubDescriptor_AVCProfileConstraint =
{0x04010606, 0x010c, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{04010606-010d-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.04.01.06.06.01.0d.00.00
const aafUID_t kAAFPropID_AVCSubDescriptor_AVCLevel =
{0x04010606, 0x010d, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{04010606-010e-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.04.01.06.06.01.0e.00.00
const aafUID_t kAAFPropID_AVCSubDescriptor_AVCDecodingDelay =
{0x04010606, 0x010e, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{04010606-010f-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.04.01.06.06.01.0f.00.00
const aafUID_t kAAFPropID_AVCSubDescriptor_AVCMaximumRefFrames =
{0x04010606, 0x010f, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{04010606-0110-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.04.01.06.06.01.10.00.00
const aafUID_t kAAFPropID_AVCSubDescriptor_AVCSequenceParameterSetFlag =
{0x04010606, 0x0110, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{04010606-0111-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.04.01.06.06.01.11.00.00
const aafUID_t kAAFPropID_AVCSubDescriptor_AVCPictureParameterSetFlag =
{0x04010606, 0x0111, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{04010606-0114-0000-060e-2b340101010e}
//06.0e.2b.34.01.01.01.0e.04.01.06.06.01.14.00.00
const aafUID_t kAAFPropID_AVCSubDescriptor_AVCAverageBitRate =
{0x04010606, 0x0114, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0e}};

//{04020403-0102-0000-060e-2b340101010a}
//06.0e.2b.34.01.01.01.0a.04.02.04.03.01.02.00.00
const aafUID_t kAAFPropID_MPEGAudioDescriptor_MPEGAudioBitRate =
{0x04020403, 0x0102, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x0a}};

//{06010107-0c00-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.07.0c.00.00.00
const aafUID_t kAAFPropID_TypeDefinitionFixedArray_ElementType =
{0x06010107, 0x0c00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03010203-0300-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.01.02.03.03.00.00.00
const aafUID_t kAAFPropID_TypeDefinitionFixedArray_ElementCount =
{0x03010203, 0x0300, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010107-0d00-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.07.0d.00.00.00
const aafUID_t kAAFPropID_TypeDefinitionVariableArray_ElementType =
{0x06010107, 0x0d00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010107-0e00-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.07.0e.00.00.00
const aafUID_t kAAFPropID_TypeDefinitionSet_ElementType =
{0x06010107, 0x0e00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010107-0f00-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.07.0f.00.00.00
const aafUID_t kAAFPropID_TypeDefinitionString_ElementType =
{0x06010107, 0x0f00, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010107-1100-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.07.11.00.00.00
const aafUID_t kAAFPropID_TypeDefinitionRecord_MemberTypes =
{0x06010107, 0x1100, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03010203-0600-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.01.02.03.06.00.00.00
const aafUID_t kAAFPropID_TypeDefinitionRecord_MemberNames =
{0x03010203, 0x0600, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010107-1200-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.07.12.00.00.00
const aafUID_t kAAFPropID_TypeDefinitionRename_RenamedType =
{0x06010107, 0x1200, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03010203-0700-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.01.02.03.07.00.00.00
const aafUID_t kAAFPropID_TypeDefinitionExtendibleEnumeration_ElementNames =
{0x03010203, 0x0700, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03010203-0800-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.01.02.03.08.00.00.00
const aafUID_t kAAFPropID_TypeDefinitionExtendibleEnumeration_ElementValues =
{0x03010203, 0x0800, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{0e040101-0101-0111-060e-2b3401010101}
//06.0e.2b.34.01.01.01.01.0e.04.01.01.01.01.01.11
const aafUID_t kAAFPropID_TypeDefinitionGenericCharacter_CharacterSize =
{0x0e040101, 0x0101, 0x0111, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x01}};

//{06010107-1300-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.07.13.00.00.00
const aafUID_t kAAFPropID_MetaDefinition_Identification =
{0x06010107, 0x1300, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{03020401-0201-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.03.02.04.01.02.01.00.00
const aafUID_t kAAFPropID_MetaDefinition_Name =
{0x03020401, 0x0201, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010107-1401-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.07.14.01.00.00
const aafUID_t kAAFPropID_MetaDefinition_Description =
{0x06010107, 0x1401, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010107-0700-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.07.07.00.00.00
const aafUID_t kAAFPropID_MetaDictionary_ClassDefinitions =
{0x06010107, 0x0700, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{06010107-0800-0000-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.06.01.01.07.08.00.00.00
const aafUID_t kAAFPropID_MetaDictionary_TypeDefinitions =
{0x06010107, 0x0800, 0x0000, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

// Special property definition ids used for specifying the
// starting strong reference in the target list of a
// weak reference.
//
//{0d010301-0101-0100-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.0d.01.03.01.01.01.01.00
const aafUID_t kAAFPropID_Root_MetaDictionary =
{0x0d010301, 0x0101, 0x0100, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};

//{0d010301-0102-0100-060e-2b3401010102}
//06.0e.2b.34.01.01.01.02.0d.01.03.01.01.02.01.00
const aafUID_t kAAFPropID_Root_Header =
{0x0d010301, 0x0102, 0x0100, {0x06, 0x0e, 0x2b, 0x34, 0x01, 0x01, 0x01, 0x02}};


#endif // ! __AAFPropertyDefs_h__
