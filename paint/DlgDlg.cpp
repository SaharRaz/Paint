// DlgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Dlg.h"
#include "DlgDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDlg dialog

CDlgDlg::CDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgDlg::IDD, pParent)
	, isThin(FALSE)
	, m_Figsbox(0)
	, m_Funcbox(0)
{
	//!!2
	futureFigKIND=RECTANGLE;
	f=NULL;
	isPressed=false;
	dragitem = false;
	Drawfunction=1;
	//!!8
	buttColor=RGB(0,0,0);


	//{{AFX_DATA_INIT(CDlgDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Check(pDX, IDC_CHECK1, isThin);
	DDX_Control(pDX, IDC_CHOICE, m_Choice);
	DDX_Control(pDX, IDB_BITMAP1, m_Picture);
	DDX_Text(pDX, IDC_MFCCOLORBUTTON1, buttColor);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, ConColorbutt);
	DDX_Radio(pDX, IDC_RADIO1, m_Figsbox);
	DDX_Radio(pDX, IDC_RADIO4, m_Funcbox);
}

BEGIN_MESSAGE_MAP(CDlgDlg, CDialog)
	//{{AFX_MSG_MAP(CDlgDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO1, &CDlgDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CDlgDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CDlgDlg::OnBnClickedRadio3)
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_CHECK1, &CDlgDlg::OnBnClickedCheck1)
	ON_STN_CLICKED(IDB_BITMAP1, &CDlgDlg::OnStnClickedBitmap1)
	ON_CBN_SELCHANGE(IDC_CHOICE, &CDlgDlg::OnCbnSelchangeChoice)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &CDlgDlg::OnClickedMfccolorbutton1)
	ON_BN_CLICKED(IDC_RADIO4, &CDlgDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, &CDlgDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CDlgDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_BUTTON4, &CDlgDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlgDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_RADIO7, &CDlgDlg::OnBnClickedRadio7)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDlg message handlers

