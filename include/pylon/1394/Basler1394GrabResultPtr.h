//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2017 Basler AG
//  http://www.baslerweb.com
//  Author:  Andreas Gau
//-----------------------------------------------------------------------------
/*!
\file
\brief Pylon IEEE 1394 specific grab result data class.
*/

#ifndef INCLUDED_BASLER1394GRABRESULTPTR_H_2158406
#define INCLUDED_BASLER1394GRABRESULTPTR_H_2158406

#include <pylon/1394/Basler1394GrabResultData.h>
#include <pylon/private/DeviceSpecificGrabResultPtr.h>

namespace Pylon
{
    /** \addtogroup Pylon_InstantCameraApi1394
     * @{
     */

    /// The IEEE 1394 specific grab result smart pointer.
    PYLON_DEFINE_DEVICE_SPECIFIC_GRAB_RESULT_PTR( CBasler1394GrabResultPtr, CBasler1394GrabResultData)

     /**
     * @}
     */
} // namespace Pylon

#endif /* INCLUDED_BASLER1394GRABRESULTPTR_H_2158406 */
