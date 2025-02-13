#include "formes/Forme.h"
#include "formes/Groupe.h"

void Forme::setGroupe(Groupe* groupe)
{
	_groupe = groupe;
	_couleur = groupe->couleur();
}