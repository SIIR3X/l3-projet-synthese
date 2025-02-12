#include "design_patterns/cor/ChargeurFormeCORTriangle.h"
#include "formes/Triangle.h"
#include <string.h>

const char* FORMAT_TRIANGLE = "%lf %lf %lf %lf %lf %lf";

inline Forme* ChargeurFormeCORTriangle::chargerTXT(const char* ligne) const
{
	// On créer une copie de la ligne pour ne pas la modifier
	char* ptrLigne = strdup(ligne);

	// On récupère le nombre de points
	int nbPoints = recupererNbPoints(ptrLigne);

	// Si le nombre de points est -1, alors on retourne nullptr
	if (nbPoints == -1)
		return nullptr;

	// Si le nombre de points est différent de 3, alors on retourne nullptr
	if (nbPoints != 3)
		return nullptr;

	double x1, y1, x2, y2, x3, y3;

	// On récupère les coordonnées du triangle
	if (sscanf(ptrLigne, FORMAT_TRIANGLE, &x1, &y1, &x2, &y2, &x3, &y3) != 6)
		throw invalid_argument("Erreur lors de la lecture des coordonnées du triangle.");

	return new Triangle(Vecteur2D(x1, y1), Vecteur2D(x2, y2), Vecteur2D(x3, y3));
}