#ifndef VISITEUR_SAUVEGARDER_TXT_H
#define VISITEUR_SAUVEGARDER_TXT_H

#include "VisiteurForme.h"
#include <fstream>

class VisiteurSauvegarderTXT : public VisiteurForme
{
private:
	ofstream _fichier;

	void sauvegarderFormeSimple(const Forme* fs);

public:
	VisiteurSauvegarderTXT(string nomFichier)
	{
		_fichier.open(nomFichier);
	}

	~VisiteurSauvegarderTXT()
	{
		_fichier.close();
	}

	virtual void visiter(Segment* s) override;
	virtual void visiter(Triangle* t) override;
	virtual void visiter(Polygone* p) override;
	virtual void visiter(Cercle* c) override;
	virtual void visiter(Groupe* g) override;
};

#endif // VISITEUR_SAUVEGARDER_TXT_H