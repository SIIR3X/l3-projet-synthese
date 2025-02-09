#ifndef CHARTEUR_FORME_COR_TRIANGLE_H
#define CHARTEUR_FORME_COR_TRIANGLE_H

#include "design_patterns/cor/ChargeurFormeCOR.h"

class ChargeurFormeCORTriangle : public ChargeurFormeCOR
{
public:
	ChargeurFormeCORTriangle(ChargeurFormeCOR* suivant) 
		: ChargeurFormeCOR(suivant) {}

	Forme* chargerTXT(const char* ligne) const override;
}; // class ChargeurFormeCORTriangle

#endif // CHARTEUR_FORME_COR_TRIANGLE_H