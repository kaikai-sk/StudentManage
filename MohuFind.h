#if !defined(AFX_MOHUFIND_H__72A15406_3C9D_461C_A1A2_C4179F716EAD__INCLUDED_)
#define AFX_MOHUFIND_H__72A15406_3C9D_461C_A1A2_C4179F716EAD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MohuFind.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMohuFind dialog

class CMohuFind : public CDialog
{
// Construction
public:
	CMohuFind(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMohuFind)
	enum { IDD = IDD_DIALOG_MohuFind };
	CString	m_sKeyName;
	CString	m_sKeyID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMohuFind)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMohuFind)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOHUFIND_H__72A15406_3C9D_461C_A1A2_C4179F716EAD__INCLUDED_)
