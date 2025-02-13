#ifndef VISITEUR_DESSINER_OPENGL_H
#define VISITEUR_DESSINER_OPENGL_H

#include "design_patterns/visiteur/VisiteurForme.h"

class FenetreOpenGL;

class VisiteurDessinerOpenGL : public VisiteurForme
{
private:
	FenetreOpenGL* _fenetre;

public:
	virtual void visiter(Cercle* c) override;
	virtual void visiter(Segment* s) override;
	virtual void visiter(Triangle* t) override;
	virtual void visiter(Polygone* p) override;
	virtual void visiter(Groupe* g) override;
}; // class VisiteurDessinerOpenGL

#endif // VISITEUR_DESSINER_OPENGL_H