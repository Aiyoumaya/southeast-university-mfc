#pragma once


// CMatrixChooseDlg �Ի���

class CMatrixChooseDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMatrixChooseDlg)

public:
	CMatrixChooseDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMatrixChooseDlg();

// �Ի�������
	enum { IDD = IDD_CHOOSEMATRIX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_Matrix;
};
