#include "formes/Segment.h"
#include <cmath>

void Segment::homothetie(const Vecteur2D& centre, double k)
{
	// On applique l'homothétie au premier point
	appliquerHomothetie(_p1, centre, k);

	// On applique l'homothétie au second point
	appliquerHomothetie(_p2, centre, k);
}

void Segment::rotation(const Vecteur2D& centre, double angle)
{
	// On calcule le cosinus et le sinus de l'angle
	double cosA = cos(angle);
	double sinA = sin(angle);

	// On applique la rotation au premier point
	appliquerRotation(_p1, centre, cosA, sinA);

	// On applique la rotation au second point
	appliquerRotation(_p2, centre, cosA, sinA);
}