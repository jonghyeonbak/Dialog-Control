
// UserDIgTestView.cpp : CUserDIgTestView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
		ON_COMMAND(ID_MYDIALOG, &CUserDIgTestView::OnMydialog)
		ON_COMMAND(ID_SHAPESELECT, &CUserDIgTestView::OnShapeselect)
END_MESSAGE_MAP()

// CUserDIgTestView 생성/소멸

CUserDIgTestView::CUserDIgTestView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
		int m_ShapeType = 1;
		int m_nColor = -1;
		BOOL m_bColorApply = TRUE;

}

CUserDIgTestView::~CUserDIgTestView()
{
}

BOOL CUserDIgTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CUserDIgTestView 그리기

void CUserDIgTestView::OnDraw(CDC* pDC)
{
	CUserDIgTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	CString strMsg; // 출력할 내용을 저장할 변수 선언
	strMsg.Empty(); // 변수 초기화
	if (m_bColorApply == TRUE) {
			switch (m_nColor) {
			case 0: strMsg = "빨간색 "; break;
			case 1: strMsg = "초록색 "; break;
			case 2: strMsg = "파란색 "; break;
			case 3: strMsg = "보라색 "; break;
			}
	}
	switch (m_ShapeType) {
	case 0: strMsg += "원"; break;
	case 1: strMsg += "사각형"; break;
	case 2: strMsg += "선"; break;
	}
	pDC->TextOutW(100, 100, strMsg);
}


// CUserDIgTestView 인쇄

BOOL CUserDIgTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CUserDIgTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CUserDIgTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CUserDIgTestView 진단

#ifdef _DEBUG
void CUserDIgTestView::AssertValid() const
{
	CView::AssertValid();
}

void CUserDIgTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUserDIgTestDoc* CUserDIgTestView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUserDIgTestDoc)));
	return (CUserDIgTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CUserDIgTestView 메시지 처리기


void CUserDIgTestView::OnMydialog()
{
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
		CMyDIg dig;
		//int res = dig.DoModal();
		if (dig.DoModal() == IDCANCEL) return;
		CString strMsg;
		strMsg.Format(_T("\n 이름:% s \n 이메일:%s \n 핸드폰 번호: %s"), dig.m_strName, dig.m_strEmail, dig.m_strHphone);
		MessageBox(strMsg);

		/*if (res == IDOK)
				MessageBox(_T("<확인> 버튼이 눌려서 대화상자가 닫힘"));
		else if(res == IDCANCEL)
				MessageBox(_T("<취소> 버튼이 눌려서 대화상자가 닫힘"));*/
}


void CUserDIgTestView::OnShapeselect()
{
		// TODO: 여기에 명령 처리기 코드를 추가합니다.
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
