#pragma once


// NewDlg �Ի���

class NewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(NewDlg)

public:
	NewDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~NewDlg();

// �Ի�������
	enum { IDD = IDD_NEW_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_mRow;
	int m_mCol;
	BOOL m_Mat2;
};
