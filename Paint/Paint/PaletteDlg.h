#pragma once


// Диалоговое окно PaletteDlg

class PaletteDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PaletteDlg)

public:
	PaletteDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~PaletteDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PaletteDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	bool opened = false;

	CMFCColorButton colorB;
	CString size;
	CComboBox styleB;
	CComboBox styleP;

	int SB, SP;

	void SetColor(COLORREF color);
	COLORREF GetColor();
	void SetStyleB(int style);
	int GetStyleB();
	void SetStyleP(int style);
	int GetStyleP();
	void SetSize(int size);
	int GetSize();
	afx_msg void OnSelchangeSB();
	afx_msg void OnSelchangeSP();
	afx_msg void OnEnChangeSize();
};
