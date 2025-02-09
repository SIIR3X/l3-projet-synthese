#include "formes/Polygone.h"

void Polygone::homothetie(const Vecteur2D& centre, double k)
{
	for (Vecteur2D& point : _points)
	{
		point.x = centre.x + k * (point.x - centre.x);
		point.y = centre.y + k * (point.y - centre.y);
	}
}

void Polygone::rotation(const Vecteur2D& centre, double angle)
{
	double cosA = cos(angle);
	double sinA = sin(angle);

	for (Vecteur2D& point : _points)
	{
		Vecteur2D temp(point.x - centre.x, point.y - centre.y);

		point.x = centre.x + (temp.x * cosA) - (temp.y * sinA);
		point.y = centre.y + (temp.x * sinA) + (temp.y * cosA);
	}
}