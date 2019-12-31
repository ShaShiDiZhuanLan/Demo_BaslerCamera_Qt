//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2006-2017 Basler AG
//  http://www.baslerweb.com
//  Author:  AH
//-----------------------------------------------------------------------------
/*!
\file
\brief Definition of Transport layer information object
*/

#ifndef __TLINFO_H__
#define __TLINFO_H__

#if _MSC_VER > 1000
#pragma once
#endif

#include <pylon/Platform.h>

#ifdef _MSC_VER
#   pragma pack(push, PYLON_PACKING)
#endif /* _MSC_VER */

#include <pylon/stdinclude.h>
#include <pylon/Info.h>

namespace Pylon
{

    /**
        \ingroup Pylon_TransportLayer
        \brief Class used for storing the result of the transport
               layer enumeration process.

    Enumerating the available Transport Layer objects returns a list of
    CTlInfo objects (Pylon::TlInfoList_t). A CTlInfo object holds information
    about the enumerated transport layer.
    */
#ifdef PYLON_UNIX_BUILD
    class PYLONBASE_API CTlInfo : public CInfoBase
#else
    //not exported to get delayed loading to work
    class CTlInfo : public CInfoBase
#endif
    {
    };



}

#ifdef _MSC_VER
#   pragma pack(pop)
#endif /* _MSC_VER */

#endif /* __TLINFO_H__ */
