#include "CToolbar.h"
#include "IState.h"
#include "CDragAndDropCommand.h"
#include "CFillCommand.h"
#include "CFillOutlineCommand.h"
#include "CChangeOutlineThicknessCommand.h"
#include "CCreateCircleFigureCommand.h"
#include "CCreateRectangleFigureCommand.h"
#include "CCreateTriangleFigureCommand.h"
#include "CSetSelectedColorCommand.h"
#include "CSetSelectedThicknessCommand.h"

CToolbar::CToolbar(IState* state, RenderWindow& window, CFiguresHandler* figureHandler) 
	:m_window(window),
	m_figuresHandler(figureHandler),
	m_state(state) 
{
	//кнопки управления состоянием
	m_buttons.push_back(new CButton(Vector2f(10, 10), Vector2f(100, 40), Color::White, new CDragAndDropCommand(this), "Drag&Drop", 20));
	m_buttons.push_back(new CButton(Vector2f(120, 10), Vector2f(50, 40), Color::White, new CFillCommand(this), "Fill", 20));
	m_buttons.push_back(new CButton(Vector2f(180, 10), Vector2f(100, 40), Color::White, new CFillOutlineCommand(this), "Fill outline", 20));
	m_buttons.push_back(new CButton(Vector2f(290, 10), Vector2f(155, 40), Color::White, new CChangeOutlineThicknessCommand(this), "Change thickness", 20));

	//кнопки выбора цвета
	m_buttons.push_back(new CButton(Vector2f(830, 10), Vector2f(40, 40), Color::Cyan, new CSetSelectedColorCommand(this, Color::Cyan)));
	m_buttons.push_back(new CButton(Vector2f(890, 10), Vector2f(40, 40), Color::Magenta, new CSetSelectedColorCommand(this, Color::Magenta)));
	m_buttons.push_back(new CButton(Vector2f(950, 10), Vector2f(40, 40), Color::Yellow, new CSetSelectedColorCommand(this, Color::Yellow)));

	//кнопки выбора толщины
	m_buttons.push_back(new CButton(Vector2f(830, 70), Vector2f(40, 40), Color::White, new CSetSelectedThicknessCommand(this, 1), "1", 20));
	m_buttons.push_back(new CButton(Vector2f(890, 70), Vector2f(40, 40), Color::White, new CSetSelectedThicknessCommand(this, 2), "2", 20));
	m_buttons.push_back(new CButton(Vector2f(950, 70), Vector2f(40, 40), Color::White, new CSetSelectedThicknessCommand(this, 3), "3", 20));

	//кнопка создания круга
	auto circle = new CircleShape(15);
	circle->setPosition(835, 135);
	circle->setOutlineColor(Color::Black);
	circle->setOutlineThickness(2);
	m_buttons.push_back(new CButton(Vector2f(830, 130), Vector2f(40, 40), Color::White, new CCreateCircleFigureCommand(this), "", 0, circle));

	//кнопка создания прямоугольника
	auto rectangle = new RectangleShape();
	rectangle->setPosition(897, 137);
	rectangle->setSize(Vector2f(25, 25));
	rectangle->setOutlineColor(Color::Black);
	rectangle->setOutlineThickness(2);
	m_buttons.push_back(new CButton(Vector2f(890, 130), Vector2f(40, 40), Color::White, new CCreateRectangleFigureCommand(this), "", 0, rectangle));
	
	//кнопка создания треугольника
	auto triangle = new ConvexShape();
	triangle->setPointCount(3);
	triangle->setPoint(0, Vector2f(970, 137));
	triangle->setPoint(1, Vector2f(957, 165));
	triangle->setPoint(2, Vector2f(983, 165));
	triangle->setOutlineColor(Color::Black);
	triangle->setOutlineThickness(2);
	m_buttons.push_back(new CButton(Vector2f(950, 130), Vector2f(40, 40), Color::White, new CCreateTriangleFigureCommand(this), "", 0, triangle));
}

void CToolbar::DragAndDrop() {
	m_state->DragAndDrop(this);
}

void CToolbar::Fill() {
	m_state->Fill(this);
}

void CToolbar::FillOutline() {
	m_state->FillOutline(this);
}

void CToolbar::ChangeOutlineThickness() {
	m_state->ChangeOutlineThickness(this);
}

void CToolbar::Draw() {
	for (auto button : m_buttons) {
		button->Draw(m_window);
	}
}

void CToolbar::SetState(IState* state) {
	m_state = state;
}

void CToolbar::SetSelectedColor(Color color) {
	m_selectedColor = color;
}

void CToolbar::SetSelectedThickness(float thickness) {
	m_selectedThickness = thickness;
}

IState* CToolbar::GetState() const {
	return m_state;
}

Color CToolbar::GetSelectedColor() const {
	return m_selectedColor;
}

float CToolbar::GetSelectedThickness() const {
	return m_selectedThickness;
}

vector<CButton*> CToolbar::GetButtons() const {
	return m_buttons;
}

void CToolbar::SetCursorPosition(Vector2i pos) {
	m_cursorPosition = pos;
}

bool CToolbar::PressToolButton() const {
	for (auto button : m_buttons) {
		if (button->CursorInButton(static_cast<Vector2f>(m_cursorPosition))) {
			button->PressButton();
			return true;
		}
	}

	return false;
}
