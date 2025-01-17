

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for ActProgType64.idl:
    Oicf, W1, Zp1, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ActProgType64_i_h__
#define __ActProgType64_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IActProgType64_FWD_DEFINED__
#define __IActProgType64_FWD_DEFINED__
typedef interface IActProgType64 IActProgType64;

#endif 	/* __IActProgType64_FWD_DEFINED__ */


#ifndef __ActProgType64_FWD_DEFINED__
#define __ActProgType64_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActProgType64 ActProgType64;
#else
typedef struct ActProgType64 ActProgType64;
#endif /* __cplusplus */

#endif 	/* __ActProgType64_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IActProgType64_INTERFACE_DEFINED__
#define __IActProgType64_INTERFACE_DEFINED__

/* interface IActProgType64 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IActProgType64;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e59adb99-62fa-4da7-bc3b-be7702395bd4")
    IActProgType64 : public IUnknown
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActNetworkNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActNetworkNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActStationNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActStationNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActUnitNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActUnitNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectUnitNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectUnitNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActIONumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActIONumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPortNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPortNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActBaudRate( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActBaudRate( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDataBits( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDataBits( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActParity( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActParity( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActStopBits( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActStopBits( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActControl( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActControl( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActHostAddress( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActHostAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuTimeOut( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuTimeOut( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActSumCheck( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActSumCheck( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActSourceNetworkNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActSourceNetworkNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActSourceStationNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActSourceStationNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDestinationPortNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDestinationPortNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDestinationIONumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDestinationIONumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActMultiDropChannelNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActMultiDropChannelNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActThroughNetworkType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActThroughNetworkType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActIntelligentPreferenceBit( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActIntelligentPreferenceBit( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDidPropertyBit( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDidPropertyBit( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActDsidPropertyBit( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActDsidPropertyBit( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPacketType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPacketType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPassword( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActTargetSimulator( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActTargetSimulator( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActUnitType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActUnitType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActProtocolType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActProtocolType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( 
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock2( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT *lplData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock2( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT *lplData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom2( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT *lplData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom2( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT *lplData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CheckControl( 
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCpuType( 
            /* [string][out] */ BSTR *szCpuName,
            /* [out] */ LONG *lplCpuCode,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCpuStatus( 
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceBlock( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceBlock( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadDeviceRandom( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteDeviceRandom( 
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ReadBuffer( 
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteBuffer( 
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetClockData( 
            /* [out] */ SHORT *lpsYear,
            /* [out] */ SHORT *lpsMonth,
            /* [out] */ SHORT *lpsDay,
            /* [out] */ SHORT *lpsDayOfWeek,
            /* [out] */ SHORT *lpsHour,
            /* [out] */ SHORT *lpsMinute,
            /* [out] */ SHORT *lpsSecond,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetClockData( 
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice( 
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDevice2( 
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDevice2( 
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IActProgType64Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IActProgType64 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IActProgType64 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IActProgType64 * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActNetworkNumber )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActNetworkNumber )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActStationNumber )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActStationNumber )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActUnitNumber )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActUnitNumber )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActConnectUnitNumber )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActConnectUnitNumber )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActIONumber )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActIONumber )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActCpuType )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActCpuType )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActPortNumber )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActPortNumber )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActBaudRate )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActBaudRate )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDataBits )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDataBits )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActParity )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActParity )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActStopBits )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActStopBits )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActControl )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActControl )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActHostAddress )( 
            IActProgType64 * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActHostAddress )( 
            IActProgType64 * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActCpuTimeOut )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActCpuTimeOut )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActTimeOut )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActTimeOut )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActSumCheck )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActSumCheck )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActSourceNetworkNumber )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActSourceNetworkNumber )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActSourceStationNumber )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActSourceStationNumber )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDestinationPortNumber )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDestinationPortNumber )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDestinationIONumber )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDestinationIONumber )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActMultiDropChannelNumber )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActMultiDropChannelNumber )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActThroughNetworkType )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActThroughNetworkType )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActIntelligentPreferenceBit )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActIntelligentPreferenceBit )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDidPropertyBit )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDidPropertyBit )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDsidPropertyBit )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDsidPropertyBit )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActPacketType )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActPacketType )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActPassword )( 
            IActProgType64 * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActPassword )( 
            IActProgType64 * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActTargetSimulator )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActTargetSimulator )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActUnitType )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActUnitType )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActProtocolType )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActProtocolType )( 
            IActProgType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadDeviceBlock2 )( 
            IActProgType64 * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteDeviceBlock2 )( 
            IActProgType64 * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadDeviceRandom2 )( 
            IActProgType64 * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteDeviceRandom2 )( 
            IActProgType64 * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CheckControl )( 
            IActProgType64 * This,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCpuType )( 
            IActProgType64 * This,
            /* [string][out] */ BSTR *szCpuName,
            /* [out] */ LONG *lplCpuCode,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCpuStatus )( 
            IActProgType64 * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadDeviceBlock )( 
            IActProgType64 * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteDeviceBlock )( 
            IActProgType64 * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadDeviceRandom )( 
            IActProgType64 * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteDeviceRandom )( 
            IActProgType64 * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadBuffer )( 
            IActProgType64 * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteBuffer )( 
            IActProgType64 * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetClockData )( 
            IActProgType64 * This,
            /* [out] */ SHORT *lpsYear,
            /* [out] */ SHORT *lpsMonth,
            /* [out] */ SHORT *lpsDay,
            /* [out] */ SHORT *lpsDayOfWeek,
            /* [out] */ SHORT *lpsHour,
            /* [out] */ SHORT *lpsMinute,
            /* [out] */ SHORT *lpsSecond,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetClockData )( 
            IActProgType64 * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDevice )( 
            IActProgType64 * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDevice )( 
            IActProgType64 * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDevice2 )( 
            IActProgType64 * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDevice2 )( 
            IActProgType64 * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        END_INTERFACE
    } IActProgType64Vtbl;

    interface IActProgType64
    {
        CONST_VTBL struct IActProgType64Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActProgType64_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IActProgType64_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IActProgType64_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IActProgType64_get_ActNetworkNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActNetworkNumber(This,pVal) ) 

