#pragma once
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <math.h>
using namespace std;

class CFigureDecorator {
public:
	virtual string GetDescription() const = 0;
protected:
	virtual float GetPerimeter() const = 0;
	virtual float GetSquare() const = 0;
};