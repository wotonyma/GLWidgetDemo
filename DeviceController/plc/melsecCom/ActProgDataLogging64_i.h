

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for ActProgDataLogging64.idl:
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

#ifndef __ActProgDataLogging64_i_h__
#define __ActProgDataLogging64_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IActProgDataLogging64_FWD_DEFINED__
#define __IActProgDataLogging64_FWD_DEFINED__
typedef interface IActProgDataLogging64 IActProgDataLogging64;

#endif 	/* __IActProgDataLogging64_FWD_DEFINED__ */


#ifndef __ActProgDataLogging64_FWD_DEFINED__
#define __ActProgDataLogging64_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActProgDataLogging64 ActProgDataLogging64;
#else
typedef struct ActProgDataLogging64 ActProgDataLogging64;
#endif /* __cplusplus */

#endif 	/* __ActProgDataLogging64_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IActProgDataLogging64_INTERFACE_DEFINED__
#define __IActProgDataLogging64_INTERFACE_DEFINED__

/* interface IActProgDataLogging64 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IActProgDataLogging64;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ca3932b0-f6a7-4121-94d2-42fd526d20d0")
    IActProgDataLogging64 : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActNetworkNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActNetworkNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActStationNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActStationNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActUnitNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActUnitNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActConnectUnitNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActConnectUnitNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActIONumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActIONumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActPortNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActPortNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActBaudRate( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActBaudRate( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActDataBits( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActDataBits( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActParity( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActParity( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActStopBits( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActStopBits( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActControl( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActControl( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActHostAddress( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActHostAddress( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActCpuTimeOut( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActCpuTimeOut( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActTimeOut( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActTimeOut( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActSumCheck( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActSumCheck( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActSourceNetworkNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActSourceNetworkNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActSourceStationNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActSourceStationNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActDestinationPortNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActDestinationPortNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActDestinationIONumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActDestinationIONumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActMultiDropChannelNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActMultiDropChannelNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActThroughNetworkType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActThroughNetworkType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActIntelligentPreferenceBit( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActIntelligentPreferenceBit( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActDidPropertyBit( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActDidPropertyBit( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActDsidPropertyBit( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActDsidPropertyBit( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActPacketType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActPacketType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActPassword( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActPassword( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActTargetSimulator( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActTargetSimulator( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActUnitType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActUnitType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActProtocolType( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActProtocolType( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Close( 
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReadFirstFile( 
            /* [in] */ BSTR srcDir,
            /* [out] */ BSTR *srcFilename,
            /* [out] */ LONG *srcType,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReadNextFile( 
            /* [out] */ BSTR *srcFilename,
            /* [out] */ LONG *srcType,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ReadClose( 
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetFile( 
            /* [in] */ BSTR srcFileName,
            /* [in] */ BSTR dstFileName,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CheckControl( 
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IActProgDataLogging64Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IActProgDataLogging64 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IActProgDataLogging64 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IActProgDataLogging64 * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActNetworkNumber )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActNetworkNumber )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActStationNumber )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActStationNumber )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActUnitNumber )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActUnitNumber )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActConnectUnitNumber )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActConnectUnitNumber )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActIONumber )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActIONumber )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActCpuType )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActCpuType )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActPortNumber )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActPortNumber )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActBaudRate )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActBaudRate )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDataBits )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDataBits )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActParity )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActParity )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActStopBits )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActStopBits )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActControl )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActControl )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActHostAddress )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActHostAddress )( 
            IActProgDataLogging64 * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActCpuTimeOut )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActCpuTimeOut )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActTimeOut )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActTimeOut )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActSumCheck )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActSumCheck )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActSourceNetworkNumber )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActSourceNetworkNumber )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActSourceStationNumber )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActSourceStationNumber )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDestinationPortNumber )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDestinationPortNumber )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDestinationIONumber )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDestinationIONumber )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActMultiDropChannelNumber )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActMultiDropChannelNumber )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActThroughNetworkType )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActThroughNetworkType )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActIntelligentPreferenceBit )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActIntelligentPreferenceBit )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDidPropertyBit )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDidPropertyBit )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActDsidPropertyBit )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActDsidPropertyBit )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActPacketType )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActPacketType )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActPassword )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActPassword )( 
            IActProgDataLogging64 * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActTargetSimulator )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActTargetSimulator )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActUnitType )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActUnitType )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActProtocolType )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActProtocolType )( 
            IActProgDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ReadFirstFile )( 
            IActProgDataLogging64 * This,
            /* [in] */ BSTR srcDir,
            /* [out] */ BSTR *srcFilename,
            /* [out] */ LONG *srcType,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ReadNextFile )( 
            IActProgDataLogging64 * This,
            /* [out] */ BSTR *srcFilename,
            /* [out] */ LONG *srcType,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ReadClose )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetFile )( 
            IActProgDataLogging64 * This,
            /* [in] */ BSTR srcFileName,
            /* [in] */ BSTR dstFileName,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CheckControl )( 
            IActProgDataLogging64 * This,
            /* [retval][out] */ LONG *lplReturnCode);
        
        END_INTERFACE
    } IActProgDataLogging64Vtbl;

    interface IActProgDataLogging64
    {
        CONST_VTBL struct IActProgDataLogging64Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActProgDataLogging64_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IActProgDataLogging64_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IActProgDataLogging64_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IActProgDataLogging64_get_ActNetworkNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActNetworkNumber(This,pVal) ) 

