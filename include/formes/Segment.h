#ifndef SEGMENT_H
#define SEGMENT_H

#include "formes/Forme.h"
#include <string>
#include <ostream>

using namespace std;

/**
 * @brief Classe représentant un segment.
 */
class Segment : public Forme
{
private:
	Vecteur2D _p1, _p2; /**< Les deux points du segment. */

public:
	/**
	 * @brief Constructeur de la classe Segment.
	 * @param p1 Le premier point du segment.
	 * @param p2 Le deuxième point du segment.
	 * @param couleur La couleur du segment.
	 */
	Segment(const Vecteur2D& p1, const Vecteur2D& p2, Couleur couleur = COULEUR_PAR_DEFAUT)
		: Forme(couleur), _p1(p1), _p2(p2) {}

	Segment* clone() const override { return new Segment(*this); }

	double aire() const override { return 0.0; }

	void translation(const Vecteur2D& vt) override;

	void homothetie(const Vecteur2D& centre, double k) override;

	void rotation(const Vecteur2D& centre, double angle) override; 

	const Vecteur2D& p1() const { return _p1; }

	const Vecteur2D& p2() const { return _p2; }

	operator string() const override;

	void accepter(VisiteurForme* visiteur) override { visiteur->visiter(this); }
}; // class Segment

inline void Segment::translation(const Vecteur2D& vt)
{
	_p1 += vt;
	_p2 += vt;
}

inline Segment::operator string() const
{
	ostringstream oss;
	oss << "2 " << _p1 << " " << _p2;
	return oss.str();
}

#endif // SEGMENT_H