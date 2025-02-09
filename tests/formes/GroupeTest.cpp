#include "formes/Cercle.h"
#include "formes/Segment.h"
#include "formes/Triangle.h"
#include "formes/Polygone.h"
#include "formes/Groupe.h"
#include <gtest/gtest.h>

class GroupeTest : public ::testing::Test 
{
protected:
	Cercle* cercle;
	Segment* segment;
	Triangle* triangle;
	Polygone* polygone;
	Groupe* groupe;

	void SetUp() override
	{
		Vecteur2D v1(1, 2);
		Vecteur2D v2(3, 4);
		Vecteur2D v3(5, 6);
		Vecteur2D v4(7, 8);
		Vecteur2D v5(9, 10);
		Vecteur2D v6(11, 12);
		Vecteur2D v7(13, 14);
		Vecteur2D v8(15, 16);
		Vecteur2D v9(17, 18);
		Vecteur2D v10(19, 20);

		cercle = new Cercle(v1, 1);
		segment = new Segment(v2, v3);
		triangle = new Triangle(v4, v5, v6);
		polygone = new Polygone({v7, v8, v9, v10});
		groupe = new Groupe({cercle, segment, triangle, polygone});
	}

	void TearDown() override
	{
		delete groupe;
	}
};

TEST_F(GroupeTest, ConstructeurAvecValeurs)
{
	// Assert
	EXPECT_EQ(4, groupe->nbFormes());
}

TEST_F(GroupeTest, Translation)
{
	// Act
	groupe->translation(Vecteur2D(1, 1));

	// Assert
	EXPECT_EQ(Vecteur2D(2, 3), cercle->centre());
	EXPECT_EQ(Vecteur2D(4, 5), segment->p1());
	EXPECT_EQ(Vecteur2D(6, 7), segment->p2());
	EXPECT_EQ(Vecteur2D(8, 9), triangle->p1());
	EXPECT_EQ(Vecteur2D(10, 11), triangle->p2());
	EXPECT_EQ(Vecteur2D(12, 13), triangle->p3());
	EXPECT_EQ(Vecteur2D(14, 15), polygone->points()[0]);
	EXPECT_EQ(Vecteur2D(16, 17), polygone->points()[1]);
	EXPECT_EQ(Vecteur2D(18, 19), polygone->points()[2]);
	EXPECT_EQ(Vecteur2D(20, 21), polygone->points()[3]);
}

TEST_F(GroupeTest, Homothetie)
{
	// Act
	groupe->homothetie(Vecteur2D(0, 0), 2);

	// Assert
	EXPECT_EQ(Vecteur2D(2, 4), cercle->centre());
	EXPECT_EQ(Vecteur2D(6, 8), segment->p1());
	EXPECT_EQ(Vecteur2D(10, 12), segment->p2());
	EXPECT_EQ(Vecteur2D(14, 16), triangle->p1());
	EXPECT_EQ(Vecteur2D(18, 20), triangle->p2());
	EXPECT_EQ(Vecteur2D(22, 24), triangle->p3());
	EXPECT_EQ(Vecteur2D(26, 28), polygone->points()[0]);
	EXPECT_EQ(Vecteur2D(30, 32), polygone->points()[1]);
	EXPECT_EQ(Vecteur2D(34, 36), polygone->points()[2]);
	EXPECT_EQ(Vecteur2D(38, 40), polygone->points()[3]);
}

TEST_F(GroupeTest, Rotation)
{
	// Arrange
	const double tolerance = 1e-10;

	// Act
	groupe->rotation(Vecteur2D(0, 0), PI/2);

	// Assert
	EXPECT_NEAR(-2, cercle->centre().x, tolerance);
	EXPECT_NEAR(1, cercle->centre().y, tolerance);

	EXPECT_NEAR(-4, segment->p1().x, tolerance);
	EXPECT_NEAR(3, segment->p1().y, tolerance);
	EXPECT_NEAR(-6, segment->p2().x, tolerance);
	EXPECT_NEAR(5, segment->p2().y, tolerance);

	EXPECT_NEAR(-8, triangle->p1().x, tolerance);
	EXPECT_NEAR(7, triangle->p1().y, tolerance);
	EXPECT_NEAR(-10, triangle->p2().x, tolerance);
	EXPECT_NEAR(9, triangle->p2().y, tolerance);
	EXPECT_NEAR(-12, triangle->p3().x, tolerance);
	EXPECT_NEAR(11, triangle->p3().y, tolerance);

	EXPECT_NEAR(-14, polygone->points()[0].x, tolerance);
	EXPECT_NEAR(13, polygone->points()[0].y, tolerance);
	EXPECT_NEAR(-16, polygone->points()[1].x, tolerance);
	EXPECT_NEAR(15, polygone->points()[1].y, tolerance);
	EXPECT_NEAR(-18, polygone->points()[2].x, tolerance);
	EXPECT_NEAR(17, polygone->points()[2].y, tolerance);
	EXPECT_NEAR(-20, polygone->points()[3].x, tolerance);
	EXPECT_NEAR(19, polygone->points()[3].y, tolerance);
}