//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2006-2017 Basler AG
//  http://www.baslerweb.com
//  Author:  Hartmut Nebelung
//-----------------------------------------------------------------------------
/*!
\file
\brief    Low Level API: Definition of IStreamGrabber interface
*/
#ifndef __ISTREAMGRABBER_H__
#define __ISTREAMGRABBER_H__

#if _MSC_VER > 1000
#pragma once
#endif //_MSC_VER > 1000

#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#include <GenICamFwd.h>
#include <pylon/stdinclude.h>

namespace Pylon
{
    class GrabResult;
    class WaitObject;
    /// This opaque type represents a registered buffer.
    typedef void* StreamBufferHandle;

    // -------------------------------------------------------------------------
    // interface IStreamGrabber
    // -------------------------------------------------------------------------
    /*!
        \ingroup Pylon_LowLevelApi
        \interface IStreamGrabber
        \brief Low Level API: Interface to an (input) data stream

        Data is filled into user provided buffers. Before usage
        the buffers must be registered. After calling PrepareGrab()
        enter them into a queue to become filled.

        The streamgrabber provides a output queue which contains filled data buffers.
        While the queue is not empty the associated wait object is signaled.
        Get the buffer using the RetrieveResult()
        method.
        When FinishGrab() is called the result queue remains open, so the data may
        be collected. It remains open until Close()
         resp. the device
        is closed.

        Parameter of streamgrabber are controlled by the elements of a own NodeMap,
        which can be retrieved by calling GetNodeMap().

        \sa For an introduction into the usage of stream grabbers see \ref grabbingimages
        in the Programmer's Guide.
    */
    interface IStreamGrabber
    {
        /// Opens the stream grabber
        //*! Opens the stream grabber and starts the result queue. */
        virtual void Open(void) = 0;
        /// Closes the stream grabber
        /*! Flushes the result queue and stops the thread. */
        virtual void Close(void) = 0;
        /// Retrieve whether the stream grabber is open.
        virtual bool IsOpen(void) const = 0;


        /// Registers a buffer for subsequent use.
        /*! Stream must be locked to register buffers  The Buffer size may not exceed
        the value specified when PrepareGrab was called. */
        virtual StreamBufferHandle RegisterBuffer( void* Buffer, size_t BufferSize ) = 0;
        /// Deregisters the buffer
        /*! Deregistering fails while the buffer is in use, so retrieve the buffer from
        the output queue after grabbing.
        \note Do not delete buffers before they are deregistered. */
        virtual const void* DeregisterBuffer( StreamBufferHandle ) = 0;

        /// Prepares grabbing
        /*! Allocates resources, synchronizes with the camera and locks critical parameter */
        virtual void PrepareGrab(void) = 0;
        /// Stops grabbing
        /*! Releases the resources and camera. Pending grab requests are canceled. */
        virtual void FinishGrab(void) = 0;

        /// Enqueues a buffer in the input queue.
        /*! PrepareGrab is required to queue buffers. The context is returned together with the
        buffer and the grab result. It is not touched by the stream grabber.
        It is illegal to queue a buffer a second time before it is fetched from the
        result queue.*/
        virtual void QueueBuffer( StreamBufferHandle, const void* Context=NULL ) = 0;

        /// Cancels pending requests
        /*! , resources remain allocated. Following, the results must be retrieved from the
        Output Queue. */
        virtual void CancelGrab(void) = 0;

        /// Retrieves a grab result from the output queue
        /*! \return When result was available true is returned and and the
        first result is copied into the grabresult. Otherwise the grabresult remains
        unchanged and false is returned. */
        virtual bool RetrieveResult( GrabResult& ) = 0;
        /// Returns the result event object.
        /*! This object is associated with the result queue. The event is signaled when
        queue is non-empty */
        virtual WaitObject& GetWaitObject(void) const = 0;
        /// Returns the associated stream grabber parameters.
        /*! If no parameters are available, NULL is returned. */
        virtual GENAPI_NAMESPACE::INodeMap* GetNodeMap(void) = 0;
    };

};

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif //__ISTREAMGRABBER_H__
