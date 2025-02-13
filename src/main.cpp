#include "utils/Utils.h"
#include "formes/Groupe.h"
#include "graphique/Viewport.h"
#include "opengl/vue/FenetreOpenGL.h"
#include "opengl/controleur/ControleurFenetreOpenGL.h"
#include "design_patterns/cor/ChargeurFormeCOR.h"
#include "design_patterns/cor/ChargeurFormeCORCercle.h"
#include "design_patterns/cor/ChargeurFormeCORSegment.h"
#include "design_patterns/cor/ChargeurFormeCORTriangle.h"
#include "design_patterns/cor/ChargeurFormeCORPolygone.h"
#include "design_patterns/visiteur/VisiteurDessinerTCP.h"
#include "opengl/controleur/ControleurFenetreOpenGL.h"

void java(const vector<Forme*>& formes, Viewport& viewport)
{
	VisiteurDessinerTCP visiteur = VisiteurDessinerTCP(&viewport);

	// On crée un groupe avec les formes transformées
	Groupe* groupe = new Groupe(Utils::transformerFormesVersEcran(formes, viewport), Couleur::RED);

	// On dessine les formes
	groupe->accepter(&visiteur);

	delete groupe;
}

void opengl(const vector<Forme*>& formes, Viewport& viewport)
{
	VisiteurDessinerOpenGL visiteur = VisiteurDessinerOpenGL();

	// On crée un groupe avec les formes NON transformées (la classe ControleurFenetreOpenGL s'en charge)
	Groupe* groupe = new Groupe(formes, Couleur::RED);

	// On crée le controleur de la fenêtre OpenGL
	ControleurFenetreOpenGL controleur = ControleurFenetreOpenGL(*groupe, &viewport);
	controleur.initialiserFenetre(viewport.largeurEcran(), viewport.hauteurEcran(), "OpenGL");
	controleur.setGroupeFenetre();
	controleur.runFenetre();

	delete groupe;
}

int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		cerr << "Usage: " << argv[0] << " <largeur> <hauteur> <nom_fichier> <mode>" << endl;
		return 1;
	}

	const int largeur = stoi(argv[1]);
	const int hauteur = stoi(argv[2]);
	const string nomFichier = argv[3];
	const int mode = stoi(argv[4]);

	if (mode != 0 && mode != 1)
	{
		cerr << "Le mode doit être 0 ou 1." << endl;
		return 1;
	}

	// On charge les formes
	ChargeurFormeCOR* chargeur = new ChargeurFormeCORPolygone(new ChargeurFormeCORTriangle(new ChargeurFormeCORSegment(new ChargeurFormeCORCercle(nullptr))));
	vector<Forme*> formes = Utils::chargerFormes(nomFichier, chargeur);

	// On crée un viewport
	Viewport viewport = Viewport(Vecteur2D(-4, -4), Vecteur2D(4, 4), largeur, hauteur);

	if (mode == 0)
		opengl(formes, viewport);
	else
		java(formes, viewport);

	return 0;
}