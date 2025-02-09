#include "formes/Forme.h"
#include "utils/Utils.h"

void Forme::appliquerHomothetie(Vecteur2D& point, const Vecteur2D& centre, double k) const
{
	// Calcul des nouvelles coordonnées
	point.x = Utils::calculerHomothetie(centre.x, point.x, k);
	point.y = Utils::calculerHomothetie(centre.y, point.y, k);
}

void Forme::appliquerRotation(Vecteur2D& point, const Vecteur2D& centre, double cosA, double sinA) const
{
	// On sauvegarde les coordonnées originales du point
	double originalX = point.x;
	double originalY = point.y;

	// Calcul des nouvelles coordonnées
	point.x = Utils::calculerRotationX(centre.x, centre.y, originalX, originalY, cosA, sinA);
	point.y = Utils::calculerRotationY(centre.x, centre.y, originalX, originalY, cosA, sinA);
}