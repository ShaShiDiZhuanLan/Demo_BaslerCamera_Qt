//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2010-2017 Basler AG
//  http://www.baslerweb.com
//  Author:  AH
//-----------------------------------------------------------------------------
/*!
\file
\brief Declaration of the interface information class.
*/

#ifndef __INTERFACE_INFO_H__
#define __INTERFACE_INFO_H__

#if _MSC_VER > 1000
#pragma once
#endif

#include <pylon/stdinclude.h>
#include <pylon/Info.h>

namespace Pylon
{

    /**
    \ingroup PYLON_PUBLIC

    \brief Class used for storing information about an interface object provided by a transport layer.

    Enumerating the available Transport Layer Interface objects returns a list of
    CInterface objects (Pylon::InterfaceInfoList_t). A CInterfaceInfo object holds information
    about the enumerated interface.
    */
    class PYLONBASE_API CInterfaceInfo : public CInfoBase
    {
    };



}

#endif
