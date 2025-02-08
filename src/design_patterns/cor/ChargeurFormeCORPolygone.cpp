#include "design_patterns/cor/ChargeurFormeCORPolygone.h"
#include "formes/Polygone.h"

Forme* ChargeurFormeCORPolygone::chargerTXT(const char* ligne) const
{
	// On récupère le nombre de points du polygone
	int nbPoints = recupererNbPoints(ligne);

	// Si aucun nombre de points n'a été trouvé, on lève une exception
	if (nbPoints == -1)
		throw invalid_argument("Erreur lors de la lecture du nombre de points.");

	// Si le nombre de points est inférieur ou égal à 3, on ne peut pas créer de polygone
	if (nbPoints <= 3)
		return nullptr;

	vector<Vecteur2D> points;

	// On crée un pointeur et un offset pour lire les points du polygone
	const char* ptr = ligne;
	int offset;

	// On avance le pointeur pour ignorer le nombre de points
	if (sscanf(ptr, "%*d %d%n", &nbPoints, &offset) != 1)
		throw invalid_argument("Erreur lors de la lecture du nombre de points.");
	ptr += offset;

	// Pour finir, on lit les points du polygone
	for (int i = 0; i < nbPoints; i++)
	{
		double x, y;

		if (sscanf(ptr, " ( %lf , %lf )%n", &x, &y, &offset) != 2)
			throw invalid_argument("Erreur lors de la lecture des points du polygone.");

		points.push_back(Vecteur2D(x, y));
		
		// A chaque itération, on avance le pointeur pour lire le point suivant
		ptr += offset;
	}

	return new Polygone(points);
}