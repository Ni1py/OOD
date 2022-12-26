#include "CFiguresMemento.h"

CFiguresMemento::CFiguresMemento(
	vector<CFigureMovementDecorator*> figures,
	vector<CFigureMovementDecorator*> selectedFigures
) :m_figures(figures), m_selectedFigures(selectedFigures) {};

vector<CFigureMovementDecorator*> CFiguresMemento::GetFigures() const {
	return m_figures;
}

vector<CFigureMovementDecorator*> CFiguresMemento::GetSelectedFigures() const {
	return m_selectedFigures;
}
