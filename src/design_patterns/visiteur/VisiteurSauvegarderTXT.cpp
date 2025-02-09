#include "formes/Segment.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "formes/Cercle.h"
#include "formes/Groupe.h"
#include "design_patterns/visiteur/VisiteurSauvegarderTXT.h"

void VisiteurSauvegarderTXT::visiter(Cercle* c)
{
	// Sauvegarde du cercle
	sauvegarderFormeSimple(c);
}

void VisiteurSauvegarderTXT::visiter(Segment* s)
{
	// Sauvegarde du segment
	sauvegarderFormeSimple(s);
}

void VisiteurSauvegarderTXT::visiter(Triangle* t)
{
	// Sauvegarde du triangle
	sauvegarderFormeSimple(t);
}

void VisiteurSauvegarderTXT::visiter(Polygone* p)
{
	// Sauvegarde du polygone
	sauvegarderFormeSimple(p);
}

void VisiteurSauvegarderTXT::visiter(Groupe* g)
{
	// Sauvegarde des formes du groupe
	for (const Forme* f : g->formes())
		sauvegarderFormeSimple(f);
}