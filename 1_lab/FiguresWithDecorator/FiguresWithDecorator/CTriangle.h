#include "CFigureDecorator.h"

class CTriangle : public CFigureDecorator {
public:
	CTriangle(unique_ptr<sf::ConvexShape>&& triangle);
	string GetDescription() const override;
private:
	unique_ptr<sf::ConvexShape> m_triangle;

	float GetVectorLength(sf::Vector2f point1, sf::Vector2f point2) const;
	float GetPerimeter() const override;
	float GetSquare() const override;
};
