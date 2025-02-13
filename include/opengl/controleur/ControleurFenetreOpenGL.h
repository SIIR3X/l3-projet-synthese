#ifndef CONTROLER_FENETRE_OPENGL_H
#define CONTROLER_FENETRE_OPENGL_H

#include "utils/Utils.h"
#include "graphique/Viewport.h"
#include "opengl/vue/FenetreOpenGL.h"
#include "design_patterns/visiteur/VisiteurDessinerOpenGL.h"

using namespace std;

class ControleurFenetreOpenGL
{
private:
	Groupe _groupe; /**< Groupe de formes à afficher. */
	Viewport* _viewport; /**< Viewport de la fenêtre. */
	FenetreOpenGL* _fenetre; /**< Fenêtre OpenGL. */

public:
	/**
	 * @brief Constructeur de la classe ControleurFenetreOpenGL.
	 * @param groupe Groupe de formes à afficher.
	 * @param viewport Viewport de la fenêtre.
	 */
	ControleurFenetreOpenGL(const Groupe& groupe, Viewport* viewport)
		: _groupe(groupe), _viewport(viewport), _fenetre(nullptr) {}

	/**
	 * @brief Initialise la fenêtre OpenGL.
	 * @param largeur Largeur de la fenêtre.
	 * @param hauteur Hauteur de la fenêtre.
	 * @param titre Titre de la fenêtre.
	 * @return true si l'initialisation s'est bien passée, false sinon.
	 */
	bool initialiserFenetre(int largeur, int hauteur, const string& titre);
	
	/**
	 * @brief Exécute la fenêtre OpenGL.
	 */
	void runFenetre() { _fenetre->run(); }

	/**
	 * @brief Définit le groupe de la fenêtre et recalcule les formes à afficher.
	 */
	void setGroupeFenetre();
	
	/**
	 * @brief Fonction de rappel appelée lorsqu'on redimensionne la fenêtre.
	 * @param fenetre Pointeur vers la fenêtre.
	 * @param largeur Nouvelle largeur de la fenêtre.
	 * @param hauteur Nouvelle hauteur de la fenêtre.
	 */
	static void callback_taille(GLFWwindow* fenetre, int largeur, int hauteur);
}; // class ControleurFenetreOpenGL

inline bool ControleurFenetreOpenGL::initialiserFenetre(int largeur, int hauteur, const string& titre)
{
	// On crée une instance de la fenêtre OpenGL
	_fenetre = new FenetreOpenGL(titre);

	// On initialise la fenêtre
	if (!_fenetre->initialiser(largeur, hauteur))
		return false;

	// On place le contrôleur de fenêtre comme pointeur utilisateur de la fenêtre (pour les callbacks)
	glfwSetWindowUserPointer(_fenetre->getFenetre(), this);

	return true;
}

inline void ControleurFenetreOpenGL::setGroupeFenetre()
{
	// On commence par transformer les formes du groupe
	Groupe* groupeTransforme = new Groupe(Utils::transformerFormesVersEcran(_groupe.formes(), *_viewport), _groupe.couleur());

	// On centre ensuite le groupe (optionnel, mais doit être fait après la transformation des formes)
	Utils::centrerGroupe(groupeTransforme, _viewport->centreEcran());

	// On affecte le groupe transformé à la fenêtre
	_fenetre->setGroupe(groupeTransforme);
}

inline void ControleurFenetreOpenGL::callback_taille(GLFWwindow* fenetre, int largeur, int hauteur)
{
	// On commence par récupérer le pointeur vers le contrôleur de fenêtre
	ControleurFenetreOpenGL* controleur = static_cast<ControleurFenetreOpenGL*>(glfwGetWindowUserPointer(fenetre));

	// Si on n'a pas pu récupérer le pointeur, alors on arrête tout
	if (!controleur)
		throw runtime_error("Impossible de récupérer le pointeur vers le contrôleur de fenêtre.");

	// On redéfinit les paramètres OpenGL
	controleur->_fenetre->definirParametresOpenGL(largeur, hauteur);

	// On redimensionne le viewport (de notre application)
	controleur->_viewport->setDimensionsEcran(largeur, hauteur);

	// Pour finir, on réaffecte le groupe à la fenêtre (pour recalculer les formes à afficher)
	controleur->setGroupeFenetre();

	// On redessine la fenêtre
	controleur->_fenetre->dessinerFenetre();
}

#endif // CONTROLER_FENETRE_OPENGL_H