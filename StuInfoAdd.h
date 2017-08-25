#if !defined(AFX_STUINFOADD_H__554E6014_9184_4036_B5A8_4F12D07F78AB__INCLUDED_)
#define AFX_STUINFOADD_H__554E6014_9184_4036_B5A8_4F12D07F78AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StuInfoAdd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStuInfoAdd dialog

class CStuInfoAdd : public CDialog
{
// Construction
public:
	CStuInfoAdd(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStuInfoAdd)
	enum { IDD = IDD_DIALOG_Add };
	double	m_nEng;
	CString	m_sID;
	double	m_nMath;
	CString	m_sName;
	double	m_nPhy;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStuInfoAdd)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStuInfoAdd)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUINFOADD_H__554E6014_9184_4036_B5A8_4F12D07F78AB__INCLUDED_)
