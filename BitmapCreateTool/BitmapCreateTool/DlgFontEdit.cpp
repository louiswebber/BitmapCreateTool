// DlgFontEdit.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BitmapCreateTool.h"
#include "DlgFontEdit.h"
#include "afxdialogex.h"


// CDlgFontEdit �Ի���

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
// CDlgFontEdit ��Ϣ�������

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
	// TODO: �ڴ���ӿؼ�֪ͨ����������

}
