//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2008-2017 Basler AG
//  http://www.baslerweb.com
//  Author:  JS
//-----------------------------------------------------------------------------
/*!
\file     PylonLinkage.h
\brief    Adds the pylon (and GenICam) libs to the linker comment record in the object file
*/

#ifndef PYLON_LINKAGE_H_INCLUDED_
#define PYLON_LINKAGE_H_INCLUDED_

#pragma once

// needed for COMPILER/COMPILER_STR
#include <pylon/Platform.h>

#if defined(PYLON_WIN_BUILD)

#define PYLON_VERSION_SUFFIX "_v5_0"

#if !defined(PYLON_BUILD_DEBUG)
#   if !defined(GENICAM_USER_ALWAYS_LINK_RELEASE)
#       define GENICAM_USER_ALWAYS_LINK_RELEASE
#   endif
#endif

// should be already included (needed for CONFIGURATION, GENICAM_COMPILER_STR)
#include <GenICamVersion.h>
#include <Base/GCLinkage.h>

#define PYLON_COMPILER_STR GENICAM_COMPILER_STR

//////////////////////////////////////////////////////////////////////////////
// create the Pylon suffix

// The name consits of the following parts
//    PylonBase_MDd_VC120.lib
//    [   1   ] [2] [ 3] [4]
//    [module ][  suffix   ]
//    [     lib name       ]
//    1 = module name
//    2 = configuration
//    3 = compiler version
//    4 = extension
#define PYLON_SUFFIX( config, compiler, extension ) "_" config "_" compiler "." extension

#if (defined(_DEBUG) || defined(DEBUG)) && defined(PYLON_BUILD_DEBUG)
#   define PYLON_CONFIGURATION "MDd"
#else
#   define PYLON_CONFIGURATION "MD"
#endif

// generic
#define PYLON_LIB_SUFFIX        PYLON_SUFFIX( PYLON_CONFIGURATION, PYLON_COMPILER_STR PYLON_VERSION_SUFFIX, "lib" )
#define PYLON_DLL_SUFFIX        PYLON_SUFFIX( PYLON_CONFIGURATION, PYLON_COMPILER_STR PYLON_VERSION_SUFFIX, "dll" )

// names for Transport Layer
#define PYLON_TL_LIB_SUFFIX     PYLON_SUFFIX( PYLON_CONFIGURATION, PYLON_COMPILER_STR PYLON_VERSION_SUFFIX "_TL", "lib" )
#define PYLON_TL_DLL_SUFFIX     PYLON_SUFFIX( PYLON_CONFIGURATION, PYLON_COMPILER_STR PYLON_VERSION_SUFFIX "_TL", "dll" )


//////////////////////////////////////////////////////////////////////////////
//
#define PYLON_LIB_NAME_NAKED( module )  module PYLON_SUFFIX( PYLON_CONFIGURATION, PYLON_COMPILER_STR, "lib" )
#define PYLON_DLL_NAME_NAKED( module )  module PYLON_SUFFIX( PYLON_CONFIGURATION, PYLON_COMPILER_STR, "dll" )

#define PYLON_LIB_NAME( module )  module PYLON_SUFFIX( PYLON_CONFIGURATION, PYLON_COMPILER_STR PYLON_VERSION_SUFFIX, "lib" )
#define PYLON_DLL_NAME( module )  module PYLON_SUFFIX( PYLON_CONFIGURATION, PYLON_COMPILER_STR PYLON_VERSION_SUFFIX, "dll" )

#define PYLON_TL_LIB_NAME( module )  module PYLON_TL_LIB_SUFFIX
#define PYLON_TL_DLL_NAME( module )  module PYLON_TL_DLL_SUFFIX

#endif

#endif
