#include "formes/Segment.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "formes/Cercle.h"
#include "formes/Groupe.h"
#include "visiteurs/VisiteurDessinerTCP.h"
#include <iostream>

void VisiteurDessinerTCP::visiter(Segment* /*s*/)
{
	cout << "Dessiner un segment" << endl;
}

void VisiteurDessinerTCP::visiter(Triangle* /*t*/)
{
	cout << "Dessiner un triangle" << endl;
}

void VisiteurDessinerTCP::visiter(Polygone* /*p*/)
{
	cout << "Dessiner un polygone" << endl;
}

void VisiteurDessinerTCP::visiter(Cercle* /*c*/)
{
	cout << "Dessiner un cercle" << endl;
}

void VisiteurDessinerTCP::visiter(Groupe* /*g*/)
{
	cout << "Dessiner un groupe" << endl;
}