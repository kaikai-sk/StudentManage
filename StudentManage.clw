; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CStudentManageDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "StudentManage.h"

ClassCount=9
Class1=CStudentManageApp
Class2=CStudentManageDlg
Class3=CAboutDlg

ResourceCount=9
Resource1=IDD_DIALOG_Find
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CStuInfoAdd
Resource4=IDD_DIALOG_Bar
Class5=CStuFind
Resource5=IDD_DIALOG_Add
Class6=CFindStuID
Resource6=IDD_DIALOG_Find_ID
Class7=CMohuFind
Resource7=IDD_DIALOG_MohuFind
Class8=CBarGraphDlg
Resource8=IDD_STUDENTMANAGE_DIALOG
Class9=CFenDuanSort
Resource9=IDD_DIALOG_FenDuanFind

[CLS:CStudentManageApp]
Type=0
HeaderFile=StudentManage.h
ImplementationFile=StudentManage.cpp
Filter=N

[CLS:CStudentManageDlg]
Type=0
HeaderFile=StudentManageDlg.h
ImplementationFile=StudentManageDlg.cpp
Filter=D
LastObject=IDC_BUTTON_Correct
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=StudentManageDlg.h
ImplementationFile=StudentManageDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_STUDENTMANAGE_DIALOG]
Type=1
Class=CStudentManageDlg
ControlCount=17
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST_studentinfo,SysListView32,1350631689
Control4=IDC_BUTTON_open,button,1342242816
Control5=IDC_BUTTON_add,button,1342242816
Control6=IDC_BUTTON_find,button,1342242816
Control7=IDC_BUTTON_sort,button,1342242816
Control8=IDC_BUTTON_Save,button,1342242816
Control9=IDC_BUTTON_Correct,button,1342242816
Control10=IDC_BUTTON_Delete,button,1342242816
Control11=IDC_BUTTON_Statistic,button,1342242816
Control12=IDC_BUTTON_SecStatistic,button,1342242816
Control13=IDC_BUTTON_ClearAll,button,1342242816
Control14=IDC_BUTTON_MohuFind,button,1342242816
Control15=IDC_BUTTON_Bar,button,1342242816
Control16=IDC_BUTTON_FenDuanSort,button,1342242816
Control17=IDC_STATIC_Text,static,1342308352

[CLS:CStuInfoAdd]
Type=0
HeaderFile=StuInfoAdd.h
ImplementationFile=StuInfoAdd.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CStuInfoAdd

[DLG:IDD_DIALOG_Add]
Type=1
Class=CStuInfoAdd
ControlCount=13
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,button,1342177287
Control9=IDC_EDIT_ID,edit,1350631552
Control10=IDC_EDIT_Name,edit,1350631552
Control11=IDC_EDIT_Math,edit,1350631552
Control12=IDC_EDIT_Phy,edit,1350631552
Control13=IDC_EDIT_Eng,edit,1350631552

[DLG:IDD_DIALOG_Find]
Type=1
Class=CStuFind
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_ID,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_Name,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_Math,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT_Phy,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT_Eng,edit,1350631552

[CLS:CStuFind]
Type=0
HeaderFile=StuFind.h
ImplementationFile=StuFind.cpp
BaseClass=CDialog
Filter=D
LastObject=CStuFind
VirtualFilter=dWC

[CLS:CFindStuID]
Type=0
HeaderFile=FindStuID.h
ImplementationFile=FindStuID.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT_Find_ID

[DLG:IDD_DIALOG_Find_ID]
Type=1
Class=CFindStuID
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_Find_ID,edit,1350631552

[DLG:IDD_DIALOG_MohuFind]
Type=1
Class=CMohuFind
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_KeyName,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_KeyID,edit,1350631552
Control7=IDC_STATIC,static,1342308352

[CLS:CMohuFind]
Type=0
HeaderFile=MohuFind.h
ImplementationFile=MohuFind.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT_KeyID

[DLG:IDD_DIALOG_Bar]
Type=1
Class=CBarGraphDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_RADIO_Math,button,1342308361
Control5=IDC_RADIO_Phy,button,1342177289
Control6=IDC_RADIO_Eng,button,1342177289

[CLS:CBarGraphDlg]
Type=0
HeaderFile=BarGraphDlg.h
ImplementationFile=BarGraphDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_RADIO_Math
VirtualFilter=dWC

[CLS:CFenDuanSort]
Type=0
HeaderFile=FenDuanSort.h
ImplementationFile=FenDuanSort.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_Min
VirtualFilter=dWC

[DLG:IDD_DIALOG_FenDuanFind]
Type=1
Class=CFenDuanSort
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RADIO_Math,button,1342308361
Control4=IDC_RADIO_Phy,button,1342177289
Control5=IDC_RADIO_Eng,button,1342177289
Control6=IDC_RADIO_Sum,button,1342177289
Control7=IDC_STATIC,button,1342177287
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_Max,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDIT_Min,edit,1350631552

