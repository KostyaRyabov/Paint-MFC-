
// PaintView.cpp: реализация класса CPaintView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Paint.h"
#endif

#include "PaintDoc.h"
#include "PaintView.h"
#include "PaletteDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPaintView

IMPLEMENT_DYNCREATE(CPaintView, CView)

BEGIN_MESSAGE_MAP(CPaintView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPaintView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32771, &CPaintView::OnBrush)
	ON_COMMAND(ID_32772, &CPaintView::OnLine)
	ON_COMMAND(ID_32773, &CPaintView::OnRectangle)
	ON_COMMAND(ID_32774, &CPaintView::OnCircle)
	ON_COMMAND(ID_32775, &CPaintView::OnTriangle)
	ON_COMMAND(ID_32776, &CPaintView::OnPoligon)
	ON_COMMAND(ID_32777, &CPaintView::OnPipet)
	ON_COMMAND(ID_32778, &CPaintView::OnPalette)
	ON_COMMAND(ID_32779, &CPaintView::OnArc)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_32780, &CPaintView::OnClear)
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// Создание или уничтожение CPaintView

CPaintView::CPaintView() noexcept
{
	// TODO: добавьте код создания
}

CPaintView::~CPaintView()
{
}

BOOL CPaintView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Рисование CPaintView

void CPaintView::OnDraw(CDC* /*pDC*/)
{
	CPaintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных


}


// Печать CPaintView


void CPaintView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPaintView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CPaintView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CPaintView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void CPaintView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	/*ClientToScreen(&point);
	OnContextMenu(this, point);*/

	PaletteDlg Pdlg;

	Pdlg.SetColor(Ccolor);
	Pdlg.SetSize(size);
	Pdlg.SetStyleB(styleBrush);
	Pdlg.SetStyleP(stylePen);

	Pdlg.DoModal();

	Ccolor = Pdlg.GetColor();
	size = Pdlg.GetSize();
	styleBrush = Pdlg.GetStyleB();
	stylePen = Pdlg.GetStyleP();

	hBrush = CreateHatchBrush(styleBrush, Ccolor);
	hPen = CreatePen(stylePen, size, Ccolor);
}

void CPaintView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Диагностика CPaintView

#ifdef _DEBUG
void CPaintView::AssertValid() const
{
	CView::AssertValid();
}

void CPaintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPaintDoc* CPaintView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPaintDoc)));
	return (CPaintDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CPaintView


void CPaintView::OnBrush()
{
	// TODO: добавьте свой код обработчика команд

	type = 1;
}


void CPaintView::OnLine()
{
	// TODO: добавьте свой код обработчика команд

	type = 2;
}


void CPaintView::OnArc()
{
	// TODO: добавьте свой код обработчика команд

	type = 3;
}


void CPaintView::OnRectangle()
{
	// TODO: добавьте свой код обработчика команд

	type = 4;
}


void CPaintView::OnCircle()
{
	// TODO: добавьте свой код обработчика команд

	type = 5;
}


void CPaintView::OnTriangle()
{
	// TODO: добавьте свой код обработчика команд

	type = 6;
}


void CPaintView::OnPoligon()
{
	// TODO: добавьте свой код обработчика команд

	type = 7;

	polydrow = true;
}


void CPaintView::OnPipet()
{
	// TODO: добавьте свой код обработчика команд

	type = 8;
}


void CPaintView::OnPalette()
{
	// новое окно с настройкой цвета, толщины кисти

	PaletteDlg Pdlg;

	Pdlg.SetColor(Ccolor);
	Pdlg.SetSize(size);
	Pdlg.SetStyleB(styleBrush);
	Pdlg.SetStyleP(stylePen);

	Pdlg.DoModal();

	Ccolor = Pdlg.GetColor();
	size = Pdlg.GetSize();
	styleBrush = Pdlg.GetStyleB();
	stylePen = Pdlg.GetStyleP();

	hBrush = CreateHatchBrush(styleBrush, Ccolor);
	hPen = CreatePen(stylePen, size, Ccolor);
}


void CPaintView::OnClear()
{
	Invalidate(true);
	// TODO: добавьте свой код обработчика команд
}


void CPaintView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	if (type == 8) {
		CClientDC* pDC = new CClientDC(this);

		//pDC->FillRect(Window, );

		Ccolor = pDC->GetPixel(point.x, point.y);

		hBrush = CreateHatchBrush(styleBrush, Ccolor);
		hPen = CreatePen(stylePen, size, Ccolor);

		RECT R;

		pDC->FillRect(&R, (HBRUSH)hBrush);
	}else if (type != 7) {
		Anchor.x = point.x;
		Anchor.y = point.y;
	}

	

	LMBActive = true;

	CView::OnLButtonDown(nFlags, point);
}


