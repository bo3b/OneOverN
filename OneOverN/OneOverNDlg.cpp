
// OneOverNDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OneOverN.h"
#include "OneOverNDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// COneOverNDlg dialog



COneOverNDlg::COneOverNDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ONEOVERN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COneOverNDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COneOverNDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &COneOverNDlg::OnBnClickedOk)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// COneOverNDlg message handlers

BOOL COneOverNDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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


	// Creates a 12-point-Courier-font for use for text items
	m_Font.CreatePointFont(140, _T("Courier New"));
	
	m_Time = GetDlgItem(IDC_STATIC_TIME);
	m_N = GetDlgItem(IDC_STATIC_N);
	m_Sum = GetDlgItem(IDC_STATIC_SUM);
	m_Time->SetFont(&m_Font);
	m_N->SetFont(&m_Font);
	m_Sum->SetFont(&m_Font);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COneOverNDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void COneOverNDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COneOverNDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



// Click on the Start button

void COneOverNDlg::OnBnClickedOk()
{
	::Beep(800, 400);

	// Create a worker thread to do all the math.
	// So that the app can do normal event handling, and our
	// 1/n can run a full CPU, full throttle.
	//m_worker = AfxBeginThread();

	// Create a timer to send WM_TIMER events to the main loop,
	// every second.  We'll use this to update the values in the window.
	m_Timer = SetTimer(1, 1000, NULL);
}


// Called for each WM_TIMER event, once a second.
// Update the values in the main dialog.

void COneOverNDlg::OnTimer(UINT_PTR nIDEvent)
{
	m_Time->SetWindowText(L"arf");

	CDialogEx::OnTimer(nIDEvent);
}
