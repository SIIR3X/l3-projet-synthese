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
	Cercle(const Vecteur2D& centre, double rayon, Couleur couleur = COULEUR_PAR_DEFAUT)
		: Forme(couleur), _centre(centre), _rayon(rayon) 
	{
		if (_rayon <= 0)
			throw invalid_argument("Le rayon doit être strictement positif.");
	}

	Cercle* clone() const override { return new Cercle(*this); }

	double aire() const override { return PI * _rayon * _rayon; }

	void translation(const Vecteur2D& vt) override;

	void homothetie(const Vecteur2D& centre, double k) override;

	void rotation(const Vecteur2D& centre, double angle) override;

	const Vecteur2D& getCentre() const { return _centre; }

	double getRayon() const { return _rayon; }

	operator string() const override;

	void accepter(VisiteurForme* visiteur) override { visiteur->visiter(this); }
}; // class Cercle

inline void Cercle::translation(const Vecteur2D& vt)
{
	_centre += vt;
}

inline Cercle::operator string() const
{
	ostringstream oss;
	oss << "1 " << _centre << " " << _rayon;
	return oss.str();
}

#endif // CERCLE_H