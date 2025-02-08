#ifndef SEGMENT_H
#define SEGMENT_H

#include "formes/Forme.h"
#include "geometrie/Vecteur2D.h"
#include <sstream>

class Segment : public Forme
{
private:
	Vecteur2D _p1, _p2;

public:
	Segment(Couleur couleur, const Vecteur2D& p1, const Vecteur2D& p2)
		: Forme(couleur), _p1(p1), _p2(p2) {}

	Segment* clone() const override { return new Segment(*this); }

	double aire() const override { return 0.0; }

	const Vecteur2D& getP1() const { return _p1; }

	const Vecteur2D& getP2() const { return _p2; }

	operator string() const override;
}; // class Segment

inline Segment::operator string() const
{
	ostringstream oss;
	oss << "Segment [Couleur : " + to_string(static_cast<int>(_couleur)) + ", Point 1 : " + string(_p1) + ", Point 2 : " + string(_p2) + "]";
	return oss.str();
}

#endif // SEGMENT_H