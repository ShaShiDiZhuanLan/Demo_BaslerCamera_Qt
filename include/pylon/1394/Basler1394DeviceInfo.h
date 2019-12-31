//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2006-2017 Basler AG
//  http://www.baslerweb.com
//  Author:  Hartmut Nebelung, AH
//-----------------------------------------------------------------------------
/*!
\file
\brief    Definition of CBasler1394CameraInfo
*/


#if _MSC_VER > 1000
#pragma once
#endif //_MSC_VER > 1000

#ifndef __BASLER1394DEVICEINFO_H__
#define __BASLER1394DEVICEINFO_H__

#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#include <pylon/PylonBase.h>
#include <pylon/DeviceInfo.h>

namespace Pylon
{
    namespace Key
    {
        ///Identifies the name of the device used by the underlying device driver. Internal use only.
        const char* const InternalNameKey = "InternalName";
    }
    /*!
    \brief FireWire specific Device Info object. Does not support SerialNumber property.
    \ingroup Pylon_TransportLayer
    */
    class PYLONBASE_API CBasler1394DeviceInfo : public CDeviceInfo
    {
    public:
        CBasler1394DeviceInfo();
        CBasler1394DeviceInfo(const CDeviceInfo&);
        virtual ~CBasler1394DeviceInfo();

        /* The underlying implementation does not need to support all the listed properties.
        The properties that are not supported always have the value "N/A" which is the value of CInfoBase::PropertyNotAvailable */

        ///Retrieves the name of the device used by the underlying device driver. Internal use only.
        ///This property is identified by Key::InternalNameKey.
        String_t GetInternalName() const;
        ///Sets the above property.
        CBasler1394DeviceInfo& SetInternalName( const String_t& InternalNameValue);
        ///Returns true if the above property is available.
        bool IsInternalNameAvailable() const;
    };
}

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif // __BASLER1394DEVICEINFO_H__
