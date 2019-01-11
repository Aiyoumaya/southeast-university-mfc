#include "StdAfx.h"
#include "Class.h"

IMPLEMENT_SERIAL(CClass,CObject,0)
CClass::CClass(void)
	: cID(0)
	, cName(_T("����"))
	, cTime(0)
	, cRoom(_T("����"))
	, cClass(0)
	, cCode(0)
	, cSemester(_T("ѧ��"))
{
}


CClass::~CClass(void)
{
}


void CClass::Serialize(CArchive& ar)
{
	if(ar.IsStoring())
	{
		ar << cID;
	    ar << cName;
	    ar << cTime;
        ar << cRoom;
	    ar << cClass;
        ar << cCode;
        ar << cSemester;
	}
	else
	{
		ar >> cID;
	    ar >> cName;
	    ar >> cTime;
        ar >> cRoom;
	    ar >> cClass;
        ar >> cCode;
        ar >> cSemester;
	}
}
