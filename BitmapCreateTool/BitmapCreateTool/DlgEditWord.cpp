// DlgEditWord.cpp : 实现文件
//

#include "stdafx.h"
#include "BitmapCreateTool.h"
#include "DlgEditWord.h"
#include "afxdialogex.h"
#include "InitUsrFontDispList.h"


// CDlgEditWord 对话框

IMPLEMENT_DYNAMIC(CDlgEditWord, CDialogEx)

CDlgEditWord::CDlgEditWord(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgEditWord::IDD, pParent)
{
}

CDlgEditWord::~CDlgEditWord()
{
}

void CDlgEditWord::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgEditWord, CDialogEx)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON1, &CDlgEditWord::OnBnClickedMfcmenubutton1)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON2, &CDlgEditWord::OnBnClickedMfcmenubutton2)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON3, &CDlgEditWord::OnBnClickedMfcmenubutton3)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON4, &CDlgEditWord::OnBnClickedMfcmenubutton4)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON5, &CDlgEditWord::OnBnClickedMfcmenubutton5)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON6, &CDlgEditWord::OnBnClickedMfcmenubutton6)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON7, &CDlgEditWord::OnBnClickedMfcmenubutton7)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON8, &CDlgEditWord::OnBnClickedMfcmenubutton8)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON9, &CDlgEditWord::OnBnClickedMfcmenubutton9)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON10, &CDlgEditWord::OnBnClickedMfcmenubutton10)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON11, &CDlgEditWord::OnBnClickedMfcmenubutton11)

	ON_BN_CLICKED(IDC_MFCMENUBUTTON12, &CDlgEditWord::OnBnClickedMfcmenubutton12)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON13, &CDlgEditWord::OnBnClickedMfcmenubutton13)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON14, &CDlgEditWord::OnBnClickedMfcmenubutton14)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON15, &CDlgEditWord::OnBnClickedMfcmenubutton15)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON16, &CDlgEditWord::OnBnClickedMfcmenubutton16)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON17, &CDlgEditWord::OnBnClickedMfcmenubutton17)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON18, &CDlgEditWord::OnBnClickedMfcmenubutton18)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON19, &CDlgEditWord::OnBnClickedMfcmenubutton19)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON20, &CDlgEditWord::OnBnClickedMfcmenubutton20)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON21, &CDlgEditWord::OnBnClickedMfcmenubutton21)
	ON_BN_CLICKED(IDC_MFCMENUBUTTON22, &CDlgEditWord::OnBnClickedMfcmenubutton22)
END_MESSAGE_MAP()


// CDlgEditWord 消息处理程序
//初始化程序，必须等到子窗口创建完毕之后再初始化，另外定义函数，在窗口create之后调用此初始化函数

//为使用for循环，缩短代码篇幅，定义必须连续

BOOL CDlgEditWord::InitDialog()
{
	{
		CString buf;
		unsigned int i;

		menuLeft.LoadMenuW(IDR_MENU1);
		for(i = 0; i < 11; i++)
		{
			((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON1 + i)))->m_hMenu	= menuLeft.GetSubMenu(0)-> GetSafeHmenu();
			((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON1 + i)))->m_bOSMenu	= TRUE;
			//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
			menuLeft.GetSubMenu(0)->GetMenuStringW(0,(CString&)buf,MF_BYPOSITION);
			SetDlgItemText(IDC_MFCMENUBUTTON1 + i,(LPCTSTR)buf);
		}

		menuRight.LoadMenuW(IDR_MENU2);
		for(i = 0; i < 11; i++)
		{
			((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON12 + i)))->m_hMenu	= menuRight.GetSubMenu(0)-> GetSafeHmenu();
			((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON12 + i)))->m_bOSMenu	= TRUE;
			//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
			menuRight.GetSubMenu(0)->GetMenuStringW(0,(CString&)buf,MF_BYPOSITION);
			SetDlgItemText(IDC_MFCMENUBUTTON12 + i,(LPCTSTR)buf);
		}
	}
	return TRUE;
}

