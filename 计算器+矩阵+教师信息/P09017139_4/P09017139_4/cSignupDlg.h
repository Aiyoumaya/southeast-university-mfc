#pragma once


// cSignupDlg �Ի���

class cSignupDlg : public CDialogEx
{
	DECLARE_DYNAMIC(cSignupDlg)

public:
	cSignupDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~cSignupDlg();

// �Ի�������
	enum { IDD = IDD_cSIGNUP_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_Class;
	int m_Code;
	int m_ID;
	CString m_Name;
	CString m_Room;
	CString m_Semester;
	int m_Time;
};
