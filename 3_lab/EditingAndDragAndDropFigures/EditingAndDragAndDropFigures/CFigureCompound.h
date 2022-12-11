#pragma once
#include "CFigureMovementDecorator.h"
using namespace std;
using namespace sf;

const string groupedFigure = "Grouped shape:";

class CFigureCompound: public CFigureMovementDecorator {
public:
	void Add(CFigureMovementDecorator* figure);
	void SetPosition(float x, float y) const override;
	void SetFillColor(Color color) const override;
	void SetOutlineColor(Color color) const override;
	void SetOutlineThickness(float thickness) const override;
	void Draw(RenderWindow& window) const override;

	string GetDescription() const override;
	FloatRect GetGlobalBounds() const override;
	Vector2f GetPosition() const override;
	vector<CFigureMovementDecorator*> GetFigures() const;
	float GetPerimeter() const override;
	float GetSquare() const override;
private:
	vector<CFigureMovementDecorator*> m_figures;
};