void CDlgEditWord::OnBnClickedMfcmenubutton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString buf;
	int postion	= 0, indexId = 0;
	indexId	= ((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON1)))->m_nMenuResult;
	switch(indexId)
	{
		case ID_MENU1_0:	postion	= 0;	break;
		case ID_MENU1_1:	postion	= 1;	break;
		case ID_MENU1_2:	postion	= 2;	break;
		case ID_MENU1_3:	postion	= 3;	break;
		case ID_MENU1_4:	postion	= 4;	break;
		case ID_MENU1_5:	postion	= 5;	break;
		case ID_MENU1_6:	postion	= 6;	break;
		case ID_MENU1_7:	postion	= 7;	break;
		case ID_MENU1_8:	postion	= 8;	break;
		default:	postion	= 0;	break;
	}
	//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
	menuLeft.GetSubMenu(0)->GetMenuStringW(postion,(CString&)buf,MF_BYPOSITION);
	SetDlgItemText(IDC_MFCMENUBUTTON1,(LPCTSTR)buf);
	::SendMessage(GetParent()->m_hWnd,  CHILD_DLG_MENUBTN_SELECTMSG, 0, (IDC_MFCMENUBUTTON1 << 16) | postion);
}


void CDlgEditWord::OnBnClickedMfcmenubutton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString buf;
	int postion	= 0, indexId = 0;
	indexId	= ((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON2)))->m_nMenuResult;
	switch(indexId)
	{
		case ID_MENU1_0:	postion	= 0;	break;
		case ID_MENU1_1:	postion	= 1;	break;
		case ID_MENU1_2:	postion	= 2;	break;
		case ID_MENU1_3:	postion	= 3;	break;
		case ID_MENU1_4:	postion	= 4;	break;
		case ID_MENU1_5:	postion	= 5;	break;
		case ID_MENU1_6:	postion	= 6;	break;
		case ID_MENU1_7:	postion	= 7;	break;
		case ID_MENU1_8:	postion	= 8;	break;
		default:	postion	= 0;	break;
	}
	menuLeft.GetSubMenu(0)->GetMenuStringW(postion,(CString&)buf,MF_BYPOSITION);//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
	SetDlgItemText(IDC_MFCMENUBUTTON2,(LPCTSTR)buf);
	::SendMessage(GetParent()->m_hWnd,  CHILD_DLG_MENUBTN_SELECTMSG, 0, (IDC_MFCMENUBUTTON2 << 16) | postion);
}


void CDlgEditWord::OnBnClickedMfcmenubutton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString buf;
	int postion	= 0, indexId = 0;
	indexId	= ((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON3)))->m_nMenuResult;
	switch(indexId)
	{
		case ID_MENU1_0:	postion	= 0;	break;
		case ID_MENU1_1:	postion	= 1;	break;
		case ID_MENU1_2:	postion	= 2;	break;
		case ID_MENU1_3:	postion	= 3;	break;
		case ID_MENU1_4:	postion	= 4;	break;
		case ID_MENU1_5:	postion	= 5;	break;
		case ID_MENU1_6:	postion	= 6;	break;
		case ID_MENU1_7:	postion	= 7;	break;
		case ID_MENU1_8:	postion	= 8;	break;
		default:	postion	= 0;	break;
	}
	menuLeft.GetSubMenu(0)->GetMenuStringW(postion,(CString&)buf,MF_BYPOSITION);//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
	SetDlgItemText(IDC_MFCMENUBUTTON3,(LPCTSTR)buf);
	::SendMessage(GetParent()->m_hWnd,  CHILD_DLG_MENUBTN_SELECTMSG, 0, (IDC_MFCMENUBUTTON3 << 16) | postion);
}


