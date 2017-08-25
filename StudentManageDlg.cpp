// StudentManageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "afxtempl.h"
#include "StudentManage.h"
#include "StudentManageDlg.h"
#include "StuInfoAdd.h"
#include "FenDuanSort.h"
#include "FindStuID.h"
#include "StuFind.h"
#include "MohuFind.h"
#include "BarGraphDlg.h"
#include <fstream.h>
#include <iostream>
#include <string>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	


// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentManageDlg dialog

CStudentManageDlg::CStudentManageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStudentManageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStudentManageDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_sID="20131004087";
	m_sName="单凯";
	m_nMath=100;
	m_nPhy=100;
	m_nEng=100;
	m_bAsc=true;
    m_SortColumn=2;
	m_font.CreatePointFont(200,"华文行楷");
}

void CStudentManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStudentManageDlg)
	
	DDX_Control(pDX, IDC_LIST_studentinfo, m_myListCtrl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CStudentManageDlg, CDialog)
	//{{AFX_MSG_MAP(CStudentManageDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_open, OnBUTTONopen)
	ON_BN_CLICKED(IDC_BUTTON_add, OnBUTTONadd)
	ON_BN_CLICKED(IDC_BUTTON_find, OnBUTTONfind)
	ON_BN_CLICKED(IDC_BUTTON_Save, OnBUTTONSave)
	ON_BN_CLICKED(IDC_BUTTON_Correct, OnBUTTONCorrect)
	ON_BN_CLICKED(IDC_BUTTON_Delete, OnBUTTONDelete)
	ON_BN_CLICKED(IDC_BUTTON_sort, OnBUTTONsort)
	ON_BN_CLICKED(IDC_BUTTON_Statistic, OnBUTTONStatistic)
	ON_BN_CLICKED(IDC_BUTTON_SecStatistic, OnBUTTONSecStatistic)
	ON_BN_CLICKED(IDC_BUTTON_ClearAll, OnBUTTONClearAll)
	ON_BN_CLICKED(IDC_BUTTON_MohuFind, OnBUTTONMohuFind)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST_studentinfo, OnColumnclickLISTstudentinfo)
	ON_BN_CLICKED(IDC_BUTTON_Bar, OnBUTTONBar)
	ON_BN_CLICKED(IDC_BUTTON_FenDuanSort, OnBUTTONFenDuanSort)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentManageDlg message handlers

BOOL CStudentManageDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);


	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
			 
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_myListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_myListCtrl.InsertColumn(0,_T("学号"));
	m_myListCtrl.InsertColumn(1,_T("姓名"));
	m_myListCtrl.InsertColumn(2,_T("数学"));
	m_myListCtrl.InsertColumn(3,_T("物理"));
	m_myListCtrl.InsertColumn(4,_T("英语"));
    m_myListCtrl.InsertColumn(5,_T("总分"));
	CRect  rect4;
	m_myListCtrl.GetClientRect( rect4 );   //该函数获取窗口客户区的坐标.左上角（0，0），右下角。如果函数成功，返回一个非零值。如果函数失败，返回零。
	                                       //函数的作用总的来说就是把客户区的大小写进参数所指的Rect结构当中。
    m_myListCtrl.SetColumnWidth( 0, rect4.Width()/5 );
    m_myListCtrl.SetColumnWidth( 1, rect4.Width()/6 );
	m_myListCtrl.SetColumnWidth( 2, rect4.Width()/6 );
	m_myListCtrl.SetColumnWidth( 3, rect4.Width()/6 );
	m_myListCtrl.SetColumnWidth( 4, rect4.Width()/6 );
	m_myListCtrl.SetColumnWidth( 5, rect4.Width()/6 );
	DWORD dwStyle = m_myListCtrl.GetExtendedStyle();
       dwStyle |= LVS_EX_FULLROWSELECT;  //整行高亮所选中的行. 只适用Report Style
       dwStyle |= LVS_EX_GRIDLINES;           //网格线. 只适用Report Style
       dwStyle |= LVS_EX_CHECKBOXES;       //item前添加CheckBox控件
       m_myListCtrl.SetExtendedStyle( dwStyle );
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CStudentManageDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CStudentManageDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CStudentManageDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CStudentManageDlg::OnBUTTONopen() 
{
	CStdioFile file;
	CFileDialog fileDlg(TRUE);
	CString str,strtemp;
	fileDlg.m_ofn.lpstrTitle="我的文件打开对话框";
	fileDlg.m_ofn.lpstrFilter="Text Files(*.txt) \0*.txt\0All Files(*.*)\0 *.*\0\0";
	if (IDOK == fileDlg.DoModal())
	{
		str = fileDlg.GetFileName();
	}
    if ( !file.Open(_T(str),CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite))	
		return;	    
	else
	{
          m_myListCtrl.DeleteAllItems();
	      CString strOneline,strtemp,strtemp2;
		  int i=0;
		  CArray<CString,CString>strArray; 
	      while(file.ReadString(strOneline))
		  {
			  strtemp2=strOneline;
             while(strtemp2.Find(" ")+1)
			  {
				   int length= strtemp2.Find(" ");
			       strtemp =  strtemp2.Left(length);
				   strArray.Add(strtemp);
				   strtemp2=strOneline.Right(strtemp2.GetLength() - length - 1 );   
			  }
              strArray.Add(strtemp2);
			  m_myListCtrl.InsertItem(i,strArray.GetAt(0));
		      m_myListCtrl.SetItemText(i,1,strArray.GetAt(1));
		      m_myListCtrl.SetItemText(i,2,strArray.GetAt(2));
		      m_myListCtrl.SetItemText(i,3,strArray.GetAt(3));
              m_myListCtrl.SetItemText(i,4,strArray.GetAt(4));
			  strArray.RemoveAll();
			  i++ ;	  
		  }
	      m_nFileLineNum=i;  
	    
	}
	file.Close();
}

