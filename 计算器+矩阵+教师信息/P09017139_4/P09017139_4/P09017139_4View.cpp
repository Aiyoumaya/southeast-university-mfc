
// P09017139_4View.cpp : CP09017139_4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "P09017139_4.h"
#endif

#include "P09017139_4Doc.h"
#include "P09017139_4View.h"
#include"CalDlg.h"
#include"SearchDlg.h"
#include"TeacherClassDlg.h"
#include"MatrixNumDlg.h"
#include"MatrixChooseDlg.h"
#include"CSearchDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CP09017139_4View

IMPLEMENT_DYNCREATE(CP09017139_4View, CListView)

BEGIN_MESSAGE_MAP(CP09017139_4View, CListView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()

	ON_COMMAND(ID_tOUTPUT, &CP09017139_4View::Ontoutput)
	
	//ON_COMMAND(ID_CAL, &CP09017139_4View::OnCal)

	ON_COMMAND(ID_Search, &CP09017139_4View::OnSearch)
	ON_COMMAND(ID_MATRIXP, &CP09017139_4View::OnMatrixp)
	ON_COMMAND(ID_MATRIXS, &CP09017139_4View::OnMatrixs)
	ON_COMMAND(ID_MATRIXM, &CP09017139_4View::OnMatrixm)
	ON_COMMAND(ID_cOUTPUT, &CP09017139_4View::Oncoutput)
	ON_COMMAND(ID_TeacherClass, &CP09017139_4View::OnTeacherClass)
	ON_COMMAND(ID_MatrixNum, &CP09017139_4View::OnMatrixNum)
	ON_COMMAND(ID_MATRIX, &CP09017139_4View::OnMatrix)
	ON_COMMAND(ID_ClassSearch, &CP09017139_4View::OnClassSearch)
END_MESSAGE_MAP()


// CP09017139_4View ����/����

CP09017139_4View::CP09017139_4View()
{
	// TODO: �ڴ˴���ӹ������

}

CP09017139_4View::~CP09017139_4View()
{
}

BOOL CP09017139_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	cs.style |= LVS_SHOWSELALWAYS | LVS_REPORT;
	return CListView::PreCreateWindow(cs);
}

void CP09017139_4View::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: ���� GetListCtrl() ֱ�ӷ��� ListView ���б�ؼ���
	//  �Ӷ������������ ListView��
}

void CP09017139_4View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CP09017139_4View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CP09017139_4View ���

#ifdef _DEBUG
void CP09017139_4View::AssertValid() const
{
	CListView::AssertValid();
}

void CP09017139_4View::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CP09017139_4Doc* CP09017139_4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CP09017139_4Doc)));
	return (CP09017139_4Doc*)m_pDocument;
}
#endif //_DEBUG


// CP09017139_4View ��Ϣ�������


void CP09017139_4View::Ontoutput()
{
	int i,j,Index;
	CString Str;
	CTeacher* pTeacher = NULL;
	Index=0;
	CListCtrl& ListCtrl = GetListCtrl();//�õ�CListView�еķ�װ�Ŀؼ�CListCtrl 
	while(ListCtrl.DeleteColumn(0)){};
	ListCtrl.DeleteAllItems();
	//����2�д����������ԭ�е���ʾ
	ListCtrl.InsertColumn(0,_T("���"));
	ListCtrl.SetColumnWidth(0,100);
	//����2�д������ڲ����ͷ
	ListCtrl.InsertColumn(1,_T("����"));
	ListCtrl.SetColumnWidth(1,100);
	ListCtrl.InsertColumn(2,_T("�Ա�"));
	ListCtrl.SetColumnWidth(2,100);
	ListCtrl.InsertColumn(3,_T("��������"));
	ListCtrl.SetColumnWidth(3,100);
	ListCtrl.InsertColumn(4,_T("���ѧ��"));
	ListCtrl.SetColumnWidth(4,100);
	ListCtrl.InsertColumn(5,_T("ְ��"));
	ListCtrl.SetColumnWidth(5,100);
	ListCtrl.InsertColumn(6,_T("����"));
	ListCtrl.SetColumnWidth(6,100);
	ListCtrl.InsertColumn(7,_T("����״��"));
	ListCtrl.SetColumnWidth(7,100);
	CP09017139_4Doc* pDoc = GetDocument(); //�õ��ĵ�
	for(i = 0;i < pDoc->mTeacherArray.GetSize();i++)//���������˶�Ա
	{
		pTeacher=pDoc->mTeacherArray[i];
		Str.Format(_T("%d"),pTeacher->tID); 	//��������ʽ��Ϊ�ַ���
		Index = ListCtrl.InsertItem(Index,Str); //�ڱ��в���һ��

		j = 1;
		Str.Format(_T("%s"),pTeacher->tName); //���ַ�����ʽ��Ϊ�ַ���

		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL); //����ĵ�Ԫ�����
		j++;
		Str.Format(_T("%s"),pTeacher->tGender); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d-%d-%d"),pTeacher->tBirth.GetYear(),pTeacher->tBirth.GetMonth(),pTeacher->tBirth.GetDay());
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tBack); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tTitle); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d"),pTeacher->tSalary); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tMarry); //��������ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		Index++;
	}	
	
	

}


