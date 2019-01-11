
// P09017139_4Doc.cpp : CP09017139_4Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "P09017139_4.h"
#endif
#include"tSignupDlg.h"
#include "P09017139_4Doc.h"
#include"cSignupDlg.h"
#include"SearchDlg.h"
#include <propkey.h>
#include"CalDlg.h"
#include"NewDlg.h"
#include"Matrix.h"
#include"CSearchDlg.h"
#include"MatrixNumDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CP09017139_4Doc

IMPLEMENT_DYNCREATE(CP09017139_4Doc, CDocument)

BEGIN_MESSAGE_MAP(CP09017139_4Doc, CDocument)
	ON_COMMAND(ID_IPUT_tSIGNUP, &CP09017139_4Doc::OnIputtsignup)
	ON_COMMAND(ID_INPUT_SIGNUP, &CP09017139_4Doc::OnInputcSignup)
	ON_COMMAND(ID_CAL, &CP09017139_4Doc::OnCal)
	ON_COMMAND(ID_EditTeacher, &CP09017139_4Doc::OnEditteacher)
	ON_COMMAND(ID_DELETE, &CP09017139_4Doc::OnDelete)
	ON_COMMAND(ID_NEW, &CP09017139_4Doc::OnNew)
	ON_COMMAND(ID_cDELETE, &CP09017139_4Doc::Oncdelete)
	ON_COMMAND(ID_EditClass, &CP09017139_4Doc::OnEditClass)
END_MESSAGE_MAP()


// CP09017139_4Doc ����/����

CP09017139_4Doc::CP09017139_4Doc()
{
	// TODO: �ڴ����һ���Թ������

}

CP09017139_4Doc::~CP09017139_4Doc()
{
}

BOOL CP09017139_4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CP09017139_4Doc ���л�

