#ifndef CONTROLER_FENETRE_OPENGL_H
#define CONTROLER_FENETRE_OPENGL_H

#include "opengl/vue/FenetreOpenGL.h"
#include "design_patterns/visiteur/VisiteurDessinerOpenGL.h"

using namespace std;

class ControleurFenetreOpenGL
{
private:
	VisiteurDessinerOpenGL* _visiteur;
	FenetreOpenGL* _fenetre;

public:
	ControleurFenetreOpenGL(VisiteurForme* visiteur)
		: _visiteur(new VisiteurDessinerOpenGL(visiteur)), _fenetre(nullptr) {}
}; // class ControleurFenetreOpenGL

#endif // CONTROLER_FENETRE_OPENGL_H