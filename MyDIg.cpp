// MyDIg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "UserDIgTest.h"
#include "MyDIg.h"
#include "afxdialogex.h"


// CMyDIg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMyDIg, CDialog)

CMyDIg::CMyDIg(CWnd* pParent/* =NULL*/)
	: CDialog(IDD_MYDIALOG, pParent)

		, m_strName(_T(""))
		, m_strHphone(_T(""))
		, m_strEmail(_T(""))
{

}

CMyDIg::~CMyDIg()
{
}

void CMyDIg::DoDataExchange(CDataExchange* pDX)
{
		CDialog::DoDataExchange(pDX);

		DDX_Text(pDX, IDC_NAME, m_strName);
		DDX_Text(pDX, IDC_HPHONE, m_strHphone);
		DDX_Text(pDX, IDC_EMAIL, m_strEmail);
}


BEGIN_MESSAGE_MAP(CMyDIg, CDialog)
END_MESSAGE_MAP()


// CMyDIg 메시지 처리기입니다.
