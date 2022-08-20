// TimeEditCtrl.cpp : Implementation of CTimeEditCtrl

#include "stdafx.h"
#include "BHMCtrl.h"
#include "TimeEditCtrl.h"

/////////////////////////////////////////////////////////////////////////////
// CTimeEditCtrl

CTimeEditCtrl::CTimeEditCtrl()
{
	m_bWindowOnly = TRUE;
	m_nCurrentPosition = 0;
	m_ptCaretPosition.x = m_ptCaretPosition.y = 0;
	m_pFont = NULL;
	m_clrForeColor = 0;
	m_clrBackColor = RGB(255, 255, 255);

	USES_CONVERSION;
	m_strText = _T("00:00:00");
	m_hFont = NULL;
	m_bReadOnly = FALSE;
}

HRESULT CTimeEditCtrl::OnDrawAdvanced(ATL_DRAWINFO& di)
{
	HDC hDC = di.hdcDraw;
	int nSDC = SaveDC(hDC);

	RECT& rc = *(RECT*)di.prcBounds;
	Rectangle(hDC, rc.left, rc.top, rc.right, rc.bottom);
	
	USES_CONVERSION;
	if (m_hFont)
	{
		HFONT hFontOld = (HFONT)SelectObject(hDC, m_hFont);

		COLORREF clrFore = RGB(0, 0, 0), clrBack = RGB(255, 255, 255);
		OleTranslateColor(m_clrForeColor, NULL, &clrFore);
		OleTranslateColor(m_clrBackColor, NULL, &clrBack);

		SetTextColor(hDC, m_bReadOnly ? RGB(125, 125, 125) : m_clrForeColor);
		SetBkColor(hDC, m_clrBackColor);
		SetTextAlign(hDC, TA_LEFT);
		ExtTextOut(hDC, rc.left, rc.top, ETO_CLIPPED | ETO_OPAQUE, &rc,
			OLE2T(m_strText), 8, NULL);
	
		BOOL bRunMode;
		GetAmbientUserMode(bRunMode);
		if (GetFocus() == m_hWnd && bRunMode)
		{
			DisplayCaret(hDC);
		}

		SelectObject(hDC, hFontOld);
	}

	RestoreDC(hDC, nSDC);

	return S_OK;
}

STDMETHODIMP CTimeEditCtrl::get_Text(BSTR *pVal)
{
	USES_CONVERSION;
	*pVal = m_strText.Copy();

	return S_OK;
}

STDMETHODIMP CTimeEditCtrl::put_Text(BSTR newVal)
{
	if (m_bReadOnly)
	{
		SysFreeString(newVal);
		return Error(_T("Can not edit eadonly value"));
	}

	USES_CONVERSION;

	if (SysStringLen(newVal) != 8)
	{
		SysFreeString(newVal);
		return S_OK;
	}

	for (UINT i = 0; i < 8; i++)
	{
		if (!IsValidChar((char)newVal[i] , i))
		{
			SysFreeString(newVal);
			return Error(_T("Invalid Value"));
		}
	}

	m_strText = newVal;

	m_bRequiresSave = TRUE;
	
	if (m_nFreezeEvents == 0)
	{
		FireOnChanged(dispidText);
		FireViewChange();
		Fire_Change();
	}

	return S_OK;
}

void CTimeEditCtrl::DisplayCaret(HDC hDC)
{
	HideCaret();

	USES_CONVERSION;

	SIZE szExt;
	if (8 > m_nCurrentPosition)
		GetTextExtentPoint32(hDC, OLE2T(m_strText), m_nCurrentPosition, 
		&szExt);

	m_ptCaretPosition.x = szExt.cx;
	SIZE szCaret;
	GetTextExtentPoint32(hDC, m_nCurrentPosition >= 8 ? 
		"A" : OLE2T(m_strText) + m_nCurrentPosition, 1, &szCaret);
	::CreateCaret(m_hWnd, NULL, szCaret.cx, szCaret.cy);
	ShowCaret();
	SetCaretPos(m_ptCaretPosition.x, m_ptCaretPosition.y);
}

HRESULT STDMETHODCALLTYPE CTimeEditCtrl::put_Font(IFontDisp *pFont)
{
	HRESULT hr = CStockPropImpl<CTimeEditCtrl, IBHMTimeEditCtrl, 
		&IID_IBHMTimeEditCtrl, &LIBID_BHMCTRLLib>::put_Font(pFont);
	RetrieveHFont();
	
	return hr;
}

HRESULT STDMETHODCALLTYPE CTimeEditCtrl::putref_Font(IFontDisp *pFont)
{
	HRESULT hr = CStockPropImpl<CTimeEditCtrl, IBHMTimeEditCtrl, 
		&IID_IBHMTimeEditCtrl, &LIBID_BHMCTRLLib>::putref_Font(pFont);
	RetrieveHFont();
	
	return hr;
}

