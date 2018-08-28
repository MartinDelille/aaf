//=---------------------------------------------------------------------=
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

// @doc OMINTERNAL
#ifndef OMDATASTREAM_H
#define OMDATASTREAM_H

#include "OMProperty.h"

  // @class Persistent data stream properties supported by the Object
  //        Manager.
  //   @base | public <c OMProperty>.
  //   @cauthor Tim Bingham | tjb | Avid Technology, Inc.
class OMDataStream : public OMProperty {
public:
  // @access Public members.

    // @cmember Constructor.
  OMDataStream(const OMPropertyId propertyId,
               const wchar_t* name);

    // @cmember Destructor.
  virtual ~OMDataStream(void);

    // @cmember The size, in bytes, of the data in this
    //          <c OMDataStreamProperty>.
  virtual OMUInt64 size(void) const = 0;

    // @cmember Set the size, in bytes, of the data in this
    //          <c OMDataStreamProperty>.
  virtual void setSize(const OMUInt64 newSize) = 0;

    // @cmember The current position for <f read()> and <f write()>, as an
    //          offset in bytes from the begining of the data stream.
  virtual OMUInt64 position(void) const = 0;

    // @cmember Set the current position for <f read()> and <f write()>, as an
    //          offset in bytes from the begining of the data stream.
  virtual void setPosition(const OMUInt64 offset) const = 0;

    // @cmember Attempt to read the number of bytes given by <p bytes>
    //          from the data stream into the buffer at address
    //          <p buffer>. The actual number of bytes read is returned
    //          in <p bytesRead>.
  virtual void read(OMByte* buffer,
                    const OMUInt32 bytes,
                    OMUInt32& bytesRead) const = 0;

    // @cmember Attempt to write the number of bytes given by <p bytes>
    //          to the data stream from the buffer at address
    //          <p buffer>. The actual number of bytes written is returned
    //          in <p bytesWritten>.
  virtual void write(const OMByte* buffer,
                     const OMUInt32 bytes,
                     OMUInt32& bytesWritten) = 0;

    // @cmember Attempt to read the vector of buffers given by <p buffers>
    //          from this <c OMDataStream>. This is "read scatter". The
    //          <p bufferCount> buffers are read in order until all have
    //          been successfully read or an error is encountered. Once
    //          an error has been encountered on one buffer no additional
    //          buffers are read.
    //          The number of bytes read is returned in <p bytesRead>.
  virtual void read(OMIOBufferDescriptor* buffers,
                    OMUInt32 bufferCount,
                    OMUInt32& bytesRead) const = 0;

    // @cmember Attempt to write the vector of buffers given by <p buffers>
    //          to this <c OMDataStream>. This is "write gather". The
    //          <p bufferCount> buffers are written in order until all have
    //          been successfully written or an error is encountered. Once
    //          an error has been encountered on one buffer no additional
    //          buffers are written.
    //          The number of bytes written is returned in <p bytesWritten>.
  virtual void write(const OMIOBufferDescriptor* buffers,
                     OMUInt32 bufferCount,
                     OMUInt32& bytesWritten) = 0;

    // Asynchronous read - single buffer
  virtual void read(OMUInt64 position,
                    OMByte* buffer,
                    const OMUInt32 bytes,
                    void* /* */ completion,
                    const void* clientArgument) = 0;

    // Asynchronous write - single buffer
  virtual void write(OMUInt64 position,
                     const OMByte* buffer,
                     const OMUInt32 bytes,
                     void* /* */ completion,
                     const void* clientArgument) = 0;

    // Asynchronous read - multiple buffers
  virtual void read(OMUInt64 position,
                    OMIOBufferDescriptor* buffers,
                    OMUInt32 bufferCount,
                    void* /* */ completion,
                    const void* clientArgument) const = 0;

    // Asynchronous write - multiple buffers
  virtual void write(OMUInt64 position,
                     const OMIOBufferDescriptor* buffers,
                     OMUInt32 bufferCount,
                     void* /* */ completion,
                     const void* clientArgument) = 0;

  virtual OMByteOrder storedByteOrder(void) const = 0;

  virtual void setStoredByteOrder(OMByteOrder byteOrder) = 0;

};

#endif
