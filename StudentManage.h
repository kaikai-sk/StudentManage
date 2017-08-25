// StudentManage.h : main header file for the STUDENTMANAGE application
//

#if !defined(AFX_STUDENTMANAGE_H__C8824086_E310_43C4_97E7_2BA99E44E5C8__INCLUDED_)
#define AFX_STUDENTMANAGE_H__C8824086_E310_43C4_97E7_2BA99E44E5C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStudentManageApp:
// See StudentManage.cpp for the implementation of this class
//

class CStudentManageApp : public CWinApp
{
public:
	CStudentManageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentManageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStudentManageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTMANAGE_H__C8824086_E310_43C4_97E7_2BA99E44E5C8__INCLUDED_)
