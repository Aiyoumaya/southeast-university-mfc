// CSearchDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "P09017139_4.h"
#include "CSearchDlg.h"
#include "afxdialogex.h"


// CCSearchDlg �Ի���

IMPLEMENT_DYNAMIC(CCSearchDlg, CDialogEx)

CCSearchDlg::CCSearchDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCSearchDlg::IDD, pParent)
{

	//  m_CID = 0;
	//  m_CTID = 0;
	m_cName1 = _T("");
	m_CTName1 = _T("");
}

CCSearchDlg::~CCSearchDlg()
{
}

void CCSearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_cNAME, m_CNAME);
	//  D//  DX_Text(p//  DX, I//  DC_cI//  D, m_CI//  D);
	//  DDX_Text(pDX, IDC_CTID, m_CTID);
	DDX_Control(pDX, IDC_CTNAME, m_CTNAME);
	DDX_CBString(pDX, IDC_cNAME, m_cName1);
	DDX_CBString(pDX, IDC_CTNAME, m_CTName1);
}


BEGIN_MESSAGE_MAP(CCSearchDlg, CDialogEx)
END_MESSAGE_MAP()


// CCSearchDlg ��Ϣ�������


BOOL CCSearchDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CDialogEx::OnInitDialog();
	CTeacher* pTeacher=NULL;
	CClass* pClass=NULL;
	CString Str1,Str2;
	for(int i=0; i < p->mTeacherArray.GetSize();i++)
	{
		pTeacher=p->mTeacherArray[i];
		Str1.Format(_T("%s"),pTeacher->tName);
		m_CTNAME.AddString(Str1);
		for(int j = 0; j < pTeacher->tClassArray.GetSize();j++)
		{
			pClass=pTeacher->tClassArray[j];
			Str2.Format(_T("%s"),pClass->cName);
			m_CNAME.AddString(Str2);
		}

	}// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
