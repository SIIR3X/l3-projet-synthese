#ifndef CERCLE_H
#define CERCLE_H

#include "formes/Forme.h"
#include "geometrie/Vecteur2D.h"
#include <sstream>
#include <stdexcept>

const double PI = 3.14159265358979323846;

class Cercle : public Forme
{
private:
	Vecteur2D _centre;
	double _rayon;

public:
	Cercle(Couleur couleur, const Vecteur2D& centre, double rayon)
		: Forme(couleur), _centre(centre), _rayon(rayon) 
	{
		if (_rayon <= 0)
			throw invalid_argument("Le rayon doit être strictement positif.");
	}

	Cercle* clone() const override { return new Cercle(*this); }

	double aire() const override { return PI * _rayon * _rayon; }

	const Vecteur2D& getCentre() const { return _centre; }

	double getRayon() const { return _rayon; }

	operator string() const override;
}; // class Cercle

inline Cercle::operator string() const
{
	ostringstream oss;
	oss << "Cercle [Couleur : " + to_string(static_cast<int>(_couleur)) + ", Centre : " + string(_centre) + ", Rayon : " + to_string(_rayon) + "]";
	return oss.str();
}

#endif // CERCLE_H