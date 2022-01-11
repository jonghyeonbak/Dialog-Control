
// UserDIgTestView.cpp : CUserDIgTestView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "UserDIgTest.h"
#endif

#include "UserDIgTestDoc.h"
#include "UserDIgTestView.h"

#include "MyDIg.h"
#include "ShapeDIg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUserDIgTestView

IMPLEMENT_DYNCREATE(CUserDIgTestView, CView)

BEGIN_MESSAGE_MAP(CUserDIgTestView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
		ON_COMMAND(ID_MYDIALOG, &CUserDIgTestView::OnMydialog)
		ON_COMMAND(ID_SHAPESELECT, &CUserDIgTestView::OnShapeselect)
END_MESSAGE_MAP()

// CUserDIgTestView ����/�Ҹ�

CUserDIgTestView::CUserDIgTestView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
		int m_ShapeType = 1;
		int m_nColor = -1;
		BOOL m_bColorApply = TRUE;

}

CUserDIgTestView::~CUserDIgTestView()
{
}

BOOL CUserDIgTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CUserDIgTestView �׸���

void CUserDIgTestView::OnDraw(CDC* pDC)
{
	CUserDIgTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.

	CString strMsg; // ����� ������ ������ ���� ����
	strMsg.Empty(); // ���� �ʱ�ȭ
	if (m_bColorApply == TRUE) {
			switch (m_nColor) {
			case 0: strMsg = "������ "; break;
			case 1: strMsg = "�ʷϻ� "; break;
			case 2: strMsg = "�Ķ��� "; break;
			case 3: strMsg = "����� "; break;
			}
	}
	switch (m_ShapeType) {
	case 0: strMsg += "��"; break;
	case 1: strMsg += "�簢��"; break;
	case 2: strMsg += "��"; break;
	}
	pDC->TextOutW(100, 100, strMsg);
}


// CUserDIgTestView �μ�

BOOL CUserDIgTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CUserDIgTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CUserDIgTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CUserDIgTestView ����

#ifdef _DEBUG
void CUserDIgTestView::AssertValid() const
{
	CView::AssertValid();
}

void CUserDIgTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUserDIgTestDoc* CUserDIgTestView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUserDIgTestDoc)));
	return (CUserDIgTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CUserDIgTestView �޽��� ó����


void CUserDIgTestView::OnMydialog()
{
		// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
		CMyDIg dig;
		//int res = dig.DoModal();
		if (dig.DoModal() == IDCANCEL) return;
		CString strMsg;
		strMsg.Format(_T("\n �̸�:% s \n �̸���:%s \n �ڵ��� ��ȣ: %s"), dig.m_strName, dig.m_strEmail, dig.m_strHphone);
		MessageBox(strMsg);

		/*if (res == IDOK)
				MessageBox(_T("<Ȯ��> ��ư�� ������ ��ȭ���ڰ� ����"));
		else if(res == IDCANCEL)
				MessageBox(_T("<���> ��ư�� ������ ��ȭ���ڰ� ����"));*/
}


void CUserDIgTestView::OnShapeselect()
{
		// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
		CShapeDIg dig;

		dig.m_nShape = m_ShapeType;
		dig.m_nColor = m_nColor;
		dig.m_bColorApply = m_bColorApply;

		if (dig.DoModal() == IDCANCEL) return;

		m_ShapeType = dig.m_nShape;
		m_nColor = dig.m_nColor;
		m_bColorApply = dig.m_bColorApply;

		Invalidate();

}
