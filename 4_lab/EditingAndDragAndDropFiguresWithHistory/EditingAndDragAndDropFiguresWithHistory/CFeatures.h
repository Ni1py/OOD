#pragma once

#include <vector>
#include "CFigureMovementDecorator.h"

class CFeatures {
public:
	/*static vector<CFigureMovementDecorator*> GetNewFiguresWithSelect(vector<CFigureMovementDecorator*> figures, vector<CFigureMovementDecorator*> selectedFigures);
	static vector<CFigureMovementDecorator*> GetNewSelectedFigures(vector<CFigureMovementDecorator*> selectedFigures);*/
	static vector<CFigureMovementDecorator*> GetNewFigures(vector<CFigureMovementDecorator*> figures);
};
