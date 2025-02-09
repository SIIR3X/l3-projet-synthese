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
	Segment(const Vecteur2D& p1, const Vecteur2D& p2, Couleur couleur = COULEUR_PAR_DEFAUT)
		: Forme(couleur), _p1(p1), _p2(p2) {}

	Segment* clone() const override { return new Segment(*this); }

	double aire() const override { return 0.0; }

	void translation(const Vecteur2D& v) override;

	const Vecteur2D& getP1() const { return _p1; }

	const Vecteur2D& getP2() const { return _p2; }

	operator string() const override;

	void accepter(VisiteurForme* visiteur) override { visiteur->visiter(this); }
}; // class Segment

inline void Segment::translation(const Vecteur2D& v)
{
	_p1 += v;
	_p2 += v;
}

inline Segment::operator string() const
{
	ostringstream oss;
	oss << "2 " << _p1 << " " << _p2;
	return oss.str();
}

#endif // SEGMENT_H