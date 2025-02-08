#ifndef CHARGEUR_FORME_H
#define CHARGEUR_FORME_H

#include "formes/Forme.h"

class ChargeurForme
{
public:
	virtual Forme* charger(const char* ligne) const = 0;
}; // class ChargeurForme

#endif // CHARGEUR_FORME_H