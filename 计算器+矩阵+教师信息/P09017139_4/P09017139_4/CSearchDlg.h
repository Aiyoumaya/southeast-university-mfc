#pragma once
#include"P09017139_4Doc.h"

// CCSearchDlg �Ի���

class CCSearchDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCSearchDlg)

public:
	CCSearchDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCSearchDlg();

// �Ի�������
	enum { IDD = IDD_CDELETE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_CNAME;
	CComboBox m_CTNAME;
	CString m_cName1;
	CString m_CTName1;   
	virtual BOOL OnInitDialog();	
	CP09017139_4Doc* p;
};
