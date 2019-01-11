
// P09017139_4View.h : CP09017139_4View ��Ľӿ�
//

#pragma once


class CP09017139_4View : public CListView
{
protected: // �������л�����
	CP09017139_4View();
	DECLARE_DYNCREATE(CP09017139_4View)

// ����
public:
	CP09017139_4Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CP09017139_4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOutputtsignup();
	afx_msg void Ontoutput();

	//afx_msg void OnCal();

	afx_msg void OnSearch();
	void ShowMatrix(CMatrix<float>* pMat);
	afx_msg void OnMatrixp();
	afx_msg void OnMatrixs();
	afx_msg void OnMatrixm();
	afx_msg void Oncoutput();
	afx_msg void OnTeacherClass();
	// ��ʦ��Ϣ��ʾ
	void ShowTeacher(CTeacher* pTeacher,int Index);
	afx_msg void OnMatrixNum();
	afx_msg void OnMatrix();
	afx_msg void OnClassSearch();
};

#ifndef _DEBUG  // P09017139_4View.cpp �еĵ��԰汾
inline CP09017139_4Doc* CP09017139_4View::GetDocument() const
   { return reinterpret_cast<CP09017139_4Doc*>(m_pDocument); }
#endif

