//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2006-2017 Basler AG
//  http://www.baslerweb.com
//  Author:  AH
//-----------------------------------------------------------------------------
/*!
\file
\brief Definiton of Transportlayer interface and the common Transportlayer base class
*/

#ifndef __TRANSPORTLAYER__
#define __TRANSPORTLAYER__

#if _MSC_VER>1000
#pragma once
#endif // _MSC_VER>1000

#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#include <GenICamFwd.h>
#include <pylon/stdinclude.h>
#include <pylon/PylonBase.h>
#include <pylon/DeviceFactory.h>
#include <pylon/TlInfo.h>

namespace Pylon
{


    /*!
    \ingroup Pylon_TransportLayer
    \interface ITransportLayer
    \brief The interface of Transport Layer objects

    Transport Layer objects are used for enumerating and creating devices accessible
    by a specific transport layer (like the Pylon1394 or the PylonGigE transport layer).
    */
    interface PUBLIC_INTERFACE ITransportLayer : public IDeviceFactory
    {
        virtual CTlInfo GetTlInfo() const = 0;

        /** \brief Creates and returns an 'empty' Device Info object appropriate
        for the transport layer.

        Device Info objects returned by the CreateDeviceInfo() method are used to create
        devices from device info objects that are not the result of a device enumeration process but are
        provided by the user. The user is responsible for
        filling in the fields of the Device Info object that are needed to identify and create a device.

        Example: To open a GigE device for which the IP address is known, the user lets the Transport Layer object
        create a Device Info object, specifies the IP address and passes the device info object to the
        CreateDevice() method.

        */
        virtual CDeviceInfo CreateDeviceInfo() = 0;

        /** \brief Returns the GenApi node map used for accessing parameters provided by the transport layer.

        \return NULL, if the transport layer doesn't provide parameters, a pointer to the parameter node map otherwise.
        */
        virtual GENAPI_NAMESPACE::INodeMap* GetNodeMap() = 0;

        /** \brief Retrieves a list of available interfaces.

        \note This method is currently only supported by the pylon GenTL consumer transport layer prototype.

        The concept of interfaces is not supported by all transport layers.
        Depending on the transport layer, an interface may represent a frame grabber board, a network card, etc.

        By default, the list passed in will be cleared.

        If the transport layer doesn't support the interface concept, EnumerateInterfaces() always returns 0.

        \param list The list to be filled with interface info objects
        \param addToList If true, found devices will be added to the list instead of deleting the list
        \return Number of interfaces provided by the transport layer.
        */
        virtual int EnumerateInterfaces( InterfaceInfoList_t& list, bool addToList = false ) = 0;


    };


}

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif /* __TRANSPORTLAYER__ */
