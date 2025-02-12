#include <vector>
#include <fstream>
#include <iostream>

#include "utils/Utils.h"

#include "design_patterns/cor/ChargeurFormeCOR.h"
#include "design_patterns/cor/ChargeurFormeCORCercle.h"
#include "design_patterns/cor/ChargeurFormeCORSegment.h"
#include "design_patterns/cor/ChargeurFormeCORTriangle.h"
#include "design_patterns/cor/ChargeurFormeCORPolygone.h"

#include "design_patterns/visiteur/VisiteurDessinerTCP.h"

#include "graphique/Viewport.h"

#include "formes/Groupe.h"

int main(void)
{
	string nomFichier = "data/tortue/faces.txt";

	ChargeurFormeCOR* chargeur = new ChargeurFormeCORCercle(new ChargeurFormeCORSegment(new ChargeurFormeCORTriangle(new ChargeurFormeCORPolygone(nullptr))));
	vector<Forme*> formes = Utils::chargerFormes(nomFichier, chargeur);

	Viewport viewport = Viewport(Vecteur2D(-5, -5), Vecteur2D(5, 5), 1000, 1000);
	vector<Forme*> formesTransformees = Utils::transformerFormesVersEcran(viewport, formes);
	Groupe* groupe = new Groupe(formesTransformees);

	VisiteurDessinerTCP visiteur = VisiteurDessinerTCP(&viewport);
	groupe->accepter(&visiteur);

	return 0;
}