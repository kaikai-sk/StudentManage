#if !defined(AFX_FINDSTUID_H__00C83367_1752_4DB2_8B40_C66D55C294D7__INCLUDED_)
#define AFX_FINDSTUID_H__00C83367_1752_4DB2_8B40_C66D55C294D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FindStuID.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFindStuID dialog

class CFindStuID : public CDialog
{
// Construction
public:
	CFindStuID(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFindStuID)
	enum { IDD = IDD_DIALOG_Find_ID };
	CString	m_sFindStuID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFindStuID)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFindStuID)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINDSTUID_H__00C83367_1752_4DB2_8B40_C66D55C294D7__INCLUDED_)
