#include "opengl/vue/FenetreOpenGL.h"
#include "opengl/controleur/ControleurFenetreOpenGL.h"
#include <iostream>

bool FenetreOpenGL::initialiser(int largeur, int hauteur)
{
	// On commence par initialiser GLFW (Graphics Library Framework, la bibliothèque qui gère les fenêtres et les contextes OpenGL)
	if (!glfwInit())
	{
		cerr << "Echec de l'initialisation de GLFW." << endl;
		return false;
	}

	// On crée ensuite une fenêtre
	_fenetre = glfwCreateWindow(largeur, hauteur, _titre.c_str(), nullptr, nullptr);

	// Si la fenêtre n'a pas pu être créée, on arrête tout
	if (!_fenetre)
	{
		cerr << "Echec de la création de la fenêtre." << endl;
		glfwTerminate(); // Libère les ressources allouées par GLFW
		return false;
	}

	// On indique à GLFW que la fenêtre que l'on vient de créer est celle sur laquelle on va travailler
	glfwMakeContextCurrent(_fenetre);

	// On défini la couleur de fond de la fenêtre OpenGL (blanc)
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	// On indique à GLFW que l'on veut appeler la fonction callback_taille lorsque la fenêtre est redimensionnée (une sorte de "listener" en Java)
	glfwSetFramebufferSizeCallback(_fenetre, ControleurFenetreOpenGL::callback_taille);

	// On défini les paramètres OpenGL
	definirParametresOpenGL(largeur, hauteur);

	// Si on arrive ici, c'est que tout s'est bien passé
	return true;
}