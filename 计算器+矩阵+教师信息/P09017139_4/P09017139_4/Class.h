#pragma once
#include "afx.h"
class CClass :
	public CObject
{
	DECLARE_SERIAL(CClass)
public:
	CClass(void);
	~CClass(void);
	// �γ̱��
	int cID;

	// �γ�����
	CString cName;
	// ��ʱ
	int cTime;
	// ����
	CString cRoom;
	// �ڿΰ༶
	int cClass;
	// ѧ��
	int cCode;
	// ѧ��
	CString cSemester;
	void Serialize(CArchive& ar);
};

