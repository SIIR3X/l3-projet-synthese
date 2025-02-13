#ifndef FENETRE_OPENGL_H
#define FENETRE_OPENGL_H

#include "formes/Groupe.h"
#include "geometrie/Vecteur2D.h"
#include "design_patterns/visiteur/VisiteurDessinerOpenGL.h"
#include <string>
#include <vector>
#include <GLFW/glfw3.h>

using namespace std;

class FenetreOpenGL
{
private:
	string _titre; /**< Titre de la fenêtre */
	Groupe* _groupe; /**< Groupe de formes à dessiner (déjà transformées) */
	GLFWwindow* _fenetre; /**< Fenêtre OpenGL */
	VisiteurDessinerOpenGL _visiteur; /**< Visiteur pour dessiner les formes */

	/**
	 * @brief Stoppe la fenêtre.
	 */
	void stop();

	/**
	 * @brief Dessine le repère.
	 */
	void dessinerRepere();

public:
	/**
	 * @brief Constructeur de la classe FenetreOpenGL.
	 * 
	 */
	FenetreOpenGL(const string& titre)
		: _titre(titre), _groupe(nullptr), _fenetre(nullptr), _visiteur() {}

	/**
	 * @brief Définit les paramètres OpenGL.
	 * @param largeur Largeur de la fenêtre.
	 * @param hauteur Hauteur de la fenêtre.
	 */
	void definirParametresOpenGL(int largeur, int hauteur);

	/**
	 * @brief Initialisation de la fenêtre.
	 * @param largeur Largeur de la fenêtre.
	 * @param hauteur Hauteur de la fenêtre.
	 * @return true si l'initialisation s'est bien passée, false sinon.
	 */
	bool initialiser(int largeur, int hauteur);

	/**
	 * @brief Exécution de la fenêtre.
	 */
	void run();

	void dessinerFenetre();

	Vecteur2D centre() const;

	const string& getTitre() const { return _titre; }

	Groupe* getGroupe() { return _groupe; }

	void setGroupe(Groupe* groupe);

	GLFWwindow* getFenetre() { return _fenetre; }

	VisiteurDessinerOpenGL& getVisiteur() { return _visiteur; }

	/**
	 * @brief Récupère les dimensions de la fenêtre.
	 * @param largeur Référence vers la largeur de la fenêtre.
	 * @param hauteur Référence vers la hauteur de la fenêtre.
	 */
	void getDimensions(int& largeur, int& hauteur) const;

	/**
	 * @brief Applique une couleur.
	 * @param couleur Couleur à appliquer.
	 */
	static void appliquerCouleur(Couleur couleur);
}; // class FenetreOpenGL

inline void FenetreOpenGL::definirParametresOpenGL(int largeur, int hauteur)
{
	// On commence par redimensionner le viewport d'OpenGL (différent de celui de notre application)
	glViewport(0, 0, largeur, hauteur);
	
	// On passe en mode projection
	glMatrixMode(GL_PROJECTION);

	// On charge la matrice identité (pour repartir de zéro)
	glLoadIdentity();

	// On définit la matrice de projection en mode orthogonal (car OpenGL utilise un repère [-1, 1] dans chaque direction de base)
	glOrtho(0, largeur, hauteur, 0, -1, 1);

	// On repasse en mode modelview
	glMatrixMode(GL_MODELVIEW);

	// On charge la matrice identité (pour repartir de zéro)
	glLoadIdentity();

    // Activer le blending pour la transparence
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

inline void FenetreOpenGL::run()
{
	// On défini la couleur de fond de la fenêtre OpenGL (blanc)
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	// Tant que la fenêtre n'est pas fermée, alors on boucle
	while (!glfwWindowShouldClose(_fenetre))
	{
		// On dessine la fenêtre
		dessinerFenetre();
	}
}

inline void FenetreOpenGL::dessinerFenetre()
{
	// On efface le contenu de la fenêtre
	glClear(GL_COLOR_BUFFER_BIT);

	// On dessine le repère
	dessinerRepere();

	// On dessine le groupe de formes
	_groupe->accepter(&_visiteur);

	// Mise à jour de la fenêtre
	glfwSwapBuffers(_fenetre);

	// On gère les événements
	glfwPollEvents();
}

inline void FenetreOpenGL::appliquerCouleur(Couleur couleur)
{
	switch (couleur)
	{
	case Couleur::BLACK:
		glColor3f(0.0f, 0.0f, 0.0f);
		break;
	case Couleur::BLUE:
		glColor3f(0.0f, 0.0f, 1.0f);
		break;
	case Couleur::RED:
		glColor4f(1.0f, 0.0f, 0.0f, 0.80f);
		break;
	case Couleur::GREEN:
		glColor3f(0.0f, 1.0f, 0.0f);
		break;
	case Couleur::YELLOW:
		glColor3f(1.0f, 1.0f, 0.0f);
		break;
	case Couleur::CYAN:
		glColor3f(0.0f, 1.0f, 1.0f);
		break;
	default:
		break;
	}
}

inline Vecteur2D FenetreOpenGL::centre() const
{
	int largeur, hauteur;

	// On récupère les dimensions de la fenêtre
	getDimensions(largeur, hauteur);

	// On retourne le centre de la fenêtre
	return Vecteur2D(largeur / 2, hauteur / 2);
}

inline void FenetreOpenGL::setGroupe(Groupe* groupe)
{
	// On commence par supprimer l'ancien groupe
	if (_groupe != nullptr)
		delete _groupe;

	// On affecte le nouveau groupe
	_groupe = groupe;
}

inline void FenetreOpenGL::getDimensions(int& largeur, int& hauteur) const
{
	// On récupère les dimensions de la fenêtre OpenGL
	glfwGetWindowSize(_fenetre, &largeur, &hauteur);
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
	int largeur, hauteur;

	// On récupère les dimensions de la fenêtre
	getDimensions(largeur, hauteur);

	// On défini la couleur du repère (noir)
	glColor3f(0.0f, 0.0f, 0.0f);

	// On passe en mode dessin de lignes
	glBegin(GL_LINES);

	// Axe horizontal : de 0 à la largeur, positionné à la moitié de la hauteur
	glVertex2f(0, hauteur / 2);
	glVertex2f(largeur, hauteur / 2);

	// Axe vertical : de 0 à la hauteur, positionné à la moitié de la largeur
	glVertex2f(largeur / 2, 0);
	glVertex2f(largeur / 2, hauteur);

	// On indique que l'on a fini de dessiner
	glEnd();
}

#endif // FENETRE_OPENGL_H