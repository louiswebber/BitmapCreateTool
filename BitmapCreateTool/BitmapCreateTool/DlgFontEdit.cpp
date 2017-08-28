// DlgFontEdit.cpp : 实现文件
//

#include "stdafx.h"
#include "BitmapCreateTool.h"
#include "DlgFontEdit.h"
#include "afxdialogex.h"


// CDlgFontEdit 对话框

IMPLEMENT_DYNAMIC(CDlgFontEdit, CDialogEx)

CDlgFontEdit::CDlgFontEdit(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgFontEdit::IDD, pParent)
{
}

CDlgFontEdit::~CDlgFontEdit()
{
}

void CDlgFontEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgFontEdit, CDialogEx)
	ON_BN_CLICKED(ID_FONT_SAVE, &CDlgFontEdit::OnBnClickedFontSave)
END_MESSAGE_MAP()

extern CString usrFontListString[256];
// CDlgFontEdit 消息处理程序

BOOL CDlgFontEdit::OnInitDialog()
{
	DWORD i = 0;

	CListBox* pDispList = ((CListBox*)GetDlgItem(IDC_DISP_FONT_LIST));
	for(i = 0; i <256; i++)
	{
		pDispList->InsertString(i, usrFontListString[i]);
	}
	Sleep(100);
	return TRUE;
}

void CDlgFontEdit::OnBnClickedFontSave()
{
	// TODO: 在此添加控件通知处理程序代码

}
