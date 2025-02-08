#ifndef FORME_H
#define FORME_H

#include "visiteurs/VisiteurForme.h"
#include <string>
#include <ostream>

using namespace std;

enum class Couleur { BLACK, BLUE, RED, GREEN, YELLOW, CYAN };

const Couleur COULEUR_PAR_DEFAUT = Couleur::BLACK;

class Forme
{
protected:
	Couleur _couleur;

public:
	Forme(Couleur couleur = COULEUR_PAR_DEFAUT)
		: _couleur(couleur) {}

	virtual ~Forme() = default;

	virtual Forme* clone() const = 0;

	virtual double aire() const = 0;

	Couleur getCouleur() const { return _couleur; }

	virtual operator string() const = 0;

	friend ostream& operator<<(ostream& os, const Forme& forme)
	{
		return os << string(forme);
	}

	virtual void accepter(VisiteurForme* visiteur) = 0;
}; // class Forme

#endif // FORME_H