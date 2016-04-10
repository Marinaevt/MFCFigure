
// ChildView.cpp : реализация класса CChildView
//

#include "stdafx.h"
#include "TestMFC.h"
#include "ChildView.h"
#include <Windows.h>
#include <time.h>
#include <wingdi.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView(){
	m_nCatched = -1;
}

CChildView::~CChildView()
{
	for (int i = 0; i < m_figure.size(); i++) {
		delete m_figure[i];
	}
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CHAR()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
//	ON_WM_MOVE()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_ADD, AddNewFig)
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// обработчики сообщений CChildView

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // контекст устройства для рисования
	CDC dcMem;
	CBitmap bmpDC;
	CRect rcClient;
	CRect rect;
	GetClientRect(&rcClient);
	dcMem.CreateCompatibleDC(&dc);
	bmpDC.CreateCompatibleBitmap(&dc, rcClient.Width(), rcClient.Height());
	dcMem.SelectObject(&bmpDC);
	GetClientRect(&rect);
	dcMem.Rectangle(rect);
		for (int i = 0; i< m_figure.size(); i++) {
			m_figure[i]->Draw(dcMem);
		}
	dc.BitBlt(0, 0, rcClient.Width(), rcClient.Height(), &dcMem, 0, 0, SRCCOPY);
	dcMem.DeleteDC();
	bmpDC.DeleteObject();

	//CMy2DPoint c = m_figure.GetCenter();
	//double A = m_figure.GetA(), A1 = m_figure.GetA1(), A2 = m_figure.GetA2(), A3 = m_figure.GetA3(), angle = m_figure.GetAngle();
	//double cx = 170, cy = 170;
	//double A2 = 100, A = 300, A3 = 80, A1 = 80;

	/*
	double rx, ry;
	HDC hDc = dc.GetSafeHdc();

	CMy2DPoint center = m_figure.GetCenter();

	int nGraphicsMode = SetGraphicsMode(hDc, GM_ADVANCED);
	XFORM xform;
	double m_iAngle = -m_figure.GetAngle();
	if (m_iAngle != 0)
	{
		double fangle = (double)m_iAngle / 180. * 3.1415926;
		xform.eM11 = (float)cos(fangle);
		xform.eM12 = (float)sin(fangle);
		xform.eM21 = (float)-sin(fangle);
		xform.eM22 = (float)cos(fangle);
		xform.eDx = (float)(c.m_dx - cos(fangle)*c.m_dx + sin(fangle)*c.m_dy);
		xform.eDy = (float)(c.m_dy - cos(fangle)*c.m_dy - sin(fangle)*c.m_dy);

		SetWorldTransform(hDc, &xform);
	}
	*/
	/*
	dc.MoveTo(A2+c.m_dx - A/2, c.m_dy-A/2);
	dc.AngleArc(A2+c.m_dx - A / 2, A2+ c.m_dy - A / 2, A2, 90, 90);
	dc.LineTo(c.m_dx - A / 2, c.m_dy- A / 2 + A2 + (A-A2 - A3));
	dc.LineTo(c.m_dx - A / 2 + A3, c.m_dy - A / 2 + A - A3);
	dc.LineTo(A3 + c.m_dx - A / 2, c.m_dy - A / 2 + A);
	dc.LineTo(A + c.m_dx - A / 2, A + c.m_dy - A / 2);
	dc.LineTo(A + c.m_dx - A / 2, c.m_dy - A / 2 + 2*A1 + A/2 - A1);
	dc.AngleArc(c.m_dx - A / 2 + A, c.m_dy - A / 2 + A / 2, A1, -90, -180);
	dc.LineTo(c.m_dx - A / 2 + A, c.m_dy - A / 2);
	dc.LineTo(c.m_dx - A / 2 + A2, c.m_dy - A / 2);
	*/
	// Не вызывайте CWnd::OnPaint() для сообщений рисования
}
int CChildView::FindObject(CPoint point) {
	double tempx, tempy;
	for (int i = m_figure.size() - 1; i >= 0; i--) {
		//point.x = NCx(point.x, point.y, m_figure[i]->GetAngle());
		//point.y = NCy(point.x, point.y, m_figure[i]->GetAngle());
		if (m_figure[i]->IsInside(point.x, point.y)) {
			return i;
		}
	}
	return -1;
}


void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	CWnd::OnChar(nChar, nRepCnt, nFlags);
	if (nChar == 0x0D) {
		GetParent()->PostMessage(WM_QUIT);
	}
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	//point.x = NCx(point.x, point.y, m_figure[m_nCatched]->GetAngle());
	//point.y = NCy(point.x, point.y, m_figure[m_nCatched]->GetAngle());
	m_nCatched = -1;
	ReleaseCapture();
	CWnd::OnLButtonUp(nFlags, point);
//	if (m_figure.IsInside(point.x, point.y)) {
//		AfxMessageBox(_T("INSIDE"));
//	}
}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	m_nCatched = FindObject(point);
	if (m_nCatched >= 0) {
		m_MousePos = point;
		SetCapture();
	}
//	if (m_figure.IsInside(point.x, point.y)) {
//		m_bCatched = 1;
//		m_MousePos = point;
//		SetCapture();
//	}
	CWnd::OnLButtonDown(nFlags, point);
}


//void CChildView::OnMove(int x, int y)
//{
//	CWnd::OnMove(x, y);
//
//	// TODO: добавьте свой код обработчика сообщений
//}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	if (m_nCatched >= 0) {
		//point.x = NCx(point.x, point.y, m_figure[m_nCatched]->GetAngle());
		//point.y = NCy(point.x, point.y, m_figure[m_nCatched]->GetAngle());
		CRect rect;
		GetClientRect(&rect);
		point.x = min(rect.right, max(rect.left, point.x));
		point.y = min(rect.bottom, max(rect.top, point.y));
		CPoint Delta = point - m_MousePos;
		m_figure[m_nCatched]->Move(Delta.x, Delta.y, 0);
		m_MousePos = point;
		Invalidate();
		UpdateWindow();
	}
	CWnd::OnMouseMove(nFlags, point);
}
void CChildView::AddNewFig() {
	CRect rect;
	GetClientRect(&rect);
	m_figure.push_back(new CMy2DObject8A(150, 40, 20, 60, 60, 200, 340));
	Invalidate();
	//UpdateWindow();
}


void CChildView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);
	// TODO: добавьте свой код обработчика сообщений
}


BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	//return CWnd::OnEraseBkgnd(pDC);
	return FALSE;
}