#define IActProgType64_put_ActNetworkNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActNetworkNumber(This,newVal) ) 

#define IActProgType64_get_ActStationNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActStationNumber(This,pVal) ) 

#define IActProgType64_put_ActStationNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActStationNumber(This,newVal) ) 

#define IActProgType64_get_ActUnitNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActUnitNumber(This,pVal) ) 

#define IActProgType64_put_ActUnitNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActUnitNumber(This,newVal) ) 

#define IActProgType64_get_ActConnectUnitNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal) ) 

#define IActProgType64_put_ActConnectUnitNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal) ) 

#define IActProgType64_get_ActIONumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActIONumber(This,pVal) ) 

#define IActProgType64_put_ActIONumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActIONumber(This,newVal) ) 

#define IActProgType64_get_ActCpuType(This,pVal)	\
    ( (This)->lpVtbl -> get_ActCpuType(This,pVal) ) 

#define IActProgType64_put_ActCpuType(This,newVal)	\
    ( (This)->lpVtbl -> put_ActCpuType(This,newVal) ) 

#define IActProgType64_get_ActPortNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActPortNumber(This,pVal) ) 

#define IActProgType64_put_ActPortNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActPortNumber(This,newVal) ) 

#define IActProgType64_get_ActBaudRate(This,pVal)	\
    ( (This)->lpVtbl -> get_ActBaudRate(This,pVal) ) 