void CDlgEditWord::OnBnClickedMfcmenubutton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CString buf;
	int postion	= 0, indexId = 0;
	indexId	= ((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON4)))->m_nMenuResult;
	switch(indexId)
	{
		case ID_MENU1_0:	postion	= 0;	break;
		case ID_MENU1_1:	postion	= 1;	break;
		case ID_MENU1_2:	postion	= 2;	break;
		case ID_MENU1_3:	postion	= 3;	break;
		case ID_MENU1_4:	postion	= 4;	break;
		case ID_MENU1_5:	postion	= 5;	break;
		case ID_MENU1_6:	postion	= 6;	break;
		case ID_MENU1_7:	postion	= 7;	break;
		case ID_MENU1_8:	postion	= 8;	break;
		default:	postion	= 0;	break;
	}
	menuLeft.GetSubMenu(0)->GetMenuStringW(postion,(CString&)buf,MF_BYPOSITION);//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
	SetDlgItemText(IDC_MFCMENUBUTTON4,(LPCTSTR)buf);
	::SendMessage(GetParent()->m_hWnd,  CHILD_DLG_MENUBTN_SELECTMSG, 0, (IDC_MFCMENUBUTTON4 << 16) | postion);
}


void CDlgEditWord::OnBnClickedMfcmenubutton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CString buf;
	int postion	= 0, indexId = 0;
	indexId	= ((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON5)))->m_nMenuResult;
	switch(indexId)
	{
		case ID_MENU1_0:	postion	= 0;	break;
		case ID_MENU1_1:	postion	= 1;	break;
		case ID_MENU1_2:	postion	= 2;	break;
		case ID_MENU1_3:	postion	= 3;	break;
		case ID_MENU1_4:	postion	= 4;	break;
		case ID_MENU1_5:	postion	= 5;	break;
		case ID_MENU1_6:	postion	= 6;	break;
		case ID_MENU1_7:	postion	= 7;	break;
		case ID_MENU1_8:	postion	= 8;	break;
		default:	postion	= 0;	break;
	}
	menuLeft.GetSubMenu(0)->GetMenuStringW(postion,(CString&)buf,MF_BYPOSITION);//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
	SetDlgItemText(IDC_MFCMENUBUTTON5,(LPCTSTR)buf);
	::SendMessage(GetParent()->m_hWnd,  CHILD_DLG_MENUBTN_SELECTMSG, 0, (IDC_MFCMENUBUTTON5 << 16) | postion);
}


void CDlgEditWord::OnBnClickedMfcmenubutton6()
{
	// TODO: 在此添加控件通知处理程序代码
	CString buf;
	int postion	= 0, indexId = 0;
	indexId	= ((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON6)))->m_nMenuResult;
	switch(indexId)
	{
		case ID_MENU1_0:	postion	= 0;	break;
		case ID_MENU1_1:	postion	= 1;	break;
		case ID_MENU1_2:	postion	= 2;	break;
		case ID_MENU1_3:	postion	= 3;	break;
		case ID_MENU1_4:	postion	= 4;	break;
		case ID_MENU1_5:	postion	= 5;	break;
		case ID_MENU1_6:	postion	= 6;	break;
		case ID_MENU1_7:	postion	= 7;	break;
		case ID_MENU1_8:	postion	= 8;	break;
		default:	postion	= 0;	break;
	}
	menuLeft.GetSubMenu(0)->GetMenuStringW(postion,(CString&)buf,MF_BYPOSITION);//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
	SetDlgItemText(IDC_MFCMENUBUTTON6,(LPCTSTR)buf);
	::SendMessage(GetParent()->m_hWnd,  CHILD_DLG_MENUBTN_SELECTMSG, 0, (IDC_MFCMENUBUTTON6 << 16) | postion);
}


void CDlgEditWord::OnBnClickedMfcmenubutton7()
{
	// TODO: 在此添加控件通知处理程序代码
	CString buf;
	int postion	= 0, indexId = 0;
	indexId	= ((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON7)))->m_nMenuResult;
	switch(indexId)
	{
		case ID_MENU1_0:	postion	= 0;	break;
		case ID_MENU1_1:	postion	= 1;	break;
		case ID_MENU1_2:	postion	= 2;	break;
		case ID_MENU1_3:	postion	= 3;	break;
		case ID_MENU1_4:	postion	= 4;	break;
		case ID_MENU1_5:	postion	= 5;	break;
		case ID_MENU1_6:	postion	= 6;	break;
		case ID_MENU1_7:	postion	= 7;	break;
		case ID_MENU1_8:	postion	= 8;	break;
		default:	postion	= 0;	break;
	}
	menuLeft.GetSubMenu(0)->GetMenuStringW(postion,(CString&)buf,MF_BYPOSITION);//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
	SetDlgItemText(IDC_MFCMENUBUTTON7,(LPCTSTR)buf);
	::SendMessage(GetParent()->m_hWnd,  CHILD_DLG_MENUBTN_SELECTMSG, 0, (IDC_MFCMENUBUTTON7 << 16) | postion);
}


