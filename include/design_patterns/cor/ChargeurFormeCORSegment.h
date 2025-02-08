#ifndef CHARGEUR_FORME_COR_SEGMENT_H
#define CHARGEUR_FORME_COR_SEGMENT_H

#include "design_patterns/cor/ChargeurFormeCOR.h"

class ChargeurFormeCORSegment : public ChargeurFormeCOR
{
public:
	ChargeurFormeCORSegment(ChargeurForme* suivant) 
		: ChargeurFormeCOR(suivant) {}

	Forme* chargerTXT(const char* ligne) const override;
}; // class ChargeurFormeCORSegment

#endif // CHARGEUR_FORME_COR_SEGMENT_H