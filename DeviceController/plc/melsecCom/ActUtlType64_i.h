

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for ActUtlType64.idl:
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

#ifndef __ActUtlType64_i_h__
#define __ActUtlType64_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IActUtlType64_FWD_DEFINED__
#define __IActUtlType64_FWD_DEFINED__
typedef interface IActUtlType64 IActUtlType64;

#endif 	/* __IActUtlType64_FWD_DEFINED__ */


#ifndef __ActUtlType64_FWD_DEFINED__
#define __ActUtlType64_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActUtlType64 ActUtlType64;
#else
typedef struct ActUtlType64 ActUtlType64;
#endif /* __cplusplus */

#endif 	/* __ActUtlType64_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IActUtlType64_INTERFACE_DEFINED__
#define __IActUtlType64_INTERFACE_DEFINED__

/* interface IActUtlType64 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IActUtlType64;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("174DD3F4-961E-4833-A4D2-6BFFE5DDFC6C")
    IActUtlType64 : public IUnknown
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActLogicalStationNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActLogicalStationNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ActPassword( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ActPassword( 
            /* [in] */ BSTR newVal) = 0;
        
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

    typedef struct IActUtlType64Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IActUtlType64 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IActUtlType64 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IActUtlType64 * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActLogicalStationNumber )( 
            IActUtlType64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActLogicalStationNumber )( 
            IActUtlType64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActPassword )( 
            IActUtlType64 * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActPassword )( 
            IActUtlType64 * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IActUtlType64 * This,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IActUtlType64 * This,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadDeviceBlock2 )( 
            IActUtlType64 * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteDeviceBlock2 )( 
            IActUtlType64 * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadDeviceRandom2 )( 
            IActUtlType64 * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteDeviceRandom2 )( 
            IActUtlType64 * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CheckControl )( 
            IActUtlType64 * This,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCpuType )( 
            IActUtlType64 * This,
            /* [string][out] */ BSTR *szCpuName,
            /* [out] */ LONG *lplCpuCode,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCpuStatus )( 
            IActUtlType64 * This,
            /* [in] */ LONG lOperation,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadDeviceBlock )( 
            IActUtlType64 * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteDeviceBlock )( 
            IActUtlType64 * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadDeviceRandom )( 
            IActUtlType64 * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteDeviceRandom )( 
            IActUtlType64 * This,
            /* [string][in] */ BSTR szDeviceList,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ReadBuffer )( 
            IActUtlType64 * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][out] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteBuffer )( 
            IActUtlType64 * This,
            /* [in] */ LONG lStartIO,
            /* [in] */ LONG lAddress,
            /* [in] */ LONG lSize,
            /* [size_is][in] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetClockData )( 
            IActUtlType64 * This,
            /* [out] */ SHORT *lpsYear,
            /* [out] */ SHORT *lpsMonth,
            /* [out] */ SHORT *lpsDay,
            /* [out] */ SHORT *lpsDayOfWeek,
            /* [out] */ SHORT *lpsHour,
            /* [out] */ SHORT *lpsMinute,
            /* [out] */ SHORT *lpsSecond,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetClockData )( 
            IActUtlType64 * This,
            /* [in] */ SHORT sYear,
            /* [in] */ SHORT sMonth,
            /* [in] */ SHORT sDay,
            /* [in] */ SHORT sDayOfWeek,
            /* [in] */ SHORT sHour,
            /* [in] */ SHORT sMinute,
            /* [in] */ SHORT sSecond,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDevice )( 
            IActUtlType64 * This,
            /* [string][in] */ BSTR szDevice,
            /* [in] */ LONG lData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDevice )( 
            IActUtlType64 * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ LONG *lplData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDevice2 )( 
            IActUtlType64 * This,
            /* [string][in] */ BSTR szDevice,
            /* [out] */ SHORT *lpsData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDevice2 )( 
            IActUtlType64 * This,
            /* [in] */ BSTR szDevice,
            /* [in] */ SHORT sData,
            /* [retval][out] */ LONG *lplReturnCode);
        
        END_INTERFACE
    } IActUtlType64Vtbl;

    interface IActUtlType64
    {
        CONST_VTBL struct IActUtlType64Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActUtlType64_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IActUtlType64_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IActUtlType64_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IActUtlType64_get_ActLogicalStationNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActLogicalStationNumber(This,pVal) ) 

#define IActUtlType64_put_ActLogicalStationNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActLogicalStationNumber(This,newVal) ) 

