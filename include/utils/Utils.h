#ifndef UTILS_H
#define UTILS_H

#include "geometrie/Vecteur2D.h"
#include "design_patterns/cor/ChargeurFormeCOR.h"
#include "design_patterns/visiteur/VisiteurForme.h"
#include <vector>
#include <ostream>

using namespace std;

/**
 * @brief Classe utilitaire contenant des méthodes statiques.
 */
class Utils
{
public:
	/**
	 * @brief Calcule l'homothétie d'un point par rapport à un centre.
	 * @param centre Le centre de l'homothétie.
	 * @param point Le point à transformer.
	 * @param k Le facteur d'homothétie.
	 * @return La nouvelle coordonnée du point après l'homothétie.
	 */
	static double calculerHomothetie(double centre, double point, double k);

	/**
	 * @brief Calcule la rotation d'un point autour d'un centre selon l'axe des abscisses.
	 * @param centreX La coordonnée X du centre de la rotation.
	 * @param centreY La coordonnée Y du centre de la rotation.
	 * @param pointX La coordonnée X du point à transformer.
	 * @param pointY La coordonnée Y du point à transformer.
	 * @param cosA Le cosinus de l'angle de rotation.
	 * @param sinA Le sinus de l'angle de rotation.
	 * @return La nouvelle coordonnée X du point après la rotation.
	 */
	static double calculerRotationX(double centreX, double centreY, double pointX, double pointY, double cosA, double sinA);

	/**
	 * @brief Calcule la rotation d'un point autour d'un centre selon l'axe des ordonnées.
	 * @param centreX La coordonnée X du centre de la rotation.
	 * @param centreY La coordonnée Y du centre de la rotation.
	 * @param pointX La coordonnée X du point à transformer.
	 * @param pointY La coordonnée Y du point à transformer.
	 * @param cosA Le cosinus de l'angle de rotation.
	 * @param sinA Le sinus de l'angle de rotation.
	 * @return La nouvelle coordonnée Y du point après la rotation.
	 */
	static double calculerRotationY(double centreX, double centreY, double pointX, double pointY, double cosA, double sinA);

	/**
	 * @brief Charge les formes à partir d'un fichier.
	 * @param nomFichier Le nom du fichier à charger.
	 * @param chargeurFormeCOR Le chargeur de formes.
	 * @return Le vecteur de formes chargées.
	 */
	static vector<Forme*> chargerFormes(const string& nomFichier, ChargeurFormeCOR* chargeurFormeCOR);

	/**
	 * @brief Sauvegarde les formes dans un fichier.
	 * @param nomFichier Le nom du fichier de sauvegarde.
	 * @param visiteurForme Le visiteur de formes.
	 * @param formes Le vecteur de formes à sauvegarder.
	 */
	static void sauvegarderFormes(ofstream* fichier, VisiteurForme* visiteurForme, const vector<Forme*>& formes);
}; // class Utils

inline double Utils::calculerHomothetie(double centre, double point, double k)
{
	return centre + (point - centre) * k;
}

inline double Utils::calculerRotationX(double centreX, double centreY, double pointX, double pointY, double cosA, double sinA)
{
	return centreX + (pointX - centreX) * cosA - (pointY - centreY) * sinA;
}

inline double Utils::calculerRotationY(double centreX, double centreY, double pointX, double pointY, double cosA, double sinA)
{
	return centreY + (pointX - centreX) * sinA + (pointY - centreY) * cosA;
}

#endif // UTILS_H