#pragma once


// tSignupDlg �Ի���

class CtSignupDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CtSignupDlg)

public:
	CtSignupDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CtSignupDlg();

// �Ի�������
	enum { IDD = IDD_tSIGNUP_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_tID;
	int m_Salary;
	COleDateTime m_Date;
	CString m_Name;
	CString m_Back;
	CString m_Gender;
	CString m_Marry;
	CString m_Title;
};