#define IActProgType64_put_ActBaudRate(This,newVal)	\
    ( (This)->lpVtbl -> put_ActBaudRate(This,newVal) ) 

#define IActProgType64_get_ActDataBits(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDataBits(This,pVal) ) 

#define IActProgType64_put_ActDataBits(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDataBits(This,newVal) ) 

#define IActProgType64_get_ActParity(This,pVal)	\
    ( (This)->lpVtbl -> get_ActParity(This,pVal) ) 

#define IActProgType64_put_ActParity(This,newVal)	\
    ( (This)->lpVtbl -> put_ActParity(This,newVal) ) 

#define IActProgType64_get_ActStopBits(This,pVal)	\
    ( (This)->lpVtbl -> get_ActStopBits(This,pVal) ) 

#define IActProgType64_put_ActStopBits(This,newVal)	\
    ( (This)->lpVtbl -> put_ActStopBits(This,newVal) ) 

#define IActProgType64_get_ActControl(This,pVal)	\
    ( (This)->lpVtbl -> get_ActControl(This,pVal) ) 

#define IActProgType64_put_ActControl(This,newVal)	\
    ( (This)->lpVtbl -> put_ActControl(This,newVal) ) 

#define IActProgType64_get_ActHostAddress(This,pVal)	\
    ( (This)->lpVtbl -> get_ActHostAddress(This,pVal) ) 

#define IActProgType64_put_ActHostAddress(This,newVal)	\
    ( (This)->lpVtbl -> put_ActHostAddress(This,newVal) ) 

#define IActProgType64_get_ActCpuTimeOut(This,pVal)	\
    ( (This)->lpVtbl -> get_ActCpuTimeOut(This,pVal) ) 

#define IActProgType64_put_ActCpuTimeOut(This,newVal)	\
    ( (This)->lpVtbl -> put_ActCpuTimeOut(This,newVal) ) 

#define IActProgType64_get_ActTimeOut(This,pVal)	\
    ( (This)->lpVtbl -> get_ActTimeOut(This,pVal) ) 

#define IActProgType64_put_ActTimeOut(This,newVal)	\
    ( (This)->lpVtbl -> put_ActTimeOut(This,newVal) ) 

#define IActProgType64_get_ActSumCheck(This,pVal)	\
    ( (This)->lpVtbl -> get_ActSumCheck(This,pVal) ) 

#define IActProgType64_put_ActSumCheck(This,newVal)	\
    ( (This)->lpVtbl -> put_ActSumCheck(This,newVal) ) 

#define IActProgType64_get_ActSourceNetworkNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActSourceNetworkNumber(This,pVal) ) 

#define IActProgType64_put_ActSourceNetworkNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActSourceNetworkNumber(This,newVal) ) 

#define IActProgType64_get_ActSourceStationNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActSourceStationNumber(This,pVal) ) 

#define IActProgType64_put_ActSourceStationNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActSourceStationNumber(This,newVal) ) 

#define IActProgType64_get_ActDestinationPortNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDestinationPortNumber(This,pVal) ) 

#define IActProgType64_put_ActDestinationPortNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDestinationPortNumber(This,newVal) ) 

#define IActProgType64_get_ActDestinationIONumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal) ) 

#define IActProgType64_put_ActDestinationIONumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal) ) 

#define IActProgType64_get_ActMultiDropChannelNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal) ) 

#define IActProgType64_put_ActMultiDropChannelNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal) ) 

#define IActProgType64_get_ActThroughNetworkType(This,pVal)	\
    ( (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal) ) 

#define IActProgType64_put_ActThroughNetworkType(This,newVal)	\
    ( (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal) ) 

#define IActProgType64_get_ActIntelligentPreferenceBit(This,pVal)	\
    ( (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal) ) 

#define IActProgType64_put_ActIntelligentPreferenceBit(This,newVal)	\
    ( (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal) ) 

#define IActProgType64_get_ActDidPropertyBit(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal) ) 

#define IActProgType64_put_ActDidPropertyBit(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal) ) 

