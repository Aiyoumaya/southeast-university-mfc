
// P09017139_4Doc.h : CP09017139_4Doc ��Ľӿ�
//


#pragma once
#include "afxtempl.h"
#include"Teacher.h"
#include"Matrix.h"

class CP09017139_4Doc : public CDocument
{
protected: // �������л�����
	CP09017139_4Doc();
	DECLARE_DYNCREATE(CP09017139_4Doc)

// ����
public:

	CMatrix<float> mMat1;
	CMatrix<float> mMat2;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CP09017139_4Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	// ��Ž�ʦ
	CTypedPtrArray<CObArray, CTeacher*> mTeacherArray;
	afx_msg void OnIputtsignup();
	afx_msg void OnInputcSignup();
	// ��ſγ�
	CTypedPtrArray<CObArray, CClass*> mClassArray;


	afx_msg void OnCal();
	afx_msg void OnEditteacher();
	afx_msg void OnDelete();
	afx_msg void OnNew();
	afx_msg void Oncdelete();
	afx_msg void OnEditClass();
};
