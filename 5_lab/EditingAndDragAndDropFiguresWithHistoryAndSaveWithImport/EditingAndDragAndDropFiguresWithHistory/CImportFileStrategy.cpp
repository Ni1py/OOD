#include "CImportFileStrategy.h"

vector<CFigureMovementDecorator*> CImportFileStrategy::GetFiguresFromFile(istream& input) {
	auto creator = CFiguresCreator();
	vector<unsigned int> characteristics;
	vector<CFigureMovementDecorator*> figures;
	string line, lineCharact, type;

	while ((input >> type) && getline(input, line)) {
		stringstream ss(line);
		while (ss >> lineCharact)
			characteristics.push_back(stoul(lineCharact));

		if (type == circle)
			creator.SetBuider(new CCircleBuilder(characteristics));
		else if (type == rectangle)
			creator.SetBuider(new CRectangleBuilder(characteristics));
		else if (type == triangle)
			creator.SetBuider(new CTriangleBuilder(characteristics));
		else if (type == grouped)
			creator.SetBuider(new CCompoundBuilder(GetFiguresFromFile(input)));
		else if (type == endGrouped)
			return figures;
		characteristics.clear();
		figures.push_back(creator.CreateAndGetFigure());
	}

	return figures;
}
