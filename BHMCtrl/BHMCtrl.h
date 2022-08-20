/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Mar 22 14:11:55 1999
 */
/* Compiler settings for C:\wxz\BHMCtrl\BHMCtrl.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __BHMCtrl_h__
#define __BHMCtrl_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IBHMTimeEditCtrl_FWD_DEFINED__
#define __IBHMTimeEditCtrl_FWD_DEFINED__
typedef interface IBHMTimeEditCtrl IBHMTimeEditCtrl;
#endif 	/* __IBHMTimeEditCtrl_FWD_DEFINED__ */


#ifndef ___IBHMTimeEditCtrlEvents_FWD_DEFINED__
#define ___IBHMTimeEditCtrlEvents_FWD_DEFINED__
typedef interface _IBHMTimeEditCtrlEvents _IBHMTimeEditCtrlEvents;
#endif 	/* ___IBHMTimeEditCtrlEvents_FWD_DEFINED__ */


#ifndef __BHMTimeEditCtrl_FWD_DEFINED__
#define __BHMTimeEditCtrl_FWD_DEFINED__

#ifdef __cplusplus
typedef class BHMTimeEditCtrl BHMTimeEditCtrl;
#else
typedef struct BHMTimeEditCtrl BHMTimeEditCtrl;
#endif /* __cplusplus */

#endif 	/* __BHMTimeEditCtrl_FWD_DEFINED__ */


#ifndef __TEPpg_FWD_DEFINED__
#define __TEPpg_FWD_DEFINED__

#ifdef __cplusplus
typedef class TEPpg TEPpg;
#else
typedef struct TEPpg TEPpg;
#endif /* __cplusplus */

#endif 	/* __TEPpg_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IBHMTimeEditCtrl_INTERFACE_DEFINED__
#define __IBHMTimeEditCtrl_INTERFACE_DEFINED__

/* interface IBHMTimeEditCtrl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IBHMTimeEditCtrl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("389612AE-D16F-11D2-9CE8-0080C8763FA4")
    IBHMTimeEditCtrl : public IDispatch
    {
    public:
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BackColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BackColor( 
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ForeColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ForeColor( 
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr) = 0;
        
        virtual /* [id][propputref] */ HRESULT STDMETHODCALLTYPE putref_Font( 
            /* [in] */ IFontDisp __RPC_FAR *pFont) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Font( 
            /* [in] */ IFontDisp __RPC_FAR *pFont) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Font( 
            /* [retval][out] */ IFontDisp __RPC_FAR *__RPC_FAR *ppFont) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Text( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Text( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ReadOnly( 
            /* [retval][out] */ BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ReadOnly( 
            /* [in] */ BOOL newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBHMTimeEditCtrlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IBHMTimeEditCtrl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IBHMTimeEditCtrl __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IBHMTimeEditCtrl __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IBHMTimeEditCtrl __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IBHMTimeEditCtrl __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IBHMTimeEditCtrl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IBHMTimeEditCtrl __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BackColor )( 
            IBHMTimeEditCtrl __RPC_FAR * This,
            /* [in] */ OLE_COLOR clr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BackColor )( 
            IBHMTimeEditCtrl __RPC_FAR * This,
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ForeColor )( 
            IBHMTimeEditCtrl __RPC_FAR * This,
            /* [in] */ OLE_COLOR clr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ForeColor )( 
            IBHMTimeEditCtrl __RPC_FAR * This,
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr);
        
        /* [id][propputref] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_Font )( 
            IBHMTimeEditCtrl __RPC_FAR * This,
            /* [in] */ IFontDisp __RPC_FAR *pFont);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Font )( 
            IBHMTimeEditCtrl __RPC_FAR * This,
            /* [in] */ IFontDisp __RPC_FAR *pFont);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Font )( 
            IBHMTimeEditCtrl __RPC_FAR * This,
            /* [retval][out] */ IFontDisp __RPC_FAR *__RPC_FAR *ppFont);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Text )( 
            IBHMTimeEditCtrl __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Text )( 
            IBHMTimeEditCtrl __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReadOnly )( 
            IBHMTimeEditCtrl __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ReadOnly )( 
            IBHMTimeEditCtrl __RPC_FAR * This,
            /* [in] */ BOOL newVal);
        
        END_INTERFACE
    } IBHMTimeEditCtrlVtbl;

    interface IBHMTimeEditCtrl
    {
        CONST_VTBL struct IBHMTimeEditCtrlVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBHMTimeEditCtrl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBHMTimeEditCtrl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBHMTimeEditCtrl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBHMTimeEditCtrl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IBHMTimeEditCtrl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IBHMTimeEditCtrl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IBHMTimeEditCtrl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IBHMTimeEditCtrl_put_BackColor(This,clr)	\
    (This)->lpVtbl -> put_BackColor(This,clr)

#define IBHMTimeEditCtrl_get_BackColor(This,pclr)	\
    (This)->lpVtbl -> get_BackColor(This,pclr)

#define IBHMTimeEditCtrl_put_ForeColor(This,clr)	\
    (This)->lpVtbl -> put_ForeColor(This,clr)

#define IBHMTimeEditCtrl_get_ForeColor(This,pclr)	\
    (This)->lpVtbl -> get_ForeColor(This,pclr)

#define IBHMTimeEditCtrl_putref_Font(This,pFont)	\
    (This)->lpVtbl -> putref_Font(This,pFont)

#define IBHMTimeEditCtrl_put_Font(This,pFont)	\
    (This)->lpVtbl -> put_Font(This,pFont)

#define IBHMTimeEditCtrl_get_Font(This,ppFont)	\
    (This)->lpVtbl -> get_Font(This,ppFont)

#define IBHMTimeEditCtrl_get_Text(This,pVal)	\
    (This)->lpVtbl -> get_Text(This,pVal)

#define IBHMTimeEditCtrl_put_Text(This,newVal)	\
    (This)->lpVtbl -> put_Text(This,newVal)

#define IBHMTimeEditCtrl_get_ReadOnly(This,pVal)	\
    (This)->lpVtbl -> get_ReadOnly(This,pVal)

#define IBHMTimeEditCtrl_put_ReadOnly(This,newVal)	\
    (This)->lpVtbl -> put_ReadOnly(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propput] */ HRESULT STDMETHODCALLTYPE IBHMTimeEditCtrl_put_BackColor_Proxy( 
    IBHMTimeEditCtrl __RPC_FAR * This,
    /* [in] */ OLE_COLOR clr);


void __RPC_STUB IBHMTimeEditCtrl_put_BackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IBHMTimeEditCtrl_get_BackColor_Proxy( 
    IBHMTimeEditCtrl __RPC_FAR * This,
    /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr);


void __RPC_STUB IBHMTimeEditCtrl_get_BackColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IBHMTimeEditCtrl_put_ForeColor_Proxy( 
    IBHMTimeEditCtrl __RPC_FAR * This,
    /* [in] */ OLE_COLOR clr);


void __RPC_STUB IBHMTimeEditCtrl_put_ForeColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IBHMTimeEditCtrl_get_ForeColor_Proxy( 
    IBHMTimeEditCtrl __RPC_FAR * This,
    /* [retval][out] */ OLE_COLOR __RPC_FAR *pclr);


void __RPC_STUB IBHMTimeEditCtrl_get_ForeColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propputref] */ HRESULT STDMETHODCALLTYPE IBHMTimeEditCtrl_putref_Font_Proxy( 
    IBHMTimeEditCtrl __RPC_FAR * This,
    /* [in] */ IFontDisp __RPC_FAR *pFont);


