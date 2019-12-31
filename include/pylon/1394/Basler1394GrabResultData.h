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

#ifndef INCLUDED_BASLER1394GRABRESULTDATA_H_3152277
#define INCLUDED_BASLER1394GRABRESULTDATA_H_3152277

#include <pylon/1394/_IIDC1394ChunkData.h>
#include <pylon/GrabResultData.h>

namespace Pylon
{
    /** \addtogroup Pylon_InstantCameraApi1394
     * @{
     */

    /// The IEEE 1394 specific grab result data class.
    class CBasler1394GrabResultData : public CGrabResultData, public Basler_IIDC1394ChunkData::CIIDC1394ChunkData_Params
    {
    protected:
        // Internal use only. The grab result data class should only be created by the instant camera class.
        friend class CBasler1394InstantCamera;
        CBasler1394GrabResultData()
        {
        }

        // Internal use only.
        virtual void Destroy()
        {
            delete this;
        }

        // Internal use only.
        virtual void Initialize()
        {
            _Initialize( &GetChunkDataNodeMap());
        }
    };

    /**
     * @}
     */
} // namespace Pylon

#endif /* INCLUDED_BASLER1394GRABRESULTDATA_H_3152277 */
