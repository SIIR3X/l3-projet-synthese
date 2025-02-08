#include "design_patterns/cor/ChargeurFormeCORSegment.h"
#include "formes/Segment.h"

inline Forme* ChargeurFormeCORSegment::chargerTXT(const char* ligne) const
{
	int nbPoints = recupererNbPoints(ligne);

	if (nbPoints == -1)
		return nullptr;

	if (nbPoints != 2)
		return nullptr;

	double x1, y1, x2, y2;

	if (sscanf(ligne, "%*d %*d ( %lf, %lf) ( %lf, %lf)", &x1, &y1, &x2, &y2) != 4)
		throw invalid_argument("Erreur lors de la lecture des coordonnées du segment.");

	return new Segment(Vecteur2D(x1, y1), Vecteur2D(x2, y2));
}