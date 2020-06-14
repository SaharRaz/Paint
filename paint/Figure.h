#pragma once   

           
class Figure: public CObject 
{
	
	DECLARE_SERIAL (Figure)       
public:
	void Serialize (CArchive& ar)
	{
		CObject::Serialize (ar);
		if (ar.IsStoring ())
		{
			ar << x1;
			ar << x2;
			ar << y1;
			ar << y2;
			ar << figColor;
		}
		else // Loading, not storing
		{
			ar >> x1;
			ar >> x2;
			ar >> y1;
			ar >> y2;
			ar >> figColor;
		}
	}
	
protected:
public:
	int x1,y1,x2,y2,KIND;
	COLORREF figColor;
	Figure();
	Figure(int xx1,int yy1, int xx2, int yy2, COLORREF figsColor)
	{
		x1=xx1;
		x2=xx2;
		y1=yy1;
		y2=yy2;
		figColor = figsColor;
	}
                            
	virtual void Draw(CDC *dc){}
	virtual ~Figure(void);
};

class RectangleM:public Figure{
	
	DECLARE_SERIAL (RectangleM)       
public:
	RectangleM();  
	RectangleM(int xx1,int yy1, int xx2, int yy2, COLORREF figColor)
		:Figure(xx1,yy1,xx2,yy2,figColor)
	{
		KIND=0;
	}
	void Draw(CDC *dc)
	{
		CBrush myBrush,*oldBrush;
		myBrush.CreateSolidBrush(figColor);
		oldBrush=dc->SelectObject( &myBrush );

		dc->Rectangle(x1,y1,x2,y2);
 
		dc->SelectObject( oldBrush ); 
	}
};
class EllipseM:public Figure{
	
	DECLARE_SERIAL (EllipseM)     
	
public:
	EllipseM();  
	EllipseM(int xx1,int yy1, int xx2, int yy2, COLORREF figColor)
		:Figure(xx1,yy1,xx2,yy2,figColor)
	{
		KIND=1;
	}
	void Draw(CDC *dc)
	{
		CBrush myBrush,*oldBrush;
		myBrush.CreateSolidBrush(figColor);
		oldBrush=dc->SelectObject( &myBrush );

		dc->Ellipse(x1,y1,x2,y2);

		dc->SelectObject( oldBrush ); 
	}
};


class LineM:public Figure{
	
	DECLARE_SERIAL (LineM)       
public:
	LineM();  
	LineM(int xx1,int yy1, int xx2, int yy2, COLORREF figColor)
		:Figure(xx1,yy1,xx2,yy2,figColor)
	{
		KIND=2;
	}
	void Draw(CDC *dc)
	{
		CPoint startP(x1,y1), point(x2,y2), endP;
		CPen myPen1(PS_SOLID, 3, figColor);
		CPen *oldPen;
		oldPen=dc->SelectObject( &myPen1 ); 
		//dc->SetROP2(R2_NOTXORPEN);  
		endP=point;
  		dc->MoveTo(startP);
		dc->LineTo(endP.x, endP.y);
		dc->SelectObject( oldPen ); 
	}
};