#ifndef VISITEUR_DESSINER_TCP_H
#define VISITEUR_DESSINER_TCP_H

#include "visiteurs/VisiteurForme.h"

class VisiteurDessinerTCP : public VisiteurForme
{
public:
	virtual void visiter(Segment* s) override;
	virtual void visiter(Triangle* t) override;
	virtual void visiter(Polygone* p) override;
	virtual void visiter(Cercle* c) override;
	virtual void visiter(Groupe* g) override;
}; // class VisiteurDessinerTCP

#endif // VISITEUR_DESSINER_TCP_H