void CDlgEditWord::OnBnClickedMfcmenubutton8()
{
	// TODO: 在此添加控件通知处理程序代码
	CString buf;
	int postion	= 0, indexId = 0;
	indexId	= ((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON8)))->m_nMenuResult;
	switch(indexId)
	{
		case ID_MENU1_0:	postion	= 0;	break;
		case ID_MENU1_1:	postion	= 1;	break;
		case ID_MENU1_2:	postion	= 2;	break;
		case ID_MENU1_3:	postion	= 3;	break;
		case ID_MENU1_4:	postion	= 4;	break;
		case ID_MENU1_5:	postion	= 5;	break;
		case ID_MENU1_6:	postion	= 6;	break;
		case ID_MENU1_7:	postion	= 7;	break;
		case ID_MENU1_8:	postion	= 8;	break;
		default:	postion	= 0;	break;
	}
	menuLeft.GetSubMenu(0)->GetMenuStringW(postion,(CString&)buf,MF_BYPOSITION);//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
	SetDlgItemText(IDC_MFCMENUBUTTON8,(LPCTSTR)buf);
	::SendMessage(GetParent()->m_hWnd,  CHILD_DLG_MENUBTN_SELECTMSG, 0, (IDC_MFCMENUBUTTON8 << 16) | postion);
}


void CDlgEditWord::OnBnClickedMfcmenubutton9()
{
	// TODO: 在此添加控件通知处理程序代码
	CString buf;
	int postion	= 0, indexId = 0;
	indexId	= ((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON9)))->m_nMenuResult;
	switch(indexId)
	{
		case ID_MENU1_0:	postion	= 0;	break;
		case ID_MENU1_1:	postion	= 1;	break;
		case ID_MENU1_2:	postion	= 2;	break;
		case ID_MENU1_3:	postion	= 3;	break;
		case ID_MENU1_4:	postion	= 4;	break;
		case ID_MENU1_5:	postion	= 5;	break;
		case ID_MENU1_6:	postion	= 6;	break;
		case ID_MENU1_7:	postion	= 7;	break;
		case ID_MENU1_8:	postion	= 8;	break;
		default:	postion	= 0;	break;
	}
	menuLeft.GetSubMenu(0)->GetMenuStringW(postion,(CString&)buf,MF_BYPOSITION);//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
	SetDlgItemText(IDC_MFCMENUBUTTON9,(LPCTSTR)buf);
	::SendMessage(GetParent()->m_hWnd,  CHILD_DLG_MENUBTN_SELECTMSG, 0, (IDC_MFCMENUBUTTON9 << 16) | postion);
}


void CDlgEditWord::OnBnClickedMfcmenubutton10()
{
	// TODO: 在此添加控件通知处理程序代码
	CString buf;
	int postion	= 0, indexId = 0;
	indexId	= ((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON10)))->m_nMenuResult;
	switch(indexId)
	{
		case ID_MENU1_0:	postion	= 0;	break;
		case ID_MENU1_1:	postion	= 1;	break;
		case ID_MENU1_2:	postion	= 2;	break;
		case ID_MENU1_3:	postion	= 3;	break;
		case ID_MENU1_4:	postion	= 4;	break;
		case ID_MENU1_5:	postion	= 5;	break;
		case ID_MENU1_6:	postion	= 6;	break;
		case ID_MENU1_7:	postion	= 7;	break;
		case ID_MENU1_8:	postion	= 8;	break;
		default:	postion	= 0;	break;
	}
	menuLeft.GetSubMenu(0)->GetMenuStringW(postion,(CString&)buf,MF_BYPOSITION);//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
	SetDlgItemText(IDC_MFCMENUBUTTON10,(LPCTSTR)buf);
	::SendMessage(GetParent()->m_hWnd,  CHILD_DLG_MENUBTN_SELECTMSG, 0, (IDC_MFCMENUBUTTON10 << 16) | postion);
}