void CTimeEditCtrl::RetrieveHFont()
{
	if (m_pIFont)
	{
		if (m_hFont)
		{
			m_pIFont->ReleaseHfont(m_hFont);
			m_hFont = NULL;
		}
		m_pIFont = NULL;
	}

	if (m_pFont)
	{
		CComQIPtr<IFont, &IID_IFont> pFontAmbient(m_pFont);
		if (pFontAmbient)
		{
			pFontAmbient->Clone(&m_pIFont);
			m_pIFont->get_hFont(&m_hFont);
			if (m_hFont)
				m_pIFont->AddRefHfont(m_hFont);
		}
	}
}

LRESULT CTimeEditCtrl::OnKillFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	HideCaret();
	DestroyCaret();
	
	if (m_nFreezeEvents == 0)
		FireViewChange();
	
	return 0;
}

LRESULT CTimeEditCtrl::OnSetFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if (m_nFreezeEvents == 0)
		FireViewChange();

	return 0;
}

LRESULT CTimeEditCtrl::OnKeyDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	switch (wParam)
	{
	case VK_LEFT:
	case VK_UP:
		MoveLeft(1);
		break;

	case VK_RIGHT:
	case VK_DOWN:
		MoveRight(1);
		break;

//	case VK_DELETE:
//		OnChar(uMsg, wParam, lParam, bHandled);
//		break;

	case VK_HOME:
		m_nCurrentPosition = 0;
		if (m_nFreezeEvents == 0)
			FireViewChange();
		break;

	case VK_END:
		m_nCurrentPosition = 7;
		if (m_nFreezeEvents == 0)
			FireViewChange();
		break;
	
	default:
		DefWindowProc(uMsg, wParam, lParam);
	}

	return 0;
}

BOOL CTimeEditCtrl::PreTranslateAccelerator(LPMSG pMsg, HRESULT &hRet)
{
	if (pMsg->hwnd == m_hWnd && pMsg->message == WM_KEYDOWN)
	{
		short nCharShort = (USHORT)pMsg->wParam;
		short nShiftState = ShiftState();
		if (m_nFreezeEvents == 0)
			Fire_KeyDown(&nCharShort, nShiftState);
		if (nCharShort == 0)
			return TRUE;
	
		pMsg->wParam = nCharShort;
		BOOL bHandled = TRUE;
		OnKeyDown(WM_KEYDOWN, pMsg->wParam, pMsg->lParam, bHandled);
		switch (pMsg->wParam)
		{
		case VK_HOME:
		case VK_END:
		case VK_LEFT:
		case VK_RIGHT:
		case VK_DOWN:
		case VK_UP:
			return TRUE;
			break;

		default:
			return FALSE;
		}
	}

	else if (pMsg->hwnd == m_hWnd && pMsg->message == WM_CHAR)
	{
		short nCharShort = (short)pMsg->wParam;
		if (m_nFreezeEvents == 0)
			Fire_KeyPress(&nCharShort);

		pMsg->wParam = nCharShort;
		return nCharShort == 0;
	}

	return FALSE;
}

void CTimeEditCtrl::MoveLeft(int nSteps)
{
	m_nCurrentPosition -= nSteps;
	if (m_nCurrentPosition == 2 || m_nCurrentPosition == 5)
	{
		if (nSteps <= 0)
			m_nCurrentPosition ++;
		else
			m_nCurrentPosition --;
	}

	if (m_nCurrentPosition <= 0)
		m_nCurrentPosition = 0;
	else if (m_nCurrentPosition >= 8)
		m_nCurrentPosition = 7;

	if (m_nFreezeEvents == 0)
		FireViewChange();
}

void CTimeEditCtrl::MoveRight(int nSteps)
{
	MoveLeft(-nSteps);
}

LRESULT CTimeEditCtrl::OnChar(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	if (m_bReadOnly)
		return S_OK;

	USES_CONVERSION;

	if (m_nCurrentPosition >= 8)
		return 0;

	if (/*wParam != VK_DELETE && */(wParam > '9' || wParam < '0'))
		return 0;

	if (!IsValidChar(wParam, m_nCurrentPosition))
	{
		MoveRight(1);
		if (!IsValidChar(wParam, m_nCurrentPosition))
			return 0;
	}

//	TCHAR * cText = OLE2T(m_strText);
//	if (wParam == VK_DELETE)
//		m_strText.m_str[m_nCurrentPosition] = '_';
//	else
		m_strText.m_str[m_nCurrentPosition] = wParam;

//	m_strText = cText;
	MoveRight(1);
	if (m_nFreezeEvents == 0)
	{
		FireViewChange();
		Fire_Change();
	}

	return 0;
}

BOOL CTimeEditCtrl::IsValidChar(TCHAR cNewChar, int nPos)
{
	if (nPos == 2 || nPos == 5)
		return cNewChar == ':';
	else
		return ((nPos % 3 == 0 && cNewChar >= '0' && cNewChar <= '5')
			|| (nPos % 3 != 0 && cNewChar >= '0' && cNewChar <= '9'));
}

