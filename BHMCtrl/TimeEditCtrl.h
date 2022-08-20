// TimeEditCtrl.h : Declaration of the CTimeEditCtrl

#ifndef __BHMTIMEEDITCTRL_H_
#define __BHMTIMEEDITCTRL_H_

#include "resource.h"       // main symbols
#include <atlctl.h>
#include "BHMCtrlCP.h"


/////////////////////////////////////////////////////////////////////////////
// CTimeEditCtrl
class ATL_NO_VTABLE CTimeEditCtrl : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CStockPropImpl<CTimeEditCtrl, IBHMTimeEditCtrl, &IID_IBHMTimeEditCtrl, &LIBID_BHMCTRLLib>,
	public CComControl<CTimeEditCtrl>,
	public IPersistStreamInitImpl<CTimeEditCtrl>,
	public IOleControlImpl<CTimeEditCtrl>,
	public IOleObjectImpl<CTimeEditCtrl>,
	public IOleInPlaceActiveObjectImpl<CTimeEditCtrl>,
	public IViewObjectExImpl<CTimeEditCtrl>,
	public IOleInPlaceObjectWindowlessImpl<CTimeEditCtrl>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CTimeEditCtrl>,
	public IPersistStorageImpl<CTimeEditCtrl>,
	public ISpecifyPropertyPagesImpl<CTimeEditCtrl>,
	public IQuickActivateImpl<CTimeEditCtrl>,
	public IDataObjectImpl<CTimeEditCtrl>,
	public IProvideClassInfo2Impl<&CLSID_BHMTimeEditCtrl, &DIID__IBHMTimeEditCtrlEvents, &LIBID_BHMCTRLLib>,
	public IPropertyNotifySinkCP<CTimeEditCtrl>,
	public CComCoClass<CTimeEditCtrl, &CLSID_BHMTimeEditCtrl>,
	public CProxy_IBHMTimeEditCtrlEvents< CTimeEditCtrl >,
	public IPerPropertyBrowsingImpl<CTimeEditCtrl>,
	public IPersistPropertyBagImpl<CTimeEditCtrl>
{
public:
	CTimeEditCtrl();

DECLARE_REGISTRY_RESOURCEID(IDR_BHMTIMEEDITCTRL)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CTimeEditCtrl)
	COM_INTERFACE_ENTRY(IBHMTimeEditCtrl)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY(IPerPropertyBrowsing)
	COM_INTERFACE_ENTRY(IPersistPropertyBag)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()

BEGIN_PROPERTY_MAP(CTimeEditCtrl)
	PROP_ENTRY("BackColor", DISPID_BACKCOLOR, CLSID_StockColorPage)
	PROP_ENTRY("ForeColor", DISPID_FORECOLOR, CLSID_StockColorPage)
	PROP_ENTRY("Font", DISPID_FONT, CLSID_StockFontPage)
	PROP_ENTRY("Text", dispidText, CLSID_NULL)
	PROP_ENTRY("ReadOnly", dispidReadOnly, CLSID_TEPpg)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(CTimeEditCtrl)
	CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
	CONNECTION_POINT_ENTRY(DIID__IBHMTimeEditCtrlEvents)
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CTimeEditCtrl)
	CHAIN_MSG_MAP(CComControl<CTimeEditCtrl>)
	DEFAULT_REFLECTION_HANDLER()
	MESSAGE_HANDLER(WM_KILLFOCUS, OnKillFocus)
	MESSAGE_HANDLER(WM_SETFOCUS, OnSetFocus)
	MESSAGE_HANDLER(WM_CREATE, OnCreate)
	MESSAGE_HANDLER(WM_KEYDOWN, OnKeyDown)
	MESSAGE_HANDLER(WM_CHAR, OnChar)
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);



// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid)
	{
		static const IID* arr[] = 
		{
			&IID_IBHMTimeEditCtrl,
		};

		for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
		{
			if (InlineIsEqualGUID(*arr[i], riid))
				return S_OK;
		}

		return S_FALSE;
	}

// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IBHMTimeEditCtrl
public:
	STDMETHOD(get_Text)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Text)(/*[in]*/ BSTR newVal);

	HRESULT OnDrawAdvanced(ATL_DRAWINFO& di);
	OLE_COLOR m_clrBackColor;
	OLE_COLOR m_clrForeColor;
protected:
	short ShiftState();
	BOOL IsValidChar(TCHAR cNewChar, int nPos);
	void MoveRight(int nSteps = 0);
	void MoveLeft(int nSteps = 0);
	int m_nCurrentPosition;
	POINT m_ptCaretPosition;
	void RetrieveHFont();
	HFONT m_hFont;
	CComPtr<IFont> m_pIFont;
	void DisplayCaret(HDC hDC);
	CComBSTR m_strText;
	BOOL m_bReadOnly;

public:
	STDMETHOD(DoVerb)(LONG iVerb, LPMSG lpmsg, IOleClientSite* pActiveSite, LONG lindex, HWND hwndParent, LPCRECT lprcPosRect);
	STDMETHOD(InitNew)();
	STDMETHOD(GetPredefinedStrings)(DISPID dispID, CALPOLESTR* pCaStringsOut, CADWORD* pCaCookiesOut);
	STDMETHOD(GetPredefinedValue)(DISPID dispID, DWORD dwCookie, VARIANT* pVarOut);
	STDMETHOD(GetDisplayString)(DISPID dispID, BSTR* pBstr);
	STDMETHOD(get_ReadOnly)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(put_ReadOnly)(/*[in]*/ BOOL newVal);
	BOOL PreTranslateAccelerator(LPMSG pMsg, HRESULT& hRet);
	CComPtr<IFontDisp> m_pFont;
	HRESULT STDMETHODCALLTYPE putref_Font(IFontDisp* pFont);
	HRESULT STDMETHODCALLTYPE put_Font(IFontDisp* pFont);
	
	enum
	{
		dispidText = 1L,
		dispidReadOnly = 2L,
	};

	LRESULT OnKillFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	
	LRESULT OnSetFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	
	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		ModifyStyleEx(NULL, WS_EX_CLIENTEDGE);

		return 0;
	}

	LRESULT OnKeyDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	
	LRESULT OnChar(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	
	LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		Fire_Click();

		return 0;
	}

	LPOLESTR CopyString(LPCTSTR psz)
	{
		USES_CONVERSION;

		if (psz == NULL)
			return NULL;

		int cch = lstrlen(psz) + 1;
		LPOLESTR pszCopy = NULL;

		if ((pszCopy = (LPOLESTR)CoTaskMemAlloc(cch * sizeof(OLECHAR))) != NULL)
		{
			MultiByteToWideChar(CP_ACP, 0, psz, -1, pszCopy, cch);
		}

		return pszCopy;
	}
};

#endif //__BHMTIMEEDITCTRL_H_
