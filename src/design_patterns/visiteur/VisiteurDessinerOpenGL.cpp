#include "design_patterns/visiteur/VisiteurDessinerOpenGL.h"
#include "formes/Cercle.h"
#include "formes/Segment.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "formes/Groupe.h"
#include "opengl/vue/FenetreOpenGL.h"

const int num_segments = 100;
const double angle_increment = 2.0 * PI / num_segments;

void VisiteurDessinerOpenGL::visiter(Cercle* c)
{
	// On applique la couleur du cercle
	FenetreOpenGL::appliquerCouleur(c->couleur());

	// On passe en mode dessin de lignes
	glBegin(GL_LINE_LOOP);

	// On dessine le cercle
	for (int i = 0; i < num_segments; ++i)
	{
		double angle = i * angle_increment;
		float x = c->centre().x + c->rayon() * std::cos(angle);
		float y = c->centre().y + c->rayon() * std::sin(angle);
		glVertex2f(x, y);
	}

	// On indique que l'on a fini de dessiner
	glEnd();
}

void VisiteurDessinerOpenGL::visiter(Segment* s)
{
	// On applique la couleur du segment
	FenetreOpenGL::appliquerCouleur(s->couleur());

	// On passe en mode dessin de lignes
	glBegin(GL_LINES);

	// On dessine le segment
	glVertex2f(s->p1().x, s->p1().y);
	glVertex2f(s->p2().x, s->p2().y);

	// On indique que l'on a fini de dessiner
	glEnd();
}

void VisiteurDessinerOpenGL::visiter(Triangle* t)
{
    // -- 1) Dessin du remplissage --
    // Appliquer la couleur du triangle (avec ou sans transparence).
    FenetreOpenGL::appliquerCouleur(t->couleur());

    glBegin(GL_TRIANGLES);
        glVertex2f(t->p1().x, t->p1().y);
        glVertex2f(t->p2().x, t->p2().y);
        glVertex2f(t->p3().x, t->p3().y);
    glEnd();

    // -- 2) Dessin du contour --
    // Dessiner le contour du triangle (par exemple, en noir opaque).
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f); // ou glColor3f(0.0f, 0.0f, 0.0f)
    glBegin(GL_LINE_LOOP);
        glVertex2f(t->p1().x, t->p1().y);
        glVertex2f(t->p2().x, t->p2().y);
        glVertex2f(t->p3().x, t->p3().y);
    glEnd();
}

void VisiteurDessinerOpenGL::visiter(Polygone* p)
{
	// On applique la couleur du polygone
	FenetreOpenGL::appliquerCouleur(p->couleur());

	// On passe en mode dessin de polygones
	glBegin(GL_POLYGON);

	// On dessine le polygone
	for (const auto& point : p->points())
		glVertex2f(point.x, point.y);

	// On indique que l'on a fini de dessiner
	glEnd();

    glColor4f(0.0f, 0.0f, 0.0f, 1.0f); // ou glColor3f(0.0f, 0.0f, 0.0f) si vous n'utilisez pas l'alpha
    glBegin(GL_LINE_LOOP);
    for (const auto& point : p->points())
    {
        glVertex2f(point.x, point.y);
    }
    glEnd();
}

void VisiteurDessinerOpenGL::visiter(Groupe* g)
{
	for (const auto& forme : g->formes())
		forme->accepter(this);
}