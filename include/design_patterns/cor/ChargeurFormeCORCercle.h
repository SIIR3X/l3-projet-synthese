#ifndef CHARTEUR_FORME_COR_CERCLE_H
#define CHARTEUR_FORME_COR_CERCLE_H

#include "design_patterns/cor/ChargeurFormeCOR.h"

class ChargeurFormeCORCercle : public ChargeurFormeCOR
{
public:
	ChargeurFormeCORCercle(ChargeurFormeCOR* suivant)
		: ChargeurFormeCOR(suivant) {}

	Forme* chargerTXT(const char* ligne) const override;
}; // class ChargeurFormeCORCercle

#endif // CHARTEUR_FORME_COR_CERCLE_H