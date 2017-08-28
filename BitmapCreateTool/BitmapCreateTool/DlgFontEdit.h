#pragma once
#include "afxwin.h"


// CDlgFontEdit 对话框

class CDlgFontEdit : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgFontEdit)

public:
	CDlgFontEdit(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgFontEdit();

// 对话框数据
	enum { IDD = IDD_DLG_FONT_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedFontSave();
};


