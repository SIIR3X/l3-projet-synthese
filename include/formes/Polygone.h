#ifndef POLYGONE_H
#define POLYGONE_H

#include "formes/Forme.h"
#include "geometrie/Vecteur2D.h"
#include <vector>
#include <sstream>
#include <stdexcept>

class Polygone : public Forme
{
private:
	vector<Vecteur2D> _points;

public:
	Polygone(const vector<Vecteur2D>& points, Couleur couleur = COULEUR_PAR_DEFAUT)
		: Forme(couleur), _points(points) 
	{
		if (points.size() < 3)
			throw std::invalid_argument("Un polygone doit avoir au moins 3 sommets.");
	}

	Polygone* clone() const override { return new Polygone(*this); }

	double aire() const override;

	void translation(const Vecteur2D& vt) override;

	void homothetie(const Vecteur2D& centre, double k) override;

	void rotation(const Vecteur2D& centre, double angle) override;

	size_t getNbPoints() const { return _points.size(); }

	const vector<Vecteur2D>& getPoints() const { return _points; }

	const Vecteur2D& getPoint(size_t index) const;

	const Vecteur2D& operator[](size_t index) const { return _points[index]; }

	operator string() const override;

	void accepter(VisiteurForme* visiteur) override { visiteur->visiter(this); }
}; // class Polygone

inline double Polygone::aire() const
{
	double aire = 0.0;

	for (size_t i = 0; i < _points.size(); ++i)
	{
		const Vecteur2D& p1 = _points[i];
		const Vecteur2D& p2 = _points[(i + 1) % _points.size()];

		aire += p1.determinant(p2);
	}

	return abs(aire) / 2.0;
}

inline void Polygone::translation(const Vecteur2D& vt)
{
	for (Vecteur2D& point : _points)
		point += vt;
}

inline const Vecteur2D& Polygone::getPoint(size_t index) const
{
	if (index < _points.size())
		return _points[index];

	throw std::out_of_range("Index hors limites.");
}

inline Polygone::operator string() const
{
	ostringstream oss;

	oss << _points.size();
	for (const Vecteur2D& point : _points)
		oss << " " << point;

	return oss.str();
}

#endif // POLYGONE_H