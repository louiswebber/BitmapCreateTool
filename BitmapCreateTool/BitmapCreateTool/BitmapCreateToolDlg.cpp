
// BitmapCreateToolDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "BitmapCreateTool.h"
#include "BitmapCreateToolDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBitmapCreateToolDlg 对话框



CBitmapCreateToolDlg::CBitmapCreateToolDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBitmapCreateToolDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBitmapCreateToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_OPEN_CONFIG_BUTTON, openConfig);
	DDX_Control(pDX, IDC_SAVE_CONFIG_BUTTON, saveConfigButton);
	DDX_Control(pDX, IDC_CLEAR_ALL_WORD, clearWordButton);
	DDX_Control(pDX, IDC_SELECT_LED_NUM, selectLedNumComboBox);
	DDX_Control(pDX, IDC_SELECT_USER_FONT, slectUsrFontEditBrowse);
	DDX_Control(pDX, IDC_EDIT_USR_FONT, editUsrFontButton);
	DDX_Control(pDX, IDC_SCAN_DIRECTION, scanDirectButton);
	DDX_Control(pDX, IDC_EXPORT_ASM, exportAsmFile);
}

BEGIN_MESSAGE_MAP(CBitmapCreateToolDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPEN_CONFIG_BUTTON, &CBitmapCreateToolDlg::OnBnClickedOpenFileButton)
	ON_BN_CLICKED(IDC_SAVE_CONFIG_BUTTON, &CBitmapCreateToolDlg::OnBnClickedSaveConfigButton)
	ON_BN_CLICKED(IDC_CLEAR_ALL_WORD, &CBitmapCreateToolDlg::OnBnClickedClearAllWord)
	ON_CBN_SELCHANGE(IDC_SELECT_LED_NUM, &CBitmapCreateToolDlg::OnCbnSelchangeSelectLedNum)
	ON_EN_CHANGE(IDC_SELECT_USER_FONT, &CBitmapCreateToolDlg::OnEnChangeSelectUserFont)
	ON_BN_CLICKED(IDC_SCAN_DIRECTION, &CBitmapCreateToolDlg::OnBnClickedScanDirection)
	ON_BN_CLICKED(IDC_EDIT_USR_FONT, &CBitmapCreateToolDlg::OnBnClickedEditUsrFont)
	ON_BN_CLICKED(IDC_EXPORT_ASM, &CBitmapCreateToolDlg::OnBnClickedExportAsm)
	ON_WM_VSCROLL()
END_MESSAGE_MAP()


// CBitmapCreateToolDlg 消息处理程序

BOOL CBitmapCreateToolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	((CScrollBar*)GetDlgItem(IDC_SCROLLBAR1))->SetScrollRange(0, 100);
	//scollbar.SetScrollRange(0, 100);
	CMenu* pMenu = new CMenu;
	pMenu->LoadMenu(IDR_MENU2); //载入菜单资源
	((CMFCMenuButton*)GetDlgItem(IDC_MFCMENUBUTTON1))->m_hMenu = pMenu->GetSubMenu(0)->GetSafeHmenu();
	((CMFCMenuButton*)GetDlgItem(IDC_MFCMENUBUTTON1))->SizeToContent();
	((CMFCMenuButton*)GetDlgItem(IDC_MFCMENUBUTTON1))->m_bOSMenu = FALSE;


	CMenu* pMenu2 = new CMenu;
	pMenu2->LoadMenu(IDR_MENU3); //载入菜单资源
	((CMFCMenuButton*)GetDlgItem(IDC_MFCMENUBUTTON12))->m_hMenu = pMenu2->GetSubMenu(0)->GetSafeHmenu();
	((CMFCMenuButton*)GetDlgItem(IDC_MFCMENUBUTTON12))->SizeToContent();
	((CMFCMenuButton*)GetDlgItem(IDC_MFCMENUBUTTON12))->m_bOSMenu = FALSE;

	((CComboBox*)GetDlgItem(IDC_SELECT_LED_NUM))->SelectString(-1,_T("11Led"));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CBitmapCreateToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CBitmapCreateToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CBitmapCreateToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CBitmapCreateToolDlg::OnBnClickedOpenFileButton()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CBitmapCreateToolDlg::OnBnClickedSaveConfigButton()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CBitmapCreateToolDlg::OnBnClickedClearAllWord()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CBitmapCreateToolDlg::OnCbnSelchangeSelectLedNum()
{
	// TODO: 在此添加控件通知处理程序代码
	int index	= selectLedNumComboBox.GetCurSel();
	Sleep(100);
}


