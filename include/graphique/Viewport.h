#ifndef VIEWPORT_H
#define VIEWPORT_H

#include "geometrie/Vecteur2D.h"
#include "formes/Forme.h"
#include <string>
#include <ostream>
#include <stdexcept>

using namespace std;

/**
 * @brief Classe Viewport permettant de convertir des formes du monde en formes de l'écran.
 */
class Viewport
{
private:
	Vecteur2D _coinMin; /**< Coin minimal du monde. */
	Vecteur2D _coinMax; /**< Coin maximal du monde. */
	int _largeurEcran, _hauteurEcran; /**< Dimensions de l'écran. */
	Vecteur2D _centreMonde; /**< Centre du monde. */
	double _echelleX; /**< Échelle en X. */
	double _echelleY; /**< Échelle en Y. */
	double _facteurZoom; /**< Facteur de zoom. */

	/**
	 * @brief Calcule les échelles en X et en Y ainsi que le facteur de zoom.
	 */
	void calculerEchelles();

public:
	/**
	 * @brief Constructeur de la classe Viewport.
	 * @param coinMin Coin minimal du monde.
	 * @param coinMax Coin maximal du monde.
	 * @param largeurEcran Largeur de l'écran.
	 * @param hauteurEcran Hauteur de l'écran.
	 */
	Viewport(const Vecteur2D& coinMin, const Vecteur2D& coinMax, int largeurEcran, int hauteurEcran);

	/**
	 * @brief Convertit une forme du monde en une forme de l'écran.
	 * @param forme Forme à convertir.
	 * @return Pointeur vers la forme convertie.
	 */
	Forme* formeVersEcran(const Forme& forme) const;

	Vecteur2D coinMin() const { return _coinMin; }

	Vecteur2D coinMax() const { return _coinMax; }

	int largeurEcran() const { return _largeurEcran; }

	int hauteurEcran() const { return _hauteurEcran; }

	void setDimensionsEcran(int largeur, int hauteur);

	Vecteur2D centreMonde() const { return _centreMonde; }

	Vecteur2D centreEcran() const { return Vecteur2D(_largeurEcran / 2, _hauteurEcran / 2); }

	double echelleX() const { return _echelleX; }

	double echelleY() const { return _echelleY; }

	double facteurZoom() const { return _facteurZoom; }

	operator string() const;

	friend ostream& operator<<(ostream& os, const Viewport& viewport)
	{
		return os << string(viewport);
	}
}; // class Viewport

inline void Viewport::calculerEchelles()
{
	// On commence par calculer le centre du monde
	double centre = (_coinMin.x + _coinMax.y) / 2;

	// On créé un vecteur 2D qui représente le centre du monde
	_centreMonde = Vecteur2D(centre, centre);

	// On calcule les échelles en X et en Y
	_echelleX = _largeurEcran / (_coinMax.x - _coinMin.x);
	_echelleY = _hauteurEcran / (_coinMax.y - _coinMin.y);

	// On prend le minimum des deux échelles pour le facteur de zoom
	_facteurZoom = min(_echelleX, _echelleY);
}

inline Viewport::Viewport(const Vecteur2D& coinMin, const Vecteur2D& coinMax, int largeurEcran, int hauteurEcran)
	: _coinMin(coinMin), _coinMax(coinMax), _largeurEcran(largeurEcran), _hauteurEcran(hauteurEcran)
{
	// Si les coins du monde ne sont pas valides, on lance une exception
	if (coinMin.x >= coinMax.x || coinMin.y >= coinMax.y)
		throw invalid_argument("Les coins du monde ne sont pas valides.");

	// Si les dimensions de l'écran ne sont pas valides, on lance une exception
	if (largeurEcran <= 0 || hauteurEcran <= 0)
		throw invalid_argument("Les dimensions de l'écran ne sont pas valides.");

	// On calcule ensuite les échelles
	calculerEchelles();
}

inline Forme* Viewport::formeVersEcran(const Forme& forme) const
{
	// On clone la forme
	Forme* copie = forme.clone();

	// On applique une translation pour centrer le monde
	copie->translation(-_centreMonde);

	// On applique une homothétie pour zoomer
	copie->homothetie(Vecteur2D(0, 0), _facteurZoom);

	// On applique une translation pour centrer l'écran
	copie->translation(Vecteur2D(_largeurEcran / 2, _hauteurEcran / 2));

	return copie;
}

inline void Viewport::setDimensionsEcran(int largeur, int hauteur)
{
	// Si les dimensions de l'écran ne sont pas valides, on lance une exception
	if (largeur < 0 || hauteur < 0)
		throw invalid_argument("Les dimensions de l'écran ne sont pas valides.");

	// On met à jour les dimensions de l'écran
	_largeurEcran = largeur;
	_hauteurEcran = hauteur;

	// On recalcule ensuite les échelles
	calculerEchelles();
}

inline Viewport::operator string() const
{
	ostringstream oss;
	oss << _coinMin << " -> " << _coinMax << " (" << _largeurEcran << "x" << _hauteurEcran << ")";
	return oss.str();
}

#endif // VIEWPORT_H