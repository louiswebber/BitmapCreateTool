
// BitmapCreateToolDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "BitmapCreateTool.h"
#include "BitmapCreateToolDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define TIMER1	0x0001

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
	ON_BN_CLICKED(IDC_RADIO_USR_FONT_USE_FLAG, &CBitmapCreateToolDlg::OnBnClickedRadioUsrFontUseFlag)
	ON_BN_CLICKED(IDC_RADIO2, &CBitmapCreateToolDlg::OnBnClickedRadio2)
	ON_WM_TIMER()
	ON_WM_VSCROLL()
END_MESSAGE_MAP()


// CBitmapCreateToolDlg 消息处理程序
CDialog dlgWordEnter;
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

	SetTimer(TIMER1,100,NULL);//
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
#if 0
		CRect rect;
		((CEdit*)(GetDlgItem(IDC_EDIT1)))->GetWindowRect(rect);
		//ClientToScreen(rect);
		dlgWordEnter.Create(IDD_DIALOG1,this);
		dlgWordEnter.MoveWindow(rect);  
		dlgWordEnter.ShowWindow(SW_SHOW);
		SCROLLINFO si;
		si.cbSize	= sizeof (SCROLLINFO) ;
		si.fMask	= SIF_RANGE;
		si.nPos	= rect.top;
		si.nMin	= rect.top ;
		si.nMax	= rect.bottom;
		((CDialog*)GetDlgItem(IDD_DIALOG1))->SetScrollInfo(SB_VERT,&si,1);
#endif
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

void CBitmapCreateToolDlg::OnBnClickedRadioUsrFontUseFlag()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CBitmapCreateToolDlg::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CBitmapCreateToolDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

		CRect rect;

		((CEdit*)(GetDlgItem(IDC_EDIT1)))->GetWindowRect(rect);
#if 1	
		//ClientToScreen(rect);
		dlgWordEnter.Create(IDD_DIALOG1,this);
		dlgWordEnter.MoveWindow(rect);  
		dlgWordEnter.ShowWindow(SW_SHOW);
#endif
		SCROLLINFO si;
		((CEdit*)(GetDlgItem(IDC_SCROLLBAR1)))->GetWindowRect(rect);
		si.cbSize	= sizeof (SCROLLINFO) ;
		si.fMask	= SIF_RANGE|SIF_POS;
		si.nPos	= rect.top;
		si.nMin	= rect.top ;
		si.nMax	= rect.bottom;
		((CScrollBar*)GetDlgItem(IDC_SCROLLBAR1))->SetScrollInfo(&si,1);
	KillTimer(nIDEvent);
	CDialogEx::OnTimer(nIDEvent);
}



void CBitmapCreateToolDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int scrollCurPos	= 0;
	SCROLLINFO si;
	CRect rect;
	scrollCurPos	= ((CScrollBar*)GetDlgItem(IDC_SCROLLBAR1))->GetScrollPos();
	((CScrollBar*)GetDlgItem(IDC_SCROLLBAR1))->GetScrollInfo(&si,SIF_ALL);

	
	//((CEdit*)(GetDlgItem(IDC_EDIT1)))->GetWindowRect(rect);
	ScreenToClient(rect);
	switch (nSBCode)
	{
	case SB_LINEDOWN:
		dlgWordEnter.ScrollWindow( 0,-2,NULL,NULL);
		scrollCurPos	+= 2;
		break;
	case SB_LINEUP:
		scrollCurPos	-= 2;
		dlgWordEnter.ScrollWindow( 0,2,NULL,NULL);
		break;
	case SB_THUMBPOSITION:
	case SB_THUMBTRACK:
		dlgWordEnter.ScrollWindow( 0,scrollCurPos - si.nTrackPos,NULL,NULL);
		scrollCurPos	= si.nTrackPos;
		break;
	case SB_ENDSCROLL:
		break;
	default :
		break;
	}
	((CScrollBar*)GetDlgItem(IDC_SCROLLBAR1))->SetScrollPos(scrollCurPos);
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}