void CP09017139_4View::Oncoutput()
{
	SearchDlg Dlg;
	CP09017139_4Doc* p=GetDocument();
	Dlg.p=p;
	CListCtrl& ListCtrl = GetListCtrl();//�õ�CListView�еķ�װ�Ŀؼ�CListCtrl 
	while(ListCtrl.DeleteColumn(0)){};
	ListCtrl.DeleteAllItems();
	//����2�д����������ԭ�е���ʾ
	ListCtrl.InsertColumn(0,_T("�γ̱��"));
	ListCtrl.SetColumnWidth(0,100);
	//����2�д������ڲ����ͷ
	ListCtrl.InsertColumn(1,_T("�γ�����"));
	ListCtrl.SetColumnWidth(1,100);
	ListCtrl.InsertColumn(2,_T("��ʱ"));
	ListCtrl.SetColumnWidth(2,100);
	ListCtrl.InsertColumn(3,_T("�ڿν���"));
	ListCtrl.SetColumnWidth(3,100);
	ListCtrl.InsertColumn(4,_T("�ڿΰ༶"));
	ListCtrl.SetColumnWidth(4,100);
	ListCtrl.InsertColumn(5,_T("ѧ��"));
	ListCtrl.SetColumnWidth(5,100);
	ListCtrl.InsertColumn(6,_T("ѧ��"));
	ListCtrl.SetColumnWidth(6,100);

	
	if(Dlg.DoModal()==IDOK)
	{
		int i,k,j,Index;
	    CString Str;
	CTeacher* pTeacher = NULL;
	CClass* pClass = NULL;
	CP09017139_4Doc* pDoc = GetDocument(); //�õ��ĵ�
	Index = 0;
		
	for(i = 0;i < pDoc->mTeacherArray.GetSize();i++)//���������˶�Ա
	{
		pTeacher = pDoc->mTeacherArray[i];
		if(Dlg.m_Name1==pTeacher->tName)
		{
		for(k=0; k < pTeacher->tClassArray.GetSize();k++)
		{
		pClass = pTeacher->tClassArray[k];
		Str.Format(_T("%d"),pClass->cID); 	//��������ʽ��Ϊ�ַ���
		Index = ListCtrl.InsertItem(Index,Str); //�ڱ��в���һ��

		j = 1;
		Str.Format(_T("%s"),pClass->cName); //���ַ�����ʽ��Ϊ�ַ���

		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL); //����ĵ�Ԫ�����
		j++;
		Str.Format(_T("%d"),pClass->cTime);//��������ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pClass->cRoom); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d"),pClass->cClass); //��������ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d"),pClass->cCode); //��������ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pClass->cSemester); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		Index++;
		
		}// TODO: �ڴ���������������

		}
	}
	}
}




void CP09017139_4View::OnSearch()
{
	SearchDlg Dlg;
	CP09017139_4Doc* pDoc=GetDocument();
	Dlg.p=pDoc;
	int Index=0;
	if(Dlg.DoModal()==IDOK)
	{
	CTeacher* pTeacher = NULL;
		
	for(int i = 0;i < pDoc->mTeacherArray.GetSize();i++)//���������˶�Ա
	{
		pTeacher = pDoc->mTeacherArray[i];
		if(Dlg.m_Name1==pTeacher->tName)
		ShowTeacher(pTeacher,Index);
	}
	}
}



