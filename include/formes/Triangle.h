#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "formes/Forme.h"
#include <string>
#include <ostream>
#include <algorithm>

using namespace std;

/**
 * @brief Classe représentant un triangle.
 */
class Triangle : public Forme
{
private:
	Vecteur2D _p1, _p2, _p3; /**< Les trois points du triangle. */

public:
	/**
	 * @brief Constructeur de la classe Triangle.
	 * @param p1 Le premier point du triangle.
	 * @param p2 Le deuxième point du triangle.
	 * @param p3 Le troisième point du triangle.
	 * @param couleur La couleur du triangle.
	 */
	Triangle(const Vecteur2D& p1, const Vecteur2D& p2, const Vecteur2D& p3, Couleur couleur = COULEUR_PAR_DEFAUT)
		: Forme(couleur), _p1(p1), _p2(p2), _p3(p3) {}

	Triangle* clone() const override { return new Triangle(*this); }

	double aire() const override;

	void translation(const Vecteur2D& vt) override;

	void homothetie(const Vecteur2D& centre, double k) override;

	void rotation(const Vecteur2D& centre, double angle) override;

	void bornes(Vecteur2D& pmin, Vecteur2D& pmax) const override;

	Vecteur2D calculerCentre() const override;

	const Vecteur2D& p1() const { return _p1; }

	const Vecteur2D& p2() const { return _p2; }

	const Vecteur2D& p3() const { return _p3; }

	operator string() const override;

	void accepter(VisiteurForme* visiteur) override { visiteur->visiter(this); }
}; // class Triangle

inline double Triangle::aire() const
{
	// On calcule l'aire du triangle en utilisant le déterminant des points successifs
	return abs((_p1 - _p3).determinant(_p2 - _p3)) / 2.0;
}

inline void Triangle::translation(const Vecteur2D& vt)
{
	_p1 += vt;
	_p2 += vt;
	_p3 += vt;
}

inline void Triangle::bornes(Vecteur2D& pmin, Vecteur2D& pmax) const
{
	pmin = Vecteur2D(min({ _p1.x, _p2.x, _p3.x }), min({ _p1.y, _p2.y, _p3.y }));
	pmax = Vecteur2D(max({ _p1.x, _p2.x, _p3.x }), max({ _p1.y, _p2.y, _p3.y }));
}

inline Vecteur2D Triangle::calculerCentre() const
{
	return Vecteur2D((_p1.x + _p2.x + _p3.x) / 3, (_p1.y + _p2.y + _p3.y) / 3);
}

inline Triangle::operator string() const
{
	ostringstream oss;
	oss << "3 " << _p1 << " " << _p2 << " " << _p3;
	return oss.str();
}

#endif // TRIANGLE_H