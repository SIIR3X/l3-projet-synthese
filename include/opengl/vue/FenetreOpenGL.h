#ifndef FENETRE_OPENGL_H
#define FENETRE_OPENGL_H

#include "geometrie/Vecteur2D.h"
#include "formes/Groupe.h"
#include "design_patterns/visiteur/VisiteurDessinerOpenGL.h"
#include <GLFW/glfw3.h>
#include <vector>
#include <string>

#include "graphique/Viewport.h"
#include "utils/Utils.h"

#include <iostream>

using namespace std;

class FenetreOpenGL
{
private:
	int _largeur, _hauteur; /**< Largeur et hauteur de la fenêtre */
	string _titre; /**< Titre de la fenêtre */
	Groupe* _groupe; /**< Groupe de formes à dessiner */
	GLFWwindow* _fenetre; /**< Fenêtre OpenGL */

	void stop();

	void dessinerRepere();

public:
	FenetreOpenGL(int largeur, int hauteur, string titre)
		: _largeur(largeur), _hauteur(hauteur), _titre(titre), _fenetre(nullptr) {}

	void setGroupe(Groupe* groupe) { _groupe = groupe; }

	bool initialiser();

	void run();

	Vecteur2D centre() const;

	Groupe* getGroupe() { return _groupe; }

	GLFWwindow* getFenetre() { return _fenetre; }

	void setLargeur(int largeur) { _largeur = largeur; }

	void setHauteur(int hauteur) { _hauteur = hauteur; }
}; // class FenetreOpenGL

#include <iostream>

inline void FenetreOpenGL::run()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	// Tant que la fenêtre n'est pas fermée, alors on boucle
	while (!glfwWindowShouldClose(_fenetre))
	{
		// On efface le contenu de la fenêtre
		glClear(GL_COLOR_BUFFER_BIT);

		dessinerRepere();

		VisiteurDessinerOpenGL visiteur;
		_groupe->accepter(&visiteur);

		// Mise à jour de la fenêtre
		glfwSwapBuffers(_fenetre);
		glfwPollEvents();
	}
}

inline Vecteur2D FenetreOpenGL::centre() const
{
	int largeur, hauteur;
	glfwGetWindowSize(_fenetre, &largeur, &hauteur);

	return Vecteur2D(largeur / 2, hauteur / 2);
}

inline void FenetreOpenGL::stop()
{
	// Si la fenêtre n'est pas nulle, alors on la détruit
	if (_fenetre != nullptr)
	{
		// On commence par détruire la fenêtre
		glfwDestroyWindow(_fenetre);

		// Et on indique que l'on a terminé l'utilisation de GLFW
		glfwTerminate();
	}
}

inline void FenetreOpenGL::dessinerRepere()
{
    int width, height;
    glfwGetWindowSize(_fenetre, &width, &height);

	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
        // Axe horizontal : de 0 à la largeur, positionné à la moitié de la hauteur
        glVertex2f(0, height / 2);
        glVertex2f(width, height / 2);
        // Axe vertical : de 0 à la hauteur, positionné à la moitié de la largeur
        glVertex2f(width / 2, 0);
        glVertex2f(width / 2, height);
	glEnd();
}

#endif // FENETRE_OPENGL_H