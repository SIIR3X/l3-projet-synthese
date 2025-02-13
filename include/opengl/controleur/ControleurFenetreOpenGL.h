#ifndef CONTROLER_FENETRE_OPENGL_H
#define CONTROLER_FENETRE_OPENGL_H

#include "opengl/vue/FenetreOpenGL.h"
#include "design_patterns/visiteur/VisiteurDessinerOpenGL.h"
#include "graphique/Viewport.h"
#include "utils/Utils.h"

#include <iostream>

using namespace std;

class ControleurFenetreOpenGL
{
private:
	Viewport* _viewport;
	FenetreOpenGL* _fenetre;
	Groupe _groupe;

public:
	ControleurFenetreOpenGL(const Groupe& groupe, Viewport* viewport)
		: _groupe(groupe), _viewport(viewport), _fenetre(nullptr) {}

	void setGroupeFenetre();

	bool initialiserFenetre(int largeur, int hauteur, string titre);

	void runFenetre() { _fenetre->run(); }
	
	static void callback_taille(GLFWwindow* fenetre, int largeur, int hauteur)
	{
		glViewport(0, 0, largeur, hauteur);


		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		glOrtho(0, largeur, hauteur, 0, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		ControleurFenetreOpenGL* controleur = static_cast<ControleurFenetreOpenGL*>(glfwGetWindowUserPointer(fenetre));
		if (controleur)
		{
			int largeur, hauteur;
			glfwGetFramebufferSize(fenetre, &largeur, &hauteur);

			controleur->_viewport->setDimensionsEcran(largeur, hauteur);

			controleur->setGroupeFenetre();
		}
	}

}; // class ControleurFenetreOpenGL

inline void ControleurFenetreOpenGL::setGroupeFenetre()
{
	Groupe* groupeTransforme = new Groupe(Utils::transformerFormesVersEcran(_groupe.formes(), *_viewport));

	Utils::centrerGroupe(groupeTransforme, _viewport->centreEcran());

	_fenetre->setGroupe(groupeTransforme);
}

inline bool ControleurFenetreOpenGL::initialiserFenetre(int largeur, int hauteur, string titre)
{
	_fenetre = new FenetreOpenGL(largeur, hauteur, titre);
	if (!_fenetre->initialiser())
		return false;

	glfwSetWindowUserPointer(_fenetre->getFenetre(), this);

	return true;
}

#endif // CONTROLER_FENETRE_OPENGL_H