BOOL CDlgDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

    
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	//!!2
	CheckRadioButton(IDC_RADIO1,IDC_RADIO3,IDC_RADIO1);
	// TODO: Add extra initialization here
	
	m_Choice.SetCurSel(0);

	Bmp1.LoadBitmap(IDB_BITMAP1);
	Bmp2.LoadBitmap(IDB_BITMAP2);
	Bmp3.LoadBitmap(IDB_BITMAP3);
	Bmp4.LoadBitmap(IDB_BITMAP4);
	
	bitmap = IDB_BITMAP1;

	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDlgDlg::OnPaint() 
{
    //Invalidate();
	InvalidateRect(CRect(205, 50, 896, 504));
	CRect rect;
    GetClientRect (&rect);

    CFont font;
    font.CreatePointFont (500, _T ("Arial"));


	CPaintDC dc (this);
	
	SetTextColor(dc, RGB(216, 27, 27));
	SetBkMode(dc, TRANSPARENT);
	CBitmap bmp;
    bmp.LoadBitmap(bitmap);
 
     CBrush brush(&bmp), myBrush,*oldBrush;
     dc.FillRect(CRect(205, 50, 896, 504), &brush);

	for(int i=0;i<figs.GetSize();i++)
		figs[i]->Draw(&dc);

    //if creation
	if(isPressed)
	{
		dc.MoveTo(startP.x,startP.y);
		dc.LineTo(startP.x,endP.y);
		dc.LineTo(endP.x,endP.y);
		dc.LineTo(endP.x,startP.y);
		dc.LineTo(startP.x,startP.y);
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDlgDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDlgDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	endP=startP=point;
	if(point.x>=205 && point.y>=50 && point.x<=896 && point.y<=504) //CRect(205, 50, 896, 504)
	{
		
		switch(Drawfunction)
		{
			case 1: //draw
				isPressed=true;
				break;
			case 2: //fill
				for(int i=0;i<figs.GetSize();i++)
				{
					if(point.x>=figs[i]->x1 && point.y>=figs[i]->y1 && point.x<=figs[i]->x2 && point.y<=figs[i]->y2)
					{
						figs[i]->figColor = buttColor;
						InvalidateRect(CRect(figs[i]->x1, figs[i]->y1, figs[i]->x2, figs[i]->y2)); 
					}
				}
				break;
			case 3: //drag
				for(int i=0;i<figs.GetSize();i++)
				{
					if(point.x>=figs[i]->x1 && point.y>=figs[i]->y1 && point.x<=figs[i]->x2 && point.y<=figs[i]->y2)
					{
						dragedfig=i;
						dragitem=true;
						x2drag = (figs[i]->x2) - (figs[i]->x1);
						y2drag = (figs[i]->y2) - (figs[i]->y1);
					}
				}	
				break;
			case 4: //copy
				for(int i=0;i<figs.GetSize();i++)
				{
					if(point.x>=figs[i]->x1 && point.y>=figs[i]->y1 && point.x<=figs[i]->x2 && point.y<=figs[i]->y2)
					{
						copyfig = figs[i]->KIND;
						x2drag = (figs[i]->x2) - (figs[i]->x1);
						y2drag = (figs[i]->y2) - (figs[i]->y1);
					}
				}	
				break;
		}
	}

	CDialog::OnLButtonDown(nFlags, point);
}

void CDlgDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	
	if(point.x>=205 && point.y>=50 && point.x<=896 && point.y<=504) //CRect(205, 50, 896, 504)
	{
		
		switch(Drawfunction)
		{
			case 1: //draw
				if(isPressed)
				{

					endP=point;
					isPressed=false;

					switch(futureFigKIND)
					{
					case RECTANGLE:
						figs.Add(new RectangleM(startP.x,startP.y,endP.x,endP.y, buttColor));
						break;
					case ELLIPSE:
						figs.Add(new EllipseM(startP.x,startP.y,endP.x,endP.y, buttColor));
						break;
					case LINE:
						figs.Add(new LineM(startP.x,startP.y,endP.x,endP.y, buttColor));
						break;
					}
					InvalidateRect(CRect(205, 50, 896, 504)); 
				}
				break;
			case 2: //fill
				break;
			case 3: //drag
				if(dragitem==true)
				{
					dragitem=false;
					figs[dragedfig]->x1 = point.x;
					figs[dragedfig]->y1 = point.y;
					figs[dragedfig]->x2 = point.x + x2drag;
					figs[dragedfig]->y2 = point.y + y2drag;
					InvalidateRect(CRect(205, 50, 896, 504));
					//InvalidateRect(CRect(point.x, point.y, point.x + x2drag, point.y + y2drag));
				}
				break;
		}
	}
	
	
	
	

	
	CDialog::OnLButtonUp(nFlags, point);
}

void CDlgDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if(point.x>=205 && point.y>=50 && point.x<=896 && point.y<=504) //CRect(205, 50, 896, 504)
	{
		
		switch(Drawfunction)
		{
			case 1: //draw
				 if(isPressed)
				{
					CClientDC dc(this);
					CBrush myBrush,*oldBrush;
					myBrush.CreateSolidBrush(buttColor);
					oldBrush=dc.SelectObject( &myBrush );               
					CPen myPen1(PS_SOLID, isThin?1:3, buttColor);
					CPen *oldPen;
					oldPen=dc.SelectObject( &myPen1 ); 
					//dc.SetROP2(R2_NOTXORPEN);  
  
					switch(futureFigKIND)
					{
					case RECTANGLE:
						dc.Rectangle(startP.x, startP.y,endP.x, endP.y);
						endP=point;
						dc.Rectangle(startP.x, startP.y,endP.x, endP.y);
						break;
					case ELLIPSE:
						dc.Ellipse(startP.x, startP.y,endP.x, endP.y);
						endP=point;
						dc.Ellipse(startP.x, startP.y,endP.x, endP.y);
						break;
					case LINE: 
						endP=point;
  						dc. MoveTo(startP);
						dc.LineTo(endP.x, endP.y);
						break;
					}
					dc.SelectObject( oldPen ); 
					dc.SetROP2(R2_COPYPEN);  
					dc.SelectObject( oldBrush ); 
				}
				break;

			case 2: //fill
				break;
			case 3: //drag
				if(dragitem == true)
				{
					figs[dragedfig]->x1 = point.x;
					figs[dragedfig]->y1 = point.y;
					figs[dragedfig]->x2 = point.x + x2drag;
					figs[dragedfig]->y2 = point.y + y2drag;
					//Invalidate();
					//InvalidateRect(CRect(205, 50, 896, 504));
					//InvalidateRect(CRect(point.x, point.y, point.x + x2drag, point.y + y2drag));
				}
				break;
		}
	}


	CDialog::OnMouseMove(nFlags, point);
}


void CDlgDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CFile file(_T("File.$$"), CFile::modeWrite);
	CArchive ar (&file, CArchive::store);
	figs.Serialize(ar);
	ar.Close();
	file.Close();
}

void CDlgDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CFile file(_T("File.$$"), CFile::modeRead);
	CArchive ar (&file, CArchive::load);
	figs.Serialize(ar);
	ar.Close();
	file.Close();
	Invalidate();
}
void CDlgDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
    futureFigKIND=RECTANGLE;
}

void CDlgDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	futureFigKIND=ELLIPSE;
}

void CDlgDlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	futureFigKIND=LINE;
}



void CDlgDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	if(Drawfunction==4)
	{
		switch(copyfig)
		{
		case 0:
			figs.Add(new RectangleM(point.x, point.y, point.x + x2drag, point.y + y2drag, buttColor));
			break;

		case 1:
			figs.Add(new EllipseM(point.x, point.y, point.x + x2drag, point.y + y2drag, buttColor));
			break;

		case 2:
			figs.Add(new LineM(point.x, point.y, point.x + x2drag, point.y + y2drag, buttColor));
			break;
		}
			

		InvalidateRect(CRect(205, 50, 896, 504));
	}

	CDialog::OnRButtonDown(nFlags, point);
}

void CDlgDlg::OnBnClickedCheck1()
{
	UpdateData(true);
	// TODO: Add your control notification handler code here
}


void CDlgDlg::OnStnClickedBitmap1()
{
	// TODO: Add your control notification handler code here
}





void CDlgDlg::OnCbnSelchangeChoice()
{


	int CurSel = m_Choice.GetCurSel();
	CBitmap bmp;
	// Change the bitmap according to the selection
	switch( CurSel )
	{
	case 0:
		//m_Picture.SetBitmap(Bmp1);
		bitmap = IDB_BITMAP1;
		Invalidate();
		break;
	case 1:
		//m_Picture.SetBitmap(Bmp2);
		bitmap = IDB_BITMAP2;
		Invalidate();
		break;
	case 2:
		//m_Picture.SetBitmap(Bmp3);
		bitmap = IDB_BITMAP3;
		Invalidate();
		break;
	case 3:
		//m_Picture.SetBitmap(Bmp4);
		bitmap = IDB_BITMAP4;
		Invalidate();
		break;
	}
}



void CDlgDlg::OnClickedMfccolorbutton1()
{
	buttColor = ConColorbutt.GetColor();
}



void CDlgDlg::OnBnClickedRadio4()
{
	// TODO: Add your control notification handler code here
	Drawfunction = 1; // draw
}


void CDlgDlg::OnBnClickedRadio5()
{
	Drawfunction = 2; // fill
}


void CDlgDlg::OnBnClickedRadio6()
{
	Drawfunction = 3; //drag
}


void CDlgDlg::OnBnClickedButton4() //undo
{
	if(figs.GetSize()>0)
	{
		Redofigs.Add(figs[figs.GetSize()-1]);
		figs.RemoveAt(figs.GetSize()-1,1);
		InvalidateRect(CRect(205, 50, 896, 504));
	}
	
}


void CDlgDlg::OnBnClickedButton3() //redo
{
	if(Redofigs.GetSize()>0)
	{
		figs.Add(Redofigs[Redofigs.GetSize()-1]);
		Redofigs.RemoveAt(Redofigs.GetSize()-1,1);
		InvalidateRect(CRect(205, 50, 896, 504));
	}
}


void CDlgDlg::OnBnClickedRadio7() //copy
{
	Drawfunction = 4; //copy
}
