#pragma once

#include "CFigureMovementDecorator.h"
#include "CCircleDecorator.h"
#include "CRectangleDecorator.h"
#include "CTriangleDecorator.h"
#include "CFigureCompound.h"
#include "CConstants.h"
#include <sstream>
#include <fstream>

class CSaveFileStrategy {
public:
	virtual void Save(string filename, vector<CFigureMovementDecorator*> figures) = 0;
protected:
	void WriteFiguresInfo(ostream& output, vector<CFigureMovementDecorator*> figures);
	string GetCircleInfo(CCircleDecorator* circleDecorator);
	string GetRectangleInfo(CRectangleDecorator* rectangleDecorator);
	string GetTriangleInfo(CTriangleDecorator* triangleDecorator);
};
