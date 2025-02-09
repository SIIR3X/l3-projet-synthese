#ifndef VISITEUR_DESSINER_TCP_H
#define VISITEUR_DESSINER_TCP_H

#include "design_patterns/visiteur/VisiteurForme.h"
#include <string>
#include <sstream>

using namespace std;

/**
 * @brief Classe VisiteurDessinerTCP permettant de dessiner des formes en TCP.
 */
class VisiteurDessinerTCP : public VisiteurForme
{
private:
	stringstream _buffer;
	bool _dansGroupe = false;

	void envoyerDonnees();

public:
	virtual void visiter(Cercle* c) override;
	virtual void visiter(Segment* s) override;
	virtual void visiter(Triangle* t) override;
	virtual void visiter(Polygone* p) override;
	virtual void visiter(Groupe* g) override;
}; // class VisiteurDessinerTCP

inline void VisiteurDessinerTCP::envoyerDonnees()
{
	// Si le buffer n'est pas vide, alors on envoie les données
	if (!_buffer.str().empty())
	{
		// Envoie de la requête TCP
		// send(_buffer)

		_buffer.str("");
		_buffer.clear();
	}
}

#endif // VISITEUR_DESSINER_TCP_H