void CBitmapCreateToolDlg::OnEnChangeSelectUserFont()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。


	// TODO:  在此添加控件通知处理程序代码
	int lenth;
	char  buf[200];
	GetDlgItemText(IDC_SELECT_USER_FONT, (LPTSTR)buf,200);
	lenth	= WideCharToMultiByte(CP_ACP, 0, (LPCWCH)buf, -1, NULL, 0, NULL, 0);
	usrFontName = new char[lenth];
	WideCharToMultiByte(CP_ACP, 0, (LPCWCH)buf, -1, usrFontName, lenth, NULL, 0);
	Sleep(100);
	delete usrFontName;
	Sleep(100);
}



void CBitmapCreateToolDlg::OnBnClickedScanDirection()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CBitmapCreateToolDlg::OnBnClickedEditUsrFont()
{
	// TODO: 在此添加控件通知处理程序代码
	CDlgFontEdit fontEditDlg;
	fontEditDlg.DoModal();
}


void CBitmapCreateToolDlg::OnBnClickedExportAsm()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CBitmapCreateToolDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int nMin,nMax,nCurpos,step = 0;

	pScrollBar->GetScrollRange(&nMin,&nMax);
	nCurpos	= pScrollBar->GetScrollPos();

	
	switch(nSBCode)
	{  
		case SB_LINEUP:
			step	=  -1;
			break;     
		case SB_LINEDOWN:  
			step	=  1;
			break;
		case SB_THUMBTRACK:
			step = nPos - nCurpos;
			//nCurpos = nPos;
			break;  
	}

	nCurpos	+= step;
	pScrollBar->SetScrollPos(nCurpos); 
