// FenDuanSort.cpp : implementation file
//

#include "stdafx.h"
#include "StudentManage.h"
#include "FenDuanSort.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFenDuanSort dialog


CFenDuanSort::CFenDuanSort(CWnd* pParent /*=NULL*/)
	: CDialog(CFenDuanSort::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFenDuanSort)
	m_nMax = 0.0;
	m_nMin = 0.0;
	m_nMath = -1;
	//}}AFX_DATA_INIT
}


void CFenDuanSort::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFenDuanSort)
	DDX_Text(pDX, IDC_EDIT_Max, m_nMax);
	DDX_Text(pDX, IDC_EDIT_Min, m_nMin);
	DDX_Radio(pDX, IDC_RADIO_Math, m_nMath);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFenDuanSort, CDialog)
	//{{AFX_MSG_MAP(CFenDuanSort)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFenDuanSort message handlers
