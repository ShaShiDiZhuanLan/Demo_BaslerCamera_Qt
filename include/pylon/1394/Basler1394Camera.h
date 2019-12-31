//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2007-2017 Basler AG
//  http://www.baslerweb.com
//-----------------------------------------------------------------------------
/*!
\file
\brief Generic pylon 1394 camera interface
\brief Pylon 1394 camera interface for Basler 1394 cameras

*/

#ifndef BASLER_IIDC1394_CAMERA_H
#define BASLER_IIDC1394_CAMERA_H

#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */


#include "Pylon1394Camera.h"

#include "pylon/1394/_Basler1394CameraParams.h"


namespace Pylon
{
    //**************************************************************************************************
    //! Low Level API: The camera class for Basler 1394 camera devices
    /**
    Class for Basler 1394 cameras providing access to camera parameters.
    \see \ref configuringcameras

    \ingroup Pylon_LowLevelApi
    */
    //**************************************************************************************************
    PYLON_DEFINE_CAMERA(CBasler1394Camera, Pylon::CPylon1394CameraT<Basler_IIDC1394CameraParams::CIIDC1394CameraParams_Params>);

} // namespace Pylon

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif // BASLER_IIDC1394_CAMERA_H
