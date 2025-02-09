#include "formes/Polygone.h"

void Polygone::homothetie(const Vecteur2D& centre, double k)
{
	// On parcours tous les points du polygone
	for (Vecteur2D& point : _points)
	{
		// On applique l'homothétie à chaque point
		appliquerHomothetie(point, centre, k);
	}
}

void Polygone::rotation(const Vecteur2D& centre, double angle)
{
	// On calcule le cosinus et le sinus de l'angle
	double cosA = cos(angle);
	double sinA = sin(angle);

	// On parcours tous les points du polygone
	for (Vecteur2D& point : _points)
	{
		// On applique la rotation à chaque point
		appliquerRotation(point, centre, cosA, sinA);
	}
}