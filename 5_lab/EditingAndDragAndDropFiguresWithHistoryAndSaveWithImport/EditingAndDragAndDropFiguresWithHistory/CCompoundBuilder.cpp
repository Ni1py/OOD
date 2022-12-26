#include "CCompoundBuilder.h"

CCompoundBuilder::CCompoundBuilder(vector<CFigureMovementDecorator*> figures)
	:m_figures(figures)
{}

void CCompoundBuilder::SetShape() {
	auto compoundFigure = new CFigureCompound();
	for (auto figure : m_figures)
		compoundFigure->Add(figure);
	m_figure = compoundFigure;
}