#define IActProgDataLogging64_put_ActNetworkNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActNetworkNumber(This,newVal) ) 

#define IActProgDataLogging64_get_ActStationNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActStationNumber(This,pVal) ) 

#define IActProgDataLogging64_put_ActStationNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActStationNumber(This,newVal) ) 

#define IActProgDataLogging64_get_ActUnitNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActUnitNumber(This,pVal) ) 

#define IActProgDataLogging64_put_ActUnitNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActUnitNumber(This,newVal) ) 

#define IActProgDataLogging64_get_ActConnectUnitNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActConnectUnitNumber(This,pVal) ) 

#define IActProgDataLogging64_put_ActConnectUnitNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActConnectUnitNumber(This,newVal) ) 

#define IActProgDataLogging64_get_ActIONumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActIONumber(This,pVal) ) 

#define IActProgDataLogging64_put_ActIONumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActIONumber(This,newVal) ) 

#define IActProgDataLogging64_get_ActCpuType(This,pVal)	\
    ( (This)->lpVtbl -> get_ActCpuType(This,pVal) ) 

#define IActProgDataLogging64_put_ActCpuType(This,newVal)	\
    ( (This)->lpVtbl -> put_ActCpuType(This,newVal) ) 

#define IActProgDataLogging64_get_ActPortNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActPortNumber(This,pVal) ) 

#define IActProgDataLogging64_put_ActPortNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActPortNumber(This,newVal) ) 

#define IActProgDataLogging64_get_ActBaudRate(This,pVal)	\
    ( (This)->lpVtbl -> get_ActBaudRate(This,pVal) ) 

#define IActProgDataLogging64_put_ActBaudRate(This,newVal)	\
    ( (This)->lpVtbl -> put_ActBaudRate(This,newVal) ) 

#define IActProgDataLogging64_get_ActDataBits(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDataBits(This,pVal) ) 

#define IActProgDataLogging64_put_ActDataBits(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDataBits(This,newVal) ) 

#define IActProgDataLogging64_get_ActParity(This,pVal)	\
    ( (This)->lpVtbl -> get_ActParity(This,pVal) ) 

#define IActProgDataLogging64_put_ActParity(This,newVal)	\
    ( (This)->lpVtbl -> put_ActParity(This,newVal) ) 

#define IActProgDataLogging64_get_ActStopBits(This,pVal)	\
    ( (This)->lpVtbl -> get_ActStopBits(This,pVal) ) 

