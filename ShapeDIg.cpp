// ShapeDIg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "UserDIgTest.h"
#include "ShapeDIg.h"
#include "afxdialogex.h"


// CShapeDIg ��ȭ �����Դϴ�.

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


// CShapeDIg �޽��� ó�����Դϴ�.



void CShapeDIg::OnBnClickedCheck1()
{
		// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
		UpdateData(TRUE); // üũ �ڽ��� ���� ���� ���´�.
		
		//üũ �ڽ��� ���¸� �ݿ��ϴ� ��Ӻ����� ���ؼ�
		// ���� ��ư�� Ȱ��ȭ or ��Ȱ��ȭ
		c_Red.EnableWindow(m_bColorApply);
		c_Green.EnableWindow(m_bColorApply);
		c_Blue.EnableWindow(m_bColorApply);
		c_Purple.EnableWindow(m_bColorApply);
}
