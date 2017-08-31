
// BitmapCreateToolDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxeditbrowsectrl.h"
#include "DlgFontEdit.h"

// CBitmapCreateToolDlg 对话框
class CBitmapCreateToolDlg : public CDialogEx
{
// 构造
public:
	CBitmapCreateToolDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_BITMAPCREATETOOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	char *usrFontName;

	CButton openConfig;
	afx_msg void OnBnClickedOpenFileButton();
	CButton saveConfigButton;
	afx_msg void OnBnClickedSaveConfigButton();
	CButton clearWordButton;
	afx_msg void OnBnClickedClearAllWord();
	CComboBox selectLedNumComboBox;
	afx_msg void OnCbnSelchangeSelectLedNum();

	afx_msg void OnEnChangeSelectUserFont();
	CButton scanDirectButton;
	afx_msg void OnBnClickedScanDirection();
	CButton editUsrFontButton;
	afx_msg void OnBnClickedEditUsrFont();
	CButton exportAsmFile;
	afx_msg void OnBnClickedExportAsm();
	CScrollBar scollbar;
	afx_msg void OnBnClickedRadioUsrFontUseFlag();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
