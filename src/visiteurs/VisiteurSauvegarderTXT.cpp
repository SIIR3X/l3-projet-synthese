#include "formes/Segment.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "formes/Cercle.h"
#include "formes/Groupe.h"
#include "visiteurs/VisiteurSauvegarderTXT.h"

void VisiteurSauvegarderTXT::visiter(Segment* s)
{
	sauvegarderFormeSimple(s);
}

void VisiteurSauvegarderTXT::visiter(Triangle* t)
{
	sauvegarderFormeSimple(t);
}

void VisiteurSauvegarderTXT::visiter(Polygone* p)
{
	sauvegarderFormeSimple(p);
}

void VisiteurSauvegarderTXT::visiter(Cercle* c)
{
	sauvegarderFormeSimple(c);
}

void VisiteurSauvegarderTXT::visiter(Groupe* g)
{
	_fichier << g->getNbFormes() << endl;

	for (const Forme* f : g->getFormes())
		sauvegarderFormeSimple(f);
}

void VisiteurSauvegarderTXT::sauvegarderFormeSimple(const Forme* fs)
{
	string str = string(*fs);
	
	_fichier << str.length() << " " << str << endl;
}