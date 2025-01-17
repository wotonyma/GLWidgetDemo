

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for ActUtlDataLogging64.idl:
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

#ifndef __ActUtlDataLogging64_i_h__
#define __ActUtlDataLogging64_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IActUtlDataLogging64_FWD_DEFINED__
#define __IActUtlDataLogging64_FWD_DEFINED__
typedef interface IActUtlDataLogging64 IActUtlDataLogging64;

#endif 	/* __IActUtlDataLogging64_FWD_DEFINED__ */


#ifndef __ActUtlDataLogging64_FWD_DEFINED__
#define __ActUtlDataLogging64_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActUtlDataLogging64 ActUtlDataLogging64;
#else
typedef struct ActUtlDataLogging64 ActUtlDataLogging64;
#endif /* __cplusplus */

#endif 	/* __ActUtlDataLogging64_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IActUtlDataLogging64_INTERFACE_DEFINED__
#define __IActUtlDataLogging64_INTERFACE_DEFINED__

/* interface IActUtlDataLogging64 */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IActUtlDataLogging64;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DD00E90B-AF7D-461E-89A8-432424F727F6")
    IActUtlDataLogging64 : public IUnknown
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActLogicalStationNumber( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActLogicalStationNumber( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_ActPassword( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_ActPassword( 
            /* [in] */ BSTR newVal) = 0;
        
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

    typedef struct IActUtlDataLogging64Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IActUtlDataLogging64 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IActUtlDataLogging64 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IActUtlDataLogging64 * This);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActLogicalStationNumber )( 
            IActUtlDataLogging64 * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActLogicalStationNumber )( 
            IActUtlDataLogging64 * This,
            /* [in] */ LONG newVal);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ActPassword )( 
            IActUtlDataLogging64 * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ActPassword )( 
            IActUtlDataLogging64 * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IActUtlDataLogging64 * This,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IActUtlDataLogging64 * This,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ReadFirstFile )( 
            IActUtlDataLogging64 * This,
            /* [in] */ BSTR srcDir,
            /* [out] */ BSTR *srcFilename,
            /* [out] */ LONG *srcType,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ReadNextFile )( 
            IActUtlDataLogging64 * This,
            /* [out] */ BSTR *srcFilename,
            /* [out] */ LONG *srcType,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ReadClose )( 
            IActUtlDataLogging64 * This,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetFile )( 
            IActUtlDataLogging64 * This,
            /* [in] */ BSTR srcFileName,
            /* [in] */ BSTR dstFileName,
            /* [retval][out] */ LONG *lplReturnCode);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *CheckControl )( 
            IActUtlDataLogging64 * This,
            /* [retval][out] */ LONG *lplReturnCode);
        
        END_INTERFACE
    } IActUtlDataLogging64Vtbl;

    interface IActUtlDataLogging64
    {
        CONST_VTBL struct IActUtlDataLogging64Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActUtlDataLogging64_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IActUtlDataLogging64_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IActUtlDataLogging64_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IActUtlDataLogging64_get_ActLogicalStationNumber(This,pVal)	\
    ( (This)->lpVtbl -> get_ActLogicalStationNumber(This,pVal) ) 

#define IActUtlDataLogging64_put_ActLogicalStationNumber(This,newVal)	\
    ( (This)->lpVtbl -> put_ActLogicalStationNumber(This,newVal) ) 

#define IActUtlDataLogging64_get_ActPassword(This,pVal)	\
    ( (This)->lpVtbl -> get_ActPassword(This,pVal) ) 

#define IActUtlDataLogging64_put_ActPassword(This,newVal)	\
    ( (This)->lpVtbl -> put_ActPassword(This,newVal) ) 

#define IActUtlDataLogging64_Open(This,lplReturnCode)	\
    ( (This)->lpVtbl -> Open(This,lplReturnCode) ) 

#define IActUtlDataLogging64_Close(This,lplReturnCode)	\
    ( (This)->lpVtbl -> Close(This,lplReturnCode) ) 

#define IActUtlDataLogging64_ReadFirstFile(This,srcDir,srcFilename,srcType,lplReturnCode)	\
    ( (This)->lpVtbl -> ReadFirstFile(This,srcDir,srcFilename,srcType,lplReturnCode) ) 

#define IActUtlDataLogging64_ReadNextFile(This,srcFilename,srcType,lplReturnCode)	\
    ( (This)->lpVtbl -> ReadNextFile(This,srcFilename,srcType,lplReturnCode) ) 

#define IActUtlDataLogging64_ReadClose(This,lplReturnCode)	\
    ( (This)->lpVtbl -> ReadClose(This,lplReturnCode) ) 

#define IActUtlDataLogging64_GetFile(This,srcFileName,dstFileName,lplReturnCode)	\
    ( (This)->lpVtbl -> GetFile(This,srcFileName,dstFileName,lplReturnCode) ) 

#define IActUtlDataLogging64_CheckControl(This,lplReturnCode)	\
    ( (This)->lpVtbl -> CheckControl(This,lplReturnCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActUtlDataLogging64_INTERFACE_DEFINED__ */



#ifndef __ActUtlDataLogging64Lib_LIBRARY_DEFINED__
#define __ActUtlDataLogging64Lib_LIBRARY_DEFINED__

/* library ActUtlDataLogging64Lib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ActUtlDataLogging64Lib;

EXTERN_C const CLSID CLSID_ActUtlDataLogging64;

#ifdef __cplusplus

class DECLSPEC_UUID("DA10D3E5-8645-475C-BB9E-7C108A4C0653")
ActUtlDataLogging64;
#endif
#endif /* __ActUtlDataLogging64Lib_LIBRARY_DEFINED__ */

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


