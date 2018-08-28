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
#ifndef OMSTOREDSTREAMFILTER_H
#define OMSTOREDSTREAMFILTER_H

#include "OMDataTypes.h"

class OMStoredStream;

  // @class Filtered OMStoredStream
class OMStoredStreamFilter {
public:
  // @access Public members.

    // @cmember Destroy this <c OMStoredStreamFilter>.
  virtual ~OMStoredStreamFilter(void) {}

    // @cmember Read <p size> bytes from this <c OMStoredStreamFilter>
    //          into the buffer at address <p data>.
  virtual void read(void* data, OMUInt32 size) const = 0;

    // @cmember Attempt to read <p bytes> bytes from this
    //          <c OMStoredStreamFilter> into the buffer at address <p data>.
    //          The actual number of bytes read is returned in <p bytesRead>.
  virtual void read(OMByte* data,
                    const OMUInt32 bytes,
                    OMUInt32& bytesRead) const = 0;

    // @cmember Attempt to read the vector of buffers given by <p buffers>
    //          from this <c OMStoredStreamFilter>. This is "read scatter". The
    //          <p bufferCount> buffers are read in order until all have
    //          been successfully read or an error is encountered. Once
    //          an error has been encountered on one buffer no additional
    //          buffers are read.
    //          The number of bytes read is returned in <p bytesRead>.
  virtual void read(OMIOBufferDescriptor* buffers,
                    OMUInt32 bufferCount,
                    OMUInt32& bytesRead) const = 0;

    // Asynchronous read - single buffer
  virtual void read(OMUInt64 position,
                    OMByte* buffer,
                    const OMUInt32 bytes,
                    void* /* */ completion,
                    const void* clientArgument) const = 0;

    // Asynchronous read - multiple buffers
  virtual void read(OMUInt64 position,
                    OMIOBufferDescriptor* buffers,
                    OMUInt32 bufferCount,
                    void* /* */ completion,
                    const void* clientArgument) const = 0;

    // @cmember Write <p size> bytes from the buffer at address
    //          <p data> to this <c OMStoredStreamFilter>.
  virtual void write(void* data, OMUInt32 size) = 0;

    // @cmember Attempt to write <p bytes> bytes from the buffer at
    //          address <p data> to this <c OMStoredStreamFilter>. The actual
    //          number of bytes written is returned in <p bytesWritten>.
  virtual void write(const OMByte* data,
                     const OMUInt32 bytes,
                     OMUInt32& bytesWritten) = 0;

    // @cmember Attempt to write the vector of buffers given by <p buffers>
    //          to this <c OMStoredStreamFilter>. This is "write gather". The
    //          <p bufferCount> buffers are written in order until all have
    //          been successfully written or an error is encountered. Once
    //          an error has been encountered on one buffer no additional
    //          buffers are written.
    //          The number of bytes written is returned in <p bytesWritten>.
  virtual void write(OMIOBufferDescriptor* buffers,
                     OMUInt32 bufferCount,
                     OMUInt32& bytesWritten) = 0;

    // Asynchronous write - single buffer
  virtual void write(OMUInt64 position,
                     const OMByte* buffer,
                     const OMUInt32 bytes,
                     void* /* */ completion,
                     const void* clientArgument) = 0;

    // Asynchronous write - multiple buffers
  virtual void write(OMUInt64 position,
                     const OMIOBufferDescriptor* buffers,
                     OMUInt32 bufferCount,
                     void* /* */ completion,
                     const void* clientArgument) = 0;

    // @cmember The size of this <c OMStoredStreamFilter> in bytes.
  virtual OMUInt64 size(void) const = 0;

    // @cmember Set the size of this <c OMStoredStreamFilter> to <p bytes>.
  virtual void setSize(const OMUInt64 newSize) = 0;

    // @cmember The current position for <f read()> and
    //          <f write()>, as an offset in bytes from the
    //          begining of this <c OMStoredStreamFilter>.
  virtual OMUInt64 position(void) const = 0;

    // @cmember Set the current position for <f read()> and
    //          <f write()>, as an offset in bytes from the
    //          begining of this <c OMStoredStreamFilter>.
  virtual void setPosition(const OMUInt64 offset) const = 0;

    // @cmember Synchronize this <c OMStoredStreamFilter> with
    //          the underlying <c OMStoredStream>.
    //          An implementation of <c OMStoredStreamFilter> would
    //          use this method to write and read encoding-specific
    //          data to and from the underlying <c OMStoredStream>.
    //          Calling this method brings the encoding-specific
    //          represenation of <c OMStoredStream> into a valid state.
  virtual void synchronize(void) const = 0;

    // @cmember Close this <c OMStoredStreamFilter>.
//  virtual void close(void) = 0;

    // @cmember Get unfiltered <c OMStoredStream>.
  virtual const OMStoredStream* stream() const = 0;

    // @cmember Get unfiltered <c OMStoredStream>.
  virtual OMStoredStream* stream() = 0;
};

#endif
