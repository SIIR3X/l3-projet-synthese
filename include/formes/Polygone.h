#ifndef POLYGONE_H
#define POLYGONE_H

#include "formes/Forme.h"
#include <string>
#include <vector>
#include <ostream>
#include <stdexcept>
#include <algorithm>

using namespace std;

/**
 * @brief Classe représentant un polygone.
 */
class Polygone : public Forme
{
private:
	vector<Vecteur2D> _points; /**< Les sommets du polygone. */

public:
	/**
	 * @brief Constructeur de la classe Polygone.
	 * @param couleur La couleur du polygone.
	 */
	Polygone(Couleur couleur = COULEUR_PAR_DEFAUT) 
		: Forme(couleur) {}

	/**
	 * @brief Constructeur de la classe Polygone.
	 * @param points Les sommets du polygone.
	 * @param couleur La couleur du polygone.
	 */
	Polygone(const vector<Vecteur2D>& points, Couleur couleur = COULEUR_PAR_DEFAUT)
		: Forme(couleur), _points(points) 
	{
		// Si le polygone a moins de 4 sommets, on lance une exception.
		if (points.size() <= 3)
			throw invalid_argument("Un polygone doit avoir au moins 4 sommets.");
	}

	Polygone* clone() const override { return new Polygone(*this); }

	double aire() const override;

	void translation(const Vecteur2D& vt) override;

	void homothetie(const Vecteur2D& centre, double k) override;

	void rotation(const Vecteur2D& centre, double angle) override;

	void bornes(Vecteur2D& pmin, Vecteur2D& pmax) const override;

	Vecteur2D calculerCentre() const override;

	size_t nbPoints() const { return _points.size(); }

	const vector<Vecteur2D>& points() const { return _points; }

	const Vecteur2D& point(size_t index) const;

	const Vecteur2D& operator[](size_t index) const { return _points[index]; }

	/**
	 * @brief Ajoute un point au polygone.
	 * @param point Le point à ajouter.
	 */
	void ajouterPoint(const Vecteur2D& point);

	/**
	 * @brief Retire un point du polygone.
	 * @param index L'index du point à retirer.
	 */
	void retirerPoint(size_t index);

	operator string() const override;

	void accepter(VisiteurForme* visiteur) override { visiteur->visiter(this); }
}; // class Polygone

inline double Polygone::aire() const
{
	double aire = 0.0;

	// On parcours les sommets du polygone
	for (size_t i = 0; i < _points.size(); ++i)
	{
		// Puis on récupère les points successifs
		const Vecteur2D& p1 = _points[i];
		const Vecteur2D& p2 = _points[(i + 1) % _points.size()];

		// Et on ajoute le déterminant des points successifs à l'aire totale
		aire += p1.determinant(p2);
	}

	// On retourne la valeur absolue de l'aire divisée par 2
	return abs(aire) / 2.0;
}

inline void Polygone::translation(const Vecteur2D& vt)
{
	for (Vecteur2D& point : _points)
		point += vt;
}

inline void Polygone::bornes(Vecteur2D& pmin, Vecteur2D& pmax) const
{
	// On commence par initialiser les bornes minimales et maximales avec le premier sommet
	pmin = _points[0];
	pmax = _points[0];

	// On parcours ensuite les autres points du polygone
	for (const Vecteur2D& point : _points)
	{
		// Et on met à jour les bornes minimales et maximales
		pmin.x = min(pmin.x, point.x);
		pmin.y = min(pmin.y, point.y);
		pmax.x = max(pmax.x, point.x);
		pmax.y = max(pmax.y, point.y);
	}
}

inline Vecteur2D Polygone::calculerCentre() const
{
	Vecteur2D pmin, pmax;

	// On commence par calculer les bornes du polygone
	bornes(pmin, pmax);

	// Puis on calcule le centre du polygone
	return Vecteur2D((pmin.x + pmax.x) / 2, (pmin.y + pmax.y) / 2);
}

inline const Vecteur2D& Polygone::point(size_t index) const
{
	// Si l'index est hors limites, on lance une exception
	if (index >= _points.size())
		throw std::out_of_range("Index hors limites.");

	return _points[index];
}

inline void Polygone::ajouterPoint(const Vecteur2D& point)
{
	// On parcoure la liste des points du polygone
	for (const Vecteur2D& p : _points)
	{
		// Si le point est déjà présent dans le polygone, on lance une exception
		if (p == point)
			throw std::invalid_argument("Le point est déjà présent dans le polygone.");
	}

	// On ajoute le point au polygone
	_points.push_back(point);
}

inline void Polygone::retirerPoint(size_t index)
{
	// Si l'index est hors limites, on lance une exception
	if (index >= _points.size())
		throw std::out_of_range("Index hors limites.");

	// On retire le point du polygone
	_points.erase(_points.begin() + index);
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