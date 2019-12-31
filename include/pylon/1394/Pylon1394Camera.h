//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2007-2017 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief Low Level API: Generic pylon 1394 camera interface
*/

#ifndef PYLON_IIDC1394_CAMERA_H
#define PYLON_IIDC1394_CAMERA_H

#if _MSC_VER > 1000
#pragma once
#endif //_MSC_VER > 1000

#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#include "../DeviceClass.h"
#include "../NodeMapProxy.h"
#include "../StreamGrabberProxy.h"
#include "../EventGrabberProxy.h"

#include "Basler1394DeviceInfo.h"
#include "../PylonDeviceProxy.h"

#include "pylon/1394/_IIDC1394StreamParams.h"
#include "pylon/1394/_IIDC1394EventParams.h"


namespace Pylon
{
    //**************************************************************************************************
    //! Low Level API: Class for pylon 1394 cameras providing access to transport layer related parameters.
    /**
    \see \ref configuringcameras
    \ingroup Pylon_LowLevelApi
    */
    //**************************************************************************************************
    typedef void CPylon1394TLParams;
    //PYLON_DEFINE_NODEMAP(CPylon1394TLParams, CNodeMapProxyT<>);


    //**************************************************************************************************
    //! Low Level API: Class for pylon 1394 cameras providing access to stream grabber related methods and parameters.
    /**
    \see \ref configuringcameras
    \ingroup Pylon_LowLevelApi
    */
    //**************************************************************************************************
    PYLON_DEFINE_STREAMGRABBER(CPylon1394StreamGrabber, CStreamGrabberProxyT<Basler_IIDC1394StreamParams::CIIDC1394StreamParams_Params>);


    //**************************************************************************************************
    //! Low Level API: Class for pylon 1394 cameras providing access to event grabber related methods and parameters.
    /**
    \see \ref configuringcameras
    \ingroup Pylon_LowLevelApi
    */
    //**************************************************************************************************
    PYLON_DEFINE_EVENTGRABBER(CPylon1394EventGrabber, CEventGrabberProxyT<Basler_IIDC1394EventParams::CIIDC1394EventParams_Params>);


    //**************************************************************************************************
    //! Low Level API: The camera class for pylon 1394 camera devices
    /**
    This is the base class for pylon 1394 cameras providing access to camera parameters.
    \see \ref configuringcameras

    \tparam TCameraParams  The camera specific parameter class (auto generated from camera xml file)
    \ingroup Pylon_LowLevelApi
    */
    //**************************************************************************************************
    template<class TCameraParams>
    class CPylon1394CameraT : public CPylonDeviceProxyT<TCameraParams>
    {
    public:
        typedef Pylon::CBasler1394DeviceInfo   DeviceInfo_t;    //!< \copybrief Pylon::CBaslerGigEDeviceInfo
        typedef Pylon::CPylon1394TLParams      TlParams_t;      //!< \copybrief Pylon::CPylon1394TLParams
        typedef Pylon::CPylon1394StreamGrabber StreamGrabber_t; //!< \copybrief Pylon::CPylon1394StreamGrabber
        typedef Pylon::CPylon1394EventGrabber  EventGrabber_t;  //!< \copybrief Pylon::CPylon1394EventGrabber

        /// The name of this device class, use this for enumeration
        static String_t DeviceClass() { return Basler1394DeviceClass; }

    public:
        //! \name Construction
        // \{

        /** \brief \copybrief Pylon::CPylonDeviceProxyT::CPylonDeviceProxyT()

        \copydetails Pylon::CPylonDeviceProxyT::CPylonDeviceProxyT()
        */
        CPylon1394CameraT() {};

        /** \brief \copybrief Pylon::CPylonDeviceProxyT::CPylonDeviceProxyT(IPylonDevice*,bool)

        \copydetails Pylon::CPylonDeviceProxyT::CPylonDeviceProxyT(IPylonDevice*,bool)
        */
        CPylon1394CameraT(IPylonDevice* pDevice, bool takeOwnership = true)
            : CPylonDeviceProxyT<TCameraParams>(pDevice, takeOwnership)
        {
        }

        //\}
    };


} // namespace Pylon

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif // PYLON_IIDC1394_CAMERA_H
