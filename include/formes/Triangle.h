#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "formes/Forme.h"
#include <sstream>

class Triangle : public Forme
{
private:
	Vecteur2D _p1, _p2, _p3;

public:
	Triangle(const Vecteur2D& p1, const Vecteur2D& p2, const Vecteur2D& p3, Couleur couleur = COULEUR_PAR_DEFAUT)
		: Forme(couleur), _p1(p1), _p2(p2), _p3(p3) {}

	Triangle* clone() const override { return new Triangle(*this); }

	double aire() const override;

	void translation(const Vecteur2D& vt) override;

	void homothetie(const Vecteur2D& centre, double k) override;

	void rotation(const Vecteur2D& centre, double angle) override;

	const Vecteur2D& getP1() const { return _p1; }

	const Vecteur2D& getP2() const { return _p2; }

	const Vecteur2D& getP3() const { return _p3; }

	operator string() const override;

	void accepter(VisiteurForme* visiteur) override { visiteur->visiter(this); }
}; // class Triangle

inline double Triangle::aire() const
{
	return abs((_p1 - _p3).determinant(_p2 - _p3)) / 2.0;
}

inline void Triangle::translation(const Vecteur2D& vt)
{
	_p1 += vt;
	_p2 += vt;
	_p3 += vt;
}

inline Triangle::operator string() const
{
	ostringstream oss;
	oss << "3 " << _p1 << " " << _p2 << " " << _p3;
	return oss.str();
}

#endif // TRIANGLE_H