#define IActUtlType64_get_ActPassword(This,pVal)	\
    ( (This)->lpVtbl -> get_ActPassword(This,pVal) ) 

#define IActUtlType64_put_ActPassword(This,newVal)	\
    ( (This)->lpVtbl -> put_ActPassword(This,newVal) ) 

#define IActUtlType64_Open(This,lplReturnCode)	\
    ( (This)->lpVtbl -> Open(This,lplReturnCode) ) 

#define IActUtlType64_Close(This,lplReturnCode)	\
    ( (This)->lpVtbl -> Close(This,lplReturnCode) ) 

#define IActUtlType64_ReadDeviceBlock2(This,szDevice,lSize,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> ReadDeviceBlock2(This,szDevice,lSize,lplData,lplReturnCode) ) 

#define IActUtlType64_WriteDeviceBlock2(This,szDevice,lSize,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> WriteDeviceBlock2(This,szDevice,lSize,lplData,lplReturnCode) ) 

#define IActUtlType64_ReadDeviceRandom2(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> ReadDeviceRandom2(This,szDeviceList,lSize,lplData,lplReturnCode) ) 

#define IActUtlType64_WriteDeviceRandom2(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> WriteDeviceRandom2(This,szDeviceList,lSize,lplData,lplReturnCode) ) 

#define IActUtlType64_CheckControl(This,lplReturnCode)	\
    ( (This)->lpVtbl -> CheckControl(This,lplReturnCode) ) 

#define IActUtlType64_GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode)	\
    ( (This)->lpVtbl -> GetCpuType(This,szCpuName,lplCpuCode,lplReturnCode) ) 

#define IActUtlType64_SetCpuStatus(This,lOperation,lplReturnCode)	\
    ( (This)->lpVtbl -> SetCpuStatus(This,lOperation,lplReturnCode) ) 

#define IActUtlType64_ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> ReadDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode) ) 

#define IActUtlType64_WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> WriteDeviceBlock(This,szDevice,lSize,lplData,lplReturnCode) ) 

#define IActUtlType64_ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> ReadDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode) ) 

#define IActUtlType64_WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> WriteDeviceRandom(This,szDeviceList,lSize,lplData,lplReturnCode) ) 

#define IActUtlType64_ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    ( (This)->lpVtbl -> ReadBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode) ) 

#define IActUtlType64_WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode)	\
    ( (This)->lpVtbl -> WriteBuffer(This,lStartIO,lAddress,lSize,lpsData,lplReturnCode) ) 

#define IActUtlType64_GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode)	\
    ( (This)->lpVtbl -> GetClockData(This,lpsYear,lpsMonth,lpsDay,lpsDayOfWeek,lpsHour,lpsMinute,lpsSecond,lplReturnCode) ) 

#define IActUtlType64_SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode)	\
    ( (This)->lpVtbl -> SetClockData(This,sYear,sMonth,sDay,sDayOfWeek,sHour,sMinute,sSecond,lplReturnCode) ) 

#define IActUtlType64_SetDevice(This,szDevice,lData,lplReturnCode)	\
    ( (This)->lpVtbl -> SetDevice(This,szDevice,lData,lplReturnCode) ) 

#define IActUtlType64_GetDevice(This,szDevice,lplData,lplReturnCode)	\
    ( (This)->lpVtbl -> GetDevice(This,szDevice,lplData,lplReturnCode) ) 

#define IActUtlType64_GetDevice2(This,szDevice,lpsData,lplReturnCode)	\
    ( (This)->lpVtbl -> GetDevice2(This,szDevice,lpsData,lplReturnCode) ) 

#define IActUtlType64_SetDevice2(This,szDevice,sData,lplReturnCode)	\
    ( (This)->lpVtbl -> SetDevice2(This,szDevice,sData,lplReturnCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActUtlType64_INTERFACE_DEFINED__ */



#ifndef __ActUtlType64Lib_LIBRARY_DEFINED__
#define __ActUtlType64Lib_LIBRARY_DEFINED__

/* library ActUtlType64Lib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ActUtlType64Lib;

EXTERN_C const CLSID CLSID_ActUtlType64;

#ifdef __cplusplus

class DECLSPEC_UUID("F0B1A112-BFCB-4DA3-9535-C296D69A17E0")
ActUtlType64;
#endif
#endif /* __ActUtlType64Lib_LIBRARY_DEFINED__ */

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


