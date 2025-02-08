#ifndef CHARTEUR_FORME_COR_H
#define CHARTEUR_FORME_COR_H

#include "design_patterns/cor/ChargeurForme.h"
#include <sstream>

class ChargeurFormeCOR : public ChargeurForme
{
protected:
	ChargeurForme* suivant;

	int recupererNbPoints(const char* ligne) const;

public:
	ChargeurFormeCOR(ChargeurForme* suivant)
	{
		this->suivant = suivant;
	}

	Forme* charger(const char* ligne) const override;

	virtual Forme* chargerTXT(const char* ligne) const = 0;
}; // class ChargeurFormeCOR

inline Forme* ChargeurFormeCOR::charger(const char* ligne) const
{
	Forme* forme = chargerTXT(ligne);

	if (forme == nullptr && suivant != nullptr)
		forme = suivant->charger(ligne);

	return forme;
}

inline int ChargeurFormeCOR::recupererNbPoints(const char* ligne) const
{
	int nbPoints;

	if (sscanf(ligne, "%*d %d", &nbPoints) != 1)
		return -1;

	return nbPoints;
}

#endif // CHARTEUR_FORME_COR_H