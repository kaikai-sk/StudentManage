#if !defined(AFX_FENDUANSORT_H__AAC06133_FBE3_4FB4_BBA9_1709F29D751F__INCLUDED_)
#define AFX_FENDUANSORT_H__AAC06133_FBE3_4FB4_BBA9_1709F29D751F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FenDuanSort.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFenDuanSort dialog

class CFenDuanSort : public CDialog
{
// Construction
public:
	CFenDuanSort(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFenDuanSort)
	enum { IDD = IDD_DIALOG1 };
	double	m_nMax;
	double	m_nMin;
	int		m_nMath;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFenDuanSort)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFenDuanSort)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FENDUANSORT_H__AAC06133_FBE3_4FB4_BBA9_1709F29D751F__INCLUDED_)