#if 1
	//for (int i = 0; i < 11; i++)
	{
		CRect m_rect, rect;
		int pixelStep;
		((CEdit*)GetDlgItem(IDC_EDIT5))->GetWindowRect(&m_rect);
		((CEdit*)GetDlgItem(IDC_EDIT15))->GetWindowRect(&rect);
		pixelStep	= (rect.bottom - m_rect.top) / 100;

		((CEdit*)GetDlgItem(IDC_STATIC))->GetWindowRect(&rect);
		ScreenToClient(rect);

		((CEdit*)GetDlgItem(IDC_EDIT5))->GetWindowRect(&m_rect);
		ScreenToClient(m_rect);
		m_rect.top		-= step * pixelStep;
		m_rect.bottom	-= step * pixelStep;
		((CEdit*)GetDlgItem(IDC_EDIT5))->MoveWindow(m_rect);
		if (m_rect.bottom >= rect.bottom || m_rect.top <= rect.top)
		{
			((CEdit*)GetDlgItem(IDC_EDIT5))->ShowWindow(FALSE);
		}
		else
		{
			((CEdit*)GetDlgItem(IDC_EDIT5))->ShowWindow(TRUE);
		}

		((CEdit*)GetDlgItem(IDC_EDIT6))->GetWindowRect(&m_rect);
		ScreenToClient(m_rect);
		m_rect.top		-= step * pixelStep;
		m_rect.bottom	-= step * pixelStep;
		((CEdit*)GetDlgItem(IDC_EDIT6))->MoveWindow(m_rect);
		if (m_rect.bottom >= rect.bottom || m_rect.top <= rect.top)
		{
			((CEdit*)GetDlgItem(IDC_EDIT6))->ShowWindow(FALSE);
		}
		else
		{
			((CEdit*)GetDlgItem(IDC_EDIT6))->ShowWindow(TRUE);
		}

		((CEdit*)GetDlgItem(IDC_EDIT7))->GetWindowRect(&m_rect);
		ScreenToClient(m_rect);
		m_rect.top		-= step * pixelStep;
		m_rect.bottom	-= step * pixelStep;
		((CEdit*)GetDlgItem(IDC_EDIT7))->MoveWindow(m_rect);
		if (m_rect.bottom >= rect.bottom || m_rect.top <= rect.top)
		{
			((CEdit*)GetDlgItem(IDC_EDIT7))->ShowWindow(FALSE);
		}
		else
		{
			((CEdit*)GetDlgItem(IDC_EDIT7))->ShowWindow(TRUE);
		}

		((CEdit*)GetDlgItem(IDC_EDIT8))->GetWindowRect(&m_rect);
		ScreenToClient(m_rect);
		m_rect.top		-= step * pixelStep;
		m_rect.bottom	-= step * pixelStep;
		((CEdit*)GetDlgItem(IDC_EDIT8))->MoveWindow(m_rect);
		if (m_rect.bottom >= rect.bottom || m_rect.top <= rect.top)
		{
			((CEdit*)GetDlgItem(IDC_EDIT8))->ShowWindow(FALSE);
		}
		else
		{
			((CEdit*)GetDlgItem(IDC_EDIT8))->ShowWindow(TRUE);
		}

		((CEdit*)GetDlgItem(IDC_EDIT9))->GetWindowRect(&m_rect);
		ScreenToClient(m_rect);
		m_rect.top		-= step * pixelStep;
		m_rect.bottom	-= step * pixelStep;
		((CEdit*)GetDlgItem(IDC_EDIT9))->MoveWindow(m_rect);
		if (m_rect.bottom >= rect.bottom || m_rect.top <= rect.top)
		{
			((CEdit*)GetDlgItem(IDC_EDIT9))->ShowWindow(FALSE);
		}
		else
		{
			((CEdit*)GetDlgItem(IDC_EDIT9))->ShowWindow(TRUE);
		}

		((CEdit*)GetDlgItem(IDC_EDIT10))->GetWindowRect(&m_rect);
		ScreenToClient(m_rect);
		m_rect.top		-= step * pixelStep;
		m_rect.bottom	-= step * pixelStep;
		((CEdit*)GetDlgItem(IDC_EDIT10))->MoveWindow(m_rect);
		if (m_rect.bottom >= rect.bottom || m_rect.top <= rect.top)
		{
			((CEdit*)GetDlgItem(IDC_EDIT10))->ShowWindow(FALSE);
		}
		else
		{
			((CEdit*)GetDlgItem(IDC_EDIT10))->ShowWindow(TRUE);
		}

		((CEdit*)GetDlgItem(IDC_EDIT11))->GetWindowRect(&m_rect);
		ScreenToClient(m_rect);
		m_rect.top		-= step * pixelStep;
		m_rect.bottom	-= step * pixelStep;
		((CEdit*)GetDlgItem(IDC_EDIT11))->MoveWindow(m_rect);
		if (m_rect.bottom >= rect.bottom || m_rect.top <= rect.top)
		{
			((CEdit*)GetDlgItem(IDC_EDIT11))->ShowWindow(FALSE);
		}
		else
		{
			((CEdit*)GetDlgItem(IDC_EDIT11))->ShowWindow(TRUE);
		}

		((CEdit*)GetDlgItem(IDC_EDIT12))->GetWindowRect(&m_rect);
		ScreenToClient(m_rect);
		m_rect.top		-= step * pixelStep;
		m_rect.bottom	-= step * pixelStep;
		((CEdit*)GetDlgItem(IDC_EDIT12))->MoveWindow(m_rect);
		if (m_rect.bottom >= rect.bottom || m_rect.top <= rect.top)
		{
			((CEdit*)GetDlgItem(IDC_EDIT12))->ShowWindow(FALSE);
		}
		else
		{
			((CEdit*)GetDlgItem(IDC_EDIT12))->ShowWindow(TRUE);
		}

		((CEdit*)GetDlgItem(IDC_EDIT13))->GetWindowRect(&m_rect);
		ScreenToClient(m_rect);
		m_rect.top		-= step * pixelStep;
		m_rect.bottom	-= step * pixelStep;
		((CEdit*)GetDlgItem(IDC_EDIT13))->MoveWindow(m_rect);
		if (m_rect.bottom >= rect.bottom || m_rect.top <= rect.top)
		{
			((CEdit*)GetDlgItem(IDC_EDIT13))->ShowWindow(FALSE);
		}
		else
		{
			((CEdit*)GetDlgItem(IDC_EDIT13))->ShowWindow(TRUE);
		}

		((CEdit*)GetDlgItem(IDC_EDIT14))->GetWindowRect(&m_rect);
		ScreenToClient(m_rect);
		m_rect.top		-= step * pixelStep;
		m_rect.bottom	-= step * pixelStep;
		((CEdit*)GetDlgItem(IDC_EDIT14))->MoveWindow(m_rect);
		if (m_rect.bottom >= rect.bottom || m_rect.top <= rect.top)
		{
			((CEdit*)GetDlgItem(IDC_EDIT14))->ShowWindow(FALSE);
		}
		else
		{
			((CEdit*)GetDlgItem(IDC_EDIT14))->ShowWindow(TRUE);
		}

		((CEdit*)GetDlgItem(IDC_EDIT15))->GetWindowRect(&m_rect);
		ScreenToClient(m_rect);
		m_rect.top		-= step * pixelStep;
		m_rect.bottom	-= step * pixelStep;
		((CEdit*)GetDlgItem(IDC_EDIT15))->MoveWindow(m_rect);
		if (m_rect.bottom >= rect.bottom || m_rect.top <= rect.top)
		{
			((CEdit*)GetDlgItem(IDC_EDIT15))->ShowWindow(FALSE);
		}
		else
		{
			((CEdit*)GetDlgItem(IDC_EDIT15))->ShowWindow(TRUE);
		}
	}
#endif
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}
