#ifndef FORME_H
#define FORME_H

#include "geometrie/Vecteur2D.h"
#include "design_patterns/visiteur/VisiteurForme.h"
#include <string>
#include <ostream>

using namespace std;

class Groupe;

/**
 * @brief Énumération des couleurs possibles pour une forme.
 */
enum class Couleur { BLACK, BLUE, RED, GREEN, YELLOW, CYAN };

/**
 * @brief Couleur par défaut pour une forme.
 */
const Couleur COULEUR_PAR_DEFAUT = Couleur::BLACK;

/**
 * @brief Classe abstraite représentant une forme géométrique.
 */
class Forme
{
private:
	Couleur _couleur; /**< La couleur de la forme. */
	Groupe* _groupe; /**< Pointeur vers le groupe contenant la forme. */

protected:
	/**
	 * @brief Applique une homothétie à un point.
	 * @param point Le point à transformer.
	 * @param centre Le centre de l'homothétie.
	 * @param k Le facteur d'homothétie.
	 */
	void appliquerHomothetie(Vecteur2D& point, const Vecteur2D& centre, double k) const;

	/**
	 * @brief Applique une rotation à un point.
	 * @param point Le point à transformer.
	 * @param centre Le centre de la rotation.
	 * @param cosA Le cosinus de l'angle de rotation.
	 * @param sinA Le sinus de l'angle de rotation.
	 */
	void appliquerRotation(Vecteur2D& point, const Vecteur2D& centre, double cosA, double sinA) const;

public:
	/**
	 * @brief Constructeur de la classe Forme.
	 * @param couleur La couleur de la forme.
	 */
	Forme(Couleur couleur = COULEUR_PAR_DEFAUT)
		: _couleur(couleur), _groupe(nullptr) {}

	virtual ~Forme() = default;

	/**
	 * @brief Retourne une copie de la forme.
	 * @return Un pointeur vers la copie de la forme.
	 */
	virtual Forme* clone() const = 0;

	/**
	 * @brief Calcule l'aire de la forme.
	 * @return L'aire de la forme.
	 */
	virtual double aire() const = 0;

	/**
	 * @brief Réalise une translation de la forme.
	 * @param vt Le vecteur de translation.
	 */
	virtual void translation(const Vecteur2D& vt) = 0;

	/**
	 * @brief Réalise une homothétie de la forme.
	 * @param centre Le centre de l'homothétie.
	 * @param k Le facteur d'homothétie.
	 */
	virtual void homothetie(const Vecteur2D& centre, double k) = 0;

	/**
	 * @brief Réalise une rotation de la forme.
	 * @param centre Le centre de la rotation.
	 * @param angle L'angle de rotation.
	 */
	virtual void rotation(const Vecteur2D& centre, double angle) = 0;

	Groupe* groupe() const { return _groupe; }

	void setGroupe(Groupe* groupe) { _groupe = groupe; }

	Couleur couleur() const { return _couleur; }

	virtual operator string() const = 0;

	friend ostream& operator<<(ostream& os, const Forme& forme)
	{
		return os << string(forme);
	}

	/**
	 * @brief Accepte un visiteur pour la forme.
	 * @param visiteur Le visiteur à accepter.
	 */
	virtual void accepter(VisiteurForme* visiteur) = 0;
}; // class Forme

#endif // FORME_H