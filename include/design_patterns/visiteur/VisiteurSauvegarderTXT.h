#ifndef VISITEUR_SAUVEGARDER_TXT_H
#define VISITEUR_SAUVEGARDER_TXT_H

#include "design_patterns/visiteur/VisiteurForme.h"
#include <string>
#include <fstream>

using namespace std;

#define TAILLE_BUFFER 256 /**< Taille du buffer pour la conversion de la forme en chaîne de caractères. */

/**
 * @brief Classe VisiteurSauvegarderTXT permettant de sauvegarder des formes dans un fichier texte.
 */
class VisiteurSauvegarderTXT : public VisiteurForme
{
private:
	string _nomFichier; /**< Nom du fichier de sauvegarde. */
	bool _dansGroupe = false; /**< Flag indiquant si on est dans un groupe. */
	ofstream* _fichier = nullptr; /**< Fichier de sauvegarde. */

	/**
	 * @brief Sauvegarde une forme simple dans un fichier.
	 * @param fs Forme simple à sauvegarder.
	 */
	void sauvegarderFormeSimple(const Forme* fs);

	/**
	 * @brief Ouvre le fichier de sauvegarde.
	 */
	void ouvrirFichier();

	/**
	 * @brief Ferme le fichier de sauvegarde.
	 */
	void fermerFichier();

public:
	/**
	 * @brief Constructeur de la classe VisiteurSauvegarderTXT.
	 * @param nomFichier Nom du fichier de sauvegarde.
	 */
	VisiteurSauvegarderTXT(const string& nomFichier) 
		: _nomFichier(nomFichier) {}
	
	/**
	 * @brief Destructeur de la classe VisiteurSauvegarderTXT.
	 * Ferme le fichier si ce n'est pas déjà fait.
	 */
	virtual ~VisiteurSauvegarderTXT() override
	{
		// On ferme le fichier si ce n'est pas déjà fait
		fermerFichier();
	}

	void setNomFichier (const string& nomFichier) { _nomFichier = nomFichier; }

	virtual void visiter(Cercle* c) override;
	virtual void visiter(Segment* s) override;
	virtual void visiter(Triangle* t) override;
	virtual void visiter(Polygone* p) override;
	virtual void visiter(Groupe* g) override;
}; // class VisiteurSauvegarderTXT

inline void VisiteurSauvegarderTXT::sauvegarderFormeSimple(const Forme* fs)
{
	if (_fichier == nullptr || !_fichier->is_open())
		throw invalid_argument("Impossible de sauvegarder la forme simple : fichier non ouvert.");

	// Buffer pour la conversion de la forme simple en chaîne de caractères
	char buffer[TAILLE_BUFFER];

	// Conversion de la forme simple en chaîne de caractères
	int length = snprintf(buffer, sizeof(buffer), "%s\n", string(*fs).c_str());
	
	// Si la longueur est supérieure à 0, on écrit dans le fichier
	if (length > 0)
		_fichier->write(buffer, length);

	// Si la forme n'est pas dans un groupe, on ferme le fichier (seule forme à sauvegarder)
	if (!_dansGroupe)
		fermerFichier();
}

inline void VisiteurSauvegarderTXT::ouvrirFichier()
{
	// Si le nom du fichier est vide, on ne peut pas ouvrir le fichier
	if (_nomFichier.empty())
		throw invalid_argument("Impossible d'ouvrir le fichier : nom de fichier vide.");

	// On ouvre le fichier en mode écriture
	_fichier = new ofstream(_nomFichier, ios::out);

	// Si le fichier n'est pas ouvert, on lève une exception
	if (!_fichier->is_open())
		throw invalid_argument("Impossible d'ouvrir le fichier : " + _nomFichier);
}

inline void VisiteurSauvegarderTXT::fermerFichier()
{
	if (_fichier != nullptr)
	{
		// Si le fichier est ouvert, on le ferme
		if (_fichier->is_open())
			_fichier->close();

		// On supprime le pointeur
		delete _fichier;
		_fichier = nullptr;
	}

	// On remet le flag à false
	_dansGroupe = false;

}

#endif // VISITEUR_SAUVEGARDER_TXT_H