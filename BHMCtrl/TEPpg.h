// TEPpg.h : Declaration of the CTEPpg

#ifndef __TEPPG_H_
#define __TEPPG_H_

#include "resource.h"       // main symbols

EXTERN_C const CLSID CLSID_TEPpg;

/////////////////////////////////////////////////////////////////////////////
// CTEPpg
class ATL_NO_VTABLE CTEPpg :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTEPpg, &CLSID_TEPpg>,
	public IPropertyPageImpl<CTEPpg>,
	public CDialogImpl<CTEPpg>
{
public:
	CTEPpg() 
	{
		m_dwTitleID = IDS_TITLETEPpg;
		m_dwHelpFileID = IDS_HELPFILETEPpg;
		m_dwDocStringID = IDS_DOCSTRINGTEPpg;
	}

	enum {IDD = IDD_TEPPG};

DECLARE_REGISTRY_RESOURCEID(IDR_TEPPG)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CTEPpg) 
	COM_INTERFACE_ENTRY(IPropertyPage)
END_COM_MAP()

BEGIN_MSG_MAP(CTEPpg)
	CHAIN_MSG_MAP(IPropertyPageImpl<CTEPpg>)
	COMMAND_HANDLER(IDC_CHECK_READONLY, BN_CLICKED, OnClickedCheck_readonly)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	STDMETHOD(Apply)(void)
	{
		USES_CONVERSION;	
		ATLTRACE(_T("CTEPpg::Apply\n"));
		for (UINT i = 0; i < m_nObjects; i++)
		{
			CComQIPtr<IBHMTimeEditCtrl, &IID_IBHMTimeEditCtrl> pTECtrl(m_ppUnk[i]);
			BOOL bReadOnly = IsDlgButtonChecked(IDC_CHECK_READONLY);
			if FAILED(pTECtrl->put_ReadOnly(bReadOnly))
			{
				CComPtr<IErrorInfo> pError;         
				CComBSTR strError;
				GetErrorInfo(0, &pError);         
				pError->GetDescription(&strError);
				MessageBox(OLE2T(strError), _T("Error"), MB_ICONEXCLAMATION);
				return E_FAIL;
			}
		}
		m_bDirty = FALSE;
		return S_OK;
	}
	LRESULT OnClickedCheck_readonly(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		SetDirty(TRUE);
		return 0;
	}
	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		if (m_nObjects != 1)
			return 0;
		
		CComQIPtr<IBHMTimeEditCtrl, &IID_IBHMTimeEditCtrl> pTECtrl(m_ppUnk[0]);
		BOOL bReadOnly = FALSE;
		if FAILED(pTECtrl->get_ReadOnly(&bReadOnly))
			return 0;

		CheckDlgButton(IDC_CHECK_READONLY, bReadOnly);
		return 0;
	}
};

#endif //__TEPPG_H_
