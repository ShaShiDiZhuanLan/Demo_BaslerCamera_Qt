//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2006-2017 Basler AG
//  http://www.baslerweb.com
//  Author:  AH
//-----------------------------------------------------------------------------
/*!
\file
\brief Definition of the IProperties interface and the CInfoBase class
*/

#ifndef __INFO_H__
#define __INFO_H__

#if _MSC_VER > 1000
#pragma once
#endif

#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#include <pylon/stdinclude.h>
#include <pylon/PylonBase.h>

namespace Pylon
{
    /*!
        \interface IProperties
        \brief interface for a property container
    */
    interface PUBLIC_INTERFACE IProperties
    {
        /// Retrieves a list of property names
        virtual int GetPropertyNames( StringList_t & ) const = 0;
        /// Returns true if a property with the provided name is available
        virtual bool GetPropertyAvailable( const String_t& Name) const = 0;
        /// Retrieves a property value
        virtual bool GetPropertyValue( const String_t& Name, String_t& Value ) const = 0;
        /// Modifies a property value
        virtual IProperties& SetPropertyValue( const String_t& Name, const String_t& Value) = 0;
        /// Returns true if all properties of the subset can be found and the values are equal
        /// The implementing container may use special knowledge on how to compare the values
        /// For instance for IP adresses, 192.2.3.45 == 192.2.3.0x2D
        virtual bool IsSubset( const IProperties& Subset) const = 0;

    };

    namespace Key
    {
        ///Identifies the human readable name of the device.
        const char* const FriendlyNameKey = "FriendlyName";
        ///Identifies the full name identifying the device.
        const char* const FullNameKey = "FullName";
        ///Identifies the vendor name of the device.
        const char* const VendorNameKey = "VendorName";
        ///Identifies the device class device, e.g. Basler1394.
        const char* const DeviceClassKey = "DeviceClass";
    }

    class CInfoImpl;

    /*!
    \brief Base implementation for PYLON info container.

    Info container allow a generic access to implemented properties. All
    Properties and their values can be accessed without knowing them in
    advance. It is possible to enumerate all properties available and corresponding
    values. Properties and values are represented as String_t. The normal usage
    is to have enumerators that create the info objects and clients that read only.

    If the type of the info object is known before client can use specific
    accessor function to retrieve the property values

    */
    class PYLONBASE_API CInfoBase : public IProperties
    {
    public:
        static const char* const PropertyNotAvailable;

        CInfoBase& operator=(const CInfoBase&);

        /// compare two info objects
        bool operator==( const CInfoBase& rhs) const;

        /*!
        \brief Compares CInfoBase objects by device class.
        \param[in]  rhs The right-hand side object of the comparison.
        \return Returns true according to this rule: USB < GigE < CameraLink < 1394 < Bcon < Less than compare of device class text < CamEmu.
        \error
        Does not throw C++ exceptions.
        */
        bool operator < (const CInfoBase& rhs) const;

        /* The underlying implementation does not need to support all the listed properties.
        The properties that are not supported always have the value "N/A" which is the value of CInfoBase::PropertyNotAvailable */

        ///Retrieves the human readable name of the device.
        ///This property is identified by Key::FriendlyNameKey.
        String_t GetFriendlyName() const;
        ///Sets the above property.
        CInfoBase& SetFriendlyName( const String_t& FriendlyNameValue);
        ///Returns true if the above property is available.
        bool IsFriendlyNameAvailable() const;

        ///Retrieves the full name identifying the device.
        ///This property is identified by Key::FullNameKey.
        String_t GetFullName() const;
        ///Sets the above property.
        CInfoBase& SetFullName( const String_t& FullNameValue);
        ///Returns true if the above property is available.
        bool IsFullNameAvailable() const;

        ///Retrieves the vendor name of the device.
        ///This property is identified by Key::VendorNameKey.
        String_t GetVendorName() const;
        ///Sets the above property.
        CInfoBase& SetVendorName( const String_t& VendorNameValue);
        ///Returns true if the above property is available.
        bool IsVendorNameAvailable() const;

        ///Retrieves the device class device, e.g. Basler1394.
        ///This property is identified by Key::DeviceClassKey.
        String_t GetDeviceClass() const;
        ///Sets the above property.
        CInfoBase& SetDeviceClass( const String_t& DeviceClassValue);
        ///Returns true if the above property is available.
        bool IsDeviceClassAvailable() const;

    public:
        static const char* GetPropertyNotAvailable();
        virtual int GetPropertyNames( StringList_t & ) const;
        virtual bool GetPropertyAvailable( const String_t& Name) const;
        /* Returns the value of the property if this property is supported by the underlying implementation or "N/A". */
        virtual bool GetPropertyValue( const String_t& Name, String_t& Value ) const;
        virtual IProperties& SetPropertyValue( const String_t& Name, const String_t& Value);
        virtual bool IsUserProvided() const;
        virtual bool IsSubset( const IProperties& Subset) const;

    protected:
        CInfoBase();
        CInfoBase( const CInfoBase&);
        virtual ~CInfoBase();

    protected:
        CInfoImpl*  m_pImpl;
    };
}

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif
