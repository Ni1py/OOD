#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include <fstream>
#include <iostream>
using namespace std;

const string triangle = "TRIANGLE";
const string circle = "CIRCLE";
const string rectangle = "RECTANGLE";
const string outputFileName = "output.txt";

int main(int argc, char* argv[])
{
	ifstream input(argv[1]);
	if (!input.is_open()) {
		cout << "errorInput" << endl;
		return 1;
	}
	ofstream output(outputFileName);
	string figure;

	sf::RenderWindow window(sf::VideoMode(800, 600), "Visualization of shapes");
	window.setVerticalSyncEnabled(true);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		while (input >> figure) {
			if (figure == circle) {
				float x, y, r;
				input >> x >> y >> r;
				auto circleShape = make_unique<sf::CircleShape>(r);
				circleShape->setPosition(x, y);
				circleShape->setFillColor(sf::Color::Blue);
				window.draw(*circleShape);
				auto circleDecorator = make_unique<CCircle>(move(circleShape));
				output << circleDecorator->GetDescription() << endl;
			}

			if (figure == rectangle) {
				float x1, y1, x2, y2;
				input >> x1 >> y1 >> x2 >> y2;
				auto rectangleShape = make_unique<sf::RectangleShape>();
				rectangleShape->setSize(sf::Vector2f(x2 - x1, y2 - y1));
				rectangleShape->setPosition((x2 - x1) / 2, (y2 - y1) / 2);
				rectangleShape->setFillColor(sf::Color::Cyan);
				window.draw(*rectangleShape);
				auto rectangleDecorator = make_unique<CRectangle>(move(rectangleShape));
				output << rectangleDecorator->GetDescription() << endl;
			}

			if (figure == triangle) {
				sf::Vector2f point1, point2, point3;
				input >> point1.x >> point1.y >> point2.x >> point2.y >> point3.x >> point3.y;
				auto triangleShape = make_unique<sf::ConvexShape>();
				triangleShape->setFillColor(sf::Color::Red);
				triangleShape->setPointCount(3);
				triangleShape->setPoint(0, point1);
				triangleShape->setPoint(1, point2);
				triangleShape->setPoint(2, point3);
				triangleShape->setPosition((point1.x + point2.x + point3.x) / 3, (point1.y + point2.y + point3.y) / 3);
				window.draw(*triangleShape);
				auto triangleDecorator = make_unique<CTriangle>(move(triangleShape));
				output << triangleDecorator->GetDescription() << endl;
			}
		}
		window.display();
	}

	input.close();
	output.close();

	return 0;
}