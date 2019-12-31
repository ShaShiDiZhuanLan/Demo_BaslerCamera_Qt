//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2017 Basler AG
//  http://www.baslerweb.com
//  Author:  Andreas Gau
//-----------------------------------------------------------------------------
/*!
\file
\brief Pylon IEEE 1394 specific instant camera array class.
*/

#ifndef INCLUDED_BASLER1394INSTANTCAMERAARRAY_H_8675959
#define INCLUDED_BASLER1394INSTANTCAMERAARRAY_H_8675959

#include <pylon/1394/Basler1394InstantCamera.h>
#include <pylon/private/DeviceSpecificInstantCameraArray.h>

namespace Pylon
{
    /** \addtogroup Pylon_InstantCameraApi1394
     * @{
     */

    /*!
    \class  CBasler1394InstantCameraArray
    \brief  IIDC 1394 specific instant camera array

    \threading
        The CBasler1394InstantCameraArray class is not thread-safe.
    */
    class CBasler1394InstantCameraArray : public CDeviceSpecificInstantCameraArrayT<CBasler1394InstantCamera>
    {
    public:
        /*!
            \copybrief CInstantCameraArray::CInstantCameraArray()
            \copydetails CInstantCameraArray::CInstantCameraArray()
        */
        CBasler1394InstantCameraArray() {}
        /*!
            \copybrief CInstantCameraArray::CInstantCameraArray( size_t)
            \copydetails CInstantCameraArray::CInstantCameraArray( size_t)
        */
        CBasler1394InstantCameraArray( size_t numberOfCameras) : CDeviceSpecificInstantCameraArrayT<CBasler1394InstantCamera>(numberOfCameras) {}

    };

    /**
     * @}
     */
} // namespace Pylon

#endif /* INCLUDED_BASLER1394INSTANTCAMERAARRAY_H_8675959 */
