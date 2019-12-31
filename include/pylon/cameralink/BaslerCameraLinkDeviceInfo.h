//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2007-2017 Basler AG
//  http://www.baslerweb.com
//  Author:  JS
//-----------------------------------------------------------------------------
/*!
\file
\brief    Definition of CPylonPylonCLSerDeviceInfo
*/


#if _MSC_VER > 1000
#pragma once
#endif //_MSC_VER > 1000

#ifndef PYLONCLSERDEVICEINFO_H__
#define PYLONCLSERDEVICEINFO_H__

#if _MSC_VER > 1000
#pragma once
#endif //_MSC_VER > 1000

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
        ///Identifies the ID of the serial port the device is connected to.
        const char* const PortIDKey = "PortID";
        ///Identifies the device ID.
        const char* const DeviceIDKey = "DeviceID";
        ///Identifies the initial baud rate of the serial port the device is connected to.
        const char* const InitialBaudRateKey = "InitialBaudRate";
        ///Identifies the device xml file override used. Internal use only.
        const char* const DeviceXMLFileOverrideKey = "DeviceXMLFileOverride";
        ///Identifies the device specific string. Internal use only.
        const char* const DeviceSpecificStringKey = "DeviceSpecificString";
        ///Identifies the port specific string of the device. Internal use only.
        const char* const PortSpecificStringKey = "PortSpecificString";
    }

    /*!
    \brief PylonCLSer specific Device Info object.
    \ingroup Pylon_TransportLayer
    */
    class PYLONBASE_API CBaslerCameraLinkDeviceInfo : public Pylon::CDeviceInfo
    {
    public:
        CBaslerCameraLinkDeviceInfo();
        CBaslerCameraLinkDeviceInfo(const CDeviceInfo& di);
        virtual ~CBaslerCameraLinkDeviceInfo();

        /* The underlying implementation does not need to support all the listed properties.
        The properties that are not supported always have the value "N/A" which is the value of CInfoBase::PropertyNotAvailable */

        ///Retrieves the ID of the serial port the device is connected to.
        ///This property is identified by Key::PortIDKey.
        String_t GetPortID() const;
        ///Sets the above property.
        CBaslerCameraLinkDeviceInfo& SetPortID( const String_t& PortIDValue);
        ///Returns true if the above property is available.
        bool IsPortIDAvailable() const;

        ///Retrieves the device ID.
        ///This property is identified by Key::DeviceIDKey.
        String_t GetDeviceID() const;
        ///Sets the above property.
        CBaslerCameraLinkDeviceInfo& SetDeviceID( const String_t& DeviceIDValue);
        ///Returns true if the above property is available.
        bool IsDeviceIDAvailable() const;

        ///Retrieves the initial baud rate of the serial port the device is connected to.
        ///This property is identified by Key::InitialBaudRateKey.
        String_t GetInitialBaudRate() const;
        ///Sets the above property.
        CBaslerCameraLinkDeviceInfo& SetInitialBaudRate( const String_t& InitialBaudRateValue);
        ///Returns true if the above property is available.
        bool IsInitialBaudRateAvailable() const;

        ///Retrieves the device xml file override used. Internal use only.
        ///This property is identified by Key::DeviceXMLFileOverrideKey.
        String_t GetDeviceXMLFileOverride() const;
        ///Sets the above property.
        CBaslerCameraLinkDeviceInfo& SetDeviceXMLFileOverride( const String_t& DeviceXMLFileOverrideValue);
        ///Returns true if the above property is available.
        bool IsDeviceXMLFileOverrideAvailable() const;

        ///Retrieves the device specific string. Internal use only.
        ///This property is identified by Key::DeviceSpecificStringKey.
        String_t GetDeviceSpecificString() const;
        ///Sets the above property.
        CBaslerCameraLinkDeviceInfo& SetDeviceSpecificString( const String_t& DeviceSpecificStringValue);
        ///Returns true if the above property is available.
        bool IsDeviceSpecificStringAvailable() const;

        ///Retrieves the port specific string of the device. Internal use only.
        ///This property is identified by Key::PortSpecificStringKey.
        String_t GetPortSpecificString() const;
        ///Sets the above property.
        CBaslerCameraLinkDeviceInfo& SetPortSpecificString( const String_t& PortSpecificStringValue);
        ///Returns true if the above property is available.
        bool IsPortSpecificStringAvailable() const;
    };
}

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif // PYLONCLSERDEVICEINFO_H__
