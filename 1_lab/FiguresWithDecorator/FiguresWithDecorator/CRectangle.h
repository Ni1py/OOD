#pragma once
#include "CFigureDecorator.h";

class CRectangle : public CFigureDecorator {
public:
	CRectangle(unique_ptr<sf::RectangleShape>&& rectangle);
	string GetDescription() const override;
private:
	unique_ptr<sf::RectangleShape> m_rectangle;

	float GetPerimeter() const override;
	float GetSquare() const override;
};