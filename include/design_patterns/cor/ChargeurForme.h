#ifndef CHARGEUR_FORME_H
#define CHARGEUR_FORME_H

#include "formes/Forme.h"

/**
 * @brief Classe abstraite ChargeurForme permettant de charger une forme à partir d'une chaîne de caractères.
 */
class ChargeurForme
{
public:
	/**
	 * @brief Charge une forme à partir d'une chaîne de caractères.
	 * @param ligne Chaîne de caractères.
	 * @return Pointeur vers la forme créée.
	 */
	virtual Forme* charger(const char* ligne) const = 0;
}; // class ChargeurForme

#endif // CHARGEUR_FORME_H