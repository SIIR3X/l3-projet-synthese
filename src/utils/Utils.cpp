#include "utils/Utils.h"
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

void Utils::sauvegarderFormes(ofstream* fichier, VisiteurForme* visiteurForme, const vector<Forme*>& formes)
{
	// On sauvegarde le nombre de formes
	*fichier << formes.size() << endl;

	// On sauvegarde chaque forme dans le fichier
	for (Forme* forme : formes)
		forme->accepter(visiteurForme);
}