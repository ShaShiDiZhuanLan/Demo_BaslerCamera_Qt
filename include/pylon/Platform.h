//-----------------------------------------------------------------------------
//  Basler pylon SDK
//  Copyright (c) 2008-2017 Basler AG
//  http://www.baslerweb.com
//  Author:  Thomas Koeller
//-----------------------------------------------------------------------------
/** \file
\brief Provides platform-specific defines
*/


#if !defined(PYLON_PLATFORM_H)
#define PYLON_PLATFORM_H

#if defined (_MSC_VER) && defined (_WIN32)
// Platform Microsoft windows, Microsoft tool chain



/** \brief Is defined, when using the pylon for Windows API */
#   define PYLON_WIN_BUILD  // we are building for windows

#   define PYLON_HAS_AVI_SUPPORT
#   define PYLON_HAS_MALLOC_H

// define PYLON_XX_BUILD to distinguish between 32 & 64 bit builds
#   if defined(_WIN32) && !defined(_WIN64)
#       define PYLON_32_BUILD
#   elif defined(_WIN32) && defined(_WIN64)
#       define PYLON_64_BUILD
#   else
#       error unsupported wordsize (32/64 platform)
#   endif



#   if defined(PYLON_STATIC)
#       define APIEXPORT
#       define APIIMPORT
#       define PUBLIC_INTERFACE
#   else
#       define APIEXPORT __declspec(dllexport)
#       define APIIMPORT __declspec(dllimport)
#       define PUBLIC_INTERFACE
#   endif

#   if !defined(CDECL)
#       define CDECL
#   endif

#   if defined PYLON_NO_DEPRECATE
#       define PYLON_DEPRECATED(x)
#   else
#       if _MSC_VER >= 1400
#           define PYLON_DEPRECATED(x) __declspec(deprecated(x))
#       else
#           define PYLON_DEPRECATED(x) __declspec(deprecated)
#       endif
#   endif

// packing used for pylon structs/classes
#   define PYLON_PACKING 8

// mark char8_t and uchar8_t as deprecated
// We'll typedef them here again, so can use declspec(deprecated) instead of #deprecated
PYLON_DEPRECATED("The type 'char8_t' is deprecated. Please use 'int8_t' instead.")           typedef char            char8_t;
PYLON_DEPRECATED("The type 'uchar8_t' is deprecated. Please use 'uint8_t' instead.")         typedef unsigned char   uchar8_t;
PYLON_DEPRECATED("The type 'pcchar8_t' is deprecated. Please use 'const char *' instead.")   typedef const char *    pcchar8_t;
PYLON_DEPRECATED("The type 'pchar8_t' is deprecated. Please use 'char *' instead.")          typedef char *          pchar8_t;

#elif (defined(__GNUC__) && defined(__linux__)) || defined(__APPLE__)
// Platform Linux, gcc or Darwin, llvm toolchain

#ifdef __APPLE__
    // Platform Darwin / OS X
#   define PYLON_OSX_BUILD
#   define PYLON_HAS_BYTEORDER

#else
#   define PYLON_LINUX_BUILD
    // Platform Linux

#   define PYLON_HAS_MALLOC_H
#   define PYLON_HAS_BYTESWAP
#   define PYLON_HAS_THREADCAP
#endif

/** \brief Is defined when using the pylon for Unix API (Linux & Darwin / OS X */
#   define PYLON_UNIX_BUILD
#   define PYLON_HAS_POSIX_THREADS

//TODO this works only on a C99 compiler. We must ensure, that things like SIZE_MAX UINTPTR_MAX are always defined
#   define  __STDC_LIMIT_MACROS
#   define  __STDC_CONSTANT_MACROS
#   define  __STDC_FORMAT_MACROS    // for PRI* in inttypes.h

#   include <pylon/api_autoconf.h>
#   include <stdint.h>

// gnu compiler needs explicit visibility of interfaces, so dynamic_cast works
#   define PUBLIC_INTERFACE APIEXPORT

// define PYLON_XX_BUILD to distinguish between 32 & 64 bit builds
// __WORDSIZE is not always defined and sometimes set to 32 on 64 bit platforms. So we prefer other sources.
#   if __GNUC__
#       if __x86_64__ || __ppc64__ || __powerpc64__ || __aarch64__
#           define PYLON_64_BUILD
#       else
#           define PYLON_32_BUILD
#       endif
#   else
    // Fallback to the unsafe wordsize method
#       if __WORDSIZE == 32
#           define PYLON_32_BUILD
#       elif __WORDSIZE == 64
#           define PYLON_64_BUILD
#       else
#           error unsupported wordsize (32/64 platform)
#       endif
#   endif

// packing used for pylon structs/classes
#   define PYLON_PACKING 8

#else

#   error Unsupported platform

#endif

// The GENICAM_BUILD define has been removed in GenICam 3.0.
#if defined(GENICAM_BUILD) && defined(PYLON_WIN_BUILD)
#pragma message("The GENICAM_BUILD define has been deprecated and can therefore be removed.")
#endif

// Check whether the GenICam header (GCLinkage.h) has been included before this one as this leads to wrong DLL suffixes in debug builds.
#if defined(LINKAGE_H) && defined(PYLON_WIN_BUILD) && !defined(GENICAM_NO_AUTO_IMPLIB) && !defined(GENICAM_USER_ALWAYS_LINK_RELEASE) && (defined(_DEBUG) || defined(DEBUG)) && !defined(PYLON_BUILD_DEBUG)
#error You must include pylon/Platform.h (or at least define GENICAM_USER_ALWAYS_LINK_RELEASE) before including any GenICam headers. Note: If you include only pylon/PylonIncludes.h this will be done automatically.
#endif

// Turn off GenICam compiler warning about untested compiler.
#define GENICAM_USER_ACCEPTS_ANY_COMPILER

#endif /* !defined(PYLON_PLATFORM_H) */
