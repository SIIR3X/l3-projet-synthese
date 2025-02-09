#include "formes/Segment.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "formes/Cercle.h"
#include "formes/Groupe.h"
#include "design_patterns/visiteur/VisiteurSauvegarderTXT.h"

void VisiteurSauvegarderTXT::visiter(Cercle* c)
{
	// Sauvegarde du nombre de points du cercle
	sauvegarderNbPoints(1);

	// Sauvegarde du cercle
	sauvegarderFormeSimple(c);
}

void VisiteurSauvegarderTXT::visiter(Segment* s)
{
	// Sauvegarde du nombre de points du segment
	sauvegarderNbPoints(2);

	// Sauvegarde du segment
	sauvegarderFormeSimple(s);
}

void VisiteurSauvegarderTXT::visiter(Triangle* t)
{
	// Sauvegarde du nombre de points du triangle
	sauvegarderNbPoints(3);

	// Sauvegarde du triangle
	sauvegarderFormeSimple(t);
}

void VisiteurSauvegarderTXT::visiter(Polygone* p)
{
	// Sauvegarde du nombre de points du polygone
	sauvegarderNbPoints(p->nbPoints());

	// Sauvegarde du polygone
	sauvegarderFormeSimple(p);
}

void VisiteurSauvegarderTXT::visiter(Groupe* g)
{
	// Sauvegarde du nombre de formes du groupe
	_fichier << g->nbFormes() << endl;

	// Sauvegarde des formes du groupe
	for (const Forme* f : g->formes())
		sauvegarderFormeSimple(f);
}