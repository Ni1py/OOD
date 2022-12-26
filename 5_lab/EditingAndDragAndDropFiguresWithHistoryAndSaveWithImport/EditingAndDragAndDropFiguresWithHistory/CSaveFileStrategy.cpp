#include "CSaveFileStrategy.h"

string CSaveFileStrategy::GetCircleInfo(CCircleDecorator* circleDecorator) {
	auto circleShape = circleDecorator->GetCircle();

	auto position = circleShape->getPosition();
	auto radius = circleShape->getRadius();
	Vector2f center = { position.x + radius, position.y + radius };
	auto outlineThickness = circleShape->getOutlineThickness();
	auto fillColor = circleShape->getFillColor();
	auto outlineColor = circleShape->getOutlineColor();

	stringstream stream;

	stream << circle << " " << center.x << " "
		<< center.y << " " << static_cast<int>(radius) << " "
		<< fillColor.toInteger() << " " << outlineColor.toInteger()
		<< " " << static_cast<int>(outlineThickness) << endl;

	return stream.str();
}

string CSaveFileStrategy::GetRectangleInfo(CRectangleDecorator* rectangleDecorator) {
	auto rectangleShape = rectangleDecorator->GetRectangle();
	auto rectangleBounds = rectangleDecorator->GetGlobalBounds();
	
	auto pointLT = rectangleShape->getPosition();
	auto outlineThickness = rectangleShape->getOutlineThickness();
	Vector2f pointRB = { 
		(pointLT.x + rectangleBounds.width - 2 * outlineThickness), 
		(pointLT.y + rectangleBounds.height - 2 * outlineThickness) };
	auto fillColor = rectangleShape->getFillColor();
	auto outlineColor = rectangleShape->getOutlineColor();

	stringstream stream;

	stream << rectangle << " " << pointLT.x << " "
		<< pointLT.y << " " << pointRB.x << " " << pointRB.y << " "
		<< fillColor.toInteger() << " " << outlineColor.toInteger()
		<< " " << static_cast<int>(outlineThickness) << endl;

	return stream.str();
}

string CSaveFileStrategy::GetTriangleInfo(CTriangleDecorator* triangleDecorator) {
	auto triangleShape = triangleDecorator->GetTriangle();

	auto point0 = triangleShape->getPoint(0);
	auto point1 = triangleShape->getPoint(1);
	auto point2 = triangleShape->getPoint(2);
	auto fillColor = triangleShape->getFillColor();
	auto outlineColor = triangleShape->getOutlineColor();
	auto outlineThickness = triangleShape->getOutlineThickness();

	stringstream stream;

	stream << triangle << " " 
		<< point0.x << " " << point0.y << " "
		<< point1.x << " " << point1.y << " " 
		<< point2.x << " " << point2.y << " "
		<< fillColor.toInteger() << " " << outlineColor.toInteger()
		<< " " << static_cast<int>(outlineThickness) << endl;

	return stream.str();
}

void CSaveFileStrategy::WriteFiguresInfo(ostream& output, vector<CFigureMovementDecorator*> figures) {
	for (auto figure : figures) {
		if (typeid(*figure) == typeid(CCircleDecorator)) {
			output << GetCircleInfo(static_cast<CCircleDecorator*>(figure));
		}
		else if (typeid(*figure) == typeid(CRectangleDecorator)) {
			output << GetRectangleInfo(static_cast<CRectangleDecorator*>(figure));
		}
		else if (typeid(*figure) == typeid(CTriangleDecorator)) {
			output << GetTriangleInfo(static_cast<CTriangleDecorator*>(figure));
		}
		else if (typeid(*figure) == typeid(CFigureCompound)) {
			output << grouped << endl;
			WriteFiguresInfo(output, static_cast<CFigureCompound*>(figure)->GetFigures());
			output << endGrouped << endl;
		}
	}
}
