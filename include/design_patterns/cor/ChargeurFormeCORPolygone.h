#ifndef CHARTEUR_FORME_COR_POLYGONE_H
#define CHARTEUR_FORME_COR_POLYGONE_H

#include "design_patterns/cor/ChargeurFormeCOR.h"

class ChargeurFormeCORPolygone : public ChargeurFormeCOR
{
public:
	ChargeurFormeCORPolygone(ChargeurForme* suivant) 
		: ChargeurFormeCOR(suivant) {}

	Forme* chargerTXT(const char* ligne) const override;
}; // class ChargeurFormeCORPolygone

#endif // CHARTEUR_FORME_COR_POLYGONE_H