void CPaintView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	CClientDC* pDC = new CClientDC(this);

	pDC->SelectObject(hBrush);
	pDC->SelectObject(hPen);

	switch (type)
	{
	case 2:
		{
			pDC->MoveTo(Anchor.x, Anchor.y);
			pDC->LineTo(point.x, point.y);
		}
		break;
	case 3:
		{
			pDC->Arc(Anchor.x, Anchor.y, point.x, point.y, Anchor.x, Anchor.y, point.x, point.y);
		}
		break;
	case 4:
		{
			pDC->Rectangle(Anchor.x, Anchor.y, point.x, point.y);
		}
		break;
	case 5:
		{
			pDC->Chord(Anchor.x, Anchor.y, point.x, point.y, 0, 0, 0, 0);
		}
		break;
	case 6:
		{
			POINT poly[4];

			poly[0].x = Anchor.x;
			poly[0].y = Anchor.y;

			poly[1].x = (Anchor.x + point.x) / 2;
			poly[1].y = point.y;

			poly[2].x = point.x;
			poly[2].y = Anchor.y;

			poly[3].x = Anchor.x;
			poly[3].y = Anchor.y;

			pDC->Polyline(poly, 4);
		}
		break;
	case 7:
	{
		if (polydrow) {
			Ptmp.x = point.x;
			Ptmp.y = point.y;
			
			Anchor.x = point.x;
			Anchor.y = point.y;

			polydrow = false;
		}
		else {
			pDC->MoveTo(Anchor.x, Anchor.y);
			pDC->LineTo(point.x, point.y);

			Anchor.x = point.x;
			Anchor.y = point.y;
		}
	}
		break;
	default:
		break;
	}

	LMBActive = false;

	CView::OnLButtonUp(nFlags, point);
}


void CPaintView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	CClientDC* pDC = new CClientDC(this);

	pDC->SelectObject(hBrush);
	pDC->SelectObject(hPen);

	if (LMBActive && type == 1) {
		pDC->MoveTo(Anchor.x, Anchor.y);
		pDC->LineTo(point.x, point.y);

		Anchor.x = point.x;
		Anchor.y = point.y;
	}

	CView::OnMouseMove(nFlags, point);
}


void CPaintView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	if (nChar == ' ') {
		if (type == 7) {
			CClientDC* pDC = new CClientDC(this);

			pDC->SelectObject(hBrush);
			pDC->SelectObject(hPen);

			pDC->MoveTo(Anchor.x, Anchor.y);
			pDC->LineTo(Ptmp.x, Ptmp.y);

			polydrow = true;
		}
	}
	else if (nChar == '0') {
		Invalidate(true);
	}
	else if (nChar == '1') {
		type = 1;
	}
	else if (nChar == '2') {
		type = 2;
	}
	else if (nChar == '3') {
		type = 3;
	}
	else if (nChar == '4') {
		type = 4;
	}
	else if (nChar == '5') {
		type = 5;
	}
	else if (nChar == '6') {
		type = 6;
	}
	else if (nChar == '7') {
		type = 7;
	}
	else if (nChar == '8') {
		type = 8;
	}
	else if (nChar == '9') {
		PaletteDlg Pdlg;

		Pdlg.SetColor(Ccolor);
		Pdlg.SetSize(size);
		Pdlg.SetStyleB(styleBrush);
		Pdlg.SetStyleP(stylePen);

		Pdlg.DoModal();

		Ccolor = Pdlg.GetColor();
		size = Pdlg.GetSize();
		styleBrush = Pdlg.GetStyleB();
		stylePen = Pdlg.GetStyleP();

		hBrush = CreateHatchBrush(styleBrush, Ccolor);
		hPen = CreatePen(stylePen, size, Ccolor);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
