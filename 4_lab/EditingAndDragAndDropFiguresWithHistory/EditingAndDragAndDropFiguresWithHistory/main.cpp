#include "CApplication.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

const string outputFileName = "output.txt";

int main(int argc, char* argv[])
{
	ifstream input(argv[1]);
	if (!input.is_open()) {
		cout << "errorInput" << endl;
		return 1;
	}
	ofstream output(outputFileName);

	RenderWindow window(sf::VideoMode(1000, 900), "Visualization of shapes");
	window.setVerticalSyncEnabled(true);

	CApplication* application = CApplication::GetInstance(input, output, window);
	application->ReadFigures();

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event))
		{
			application->ProcessAnEvent(event);
		}
	}

	application->PrintFiguresInfo();

	input.close();
	output.close();

	return 0;
}