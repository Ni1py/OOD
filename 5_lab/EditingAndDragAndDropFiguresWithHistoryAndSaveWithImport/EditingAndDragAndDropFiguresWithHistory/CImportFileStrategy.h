#pragma once

#include "CFiguresMemento.h"
#include "CFiguresCreator.h"
#include "CConstants.h"
#include "CCircleBuilder.h"
#include "CRectangleBuilder.h"
#include "CCompoundBuilder.h"
#include "CTriangleBuilder.h"
#include <sstream>
#include <fstream>

class CImportFileStrategy {
public:
	virtual CFiguresMemento Import(string filename) = 0;
protected:
	vector<CFigureMovementDecorator*> GetFiguresFromFile(istream& input);
};
