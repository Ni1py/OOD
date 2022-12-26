#pragma once

#include "CBuilder.h"
#include "CFigureCompound.h"

class CCompoundBuilder : public CBuider {
public:
	CCompoundBuilder(vector<CFigureMovementDecorator*> figures);
	void SetShape() override;
	void SetPosition() override {};
	void SetFillColor() override {};
	void SetOutlineColor() override {};
	void SetOutlineThickness() override {};
private:
	vector<CFigureMovementDecorator*> m_figures;
};
