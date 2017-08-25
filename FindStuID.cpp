// FindStuID.cpp : implementation file
//

#include "stdafx.h"
#include "StudentManage.h"
#include "FindStuID.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFindStuID dialog


CFindStuID::CFindStuID(CWnd* pParent /*=NULL*/)
	: CDialog(CFindStuID::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFindStuID)
	m_sFindStuID = _T("");
	//}}AFX_DATA_INIT
}


void CFindStuID::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFindStuID)
	DDX_Text(pDX, IDC_EDIT_Find_ID, m_sFindStuID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFindStuID, CDialog)
	//{{AFX_MSG_MAP(CFindStuID)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFindStuID message handlers
