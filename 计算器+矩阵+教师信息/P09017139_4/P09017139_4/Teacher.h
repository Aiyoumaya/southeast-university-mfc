#pragma once
#include "afx.h"
#include "atlcomtime.h"
#include "afxtempl.h"
#include"Class.h"
class CTeacher :
	public CObject
{
	DECLARE_SERIAL(CTeacher) 
public:
	CTeacher(void);
	~CTeacher(void);
	int tID;//���
	CString tName;//����
	CString tGender;//�Ա�
	COleDateTime tBirth;//��������
	CString tBack;//���ѧ��
	CString tTitle;//ְ��
	int tSalary;//����
	CString tMarry;//����״��
	
	// �������ͳ�Ա����Ž��ڵĿγ�
	CTypedPtrArray<CObArray, CClass*> tClassArray;
	void Serialize(CArchive& ar);
};

