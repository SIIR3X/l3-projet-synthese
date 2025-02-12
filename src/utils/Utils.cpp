#include "utils/Utils.h"
#include "formes/Groupe.h"
#include <fstream>

vector<Forme*> Utils::chargerFormes(const string& nomFichier, ChargeurFormeCOR* chargeurFormeCOR)
{
	// On crée un vecteur de formes
	vector<Forme*> formes;

	// On ouvre le fichier
	ifstream fichier(nomFichier);

	// Si le fichier n'a pas pu être ouvert, on lance une exception
	if (!fichier)
		throw runtime_error("Impossible d'ouvrir le fichier " + nomFichier);

	string ligne;

	// On lit le fichier ligne par ligne
	while (getline(fichier, ligne))
	{
		// On charge la forme à partir de la ligne
		Forme* forme = chargeurFormeCOR->charger(ligne.c_str());

		// Si la forme n'est pas nulle, on l'ajoute au vecteur
		if (forme != nullptr)
			formes.push_back(forme);
	}

	// On ferme le fichier
	fichier.close();

	return formes;
}

void Utils::sauvegarderFormes(const vector<Forme*>& formes, VisiteurForme* visiteurForme)
{
	// On sauvegarde chaque forme dans le fichier
	for (Forme* forme : formes)
		forme->accepter(visiteurForme);
}

vector<Forme*> Utils::transformerFormesVersEcran(const vector<Forme*>& formes, const Viewport& viewport)
{
	// On crée un vecteur de formes transformées
	vector<Forme*> formesTransformees;

	// On transforme chaque forme du monde vers l'écran
	for (Forme* forme : formes)
		formesTransformees.push_back(viewport.formeVersEcran(*forme));

	return formesTransformees;
}

void Utils::centrerGroupe(Groupe* groupe, const Vecteur2D& centre)
{
	// On récupère le centre du groupe
	Vecteur2D centreGroupe = groupe->calculerCentre();

	// On calcule le vecteur de translation
	Vecteur2D translation(centre.x - centreGroupe.x, centre.y - centreGroupe.y);

	// On centre le groupe
	groupe->translation(translation);
}