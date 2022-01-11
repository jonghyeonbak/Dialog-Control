// ShapeDIg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "UserDIgTest.h"
#include "ShapeDIg.h"
#include "afxdialogex.h"


// CShapeDIg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CShapeDIg, CDialog)

CShapeDIg::CShapeDIg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DIALOG_SHAPE, pParent)
		, m_nShape(0)
		, m_nColor(0)
		, m_bColorApply(FALSE)
{

}

CShapeDIg::~CShapeDIg()
{
}

void CShapeDIg::DoDataExchange(CDataExchange* pDX)
{
		CDialog::DoDataExchange(pDX);
		DDX_Radio(pDX, IDC_RADIO1, m_nShape);
		DDX_Radio(pDX, IDC_RADIO4, m_nColor);
		DDX_Check(pDX, IDC_CHECK1, m_bColorApply);
		DDX_Control(pDX, IDC_RADIO4, c_Red);
		DDX_Control(pDX, IDC_RADIO1, c_Ellipse);
		DDX_Control(pDX, IDC_RADIO2, c_Square);
		DDX_Control(pDX, IDC_RADIO3, c_Line);
		DDX_Control(pDX, IDC_RADIO6, c_Green);
		DDX_Control(pDX, IDC_RADIO5, c_Blue);
		DDX_Control(pDX, IDC_RADIO7, c_Purple);
}


BEGIN_MESSAGE_MAP(CShapeDIg, CDialog)
		ON_BN_CLICKED(IDC_CHECK1, &CShapeDIg::OnBnClickedCheck1)
END_MESSAGE_MAP()


// CShapeDIg 메시지 처리기입니다.



void CShapeDIg::OnBnClickedCheck1()
{
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		UpdateData(TRUE); // 체크 박스의 상태 값을 얻어온다.
		
		//체크 박스의 상태를 반영하는 멤머변수에 의해서
		// 라디오 버튼이 활성화 or 비활성화
		c_Red.EnableWindow(m_bColorApply);
		c_Green.EnableWindow(m_bColorApply);
		c_Blue.EnableWindow(m_bColorApply);
		c_Purple.EnableWindow(m_bColorApply);
}
