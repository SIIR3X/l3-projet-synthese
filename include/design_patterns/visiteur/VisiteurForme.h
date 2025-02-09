#ifndef VISITEUR_FORME_H
#define VISITEUR_FORME_H

class Segment;
class Triangle;
class Polygone;
class Cercle;
class Groupe;

/**
 * @brief Classe abstraite VisiteurForme permettant de visiter des formes.
 */
class VisiteurForme
{
public:
	virtual void visiter(Cercle* c) = 0;
	virtual void visiter(Segment* s) = 0;
	virtual void visiter(Triangle* t) = 0;
	virtual void visiter(Polygone* p) = 0;
	virtual void visiter(Groupe* g) = 0;
}; // class VisiteurForme

#endif // VISITEUR_FORME_H