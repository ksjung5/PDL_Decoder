// line_patcherDlg.h : header file
//

#if !defined(AFX_LINE_PATCHERDLG_H__B77E5588_9283_4971_B891_88F6447A1495__INCLUDED_)
#define AFX_LINE_PATCHERDLG_H__B77E5588_9283_4971_B891_88F6447A1495__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CLine_patcherDlg dialog

class CLine_patcherDlg : public CDialog
{
// Construction
public:
	CLine_patcherDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CLine_patcherDlg)
	enum { IDD = IDD_LINE_PATCHER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLine_patcherDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CLine_patcherDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonFileopen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINE_PATCHERDLG_H__B77E5588_9283_4971_B891_88F6447A1495__INCLUDED_)
