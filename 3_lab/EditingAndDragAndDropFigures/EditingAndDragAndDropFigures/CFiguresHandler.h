#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "CFigureMovementDecorator.h"
#include "CCircleDecorator.h"
#include "CRectangleDecorator.h"
#include "CTriangleDecorator.h"
#include "CFigureCompound.h"
#include <sstream>

const string triangle = "TRIANGLE";
const string circle = "CIRCLE";
const string rectangle = "RECTANGLE";

const float defaultX = 500;
const float defaultY = 400;

class CFiguresHandler {
public:
	CFiguresHandler(RenderWindow& window);
	void CreatingFigures(stringstream& ss);
	void CreateCircleFigure();
	void CreateRectangleFigure();
	void CreateTriangleFigure();

	void SelectFigures();
	void SelectFigure();
	void UnselectFigure();
	void UnselectFigures();
	void ChangeFigureColor(Color color);
	void ChangeFigureOutlineColor(Color color);
	void ChangeOutlineThickness(float thichness);

	void MoveFigure();
	void ResetTheIndexMovableFigure();

	void GroupFigures();
	void UngroupFigures();

	void SetCursorPosition(Vector2i pos);
	void SetDx(float dX);
	void SetDy(float dY);

	void Draw();
	vector<CFigureMovementDecorator*> GetFigures() const;
private:
	vector<CFigureMovementDecorator*> m_figures;
	vector<CFigureMovementDecorator*> m_selectedFigures;
	int m_indexMovableFigure = -1;
	Vector2i m_cursorPosition;
	float m_dX = 0;
	float m_dY = 0;
	RenderWindow& m_window;
};