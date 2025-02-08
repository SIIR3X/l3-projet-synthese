#include "design_patterns/cor/ChargeurFormeCORTriangle.h"
#include "formes/Triangle.h"

inline Forme* ChargeurFormeCORTriangle::chargerTXT(const char* ligne) const
{
	int nbPoints = recupererNbPoints(ligne);

	if (nbPoints == -1)
		return nullptr;

	if (nbPoints != 3)
		return nullptr;

	double x1, y1, x2, y2, x3, y3;

	if (sscanf(ligne, "%*d %*d ( %lf, %lf) ( %lf, %lf) ( %lf, %lf)", &x1, &y1, &x2, &y2, &x3, &y3) != 6)
		throw invalid_argument("Erreur lors de la lecture des coordonnées du triangle.");

	return new Triangle(Vecteur2D(x1, y1), Vecteur2D(x2, y2), Vecteur2D(x3, y3));
}