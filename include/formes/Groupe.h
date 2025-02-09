#ifndef GROUPE_H
#define GROUPE_H

#include "formes/Forme.h"
#include <string>
#include <vector>
#include <ostream>
#include <stdexcept>

using namespace std;

/**
 * @brief Classe représentant un groupe de formes.
 */
class Groupe : public Forme
{
private:
	vector<Forme*> _formes; /**< Les formes du groupe. */

public:
	/**
	 * @brief Constructeur de la classe Groupe.
	 * @param formes Les formes du groupe.
	 * @param couleur La couleur du groupe.
	 */
	Groupe(const vector<Forme*>& formes, Couleur couleur = COULEUR_PAR_DEFAUT)
		: Forme(couleur), _formes(formes) {}

	/**
	 * @brief Constructeur par copie de la classe Groupe.
	 * @param groupe Le groupe à copier.
	 */
	Groupe(const Groupe& groupe);

	/**
	 * @brief Destructeur de la classe Groupe.
	 * Libère la mémoire allouée dynamiquement pour les formes.
	 */
	~Groupe();

	Groupe* clone() const override { return new Groupe(*this); }

	double aire() const override;

	void translation(const Vecteur2D& vt) override;

	void homothetie(const Vecteur2D& centre, double k) override;

	void rotation(const Vecteur2D& centre, double angle) override;

	size_t nbFormes() const { return _formes.size(); }

	const vector<Forme*>& formes() const { return _formes; }

	const Forme* forme(size_t index) const;

	const Forme* operator[](size_t index) const { return _formes[index]; }

	/**
	 * @brief Ajoute une forme au groupe.
	 * @param forme La forme à ajouter.
	 */
	void ajouterForme(Forme& forme);

	/**
	 * @brief Retire une forme du groupe.
	 * @param index L'index de la forme à retirer.
	 */
	void retirerForme(size_t index);

	operator string() const override;

	void accepter(VisiteurForme* visiteur) override { visiteur->visiter(this); }
}; // class Groupe

inline Groupe::Groupe(const Groupe& groupe)
	: Forme(groupe)
{
	for (Forme* forme : groupe._formes)
		_formes.push_back(forme->clone());
}

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

inline void Groupe::translation(const Vecteur2D& vt)
{
	for (Forme* forme : _formes)
		forme->translation(vt);
}

inline void Groupe::homothetie(const Vecteur2D& centre, double k)
{
	for (Forme* forme : _formes)
		forme->homothetie(centre, k);
}

inline void Groupe::rotation(const Vecteur2D& centre, double angle)
{
	for (Forme* forme : _formes)
		forme->rotation(centre, angle);
}

inline const Forme* Groupe::forme(size_t index) const
{
	// Si l'index est hors limites, on lance une exception
	if (index >= _formes.size())
		throw out_of_range("Index hors limites.");

	return _formes[index];
}

inline void Groupe::ajouterForme(Forme& forme)
{
	// Si la forme appartient déjà à un groupe, on lance une exception
	if (forme.groupe() != nullptr)
		throw invalid_argument("La forme appartient déjà à un groupe.");

	// On met à jour le groupe de la forme
	forme.setGroupe(this);

	// Puis on ajoute la forme au vecteur
	_formes.push_back(forme.clone());
}

inline void Groupe::retirerForme(size_t index)
{
	// Si l'index est hors limites, on lance une exception
	if (index >= _formes.size())
		throw out_of_range("Index hors limites.");
	
	// On supprime la forme à l'index donné
	delete _formes[index];

	// Puis on retire la forme du vecteur
	_formes.erase(_formes.begin() + index);
}

inline Groupe::operator string() const
{
	ostringstream oss;

	oss << nbFormes() << endl;
	for (const Forme* forme : _formes)
		oss << string(*forme) << endl;

	return oss.str();
}

#endif // GROUPE_H