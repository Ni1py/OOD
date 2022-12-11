#pragma once
#include "CFigureDecorator.h"

class CCircleDecorator : public CFigureDecorator {
public:
	CCircleDecorator(CircleShape* circle);
	string GetDescription() const override;
	void SetRadius(float r) const;

	float GetPerimeter() const override;
	float GetSquare() const override;
private:
	CircleShape* m_circle;
};