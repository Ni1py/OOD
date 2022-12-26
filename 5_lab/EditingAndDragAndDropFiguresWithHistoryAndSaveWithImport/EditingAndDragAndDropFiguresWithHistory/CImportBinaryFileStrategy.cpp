#include "CImportBinaryFileStrategy.h"

CFiguresMemento CImportBinaryFileStrategy::Import(string filename) {
	fstream input(filename + ".bin", ios::in | ios::out | ios::binary);
	char ch[1];
	string str = "";
	while (input.read(ch, 1))
		str += ch[0];

	stringstream stream(str);

	return CFiguresMemento(GetFiguresFromFile(stream), {});
}