void CP09017139_4View::OnTeacherClass()
{
	CTeacherClassDlg Dlg;
	CP09017139_4Doc* p=GetDocument();
	CListCtrl& ListCtrl = GetListCtrl();//�õ�CListView�еķ�װ�Ŀؼ�CListCtrl 
	while(ListCtrl.DeleteColumn(0)){};
	ListCtrl.DeleteAllItems();
	//����2�д����������ԭ�е���ʾ
	ListCtrl.InsertColumn(0,_T("���"));
	ListCtrl.SetColumnWidth(0,100);
	//����2�д������ڲ����ͷ
	ListCtrl.InsertColumn(1,_T("����"));
	ListCtrl.SetColumnWidth(1,100);
	ListCtrl.InsertColumn(2,_T("�Ա�"));
	ListCtrl.SetColumnWidth(2,100);
	ListCtrl.InsertColumn(3,_T("��������"));
	ListCtrl.SetColumnWidth(3,100);
	ListCtrl.InsertColumn(4,_T("���ѧ��"));
	ListCtrl.SetColumnWidth(4,100);
	ListCtrl.InsertColumn(5,_T("ְ��"));
	ListCtrl.SetColumnWidth(5,100);
	ListCtrl.InsertColumn(6,_T("����"));
	ListCtrl.SetColumnWidth(6,100);
	ListCtrl.InsertColumn(7,_T("����״��"));
	ListCtrl.SetColumnWidth(7,100);
	
	if(Dlg.DoModal()==IDOK)
	{
		int i,j,Index;
	    CString Str;
	CTeacher* pTeacher = NULL;
	CP09017139_4Doc* pDoc = GetDocument(); //�õ��ĵ�
	Index = 0;
	switch(Dlg.m_Flag)
	{
	case 0:
	{	
		for(i = 0;i < pDoc->mTeacherArray.GetSize();i++)//���������˶�Ա
	{
		pTeacher = pDoc->mTeacherArray[i];
		if(Dlg.m_ClassGender==pTeacher->tGender)
		{
		Str.Format(_T("%d"),pTeacher->tID); 	//��������ʽ��Ϊ�ַ���
		Index = ListCtrl.InsertItem(Index,Str); //�ڱ��в���һ��

		j = 1;
		Str.Format(_T("%s"),pTeacher->tName); //���ַ�����ʽ��Ϊ�ַ���

		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL); //����ĵ�Ԫ�����
		j++;
		Str.Format(_T("%s"),pTeacher->tGender); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d-%d-%d"),pTeacher->tBirth.GetYear(),pTeacher->tBirth.GetMonth(),pTeacher->tBirth.GetDay());
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tBack); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tTitle); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d"),pTeacher->tSalary); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tMarry); //��������ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		}// TODO: �ڴ���������������
	Index++;
	}
	}
		break;
	case 1:
		{
				for(i = 0;i < pDoc->mTeacherArray.GetSize();i++)//���������˶�Ա
	{
		pTeacher = pDoc->mTeacherArray[i];
		if(Dlg.m_ClassADate.GetYear()>pTeacher->tBirth.GetYear())
		{
		Str.Format(_T("%d"),pTeacher->tID); 	//��������ʽ��Ϊ�ַ���
		Index = ListCtrl.InsertItem(Index,Str); //�ڱ��в���һ��

		j = 1;
		Str.Format(_T("%s"),pTeacher->tName); //���ַ�����ʽ��Ϊ�ַ���

		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL); //����ĵ�Ԫ�����
		j++;
		Str.Format(_T("%s"),pTeacher->tGender); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d-%d-%d"),pTeacher->tBirth.GetYear(),pTeacher->tBirth.GetMonth(),pTeacher->tBirth.GetDay());
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tBack); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tTitle); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d"),pTeacher->tSalary); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tMarry); //��������ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		}// TODO: �ڴ���������������
		else
			if(Dlg.m_ClassADate.GetYear()==pTeacher->tBirth.GetYear()&&Dlg.m_ClassADate.GetMonth()>pTeacher->tBirth.GetMonth())
		{
		Str.Format(_T("%d"),pTeacher->tID); 	//��������ʽ��Ϊ�ַ���
		Index = ListCtrl.InsertItem(Index,Str); //�ڱ��в���һ��

		j = 1;
		Str.Format(_T("%s"),pTeacher->tName); //���ַ�����ʽ��Ϊ�ַ���

		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL); //����ĵ�Ԫ�����
		j++;
		Str.Format(_T("%s"),pTeacher->tGender); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d-%d-%d"),pTeacher->tBirth.GetYear(),pTeacher->tBirth.GetMonth(),pTeacher->tBirth.GetDay());
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tBack); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tTitle); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d"),pTeacher->tSalary); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tMarry); //��������ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		}// TODO: �ڴ���������������
	Index++;
	}
		}
		break;
	case 2:
		{
				for(i = 0;i < pDoc->mTeacherArray.GetSize();i++)//���������˶�Ա
	{
		pTeacher = pDoc->mTeacherArray[i];
		if(Dlg.m_ClassADate.GetYear()<pTeacher->tBirth.GetYear())
		{
		Str.Format(_T("%d"),pTeacher->tID); 	//��������ʽ��Ϊ�ַ���
		Index = ListCtrl.InsertItem(Index,Str); //�ڱ��в���һ��

		j = 1;
		Str.Format(_T("%s"),pTeacher->tName); //���ַ�����ʽ��Ϊ�ַ���

		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL); //����ĵ�Ԫ�����
		j++;
		Str.Format(_T("%s"),pTeacher->tGender); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d-%d-%d"),pTeacher->tBirth.GetYear(),pTeacher->tBirth.GetMonth(),pTeacher->tBirth.GetDay());
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tBack); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tTitle); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d"),pTeacher->tSalary); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tMarry); //��������ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		}// TODO: �ڴ���������������
		else
			if(Dlg.m_ClassADate.GetYear()==pTeacher->tBirth.GetYear()&&Dlg.m_ClassADate.GetMonth()<pTeacher->tBirth.GetMonth())
		{
		Str.Format(_T("%d"),pTeacher->tID); 	//��������ʽ��Ϊ�ַ���
		Index = ListCtrl.InsertItem(Index,Str); //�ڱ��в���һ��

		j = 1;
		Str.Format(_T("%s"),pTeacher->tName); //���ַ�����ʽ��Ϊ�ַ���

		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL); //����ĵ�Ԫ�����
		j++;
		Str.Format(_T("%s"),pTeacher->tGender); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d-%d-%d"),pTeacher->tBirth.GetYear(),pTeacher->tBirth.GetMonth(),pTeacher->tBirth.GetDay());
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tBack); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tTitle); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d"),pTeacher->tSalary); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tMarry); //��������ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		}// TODO: �ڴ���������������
	Index++;
	}
		}
		break;
	case 3:
		{
			for(i = 0;i < pDoc->mTeacherArray.GetSize();i++)//���������˶�Ա
	{
		pTeacher = pDoc->mTeacherArray[i];
		if(Dlg.m_ClassTitle==pTeacher->tTitle)
		{
		Str.Format(_T("%d"),pTeacher->tID); 	//��������ʽ��Ϊ�ַ���
		Index = ListCtrl.InsertItem(Index,Str); //�ڱ��в���һ��

		j = 1;
		Str.Format(_T("%s"),pTeacher->tName); //���ַ�����ʽ��Ϊ�ַ���

		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL); //����ĵ�Ԫ�����
		j++;
		Str.Format(_T("%s"),pTeacher->tGender); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d-%d-%d"),pTeacher->tBirth.GetYear(),pTeacher->tBirth.GetMonth(),pTeacher->tBirth.GetDay());
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tBack); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tTitle); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d"),pTeacher->tSalary); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tMarry); //��������ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		}// TODO: �ڴ���������������
	Index++;
	}
		}
		break;
	case 4:
		{
			for(i = 0;i < pDoc->mTeacherArray.GetSize();i++)//���������˶�Ա
	{
		pTeacher = pDoc->mTeacherArray[i];
		if(Dlg.m_ClassBack==pTeacher->tBack)
		{
		Str.Format(_T("%d"),pTeacher->tID); 	//��������ʽ��Ϊ�ַ���
		Index = ListCtrl.InsertItem(Index,Str); //�ڱ��в���һ��

		j = 1;
		Str.Format(_T("%s"),pTeacher->tName); //���ַ�����ʽ��Ϊ�ַ���

		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL); //����ĵ�Ԫ�����
		j++;
		Str.Format(_T("%s"),pTeacher->tGender); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d-%d-%d"),pTeacher->tBirth.GetYear(),pTeacher->tBirth.GetMonth(),pTeacher->tBirth.GetDay());
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tBack); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tTitle); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d"),pTeacher->tSalary); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tMarry); //��������ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		}// TODO: �ڴ���������������
	Index++;
	}
		}
		break;
	case 5:
		{
			for(i = 0;i < pDoc->mTeacherArray.GetSize();i++)//���������˶�Ա
	{
		pTeacher = pDoc->mTeacherArray[i];
		if(Dlg.m_ClassMarry==pTeacher->tMarry)
		{
		Str.Format(_T("%d"),pTeacher->tID); 	//��������ʽ��Ϊ�ַ���
		Index = ListCtrl.InsertItem(Index,Str); //�ڱ��в���һ��

		j = 1;
		Str.Format(_T("%s"),pTeacher->tName); //���ַ�����ʽ��Ϊ�ַ���

		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL); //����ĵ�Ԫ�����
		j++;
		Str.Format(_T("%s"),pTeacher->tGender); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d-%d-%d"),pTeacher->tBirth.GetYear(),pTeacher->tBirth.GetMonth(),pTeacher->tBirth.GetDay());
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tBack); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tTitle); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d"),pTeacher->tSalary); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tMarry); //��������ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		}// TODO: �ڴ���������������
	Index++;
	}
		}
		break;
			
	}
	}// TODO: �ڴ���������������
}


