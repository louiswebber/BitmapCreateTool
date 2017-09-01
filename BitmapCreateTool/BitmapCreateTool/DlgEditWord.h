#pragma once


// CDlgEditWord 对话框

class CDlgEditWord : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgEditWord)

public:
	CDlgEditWord(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgEditWord();
	virtual BOOL InitDialog();
// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	CMenu menuLeft;
	CMenu menuRight;
	afx_msg void OnBnClickedMfcmenubutton1();
	afx_msg void OnBnClickedMfcmenubutton2();
	afx_msg void OnBnClickedMfcmenubutton3();
	afx_msg void OnBnClickedMfcmenubutton4();
	afx_msg void OnBnClickedMfcmenubutton5();
	afx_msg void OnBnClickedMfcmenubutton6();
	afx_msg void OnBnClickedMfcmenubutton7();
	afx_msg void OnBnClickedMfcmenubutton8();
	afx_msg void OnBnClickedMfcmenubutton9();
	afx_msg void OnBnClickedMfcmenubutton10();
	afx_msg void OnBnClickedMfcmenubutton11();

	afx_msg void OnBnClickedMfcmenubutton12();
	afx_msg void OnBnClickedMfcmenubutton13();
	afx_msg void OnBnClickedMfcmenubutton14();
	afx_msg void OnBnClickedMfcmenubutton15();
	afx_msg void OnBnClickedMfcmenubutton16();
	afx_msg void OnBnClickedMfcmenubutton17();
	afx_msg void OnBnClickedMfcmenubutton18();
	afx_msg void OnBnClickedMfcmenubutton19();
	afx_msg void OnBnClickedMfcmenubutton20();
	afx_msg void OnBnClickedMfcmenubutton21();
	afx_msg void OnBnClickedMfcmenubutton22();
};