void CStudentManageDlg::OnBUTTONadd() 
{
     CStuInfoAdd dlg;
	 CStudentManageDlg dlg2;
     dlg.m_sID=dlg2.m_sID;
	 dlg.m_sName=dlg2.m_sName;
	 dlg.m_nMath=dlg2.m_nMath;
	 dlg.m_nPhy=dlg2.m_nPhy;
	 dlg.m_nEng=dlg2.m_nEng;
	
	 if(dlg.DoModal()==IDOK)
	 {
            UpdateData(TRUE);
			if(dlg.m_sID.IsEmpty()||dlg.m_sName.IsEmpty())
			{
					MessageBox("请输入完整！","提示！");
					return;
			}
			for(int i=0;i<m_myListCtrl.GetItemCount();i++)
			{
				if(dlg.m_sID==m_myListCtrl.GetItemText(i,0))
				{
					MessageBox("数据重复！","警告",MB_ICONWARNING);
                    return;
				}
			}
		    int nItems=m_nFileLineNum;
		    m_myListCtrl.InsertItem(nItems,dlg.m_sID);
            m_myListCtrl.SetItemText(nItems,1,dlg.m_sName);
		    CString str,str1,str2;
		    str.Format("%f",dlg.m_nMath);
		    m_myListCtrl.SetItemText(nItems,2,str);
		    str1.Format("%lf",dlg.m_nPhy);
		    m_myListCtrl.SetItemText(nItems,3,str1);
		    str2.Format("%lf",dlg.m_nEng);
		    m_myListCtrl.SetItemText(nItems,4,str2);
		    UpdateData(FALSE);	
			m_nFileLineNum+=1;
	 }
	 else return;
}



 void CStudentManageDlg::OnBUTTONfind() 
 {
    CStudentManageDlg maindlg;
	CFindStuID fdlg;
	bool flag=false;
	fdlg.m_sFindStuID=maindlg.m_sID;
	if(fdlg.DoModal()==IDOK)
	{
        maindlg.m_sID=fdlg.m_sFindStuID;
		
	
    
	  int iRow;
	  for(iRow=0;iRow<m_myListCtrl.GetItemCount();iRow++)
	  {
         maindlg.tempm_sID=m_myListCtrl.GetItemText(iRow,0);
         maindlg.tempm_sName=m_myListCtrl.GetItemText(iRow,1);
         maindlg.tempm_nMath=atof(m_myListCtrl.GetItemText(iRow,2));
		 maindlg.tempm_nPhy=atof(m_myListCtrl.GetItemText(iRow,3));
		 maindlg.tempm_nEng=atof(m_myListCtrl.GetItemText(iRow,4));
		 if(maindlg.m_sID==maindlg.tempm_sID)
		 {
			 
             CString str,str1,str2,strOneline;
		     str.Format("%lf",maindlg.tempm_nMath);
			 str1.Format("%lf",maindlg.tempm_nPhy);
			 str2.Format("%lf",maindlg.tempm_nEng);
             strOneline=maindlg.tempm_sID+" "+maindlg.tempm_sName+" "+str+" "+str1+" "+str2;
			 MessageBox(strOneline);
			 m_myListCtrl.SetFocus();
	         m_myListCtrl.SetItemState(iRow,LVIS_SELECTED,LVIS_SELECTED);
			 flag=true;
		 }
	 
	  }
	}
    else
	{
        flag=true;
		return;
	}
    if(flag==false)
			 MessageBox("所查找的学生不存在！","提示"); 
   
 }



void CStudentManageDlg::OnBUTTONSave() 
{
     CStdioFile file;
	 CFileDialog fileDlg(FALSE);
	 CString filepathname;
	 fileDlg.m_ofn.lpstrTitle="我的文件保存对话框";
	 fileDlg.m_ofn.lpstrFilter="Text Files(*.txt) \0*.txt\0All Files(*.*)\0 *.*\0\0";
     fileDlg.m_ofn.lpstrDefExt="txt";
     if(IDOK==fileDlg.DoModal())
	 {
		 filepathname=fileDlg.GetFileName();
	 }
	if(file.Open(_T(filepathname),CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite))
	{
		file.SeekToBegin();
		CString strID,strName,strMath,strPhy,strEng,strSum,strOneline;
		int iRow;
		for(iRow=0;iRow<m_myListCtrl.GetItemCount();iRow++)
		{
			strID=m_myListCtrl.GetItemText(iRow,0);
            strName=m_myListCtrl.GetItemText(iRow,1);
			strMath=m_myListCtrl.GetItemText(iRow,2);
			strPhy=m_myListCtrl.GetItemText(iRow,3);
			strEng=m_myListCtrl.GetItemText(iRow,4);
			strSum=m_myListCtrl.GetItemText(iRow,5);
            strOneline=strID+" "+strName+" "+strMath+" "+strPhy+" "+strEng+" "+strSum+'\n';
			file.WriteString(strOneline);
            strOneline.Empty();
		}
		file.Close();
		MessageBox("保存成功！","提示");
	}
	else
	{
		MessageBox("保存失败！","提示");
	}				
}



