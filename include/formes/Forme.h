#ifndef FORME_H
#define FORME_H

#include <string>
#include <ostream>

using namespace std;

enum class Couleur { BLACK, BLUE, RED, GREEN, YELLOW, CYAN };

class Forme
{
protected:
	Couleur _couleur;

public:
	Forme(Couleur couleur)
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
}; // class Forme

#endif // FORME_H