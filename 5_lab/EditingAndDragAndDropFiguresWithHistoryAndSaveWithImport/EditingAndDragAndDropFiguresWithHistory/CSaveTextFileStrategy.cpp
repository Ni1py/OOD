#include "CSaveTextFileStrategy.h"

void CSaveTextFileStrategy::Save(string filename, vector<CFigureMovementDecorator*> figures) {
	ofstream output(filename + ".txt");
	WriteFiguresInfo(output, figures);
	output.close();
}
