
// PaintView.h: интерфейс класса CPaintView
//

#pragma once


class CPaintView : public CView
{
protected: // создать только из сериализации
	CPaintView() noexcept;
	DECLARE_DYNCREATE(CPaintView)

// Атрибуты
public:
	CPaintDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CPaintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	int type = 0;
	int size = 10;
	int styleBrush = HS_API_MAX;
	int stylePen = PS_SOLID;

	COLORREF Ccolor = RGB(0,0,0);

	HBRUSH hBrush = CreateHatchBrush(styleBrush, Ccolor);
	HPEN hPen = CreatePen(stylePen, size, Ccolor);

	POINT Anchor, Cursor, Ptmp;

	LPCRECT Window;

	bool LMBActive = false;
	bool polydrow;

	afx_msg void OnBrush();
	afx_msg void OnLine();
	afx_msg void OnRectangle();
	afx_msg void OnCircle();
	afx_msg void OnTriangle();
	afx_msg void OnPoligon();
	afx_msg void OnPipet();
	afx_msg void OnPalette();
	afx_msg void OnArc();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnClear();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // версия отладки в PaintView.cpp
inline CPaintDoc* CPaintView::GetDocument() const
   { return reinterpret_cast<CPaintDoc*>(m_pDocument); }
#endif