void CDlgEditWord::OnBnClickedMfcmenubutton11()
{
	// TODO: 在此添加控件通知处理程序代码
	CString buf;
	int postion	= 0, indexId = 0;
	indexId	= ((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON11)))->m_nMenuResult;
	switch(indexId)
	{
		case ID_MENU1_0:	postion	= 0;	break;
		case ID_MENU1_1:	postion	= 1;	break;
		case ID_MENU1_2:	postion	= 2;	break;
		case ID_MENU1_3:	postion	= 3;	break;
		case ID_MENU1_4:	postion	= 4;	break;
		case ID_MENU1_5:	postion	= 5;	break;
		case ID_MENU1_6:	postion	= 6;	break;
		case ID_MENU1_7:	postion	= 7;	break;
		case ID_MENU1_8:	postion	= 8;	break;
		default:	postion	= 0;	break;
	}
	menuLeft.GetSubMenu(0)->GetMenuStringW(postion,(CString&)buf,MF_BYPOSITION);//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
	SetDlgItemText(IDC_MFCMENUBUTTON11,(LPCTSTR)buf);
	::SendMessage(GetParent()->m_hWnd,  CHILD_DLG_MENUBTN_SELECTMSG, 0, (IDC_MFCMENUBUTTON11 << 16) | postion);
}


void CDlgEditWord::OnBnClickedMfcmenubutton12()
{
	// TODO: 在此添加控件通知处理程序代码
	CString buf;
	int postion	= 0, indexId = 0;
	indexId	= ((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON12)))->m_nMenuResult;
	switch(indexId)
	{
		case ID_MENU2_0:	postion	= 0;	break;
		case ID_MENU2_1:	postion	= 1;	break;
		case ID_MENU2_2:	postion	= 2;	break;
		case ID_MENU2_3:	postion	= 3;	break;
		case ID_MENU2_4:	postion	= 4;	break;
		case ID_MENU2_5:	postion	= 5;	break;
		case ID_MENU2_6:	postion	= 6;	break;
		case ID_MENU2_7:	postion	= 7;	break;
		case ID_MENU2_8:	postion	= 8;	break;
		default:	postion	= 0;	break;
	}
	menuRight.GetSubMenu(0)->GetMenuStringW(postion,(CString&)buf,MF_BYPOSITION);//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
	SetDlgItemText(IDC_MFCMENUBUTTON12,(LPCTSTR)buf);
	::SendMessage(GetParent()->m_hWnd,  CHILD_DLG_MENUBTN_SELECTMSG, 1, (IDC_MFCMENUBUTTON12 << 16) | postion);
}


void CDlgEditWord::OnBnClickedMfcmenubutton13()
{
	// TODO: 在此添加控件通知处理程序代码
	CString buf;
	int postion	= 0, indexId = 0;
	indexId	= ((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON13)))->m_nMenuResult;
	switch(indexId)
	{
		case ID_MENU2_0:	postion	= 0;	break;
		case ID_MENU2_1:	postion	= 1;	break;
		case ID_MENU2_2:	postion	= 2;	break;
		case ID_MENU2_3:	postion	= 3;	break;
		case ID_MENU2_4:	postion	= 4;	break;
		case ID_MENU2_5:	postion	= 5;	break;
		case ID_MENU2_6:	postion	= 6;	break;
		case ID_MENU2_7:	postion	= 7;	break;
		case ID_MENU2_8:	postion	= 8;	break;
		default:	postion	= 0;	break;
	}
	menuRight.GetSubMenu(0)->GetMenuStringW(postion,(CString&)buf,MF_BYPOSITION);//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
	SetDlgItemText(IDC_MFCMENUBUTTON13,(LPCTSTR)buf);
	::SendMessage(GetParent()->m_hWnd,  CHILD_DLG_MENUBTN_SELECTMSG, 1, (IDC_MFCMENUBUTTON13 << 16) | postion);
}


