//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2017 Basler AG
//  http://www.baslerweb.com
//  Author:  Andreas Gau
//-----------------------------------------------------------------------------
/*!
\file
\brief Pylon IEEE 1394 specific instant camera class.
*/

#ifndef INCLUDED_BASLER1394INSTANTCAMERA_H_8353344
#define INCLUDED_BASLER1394INSTANTCAMERA_H_8353344

#include <pylon/1394/_Basler1394CameraParams.h>
#include <pylon/1394/_IIDC1394EventParams.h>
#include <pylon/1394/_IIDC1394StreamParams.h>
#include <pylon/1394/Basler1394DeviceInfo.h>
#include <pylon/1394/Basler1394ConfigurationEventHandler.h>
#include <pylon/1394/Basler1394ImageEventHandler.h>
#include <pylon/1394/Basler1394CameraEventHandler.h>
#include <pylon/1394/Basler1394GrabResultPtr.h>
#include <pylon/private/DeviceSpecificInstantCamera.h>
#include <pylon/DeviceClass.h>
#include <pylon/NodeMapProxy.h>

namespace Pylon
{
    /** \addtogroup Pylon_InstantCameraApi1394
     * @{
     */

    // IEEE 1394 devices do not support a transport layer node map.
    // This is a dummy implementation for the IEEE 1394 device specific camera.
    class C1394TLDummyParams_Params
    {
    public:
        void _Initialize(GENAPI_NAMESPACE::INodeMap*)
        {
        }
    };

    class CBasler1394InstantCamera;

    /// Lists all the types used by the IEEE 1394 device specific instant camera class.
    struct CBasler1394InstantCameraTraits
    {
        /// The type of the final camera class.
        typedef CBasler1394InstantCamera InstantCamera_t;
        /// \copybrief Basler_IIDC1394CameraParams::CIIDC1394CameraParams_Params
        typedef Basler_IIDC1394CameraParams::CIIDC1394CameraParams_Params CameraParams_t;
        /// \copybrief Pylon::IPylonDevice
        typedef IPylonDevice IPylonDevice_t;
        /// \copybrief Pylon::CBasler1394DeviceInfo
        typedef Pylon::CBasler1394DeviceInfo DeviceInfo_t;
        /// IEEE 1394 devices do not support a transport layer node map, using dummy class.
        typedef CNodeMapProxyT<C1394TLDummyParams_Params> TlParams_t;
        /// The parameters of the IEEE 1394 streamgrabber.
        typedef CNodeMapProxyT<Basler_IIDC1394StreamParams::CIIDC1394StreamParams_Params> StreamGrabberParams_t;
        /// The parameters of the IEEE 1394 eventgrabber.
        typedef CNodeMapProxyT<Basler_IIDC1394EventParams::CIIDC1394EventParams_Params> EventGrabberParams_t;
        /// The IEEE 1394 specific configuration event handler class.
        typedef CBasler1394ConfigurationEventHandler ConfigurationEventHandler_t;
        /// The IEEE 1394 specific image event handler class.
        typedef CBasler1394ImageEventHandler ImageEventHandler_t;
        /// The IEEE 1394 specific image event handler class.
        typedef CBasler1394CameraEventHandler CameraEventHandler_t;
        /// The IEEE 1394 specific grab result data.
        typedef CBasler1394GrabResultData GrabResultData_t;
        /// The IEEE 1394 specific grab result smart pointer.
        typedef CBasler1394GrabResultPtr GrabResultPtr_t;

        //! The name of this device class. Use this one for enumeration.
        static String_t DeviceClass() { return Basler1394DeviceClass; }
    };


    /*!
    \class  CBasler1394InstantCamera
    \brief  Extends the CInstantCamera by IEEE 1394 specific parameter interface classes.
    */
    PYLON_DEFINE_INSTANT_CAMERA( CBasler1394InstantCamera, CDeviceSpecificInstantCameraT<CBasler1394InstantCameraTraits>)

    /**
     * @}
     */
} // namespace Pylon

#endif /* INCLUDED_BASLER1394INSTANTCAMERA_H_8353344 */
