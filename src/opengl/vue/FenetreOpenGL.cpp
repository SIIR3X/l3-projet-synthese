#include "opengl/vue/FenetreOpenGL.h"
#include <iostream>
#include "opengl/controleur/ControleurFenetreOpenGL.h"

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
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Fond blanc

	glfwSetFramebufferSizeCallback(_fenetre, ControleurFenetreOpenGL::callback_taille);


	// Dans votre fonction d'initialisation ou juste avant de dessiner
	glViewport(0, 0, _largeur, _hauteur);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, _largeur, _hauteur, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	


	// Si on arrive ici, c'est que tout s'est bien passé
	return true;
}