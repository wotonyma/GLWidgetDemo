

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for ActSupportMsg.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
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

#ifndef __ActSupportMsg64_i_h__
#define __ActSupportMsg64_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IActSupportMsg64_FWD_DEFINED__
#define __IActSupportMsg64_FWD_DEFINED__
typedef interface IActSupportMsg64 IActSupportMsg64;

#endif 	/* __IActSupportMsg64_FWD_DEFINED__ */


#ifndef ___IActSupportMsg64Events_FWD_DEFINED__
#define ___IActSupportMsg64Events_FWD_DEFINED__
typedef interface _IActSupportMsg64Events _IActSupportMsg64Events;

#endif 	/* ___IActSupportMsg64Events_FWD_DEFINED__ */


#ifndef __ActSupportMsg64_FWD_DEFINED__
#define __ActSupportMsg64_FWD_DEFINED__

#ifdef __cplusplus
typedef class ActSupportMsg64 ActSupportMsg64;
#else
typedef struct ActSupportMsg64 ActSupportMsg64;
#endif /* __cplusplus */

#endif 	/* __ActSupportMsg64_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IActSupportMsg64_INTERFACE_DEFINED__
#define __IActSupportMsg64_INTERFACE_DEFINED__

/* interface IActSupportMsg64 */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IActSupportMsg64;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2B77E97C-7E62-41F4-AA82-04FB1B2A08AC")
    IActSupportMsg64 : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetErrorMessage( 
            /* [in] */ LONG lErrorCode,
            /* [string][out] */ BSTR *lpszErrorMessage,
            /* [retval][out] */ LONG *lplReturnCode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IActSupportMsg64Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IActSupportMsg64 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IActSupportMsg64 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IActSupportMsg64 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IActSupportMsg64 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IActSupportMsg64 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IActSupportMsg64 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IActSupportMsg64 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetErrorMessage )( 
            IActSupportMsg64 * This,
            /* [in] */ LONG lErrorCode,
            /* [string][out] */ BSTR *lpszErrorMessage,
            /* [retval][out] */ LONG *lplReturnCode);
        
        END_INTERFACE
    } IActSupportMsg64Vtbl;

    interface IActSupportMsg64
    {
        CONST_VTBL struct IActSupportMsg64Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IActSupportMsg64_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IActSupportMsg64_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IActSupportMsg64_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IActSupportMsg64_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IActSupportMsg64_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IActSupportMsg64_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IActSupportMsg64_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IActSupportMsg64_GetErrorMessage(This,lErrorCode,lpszErrorMessage,lplReturnCode)	\
    ( (This)->lpVtbl -> GetErrorMessage(This,lErrorCode,lpszErrorMessage,lplReturnCode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IActSupportMsg64_INTERFACE_DEFINED__ */



#ifndef __ActSupportMsg64Lib_LIBRARY_DEFINED__
#define __ActSupportMsg64Lib_LIBRARY_DEFINED__

/* library ActSupportMsg64Lib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ActSupportMsg64Lib;

#ifndef ___IActSupportMsg64Events_DISPINTERFACE_DEFINED__
#define ___IActSupportMsg64Events_DISPINTERFACE_DEFINED__

/* dispinterface _IActSupportMsg64Events */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IActSupportMsg64Events;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("05FFDC02-F6A0-4DBE-A3E3-CB23001FE785")
    _IActSupportMsg64Events : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IActSupportMsg64EventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IActSupportMsg64Events * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IActSupportMsg64Events * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IActSupportMsg64Events * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IActSupportMsg64Events * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IActSupportMsg64Events * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IActSupportMsg64Events * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IActSupportMsg64Events * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _IActSupportMsg64EventsVtbl;

    interface _IActSupportMsg64Events
    {
        CONST_VTBL struct _IActSupportMsg64EventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IActSupportMsg64Events_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IActSupportMsg64Events_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IActSupportMsg64Events_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IActSupportMsg64Events_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IActSupportMsg64Events_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IActSupportMsg64Events_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IActSupportMsg64Events_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IActSupportMsg64Events_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ActSupportMsg64;

#ifdef __cplusplus

class DECLSPEC_UUID("89989363-40DF-4CA3-9B3B-0FED7AB7D89A")
ActSupportMsg64;
#endif
#endif /* __ActSupportMsg64Lib_LIBRARY_DEFINED__ */

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


