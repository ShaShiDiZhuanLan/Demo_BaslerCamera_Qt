/*-----------------------------------------------------------------------------
    Basler pylon C SDK
    Copyright (c) 2012-2017 Basler AG
    http://www.baslerweb.com
-----------------------------------------------------------------------------*/
/**
  \file
  \brief GenApi C bindings  - 32 bit functions.
*/

#ifndef GenApiC32BitMethods_h__
#define GenApiC32BitMethods_h__

#include <genapic/GenApiCDefines.h>

#pragma pack(push, GENAPIC_PACKING)

#include <genapic/GenApiCTypes.h>

#ifdef __cplusplus
// avoid namespace ambiguities between std::_Bool (from yvals.h) and ::_Bool (from GenApiCTypes.h)
#  ifdef _MSC_VER
#    define _Bool ::_Bool
#    define PYLONC_BOOL_DEFINED
#  endif

extern "C"
{
#endif /* __cplusplus */

        GENAPIC_API GENAPIC_RESULT GENAPIC_CC GenApiNodeGetPollingTimeInt32( NODE_HANDLE hNode,  int32_t *pollingTime );
        GENAPIC_API GENAPIC_RESULT GENAPIC_CC GenApiIntegerSetValueInt32( NODE_HANDLE hNode, int32_t value );
        GENAPIC_API GENAPIC_RESULT GENAPIC_CC GenApiIntegerSetValueExInt32( NODE_HANDLE hNode, _Bool verify, int32_t value );
        GENAPIC_API GENAPIC_RESULT GENAPIC_CC GenApiIntegerGetValueInt32( NODE_HANDLE hNode,  int32_t* pValue );
        GENAPIC_API GENAPIC_RESULT GENAPIC_CC GenApiIntegerGetValueExInt32( NODE_HANDLE hNode, _Bool verify, int32_t* pValue );
        GENAPIC_API GENAPIC_RESULT GENAPIC_CC GenApiIntegerGetMinInt32( NODE_HANDLE hNode,  int32_t* pValue );
        GENAPIC_API GENAPIC_RESULT GENAPIC_CC GenApiIntegerGetMaxInt32( NODE_HANDLE hNode,  int32_t* pValue );
        GENAPIC_API GENAPIC_RESULT GENAPIC_CC GenApiIntegerGetIncInt32( NODE_HANDLE hNode,  int32_t* pValue );
        GENAPIC_API GENAPIC_RESULT GENAPIC_CC GenApiNodeMapPollInt32( NODEMAP_HANDLE hMap, int32_t timestamp);

#ifdef GENAPIC_WIN_BUILD
        /* special functions for VB since it doesn't support 64-bit values */
        GENAPIC_API GENAPIC_RESULT GENAPIC_CC GenApiPortReadVb(NODE_HANDLE hNode, void* pBuffer, int32_t AddressHi, uint32_t AddressLo, uint32_t Length);
        GENAPIC_API GENAPIC_RESULT GENAPIC_CC GenApiPortWriteVb(NODE_HANDLE hNode, const void* pBuffer, int32_t AddressHi, uint32_t AddressLo, uint32_t Length);
#endif
#ifdef __cplusplus
} /* extern "C" */

#  ifdef PYLONC_BOOL_DEFINED
#    undef _Bool
#    undef PYLONC_BOOL_DEFINED
#  endif

#endif /* __cplusplus */

#pragma pack(pop)

#endif /* GenApiC32BitMethods_h__ */
