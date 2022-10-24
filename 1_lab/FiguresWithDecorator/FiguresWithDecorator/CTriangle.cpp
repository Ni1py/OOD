#include "CTriangle.h"

const string triangle = "TRIANGLE: ";

CTriangle::CTriangle(unique_ptr<sf::ConvexShape>&& triangle)
	:m_triangle(move(triangle)) {}

float CTriangle::GetVectorLength(sf::Vector2f point1, sf::Vector2f point2) const {
	return sqrt((point2.x - point1.x) * (point2.x - point1.x) + (point2.y - point1.y) * (point2.y - point1.y));
}

float CTriangle::GetPerimeter() const {
	return GetVectorLength(m_triangle->getPoint(0), m_triangle->getPoint(1))
		+ GetVectorLength(m_triangle->getPoint(0), m_triangle->getPoint(2))
		+ GetVectorLength(m_triangle->getPoint(1), m_triangle->getPoint(2));
}

float CTriangle::GetSquare() const {
	float sideLength1 = GetVectorLength(m_triangle->getPoint(0), m_triangle->getPoint(1));
	float sideLength2 = GetVectorLength(m_triangle->getPoint(0), m_triangle->getPoint(2));
	float sideLength3 = GetVectorLength(m_triangle->getPoint(1), m_triangle->getPoint(2));
	float semiPerimeter = GetPerimeter() / 2;
	return sqrt(semiPerimeter * (semiPerimeter - sideLength1)
		* (semiPerimeter - sideLength2) * (semiPerimeter - sideLength3));
}

string CTriangle::GetDescription() const {
	return triangle + "P=" + std::to_string(GetPerimeter()) + "; S=" + std::to_string(round(GetSquare()));
}