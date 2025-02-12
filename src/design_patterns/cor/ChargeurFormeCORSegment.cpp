#include "design_patterns/cor/ChargeurFormeCORSegment.h"
#include "formes/Segment.h"
#include <string.h>

const char* FORMAT_SEGMENT = "%lf %lf %lf %lf";

inline Forme* ChargeurFormeCORSegment::chargerTXT(const char* ligne) const
{
	// On créer une copie de la ligne pour ne pas la modifier
	char* ptrLigne = strdup(ligne);

	// On récupère le nombre de points
	int nbPoints = recupererNbPoints(ptrLigne);

	// Si le nombre de points est -1, alors on retourne nullptr
	if (nbPoints == -1)
		return nullptr;

	// Si le nombre de points est différent de 2, alors on retourne nullptr
	if (nbPoints != 2)
		return nullptr;

	double x1, y1, x2, y2;

	// On récupère les coordonnées du segment
	if (sscanf(ptrLigne, FORMAT_SEGMENT, &x1, &y1, &x2, &y2) != 4)
		throw invalid_argument("Erreur lors de la lecture des coordonnées du segment.");

	return new Segment(Vecteur2D(x1, y1), Vecteur2D(x2, y2));
}