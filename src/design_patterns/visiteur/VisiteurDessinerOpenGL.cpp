#include "design_patterns/visiteur/VisiteurDessinerOpenGL.h"
#include "formes/Cercle.h"
#include "formes/Segment.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "formes/Groupe.h"
#include "opengl/vue/FenetreOpenGL.h"

void VisiteurDessinerOpenGL::visiter(Cercle* c)
{

}

void VisiteurDessinerOpenGL::visiter(Segment* s)
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2f(s->p1().x, s->p1().y);
	glVertex2f(s->p2().x, s->p2().y);
	glEnd();
}

void VisiteurDessinerOpenGL::visiter(Triangle* t)
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	glVertex2f(t->p1().x, t->p1().y);
	glVertex2f(t->p2().x, t->p2().y);
	glVertex2f(t->p3().x, t->p3().y);
	glEnd(); 
}

void VisiteurDessinerOpenGL::visiter(Polygone* p)
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	for (const auto& point : p->points()) {
		glVertex2f(point.x, point.y);
	}
	glEnd();
}

void VisiteurDessinerOpenGL::visiter(Groupe* g)
{
	for (const auto& forme : g->formes()) {
		forme->accepter(this);
	}
}