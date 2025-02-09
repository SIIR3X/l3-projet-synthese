#ifndef CHARTEUR_FORME_COR_H
#define CHARTEUR_FORME_COR_H

#include "design_patterns/cor/ChargeurForme.h"
#include <sstream>

/**
 * @brief Classe abstraite ChargeurFormeCOR permettant de charger une forme à partir d'une chaîne de caractères.
 */
class ChargeurFormeCOR : public ChargeurForme
{
private:
	ChargeurFormeCOR* _suivant; /**< Chargeur suivant dans la chaîne de responsabilité. */

protected:
	/**
	 * @brief Récupère le nombre de points d'une forme à partir d'une chaîne de caractères.
	 * @param ligne Chaîne de caractères.
	 * @return Nombre de points de la forme.
	 */
	int recupererNbPoints(const char* ligne) const;

public:
	/**
	 * @brief Constructeur de ChargeurFormeCOR.
	 * @param _suivant Chargeur suivant dans la chaîne de responsabilité.
	 */
	ChargeurFormeCOR(ChargeurFormeCOR* _suivant);

	Forme* charger(const char* ligne) const override;

	/**
	 * @brief Charge une forme à partir d'une chaîne de caractères.
	 * @param ligne Chaîne de caractères.
	 * @return Pointeur vers la forme créée.
	 */
	virtual Forme* chargerTXT(const char* ligne) const = 0;
}; // class ChargeurFormeCOR

inline ChargeurFormeCOR::ChargeurFormeCOR(ChargeurFormeCOR* suivant) 
	: _suivant(suivant) {}

inline Forme* ChargeurFormeCOR::charger(const char* ligne) const
{
	Forme* forme = chargerTXT(ligne);

	// Si la forme n'a pas été chargée et qu'il y a un chargeur suivant, on le charge
	if (forme == nullptr && _suivant != nullptr)
		forme = _suivant->charger(ligne);

	return forme;
}

inline int ChargeurFormeCOR::recupererNbPoints(const char* ligne) const
{
	int nbPoints;

	// On récupère le nombre de points de la forme
	if (sscanf(ligne, "%*d %d", &nbPoints) != 1)
		return -1;

	return nbPoints;
}

#endif // CHARTEUR_FORME_COR_H