void CDlgEditWord::OnBnClickedMfcmenubutton14()
{
	// TODO: 在此添加控件通知处理程序代码
	CString buf;
	int postion	= 0, indexId = 0;
	indexId	= ((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON14)))->m_nMenuResult;
	switch(indexId)
	{
		case ID_MENU2_0:	postion	= 0;	break;
		case ID_MENU2_1:	postion	= 1;	break;
		case ID_MENU2_2:	postion	= 2;	break;
		case ID_MENU2_3:	postion	= 3;	break;
		case ID_MENU2_4:	postion	= 4;	break;
		case ID_MENU2_5:	postion	= 5;	break;
		case ID_MENU2_6:	postion	= 6;	break;
		case ID_MENU2_7:	postion	= 7;	break;
		case ID_MENU2_8:	postion	= 8;	break;
		default:	postion	= 0;	break;
	}
	menuRight.GetSubMenu(0)->GetMenuStringW(postion,(CString&)buf,MF_BYPOSITION);//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
	SetDlgItemText(IDC_MFCMENUBUTTON14,(LPCTSTR)buf);
	::SendMessage(GetParent()->m_hWnd,  CHILD_DLG_MENUBTN_SELECTMSG, 1, (IDC_MFCMENUBUTTON14 << 16) | postion);
}


void CDlgEditWord::OnBnClickedMfcmenubutton15()
{
	// TODO: 在此添加控件通知处理程序代码
	CString buf;
	int postion	= 0, indexId = 0;
	indexId	= ((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON15)))->m_nMenuResult;
	switch(indexId)
	{
		case ID_MENU2_0:	postion	= 0;	break;
		case ID_MENU2_1:	postion	= 1;	break;
		case ID_MENU2_2:	postion	= 2;	break;
		case ID_MENU2_3:	postion	= 3;	break;
		case ID_MENU2_4:	postion	= 4;	break;
		case ID_MENU2_5:	postion	= 5;	break;
		case ID_MENU2_6:	postion	= 6;	break;
		case ID_MENU2_7:	postion	= 7;	break;
		case ID_MENU2_8:	postion	= 8;	break;
		default:	postion	= 0;	break;
	}
	menuRight.GetSubMenu(0)->GetMenuStringW(postion,(CString&)buf,MF_BYPOSITION);//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
	SetDlgItemText(IDC_MFCMENUBUTTON15,(LPCTSTR)buf);
	::SendMessage(GetParent()->m_hWnd,  CHILD_DLG_MENUBTN_SELECTMSG, 1, (IDC_MFCMENUBUTTON15 << 16) | postion);
}


void CDlgEditWord::OnBnClickedMfcmenubutton16()
{
	// TODO: 在此添加控件通知处理程序代码
	CString buf;
	int postion	= 0, indexId = 0;
	indexId	= ((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON16)))->m_nMenuResult;
	switch(indexId)
	{
		case ID_MENU2_0:	postion	= 0;	break;
		case ID_MENU2_1:	postion	= 1;	break;
		case ID_MENU2_2:	postion	= 2;	break;
		case ID_MENU2_3:	postion	= 3;	break;
		case ID_MENU2_4:	postion	= 4;	break;
		case ID_MENU2_5:	postion	= 5;	break;
		case ID_MENU2_6:	postion	= 6;	break;
		case ID_MENU2_7:	postion	= 7;	break;
		case ID_MENU2_8:	postion	= 8;	break;
		default:	postion	= 0;	break;
	}
	menuRight.GetSubMenu(0)->GetMenuStringW(postion,(CString&)buf,MF_BYPOSITION);//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
	SetDlgItemText(IDC_MFCMENUBUTTON16,(LPCTSTR)buf);
	::SendMessage(GetParent()->m_hWnd,  CHILD_DLG_MENUBTN_SELECTMSG, 1, (IDC_MFCMENUBUTTON16 << 16) | postion);
}


