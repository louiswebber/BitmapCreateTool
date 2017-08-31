
// BitmapCreateToolDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxeditbrowsectrl.h"
#include "DlgFontEdit.h"

// CBitmapCreateToolDlg �Ի���
class CBitmapCreateToolDlg : public CDialogEx
{
// ����
public:
	CBitmapCreateToolDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_BITMAPCREATETOOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
