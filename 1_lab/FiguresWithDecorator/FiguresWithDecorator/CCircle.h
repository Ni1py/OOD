#pragma once
#include "CFigureDecorator.h"

class CCircle : public CFigureDecorator {
public:
	CCircle(unique_ptr<sf::CircleShape>&& circle);
	string GetDescription() const override;
private:
	unique_ptr<sf::CircleShape> m_circle;

	float GetPerimeter() const override;
	float GetSquare() const override;
};