#pragma once
#include "afxwin.h"


// CDlgFontEdit �Ի���

class CDlgFontEdit : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgFontEdit)

public:
	CDlgFontEdit(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgFontEdit();

// �Ի�������
	enum { IDD = IDD_DLG_FONT_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedFontSave();
};


