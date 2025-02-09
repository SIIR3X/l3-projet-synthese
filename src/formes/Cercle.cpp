#include "formes/Cercle.h"
#include <cmath>

void Cercle::rotation(const Vecteur2D& centre, double angle)
{
	double cosA = cos(angle);
	double sinA = sin(angle);

	Vecteur2D temp(_centre.x - centre.x, _centre.y - centre.y);

	_centre.x = centre.x + (temp.x * cosA) - (temp.y * sinA);
	_centre.y = centre.y + (temp.x * sinA) + (temp.y * cosA);
}