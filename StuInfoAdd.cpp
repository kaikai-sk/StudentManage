// StuInfoAdd.cpp : implementation file
//

#include "stdafx.h"
#include "StudentManage.h"
#include "StuInfoAdd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStuInfoAdd dialog


CStuInfoAdd::CStuInfoAdd(CWnd* pParent /*=NULL*/)
	: CDialog(CStuInfoAdd::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStuInfoAdd)
	m_nEng = 100.0;
	m_sID = _T("µ¥¿­");
	m_nMath = 100.0;
	m_sName = _T("20131004087");
	m_nPhy = 100.0;
	//}}AFX_DATA_INIT
}


void CStuInfoAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStuInfoAdd)
	DDX_Text(pDX, IDC_EDIT_Eng, m_nEng);
	DDX_Text(pDX, IDC_EDIT_ID, m_sID);
	DDX_Text(pDX, IDC_EDIT_Math, m_nMath);
	DDX_Text(pDX, IDC_EDIT_Name, m_sName);
	DDX_Text(pDX, IDC_EDIT_Phy, m_nPhy);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStuInfoAdd, CDialog)
	//{{AFX_MSG_MAP(CStuInfoAdd)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStuInfoAdd message handlers
