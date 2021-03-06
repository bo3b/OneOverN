
// OneOverNDlg.h : header file
//

#pragma once


// COneOverNDlg dialog
class COneOverNDlg : public CDialogEx
{
// Construction
public:
	COneOverNDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ONEOVERN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	CFont m_Font;
	CWnd* m_Time;
	CWnd* m_N;
	CWnd* m_Sum;
	CWinThread* m_worker;
	UINT_PTR m_Timer;
	SYSTEMTIME m_StartTime;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedCancel();
};

UINT __cdecl Calculation(LPVOID pParam);