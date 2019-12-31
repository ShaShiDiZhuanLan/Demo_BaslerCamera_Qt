//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2006-2017 Basler AG
//  http://www.baslerweb.com
//  Author:  Hartmut Nebelung, AH
//-----------------------------------------------------------------------------
/*!
\file
\brief Definition of CDeviceInfo class
*/

#ifndef __DEVICEINFO_H__
#define __DEVICEINFO_H__

#if _MSC_VER > 1000
#pragma once
#endif

#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#include <pylon/PylonBase.h>
#include <pylon/stdinclude.h>
#include <pylon/Info.h>

namespace Pylon
{

    ///This namespace contains keys for accessing the properties of pylon info objects
    namespace Key
    {
        ///Identifies the serial number if it supported by the underlying implementation
        const char* const SerialNumberKey = "SerialNumber";
        ///Identifies the user-defined name if present.
        const char* const UserDefinedNameKey = "UserDefinedName";
        ///Identifies the model name of the device.
        const char* const ModelNameKey = "ModelName";
        ///Identifies the version string of the device.
        const char* const DeviceVersionKey = "DeviceVersion";
        ///Identifies the identifier for the transport layer able to create this device.
        const char* const DeviceFactoryKey = "DeviceFactory";
        ///Identifies the source of the XML used to create the node map of this device.
        const char* const XMLSourceKey = "XMLSource";
        ///Identifies the manufacturer info.
        const char* const ManufacturerInfoKey("ManufacturerInfo");
        // Internal use only
        const char* const DeviceIdxKey = "DeviceIdx";
    }

    /// Holds information about an enumerated device.
    /*!
        The device enumeration process creates a list of CDeviceInfo objects
        (Pylon::DeviceInfoList_t). Each CDeviceInfo objects stores information
        about a device. The information is retrieved during the device enumeration process (ITransportLayer::EnumerateDevices resp.
        CTlFactory::EnumerateDevices)

        \ingroup Pylon_TransportLayer
    */
    class PYLONBASE_API CDeviceInfo : public CInfoBase
    {
    public:

        CDeviceInfo();
        CDeviceInfo( const CDeviceInfo& );

        /*!
        \brief Compares CDeviceInfo objects by device class and serial number.
        \param[in]  rhs The right-hand side object of the comparison.
        \return Returns true according to this rule: USB < GigE < CameraLink < 1394 < Bcon < Less than compare of device class text < CamEmu.
                CDeviceInfo objects of the same transport layer are compared by serial number. Numeric serial numbers are less than alphanumeric 
                serial numbers. Two alphanumeric serial numbers return the result of a less than text comparison.
        \error
        Does not throw C++ exceptions.
        */
        bool operator<(const CDeviceInfo& rhs) const;

        /* The underlying implementation does not need to support all the listed properties.
        The properties that are not supported always have the value "N/A" which is the value of CInfoBase::PropertyNotAvailable */

        ///Retrieves the serial number if it supported by the underlying implementation
        ///This property is identified by Key::SerialNumberKey.
        String_t GetSerialNumber() const;
        ///Sets the above property.
        CDeviceInfo& SetSerialNumber(const String_t& SerialNumberValue);
        ///Returns true if the above property is available.
        bool IsSerialNumberAvailable() const;

        ///Retrieves the user-defined name if present.
        ///This property is identified by Key::UserDefinedNameKey.
        String_t GetUserDefinedName() const;
        ///Sets the above property.
        CDeviceInfo& SetUserDefinedName(const String_t& UserDefinedNameValue);
        ///Returns true if the above property is available.
        bool IsUserDefinedNameAvailable() const;

        ///Retrieves the model name of the device.
        ///This property is identified by Key::ModelNameKey.
        String_t GetModelName() const;
        ///Sets the above property.
        CDeviceInfo& SetModelName(const String_t& ModelNameValue);
        ///Returns true if the above property is available.
        bool IsModelNameAvailable() const;

        ///Retrieves the version string of the device.
        ///This property is identified by Key::DeviceVersionKey.
        String_t GetDeviceVersion() const;
        ///Sets the above property.
        CDeviceInfo& SetDeviceVersion(const String_t& DeviceVersionValue);
        ///Returns true if the above property is available.
        bool IsDeviceVersionAvailable() const;

        ///Retrieves the identifier for the transport layer able to create this device.
        ///This property is identified by Key::DeviceFactoryKey.
        String_t GetDeviceFactory() const;
        ///Sets the above property.
        CDeviceInfo& SetDeviceFactory(const String_t& DeviceFactoryValue);
        ///Returns true if the above property is available.
        bool IsDeviceFactoryAvailable() const;

        ///Retrieves the location where the XML file was loaded from.
        ///This property is identified by Key::XMLSourceKey.
        ///You must use the DeviceInfo of an opened IPylonDevice to retrieve this property.
        String_t GetXMLSource() const;
        ///Sets the above property.
        CDeviceInfo& SetXMLSource(const String_t& XMLSource);
        ///Returns true if the above property is available.
        bool IsXMLSourceAvailable() const;

        ///Sets the display friendly name of the device.
        ///This property is identified by Key::FriendlyNameKey.
        ///This method overrides a method of a base class returning a reference to CDeviceInfo
        CDeviceInfo& SetFriendlyName(const String_t& FriendlyNameValue);

        ///Sets the full name identifying the device.
        ///This property is identified by Key::FullNameKey.
        ///This method overrides a method of a base class returning a reference to CDeviceInfo
        CDeviceInfo& SetFullName(const String_t& FullNameValue);

        ///Sets the vendor name of the device.
        ///This property is identified by Key::VendorNameKey.
        ///This method overrides a method of a base class returning a reference to CDeviceInfo
        CDeviceInfo& SetVendorName(const String_t& VendorNameValue);

        ///Sets the device class device, e.g. Basler1394.
        ///This property is identified by Key::DeviceClassKey.
        ///This method overrides a method of a base class returning a reference to CDeviceInfo
        CDeviceInfo& SetDeviceClass(const String_t& DeviceClassValue);

        /// Modifies a property value
        ///This method overrides a method of a base class returning a reference to CDeviceInfo
        virtual CDeviceInfo& SetPropertyValue(const String_t& Name, const String_t& Value)
        {
            CInfoBase::SetPropertyValue(Name, Value);
            return *this;
        }
    };
}

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif //__DEVICEINFO_H__
