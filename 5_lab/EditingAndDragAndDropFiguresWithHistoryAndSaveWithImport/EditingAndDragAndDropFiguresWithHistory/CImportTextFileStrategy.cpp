#include "CImportTextFileStrategy.h"

CFiguresMemento CImportTextFileStrategy::Import(string filename) {
	ifstream input(filename + ".txt");

	return CFiguresMemento(GetFiguresFromFile(input), {});
}
