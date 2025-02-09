#ifndef VIEWPORT_H
#define VIEWPORT_H

#include "geometrie/Vecteur2D.h"
#include "formes/Forme.h"

class Viewport
{
private:
	Vecteur2D _coinMin;
	Vecteur2D _coinMax;
	int _largeurEcran, _hauteurEcran;
	Vecteur2D _centreMonde;
	double _echelleX;
	double _echelleY;
	double _facteurZoom;

public:
	Viewport(const Vecteur2D& coinMin, const Vecteur2D& coinMax, int largeurEcran, int hauteurEcran);

	Forme* formeVersEcran(const Forme& forme) const;

	Vecteur2D coinMin() const { return _coinMin; }

	Vecteur2D coinMax() const { return _coinMax; }

	int largeurEcran() const { return _largeurEcran; }

	int hauteurEcran() const { return _hauteurEcran; }

	Vecteur2D centreMonde() const { return _centreMonde; }

	double echelleX() const { return _echelleX; }

	double echelleY() const { return _echelleY; }

	double facteurZoom() const { return _facteurZoom; }

	operator string() const;

	friend ostream& operator<<(ostream& os, const Viewport& viewport)
	{
		return os << string(viewport);
	}
}; // class Viewport

inline Viewport::Viewport(const Vecteur2D& coinMin, const Vecteur2D& coinMax, int largeurEcran, int hauteurEcran)
	: _coinMin(coinMin), _coinMax(coinMax), _largeurEcran(largeurEcran), _hauteurEcran(hauteurEcran)
{
	double centre = (coinMin.x + coinMax.y) / 2;

	_centreMonde = Vecteur2D(centre, centre);

	_echelleX = _largeurEcran / (_coinMax.x - _coinMin.x);
	_echelleY = _hauteurEcran / (_coinMax.y - _coinMin.y);
	_facteurZoom = min(_echelleX, _echelleY);
}

inline Forme* Viewport::formeVersEcran(const Forme& forme) const
{
	Forme* copie = forme.clone();

	copie->translation(-_centreMonde);

	copie->homothetie(Vecteur2D(0, 0), _facteurZoom);

	copie->translation(Vecteur2D(_largeurEcran / 2, _hauteurEcran / 2));

	return copie;
}

inline Viewport::operator string() const
{
	ostringstream oss;
	oss << _coinMin << " -> " << _coinMax << " (" << _largeurEcran << "x" << _hauteurEcran << ")";
	return oss.str();
}

#endif // VIEWPORT_H