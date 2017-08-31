
// BitmapCreateToolDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BitmapCreateTool.h"
#include "BitmapCreateToolDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define TIMER1	0x0001

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CBitmapCreateToolDlg �Ի���



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


// CBitmapCreateToolDlg ��Ϣ�������
CDialog dlgWordEnter;
BOOL CBitmapCreateToolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	SetTimer(TIMER1,100,NULL);//
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CBitmapCreateToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
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

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CBitmapCreateToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CBitmapCreateToolDlg::OnBnClickedOpenFileButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CBitmapCreateToolDlg::OnBnClickedSaveConfigButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CBitmapCreateToolDlg::OnBnClickedClearAllWord()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CBitmapCreateToolDlg::OnCbnSelchangeSelectLedNum()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int index	= selectLedNumComboBox.GetCurSel();
	Sleep(100);
}


void CBitmapCreateToolDlg::OnEnChangeSelectUserFont()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�


	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CBitmapCreateToolDlg::OnBnClickedEditUsrFont()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDlgFontEdit fontEditDlg;
	fontEditDlg.DoModal();
}


void CBitmapCreateToolDlg::OnBnClickedExportAsm()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CBitmapCreateToolDlg::OnBnClickedRadioUsrFontUseFlag()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CBitmapCreateToolDlg::OnBnClickedRadio2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CBitmapCreateToolDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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

