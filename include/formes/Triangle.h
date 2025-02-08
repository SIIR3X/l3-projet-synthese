#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "formes/Forme.h"
#include "geometrie/Vecteur2D.h"
#include <sstream>

class Triangle : public Forme
{
private:
	Vecteur2D _p1, _p2, _p3;

public:
	Triangle(Couleur couleur, const Vecteur2D& p1, const Vecteur2D& p2, const Vecteur2D& p3)
		: Forme(couleur), _p1(p1), _p2(p2), _p3(p3) {}

	Triangle* clone() const override { return new Triangle(*this); }

	double aire() const override;

	const Vecteur2D& getP1() const { return _p1; }

	const Vecteur2D& getP2() const { return _p2; }

	const Vecteur2D& getP3() const { return _p3; }

	operator string() const override;
}; // class Triangle

inline double Triangle::aire() const
{
	return abs((_p1 - _p3).determinant(_p2 - _p3)) / 2.0;
}

inline Triangle::operator string() const
{
	ostringstream oss;
	oss << "Triangle [Couleur : " + to_string(static_cast<int>(_couleur)) + ", Point 1 : " + string(_p1) + ", Point 2 : " + string(_p2) + ", Point 3 : " + string(_p3) + "]";
	return oss.str();
}

#endif // TRIANGLE_H