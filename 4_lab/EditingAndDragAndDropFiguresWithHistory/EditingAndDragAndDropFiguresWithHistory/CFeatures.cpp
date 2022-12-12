#include "CFeatures.h"
#include "CCircleDecorator.h"
#include "CRectangleDecorator.h"
#include "CTriangleDecorator.h"
#include "CFigureCompound.h"

//vector<CFigureMovementDecorator*> CFeatures::GetNewFiguresWithSelect(vector<CFigureMovementDecorator*> figures, vector<CFigureMovementDecorator*> selectedFigures) {
//	vector<CFigureMovementDecorator*> newFigures;
//
//	for (auto figure : figures) {
//		vector<CFigureMovementDecorator*>::iterator itShapes = find(selectedFigures.begin(), selectedFigures.end(), figure);
//
//		if (typeid(*figure) == typeid(CCircleDecorator)) {
//			CFigureMovementDecorator* circleDecorator = new CCircleDecorator(*static_cast<CCircleDecorator*>(figure));
//
//			if (itShapes != figures.end()) {
//				circleDecorator->SetMoved(true);
//				newFigures.push_back(circleDecorator);
//			} else 
//				newFigures.push_back(circleDecorator);
//		}
//		else if (typeid(*figure) == typeid(CRectangleDecorator)) {
//			CFigureMovementDecorator* rectangleDecorator = new CRectangleDecorator(*static_cast<CRectangleDecorator*>(figure));
//
//			if (itShapes != figures.end()) {
//				rectangleDecorator->SetMoved(true);
//				newFigures.push_back(rectangleDecorator);
//			}
//			else
//				newFigures.push_back(rectangleDecorator);
//		}
//		else if (typeid(*figure) == typeid(CTriangleDecorator)) {
//			CFigureMovementDecorator* triangleDecorator = new CTriangleDecorator(*static_cast<CTriangleDecorator*>(figure));
//
//			if (itShapes != figures.end()) {
//				triangleDecorator->SetMoved(true);
//				newFigures.push_back(triangleDecorator);
//			}
//			else
//				newFigures.push_back(triangleDecorator);
//		}
//		else if (typeid(*figure) == typeid(CFigureCompound)) {
//			CFigureMovementDecorator* compoundFigure = new CFigureCompound(*static_cast<CFigureCompound*>(figure));
//
//			if (itShapes != figures.end()) {
//				compoundFigure->SetMoved(true);
//				newFigures.push_back(compoundFigure);
//			}
//			else
//				newFigures.push_back(compoundFigure);
//		}
//	}
//
//	return newFigures;
//}
//
//vector<CFigureMovementDecorator*> CFeatures::GetNewSelectedFigures(vector<CFigureMovementDecorator*> selectedFigures) {
//	vector<CFigureMovementDecorator*> newSelectedFigures;
//
//	for (auto figure : selectedFigures) {
//		if (typeid(*figure) == typeid(CCircleDecorator)) {
//			CFigureMovementDecorator* circleDecorator = new CCircleDecorator(*static_cast<CCircleDecorator*>(figure));
//			circleDecorator->SetMoved(true);
//			newSelectedFigures.push_back(circleDecorator);
//		}
//		else if (typeid(*figure) == typeid(CRectangleDecorator)) {
//			CFigureMovementDecorator* rectangleDecorator = new CRectangleDecorator(*static_cast<CRectangleDecorator*>(figure));
//			rectangleDecorator->SetMoved(true);
//			newSelectedFigures.push_back(rectangleDecorator);
//		}
//		else if (typeid(*figure) == typeid(CTriangleDecorator)) {
//			CFigureMovementDecorator* triangleDecorator = new CTriangleDecorator(*static_cast<CTriangleDecorator*>(figure));
//			triangleDecorator->SetMoved(true);
//			newSelectedFigures.push_back(triangleDecorator);
//		}
//		else if (typeid(*figure) == typeid(CFigureCompound)) {
//			CFigureMovementDecorator* compoundFigure = new CFigureCompound(*static_cast<CFigureCompound*>(figure));
//			compoundFigure->SetMoved(true);
//			newSelectedFigures.push_back(compoundFigure);
//		}
//	}
//
//	return newSelectedFigures;
//}

vector<CFigureMovementDecorator*> CFeatures::GetNewFigures(vector<CFigureMovementDecorator*> figures) {
	vector<CFigureMovementDecorator*> newFigures;

	for (auto figure : figures) {
		if (typeid(*figure) == typeid(CCircleDecorator))
			newFigures.push_back(new CCircleDecorator(*static_cast<CCircleDecorator*>(figure)));
		else if (typeid(*figure) == typeid(CRectangleDecorator))
			newFigures.push_back(new CRectangleDecorator(*static_cast<CRectangleDecorator*>(figure)));
		else if (typeid(*figure) == typeid(CTriangleDecorator))
			newFigures.push_back(new CTriangleDecorator(*static_cast<CTriangleDecorator*>(figure)));
		else if (typeid(*figure) == typeid(CFigureCompound))
			newFigures.push_back(new CFigureCompound(*static_cast<CFigureCompound*>(figure)));
	}

	return newFigures;
}
