#if !defined(AFX_BARGRAPHDLG_H__13382174_74D5_4968_9EC9_6CE18EB607B8__INCLUDED_)
#define AFX_BARGRAPHDLG_H__13382174_74D5_4968_9EC9_6CE18EB607B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BarGraphDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBarGraphDlg dialog

class CBarGraphDlg : public CDialog
{
// Construction
public:
	CBarGraphDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBarGraphDlg)
	enum { IDD = IDD_DIALOG_Bar };
	int		m_nSelectCase;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBarGraphDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBarGraphDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BARGRAPHDLG_H__13382174_74D5_4968_9EC9_6CE18EB607B8__INCLUDED_)
