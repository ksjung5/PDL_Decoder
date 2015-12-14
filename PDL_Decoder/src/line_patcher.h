// line_patcher.h : main header file for the LINE_PATCHER application
//

#if !defined(AFX_LINE_PATCHER_H__423A609B_8580_41F2_916C_E993D692D52C__INCLUDED_)
#define AFX_LINE_PATCHER_H__423A609B_8580_41F2_916C_E993D692D52C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLine_patcherApp:
// See line_patcher.cpp for the implementation of this class
//

class CLine_patcherApp : public CWinApp
{
public:
	CLine_patcherApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLine_patcherApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLine_patcherApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINE_PATCHER_H__423A609B_8580_41F2_916C_E993D692D52C__INCLUDED_)
