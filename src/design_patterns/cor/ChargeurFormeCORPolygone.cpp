#include "design_patterns/cor/ChargeurFormeCORPolygone.h"
#include "formes/Polygone.h"
#include <string.h>

const char* FORMAT_POLYGONE = "%lf %lf%n";

Forme* ChargeurFormeCORPolygone::chargerTXT(const char* ligne) const
{
	// On créer une copie de la ligne pour ne pas la modifier
	char* ptrLigne = strdup(ligne);

	// On récupère le nombre de points du polygone
	int nbPoints = recupererNbPoints(ptrLigne);

	// Si aucun nombre de points n'a été trouvé, on lève une exception
	if (nbPoints == -1)
		throw invalid_argument("Erreur lors de la lecture du nombre de points.");

	// Si le nombre de points est inférieur ou égal à 3, on ne peut pas créer de polygone
	if (nbPoints <= 3)
		return nullptr;

	vector<Vecteur2D> points;

	// On crée un offset pour avancer le pointeur
	int offset;

	// Pour finir, on lit les points du polygone
	for (int i = 0; i < nbPoints; i++)
	{
		double x, y;

		if (sscanf(ptrLigne, FORMAT_POLYGONE, &x, &y, &offset) != 2)
			throw invalid_argument("Erreur lors de la lecture des points du polygone.");

		points.push_back(Vecteur2D(x, y));
		
		// A chaque itération, on avance le pointeur pour lire le point suivant
		ptrLigne += offset;
	}

	return new Polygone(points);
}