short CTimeEditCtrl::ShiftState()
{
	BOOL bShift = (GetKeyState(VK_SHIFT) < 0);
	BOOL bCtrl  = (GetKeyState(VK_CONTROL) < 0);
	BOOL bAlt   = (GetKeyState(VK_MENU) < 0);

	return (short)(bShift + (bCtrl << 1) + (bAlt << 2));
}

STDMETHODIMP CTimeEditCtrl::get_ReadOnly(BOOL *pVal)
{
	*pVal = m_bReadOnly;

	return S_OK;
}

STDMETHODIMP CTimeEditCtrl::put_ReadOnly(BOOL newVal)
{
	m_bReadOnly = newVal;
	m_bRequiresSave = TRUE;
	if (m_nFreezeEvents == 0)
	{
		FireOnChanged(dispidReadOnly);
		FireViewChange();
		Fire_Change();
	}

	return S_OK;
}

STDMETHODIMP CTimeEditCtrl::GetPredefinedStrings(DISPID dispID, CALPOLESTR *pCaStringsOut, CADWORD *pCaCookiesOut)
{
	if ((pCaStringsOut == NULL) || (pCaCookiesOut == NULL))
		return E_POINTER;

	if (dispID != dispidReadOnly)
		return E_NOTIMPL;

	pCaStringsOut->pElems = (LPOLESTR*)CoTaskMemAlloc(
		sizeof(LPOLESTR) * 2);
	
	if (pCaStringsOut->pElems == NULL)
		return E_OUTOFMEMORY;
	
	pCaCookiesOut->pElems = (DWORD*)CoTaskMemAlloc(
		sizeof(DWORD*) * 2);
	
	if (pCaCookiesOut->pElems == NULL)
	{
		CoTaskMemFree(pCaStringsOut->pElems);
		return E_OUTOFMEMORY;
	}
	
	pCaStringsOut->cElems = 2;
	pCaCookiesOut->cElems = 2;
	LPOLESTR lpszCopy;
	
	lpszCopy = CopyString("True");
	
	if (lpszCopy == NULL)
	{
		CoTaskMemFree(pCaCookiesOut->pElems);
		CoTaskMemFree(pCaStringsOut->pElems);
		
		return E_OUTOFMEMORY;
	}
	
	pCaStringsOut->pElems[0] = lpszCopy;
	pCaCookiesOut->pElems[0] = -1;
	
	lpszCopy = CopyString("False");
	
	if (lpszCopy == NULL)
	{
		// cleanup everything allocated so far...
		CoTaskMemFree(pCaStringsOut->pElems[0]);
		
		CoTaskMemFree(pCaCookiesOut->pElems);
		CoTaskMemFree(pCaStringsOut->pElems);
		
		return E_OUTOFMEMORY;
	}
	
	pCaStringsOut->pElems[1] = lpszCopy;
	pCaCookiesOut->pElems[1] = 0;

	return S_OK;
}

STDMETHODIMP CTimeEditCtrl::GetPredefinedValue(DISPID dispID, DWORD dwCookie, VARIANT* pVarOut)
{
	if (dispID == dispidReadOnly)
	{
		VariantInit(pVarOut);
		pVarOut->vt = VT_BOOL;
		pVarOut->boolVal = (BOOL)dwCookie;
		return S_OK;
	}

	return E_NOTIMPL;
}

STDMETHODIMP CTimeEditCtrl::GetDisplayString(DISPID dispID, BSTR* pBstr)
{
	USES_CONVERSION;

	if (dispID == dispidReadOnly)
	{
		*pBstr = A2BSTR(m_bReadOnly ? "True" : "False");
		return S_OK;
	}

	return E_NOTIMPL;
}

STDMETHODIMP CTimeEditCtrl::InitNew()
{
	FONTDESC FontDescDefault =
	{ 
		sizeof(FONTDESC), OLESTR("MS Sans Serif"), FONTSIZE(12), 
			FW_NORMAL, DEFAULT_CHARSET, FALSE, FALSE, FALSE 
	};
	if (!m_pFont)
	{
		IFont * pIFont = NULL;
		if (SUCCEEDED(GetAmbientFont(&pIFont)))
		{
			pIFont->QueryInterface(IID_IFontDisp, (void **)&m_pFont);
			pIFont->Release();
			RetrieveHFont();
		}
		else
			if (OleCreateFontIndirect(&FontDescDefault, IID_IFontDisp,
				(void **)&m_pFont) == S_OK)
				RetrieveHFont();
	}

	return S_OK;
}

STDMETHODIMP CTimeEditCtrl::DoVerb(LONG iVerb, LPMSG lpmsg, IOleClientSite *pActiveSite, LONG lindex, HWND hwndParent, LPCRECT lprcPosRect)
{
	if (iVerb == 1)
		return DoVerbProperties(lprcPosRect, hwndParent);
	else if (iVerb == 2)
	{
		if (m_nFreezeEvents == 0)
			FireViewChange();
		return S_OK;
	}
	else
		return IOleObjectImpl<CTimeEditCtrl>::DoVerb(iVerb, lpmsg, pActiveSite, lindex, hwndParent, lprcPosRect);
}
