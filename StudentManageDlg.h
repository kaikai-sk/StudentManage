// StudentManageDlg.h : header file
//

#if !defined(AFX_STUDENTMANAGEDLG_H__BF2DEA72_79A3_49E5_8EF1_6DE792DE3752__INCLUDED_)
#define AFX_STUDENTMANAGEDLG_H__BF2DEA72_79A3_49E5_8EF1_6DE792DE3752__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStudentManageDlg dialog

class CStudentManageDlg : public CDialog
{
// Construction
public:
	CStudentManageDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CStudentManageDlg)
	enum { IDD = IDD_STUDENTMANAGE_DIALOG };
	CComboBox	m_ComSort;
	CListCtrl	m_myListCtrl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentManageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CSoft4Dlg)
    //}}AFX_MSG


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStudentManageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBUTTONopen();
	afx_msg void OnBUTTONadd();
	afx_msg void OnBUTTONfind();
	afx_msg void OnBUTTONSave();
	afx_msg void OnBUTTONCorrect();
	afx_msg void OnBUTTONDelete();
	afx_msg void OnBUTTONsort();
	afx_msg void OnBUTTONStatistic();
	afx_msg void OnBUTTONSecStatistic();
	afx_msg void OnBUTTONClearAll();
	afx_msg void OnBUTTONMohuFind();
	afx_msg void OnColumnclickLISTstudentinfo(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBUTTONBar();
	afx_msg void OnBUTTONFenDuanSort();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CFont  m_font;
	double m_nEng;
	double m_nPhy;
	double m_nMath;
	double m_nSum;
	CString m_sName;
	CString m_sID;
	int    m_nFileLineNum;
   
public:
	//HBRUSH OnCtlColor(CDC* pDC,CWnd* pWnd,UINT nCtlColor);
	void DelReplyWithPosition(POSITION pos);
	double tempm_nEng;
	double tempm_nPhy;
	double tempm_nMath;
	CString tempm_sName;
	CString tempm_sID;
    int m_SortColumn;
    BOOL m_bAsc;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTMANAGEDLG_H__BF2DEA72_79A3_49E5_8EF1_6DE792DE3752__INCLUDED_)
