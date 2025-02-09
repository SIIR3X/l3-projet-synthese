#ifndef CERCLE_H
#define CERCLE_H

#include "formes/Forme.h"
#include <string>
#include <ostream>
#include <stdexcept>

using namespace std;

const double PI = 3.14159265358979323846;

/**
 * @brief Classe représentant un cercle.
 */
class Cercle : public Forme
{
private:
	Vecteur2D _centre; /**< Le centre du cercle. */
	double _rayon; /**< Le rayon du cercle. */

public:
	/**
	 * @brief Constructeur de la classe Cercle.
	 * @param centre Le centre du cercle.
	 * @param rayon Le rayon du cercle.
	 * @param couleur La couleur du cercle.
	 */
	Cercle(const Vecteur2D& centre, double rayon, Couleur couleur = COULEUR_PAR_DEFAUT)
		: Forme(couleur), _centre(centre), _rayon(rayon) 
	{
		// Si le rayon est négatif ou nul, on lance une exception.
		if (_rayon <= 0)
			throw invalid_argument("Le rayon doit être strictement positif.");
	}

	Cercle* clone() const override { return new Cercle(*this); }

	double aire() const override { return PI * _rayon * _rayon; }

	void translation(const Vecteur2D& vt) override;

	void homothetie(const Vecteur2D& centre, double k) override;

	void rotation(const Vecteur2D& centre, double angle) override;

	const Vecteur2D& centre() const { return _centre; }

	double rayon() const { return _rayon; }

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