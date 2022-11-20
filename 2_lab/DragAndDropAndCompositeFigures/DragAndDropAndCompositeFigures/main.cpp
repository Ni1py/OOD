#include "CCircleDecorator.h"
#include "CRectangleDecorator.h"
#include "CTriangleDecorator.h"
#include <fstream>
#include <iostream>
#include <vector>
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

	RenderWindow window(sf::VideoMode(800, 600), "Visualization of shapes");
	window.setVerticalSyncEnabled(true);

	vector<CFigureDecorator*> shapes;

	while (input >> figure) {
		if (figure == circle) {
			float x, y, r;
			input >> x >> y >> r;
			CCircleDecorator* circleDecorator = new CCircleDecorator(new CircleShape());
			circleDecorator->SetRadius(r);
			circleDecorator->SetPosition(x, y);
			circleDecorator->SetFillColor(Color::Blue);
			//circleDecorator->Draw(window);
			shapes.push_back(circleDecorator);
			output << circleDecorator->GetDescription() << endl;
		}

		if (figure == rectangle) {
			float x1, y1, x2, y2;
			input >> x1 >> y1 >> x2 >> y2;
			CRectangleDecorator* rectangleDecorator = new CRectangleDecorator(new RectangleShape());
			rectangleDecorator->SetSize(Vector2f(x2 - x1, y2 - y1));
			rectangleDecorator->SetPosition((x2 - x1) / 2, (y2 - y1) / 2);
			rectangleDecorator->SetFillColor(Color::Cyan);
			//rectangleDecorator->Draw(window);
			shapes.push_back(rectangleDecorator);
			output << rectangleDecorator->GetDescription() << endl;
		}

		if (figure == triangle) {
			sf::Vector2f point1, point2, point3;
			input >> point1.x >> point1.y >> point2.x >> point2.y >> point3.x >> point3.y;
			CTriangleDecorator* triangleDecorator = new CTriangleDecorator(new ConvexShape());
			triangleDecorator->SetPointCount(3);
			triangleDecorator->SetPoint(0, point1);
			triangleDecorator->SetPoint(1, point2);
			triangleDecorator->SetPoint(2, point3);
			triangleDecorator->SetPosition((point1.x + point2.x + point3.x) / 3, (point1.y + point2.y + point3.y) / 3);
			triangleDecorator->SetFillColor(Color::Red);
			//triangleDecorator->Draw(window);
			shapes.push_back(move(triangleDecorator));
			output << triangleDecorator->GetDescription() << endl;
		}
	}

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		for (size_t i = 0; i < shapes.size(); i++)
		{
			shapes[i]->Draw(window);
		}
		window.display();
	}

	input.close();
	output.close();

	return 0;
}