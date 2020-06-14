#include "stdafx.h"
#include "Figure.h"

IMPLEMENT_SERIAL (Figure, CObject, 1)
IMPLEMENT_SERIAL (RectangleM, CObject, 1)
IMPLEMENT_SERIAL (EllipseM, CObject, 1)
IMPLEMENT_SERIAL (LineM, CObject, 1)

Figure::Figure(void)
{
}

Figure::~Figure(void)
{
}

RectangleM::RectangleM(){}

EllipseM::EllipseM(){}

LineM::LineM(){}