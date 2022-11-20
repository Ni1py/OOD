#include "CFigureDecorator.h"

CFigureDecorator::CFigureDecorator(Shape* shape)
	:m_shape(shape) {}

void CFigureDecorator::SetFillColor(Color color)
{
	m_shape->setFillColor(color);
}

void CFigureDecorator::SetPosition(float x, float y)
{
	m_shape->setPosition(x, y);
}

void CFigureDecorator::Draw(RenderWindow& window)
{
	window.draw(*m_shape);
}