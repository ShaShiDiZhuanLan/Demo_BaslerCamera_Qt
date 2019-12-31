//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2017 Basler AG
//  http://www.baslerweb.com
//  Author:  Andreas Gau
//-----------------------------------------------------------------------------
/*!
\file
\brief Pylon GigE specific instant camera array class.
*/

#ifndef INCLUDED_BASLERGIGEINSTANTCAMERAARRAY_H_6278605
#define INCLUDED_BASLERGIGEINSTANTCAMERAARRAY_H_6278605

#include <pylon/gige/BaslerGigEInstantCamera.h>
#include <pylon/private/DeviceSpecificInstantCameraArray.h>

namespace Pylon
{
    /** \addtogroup Pylon_InstantCameraApiGigE
     * @{
     */

    /*!
    \class  CBaslerGigEInstantCameraArray
    \brief  GigE specific instant camera array.

    \threading
        The CBaslerGigEInstantCameraArray class is not thread-safe.
    */
    class CBaslerGigEInstantCameraArray : public CDeviceSpecificInstantCameraArrayT<CBaslerGigEInstantCamera>
    {
    public:
        /*!
            \copybrief CInstantCameraArray::CInstantCameraArray()
            \copydetails CInstantCameraArray::CInstantCameraArray()
        */
        CBaslerGigEInstantCameraArray() {}
        /*!
            \copybrief CInstantCameraArray::CInstantCameraArray( size_t)
            \copydetails CInstantCameraArray::CInstantCameraArray( size_t)
        */
        CBaslerGigEInstantCameraArray( size_t numberOfCameras) : CDeviceSpecificInstantCameraArrayT<CBaslerGigEInstantCamera>(numberOfCameras) {}

    };

    /**
     * @}
     */
} // namespace Pylon

#endif /* INCLUDED_BASLERGIGEINSTANTCAMERAARRAY_H_6278605 */
