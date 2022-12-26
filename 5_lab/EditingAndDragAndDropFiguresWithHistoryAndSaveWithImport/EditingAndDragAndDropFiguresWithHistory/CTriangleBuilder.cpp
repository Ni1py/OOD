#include "CTriangleBuilder.h"

CTriangleBuilder::CTriangleBuilder(vector<unsigned int> characteristics)
	:m_point0({ static_cast<float>(characteristics[0]),
		static_cast<float>(characteristics[1]) }),
	m_point1({ static_cast<float>(characteristics[2]),
		static_cast<float>(characteristics[3]) }),
	m_point2({ static_cast<float>(characteristics[4]),
		static_cast<float>(characteristics[5]) })
{
	m_fillColor = characteristics[6];
	m_outlineColor = characteristics[7];
	m_outlineThickness = characteristics[8];
}

void CTriangleBuilder::SetShape() {
	auto triangleShape = new ConvexShape();
	triangleShape->setPointCount(3);
	triangleShape->setPoint(0, m_point0);
	triangleShape->setPoint(1, m_point1);
	triangleShape->setPoint(2, m_point2);
	m_figure = new CTriangleDecorator(triangleShape);
}

void CTriangleBuilder::SetPosition() {
	float minX;
	float minY;

	if (m_point0.x < m_point1.x && m_point0.x < m_point2.x)
		minX = m_point0.x;
	else if (m_point1.x < m_point0.x && m_point1.x < m_point2.x)
		minX = m_point1.x;
	else minX = m_point2.x;

	if (m_point0.y < m_point1.y && m_point0.y < m_point2.y)
		minY = m_point0.y;
	else if (m_point1.y < m_point0.y && m_point1.y < m_point2.y)
		minY = m_point1.y;
	else minY = m_point2.y;

	m_figure->SetPosition(minX, minY);
}