void __RPC_STUB IBHMTimeEditCtrl_putref_Font_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IBHMTimeEditCtrl_put_Font_Proxy( 
    IBHMTimeEditCtrl __RPC_FAR * This,
    /* [in] */ IFontDisp __RPC_FAR *pFont);


void __RPC_STUB IBHMTimeEditCtrl_put_Font_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE IBHMTimeEditCtrl_get_Font_Proxy( 
    IBHMTimeEditCtrl __RPC_FAR * This,
    /* [retval][out] */ IFontDisp __RPC_FAR *__RPC_FAR *ppFont);


void __RPC_STUB IBHMTimeEditCtrl_get_Font_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IBHMTimeEditCtrl_get_Text_Proxy( 
    IBHMTimeEditCtrl __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IBHMTimeEditCtrl_get_Text_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IBHMTimeEditCtrl_put_Text_Proxy( 
    IBHMTimeEditCtrl __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IBHMTimeEditCtrl_put_Text_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IBHMTimeEditCtrl_get_ReadOnly_Proxy( 
    IBHMTimeEditCtrl __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pVal);


void __RPC_STUB IBHMTimeEditCtrl_get_ReadOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IBHMTimeEditCtrl_put_ReadOnly_Proxy( 
    IBHMTimeEditCtrl __RPC_FAR * This,
    /* [in] */ BOOL newVal);


void __RPC_STUB IBHMTimeEditCtrl_put_ReadOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBHMTimeEditCtrl_INTERFACE_DEFINED__ */



#ifndef __BHMCTRLLib_LIBRARY_DEFINED__
#define __BHMCTRLLib_LIBRARY_DEFINED__

/* library BHMCTRLLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_BHMCTRLLib;

#ifndef ___IBHMTimeEditCtrlEvents_DISPINTERFACE_DEFINED__
#define ___IBHMTimeEditCtrlEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IBHMTimeEditCtrlEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IBHMTimeEditCtrlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("389612B0-D16F-11D2-9CE8-0080C8763FA4")
    _IBHMTimeEditCtrlEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IBHMTimeEditCtrlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IBHMTimeEditCtrlEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IBHMTimeEditCtrlEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IBHMTimeEditCtrlEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IBHMTimeEditCtrlEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IBHMTimeEditCtrlEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IBHMTimeEditCtrlEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IBHMTimeEditCtrlEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IBHMTimeEditCtrlEventsVtbl;

    interface _IBHMTimeEditCtrlEvents
    {
        CONST_VTBL struct _IBHMTimeEditCtrlEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IBHMTimeEditCtrlEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IBHMTimeEditCtrlEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IBHMTimeEditCtrlEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IBHMTimeEditCtrlEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IBHMTimeEditCtrlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IBHMTimeEditCtrlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IBHMTimeEditCtrlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IBHMTimeEditCtrlEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_BHMTimeEditCtrl;

#ifdef __cplusplus

class DECLSPEC_UUID("389612AF-D16F-11D2-9CE8-0080C8763FA4")
BHMTimeEditCtrl;
#endif

EXTERN_C const CLSID CLSID_TEPpg;

#ifdef __cplusplus

class DECLSPEC_UUID("DECC1F80-E05F-11D2-A7FE-0080C8763FA4")
TEPpg;
#endif
#endif /* __BHMCTRLLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
