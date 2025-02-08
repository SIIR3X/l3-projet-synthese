#include "design_patterns/cor/ChargeurFormeCORCercle.h"
#include "formes/Cercle.h"

Forme* ChargeurFormeCORCercle::chargerTXT(const char* ligne) const
{
	int nbPoints = recupererNbPoints(ligne);

	if (nbPoints == -1)
		throw invalid_argument("Erreur lors de la lecture du nombre de points.");

	if (nbPoints != 1)
		return nullptr;

	double x, y, rayon;

	if (sscanf(ligne, "%*d %*d ( %lf, %lf) %lf", &x, &y, &rayon) != 3)
		throw invalid_argument("Erreur lors de la lecture des coordonnées du cercle.");

	return new Cercle(Vecteur2D(x, y), rayon);
}