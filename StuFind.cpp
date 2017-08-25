// StuFind.cpp : implementation file
//

#include "stdafx.h"
#include "StudentManage.h"
#include "StuFind.h"
#include "StudentManageDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStuFind dialog


CStuFind::CStuFind(CWnd* pParent /*=NULL*/)
	: CDialog(CStuFind::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStuFind)
	m_sID = _T("");
	m_nMath = 0.0;
	m_sName = _T("");
	m_nPhy = 0.0;
	m_nEng = 0.0;
	//}}AFX_DATA_INIT
}


void CStuFind::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStuFind)
	DDX_Text(pDX, IDC_EDIT_ID, m_sID);
	DDX_Text(pDX, IDC_EDIT_Math, m_nMath);
	DDX_Text(pDX, IDC_EDIT_Name, m_sName);
	DDX_Text(pDX, IDC_EDIT_Phy, m_nPhy);
	DDX_Text(pDX, IDC_EDIT_Eng, m_nEng);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStuFind, CDialog)
	//{{AFX_MSG_MAP(CStuFind)
	ON_BN_CLICKED(IDC_BUTTON_find, OnBUTTONfind)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStuFind message handlers





void CStuFind::OnBUTTONfind() 
{
	CStuFind dlg;
	CStudentManageDlg maindlg;
   // UpdateData(TRUE);
	dlg.m_sID=maindlg.tempm_sID;
	dlg.m_sName=maindlg.tempm_sName;
	dlg.m_nMath=maindlg.tempm_nMath;
	dlg.m_nPhy=maindlg.tempm_nPhy;
	dlg.m_nEng=maindlg.tempm_nEng ;
    UpdateData(FALSE);
	
}
