//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2006-2017 Basler AG
//  http://www.baslerweb.com
//  Author:  Hartmut Nebelung, AH
//-----------------------------------------------------------------------------
/*!
\file
\brief Definition of CGigEDeviceInfo class

This file contains the CBaslerGigEDeviceInfo class and  additional key values
that are used in the CBaslerGigEDeviceInfo class.
*/


#ifndef __BASLERGIGEDEVICEINFO_H__
#define __BASLERGIGEDEVICEINFO_H__

#if _MSC_VER > 1000
#pragma once
#endif //_MSC_VER > 1000

#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#include <pylon/DeviceInfo.h>
#include <pylon/gige/PylonGigE.h>

namespace Pylon
{
    ///This namespace contains keys for accessing the properties of pylon info objects
    namespace Key
    {
        ///Identifies the IP address of the device IP address in a human-readable representation including the port number.
        const char* const AddressKey = "Address";
        ///Identifies the IP address of the device IP address in a human-readable representation.
        const char* const IpAddressKey = "IpAddress";
        ///Identifies the default gateway of the device IP address in a human-readable representation.
        const char* const DefaultGatewayKey = "DefaultGateway";
        ///Identifies the subnet mask of the device IP address in a human-readable representation.
        const char* const SubnetMaskKey = "SubnetMask";
        ///Identifies the subnet address of the device in a human-readable representation.
        const char* const SubnetAddressKey = "SubnetAddress";
        ///Identifies the port number used.
        const char* const PortNrKey = "PortNr";
        ///Identifies the MAC address of the device of the device IP address in a human-readable representation.
        const char* const MacAddressKey = "MacAddress";
        ///Identifies the address of the network interface the device is connected.
        const char* const InterfaceKey = "Interface";
        ///Identifies the persistent IP configuration options.
        const char* const IpConfigOptionsKey = "IpConfigOptions";
        ///Identifies the current IP configuration of the device.
        const char* const IpConfigCurrentKey = "IpConfigCurrent";
    }

    /*!
        \ingroup Pylon_TransportLayer
        \class CBaslerGigEDeviceInfo
        \brief Implementation of the GiGE specific device info object

        Enhances the general CDeviceInfo by the attributes Address and
        Interface. Address is the device IP number, Interface is the IP
        number of the connected interface.
    */
    class PYLONBASE_API CBaslerGigEDeviceInfo : public CDeviceInfo
    {
    public:

        CBaslerGigEDeviceInfo();
        CBaslerGigEDeviceInfo(const CDeviceInfo&);
        virtual ~CBaslerGigEDeviceInfo();

        /* The underlying implementation does not need to support all the listed properties.
        The properties that are not supported always have the value "N/A" which is the value of CInfoBase::PropertyNotAvailable */

        ///Retrieves the IP address the device IP address in a human-readable representation including the port number.
        ///This property is identified by Key::AddressKey.
        String_t GetAddress() const;
        ///Sets the above property.
        CBaslerGigEDeviceInfo& SetAddress( const String_t& AddressValue);
        ///Returns true if the above property is available.
        bool IsAddressAvailable() const;

        ///Retrieves the IP address the device IP address in a human-readable representation.
        ///This property is identified by Key::IpAddressKey.
        String_t GetIpAddress() const;
        ///Sets the above property.
        CBaslerGigEDeviceInfo& SetIpAddress( const String_t& IpAddressValue);
        ///Returns true if the above property is available.
        bool IsIpAddressAvailable() const;

        ///Retrieves the IP address of the subnet.
        /// This property is identified by Key::SubnetAddressKey
        String_t GetSubnetAddress() const;
        ///Sets the above property.
        CBaslerGigEDeviceInfo& SetSubnetAddress( const String_t& SubnetAddressValue );
        ///Returns true if the above property is available.
        bool IsSubnetAddressAvailable() const;

        ///Retrieves the default gateway the device IP address in a human-readable representation.
        ///This property is identified by Key::DefaultGatewayKey.
        String_t GetDefaultGateway() const;
        ///Sets the above property.
        CBaslerGigEDeviceInfo& SetDefaultGateway( const String_t& DefaultGatewayValue);
        ///Returns true if the above property is available.
        bool IsDefaultGatewayAvailable() const;

        ///Retrieves the subnet mask the device IP address in a human-readable representation.
        ///This property is identified by Key::SubnetMaskKey.
        String_t GetSubnetMask() const;
        ///Sets the above property.
        CBaslerGigEDeviceInfo& SetSubnetMask( const String_t& SubnetMaskValue);
        ///Returns true if the above property is available.
        bool IsSubnetMaskAvailable() const;

        ///Retrieves the port number used.
        ///This property is identified by Key::PortNrKey.
        String_t GetPortNr() const;
        ///Sets the above property.
        CBaslerGigEDeviceInfo& SetPortNr( const String_t& PortNrValue);
        ///Returns true if the above property is available.
        bool IsPortNrAvailable() const;

        ///Retrieves the MAC address of the device the device IP address in a human-readable representation.
        ///This property is identified by Key::MacAddressKey.
        String_t GetMacAddress() const;
        ///Sets the above property.
        CBaslerGigEDeviceInfo& SetMacAddress( const String_t& MacAddressValue);
        ///Returns true if the above property is available.
        bool IsMacAddressAvailable() const;

        ///Retrieves the address of the network interface the device is connected.
        ///This property is identified by Key::InterfaceKey.
        String_t GetInterface() const;
        ///Sets the above property.
        CBaslerGigEDeviceInfo& SetInterface( const String_t& InterfaceValue);
        ///Returns true if the above property is available.
        bool IsInterfaceAvailable() const;

        ///Retrieves the persistent IP configuration options.
        ///This property is identified by Key::IpConfigOptionsKey.
        String_t GetIpConfigOptions() const;
        ///Sets the above property.
        CBaslerGigEDeviceInfo& SetIpConfigOptions( const String_t& IpConfigOptionsValue);
        ///Returns true if the above property is available.
        bool IsIpConfigOptionsAvailable() const;

        ///Retrieves the current IP configuration of the device.
        ///This property is identified by Key::IpConfigCurrentKey.
        String_t GetIpConfigCurrent() const;
        ///Sets the above property.
        CBaslerGigEDeviceInfo& SetIpConfigCurrent( const String_t& IpConfigCurrentValue);
        ///Returns true if the above property is available.
        bool IsIpConfigCurrentAvailable() const;

    public:
        //! \brief Returns true when the device is configured for a persistent IP address
        bool IsPersistentIpActive(void) const;

        //! \brief Returns true when the device is configured for using DHCP
        bool IsDhcpActive(void) const;

        //! \brief Returns true when the device is configured for using Auto IP (aka LLA)
        bool IsAutoIpActive(void) const;

        //! \brief Returns true when the device supports configuring a persistent IP address
        bool IsPersistentIpSupported(void) const;

        //! \brief Returns true when the device supports DHCP
        bool IsDhcpSupported(void) const;

        //! \brief Returns true when the device supports Auto IP (aka LLA)
        bool IsAutoIpSupported(void) const;

        //! \brief Returns true when subset, applies special knowledge on how to compare GigE specific values
        virtual bool IsSubset( const IProperties& Subset) const;
    };

}

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif /* __BASLERGIGEDEVICEINFO_H__ */
