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
	// On ouvre le fichier
	ouvrirFichier();

	// On met le flag à true pour indiquer qu'on est dans un groupe
	_dansGroupe = true;

	// Sauvegarde des formes du groupe
	for (Forme* f : g->formes())
		f->accepter(this);

	// On remet le flag à false
	_dansGroupe = false;

	// On ferme le fichier
	fermerFichier();
}