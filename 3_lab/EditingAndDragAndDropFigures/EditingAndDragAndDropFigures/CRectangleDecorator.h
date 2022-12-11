#pragma once
#include "CFigureDecorator.h";

class CRectangleDecorator : public CFigureDecorator {
public:
	CRectangleDecorator(RectangleShape* rectangle);
	string GetDescription() const override;
	void SetSize(Vector2f size) const;

	float GetPerimeter() const override;
	float GetSquare() const override;
private:
	RectangleShape* m_rectangle;
};