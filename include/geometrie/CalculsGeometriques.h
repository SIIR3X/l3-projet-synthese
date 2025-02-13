#ifndef CALCULS_GEOMETRIQUES_H
#define CALCULS_GEOMETRIQUES_H

/**
 * @brief Classe contenant des méthodes de calculs géométriques.
 */
class CalculsGeometriques
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
}; // class CalculsGeometriques

inline double CalculsGeometriques::calculerHomothetie(double centre, double point, double k)
{
	return centre + (point - centre) * k;
}

inline double CalculsGeometriques::calculerRotationX(double centreX, double centreY, double pointX, double pointY, double cosA, double sinA)
{
	return centreX + (pointX - centreX) * cosA - (pointY - centreY) * sinA;
}

inline double CalculsGeometriques::calculerRotationY(double centreX, double centreY, double pointX, double pointY, double cosA, double sinA)
{
	return centreY + (pointX - centreX) * sinA + (pointY - centreY) * cosA;
}

#endif // CALCULS_GEOMETRIQUES_H