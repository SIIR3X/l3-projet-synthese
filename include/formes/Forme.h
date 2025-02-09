#ifndef FORME_H
#define FORME_H

#include "design_patterns/visiteur/VisiteurForme.h"
#include <string>
#include <ostream>

using namespace std;

class Groupe;

enum class Couleur { BLACK, BLUE, RED, GREEN, YELLOW, CYAN };

const Couleur COULEUR_PAR_DEFAUT = Couleur::BLACK;

class Forme
{
private:
	Groupe* _groupe;
	Couleur _couleur;

public:
	Forme(Couleur couleur = COULEUR_PAR_DEFAUT)
		: _couleur(couleur), _groupe(nullptr) {}

	virtual ~Forme() = default;

	virtual Forme* clone() const = 0;

	virtual double aire() const = 0;

	virtual void translation(const Vecteur2D& v) = 0;

	virtual void rotation(const Vecteur2D& centre, double angle) = 0;

	Groupe* getGroupe() const { return _groupe; }

	void setGroupe(Groupe* groupe) { _groupe = groupe; }

	Couleur getCouleur() const { return _couleur; }

	virtual operator string() const = 0;

	friend ostream& operator<<(ostream& os, const Forme& forme)
	{
		return os << string(forme);
	}

	virtual void accepter(VisiteurForme* visiteur) = 0;
}; // class Forme

#endif // FORME_H