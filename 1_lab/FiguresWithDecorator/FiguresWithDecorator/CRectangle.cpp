#include "CRectangle.h";
#include "CFigureDecorator.h";

const string rectangle = "RECTANGLE: ";

CRectangle::CRectangle(unique_ptr<sf::RectangleShape>&& rectangle)
	:m_rectangle(move(rectangle)) {}

float CRectangle::GetPerimeter() const {
	auto size = m_rectangle->getSize();
	return (size.x + size.y) * 2;
}

float CRectangle::GetSquare() const {
	auto size = m_rectangle->getSize();
	return size.x * size.y;
}

string CRectangle::GetDescription() const {
	return rectangle + "P=" + std::to_string(GetPerimeter()) + "; S=" + std::to_string(round(GetSquare()));
}