void CP09017139_4Doc::Serialize(CArchive& ar)
{
	mTeacherArray.Serialize(ar);
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CP09017139_4Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CP09017139_4Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CP09017139_4Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CP09017139_4Doc ���

#ifdef _DEBUG
void CP09017139_4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CP09017139_4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CP09017139_4Doc ����


void CP09017139_4Doc::OnIputtsignup()
{
	CtSignupDlg Dlg;
	if(Dlg.DoModal() == IDOK)
	{
		CTeacher* pTeacher = new CTeacher;
		//��new����CSportMan����
        pTeacher->tBirth = Dlg.m_Date;
		pTeacher->tID = Dlg.m_tID;
		pTeacher->tName = Dlg.m_Name;
		pTeacher->tGender = Dlg.m_Gender;
		pTeacher->tBack = Dlg.m_Back;
		pTeacher->tTitle = Dlg.m_Title;
		pTeacher->tSalary = Dlg.m_Salary;
		pTeacher->tMarry = Dlg.m_Marry;
		mTeacherArray.Add(pTeacher);
	}

// TODO: �ڴ���������������
}


void CP09017139_4Doc::OnInputcSignup()
{
	SearchDlg Dlg;
	Dlg.p=this;
	if(Dlg.DoModal()==IDOK)
	{
		CTeacher* pTeacher = new CTeacher;
		for(int i=0; i<mTeacherArray.GetSize();i++)
		{
			pTeacher = mTeacherArray[i];
			if(pTeacher->tName==Dlg.m_Name1)
			{
				cSignupDlg ItemDlg;
				if(ItemDlg.DoModal()==IDOK)
				{
					CClass* pItem = new CClass;
					pItem->cID = ItemDlg.m_ID;
					pItem->cName = ItemDlg.m_Name;
					pItem->cTime = ItemDlg.m_Time;
					pItem->cRoom = ItemDlg.m_Room;
					pItem->cClass = ItemDlg.m_Class;
					pItem->cCode = ItemDlg.m_Code;
					pItem->cSemester = ItemDlg.m_Semester;
					pTeacher->tClassArray.Add(pItem);
					return;
				}
			}
		}
	}
}

	
	
void CP09017139_4Doc::OnCal()
{
	CalDlg Dlg;
	Dlg.DoModal();// TODO: �ڴ���������������
}


void CP09017139_4Doc::OnEditteacher()
{
	SearchDlg IDDlg;  
	IDDlg.p=this;
if(IDDlg.DoModal()==IDOK) //�������д���������ȡm_ID��ֵ
{
	CTeacher* pTeacher = NULL;
	for(int i=0; i<mTeacherArray.GetSize();i++)
{
    pTeacher = mTeacherArray[i];
	if(pTeacher->tName==IDDlg.m_Name1) //����m_ID���Ҷ���
	{  //�ҵ�Ҫ�޸ĵĶ�����
		CtSignupDlg Dlg; //����5�д����öԻ�����ʾ�޸�ǰ����Ϣ
		Dlg.m_tID = pTeacher->tID;
        Dlg.m_Name = pTeacher->tName;
        Dlg.m_Date = pTeacher->tBirth;
        Dlg.m_Salary = pTeacher->tSalary;
        Dlg.m_Gender = pTeacher->tGender;
		Dlg.m_Back = pTeacher->tBack;
		Dlg.m_Title = pTeacher->tTitle;
		Dlg.m_Marry = pTeacher->tMarry;
		if(Dlg.DoModal() == IDOK) //����Ĵ�������޸�
		{
            pTeacher->tBirth = Dlg.m_Date;
		    pTeacher->tID = Dlg.m_tID;
		    pTeacher->tName = Dlg.m_Name;
		    pTeacher->tGender = Dlg.m_Gender;
		    pTeacher->tBack = Dlg.m_Back;
		    pTeacher->tTitle = Dlg.m_Title;
		    pTeacher->tSalary = Dlg.m_Salary;
		    pTeacher->tMarry = Dlg.m_Marry;
			//����4���޸����ݣ�ֻ�����¸�ֵ�����ˣ�ID��Ҫ��ֵ
			return; //�޸Ľ������˳�����
         }
         AfxMessageBox(_T("�鵽��ʦ��������ȡ����ť��"));
         return;
     }
}
AfxMessageBox(_T("���ṩ��ID�ţ�û�鵽��ʦ��"));
	return;
}
AfxMessageBox(_T( "�����ṩID���ˣ�"));
}



void CP09017139_4Doc::OnDelete()
{
	
	SearchDlg IDDlg; 
	IDDlg.p=this;
if(IDDlg.DoModal()==IDOK) //�������д���������ȡm_ID��ֵ
{
	CTeacher* pTeacher = NULL;
	for( int i=0; i<mTeacherArray.GetSize();i++)
{
    pTeacher = mTeacherArray[i];
	if(pTeacher->tName==IDDlg.m_Name1) //����m_ID���Ҷ���
	{ 
		mTeacherArray.RemoveAt(i);//�ҵ�Ҫ�޸ĵĶ�����
	}
	return;
}
AfxMessageBox(_T( "�����ṩID���ˣ�"));// TODO: �ڴ���������������
}
}


void CP09017139_4Doc::Oncdelete()
{
	CCSearchDlg IDDlg; 
	IDDlg.p=this;
if(IDDlg.DoModal()==IDOK) //�������д���������ȡm_ID��ֵ
{
	CTeacher* pTeacher = NULL;
	CClass* pClass = NULL;
	for( int i=0; i<mTeacherArray.GetSize();i++)
{
    pTeacher = mTeacherArray[i];
	if(pTeacher->tName==IDDlg.m_CTName1) //����m_ID���Ҷ���
	{ 
		for( int j = 0; j<pTeacher->tClassArray.GetSize();j++)
		{
			pClass=pTeacher->tClassArray[j];
			if(pClass->cName==IDDlg.m_cName1)
				pTeacher->tClassArray.RemoveAt(j);//�ҵ�Ҫ�޸ĵĶ�����
			else
				AfxMessageBox(_T( "δ�鵽�γ̣�"));return;
		}
	}
}
}
else
	AfxMessageBox(_T( "δ�鵽��ʦ��"));return;// TODO: �ڴ���������������
}


void CP09017139_4Doc::OnNew()
{
	NewDlg Dlg;
	Dlg.m_mCol = 2;
	Dlg.m_mRow = 3;
	if(Dlg.DoModal()==IDOK)
	{
		if(Dlg.m_Mat2)
			mMat2.Create(Dlg.m_mRow,Dlg.m_mCol);
		else
			mMat1.Create(Dlg.m_mRow,Dlg.m_mCol);
	}// TODO: �ڴ���������������
}






void CP09017139_4Doc::OnEditClass()
{
	CCSearchDlg IDDlg;  
	IDDlg.p=this;
if(IDDlg.DoModal()==IDOK) //�������д���������ȡm_ID��ֵ
{
	CTeacher* pTeacher = NULL;
	CClass* pClass = NULL;
	for( int i=0; i<mTeacherArray.GetSize();i++)
{
    pTeacher = mTeacherArray[i];
	if(pTeacher->tName==IDDlg.m_CTName1) //����m_ID���Ҷ���
	{ 
		for( int j = 0; j<pTeacher->tClassArray.GetSize();j++)
		{
			pClass=pTeacher->tClassArray[j];
			if(pClass->cName==IDDlg.m_cName1)
			{
				cSignupDlg Dlg1;
				    Dlg1.m_ID=pClass->cID;
					Dlg1.m_Name=pClass->cName;
					Dlg1.m_Time=pClass->cTime;
					Dlg1.m_Room=pClass->cRoom  ;
					Dlg1.m_Class=pClass->cClass ;
					Dlg1.m_Code=pClass->cCode;
					Dlg1.m_Semester=pClass->cSemester;
					if(Dlg1.DoModal()==IDOK)
					{
						pClass->cID = Dlg1.m_ID;
					pClass->cName = Dlg1.m_Name;
					pClass->cTime = Dlg1.m_Time;
					pClass->cRoom = Dlg1.m_Room;
					pClass->cClass = Dlg1.m_Class;
					pClass->cCode = Dlg1.m_Code;
					pClass->cSemester = Dlg1.m_Semester;
					}

			}//�ҵ�Ҫ�޸ĵĶ�����
			else
				AfxMessageBox(_T( "δ�鵽�γ̣�"));return;
		}
	}
	else
	AfxMessageBox(_T( "δ�鵽��ʦ��"));return;
}
}
AfxMessageBox(_T( "�����ṩID���ˣ�"));// TODO: �ڴ���������������
}
