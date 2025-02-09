#ifndef VISITEUR_SAUVEGARDER_TXT_H
#define VISITEUR_SAUVEGARDER_TXT_H

#include "design_patterns/visiteur/VisiteurForme.h"
#include <string>
#include <fstream>

using namespace std;

/**
 * @brief Classe VisiteurSauvegarderTXT permettant de sauvegarder des formes dans un fichier texte.
 */
class VisiteurSauvegarderTXT : public VisiteurForme
{
private:
	ofstream _fichier; /**< Fichier de sauvegarde. */

	/**
	 * @brief Sauvegarde le nombre de points d'une forme.
	 * @param nbPoints Nombre de points à sauvegarder.
	 */
	void sauvegarderNbPoints(int nbPoints);

	/**
	 * @brief Sauvegarde une forme simple.
	 * @param fs Forme simple à sauvegarder.
	 */
	void sauvegarderFormeSimple(const Forme* fs);

public:
	/**
	 * @brief Constructeur de la classe VisiteurSauvegarderTXT.
	 * @param nomFichier Nom du fichier de sauvegarde.
	 */
	VisiteurSauvegarderTXT(const string& nomFichier);

	~VisiteurSauvegarderTXT();

	void setFichier(const string& nomFichier);

	virtual void visiter(Cercle* c) override;
	virtual void visiter(Segment* s) override;
	virtual void visiter(Triangle* t) override;
	virtual void visiter(Polygone* p) override;
	virtual void visiter(Groupe* g) override;
}; // class VisiteurSauvegarderTXT

inline void VisiteurSauvegarderTXT::sauvegarderNbPoints(int nbPoints)
{
	_fichier << nbPoints << endl;
}

inline void VisiteurSauvegarderTXT::sauvegarderFormeSimple(const Forme* fs)
{
	string str = string(*fs);
	
	_fichier << str.length() << " " << str << endl;
}

inline VisiteurSauvegarderTXT::VisiteurSauvegarderTXT(const string& nomFichier)
{
	_fichier.open(nomFichier);
}

inline VisiteurSauvegarderTXT::~VisiteurSauvegarderTXT()
{
	_fichier.close();
}

inline void VisiteurSauvegarderTXT::setFichier(const string& nomFichier)
{
	_fichier.close();
	_fichier.open(nomFichier);
}

#endif // VISITEUR_SAUVEGARDER_TXT_H