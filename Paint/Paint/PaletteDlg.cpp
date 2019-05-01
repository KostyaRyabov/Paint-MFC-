// PaletteDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "Paint.h"
#include "PaletteDlg.h"
#include "afxdialogex.h"


// Диалоговое окно PaletteDlg

IMPLEMENT_DYNAMIC(PaletteDlg, CDialogEx)

PaletteDlg::PaletteDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PaletteDlg, pParent)
	, size(_T("1"))
{
	
}

PaletteDlg::~PaletteDlg()
{
}

void PaletteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, colorB);
	DDX_Text(pDX, IDC_EDIT1, size);
	DDX_Control(pDX, IDC_COMBO1, styleB);
	DDX_Control(pDX, IDC_COMBO2, styleP);

	if (opened == false) {
		
		styleB.AddString(L"HS_CROSS");
		styleB.AddString(L"HS_DIAGCROSS");
		styleB.AddString(L"HS_FDIAGONAL");
		styleB.AddString(L"HS_HORIZONTAL");
		styleB.AddString(L"HS_VERTICAL");
		styleB.AddString(L"HS_API_MAX");

		
		styleP.AddString(L"PS_DASH");
		styleP.AddString(L"PS_DOT");
		styleP.AddString(L"PS_DASHDOT ");
		styleP.AddString(L"PS_DASHDOTDOT");
		styleP.AddString(L"PS_INSIDEFRAME");
		styleP.AddString(L"PS_SOLID");
		styleP.AddString(L"PS_NULL");
		
		
		styleB.SetCurSel(SB);
		styleP.SetCurSel(SP);
		
		opened = true;
	}
}


BEGIN_MESSAGE_MAP(PaletteDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &PaletteDlg::OnSelchangeSB)
	ON_CBN_SELCHANGE(IDC_COMBO2, &PaletteDlg::OnSelchangeSP)
	ON_EN_CHANGE(IDC_EDIT1, &PaletteDlg::OnEnChangeSize)
END_MESSAGE_MAP()


// Обработчики сообщений PaletteDlg

void PaletteDlg::SetColor(COLORREF color)
{
	colorB.SetColor(color);
}

COLORREF PaletteDlg::GetColor()
{
	return colorB.GetColor();
}

void PaletteDlg::SetStyleB(int Cstyle)
{
	switch (Cstyle)
	{
	case HS_CROSS: SB = 0; break;
	case HS_DIAGCROSS: SB = 1; break;
	case HS_FDIAGONAL: SB = 2; break;
	case HS_HORIZONTAL: SB = 3; break;
	case HS_VERTICAL: SB = 4; break;
	case HS_API_MAX: SB = 5; break;
	default: SB = 5; break;
	}
}


int PaletteDlg::GetStyleB()
{
	switch (SB)
	{
	case 0: return HS_CROSS;
	case 1: return HS_DIAGCROSS;
	case 2: return HS_FDIAGONAL;
	case 3: return HS_HORIZONTAL;
	case 4: return HS_VERTICAL;
	case 5: return HS_API_MAX;
	default: return HS_API_MAX;
	}
}


void PaletteDlg::SetStyleP(int Cstyle)
{
	switch (Cstyle)
	{
	case PS_DASH: SP = 0; break;
	case PS_DOT: SP = 1; break;
	case PS_DASHDOT: SP = 2; break;
	case PS_DASHDOTDOT: SP = 3; break;
	case PS_INSIDEFRAME: SP = 4; break;
	case PS_SOLID: SP = 5; break;
	case PS_NULL: SP = 6; break;
	default: SP = 0; break;
	}
}


int PaletteDlg::GetStyleP()
{
	switch (SP)
	{
	case 0: return PS_DASH;
	case 1: return PS_DOT;
	case 2: return PS_DASHDOT;
	case 3: return PS_DASHDOTDOT;
	case 4: return PS_INSIDEFRAME;
	case 5: return PS_SOLID;
	case 6: return PS_NULL;
	default: return PS_DASH;
	}
}


void PaletteDlg::SetSize(int Csize)
{
	size.Format(L"%d", Csize);
}

int PaletteDlg::GetSize()
{
	return _ttoi(size);
}

void PaletteDlg::OnSelchangeSB()
{
	// TODO: добавьте свой код обработчика уведомлений
	SB = styleB.GetCurSel();
}


void PaletteDlg::OnSelchangeSP()
{
	// TODO: добавьте свой код обработчика уведомлений
	SP = styleP.GetCurSel();
}


void PaletteDlg::OnEnChangeSize()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления

	UpdateData(true);

	if (size.GetLength() > 3) {
		size = L"999";
	}

	UpdateData(false);
}