#define IActProgDataLogging64_put_ActStopBits(This,newVal)	\
    ( (This)->lpVtbl -> put_ActStopBits(This,newVal) ) 

#define IActProgDataLogging64_get_ActControl(This,pVal)	\
    ( (This)->lpVtbl -> get_ActControl(This,pVal) ) 

#define IActProgDataLogging64_put_ActControl(This,newVal)	\
    ( (This)->lpVtbl -> put_ActControl(This,newVal) ) 

#define IActProgDataLogging64_get_ActHostAddress(This,pVal)	\
    ( (This)->lpVtbl -> get_ActHostAddress(This,pVal) ) 

#define IActProgDataLogging64_put_ActHostAddress(This,newVal)	\
    ( (This)->lpVtbl -> put_ActHostAddress(This,newVal) ) 

#define IActProgDataLogging64_get_ActCpuTimeOut(This,pVal)	\
    ( (This)->lpVtbl -> get_ActCpuTimeOut(This,pVal) ) 

#define IActProgDataLogging64_put_ActCpuTimeOut(This,newVal)	\
    ( (This)->lpVtbl -> put_ActCpuTimeOut(This,newVal) ) 

#define IActProgDataLogging64_get_ActTimeOut(This,pVal)	\
    ( (This)->lpVtbl -> get_ActTimeOut(This,pVal) ) 

#define IActProgDataLogging64_put_ActTimeOut(This,newVal)	\
    ( (This)->lpVtbl -> put_ActTimeOut(This,newVal) ) 

#define IActProgDataLogging64_get_ActSumCheck(This,pVal)	\
    ( (This)->lpVtbl -> get_ActSumCheck(This,pVal) ) 

#define IActProgDataLogging64_put_ActSumCheck(This,newVal)	\
    ( (This)->lpVtbl -> put_ActSumCheck(This,newVal) ) 

#define IActProgDataLogging64_get_ActSourceNetworkNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActSourceNetworkNumber(This,pVal) ) 

#define IActProgDataLogging64_put_ActSourceNetworkNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActSourceNetworkNumber(This,newVal) ) 

#define IActProgDataLogging64_get_ActSourceStationNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActSourceStationNumber(This,pVal) ) 

#define IActProgDataLogging64_put_ActSourceStationNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActSourceStationNumber(This,newVal) ) 

#define IActProgDataLogging64_get_ActDestinationPortNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDestinationPortNumber(This,pVal) ) 

#define IActProgDataLogging64_put_ActDestinationPortNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDestinationPortNumber(This,newVal) ) 

#define IActProgDataLogging64_get_ActDestinationIONumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDestinationIONumber(This,pVal) ) 

#define IActProgDataLogging64_put_ActDestinationIONumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDestinationIONumber(This,newVal) ) 

#define IActProgDataLogging64_get_ActMultiDropChannelNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActMultiDropChannelNumber(This,pVal) ) 

#define IActProgDataLogging64_put_ActMultiDropChannelNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActMultiDropChannelNumber(This,newVal) ) 

#define IActProgDataLogging64_get_ActThroughNetworkType(This,pVal)	\
    ( (This)->lpVtbl -> get_ActThroughNetworkType(This,pVal) ) 

#define IActProgDataLogging64_put_ActThroughNetworkType(This,newVal)	\
    ( (This)->lpVtbl -> put_ActThroughNetworkType(This,newVal) ) 

#define IActProgDataLogging64_get_ActIntelligentPreferenceBit(This,pVal)	\
    ( (This)->lpVtbl -> get_ActIntelligentPreferenceBit(This,pVal) ) 

#define IActProgDataLogging64_put_ActIntelligentPreferenceBit(This,newVal)	\
    ( (This)->lpVtbl -> put_ActIntelligentPreferenceBit(This,newVal) ) 

#define IActProgDataLogging64_get_ActDidPropertyBit(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDidPropertyBit(This,pVal) ) 

#define IActProgDataLogging64_put_ActDidPropertyBit(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDidPropertyBit(This,newVal) ) 

