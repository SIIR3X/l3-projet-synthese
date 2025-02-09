#include "formes/Cercle.h"
#include "formes/Segment.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "formes/Groupe.h"
#include "graphique/Viewport.h"
#include <gtest/gtest.h>

const Viewport viewport(Vecteur2D(0, 0), Vecteur2D(100, 100), 800, 600);

TEST(Viewport, ConstructeurAvecValeurs)
{
	// Assert
	EXPECT_EQ(Vecteur2D(0, 0), viewport.coinMin());
	EXPECT_EQ(Vecteur2D(100, 100), viewport.coinMax());
	EXPECT_EQ(800, viewport.largeurEcran());
	EXPECT_EQ(600, viewport.hauteurEcran());
	EXPECT_EQ(Vecteur2D(50, 50), viewport.centreMonde());
	EXPECT_EQ(8, viewport.echelleX());
	EXPECT_EQ(6, viewport.echelleY());
	EXPECT_EQ(6, viewport.facteurZoom());
}

TEST(Viewport, FormeVersEcranCercle)
{
	// Arrange
	Cercle cercle(Vecteur2D(50, 50), 10);

	// Act
	Cercle* cercleEcran = dynamic_cast<Cercle*>(viewport.formeVersEcran(cercle));

	// Assert
	EXPECT_EQ(Vecteur2D(400, 300), cercleEcran->centre());
	EXPECT_EQ(60, cercleEcran->rayon());

	// Clean
	delete cercleEcran;
}

TEST(Viewport, FormeVersEcranSegment)
{
	// Arrange
	Segment segment(Vecteur2D(10, 10), Vecteur2D(90, 90));

	// Act
	Segment* segmentEcran = dynamic_cast<Segment*>(viewport.formeVersEcran(segment));

	// Assert
	EXPECT_EQ(Vecteur2D(160, 60), segmentEcran->p1());
	EXPECT_EQ(Vecteur2D(640, 540), segmentEcran->p2());

	// Clean
	delete segmentEcran;
}

TEST(Viewport, FormeVersEcranTriangle)
{
	// Arrange
	Triangle triangle(Vecteur2D(10, 10), Vecteur2D(90, 10), Vecteur2D(50, 90));

	// Act
	Triangle* triangleEcran = dynamic_cast<Triangle*>(viewport.formeVersEcran(triangle));

	// Assert
	EXPECT_EQ(Vecteur2D(160, 60), triangleEcran->p1());
	EXPECT_EQ(Vecteur2D(640, 60), triangleEcran->p2());
	EXPECT_EQ(Vecteur2D(400, 540), triangleEcran->p3());

	// Clean
	delete triangleEcran;
}

TEST(Viewport, FormeVersEcranPolygone)
{
	// Arrange
	Polygone polygone({ Vecteur2D(10, 10), Vecteur2D(90, 10), Vecteur2D(90, 90), Vecteur2D(10, 90) });

	// Act
	Polygone* polygoneEcran = dynamic_cast<Polygone*>(viewport.formeVersEcran(polygone));

	// Assert
	EXPECT_EQ(Vecteur2D(160, 60), polygoneEcran->points()[0]);
	EXPECT_EQ(Vecteur2D(640, 60), polygoneEcran->points()[1]);
	EXPECT_EQ(Vecteur2D(640, 540), polygoneEcran->points()[2]);
	EXPECT_EQ(Vecteur2D(160, 540), polygoneEcran->points()[3]);

	// Clean
	delete polygoneEcran;
}
