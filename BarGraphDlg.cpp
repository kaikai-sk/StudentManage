// BarGraphDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StudentManage.h"
#include "BarGraphDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBarGraphDlg dialog


CBarGraphDlg::CBarGraphDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBarGraphDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBarGraphDlg)
	m_nSelectCase = -1;
	//}}AFX_DATA_INIT
}


void CBarGraphDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBarGraphDlg)
	DDX_Radio(pDX, IDC_RADIO_Math, m_nSelectCase);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBarGraphDlg, CDialog)
	//{{AFX_MSG_MAP(CBarGraphDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBarGraphDlg message handlers