#define IActProgDataLogging64_get_ActDsidPropertyBit(This,pVal)	\
    ( (This)->lpVtbl -> get_ActDsidPropertyBit(This,pVal) ) 

#define IActProgDataLogging64_put_ActDsidPropertyBit(This,newVal)	\
    ( (This)->lpVtbl -> put_ActDsidPropertyBit(This,newVal) ) 

#define IActProgDataLogging64_get_ActPacketType(This,pVal)	\
    ( (This)->lpVtbl -> get_ActPacketType(This,pVal) ) 

#define IActProgDataLogging64_put_ActPacketType(This,newVal)	\
    ( (This)->lpVtbl -> put_ActPacketType(This,newVal) ) 

#define IActProgDataLogging64_get_ActPassword(This,pVal)	\
    ( (This)->lpVtbl -> get_ActPassword(This,pVal) ) 

#define IActProgDataLogging64_put_ActPassword(This,newVal)	\
    ( (This)->lpVtbl -> put_ActPassword(This,newVal) ) 

#define IActProgDataLogging64_get_ActTargetSimulator(This,pVal)	\
    ( (This)->lpVtbl -> get_ActTargetSimulator(This,pVal) ) 

#define IActProgDataLogging64_put_ActTargetSimulator(This,newVal)	\
    ( (This)->lpVtbl -> put_ActTargetSimulator(This,newVal) ) 

#define IActProgDataLogging64_get_ActUnitType(This,pVal)	\
    ( (This)->lpVtbl -> get_ActUnitType(This,pVal) ) 

#define IActProgDataLogging64_put_ActUnitType(This,newVal)	\
    ( (This)->lpVtbl -> put_ActUnitType(This,newVal) ) 

#define IActProgDataLogging64_get_ActProtocolType(This,pVal)	\
    ( (This)->lpVtbl -> get_ActProtocolType(This,pVal) ) 

#define IActProgDataLogging64_put_ActProtocolType(This,newVal)	\
    ( (This)->lpVtbl -> put_ActProtocolType(This,newVal) ) 

#define IActProgDataLogging64_Open(This,lplReturnCode)	\
    ( (This)->lpVtbl -> Open(This,lplReturnCode) ) 

#define IActProgDataLogging64_Close(This,lplReturnCode)	\
    ( (This)->lpVtbl -> Close(This,lplReturnCode) ) 

#define IActProgDataLogging64_ReadFirstFile(This,srcDir,srcFilename,srcType,lplReturnCode)	\
    ( (This)->lpVtbl -> ReadFirstFile(This,srcDir,srcFilename,srcType,lplReturnCode) ) 

#define IActProgDataLogging64_ReadNextFile(This,srcFilename,srcType,lplReturnCode)	\
    ( (This)->lpVtbl -> ReadNextFile(This,srcFilename,srcType,lplReturnCode) ) 

#define IActProgDataLogging64_ReadClose(This,lplReturnCode)	\
    ( (This)->lpVtbl -> ReadClose(This,lplReturnCode) ) 

#define IActProgDataLogging64_GetFile(This,srcFileName,dstFileName,lplReturnCode)	\
    ( (This)->lpVtbl -> GetFile(This,srcFileName,dstFileName,lplReturnCode) ) 

#define IActProgDataLogging64_CheckControl(This,lplReturnCode)	\
    ( (This)->lpVtbl -> CheckControl(This,lplReturnCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActProgDataLogging64_INTERFACE_DEFINED__ */



#ifndef __ActProgDataLogging64Lib_LIBRARY_DEFINED__
#define __ActProgDataLogging64Lib_LIBRARY_DEFINED__

/* library ActProgDataLogging64Lib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ActProgDataLogging64Lib;

EXTERN_C const CLSID CLSID_ActProgDataLogging64;

#ifdef __cplusplus

class DECLSPEC_UUID("c933a0ad-ca4c-4ff3-9587-cd2078728a91")
ActProgDataLogging64;
#endif
#endif /* __ActProgDataLogging64Lib_LIBRARY_DEFINED__ */

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