void CDlgEditWord::OnBnClickedMfcmenubutton17()
{
	// TODO: 在此添加控件通知处理程序代码
	CString buf;
	int postion	= 0, indexId = 0;
	indexId	= ((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON17)))->m_nMenuResult;
	switch(indexId)
	{
		case ID_MENU2_0:	postion	= 0;	break;
		case ID_MENU2_1:	postion	= 1;	break;
		case ID_MENU2_2:	postion	= 2;	break;
		case ID_MENU2_3:	postion	= 3;	break;
		case ID_MENU2_4:	postion	= 4;	break;
		case ID_MENU2_5:	postion	= 5;	break;
		case ID_MENU2_6:	postion	= 6;	break;
		case ID_MENU2_7:	postion	= 7;	break;
		case ID_MENU2_8:	postion	= 8;	break;
		default:	postion	= 0;	break;
	}
	menuRight.GetSubMenu(0)->GetMenuStringW(postion,(CString&)buf,MF_BYPOSITION);//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
	SetDlgItemText(IDC_MFCMENUBUTTON17,(LPCTSTR)buf);
	::SendMessage(GetParent()->m_hWnd,  CHILD_DLG_MENUBTN_SELECTMSG, 1, (IDC_MFCMENUBUTTON17 << 16) | postion);
}


void CDlgEditWord::OnBnClickedMfcmenubutton18()
{
	// TODO: 在此添加控件通知处理程序代码
	CString buf;
	int postion	= 0, indexId = 0;
	indexId	= ((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON18)))->m_nMenuResult;
	switch(indexId)
	{
		case ID_MENU2_0:	postion	= 0;	break;
		case ID_MENU2_1:	postion	= 1;	break;
		case ID_MENU2_2:	postion	= 2;	break;
		case ID_MENU2_3:	postion	= 3;	break;
		case ID_MENU2_4:	postion	= 4;	break;
		case ID_MENU2_5:	postion	= 5;	break;
		case ID_MENU2_6:	postion	= 6;	break;
		case ID_MENU2_7:	postion	= 7;	break;
		case ID_MENU2_8:	postion	= 8;	break;
		default:	postion	= 0;	break;
	}
	menuRight.GetSubMenu(0)->GetMenuStringW(postion,(CString&)buf,MF_BYPOSITION);//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
	SetDlgItemText(IDC_MFCMENUBUTTON18,(LPCTSTR)buf);
	::SendMessage(GetParent()->m_hWnd,  CHILD_DLG_MENUBTN_SELECTMSG, 1, (IDC_MFCMENUBUTTON18 << 16) | postion);
}


void CDlgEditWord::OnBnClickedMfcmenubutton19()
{
	// TODO: 在此添加控件通知处理程序代码
	CString buf;
	int postion	= 0, indexId = 0;
	indexId	= ((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON19)))->m_nMenuResult;
	switch(indexId)
	{
		case ID_MENU2_0:	postion	= 0;	break;
		case ID_MENU2_1:	postion	= 1;	break;
		case ID_MENU2_2:	postion	= 2;	break;
		case ID_MENU2_3:	postion	= 3;	break;
		case ID_MENU2_4:	postion	= 4;	break;
		case ID_MENU2_5:	postion	= 5;	break;
		case ID_MENU2_6:	postion	= 6;	break;
		case ID_MENU2_7:	postion	= 7;	break;
		case ID_MENU2_8:	postion	= 8;	break;
		default:	postion	= 0;	break;
	}
	menuRight.GetSubMenu(0)->GetMenuStringW(postion,(CString&)buf,MF_BYPOSITION);//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
	SetDlgItemText(IDC_MFCMENUBUTTON19,(LPCTSTR)buf);
	::SendMessage(GetParent()->m_hWnd,  CHILD_DLG_MENUBTN_SELECTMSG, 1, (IDC_MFCMENUBUTTON19 << 16) | postion);
}


