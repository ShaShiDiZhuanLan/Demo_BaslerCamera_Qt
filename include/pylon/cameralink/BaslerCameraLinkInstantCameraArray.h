//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2017 Basler AG
//  http://www.baslerweb.com
//  Author:  Andreas Gau
//-----------------------------------------------------------------------------
/*!
\file
\brief Camera Link specific instant camera array class.
*/
#ifndef INCLUDED_BASLERCAMERALINKINSTANTCAMERAARRAY_H_5817072
#define INCLUDED_BASLERCAMERALINKINSTANTCAMERAARRAY_H_5817072

#include <pylon/cameralink/BaslerCameraLinkInstantCamera.h>
#include <pylon/private/DeviceSpecificInstantCameraArray.h>

namespace Pylon
{
    /** \addtogroup Pylon_InstantCameraApiCameraLink
     * @{
     */

    /*!
    \class  CBaslerCameraLinkInstantCameraArray
    \brief  Camera Link specific instant camera array

    \threading
        The CBaslerCameraLinkInstantCameraArray class is not thread-safe.
    */
    class CBaslerCameraLinkInstantCameraArray : public CDeviceSpecificInstantCameraArrayT<CBaslerCameraLinkInstantCamera>
    {
    public:
        /*!
            \copybrief CInstantCameraArray::CInstantCameraArray()
            \copydetails CInstantCameraArray::CInstantCameraArray()
        */
        CBaslerCameraLinkInstantCameraArray() {}
        /*!
            \copybrief CInstantCameraArray::CInstantCameraArray( size_t)
            \copydetails CInstantCameraArray::CInstantCameraArray( size_t)
        */
        CBaslerCameraLinkInstantCameraArray( size_t numberOfCameras) : CDeviceSpecificInstantCameraArrayT<CBaslerCameraLinkInstantCamera>(numberOfCameras) {}

    };

    /**
     * @}
     */
}

#endif /* INCLUDED_BASLERCAMERALINKINSTANTCAMERAARRAY_H_5817072 */
