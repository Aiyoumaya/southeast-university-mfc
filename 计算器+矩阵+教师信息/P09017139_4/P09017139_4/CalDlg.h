#pragma once


// CalDlg �Ի���

class CalDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CalDlg)

public:
	CalDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CalDlg();

// �Ի�������
	enum { IDD = IDD_CAL_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:

	
	afx_msg void OnBnClickedCal();
	float GetResult(CString Str);
	char FindOper(CString Str, CString& LStr, CString& RStr);

};
