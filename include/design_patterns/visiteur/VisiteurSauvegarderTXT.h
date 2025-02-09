#ifndef VISITEUR_SAUVEGARDER_TXT_H
#define VISITEUR_SAUVEGARDER_TXT_H

#include "design_patterns/visiteur/VisiteurForme.h"
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

#define TAILLE_BUFFER 4096

/**
 * @brief Classe VisiteurSauvegarderTXT permettant de sauvegarder des formes dans un fichier texte.
 */
class VisiteurSauvegarderTXT : public VisiteurForme
{
private:
	ofstream* _fichier; /**< Fichier de sauvegarde. */

	/**
	 * @brief Sauvegarde une forme simple.
	 * @param fs Forme simple à sauvegarder.
	 */
	void sauvegarderFormeSimple(const Forme* fs);

public:
	/**
	 * @brief Constructeur de VisiteurSauvegarderTXT.
	 * @param fichier Fichier de sauvegarde.
	 */
	VisiteurSauvegarderTXT(ofstream* fichier);

	void setFichier(ofstream* fichier);

	virtual void visiter(Cercle* c) override;
	virtual void visiter(Segment* s) override;
	virtual void visiter(Triangle* t) override;
	virtual void visiter(Polygone* p) override;
	virtual void visiter(Groupe* g) override;
}; // class VisiteurSauvegarderTXT

inline VisiteurSauvegarderTXT::VisiteurSauvegarderTXT(ofstream* fichier)
	: _fichier(fichier)
{
	// Si le fichier de sauvegarde n'est pas ouvert, on lance une exception
	if (!fichier || !fichier->is_open())
		throw invalid_argument("Le fichier de sauvegarde n'est pas ouvert.");
}

inline void VisiteurSauvegarderTXT::setFichier(ofstream* fichier)
{
	_fichier = fichier;
}

inline void VisiteurSauvegarderTXT::sauvegarderFormeSimple(const Forme* fs)
{
	// Buffer pour la conversion de la forme simple en chaîne de caractères
    char buffer[TAILLE_BUFFER];

	// Conversion de la forme simple en chaîne de caractères
    string str = string(*fs);
    int length = snprintf(buffer, sizeof(buffer), "%zu %s\n", str.length(), str.c_str());
	
	// Si la longueur est supérieure à 0, on écrit dans le fichier
    if (length > 0)
    	_fichier->write(buffer, length);
}

#endif // VISITEUR_SAUVEGARDER_TXT_H