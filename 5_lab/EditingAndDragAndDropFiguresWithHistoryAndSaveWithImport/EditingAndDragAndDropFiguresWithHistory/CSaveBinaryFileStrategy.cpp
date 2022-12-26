#include "CSaveBinaryFileStrategy.h"

void CSaveBinaryFileStrategy::Save(string filename, vector<CFigureMovementDecorator*> figures) {
	stringstream stream;
	WriteFiguresInfo(stream, figures);
	ofstream output(filename + ".bin", ios::out | ios::binary);
	output << stream.str().c_str();
	output.close();
}
