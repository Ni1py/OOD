#pragma once

#include "CFigureMovementDecorator.h"
#include <vector>

class CFiguresMemento {
public:
	CFiguresMemento(
		vector<CFigureMovementDecorator*> figures,
		vector<CFigureMovementDecorator*> selectedFigures
	);
	vector<CFigureMovementDecorator*> GetFigures() const;
	vector<CFigureMovementDecorator*> GetSelectedFigures() const;
private:
	vector<CFigureMovementDecorator*> m_figures;
	vector<CFigureMovementDecorator*> m_selectedFigures;
};
