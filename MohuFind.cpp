// MohuFind.cpp : implementation file
//

#include "stdafx.h"
#include "StudentManage.h"
#include "MohuFind.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMohuFind dialog


CMohuFind::CMohuFind(CWnd* pParent /*=NULL*/)
	: CDialog(CMohuFind::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMohuFind)
	m_sKeyName = _T("");
	m_sKeyID = _T("");
	//}}AFX_DATA_INIT
}


void CMohuFind::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMohuFind)
	DDX_Text(pDX, IDC_EDIT_KeyName, m_sKeyName);
	DDX_Text(pDX, IDC_EDIT_KeyID, m_sKeyID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMohuFind, CDialog)
	//{{AFX_MSG_MAP(CMohuFind)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMohuFind message handlers
