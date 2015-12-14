; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLine_patcherDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "line_patcher.h"

ClassCount=4
Class1=CLine_patcherApp
Class2=CLine_patcherDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_LINE_PATCHER_DIALOG

[CLS:CLine_patcherApp]
Type=0
HeaderFile=line_patcher.h
ImplementationFile=line_patcher.cpp
Filter=N

[CLS:CLine_patcherDlg]
Type=0
HeaderFile=line_patcherDlg.h
ImplementationFile=line_patcherDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=line_patcherDlg.h
ImplementationFile=line_patcherDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LINE_PATCHER_DIALOG]
Type=1
Class=CLine_patcherDlg
ControlCount=3
Control1=IDC_BUTTON_FILEOPEN,button,1342242816
Control2=IDC_EDIT_FILENAME,edit,1350633600
Control3=IDC_EDIT_TEXT,edit,1353777348

