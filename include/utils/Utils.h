#ifndef UTILS_H
#define UTILS_H

#include "geometrie/Vecteur2D.h"
#include "design_patterns/cor/ChargeurFormeCOR.h"
#include "design_patterns/visiteur/VisiteurForme.h"
#include "graphique/Viewport.h"
#include <vector>

using namespace std;

/**
 * @brief Classe utilitaire contenant des méthodes statiques.
 */
class Utils
{
public:
	/**
	 * @brief Charge les formes à partir d'un fichier.
	 * @param nomFichier Le nom du fichier à charger.
	 * @param chargeurFormeCOR Le chargeur de formes.
	 * @return Le vecteur de formes chargées.
	 */
	static vector<Forme*> chargerFormes(const string& nomFichier, ChargeurFormeCOR* chargeurFormeCOR);

	/**
	 * @brief Sauvegarde les formes dans un fichier.
	 * @param formes Le vecteur de formes à sauvegarder.
	 * @param visiteurForme Le visiteur de formes.
	 */
	static void sauvegarderFormes(const vector<Forme*>& formes, VisiteurForme* visiteurForme);

	/**
	 * @brief Transforme les formes du monde vers l'écran.
	 * @param formes Le vecteur de formes à transformer.
	 * @param viewport Le viewport.
	 * @return Le vecteur de formes transformées.
	 */
	static vector<Forme*> transformerFormesVersEcran(const vector<Forme*>& formes, const Viewport& viewport);

	/**
	 * @brief Centre un groupe de formes par rapport à un centre donné.
	 * @param groupe Le groupe de formes à centrer.
	 * @param centre Le centre du groupe.
	 */
	static void centrerGroupe(Groupe* groupe, const Vecteur2D& centre);
}; // class Utils

#endif // UTILS_H