#ifndef FENETRE_OPENGL_H
#define FENETRE_OPENGL_H

#include <GLFW/glfw3.h>
#include "formes/Forme.h"
#include <vector>
#include <string>

using namespace std;

class FenetreOpenGL
{
private:
	int _largeur, _hauteur; /**< Largeur et hauteur de la fenêtre */
	string _titre; /**< Titre de la fenêtre */
	GLFWwindow* _fenetre; /**< Fenêtre OpenGL */
	vector<Forme*> _formes; /**< Formes à dessiner */

	void stop();

public:
	FenetreOpenGL(int largeur, int hauteur, string titre)
		: _largeur(largeur), _hauteur(hauteur), _titre(titre), _fenetre(nullptr) {}

	bool initialiser();

	void run();
}; // class FenetreOpenGL

inline void FenetreOpenGL::run()
{
	// Tant que la fenêtre n'est pas fermée, alors on boucle
	while (!glfwWindowShouldClose(_fenetre))
	{
		// On commence par effacer le contenu de la fenêtre
		glClear(GL_COLOR_BUFFER_BIT);

		// On dessine ensuite toutes les formes à l'aide du visiteur
		for (Forme* forme : _formes)
		{
			forme->accepter(_visiteur);
		}

		glfwSwapBuffers(_fenetre);
		glfwPollEvents();
	}
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

#endif // FENETRE_OPENGL_H