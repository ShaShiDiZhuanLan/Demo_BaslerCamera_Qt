//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2012-2017 Basler AG
//  http://www.baslerweb.com
//  Author:  Andreas Gau
//-----------------------------------------------------------------------------
/*!
\file
\brief USB specific instant camera array class.
*/
#ifndef INCLUDED_BASLERUSBINSTANTCAMERAARRAY_H_5817072
#define INCLUDED_BASLERUSBINSTANTCAMERAARRAY_H_5817072

#include <pylon/usb/BaslerUsbInstantCamera.h>
#include <pylon/private/DeviceSpecificInstantCameraArray.h>

namespace Pylon
{
    /** \addtogroup Pylon_InstantCameraApiUsb
     * @{
     */

    /*!
    \class  CBaslerUsbInstantCameraArray
    \brief  USB specific instant camera array

    \threading
        The CBaslerUsbInstantCameraArray class is not thread-safe.
    */
    class CBaslerUsbInstantCameraArray : public CDeviceSpecificInstantCameraArrayT<CBaslerUsbInstantCamera>
    {
    public:
        /*!
            \copybrief CInstantCameraArray::CInstantCameraArray()
            \copydetails CInstantCameraArray::CInstantCameraArray()
        */
        CBaslerUsbInstantCameraArray() {}
        /*!
            \copybrief CInstantCameraArray::CInstantCameraArray( size_t)
            \copydetails CInstantCameraArray::CInstantCameraArray( size_t)
        */
        CBaslerUsbInstantCameraArray( size_t numberOfCameras) : CDeviceSpecificInstantCameraArrayT<CBaslerUsbInstantCamera>(numberOfCameras) {}

    };

    /**
     * @}
     */
}

#endif /* INCLUDED_BASLERUSBINSTANTCAMERAARRAY_H_5817072 */
