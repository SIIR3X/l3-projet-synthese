#include "design_patterns/cor/ChargeurFormeCORTriangle.h"
#include "formes/Triangle.h"

inline Forme* ChargeurFormeCORTriangle::chargerTXT(const char* ligne) const
{
	// On récupère le nombre de points
	int nbPoints = recupererNbPoints(ligne);

	// Si le nombre de points est -1, alors on retourne nullptr
	if (nbPoints == -1)
		return nullptr;

	// Si le nombre de points est différent de 3, alors on retourne nullptr
	if (nbPoints != 3)
		return nullptr;

	double x1, y1, x2, y2, x3, y3;

	// On récupère les coordonnées du triangle
	if (sscanf(ligne, "%*d %*d ( %lf, %lf) ( %lf, %lf) ( %lf, %lf)", &x1, &y1, &x2, &y2, &x3, &y3) != 6)
		throw invalid_argument("Erreur lors de la lecture des coordonnées du triangle.");

	return new Triangle(Vecteur2D(x1, y1), Vecteur2D(x2, y2), Vecteur2D(x3, y3));
}