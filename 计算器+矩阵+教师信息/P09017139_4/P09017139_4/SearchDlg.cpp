// SearchDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "P09017139_4.h"
#include "SearchDlg.h"
#include "afxdialogex.h"


// SearchDlg �Ի���

IMPLEMENT_DYNAMIC(SearchDlg, CDialogEx)

SearchDlg::SearchDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(SearchDlg::IDD, pParent)
{


	//  m_IDS = 0;

	m_Name1 = _T("");
}

SearchDlg::~SearchDlg()
{
}

void SearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_tINPUT, m_IDS);
	DDX_Control(pDX, IDC_NAME, m_Name);
	DDX_CBString(pDX, IDC_NAME, m_Name1);
}


BEGIN_MESSAGE_MAP(SearchDlg, CDialogEx)
END_MESSAGE_MAP()


// SearchDlg ��Ϣ�������







BOOL SearchDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CTeacher* pTeacher=NULL;
	CString Str;
	for(int i=0; i < p->mTeacherArray.GetSize();i++)
	{
		pTeacher=p->mTeacherArray[i];
		Str.Format(_T("%s"),pTeacher->tName);
		m_Name.AddString(Str);

	}// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


