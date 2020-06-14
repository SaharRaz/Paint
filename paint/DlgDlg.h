// DlgDlg.h : header file
//

#if !defined(AFX_DLGDLG_H__D02F91E6_1066_4AA4_AE0B_1D16C986AE2C__INCLUDED_)
#define AFX_DLGDLG_H__D02F91E6_1066_4AA4_AE0B_1D16C986AE2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDlgDlg dialog
// added s
#include <vector>
#include "Figure.h"
#include "afxwin.h"
#include "afxcolorbutton.h"
using namespace std;
// added e
class CDlgDlg : public CDialog
{
	enum FIGURES{RECTANGLE,ELLIPSE,LINE};
	FIGURES futureFigKIND;
    COLORREF curColor;

	Figure *f;
	//!!6 b
	//vector <Figure *> figs;
	CTypedPtrArray< CObArray, Figure*> figs, Redofigs, Undofigs;


	bool isPressed;
	int Drawfunction;
	bool dragitem;
	int dragedfig, x2drag, y2drag, copyfig;
	int bitmap;
	CPoint startP;
	CPoint endP;

public:
	CDlgDlg(CWnd* pParent = NULL);	// standard constructor
	
// Dialog Data
	//{{AFX_DATA(CDlgDlg)
	enum { IDD = IDD_DLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDlgDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	BOOL isThin;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnStnClickedBitmap1();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeChoice();
	afx_msg void OnBnClickedMfccolorbutton1();
	private:
		CBitmap Bmp1, Bmp2, Bmp3, Bmp4;
		
public:
	CComboBox m_Choice;
	CStatic m_Picture;
	COLORREF buttColor;
	CMFCColorButton ConColorbutt;
	afx_msg void OnClickedMfccolorbutton1();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
	int m_Figsbox;
	int m_Funcbox;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedRadio7();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGDLG_H__D02F91E6_1066_4AA4_AE0B_1D16C986AE2C__INCLUDED_)
