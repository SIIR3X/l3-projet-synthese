#include "opengl/vue/FenetreOpenGL.h"

bool FenetreOpenGL::initialiser()
{
	// On commence par initialiser GLFW (Graphics Library Framework, la bibliothèque qui gère les fenêtres et les contextes OpenGL)
	if (!glfwInit())
	{
		cerr << "Echec de l'initialisation de GLFW." << endl;
		return false;
	}

	// On crée ensuite une fenêtre
	_fenetre = glfwCreateWindow(_largeur, _hauteur, _titre.c_str(), nullptr, nullptr);

	// Si la fenêtre n'a pas pu être créée, on arrête tout
	if (!_fenetre)
	{
		cerr << "Echec de la création de la fenêtre." << endl;
		glfwTerminate(); // Libère les ressources allouées par GLFW
		return false;
	}

	// On indique à GLFW que la fenêtre que l'on vient de créer est celle sur laquelle on va travailler
	glfwMakeContextCurrent(_fenetre);

	// Si on arrive ici, c'est que tout s'est bien passé
	return true;
}