#define IActProgType64_get_ActDsidPropertyBit(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal) ) 

#define IActProgType64_put_ActDsidPropertyBit(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal) ) 

#define IActProgType64_get_ActPacketType(This,pVal)	\
    ( (This)->lpVtbl -> get_ActPacketType(This,pVal) ) 

#define IActProgType64_put_ActPacketType(This,newVal)	\
    ( (This)->lpVtbl -> put_ActPacketType(This,newVal) ) 

#define IActProgType64_get_ActPassword(This,pVal)	\
    ( (This)->lpVtbl -> get_ActPassword(This,pVal) ) 

#define IActProgType64_put_ActPassword(This,newVal)	\
    ( (This)->lpVtbl -> put_ActPassword(This,newVal) ) 

#define IActProgType64_get_ActTargetSimulator(This,pVal)	\
    ( (This)->lpVtbl -> get_ActTargetSimulator(This,pVal) ) 

#define IActProgType64_put_ActTargetSimulator(This,newVal)	\
    ( (This)->lpVtbl -> put_ActTargetSimulator(This,newVal) ) 

#define IActProgType64_get_ActUnitType(This,pVal)	\
    ( (This)->lpVtbl -> get_ActUnitType(This,pVal) ) 

#define IActProgType64_put_ActUnitType(This,newVal)	\
    ( (This)->lpVtbl -> put_ActUnitType(This,newVal) ) 

#define IActProgType64_get_ActProtocolType(This,pVal)	\
    ( (This)->lpVtbl -> get_ActProtocolType(This,pVal) ) 

#define IActProgType64_put_ActProtocolType(This,newVal)	\
    ( (This)->lpVtbl -> put_ActProtocolType(This,newVal) ) 

#define IActProgType64_Open(This,lplReturnCode)	\
    ( (This)->lpVtbl -> Open(This,lplReturnCode) ) 

#define IActProgType64_Close(This,lplReturnCode)	\
    ( (This)->lpVtbl -> Close(This,lplReturnCode) ) 

#define IActProgType64_ReadDeviceBlock2(This,szDevice,lSize,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lplData,lplReturnCode) ) 

#define IActProgType64_WriteDeviceBlock2(This,szDevice,lSize,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lplData,lplReturnCode) ) 

#define IActProgType64_ReadDeviceRandom2(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lplData,lplReturnCode) ) 

#define IActProgType64_WriteDeviceRandom2(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lplData,lplReturnCode) ) 

#define IActProgType64_CheckControl(This,lplReturnCode)	\
    ( (This)->lpVtbl -> CheckControl(This,lplReturnCode) ) 

#define IActProgType64_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    ( (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode) ) 

#define IActProgType64_SetCpuStatus(This,lOperation,lplReturnCode)	\
    ( (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode) ) 

#define IActProgType64_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode) ) 

#define IActProgType64_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode) ) 

#define IActProgType64_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode) ) 

#define IActProgType64_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode) ) 

#define IActProgType64_ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    ( (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode) ) 

#define IActProgType64_WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    ( (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode) ) 

#define IActProgType64_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    ( (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode) ) 

#define IActProgType64_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    ( (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode) ) 

#define IActProgType64_SetDevice(This,szDevice,lData,lplReturnCode)	\
    ( (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode) ) 

#define IActProgType64_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode) ) 

#define IActProgType64_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    ( (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode) ) 

#define IActProgType64_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    ( (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActProgType64_INTERFACE_DEFINED__ */



#ifndef __ActProgType64Lib_LIBRARY_DEFINED__
#define __ActProgType64Lib_LIBRARY_DEFINED__

/* library ActProgType64Lib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ActProgType64Lib;

EXTERN_C const CLSID CLSID_ActProgType64;

#ifdef __cplusplus

class DECLSPEC_UUID("a6ebe2ca-37b5-47c8-937b-d04425aff7dc")
ActProgType64;
#endif
#endif /* __ActProgType64Lib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