void CDlgEditWord::OnBnClickedMfcmenubutton20()
{
	// TODO: 在此添加控件通知处理程序代码
	CString buf;
	int postion	= 0, indexId = 0;
	indexId	= ((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON20)))->m_nMenuResult;
	switch(indexId)
	{
		case ID_MENU2_0:	postion	= 0;	break;
		case ID_MENU2_1:	postion	= 1;	break;
		case ID_MENU2_2:	postion	= 2;	break;
		case ID_MENU2_3:	postion	= 3;	break;
		case ID_MENU2_4:	postion	= 4;	break;
		case ID_MENU2_5:	postion	= 5;	break;
		case ID_MENU2_6:	postion	= 6;	break;
		case ID_MENU2_7:	postion	= 7;	break;
		case ID_MENU2_8:	postion	= 8;	break;
		default:	postion	= 0;	break;
	}
	menuRight.GetSubMenu(0)->GetMenuStringW(postion,(CString&)buf,MF_BYPOSITION);//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
	SetDlgItemText(IDC_MFCMENUBUTTON20,(LPCTSTR)buf);
	::SendMessage(GetParent()->m_hWnd,  CHILD_DLG_MENUBTN_SELECTMSG, 1, (IDC_MFCMENUBUTTON20 << 16) | postion);
}


void CDlgEditWord::OnBnClickedMfcmenubutton21()
{
	// TODO: 在此添加控件通知处理程序代码
	CString buf;
	int postion	= 0, indexId = 0;
	indexId	= ((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON21)))->m_nMenuResult;
	switch(indexId)
	{
		case ID_MENU2_0:	postion	= 0;	break;
		case ID_MENU2_1:	postion	= 1;	break;
		case ID_MENU2_2:	postion	= 2;	break;
		case ID_MENU2_3:	postion	= 3;	break;
		case ID_MENU2_4:	postion	= 4;	break;
		case ID_MENU2_5:	postion	= 5;	break;
		case ID_MENU2_6:	postion	= 6;	break;
		case ID_MENU2_7:	postion	= 7;	break;
		case ID_MENU2_8:	postion	= 8;	break;
		default:	postion	= 0;	break;
	}
	menuRight.GetSubMenu(0)->GetMenuStringW(postion,(CString&)buf,MF_BYPOSITION);//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
	SetDlgItemText(IDC_MFCMENUBUTTON21,(LPCTSTR)buf);
	::SendMessage(GetParent()->m_hWnd,  CHILD_DLG_MENUBTN_SELECTMSG, 1, (IDC_MFCMENUBUTTON21 << 16) | postion);
}


void CDlgEditWord::OnBnClickedMfcmenubutton22()
{
	// TODO: 在此添加控件通知处理程序代码
	CString buf;
	int postion	= 0, indexId = 0;
	indexId	= ((CMFCMenuButton*)(GetDlgItem(IDC_MFCMENUBUTTON22)))->m_nMenuResult;
	switch(indexId)
	{
		case ID_MENU2_0:	postion	= 0;	break;
		case ID_MENU2_1:	postion	= 1;	break;
		case ID_MENU2_2:	postion	= 2;	break;
		case ID_MENU2_3:	postion	= 3;	break;
		case ID_MENU2_4:	postion	= 4;	break;
		case ID_MENU2_5:	postion	= 5;	break;
		case ID_MENU2_6:	postion	= 6;	break;
		case ID_MENU2_7:	postion	= 7;	break;
		case ID_MENU2_8:	postion	= 8;	break;
		default:	postion	= 0;	break;
	}
	menuRight.GetSubMenu(0)->GetMenuStringW(postion,(CString&)buf,MF_BYPOSITION);//通过位置(而非ID)获取第一个menu下的第一级子menu中第一个postion的字符串获取
	SetDlgItemText(IDC_MFCMENUBUTTON22,(LPCTSTR)buf);
	::SendMessage(GetParent()->m_hWnd,  CHILD_DLG_MENUBTN_SELECTMSG, 1, (IDC_MFCMENUBUTTON22 << 16) | postion);
}