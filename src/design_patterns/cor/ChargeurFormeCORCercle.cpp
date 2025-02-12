#include "design_patterns/cor/ChargeurFormeCORCercle.h"
#include "formes/Cercle.h"
#include <string.h>

const char* FORMAT_CERCLE = "%lf %lf %lf";

Forme* ChargeurFormeCORCercle::chargerTXT(const char* ligne) const
{
	// On créer une copie de la ligne pour ne pas la modifier
	char* ptrLigne = strdup(ligne);

	// On récupère le nombre de points
	int nbPoints = recupererNbPoints(ptrLigne);

	// Si le nombre de points est -1, alors on lance une exception
	if (nbPoints == -1)
		throw invalid_argument("Erreur lors de la lecture du nombre de points.");

	// Si le nombre de points est différent de 1, alors on retourne nullptr
	if (nbPoints != 1)
		return nullptr;

	double x, y, rayon;

	// On récupère les coordonnées du cercle
	if (sscanf(ptrLigne, FORMAT_CERCLE, &x, &y, &rayon) != 3)
		throw invalid_argument("Erreur lors de la lecture des coordonnées du cercle.");

	return new Cercle(Vecteur2D(x, y), rayon);
}