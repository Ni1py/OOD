#include "CCircle.h"
#define _USE_MATH_DEFINES
#include <math.h>

const string circle = "CIRCLE: ";

CCircle::CCircle(unique_ptr<sf::CircleShape>&& circle)
	:m_circle(move(circle)) {}

float CCircle::GetPerimeter() const {
	auto radius = m_circle->getRadius();
	return 2 * M_PI * radius;
}

float CCircle::GetSquare() const {
	auto radius = m_circle->getRadius();
	return M_PI * radius * radius;
}

string CCircle::GetDescription() const {
	return circle + " P=" + std::to_string(GetPerimeter()) + "; S=" + std::to_string(round(GetSquare()));
}