void CStudentManageDlg::OnBUTTONCorrect() 
{
	CStudentManageDlg maindlg;
	CFindStuID fdlg;
    CStuFind Fdlg;
	bool flag=false;
	if(fdlg.DoModal()==IDOK)
	{
        maindlg.m_sID=fdlg.m_sFindStuID;
        UpdateData(TRUE);
        Fdlg.m_sID=fdlg.m_sFindStuID;
		UpdateData(FALSE);
	
	}
	int iRow;
	if(!Fdlg.m_sID.IsEmpty())
	{
	   for(iRow=0;iRow<m_myListCtrl.GetItemCount();iRow++)
	   {
		maindlg.tempm_sID=m_myListCtrl.GetItemText(iRow,0);
		if(maindlg.m_sID==maindlg.tempm_sID)
		 {
             CStuFind dlg;
			 dlg.m_sID=m_myListCtrl.GetItemText(iRow,0);
			 dlg.m_sName=m_myListCtrl.GetItemText(iRow,1);
			 dlg.m_nMath=atof(m_myListCtrl.GetItemText(iRow,2));
             dlg.m_nPhy=atof(m_myListCtrl.GetItemText(iRow,3));
			 dlg.m_nEng=atof(m_myListCtrl.GetItemText(iRow,4));
			 if(dlg.DoModal()==IDOK)
			 {
				 m_myListCtrl.DeleteItem(iRow); 
				 maindlg.m_sID=maindlg.tempm_sID;
                 maindlg.m_sName=dlg.m_sName;
				 maindlg.m_nMath=dlg.m_nMath;
				 maindlg.m_nPhy=dlg.m_nPhy;
				 maindlg.m_nEng=dlg.m_nEng;
                 m_myListCtrl.InsertItem(iRow,maindlg.m_sID);
                 m_myListCtrl.SetItemText(iRow,1,maindlg.m_sName);
		         CString str,str1,str2,strOneline;
		         str.Format("%lf",maindlg.m_nMath);
		         m_myListCtrl.SetItemText(iRow,2,str);
		         str1.Format("%lf",maindlg.m_nPhy);
		         m_myListCtrl.SetItemText(iRow,3,str1);
		         str2.Format("%lf",maindlg.m_nEng);
		         m_myListCtrl.SetItemText(iRow,4,str2);
                 strOneline=maindlg.m_sID+" "+maindlg.m_sName+" "+str+" "+str1+" "+str2;
				 
			     MessageBox(strOneline);  
				 flag=true;
				 break;
				 
			 }
		}

	   }
	}
	else
	{
		CStuFind dlg;
		POSITION pos = m_myListCtrl.GetFirstSelectedItemPosition();
		int iItemIndex = m_myListCtrl.GetNextSelectedItem(pos);
		dlg.m_sID=m_myListCtrl.GetItemText(iItemIndex,0);
		dlg.m_sName=m_myListCtrl.GetItemText(iItemIndex,1);
		dlg.m_nMath=atof(m_myListCtrl.GetItemText(iItemIndex,2));
        dlg.m_nPhy=atof(m_myListCtrl.GetItemText(iItemIndex,3));
	    dlg.m_nEng=atof(m_myListCtrl.GetItemText(iItemIndex,4)); 
		if(dlg.DoModal()==IDOK)
		{
			if(dlg.m_sID.IsEmpty()||dlg.m_sName.IsEmpty())
			{
				MessageBox("请输入完整！","警告",MB_ICONWARNING);
				return;
			}
            m_myListCtrl.DeleteItem(iItemIndex); 
		    maindlg.m_sID=dlg.m_sID;
            maindlg.m_sName=dlg.m_sName;
	        maindlg.m_nMath=dlg.m_nMath;
		    maindlg.m_nPhy=dlg.m_nPhy;
		    maindlg.m_nEng=dlg.m_nEng;
            m_myListCtrl.InsertItem(iItemIndex,maindlg.m_sID);
            m_myListCtrl.SetItemText(iItemIndex,1,maindlg.m_sName);
		    CString str,str1,str2,strOneline;
		    str.Format("%lf",maindlg.m_nMath);
		    m_myListCtrl.SetItemText(iItemIndex,2,str);
		    str1.Format("%lf",maindlg.m_nPhy);
		    m_myListCtrl.SetItemText(iItemIndex,3,str1);
		    str2.Format("%lf",maindlg.m_nEng);
		    m_myListCtrl.SetItemText(iItemIndex,4,str2);
            strOneline=maindlg.m_sID+" "+maindlg.m_sName+" "+str+" "+str1+" "+str2;
	        MessageBox(strOneline);  
		    flag=true;
		}
	}
    if(flag==false)
      MessageBox("所修改的的学生不存在！","提示");
	
}

