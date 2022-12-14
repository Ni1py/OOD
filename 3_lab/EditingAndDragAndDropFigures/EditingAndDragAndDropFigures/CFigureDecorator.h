#pragma once
#include "CFigureMovementDecorator.h"
using namespace std;
using namespace sf;

class CFigureDecorator : public CFigureMovementDecorator {
public:
	void SetPosition(float x, float y) const override;
	void SetFillColor(Color color) const override;
	void SetOutlineColor(Color color) const override;
	void SetOutlineThickness(float thickness) const override;
	void Draw(RenderWindow& window) const override;

	FloatRect GetGlobalBounds() const override;
	Vector2f GetPosition() const override;
protected:
	Shape* m_shape;

	CFigureDecorator(Shape* shape);
};