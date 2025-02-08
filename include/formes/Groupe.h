#ifndef GROUPE_H
#define GROUPE_H

#include "formes/Forme.h"
#include <vector>
#include <sstream>
#include <stdexcept>

class Groupe : public Forme
{
private:
	vector<Forme*> _formes;

public:
	Groupe(Couleur couleur)
		: Forme(couleur) {}

	~Groupe();

	Groupe* clone() const override { return new Groupe(*this); }

	double aire() const override;

	size_t getNbFormes() const { return _formes.size(); }

	const Forme* getForme(size_t index) const;

	const Forme* operator[](size_t index) const { return _formes[index]; }

	void ajouterForme(const Forme& forme) { _formes.push_back(forme.clone()); }

	void retirerForme(size_t index);

	operator string() const override;

}; // class Groupe

inline Groupe::~Groupe()
{
	for (vector<Forme*>::iterator it = _formes.begin(); it != _formes.end(); ++it)
		delete *it;

	_formes.clear();
}

inline double Groupe::aire() const
{
	double aireTotale = 0.0;
	
	for (vector<Forme*>::const_iterator it = _formes.begin(); it != _formes.end(); ++it)
		aireTotale += (*it)->aire();

	return aireTotale;
}

inline const Forme* Groupe::getForme(size_t index) const
{
	if (index < _formes.size())
		return _formes[index];
	
	throw out_of_range("Index hors limites.");
}

inline void Groupe::retirerForme(size_t index)
{
	if (index < _formes.size())
	{
		delete _formes[index];
		_formes.erase(_formes.begin() + index);
	}
	
	throw out_of_range("Index hors limites.");
}

inline Groupe::operator string() const
{
	ostringstream oss;

	oss << "Groupe [Couleur : " + to_string(static_cast<int>(_couleur)) + "] :\n";
	for (vector<Forme*>::const_iterator it = _formes.begin(); it != _formes.end(); ++it)
		oss << "  " << **it << "\n";

	return oss.str();
}

#endif // GROUPE_H