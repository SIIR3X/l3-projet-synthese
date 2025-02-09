#include "formes/Triangle.h"
#include <cmath>

void Triangle::rotation(const Vecteur2D& centre, double angle)
{
	double cosA = cos(angle);
	double sinA = sin(angle);

	Vecteur2D temp(_p1.x - centre.x, _p2.y - centre.y);
	_p1.x = centre.x + (temp.x * cosA) - (temp.y * sinA);
	_p1.y = centre.y + (temp.x * sinA) + (temp.y * cosA);

	temp.x = _p2.x - centre.x;
	temp.y = _p2.y - centre.y;
	_p2.x = centre.x + (temp.x * cosA) - (temp.y * sinA);
	_p2.y = centre.y + (temp.x * sinA) + (temp.y * cosA);

	temp.x = _p3.x - centre.x;
	temp.y = _p3.y - centre.y;
	_p3.x = centre.x + (temp.x * cosA) - (temp.y * sinA);
	_p3.y = centre.y + (temp.x * sinA) + (temp.y * cosA);
}