void CP09017139_4View::ShowMatrix(CMatrix<float>* pMat)//������ʾ
{
	CListCtrl& ListCtrl = GetListCtrl();
	while(ListCtrl.DeleteColumn(0)){};
	ListCtrl.DeleteAllItems();
	
	int i,j,Index;
	CString Str;
	ListCtrl.InsertColumn(0,_T(""));
	ListCtrl.SetColumnWidth(0,120);
	
	for(j = 1; j <= pMat->mCol;j++ )
	{
		Str.Format(_T("%d"),j);
		ListCtrl.InsertColumn(j,Str);
		ListCtrl.SetColumnWidth(j,120);
	}
	Index = 0;
	for(i = 0;i < pMat->mRow;i++)
	{
		Str.Format(_T("%d"),i+1);
		ListCtrl.InsertItem(i,Str);
		
		for(j = 0;j < pMat->mCol;j++,Index++)
		{
			Str.Format(_T("%f"),pMat->mpElement[Index]);
			ListCtrl.SetItem(i,j+1,LVIF_TEXT,Str,0,0,0,NULL);
		}
	}

}




void CP09017139_4View::OnMatrixp()//�������
{
	CP09017139_4Doc*pDoc=GetDocument();
	ShowMatrix(&(pDoc->mMat1+pDoc->mMat2));// TODO: �ڴ���������������
}



