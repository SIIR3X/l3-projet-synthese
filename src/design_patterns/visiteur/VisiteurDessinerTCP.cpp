#include "formes/Cercle.h"
#include "formes/Segment.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "formes/Groupe.h"
#include "design_patterns/visiteur/VisiteurDessinerTCP.h"
#include <iostream>

void VisiteurDessinerTCP::visiter(Cercle* c)
{
	_buffer << string(*c) << endl;

	// Si on n'est pas dans un groupe, on envoie les données (évite les envois multiples)
	if (!_dansGroupe)
		envoyerDonnees();
}

void VisiteurDessinerTCP::visiter(Segment* s)
{
	_buffer << string(*s) << endl;

	// Si on n'est pas dans un groupe, on envoie les données (évite les envois multiples)
	if (!_dansGroupe)
		envoyerDonnees();
}

void VisiteurDessinerTCP::visiter(Triangle* t)
{
	_buffer << string(*t) << endl;

	// Si on n'est pas dans un groupe, on envoie les données (évite les envois multiples)
	if (!_dansGroupe)
		envoyerDonnees();
}

void VisiteurDessinerTCP::visiter(Polygone* p)
{
	_buffer << string(*p) << endl;

	// Si on n'est pas dans un groupe, on envoie les données (évite les envois multiples)
	if (!_dansGroupe)
		envoyerDonnees();
}

void VisiteurDessinerTCP::visiter(Groupe* g)
{
	// On met le flag à true pour ne pas envoyer les données à chaque forme (évite les envois multiples)
	_dansGroupe = true;

	// On visite chaque forme du groupe
	for (Forme* f : g->formes())
		f->accepter(this);

	// On remet le flag à false pour pouvoir envoyer les données
	_dansGroupe = false;

	// On envoie les données
	envoyerDonnees();
}