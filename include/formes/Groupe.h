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
	Groupe(const vector<Forme*>& formes, Couleur couleur = COULEUR_PAR_DEFAUT)
		: Forme(couleur), _formes(formes) {}

	~Groupe();

	Groupe* clone() const override { return new Groupe(*this); }

	double aire() const override;

	size_t getNbFormes() const { return _formes.size(); }

	const vector<Forme*>& getFormes() const { return _formes; }

	const Forme* getForme(size_t index) const;

	const Forme* operator[](size_t index) const { return _formes[index]; }

	void ajouterForme(const Forme& forme) { _formes.push_back(forme.clone()); }

	void retirerForme(size_t index);

	operator string() const override;

	void accepter(VisiteurForme* visiteur) override { visiteur->visiter(this); }
}; // class Groupe

inline Groupe::~Groupe()
{
	for (Forme* forme : _formes)
		delete forme;

	_formes.clear();
}

inline double Groupe::aire() const
{
	double aireTotale = 0.0;
	
	for (const Forme* forme : _formes)
		aireTotale += forme->aire();

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

	oss << getNbFormes() << endl;
	for (const Forme* forme : _formes)
		oss << string(*forme) << endl;

	return oss.str();
}

#endif // GROUPE_H