#include "formes/Forme.h"
#include "formes/Groupe.h"

void Forme::setGroupe(Groupe* groupe)
{
	// On met à jour le groupe de la forme et sa couleur
	_groupe = groupe;
	_couleur = groupe->couleur();
}