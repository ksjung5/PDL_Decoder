// line_patcherDlg.cpp : implementation file
//

#include "stdafx.h"
#include "line_patcher.h"
#include "line_patcherDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLine_patcherDlg dialog

CLine_patcherDlg::CLine_patcherDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLine_patcherDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLine_patcherDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLine_patcherDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLine_patcherDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLine_patcherDlg, CDialog)
	//{{AFX_MSG_MAP(CLine_patcherDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_FILEOPEN, OnButtonFileopen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLine_patcherDlg message handlers

BOOL CLine_patcherDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CLine_patcherDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLine_patcherDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLine_patcherDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CLine_patcherDlg::OnButtonFileopen() 
{
	// TODO: Add your control notification handler code here
	// TODO: Add your command handler code here
	// szFilters is a text string that includes two file name filters:
	// "*.my" for "MyType Files" and "*.*' for "All Files."
	char szFilters[]=
		"Text File (*.*)|*.*|All Files (*.*)|*.*||";
	
	// Create an Open dialog; the default file name extension is ".my".
	CFileDialog fileDlg (TRUE, "", "*.*",
		OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, szFilters, this);
	
	// Display the file dialog. When user clicks OK, fileDlg.DoModal() 
	// returns IDOK.
	UINT line_count=1;
	FILE* m_image_fp;
	char line_tmp[1024];
	char total_data[202400];
	char line_data[1024];
	
	/*TEST*/
	int line_temp_cnt = 0;

	memset(line_tmp, 0, sizeof(line_tmp));
	memset(total_data, 0, sizeof(total_data));
	memset(line_data, 0, sizeof(line_data));
			
	if( fileDlg.DoModal ()==IDOK )
	{
		CString fileName = fileDlg.GetFileName();
		CString pathName = fileDlg.GetPathName();

		//m_image_fp = fopen(fileName.GetBuffer(100),"r");
		m_image_fp = fopen(pathName, "r");

		if(m_image_fp == NULL)
		{
			MessageBoxA("ÆÄÀÏ¿ÀÇÂ¿¡·¯");
			return;
		}
		total_data[0] = '\0';
		while( !feof(m_image_fp) )
		{
			
			fgets(line_tmp,1024-5,m_image_fp);	//ÀÚµ¿À¸·Î NULL¹®ÀÚ »ðÀÔµÊ
			line_temp_cnt = strlen(line_tmp);
			line_tmp[strlen(line_tmp)-1] = '\0';
			sprintf(line_data,"%03x %s\r\n",line_count,line_tmp);			
			strcat(total_data,line_data);
			line_count++;
		}
		
		//SetDlgItemText(IDC_EDIT_FILENAME,fileName.GetBuffer(200));
		SetDlgItemText(IDC_EDIT_FILENAME,"TEMP_TEST.prn");
		SetDlgItemText(IDC_EDIT_TEXT,total_data);

	}	
}
