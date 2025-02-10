#include "formes/Cercle.h"
#include "formes/Segment.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "formes/Groupe.h"
#include "design_patterns/visiteur/VisiteurDessinerTCP.h"
#include <iostream>

void VisiteurDessinerTCP::visiter(Cercle* c)
{
	envoyerFormeSimple(c);
}

void VisiteurDessinerTCP::visiter(Segment* s)
{
	envoyerFormeSimple(s);
}

void VisiteurDessinerTCP::visiter(Triangle* t)
{
	envoyerFormeSimple(t);
}

void VisiteurDessinerTCP::visiter(Polygone* p)
{
	envoyerFormeSimple(p);
}

void VisiteurDessinerTCP::visiter(Groupe* g)
{
	// On se connecte au serveur
	_client.connect_to_server();

	// On commence par envoyer l'entête du groupe
	envoyerPaquet(creerEntete(g->couleur()));

	// On met le flag à true pour ne pas envoyer l'entête à chaque forme
	_dansGroupe = true;

	// On visite chaque forme du groupe
	for (Forme* f : g->formes())
		f->accepter(this);

	// On remet le flag à false
	_dansGroupe = false;

	// On se déconnecte du serveur
	_client.shutdown_connection();
}