void CP09017139_4View::OnMatrixs()//�������
{
	CP09017139_4Doc*pDoc=GetDocument();
	ShowMatrix(&(pDoc->mMat1-pDoc->mMat2));// TODO: �ڴ���������������
}


void CP09017139_4View::OnMatrixm()//�������
{
	CP09017139_4Doc*pDoc=GetDocument();
	ShowMatrix(&(pDoc->mMat1*pDoc->mMat2));// TODO: �ڴ���������������
}






// ��ʦ��Ϣ��ʾ
void CP09017139_4View::ShowTeacher(CTeacher* pTeacher,int Index)
{
	int j;
	CString Str;
	CListCtrl& ListCtrl = GetListCtrl();//�õ�CListView�еķ�װ�Ŀؼ�CListCtrl 
	while(ListCtrl.DeleteColumn(0)){};
	ListCtrl.DeleteAllItems();
	//����2�д����������ԭ�е���ʾ
	ListCtrl.InsertColumn(0,_T("���"));
	ListCtrl.SetColumnWidth(0,100);
	//����2�д������ڲ����ͷ
	ListCtrl.InsertColumn(1,_T("����"));
	ListCtrl.SetColumnWidth(1,100);
	ListCtrl.InsertColumn(2,_T("�Ա�"));
	ListCtrl.SetColumnWidth(2,100);
	ListCtrl.InsertColumn(3,_T("��������"));
	ListCtrl.SetColumnWidth(3,100);
	ListCtrl.InsertColumn(4,_T("���ѧ��"));
	ListCtrl.SetColumnWidth(4,100);
	ListCtrl.InsertColumn(5,_T("ְ��"));
	ListCtrl.SetColumnWidth(5,100);
	ListCtrl.InsertColumn(6,_T("����"));
	ListCtrl.SetColumnWidth(6,100);
	ListCtrl.InsertColumn(7,_T("����״��"));
	ListCtrl.SetColumnWidth(7,100);
	
	    Str.Format(_T("%d"),pTeacher->tID); 	//��������ʽ��Ϊ�ַ���
		Index = ListCtrl.InsertItem(Index,Str); //�ڱ��в���һ��
		j = 1;
		Str.Format(_T("%s"),pTeacher->tName); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL); //����ĵ�Ԫ�����
		j++;
		Str.Format(_T("%s"),pTeacher->tGender); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d-%d-%d"),pTeacher->tBirth.GetYear(),pTeacher->tBirth.GetMonth(),pTeacher->tBirth.GetDay());
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tBack); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tTitle); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d"),pTeacher->tSalary); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pTeacher->tMarry); //��������ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
}