void CStudentManageDlg::OnBUTTONDelete() 
{
    CStudentManageDlg maindlg;
	CFindStuID fdlg;
	if(fdlg.DoModal()==IDOK)
	{
        maindlg.m_sID=fdlg.m_sFindStuID;
	}
	if( !maindlg.m_sID.IsEmpty())
	{
		int iRow;
	
		for(iRow=0;iRow<m_myListCtrl.GetItemCount();iRow++)
		{
		
			maindlg.tempm_sID=m_myListCtrl.GetItemText(iRow,0);
		    if(maindlg.m_sID==maindlg.tempm_sID)
			{ 

			   CString strOneline;
			    strOneline=m_myListCtrl.GetItemText(iRow,0)+" "+m_myListCtrl.GetItemText(iRow,1)+" "+m_myListCtrl.GetItemText(iRow,2)+" "+
				m_myListCtrl.GetItemText(iRow,3)+" "+m_myListCtrl.GetItemText(iRow,4);
			    if(MessageBox(strOneline,"提示",MB_YESNO |MB_ICONWARNING)==IDNO)
				return;
			    m_myListCtrl.DeleteItem(iRow); 
				m_nFileLineNum-=1;
			}
		}
	}
	else
	{
		POSITION pos = m_myListCtrl.GetFirstSelectedItemPosition();
		if (pos == NULL)
		{
			TRACE(_T("No items were selected!\n"));
		}
		else
		{
            DelReplyWithPosition(pos);     
		}
	}

}


 static int CALLBACK MyCompareProc(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{    CListCtrl* pListCtrl = (CListCtrl*) lParamSort; 
     CStudentManageDlg dlg;
     int m_SortColumn=dlg.m_SortColumn;
	 BOOL m_bAsc=dlg.m_bAsc;
     CString   strItem1 = pListCtrl->GetItemText(lParam1,m_SortColumn);    
     CString   strItem2 = pListCtrl->GetItemText(lParam2,m_SortColumn);        
     if (m_bAsc)    
	 {           
	     return strcmp(strItem2, strItem1);        
	 }    
     else        
	 {        
	     return strcmp(strItem1, strItem2);        
	 }
} 
 

 //函数功能：响应点击列表框上的表头动作，对列表中的数据进行排序
//DEL void CStudentManageDlg::OnColumnclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
//DEL {    
//DEL      NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;    // TODO: Add your control notification handler code here    
//DEL      m_SortColumn = pNMListView->iSubItem;        
//DEL      m_bAsc=!m_bAsc;//升序还是降序      
//DEL      int count = m_myListCtrl.GetItemCount(); //行数        
//DEL      for(int i=0; i<count;  i++)          
//DEL 	 {          
//DEL 	      m_myListCtrl.SetItemData(i,i);          
//DEL 	 }    
//DEL      m_myListCtrl.SortItems(MyCompareProc, (LPARAM) &m_myListCtrl);    
//DEL      *pResult = 0;
//DEL } 

//这里有一点需要注意的地方，m_bAsc和m_SortColumn必须声明为static变量，在类外初始化。MyCompareProc也要声明为static CALLBACK函数。

void CStudentManageDlg::OnBUTTONsort() 
{
     MessageBox("请单击表头！","提示");
}

void CStudentManageDlg::OnBUTTONStatistic() 
{
	for(int i=0;i<m_myListCtrl.GetItemCount();i++)
	{
		m_nMath=atof(m_myListCtrl.GetItemText(i,2));
		m_nPhy=atof(m_myListCtrl.GetItemText(i,3));
		m_nEng=atof(m_myListCtrl.GetItemText(i,3));
		m_nSum=m_nMath+m_nPhy+m_nEng;
		CString str;
		str.Format("%lf",m_nSum);
        m_myListCtrl.SetItemText(i,5,str);
	}
}
    
            

void CStudentManageDlg::OnBUTTONSecStatistic() 
{
	double sumMath=0,avMath;
	double sumPhy=0,avPhy;
	double sumEng=0,avEng;
	double fangcha1=0,fangcha2=0,fangcha3=0;
	int nItems;
	for( int i=0;i<m_myListCtrl.GetItemCount();i++)
	{
		sumMath+=atof(m_myListCtrl.GetItemText(i,2));
		sumPhy+=atof(m_myListCtrl.GetItemText(i,3));
        sumEng+=atof(m_myListCtrl.GetItemText(i,4));
	}
    avMath=sumMath/m_myListCtrl.GetItemCount();
    avPhy=sumPhy/m_myListCtrl.GetItemCount();
	avEng=sumEng/m_myListCtrl.GetItemCount();
    for(i=0;i<m_myListCtrl.GetItemCount();i++)
	{
        fangcha1+=(atof(m_myListCtrl.GetItemText(i,2))-avMath)*(atof(m_myListCtrl.GetItemText(i,2))-avMath);
		fangcha2+=(atof(m_myListCtrl.GetItemText(i,3))-avPhy)*(atof(m_myListCtrl.GetItemText(i,3))-avPhy);
		fangcha3+=(atof(m_myListCtrl.GetItemText(i,4))-avEng)*(atof(m_myListCtrl.GetItemText(i,4))-avEng);
	}
	fangcha1=fangcha1/m_myListCtrl.GetItemCount();
    fangcha2=fangcha2/m_myListCtrl.GetItemCount();
	fangcha3=fangcha3/m_myListCtrl.GetItemCount();
	CString str,str1,str2;
    str.Format("%lf",sumMath);
	str1.Format("%lf",sumPhy);
	str2.Format("%lf",sumEng);
	nItems=m_myListCtrl.GetItemCount();
	m_myListCtrl.InsertItem(nItems,"三科总成绩");
	m_myListCtrl.SetItemText(nItems,1,"  ");
	m_myListCtrl.SetItemText(nItems,2,str);
	m_myListCtrl.SetItemText(nItems,3,str1);
	m_myListCtrl.SetItemText(nItems,4,str2);
	str.Format("%lf",avMath);
	str1.Format("%lf",avPhy);
	str2.Format("%lf",avEng);
	m_myListCtrl.InsertItem(nItems+1,"三科平均成绩");
	m_myListCtrl.SetItemText(nItems+1,1,"  ");
	m_myListCtrl.SetItemText(nItems+1,2,str);
	m_myListCtrl.SetItemText(nItems+1,3,str1);
	m_myListCtrl.SetItemText(nItems+1,4,str2);
    str.Format("%lf",fangcha1);
	str1.Format("%lf",fangcha2);
	str2.Format("%lf",fangcha3);
	m_myListCtrl.InsertItem(nItems+2,"三科方差：");
	m_myListCtrl.SetItemText(nItems+2,1,"  ");
	m_myListCtrl.SetItemText(nItems+2,2,str);
	m_myListCtrl.SetItemText(nItems+2,3,str1);
	m_myListCtrl.SetItemText(nItems+2,4,str2);
    str.Format("%lf",sqrt(fangcha1));
	str1.Format("%lf",sqrt(fangcha2));
	str2.Format("%lf",sqrt(fangcha3));
    m_myListCtrl.InsertItem(nItems+3,"三科标准差：");
    m_myListCtrl.SetItemText(nItems+3,1,"  ");
	m_myListCtrl.SetItemText(nItems+3,2,str);
	m_myListCtrl.SetItemText(nItems+3,3,str1);
	m_myListCtrl.SetItemText(nItems+3,4,str2);
}

void CStudentManageDlg::OnBUTTONClearAll() 
{
	m_myListCtrl.DeleteAllItems();	
}

//NextDlgCtrl();
void CStudentManageDlg::OnBUTTONMohuFind() 
{
     	
    string strTempName,strListName,strTempID,strListID;
	CString strID,strName,strMath,strPhy,strEng,strSum,strOneline;
	bool flag=false;
	CArray<int,int> intArray;
    CMohuFind dlg;
	if(dlg.DoModal()==IDOK)
	{
		
		strTempName=dlg.m_sKeyName;
        strTempID=dlg.m_sKeyID;
	      for(int i=0;i<=m_myListCtrl.GetItemCount();i++)
		  {
			     strListName=m_myListCtrl.GetItemText(i,1);
                 strListID=m_myListCtrl.GetItemText(i,0);
		         if(strListName.find(strTempName)!=string::npos&&strListID.find(strTempID)!=string::npos)
				 {
					   m_myListCtrl.SetFocus();
                       m_myListCtrl.SetItemState(i,LVIS_SELECTED,LVIS_SELECTED);
                       intArray.Add(i);
					   strID=m_myListCtrl.GetItemText(i,0);
                       strName=m_myListCtrl.GetItemText(i,1);
			           strMath=m_myListCtrl.GetItemText(i,2);
			           strPhy=m_myListCtrl.GetItemText(i,3);
			           strEng=m_myListCtrl.GetItemText(i,4);
			           strSum=m_myListCtrl.GetItemText(i,5);
                       strOneline=strID+" "+strName+" "+strMath+" "+strPhy+" "+strEng+" "+strSum+'\n';
					   MessageBox(strOneline);
					   flag=true;
				 } 
		  }
		  if(flag==false)
			 MessageBox("所查找的学生不存在！","提示");
	}
}

void CStudentManageDlg::OnColumnclickLISTstudentinfo(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	m_SortColumn = pNMListView->iSubItem;

	int count = m_myListCtrl.GetItemCount(); //行数
    bool noswap;
	int i,j;
	CString temp;
	m_bAsc=!m_bAsc;//升序还是降序
	if(!m_bAsc)
	for(i=0;i<m_nFileLineNum;i++)
	{
		noswap=true;
		for(j=m_nFileLineNum-1;j>i;j--)
		{
			
			if(m_myListCtrl.GetItemText(j,m_SortColumn)<m_myListCtrl.GetItemText(j-1,m_SortColumn))
			{
				temp=m_myListCtrl.GetItemText(j,0);
				m_myListCtrl.SetItemText(j,0,m_myListCtrl.GetItemText(j-1,0));
				m_myListCtrl.SetItemText(j-1,0,temp);
				temp.Empty();
				temp=m_myListCtrl.GetItemText(j,5);
				m_myListCtrl.SetItemText(j,5,m_myListCtrl.GetItemText(j-1,5));
				m_myListCtrl.SetItemText(j-1,5,temp);
				temp.Empty();
				temp=m_myListCtrl.GetItemText(j,4);
				m_myListCtrl.SetItemText(j,4,m_myListCtrl.GetItemText(j-1,4));
				m_myListCtrl.SetItemText(j-1,4,temp);
				temp.Empty();
				temp=m_myListCtrl.GetItemText(j,3);
				m_myListCtrl.SetItemText(j,3,m_myListCtrl.GetItemText(j-1,3));
				m_myListCtrl.SetItemText(j-1,3,temp);
				temp.Empty();
				temp=m_myListCtrl.GetItemText(j,2);
				m_myListCtrl.SetItemText(j,2,m_myListCtrl.GetItemText(j-1,2));
				m_myListCtrl.SetItemText(j-1,2,temp);
				temp.Empty();
				temp=m_myListCtrl.GetItemText(j,1);
				m_myListCtrl.SetItemText(j,1,m_myListCtrl.GetItemText(j-1,1));
				m_myListCtrl.SetItemText(j-1,1,temp);
				temp.Empty();
                
				noswap=false;
			}
		}
		if(noswap) break;
	}


	if(m_bAsc)
	{
         	for(i=0;i<m_nFileLineNum;i++)
			{
		       
				noswap=true;
	           	for(j=m_nFileLineNum-1;j>i;j--)
				{

			          if(m_myListCtrl.GetItemText(j,m_SortColumn)>m_myListCtrl.GetItemText(j-1,m_SortColumn))
					  {
				temp=m_myListCtrl.GetItemText(j,0);
				m_myListCtrl.SetItemText(j,0,m_myListCtrl.GetItemText(j-1,0));
				m_myListCtrl.SetItemText(j-1,0,temp);
				temp.Empty();
				temp=m_myListCtrl.GetItemText(j,5);
				m_myListCtrl.SetItemText(j,5,m_myListCtrl.GetItemText(j-1,5));
				m_myListCtrl.SetItemText(j-1,5,temp);
				temp.Empty();
				temp=m_myListCtrl.GetItemText(j,4);
				m_myListCtrl.SetItemText(j,4,m_myListCtrl.GetItemText(j-1,4));
				m_myListCtrl.SetItemText(j-1,4,temp);
				temp.Empty();
				temp=m_myListCtrl.GetItemText(j,3);
				m_myListCtrl.SetItemText(j,3,m_myListCtrl.GetItemText(j-1,3));
				m_myListCtrl.SetItemText(j-1,3,temp);
				temp.Empty();
				temp=m_myListCtrl.GetItemText(j,2);
				m_myListCtrl.SetItemText(j,2,m_myListCtrl.GetItemText(j-1,2));
				m_myListCtrl.SetItemText(j-1,2,temp);
				temp.Empty();
				temp=m_myListCtrl.GetItemText(j,1);
				m_myListCtrl.SetItemText(j,1,m_myListCtrl.GetItemText(j-1,1));
				m_myListCtrl.SetItemText(j-1,1,temp);
				temp.Empty();
                
				noswap=false;
					  }
				}
		       if(noswap) break;
			}

	}
	if(m_SortColumn==2||m_SortColumn==3||m_SortColumn==4)
	{
          if(!m_bAsc)
	 for(i=0;i<m_nFileLineNum;i++)
	 {
		noswap=true;
		for(j=m_nFileLineNum-1;j>i;j--)
		{
			
			if(atof(m_myListCtrl.GetItemText(j,m_SortColumn))<atof(m_myListCtrl.GetItemText(j-1,m_SortColumn)))
			{
				temp=m_myListCtrl.GetItemText(j,0);
				m_myListCtrl.SetItemText(j,0,m_myListCtrl.GetItemText(j-1,0));
				m_myListCtrl.SetItemText(j-1,0,temp);
				temp.Empty();
				temp=m_myListCtrl.GetItemText(j,5);
				m_myListCtrl.SetItemText(j,5,m_myListCtrl.GetItemText(j-1,5));
				m_myListCtrl.SetItemText(j-1,5,temp);
				temp.Empty();
				temp=m_myListCtrl.GetItemText(j,4);
				m_myListCtrl.SetItemText(j,4,m_myListCtrl.GetItemText(j-1,4));
				m_myListCtrl.SetItemText(j-1,4,temp);
				temp.Empty();
				temp=m_myListCtrl.GetItemText(j,3);
				m_myListCtrl.SetItemText(j,3,m_myListCtrl.GetItemText(j-1,3));
				m_myListCtrl.SetItemText(j-1,3,temp);
				temp.Empty();
				temp=m_myListCtrl.GetItemText(j,2);
				m_myListCtrl.SetItemText(j,2,m_myListCtrl.GetItemText(j-1,2));
				m_myListCtrl.SetItemText(j-1,2,temp);
				temp.Empty();
				temp=m_myListCtrl.GetItemText(j,1);
				m_myListCtrl.SetItemText(j,1,m_myListCtrl.GetItemText(j-1,1));
				m_myListCtrl.SetItemText(j-1,1,temp);
				temp.Empty();
                
				noswap=false;
			}
		}
		if(noswap) break;
	 }

         if(m_bAsc)
	{
         	for(i=0;i<m_nFileLineNum;i++)
			{
		       
				noswap=true;
	           	for(j=m_nFileLineNum-1;j>i;j--)
				{

			          if(atof(m_myListCtrl.GetItemText(j,m_SortColumn))>atof(m_myListCtrl.GetItemText(j-1,m_SortColumn)))
					  {
				temp=m_myListCtrl.GetItemText(j,0);
				m_myListCtrl.SetItemText(j,0,m_myListCtrl.GetItemText(j-1,0));
				m_myListCtrl.SetItemText(j-1,0,temp);
				temp.Empty();
				temp=m_myListCtrl.GetItemText(j,5);
				m_myListCtrl.SetItemText(j,5,m_myListCtrl.GetItemText(j-1,5));
				m_myListCtrl.SetItemText(j-1,5,temp);
				temp.Empty();
				temp=m_myListCtrl.GetItemText(j,4);
				m_myListCtrl.SetItemText(j,4,m_myListCtrl.GetItemText(j-1,4));
				m_myListCtrl.SetItemText(j-1,4,temp);
				temp.Empty();
				temp=m_myListCtrl.GetItemText(j,3);
				m_myListCtrl.SetItemText(j,3,m_myListCtrl.GetItemText(j-1,3));
				m_myListCtrl.SetItemText(j-1,3,temp);
				temp.Empty();
				temp=m_myListCtrl.GetItemText(j,2);
				m_myListCtrl.SetItemText(j,2,m_myListCtrl.GetItemText(j-1,2));
				m_myListCtrl.SetItemText(j-1,2,temp);
				temp.Empty();
				temp=m_myListCtrl.GetItemText(j,1);
				m_myListCtrl.SetItemText(j,1,m_myListCtrl.GetItemText(j-1,1));
				m_myListCtrl.SetItemText(j-1,1,temp);
				temp.Empty();
                
				noswap=false;
					  }
				}
		       if(noswap) break;
			}

		 }
	}
	*pResult = 0;
}

void CStudentManageDlg::DelReplyWithPosition(POSITION pos)
{
    int iItemIndex = m_myListCtrl.GetNextSelectedItem(pos); 
	int i=0;
    if (pos != NULL)  
    {  
		i++;
        DelReplyWithPosition(pos);  
        m_myListCtrl.DeleteItem(iItemIndex);  
    }  
    else  
    {  
        m_myListCtrl.DeleteItem(iItemIndex);  
		
    }  
	m_nFileLineNum-=i;
    m_nFileLineNum-=1;
}

void CStudentManageDlg::OnBUTTONBar() 
{
	CBarGraphDlg dlg;
	double		m_dRateArray[5];
	double      m_nArray[5];
	int         bujige=0,jige=0,yiban=0,lianghao=0,youxiu=0;
	

	if(dlg.DoModal()==IDOK)
	{
		for(int i=0;i<m_myListCtrl.GetItemCount();i++)
		{
		     if(atof(m_myListCtrl.GetItemText(i,dlg.m_nSelectCase+2))<=60&&atof(m_myListCtrl.GetItemText(i,dlg.m_nSelectCase+2))>=0) 
			bujige++;
		     else if(atof(m_myListCtrl.GetItemText(i,dlg.m_nSelectCase+2))>60&&atof(m_myListCtrl.GetItemText(i,dlg.m_nSelectCase+2))<=70)
			jige++;
		     else if(atof(m_myListCtrl.GetItemText(i,dlg.m_nSelectCase+2))>70&&atof(m_myListCtrl.GetItemText(i,dlg.m_nSelectCase+2))<=80)
			yiban++;
		     else if(atof(m_myListCtrl.GetItemText(i,dlg.m_nSelectCase+2))>80&&atof(m_myListCtrl.GetItemText(i,dlg.m_nSelectCase+2))<=90)
			lianghao++;
		      else
			youxiu++;

		}
	  m_nArray[0]=bujige;
      m_nArray[1]=jige;
      m_nArray[2]=yiban;
	  m_nArray[3]=lianghao;
	  m_nArray[4]=youxiu;
	  int count=m_myListCtrl.GetItemCount();
    for(i=0;i<5;i++)
	{
		m_dRateArray[i]=(double)m_nArray[i]/(double)count;
	}

	    CClientDC dc(this);
        CPen pen;
	    pen.CreatePen(0,1,RGB(0,0,0));
		dc.SelectObject (pen);
		dc.Rectangle(0,290,400,260+290);
		dc.Rectangle(401,0+290,800,260+290);
        dc.MoveTo(80,220+290);
	    dc.LineTo(350,220+290);
	    dc.MoveTo(80,220+290);
	    dc.LineTo(80,20+290);
	    dc.MoveTo(350,220+290);
     	dc.LineTo(345,215+290);
        dc.MoveTo(350,220+290);
	    dc.LineTo(345,225+290);
	    dc.MoveTo(80,20+290);
        dc.LineTo(75,25+290);
	    dc.MoveTo(80,20+290);
		dc.LineTo(85,25+290);

	   for(i=1;i<=5;i++)
		{
	    	dc.MoveTo(80+50*i,220+290);
	    	dc.LineTo(80+50*i,215+290);
		}
	    dc.TextOut(80,225+290,"60以下  61-70   71-80    81-90   91-100     分数");
		dc.TextOut(40,20+290,"人数");
		double m;
		CString str;
		for(i=0;i<5;i++)
		{
			m=220*m_dRateArray[i];
			str.Format (_T("%3.1f"),m_nArray[i]);
			dc.Rectangle(80+50*i,220+290,80+50*(i+1),220-m+290);
			dc.TextOut(100+50*i,200-m+290,str);
		}
	
	//////////////////
		COLORREF color[5];
		color[0]=RGB(255,0,0);
		color[1]=RGB(0,255,0);
		color[2]=RGB(0,0,255);
		color[3]=RGB(255,165,0);
		color[4]=RGB(167,87,168);
		CString  sGrade[5],strRate[5];
		sGrade[0]="60分以下:";
		sGrade[1]="61----70:";
		sGrade[2]="71----80:";
		sGrade[3]="81----90:";
		sGrade[4]="91分以上:";
		for(i=0;i<5;i++)
		{
            strRate[i].Format("%1.3f",m_dRateArray[i]);
		}
		double dAngle=0,dxArray[6],dyArray[6];
        dxArray[0]=650;
		dyArray[0]=220+290;
		for(i=0;i<4;i++)
		{
			dAngle=dAngle+2*3.1415926*m_dRateArray[i];
			int a=2*dAngle/3.1415926;
			switch(a)
			{
			    case 0:
				    dxArray[i+1]=650;
				    dyArray[i+1]=100*tan(3.1415926/4-dAngle)+120+290;
				     break;
		    	case 1:
			    	dxArray[i+1]=100*tan(3*3.1415926/4-dAngle)+550;
				    dyArray[i+1]=20+290;
				    break;
			    case 2:
				    dxArray[i+1]=450;
				    dyArray[i+1]=100*tan(dAngle-5*3.1415926/4)+120+290;
				    break;
			    case 3:
			     	dxArray[i+1]=100*tan(dAngle-7*3.1415926/4)+550;
			    	dyArray[i+1]=220+290;
				    break;
			}
		}
		dxArray[5]=650;
		dyArray[5]=220+290;
		for(i=0;i<5;i++)
		{
			CBrush brush;
	        brush.CreateSolidBrush(color[i]);
	        dc.SelectObject (brush);
		    if(dxArray[i]!=dxArray[i+1]||dyArray[i]!=dyArray[i+1])
			{
				dc.Pie(450,20+290,650,220+290,dxArray[i],dyArray[i],dxArray[i+1],dyArray[i+1]);
			}
		    dc.Rectangle(750,50+30*i+290,790,70+30*i+290);
		    brush.DeleteObject();
		    dc.TextOut(680,30*i+52+290,sGrade[i]);
            dc.TextOut(401,30*i+52+290,strRate[i]);
		}
	}
}
	


void CStudentManageDlg::OnBUTTONFenDuanSort() 
{
   	CFenDuanSort dlg;
	bool flag=false;
	if(dlg.DoModal()==IDOK)
	{
		int j=dlg.m_nMath+2;
		for(int i=0;i<m_myListCtrl.GetItemCount();i++)
		{
			if(atof(m_myListCtrl.GetItemText(i,j))<=dlg.m_nMax && atof(m_myListCtrl.GetItemText(i,j))>=dlg.m_nMin)
			{
				m_myListCtrl.SetFocus();
	            m_myListCtrl.SetItemState(i,LVIS_SELECTED,LVIS_SELECTED);
				CString strID,strName,strMath,strPhy,strEng,strSum,strOneline;
				strID=m_myListCtrl.GetItemText(i,0);
                strName=m_myListCtrl.GetItemText(i,1);
			    strMath=m_myListCtrl.GetItemText(i,2);
				strPhy=m_myListCtrl.GetItemText(i,3);
		        strEng=m_myListCtrl.GetItemText(i,4);
			    strSum=m_myListCtrl.GetItemText(i,5);
                strOneline=strID+" "+strName+" "+strMath+" "+strPhy+" "+strEng+" "+strSum+'\n';
                MessageBox(strOneline);
				flag=true;
			}
		}
		if(flag==false)
			MessageBox("无符合此分数段的数据！");
	}

}

//HBRUSH CStudentManageDlg::OnCtlColor(CDC *pDC, CWnd *pWnd, UINT nCtlColor)
//{
//	HBRUSH hbr=CStudentManageDlg::OnCtlColor(pDC,pWnd,nCtlColor);
   // if(pWnd->GetDlgCtrlID()==IDC_STATIC_Text)
//	{

	  // pDC->SelectObject(&m_font);
///	}
	//return hbr;

//}

HBRUSH CStudentManageDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(pWnd->GetDlgCtrlID()==IDC_STATIC_Text)
	{
       pDC->SetTextColor(RGB(255,0,0));
       pDC->SetBkColor(RGB(0,200,0));
	   pDC->SelectObject(&m_font);
	}
	return hbr;
}
