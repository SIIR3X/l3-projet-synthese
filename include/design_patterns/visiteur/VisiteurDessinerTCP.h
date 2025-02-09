#ifndef VISITEUR_DESSINER_TCP_H
#define VISITEUR_DESSINER_TCP_H

#include "design_patterns/visiteur/VisiteurForme.h"

using namespace std;

/**
 * @brief Classe VisiteurDessinerTCP permettant de dessiner des formes en TCP.
 */
class VisiteurDessinerTCP : public VisiteurForme
{
public:
	virtual void visiter(Cercle* c) override;
	virtual void visiter(Segment* s) override;
	virtual void visiter(Triangle* t) override;
	virtual void visiter(Polygone* p) override;
	virtual void visiter(Groupe* g) override;
}; // class VisiteurDessinerTCP

#endif // VISITEUR_DESSINER_TCP_H