void CP09017139_4View::OnMatrixNum()
{
	CMatrixNumDlg Dlg;
	CP09017139_4Doc*pDoc=GetDocument();
	Dlg.p=pDoc;
	if(Dlg.DoModal()!=IDOK)
	{
	if(Dlg.flag)
	{
		if(Dlg.m_MatrixNum)
			ShowMatrix(&pDoc->mMat2);
		else
			ShowMatrix(&pDoc->mMat1);
	}
	}
// TODO: �ڴ���������������
}


void CP09017139_4View::OnMatrix()
{
	CMatrixChooseDlg Dlg;
	CP09017139_4Doc*pDoc=GetDocument();
	if(Dlg.DoModal()==IDOK)
		{
			if(Dlg.m_Matrix)
				ShowMatrix(&pDoc->mMat1);
			else
				ShowMatrix(&pDoc->mMat2);
	     }// TODO: �ڴ���������������
}



void CP09017139_4View::OnClassSearch()
{
	CCSearchDlg IDDlg;
	CP09017139_4Doc* pDoc=GetDocument();
	IDDlg.p=pDoc;
	CString Str;
	int j;
	int Index=0;
	if(IDDlg.DoModal()==IDOK)
	{
	CTeacher* pTeacher = NULL;
	CClass* pClass = NULL;		
	for(int x = 0;x < pDoc->mTeacherArray.GetSize();x++)//���������˶�Ա
	{
		pTeacher = pDoc->mTeacherArray[x];
		if(pTeacher->tName==IDDlg.m_CTName1)
		{
			for(int y=0;y<pTeacher->tClassArray.GetSize();y++)
			{
				pClass=pTeacher->tClassArray[y];
				if(pClass->cName==IDDlg.m_cName1)
				{
					CListCtrl& ListCtrl = GetListCtrl();//�õ�CListView�еķ�װ�Ŀؼ�CListCtrl 
	while(ListCtrl.DeleteColumn(0)){};
	ListCtrl.DeleteAllItems();
	//����2�д����������ԭ�е���ʾ
	ListCtrl.InsertColumn(0,_T("�γ̱��"));
	ListCtrl.SetColumnWidth(0,100);
	//����2�д������ڲ����ͷ
	ListCtrl.InsertColumn(1,_T("�γ�����"));
	ListCtrl.SetColumnWidth(1,100);
	ListCtrl.InsertColumn(2,_T("��ʱ"));
	ListCtrl.SetColumnWidth(2,100);
	ListCtrl.InsertColumn(3,_T("�ڿν���"));
	ListCtrl.SetColumnWidth(3,100);
	ListCtrl.InsertColumn(4,_T("�ڿΰ༶"));
	ListCtrl.SetColumnWidth(4,100);
	ListCtrl.InsertColumn(5,_T("ѧ��"));
	ListCtrl.SetColumnWidth(5,100);
	ListCtrl.InsertColumn(6,_T("ѧ��"));
	ListCtrl.SetColumnWidth(6,100);
	Str.Format(_T("%d"),pClass->cID); 	//��������ʽ��Ϊ�ַ���
		Index = ListCtrl.InsertItem(Index,Str); //�ڱ��в���һ��

		j = 1;
		Str.Format(_T("%s"),pClass->cName); //���ַ�����ʽ��Ϊ�ַ���

		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL); //����ĵ�Ԫ�����
		j++;
		Str.Format(_T("%d"),pClass->cTime);//��������ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pClass->cRoom); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d"),pClass->cClass); //��������ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%d"),pClass->cCode); //��������ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		j++;
		Str.Format(_T("%s"),pClass->cSemester); //���ַ�����ʽ��Ϊ�ַ���
		ListCtrl.SetItem(Index,j,LVIF_TEXT,Str,0,0,0,NULL);
		Index++;

	}
	}// TODO: �ڴ���������������
}
	}
	}
}