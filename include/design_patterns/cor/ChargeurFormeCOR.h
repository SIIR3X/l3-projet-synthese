#ifndef CHARTEUR_FORME_COR_H
#define CHARTEUR_FORME_COR_H

#include "design_patterns/cor/ChargeurForme.h"
#include <sstream>

class ChargeurFormeCOR : public ChargeurForme
{
private:
	ChargeurFormeCOR* _suivant;

protected:
	int recupererNbPoints(const char* ligne) const;

public:
	ChargeurFormeCOR(ChargeurFormeCOR* _suivant)
	{
		this->_suivant = _suivant;
	}

	Forme* charger(const char* ligne) const override;

	virtual Forme* chargerTXT(const char* ligne) const = 0;
}; // class ChargeurFormeCOR

inline Forme* ChargeurFormeCOR::charger(const char* ligne) const
{
	Forme* forme = chargerTXT(ligne);

	if (forme == nullptr && _suivant != nullptr)
		forme = _suivant->charger(ligne);

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