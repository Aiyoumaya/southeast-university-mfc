#pragma once
#include"P09017139_4Doc.h"

// SearchDlg �Ի���

class SearchDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SearchDlg)

public:
	SearchDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~SearchDlg();

// �Ի�������
	enum { IDD = IDD_Search };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:

//	int m_IDS;
	virtual BOOL OnInitDialog();
	CP09017139_4Doc* p;
	CComboBox m_Name;
	CString m_Name1;
};
