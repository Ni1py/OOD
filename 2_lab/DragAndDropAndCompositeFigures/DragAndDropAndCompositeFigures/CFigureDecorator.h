#pragma once
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <math.h>
using namespace std;
using namespace sf;

class CFigureDecorator {
public:
	virtual string GetDescription() const = 0;
	void SetPosition(float x, float y);
	void SetFillColor(Color color);
	void Draw(RenderWindow& window);
protected:
	Shape* m_shape;

	CFigureDecorator(Shape* shape);
	virtual float GetPerimeter() const = 0;
	virtual float GetSquare() const = 0;
};