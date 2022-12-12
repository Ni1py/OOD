#pragma once

#include <SFML/Graphics.hpp>
#include "CFiguresHandler.h"
#include "CToolbar.h"
#include "CDragAndDropState.h"
#include "CFillVisitor.h"
#include "CFillOutlineVisitor.h"
#include "CChangeOutlineThicknessVisitor.h"

using namespace std;
using namespace sf;

class CApplication {
public:
	static CApplication* GetInstance(istream& input, ostream& output, RenderWindow& window);
	
	void ReadFigures();
	void ProcessAnEvent(Event event);
	void PrintFiguresInfo();

private:
	CApplication(istream& input, ostream& output, RenderWindow& window);

	void Render();
	void DrawApplication();

	static CApplication* m_instance;
	istream& m_input;
	ostream& m_output;
	RenderWindow& m_window;

	CFiguresHandler* m_figuresHandler;
	CToolbar* m_toolbar;
};
