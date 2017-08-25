#if !defined(AFX_STUFIND_H__0B2215E7_5197_4248_A6AB_CBA25C1805EC__INCLUDED_)
#define AFX_STUFIND_H__0B2215E7_5197_4248_A6AB_CBA25C1805EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StuFind.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStuFind dialog

class CStuFind : public CDialog
{
// Construction
public:
	CStuFind(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStuFind)
	enum { IDD = IDD_DIALOG_Find };
	CString	m_sID;
	double	m_nMath;
	CString	m_sName;
	double	m_nPhy;
	double	m_nEng;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStuFind)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:

	// Generated message map functions
	//{{AFX_MSG(CStuFind)
	afx_msg void OnBUTTONfind();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUFIND_H__0B2215E7_5197_4248_A6AB_CBA25C1805EC__INCLUDED_)
