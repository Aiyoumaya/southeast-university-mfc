#pragma once


// CTeacherClassDlg �Ի���

class CTeacherClassDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTeacherClassDlg)

public:
	CTeacherClassDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTeacherClassDlg();

// �Ի�������
	enum { IDD = IDD_TeacherClass };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	COleDateTime m_ClassADate;
	COleDateTime m_ClassBDate;
	CString m_ClassBack;
	CString m_ClassGender;
	CString m_ClassMarry;
	CString m_ClassTitle;	
	int m_Flag;
};
