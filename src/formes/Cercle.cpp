#include "formes/Cercle.h"
#include <cmath>

void Cercle::homothetie(const Vecteur2D& centre, double k)
{
	// On applique l'homothétie au centre du cercle
	appliquerHomothetie(_centre, centre, k);

	// On multiplie le rayon par la valeur absolue du coefficient d'homothétie
	_rayon *= abs(k);
}

void Cercle::rotation(const Vecteur2D& centre, double angle)
{
	// On calcule le cosinus et le sinus de l'angle
	double cosA = cos(angle);
	double sinA = sin(angle);

	// On applique la rotation au centre du cercle
	appliquerRotation(_centre, centre, cosA, sinA);
}